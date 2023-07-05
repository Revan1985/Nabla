#ifndef _NBL_VIDEO_C_VULKAN_ACCELERATION_STRUCTURE_H_INCLUDED_
#define _NBL_VIDEO_C_VULKAN_ACCELERATION_STRUCTURE_H_INCLUDED_


#include "nbl/video/IGPUAccelerationStructure.h"

#define VK_NO_PROTOTYPES
#include "vulkan/vulkan.h"

#include "nbl/video/CVulkanCommon.h"


namespace nbl::video
{

//! all these utilities cannot be nested because of the complex inheritance between `IGPUAccelerationStructure` and the Vulkan classes
inline VkCopyAccelerationStructureModeKHR getVkCopyAccelerationStructureModeFrom(const IGPUAccelerationStructure::COPY_MODE in)
{
	return static_cast<VkCopyAccelerationStructureModeKHR>(in);
}
inline VkCopyAccelerationStructureInfoKHR getVkCopyAccelerationStructureInfoFrom(const IGPUAccelerationStructure::CopyInfo& copyInfo)
{
	VkCopyAccelerationStructureInfoKHR info = { VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR,nullptr };
	info.src = *reinterpret_cast<const VkAccelerationStructureKHR*>(copyInfo.src->getNativeHandle());
	info.dst = *reinterpret_cast<const VkAccelerationStructureKHR*>(copyInfo.dst->getNativeHandle());
	info.mode = getVkCopyAccelerationStructureModeFrom(copyInfo.mode);
	return info;
}

template<typename BufferType>
inline VkDeviceOrHostAddressKHR getVkDeviceOrHostAddress(const asset::SBufferBinding<BufferType>& binding)
{
	VkDeviceOrHostAddressKHR addr;
	if constexpr (std::is_same_v<BufferType,IGPUBuffer>)
		addr.deviceAddress = binding.buffer->getDeviceAddress()+binding.offset;
	else
	{
		static_assert(std::is_same_v<BufferType,asset::ICPUBuffer>);
		addr.hostAddress = reinterpret_cast<uint8_t*>(binding.buffer->getPointer())+binding.offset;
	}
	return addr;
}
template<typename BufferType>
inline VkDeviceOrHostAddressConstKHR getVkDeviceOrHostConstAddress(const asset::SBufferBinding<const BufferType>& binding)
{
	VkDeviceOrHostAddressConstKHR addr;
	if constexpr (std::is_same_v<BufferType,IGPUBuffer>)
		addr.deviceAddress = binding.buffer->getDeviceAddress()+binding.offset;
	else
	{
		static_assert(std::is_same_v<BufferType,asset::ICPUBuffer>);
		addr.hostAddress = reinterpret_cast<const uint8_t*>(binding.buffer->getPointer())+binding.offset;
	}
	return addr;
}
template<typename BufferType>
inline VkCopyAccelerationStructureToMemoryInfoKHR getVkCopyAccelerationStructureToMemoryInfoFrom(const IGPUAccelerationStructure::CopyToMemoryInfo<BufferType>& copyInfo)
{
	VkCopyAccelerationStructureToMemoryInfoKHR info = { VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR,nullptr };
	info.src = *reinterpret_cast<const VkAccelerationStructureKHR*>(copyInfo.src->getNativeHandle());
	info.dst = getVkDeviceOrHostAddress<BufferType>(copyInfo.dst);
	info.mode = getVkCopyAccelerationStructureModeFrom(copyInfo.mode);
	return info;
}
template<typename BufferType>
inline VkCopyMemoryToAccelerationStructureInfoKHR getVkCopyMemoryToAccelerationStructureInfoFrom(const IGPUAccelerationStructure::CopyFromMemoryInfo<BufferType>& copyInfo)
{
	VkCopyMemoryToAccelerationStructureInfoKHR info = { VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR,nullptr };
	info.src = getVkDeviceOrHostConstAddress<BufferType>(copyInfo.src);
	info.dst = *reinterpret_cast<const VkAccelerationStructureKHR*>(copyInfo.dst->getNativeHandle());
	info.mode = getVkCopyAccelerationStructureModeFrom(copyInfo.mode);
	return info;
}

inline VkGeometryFlagsKHR getVkGeometryFlagsFrom(const IGPUBottomLevelAccelerationStructure::GEOMETRY_FLAGS in)
{
	return static_cast<VkGeometryFlagsKHR>(in);
}

// The srcAccelerationStructure, dstAccelerationStructure, and mode members of pBuildInfo are ignored. Any VkDeviceOrHostAddressKHR members of pBuildInfo are ignored by this command
static const VkDeviceOrHostAddressConstKHR NullAddress = { 0x0ull };
template<class BufferType, bool QueryOnly=false>
void getVkAcelerationStructureGeometryFrom(const IGPUBottomLevelAccelerationStructure::Triangles<BufferType>& triangles, VkAccelerationStructureGeometryKHR& outBase)
{
	static const VkDeviceOrHostAddressConstKHR DummyNonNullAddress = { 0xdeadbeefBADC0FFEull };

	outBase = {VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR,nullptr,VK_GEOMETRY_TYPE_TRIANGLES_KHR};
	outBase.geometry.triangles = {VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR,nullptr};
	outBase.geometry.triangles.vertexFormat = getVkFormatFromFormat(triangles.vertexFormat);
	outBase.geometry.triangles.vertexData = QueryOnly ? NullAddress:getVkDeviceOrHostConstAddress<BufferType>(triangles.vertexData[0]);
	outBase.geometry.triangles.vertexStride = triangles.vertexStride;
	outBase.geometry.triangles.maxVertex = triangles.maxVertex;
	outBase.geometry.triangles.indexType = static_cast<VkIndexType>(triangles.indexType);
	outBase.geometry.triangles.indexData = QueryOnly ? NullAddress:getVkDeviceOrHostConstAddress<BufferType>(triangles.indexData);
	// except that the hostAddress member of VkAccelerationStructureGeometryTrianglesDataKHR::transformData will be examined to check if it is NULL.
	outBase.geometry.triangles.transformData = QueryOnly ? DummyNonNullAddress:getVkDeviceOrHostConstAddress<BufferType>(triangles.transformData);
	outBase.flags = getVkGeometryFlagsFrom(triangles.geometryFlags.value);
}
#if 0 // TODO
template<class BufferType, bool QueryOnly=false>
void getVkAcelerationStructureGeometryFrom(const IGPUBottomLevelAccelerationStructure::Triangles<BufferType>& triangles, VkAccelerationStructureGeometryKHR& outBase, VkAccelerationStructureGeometryMotionTrianglesDataNV& vertexMotion)
{
	getVkAcelerationStructureGeometryFrom(triangles,outBase);
	if (triangles.vertexData[1].buffer)
	{
		vertexMotion->vertexData = QueryOnly ? NullAddress:getVkDeviceOrHostConstAddress<BufferType>(triangles.vertexData[1]);
		outBase.geometry.triangles.pNext = vertexMotion;
	}
}
#endif
template<class BufferType, bool QueryOnly=false>
void getVkAcelerationStructureGeometryFrom(const IGPUBottomLevelAccelerationStructure::AABBs<BufferType>& aabbs, VkAccelerationStructureGeometryKHR& outBase)
{
	outBase = {VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR,nullptr,VK_GEOMETRY_TYPE_AABBS_KHR};
	outBase.geometry.aabbs = {VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR,nullptr};
	outBase.geometry.aabbs.data = QueryOnly ? NullAddress:getVkDeviceOrHostConstAddress<BufferType>(aabbs.data);
	outBase.geometry.aabbs.stride = aabbs.stride;
	outBase.flags = getVkGeometryFlagsFrom(aabbs.geometryFlags.value);
}

inline VkBuildAccelerationStructureFlagsKHR getVkASBuildFlagsFrom(const IGPUBottomLevelAccelerationStructure::BUILD_FLAGS in)
{
	return static_cast<VkBuildAccelerationStructureFlagsKHR>(in);
}
inline VkBuildAccelerationStructureFlagsKHR getVkASBuildFlagsFrom(const IGPUTopLevelAccelerationStructure::BUILD_FLAGS in)
{
	return static_cast<VkBuildAccelerationStructureFlagsKHR>(in);
}


class CVulkanLogicalDevice;


template<class GPUAccelerationStructure>
class CVulkanAccelerationStructure : public GPUAccelerationStructure
{
	public:
		inline const void* getNativeHandle() const { return &m_accelerationStructure; }
		inline VkAccelerationStructureKHR getInternalObject() const { return m_vkAccelerationStructure; }
	
		bool wasCopySuccessful(const IDeferredOperation* const deferredOp) override;

	protected:
		CVulkanAccelerationStructure(core::smart_refctd_ptr<const CVulkanLogicalDevice>&& logicalDevice, IGPUAccelerationStructure::SCreationParams&& params, const VkAccelerationStructureKHR accelerationStructure);
		~CVulkanAccelerationStructure();

		VkAccelerationStructureKHR m_vkAccelerationStructure;
		VkDeviceAddress m_deviceAddress;
		
};

class CVulkanBottomLevelAccelerationStructure final : public CVulkanAccelerationStructure<IGPUBottomLevelAccelerationStructure>
{
	public:
		using CVulkanAccelerationStructure<IGPUBottomLevelAccelerationStructure>::CVulkanAccelerationStructure<IGPUBottomLevelAccelerationStructure>;

		inline device_op_ref_t getReferenceForDeviceOperations() const override {return {m_deviceAddress};}
		inline host_op_ref_t getReferenceForHostOperations() const override {return {reinterpret_cast<uint64_t>(m_vkAccelerationStructure)};}

	private:
};

class CVulkanTopLevelAccelerationStructure final : public CVulkanAccelerationStructure<IGPUTopLevelAccelerationStructure>
{
	public:
		using CVulkanAccelerationStructure<IGPUTopLevelAccelerationStructure>::CVulkanAccelerationStructure<IGPUTopLevelAccelerationStructure>;
};

}

#endif
