#include <utility>
#include "irr/asset/format/convertColor.h"

namespace irr
{
namespace asset
{


namespace impl
{


template<E_FORMAT sF>
static void convertColor_RTimpl(E_FORMAT _dfmt, const void* _srcPix[4], void* _dstPix, size_t _pixOrBlockCnt, core::vector3d<uint32_t>& _imgSize, PolymorphicSwizzle* swizzle)
{
    switch (_dfmt)
    {
        case EF_R4G4_UNORM_PACK8: return convertColor<sF, EF_R4G4_UNORM_PACK8,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R4G4B4A4_UNORM_PACK16: return convertColor<sF, EF_R4G4B4A4_UNORM_PACK16,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B4G4R4A4_UNORM_PACK16: return convertColor<sF, EF_B4G4R4A4_UNORM_PACK16,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R5G6B5_UNORM_PACK16: return convertColor<sF, EF_R5G6B5_UNORM_PACK16,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B5G6R5_UNORM_PACK16: return convertColor<sF, EF_B5G6R5_UNORM_PACK16,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R5G5B5A1_UNORM_PACK16: return convertColor<sF, EF_R5G5B5A1_UNORM_PACK16,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B5G5R5A1_UNORM_PACK16: return convertColor<sF, EF_B5G5R5A1_UNORM_PACK16,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A1R5G5B5_UNORM_PACK16: return convertColor<sF, EF_A1R5G5B5_UNORM_PACK16,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8_UNORM: return convertColor<sF, EF_R8_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8_SNORM: return convertColor<sF, EF_R8_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8_USCALED: return convertColor<sF, EF_R8_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8_SSCALED: return convertColor<sF, EF_R8_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8_UINT: return convertColor<sF, EF_R8_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8_SINT: return convertColor<sF, EF_R8_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8_SRGB: return convertColor<sF, EF_R8_SRGB,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8_UNORM: return convertColor<sF, EF_R8G8_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8_SNORM: return convertColor<sF, EF_R8G8_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8_USCALED: return convertColor<sF, EF_R8G8_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8_SSCALED: return convertColor<sF, EF_R8G8_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8_UINT: return convertColor<sF, EF_R8G8_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8_SINT: return convertColor<sF, EF_R8G8_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8_SRGB: return convertColor<sF, EF_R8G8_SRGB,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8_UNORM: return convertColor<sF, EF_R8G8B8_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8_SNORM: return convertColor<sF, EF_R8G8B8_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8_USCALED: return convertColor<sF, EF_R8G8B8_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8_SSCALED: return convertColor<sF, EF_R8G8B8_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8_UINT: return convertColor<sF, EF_R8G8B8_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8_SINT: return convertColor<sF, EF_R8G8B8_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8_SRGB: return convertColor<sF, EF_R8G8B8_SRGB,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8_UNORM: return convertColor<sF, EF_B8G8R8_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8_SNORM: return convertColor<sF, EF_B8G8R8_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8_USCALED: return convertColor<sF, EF_B8G8R8_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8_SSCALED: return convertColor<sF, EF_B8G8R8_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8_UINT: return convertColor<sF, EF_B8G8R8_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8_SINT: return convertColor<sF, EF_B8G8R8_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8_SRGB: return convertColor<sF, EF_B8G8R8_SRGB,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8A8_UNORM: return convertColor<sF, EF_R8G8B8A8_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8A8_SNORM: return convertColor<sF, EF_R8G8B8A8_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8A8_USCALED: return convertColor<sF, EF_R8G8B8A8_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8A8_SSCALED: return convertColor<sF, EF_R8G8B8A8_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8A8_UINT: return convertColor<sF, EF_R8G8B8A8_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8A8_SINT: return convertColor<sF, EF_R8G8B8A8_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R8G8B8A8_SRGB: return convertColor<sF, EF_R8G8B8A8_SRGB,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8A8_UNORM: return convertColor<sF, EF_B8G8R8A8_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8A8_SNORM: return convertColor<sF, EF_B8G8R8A8_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8A8_USCALED: return convertColor<sF, EF_B8G8R8A8_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8A8_SSCALED: return convertColor<sF, EF_B8G8R8A8_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8A8_UINT: return convertColor<sF, EF_B8G8R8A8_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8A8_SINT: return convertColor<sF, EF_B8G8R8A8_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B8G8R8A8_SRGB: return convertColor<sF, EF_B8G8R8A8_SRGB,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A8B8G8R8_UNORM_PACK32: return convertColor<sF, EF_A8B8G8R8_UNORM_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A8B8G8R8_SNORM_PACK32: return convertColor<sF, EF_A8B8G8R8_SNORM_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A8B8G8R8_USCALED_PACK32: return convertColor<sF, EF_A8B8G8R8_USCALED_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A8B8G8R8_SSCALED_PACK32: return convertColor<sF, EF_A8B8G8R8_SSCALED_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A8B8G8R8_UINT_PACK32: return convertColor<sF, EF_A8B8G8R8_UINT_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A8B8G8R8_SINT_PACK32: return convertColor<sF, EF_A8B8G8R8_SINT_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A8B8G8R8_SRGB_PACK32: return convertColor<sF, EF_A8B8G8R8_SRGB_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2R10G10B10_UNORM_PACK32: return convertColor<sF, EF_A2R10G10B10_UNORM_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2R10G10B10_SNORM_PACK32: return convertColor<sF, EF_A2R10G10B10_SNORM_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2R10G10B10_USCALED_PACK32: return convertColor<sF, EF_A2R10G10B10_USCALED_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2R10G10B10_SSCALED_PACK32: return convertColor<sF, EF_A2R10G10B10_SSCALED_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2R10G10B10_UINT_PACK32: return convertColor<sF, EF_A2R10G10B10_UINT_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2R10G10B10_SINT_PACK32: return convertColor<sF, EF_A2R10G10B10_SINT_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2B10G10R10_UNORM_PACK32: return convertColor<sF, EF_A2B10G10R10_UNORM_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2B10G10R10_SNORM_PACK32: return convertColor<sF, EF_A2B10G10R10_SNORM_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2B10G10R10_USCALED_PACK32: return convertColor<sF, EF_A2B10G10R10_USCALED_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2B10G10R10_SSCALED_PACK32: return convertColor<sF, EF_A2B10G10R10_SSCALED_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2B10G10R10_UINT_PACK32: return convertColor<sF, EF_A2B10G10R10_UINT_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_A2B10G10R10_SINT_PACK32: return convertColor<sF, EF_A2B10G10R10_SINT_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16_UNORM: return convertColor<sF, EF_R16_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16_SNORM: return convertColor<sF, EF_R16_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16_USCALED: return convertColor<sF, EF_R16_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16_SSCALED: return convertColor<sF, EF_R16_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16_UINT: return convertColor<sF, EF_R16_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16_SINT: return convertColor<sF, EF_R16_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16_SFLOAT: return convertColor<sF, EF_R16_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16_UNORM: return convertColor<sF, EF_R16G16_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16_SNORM: return convertColor<sF, EF_R16G16_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16_USCALED: return convertColor<sF, EF_R16G16_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16_SSCALED: return convertColor<sF, EF_R16G16_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16_UINT: return convertColor<sF, EF_R16G16_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16_SINT: return convertColor<sF, EF_R16G16_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16_SFLOAT: return convertColor<sF, EF_R16G16_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16_UNORM: return convertColor<sF, EF_R16G16B16_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16_SNORM: return convertColor<sF, EF_R16G16B16_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16_USCALED: return convertColor<sF, EF_R16G16B16_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16_SSCALED: return convertColor<sF, EF_R16G16B16_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16_UINT: return convertColor<sF, EF_R16G16B16_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16_SINT: return convertColor<sF, EF_R16G16B16_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16_SFLOAT: return convertColor<sF, EF_R16G16B16_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16A16_UNORM: return convertColor<sF, EF_R16G16B16A16_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16A16_SNORM: return convertColor<sF, EF_R16G16B16A16_SNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16A16_USCALED: return convertColor<sF, EF_R16G16B16A16_USCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16A16_SSCALED: return convertColor<sF, EF_R16G16B16A16_SSCALED,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16A16_UINT: return convertColor<sF, EF_R16G16B16A16_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16A16_SINT: return convertColor<sF, EF_R16G16B16A16_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R16G16B16A16_SFLOAT: return convertColor<sF, EF_R16G16B16A16_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32_UINT: return convertColor<sF, EF_R32_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32_SINT: return convertColor<sF, EF_R32_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32_SFLOAT: return convertColor<sF, EF_R32_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32G32_UINT: return convertColor<sF, EF_R32G32_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32G32_SINT: return convertColor<sF, EF_R32G32_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32G32_SFLOAT: return convertColor<sF, EF_R32G32_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32G32B32_UINT: return convertColor<sF, EF_R32G32B32_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32G32B32_SINT: return convertColor<sF, EF_R32G32B32_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32G32B32_SFLOAT: return convertColor<sF, EF_R32G32B32_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32G32B32A32_UINT: return convertColor<sF, EF_R32G32B32A32_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32G32B32A32_SINT: return convertColor<sF, EF_R32G32B32A32_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R32G32B32A32_SFLOAT: return convertColor<sF, EF_R32G32B32A32_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64_UINT: return convertColor<sF, EF_R64_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64_SINT: return convertColor<sF, EF_R64_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64_SFLOAT: return convertColor<sF, EF_R64_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64G64_UINT: return convertColor<sF, EF_R64G64_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64G64_SINT: return convertColor<sF, EF_R64G64_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64G64_SFLOAT: return convertColor<sF, EF_R64G64_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64G64B64_UINT: return convertColor<sF, EF_R64G64B64_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64G64B64_SINT: return convertColor<sF, EF_R64G64B64_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64G64B64_SFLOAT: return convertColor<sF, EF_R64G64B64_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64G64B64A64_UINT: return convertColor<sF, EF_R64G64B64A64_UINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64G64B64A64_SINT: return convertColor<sF, EF_R64G64B64A64_SINT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_R64G64B64A64_SFLOAT: return convertColor<sF, EF_R64G64B64A64_SFLOAT,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_B10G11R11_UFLOAT_PACK32: return convertColor<sF, EF_B10G11R11_UFLOAT_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_E5B9G9R9_UFLOAT_PACK32: return convertColor<sF, EF_E5B9G9R9_UFLOAT_PACK32,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_BC1_RGB_UNORM_BLOCK: return convertColor<sF, EF_BC1_RGB_UNORM_BLOCK,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_BC1_RGB_SRGB_BLOCK: return convertColor<sF, EF_BC1_RGB_SRGB_BLOCK,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_BC1_RGBA_UNORM_BLOCK: return convertColor<sF, EF_BC1_RGBA_UNORM_BLOCK,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_BC1_RGBA_SRGB_BLOCK: return convertColor<sF, EF_BC1_RGBA_SRGB_BLOCK,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_BC2_UNORM_BLOCK: return convertColor<sF, EF_BC2_UNORM_BLOCK,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_BC2_SRGB_BLOCK: return convertColor<sF, EF_BC2_SRGB_BLOCK,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_BC3_UNORM_BLOCK: return convertColor<sF, EF_BC3_UNORM_BLOCK,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_BC3_SRGB_BLOCK: return convertColor<sF, EF_BC3_SRGB_BLOCK,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_G8_B8_R8_3PLANE_420_UNORM: return convertColor<sF, EF_G8_B8_R8_3PLANE_420_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_G8_B8R8_2PLANE_420_UNORM: return convertColor<sF, EF_G8_B8R8_2PLANE_420_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_G8_B8_R8_3PLANE_422_UNORM: return convertColor<sF, EF_G8_B8_R8_3PLANE_422_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_G8_B8R8_2PLANE_422_UNORM: return convertColor<sF, EF_G8_B8R8_2PLANE_422_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
        case EF_G8_B8_R8_3PLANE_444_UNORM: return convertColor<sF, EF_G8_B8_R8_3PLANE_444_UNORM,void>(_srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    }
}


}//namespace impl



void convertColor(E_FORMAT _sfmt, E_FORMAT _dfmt, const void* _srcPix[4], void* _dstPix, size_t _pixOrBlockCnt, core::vector3d<uint32_t>& _imgSize, PolymorphicSwizzle* swizzle)
{
    switch (_sfmt)
    {
    case EF_R4G4_UNORM_PACK8: return impl::convertColor_RTimpl<EF_R4G4_UNORM_PACK8>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R4G4B4A4_UNORM_PACK16: return impl::convertColor_RTimpl<EF_R4G4B4A4_UNORM_PACK16>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B4G4R4A4_UNORM_PACK16: return impl::convertColor_RTimpl<EF_B4G4R4A4_UNORM_PACK16>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R5G6B5_UNORM_PACK16: return impl::convertColor_RTimpl<EF_R5G6B5_UNORM_PACK16>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B5G6R5_UNORM_PACK16: return impl::convertColor_RTimpl<EF_B5G6R5_UNORM_PACK16>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R5G5B5A1_UNORM_PACK16: return impl::convertColor_RTimpl<EF_R5G5B5A1_UNORM_PACK16>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B5G5R5A1_UNORM_PACK16: return impl::convertColor_RTimpl<EF_B5G5R5A1_UNORM_PACK16>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A1R5G5B5_UNORM_PACK16: return impl::convertColor_RTimpl<EF_A1R5G5B5_UNORM_PACK16>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8_UNORM: return impl::convertColor_RTimpl<EF_R8_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8_SNORM: return impl::convertColor_RTimpl<EF_R8_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8_USCALED: return impl::convertColor_RTimpl<EF_R8_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8_SSCALED: return impl::convertColor_RTimpl<EF_R8_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8_UINT: return impl::convertColor_RTimpl<EF_R8_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8_SINT: return impl::convertColor_RTimpl<EF_R8_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8_SRGB: return impl::convertColor_RTimpl<EF_R8_SRGB>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8_UNORM: return impl::convertColor_RTimpl<EF_R8G8_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8_SNORM: return impl::convertColor_RTimpl<EF_R8G8_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8_USCALED: return impl::convertColor_RTimpl<EF_R8G8_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8_SSCALED: return impl::convertColor_RTimpl<EF_R8G8_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8_UINT: return impl::convertColor_RTimpl<EF_R8G8_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8_SINT: return impl::convertColor_RTimpl<EF_R8G8_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8_SRGB: return impl::convertColor_RTimpl<EF_R8G8_SRGB>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8_UNORM: return impl::convertColor_RTimpl<EF_R8G8B8_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8_SNORM: return impl::convertColor_RTimpl<EF_R8G8B8_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8_USCALED: return impl::convertColor_RTimpl<EF_R8G8B8_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8_SSCALED: return impl::convertColor_RTimpl<EF_R8G8B8_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8_UINT: return impl::convertColor_RTimpl<EF_R8G8B8_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8_SINT: return impl::convertColor_RTimpl<EF_R8G8B8_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8_SRGB: return impl::convertColor_RTimpl<EF_R8G8B8_SRGB>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8_UNORM: return impl::convertColor_RTimpl<EF_B8G8R8_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8_SNORM: return impl::convertColor_RTimpl<EF_B8G8R8_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8_USCALED: return impl::convertColor_RTimpl<EF_B8G8R8_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8_SSCALED: return impl::convertColor_RTimpl<EF_B8G8R8_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8_UINT: return impl::convertColor_RTimpl<EF_B8G8R8_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8_SINT: return impl::convertColor_RTimpl<EF_B8G8R8_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8_SRGB: return impl::convertColor_RTimpl<EF_B8G8R8_SRGB>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8A8_UNORM: return impl::convertColor_RTimpl<EF_R8G8B8A8_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8A8_SNORM: return impl::convertColor_RTimpl<EF_R8G8B8A8_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8A8_USCALED: return impl::convertColor_RTimpl<EF_R8G8B8A8_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8A8_SSCALED: return impl::convertColor_RTimpl<EF_R8G8B8A8_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8A8_UINT: return impl::convertColor_RTimpl<EF_R8G8B8A8_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8A8_SINT: return impl::convertColor_RTimpl<EF_R8G8B8A8_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R8G8B8A8_SRGB: return impl::convertColor_RTimpl<EF_R8G8B8A8_SRGB>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8A8_UNORM: return impl::convertColor_RTimpl<EF_B8G8R8A8_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8A8_SNORM: return impl::convertColor_RTimpl<EF_B8G8R8A8_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8A8_USCALED: return impl::convertColor_RTimpl<EF_B8G8R8A8_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8A8_SSCALED: return impl::convertColor_RTimpl<EF_B8G8R8A8_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8A8_UINT: return impl::convertColor_RTimpl<EF_B8G8R8A8_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8A8_SINT: return impl::convertColor_RTimpl<EF_B8G8R8A8_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B8G8R8A8_SRGB: return impl::convertColor_RTimpl<EF_B8G8R8A8_SRGB>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A8B8G8R8_UNORM_PACK32: return impl::convertColor_RTimpl<EF_A8B8G8R8_UNORM_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A8B8G8R8_SNORM_PACK32: return impl::convertColor_RTimpl<EF_A8B8G8R8_SNORM_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A8B8G8R8_USCALED_PACK32: return impl::convertColor_RTimpl<EF_A8B8G8R8_USCALED_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A8B8G8R8_SSCALED_PACK32: return impl::convertColor_RTimpl<EF_A8B8G8R8_SSCALED_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A8B8G8R8_UINT_PACK32: return impl::convertColor_RTimpl<EF_A8B8G8R8_UINT_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A8B8G8R8_SINT_PACK32: return impl::convertColor_RTimpl<EF_A8B8G8R8_SINT_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A8B8G8R8_SRGB_PACK32: return impl::convertColor_RTimpl<EF_A8B8G8R8_SRGB_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2R10G10B10_UNORM_PACK32: return impl::convertColor_RTimpl<EF_A2R10G10B10_UNORM_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2R10G10B10_SNORM_PACK32: return impl::convertColor_RTimpl<EF_A2R10G10B10_SNORM_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2R10G10B10_USCALED_PACK32: return impl::convertColor_RTimpl<EF_A2R10G10B10_USCALED_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2R10G10B10_SSCALED_PACK32: return impl::convertColor_RTimpl<EF_A2R10G10B10_SSCALED_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2R10G10B10_UINT_PACK32: return impl::convertColor_RTimpl<EF_A2R10G10B10_UINT_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2R10G10B10_SINT_PACK32: return impl::convertColor_RTimpl<EF_A2R10G10B10_SINT_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2B10G10R10_UNORM_PACK32: return impl::convertColor_RTimpl<EF_A2B10G10R10_UNORM_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2B10G10R10_SNORM_PACK32: return impl::convertColor_RTimpl<EF_A2B10G10R10_SNORM_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2B10G10R10_USCALED_PACK32: return impl::convertColor_RTimpl<EF_A2B10G10R10_USCALED_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2B10G10R10_SSCALED_PACK32: return impl::convertColor_RTimpl<EF_A2B10G10R10_SSCALED_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2B10G10R10_UINT_PACK32: return impl::convertColor_RTimpl<EF_A2B10G10R10_UINT_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_A2B10G10R10_SINT_PACK32: return impl::convertColor_RTimpl<EF_A2B10G10R10_SINT_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16_UNORM: return impl::convertColor_RTimpl<EF_R16_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16_SNORM: return impl::convertColor_RTimpl<EF_R16_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16_USCALED: return impl::convertColor_RTimpl<EF_R16_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16_SSCALED: return impl::convertColor_RTimpl<EF_R16_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16_UINT: return impl::convertColor_RTimpl<EF_R16_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16_SINT: return impl::convertColor_RTimpl<EF_R16_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16_SFLOAT: return impl::convertColor_RTimpl<EF_R16_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16_UNORM: return impl::convertColor_RTimpl<EF_R16G16_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16_SNORM: return impl::convertColor_RTimpl<EF_R16G16_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16_USCALED: return impl::convertColor_RTimpl<EF_R16G16_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16_SSCALED: return impl::convertColor_RTimpl<EF_R16G16_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16_UINT: return impl::convertColor_RTimpl<EF_R16G16_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16_SINT: return impl::convertColor_RTimpl<EF_R16G16_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16_SFLOAT: return impl::convertColor_RTimpl<EF_R16G16_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16_UNORM: return impl::convertColor_RTimpl<EF_R16G16B16_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16_SNORM: return impl::convertColor_RTimpl<EF_R16G16B16_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16_USCALED: return impl::convertColor_RTimpl<EF_R16G16B16_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16_SSCALED: return impl::convertColor_RTimpl<EF_R16G16B16_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16_UINT: return impl::convertColor_RTimpl<EF_R16G16B16_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16_SINT: return impl::convertColor_RTimpl<EF_R16G16B16_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16_SFLOAT: return impl::convertColor_RTimpl<EF_R16G16B16_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16A16_UNORM: return impl::convertColor_RTimpl<EF_R16G16B16A16_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16A16_SNORM: return impl::convertColor_RTimpl<EF_R16G16B16A16_SNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16A16_USCALED: return impl::convertColor_RTimpl<EF_R16G16B16A16_USCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16A16_SSCALED: return impl::convertColor_RTimpl<EF_R16G16B16A16_SSCALED>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16A16_UINT: return impl::convertColor_RTimpl<EF_R16G16B16A16_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16A16_SINT: return impl::convertColor_RTimpl<EF_R16G16B16A16_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R16G16B16A16_SFLOAT: return impl::convertColor_RTimpl<EF_R16G16B16A16_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32_UINT: return impl::convertColor_RTimpl<EF_R32_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32_SINT: return impl::convertColor_RTimpl<EF_R32_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32_SFLOAT: return impl::convertColor_RTimpl<EF_R32_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32G32_UINT: return impl::convertColor_RTimpl<EF_R32G32_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32G32_SINT: return impl::convertColor_RTimpl<EF_R32G32_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32G32_SFLOAT: return impl::convertColor_RTimpl<EF_R32G32_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32G32B32_UINT: return impl::convertColor_RTimpl<EF_R32G32B32_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32G32B32_SINT: return impl::convertColor_RTimpl<EF_R32G32B32_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32G32B32_SFLOAT: return impl::convertColor_RTimpl<EF_R32G32B32_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32G32B32A32_UINT: return impl::convertColor_RTimpl<EF_R32G32B32A32_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32G32B32A32_SINT: return impl::convertColor_RTimpl<EF_R32G32B32A32_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R32G32B32A32_SFLOAT: return impl::convertColor_RTimpl<EF_R32G32B32A32_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64_UINT: return impl::convertColor_RTimpl<EF_R64_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64_SINT: return impl::convertColor_RTimpl<EF_R64_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64_SFLOAT: return impl::convertColor_RTimpl<EF_R64_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64G64_UINT: return impl::convertColor_RTimpl<EF_R64G64_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64G64_SINT: return impl::convertColor_RTimpl<EF_R64G64_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64G64_SFLOAT: return impl::convertColor_RTimpl<EF_R64G64_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64G64B64_UINT: return impl::convertColor_RTimpl<EF_R64G64B64_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64G64B64_SINT: return impl::convertColor_RTimpl<EF_R64G64B64_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64G64B64_SFLOAT: return impl::convertColor_RTimpl<EF_R64G64B64_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64G64B64A64_UINT: return impl::convertColor_RTimpl<EF_R64G64B64A64_UINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64G64B64A64_SINT: return impl::convertColor_RTimpl<EF_R64G64B64A64_SINT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_R64G64B64A64_SFLOAT: return impl::convertColor_RTimpl<EF_R64G64B64A64_SFLOAT>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_B10G11R11_UFLOAT_PACK32: return impl::convertColor_RTimpl<EF_B10G11R11_UFLOAT_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_E5B9G9R9_UFLOAT_PACK32: return impl::convertColor_RTimpl<EF_E5B9G9R9_UFLOAT_PACK32>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_BC1_RGB_UNORM_BLOCK: return impl::convertColor_RTimpl<EF_BC1_RGB_UNORM_BLOCK>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_BC1_RGB_SRGB_BLOCK: return impl::convertColor_RTimpl<EF_BC1_RGB_SRGB_BLOCK>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_BC1_RGBA_UNORM_BLOCK: return impl::convertColor_RTimpl<EF_BC1_RGBA_UNORM_BLOCK>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_BC1_RGBA_SRGB_BLOCK: return impl::convertColor_RTimpl<EF_BC1_RGBA_SRGB_BLOCK>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_BC2_UNORM_BLOCK: return impl::convertColor_RTimpl<EF_BC2_UNORM_BLOCK>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_BC2_SRGB_BLOCK: return impl::convertColor_RTimpl<EF_BC2_SRGB_BLOCK>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_BC3_UNORM_BLOCK: return impl::convertColor_RTimpl<EF_BC3_UNORM_BLOCK>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_BC3_SRGB_BLOCK: return impl::convertColor_RTimpl<EF_BC3_SRGB_BLOCK>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_G8_B8_R8_3PLANE_420_UNORM: return impl::convertColor_RTimpl<EF_G8_B8_R8_3PLANE_420_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_G8_B8R8_2PLANE_420_UNORM: return impl::convertColor_RTimpl<EF_G8_B8R8_2PLANE_420_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_G8_B8_R8_3PLANE_422_UNORM: return impl::convertColor_RTimpl<EF_G8_B8_R8_3PLANE_422_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_G8_B8R8_2PLANE_422_UNORM: return impl::convertColor_RTimpl<EF_G8_B8R8_2PLANE_422_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    case EF_G8_B8_R8_3PLANE_444_UNORM: return impl::convertColor_RTimpl<EF_G8_B8_R8_3PLANE_444_UNORM>(_dfmt, _srcPix, _dstPix, _pixOrBlockCnt, _imgSize,swizzle);
    }
}


}
}
