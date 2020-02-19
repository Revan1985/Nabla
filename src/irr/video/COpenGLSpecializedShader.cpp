#include "COpenGLSpecializedShader.h"
#include "COpenGLDriver.h"
#include "irr/asset/spvUtils.h"
#include <algorithm>
#include "spirv_cross/spirv_parser.hpp"

#ifdef _IRR_COMPILE_WITH_OPENGL_

namespace irr
{
namespace video
{

namespace impl
{
static void specialize(spirv_cross::CompilerGLSL& _comp, const asset::ISpecializedShader::SInfo& _specData)
{
    spirv_cross::SmallVector<spirv_cross::SpecializationConstant> sconsts = _comp.get_specialization_constants();
    for (const auto& sc : sconsts)
    {
        spirv_cross::SPIRConstant& val = _comp.get_constant(sc.id);
        val.specialization = false; // despecializing. If spec-data is not provided, the spec constant is left with its default value. Default value can be queried through introspection mechanism.

        auto specVal = _specData.getSpecializationByteValue(sc.constant_id);
        if (!specVal.first)
            continue;
        memcpy(&val.m.c[0].r[0].u64, specVal.first, specVal.second); // this will do for spec constants of scalar types (uint, int, float,...) regardless of size
        // but it's ok since ,according to SPIR-V specification, only specialization constants of scalar types are supported (only scalar spec constants can have SpecId decoration)
    }
}

static void reorderBindings(spirv_cross::CompilerGLSL& _comp, const COpenGLPipelineLayout* _layout)
{
    auto sort_ = [&_comp](spirv_cross::SmallVector<spirv_cross::Resource>& res) {
        using R_t = spirv_cross::Resource;
        auto cmp = [&_comp](const R_t& a, const R_t& b) {
            uint32_t a_set = _comp.get_decoration(a.id, spv::DecorationDescriptorSet);
            uint32_t b_set = _comp.get_decoration(b.id, spv::DecorationDescriptorSet);
            if (a_set < b_set)
                return true;
            if (a_set > b_set)
                return false;
            uint32_t a_bnd = _comp.get_decoration(a.id, spv::DecorationBinding);
            uint32_t b_bnd = _comp.get_decoration(b.id, spv::DecorationBinding);
            return a_bnd < b_bnd;
        };
        std::sort(res.begin(), res.end(), cmp);
    };
    auto reorder_ = [&_comp,_layout](spirv_cross::SmallVector<spirv_cross::Resource>& res, asset::E_DESCRIPTOR_TYPE _dtype1, asset::E_DESCRIPTOR_TYPE _dtype2) {
        uint32_t availableBinding = 0u;
		uint32_t currSet = 0u;
		const IGPUDescriptorSetLayout* dsl = nullptr;
        for (uint32_t i = 0u, j = 0u; i < res.size(); ++j) {
			uint32_t set = _comp.get_decoration(res[i].id, spv::DecorationDescriptorSet);
			if (!dsl || currSet!=set) {
				currSet = set;
				dsl = _layout->getDescriptorSetLayout(currSet);
				j = 0u;
			}

            const spirv_cross::Resource& r = res[i];
			const uint32_t r_bnd = _comp.get_decoration(r.id, spv::DecorationBinding);

			if (dsl->getBindings().begin()[j].binding != r_bnd) {
				const asset::E_DESCRIPTOR_TYPE dtype = dsl->getBindings().begin()[j].type;
				if (dtype==_dtype1 || dtype==_dtype2)
					availableBinding += dsl->getBindings().begin()[j].count;
				continue;
			}

            _comp.set_decoration(r.id, spv::DecorationBinding, availableBinding);
            const spirv_cross::SPIRType& type = _comp.get_type(r.type_id);
			availableBinding += (type.array.size() ? type.array[0] : 1u);
            _comp.unset_decoration(r.id, spv::DecorationDescriptorSet);
			++i;
        }
    };

    spirv_cross::ShaderResources resources = _comp.get_shader_resources(_comp.get_active_interface_variables());
	assert(resources.push_constant_buffers.size()<=1u);
	for (const auto& pushConstants : resources.push_constant_buffers)
		_comp.set_decoration(pushConstants.id, spv::DecorationLocation, 0);

    auto samplers = std::move(resources.sampled_images);
    for (const auto& samplerBuffer : resources.separate_images)
        if (_comp.get_type(samplerBuffer.type_id).image.dim == spv::DimBuffer)
            samplers.push_back(samplerBuffer);//see https://github.com/KhronosGroup/SPIRV-Cross/wiki/Reflection-API-user-guide for explanation
    sort_(samplers);
    reorder_(samplers, asset::EDT_COMBINED_IMAGE_SAMPLER, asset::EDT_UNIFORM_TEXEL_BUFFER);

    auto images = std::move(resources.storage_images);
    sort_(images);
    reorder_(images, asset::EDT_STORAGE_IMAGE, asset::EDT_STORAGE_TEXEL_BUFFER);

    auto ubos = std::move(resources.uniform_buffers);
    sort_(ubos);
    reorder_(ubos, asset::EDT_UNIFORM_BUFFER, asset::EDT_UNIFORM_BUFFER_DYNAMIC);

    auto ssbos = std::move(resources.storage_buffers);
    sort_(ssbos);
    reorder_(ssbos, asset::EDT_STORAGE_BUFFER, asset::EDT_STORAGE_BUFFER_DYNAMIC);
}

static GLenum ESS2GLenum(asset::ISpecializedShader::E_SHADER_STAGE _stage)
{
    using namespace asset;
    switch (_stage)
    {
		case asset::ISpecializedShader::ESS_VERTEX: return GL_VERTEX_SHADER;
		case asset::ISpecializedShader::ESS_TESSELATION_CONTROL: return GL_TESS_CONTROL_SHADER;
		case asset::ISpecializedShader::ESS_TESSELATION_EVALUATION: return GL_TESS_EVALUATION_SHADER;
		case asset::ISpecializedShader::ESS_GEOMETRY: return GL_GEOMETRY_SHADER;
		case asset::ISpecializedShader::ESS_FRAGMENT: return GL_FRAGMENT_SHADER;
		case asset::ISpecializedShader::ESS_COMPUTE: return GL_COMPUTE_SHADER;
		default: return GL_INVALID_ENUM;
    }
}

}//namesapce impl

}
}//irr::video

using namespace irr;
using namespace irr::video;

COpenGLSpecializedShader::COpenGLSpecializedShader(uint32_t _GLSLversion, const asset::ICPUBuffer* _spirv, const asset::ISpecializedShader::SInfo& _specInfo, const asset::CIntrospectionData* _introspection) :
	core::impl::ResolveAlignment<IGPUSpecializedShader, core::AllocationOverrideBase<128>>(_specInfo.shaderStage),
    m_GLstage(impl::ESS2GLenum(_specInfo.shaderStage)),
	m_specInfo(_specInfo),//TODO make it move()
	m_spirv(core::smart_refctd_ptr<const asset::ICPUBuffer>(_spirv))
{
	m_options.version = _GLSLversion;
	//vulkan_semantics=false causes spirv_cross to translate push_constants into non-UBO uniform of struct type! Exactly like we wanted!
	m_options.vulkan_semantics = false; // with this it's likely that SPIRV-Cross will take care of built-in variables renaming, but need testing
	m_options.separate_shader_objects = true;

	core::XXHash_256(_spirv->getPointer(), _spirv->getSize(), m_spirvHash.data());

	assert(_introspection);
	const auto& pc = _introspection->pushConstant;
	if (pc.present)
	{
		const auto& pc_layout = pc.info;
		core::queue<SMember> q;
		SMember initial;
		initial.type = asset::EGVT_UNKNOWN_OR_STRUCT;
		initial.members = pc_layout.members;
		initial.name = pc.info.name;
		q.push(initial);
		while (!q.empty())
		{
			const SMember top = q.front();
			q.pop();
			if (top.type == asset::EGVT_UNKNOWN_OR_STRUCT && top.members.count) {
				for (size_t i = 0ull; i < top.members.count; ++i) {
					SMember m = top.members.array[i];
					m.name = top.name + "." + m.name;
					if (m.count > 1u)
						m.name += "[0]";
					q.push(m);
				}
				continue;
			}
			m_uniformsList.emplace_back(top);
		}
	}
}

void COpenGLSpecializedShader::setUniformsImitatingPushConstants(const uint8_t* _pcData, GLuint _GLname, uint8_t* _state, bool _dontCmpWithState) const
{
    IRR_ASSUME_ALIGNED(_pcData, 128);

    using gl = COpenGLExtensionHandler;
	uint32_t loc_i = 0u;
    for (auto u_it = m_uniformsList.begin(); u_it!=m_uniformsList.end(); ++u_it, ++loc_i)
    {
		if (m_locations[loc_i]<0)
			continue;

		const SUniform& u = *u_it;

        const SMember& m = u.m;
        auto is_scalar_or_vec = [&m] { return (m.mtxRowCnt >= 1u && m.mtxColCnt == 1u); };
        auto is_mtx = [&m] { return (m.mtxRowCnt > 1u && m.mtxColCnt > 1u); };

		uint8_t* valueptr = _state+m.offset;

        uint32_t arrayStride = 0u;
        {
            uint32_t arrayStride1 = 0u;
            if (is_scalar_or_vec())
                arrayStride1 = (m.mtxRowCnt==1u) ? m.size : core::roundUpToPoT(m.mtxRowCnt)*4u;
            else if (is_mtx())
                arrayStride1 = m.arrayStride;
            assert(arrayStride1);
            arrayStride = (m.count <= 1u) ? arrayStride1 : m.arrayStride;
        }
		assert(m.mtxStride==0u || arrayStride%m.mtxStride==0u);
		IRR_ASSUME_ALIGNED(valueptr, sizeof(float));
		IRR_ASSUME_ALIGNED(valueptr, arrayStride);
		
		auto* baseOffset = _pcData+m.offset;
		IRR_ASSUME_ALIGNED(baseOffset, sizeof(float));
		IRR_ASSUME_ALIGNED(baseOffset, arrayStride);

		constexpr uint32_t MAX_DWORD_SIZE = IGPUMeshBuffer::MAX_PUSH_CONSTANT_BYTESIZE/sizeof(GLfloat);
		alignas(128u) std::array<GLfloat,MAX_DWORD_SIZE> packed_data;

        const uint32_t count = std::min<uint32_t>(m.count, MAX_DWORD_SIZE/(m.count*m.mtxRowCnt*m.mtxColCnt));
		if (!std::equal(baseOffset, baseOffset+arrayStride*count, valueptr) || _dontCmpWithState)
		{
			// pack the constant data as OpenGL uniform update functions expect packed arrays
			{
				const bool isRowMajor = is_scalar_or_vec() || m.rowMajor;
				const uint32_t rowOrColCnt = isRowMajor ? m.mtxColCnt : m.mtxRowCnt;
				const uint32_t len = isRowMajor ? m.mtxRowCnt : m.mtxColCnt;
				for (uint32_t i = 0u; i < count; ++i)
				for (uint32_t c = 0u; c < rowOrColCnt; ++c)
				{
					const GLfloat* in = reinterpret_cast<const GLfloat*>(baseOffset + i*arrayStride + c*m.mtxStride);
					GLfloat* out = packed_data.data() + (i*m.mtxRowCnt*m.mtxColCnt) + (c*len);
					std::copy(in, in+len, out);
				}
			}

			if (is_mtx() && m.type==asset::EGVT_F32)
			{
					PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrixNxMfv_fptr[3][3]{ //N - num of columns, M - num of rows because of weird OpenGL naming convention
						{&gl::extGlProgramUniformMatrix2fv, &gl::extGlProgramUniformMatrix2x3fv, &gl::extGlProgramUniformMatrix2x4fv},//2xM
						{&gl::extGlProgramUniformMatrix3x2fv, &gl::extGlProgramUniformMatrix3fv, &gl::extGlProgramUniformMatrix3x4fv},//3xM
						{&gl::extGlProgramUniformMatrix4x2fv, &gl::extGlProgramUniformMatrix4x3fv, &gl::extGlProgramUniformMatrix4fv} //4xM
					};

					glProgramUniformMatrixNxMfv_fptr[m.mtxColCnt - 2u][m.mtxRowCnt - 2u](_GLname, m_locations[loc_i], m.count, m.rowMajor ? GL_TRUE : GL_FALSE, packed_data.data());
			}
			else if (is_scalar_or_vec())
			{
				switch (m.type) 
				{
					case asset::EGVT_F32:
					{
						PFNGLPROGRAMUNIFORM1FVPROC glProgramUniformNfv_fptr[4]{
							&gl::extGlProgramUniform1fv, &gl::extGlProgramUniform2fv, &gl::extGlProgramUniform3fv, &gl::extGlProgramUniform4fv
						};
						glProgramUniformNfv_fptr[m.mtxRowCnt-1u](_GLname, m_locations[loc_i], m.count, packed_data.data());
						break;
					}
					case asset::EGVT_I32:
					{
						PFNGLPROGRAMUNIFORM1IVPROC glProgramUniformNiv_fptr[4]{
							&gl::extGlProgramUniform1iv, &gl::extGlProgramUniform2iv, &gl::extGlProgramUniform3iv, &gl::extGlProgramUniform4iv
						};
						glProgramUniformNiv_fptr[m.mtxRowCnt-1u](_GLname, m_locations[loc_i], m.count, reinterpret_cast<const GLint*>(packed_data.data()));
						break;
					}
					case asset::EGVT_U32:
					{
						PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniformNuiv_fptr[4]{
							&gl::extGlProgramUniform1uiv, &gl::extGlProgramUniform2uiv, &gl::extGlProgramUniform3uiv, &gl::extGlProgramUniform4uiv
						};
						glProgramUniformNuiv_fptr[m.mtxRowCnt-1u](_GLname, m_locations[loc_i], m.count, reinterpret_cast<const GLuint*>(packed_data.data()));
						break;
					}
				}
			}
			std::copy(baseOffset, baseOffset+arrayStride*count, valueptr);
        }
    }
}

auto COpenGLSpecializedShader::compile(const COpenGLPipelineLayout* _layout, const spirv_cross::ParsedIR* _parsedSpirv) const -> std::pair<GLuint, SProgramBinary>
{
	spirv_cross::ParsedIR parsed;
	if (_parsedSpirv)
		parsed = _parsedSpirv[0];
	else
	{
		spirv_cross::Parser parser(reinterpret_cast<const uint32_t*>(m_spirv->getPointer()), m_spirv->getSize()/4ull);
		parser.parse();
		parsed = std::move(parser.get_parsed_ir());
	}
	spirv_cross::CompilerGLSL comp(std::move(parsed));

	comp.set_entry_point(m_specInfo.entryPoint, asset::ESS2spvExecModel(m_specInfo.shaderStage));
	comp.set_common_options(m_options);

	impl::specialize(comp, m_specInfo);
	impl::reorderBindings(comp, _layout);

	std::string glslCode = comp.compile();
	const char* glslCode_cstr = glslCode.c_str();

	GLuint GLname = COpenGLExtensionHandler::extGlCreateShaderProgramv(m_GLstage, 1u, &glslCode_cstr);

	GLchar logbuf[1u<<12]; //4k
	COpenGLExtensionHandler::extGlGetProgramInfoLog(GLname, sizeof(logbuf), nullptr, logbuf);
	if (logbuf[0])
		os::Printer::log(logbuf, ELL_ERROR);

	if (m_locations.empty())
		gatherUniformLocations(GLname);

	SProgramBinary binary;
	GLint binaryLength = 0;
	COpenGLExtensionHandler::extGlGetProgramiv(GLname, GL_PROGRAM_BINARY_LENGTH, &binaryLength);
	binary.binary = core::make_refctd_dynamic_array<core::smart_refctd_dynamic_array<uint8_t>>(binaryLength);
	COpenGLExtensionHandler::extGlGetProgramBinary(GLname, binaryLength, nullptr, &binary.format, binary.binary->data());

	return {GLname, std::move(binary)};
}

void COpenGLSpecializedShader::gatherUniformLocations(GLuint _GLname) const
{
	m_locations.resize(m_uniformsList.size());
	for (size_t i = 0ull; i < m_uniformsList.size(); ++i)
		m_locations[i] = COpenGLExtensionHandler::extGlGetUniformLocation(_GLname, m_uniformsList[i].m.name.c_str());
}

#endif