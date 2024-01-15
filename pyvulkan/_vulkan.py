from __future__ import annotations

from enum import (
    Enum,
    Flag
)
from typing import (
    Any,
    Dict,
    Union  # For annotating pNext parameter.
)

from ._vulkan_ffi import ffi


# Determines whether a nonzero success code will raise an exception.
NONZERO_SUCCESS_CODES_AS_EXCEPTIONS: bool = False


# Annotate the result as Any, so that we can access api exports
# directly by names without upsetting type checker.
def load_vulkan() -> Any:
    lib_names = (
        "libvulkan.so.1",
        "vulkan-1.dll",
        "libvulkan.dylib"
    )
    for name in lib_names:
        try:
            return ffi.dlopen(name)
        except OSError:
            continue
    raise OSError("Cannot find Vulkan SDK version.")


class VulkanCData:
    __slots__ = ("_ptr",)

    def __init__(
        self,
        ptr: Any
    ) -> None:
        super().__init__()
        self._ptr: Any = ptr


class VulkanException(Exception):
    __slots__ = ()


lib = load_vulkan()

RETURN_CODES: Dict[int, str] = {}


# End of preamble

def VK_MAKE_VIDEO_STD_VERSION(
    major: int,
    minor: int,
    patch: int,
) -> int:
    return (major << 22) | (minor << 12) | patch

VK_STD_VULKAN_VIDEO_CODEC_H264_DECODE_API_VERSION_1_0_0 = VK_MAKE_VIDEO_STD_VERSION(1, 0, 0)

VK_STD_VULKAN_VIDEO_CODEC_H264_ENCODE_API_VERSION_1_0_0 = VK_MAKE_VIDEO_STD_VERSION(1, 0, 0)

VK_STD_VULKAN_VIDEO_CODEC_H265_DECODE_API_VERSION_1_0_0 = VK_MAKE_VIDEO_STD_VERSION(1, 0, 0)

VK_STD_VULKAN_VIDEO_CODEC_H265_ENCODE_API_VERSION_1_0_0 = VK_MAKE_VIDEO_STD_VERSION(1, 0, 0)

class StdVideoH264ChromaFormatIdc(Enum):
    STD_VIDEO_H264_CHROMA_FORMAT_IDC_MONOCHROME = 0
    STD_VIDEO_H264_CHROMA_FORMAT_IDC_420 = 1
    STD_VIDEO_H264_CHROMA_FORMAT_IDC_422 = 2
    STD_VIDEO_H264_CHROMA_FORMAT_IDC_444 = 3
    STD_VIDEO_H264_CHROMA_FORMAT_IDC_INVALID = 2147483647

class StdVideoH264ProfileIdc(Enum):
    STD_VIDEO_H264_PROFILE_IDC_BASELINE = 66
    STD_VIDEO_H264_PROFILE_IDC_MAIN = 77
    STD_VIDEO_H264_PROFILE_IDC_HIGH = 100
    STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE = 244
    STD_VIDEO_H264_PROFILE_IDC_INVALID = 2147483647

class StdVideoH264LevelIdc(Enum):
    STD_VIDEO_H264_LEVEL_IDC_1_0 = 0
    STD_VIDEO_H264_LEVEL_IDC_1_1 = 1
    STD_VIDEO_H264_LEVEL_IDC_1_2 = 2
    STD_VIDEO_H264_LEVEL_IDC_1_3 = 3
    STD_VIDEO_H264_LEVEL_IDC_2_0 = 4
    STD_VIDEO_H264_LEVEL_IDC_2_1 = 5
    STD_VIDEO_H264_LEVEL_IDC_2_2 = 6
    STD_VIDEO_H264_LEVEL_IDC_3_0 = 7
    STD_VIDEO_H264_LEVEL_IDC_3_1 = 8
    STD_VIDEO_H264_LEVEL_IDC_3_2 = 9
    STD_VIDEO_H264_LEVEL_IDC_4_0 = 10
    STD_VIDEO_H264_LEVEL_IDC_4_1 = 11
    STD_VIDEO_H264_LEVEL_IDC_4_2 = 12
    STD_VIDEO_H264_LEVEL_IDC_5_0 = 13
    STD_VIDEO_H264_LEVEL_IDC_5_1 = 14
    STD_VIDEO_H264_LEVEL_IDC_5_2 = 15
    STD_VIDEO_H264_LEVEL_IDC_6_0 = 16
    STD_VIDEO_H264_LEVEL_IDC_6_1 = 17
    STD_VIDEO_H264_LEVEL_IDC_6_2 = 18
    STD_VIDEO_H264_LEVEL_IDC_INVALID = 2147483647

class StdVideoH264PocType(Enum):
    STD_VIDEO_H264_POC_TYPE_0 = 0
    STD_VIDEO_H264_POC_TYPE_1 = 1
    STD_VIDEO_H264_POC_TYPE_2 = 2
    STD_VIDEO_H264_POC_TYPE_INVALID = 2147483647

class StdVideoH264AspectRatioIdc(Enum):
    STD_VIDEO_H264_ASPECT_RATIO_IDC_UNSPECIFIED = 0
    STD_VIDEO_H264_ASPECT_RATIO_IDC_SQUARE = 1
    STD_VIDEO_H264_ASPECT_RATIO_IDC_12_11 = 2
    STD_VIDEO_H264_ASPECT_RATIO_IDC_10_11 = 3
    STD_VIDEO_H264_ASPECT_RATIO_IDC_16_11 = 4
    STD_VIDEO_H264_ASPECT_RATIO_IDC_40_33 = 5
    STD_VIDEO_H264_ASPECT_RATIO_IDC_24_11 = 6
    STD_VIDEO_H264_ASPECT_RATIO_IDC_20_11 = 7
    STD_VIDEO_H264_ASPECT_RATIO_IDC_32_11 = 8
    STD_VIDEO_H264_ASPECT_RATIO_IDC_80_33 = 9
    STD_VIDEO_H264_ASPECT_RATIO_IDC_18_11 = 10
    STD_VIDEO_H264_ASPECT_RATIO_IDC_15_11 = 11
    STD_VIDEO_H264_ASPECT_RATIO_IDC_64_33 = 12
    STD_VIDEO_H264_ASPECT_RATIO_IDC_160_99 = 13
    STD_VIDEO_H264_ASPECT_RATIO_IDC_4_3 = 14
    STD_VIDEO_H264_ASPECT_RATIO_IDC_3_2 = 15
    STD_VIDEO_H264_ASPECT_RATIO_IDC_2_1 = 16
    STD_VIDEO_H264_ASPECT_RATIO_IDC_EXTENDED_SAR = 255
    STD_VIDEO_H264_ASPECT_RATIO_IDC_INVALID = 2147483647

class StdVideoH264WeightedBipredIdc(Enum):
    STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_DEFAULT = 0
    STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_EXPLICIT = 1
    STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_IMPLICIT = 2
    STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_INVALID = 2147483647

class StdVideoH264ModificationOfPicNumsIdc(Enum):
    STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_SUBTRACT = 0
    STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_ADD = 1
    STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_LONG_TERM = 2
    STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_END = 3
    STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_INVALID = 2147483647

class StdVideoH264MemMgmtControlOp(Enum):
    STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_END = 0
    STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_SHORT_TERM = 1
    STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_LONG_TERM = 2
    STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_LONG_TERM = 3
    STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_SET_MAX_LONG_TERM_INDEX = 4
    STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_ALL = 5
    STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_CURRENT_AS_LONG_TERM = 6
    STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_INVALID = 2147483647

class StdVideoH264CabacInitIdc(Enum):
    STD_VIDEO_H264_CABAC_INIT_IDC_0 = 0
    STD_VIDEO_H264_CABAC_INIT_IDC_1 = 1
    STD_VIDEO_H264_CABAC_INIT_IDC_2 = 2
    STD_VIDEO_H264_CABAC_INIT_IDC_INVALID = 2147483647

class StdVideoH264DisableDeblockingFilterIdc(Enum):
    STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_DISABLED = 0
    STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_ENABLED = 1
    STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_PARTIAL = 2
    STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_INVALID = 2147483647

class StdVideoH264SliceType(Enum):
    STD_VIDEO_H264_SLICE_TYPE_P = 0
    STD_VIDEO_H264_SLICE_TYPE_B = 1
    STD_VIDEO_H264_SLICE_TYPE_I = 2
    STD_VIDEO_H264_SLICE_TYPE_INVALID = 2147483647

class StdVideoH264PictureType(Enum):
    STD_VIDEO_H264_PICTURE_TYPE_P = 0
    STD_VIDEO_H264_PICTURE_TYPE_B = 1
    STD_VIDEO_H264_PICTURE_TYPE_I = 2
    STD_VIDEO_H264_PICTURE_TYPE_IDR = 5
    STD_VIDEO_H264_PICTURE_TYPE_INVALID = 2147483647

class StdVideoH264NonVclNaluType(Enum):
    STD_VIDEO_H264_NON_VCL_NALU_TYPE_SPS = 0
    STD_VIDEO_H264_NON_VCL_NALU_TYPE_PPS = 1
    STD_VIDEO_H264_NON_VCL_NALU_TYPE_AUD = 2
    STD_VIDEO_H264_NON_VCL_NALU_TYPE_PREFIX = 3
    STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_SEQUENCE = 4
    STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_STREAM = 5
    STD_VIDEO_H264_NON_VCL_NALU_TYPE_PRECODED = 6
    STD_VIDEO_H264_NON_VCL_NALU_TYPE_INVALID = 2147483647

class StdVideoDecodeH264FieldOrderCount(Enum):
    STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_TOP = 0
    STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_BOTTOM = 1
    STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_INVALID = 2147483647

class StdVideoH265ChromaFormatIdc(Enum):
    STD_VIDEO_H265_CHROMA_FORMAT_IDC_MONOCHROME = 0
    STD_VIDEO_H265_CHROMA_FORMAT_IDC_420 = 1
    STD_VIDEO_H265_CHROMA_FORMAT_IDC_422 = 2
    STD_VIDEO_H265_CHROMA_FORMAT_IDC_444 = 3
    STD_VIDEO_H265_CHROMA_FORMAT_IDC_INVALID = 2147483647

class StdVideoH265ProfileIdc(Enum):
    STD_VIDEO_H265_PROFILE_IDC_MAIN = 1
    STD_VIDEO_H265_PROFILE_IDC_MAIN_10 = 2
    STD_VIDEO_H265_PROFILE_IDC_MAIN_STILL_PICTURE = 3
    STD_VIDEO_H265_PROFILE_IDC_FORMAT_RANGE_EXTENSIONS = 4
    STD_VIDEO_H265_PROFILE_IDC_SCC_EXTENSIONS = 9
    STD_VIDEO_H265_PROFILE_IDC_INVALID = 2147483647

class StdVideoH265LevelIdc(Enum):
    STD_VIDEO_H265_LEVEL_IDC_1_0 = 0
    STD_VIDEO_H265_LEVEL_IDC_2_0 = 1
    STD_VIDEO_H265_LEVEL_IDC_2_1 = 2
    STD_VIDEO_H265_LEVEL_IDC_3_0 = 3
    STD_VIDEO_H265_LEVEL_IDC_3_1 = 4
    STD_VIDEO_H265_LEVEL_IDC_4_0 = 5
    STD_VIDEO_H265_LEVEL_IDC_4_1 = 6
    STD_VIDEO_H265_LEVEL_IDC_5_0 = 7
    STD_VIDEO_H265_LEVEL_IDC_5_1 = 8
    STD_VIDEO_H265_LEVEL_IDC_5_2 = 9
    STD_VIDEO_H265_LEVEL_IDC_6_0 = 10
    STD_VIDEO_H265_LEVEL_IDC_6_1 = 11
    STD_VIDEO_H265_LEVEL_IDC_6_2 = 12
    STD_VIDEO_H265_LEVEL_IDC_INVALID = 2147483647

class StdVideoH265SliceType(Enum):
    STD_VIDEO_H265_SLICE_TYPE_B = 0
    STD_VIDEO_H265_SLICE_TYPE_P = 1
    STD_VIDEO_H265_SLICE_TYPE_I = 2
    STD_VIDEO_H265_SLICE_TYPE_INVALID = 2147483647

class StdVideoH265PictureType(Enum):
    STD_VIDEO_H265_PICTURE_TYPE_P = 0
    STD_VIDEO_H265_PICTURE_TYPE_B = 1
    STD_VIDEO_H265_PICTURE_TYPE_I = 2
    STD_VIDEO_H265_PICTURE_TYPE_IDR = 3
    STD_VIDEO_H265_PICTURE_TYPE_INVALID = 2147483647

class StdVideoH265AspectRatioIdc(Enum):
    STD_VIDEO_H265_ASPECT_RATIO_IDC_UNSPECIFIED = 0
    STD_VIDEO_H265_ASPECT_RATIO_IDC_SQUARE = 1
    STD_VIDEO_H265_ASPECT_RATIO_IDC_12_11 = 2
    STD_VIDEO_H265_ASPECT_RATIO_IDC_10_11 = 3
    STD_VIDEO_H265_ASPECT_RATIO_IDC_16_11 = 4
    STD_VIDEO_H265_ASPECT_RATIO_IDC_40_33 = 5
    STD_VIDEO_H265_ASPECT_RATIO_IDC_24_11 = 6
    STD_VIDEO_H265_ASPECT_RATIO_IDC_20_11 = 7
    STD_VIDEO_H265_ASPECT_RATIO_IDC_32_11 = 8
    STD_VIDEO_H265_ASPECT_RATIO_IDC_80_33 = 9
    STD_VIDEO_H265_ASPECT_RATIO_IDC_18_11 = 10
    STD_VIDEO_H265_ASPECT_RATIO_IDC_15_11 = 11
    STD_VIDEO_H265_ASPECT_RATIO_IDC_64_33 = 12
    STD_VIDEO_H265_ASPECT_RATIO_IDC_160_99 = 13
    STD_VIDEO_H265_ASPECT_RATIO_IDC_4_3 = 14
    STD_VIDEO_H265_ASPECT_RATIO_IDC_3_2 = 15
    STD_VIDEO_H265_ASPECT_RATIO_IDC_2_1 = 16
    STD_VIDEO_H265_ASPECT_RATIO_IDC_EXTENDED_SAR = 255
    STD_VIDEO_H265_ASPECT_RATIO_IDC_INVALID = 2147483647

STD_VIDEO_H264_CPB_CNT_LIST_SIZE = 32

STD_VIDEO_H264_SCALING_LIST_4X4_NUM_LISTS = 6

STD_VIDEO_H264_SCALING_LIST_4X4_NUM_ELEMENTS = 16

STD_VIDEO_H264_SCALING_LIST_8X8_NUM_LISTS = 6

STD_VIDEO_H264_SCALING_LIST_8X8_NUM_ELEMENTS = 64

STD_VIDEO_H264_MAX_NUM_LIST_REF = 32

STD_VIDEO_H264_MAX_CHROMA_PLANES = 2

STD_VIDEO_H264_NO_REFERENCE_PICTURE = 0xFF

VK_STD_VULKAN_VIDEO_CODEC_H264_DECODE_SPEC_VERSION = VK_STD_VULKAN_VIDEO_CODEC_H264_DECODE_API_VERSION_1_0_0

VK_STD_VULKAN_VIDEO_CODEC_H264_DECODE_EXTENSION_NAME = "VK_STD_vulkan_video_codec_h264_decode"

STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_LIST_SIZE = 2

VK_STD_VULKAN_VIDEO_CODEC_H264_ENCODE_SPEC_VERSION = VK_STD_VULKAN_VIDEO_CODEC_H264_ENCODE_API_VERSION_1_0_0

VK_STD_VULKAN_VIDEO_CODEC_H264_ENCODE_EXTENSION_NAME = "VK_STD_vulkan_video_codec_h264_encode"

STD_VIDEO_H265_CPB_CNT_LIST_SIZE = 32

STD_VIDEO_H265_SUBLAYERS_LIST_SIZE = 7

STD_VIDEO_H265_SCALING_LIST_4X4_NUM_LISTS = 6

STD_VIDEO_H265_SCALING_LIST_4X4_NUM_ELEMENTS = 16

STD_VIDEO_H265_SCALING_LIST_8X8_NUM_LISTS = 6

STD_VIDEO_H265_SCALING_LIST_8X8_NUM_ELEMENTS = 64

STD_VIDEO_H265_SCALING_LIST_16X16_NUM_LISTS = 6

STD_VIDEO_H265_SCALING_LIST_16X16_NUM_ELEMENTS = 64

STD_VIDEO_H265_SCALING_LIST_32X32_NUM_LISTS = 2

STD_VIDEO_H265_SCALING_LIST_32X32_NUM_ELEMENTS = 64

STD_VIDEO_H265_CHROMA_QP_OFFSET_LIST_SIZE = 6

STD_VIDEO_H265_CHROMA_QP_OFFSET_TILE_COLS_LIST_SIZE = 19

STD_VIDEO_H265_CHROMA_QP_OFFSET_TILE_ROWS_LIST_SIZE = 21

STD_VIDEO_H265_PREDICTOR_PALETTE_COMPONENTS_LIST_SIZE = 3

STD_VIDEO_H265_PREDICTOR_PALETTE_COMP_ENTRIES_LIST_SIZE = 128

STD_VIDEO_H265_MAX_NUM_LIST_REF = 15

STD_VIDEO_H265_MAX_CHROMA_PLANES = 2

STD_VIDEO_H265_MAX_SHORT_TERM_REF_PIC_SETS = 64

STD_VIDEO_H265_MAX_DPB_SIZE = 16

STD_VIDEO_H265_MAX_LONG_TERM_REF_PICS_SPS = 32

STD_VIDEO_H265_MAX_LONG_TERM_PICS = 16

STD_VIDEO_H265_MAX_DELTA_POC = 48

STD_VIDEO_H265_NO_REFERENCE_PICTURE = 0xFF

VK_STD_VULKAN_VIDEO_CODEC_H265_DECODE_SPEC_VERSION = VK_STD_VULKAN_VIDEO_CODEC_H265_DECODE_API_VERSION_1_0_0

VK_STD_VULKAN_VIDEO_CODEC_H265_DECODE_EXTENSION_NAME = "VK_STD_vulkan_video_codec_h265_decode"

STD_VIDEO_DECODE_H265_REF_PIC_SET_LIST_SIZE = 8

VK_STD_VULKAN_VIDEO_CODEC_H265_ENCODE_SPEC_VERSION = VK_STD_VULKAN_VIDEO_CODEC_H265_ENCODE_API_VERSION_1_0_0

VK_STD_VULKAN_VIDEO_CODEC_H265_ENCODE_EXTENSION_NAME = "VK_STD_vulkan_video_codec_h265_encode"

def VK_MAKE_VERSION(
    major: int,
    minor: int,
    patch: int,
) -> int:
    return (major << 22) | (minor << 12) | patch

def VK_VERSION_MAJOR(
    version: int,
) -> int:
    return version >> 22

def VK_VERSION_MINOR(
    version: int,
) -> int:
    return (version >> 12) & 0x3FF

def VK_VERSION_PATCH(
    version: int,
) -> int:
    return version & 0xFFF

def VK_MAKE_API_VERSION(
    variant: int,
    major: int,
    minor: int,
    patch: int,
) -> int:
    return (variant << 29) | (major << 22) | (minor << 12) | patch

def VK_API_VERSION_VARIANT(
    version: int,
) -> int:
    return version >> 29

def VK_API_VERSION_MAJOR(
    version: int,
) -> int:
    return (version >> 22) & 0x7F

def VK_API_VERSION_MINOR(
    version: int,
) -> int:
    return (version >> 12) & 0x3FF

def VK_API_VERSION_PATCH(
    version: int,
) -> int:
    return version & 0xFFF

VK_API_VERSION = None

VK_API_VERSION_1_0 = VK_MAKE_API_VERSION(0, 1, 0, 0)

VK_API_VERSION_1_1 = VK_MAKE_API_VERSION(0, 1, 1, 0)

VK_API_VERSION_1_2 = VK_MAKE_API_VERSION(0, 1, 2, 0)

VK_API_VERSION_1_3 = VK_MAKE_API_VERSION(0, 1, 3, 0)

VKSC_API_VERSION_1_0 = VK_MAKE_API_VERSION(VKSC_API_VARIANT, 1, 0, 0)

VK_HEADER_VERSION = 275

VKSC_API_VARIANT = 1

VK_HEADER_VERSION_COMPLETE = VK_MAKE_API_VERSION(0, 1, 3, VK_HEADER_VERSION)

VK_DEFINE_HANDLE = None

VK_USE_64_BIT_PTR_DEFINES = None

VK_NULL_HANDLE = None

VK_DEFINE_NON_DISPATCHABLE_HANDLE = None

VkSampleMask = int

VkBool32 = int

VkFlags = int

VkFlags64 = int

VkDeviceSize = int

VkDeviceAddress = int

VkFramebufferCreateFlags = VkFramebufferCreateFlagBits

class VkQueryPoolCreateFlags(Flag):
    pass

VkRenderPassCreateFlags = VkRenderPassCreateFlagBits

VkSamplerCreateFlags = VkSamplerCreateFlagBits

VkPipelineLayoutCreateFlags = VkPipelineLayoutCreateFlagBits

VkPipelineCacheCreateFlags = VkPipelineCacheCreateFlagBits

VkPipelineDepthStencilStateCreateFlags = VkPipelineDepthStencilStateCreateFlagBits

class VkPipelineDynamicStateCreateFlags(Flag):
    pass

VkPipelineColorBlendStateCreateFlags = VkPipelineColorBlendStateCreateFlagBits

class VkPipelineMultisampleStateCreateFlags(Flag):
    pass

class VkPipelineRasterizationStateCreateFlags(Flag):
    pass

class VkPipelineViewportStateCreateFlags(Flag):
    pass

class VkPipelineTessellationStateCreateFlags(Flag):
    pass

class VkPipelineInputAssemblyStateCreateFlags(Flag):
    pass

class VkPipelineVertexInputStateCreateFlags(Flag):
    pass

VkPipelineShaderStageCreateFlags = VkPipelineShaderStageCreateFlagBits

VkDescriptorSetLayoutCreateFlags = VkDescriptorSetLayoutCreateFlagBits

class VkBufferViewCreateFlags(Flag):
    pass

VkInstanceCreateFlags = VkInstanceCreateFlagBits

class VkDeviceCreateFlags(Flag):
    pass

VkDeviceQueueCreateFlags = VkDeviceQueueCreateFlagBits

VkQueueFlags = VkQueueFlagBits

VkMemoryPropertyFlags = VkMemoryPropertyFlagBits

VkMemoryHeapFlags = VkMemoryHeapFlagBits

VkAccessFlags = VkAccessFlagBits

VkBufferUsageFlags = VkBufferUsageFlagBits

VkBufferCreateFlags = VkBufferCreateFlagBits

VkShaderStageFlags = VkShaderStageFlagBits

VkImageUsageFlags = VkImageUsageFlagBits

VkImageCreateFlags = VkImageCreateFlagBits

VkImageViewCreateFlags = VkImageViewCreateFlagBits

VkPipelineCreateFlags = VkPipelineCreateFlagBits

VkColorComponentFlags = VkColorComponentFlagBits

VkFenceCreateFlags = VkFenceCreateFlagBits

class VkSemaphoreCreateFlags(Flag):
    pass

VkFormatFeatureFlags = VkFormatFeatureFlagBits

VkQueryControlFlags = VkQueryControlFlagBits

VkQueryResultFlags = VkQueryResultFlagBits

class VkShaderModuleCreateFlags(Flag):
    pass

VkEventCreateFlags = VkEventCreateFlagBits

VkCommandPoolCreateFlags = VkCommandPoolCreateFlagBits

VkCommandPoolResetFlags = VkCommandPoolResetFlagBits

VkCommandBufferResetFlags = VkCommandBufferResetFlagBits

VkCommandBufferUsageFlags = VkCommandBufferUsageFlagBits

VkQueryPipelineStatisticFlags = VkQueryPipelineStatisticFlagBits

class VkMemoryMapFlags(Flag):
    pass

class VkMemoryUnmapFlagsKHR(Flag):
    pass

VkImageAspectFlags = VkImageAspectFlagBits

VkSparseMemoryBindFlags = VkSparseMemoryBindFlagBits

VkSparseImageFormatFlags = VkSparseImageFormatFlagBits

VkSubpassDescriptionFlags = VkSubpassDescriptionFlagBits

VkPipelineStageFlags = VkPipelineStageFlagBits

VkSampleCountFlags = VkSampleCountFlagBits

VkAttachmentDescriptionFlags = VkAttachmentDescriptionFlagBits

VkStencilFaceFlags = VkStencilFaceFlagBits

VkCullModeFlags = VkCullModeFlagBits

VkDescriptorPoolCreateFlags = VkDescriptorPoolCreateFlagBits

class VkDescriptorPoolResetFlags(Flag):
    pass

VkDependencyFlags = VkDependencyFlagBits

VkSubgroupFeatureFlags = VkSubgroupFeatureFlagBits

VkIndirectCommandsLayoutUsageFlagsNV = VkIndirectCommandsLayoutUsageFlagBitsNV

VkIndirectStateFlagsNV = VkIndirectStateFlagBitsNV

VkGeometryFlagsKHR = VkGeometryFlagBitsKHR


VkGeometryInstanceFlagsKHR = VkGeometryInstanceFlagBitsKHR


VkBuildAccelerationStructureFlagsKHR = VkBuildAccelerationStructureFlagBitsKHR


class VkPrivateDataSlotCreateFlags(Flag):
    pass


VkAccelerationStructureCreateFlagsKHR = VkAccelerationStructureCreateFlagBitsKHR

class VkDescriptorUpdateTemplateCreateFlags(Flag):
    pass


VkPipelineCreationFeedbackFlags = VkPipelineCreationFeedbackFlagBits


VkPerformanceCounterDescriptionFlagsKHR = VkPerformanceCounterDescriptionFlagBitsKHR

VkAcquireProfilingLockFlagsKHR = VkAcquireProfilingLockFlagBitsKHR

VkSemaphoreWaitFlags = VkSemaphoreWaitFlagBits


VkPipelineCompilerControlFlagsAMD = VkPipelineCompilerControlFlagBitsAMD

VkShaderCorePropertiesFlagsAMD = VkShaderCorePropertiesFlagBitsAMD

VkDeviceDiagnosticsConfigFlagsNV = VkDeviceDiagnosticsConfigFlagBitsNV

VkRefreshObjectFlagsKHR = VkRefreshObjectFlagBitsKHR

VkAccessFlags2 = VkAccessFlagBits2


VkPipelineStageFlags2 = VkPipelineStageFlagBits2


class VkAccelerationStructureMotionInfoFlagsNV(Flag):
    pass

class VkAccelerationStructureMotionInstanceFlagsNV(Flag):
    pass

VkFormatFeatureFlags2 = VkFormatFeatureFlagBits2


VkRenderingFlags = VkRenderingFlagBits

VkMemoryDecompressionMethodFlagsNV = VkMemoryDecompressionMethodFlagBitsNV


VkBuildMicromapFlagsEXT = VkBuildMicromapFlagBitsEXT

VkMicromapCreateFlagsEXT = VkMicromapCreateFlagBitsEXT

class VkDirectDriverLoadingFlagsLUNARG(Flag):
    pass

VkPipelineCreateFlags2KHR = VkPipelineCreateFlagBits2KHR

VkBufferUsageFlags2KHR = VkBufferUsageFlagBits2KHR

VkCompositeAlphaFlagsKHR = VkCompositeAlphaFlagBitsKHR

VkDisplayPlaneAlphaFlagsKHR = VkDisplayPlaneAlphaFlagBitsKHR

VkSurfaceTransformFlagsKHR = VkSurfaceTransformFlagBitsKHR

VkSwapchainCreateFlagsKHR = VkSwapchainCreateFlagBitsKHR

class VkDisplayModeCreateFlagsKHR(Flag):
    pass

class VkDisplaySurfaceCreateFlagsKHR(Flag):
    pass

class VkAndroidSurfaceCreateFlagsKHR(Flag):
    pass

class VkViSurfaceCreateFlagsNN(Flag):
    pass

class VkWaylandSurfaceCreateFlagsKHR(Flag):
    pass

class VkWin32SurfaceCreateFlagsKHR(Flag):
    pass

class VkXlibSurfaceCreateFlagsKHR(Flag):
    pass

class VkXcbSurfaceCreateFlagsKHR(Flag):
    pass

class VkDirectFBSurfaceCreateFlagsEXT(Flag):
    pass

class VkIOSSurfaceCreateFlagsMVK(Flag):
    pass

class VkMacOSSurfaceCreateFlagsMVK(Flag):
    pass

class VkMetalSurfaceCreateFlagsEXT(Flag):
    pass

class VkImagePipeSurfaceCreateFlagsFUCHSIA(Flag):
    pass

class VkStreamDescriptorSurfaceCreateFlagsGGP(Flag):
    pass

class VkHeadlessSurfaceCreateFlagsEXT(Flag):
    pass

class VkScreenSurfaceCreateFlagsQNX(Flag):
    pass

VkPeerMemoryFeatureFlags = VkPeerMemoryFeatureFlagBits


VkMemoryAllocateFlags = VkMemoryAllocateFlagBits


VkDeviceGroupPresentModeFlagsKHR = VkDeviceGroupPresentModeFlagBitsKHR

VkDebugReportFlagsEXT = VkDebugReportFlagBitsEXT

class VkCommandPoolTrimFlags(Flag):
    pass


VkExternalMemoryHandleTypeFlagsNV = VkExternalMemoryHandleTypeFlagBitsNV

VkExternalMemoryFeatureFlagsNV = VkExternalMemoryFeatureFlagBitsNV

VkExternalMemoryHandleTypeFlags = VkExternalMemoryHandleTypeFlagBits


VkExternalMemoryFeatureFlags = VkExternalMemoryFeatureFlagBits


VkExternalSemaphoreHandleTypeFlags = VkExternalSemaphoreHandleTypeFlagBits


VkExternalSemaphoreFeatureFlags = VkExternalSemaphoreFeatureFlagBits


VkSemaphoreImportFlags = VkSemaphoreImportFlagBits


VkExternalFenceHandleTypeFlags = VkExternalFenceHandleTypeFlagBits


VkExternalFenceFeatureFlags = VkExternalFenceFeatureFlagBits


VkFenceImportFlags = VkFenceImportFlagBits


VkSurfaceCounterFlagsEXT = VkSurfaceCounterFlagBitsEXT

class VkPipelineViewportSwizzleStateCreateFlagsNV(Flag):
    pass

class VkPipelineDiscardRectangleStateCreateFlagsEXT(Flag):
    pass

class VkPipelineCoverageToColorStateCreateFlagsNV(Flag):
    pass

class VkPipelineCoverageModulationStateCreateFlagsNV(Flag):
    pass

class VkPipelineCoverageReductionStateCreateFlagsNV(Flag):
    pass

class VkValidationCacheCreateFlagsEXT(Flag):
    pass

VkDebugUtilsMessageSeverityFlagsEXT = VkDebugUtilsMessageSeverityFlagBitsEXT

VkDebugUtilsMessageTypeFlagsEXT = VkDebugUtilsMessageTypeFlagBitsEXT

class VkDebugUtilsMessengerCreateFlagsEXT(Flag):
    pass

class VkDebugUtilsMessengerCallbackDataFlagsEXT(Flag):
    pass

class VkDeviceMemoryReportFlagsEXT(Flag):
    pass

class VkPipelineRasterizationConservativeStateCreateFlagsEXT(Flag):
    pass

VkDescriptorBindingFlags = VkDescriptorBindingFlagBits


VkConditionalRenderingFlagsEXT = VkConditionalRenderingFlagBitsEXT

VkResolveModeFlags = VkResolveModeFlagBits


class VkPipelineRasterizationStateStreamCreateFlagsEXT(Flag):
    pass

class VkPipelineRasterizationDepthClipStateCreateFlagsEXT(Flag):
    pass

VkSwapchainImageUsageFlagsANDROID = VkSwapchainImageUsageFlagBitsANDROID

VkToolPurposeFlags = VkToolPurposeFlagBits


VkSubmitFlags = VkSubmitFlagBits


class VkImageFormatConstraintsFlagsFUCHSIA(Flag):
    pass

VkHostImageCopyFlagsEXT = VkHostImageCopyFlagBitsEXT

VkImageConstraintsInfoFlagsFUCHSIA = VkImageConstraintsInfoFlagBitsFUCHSIA

VkGraphicsPipelineLibraryFlagsEXT = VkGraphicsPipelineLibraryFlagBitsEXT

VkImageCompressionFlagsEXT = VkImageCompressionFlagBitsEXT

VkImageCompressionFixedRateFlagsEXT = VkImageCompressionFixedRateFlagBitsEXT

VkExportMetalObjectTypeFlagsEXT = VkExportMetalObjectTypeFlagBitsEXT

VkDeviceAddressBindingFlagsEXT = VkDeviceAddressBindingFlagBitsEXT

VkOpticalFlowGridSizeFlagsNV = VkOpticalFlowGridSizeFlagBitsNV

VkOpticalFlowUsageFlagsNV = VkOpticalFlowUsageFlagBitsNV

VkOpticalFlowSessionCreateFlagsNV = VkOpticalFlowSessionCreateFlagBitsNV

VkOpticalFlowExecuteFlagsNV = VkOpticalFlowExecuteFlagBitsNV

VkFrameBoundaryFlagsEXT = VkFrameBoundaryFlagBitsEXT

VkPresentScalingFlagsEXT = VkPresentScalingFlagBitsEXT

VkPresentGravityFlagsEXT = VkPresentGravityFlagBitsEXT

VkShaderCreateFlagsEXT = VkShaderCreateFlagBitsEXT

VkPhysicalDeviceSchedulingControlsFlagsARM = VkPhysicalDeviceSchedulingControlsFlagBitsARM

VkVideoCodecOperationFlagsKHR = VkVideoCodecOperationFlagBitsKHR

VkVideoCapabilityFlagsKHR = VkVideoCapabilityFlagBitsKHR

VkVideoSessionCreateFlagsKHR = VkVideoSessionCreateFlagBitsKHR

class VkVideoSessionParametersCreateFlagsKHR(Flag):
    pass

class VkVideoBeginCodingFlagsKHR(Flag):
    pass

class VkVideoEndCodingFlagsKHR(Flag):
    pass

VkVideoCodingControlFlagsKHR = VkVideoCodingControlFlagBitsKHR

VkVideoDecodeUsageFlagsKHR = VkVideoDecodeUsageFlagBitsKHR

VkVideoDecodeCapabilityFlagsKHR = VkVideoDecodeCapabilityFlagBitsKHR

class VkVideoDecodeFlagsKHR(Flag):
    pass

VkVideoDecodeH264PictureLayoutFlagsKHR = VkVideoDecodeH264PictureLayoutFlagBitsKHR

class VkVideoEncodeFlagsKHR(Flag):
    pass

VkVideoEncodeUsageFlagsKHR = VkVideoEncodeUsageFlagBitsKHR

VkVideoEncodeContentFlagsKHR = VkVideoEncodeContentFlagBitsKHR

VkVideoEncodeCapabilityFlagsKHR = VkVideoEncodeCapabilityFlagBitsKHR

VkVideoEncodeFeedbackFlagsKHR = VkVideoEncodeFeedbackFlagBitsKHR

class VkVideoEncodeRateControlFlagsKHR(Flag):
    pass

VkVideoEncodeRateControlModeFlagsKHR = VkVideoEncodeRateControlModeFlagBitsKHR

VkVideoChromaSubsamplingFlagsKHR = VkVideoChromaSubsamplingFlagBitsKHR

VkVideoComponentBitDepthFlagsKHR = VkVideoComponentBitDepthFlagBitsKHR

VkVideoEncodeH264CapabilityFlagsKHR = VkVideoEncodeH264CapabilityFlagBitsKHR

VkVideoEncodeH264StdFlagsKHR = VkVideoEncodeH264StdFlagBitsKHR

VkVideoEncodeH264RateControlFlagsKHR = VkVideoEncodeH264RateControlFlagBitsKHR

VkVideoEncodeH265CapabilityFlagsKHR = VkVideoEncodeH265CapabilityFlagBitsKHR

VkVideoEncodeH265StdFlagsKHR = VkVideoEncodeH265StdFlagBitsKHR

VkVideoEncodeH265RateControlFlagsKHR = VkVideoEncodeH265RateControlFlagBitsKHR

VkVideoEncodeH265CtbSizeFlagsKHR = VkVideoEncodeH265CtbSizeFlagBitsKHR

VkVideoEncodeH265TransformBlockSizeFlagsKHR = VkVideoEncodeH265TransformBlockSizeFlagBitsKHR

class VkInstance(VulkanCData):
    __slots__ = ()

class VkPhysicalDevice(VulkanCData):
    __slots__ = ()

class VkDevice(VulkanCData):
    __slots__ = ()

class VkQueue(VulkanCData):
    __slots__ = ()

class VkCommandBuffer(VulkanCData):
    __slots__ = ()

class VkDeviceMemory(VulkanCData):
    __slots__ = ()

class VkCommandPool(VulkanCData):
    __slots__ = ()

class VkBuffer(VulkanCData):
    __slots__ = ()

class VkBufferView(VulkanCData):
    __slots__ = ()

class VkImage(VulkanCData):
    __slots__ = ()

class VkImageView(VulkanCData):
    __slots__ = ()

class VkShaderModule(VulkanCData):
    __slots__ = ()

class VkPipeline(VulkanCData):
    __slots__ = ()

class VkPipelineLayout(VulkanCData):
    __slots__ = ()

class VkSampler(VulkanCData):
    __slots__ = ()

class VkDescriptorSet(VulkanCData):
    __slots__ = ()

class VkDescriptorSetLayout(VulkanCData):
    __slots__ = ()

class VkDescriptorPool(VulkanCData):
    __slots__ = ()

class VkFence(VulkanCData):
    __slots__ = ()

class VkSemaphore(VulkanCData):
    __slots__ = ()

class VkEvent(VulkanCData):
    __slots__ = ()

class VkQueryPool(VulkanCData):
    __slots__ = ()

class VkFramebuffer(VulkanCData):
    __slots__ = ()

class VkRenderPass(VulkanCData):
    __slots__ = ()

class VkPipelineCache(VulkanCData):
    __slots__ = ()

class VkIndirectCommandsLayoutNV(VulkanCData):
    __slots__ = ()

class VkDescriptorUpdateTemplate(VulkanCData):
    __slots__ = ()


class VkSamplerYcbcrConversion(VulkanCData):
    __slots__ = ()


class VkValidationCacheEXT(VulkanCData):
    __slots__ = ()

class VkAccelerationStructureKHR(VulkanCData):
    __slots__ = ()

class VkAccelerationStructureNV(VulkanCData):
    __slots__ = ()

class VkPerformanceConfigurationINTEL(VulkanCData):
    __slots__ = ()

class VkBufferCollectionFUCHSIA(VulkanCData):
    __slots__ = ()

class VkDeferredOperationKHR(VulkanCData):
    __slots__ = ()

class VkPrivateDataSlot(VulkanCData):
    __slots__ = ()


class VkCuModuleNVX(VulkanCData):
    __slots__ = ()

class VkCuFunctionNVX(VulkanCData):
    __slots__ = ()

class VkOpticalFlowSessionNV(VulkanCData):
    __slots__ = ()

class VkMicromapEXT(VulkanCData):
    __slots__ = ()

class VkShaderEXT(VulkanCData):
    __slots__ = ()

class VkDisplayKHR(VulkanCData):
    __slots__ = ()

class VkDisplayModeKHR(VulkanCData):
    __slots__ = ()

class VkSurfaceKHR(VulkanCData):
    __slots__ = ()

class VkSwapchainKHR(VulkanCData):
    __slots__ = ()

class VkDebugReportCallbackEXT(VulkanCData):
    __slots__ = ()

class VkDebugUtilsMessengerEXT(VulkanCData):
    __slots__ = ()

class VkVideoSessionKHR(VulkanCData):
    __slots__ = ()

class VkVideoSessionParametersKHR(VulkanCData):
    __slots__ = ()

class VkSemaphoreSciSyncPoolNV(VulkanCData):
    __slots__ = ()

class VkAttachmentLoadOp(Enum):
    VK_ATTACHMENT_LOAD_OP_LOAD = 0
    VK_ATTACHMENT_LOAD_OP_CLEAR = 1
    VK_ATTACHMENT_LOAD_OP_DONT_CARE = 2
    VK_ATTACHMENT_LOAD_OP_NONE_EXT = 1000400000

class VkAttachmentStoreOp(Enum):
    VK_ATTACHMENT_STORE_OP_STORE = 0
    VK_ATTACHMENT_STORE_OP_DONT_CARE = 1
    VK_ATTACHMENT_STORE_OP_NONE = 1000301000
    VK_ATTACHMENT_STORE_OP_NONE_KHR = VK_ATTACHMENT_STORE_OP_NONE
    VK_ATTACHMENT_STORE_OP_NONE_QCOM = VK_ATTACHMENT_STORE_OP_NONE
    VK_ATTACHMENT_STORE_OP_NONE_EXT = VK_ATTACHMENT_STORE_OP_NONE

class VkBlendFactor(Enum):
    VK_BLEND_FACTOR_ZERO = 0
    VK_BLEND_FACTOR_ONE = 1
    VK_BLEND_FACTOR_SRC_COLOR = 2
    VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR = 3
    VK_BLEND_FACTOR_DST_COLOR = 4
    VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR = 5
    VK_BLEND_FACTOR_SRC_ALPHA = 6
    VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA = 7
    VK_BLEND_FACTOR_DST_ALPHA = 8
    VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA = 9
    VK_BLEND_FACTOR_CONSTANT_COLOR = 10
    VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR = 11
    VK_BLEND_FACTOR_CONSTANT_ALPHA = 12
    VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA = 13
    VK_BLEND_FACTOR_SRC_ALPHA_SATURATE = 14
    VK_BLEND_FACTOR_SRC1_COLOR = 15
    VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR = 16
    VK_BLEND_FACTOR_SRC1_ALPHA = 17
    VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA = 18

class VkBlendOp(Enum):
    VK_BLEND_OP_ADD = 0
    VK_BLEND_OP_SUBTRACT = 1
    VK_BLEND_OP_REVERSE_SUBTRACT = 2
    VK_BLEND_OP_MIN = 3
    VK_BLEND_OP_MAX = 4
    VK_BLEND_OP_ZERO_EXT = 1000148000
    VK_BLEND_OP_SRC_EXT = 1000148001
    VK_BLEND_OP_DST_EXT = 1000148002
    VK_BLEND_OP_SRC_OVER_EXT = 1000148003
    VK_BLEND_OP_DST_OVER_EXT = 1000148004
    VK_BLEND_OP_SRC_IN_EXT = 1000148005
    VK_BLEND_OP_DST_IN_EXT = 1000148006
    VK_BLEND_OP_SRC_OUT_EXT = 1000148007
    VK_BLEND_OP_DST_OUT_EXT = 1000148008
    VK_BLEND_OP_SRC_ATOP_EXT = 1000148009
    VK_BLEND_OP_DST_ATOP_EXT = 1000148010
    VK_BLEND_OP_XOR_EXT = 1000148011
    VK_BLEND_OP_MULTIPLY_EXT = 1000148012
    VK_BLEND_OP_SCREEN_EXT = 1000148013
    VK_BLEND_OP_OVERLAY_EXT = 1000148014
    VK_BLEND_OP_DARKEN_EXT = 1000148015
    VK_BLEND_OP_LIGHTEN_EXT = 1000148016
    VK_BLEND_OP_COLORDODGE_EXT = 1000148017
    VK_BLEND_OP_COLORBURN_EXT = 1000148018
    VK_BLEND_OP_HARDLIGHT_EXT = 1000148019
    VK_BLEND_OP_SOFTLIGHT_EXT = 1000148020
    VK_BLEND_OP_DIFFERENCE_EXT = 1000148021
    VK_BLEND_OP_EXCLUSION_EXT = 1000148022
    VK_BLEND_OP_INVERT_EXT = 1000148023
    VK_BLEND_OP_INVERT_RGB_EXT = 1000148024
    VK_BLEND_OP_LINEARDODGE_EXT = 1000148025
    VK_BLEND_OP_LINEARBURN_EXT = 1000148026
    VK_BLEND_OP_VIVIDLIGHT_EXT = 1000148027
    VK_BLEND_OP_LINEARLIGHT_EXT = 1000148028
    VK_BLEND_OP_PINLIGHT_EXT = 1000148029
    VK_BLEND_OP_HARDMIX_EXT = 1000148030
    VK_BLEND_OP_HSL_HUE_EXT = 1000148031
    VK_BLEND_OP_HSL_SATURATION_EXT = 1000148032
    VK_BLEND_OP_HSL_COLOR_EXT = 1000148033
    VK_BLEND_OP_HSL_LUMINOSITY_EXT = 1000148034
    VK_BLEND_OP_PLUS_EXT = 1000148035
    VK_BLEND_OP_PLUS_CLAMPED_EXT = 1000148036
    VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT = 1000148037
    VK_BLEND_OP_PLUS_DARKER_EXT = 1000148038
    VK_BLEND_OP_MINUS_EXT = 1000148039
    VK_BLEND_OP_MINUS_CLAMPED_EXT = 1000148040
    VK_BLEND_OP_CONTRAST_EXT = 1000148041
    VK_BLEND_OP_INVERT_OVG_EXT = 1000148042
    VK_BLEND_OP_RED_EXT = 1000148043
    VK_BLEND_OP_GREEN_EXT = 1000148044
    VK_BLEND_OP_BLUE_EXT = 1000148045

class VkBorderColor(Enum):
    VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK = 0
    VK_BORDER_COLOR_INT_TRANSPARENT_BLACK = 1
    VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK = 2
    VK_BORDER_COLOR_INT_OPAQUE_BLACK = 3
    VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE = 4
    VK_BORDER_COLOR_INT_OPAQUE_WHITE = 5
    VK_BORDER_COLOR_FLOAT_CUSTOM_EXT = 1000287003
    VK_BORDER_COLOR_INT_CUSTOM_EXT = 1000287004

class VkFramebufferCreateFlagBits(Flag):
    VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT = 0x00000001
    VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT_KHR = VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT

class VkQueryPoolCreateFlagBits(Enum):
    pass

class VkRenderPassCreateFlagBits(Flag):
    VK_RENDER_PASS_CREATE_RESERVED_0_BIT_KHR = 0x00000001
    VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM = 0x00000002

class VkSamplerCreateFlagBits(Flag):
    VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT = 0x00000001
    VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT = 0x00000002
    VK_SAMPLER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT = 0x00000008
    VK_SAMPLER_CREATE_NON_SEAMLESS_CUBE_MAP_BIT_EXT = 0x00000004
    VK_SAMPLER_CREATE_IMAGE_PROCESSING_BIT_QCOM = 0x00000010

class VkPipelineCacheHeaderVersion(Enum):
    VK_PIPELINE_CACHE_HEADER_VERSION_ONE = 1

class VkPipelineCacheCreateFlagBits(Flag):
    VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT = 0x00000001
    VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT_EXT = VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT

class VkPipelineShaderStageCreateFlagBits(Flag):
    VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT = 0x00000001
    VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT = 0x00000002
    VK_PIPELINE_SHADER_STAGE_CREATE_RESERVED_3_BIT_KHR = 0x00000008
    VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT = VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT
    VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT = VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT

class VkDescriptorSetLayoutCreateFlagBits(Flag):
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT = 0x00000002
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR = 0x00000001
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_DESCRIPTOR_BUFFER_BIT_EXT = 0x00000010
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_EMBEDDED_IMMUTABLE_SAMPLERS_BIT_EXT = 0x00000020
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_RESERVED_3_BIT_AMD = 0x00000008
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_INDIRECT_BINDABLE_BIT_NV = 0x00000080
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_EXT = 0x00000004
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_PER_STAGE_BIT_NV = 0x00000040
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT_EXT = VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT
    VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_VALVE = VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_EXT

class VkInstanceCreateFlagBits(Flag):
    VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR = 0x00000001

class VkDeviceQueueCreateFlagBits(Flag):
    VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT = 0x00000001
    VK_DEVICE_QUEUE_CREATE_RESERVED_1_BIT_QCOM = 0x00000002

class VkBufferCreateFlagBits(Flag):
    VK_BUFFER_CREATE_SPARSE_BINDING_BIT = 0x00000001
    VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT = 0x00000002
    VK_BUFFER_CREATE_SPARSE_ALIASED_BIT = 0x00000004
    VK_BUFFER_CREATE_PROTECTED_BIT = 0x00000008
    VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT = 0x00000010
    VK_BUFFER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT = 0x00000020
    VK_BUFFER_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR = 0x00000040
    VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT
    VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR = VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT

class VkBufferUsageFlagBits(Flag):
    VK_BUFFER_USAGE_TRANSFER_SRC_BIT = 0x00000001
    VK_BUFFER_USAGE_TRANSFER_DST_BIT = 0x00000002
    VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT = 0x00000004
    VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT = 0x00000008
    VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT = 0x00000010
    VK_BUFFER_USAGE_STORAGE_BUFFER_BIT = 0x00000020
    VK_BUFFER_USAGE_INDEX_BUFFER_BIT = 0x00000040
    VK_BUFFER_USAGE_VERTEX_BUFFER_BIT = 0x00000080
    VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT = 0x00000100
    VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT = 0x00020000
    VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR = 0x00002000
    VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR = 0x00004000
    VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT = 0x00000800
    VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT = 0x00001000
    VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT = 0x00000200
    VK_BUFFER_USAGE_EXECUTION_GRAPH_SCRATCH_BIT_AMDX = 0x02000000
    VK_BUFFER_USAGE_RESERVED_28_BIT_KHR = 0x10000000
    VK_BUFFER_USAGE_RESERVED_29_BIT_KHR = 0x20000000
    VK_BUFFER_USAGE_RESERVED_30_BIT_KHR = 0x40000000
    VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR = 0x00080000
    VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR = 0x00100000
    VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR = 0x00000400
    VK_BUFFER_USAGE_VIDEO_ENCODE_DST_BIT_KHR = 0x00008000
    VK_BUFFER_USAGE_VIDEO_ENCODE_SRC_BIT_KHR = 0x00010000
    VK_BUFFER_USAGE_RESERVED_27_BIT_QCOM = 0x08000000
    VK_BUFFER_USAGE_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT = 0x00200000
    VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT = 0x00400000
    VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT = 0x04000000
    VK_BUFFER_USAGE_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT = 0x00800000
    VK_BUFFER_USAGE_MICROMAP_STORAGE_BIT_EXT = 0x01000000
    VK_BUFFER_USAGE_RAY_TRACING_BIT_NV = VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR
    VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_EXT = VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT
    VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_KHR = VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT

class VkColorComponentFlagBits(Flag):
    VK_COLOR_COMPONENT_R_BIT = 0x00000001
    VK_COLOR_COMPONENT_G_BIT = 0x00000002
    VK_COLOR_COMPONENT_B_BIT = 0x00000004
    VK_COLOR_COMPONENT_A_BIT = 0x00000008

class VkComponentSwizzle(Enum):
    VK_COMPONENT_SWIZZLE_IDENTITY = 0
    VK_COMPONENT_SWIZZLE_ZERO = 1
    VK_COMPONENT_SWIZZLE_ONE = 2
    VK_COMPONENT_SWIZZLE_R = 3
    VK_COMPONENT_SWIZZLE_G = 4
    VK_COMPONENT_SWIZZLE_B = 5
    VK_COMPONENT_SWIZZLE_A = 6

class VkCommandPoolCreateFlagBits(Flag):
    VK_COMMAND_POOL_CREATE_TRANSIENT_BIT = 0x00000001
    VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT = 0x00000002
    VK_COMMAND_POOL_CREATE_PROTECTED_BIT = 0x00000004

class VkCommandPoolResetFlagBits(Flag):
    VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT = 0x00000001
    VK_COMMAND_POOL_RESET_RESERVED_1_BIT_COREAVI = 0x00000002

class VkCommandBufferResetFlagBits(Flag):
    VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT = 0x00000001

class VkCommandBufferLevel(Enum):
    VK_COMMAND_BUFFER_LEVEL_PRIMARY = 0
    VK_COMMAND_BUFFER_LEVEL_SECONDARY = 1

class VkCommandBufferUsageFlagBits(Flag):
    VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT = 0x00000001
    VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT = 0x00000002
    VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT = 0x00000004

class VkCompareOp(Enum):
    VK_COMPARE_OP_NEVER = 0
    VK_COMPARE_OP_LESS = 1
    VK_COMPARE_OP_EQUAL = 2
    VK_COMPARE_OP_LESS_OR_EQUAL = 3
    VK_COMPARE_OP_GREATER = 4
    VK_COMPARE_OP_NOT_EQUAL = 5
    VK_COMPARE_OP_GREATER_OR_EQUAL = 6
    VK_COMPARE_OP_ALWAYS = 7

class VkCullModeFlagBits(Flag):
    VK_CULL_MODE_NONE = 0x00000000
    VK_CULL_MODE_FRONT_BIT = 0x00000001
    VK_CULL_MODE_BACK_BIT = 0x00000002
    VK_CULL_MODE_FRONT_AND_BACK = 0x00000003

class VkDescriptorType(Enum):
    VK_DESCRIPTOR_TYPE_SAMPLER = 0
    VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER = 1
    VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE = 2
    VK_DESCRIPTOR_TYPE_STORAGE_IMAGE = 3
    VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER = 4
    VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER = 5
    VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER = 6
    VK_DESCRIPTOR_TYPE_STORAGE_BUFFER = 7
    VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC = 8
    VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC = 9
    VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT = 10
    VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK = 1000138000
    VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR = 1000150000
    VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV = 1000165000
    VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM = 1000440000
    VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM = 1000440001
    VK_DESCRIPTOR_TYPE_MUTABLE_EXT = 1000351000
    VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT = VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK
    VK_DESCRIPTOR_TYPE_MUTABLE_VALVE = VK_DESCRIPTOR_TYPE_MUTABLE_EXT

class VkDeviceCreateFlagBits(Enum):
    pass

class VkDynamicState(Enum):
    VK_DYNAMIC_STATE_VIEWPORT = 0
    VK_DYNAMIC_STATE_SCISSOR = 1
    VK_DYNAMIC_STATE_LINE_WIDTH = 2
    VK_DYNAMIC_STATE_DEPTH_BIAS = 3
    VK_DYNAMIC_STATE_BLEND_CONSTANTS = 4
    VK_DYNAMIC_STATE_DEPTH_BOUNDS = 5
    VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK = 6
    VK_DYNAMIC_STATE_STENCIL_WRITE_MASK = 7
    VK_DYNAMIC_STATE_STENCIL_REFERENCE = 8
    VK_DYNAMIC_STATE_CULL_MODE = 1000267000
    VK_DYNAMIC_STATE_FRONT_FACE = 1000267001
    VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY = 1000267002
    VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT = 1000267003
    VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT = 1000267004
    VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE = 1000267005
    VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE = 1000267006
    VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE = 1000267007
    VK_DYNAMIC_STATE_DEPTH_COMPARE_OP = 1000267008
    VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE = 1000267009
    VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE = 1000267010
    VK_DYNAMIC_STATE_STENCIL_OP = 1000267011
    VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE = 1000377001
    VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE = 1000377002
    VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE = 1000377004
    VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV = 1000087000
    VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT = 1000099000
    VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT = 1000099001
    VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT = 1000099002
    VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT = 1000143000
    VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR = 1000347000
    VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV = 1000164004
    VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV = 1000164006
    VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_ENABLE_NV = 1000205000
    VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV = 1000205001
    VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR = 1000226000
    VK_DYNAMIC_STATE_LINE_STIPPLE_EXT = 1000259000
    VK_DYNAMIC_STATE_VERTEX_INPUT_EXT = 1000352000
    VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT = 1000377000
    VK_DYNAMIC_STATE_LOGIC_OP_EXT = 1000377003
    VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT = 1000381000
    VK_DYNAMIC_STATE_TESSELLATION_DOMAIN_ORIGIN_EXT = 1000455002
    VK_DYNAMIC_STATE_DEPTH_CLAMP_ENABLE_EXT = 1000455003
    VK_DYNAMIC_STATE_POLYGON_MODE_EXT = 1000455004
    VK_DYNAMIC_STATE_RASTERIZATION_SAMPLES_EXT = 1000455005
    VK_DYNAMIC_STATE_SAMPLE_MASK_EXT = 1000455006
    VK_DYNAMIC_STATE_ALPHA_TO_COVERAGE_ENABLE_EXT = 1000455007
    VK_DYNAMIC_STATE_ALPHA_TO_ONE_ENABLE_EXT = 1000455008
    VK_DYNAMIC_STATE_LOGIC_OP_ENABLE_EXT = 1000455009
    VK_DYNAMIC_STATE_COLOR_BLEND_ENABLE_EXT = 1000455010
    VK_DYNAMIC_STATE_COLOR_BLEND_EQUATION_EXT = 1000455011
    VK_DYNAMIC_STATE_COLOR_WRITE_MASK_EXT = 1000455012
    VK_DYNAMIC_STATE_RASTERIZATION_STREAM_EXT = 1000455013
    VK_DYNAMIC_STATE_CONSERVATIVE_RASTERIZATION_MODE_EXT = 1000455014
    VK_DYNAMIC_STATE_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT = 1000455015
    VK_DYNAMIC_STATE_DEPTH_CLIP_ENABLE_EXT = 1000455016
    VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_ENABLE_EXT = 1000455017
    VK_DYNAMIC_STATE_COLOR_BLEND_ADVANCED_EXT = 1000455018
    VK_DYNAMIC_STATE_PROVOKING_VERTEX_MODE_EXT = 1000455019
    VK_DYNAMIC_STATE_LINE_RASTERIZATION_MODE_EXT = 1000455020
    VK_DYNAMIC_STATE_LINE_STIPPLE_ENABLE_EXT = 1000455021
    VK_DYNAMIC_STATE_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT = 1000455022
    VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_ENABLE_NV = 1000455023
    VK_DYNAMIC_STATE_VIEWPORT_SWIZZLE_NV = 1000455024
    VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_ENABLE_NV = 1000455025
    VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_LOCATION_NV = 1000455026
    VK_DYNAMIC_STATE_COVERAGE_MODULATION_MODE_NV = 1000455027
    VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_ENABLE_NV = 1000455028
    VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_NV = 1000455029
    VK_DYNAMIC_STATE_SHADING_RATE_IMAGE_ENABLE_NV = 1000455030
    VK_DYNAMIC_STATE_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV = 1000455031
    VK_DYNAMIC_STATE_COVERAGE_REDUCTION_MODE_NV = 1000455032
    VK_DYNAMIC_STATE_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT = 1000524000
    VK_DYNAMIC_STATE_CULL_MODE_EXT = VK_DYNAMIC_STATE_CULL_MODE
    VK_DYNAMIC_STATE_FRONT_FACE_EXT = VK_DYNAMIC_STATE_FRONT_FACE
    VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY_EXT = VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY
    VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT_EXT = VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT
    VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT_EXT = VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT
    VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT = VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE
    VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE_EXT = VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE
    VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE_EXT = VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE
    VK_DYNAMIC_STATE_DEPTH_COMPARE_OP_EXT = VK_DYNAMIC_STATE_DEPTH_COMPARE_OP
    VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE_EXT = VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE
    VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE_EXT = VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE
    VK_DYNAMIC_STATE_STENCIL_OP_EXT = VK_DYNAMIC_STATE_STENCIL_OP
    VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE_EXT = VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE
    VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE_EXT = VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE
    VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE_EXT = VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE

class VkFenceCreateFlagBits(Flag):
    VK_FENCE_CREATE_SIGNALED_BIT = 0x00000001

class VkPolygonMode(Enum):
    VK_POLYGON_MODE_FILL = 0
    VK_POLYGON_MODE_LINE = 1
    VK_POLYGON_MODE_POINT = 2
    VK_POLYGON_MODE_FILL_RECTANGLE_NV = 1000153000

class VkFormat(Enum):
    VK_FORMAT_UNDEFINED = 0
    VK_FORMAT_R4G4_UNORM_PACK8 = 1
    VK_FORMAT_R4G4B4A4_UNORM_PACK16 = 2
    VK_FORMAT_B4G4R4A4_UNORM_PACK16 = 3
    VK_FORMAT_R5G6B5_UNORM_PACK16 = 4
    VK_FORMAT_B5G6R5_UNORM_PACK16 = 5
    VK_FORMAT_R5G5B5A1_UNORM_PACK16 = 6
    VK_FORMAT_B5G5R5A1_UNORM_PACK16 = 7
    VK_FORMAT_A1R5G5B5_UNORM_PACK16 = 8
    VK_FORMAT_R8_UNORM = 9
    VK_FORMAT_R8_SNORM = 10
    VK_FORMAT_R8_USCALED = 11
    VK_FORMAT_R8_SSCALED = 12
    VK_FORMAT_R8_UINT = 13
    VK_FORMAT_R8_SINT = 14
    VK_FORMAT_R8_SRGB = 15
    VK_FORMAT_R8G8_UNORM = 16
    VK_FORMAT_R8G8_SNORM = 17
    VK_FORMAT_R8G8_USCALED = 18
    VK_FORMAT_R8G8_SSCALED = 19
    VK_FORMAT_R8G8_UINT = 20
    VK_FORMAT_R8G8_SINT = 21
    VK_FORMAT_R8G8_SRGB = 22
    VK_FORMAT_R8G8B8_UNORM = 23
    VK_FORMAT_R8G8B8_SNORM = 24
    VK_FORMAT_R8G8B8_USCALED = 25
    VK_FORMAT_R8G8B8_SSCALED = 26
    VK_FORMAT_R8G8B8_UINT = 27
    VK_FORMAT_R8G8B8_SINT = 28
    VK_FORMAT_R8G8B8_SRGB = 29
    VK_FORMAT_B8G8R8_UNORM = 30
    VK_FORMAT_B8G8R8_SNORM = 31
    VK_FORMAT_B8G8R8_USCALED = 32
    VK_FORMAT_B8G8R8_SSCALED = 33
    VK_FORMAT_B8G8R8_UINT = 34
    VK_FORMAT_B8G8R8_SINT = 35
    VK_FORMAT_B8G8R8_SRGB = 36
    VK_FORMAT_R8G8B8A8_UNORM = 37
    VK_FORMAT_R8G8B8A8_SNORM = 38
    VK_FORMAT_R8G8B8A8_USCALED = 39
    VK_FORMAT_R8G8B8A8_SSCALED = 40
    VK_FORMAT_R8G8B8A8_UINT = 41
    VK_FORMAT_R8G8B8A8_SINT = 42
    VK_FORMAT_R8G8B8A8_SRGB = 43
    VK_FORMAT_B8G8R8A8_UNORM = 44
    VK_FORMAT_B8G8R8A8_SNORM = 45
    VK_FORMAT_B8G8R8A8_USCALED = 46
    VK_FORMAT_B8G8R8A8_SSCALED = 47
    VK_FORMAT_B8G8R8A8_UINT = 48
    VK_FORMAT_B8G8R8A8_SINT = 49
    VK_FORMAT_B8G8R8A8_SRGB = 50
    VK_FORMAT_A8B8G8R8_UNORM_PACK32 = 51
    VK_FORMAT_A8B8G8R8_SNORM_PACK32 = 52
    VK_FORMAT_A8B8G8R8_USCALED_PACK32 = 53
    VK_FORMAT_A8B8G8R8_SSCALED_PACK32 = 54
    VK_FORMAT_A8B8G8R8_UINT_PACK32 = 55
    VK_FORMAT_A8B8G8R8_SINT_PACK32 = 56
    VK_FORMAT_A8B8G8R8_SRGB_PACK32 = 57
    VK_FORMAT_A2R10G10B10_UNORM_PACK32 = 58
    VK_FORMAT_A2R10G10B10_SNORM_PACK32 = 59
    VK_FORMAT_A2R10G10B10_USCALED_PACK32 = 60
    VK_FORMAT_A2R10G10B10_SSCALED_PACK32 = 61
    VK_FORMAT_A2R10G10B10_UINT_PACK32 = 62
    VK_FORMAT_A2R10G10B10_SINT_PACK32 = 63
    VK_FORMAT_A2B10G10R10_UNORM_PACK32 = 64
    VK_FORMAT_A2B10G10R10_SNORM_PACK32 = 65
    VK_FORMAT_A2B10G10R10_USCALED_PACK32 = 66
    VK_FORMAT_A2B10G10R10_SSCALED_PACK32 = 67
    VK_FORMAT_A2B10G10R10_UINT_PACK32 = 68
    VK_FORMAT_A2B10G10R10_SINT_PACK32 = 69
    VK_FORMAT_R16_UNORM = 70
    VK_FORMAT_R16_SNORM = 71
    VK_FORMAT_R16_USCALED = 72
    VK_FORMAT_R16_SSCALED = 73
    VK_FORMAT_R16_UINT = 74
    VK_FORMAT_R16_SINT = 75
    VK_FORMAT_R16_SFLOAT = 76
    VK_FORMAT_R16G16_UNORM = 77
    VK_FORMAT_R16G16_SNORM = 78
    VK_FORMAT_R16G16_USCALED = 79
    VK_FORMAT_R16G16_SSCALED = 80
    VK_FORMAT_R16G16_UINT = 81
    VK_FORMAT_R16G16_SINT = 82
    VK_FORMAT_R16G16_SFLOAT = 83
    VK_FORMAT_R16G16B16_UNORM = 84
    VK_FORMAT_R16G16B16_SNORM = 85
    VK_FORMAT_R16G16B16_USCALED = 86
    VK_FORMAT_R16G16B16_SSCALED = 87
    VK_FORMAT_R16G16B16_UINT = 88
    VK_FORMAT_R16G16B16_SINT = 89
    VK_FORMAT_R16G16B16_SFLOAT = 90
    VK_FORMAT_R16G16B16A16_UNORM = 91
    VK_FORMAT_R16G16B16A16_SNORM = 92
    VK_FORMAT_R16G16B16A16_USCALED = 93
    VK_FORMAT_R16G16B16A16_SSCALED = 94
    VK_FORMAT_R16G16B16A16_UINT = 95
    VK_FORMAT_R16G16B16A16_SINT = 96
    VK_FORMAT_R16G16B16A16_SFLOAT = 97
    VK_FORMAT_R32_UINT = 98
    VK_FORMAT_R32_SINT = 99
    VK_FORMAT_R32_SFLOAT = 100
    VK_FORMAT_R32G32_UINT = 101
    VK_FORMAT_R32G32_SINT = 102
    VK_FORMAT_R32G32_SFLOAT = 103
    VK_FORMAT_R32G32B32_UINT = 104
    VK_FORMAT_R32G32B32_SINT = 105
    VK_FORMAT_R32G32B32_SFLOAT = 106
    VK_FORMAT_R32G32B32A32_UINT = 107
    VK_FORMAT_R32G32B32A32_SINT = 108
    VK_FORMAT_R32G32B32A32_SFLOAT = 109
    VK_FORMAT_R64_UINT = 110
    VK_FORMAT_R64_SINT = 111
    VK_FORMAT_R64_SFLOAT = 112
    VK_FORMAT_R64G64_UINT = 113
    VK_FORMAT_R64G64_SINT = 114
    VK_FORMAT_R64G64_SFLOAT = 115
    VK_FORMAT_R64G64B64_UINT = 116
    VK_FORMAT_R64G64B64_SINT = 117
    VK_FORMAT_R64G64B64_SFLOAT = 118
    VK_FORMAT_R64G64B64A64_UINT = 119
    VK_FORMAT_R64G64B64A64_SINT = 120
    VK_FORMAT_R64G64B64A64_SFLOAT = 121
    VK_FORMAT_B10G11R11_UFLOAT_PACK32 = 122
    VK_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123
    VK_FORMAT_D16_UNORM = 124
    VK_FORMAT_X8_D24_UNORM_PACK32 = 125
    VK_FORMAT_D32_SFLOAT = 126
    VK_FORMAT_S8_UINT = 127
    VK_FORMAT_D16_UNORM_S8_UINT = 128
    VK_FORMAT_D24_UNORM_S8_UINT = 129
    VK_FORMAT_D32_SFLOAT_S8_UINT = 130
    VK_FORMAT_BC1_RGB_UNORM_BLOCK = 131
    VK_FORMAT_BC1_RGB_SRGB_BLOCK = 132
    VK_FORMAT_BC1_RGBA_UNORM_BLOCK = 133
    VK_FORMAT_BC1_RGBA_SRGB_BLOCK = 134
    VK_FORMAT_BC2_UNORM_BLOCK = 135
    VK_FORMAT_BC2_SRGB_BLOCK = 136
    VK_FORMAT_BC3_UNORM_BLOCK = 137
    VK_FORMAT_BC3_SRGB_BLOCK = 138
    VK_FORMAT_BC4_UNORM_BLOCK = 139
    VK_FORMAT_BC4_SNORM_BLOCK = 140
    VK_FORMAT_BC5_UNORM_BLOCK = 141
    VK_FORMAT_BC5_SNORM_BLOCK = 142
    VK_FORMAT_BC6H_UFLOAT_BLOCK = 143
    VK_FORMAT_BC6H_SFLOAT_BLOCK = 144
    VK_FORMAT_BC7_UNORM_BLOCK = 145
    VK_FORMAT_BC7_SRGB_BLOCK = 146
    VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147
    VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148
    VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149
    VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150
    VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151
    VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152
    VK_FORMAT_EAC_R11_UNORM_BLOCK = 153
    VK_FORMAT_EAC_R11_SNORM_BLOCK = 154
    VK_FORMAT_EAC_R11G11_UNORM_BLOCK = 155
    VK_FORMAT_EAC_R11G11_SNORM_BLOCK = 156
    VK_FORMAT_ASTC_4x4_UNORM_BLOCK = 157
    VK_FORMAT_ASTC_4x4_SRGB_BLOCK = 158
    VK_FORMAT_ASTC_5x4_UNORM_BLOCK = 159
    VK_FORMAT_ASTC_5x4_SRGB_BLOCK = 160
    VK_FORMAT_ASTC_5x5_UNORM_BLOCK = 161
    VK_FORMAT_ASTC_5x5_SRGB_BLOCK = 162
    VK_FORMAT_ASTC_6x5_UNORM_BLOCK = 163
    VK_FORMAT_ASTC_6x5_SRGB_BLOCK = 164
    VK_FORMAT_ASTC_6x6_UNORM_BLOCK = 165
    VK_FORMAT_ASTC_6x6_SRGB_BLOCK = 166
    VK_FORMAT_ASTC_8x5_UNORM_BLOCK = 167
    VK_FORMAT_ASTC_8x5_SRGB_BLOCK = 168
    VK_FORMAT_ASTC_8x6_UNORM_BLOCK = 169
    VK_FORMAT_ASTC_8x6_SRGB_BLOCK = 170
    VK_FORMAT_ASTC_8x8_UNORM_BLOCK = 171
    VK_FORMAT_ASTC_8x8_SRGB_BLOCK = 172
    VK_FORMAT_ASTC_10x5_UNORM_BLOCK = 173
    VK_FORMAT_ASTC_10x5_SRGB_BLOCK = 174
    VK_FORMAT_ASTC_10x6_UNORM_BLOCK = 175
    VK_FORMAT_ASTC_10x6_SRGB_BLOCK = 176
    VK_FORMAT_ASTC_10x8_UNORM_BLOCK = 177
    VK_FORMAT_ASTC_10x8_SRGB_BLOCK = 178
    VK_FORMAT_ASTC_10x10_UNORM_BLOCK = 179
    VK_FORMAT_ASTC_10x10_SRGB_BLOCK = 180
    VK_FORMAT_ASTC_12x10_UNORM_BLOCK = 181
    VK_FORMAT_ASTC_12x10_SRGB_BLOCK = 182
    VK_FORMAT_ASTC_12x12_UNORM_BLOCK = 183
    VK_FORMAT_ASTC_12x12_SRGB_BLOCK = 184
    VK_FORMAT_G8B8G8R8_422_UNORM = 1000156000
    VK_FORMAT_B8G8R8G8_422_UNORM = 1000156001
    VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM = 1000156002
    VK_FORMAT_G8_B8R8_2PLANE_420_UNORM = 1000156003
    VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM = 1000156004
    VK_FORMAT_G8_B8R8_2PLANE_422_UNORM = 1000156005
    VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM = 1000156006
    VK_FORMAT_R10X6_UNORM_PACK16 = 1000156007
    VK_FORMAT_R10X6G10X6_UNORM_2PACK16 = 1000156008
    VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16 = 1000156009
    VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 = 1000156010
    VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 = 1000156011
    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 = 1000156012
    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 = 1000156013
    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 = 1000156014
    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 = 1000156015
    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 = 1000156016
    VK_FORMAT_R12X4_UNORM_PACK16 = 1000156017
    VK_FORMAT_R12X4G12X4_UNORM_2PACK16 = 1000156018
    VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16 = 1000156019
    VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 = 1000156020
    VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 = 1000156021
    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 = 1000156022
    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 = 1000156023
    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 = 1000156024
    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 = 1000156025
    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 = 1000156026
    VK_FORMAT_G16B16G16R16_422_UNORM = 1000156027
    VK_FORMAT_B16G16R16G16_422_UNORM = 1000156028
    VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM = 1000156029
    VK_FORMAT_G16_B16R16_2PLANE_420_UNORM = 1000156030
    VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM = 1000156031
    VK_FORMAT_G16_B16R16_2PLANE_422_UNORM = 1000156032
    VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM = 1000156033
    VK_FORMAT_G8_B8R8_2PLANE_444_UNORM = 1000330000
    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16 = 1000330001
    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16 = 1000330002
    VK_FORMAT_G16_B16R16_2PLANE_444_UNORM = 1000330003
    VK_FORMAT_A4R4G4B4_UNORM_PACK16 = 1000340000
    VK_FORMAT_A4B4G4R4_UNORM_PACK16 = 1000340001
    VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK = 1000066000
    VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK = 1000066001
    VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK = 1000066002
    VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK = 1000066003
    VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK = 1000066004
    VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK = 1000066005
    VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK = 1000066006
    VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK = 1000066007
    VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK = 1000066008
    VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK = 1000066009
    VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK = 1000066010
    VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK = 1000066011
    VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK = 1000066012
    VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK = 1000066013
    VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG = 1000054000
    VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG = 1000054001
    VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG = 1000054002
    VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG = 1000054003
    VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG = 1000054004
    VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG = 1000054005
    VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG = 1000054006
    VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG = 1000054007
    VK_FORMAT_ASTC_3x3x3_UNORM_BLOCK_EXT = 1000288000
    VK_FORMAT_ASTC_3x3x3_SRGB_BLOCK_EXT = 1000288001
    VK_FORMAT_ASTC_3x3x3_SFLOAT_BLOCK_EXT = 1000288002
    VK_FORMAT_ASTC_4x3x3_UNORM_BLOCK_EXT = 1000288003
    VK_FORMAT_ASTC_4x3x3_SRGB_BLOCK_EXT = 1000288004
    VK_FORMAT_ASTC_4x3x3_SFLOAT_BLOCK_EXT = 1000288005
    VK_FORMAT_ASTC_4x4x3_UNORM_BLOCK_EXT = 1000288006
    VK_FORMAT_ASTC_4x4x3_SRGB_BLOCK_EXT = 1000288007
    VK_FORMAT_ASTC_4x4x3_SFLOAT_BLOCK_EXT = 1000288008
    VK_FORMAT_ASTC_4x4x4_UNORM_BLOCK_EXT = 1000288009
    VK_FORMAT_ASTC_4x4x4_SRGB_BLOCK_EXT = 1000288010
    VK_FORMAT_ASTC_4x4x4_SFLOAT_BLOCK_EXT = 1000288011
    VK_FORMAT_ASTC_5x4x4_UNORM_BLOCK_EXT = 1000288012
    VK_FORMAT_ASTC_5x4x4_SRGB_BLOCK_EXT = 1000288013
    VK_FORMAT_ASTC_5x4x4_SFLOAT_BLOCK_EXT = 1000288014
    VK_FORMAT_ASTC_5x5x4_UNORM_BLOCK_EXT = 1000288015
    VK_FORMAT_ASTC_5x5x4_SRGB_BLOCK_EXT = 1000288016
    VK_FORMAT_ASTC_5x5x4_SFLOAT_BLOCK_EXT = 1000288017
    VK_FORMAT_ASTC_5x5x5_UNORM_BLOCK_EXT = 1000288018
    VK_FORMAT_ASTC_5x5x5_SRGB_BLOCK_EXT = 1000288019
    VK_FORMAT_ASTC_5x5x5_SFLOAT_BLOCK_EXT = 1000288020
    VK_FORMAT_ASTC_6x5x5_UNORM_BLOCK_EXT = 1000288021
    VK_FORMAT_ASTC_6x5x5_SRGB_BLOCK_EXT = 1000288022
    VK_FORMAT_ASTC_6x5x5_SFLOAT_BLOCK_EXT = 1000288023
    VK_FORMAT_ASTC_6x6x5_UNORM_BLOCK_EXT = 1000288024
    VK_FORMAT_ASTC_6x6x5_SRGB_BLOCK_EXT = 1000288025
    VK_FORMAT_ASTC_6x6x5_SFLOAT_BLOCK_EXT = 1000288026
    VK_FORMAT_ASTC_6x6x6_UNORM_BLOCK_EXT = 1000288027
    VK_FORMAT_ASTC_6x6x6_SRGB_BLOCK_EXT = 1000288028
    VK_FORMAT_ASTC_6x6x6_SFLOAT_BLOCK_EXT = 1000288029
    VK_FORMAT_R16G16_S10_5_NV = 1000464000
    VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR = 1000470000
    VK_FORMAT_A8_UNORM_KHR = 1000470001
    VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK
    VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK
    VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK
    VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK
    VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK
    VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK
    VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK
    VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK
    VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK
    VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK
    VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK
    VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK
    VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK
    VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT = VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK
    VK_FORMAT_G8B8G8R8_422_UNORM_KHR = VK_FORMAT_G8B8G8R8_422_UNORM
    VK_FORMAT_B8G8R8G8_422_UNORM_KHR = VK_FORMAT_B8G8R8G8_422_UNORM
    VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR = VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM
    VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR = VK_FORMAT_G8_B8R8_2PLANE_420_UNORM
    VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR = VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM
    VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR = VK_FORMAT_G8_B8R8_2PLANE_422_UNORM
    VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR = VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM
    VK_FORMAT_R10X6_UNORM_PACK16_KHR = VK_FORMAT_R10X6_UNORM_PACK16
    VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR = VK_FORMAT_R10X6G10X6_UNORM_2PACK16
    VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR = VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16
    VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR = VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16
    VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR = VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16
    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16
    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16
    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16
    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16
    VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR = VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16
    VK_FORMAT_R12X4_UNORM_PACK16_KHR = VK_FORMAT_R12X4_UNORM_PACK16
    VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR = VK_FORMAT_R12X4G12X4_UNORM_2PACK16
    VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR = VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16
    VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR = VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16
    VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR = VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16
    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16
    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16
    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16
    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16
    VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR = VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16
    VK_FORMAT_G16B16G16R16_422_UNORM_KHR = VK_FORMAT_G16B16G16R16_422_UNORM
    VK_FORMAT_B16G16R16G16_422_UNORM_KHR = VK_FORMAT_B16G16R16G16_422_UNORM
    VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR = VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM
    VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR = VK_FORMAT_G16_B16R16_2PLANE_420_UNORM
    VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR = VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM
    VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR = VK_FORMAT_G16_B16R16_2PLANE_422_UNORM
    VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR = VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM
    VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT = VK_FORMAT_G8_B8R8_2PLANE_444_UNORM
    VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT = VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16
    VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT = VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16
    VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT = VK_FORMAT_G16_B16R16_2PLANE_444_UNORM
    VK_FORMAT_A4R4G4B4_UNORM_PACK16_EXT = VK_FORMAT_A4R4G4B4_UNORM_PACK16
    VK_FORMAT_A4B4G4R4_UNORM_PACK16_EXT = VK_FORMAT_A4B4G4R4_UNORM_PACK16

class VkFormatFeatureFlagBits(Flag):
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT = 0x00000001
    VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT = 0x00000002
    VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT = 0x00000004
    VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT = 0x00000008
    VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT = 0x00000010
    VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT = 0x00000020
    VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT = 0x00000040
    VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT = 0x00000080
    VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT = 0x00000100
    VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT = 0x00000200
    VK_FORMAT_FEATURE_BLIT_SRC_BIT = 0x00000400
    VK_FORMAT_FEATURE_BLIT_DST_BIT = 0x00000800
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT = 0x00001000
    VK_FORMAT_FEATURE_TRANSFER_SRC_BIT = 0x00004000
    VK_FORMAT_FEATURE_TRANSFER_DST_BIT = 0x00008000
    VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT = 0x00020000
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT = 0x00040000
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT = 0x00080000
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT = 0x00100000
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT = 0x00200000
    VK_FORMAT_FEATURE_DISJOINT_BIT = 0x00400000
    VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT = 0x00800000
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT = 0x00010000
    VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR = 0x02000000
    VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR = 0x04000000
    VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR = 0x20000000
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT = 0x00002000
    VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT = 0x01000000
    VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR = 0x40000000
    VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR = 0x08000000
    VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR = 0x10000000
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT
    VK_FORMAT_FEATURE_TRANSFER_SRC_BIT_KHR = VK_FORMAT_FEATURE_TRANSFER_SRC_BIT
    VK_FORMAT_FEATURE_TRANSFER_DST_BIT_KHR = VK_FORMAT_FEATURE_TRANSFER_DST_BIT
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT = VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT
    VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT_KHR = VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT_KHR = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT_KHR = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT_KHR = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT
    VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT_KHR = VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT
    VK_FORMAT_FEATURE_DISJOINT_BIT_KHR = VK_FORMAT_FEATURE_DISJOINT_BIT
    VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT_KHR = VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT

class VkFrontFace(Enum):
    VK_FRONT_FACE_COUNTER_CLOCKWISE = 0
    VK_FRONT_FACE_CLOCKWISE = 1

class VkImageAspectFlagBits(Flag):
    VK_IMAGE_ASPECT_COLOR_BIT = 0x00000001
    VK_IMAGE_ASPECT_DEPTH_BIT = 0x00000002
    VK_IMAGE_ASPECT_STENCIL_BIT = 0x00000004
    VK_IMAGE_ASPECT_METADATA_BIT = 0x00000008
    VK_IMAGE_ASPECT_PLANE_0_BIT = 0x00000010
    VK_IMAGE_ASPECT_PLANE_1_BIT = 0x00000020
    VK_IMAGE_ASPECT_PLANE_2_BIT = 0x00000040
    VK_IMAGE_ASPECT_NONE = 0x00000000
    VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT = 0x00000080
    VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT = 0x00000100
    VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT = 0x00000200
    VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT = 0x00000400
    VK_IMAGE_ASPECT_PLANE_0_BIT_KHR = VK_IMAGE_ASPECT_PLANE_0_BIT
    VK_IMAGE_ASPECT_PLANE_1_BIT_KHR = VK_IMAGE_ASPECT_PLANE_1_BIT
    VK_IMAGE_ASPECT_PLANE_2_BIT_KHR = VK_IMAGE_ASPECT_PLANE_2_BIT
    VK_IMAGE_ASPECT_NONE_KHR = VK_IMAGE_ASPECT_NONE

class VkImageCreateFlagBits(Flag):
    VK_IMAGE_CREATE_SPARSE_BINDING_BIT = 0x00000001
    VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT = 0x00000002
    VK_IMAGE_CREATE_SPARSE_ALIASED_BIT = 0x00000004
    VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT = 0x00000008
    VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT = 0x00000010
    VK_IMAGE_CREATE_ALIAS_BIT = 0x00000400
    VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT = 0x00000040
    VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT = 0x00000020
    VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT = 0x00000080
    VK_IMAGE_CREATE_EXTENDED_USAGE_BIT = 0x00000100
    VK_IMAGE_CREATE_PROTECTED_BIT = 0x00000800
    VK_IMAGE_CREATE_DISJOINT_BIT = 0x00000200
    VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV = 0x00002000
    VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT = 0x00001000
    VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT = 0x00004000
    VK_IMAGE_CREATE_RESERVED_19_BIT_EXT = 0x00080000
    VK_IMAGE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT = 0x00010000
    VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT = 0x00040000
    VK_IMAGE_CREATE_2D_VIEW_COMPATIBLE_BIT_EXT = 0x00020000
    VK_IMAGE_CREATE_FRAGMENT_DENSITY_MAP_OFFSET_BIT_QCOM = 0x00008000
    VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR = 0x00100000
    VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR = VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT
    VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT_KHR = VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT
    VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR = VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT
    VK_IMAGE_CREATE_EXTENDED_USAGE_BIT_KHR = VK_IMAGE_CREATE_EXTENDED_USAGE_BIT
    VK_IMAGE_CREATE_DISJOINT_BIT_KHR = VK_IMAGE_CREATE_DISJOINT_BIT
    VK_IMAGE_CREATE_ALIAS_BIT_KHR = VK_IMAGE_CREATE_ALIAS_BIT

class VkImageLayout(Enum):
    VK_IMAGE_LAYOUT_UNDEFINED = 0
    VK_IMAGE_LAYOUT_GENERAL = 1
    VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL = 2
    VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL = 3
    VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL = 4
    VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL = 5
    VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL = 6
    VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL = 7
    VK_IMAGE_LAYOUT_PREINITIALIZED = 8
    VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL = 1000117000
    VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL = 1000117001
    VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL = 1000241000
    VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL = 1000241001
    VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL = 1000241002
    VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL = 1000241003
    VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL = 1000314000
    VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL = 1000314001
    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR = 1000001002
    VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR = 1000024000
    VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR = 1000024001
    VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR = 1000024002
    VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR = 1000111000
    VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT = 1000218000
    VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR = 1000164003
    VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR = 1000299000
    VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR = 1000299001
    VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR = 1000299002
    VK_IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT = 1000339000
    VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL
    VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL
    VK_IMAGE_LAYOUT_SHADING_RATE_OPTIMAL_NV = VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR
    VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL_KHR = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL
    VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL_KHR = VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL
    VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL_KHR = VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL
    VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL_KHR = VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL
    VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL_KHR = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL
    VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL_KHR = VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL

class VkImageTiling(Enum):
    VK_IMAGE_TILING_OPTIMAL = 0
    VK_IMAGE_TILING_LINEAR = 1
    VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT = 1000158000

class VkImageType(Enum):
    VK_IMAGE_TYPE_1D = 0
    VK_IMAGE_TYPE_2D = 1
    VK_IMAGE_TYPE_3D = 2

class VkImageUsageFlagBits(Flag):
    VK_IMAGE_USAGE_TRANSFER_SRC_BIT = 0x00000001
    VK_IMAGE_USAGE_TRANSFER_DST_BIT = 0x00000002
    VK_IMAGE_USAGE_SAMPLED_BIT = 0x00000004
    VK_IMAGE_USAGE_STORAGE_BIT = 0x00000008
    VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT = 0x00000010
    VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT = 0x00000020
    VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT = 0x00000040
    VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT = 0x00000080
    VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR = 0x00000400
    VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR = 0x00000800
    VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR = 0x00001000
    VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT = 0x00000200
    VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR = 0x00000100
    VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT = 0x00400000
    VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR = 0x00002000
    VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR = 0x00004000
    VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR = 0x00008000
    VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT = 0x00080000
    VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI = 0x00040000
    VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM = 0x00100000
    VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM = 0x00200000
    VK_IMAGE_USAGE_RESERVED_24_BIT_COREAVI = 0x01000000
    VK_IMAGE_USAGE_RESERVED_23_BIT_EXT = 0x00800000
    VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV = VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR

class VkImageViewCreateFlagBits(Flag):
    VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT = 0x00000001
    VK_IMAGE_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT = 0x00000004
    VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT = 0x00000002

class VkImageViewType(Enum):
    VK_IMAGE_VIEW_TYPE_1D = 0
    VK_IMAGE_VIEW_TYPE_2D = 1
    VK_IMAGE_VIEW_TYPE_3D = 2
    VK_IMAGE_VIEW_TYPE_CUBE = 3
    VK_IMAGE_VIEW_TYPE_1D_ARRAY = 4
    VK_IMAGE_VIEW_TYPE_2D_ARRAY = 5
    VK_IMAGE_VIEW_TYPE_CUBE_ARRAY = 6

class VkSharingMode(Enum):
    VK_SHARING_MODE_EXCLUSIVE = 0
    VK_SHARING_MODE_CONCURRENT = 1

class VkIndexType(Enum):
    VK_INDEX_TYPE_UINT16 = 0
    VK_INDEX_TYPE_UINT32 = 1
    VK_INDEX_TYPE_NONE_KHR = 1000165000
    VK_INDEX_TYPE_UINT8_EXT = 1000265000
    VK_INDEX_TYPE_NONE_NV = VK_INDEX_TYPE_NONE_KHR

class VkLogicOp(Enum):
    VK_LOGIC_OP_CLEAR = 0
    VK_LOGIC_OP_AND = 1
    VK_LOGIC_OP_AND_REVERSE = 2
    VK_LOGIC_OP_COPY = 3
    VK_LOGIC_OP_AND_INVERTED = 4
    VK_LOGIC_OP_NO_OP = 5
    VK_LOGIC_OP_XOR = 6
    VK_LOGIC_OP_OR = 7
    VK_LOGIC_OP_NOR = 8
    VK_LOGIC_OP_EQUIVALENT = 9
    VK_LOGIC_OP_INVERT = 10
    VK_LOGIC_OP_OR_REVERSE = 11
    VK_LOGIC_OP_COPY_INVERTED = 12
    VK_LOGIC_OP_OR_INVERTED = 13
    VK_LOGIC_OP_NAND = 14
    VK_LOGIC_OP_SET = 15

class VkMemoryHeapFlagBits(Flag):
    VK_MEMORY_HEAP_DEVICE_LOCAL_BIT = 0x00000001
    VK_MEMORY_HEAP_MULTI_INSTANCE_BIT = 0x00000002
    VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR = VK_MEMORY_HEAP_MULTI_INSTANCE_BIT

class VkAccessFlagBits(Flag):
    VK_ACCESS_INDIRECT_COMMAND_READ_BIT = 0x00000001
    VK_ACCESS_INDEX_READ_BIT = 0x00000002
    VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT = 0x00000004
    VK_ACCESS_UNIFORM_READ_BIT = 0x00000008
    VK_ACCESS_INPUT_ATTACHMENT_READ_BIT = 0x00000010
    VK_ACCESS_SHADER_READ_BIT = 0x00000020
    VK_ACCESS_SHADER_WRITE_BIT = 0x00000040
    VK_ACCESS_COLOR_ATTACHMENT_READ_BIT = 0x00000080
    VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT = 0x00000100
    VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT = 0x00000200
    VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT = 0x00000400
    VK_ACCESS_TRANSFER_READ_BIT = 0x00000800
    VK_ACCESS_TRANSFER_WRITE_BIT = 0x00001000
    VK_ACCESS_HOST_READ_BIT = 0x00002000
    VK_ACCESS_HOST_WRITE_BIT = 0x00004000
    VK_ACCESS_MEMORY_READ_BIT = 0x00008000
    VK_ACCESS_MEMORY_WRITE_BIT = 0x00010000
    VK_ACCESS_NONE = 0x00000000
    VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT = 0x02000000
    VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT = 0x04000000
    VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT = 0x08000000
    VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT = 0x00100000
    VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT = 0x00080000
    VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR = 0x00200000
    VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR = 0x00400000
    VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT = 0x01000000
    VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR = 0x00800000
    VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV = 0x00020000
    VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV = 0x00040000
    VK_ACCESS_SHADING_RATE_IMAGE_READ_BIT_NV = VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR
    VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_NV = VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR
    VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_NV = VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR
    VK_ACCESS_NONE_KHR = VK_ACCESS_NONE

class VkMemoryPropertyFlagBits(Flag):
    VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT = 0x00000001
    VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT = 0x00000002
    VK_MEMORY_PROPERTY_HOST_COHERENT_BIT = 0x00000004
    VK_MEMORY_PROPERTY_HOST_CACHED_BIT = 0x00000008
    VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT = 0x00000010
    VK_MEMORY_PROPERTY_PROTECTED_BIT = 0x00000020
    VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD = 0x00000040
    VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD = 0x00000080
    VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV = 0x00000100

class VkPhysicalDeviceType(Enum):
    VK_PHYSICAL_DEVICE_TYPE_OTHER = 0
    VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1
    VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU = 2
    VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU = 3
    VK_PHYSICAL_DEVICE_TYPE_CPU = 4

class VkPipelineBindPoint(Enum):
    VK_PIPELINE_BIND_POINT_GRAPHICS = 0
    VK_PIPELINE_BIND_POINT_COMPUTE = 1
    VK_PIPELINE_BIND_POINT_EXECUTION_GRAPH_AMDX = 1000134000
    VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR = 1000165000
    VK_PIPELINE_BIND_POINT_SUBPASS_SHADING_HUAWEI = 1000369003
    VK_PIPELINE_BIND_POINT_RAY_TRACING_NV = VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR

class VkPipelineCreateFlagBits(Flag):
    VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT = 0x00000001
    VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT = 0x00000002
    VK_PIPELINE_CREATE_DERIVATIVE_BIT = 0x00000004
    VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT = 0x00000008
    VK_PIPELINE_CREATE_DISPATCH_BASE_BIT = 0x00000010
    VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT = 0x00000100
    VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT = 0x00000200
    VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR = 0x00200000
    VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT = 0x00400000
    VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR = 0x00004000
    VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR = 0x00008000
    VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR = 0x00010000
    VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR = 0x00020000
    VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR = 0x00001000
    VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR = 0x00002000
    VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR = 0x00080000
    VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV = 0x00000020
    VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR = 0x00000040
    VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR = 0x00000080
    VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV = 0x00040000
    VK_PIPELINE_CREATE_LIBRARY_BIT_KHR = 0x00000800
    VK_PIPELINE_CREATE_DESCRIPTOR_BUFFER_BIT_EXT = 0x20000000
    VK_PIPELINE_CREATE_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT = 0x00800000
    VK_PIPELINE_CREATE_LINK_TIME_OPTIMIZATION_BIT_EXT = 0x00000400
    VK_PIPELINE_CREATE_RAY_TRACING_ALLOW_MOTION_BIT_NV = 0x00100000
    VK_PIPELINE_CREATE_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT = 0x02000000
    VK_PIPELINE_CREATE_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT = 0x04000000
    VK_PIPELINE_CREATE_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT = 0x01000000
    VK_PIPELINE_CREATE_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV = 0x10000000
    VK_PIPELINE_CREATE_NO_PROTECTED_ACCESS_BIT_EXT = 0x08000000
    VK_PIPELINE_CREATE_PROTECTED_ACCESS_ONLY_BIT_EXT = 0x40000000
    VK_PIPELINE_CREATE_DISPATCH_BASE = VK_PIPELINE_CREATE_DISPATCH_BASE_BIT
    VK_PIPELINE_RASTERIZATION_STATE_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR = VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR
    VK_PIPELINE_RASTERIZATION_STATE_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT = VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT
    VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR = VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT
    VK_PIPELINE_CREATE_DISPATCH_BASE_KHR = VK_PIPELINE_CREATE_DISPATCH_BASE
    VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_EXT = VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT
    VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT_EXT = VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT

class VkPrimitiveTopology(Enum):
    VK_PRIMITIVE_TOPOLOGY_POINT_LIST = 0
    VK_PRIMITIVE_TOPOLOGY_LINE_LIST = 1
    VK_PRIMITIVE_TOPOLOGY_LINE_STRIP = 2
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST = 3
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP = 4
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN = 5
    VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY = 6
    VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY = 7
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY = 8
    VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY = 9
    VK_PRIMITIVE_TOPOLOGY_PATCH_LIST = 10

class VkQueryControlFlagBits(Flag):
    VK_QUERY_CONTROL_PRECISE_BIT = 0x00000001

class VkQueryPipelineStatisticFlagBits(Flag):
    VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT = 0x00000001
    VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT = 0x00000002
    VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT = 0x00000004
    VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT = 0x00000008
    VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT = 0x00000010
    VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT = 0x00000020
    VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT = 0x00000040
    VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT = 0x00000080
    VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT = 0x00000100
    VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT = 0x00000200
    VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT = 0x00000400
    VK_QUERY_PIPELINE_STATISTIC_TASK_SHADER_INVOCATIONS_BIT_EXT = 0x00000800
    VK_QUERY_PIPELINE_STATISTIC_MESH_SHADER_INVOCATIONS_BIT_EXT = 0x00001000
    VK_QUERY_PIPELINE_STATISTIC_CLUSTER_CULLING_SHADER_INVOCATIONS_BIT_HUAWEI = 0x00002000

class VkQueryResultFlagBits(Flag):
    VK_QUERY_RESULT_64_BIT = 0x00000001
    VK_QUERY_RESULT_WAIT_BIT = 0x00000002
    VK_QUERY_RESULT_WITH_AVAILABILITY_BIT = 0x00000004
    VK_QUERY_RESULT_PARTIAL_BIT = 0x00000008
    VK_QUERY_RESULT_WITH_STATUS_BIT_KHR = 0x00000010

class VkQueryType(Enum):
    VK_QUERY_TYPE_OCCLUSION = 0
    VK_QUERY_TYPE_PIPELINE_STATISTICS = 1
    VK_QUERY_TYPE_TIMESTAMP = 2
    VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR = 1000023000
    VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT = 1000028004
    VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR = 1000116000
    VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR = 1000150000
    VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR = 1000150001
    VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV = 1000165000
    VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL = 1000210000
    VK_QUERY_TYPE_VIDEO_ENCODE_FEEDBACK_KHR = 1000299000
    VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT = 1000328000
    VK_QUERY_TYPE_PRIMITIVES_GENERATED_EXT = 1000382000
    VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_BOTTOM_LEVEL_POINTERS_KHR = 1000386000
    VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SIZE_KHR = 1000386001
    VK_QUERY_TYPE_MICROMAP_SERIALIZATION_SIZE_EXT = 1000396000
    VK_QUERY_TYPE_MICROMAP_COMPACTED_SIZE_EXT = 1000396001

class VkQueueFlagBits(Flag):
    VK_QUEUE_GRAPHICS_BIT = 0x00000001
    VK_QUEUE_COMPUTE_BIT = 0x00000002
    VK_QUEUE_TRANSFER_BIT = 0x00000004
    VK_QUEUE_SPARSE_BINDING_BIT = 0x00000008
    VK_QUEUE_PROTECTED_BIT = 0x00000010
    VK_QUEUE_VIDEO_DECODE_BIT_KHR = 0x00000020
    VK_QUEUE_RESERVED_9_BIT_EXT = 0x00000200
    VK_QUEUE_VIDEO_ENCODE_BIT_KHR = 0x00000040
    VK_QUEUE_RESERVED_7_BIT_QCOM = 0x00000080
    VK_QUEUE_RESERVED_11_BIT_ARM = 0x00000800
    VK_QUEUE_OPTICAL_FLOW_BIT_NV = 0x00000100
    VK_QUEUE_RESERVED_10_BIT_EXT = 0x00000400

class VkSubpassContents(Enum):
    VK_SUBPASS_CONTENTS_INLINE = 0
    VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS = 1
    VK_SUBPASS_CONTENTS_INLINE_AND_SECONDARY_COMMAND_BUFFERS_EXT = 1000451000

class VkResult(Enum):
    VK_SUCCESS = 0
    VK_NOT_READY = 1
    VK_TIMEOUT = 2
    VK_EVENT_SET = 3
    VK_EVENT_RESET = 4
    VK_INCOMPLETE = 5
    VK_ERROR_OUT_OF_HOST_MEMORY = -1
    VK_ERROR_OUT_OF_DEVICE_MEMORY = -2
    VK_ERROR_INITIALIZATION_FAILED = -3
    VK_ERROR_DEVICE_LOST = -4
    VK_ERROR_MEMORY_MAP_FAILED = -5
    VK_ERROR_LAYER_NOT_PRESENT = -6
    VK_ERROR_EXTENSION_NOT_PRESENT = -7
    VK_ERROR_FEATURE_NOT_PRESENT = -8
    VK_ERROR_INCOMPATIBLE_DRIVER = -9
    VK_ERROR_TOO_MANY_OBJECTS = -10
    VK_ERROR_FORMAT_NOT_SUPPORTED = -11
    VK_ERROR_FRAGMENTED_POOL = -12
    VK_ERROR_UNKNOWN = -13
    VK_ERROR_OUT_OF_POOL_MEMORY = 1000069000
    VK_ERROR_INVALID_EXTERNAL_HANDLE = 1000072003
    VK_ERROR_FRAGMENTATION = 1000161000
    VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS = 1000257000
    VK_PIPELINE_COMPILE_REQUIRED = 1000297000
    VK_ERROR_SURFACE_LOST_KHR = 1000000000
    VK_ERROR_NATIVE_WINDOW_IN_USE_KHR = 1000000001
    VK_SUBOPTIMAL_KHR = 1000001003
    VK_ERROR_OUT_OF_DATE_KHR = 1000001004
    VK_ERROR_INCOMPATIBLE_DISPLAY_KHR = 1000003001
    VK_ERROR_VALIDATION_FAILED_EXT = 1000011001
    VK_ERROR_INVALID_SHADER_NV = 1000012000
    VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR = 1000023000
    VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR = 1000023001
    VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR = 1000023002
    VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR = 1000023003
    VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR = 1000023004
    VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR = 1000023005
    VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT = 1000158000
    VK_ERROR_NOT_PERMITTED_KHR = 1000174001
    VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT = 1000255000
    VK_THREAD_IDLE_KHR = 1000268000
    VK_THREAD_DONE_KHR = 1000268001
    VK_OPERATION_DEFERRED_KHR = 1000268002
    VK_OPERATION_NOT_DEFERRED_KHR = 1000268003
    VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR = 1000299000
    VK_ERROR_COMPRESSION_EXHAUSTED_EXT = 1000338000
    VK_ERROR_INCOMPATIBLE_SHADER_BINARY_EXT = 1000482000
    VK_ERROR_OUT_OF_POOL_MEMORY_KHR = VK_ERROR_OUT_OF_POOL_MEMORY
    VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR = VK_ERROR_INVALID_EXTERNAL_HANDLE
    VK_ERROR_FRAGMENTATION_EXT = VK_ERROR_FRAGMENTATION
    VK_ERROR_NOT_PERMITTED_EXT = VK_ERROR_NOT_PERMITTED_KHR
    VK_ERROR_INVALID_DEVICE_ADDRESS_EXT = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS
    VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS
    VK_PIPELINE_COMPILE_REQUIRED_EXT = VK_PIPELINE_COMPILE_REQUIRED
    VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT = VK_PIPELINE_COMPILE_REQUIRED

class VkShaderStageFlagBits(Flag):
    VK_SHADER_STAGE_VERTEX_BIT = 0x00000001
    VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT = 0x00000002
    VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT = 0x00000004
    VK_SHADER_STAGE_GEOMETRY_BIT = 0x00000008
    VK_SHADER_STAGE_FRAGMENT_BIT = 0x00000010
    VK_SHADER_STAGE_COMPUTE_BIT = 0x00000020
    VK_SHADER_STAGE_ALL_GRAPHICS = 0x0000001F
    VK_SHADER_STAGE_ALL = 0x7FFFFFFF
    VK_SHADER_STAGE_RAYGEN_BIT_KHR = 0x00000100
    VK_SHADER_STAGE_ANY_HIT_BIT_KHR = 0x00000200
    VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR = 0x00000400
    VK_SHADER_STAGE_MISS_BIT_KHR = 0x00000800
    VK_SHADER_STAGE_INTERSECTION_BIT_KHR = 0x00001000
    VK_SHADER_STAGE_CALLABLE_BIT_KHR = 0x00002000
    VK_SHADER_STAGE_TASK_BIT_EXT = 0x00000040
    VK_SHADER_STAGE_MESH_BIT_EXT = 0x00000080
    VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI = 0x00004000
    VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI = 0x00080000
    VK_SHADER_STAGE_RAYGEN_BIT_NV = VK_SHADER_STAGE_RAYGEN_BIT_KHR
    VK_SHADER_STAGE_ANY_HIT_BIT_NV = VK_SHADER_STAGE_ANY_HIT_BIT_KHR
    VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV = VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR
    VK_SHADER_STAGE_MISS_BIT_NV = VK_SHADER_STAGE_MISS_BIT_KHR
    VK_SHADER_STAGE_INTERSECTION_BIT_NV = VK_SHADER_STAGE_INTERSECTION_BIT_KHR
    VK_SHADER_STAGE_CALLABLE_BIT_NV = VK_SHADER_STAGE_CALLABLE_BIT_KHR
    VK_SHADER_STAGE_TASK_BIT_NV = VK_SHADER_STAGE_TASK_BIT_EXT
    VK_SHADER_STAGE_MESH_BIT_NV = VK_SHADER_STAGE_MESH_BIT_EXT

class VkSparseMemoryBindFlagBits(Flag):
    VK_SPARSE_MEMORY_BIND_METADATA_BIT = 0x00000001

class VkStencilFaceFlagBits(Flag):
    VK_STENCIL_FACE_FRONT_BIT = 0x00000001
    VK_STENCIL_FACE_BACK_BIT = 0x00000002
    VK_STENCIL_FACE_FRONT_AND_BACK = 0x00000003
    VK_STENCIL_FRONT_AND_BACK = VK_STENCIL_FACE_FRONT_AND_BACK

class VkStencilOp(Enum):
    VK_STENCIL_OP_KEEP = 0
    VK_STENCIL_OP_ZERO = 1
    VK_STENCIL_OP_REPLACE = 2
    VK_STENCIL_OP_INCREMENT_AND_CLAMP = 3
    VK_STENCIL_OP_DECREMENT_AND_CLAMP = 4
    VK_STENCIL_OP_INVERT = 5
    VK_STENCIL_OP_INCREMENT_AND_WRAP = 6
    VK_STENCIL_OP_DECREMENT_AND_WRAP = 7

class VkStructureType(Enum):
    VK_STRUCTURE_TYPE_APPLICATION_INFO = 0
    VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO = 1
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO = 2
    VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO = 3
    VK_STRUCTURE_TYPE_SUBMIT_INFO = 4
    VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO = 5
    VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE = 6
    VK_STRUCTURE_TYPE_BIND_SPARSE_INFO = 7
    VK_STRUCTURE_TYPE_FENCE_CREATE_INFO = 8
    VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO = 9
    VK_STRUCTURE_TYPE_EVENT_CREATE_INFO = 10
    VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO = 11
    VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO = 12
    VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO = 13
    VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO = 14
    VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO = 15
    VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO = 16
    VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO = 17
    VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO = 18
    VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO = 19
    VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO = 20
    VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO = 21
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO = 22
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO = 23
    VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO = 24
    VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO = 25
    VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO = 26
    VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO = 27
    VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO = 28
    VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO = 29
    VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO = 30
    VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO = 31
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO = 32
    VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO = 33
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO = 34
    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET = 35
    VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET = 36
    VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO = 37
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO = 38
    VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO = 39
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO = 40
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO = 41
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO = 42
    VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO = 43
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER = 44
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER = 45
    VK_STRUCTURE_TYPE_MEMORY_BARRIER = 46
    VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO = 47
    VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO = 48
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES = 1000094000
    VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO = 1000157000
    VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO = 1000157001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES = 1000083000
    VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS = 1000127000
    VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO = 1000127001
    VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO = 1000060000
    VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO = 1000060003
    VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO = 1000060004
    VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO = 1000060005
    VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO = 1000060006
    VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO = 1000060013
    VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO = 1000060014
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES = 1000070000
    VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO = 1000070001
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2 = 1000146000
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2 = 1000146001
    VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2 = 1000146002
    VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2 = 1000146003
    VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2 = 1000146004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 = 1000059000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2 = 1000059001
    VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2 = 1000059002
    VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2 = 1000059003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2 = 1000059004
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2 = 1000059005
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2 = 1000059006
    VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2 = 1000059007
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2 = 1000059008
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES = 1000117000
    VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO = 1000117001
    VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO = 1000117002
    VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO = 1000117003
    VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO = 1000053000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES = 1000053001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES = 1000053002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES = 1000120000
    VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO = 1000145000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES = 1000145001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES = 1000145002
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2 = 1000145003
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO = 1000156000
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO = 1000156001
    VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO = 1000156002
    VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO = 1000156003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES = 1000156004
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES = 1000156005
    VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO = 1000085000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO = 1000071000
    VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES = 1000071001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO = 1000071002
    VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES = 1000071003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES = 1000071004
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO = 1000072000
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO = 1000072001
    VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO = 1000072002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO = 1000112000
    VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES = 1000112001
    VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO = 1000113000
    VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO = 1000077000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO = 1000076000
    VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES = 1000076001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES = 1000168000
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT = 1000168001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES = 1000063000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES = 49
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES = 50
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES = 51
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES = 52
    VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO = 1000147000
    VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2 = 1000109000
    VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2 = 1000109001
    VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2 = 1000109002
    VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2 = 1000109003
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2 = 1000109004
    VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO = 1000109005
    VK_STRUCTURE_TYPE_SUBPASS_END_INFO = 1000109006
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES = 1000177000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES = 1000196000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES = 1000180000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES = 1000082000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES = 1000197000
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO = 1000161000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES = 1000161001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES = 1000161002
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO = 1000161003
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT = 1000161004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES = 1000199000
    VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE = 1000199001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES = 1000221000
    VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO = 1000246000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES = 1000130000
    VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO = 1000130001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES = 1000211000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES = 1000108000
    VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO = 1000108001
    VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO = 1000108002
    VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO = 1000108003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES = 1000253000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES = 1000175000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES = 1000241000
    VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT = 1000241001
    VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT = 1000241002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES = 1000261000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES = 1000207000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES = 1000207001
    VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO = 1000207002
    VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO = 1000207003
    VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO = 1000207004
    VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO = 1000207005
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES = 1000257000
    VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO = 1000244001
    VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO = 1000257002
    VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO = 1000257003
    VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO = 1000257004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES = 53
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES = 54
    VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO = 1000192000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES = 1000215000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES = 1000245000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES = 1000276000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES = 1000295000
    VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO = 1000295001
    VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO = 1000295002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES = 1000297000
    VK_STRUCTURE_TYPE_MEMORY_BARRIER_2 = 1000314000
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2 = 1000314001
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2 = 1000314002
    VK_STRUCTURE_TYPE_DEPENDENCY_INFO = 1000314003
    VK_STRUCTURE_TYPE_SUBMIT_INFO_2 = 1000314004
    VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO = 1000314005
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO = 1000314006
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES = 1000314007
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES = 1000325000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES = 1000335000
    VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2 = 1000337000
    VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2 = 1000337001
    VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2 = 1000337002
    VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2 = 1000337003
    VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2 = 1000337004
    VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2 = 1000337005
    VK_STRUCTURE_TYPE_BUFFER_COPY_2 = 1000337006
    VK_STRUCTURE_TYPE_IMAGE_COPY_2 = 1000337007
    VK_STRUCTURE_TYPE_IMAGE_BLIT_2 = 1000337008
    VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2 = 1000337009
    VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2 = 1000337010
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES = 1000225000
    VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO = 1000225001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES = 1000225002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES = 1000138000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES = 1000138001
    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK = 1000138002
    VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO = 1000138003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES = 1000066000
    VK_STRUCTURE_TYPE_RENDERING_INFO = 1000044000
    VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO = 1000044001
    VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO = 1000044002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES = 1000044003
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO = 1000044004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES = 1000280000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES = 1000280001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES = 1000281001
    VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3 = 1000360000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES = 1000413000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES = 1000413001
    VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS = 1000413002
    VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS = 1000413003
    VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR = 1000001000
    VK_STRUCTURE_TYPE_PRESENT_INFO_KHR = 1000001001
    VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR = 1000060007
    VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR = 1000060008
    VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR = 1000060009
    VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR = 1000060010
    VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR = 1000060011
    VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR = 1000060012
    VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR = 1000002000
    VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR = 1000002001
    VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR = 1000003000
    VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR = 1000004000
    VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR = 1000005000
    VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR = 1000006000
    VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR = 1000008000
    VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR = 1000009000
    VK_STRUCTURE_TYPE_NATIVE_BUFFER_ANDROID = 1000010000
    VK_STRUCTURE_TYPE_SWAPCHAIN_IMAGE_CREATE_INFO_ANDROID = 1000010001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENTATION_PROPERTIES_ANDROID = 1000010002
    VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT = 1000011000
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD = 1000018000
    VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT = 1000022000
    VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT = 1000022001
    VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT = 1000022002
    VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR = 1000023000
    VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR = 1000023001
    VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR = 1000023002
    VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR = 1000023003
    VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR = 1000023004
    VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR = 1000023005
    VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR = 1000023006
    VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR = 1000023007
    VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR = 1000023008
    VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR = 1000023009
    VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR = 1000023010
    VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR = 1000023011
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR = 1000023012
    VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR = 1000023013
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR = 1000023014
    VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR = 1000023015
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR = 1000023016
    VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR = 1000024000
    VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR = 1000024001
    VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR = 1000024002
    VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV = 1000026000
    VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV = 1000026001
    VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV = 1000026002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT = 1000028000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT = 1000028001
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT = 1000028002
    VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX = 1000029000
    VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX = 1000029001
    VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX = 1000029002
    VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX = 1000030000
    VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX = 1000030001
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR = 1000038000
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR = 1000038001
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR = 1000038002
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR = 1000038003
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR = 1000038004
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR = 1000038005
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR = 1000038006
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR = 1000038007
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR = 1000038008
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR = 1000038009
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR = 1000038010
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR = 1000038011
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR = 1000038012
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR = 1000038013
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR = 1000039000
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR = 1000039001
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR = 1000039002
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR = 1000039003
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR = 1000039004
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR = 1000039005
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR = 1000039006
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR = 1000039007
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR = 1000039009
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR = 1000039010
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR = 1000039011
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR = 1000039012
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR = 1000039013
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR = 1000039014
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR = 1000040000
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR = 1000040001
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR = 1000040003
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR = 1000040004
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR = 1000040005
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR = 1000040006
    VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD = 1000041000
    VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR = 1000044006
    VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT = 1000044007
    VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD = 1000044008
    VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX = 1000044009
    VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP = 1000049000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV = 1000050000
    VK_STRUCTURE_TYPE_PRIVATE_VENDOR_INFO_PLACEHOLDER_OFFSET_0_NV = 1000051000
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV = 1000056000
    VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV = 1000056001
    VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV = 1000057000
    VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV = 1000057001
    VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV = 1000058000
    VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT = 1000061000
    VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN = 1000062000
    VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT = 1000067000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT = 1000067001
    VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT = 1000068000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT = 1000068001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT = 1000068002
    VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR = 1000073000
    VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR = 1000073001
    VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR = 1000073002
    VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR = 1000073003
    VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR = 1000074000
    VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR = 1000074001
    VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR = 1000074002
    VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR = 1000075000
    VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR = 1000078000
    VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR = 1000078001
    VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR = 1000078002
    VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR = 1000078003
    VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR = 1000079000
    VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR = 1000079001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR = 1000080000
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT = 1000081000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT = 1000081001
    VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT = 1000081002
    VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR = 1000084000
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV = 1000087000
    VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT = 1000090000
    VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT = 1000091000
    VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT = 1000091001
    VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT = 1000091002
    VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT = 1000091003
    VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE = 1000092000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX = 1000097000
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV = 1000098000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT = 1000099000
    VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT = 1000099001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT = 1000101000
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT = 1000101001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT = 1000102000
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT = 1000102001
    VK_STRUCTURE_TYPE_HDR_METADATA_EXT = 1000105000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG = 1000110000
    VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR = 1000111000
    VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR = 1000114000
    VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR = 1000114001
    VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR = 1000114002
    VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR = 1000115000
    VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR = 1000115001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR = 1000116000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR = 1000116001
    VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR = 1000116002
    VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR = 1000116003
    VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR = 1000116004
    VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR = 1000116005
    VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR = 1000116006
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR = 1000119000
    VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR = 1000119001
    VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR = 1000119002
    VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR = 1000121000
    VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR = 1000121001
    VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR = 1000121002
    VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR = 1000121003
    VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR = 1000121004
    VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK = 1000122000
    VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK = 1000123000
    VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT = 1000128000
    VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT = 1000128001
    VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT = 1000128002
    VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT = 1000128003
    VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT = 1000128004
    VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID = 1000129000
    VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID = 1000129001
    VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID = 1000129002
    VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID = 1000129003
    VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID = 1000129004
    VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID = 1000129005
    VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID = 1000129006
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX = 1000134000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX = 1000134001
    VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX = 1000134002
    VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX = 1000134003
    VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX = 1000134004
    VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT = 1000143000
    VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT = 1000143001
    VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT = 1000143002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT = 1000143003
    VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT = 1000143004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT = 1000148000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT = 1000148001
    VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT = 1000148002
    VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV = 1000149000
    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR = 1000150007
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR = 1000150000
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR = 1000150002
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR = 1000150003
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR = 1000150004
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR = 1000150005
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR = 1000150006
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR = 1000150009
    VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR = 1000150010
    VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR = 1000150011
    VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR = 1000150012
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR = 1000150013
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR = 1000150014
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR = 1000150017
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR = 1000150020
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR = 1000347000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR = 1000347001
    VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR = 1000150015
    VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR = 1000150016
    VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR = 1000150018
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR = 1000348013
    VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV = 1000152000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV = 1000154000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV = 1000154001
    VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT = 1000158000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT = 1000158002
    VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT = 1000158003
    VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT = 1000158004
    VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT = 1000158005
    VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT = 1000158006
    VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT = 1000160000
    VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT = 1000160001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR = 1000163000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR = 1000163001
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV = 1000164000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV = 1000164001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV = 1000164002
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV = 1000164005
    VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV = 1000165000
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV = 1000165001
    VK_STRUCTURE_TYPE_GEOMETRY_NV = 1000165003
    VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV = 1000165004
    VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV = 1000165005
    VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV = 1000165006
    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV = 1000165007
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV = 1000165008
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV = 1000165009
    VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV = 1000165011
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV = 1000165012
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV = 1000166000
    VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV = 1000166001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT = 1000170000
    VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT = 1000170001
    VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT = 1000178000
    VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT = 1000178001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT = 1000178002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR = 1000181000
    VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD = 1000183000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD = 1000185000
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR = 1000187000
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR = 1000187001
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR = 1000187002
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR = 1000187003
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR = 1000187004
    VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR = 1000187005
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR = 1000174000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR = 1000388000
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR = 1000388001
    VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD = 1000189000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT = 1000190000
    VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP = 1000191000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV = 1000201000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV = 1000202000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV = 1000202001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV = 1000204000
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV = 1000205000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV = 1000205002
    VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV = 1000206000
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV = 1000206001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL = 1000209000
    VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL = 1000210000
    VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL = 1000210001
    VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL = 1000210002
    VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL = 1000210003
    VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL = 1000210004
    VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL = 1000210005
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT = 1000212000
    VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD = 1000213000
    VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD = 1000213001
    VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA = 1000214000
    VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT = 1000217000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT = 1000218000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT = 1000218001
    VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT = 1000218002
    VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR = 1000226000
    VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR = 1000226001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR = 1000226002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR = 1000226003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR = 1000226004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD = 1000227000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD = 1000229000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT = 1000234000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT = 1000237000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT = 1000238000
    VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT = 1000238001
    VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR = 1000239000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV = 1000240000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT = 1000244000
    VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT = 1000244002
    VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT = 1000247000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR = 1000248000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV = 1000249000
    VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV = 1000249001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV = 1000249002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV = 1000250000
    VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV = 1000250001
    VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV = 1000250002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT = 1000251000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT = 1000252000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT = 1000254000
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT = 1000254001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT = 1000254002
    VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT = 1000255000
    VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT = 1000255002
    VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT = 1000255001
    VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT = 1000256000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT = 1000259000
    VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT = 1000259001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT = 1000259002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT = 1000260000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT = 1000265000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT = 1000267000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR = 1000269000
    VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR = 1000269001
    VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR = 1000269002
    VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR = 1000269003
    VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR = 1000269004
    VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR = 1000269005
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT = 1000270000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT = 1000270001
    VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT = 1000270002
    VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT = 1000270003
    VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT = 1000270004
    VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT = 1000270005
    VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT = 1000270006
    VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT = 1000270007
    VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT = 1000270008
    VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT = 1000270009
    VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR = 1000271000
    VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR = 1000271001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT = 1000273000
    VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT = 1000274000
    VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT = 1000274001
    VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT = 1000274002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT = 1000275000
    VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT = 1000275001
    VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT = 1000275002
    VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT = 1000275003
    VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT = 1000275004
    VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT = 1000275005
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV = 1000277000
    VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV = 1000277001
    VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV = 1000277002
    VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV = 1000277003
    VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV = 1000277004
    VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV = 1000277005
    VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV = 1000277006
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV = 1000277007
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV = 1000278000
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV = 1000278001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT = 1000281000
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM = 1000282000
    VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM = 1000282001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT = 1000283000
    VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT = 1000283001
    VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT = 1000283002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT = 1000284000
    VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT = 1000284001
    VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT = 1000284002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT = 1000286000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT = 1000286001
    VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT = 1000287000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT = 1000287001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT = 1000287002
    VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR = 1000290000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV = 1000292000
    VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV = 1000292001
    VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV = 1000292002
    VK_STRUCTURE_TYPE_PRESENT_ID_KHR = 1000294000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR = 1000294001
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR = 1000299000
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR = 1000299001
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR = 1000299002
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR = 1000299003
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR = 1000299004
    VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR = 1000299005
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR = 1000299006
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR = 1000299007
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR = 1000299008
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR = 1000299009
    VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR = 1000299010
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV = 1000300000
    VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV = 1000300001
    VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV = 1000307000
    VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV = 1000307001
    VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV = 1000307002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV = 1000307003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV = 1000307004
    VK_STRUCTURE_TYPE_REFRESH_OBJECT_LIST_KHR = 1000308000
    VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV = 1000310000
    VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT = 1000311000
    VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT = 1000311001
    VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT = 1000311002
    VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT = 1000311003
    VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT = 1000311004
    VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT = 1000311005
    VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT = 1000311006
    VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT = 1000311007
    VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT = 1000311008
    VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT = 1000311009
    VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT = 1000311010
    VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT = 1000311011
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV = 1000314008
    VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV = 1000314009
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT = 1000316000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT = 1000316001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT = 1000316002
    VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT = 1000316003
    VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT = 1000316004
    VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT = 1000316005
    VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT = 1000316006
    VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT = 1000316007
    VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT = 1000316008
    VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT = 1000316010
    VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT = 1000316011
    VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT = 1000316012
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT = 1000316009
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT = 1000320000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT = 1000320001
    VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT = 1000320002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD = 1000321000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR = 1000203000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR = 1000322000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR = 1000323000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV = 1000326000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV = 1000326001
    VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV = 1000326002
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV = 1000327000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV = 1000327001
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV = 1000327002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT = 1000328000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT = 1000328001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT = 1000330000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT = 1000332000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT = 1000332001
    VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM = 1000333000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR = 1000336000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT = 1000338000
    VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT = 1000338001
    VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT = 1000338004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT = 1000339000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT = 1000340000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT = 1000341000
    VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT = 1000341001
    VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT = 1000341002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT = 1000344000
    VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT = 1000346000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT = 1000352000
    VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT = 1000352001
    VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT = 1000352002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT = 1000353000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT = 1000354000
    VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT = 1000354001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT = 1000355000
    VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT = 1000355001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT = 1000356000
    VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA = 1000364000
    VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA = 1000364001
    VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA = 1000364002
    VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA = 1000365000
    VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA = 1000365001
    VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA = 1000366000
    VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA = 1000366001
    VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA = 1000366002
    VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA = 1000366003
    VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA = 1000366004
    VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA = 1000366005
    VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA = 1000366006
    VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA = 1000366007
    VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA = 1000366008
    VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA = 1000366009
    VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI = 1000369000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI = 1000369001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI = 1000369002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI = 1000370000
    VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV = 1000371000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV = 1000371001
    VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT = 1000372000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT = 1000372001
    VK_STRUCTURE_TYPE_IMPORT_FENCE_SCI_SYNC_INFO_NV = 1000373000
    VK_STRUCTURE_TYPE_EXPORT_FENCE_SCI_SYNC_INFO_NV = 1000373001
    VK_STRUCTURE_TYPE_FENCE_GET_SCI_SYNC_INFO_NV = 1000373002
    VK_STRUCTURE_TYPE_SCI_SYNC_ATTRIBUTES_INFO_NV = 1000373003
    VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_SCI_SYNC_INFO_NV = 1000373004
    VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_SCI_SYNC_INFO_NV = 1000373005
    VK_STRUCTURE_TYPE_SEMAPHORE_GET_SCI_SYNC_INFO_NV = 1000373006
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_FEATURES_NV = 1000373007
    VK_STRUCTURE_TYPE_IMPORT_MEMORY_SCI_BUF_INFO_NV = 1000374000
    VK_STRUCTURE_TYPE_EXPORT_MEMORY_SCI_BUF_INFO_NV = 1000374001
    VK_STRUCTURE_TYPE_MEMORY_GET_SCI_BUF_INFO_NV = 1000374002
    VK_STRUCTURE_TYPE_MEMORY_SCI_BUF_PROPERTIES_NV = 1000374003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV = 1000374004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT = 1000375000
    VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT = 1000375001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT = 1000376000
    VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT = 1000376001
    VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT = 1000376002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT = 1000377000
    VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX = 1000378000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT = 1000381000
    VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT = 1000381001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT = 1000382000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR = 1000386000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT = 1000391000
    VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT = 1000391001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT = 1000392000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT = 1000392001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT = 1000393000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT = 1000395000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT = 1000395001
    VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT = 1000396000
    VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT = 1000396001
    VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT = 1000396002
    VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT = 1000396003
    VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT = 1000396004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT = 1000396005
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT = 1000396006
    VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT = 1000396007
    VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT = 1000396008
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT = 1000396009
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV = 1000397000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV = 1000397001
    VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV = 1000397002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI = 1000404000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI = 1000404001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI = 1000404002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT = 1000411000
    VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT = 1000411001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT = 1000412000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM = 1000415000
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM = 1000417000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM = 1000417001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM = 1000417002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT = 1000418000
    VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT = 1000418001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE = 1000420000
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE = 1000420001
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE = 1000420002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT = 1000421000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT = 1000422000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM = 1000424000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM = 1000424001
    VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM = 1000424002
    VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM = 1000424003
    VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM = 1000424004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM = 1000425000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM = 1000425001
    VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM = 1000425002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV = 1000426000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV = 1000426001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV = 1000427000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV = 1000427001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV = 1000428000
    VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV = 1000428001
    VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV = 1000428002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV = 1000430000
    VK_STRUCTURE_TYPE_APPLICATION_PARAMETERS_EXT = 1000435000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT = 1000437000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM = 1000440000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM = 1000440001
    VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM = 1000440002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT = 1000451000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT = 1000451001
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT = 1000453000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT = 1000455000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT = 1000455001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT = 1000458000
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT = 1000458001
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT = 1000458002
    VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT = 1000458003
    VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG = 1000459000
    VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG = 1000459001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT = 1000462000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT = 1000462001
    VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT = 1000462002
    VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT = 1000462003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT = 1000342000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV = 1000464000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV = 1000464001
    VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV = 1000464002
    VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV = 1000464003
    VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV = 1000464004
    VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV = 1000464005
    VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV = 1000464010
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT = 1000465000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT = 1000466000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID = 1000468000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID = 1000468001
    VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID = 1000468002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR = 1000470000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR = 1000470001
    VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR = 1000470003
    VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR = 1000470004
    VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR = 1000338002
    VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR = 1000338003
    VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR = 1000470005
    VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR = 1000470006
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR = 1000481000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT = 1000482000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT = 1000482001
    VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT = 1000482002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM = 1000484000
    VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM = 1000484001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC = 1000485000
    VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC = 1000485001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM = 1000488000
    VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_POOL_CREATE_INFO_NV = 1000489000
    VK_STRUCTURE_TYPE_SEMAPHORE_SCI_SYNC_CREATE_INFO_NV = 1000489001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_SYNC_2_FEATURES_NV = 1000489002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV = 1000490000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV = 1000490001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV = 1000492000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV = 1000492001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT = 1000351000
    VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT = 1000351002
    VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT = 1000496000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM = 1000497000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM = 1000497001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT = 1000498000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT = 1000499000
    VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV = 1000505000
    VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV = 1000505001
    VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV = 1000505002
    VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV = 1000505003
    VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV = 1000505004
    VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV = 1000505005
    VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV = 1000505006
    VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV = 1000505007
    VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV = 1000505008
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR = 1000506000
    VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR = 1000506001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR = 1000506002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM = 1000510000
    VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM = 1000510001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR = 1000515000
    VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR = 1000515001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV = 1000516000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM = 1000518000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM = 1000518001
    VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM = 1000518002
    VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM = 1000519000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM = 1000519001
    VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM = 1000519002
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM = 1000520000
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM = 1000520001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM = 1000521000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT = 1000524000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR = 1000525000
    VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR = 1000190001
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR = 1000190002
    VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX = 1000529000
    VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX = 1000529001
    VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX = 1000529002
    VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX = 1000529003
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX = 1000529004
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT = 1000530000
    VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR = 1000184000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR = 1000545000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR = 1000545001
    VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR = 1000545002
    VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR = 1000545003
    VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR = 1000545004
    VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR = 1000545005
    VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR = 1000545006
    VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT = 1000545007
    VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT = 1000545008
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV = 1000546000
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES
    VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT
    VK_STRUCTURE_TYPE_RENDERING_INFO_KHR = VK_STRUCTURE_TYPE_RENDERING_INFO
    VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO_KHR = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO
    VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO_KHR = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO
    VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_NV = VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD
    VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2
    VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2
    VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2
    VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR = VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2
    VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO_KHR = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO
    VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO_KHR = VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO
    VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO_KHR = VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO
    VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO_KHR = VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO
    VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO_KHR = VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO
    VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO_KHR = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO
    VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO_KHR = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES
    VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO
    VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR = VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO
    VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES_KHR = VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO
    VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO
    VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_KHR = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO
    VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES_KHR = VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES
    VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES
    VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO
    VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES2_EXT = VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES
    VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO
    VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO_KHR = VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO
    VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO_KHR = VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO
    VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2_KHR = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2
    VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2_KHR = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2
    VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2_KHR = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2
    VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2_KHR = VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2
    VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2_KHR = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2
    VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO_KHR = VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO
    VK_STRUCTURE_TYPE_SUBPASS_END_INFO_KHR = VK_STRUCTURE_TYPE_SUBPASS_END_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO
    VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES_KHR = VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES
    VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES
    VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO
    VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO
    VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR
    VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS_KHR = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS
    VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_KHR = VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES
    VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES
    VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK
    VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2_KHR = VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2_KHR = VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2
    VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2_KHR = VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2
    VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2_KHR = VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2
    VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2_KHR = VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2
    VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO_KHR = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO
    VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO_KHR = VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO
    VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO_KHR = VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES
    VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES_KHR = VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES
    VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO_KHR = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO
    VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO_KHR = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES
    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT_KHR = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT
    VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES
    VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT = VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR
    VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR
    VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES
    VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR = VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES
    VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO
    VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO
    VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO_KHR = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO
    VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO_KHR = VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO
    VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL = VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES
    VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES
    VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT_KHR = VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT
    VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT_KHR = VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT
    VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_EXT = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES
    VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES
    VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_KHR = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO
    VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO_KHR = VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO
    VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO_KHR = VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO
    VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO_KHR = VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES
    VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO
    VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES
    VK_STRUCTURE_TYPE_MEMORY_BARRIER_2_KHR = VK_STRUCTURE_TYPE_MEMORY_BARRIER_2
    VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2_KHR = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2
    VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2_KHR = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2
    VK_STRUCTURE_TYPE_DEPENDENCY_INFO_KHR = VK_STRUCTURE_TYPE_DEPENDENCY_INFO
    VK_STRUCTURE_TYPE_SUBMIT_INFO_2_KHR = VK_STRUCTURE_TYPE_SUBMIT_INFO_2
    VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO_KHR = VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO
    VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO_KHR = VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES
    VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2_KHR = VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2
    VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2_KHR = VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2
    VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2_KHR = VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2
    VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2_KHR = VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2
    VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2_KHR = VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2
    VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2_KHR = VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2
    VK_STRUCTURE_TYPE_BUFFER_COPY_2_KHR = VK_STRUCTURE_TYPE_BUFFER_COPY_2
    VK_STRUCTURE_TYPE_IMAGE_COPY_2_KHR = VK_STRUCTURE_TYPE_IMAGE_COPY_2
    VK_STRUCTURE_TYPE_IMAGE_BLIT_2_KHR = VK_STRUCTURE_TYPE_IMAGE_BLIT_2
    VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2_KHR = VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2
    VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2_KHR = VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2
    VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_EXT = VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR
    VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_EXT = VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_ARM = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT
    VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE = VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT
    VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3_KHR = VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3
    VK_STRUCTURE_TYPE_PIPELINE_INFO_EXT = VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SCI_BUF_FEATURES_NV = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCI_BUF_FEATURES_NV
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_EXT = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR
    VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_EXT = VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES_KHR = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES
    VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS_KHR = VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS
    VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS_KHR = VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS
    VK_STRUCTURE_TYPE_SHADER_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO

class VkSystemAllocationScope(Enum):
    VK_SYSTEM_ALLOCATION_SCOPE_COMMAND = 0
    VK_SYSTEM_ALLOCATION_SCOPE_OBJECT = 1
    VK_SYSTEM_ALLOCATION_SCOPE_CACHE = 2
    VK_SYSTEM_ALLOCATION_SCOPE_DEVICE = 3
    VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE = 4

class VkInternalAllocationType(Enum):
    VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE = 0

class VkSamplerAddressMode(Enum):
    VK_SAMPLER_ADDRESS_MODE_REPEAT = 0
    VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT = 1
    VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE = 2
    VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER = 3
    VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE = 4
    VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE_KHR = VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE

class VkFilter(Enum):
    VK_FILTER_NEAREST = 0
    VK_FILTER_LINEAR = 1
    VK_FILTER_CUBIC_EXT = 1000015000
    VK_FILTER_CUBIC_IMG = VK_FILTER_CUBIC_EXT

class VkSamplerMipmapMode(Enum):
    VK_SAMPLER_MIPMAP_MODE_NEAREST = 0
    VK_SAMPLER_MIPMAP_MODE_LINEAR = 1

class VkVertexInputRate(Enum):
    VK_VERTEX_INPUT_RATE_VERTEX = 0
    VK_VERTEX_INPUT_RATE_INSTANCE = 1

class VkPipelineStageFlagBits(Flag):
    VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT = 0x00000001
    VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT = 0x00000002
    VK_PIPELINE_STAGE_VERTEX_INPUT_BIT = 0x00000004
    VK_PIPELINE_STAGE_VERTEX_SHADER_BIT = 0x00000008
    VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT = 0x00000010
    VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT = 0x00000020
    VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT = 0x00000040
    VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT = 0x00000080
    VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT = 0x00000100
    VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT = 0x00000200
    VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT = 0x00000400
    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT = 0x00000800
    VK_PIPELINE_STAGE_TRANSFER_BIT = 0x00001000
    VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT = 0x00002000
    VK_PIPELINE_STAGE_HOST_BIT = 0x00004000
    VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT = 0x00008000
    VK_PIPELINE_STAGE_ALL_COMMANDS_BIT = 0x00010000
    VK_PIPELINE_STAGE_NONE = 0x00000000
    VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT = 0x01000000
    VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT = 0x00040000
    VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR = 0x02000000
    VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR = 0x00200000
    VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT = 0x00800000
    VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR = 0x00400000
    VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV = 0x00020000
    VK_PIPELINE_STAGE_TASK_SHADER_BIT_EXT = 0x00080000
    VK_PIPELINE_STAGE_MESH_SHADER_BIT_EXT = 0x00100000
    VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV = VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR
    VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_NV = VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR
    VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_NV = VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR
    VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV = VK_PIPELINE_STAGE_TASK_SHADER_BIT_EXT
    VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV = VK_PIPELINE_STAGE_MESH_SHADER_BIT_EXT
    VK_PIPELINE_STAGE_NONE_KHR = VK_PIPELINE_STAGE_NONE

class VkSparseImageFormatFlagBits(Flag):
    VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT = 0x00000001
    VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT = 0x00000002
    VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT = 0x00000004

class VkSampleCountFlagBits(Flag):
    VK_SAMPLE_COUNT_1_BIT = 0x00000001
    VK_SAMPLE_COUNT_2_BIT = 0x00000002
    VK_SAMPLE_COUNT_4_BIT = 0x00000004
    VK_SAMPLE_COUNT_8_BIT = 0x00000008
    VK_SAMPLE_COUNT_16_BIT = 0x00000010
    VK_SAMPLE_COUNT_32_BIT = 0x00000020
    VK_SAMPLE_COUNT_64_BIT = 0x00000040

class VkAttachmentDescriptionFlagBits(Flag):
    VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT = 0x00000001

class VkDescriptorPoolCreateFlagBits(Flag):
    VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT = 0x00000001
    VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT = 0x00000002
    VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_EXT = 0x00000004
    VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_SETS_BIT_NV = 0x00000008
    VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_POOLS_BIT_NV = 0x00000010
    VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT_EXT = VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT
    VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_VALVE = VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_EXT

class VkDependencyFlagBits(Flag):
    VK_DEPENDENCY_BY_REGION_BIT = 0x00000001
    VK_DEPENDENCY_DEVICE_GROUP_BIT = 0x00000004
    VK_DEPENDENCY_VIEW_LOCAL_BIT = 0x00000002
    VK_DEPENDENCY_FEEDBACK_LOOP_BIT_EXT = 0x00000008
    VK_DEPENDENCY_VIEW_LOCAL_BIT_KHR = VK_DEPENDENCY_VIEW_LOCAL_BIT
    VK_DEPENDENCY_DEVICE_GROUP_BIT_KHR = VK_DEPENDENCY_DEVICE_GROUP_BIT

class VkObjectType(Enum):
    VK_OBJECT_TYPE_UNKNOWN = 0
    VK_OBJECT_TYPE_INSTANCE = 1
    VK_OBJECT_TYPE_PHYSICAL_DEVICE = 2
    VK_OBJECT_TYPE_DEVICE = 3
    VK_OBJECT_TYPE_QUEUE = 4
    VK_OBJECT_TYPE_SEMAPHORE = 5
    VK_OBJECT_TYPE_COMMAND_BUFFER = 6
    VK_OBJECT_TYPE_FENCE = 7
    VK_OBJECT_TYPE_DEVICE_MEMORY = 8
    VK_OBJECT_TYPE_BUFFER = 9
    VK_OBJECT_TYPE_IMAGE = 10
    VK_OBJECT_TYPE_EVENT = 11
    VK_OBJECT_TYPE_QUERY_POOL = 12
    VK_OBJECT_TYPE_BUFFER_VIEW = 13
    VK_OBJECT_TYPE_IMAGE_VIEW = 14
    VK_OBJECT_TYPE_SHADER_MODULE = 15
    VK_OBJECT_TYPE_PIPELINE_CACHE = 16
    VK_OBJECT_TYPE_PIPELINE_LAYOUT = 17
    VK_OBJECT_TYPE_RENDER_PASS = 18
    VK_OBJECT_TYPE_PIPELINE = 19
    VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT = 20
    VK_OBJECT_TYPE_SAMPLER = 21
    VK_OBJECT_TYPE_DESCRIPTOR_POOL = 22
    VK_OBJECT_TYPE_DESCRIPTOR_SET = 23
    VK_OBJECT_TYPE_FRAMEBUFFER = 24
    VK_OBJECT_TYPE_COMMAND_POOL = 25
    VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION = 1000156000
    VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE = 1000085000
    VK_OBJECT_TYPE_PRIVATE_DATA_SLOT = 1000295000
    VK_OBJECT_TYPE_SURFACE_KHR = 1000000000
    VK_OBJECT_TYPE_SWAPCHAIN_KHR = 1000001000
    VK_OBJECT_TYPE_DISPLAY_KHR = 1000002000
    VK_OBJECT_TYPE_DISPLAY_MODE_KHR = 1000002001
    VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT = 1000011000
    VK_OBJECT_TYPE_VIDEO_SESSION_KHR = 1000023000
    VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR = 1000023001
    VK_OBJECT_TYPE_CU_MODULE_NVX = 1000029000
    VK_OBJECT_TYPE_CU_FUNCTION_NVX = 1000029001
    VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT = 1000128000
    VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR = 1000150000
    VK_OBJECT_TYPE_VALIDATION_CACHE_EXT = 1000160000
    VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV = 1000165000
    VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL = 1000210000
    VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR = 1000268000
    VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV = 1000277000
    VK_OBJECT_TYPE_CUDA_MODULE_NV = 1000307000
    VK_OBJECT_TYPE_CUDA_FUNCTION_NV = 1000307001
    VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA = 1000366000
    VK_OBJECT_TYPE_MICROMAP_EXT = 1000396000
    VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV = 1000464000
    VK_OBJECT_TYPE_SHADER_EXT = 1000482000
    VK_OBJECT_TYPE_SEMAPHORE_SCI_SYNC_POOL_NV = 1000489000
    VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR = VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE
    VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR = VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION
    VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT = VK_OBJECT_TYPE_PRIVATE_DATA_SLOT

class VkEventCreateFlagBits(Flag):
    VK_EVENT_CREATE_DEVICE_ONLY_BIT = 0x00000001
    VK_EVENT_CREATE_DEVICE_ONLY_BIT_KHR = VK_EVENT_CREATE_DEVICE_ONLY_BIT

class VkPipelineLayoutCreateFlagBits(Flag):
    VK_PIPELINE_LAYOUT_CREATE_RESERVED_0_BIT_AMD = 0x00000001
    VK_PIPELINE_LAYOUT_CREATE_INDEPENDENT_SETS_BIT_EXT = 0x00000002

class VkSemaphoreCreateFlagBits(Flag):
    pass

class VkRayTracingInvocationReorderModeNV(Enum):
    VK_RAY_TRACING_INVOCATION_REORDER_MODE_NONE_NV = 0
    VK_RAY_TRACING_INVOCATION_REORDER_MODE_REORDER_NV = 1

class VkIndirectCommandsLayoutUsageFlagBitsNV(Flag):
    VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV = 0x00000001
    VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV = 0x00000002
    VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV = 0x00000004

class VkIndirectCommandsTokenTypeNV(Enum):
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV = 0
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV = 1
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV = 2
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV = 3
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV = 4
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV = 5
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV = 6
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV = 7
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_NV = 1000328000
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NV = 1000428003
    VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NV = 1000428004

class VkIndirectStateFlagBitsNV(Flag):
    VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV = 0x00000001

class VkPrivateDataSlotCreateFlagBits(Flag):
    VK_PRIVATE_DATA_SLOT_CREATE_RESERVED_0_BIT_NV = 0x00000001


class VkDescriptorUpdateTemplateType(Enum):
    VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET = 0
    VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR = 1
    VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET_KHR = VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET


class VkViewportCoordinateSwizzleNV(Enum):
    VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV = 0
    VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV = 1
    VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV = 2
    VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV = 3
    VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV = 4
    VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV = 5
    VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV = 6
    VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV = 7

class VkDiscardRectangleModeEXT(Enum):
    VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT = 0
    VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT = 1

class VkSubpassDescriptionFlagBits(Flag):
    VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX = 0x00000001
    VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX = 0x00000002
    VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM = 0x00000004
    VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM = 0x00000008
    VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_EXT = 0x00000010
    VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT = 0x00000020
    VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT = 0x00000040
    VK_SUBPASS_DESCRIPTION_ENABLE_LEGACY_DITHERING_BIT_EXT = 0x00000080
    VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_ARM = VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_EXT
    VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_ARM = VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT
    VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_ARM = VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT

class VkPointClippingBehavior(Enum):
    VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES = 0
    VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY = 1
    VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES_KHR = VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES
    VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY_KHR = VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY


class VkCoverageModulationModeNV(Enum):
    VK_COVERAGE_MODULATION_MODE_NONE_NV = 0
    VK_COVERAGE_MODULATION_MODE_RGB_NV = 1
    VK_COVERAGE_MODULATION_MODE_ALPHA_NV = 2
    VK_COVERAGE_MODULATION_MODE_RGBA_NV = 3

class VkCoverageReductionModeNV(Enum):
    VK_COVERAGE_REDUCTION_MODE_MERGE_NV = 0
    VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV = 1

class VkValidationCacheHeaderVersionEXT(Enum):
    VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT = 1

class VkShaderInfoTypeAMD(Enum):
    VK_SHADER_INFO_TYPE_STATISTICS_AMD = 0
    VK_SHADER_INFO_TYPE_BINARY_AMD = 1
    VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD = 2

class VkQueueGlobalPriorityKHR(Enum):
    VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR = 128
    VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR = 256
    VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR = 512
    VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR = 1024
    VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT = VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR
    VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_EXT = VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR
    VK_QUEUE_GLOBAL_PRIORITY_HIGH_EXT = VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR
    VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT = VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR


class VkTimeDomainKHR(Enum):
    VK_TIME_DOMAIN_DEVICE_KHR = 0
    VK_TIME_DOMAIN_CLOCK_MONOTONIC_KHR = 1
    VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_KHR = 2
    VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_KHR = 3
    VK_TIME_DOMAIN_DEVICE_EXT = VK_TIME_DOMAIN_DEVICE_KHR
    VK_TIME_DOMAIN_CLOCK_MONOTONIC_EXT = VK_TIME_DOMAIN_CLOCK_MONOTONIC_KHR
    VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT = VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_KHR
    VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_EXT = VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_KHR


class VkConservativeRasterizationModeEXT(Enum):
    VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT = 0
    VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT = 1
    VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT = 2

class VkResolveModeFlagBits(Flag):
    VK_RESOLVE_MODE_NONE = 0x00000000
    VK_RESOLVE_MODE_SAMPLE_ZERO_BIT = 0x00000001
    VK_RESOLVE_MODE_AVERAGE_BIT = 0x00000002
    VK_RESOLVE_MODE_MIN_BIT = 0x00000004
    VK_RESOLVE_MODE_MAX_BIT = 0x00000008
    VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_ANDROID = 0x00000010
    VK_RESOLVE_MODE_NONE_KHR = VK_RESOLVE_MODE_NONE
    VK_RESOLVE_MODE_SAMPLE_ZERO_BIT_KHR = VK_RESOLVE_MODE_SAMPLE_ZERO_BIT
    VK_RESOLVE_MODE_AVERAGE_BIT_KHR = VK_RESOLVE_MODE_AVERAGE_BIT
    VK_RESOLVE_MODE_MIN_BIT_KHR = VK_RESOLVE_MODE_MIN_BIT
    VK_RESOLVE_MODE_MAX_BIT_KHR = VK_RESOLVE_MODE_MAX_BIT


class VkDescriptorBindingFlagBits(Flag):
    VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT = 0x00000001
    VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT = 0x00000002
    VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT = 0x00000004
    VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT = 0x00000008
    VK_DESCRIPTOR_BINDING_RESERVED_4_BIT_QCOM = 0x00000010
    VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT_EXT = VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT
    VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT_EXT = VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT
    VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT_EXT = VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT
    VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT_EXT = VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT


class VkConditionalRenderingFlagBitsEXT(Flag):
    VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT = 0x00000001

class VkSemaphoreType(Enum):
    VK_SEMAPHORE_TYPE_BINARY = 0
    VK_SEMAPHORE_TYPE_TIMELINE = 1
    VK_SEMAPHORE_TYPE_BINARY_KHR = VK_SEMAPHORE_TYPE_BINARY
    VK_SEMAPHORE_TYPE_TIMELINE_KHR = VK_SEMAPHORE_TYPE_TIMELINE


class VkGeometryFlagBitsKHR(Flag):
    VK_GEOMETRY_OPAQUE_BIT_KHR = 0x00000001
    VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR = 0x00000002
    VK_GEOMETRY_OPAQUE_BIT_NV = VK_GEOMETRY_OPAQUE_BIT_KHR
    VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_NV = VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR


class VkGeometryInstanceFlagBitsKHR(Flag):
    VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR = 0x00000001
    VK_GEOMETRY_INSTANCE_TRIANGLE_FLIP_FACING_BIT_KHR = 0x00000002
    VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR = 0x00000004
    VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR = 0x00000008
    VK_GEOMETRY_INSTANCE_FORCE_OPACITY_MICROMAP_2_STATE_EXT = 0x00000010
    VK_GEOMETRY_INSTANCE_DISABLE_OPACITY_MICROMAPS_EXT = 0x00000020
    VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_KHR = VK_GEOMETRY_INSTANCE_TRIANGLE_FLIP_FACING_BIT_KHR
    VK_GEOMETRY_INSTANCE_TRIANGLE_CULL_DISABLE_BIT_NV = VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR
    VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_NV = VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_KHR
    VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_NV = VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR
    VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_NV = VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR


class VkBuildAccelerationStructureFlagBitsKHR(Flag):
    VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR = 0x00000001
    VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR = 0x00000002
    VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR = 0x00000004
    VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR = 0x00000008
    VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR = 0x00000010
    VK_BUILD_ACCELERATION_STRUCTURE_MOTION_BIT_NV = 0x00000020
    VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_UPDATE_EXT = 0x00000040
    VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISABLE_OPACITY_MICROMAPS_EXT = 0x00000080
    VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_DATA_UPDATE_EXT = 0x00000100
    VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISPLACEMENT_MICROMAP_UPDATE_NV = 0x00000200
    VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DATA_ACCESS_KHR = 0x00000800
    VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_NV = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR
    VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_NV = VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR
    VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_NV = VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR
    VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_NV = VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR
    VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_NV = VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR


class VkAccelerationStructureCreateFlagBitsKHR(Flag):
    VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR = 0x00000001
    VK_ACCELERATION_STRUCTURE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT = 0x00000008
    VK_ACCELERATION_STRUCTURE_CREATE_MOTION_BIT_NV = 0x00000004

class VkBuildAccelerationStructureModeKHR(Enum):
    VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR = 0
    VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR = 1

class VkCopyAccelerationStructureModeKHR(Enum):
    VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR = 0
    VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR = 1
    VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR = 2
    VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR = 3
    VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_NV = VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR
    VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_NV = VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR


class VkAccelerationStructureTypeKHR(Enum):
    VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR = 0
    VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR = 1
    VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR = 2
    VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_NV = VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR
    VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_NV = VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR


class VkGeometryTypeKHR(Enum):
    VK_GEOMETRY_TYPE_TRIANGLES_KHR = 0
    VK_GEOMETRY_TYPE_AABBS_KHR = 1
    VK_GEOMETRY_TYPE_INSTANCES_KHR = 2
    VK_GEOMETRY_TYPE_TRIANGLES_NV = VK_GEOMETRY_TYPE_TRIANGLES_KHR
    VK_GEOMETRY_TYPE_AABBS_NV = VK_GEOMETRY_TYPE_AABBS_KHR


class VkRayTracingShaderGroupTypeKHR(Enum):
    VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR = 0
    VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR = 1
    VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR = 2
    VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_NV = VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR
    VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_NV = VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR
    VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_NV = VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR


class VkAccelerationStructureMemoryRequirementsTypeNV(Enum):
    VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV = 0
    VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV = 1
    VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV = 2

class VkAccelerationStructureBuildTypeKHR(Enum):
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR = 0
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR = 1
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR = 2

class VkAccelerationStructureCompatibilityKHR(Enum):
    VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR = 0
    VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR = 1

class VkShaderGroupShaderKHR(Enum):
    VK_SHADER_GROUP_SHADER_GENERAL_KHR = 0
    VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR = 1
    VK_SHADER_GROUP_SHADER_ANY_HIT_KHR = 2
    VK_SHADER_GROUP_SHADER_INTERSECTION_KHR = 3

class VkMemoryOverallocationBehaviorAMD(Enum):
    VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD = 0
    VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD = 1
    VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD = 2

class VkDeviceDiagnosticsConfigFlagBitsNV(Flag):
    VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV = 0x00000001
    VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV = 0x00000002
    VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV = 0x00000004
    VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_ERROR_REPORTING_BIT_NV = 0x00000008

class VkPipelineCreationFeedbackFlagBits(Flag):
    VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT = 0x00000001
    VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT = 0x00000002
    VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT = 0x00000004
    VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT_EXT = VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT
    VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT_EXT = VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT
    VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT_EXT = VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT


class VkPerformanceCounterScopeKHR(Enum):
    VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR = 0
    VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR = 1
    VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR = 2
    VK_QUERY_SCOPE_COMMAND_BUFFER_KHR = VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR
    VK_QUERY_SCOPE_RENDER_PASS_KHR = VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR
    VK_QUERY_SCOPE_COMMAND_KHR = VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR

class VkPerformanceCounterUnitKHR(Enum):
    VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR = 0
    VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR = 1
    VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR = 2
    VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR = 3
    VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR = 4
    VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR = 5
    VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR = 6
    VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR = 7
    VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR = 8
    VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR = 9
    VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR = 10

class VkPerformanceCounterStorageKHR(Enum):
    VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR = 0
    VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR = 1
    VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR = 2
    VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR = 3
    VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR = 4
    VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR = 5

class VkPerformanceCounterDescriptionFlagBitsKHR(Flag):
    VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR = 0x00000001
    VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR = 0x00000002
    VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_KHR = VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR
    VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_KHR = VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR

class VkAcquireProfilingLockFlagBitsKHR(Flag):
    pass

class VkSemaphoreWaitFlagBits(Flag):
    VK_SEMAPHORE_WAIT_ANY_BIT = 0x00000001
    VK_SEMAPHORE_WAIT_ANY_BIT_KHR = VK_SEMAPHORE_WAIT_ANY_BIT


class VkPerformanceConfigurationTypeINTEL(Enum):
    VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL = 0

class VkQueryPoolSamplingModeINTEL(Enum):
    VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL = 0

class VkPerformanceOverrideTypeINTEL(Enum):
    VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL = 0
    VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL = 1

class VkPerformanceParameterTypeINTEL(Enum):
    VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL = 0
    VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL = 1

class VkPerformanceValueTypeINTEL(Enum):
    VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL = 0
    VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL = 1
    VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL = 2
    VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL = 3
    VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL = 4

class VkLineRasterizationModeEXT(Enum):
    VK_LINE_RASTERIZATION_MODE_DEFAULT_EXT = 0
    VK_LINE_RASTERIZATION_MODE_RECTANGULAR_EXT = 1
    VK_LINE_RASTERIZATION_MODE_BRESENHAM_EXT = 2
    VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_EXT = 3

class VkShaderModuleCreateFlagBits(Flag):
    pass

class VkPipelineCompilerControlFlagBitsAMD(Flag):
    pass

class VkShaderCorePropertiesFlagBitsAMD(Flag):
    pass

class VkRefreshObjectFlagBitsKHR(Flag):
    pass

class VkFaultLevel(Enum):
    VK_FAULT_LEVEL_UNASSIGNED = 0
    VK_FAULT_LEVEL_CRITICAL = 1
    VK_FAULT_LEVEL_RECOVERABLE = 2
    VK_FAULT_LEVEL_WARNING = 3

class VkFaultType(Enum):
    VK_FAULT_TYPE_INVALID = 0
    VK_FAULT_TYPE_UNASSIGNED = 1
    VK_FAULT_TYPE_IMPLEMENTATION = 2
    VK_FAULT_TYPE_SYSTEM = 3
    VK_FAULT_TYPE_PHYSICAL_DEVICE = 4
    VK_FAULT_TYPE_COMMAND_BUFFER_FULL = 5
    VK_FAULT_TYPE_INVALID_API_USAGE = 6

class VkFaultQueryBehavior(Enum):
    VK_FAULT_QUERY_BEHAVIOR_GET_AND_CLEAR_ALL_FAULTS = 0

class VkPipelineMatchControl(Enum):
    VK_PIPELINE_MATCH_CONTROL_APPLICATION_UUID_EXACT_MATCH = 0

class VkSciSyncClientTypeNV(Enum):
    VK_SCI_SYNC_CLIENT_TYPE_SIGNALER_NV = 0
    VK_SCI_SYNC_CLIENT_TYPE_WAITER_NV = 1
    VK_SCI_SYNC_CLIENT_TYPE_SIGNALER_WAITER_NV = 2

class VkSciSyncPrimitiveTypeNV(Enum):
    VK_SCI_SYNC_PRIMITIVE_TYPE_FENCE_NV = 0
    VK_SCI_SYNC_PRIMITIVE_TYPE_SEMAPHORE_NV = 1

class VkToolPurposeFlagBits(Flag):
    VK_TOOL_PURPOSE_VALIDATION_BIT = 0x00000001
    VK_TOOL_PURPOSE_PROFILING_BIT = 0x00000002
    VK_TOOL_PURPOSE_TRACING_BIT = 0x00000004
    VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT = 0x00000008
    VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT = 0x00000010
    VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT = 0x00000020
    VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT = 0x00000040
    VK_TOOL_PURPOSE_VALIDATION_BIT_EXT = VK_TOOL_PURPOSE_VALIDATION_BIT
    VK_TOOL_PURPOSE_PROFILING_BIT_EXT = VK_TOOL_PURPOSE_PROFILING_BIT
    VK_TOOL_PURPOSE_TRACING_BIT_EXT = VK_TOOL_PURPOSE_TRACING_BIT
    VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT_EXT = VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT
    VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT_EXT = VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT


class VkFragmentShadingRateNV(Enum):
    VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV = 0
    VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV = 1
    VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV = 4
    VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV = 5
    VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV = 6
    VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV = 9
    VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV = 10
    VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV = 11
    VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV = 12
    VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV = 13
    VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV = 14
    VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV = 15

class VkFragmentShadingRateTypeNV(Enum):
    VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV = 0
    VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV = 1

class VkSubpassMergeStatusEXT(Enum):
    VK_SUBPASS_MERGE_STATUS_MERGED_EXT = 0
    VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT = 1
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT = 2
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT = 3
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT = 4
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT = 5
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT = 6
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT = 7
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT = 8
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT = 9
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT = 10
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT = 11
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT = 12
    VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT = 13

class VkAccessFlagBits2(Flag):
    VK_ACCESS_2_NONE = 0x0000000000000000
    VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT = 0x0000000000000001
    VK_ACCESS_2_INDEX_READ_BIT = 0x0000000000000002
    VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT = 0x0000000000000004
    VK_ACCESS_2_UNIFORM_READ_BIT = 0x0000000000000008
    VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT = 0x0000000000000010
    VK_ACCESS_2_SHADER_READ_BIT = 0x0000000000000020
    VK_ACCESS_2_SHADER_WRITE_BIT = 0x0000000000000040
    VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT = 0x0000000000000080
    VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT = 0x0000000000000100
    VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT = 0x0000000000000200
    VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT = 0x0000000000000400
    VK_ACCESS_2_TRANSFER_READ_BIT = 0x0000000000000800
    VK_ACCESS_2_TRANSFER_WRITE_BIT = 0x0000000000001000
    VK_ACCESS_2_HOST_READ_BIT = 0x0000000000002000
    VK_ACCESS_2_HOST_WRITE_BIT = 0x0000000000004000
    VK_ACCESS_2_MEMORY_READ_BIT = 0x0000000000008000
    VK_ACCESS_2_MEMORY_WRITE_BIT = 0x0000000000010000
    VK_ACCESS_2_SHADER_SAMPLED_READ_BIT = 0x0000000100000000
    VK_ACCESS_2_SHADER_STORAGE_READ_BIT = 0x0000000200000000
    VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT = 0x0000000400000000
    VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR = 0x0000000800000000
    VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR = 0x0000001000000000
    VK_ACCESS_2_RESERVED_46_BIT_INTEL = 0x0000400000000000
    VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR = 0x0000002000000000
    VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR = 0x0000004000000000
    VK_ACCESS_2_RESERVED_51_BIT_QCOM = 0x0008000000000000
    VK_ACCESS_2_RESERVED_52_BIT_QCOM = 0x0010000000000000
    VK_ACCESS_2_RESERVED_53_BIT_QCOM = 0x0020000000000000
    VK_ACCESS_2_RESERVED_54_BIT_QCOM = 0x0040000000000000
    VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT = 0x0000000002000000
    VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT = 0x0000000004000000
    VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT = 0x0000000008000000
    VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT = 0x0000000000100000
    VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_NV = 0x0000000000020000
    VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_NV = 0x0000000000040000
    VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR = 0x0000000000800000
    VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR = 0x0000000000200000
    VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR = 0x0000000000400000
    VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT = 0x0000000001000000
    VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT = 0x0000000000080000
    VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT = 0x0000020000000000
    VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI = 0x0000008000000000
    VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR = 0x0000010000000000
    VK_ACCESS_2_MICROMAP_READ_BIT_EXT = 0x0000100000000000
    VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT = 0x0000200000000000
    VK_ACCESS_2_RESERVED_49_BIT_ARM = 0x0002000000000000
    VK_ACCESS_2_RESERVED_50_BIT_ARM = 0x0004000000000000
    VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV = 0x0000040000000000
    VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV = 0x0000080000000000
    VK_ACCESS_2_RESERVED_47_BIT_EXT = 0x0000800000000000
    VK_ACCESS_2_RESERVED_48_BIT_EXT = 0x0001000000000000
    VK_ACCESS_2_NONE_KHR = VK_ACCESS_2_NONE
    VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT_KHR = VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT
    VK_ACCESS_2_INDEX_READ_BIT_KHR = VK_ACCESS_2_INDEX_READ_BIT
    VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT_KHR = VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT
    VK_ACCESS_2_UNIFORM_READ_BIT_KHR = VK_ACCESS_2_UNIFORM_READ_BIT
    VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT_KHR = VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT
    VK_ACCESS_2_SHADER_READ_BIT_KHR = VK_ACCESS_2_SHADER_READ_BIT
    VK_ACCESS_2_SHADER_WRITE_BIT_KHR = VK_ACCESS_2_SHADER_WRITE_BIT
    VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT_KHR = VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT
    VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT_KHR = VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT
    VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT_KHR = VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT
    VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT_KHR = VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT
    VK_ACCESS_2_TRANSFER_READ_BIT_KHR = VK_ACCESS_2_TRANSFER_READ_BIT
    VK_ACCESS_2_TRANSFER_WRITE_BIT_KHR = VK_ACCESS_2_TRANSFER_WRITE_BIT
    VK_ACCESS_2_HOST_READ_BIT_KHR = VK_ACCESS_2_HOST_READ_BIT
    VK_ACCESS_2_HOST_WRITE_BIT_KHR = VK_ACCESS_2_HOST_WRITE_BIT
    VK_ACCESS_2_MEMORY_READ_BIT_KHR = VK_ACCESS_2_MEMORY_READ_BIT
    VK_ACCESS_2_MEMORY_WRITE_BIT_KHR = VK_ACCESS_2_MEMORY_WRITE_BIT
    VK_ACCESS_2_SHADER_SAMPLED_READ_BIT_KHR = VK_ACCESS_2_SHADER_SAMPLED_READ_BIT
    VK_ACCESS_2_SHADER_STORAGE_READ_BIT_KHR = VK_ACCESS_2_SHADER_STORAGE_READ_BIT
    VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT_KHR = VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT
    VK_ACCESS_2_SHADING_RATE_IMAGE_READ_BIT_NV = VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR
    VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_NV = VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR
    VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_NV = VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR


class VkPipelineStageFlagBits2(Flag):
    VK_PIPELINE_STAGE_2_NONE = 0x0000000000000000
    VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT = 0x0000000000000001
    VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT = 0x0000000000000002
    VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT = 0x0000000000000004
    VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT = 0x0000000000000008
    VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT = 0x0000000000000010
    VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT = 0x0000000000000020
    VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT = 0x0000000000000040
    VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT = 0x0000000000000080
    VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT = 0x0000000000000100
    VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT = 0x0000000000000200
    VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT = 0x0000000000000400
    VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT = 0x0000000000000800
    VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT = 0x0000000000001000
    VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT = 0x0000000000002000
    VK_PIPELINE_STAGE_2_HOST_BIT = 0x0000000000004000
    VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT = 0x0000000000008000
    VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT = 0x0000000000010000
    VK_PIPELINE_STAGE_2_COPY_BIT = 0x0000000100000000
    VK_PIPELINE_STAGE_2_RESOLVE_BIT = 0x0000000200000000
    VK_PIPELINE_STAGE_2_BLIT_BIT = 0x0000000400000000
    VK_PIPELINE_STAGE_2_CLEAR_BIT = 0x0000000800000000
    VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT = 0x0000001000000000
    VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT = 0x0000002000000000
    VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT = 0x0000004000000000
    VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR = 0x0000000004000000
    VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR = 0x0000000008000000
    VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT = 0x0000000001000000
    VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT = 0x0000000000040000
    VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV = 0x0000000000020000
    VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR = 0x0000000000400000
    VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR = 0x0000000002000000
    VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR = 0x0000000000200000
    VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT = 0x0000000000800000
    VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT = 0x0000000000080000
    VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT = 0x0000000000100000
    VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI = 0x0000008000000000
    VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI = 0x0000010000000000
    VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR = 0x0000000010000000
    VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT = 0x0000000040000000
    VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI = 0x0000020000000000
    VK_PIPELINE_STAGE_2_RESERVED_43_BIT_ARM = 0x0000080000000000
    VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV = 0x0000000020000000
    VK_PIPELINE_STAGE_2_RESERVED_42_BIT_EXT = 0x0000040000000000
    VK_PIPELINE_STAGE_2_NONE_KHR = VK_PIPELINE_STAGE_2_NONE
    VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT_KHR = VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT
    VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT_KHR = VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT
    VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT_KHR = VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT
    VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT_KHR = VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT
    VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT_KHR = VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT
    VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT_KHR = VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT
    VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT_KHR = VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT
    VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT_KHR = VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT
    VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT_KHR = VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT
    VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT_KHR = VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT
    VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT_KHR = VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT
    VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT_KHR = VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT
    VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT_KHR = VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT
    VK_PIPELINE_STAGE_2_TRANSFER_BIT = VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT_KHR
    VK_PIPELINE_STAGE_2_TRANSFER_BIT_KHR = VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT
    VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT_KHR = VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT
    VK_PIPELINE_STAGE_2_HOST_BIT_KHR = VK_PIPELINE_STAGE_2_HOST_BIT
    VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT_KHR = VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT
    VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT_KHR = VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT
    VK_PIPELINE_STAGE_2_COPY_BIT_KHR = VK_PIPELINE_STAGE_2_COPY_BIT
    VK_PIPELINE_STAGE_2_RESOLVE_BIT_KHR = VK_PIPELINE_STAGE_2_RESOLVE_BIT
    VK_PIPELINE_STAGE_2_BLIT_BIT_KHR = VK_PIPELINE_STAGE_2_BLIT_BIT
    VK_PIPELINE_STAGE_2_CLEAR_BIT_KHR = VK_PIPELINE_STAGE_2_CLEAR_BIT
    VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT_KHR = VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT
    VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT_KHR = VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT
    VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT_KHR = VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT
    VK_PIPELINE_STAGE_2_SHADING_RATE_IMAGE_BIT_NV = VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR
    VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_NV = VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR
    VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_NV = VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR
    VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_NV = VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT
    VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_NV = VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT
    VK_PIPELINE_STAGE_2_SUBPASS_SHADING_BIT_HUAWEI = VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI


class VkProvokingVertexModeEXT(Enum):
    VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT = 0
    VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT = 1

class VkPipelineCacheValidationVersion(Enum):
    VK_PIPELINE_CACHE_VALIDATION_VERSION_SAFETY_CRITICAL_ONE = 1

class VkImageFormatConstraintsFlagBitsFUCHSIA(Flag):
    pass

class VkHostImageCopyFlagBitsEXT(Flag):
    VK_HOST_IMAGE_COPY_MEMCPY_EXT = 0x00000001

class VkImageConstraintsInfoFlagBitsFUCHSIA(Flag):
    VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_RARELY_FUCHSIA = 0x00000001
    VK_IMAGE_CONSTRAINTS_INFO_CPU_READ_OFTEN_FUCHSIA = 0x00000002
    VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_RARELY_FUCHSIA = 0x00000004
    VK_IMAGE_CONSTRAINTS_INFO_CPU_WRITE_OFTEN_FUCHSIA = 0x00000008
    VK_IMAGE_CONSTRAINTS_INFO_PROTECTED_OPTIONAL_FUCHSIA = 0x00000010

class VkFormatFeatureFlagBits2(Flag):
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT = 0x0000000000000001
    VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT = 0x0000000000000002
    VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT = 0x0000000000000004
    VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT = 0x0000000000000008
    VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT = 0x0000000000000010
    VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT = 0x0000000000000020
    VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT = 0x0000000000000040
    VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT = 0x0000000000000080
    VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT = 0x0000000000000100
    VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT = 0x0000000000000200
    VK_FORMAT_FEATURE_2_BLIT_SRC_BIT = 0x0000000000000400
    VK_FORMAT_FEATURE_2_BLIT_DST_BIT = 0x0000000000000800
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT = 0x0000000000001000
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT = 0x0000000000002000
    VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT = 0x0000000000004000
    VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT = 0x0000000000008000
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT = 0x0000000000010000
    VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT = 0x0000000000020000
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT = 0x0000000000040000
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT = 0x0000000000080000
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT = 0x0000000000100000
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT = 0x0000000000200000
    VK_FORMAT_FEATURE_2_DISJOINT_BIT = 0x0000000000400000
    VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT = 0x0000000000800000
    VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT = 0x0000000080000000
    VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT = 0x0000000100000000
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT = 0x0000000200000000
    VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR = 0x0000000002000000
    VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR = 0x0000000004000000
    VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR = 0x0000000020000000
    VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT = 0x0000000001000000
    VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR = 0x0000000040000000
    VK_FORMAT_FEATURE_2_RESERVED_44_BIT_EXT = 0x0000100000000000
    VK_FORMAT_FEATURE_2_RESERVED_45_BIT_EXT = 0x0000200000000000
    VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT = 0x0000400000000000
    VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR = 0x0000000008000000
    VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR = 0x0000000010000000
    VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV = 0x0000004000000000
    VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM = 0x0000000400000000
    VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM = 0x0000000800000000
    VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM = 0x0000001000000000
    VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM = 0x0000002000000000
    VK_FORMAT_FEATURE_2_RESERVED_47_BIT_ARM = 0x0000800000000000
    VK_FORMAT_FEATURE_2_RESERVED_39_BIT_EXT = 0x0000008000000000
    VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV = 0x0000010000000000
    VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV = 0x0000020000000000
    VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV = 0x0000040000000000
    VK_FORMAT_FEATURE_2_RESERVED_48_BIT_EXT = 0x0001000000000000
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT_KHR = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT
    VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT_KHR = VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT
    VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT_KHR = VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT
    VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT_KHR = VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT
    VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT_KHR = VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT
    VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT_KHR = VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT
    VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT_KHR = VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT
    VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT_KHR = VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT
    VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT_KHR = VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT
    VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT_KHR = VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT
    VK_FORMAT_FEATURE_2_BLIT_SRC_BIT_KHR = VK_FORMAT_FEATURE_2_BLIT_SRC_BIT
    VK_FORMAT_FEATURE_2_BLIT_DST_BIT_KHR = VK_FORMAT_FEATURE_2_BLIT_DST_BIT
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT_KHR = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT
    VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT_KHR = VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT
    VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT_KHR = VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT_KHR = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT
    VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT_KHR = VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT_KHR = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT_KHR = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT_KHR = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT_KHR = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT
    VK_FORMAT_FEATURE_2_DISJOINT_BIT_KHR = VK_FORMAT_FEATURE_2_DISJOINT_BIT
    VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT_KHR = VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT
    VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT_KHR = VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT
    VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT_KHR = VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT
    VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT_KHR = VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT


class VkRenderingFlagBits(Flag):
    VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT = 0x00000001
    VK_RENDERING_SUSPENDING_BIT = 0x00000002
    VK_RENDERING_RESUMING_BIT = 0x00000004
    VK_RENDERING_CONTENTS_INLINE_BIT_EXT = 0x00000010
    VK_RENDERING_ENABLE_LEGACY_DITHERING_BIT_EXT = 0x00000008
    VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT_KHR = VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT
    VK_RENDERING_SUSPENDING_BIT_KHR = VK_RENDERING_SUSPENDING_BIT
    VK_RENDERING_RESUMING_BIT_KHR = VK_RENDERING_RESUMING_BIT


class VkPipelineDepthStencilStateCreateFlagBits(Flag):
    VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT = 0x00000001
    VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT = 0x00000002
    VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_ARM = VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT
    VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_ARM = VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT

class VkPipelineColorBlendStateCreateFlagBits(Flag):
    VK_PIPELINE_COLOR_BLEND_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_BIT_EXT = 0x00000001
    VK_PIPELINE_COLOR_BLEND_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_BIT_ARM = VK_PIPELINE_COLOR_BLEND_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_BIT_EXT

class VkImageCompressionFlagBitsEXT(Flag):
    VK_IMAGE_COMPRESSION_DEFAULT_EXT = 0x00000000
    VK_IMAGE_COMPRESSION_FIXED_RATE_DEFAULT_EXT = 0x00000001
    VK_IMAGE_COMPRESSION_FIXED_RATE_EXPLICIT_EXT = 0x00000002
    VK_IMAGE_COMPRESSION_DISABLED_EXT = 0x00000004

class VkImageCompressionFixedRateFlagBitsEXT(Flag):
    VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT = 0x00000000
    VK_IMAGE_COMPRESSION_FIXED_RATE_1BPC_BIT_EXT = 0x00000001
    VK_IMAGE_COMPRESSION_FIXED_RATE_2BPC_BIT_EXT = 0x00000002
    VK_IMAGE_COMPRESSION_FIXED_RATE_3BPC_BIT_EXT = 0x00000004
    VK_IMAGE_COMPRESSION_FIXED_RATE_4BPC_BIT_EXT = 0x00000008
    VK_IMAGE_COMPRESSION_FIXED_RATE_5BPC_BIT_EXT = 0x00000010
    VK_IMAGE_COMPRESSION_FIXED_RATE_6BPC_BIT_EXT = 0x00000020
    VK_IMAGE_COMPRESSION_FIXED_RATE_7BPC_BIT_EXT = 0x00000040
    VK_IMAGE_COMPRESSION_FIXED_RATE_8BPC_BIT_EXT = 0x00000080
    VK_IMAGE_COMPRESSION_FIXED_RATE_9BPC_BIT_EXT = 0x00000100
    VK_IMAGE_COMPRESSION_FIXED_RATE_10BPC_BIT_EXT = 0x00000200
    VK_IMAGE_COMPRESSION_FIXED_RATE_11BPC_BIT_EXT = 0x00000400
    VK_IMAGE_COMPRESSION_FIXED_RATE_12BPC_BIT_EXT = 0x00000800
    VK_IMAGE_COMPRESSION_FIXED_RATE_13BPC_BIT_EXT = 0x00001000
    VK_IMAGE_COMPRESSION_FIXED_RATE_14BPC_BIT_EXT = 0x00002000
    VK_IMAGE_COMPRESSION_FIXED_RATE_15BPC_BIT_EXT = 0x00004000
    VK_IMAGE_COMPRESSION_FIXED_RATE_16BPC_BIT_EXT = 0x00008000
    VK_IMAGE_COMPRESSION_FIXED_RATE_17BPC_BIT_EXT = 0x00010000
    VK_IMAGE_COMPRESSION_FIXED_RATE_18BPC_BIT_EXT = 0x00020000
    VK_IMAGE_COMPRESSION_FIXED_RATE_19BPC_BIT_EXT = 0x00040000
    VK_IMAGE_COMPRESSION_FIXED_RATE_20BPC_BIT_EXT = 0x00080000
    VK_IMAGE_COMPRESSION_FIXED_RATE_21BPC_BIT_EXT = 0x00100000
    VK_IMAGE_COMPRESSION_FIXED_RATE_22BPC_BIT_EXT = 0x00200000
    VK_IMAGE_COMPRESSION_FIXED_RATE_23BPC_BIT_EXT = 0x00400000
    VK_IMAGE_COMPRESSION_FIXED_RATE_24BPC_BIT_EXT = 0x00800000

class VkExportMetalObjectTypeFlagBitsEXT(Flag):
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_DEVICE_BIT_EXT = 0x00000001
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_COMMAND_QUEUE_BIT_EXT = 0x00000002
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_BUFFER_BIT_EXT = 0x00000004
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_TEXTURE_BIT_EXT = 0x00000008
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_IOSURFACE_BIT_EXT = 0x00000010
    VK_EXPORT_METAL_OBJECT_TYPE_METAL_SHARED_EVENT_BIT_EXT = 0x00000020

class VkPipelineRobustnessBufferBehaviorEXT(Enum):
    VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT_EXT = 0
    VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED_EXT = 1
    VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_EXT = 2
    VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2_EXT = 3

class VkPipelineRobustnessImageBehaviorEXT(Enum):
    VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT_EXT = 0
    VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED_EXT = 1
    VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_EXT = 2
    VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2_EXT = 3

class VkDeviceAddressBindingFlagBitsEXT(Flag):
    VK_DEVICE_ADDRESS_BINDING_INTERNAL_OBJECT_BIT_EXT = 0x00000001

class VkDeviceAddressBindingTypeEXT(Enum):
    VK_DEVICE_ADDRESS_BINDING_TYPE_BIND_EXT = 0
    VK_DEVICE_ADDRESS_BINDING_TYPE_UNBIND_EXT = 1

class VkMicromapTypeEXT(Enum):
    VK_MICROMAP_TYPE_OPACITY_MICROMAP_EXT = 0
    VK_MICROMAP_TYPE_DISPLACEMENT_MICROMAP_NV = 1000397000

class VkBuildMicromapModeEXT(Enum):
    VK_BUILD_MICROMAP_MODE_BUILD_EXT = 0

class VkCopyMicromapModeEXT(Enum):
    VK_COPY_MICROMAP_MODE_CLONE_EXT = 0
    VK_COPY_MICROMAP_MODE_SERIALIZE_EXT = 1
    VK_COPY_MICROMAP_MODE_DESERIALIZE_EXT = 2
    VK_COPY_MICROMAP_MODE_COMPACT_EXT = 3

class VkBuildMicromapFlagBitsEXT(Flag):
    VK_BUILD_MICROMAP_PREFER_FAST_TRACE_BIT_EXT = 0x00000001
    VK_BUILD_MICROMAP_PREFER_FAST_BUILD_BIT_EXT = 0x00000002
    VK_BUILD_MICROMAP_ALLOW_COMPACTION_BIT_EXT = 0x00000004

class VkMicromapCreateFlagBitsEXT(Flag):
    VK_MICROMAP_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT = 0x00000001

class VkOpacityMicromapFormatEXT(Enum):
    VK_OPACITY_MICROMAP_FORMAT_2_STATE_EXT = 1
    VK_OPACITY_MICROMAP_FORMAT_4_STATE_EXT = 2

class VkOpacityMicromapSpecialIndexEXT(Enum):
    VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT_EXT = -1
    VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE_EXT = -2
    VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT_EXT = -3
    VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE_EXT = -4

class VkDeviceFaultVendorBinaryHeaderVersionEXT(Enum):
    VK_DEVICE_FAULT_VENDOR_BINARY_HEADER_VERSION_ONE_EXT = 1

class VkFrameBoundaryFlagBitsEXT(Flag):
    VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT = 0x00000001

class VkMemoryDecompressionMethodFlagBitsNV(Flag):
    VK_MEMORY_DECOMPRESSION_METHOD_GDEFLATE_1_0_BIT_NV = 0x0000000000000001

class VkDepthBiasRepresentationEXT(Enum):
    VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORMAT_EXT = 0
    VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORCE_UNORM_EXT = 1
    VK_DEPTH_BIAS_REPRESENTATION_FLOAT_EXT = 2

class VkDirectDriverLoadingModeLUNARG(Enum):
    VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG = 0
    VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG = 1

class VkPipelineCreateFlagBits2KHR(Flag):
    VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT_KHR = 0x0000000000000001
    VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT_KHR = 0x0000000000000002
    VK_PIPELINE_CREATE_2_DERIVATIVE_BIT_KHR = 0x0000000000000004
    VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR = 0x0000000000000008
    VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT_KHR = 0x0000000000000010
    VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV = 0x0000000000000020
    VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR = 0x0000000000000040
    VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR = 0x0000000000000080
    VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_KHR = 0x0000000000000100
    VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT_KHR = 0x0000000000000200
    VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT = 0x0000000000000400
    VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT = 0x0000000000800000
    VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR = 0x0000000000000800
    VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR = 0x0000000000001000
    VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR = 0x0000000000002000
    VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR = 0x0000000000004000
    VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR = 0x0000000000008000
    VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR = 0x0000000000010000
    VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR = 0x0000000000020000
    VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR = 0x0000000000080000
    VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV = 0x0000000000040000
    VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV = 0x0000000000100000
    VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR = 0x0000000000200000
    VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT = 0x0000000000400000
    VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT = 0x0000000001000000
    VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT = 0x0000000002000000
    VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT = 0x0000000004000000
    VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT_EXT = 0x0000000008000000
    VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT_EXT = 0x0000000040000000
    VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV = 0x0000000010000000
    VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT = 0x0000000020000000
    VK_PIPELINE_CREATE_2_RESERVED_32_BIT_KHR = 0x0000000100000000
    VK_PIPELINE_CREATE_2_RESERVED_31_BIT_KHR = 0x0000000080000000

class VkBufferUsageFlagBits2KHR(Flag):
    VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT_KHR = 0x0000000000000001
    VK_BUFFER_USAGE_2_TRANSFER_DST_BIT_KHR = 0x0000000000000002
    VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT_KHR = 0x0000000000000004
    VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT_KHR = 0x0000000000000008
    VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT_KHR = 0x0000000000000010
    VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT_KHR = 0x0000000000000020
    VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT_KHR = 0x0000000000000040
    VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT_KHR = 0x0000000000000080
    VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT_KHR = 0x0000000000000100
    VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX = 0x0000000002000000
    VK_BUFFER_USAGE_2_RESERVED_28_BIT_KHR = 0x0000000010000000
    VK_BUFFER_USAGE_2_RESERVED_29_BIT_KHR = 0x0000000020000000
    VK_BUFFER_USAGE_2_RESERVED_30_BIT_KHR = 0x0000000040000000
    VK_BUFFER_USAGE_2_RESERVED_27_BIT_QCOM = 0x0000000008000000
    VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT = 0x0000000000000200
    VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR = 0x0000000000000400
    VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT = 0x0000000000000800
    VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT = 0x0000000000001000
    VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR = 0x0000000000002000
    VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR = 0x0000000000004000
    VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR = 0x0000000000008000
    VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR = 0x0000000000010000
    VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT_KHR = 0x0000000000020000
    VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR = 0x0000000000080000
    VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR = 0x0000000000100000
    VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT = 0x0000000000200000
    VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT = 0x0000000000400000
    VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT = 0x0000000004000000
    VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT = 0x0000000000800000
    VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT = 0x0000000001000000
    VK_BUFFER_USAGE_2_RAY_TRACING_BIT_NV = VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR

class VkDisplacementMicromapFormatNV(Enum):
    VK_DISPLACEMENT_MICROMAP_FORMAT_64_TRIANGLES_64_BYTES_NV = 1
    VK_DISPLACEMENT_MICROMAP_FORMAT_256_TRIANGLES_128_BYTES_NV = 2
    VK_DISPLACEMENT_MICROMAP_FORMAT_1024_TRIANGLES_128_BYTES_NV = 3

class VkShaderCreateFlagBitsEXT(Flag):
    VK_SHADER_CREATE_LINK_STAGE_BIT_EXT = 0x00000001
    VK_SHADER_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT = 0x00000002
    VK_SHADER_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT = 0x00000004
    VK_SHADER_CREATE_NO_TASK_SHADER_BIT_EXT = 0x00000008
    VK_SHADER_CREATE_DISPATCH_BASE_BIT_EXT = 0x00000010
    VK_SHADER_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_EXT = 0x00000020
    VK_SHADER_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT = 0x00000040

class VkShaderCodeTypeEXT(Enum):
    VK_SHADER_CODE_TYPE_BINARY_EXT = 0
    VK_SHADER_CODE_TYPE_SPIRV_EXT = 1

class VkScopeKHR(Enum):
    VK_SCOPE_DEVICE_KHR = 1
    VK_SCOPE_WORKGROUP_KHR = 2
    VK_SCOPE_SUBGROUP_KHR = 3
    VK_SCOPE_QUEUE_FAMILY_KHR = 5
    VK_SCOPE_DEVICE_NV = VK_SCOPE_DEVICE_KHR
    VK_SCOPE_WORKGROUP_NV = VK_SCOPE_WORKGROUP_KHR
    VK_SCOPE_SUBGROUP_NV = VK_SCOPE_SUBGROUP_KHR
    VK_SCOPE_QUEUE_FAMILY_NV = VK_SCOPE_QUEUE_FAMILY_KHR

class VkComponentTypeKHR(Enum):
    VK_COMPONENT_TYPE_FLOAT16_KHR = 0
    VK_COMPONENT_TYPE_FLOAT32_KHR = 1
    VK_COMPONENT_TYPE_FLOAT64_KHR = 2
    VK_COMPONENT_TYPE_SINT8_KHR = 3
    VK_COMPONENT_TYPE_SINT16_KHR = 4
    VK_COMPONENT_TYPE_SINT32_KHR = 5
    VK_COMPONENT_TYPE_SINT64_KHR = 6
    VK_COMPONENT_TYPE_UINT8_KHR = 7
    VK_COMPONENT_TYPE_UINT16_KHR = 8
    VK_COMPONENT_TYPE_UINT32_KHR = 9
    VK_COMPONENT_TYPE_UINT64_KHR = 10
    VK_COMPONENT_TYPE_FLOAT16_NV = VK_COMPONENT_TYPE_FLOAT16_KHR
    VK_COMPONENT_TYPE_FLOAT32_NV = VK_COMPONENT_TYPE_FLOAT32_KHR
    VK_COMPONENT_TYPE_FLOAT64_NV = VK_COMPONENT_TYPE_FLOAT64_KHR
    VK_COMPONENT_TYPE_SINT8_NV = VK_COMPONENT_TYPE_SINT8_KHR
    VK_COMPONENT_TYPE_SINT16_NV = VK_COMPONENT_TYPE_SINT16_KHR
    VK_COMPONENT_TYPE_SINT32_NV = VK_COMPONENT_TYPE_SINT32_KHR
    VK_COMPONENT_TYPE_SINT64_NV = VK_COMPONENT_TYPE_SINT64_KHR
    VK_COMPONENT_TYPE_UINT8_NV = VK_COMPONENT_TYPE_UINT8_KHR
    VK_COMPONENT_TYPE_UINT16_NV = VK_COMPONENT_TYPE_UINT16_KHR
    VK_COMPONENT_TYPE_UINT32_NV = VK_COMPONENT_TYPE_UINT32_KHR
    VK_COMPONENT_TYPE_UINT64_NV = VK_COMPONENT_TYPE_UINT64_KHR



class VkCubicFilterWeightsQCOM(Enum):
    VK_CUBIC_FILTER_WEIGHTS_CATMULL_ROM_QCOM = 0
    VK_CUBIC_FILTER_WEIGHTS_ZERO_TANGENT_CARDINAL_QCOM = 1
    VK_CUBIC_FILTER_WEIGHTS_B_SPLINE_QCOM = 2
    VK_CUBIC_FILTER_WEIGHTS_MITCHELL_NETRAVALI_QCOM = 3

class VkBlockMatchWindowCompareModeQCOM(Enum):
    VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MIN_QCOM = 0
    VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MAX_QCOM = 1

class VkLayeredDriverUnderlyingApiMSFT(Enum):
    VK_LAYERED_DRIVER_UNDERLYING_API_NONE_MSFT = 0
    VK_LAYERED_DRIVER_UNDERLYING_API_D3D12_MSFT = 1

class VkColorSpaceKHR(Enum):
    VK_COLOR_SPACE_SRGB_NONLINEAR_KHR = 0
    VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT = 1000104001
    VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT = 1000104002
    VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT = 1000104003
    VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT = 1000104004
    VK_COLOR_SPACE_BT709_LINEAR_EXT = 1000104005
    VK_COLOR_SPACE_BT709_NONLINEAR_EXT = 1000104006
    VK_COLOR_SPACE_BT2020_LINEAR_EXT = 1000104007
    VK_COLOR_SPACE_HDR10_ST2084_EXT = 1000104008
    VK_COLOR_SPACE_DOLBYVISION_EXT = 1000104009
    VK_COLOR_SPACE_HDR10_HLG_EXT = 1000104010
    VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT = 1000104011
    VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT = 1000104012
    VK_COLOR_SPACE_PASS_THROUGH_EXT = 1000104013
    VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT = 1000104014
    VK_COLOR_SPACE_DISPLAY_NATIVE_AMD = 1000213000
    VK_COLORSPACE_SRGB_NONLINEAR_KHR = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR
    VK_COLOR_SPACE_DCI_P3_LINEAR_EXT = VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT

class VkCompositeAlphaFlagBitsKHR(Flag):
    VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR = 0x00000001
    VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR = 0x00000002
    VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR = 0x00000004
    VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR = 0x00000008

class VkDisplayPlaneAlphaFlagBitsKHR(Flag):
    VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR = 0x00000001
    VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR = 0x00000002
    VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR = 0x00000004
    VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR = 0x00000008

class VkPresentModeKHR(Enum):
    VK_PRESENT_MODE_IMMEDIATE_KHR = 0
    VK_PRESENT_MODE_MAILBOX_KHR = 1
    VK_PRESENT_MODE_FIFO_KHR = 2
    VK_PRESENT_MODE_FIFO_RELAXED_KHR = 3
    VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR = 1000111000
    VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR = 1000111001

class VkSurfaceTransformFlagBitsKHR(Flag):
    VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR = 0x00000001
    VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR = 0x00000002
    VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR = 0x00000004
    VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR = 0x00000008
    VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR = 0x00000010
    VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR = 0x00000020
    VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR = 0x00000040
    VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR = 0x00000080
    VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR = 0x00000100

class VkDebugReportFlagBitsEXT(Flag):
    VK_DEBUG_REPORT_INFORMATION_BIT_EXT = 0x00000001
    VK_DEBUG_REPORT_WARNING_BIT_EXT = 0x00000002
    VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT = 0x00000004
    VK_DEBUG_REPORT_ERROR_BIT_EXT = 0x00000008
    VK_DEBUG_REPORT_DEBUG_BIT_EXT = 0x00000010

class VkDebugReportObjectTypeEXT(Enum):
    VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT = 0
    VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT = 1
    VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT = 2
    VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT = 3
    VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT = 4
    VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT = 5
    VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT = 6
    VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT = 7
    VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT = 8
    VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT = 9
    VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT = 10
    VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT = 11
    VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT = 12
    VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT = 13
    VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT = 14
    VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT = 15
    VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT = 16
    VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT = 17
    VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT = 18
    VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT = 19
    VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT = 20
    VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT = 21
    VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT = 22
    VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT = 23
    VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT = 24
    VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT = 25
    VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT = 26
    VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT = 27
    VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT = 28
    VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT = 29
    VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT = 30
    VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT = 33
    VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT = 1000156000
    VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT = 1000085000
    VK_DEBUG_REPORT_OBJECT_TYPE_CU_MODULE_NVX_EXT = 1000029000
    VK_DEBUG_REPORT_OBJECT_TYPE_CU_FUNCTION_NVX_EXT = 1000029001
    VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT = 1000150000
    VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT = 1000165000
    VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_MODULE_NV_EXT = 1000307000
    VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_FUNCTION_NV_EXT = 1000307001
    VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA_EXT = 1000366000
    VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT = VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT
    VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT = VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT
    VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR_EXT = VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT
    VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR_EXT = VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT

class VkDeviceMemoryReportEventTypeEXT(Enum):
    VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT = 0
    VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT = 1
    VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT = 2
    VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT = 3
    VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT = 4

class VkRasterizationOrderAMD(Enum):
    VK_RASTERIZATION_ORDER_STRICT_AMD = 0
    VK_RASTERIZATION_ORDER_RELAXED_AMD = 1

class VkExternalMemoryHandleTypeFlagBitsNV(Flag):
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV = 0x00000001
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV = 0x00000002
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV = 0x00000004
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV = 0x00000008

class VkExternalMemoryFeatureFlagBitsNV(Flag):
    VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV = 0x00000001
    VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV = 0x00000002
    VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV = 0x00000004

class VkValidationCheckEXT(Enum):
    VK_VALIDATION_CHECK_ALL_EXT = 0
    VK_VALIDATION_CHECK_SHADERS_EXT = 1

class VkValidationFeatureEnableEXT(Enum):
    VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT = 0
    VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT = 1
    VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT = 2
    VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT = 3
    VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT = 4

class VkValidationFeatureDisableEXT(Enum):
    VK_VALIDATION_FEATURE_DISABLE_ALL_EXT = 0
    VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT = 1
    VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT = 2
    VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT = 3
    VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT = 4
    VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT = 5
    VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT = 6
    VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT = 7

class VkExternalMemoryHandleTypeFlagBits(Flag):
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT = 0x00000001
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT = 0x00000002
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT = 0x00000004
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT = 0x00000008
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT = 0x00000010
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT = 0x00000020
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT = 0x00000040
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT = 0x00000200
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID = 0x00000400
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT = 0x00000080
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT = 0x00000100
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA = 0x00000800
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_RDMA_ADDRESS_BIT_NV = 0x00001000
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_SCI_BUF_BIT_NV = 0x00002000
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_SCREEN_BUFFER_BIT_QNX = 0x00004000
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT_KHR = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT_KHR = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT_KHR = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT_KHR = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT
    VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT_KHR = VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT


class VkExternalMemoryFeatureFlagBits(Flag):
    VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT = 0x00000001
    VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT = 0x00000002
    VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT = 0x00000004
    VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_KHR = VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT
    VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_KHR = VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT
    VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_KHR = VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT


class VkExternalSemaphoreHandleTypeFlagBits(Flag):
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT = 0x00000001
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT = 0x00000002
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT = 0x00000004
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT = 0x00000008
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT = 0x00000010
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA = 0x00000080
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SCI_SYNC_OBJ_BIT_NV = 0x00000020
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE_BIT = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT
    VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR = VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT


class VkExternalSemaphoreFeatureFlagBits(Flag):
    VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT = 0x00000001
    VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT = 0x00000002
    VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT_KHR = VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT
    VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT_KHR = VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT


class VkSemaphoreImportFlagBits(Flag):
    VK_SEMAPHORE_IMPORT_TEMPORARY_BIT = 0x00000001
    VK_SEMAPHORE_IMPORT_TEMPORARY_BIT_KHR = VK_SEMAPHORE_IMPORT_TEMPORARY_BIT


class VkExternalFenceHandleTypeFlagBits(Flag):
    VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT = 0x00000001
    VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT = 0x00000002
    VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT = 0x00000004
    VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT = 0x00000008
    VK_EXTERNAL_FENCE_HANDLE_TYPE_SCI_SYNC_OBJ_BIT_NV = 0x00000010
    VK_EXTERNAL_FENCE_HANDLE_TYPE_SCI_SYNC_FENCE_BIT_NV = 0x00000020
    VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT
    VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT
    VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR = VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT
    VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT_KHR = VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT


class VkExternalFenceFeatureFlagBits(Flag):
    VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT = 0x00000001
    VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT = 0x00000002
    VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT_KHR = VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT
    VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT_KHR = VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT


class VkFenceImportFlagBits(Flag):
    VK_FENCE_IMPORT_TEMPORARY_BIT = 0x00000001
    VK_FENCE_IMPORT_TEMPORARY_BIT_KHR = VK_FENCE_IMPORT_TEMPORARY_BIT


class VkSurfaceCounterFlagBitsEXT(Flag):
    VK_SURFACE_COUNTER_VBLANK_BIT_EXT = 0x00000001
    VK_SURFACE_COUNTER_VBLANK_EXT = VK_SURFACE_COUNTER_VBLANK_BIT_EXT

class VkDisplayPowerStateEXT(Enum):
    VK_DISPLAY_POWER_STATE_OFF_EXT = 0
    VK_DISPLAY_POWER_STATE_SUSPEND_EXT = 1
    VK_DISPLAY_POWER_STATE_ON_EXT = 2

class VkDeviceEventTypeEXT(Enum):
    VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT = 0

class VkDisplayEventTypeEXT(Enum):
    VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT = 0

class VkPeerMemoryFeatureFlagBits(Flag):
    VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT = 0x00000001
    VK_PEER_MEMORY_FEATURE_COPY_DST_BIT = 0x00000002
    VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT = 0x00000004
    VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT = 0x00000008
    VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT_KHR = VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT
    VK_PEER_MEMORY_FEATURE_COPY_DST_BIT_KHR = VK_PEER_MEMORY_FEATURE_COPY_DST_BIT
    VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT_KHR = VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT
    VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT_KHR = VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT


class VkMemoryAllocateFlagBits(Flag):
    VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT = 0x00000001
    VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT = 0x00000002
    VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT = 0x00000004
    VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT_KHR = VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT
    VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT_KHR = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT
    VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT


class VkDeviceGroupPresentModeFlagBitsKHR(Flag):
    VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR = 0x00000001
    VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR = 0x00000002
    VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR = 0x00000004
    VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR = 0x00000008

class VkSwapchainCreateFlagBitsKHR(Flag):
    VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR = 0x00000001
    VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR = 0x00000002
    VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR = 0x00000004
    VK_SWAPCHAIN_CREATE_DEFERRED_MEMORY_ALLOCATION_BIT_EXT = 0x00000008
    VK_SWAPCHAIN_CREATE_RESERVED_4_BIT_EXT = 0x00000010

class VkSubgroupFeatureFlagBits(Flag):
    VK_SUBGROUP_FEATURE_BASIC_BIT = 0x00000001
    VK_SUBGROUP_FEATURE_VOTE_BIT = 0x00000002
    VK_SUBGROUP_FEATURE_ARITHMETIC_BIT = 0x00000004
    VK_SUBGROUP_FEATURE_BALLOT_BIT = 0x00000008
    VK_SUBGROUP_FEATURE_SHUFFLE_BIT = 0x00000010
    VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT = 0x00000020
    VK_SUBGROUP_FEATURE_CLUSTERED_BIT = 0x00000040
    VK_SUBGROUP_FEATURE_QUAD_BIT = 0x00000080
    VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV = 0x00000100

class VkTessellationDomainOrigin(Enum):
    VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT = 0
    VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT = 1
    VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT_KHR = VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT
    VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT_KHR = VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT


class VkSamplerYcbcrModelConversion(Enum):
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY = 0
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY = 1
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709 = 2
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601 = 3
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020 = 4
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY_KHR = VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY_KHR = VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709_KHR = VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601_KHR = VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601
    VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020_KHR = VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020


class VkSamplerYcbcrRange(Enum):
    VK_SAMPLER_YCBCR_RANGE_ITU_FULL = 0
    VK_SAMPLER_YCBCR_RANGE_ITU_NARROW = 1
    VK_SAMPLER_YCBCR_RANGE_ITU_FULL_KHR = VK_SAMPLER_YCBCR_RANGE_ITU_FULL
    VK_SAMPLER_YCBCR_RANGE_ITU_NARROW_KHR = VK_SAMPLER_YCBCR_RANGE_ITU_NARROW


class VkChromaLocation(Enum):
    VK_CHROMA_LOCATION_COSITED_EVEN = 0
    VK_CHROMA_LOCATION_MIDPOINT = 1
    VK_CHROMA_LOCATION_COSITED_EVEN_KHR = VK_CHROMA_LOCATION_COSITED_EVEN
    VK_CHROMA_LOCATION_MIDPOINT_KHR = VK_CHROMA_LOCATION_MIDPOINT


class VkSamplerReductionMode(Enum):
    VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE = 0
    VK_SAMPLER_REDUCTION_MODE_MIN = 1
    VK_SAMPLER_REDUCTION_MODE_MAX = 2
    VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_RANGECLAMP_QCOM = 1000521000
    VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_EXT = VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE
    VK_SAMPLER_REDUCTION_MODE_MIN_EXT = VK_SAMPLER_REDUCTION_MODE_MIN
    VK_SAMPLER_REDUCTION_MODE_MAX_EXT = VK_SAMPLER_REDUCTION_MODE_MAX


class VkBlendOverlapEXT(Enum):
    VK_BLEND_OVERLAP_UNCORRELATED_EXT = 0
    VK_BLEND_OVERLAP_DISJOINT_EXT = 1
    VK_BLEND_OVERLAP_CONJOINT_EXT = 2

class VkDebugUtilsMessageSeverityFlagBitsEXT(Flag):
    VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT = 0x00000001
    VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT = 0x00000010
    VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT = 0x00000100
    VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT = 0x00001000

class VkDebugUtilsMessageTypeFlagBitsEXT(Flag):
    VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT = 0x00000001
    VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT = 0x00000002
    VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT = 0x00000004
    VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT = 0x00000008

class VkFullScreenExclusiveEXT(Enum):
    VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT = 0
    VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT = 1
    VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT = 2
    VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT = 3

class VkShaderFloatControlsIndependence(Enum):
    VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY = 0
    VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL = 1
    VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE = 2
    VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY_KHR = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY
    VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL_KHR = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL
    VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE_KHR = VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE


class VkSwapchainImageUsageFlagBitsANDROID(Flag):
    VK_SWAPCHAIN_IMAGE_USAGE_SHARED_BIT_ANDROID = 0x00000001

class VkFragmentShadingRateCombinerOpKHR(Enum):
    VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR = 0
    VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR = 1
    VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR = 2
    VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR = 3
    VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR = 4

class VkSubmitFlagBits(Flag):
    VK_SUBMIT_PROTECTED_BIT = 0x00000001
    VK_SUBMIT_PROTECTED_BIT_KHR = VK_SUBMIT_PROTECTED_BIT


class VkGraphicsPipelineLibraryFlagBitsEXT(Flag):
    VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT = 0x00000001
    VK_GRAPHICS_PIPELINE_LIBRARY_PRE_RASTERIZATION_SHADERS_BIT_EXT = 0x00000002
    VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_SHADER_BIT_EXT = 0x00000004
    VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_OUTPUT_INTERFACE_BIT_EXT = 0x00000008

class VkOpticalFlowGridSizeFlagBitsNV(Flag):
    VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV = 0x00000000
    VK_OPTICAL_FLOW_GRID_SIZE_1X1_BIT_NV = 0x00000001
    VK_OPTICAL_FLOW_GRID_SIZE_2X2_BIT_NV = 0x00000002
    VK_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_NV = 0x00000004
    VK_OPTICAL_FLOW_GRID_SIZE_8X8_BIT_NV = 0x00000008

class VkOpticalFlowUsageFlagBitsNV(Flag):
    VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV = 0x00000000
    VK_OPTICAL_FLOW_USAGE_INPUT_BIT_NV = 0x00000001
    VK_OPTICAL_FLOW_USAGE_OUTPUT_BIT_NV = 0x00000002
    VK_OPTICAL_FLOW_USAGE_HINT_BIT_NV = 0x00000004
    VK_OPTICAL_FLOW_USAGE_COST_BIT_NV = 0x00000008
    VK_OPTICAL_FLOW_USAGE_GLOBAL_FLOW_BIT_NV = 0x00000010

class VkOpticalFlowPerformanceLevelNV(Enum):
    VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_UNKNOWN_NV = 0
    VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_SLOW_NV = 1
    VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_MEDIUM_NV = 2
    VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_FAST_NV = 3

class VkOpticalFlowSessionBindingPointNV(Enum):
    VK_OPTICAL_FLOW_SESSION_BINDING_POINT_UNKNOWN_NV = 0
    VK_OPTICAL_FLOW_SESSION_BINDING_POINT_INPUT_NV = 1
    VK_OPTICAL_FLOW_SESSION_BINDING_POINT_REFERENCE_NV = 2
    VK_OPTICAL_FLOW_SESSION_BINDING_POINT_HINT_NV = 3
    VK_OPTICAL_FLOW_SESSION_BINDING_POINT_FLOW_VECTOR_NV = 4
    VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_FLOW_VECTOR_NV = 5
    VK_OPTICAL_FLOW_SESSION_BINDING_POINT_COST_NV = 6
    VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_COST_NV = 7
    VK_OPTICAL_FLOW_SESSION_BINDING_POINT_GLOBAL_FLOW_NV = 8

class VkOpticalFlowSessionCreateFlagBitsNV(Flag):
    VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_HINT_BIT_NV = 0x00000001
    VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_COST_BIT_NV = 0x00000002
    VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_GLOBAL_FLOW_BIT_NV = 0x00000004
    VK_OPTICAL_FLOW_SESSION_CREATE_ALLOW_REGIONS_BIT_NV = 0x00000008
    VK_OPTICAL_FLOW_SESSION_CREATE_BOTH_DIRECTIONS_BIT_NV = 0x00000010

class VkOpticalFlowExecuteFlagBitsNV(Flag):
    VK_OPTICAL_FLOW_EXECUTE_DISABLE_TEMPORAL_HINTS_BIT_NV = 0x00000001

class VkDeviceFaultAddressTypeEXT(Enum):
    VK_DEVICE_FAULT_ADDRESS_TYPE_NONE_EXT = 0
    VK_DEVICE_FAULT_ADDRESS_TYPE_READ_INVALID_EXT = 1
    VK_DEVICE_FAULT_ADDRESS_TYPE_WRITE_INVALID_EXT = 2
    VK_DEVICE_FAULT_ADDRESS_TYPE_EXECUTE_INVALID_EXT = 3
    VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_UNKNOWN_EXT = 4
    VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_INVALID_EXT = 5
    VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_FAULT_EXT = 6

class VkPresentScalingFlagBitsEXT(Flag):
    VK_PRESENT_SCALING_ONE_TO_ONE_BIT_EXT = 0x00000001
    VK_PRESENT_SCALING_ASPECT_RATIO_STRETCH_BIT_EXT = 0x00000002
    VK_PRESENT_SCALING_STRETCH_BIT_EXT = 0x00000004

class VkPresentGravityFlagBitsEXT(Flag):
    VK_PRESENT_GRAVITY_MIN_BIT_EXT = 0x00000001
    VK_PRESENT_GRAVITY_MAX_BIT_EXT = 0x00000002
    VK_PRESENT_GRAVITY_CENTERED_BIT_EXT = 0x00000004

class VkLayerSettingTypeEXT(Enum):
    VK_LAYER_SETTING_TYPE_BOOL32_EXT = 0
    VK_LAYER_SETTING_TYPE_INT32_EXT = 1
    VK_LAYER_SETTING_TYPE_INT64_EXT = 2
    VK_LAYER_SETTING_TYPE_UINT32_EXT = 3
    VK_LAYER_SETTING_TYPE_UINT64_EXT = 4
    VK_LAYER_SETTING_TYPE_FLOAT32_EXT = 5
    VK_LAYER_SETTING_TYPE_FLOAT64_EXT = 6
    VK_LAYER_SETTING_TYPE_STRING_EXT = 7

class VkLatencyMarkerNV(Enum):
    VK_LATENCY_MARKER_SIMULATION_START_NV = 0
    VK_LATENCY_MARKER_SIMULATION_END_NV = 1
    VK_LATENCY_MARKER_RENDERSUBMIT_START_NV = 2
    VK_LATENCY_MARKER_RENDERSUBMIT_END_NV = 3
    VK_LATENCY_MARKER_PRESENT_START_NV = 4
    VK_LATENCY_MARKER_PRESENT_END_NV = 5
    VK_LATENCY_MARKER_INPUT_SAMPLE_NV = 6
    VK_LATENCY_MARKER_TRIGGER_FLASH_NV = 7
    VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_START_NV = 8
    VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_END_NV = 9
    VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_START_NV = 10
    VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_END_NV = 11

class VkOutOfBandQueueTypeNV(Enum):
    VK_OUT_OF_BAND_QUEUE_TYPE_RENDER_NV = 0
    VK_OUT_OF_BAND_QUEUE_TYPE_PRESENT_NV = 1

class VkPhysicalDeviceSchedulingControlsFlagBitsARM(Flag):
    VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM = 0x0000000000000001

class VkVendorId(Enum):
    VK_VENDOR_ID_VIV = 65537
    VK_VENDOR_ID_VSI = 65538
    VK_VENDOR_ID_KAZAN = 65539
    VK_VENDOR_ID_CODEPLAY = 65540
    VK_VENDOR_ID_MESA = 65541
    VK_VENDOR_ID_POCL = 65542
    VK_VENDOR_ID_MOBILEYE = 65543

class VkDriverId(Enum):
    VK_DRIVER_ID_AMD_PROPRIETARY = 1
    VK_DRIVER_ID_AMD_OPEN_SOURCE = 2
    VK_DRIVER_ID_MESA_RADV = 3
    VK_DRIVER_ID_NVIDIA_PROPRIETARY = 4
    VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS = 5
    VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA = 6
    VK_DRIVER_ID_IMAGINATION_PROPRIETARY = 7
    VK_DRIVER_ID_QUALCOMM_PROPRIETARY = 8
    VK_DRIVER_ID_ARM_PROPRIETARY = 9
    VK_DRIVER_ID_GOOGLE_SWIFTSHADER = 10
    VK_DRIVER_ID_GGP_PROPRIETARY = 11
    VK_DRIVER_ID_BROADCOM_PROPRIETARY = 12
    VK_DRIVER_ID_MESA_LLVMPIPE = 13
    VK_DRIVER_ID_MOLTENVK = 14
    VK_DRIVER_ID_COREAVI_PROPRIETARY = 15
    VK_DRIVER_ID_JUICE_PROPRIETARY = 16
    VK_DRIVER_ID_VERISILICON_PROPRIETARY = 17
    VK_DRIVER_ID_MESA_TURNIP = 18
    VK_DRIVER_ID_MESA_V3DV = 19
    VK_DRIVER_ID_MESA_PANVK = 20
    VK_DRIVER_ID_SAMSUNG_PROPRIETARY = 21
    VK_DRIVER_ID_MESA_VENUS = 22
    VK_DRIVER_ID_MESA_DOZEN = 23
    VK_DRIVER_ID_MESA_NVK = 24
    VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA = 25
    VK_DRIVER_ID_MESA_AGXV = 26
    VK_DRIVER_ID_AMD_PROPRIETARY_KHR = VK_DRIVER_ID_AMD_PROPRIETARY
    VK_DRIVER_ID_AMD_OPEN_SOURCE_KHR = VK_DRIVER_ID_AMD_OPEN_SOURCE
    VK_DRIVER_ID_MESA_RADV_KHR = VK_DRIVER_ID_MESA_RADV
    VK_DRIVER_ID_NVIDIA_PROPRIETARY_KHR = VK_DRIVER_ID_NVIDIA_PROPRIETARY
    VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS_KHR = VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS
    VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA_KHR = VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA
    VK_DRIVER_ID_IMAGINATION_PROPRIETARY_KHR = VK_DRIVER_ID_IMAGINATION_PROPRIETARY
    VK_DRIVER_ID_QUALCOMM_PROPRIETARY_KHR = VK_DRIVER_ID_QUALCOMM_PROPRIETARY
    VK_DRIVER_ID_ARM_PROPRIETARY_KHR = VK_DRIVER_ID_ARM_PROPRIETARY
    VK_DRIVER_ID_GOOGLE_SWIFTSHADER_KHR = VK_DRIVER_ID_GOOGLE_SWIFTSHADER
    VK_DRIVER_ID_GGP_PROPRIETARY_KHR = VK_DRIVER_ID_GGP_PROPRIETARY
    VK_DRIVER_ID_BROADCOM_PROPRIETARY_KHR = VK_DRIVER_ID_BROADCOM_PROPRIETARY


class VkShadingRatePaletteEntryNV(Enum):
    VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV = 0
    VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV = 1
    VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV = 2
    VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV = 3
    VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV = 4
    VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV = 5
    VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV = 6
    VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV = 7
    VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV = 8
    VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV = 9
    VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV = 10
    VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV = 11

class VkCoarseSampleOrderTypeNV(Enum):
    VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV = 0
    VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV = 1
    VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV = 2
    VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV = 3

class VkPipelineExecutableStatisticFormatKHR(Enum):
    VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR = 0
    VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR = 1
    VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR = 2
    VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR = 3

class VkVideoCodecOperationFlagBitsKHR(Flag):
    VK_VIDEO_CODEC_OPERATION_NONE_KHR = 0x00000000
    VK_VIDEO_CODEC_OPERATION_ENCODE_H264_BIT_KHR = 0x00010000
    VK_VIDEO_CODEC_OPERATION_ENCODE_H265_BIT_KHR = 0x00020000
    VK_VIDEO_CODEC_OPERATION_DECODE_H264_BIT_KHR = 0x00000001
    VK_VIDEO_CODEC_OPERATION_DECODE_H265_BIT_KHR = 0x00000002

class VkVideoChromaSubsamplingFlagBitsKHR(Flag):
    VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR = 0x00000000
    VK_VIDEO_CHROMA_SUBSAMPLING_MONOCHROME_BIT_KHR = 0x00000001
    VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR = 0x00000002
    VK_VIDEO_CHROMA_SUBSAMPLING_422_BIT_KHR = 0x00000004
    VK_VIDEO_CHROMA_SUBSAMPLING_444_BIT_KHR = 0x00000008

class VkVideoComponentBitDepthFlagBitsKHR(Flag):
    VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR = 0x00000000
    VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR = 0x00000001
    VK_VIDEO_COMPONENT_BIT_DEPTH_10_BIT_KHR = 0x00000004
    VK_VIDEO_COMPONENT_BIT_DEPTH_12_BIT_KHR = 0x00000010

class VkVideoCapabilityFlagBitsKHR(Flag):
    VK_VIDEO_CAPABILITY_PROTECTED_CONTENT_BIT_KHR = 0x00000001
    VK_VIDEO_CAPABILITY_SEPARATE_REFERENCE_IMAGES_BIT_KHR = 0x00000002

class VkVideoSessionCreateFlagBitsKHR(Flag):
    VK_VIDEO_SESSION_CREATE_PROTECTED_CONTENT_BIT_KHR = 0x00000001
    VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS_BIT_KHR = 0x00000002
    VK_VIDEO_SESSION_CREATE_INLINE_QUERIES_BIT_KHR = 0x00000004

class VkVideoCodingControlFlagBitsKHR(Flag):
    VK_VIDEO_CODING_CONTROL_RESET_BIT_KHR = 0x00000001
    VK_VIDEO_CODING_CONTROL_ENCODE_RATE_CONTROL_BIT_KHR = 0x00000002
    VK_VIDEO_CODING_CONTROL_ENCODE_QUALITY_LEVEL_BIT_KHR = 0x00000004

class VkQueryResultStatusKHR(Enum):
    VK_QUERY_RESULT_STATUS_ERROR_KHR = -1
    VK_QUERY_RESULT_STATUS_NOT_READY_KHR = 0
    VK_QUERY_RESULT_STATUS_COMPLETE_KHR = 1
    VK_QUERY_RESULT_STATUS_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_KHR = 1000299000

class VkVideoDecodeUsageFlagBitsKHR(Flag):
    VK_VIDEO_DECODE_USAGE_DEFAULT_KHR = 0x00000000
    VK_VIDEO_DECODE_USAGE_TRANSCODING_BIT_KHR = 0x00000001
    VK_VIDEO_DECODE_USAGE_OFFLINE_BIT_KHR = 0x00000002
    VK_VIDEO_DECODE_USAGE_STREAMING_BIT_KHR = 0x00000004

class VkVideoDecodeCapabilityFlagBitsKHR(Flag):
    VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR = 0x00000001
    VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR = 0x00000002

class VkVideoDecodeH264PictureLayoutFlagBitsKHR(Flag):
    VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR = 0x00000000
    VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_INTERLEAVED_LINES_BIT_KHR = 0x00000001
    VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_SEPARATE_PLANES_BIT_KHR = 0x00000002

class VkVideoEncodeUsageFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR = 0x00000000
    VK_VIDEO_ENCODE_USAGE_TRANSCODING_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_USAGE_STREAMING_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_USAGE_RECORDING_BIT_KHR = 0x00000004
    VK_VIDEO_ENCODE_USAGE_CONFERENCING_BIT_KHR = 0x00000008

class VkVideoEncodeContentFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR = 0x00000000
    VK_VIDEO_ENCODE_CONTENT_CAMERA_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_CONTENT_DESKTOP_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_CONTENT_RENDERED_BIT_KHR = 0x00000004

class VkVideoEncodeTuningModeKHR(Enum):
    VK_VIDEO_ENCODE_TUNING_MODE_DEFAULT_KHR = 0
    VK_VIDEO_ENCODE_TUNING_MODE_HIGH_QUALITY_KHR = 1
    VK_VIDEO_ENCODE_TUNING_MODE_LOW_LATENCY_KHR = 2
    VK_VIDEO_ENCODE_TUNING_MODE_ULTRA_LOW_LATENCY_KHR = 3
    VK_VIDEO_ENCODE_TUNING_MODE_LOSSLESS_KHR = 4

class VkVideoEncodeCapabilityFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_CAPABILITY_PRECEDING_EXTERNALLY_ENCODED_BYTES_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_CAPABILITY_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_DETECTION_BIT_KHR = 0x00000002

class VkVideoEncodeFeedbackFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BUFFER_OFFSET_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BYTES_WRITTEN_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_HAS_OVERRIDES_BIT_KHR = 0x00000004

class VkVideoEncodeRateControlModeFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR = 0x00000000
    VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DISABLED_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_RATE_CONTROL_MODE_CBR_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_RATE_CONTROL_MODE_VBR_BIT_KHR = 0x00000004

class VkVideoEncodeH264CapabilityFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_H264_CAPABILITY_HRD_COMPLIANCE_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_H264_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_H264_CAPABILITY_ROW_UNALIGNED_SLICE_BIT_KHR = 0x00000004
    VK_VIDEO_ENCODE_H264_CAPABILITY_DIFFERENT_SLICE_TYPE_BIT_KHR = 0x00000008
    VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR = 0x00000010
    VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR = 0x00000020
    VK_VIDEO_ENCODE_H264_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR = 0x00000040
    VK_VIDEO_ENCODE_H264_CAPABILITY_PER_SLICE_CONSTANT_QP_BIT_KHR = 0x00000080
    VK_VIDEO_ENCODE_H264_CAPABILITY_GENERATE_PREFIX_NALU_BIT_KHR = 0x00000100

class VkVideoEncodeH264StdFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_H264_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_H264_STD_QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_H264_STD_SCALING_MATRIX_PRESENT_FLAG_SET_BIT_KHR = 0x00000004
    VK_VIDEO_ENCODE_H264_STD_CHROMA_QP_INDEX_OFFSET_BIT_KHR = 0x00000008
    VK_VIDEO_ENCODE_H264_STD_SECOND_CHROMA_QP_INDEX_OFFSET_BIT_KHR = 0x00000010
    VK_VIDEO_ENCODE_H264_STD_PIC_INIT_QP_MINUS26_BIT_KHR = 0x00000020
    VK_VIDEO_ENCODE_H264_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR = 0x00000040
    VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_EXPLICIT_BIT_KHR = 0x00000080
    VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_IMPLICIT_BIT_KHR = 0x00000100
    VK_VIDEO_ENCODE_H264_STD_TRANSFORM_8X8_MODE_FLAG_SET_BIT_KHR = 0x00000200
    VK_VIDEO_ENCODE_H264_STD_DIRECT_SPATIAL_MV_PRED_FLAG_UNSET_BIT_KHR = 0x00000400
    VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_UNSET_BIT_KHR = 0x00000800
    VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_SET_BIT_KHR = 0x00001000
    VK_VIDEO_ENCODE_H264_STD_DIRECT_8X8_INFERENCE_FLAG_UNSET_BIT_KHR = 0x00002000
    VK_VIDEO_ENCODE_H264_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR = 0x00004000
    VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_DISABLED_BIT_KHR = 0x00008000
    VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_ENABLED_BIT_KHR = 0x00010000
    VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_PARTIAL_BIT_KHR = 0x00020000
    VK_VIDEO_ENCODE_H264_STD_SLICE_QP_DELTA_BIT_KHR = 0x00080000
    VK_VIDEO_ENCODE_H264_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR = 0x00100000

class VkVideoEncodeH264RateControlFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_H264_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_H264_RATE_CONTROL_REGULAR_GOP_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR = 0x00000004
    VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR = 0x00000008
    VK_VIDEO_ENCODE_H264_RATE_CONTROL_TEMPORAL_LAYER_PATTERN_DYADIC_BIT_KHR = 0x00000010

class VkVideoEncodeH265CapabilityFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_H265_CAPABILITY_HRD_COMPLIANCE_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_H265_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_H265_CAPABILITY_ROW_UNALIGNED_SLICE_SEGMENT_BIT_KHR = 0x00000004
    VK_VIDEO_ENCODE_H265_CAPABILITY_DIFFERENT_SLICE_SEGMENT_TYPE_BIT_KHR = 0x00000008
    VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR = 0x00000010
    VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR = 0x00000020
    VK_VIDEO_ENCODE_H265_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR = 0x00000040
    VK_VIDEO_ENCODE_H265_CAPABILITY_PER_SLICE_SEGMENT_CONSTANT_QP_BIT_KHR = 0x00000080
    VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_TILES_PER_SLICE_SEGMENT_BIT_KHR = 0x00000100
    VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_SLICE_SEGMENTS_PER_TILE_BIT_KHR = 0x00000200

class VkVideoEncodeH265StdFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_H265_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_H265_STD_SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_H265_STD_SCALING_LIST_DATA_PRESENT_FLAG_SET_BIT_KHR = 0x00000004
    VK_VIDEO_ENCODE_H265_STD_PCM_ENABLED_FLAG_SET_BIT_KHR = 0x00000008
    VK_VIDEO_ENCODE_H265_STD_SPS_TEMPORAL_MVP_ENABLED_FLAG_SET_BIT_KHR = 0x00000010
    VK_VIDEO_ENCODE_H265_STD_INIT_QP_MINUS26_BIT_KHR = 0x00000020
    VK_VIDEO_ENCODE_H265_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR = 0x00000040
    VK_VIDEO_ENCODE_H265_STD_WEIGHTED_BIPRED_FLAG_SET_BIT_KHR = 0x00000080
    VK_VIDEO_ENCODE_H265_STD_LOG2_PARALLEL_MERGE_LEVEL_MINUS2_BIT_KHR = 0x00000100
    VK_VIDEO_ENCODE_H265_STD_SIGN_DATA_HIDING_ENABLED_FLAG_SET_BIT_KHR = 0x00000200
    VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_SET_BIT_KHR = 0x00000400
    VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_UNSET_BIT_KHR = 0x00000800
    VK_VIDEO_ENCODE_H265_STD_PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET_BIT_KHR = 0x00001000
    VK_VIDEO_ENCODE_H265_STD_TRANSQUANT_BYPASS_ENABLED_FLAG_SET_BIT_KHR = 0x00002000
    VK_VIDEO_ENCODE_H265_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR = 0x00004000
    VK_VIDEO_ENCODE_H265_STD_ENTROPY_CODING_SYNC_ENABLED_FLAG_SET_BIT_KHR = 0x00008000
    VK_VIDEO_ENCODE_H265_STD_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET_BIT_KHR = 0x00010000
    VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET_BIT_KHR = 0x00020000
    VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENT_FLAG_SET_BIT_KHR = 0x00040000
    VK_VIDEO_ENCODE_H265_STD_SLICE_QP_DELTA_BIT_KHR = 0x00080000
    VK_VIDEO_ENCODE_H265_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR = 0x00100000

class VkVideoEncodeH265RateControlFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_H265_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_H265_RATE_CONTROL_REGULAR_GOP_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR = 0x00000004
    VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR = 0x00000008
    VK_VIDEO_ENCODE_H265_RATE_CONTROL_TEMPORAL_SUB_LAYER_PATTERN_DYADIC_BIT_KHR = 0x00000010

class VkVideoEncodeH265CtbSizeFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_H265_CTB_SIZE_16_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_H265_CTB_SIZE_32_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_H265_CTB_SIZE_64_BIT_KHR = 0x00000004

class VkVideoEncodeH265TransformBlockSizeFlagBitsKHR(Flag):
    VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_4_BIT_KHR = 0x00000001
    VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_8_BIT_KHR = 0x00000002
    VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_16_BIT_KHR = 0x00000004
    VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_32_BIT_KHR = 0x00000008



















































































































































































class VkAccelerationStructureMotionInstanceTypeNV(Enum):
    VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV = 0
    VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV = 1
    VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV = 2

class VkCudaModuleNV(VulkanCData):
    __slots__ = ()

class VkCudaFunctionNV(VulkanCData):
    __slots__ = ()











VK_MAX_PHYSICAL_DEVICE_NAME_SIZE = 256

VK_UUID_SIZE = 16

VK_LUID_SIZE = 8

VK_LUID_SIZE_KHR = VK_LUID_SIZE

VK_MAX_EXTENSION_NAME_SIZE = 256

VK_MAX_DESCRIPTION_SIZE = 256

VK_MAX_MEMORY_TYPES = 32

VK_MAX_MEMORY_HEAPS = 16

VK_LOD_CLAMP_NONE = 1000.0

VK_REMAINING_MIP_LEVELS = 0xFFFFFFFF

VK_REMAINING_ARRAY_LAYERS = 0xFFFFFFFF

VK_REMAINING_3D_SLICES_EXT = 0xFFFFFFFF

VK_WHOLE_SIZE = 0xFFFFFFFFFFFFFFFF

VK_ATTACHMENT_UNUSED = 0xFFFFFFFF

VK_TRUE = 1

VK_FALSE = 0

VK_QUEUE_FAMILY_IGNORED = 0xFFFFFFFF

VK_QUEUE_FAMILY_EXTERNAL = 0xFFFFFFFE

VK_QUEUE_FAMILY_EXTERNAL_KHR = VK_QUEUE_FAMILY_EXTERNAL

VK_QUEUE_FAMILY_FOREIGN_EXT = 0xFFFFFFFD

VK_SUBPASS_EXTERNAL = 0xFFFFFFFF

VK_MAX_DEVICE_GROUP_SIZE = 32

VK_MAX_DEVICE_GROUP_SIZE_KHR = VK_MAX_DEVICE_GROUP_SIZE

VK_MAX_DRIVER_NAME_SIZE = 256

VK_MAX_DRIVER_NAME_SIZE_KHR = VK_MAX_DRIVER_NAME_SIZE

VK_MAX_DRIVER_INFO_SIZE = 256

VK_MAX_DRIVER_INFO_SIZE_KHR = VK_MAX_DRIVER_INFO_SIZE

VK_SHADER_UNUSED_KHR = 0xFFFFFFFF

VK_SHADER_UNUSED_NV = VK_SHADER_UNUSED_KHR

VK_MAX_GLOBAL_PRIORITY_SIZE_KHR = 16

VK_MAX_GLOBAL_PRIORITY_SIZE_EXT = VK_MAX_GLOBAL_PRIORITY_SIZE_KHR

VK_MAX_SHADER_MODULE_IDENTIFIER_SIZE_EXT = 32

VK_SHADER_INDEX_UNUSED_AMDX = 0xFFFFFFFF




















































































VK_KHR_SURFACE_SPEC_VERSION = 25

VK_KHR_SURFACE_EXTENSION_NAME = "VK_KHR_surface"

VK_KHR_SWAPCHAIN_SPEC_VERSION = 70

VK_KHR_SWAPCHAIN_EXTENSION_NAME = "VK_KHR_swapchain"

VK_KHR_DISPLAY_SPEC_VERSION = 23

VK_KHR_DISPLAY_EXTENSION_NAME = "VK_KHR_display"

VK_KHR_DISPLAY_SWAPCHAIN_SPEC_VERSION = 10

VK_KHR_DISPLAY_SWAPCHAIN_EXTENSION_NAME = "VK_KHR_display_swapchain"

VK_KHR_XLIB_SURFACE_SPEC_VERSION = 6

VK_KHR_XLIB_SURFACE_EXTENSION_NAME = "VK_KHR_xlib_surface"

VK_KHR_XCB_SURFACE_SPEC_VERSION = 6

VK_KHR_XCB_SURFACE_EXTENSION_NAME = "VK_KHR_xcb_surface"

VK_KHR_WAYLAND_SURFACE_SPEC_VERSION = 6

VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME = "VK_KHR_wayland_surface"

VK_KHR_MIR_SURFACE_SPEC_VERSION = 4

VK_KHR_MIR_SURFACE_EXTENSION_NAME = "VK_KHR_mir_surface"

VK_KHR_ANDROID_SURFACE_SPEC_VERSION = 6

VK_KHR_ANDROID_SURFACE_EXTENSION_NAME = "VK_KHR_android_surface"

VK_KHR_WIN32_SURFACE_SPEC_VERSION = 6

VK_KHR_WIN32_SURFACE_EXTENSION_NAME = "VK_KHR_win32_surface"

VK_ANDROID_NATIVE_BUFFER_SPEC_VERSION = 8

VK_ANDROID_NATIVE_BUFFER_NUMBER = 11

VK_ANDROID_NATIVE_BUFFER_EXTENSION_NAME = "VK_ANDROID_native_buffer"

VK_ANDROID_NATIVE_BUFFER_NAME = VK_ANDROID_NATIVE_BUFFER_EXTENSION_NAME

VK_EXT_DEBUG_REPORT_SPEC_VERSION = 10

VK_EXT_DEBUG_REPORT_EXTENSION_NAME = "VK_EXT_debug_report"

VK_NV_GLSL_SHADER_SPEC_VERSION = 1

VK_NV_GLSL_SHADER_EXTENSION_NAME = "VK_NV_glsl_shader"

VK_EXT_DEPTH_RANGE_UNRESTRICTED_SPEC_VERSION = 1

VK_EXT_DEPTH_RANGE_UNRESTRICTED_EXTENSION_NAME = "VK_EXT_depth_range_unrestricted"

VK_KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_SPEC_VERSION = 3

VK_KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_EXTENSION_NAME = "VK_KHR_sampler_mirror_clamp_to_edge"

VK_IMG_FILTER_CUBIC_SPEC_VERSION = 1

VK_IMG_FILTER_CUBIC_EXTENSION_NAME = "VK_IMG_filter_cubic"

VK_AMD_EXTENSION_17_SPEC_VERSION = 0

VK_AMD_EXTENSION_17_EXTENSION_NAME = "VK_AMD_extension_17"

VK_AMD_EXTENSION_18_SPEC_VERSION = 0

VK_AMD_EXTENSION_18_EXTENSION_NAME = "VK_AMD_extension_18"

VK_AMD_RASTERIZATION_ORDER_SPEC_VERSION = 1

VK_AMD_RASTERIZATION_ORDER_EXTENSION_NAME = "VK_AMD_rasterization_order"

VK_AMD_EXTENSION_20_SPEC_VERSION = 0

VK_AMD_EXTENSION_20_EXTENSION_NAME = "VK_AMD_extension_20"

VK_AMD_SHADER_TRINARY_MINMAX_SPEC_VERSION = 1

VK_AMD_SHADER_TRINARY_MINMAX_EXTENSION_NAME = "VK_AMD_shader_trinary_minmax"

VK_AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_SPEC_VERSION = 1

VK_AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_EXTENSION_NAME = "VK_AMD_shader_explicit_vertex_parameter"

VK_EXT_DEBUG_MARKER_SPEC_VERSION = 4

VK_EXT_DEBUG_MARKER_EXTENSION_NAME = "VK_EXT_debug_marker"

VK_KHR_VIDEO_QUEUE_SPEC_VERSION = 8

VK_KHR_VIDEO_QUEUE_EXTENSION_NAME = "VK_KHR_video_queue"

VK_KHR_VIDEO_DECODE_QUEUE_SPEC_VERSION = 8

VK_KHR_VIDEO_DECODE_QUEUE_EXTENSION_NAME = "VK_KHR_video_decode_queue"

VK_AMD_GCN_SHADER_SPEC_VERSION = 1

VK_AMD_GCN_SHADER_EXTENSION_NAME = "VK_AMD_gcn_shader"

VK_NV_DEDICATED_ALLOCATION_SPEC_VERSION = 1

VK_NV_DEDICATED_ALLOCATION_EXTENSION_NAME = "VK_NV_dedicated_allocation"

VK_EXT_EXTENSION_28_SPEC_VERSION = 0

VK_EXT_EXTENSION_28_EXTENSION_NAME = "VK_EXT_extension_28"

VK_EXT_TRANSFORM_FEEDBACK_SPEC_VERSION = 1

VK_EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME = "VK_EXT_transform_feedback"

VK_NVX_BINARY_IMPORT_SPEC_VERSION = 1

VK_NVX_BINARY_IMPORT_EXTENSION_NAME = "VK_NVX_binary_import"

VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION = 2

VK_NVX_IMAGE_VIEW_HANDLE_EXTENSION_NAME = "VK_NVX_image_view_handle"

VK_AMD_EXTENSION_32_SPEC_VERSION = 0

VK_AMD_EXTENSION_32_EXTENSION_NAME = "VK_AMD_extension_32"

VK_AMD_EXTENSION_33_SPEC_VERSION = 0

VK_AMD_EXTENSION_33_EXTENSION_NAME = "VK_AMD_extension_33"

VK_AMD_DRAW_INDIRECT_COUNT_SPEC_VERSION = 2

VK_AMD_DRAW_INDIRECT_COUNT_EXTENSION_NAME = "VK_AMD_draw_indirect_count"

VK_AMD_EXTENSION_35_SPEC_VERSION = 0

VK_AMD_EXTENSION_35_EXTENSION_NAME = "VK_AMD_extension_35"

VK_AMD_NEGATIVE_VIEWPORT_HEIGHT_SPEC_VERSION = 1

VK_AMD_NEGATIVE_VIEWPORT_HEIGHT_EXTENSION_NAME = "VK_AMD_negative_viewport_height"

VK_AMD_GPU_SHADER_HALF_FLOAT_SPEC_VERSION = 2

VK_AMD_GPU_SHADER_HALF_FLOAT_EXTENSION_NAME = "VK_AMD_gpu_shader_half_float"

VK_AMD_SHADER_BALLOT_SPEC_VERSION = 1

VK_AMD_SHADER_BALLOT_EXTENSION_NAME = "VK_AMD_shader_ballot"

VK_KHR_VIDEO_ENCODE_H264_SPEC_VERSION = 14

VK_KHR_VIDEO_ENCODE_H264_EXTENSION_NAME = "VK_KHR_video_encode_h264"

VK_KHR_VIDEO_ENCODE_H265_SPEC_VERSION = 14

VK_KHR_VIDEO_ENCODE_H265_EXTENSION_NAME = "VK_KHR_video_encode_h265"

VK_KHR_VIDEO_DECODE_H264_SPEC_VERSION = 9

VK_KHR_VIDEO_DECODE_H264_EXTENSION_NAME = "VK_KHR_video_decode_h264"

VK_AMD_TEXTURE_GATHER_BIAS_LOD_SPEC_VERSION = 1

VK_AMD_TEXTURE_GATHER_BIAS_LOD_EXTENSION_NAME = "VK_AMD_texture_gather_bias_lod"

VK_AMD_SHADER_INFO_SPEC_VERSION = 1

VK_AMD_SHADER_INFO_EXTENSION_NAME = "VK_AMD_shader_info"

VK_AMD_EXTENSION_44_SPEC_VERSION = 0

VK_AMD_EXTENSION_44_EXTENSION_NAME = "VK_AMD_extension_44"

VK_KHR_DYNAMIC_RENDERING_SPEC_VERSION = 1

VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME = "VK_KHR_dynamic_rendering"

VK_AMD_EXTENSION_46_SPEC_VERSION = 0

VK_AMD_EXTENSION_46_EXTENSION_NAME = "VK_AMD_extension_46"

VK_AMD_SHADER_IMAGE_LOAD_STORE_LOD_SPEC_VERSION = 1

VK_AMD_SHADER_IMAGE_LOAD_STORE_LOD_EXTENSION_NAME = "VK_AMD_shader_image_load_store_lod"

VK_NVX_EXTENSION_48_SPEC_VERSION = 0

VK_NVX_EXTENSION_48_EXTENSION_NAME = "VK_NVX_extension_48"

VK_GOOGLE_EXTENSION_49_SPEC_VERSION = 0

VK_GOOGLE_EXTENSION_49_EXTENSION_NAME = "VK_GOOGLE_extension_49"

VK_GGP_STREAM_DESCRIPTOR_SURFACE_SPEC_VERSION = 1

VK_GGP_STREAM_DESCRIPTOR_SURFACE_EXTENSION_NAME = "VK_GGP_stream_descriptor_surface"

VK_NV_CORNER_SAMPLED_IMAGE_SPEC_VERSION = 2

VK_NV_CORNER_SAMPLED_IMAGE_EXTENSION_NAME = "VK_NV_corner_sampled_image"

VK_NV_PRIVATE_VENDOR_INFO_SPEC_VERSION = 2

VK_NV_PRIVATE_VENDOR_INFO_EXTENSION_NAME = "VK_NV_private_vendor_info"

VK_NV_EXTENSION_53_SPEC_VERSION = 0

VK_NV_EXTENSION_53_EXTENSION_NAME = "VK_NV_extension_53"

VK_KHR_MULTIVIEW_SPEC_VERSION = 1

VK_KHR_MULTIVIEW_EXTENSION_NAME = "VK_KHR_multiview"

VK_IMG_FORMAT_PVRTC_SPEC_VERSION = 1

VK_IMG_FORMAT_PVRTC_EXTENSION_NAME = "VK_IMG_format_pvrtc"

VK_NV_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION = 1

VK_NV_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME = "VK_NV_external_memory_capabilities"

VK_NV_EXTERNAL_MEMORY_SPEC_VERSION = 1

VK_NV_EXTERNAL_MEMORY_EXTENSION_NAME = "VK_NV_external_memory"

VK_NV_EXTERNAL_MEMORY_WIN32_SPEC_VERSION = 1

VK_NV_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME = "VK_NV_external_memory_win32"

VK_NV_WIN32_KEYED_MUTEX_SPEC_VERSION = 2

VK_NV_WIN32_KEYED_MUTEX_EXTENSION_NAME = "VK_NV_win32_keyed_mutex"

VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_SPEC_VERSION = 2

VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME = "VK_KHR_get_physical_device_properties2"

VK_KHR_DEVICE_GROUP_SPEC_VERSION = 4

VK_KHR_DEVICE_GROUP_EXTENSION_NAME = "VK_KHR_device_group"

VK_EXT_VALIDATION_FLAGS_SPEC_VERSION = 3

VK_EXT_VALIDATION_FLAGS_EXTENSION_NAME = "VK_EXT_validation_flags"

VK_NN_VI_SURFACE_SPEC_VERSION = 1

VK_NN_VI_SURFACE_EXTENSION_NAME = "VK_NN_vi_surface"

VK_KHR_SHADER_DRAW_PARAMETERS_SPEC_VERSION = 1

VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME = "VK_KHR_shader_draw_parameters"

VK_EXT_SHADER_SUBGROUP_BALLOT_SPEC_VERSION = 1

VK_EXT_SHADER_SUBGROUP_BALLOT_EXTENSION_NAME = "VK_EXT_shader_subgroup_ballot"

VK_EXT_SHADER_SUBGROUP_VOTE_SPEC_VERSION = 1

VK_EXT_SHADER_SUBGROUP_VOTE_EXTENSION_NAME = "VK_EXT_shader_subgroup_vote"

VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_SPEC_VERSION = 1

VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME = "VK_EXT_texture_compression_astc_hdr"

VK_EXT_ASTC_DECODE_MODE_SPEC_VERSION = 1

VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME = "VK_EXT_astc_decode_mode"

VK_EXT_PIPELINE_ROBUSTNESS_SPEC_VERSION = 1

VK_EXT_PIPELINE_ROBUSTNESS_EXTENSION_NAME = "VK_EXT_pipeline_robustness"

VK_KHR_MAINTENANCE_1_SPEC_VERSION = 2

VK_KHR_MAINTENANCE_1_EXTENSION_NAME = "VK_KHR_maintenance1"

VK_KHR_MAINTENANCE1_SPEC_VERSION = VK_KHR_MAINTENANCE_1_SPEC_VERSION

VK_KHR_MAINTENANCE1_EXTENSION_NAME = VK_KHR_MAINTENANCE_1_EXTENSION_NAME

VK_KHR_DEVICE_GROUP_CREATION_SPEC_VERSION = 1

VK_KHR_DEVICE_GROUP_CREATION_EXTENSION_NAME = "VK_KHR_device_group_creation"

VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION = 1

VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME = "VK_KHR_external_memory_capabilities"

VK_KHR_EXTERNAL_MEMORY_SPEC_VERSION = 1

VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME = "VK_KHR_external_memory"

VK_KHR_EXTERNAL_MEMORY_WIN32_SPEC_VERSION = 1

VK_KHR_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME = "VK_KHR_external_memory_win32"

VK_KHR_EXTERNAL_MEMORY_FD_SPEC_VERSION = 1

VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME = "VK_KHR_external_memory_fd"

VK_KHR_WIN32_KEYED_MUTEX_SPEC_VERSION = 1

VK_KHR_WIN32_KEYED_MUTEX_EXTENSION_NAME = "VK_KHR_win32_keyed_mutex"

VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_SPEC_VERSION = 1

VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_EXTENSION_NAME = "VK_KHR_external_semaphore_capabilities"

VK_KHR_EXTERNAL_SEMAPHORE_SPEC_VERSION = 1

VK_KHR_EXTERNAL_SEMAPHORE_EXTENSION_NAME = "VK_KHR_external_semaphore"

VK_KHR_EXTERNAL_SEMAPHORE_WIN32_SPEC_VERSION = 1

VK_KHR_EXTERNAL_SEMAPHORE_WIN32_EXTENSION_NAME = "VK_KHR_external_semaphore_win32"

VK_KHR_EXTERNAL_SEMAPHORE_FD_SPEC_VERSION = 1

VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME = "VK_KHR_external_semaphore_fd"

VK_KHR_PUSH_DESCRIPTOR_SPEC_VERSION = 2

VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME = "VK_KHR_push_descriptor"

VK_EXT_CONDITIONAL_RENDERING_SPEC_VERSION = 2

VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME = "VK_EXT_conditional_rendering"

VK_KHR_SHADER_FLOAT16_INT8_SPEC_VERSION = 1

VK_KHR_SHADER_FLOAT16_INT8_EXTENSION_NAME = "VK_KHR_shader_float16_int8"

VK_KHR_16BIT_STORAGE_SPEC_VERSION = 1

VK_KHR_16BIT_STORAGE_EXTENSION_NAME = "VK_KHR_16bit_storage"

VK_KHR_INCREMENTAL_PRESENT_SPEC_VERSION = 2

VK_KHR_INCREMENTAL_PRESENT_EXTENSION_NAME = "VK_KHR_incremental_present"

VK_KHR_DESCRIPTOR_UPDATE_TEMPLATE_SPEC_VERSION = 1

VK_KHR_DESCRIPTOR_UPDATE_TEMPLATE_EXTENSION_NAME = "VK_KHR_descriptor_update_template"

VK_NVX_DEVICE_GENERATED_COMMANDS_SPEC_VERSION = 3

VK_NVX_DEVICE_GENERATED_COMMANDS_EXTENSION_NAME = "VK_NVX_device_generated_commands"

VK_NV_CLIP_SPACE_W_SCALING_SPEC_VERSION = 1

VK_NV_CLIP_SPACE_W_SCALING_EXTENSION_NAME = "VK_NV_clip_space_w_scaling"

VK_EXT_DIRECT_MODE_DISPLAY_SPEC_VERSION = 1

VK_EXT_DIRECT_MODE_DISPLAY_EXTENSION_NAME = "VK_EXT_direct_mode_display"

VK_EXT_ACQUIRE_XLIB_DISPLAY_SPEC_VERSION = 1

VK_EXT_ACQUIRE_XLIB_DISPLAY_EXTENSION_NAME = "VK_EXT_acquire_xlib_display"

VK_EXT_DISPLAY_SURFACE_COUNTER_SPEC_VERSION = 1

VK_EXT_DISPLAY_SURFACE_COUNTER_EXTENSION_NAME = "VK_EXT_display_surface_counter"

VK_EXT_DISPLAY_CONTROL_SPEC_VERSION = 1

VK_EXT_DISPLAY_CONTROL_EXTENSION_NAME = "VK_EXT_display_control"

VK_GOOGLE_DISPLAY_TIMING_SPEC_VERSION = 1

VK_GOOGLE_DISPLAY_TIMING_EXTENSION_NAME = "VK_GOOGLE_display_timing"

VK_RESERVED_DO_NOT_USE_94_SPEC_VERSION = 1

VK_RESERVED_DO_NOT_USE_94_EXTENSION_NAME = "VK_RESERVED_do_not_use_94"

VK_NV_SAMPLE_MASK_OVERRIDE_COVERAGE_SPEC_VERSION = 1

VK_NV_SAMPLE_MASK_OVERRIDE_COVERAGE_EXTENSION_NAME = "VK_NV_sample_mask_override_coverage"

VK_NV_GEOMETRY_SHADER_PASSTHROUGH_SPEC_VERSION = 1

VK_NV_GEOMETRY_SHADER_PASSTHROUGH_EXTENSION_NAME = "VK_NV_geometry_shader_passthrough"

VK_NV_VIEWPORT_ARRAY_2_SPEC_VERSION = 1

VK_NV_VIEWPORT_ARRAY_2_EXTENSION_NAME = "VK_NV_viewport_array2"

VK_NV_VIEWPORT_ARRAY2_SPEC_VERSION = VK_NV_VIEWPORT_ARRAY_2_SPEC_VERSION

VK_NV_VIEWPORT_ARRAY2_EXTENSION_NAME = VK_NV_VIEWPORT_ARRAY_2_EXTENSION_NAME

VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_SPEC_VERSION = 1

VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_EXTENSION_NAME = "VK_NVX_multiview_per_view_attributes"

VK_NV_VIEWPORT_SWIZZLE_SPEC_VERSION = 1

VK_NV_VIEWPORT_SWIZZLE_EXTENSION_NAME = "VK_NV_viewport_swizzle"

VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION = 2

VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME = "VK_EXT_discard_rectangles"

VK_NV_EXTENSION_101_SPEC_VERSION = 0

VK_NV_EXTENSION_101_EXTENSION_NAME = "VK_NV_extension_101"

VK_EXT_CONSERVATIVE_RASTERIZATION_SPEC_VERSION = 1

VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME = "VK_EXT_conservative_rasterization"

VK_EXT_DEPTH_CLIP_ENABLE_SPEC_VERSION = 1

VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME = "VK_EXT_depth_clip_enable"

VK_NV_EXTENSION_104_SPEC_VERSION = 0

VK_NV_EXTENSION_104_EXTENSION_NAME = "VK_NV_extension_104"

VK_EXT_SWAPCHAIN_COLOR_SPACE_SPEC_VERSION = 4

VK_EXT_SWAPCHAIN_COLOR_SPACE_EXTENSION_NAME = "VK_EXT_swapchain_colorspace"

VK_EXT_HDR_METADATA_SPEC_VERSION = 2

VK_EXT_HDR_METADATA_EXTENSION_NAME = "VK_EXT_hdr_metadata"

VK_IMG_EXTENSION_107_SPEC_VERSION = 0

VK_IMG_EXTENSION_107_EXTENSION_NAME = "VK_IMG_extension_107"

VK_IMG_EXTENSION_108_SPEC_VERSION = 0

VK_IMG_EXTENSION_108_EXTENSION_NAME = "VK_IMG_extension_108"

VK_KHR_IMAGELESS_FRAMEBUFFER_SPEC_VERSION = 1

VK_KHR_IMAGELESS_FRAMEBUFFER_EXTENSION_NAME = "VK_KHR_imageless_framebuffer"

VK_KHR_CREATE_RENDERPASS_2_SPEC_VERSION = 1

VK_KHR_CREATE_RENDERPASS_2_EXTENSION_NAME = "VK_KHR_create_renderpass2"

VK_IMG_RELAXED_LINE_RASTERIZATION_SPEC_VERSION = 1

VK_IMG_RELAXED_LINE_RASTERIZATION_EXTENSION_NAME = "VK_IMG_relaxed_line_rasterization"

VK_KHR_SHARED_PRESENTABLE_IMAGE_SPEC_VERSION = 1

VK_KHR_SHARED_PRESENTABLE_IMAGE_EXTENSION_NAME = "VK_KHR_shared_presentable_image"

VK_KHR_EXTERNAL_FENCE_CAPABILITIES_SPEC_VERSION = 1

VK_KHR_EXTERNAL_FENCE_CAPABILITIES_EXTENSION_NAME = "VK_KHR_external_fence_capabilities"

VK_KHR_EXTERNAL_FENCE_SPEC_VERSION = 1

VK_KHR_EXTERNAL_FENCE_EXTENSION_NAME = "VK_KHR_external_fence"

VK_KHR_EXTERNAL_FENCE_WIN32_SPEC_VERSION = 1

VK_KHR_EXTERNAL_FENCE_WIN32_EXTENSION_NAME = "VK_KHR_external_fence_win32"

VK_KHR_EXTERNAL_FENCE_FD_SPEC_VERSION = 1

VK_KHR_EXTERNAL_FENCE_FD_EXTENSION_NAME = "VK_KHR_external_fence_fd"

VK_KHR_PERFORMANCE_QUERY_SPEC_VERSION = 1

VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME = "VK_KHR_performance_query"

VK_KHR_MAINTENANCE_2_SPEC_VERSION = 1

VK_KHR_MAINTENANCE_2_EXTENSION_NAME = "VK_KHR_maintenance2"

VK_KHR_MAINTENANCE2_SPEC_VERSION = VK_KHR_MAINTENANCE_2_SPEC_VERSION

VK_KHR_MAINTENANCE2_EXTENSION_NAME = VK_KHR_MAINTENANCE_2_EXTENSION_NAME

VK_KHR_EXTENSION_119_SPEC_VERSION = 0

VK_KHR_EXTENSION_119_EXTENSION_NAME = "VK_KHR_extension_119"

VK_KHR_GET_SURFACE_CAPABILITIES_2_SPEC_VERSION = 1

VK_KHR_GET_SURFACE_CAPABILITIES_2_EXTENSION_NAME = "VK_KHR_get_surface_capabilities2"

VK_KHR_VARIABLE_POINTERS_SPEC_VERSION = 1

VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME = "VK_KHR_variable_pointers"

VK_KHR_GET_DISPLAY_PROPERTIES_2_SPEC_VERSION = 1

VK_KHR_GET_DISPLAY_PROPERTIES_2_EXTENSION_NAME = "VK_KHR_get_display_properties2"

VK_MVK_IOS_SURFACE_SPEC_VERSION = 3

VK_MVK_IOS_SURFACE_EXTENSION_NAME = "VK_MVK_ios_surface"

VK_MVK_MACOS_SURFACE_SPEC_VERSION = 3

VK_MVK_MACOS_SURFACE_EXTENSION_NAME = "VK_MVK_macos_surface"

VK_MVK_MOLTENVK_SPEC_VERSION = 0

VK_MVK_MOLTENVK_EXTENSION_NAME = "VK_MVK_moltenvk"

VK_EXT_EXTERNAL_MEMORY_DMA_BUF_SPEC_VERSION = 1

VK_EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME = "VK_EXT_external_memory_dma_buf"

VK_EXT_QUEUE_FAMILY_FOREIGN_SPEC_VERSION = 1

VK_EXT_QUEUE_FAMILY_FOREIGN_EXTENSION_NAME = "VK_EXT_queue_family_foreign"

VK_KHR_DEDICATED_ALLOCATION_SPEC_VERSION = 3

VK_KHR_DEDICATED_ALLOCATION_EXTENSION_NAME = "VK_KHR_dedicated_allocation"

VK_EXT_DEBUG_UTILS_SPEC_VERSION = 2

VK_EXT_DEBUG_UTILS_EXTENSION_NAME = "VK_EXT_debug_utils"

VK_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_SPEC_VERSION = 5

VK_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_EXTENSION_NAME = "VK_ANDROID_external_memory_android_hardware_buffer"

VK_EXT_SAMPLER_FILTER_MINMAX_SPEC_VERSION = 2

VK_EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME = "VK_EXT_sampler_filter_minmax"

VK_KHR_STORAGE_BUFFER_STORAGE_CLASS_SPEC_VERSION = 1

VK_KHR_STORAGE_BUFFER_STORAGE_CLASS_EXTENSION_NAME = "VK_KHR_storage_buffer_storage_class"

VK_AMD_GPU_SHADER_INT16_SPEC_VERSION = 2

VK_AMD_GPU_SHADER_INT16_EXTENSION_NAME = "VK_AMD_gpu_shader_int16"

VK_AMD_EXTENSION_134_SPEC_VERSION = 0

VK_AMD_EXTENSION_134_EXTENSION_NAME = "VK_AMD_extension_134"

VK_AMDX_SHADER_ENQUEUE_SPEC_VERSION = 1

VK_AMDX_SHADER_ENQUEUE_EXTENSION_NAME = "VK_AMDX_shader_enqueue"

VK_KHR_EXTENSION_136_SPEC_VERSION = 0

VK_KHR_EXTENSION_136_EXTENSION_NAME = "VK_KHR_extension_136"

VK_AMD_MIXED_ATTACHMENT_SAMPLES_SPEC_VERSION = 1

VK_AMD_MIXED_ATTACHMENT_SAMPLES_EXTENSION_NAME = "VK_AMD_mixed_attachment_samples"

VK_AMD_SHADER_FRAGMENT_MASK_SPEC_VERSION = 1

VK_AMD_SHADER_FRAGMENT_MASK_EXTENSION_NAME = "VK_AMD_shader_fragment_mask"

VK_EXT_INLINE_UNIFORM_BLOCK_SPEC_VERSION = 1

VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME = "VK_EXT_inline_uniform_block"

VK_AMD_EXTENSION_140_SPEC_VERSION = 0

VK_AMD_EXTENSION_140_EXTENSION_NAME = "VK_AMD_extension_140"

VK_EXT_SHADER_STENCIL_EXPORT_SPEC_VERSION = 1

VK_EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME = "VK_EXT_shader_stencil_export"

VK_AMD_EXTENSION_142_SPEC_VERSION = 0

VK_AMD_EXTENSION_142_EXTENSION_NAME = "VK_AMD_extension_142"

VK_AMD_EXTENSION_143_SPEC_VERSION = 0

VK_AMD_EXTENSION_143_EXTENSION_NAME = "VK_AMD_extension_143"

VK_EXT_SAMPLE_LOCATIONS_SPEC_VERSION = 1

VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME = "VK_EXT_sample_locations"

VK_KHR_RELAXED_BLOCK_LAYOUT_SPEC_VERSION = 1

VK_KHR_RELAXED_BLOCK_LAYOUT_EXTENSION_NAME = "VK_KHR_relaxed_block_layout"

VK_RESERVED_DO_NOT_USE_146_SPEC_VERSION = 1

VK_RESERVED_DO_NOT_USE_146_EXTENSION_NAME = "VK_RESERVED_do_not_use_146"

VK_KHR_GET_MEMORY_REQUIREMENTS_2_SPEC_VERSION = 1

VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME = "VK_KHR_get_memory_requirements2"

VK_KHR_IMAGE_FORMAT_LIST_SPEC_VERSION = 1

VK_KHR_IMAGE_FORMAT_LIST_EXTENSION_NAME = "VK_KHR_image_format_list"

VK_EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION = 2

VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME = "VK_EXT_blend_operation_advanced"

VK_NV_FRAGMENT_COVERAGE_TO_COLOR_SPEC_VERSION = 1

VK_NV_FRAGMENT_COVERAGE_TO_COLOR_EXTENSION_NAME = "VK_NV_fragment_coverage_to_color"

VK_KHR_ACCELERATION_STRUCTURE_SPEC_VERSION = 13

VK_KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME = "VK_KHR_acceleration_structure"

VK_KHR_RAY_TRACING_PIPELINE_SPEC_VERSION = 1

VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME = "VK_KHR_ray_tracing_pipeline"

VK_KHR_RAY_QUERY_SPEC_VERSION = 1

VK_KHR_RAY_QUERY_EXTENSION_NAME = "VK_KHR_ray_query"

VK_NV_EXTENSION_152_SPEC_VERSION = 0

VK_NV_EXTENSION_152_EXTENSION_NAME = "VK_NV_extension_152"

VK_NV_FRAMEBUFFER_MIXED_SAMPLES_SPEC_VERSION = 1

VK_NV_FRAMEBUFFER_MIXED_SAMPLES_EXTENSION_NAME = "VK_NV_framebuffer_mixed_samples"

VK_NV_FILL_RECTANGLE_SPEC_VERSION = 1

VK_NV_FILL_RECTANGLE_EXTENSION_NAME = "VK_NV_fill_rectangle"

VK_NV_SHADER_SM_BUILTINS_SPEC_VERSION = 1

VK_NV_SHADER_SM_BUILTINS_EXTENSION_NAME = "VK_NV_shader_sm_builtins"

VK_EXT_POST_DEPTH_COVERAGE_SPEC_VERSION = 1

VK_EXT_POST_DEPTH_COVERAGE_EXTENSION_NAME = "VK_EXT_post_depth_coverage"

VK_KHR_SAMPLER_YCBCR_CONVERSION_SPEC_VERSION = 14

VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME = "VK_KHR_sampler_ycbcr_conversion"

VK_KHR_BIND_MEMORY_2_SPEC_VERSION = 1

VK_KHR_BIND_MEMORY_2_EXTENSION_NAME = "VK_KHR_bind_memory2"

VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_SPEC_VERSION = 2

VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME = "VK_EXT_image_drm_format_modifier"

VK_EXT_EXTENSION_160_SPEC_VERSION = 0

VK_EXT_EXTENSION_160_EXTENSION_NAME = "VK_EXT_extension_160"

VK_EXT_VALIDATION_CACHE_SPEC_VERSION = 1

VK_EXT_VALIDATION_CACHE_EXTENSION_NAME = "VK_EXT_validation_cache"

VK_EXT_DESCRIPTOR_INDEXING_SPEC_VERSION = 2

VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME = "VK_EXT_descriptor_indexing"

VK_EXT_SHADER_VIEWPORT_INDEX_LAYER_SPEC_VERSION = 1

VK_EXT_SHADER_VIEWPORT_INDEX_LAYER_EXTENSION_NAME = "VK_EXT_shader_viewport_index_layer"

VK_KHR_PORTABILITY_SUBSET_SPEC_VERSION = 1

VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME = "VK_KHR_portability_subset"

VK_NV_SHADING_RATE_IMAGE_SPEC_VERSION = 3

VK_NV_SHADING_RATE_IMAGE_EXTENSION_NAME = "VK_NV_shading_rate_image"

VK_NV_RAY_TRACING_SPEC_VERSION = 3

VK_NV_RAY_TRACING_EXTENSION_NAME = "VK_NV_ray_tracing"

VK_NV_REPRESENTATIVE_FRAGMENT_TEST_SPEC_VERSION = 2

VK_NV_REPRESENTATIVE_FRAGMENT_TEST_EXTENSION_NAME = "VK_NV_representative_fragment_test"

VK_NV_EXTENSION_168_SPEC_VERSION = 0

VK_NV_EXTENSION_168_EXTENSION_NAME = "VK_NV_extension_168"

VK_KHR_MAINTENANCE_3_SPEC_VERSION = 1

VK_KHR_MAINTENANCE_3_EXTENSION_NAME = "VK_KHR_maintenance3"

VK_KHR_MAINTENANCE3_SPEC_VERSION = VK_KHR_MAINTENANCE_3_SPEC_VERSION

VK_KHR_MAINTENANCE3_EXTENSION_NAME = VK_KHR_MAINTENANCE_3_EXTENSION_NAME

VK_KHR_DRAW_INDIRECT_COUNT_SPEC_VERSION = 1

VK_KHR_DRAW_INDIRECT_COUNT_EXTENSION_NAME = "VK_KHR_draw_indirect_count"

VK_EXT_FILTER_CUBIC_SPEC_VERSION = 3

VK_EXT_FILTER_CUBIC_EXTENSION_NAME = "VK_EXT_filter_cubic"

VK_QCOM_RENDER_PASS_SHADER_RESOLVE_SPEC_VERSION = 4

VK_QCOM_RENDER_PASS_SHADER_RESOLVE_EXTENSION_NAME = "VK_QCOM_render_pass_shader_resolve"

VK_QCOM_EXTENSION_173_SPEC_VERSION = 0

VK_QCOM_EXTENSION_173_EXTENSION_NAME = "VK_QCOM_extension_173"

VK_QCOM_EXTENSION_174_SPEC_VERSION = 0

VK_QCOM_EXTENSION_174_EXTENSION_NAME = "VK_QCOM_extension_174"

VK_EXT_GLOBAL_PRIORITY_SPEC_VERSION = 2

VK_EXT_GLOBAL_PRIORITY_EXTENSION_NAME = "VK_EXT_global_priority"

VK_KHR_SHADER_SUBGROUP_EXTENDED_TYPES_SPEC_VERSION = 1

VK_KHR_SHADER_SUBGROUP_EXTENDED_TYPES_EXTENSION_NAME = "VK_KHR_shader_subgroup_extended_types"

VK_EXT_EXTENSION_177_SPEC_VERSION = 0

VK_EXT_EXTENSION_177_EXTENSION_NAME = "VK_EXT_extension_177"

VK_KHR_8BIT_STORAGE_SPEC_VERSION = 1

VK_KHR_8BIT_STORAGE_EXTENSION_NAME = "VK_KHR_8bit_storage"

VK_EXT_EXTERNAL_MEMORY_HOST_SPEC_VERSION = 1

VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME = "VK_EXT_external_memory_host"

VK_AMD_BUFFER_MARKER_SPEC_VERSION = 1

VK_AMD_BUFFER_MARKER_EXTENSION_NAME = "VK_AMD_buffer_marker"

VK_KHR_SHADER_ATOMIC_INT64_SPEC_VERSION = 1

VK_KHR_SHADER_ATOMIC_INT64_EXTENSION_NAME = "VK_KHR_shader_atomic_int64"

VK_KHR_SHADER_CLOCK_SPEC_VERSION = 1

VK_KHR_SHADER_CLOCK_EXTENSION_NAME = "VK_KHR_shader_clock"

VK_AMD_EXTENSION_183_SPEC_VERSION = 0

VK_AMD_EXTENSION_183_EXTENSION_NAME = "VK_AMD_extension_183"

VK_AMD_PIPELINE_COMPILER_CONTROL_SPEC_VERSION = 1

VK_AMD_PIPELINE_COMPILER_CONTROL_EXTENSION_NAME = "VK_AMD_pipeline_compiler_control"

VK_EXT_CALIBRATED_TIMESTAMPS_SPEC_VERSION = 2

VK_EXT_CALIBRATED_TIMESTAMPS_EXTENSION_NAME = "VK_EXT_calibrated_timestamps"

VK_AMD_SHADER_CORE_PROPERTIES_SPEC_VERSION = 2

VK_AMD_SHADER_CORE_PROPERTIES_EXTENSION_NAME = "VK_AMD_shader_core_properties"

VK_AMD_EXTENSION_187_SPEC_VERSION = 0

VK_AMD_EXTENSION_187_EXTENSION_NAME = "VK_AMD_extension_187"

VK_KHR_VIDEO_DECODE_H265_SPEC_VERSION = 8

VK_KHR_VIDEO_DECODE_H265_EXTENSION_NAME = "VK_KHR_video_decode_h265"

VK_KHR_GLOBAL_PRIORITY_SPEC_VERSION = 1

VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME = "VK_KHR_global_priority"

VK_AMD_MEMORY_OVERALLOCATION_BEHAVIOR_SPEC_VERSION = 1

VK_AMD_MEMORY_OVERALLOCATION_BEHAVIOR_EXTENSION_NAME = "VK_AMD_memory_overallocation_behavior"

VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION = 3

VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME = "VK_EXT_vertex_attribute_divisor"

VK_GGP_FRAME_TOKEN_SPEC_VERSION = 1

VK_GGP_FRAME_TOKEN_EXTENSION_NAME = "VK_GGP_frame_token"

VK_EXT_PIPELINE_CREATION_FEEDBACK_SPEC_VERSION = 1

VK_EXT_PIPELINE_CREATION_FEEDBACK_EXTENSION_NAME = "VK_EXT_pipeline_creation_feedback"

VK_GOOGLE_EXTENSION_194_SPEC_VERSION = 0

VK_GOOGLE_EXTENSION_194_EXTENSION_NAME = "VK_GOOGLE_extension_194"

VK_GOOGLE_EXTENSION_195_SPEC_VERSION = 0

VK_GOOGLE_EXTENSION_195_EXTENSION_NAME = "VK_GOOGLE_extension_195"

VK_GOOGLE_EXTENSION_196_SPEC_VERSION = 0

VK_GOOGLE_EXTENSION_196_EXTENSION_NAME = "VK_GOOGLE_extension_196"

VK_KHR_DRIVER_PROPERTIES_SPEC_VERSION = 1

VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME = "VK_KHR_driver_properties"

VK_KHR_SHADER_FLOAT_CONTROLS_SPEC_VERSION = 4

VK_KHR_SHADER_FLOAT_CONTROLS_EXTENSION_NAME = "VK_KHR_shader_float_controls"

VK_NV_SHADER_SUBGROUP_PARTITIONED_SPEC_VERSION = 1

VK_NV_SHADER_SUBGROUP_PARTITIONED_EXTENSION_NAME = "VK_NV_shader_subgroup_partitioned"

VK_KHR_DEPTH_STENCIL_RESOLVE_SPEC_VERSION = 1

VK_KHR_DEPTH_STENCIL_RESOLVE_EXTENSION_NAME = "VK_KHR_depth_stencil_resolve"

VK_KHR_SWAPCHAIN_MUTABLE_FORMAT_SPEC_VERSION = 1

VK_KHR_SWAPCHAIN_MUTABLE_FORMAT_EXTENSION_NAME = "VK_KHR_swapchain_mutable_format"

VK_NV_COMPUTE_SHADER_DERIVATIVES_SPEC_VERSION = 1

VK_NV_COMPUTE_SHADER_DERIVATIVES_EXTENSION_NAME = "VK_NV_compute_shader_derivatives"

VK_NV_MESH_SHADER_SPEC_VERSION = 1

VK_NV_MESH_SHADER_EXTENSION_NAME = "VK_NV_mesh_shader"

VK_NV_FRAGMENT_SHADER_BARYCENTRIC_SPEC_VERSION = 1

VK_NV_FRAGMENT_SHADER_BARYCENTRIC_EXTENSION_NAME = "VK_NV_fragment_shader_barycentric"

VK_NV_SHADER_IMAGE_FOOTPRINT_SPEC_VERSION = 2

VK_NV_SHADER_IMAGE_FOOTPRINT_EXTENSION_NAME = "VK_NV_shader_image_footprint"

VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION = 2

VK_NV_SCISSOR_EXCLUSIVE_EXTENSION_NAME = "VK_NV_scissor_exclusive"

VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_SPEC_VERSION = 2

VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME = "VK_NV_device_diagnostic_checkpoints"

VK_KHR_TIMELINE_SEMAPHORE_SPEC_VERSION = 2

VK_KHR_TIMELINE_SEMAPHORE_EXTENSION_NAME = "VK_KHR_timeline_semaphore"

VK_KHR_EXTENSION_209_SPEC_VERSION = 0

VK_KHR_EXTENSION_209_EXTENSION_NAME = "VK_KHR_extension_209"

VK_INTEL_SHADER_INTEGER_FUNCTIONS_2_SPEC_VERSION = 1

VK_INTEL_SHADER_INTEGER_FUNCTIONS_2_EXTENSION_NAME = "VK_INTEL_shader_integer_functions2"

VK_INTEL_PERFORMANCE_QUERY_SPEC_VERSION = 2

VK_INTEL_PERFORMANCE_QUERY_EXTENSION_NAME = "VK_INTEL_performance_query"

VK_KHR_VULKAN_MEMORY_MODEL_SPEC_VERSION = 3

VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME = "VK_KHR_vulkan_memory_model"

VK_EXT_PCI_BUS_INFO_SPEC_VERSION = 2

VK_EXT_PCI_BUS_INFO_EXTENSION_NAME = "VK_EXT_pci_bus_info"

VK_AMD_DISPLAY_NATIVE_HDR_SPEC_VERSION = 1

VK_AMD_DISPLAY_NATIVE_HDR_EXTENSION_NAME = "VK_AMD_display_native_hdr"

VK_FUCHSIA_IMAGEPIPE_SURFACE_SPEC_VERSION = 1

VK_FUCHSIA_IMAGEPIPE_SURFACE_EXTENSION_NAME = "VK_FUCHSIA_imagepipe_surface"

VK_KHR_SHADER_TERMINATE_INVOCATION_SPEC_VERSION = 1

VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME = "VK_KHR_shader_terminate_invocation"

VK_GOOGLE_EXTENSION_217_SPEC_VERSION = 0

VK_GOOGLE_EXTENSION_217_EXTENSION_NAME = "VK_GOOGLE_extension_217"

VK_EXT_METAL_SURFACE_SPEC_VERSION = 1

VK_EXT_METAL_SURFACE_EXTENSION_NAME = "VK_EXT_metal_surface"

VK_EXT_FRAGMENT_DENSITY_MAP_SPEC_VERSION = 2

VK_EXT_FRAGMENT_DENSITY_MAP_EXTENSION_NAME = "VK_EXT_fragment_density_map"

VK_EXT_EXTENSION_220_SPEC_VERSION = 0

VK_EXT_EXTENSION_220_EXTENSION_NAME = "VK_EXT_extension_220"

VK_KHR_EXTENSION_221_SPEC_VERSION = 0

VK_KHR_EXTENSION_221_EXTENSION_NAME = "VK_KHR_extension_221"

VK_EXT_SCALAR_BLOCK_LAYOUT_SPEC_VERSION = 1

VK_EXT_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME = "VK_EXT_scalar_block_layout"

VK_EXT_EXTENSION_223_SPEC_VERSION = 0

VK_EXT_EXTENSION_223_EXTENSION_NAME = "VK_EXT_extension_223"

VK_GOOGLE_HLSL_FUNCTIONALITY_1_SPEC_VERSION = 1

VK_GOOGLE_HLSL_FUNCTIONALITY_1_EXTENSION_NAME = "VK_GOOGLE_hlsl_functionality1"

VK_GOOGLE_HLSL_FUNCTIONALITY1_SPEC_VERSION = VK_GOOGLE_HLSL_FUNCTIONALITY_1_SPEC_VERSION

VK_GOOGLE_HLSL_FUNCTIONALITY1_EXTENSION_NAME = VK_GOOGLE_HLSL_FUNCTIONALITY_1_EXTENSION_NAME

VK_GOOGLE_DECORATE_STRING_SPEC_VERSION = 1

VK_GOOGLE_DECORATE_STRING_EXTENSION_NAME = "VK_GOOGLE_decorate_string"

VK_EXT_SUBGROUP_SIZE_CONTROL_SPEC_VERSION = 2

VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME = "VK_EXT_subgroup_size_control"

VK_KHR_FRAGMENT_SHADING_RATE_SPEC_VERSION = 2

VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME = "VK_KHR_fragment_shading_rate"

VK_AMD_SHADER_CORE_PROPERTIES_2_SPEC_VERSION = 1

VK_AMD_SHADER_CORE_PROPERTIES_2_EXTENSION_NAME = "VK_AMD_shader_core_properties2"

VK_AMD_EXTENSION_229_SPEC_VERSION = 0

VK_AMD_EXTENSION_229_EXTENSION_NAME = "VK_AMD_extension_229"

VK_AMD_DEVICE_COHERENT_MEMORY_SPEC_VERSION = 1

VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME = "VK_AMD_device_coherent_memory"

VK_AMD_EXTENSION_231_SPEC_VERSION = 0

VK_AMD_EXTENSION_231_EXTENSION_NAME = "VK_AMD_extension_231"

VK_AMD_EXTENSION_232_SPEC_VERSION = 0

VK_AMD_EXTENSION_232_EXTENSION_NAME = "VK_AMD_extension_232"

VK_AMD_EXTENSION_233_SPEC_VERSION = 0

VK_AMD_EXTENSION_233_EXTENSION_NAME = "VK_AMD_extension_233"

VK_AMD_EXTENSION_234_SPEC_VERSION = 0

VK_AMD_EXTENSION_234_EXTENSION_NAME = "VK_AMD_extension_234"

VK_EXT_SHADER_IMAGE_ATOMIC_INT64_SPEC_VERSION = 1

VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME = "VK_EXT_shader_image_atomic_int64"

VK_AMD_EXTENSION_236_SPEC_VERSION = 0

VK_AMD_EXTENSION_236_EXTENSION_NAME = "VK_AMD_extension_236"

VK_KHR_SPIRV_1_4_SPEC_VERSION = 1

VK_KHR_SPIRV_1_4_EXTENSION_NAME = "VK_KHR_spirv_1_4"

VK_EXT_MEMORY_BUDGET_SPEC_VERSION = 1

VK_EXT_MEMORY_BUDGET_EXTENSION_NAME = "VK_EXT_memory_budget"

VK_EXT_MEMORY_PRIORITY_SPEC_VERSION = 1

VK_EXT_MEMORY_PRIORITY_EXTENSION_NAME = "VK_EXT_memory_priority"

VK_KHR_SURFACE_PROTECTED_CAPABILITIES_SPEC_VERSION = 1

VK_KHR_SURFACE_PROTECTED_CAPABILITIES_EXTENSION_NAME = "VK_KHR_surface_protected_capabilities"

VK_NV_DEDICATED_ALLOCATION_IMAGE_ALIASING_SPEC_VERSION = 1

VK_NV_DEDICATED_ALLOCATION_IMAGE_ALIASING_EXTENSION_NAME = "VK_NV_dedicated_allocation_image_aliasing"

VK_KHR_SEPARATE_DEPTH_STENCIL_LAYOUTS_SPEC_VERSION = 1

VK_KHR_SEPARATE_DEPTH_STENCIL_LAYOUTS_EXTENSION_NAME = "VK_KHR_separate_depth_stencil_layouts"

VK_INTEL_EXTENSION_243_SPEC_VERSION = 0

VK_INTEL_EXTENSION_243_EXTENSION_NAME = "VK_INTEL_extension_243"

VK_MESA_EXTENSION_244_SPEC_VERSION = 0

VK_MESA_EXTENSION_244_EXTENSION_NAME = "VK_MESA_extension_244"

VK_EXT_BUFFER_DEVICE_ADDRESS_SPEC_VERSION = 2

VK_EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME = "VK_EXT_buffer_device_address"

VK_EXT_TOOLING_INFO_SPEC_VERSION = 1

VK_EXT_TOOLING_INFO_EXTENSION_NAME = "VK_EXT_tooling_info"

VK_EXT_SEPARATE_STENCIL_USAGE_SPEC_VERSION = 1

VK_EXT_SEPARATE_STENCIL_USAGE_EXTENSION_NAME = "VK_EXT_separate_stencil_usage"

VK_EXT_VALIDATION_FEATURES_SPEC_VERSION = 6

VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME = "VK_EXT_validation_features"

VK_KHR_PRESENT_WAIT_SPEC_VERSION = 1

VK_KHR_PRESENT_WAIT_EXTENSION_NAME = "VK_KHR_present_wait"

VK_NV_COOPERATIVE_MATRIX_SPEC_VERSION = 1

VK_NV_COOPERATIVE_MATRIX_EXTENSION_NAME = "VK_NV_cooperative_matrix"

VK_NV_COVERAGE_REDUCTION_MODE_SPEC_VERSION = 1

VK_NV_COVERAGE_REDUCTION_MODE_EXTENSION_NAME = "VK_NV_coverage_reduction_mode"

VK_EXT_FRAGMENT_SHADER_INTERLOCK_SPEC_VERSION = 1

VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME = "VK_EXT_fragment_shader_interlock"

VK_EXT_YCBCR_IMAGE_ARRAYS_SPEC_VERSION = 1

VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME = "VK_EXT_ycbcr_image_arrays"

VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_SPEC_VERSION = 1

VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME = "VK_KHR_uniform_buffer_standard_layout"

VK_EXT_PROVOKING_VERTEX_SPEC_VERSION = 1

VK_EXT_PROVOKING_VERTEX_EXTENSION_NAME = "VK_EXT_provoking_vertex"

VK_EXT_FULL_SCREEN_EXCLUSIVE_SPEC_VERSION = 4

VK_EXT_FULL_SCREEN_EXCLUSIVE_EXTENSION_NAME = "VK_EXT_full_screen_exclusive"

VK_EXT_HEADLESS_SURFACE_SPEC_VERSION = 1

VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME = "VK_EXT_headless_surface"

VK_KHR_BUFFER_DEVICE_ADDRESS_SPEC_VERSION = 1

VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME = "VK_KHR_buffer_device_address"

VK_EXT_EXTENSION_259_SPEC_VERSION = 0

VK_EXT_EXTENSION_259_EXTENSION_NAME = "VK_EXT_extension_259"

VK_EXT_LINE_RASTERIZATION_SPEC_VERSION = 1

VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME = "VK_EXT_line_rasterization"

VK_EXT_SHADER_ATOMIC_FLOAT_SPEC_VERSION = 1

VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME = "VK_EXT_shader_atomic_float"

VK_EXT_HOST_QUERY_RESET_SPEC_VERSION = 1

VK_EXT_HOST_QUERY_RESET_EXTENSION_NAME = "VK_EXT_host_query_reset"

VK_GGP_EXTENSION_263_SPEC_VERSION = 0

VK_GGP_EXTENSION_263_EXTENSION_NAME = "VK_GGP_extension_263"

VK_BRCM_EXTENSION_264_SPEC_VERSION = 0

VK_BRCM_EXTENSION_264_EXTENSION_NAME = "VK_BRCM_extension_264"

VK_BRCM_EXTENSION_265_SPEC_VERSION = 0

VK_BRCM_EXTENSION_265_EXTENSION_NAME = "VK_BRCM_extension_265"

VK_EXT_INDEX_TYPE_UINT8_SPEC_VERSION = 1

VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME = "VK_EXT_index_type_uint8"

VK_EXT_EXTENSION_267_SPEC_VERSION = 0

VK_EXT_EXTENSION_267_EXTENSION_NAME = "VK_EXT_extension_267"

VK_EXT_EXTENDED_DYNAMIC_STATE_SPEC_VERSION = 1

VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME = "VK_EXT_extended_dynamic_state"

VK_KHR_DEFERRED_HOST_OPERATIONS_SPEC_VERSION = 4

VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME = "VK_KHR_deferred_host_operations"

VK_KHR_PIPELINE_EXECUTABLE_PROPERTIES_SPEC_VERSION = 1

VK_KHR_PIPELINE_EXECUTABLE_PROPERTIES_EXTENSION_NAME = "VK_KHR_pipeline_executable_properties"

VK_EXT_HOST_IMAGE_COPY_SPEC_VERSION = 1

VK_EXT_HOST_IMAGE_COPY_EXTENSION_NAME = "VK_EXT_host_image_copy"

VK_KHR_MAP_MEMORY_2_SPEC_VERSION = 1

VK_KHR_MAP_MEMORY_2_EXTENSION_NAME = "VK_KHR_map_memory2"

VK_INTEL_EXTENSION_273_SPEC_VERSION = 0

VK_INTEL_EXTENSION_273_EXTENSION_NAME = "VK_INTEL_extension_273"

VK_EXT_SHADER_ATOMIC_FLOAT_2_SPEC_VERSION = 1

VK_EXT_SHADER_ATOMIC_FLOAT_2_EXTENSION_NAME = "VK_EXT_shader_atomic_float2"

VK_EXT_SURFACE_MAINTENANCE_1_SPEC_VERSION = 1

VK_EXT_SURFACE_MAINTENANCE_1_EXTENSION_NAME = "VK_EXT_surface_maintenance1"

VK_EXT_SWAPCHAIN_MAINTENANCE_1_SPEC_VERSION = 1

VK_EXT_SWAPCHAIN_MAINTENANCE_1_EXTENSION_NAME = "VK_EXT_swapchain_maintenance1"

VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_SPEC_VERSION = 1

VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME = "VK_EXT_shader_demote_to_helper_invocation"

VK_NV_DEVICE_GENERATED_COMMANDS_SPEC_VERSION = 3

VK_NV_DEVICE_GENERATED_COMMANDS_EXTENSION_NAME = "VK_NV_device_generated_commands"

VK_NV_INHERITED_VIEWPORT_SCISSOR_SPEC_VERSION = 1

VK_NV_INHERITED_VIEWPORT_SCISSOR_EXTENSION_NAME = "VK_NV_inherited_viewport_scissor"

VK_KHR_EXTENSION_280_SPEC_VERSION = 0

VK_KHR_EXTENSION_280_EXTENSION_NAME = "VK_KHR_extension_280"

VK_KHR_SHADER_INTEGER_DOT_PRODUCT_SPEC_VERSION = 1

VK_KHR_SHADER_INTEGER_DOT_PRODUCT_EXTENSION_NAME = "VK_KHR_shader_integer_dot_product"

VK_EXT_TEXEL_BUFFER_ALIGNMENT_SPEC_VERSION = 1

VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME = "VK_EXT_texel_buffer_alignment"

VK_QCOM_RENDER_PASS_TRANSFORM_SPEC_VERSION = 4

VK_QCOM_RENDER_PASS_TRANSFORM_EXTENSION_NAME = "VK_QCOM_render_pass_transform"

VK_EXT_DEPTH_BIAS_CONTROL_SPEC_VERSION = 1

VK_EXT_DEPTH_BIAS_CONTROL_EXTENSION_NAME = "VK_EXT_depth_bias_control"

VK_EXT_DEVICE_MEMORY_REPORT_SPEC_VERSION = 2

VK_EXT_DEVICE_MEMORY_REPORT_EXTENSION_NAME = "VK_EXT_device_memory_report"

VK_EXT_ACQUIRE_DRM_DISPLAY_SPEC_VERSION = 1

VK_EXT_ACQUIRE_DRM_DISPLAY_EXTENSION_NAME = "VK_EXT_acquire_drm_display"

VK_EXT_ROBUSTNESS_2_SPEC_VERSION = 1

VK_EXT_ROBUSTNESS_2_EXTENSION_NAME = "VK_EXT_robustness2"

VK_EXT_CUSTOM_BORDER_COLOR_SPEC_VERSION = 12

VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME = "VK_EXT_custom_border_color"

VK_EXT_EXTENSION_289_SPEC_VERSION = 0

VK_EXT_EXTENSION_289_EXTENSION_NAME = "VK_EXT_extension_289"

VK_GOOGLE_USER_TYPE_SPEC_VERSION = 1

VK_GOOGLE_USER_TYPE_EXTENSION_NAME = "VK_GOOGLE_user_type"

VK_KHR_PIPELINE_LIBRARY_SPEC_VERSION = 1

VK_KHR_PIPELINE_LIBRARY_EXTENSION_NAME = "VK_KHR_pipeline_library"

VK_NV_EXTENSION_292_SPEC_VERSION = 0

VK_NV_EXTENSION_292_EXTENSION_NAME = "VK_NV_extension_292"

VK_NV_PRESENT_BARRIER_SPEC_VERSION = 1

VK_NV_PRESENT_BARRIER_EXTENSION_NAME = "VK_NV_present_barrier"

VK_KHR_SHADER_NON_SEMANTIC_INFO_SPEC_VERSION = 1

VK_KHR_SHADER_NON_SEMANTIC_INFO_EXTENSION_NAME = "VK_KHR_shader_non_semantic_info"

VK_KHR_PRESENT_ID_SPEC_VERSION = 1

VK_KHR_PRESENT_ID_EXTENSION_NAME = "VK_KHR_present_id"

VK_EXT_PRIVATE_DATA_SPEC_VERSION = 1

VK_EXT_PRIVATE_DATA_EXTENSION_NAME = "VK_EXT_private_data"

VK_KHR_EXTENSION_297_SPEC_VERSION = 0

VK_KHR_EXTENSION_297_EXTENSION_NAME = "VK_KHR_extension_297"

VK_EXT_PIPELINE_CREATION_CACHE_CONTROL_SPEC_VERSION = 3

VK_EXT_PIPELINE_CREATION_CACHE_CONTROL_EXTENSION_NAME = "VK_EXT_pipeline_creation_cache_control"

VK_KHR_EXTENSION_299_SPEC_VERSION = 0

VK_KHR_EXTENSION_299_EXTENSION_NAME = "VK_KHR_extension_299"

VK_KHR_VIDEO_ENCODE_QUEUE_SPEC_VERSION = 12

VK_KHR_VIDEO_ENCODE_QUEUE_EXTENSION_NAME = "VK_KHR_video_encode_queue"

VK_NV_DEVICE_DIAGNOSTICS_CONFIG_SPEC_VERSION = 2

VK_NV_DEVICE_DIAGNOSTICS_CONFIG_EXTENSION_NAME = "VK_NV_device_diagnostics_config"

VK_QCOM_RENDER_PASS_STORE_OPS_SPEC_VERSION = 2

VK_QCOM_RENDER_PASS_STORE_OPS_EXTENSION_NAME = "VK_QCOM_render_pass_store_ops"

VK_QCOM_EXTENSION_303_SPEC_VERSION = 0

VK_QCOM_EXTENSION_303_EXTENSION_NAME = "VK_QCOM_extension_303"

VK_QCOM_EXTENSION_304_SPEC_VERSION = 0

VK_QCOM_EXTENSION_304_EXTENSION_NAME = "VK_QCOM_extension_304"

VK_QCOM_EXTENSION_305_SPEC_VERSION = 0

VK_QCOM_EXTENSION_305_EXTENSION_NAME = "VK_QCOM_extension_305"

VK_QCOM_EXTENSION_306_SPEC_VERSION = 0

VK_QCOM_EXTENSION_306_EXTENSION_NAME = "VK_QCOM_extension_306"

VK_QCOM_EXTENSION_307_SPEC_VERSION = 0

VK_QCOM_EXTENSION_307_EXTENSION_NAME = "VK_QCOM_extension_307"

VK_NV_CUDA_KERNEL_LAUNCH_SPEC_VERSION = 2

VK_NV_CUDA_KERNEL_LAUNCH_EXTENSION_NAME = "VK_NV_cuda_kernel_launch"

VK_KHR_OBJECT_REFRESH_SPEC_VERSION = 1

VK_KHR_OBJECT_REFRESH_EXTENSION_NAME = "VK_KHR_object_refresh"

VK_QCOM_EXTENSION_310_SPEC_VERSION = 0

VK_QCOM_EXTENSION_310_EXTENSION_NAME = "VK_QCOM_extension_310"

VK_NV_LOW_LATENCY_SPEC_VERSION = 1

VK_NV_LOW_LATENCY_EXTENSION_NAME = "VK_NV_low_latency"

VK_EXT_METAL_OBJECTS_SPEC_VERSION = 1

VK_EXT_METAL_OBJECTS_EXTENSION_NAME = "VK_EXT_metal_objects"

VK_EXT_EXTENSION_313_SPEC_VERSION = 0

VK_EXT_EXTENSION_313_EXTENSION_NAME = "VK_EXT_extension_313"

VK_AMD_EXTENSION_314_SPEC_VERSION = 0

VK_AMD_EXTENSION_314_EXTENSION_NAME = "VK_AMD_extension_314"

VK_KHR_SYNCHRONIZATION_2_SPEC_VERSION = 1

VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME = "VK_KHR_synchronization2"

VK_AMD_EXTENSION_316_SPEC_VERSION = 0

VK_AMD_EXTENSION_316_EXTENSION_NAME = "VK_AMD_extension_316"

VK_EXT_DESCRIPTOR_BUFFER_SPEC_VERSION = 1

VK_EXT_DESCRIPTOR_BUFFER_EXTENSION_NAME = "VK_EXT_descriptor_buffer"

VK_AMD_EXTENSION_318_SPEC_VERSION = 0

VK_AMD_EXTENSION_318_EXTENSION_NAME = "VK_AMD_extension_318"

VK_AMD_EXTENSION_319_SPEC_VERSION = 0

VK_AMD_EXTENSION_319_EXTENSION_NAME = "VK_AMD_extension_319"

VK_AMD_EXTENSION_320_SPEC_VERSION = 0

VK_AMD_EXTENSION_320_EXTENSION_NAME = "VK_AMD_extension_320"

VK_EXT_GRAPHICS_PIPELINE_LIBRARY_SPEC_VERSION = 1

VK_EXT_GRAPHICS_PIPELINE_LIBRARY_EXTENSION_NAME = "VK_EXT_graphics_pipeline_library"

VK_AMD_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_SPEC_VERSION = 1

VK_AMD_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_EXTENSION_NAME = "VK_AMD_shader_early_and_late_fragment_tests"

VK_KHR_FRAGMENT_SHADER_BARYCENTRIC_SPEC_VERSION = 1

VK_KHR_FRAGMENT_SHADER_BARYCENTRIC_EXTENSION_NAME = "VK_KHR_fragment_shader_barycentric"

VK_KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_SPEC_VERSION = 1

VK_KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_EXTENSION_NAME = "VK_KHR_shader_subgroup_uniform_control_flow"

VK_KHR_EXTENSION_325_SPEC_VERSION = 0

VK_KHR_EXTENSION_325_EXTENSION_NAME = "VK_KHR_extension_325"

VK_KHR_ZERO_INITIALIZE_WORKGROUP_MEMORY_SPEC_VERSION = 1

VK_KHR_ZERO_INITIALIZE_WORKGROUP_MEMORY_EXTENSION_NAME = "VK_KHR_zero_initialize_workgroup_memory"

VK_NV_FRAGMENT_SHADING_RATE_ENUMS_SPEC_VERSION = 1

VK_NV_FRAGMENT_SHADING_RATE_ENUMS_EXTENSION_NAME = "VK_NV_fragment_shading_rate_enums"

VK_NV_RAY_TRACING_MOTION_BLUR_SPEC_VERSION = 1

VK_NV_RAY_TRACING_MOTION_BLUR_EXTENSION_NAME = "VK_NV_ray_tracing_motion_blur"

VK_EXT_MESH_SHADER_SPEC_VERSION = 1

VK_EXT_MESH_SHADER_EXTENSION_NAME = "VK_EXT_mesh_shader"

VK_NV_EXTENSION_330_SPEC_VERSION = 0

VK_NV_EXTENSION_330_EXTENSION_NAME = "VK_NV_extension_330"

VK_EXT_YCBCR_2PLANE_444_FORMATS_SPEC_VERSION = 1

VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME = "VK_EXT_ycbcr_2plane_444_formats"

VK_NV_EXTENSION_332_SPEC_VERSION = 0

VK_NV_EXTENSION_332_EXTENSION_NAME = "VK_NV_extension_332"

VK_EXT_FRAGMENT_DENSITY_MAP_2_SPEC_VERSION = 1

VK_EXT_FRAGMENT_DENSITY_MAP_2_EXTENSION_NAME = "VK_EXT_fragment_density_map2"

VK_QCOM_ROTATED_COPY_COMMANDS_SPEC_VERSION = 2

VK_QCOM_ROTATED_COPY_COMMANDS_EXTENSION_NAME = "VK_QCOM_rotated_copy_commands"

VK_KHR_EXTENSION_335_SPEC_VERSION = 0

VK_KHR_EXTENSION_335_EXTENSION_NAME = "VK_KHR_extension_335"

VK_EXT_IMAGE_ROBUSTNESS_SPEC_VERSION = 1

VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME = "VK_EXT_image_robustness"

VK_KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_SPEC_VERSION = 1

VK_KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_EXTENSION_NAME = "VK_KHR_workgroup_memory_explicit_layout"

VK_KHR_COPY_COMMANDS_2_SPEC_VERSION = 1

VK_KHR_COPY_COMMANDS_2_EXTENSION_NAME = "VK_KHR_copy_commands2"

VK_EXT_IMAGE_COMPRESSION_CONTROL_SPEC_VERSION = 1

VK_EXT_IMAGE_COMPRESSION_CONTROL_EXTENSION_NAME = "VK_EXT_image_compression_control"

VK_EXT_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_SPEC_VERSION = 2

VK_EXT_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_EXTENSION_NAME = "VK_EXT_attachment_feedback_loop_layout"

VK_EXT_4444_FORMATS_SPEC_VERSION = 1

VK_EXT_4444_FORMATS_EXTENSION_NAME = "VK_EXT_4444_formats"

VK_EXT_DEVICE_FAULT_SPEC_VERSION = 2

VK_EXT_DEVICE_FAULT_EXTENSION_NAME = "VK_EXT_device_fault"

VK_ARM_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_SPEC_VERSION = 1

VK_ARM_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXTENSION_NAME = "VK_ARM_rasterization_order_attachment_access"

VK_ARM_EXTENSION_344_SPEC_VERSION = 0

VK_ARM_EXTENSION_344_EXTENSION_NAME = "VK_ARM_extension_344"

VK_EXT_RGBA10X6_FORMATS_SPEC_VERSION = 1

VK_EXT_RGBA10X6_FORMATS_EXTENSION_NAME = "VK_EXT_rgba10x6_formats"

VK_NV_ACQUIRE_WINRT_DISPLAY_SPEC_VERSION = 1

VK_NV_ACQUIRE_WINRT_DISPLAY_EXTENSION_NAME = "VK_NV_acquire_winrt_display"

VK_EXT_DIRECTFB_SURFACE_SPEC_VERSION = 1

VK_EXT_DIRECTFB_SURFACE_EXTENSION_NAME = "VK_EXT_directfb_surface"

VK_KHR_EXTENSION_350_SPEC_VERSION = 0

VK_KHR_EXTENSION_350_EXTENSION_NAME = "VK_KHR_extension_350"

VK_NV_EXTENSION_351_SPEC_VERSION = 0

VK_NV_EXTENSION_351_EXTENSION_NAME = "VK_NV_extension_351"

VK_VALVE_MUTABLE_DESCRIPTOR_TYPE_SPEC_VERSION = 1

VK_VALVE_MUTABLE_DESCRIPTOR_TYPE_EXTENSION_NAME = "VK_VALVE_mutable_descriptor_type"

VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_SPEC_VERSION = 2

VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME = "VK_EXT_vertex_input_dynamic_state"

VK_EXT_PHYSICAL_DEVICE_DRM_SPEC_VERSION = 1

VK_EXT_PHYSICAL_DEVICE_DRM_EXTENSION_NAME = "VK_EXT_physical_device_drm"

VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_SPEC_VERSION = 1

VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME = "VK_EXT_device_address_binding_report"

VK_EXT_DEPTH_CLIP_CONTROL_SPEC_VERSION = 1

VK_EXT_DEPTH_CLIP_CONTROL_EXTENSION_NAME = "VK_EXT_depth_clip_control"

VK_EXT_PRIMITIVE_TOPOLOGY_LIST_RESTART_SPEC_VERSION = 1

VK_EXT_PRIMITIVE_TOPOLOGY_LIST_RESTART_EXTENSION_NAME = "VK_EXT_primitive_topology_list_restart"

VK_KHR_EXTENSION_358_SPEC_VERSION = 0

VK_KHR_EXTENSION_358_EXTENSION_NAME = "VK_KHR_extension_358"

VK_EXT_EXTENSION_359_SPEC_VERSION = 0

VK_EXT_EXTENSION_359_EXTENSION_NAME = "VK_EXT_extension_359"

VK_EXT_EXTENSION_360_SPEC_VERSION = 0

VK_EXT_EXTENSION_360_EXTENSION_NAME = "VK_EXT_extension_360"

VK_KHR_FORMAT_FEATURE_FLAGS_2_SPEC_VERSION = 2

VK_KHR_FORMAT_FEATURE_FLAGS_2_EXTENSION_NAME = "VK_KHR_format_feature_flags2"

VK_EXT_EXTENSION_362_SPEC_VERSION = 0

VK_EXT_EXTENSION_362_EXTENSION_NAME = "VK_EXT_extension_362"

VK_EXT_EXTENSION_363_SPEC_VERSION = 0

VK_EXT_EXTENSION_363_EXTENSION_NAME = "VK_EXT_extension_363"

VK_FUCHSIA_EXTENSION_364_SPEC_VERSION = 0

VK_FUCHSIA_EXTENSION_364_EXTENSION_NAME = "VK_FUCHSIA_extension_364"

VK_FUCHSIA_EXTERNAL_MEMORY_SPEC_VERSION = 1

VK_FUCHSIA_EXTERNAL_MEMORY_EXTENSION_NAME = "VK_FUCHSIA_external_memory"

VK_FUCHSIA_EXTERNAL_SEMAPHORE_SPEC_VERSION = 1

VK_FUCHSIA_EXTERNAL_SEMAPHORE_EXTENSION_NAME = "VK_FUCHSIA_external_semaphore"

VK_FUCHSIA_BUFFER_COLLECTION_SPEC_VERSION = 2

VK_FUCHSIA_BUFFER_COLLECTION_EXTENSION_NAME = "VK_FUCHSIA_buffer_collection"

VK_FUCHSIA_EXTENSION_368_SPEC_VERSION = 0

VK_FUCHSIA_EXTENSION_368_EXTENSION_NAME = "VK_FUCHSIA_extension_368"

VK_QCOM_EXTENSION_369_SPEC_VERSION = 0

VK_QCOM_EXTENSION_369_EXTENSION_NAME = "VK_QCOM_extension_369"

VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION = 3

VK_HUAWEI_SUBPASS_SHADING_EXTENSION_NAME = "VK_HUAWEI_subpass_shading"

VK_HUAWEI_INVOCATION_MASK_SPEC_VERSION = 1

VK_HUAWEI_INVOCATION_MASK_EXTENSION_NAME = "VK_HUAWEI_invocation_mask"

VK_NV_EXTERNAL_MEMORY_RDMA_SPEC_VERSION = 1

VK_NV_EXTERNAL_MEMORY_RDMA_EXTENSION_NAME = "VK_NV_external_memory_rdma"

VK_EXT_PIPELINE_PROPERTIES_SPEC_VERSION = 1

VK_EXT_PIPELINE_PROPERTIES_EXTENSION_NAME = "VK_EXT_pipeline_properties"

VK_NV_EXTERNAL_SCI_SYNC_SPEC_VERSION = 2

VK_NV_EXTERNAL_SCI_SYNC_EXTENSION_NAME = "VK_NV_external_sci_sync"

VK_NV_EXTERNAL_MEMORY_SCI_BUF_SPEC_VERSION = 2

VK_NV_EXTERNAL_MEMORY_SCI_BUF_EXTENSION_NAME = "VK_NV_external_memory_sci_buf"

VK_EXT_FRAME_BOUNDARY_SPEC_VERSION = 1

VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME = "VK_EXT_frame_boundary"

VK_EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_SPEC_VERSION = 1

VK_EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_EXTENSION_NAME = "VK_EXT_multisampled_render_to_single_sampled"

VK_EXT_EXTENDED_DYNAMIC_STATE_2_SPEC_VERSION = 1

VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME = "VK_EXT_extended_dynamic_state2"

VK_QNX_SCREEN_SURFACE_SPEC_VERSION = 1

VK_QNX_SCREEN_SURFACE_EXTENSION_NAME = "VK_QNX_screen_surface"

VK_KHR_EXTENSION_380_SPEC_VERSION = 0

VK_KHR_EXTENSION_380_EXTENSION_NAME = "VK_KHR_extension_380"

VK_KHR_EXTENSION_381_SPEC_VERSION = 0

VK_KHR_EXTENSION_381_EXTENSION_NAME = "VK_KHR_extension_381"

VK_EXT_COLOR_WRITE_ENABLE_SPEC_VERSION = 1

VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME = "VK_EXT_color_write_enable"

VK_EXT_PRIMITIVES_GENERATED_QUERY_SPEC_VERSION = 1

VK_EXT_PRIMITIVES_GENERATED_QUERY_EXTENSION_NAME = "VK_EXT_primitives_generated_query"

VK_EXT_EXTENSION_384_SPEC_VERSION = 0

VK_EXT_EXTENSION_384_EXTENSION_NAME = "VK_EXT_extension_384"

VK_MESA_EXTENSION_385_SPEC_VERSION = 0

VK_MESA_EXTENSION_385_EXTENSION_NAME = "VK_MESA_extension_385"

VK_GOOGLE_EXTENSION_386_SPEC_VERSION = 0

VK_GOOGLE_EXTENSION_386_EXTENSION_NAME = "VK_GOOGLE_extension_386"

VK_KHR_RAY_TRACING_MAINTENANCE_1_SPEC_VERSION = 1

VK_KHR_RAY_TRACING_MAINTENANCE_1_EXTENSION_NAME = "VK_KHR_ray_tracing_maintenance1"

VK_EXT_EXTENSION_388_SPEC_VERSION = 0

VK_EXT_EXTENSION_388_EXTENSION_NAME = "VK_EXT_extension_388"

VK_EXT_GLOBAL_PRIORITY_QUERY_SPEC_VERSION = 1

VK_EXT_GLOBAL_PRIORITY_QUERY_EXTENSION_NAME = "VK_EXT_global_priority_query"

VK_EXT_EXTENSION_390_SPEC_VERSION = 0

VK_EXT_EXTENSION_390_EXTENSION_NAME = "VK_EXT_extension_390"

VK_EXT_EXTENSION_391_SPEC_VERSION = 0

VK_EXT_EXTENSION_391_EXTENSION_NAME = "VK_EXT_extension_391"

VK_EXT_IMAGE_VIEW_MIN_LOD_SPEC_VERSION = 1

VK_EXT_IMAGE_VIEW_MIN_LOD_EXTENSION_NAME = "VK_EXT_image_view_min_lod"

VK_EXT_MULTI_DRAW_SPEC_VERSION = 1

VK_EXT_MULTI_DRAW_EXTENSION_NAME = "VK_EXT_multi_draw"

VK_EXT_IMAGE_2D_VIEW_OF_3D_SPEC_VERSION = 1

VK_EXT_IMAGE_2D_VIEW_OF_3D_EXTENSION_NAME = "VK_EXT_image_2d_view_of_3d"

VK_KHR_PORTABILITY_ENUMERATION_SPEC_VERSION = 1

VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME = "VK_KHR_portability_enumeration"

VK_EXT_SHADER_TILE_IMAGE_SPEC_VERSION = 1

VK_EXT_SHADER_TILE_IMAGE_EXTENSION_NAME = "VK_EXT_shader_tile_image"

VK_EXT_OPACITY_MICROMAP_SPEC_VERSION = 2

VK_EXT_OPACITY_MICROMAP_EXTENSION_NAME = "VK_EXT_opacity_micromap"

VK_NV_DISPLACEMENT_MICROMAP_SPEC_VERSION = 2

VK_NV_DISPLACEMENT_MICROMAP_EXTENSION_NAME = "VK_NV_displacement_micromap"

VK_JUICE_EXTENSION_399_SPEC_VERSION = 0

VK_JUICE_EXTENSION_399_EXTENSION_NAME = "VK_JUICE_extension_399"

VK_JUICE_EXTENSION_400_SPEC_VERSION = 0

VK_JUICE_EXTENSION_400_EXTENSION_NAME = "VK_JUICE_extension_400"

VK_EXT_LOAD_STORE_OP_NONE_SPEC_VERSION = 1

VK_EXT_LOAD_STORE_OP_NONE_EXTENSION_NAME = "VK_EXT_load_store_op_none"

VK_FB_EXTENSION_402_SPEC_VERSION = 0

VK_FB_EXTENSION_402_EXTENSION_NAME = "VK_FB_extension_402"

VK_FB_EXTENSION_403_SPEC_VERSION = 0

VK_FB_EXTENSION_403_EXTENSION_NAME = "VK_FB_extension_403"

VK_FB_EXTENSION_404_SPEC_VERSION = 0

VK_FB_EXTENSION_404_EXTENSION_NAME = "VK_FB_extension_404"

VK_HUAWEI_CLUSTER_CULLING_SHADER_SPEC_VERSION = 3

VK_HUAWEI_CLUSTER_CULLING_SHADER_EXTENSION_NAME = "VK_HUAWEI_cluster_culling_shader"

VK_HUAWEI_EXTENSION_406_SPEC_VERSION = 0

VK_HUAWEI_EXTENSION_406_EXTENSION_NAME = "VK_HUAWEI_extension_406"

VK_GGP_EXTENSION_407_SPEC_VERSION = 0

VK_GGP_EXTENSION_407_EXTENSION_NAME = "VK_GGP_extension_407"

VK_GGP_EXTENSION_408_SPEC_VERSION = 0

VK_GGP_EXTENSION_408_EXTENSION_NAME = "VK_GGP_extension_408"

VK_GGP_EXTENSION_409_SPEC_VERSION = 0

VK_GGP_EXTENSION_409_EXTENSION_NAME = "VK_GGP_extension_409"

VK_GGP_EXTENSION_410_SPEC_VERSION = 0

VK_GGP_EXTENSION_410_EXTENSION_NAME = "VK_GGP_extension_410"

VK_GGP_EXTENSION_411_SPEC_VERSION = 0

VK_GGP_EXTENSION_411_EXTENSION_NAME = "VK_GGP_extension_411"

VK_EXT_BORDER_COLOR_SWIZZLE_SPEC_VERSION = 1

VK_EXT_BORDER_COLOR_SWIZZLE_EXTENSION_NAME = "VK_EXT_border_color_swizzle"

VK_EXT_PAGEABLE_DEVICE_LOCAL_MEMORY_SPEC_VERSION = 1

VK_EXT_PAGEABLE_DEVICE_LOCAL_MEMORY_EXTENSION_NAME = "VK_EXT_pageable_device_local_memory"

VK_KHR_MAINTENANCE_4_SPEC_VERSION = 2

VK_KHR_MAINTENANCE_4_EXTENSION_NAME = "VK_KHR_maintenance4"

VK_HUAWEI_EXTENSION_415_SPEC_VERSION = 0

VK_HUAWEI_EXTENSION_415_EXTENSION_NAME = "VK_HUAWEI_extension_415"

VK_ARM_SHADER_CORE_PROPERTIES_SPEC_VERSION = 1

VK_ARM_SHADER_CORE_PROPERTIES_EXTENSION_NAME = "VK_ARM_shader_core_properties"

VK_KHR_EXTENSION_417_SPEC_VERSION = 0

VK_KHR_EXTENSION_417_EXTENSION_NAME = "VK_KHR_extension_417"

VK_ARM_SCHEDULING_CONTROLS_SPEC_VERSION = 1

VK_ARM_SCHEDULING_CONTROLS_EXTENSION_NAME = "VK_ARM_scheduling_controls"

VK_EXT_IMAGE_SLICED_VIEW_OF_3D_SPEC_VERSION = 1

VK_EXT_IMAGE_SLICED_VIEW_OF_3D_EXTENSION_NAME = "VK_EXT_image_sliced_view_of_3d"

VK_EXT_EXTENSION_420_SPEC_VERSION = 0

VK_EXT_EXTENSION_420_EXTENSION_NAME = "VK_EXT_extension_420"

VK_VALVE_DESCRIPTOR_SET_HOST_MAPPING_SPEC_VERSION = 1

VK_VALVE_DESCRIPTOR_SET_HOST_MAPPING_EXTENSION_NAME = "VK_VALVE_descriptor_set_host_mapping"

VK_EXT_DEPTH_CLAMP_ZERO_ONE_SPEC_VERSION = 1

VK_EXT_DEPTH_CLAMP_ZERO_ONE_EXTENSION_NAME = "VK_EXT_depth_clamp_zero_one"

VK_EXT_NON_SEAMLESS_CUBE_MAP_SPEC_VERSION = 1

VK_EXT_NON_SEAMLESS_CUBE_MAP_EXTENSION_NAME = "VK_EXT_non_seamless_cube_map"

VK_ARM_EXTENSION_424_SPEC_VERSION = 0

VK_ARM_EXTENSION_424_EXTENSION_NAME = "VK_ARM_extension_424"

VK_ARM_RENDER_PASS_STRIPED_SPEC_VERSION = 1

VK_ARM_RENDER_PASS_STRIPED_EXTENSION_NAME = "VK_ARM_render_pass_striped"

VK_QCOM_FRAGMENT_DENSITY_MAP_OFFSET_SPEC_VERSION = 1

VK_QCOM_FRAGMENT_DENSITY_MAP_OFFSET_EXTENSION_NAME = "VK_QCOM_fragment_density_map_offset"

VK_NV_COPY_MEMORY_INDIRECT_SPEC_VERSION = 1

VK_NV_COPY_MEMORY_INDIRECT_EXTENSION_NAME = "VK_NV_copy_memory_indirect"

VK_NV_MEMORY_DECOMPRESSION_SPEC_VERSION = 1

VK_NV_MEMORY_DECOMPRESSION_EXTENSION_NAME = "VK_NV_memory_decompression"

VK_NV_DEVICE_GENERATED_COMMANDS_COMPUTE_SPEC_VERSION = 2

VK_NV_DEVICE_GENERATED_COMMANDS_COMPUTE_EXTENSION_NAME = "VK_NV_device_generated_commands_compute"

VK_NV_EXTENSION_430_SPEC_VERSION = 0

VK_NV_EXTENSION_430_EXTENSION_NAME = "VK_NV_extension_430"

VK_NV_LINEAR_COLOR_ATTACHMENT_SPEC_VERSION = 1

VK_NV_LINEAR_COLOR_ATTACHMENT_EXTENSION_NAME = "VK_NV_linear_color_attachment"

VK_NV_EXTENSION_432_SPEC_VERSION = 0

VK_NV_EXTENSION_432_EXTENSION_NAME = "VK_NV_extension_432"

VK_NV_EXTENSION_433_SPEC_VERSION = 0

VK_NV_EXTENSION_433_EXTENSION_NAME = "VK_NV_extension_433"

VK_GOOGLE_SURFACELESS_QUERY_SPEC_VERSION = 2

VK_GOOGLE_SURFACELESS_QUERY_EXTENSION_NAME = "VK_GOOGLE_surfaceless_query"

VK_KHR_EXTENSION_435_SPEC_VERSION = 0

VK_KHR_EXTENSION_435_EXTENSION_NAME = "VK_KHR_extension_435"

VK_EXT_APPLICATION_PARAMETERS_SPEC_VERSION = 1

VK_EXT_APPLICATION_PARAMETERS_EXTENSION_NAME = "VK_EXT_application_parameters"

VK_EXT_EXTENSION_437_SPEC_VERSION = 0

VK_EXT_EXTENSION_437_EXTENSION_NAME = "VK_EXT_extension_437"

VK_EXT_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_SPEC_VERSION = 1

VK_EXT_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_EXTENSION_NAME = "VK_EXT_image_compression_control_swapchain"

VK_SEC_EXTENSION_439_SPEC_VERSION = 0

VK_SEC_EXTENSION_439_EXTENSION_NAME = "VK_SEC_extension_439"

VK_QCOM_EXTENSION_440_SPEC_VERSION = 0

VK_QCOM_EXTENSION_440_EXTENSION_NAME = "VK_QCOM_extension_440"

VK_QCOM_IMAGE_PROCESSING_SPEC_VERSION = 1

VK_QCOM_IMAGE_PROCESSING_EXTENSION_NAME = "VK_QCOM_image_processing"

VK_COREAVI_EXTENSION_442_SPEC_VERSION = 0

VK_COREAVI_EXTENSION_442_EXTENSION_NAME = "VK_COREAVI_extension_442"

VK_COREAVI_EXTENSION_443_SPEC_VERSION = 0

VK_COREAVI_EXTENSION_443_EXTENSION_NAME = "VK_COREAVI_extension_443"

VK_COREAVI_EXTENSION_444_SPEC_VERSION = 0

VK_COREAVI_EXTENSION_444_EXTENSION_NAME = "VK_COREAVI_extension_444"

VK_COREAVI_EXTENSION_445_SPEC_VERSION = 0

VK_COREAVI_EXTENSION_445_EXTENSION_NAME = "VK_COREAVI_extension_445"

VK_COREAVI_EXTENSION_446_SPEC_VERSION = 0

VK_COREAVI_EXTENSION_446_EXTENSION_NAME = "VK_COREAVI_extension_446"

VK_COREAVI_EXTENSION_447_SPEC_VERSION = 0

VK_COREAVI_EXTENSION_447_EXTENSION_NAME = "VK_COREAVI_extension_447"

VK_SEC_EXTENSION_448_SPEC_VERSION = 0

VK_SEC_EXTENSION_448_EXTENSION_NAME = "VK_SEC_extension_448"

VK_SEC_EXTENSION_449_SPEC_VERSION = 0

VK_SEC_EXTENSION_449_EXTENSION_NAME = "VK_SEC_extension_449"

VK_SEC_EXTENSION_450_SPEC_VERSION = 0

VK_SEC_EXTENSION_450_EXTENSION_NAME = "VK_SEC_extension_450"

VK_SEC_EXTENSION_451_SPEC_VERSION = 0

VK_SEC_EXTENSION_451_EXTENSION_NAME = "VK_SEC_extension_451"

VK_EXT_NESTED_COMMAND_BUFFER_SPEC_VERSION = 1

VK_EXT_NESTED_COMMAND_BUFFER_EXTENSION_NAME = "VK_EXT_nested_command_buffer"

VK_ARM_EXTENSION_453_SPEC_VERSION = 0

VK_ARM_EXTENSION_453_EXTENSION_NAME = "VK_ARM_extension_453"

VK_EXT_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_SPEC_VERSION = 1

VK_EXT_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXTENSION_NAME = "VK_EXT_external_memory_acquire_unmodified"

VK_GOOGLE_EXTENSION_455_SPEC_VERSION = 0

VK_GOOGLE_EXTENSION_455_EXTENSION_NAME = "VK_GOOGLE_extension_455"

VK_EXT_EXTENDED_DYNAMIC_STATE_3_SPEC_VERSION = 2

VK_EXT_EXTENDED_DYNAMIC_STATE_3_EXTENSION_NAME = "VK_EXT_extended_dynamic_state3"

VK_EXT_EXTENSION_457_SPEC_VERSION = 0

VK_EXT_EXTENSION_457_EXTENSION_NAME = "VK_EXT_extension_457"

VK_EXT_EXTENSION_458_SPEC_VERSION = 0

VK_EXT_EXTENSION_458_EXTENSION_NAME = "VK_EXT_extension_458"

VK_EXT_SUBPASS_MERGE_FEEDBACK_SPEC_VERSION = 2

VK_EXT_SUBPASS_MERGE_FEEDBACK_EXTENSION_NAME = "VK_EXT_subpass_merge_feedback"

VK_LUNARG_DIRECT_DRIVER_LOADING_SPEC_VERSION = 1

VK_LUNARG_DIRECT_DRIVER_LOADING_EXTENSION_NAME = "VK_LUNARG_direct_driver_loading"

VK_EXT_EXTENSION_461_SPEC_VERSION = 0

VK_EXT_EXTENSION_461_EXTENSION_NAME = "VK_EXT_extension_461"

VK_EXT_EXTENSION_462_SPEC_VERSION = 0

VK_EXT_EXTENSION_462_EXTENSION_NAME = "VK_EXT_extension_462"

VK_EXT_SHADER_MODULE_IDENTIFIER_SPEC_VERSION = 1

VK_EXT_SHADER_MODULE_IDENTIFIER_EXTENSION_NAME = "VK_EXT_shader_module_identifier"

VK_EXT_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_SPEC_VERSION = 1

VK_EXT_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXTENSION_NAME = "VK_EXT_rasterization_order_attachment_access"

VK_NV_OPTICAL_FLOW_SPEC_VERSION = 1

VK_NV_OPTICAL_FLOW_EXTENSION_NAME = "VK_NV_optical_flow"

VK_EXT_LEGACY_DITHERING_SPEC_VERSION = 1

VK_EXT_LEGACY_DITHERING_EXTENSION_NAME = "VK_EXT_legacy_dithering"

VK_EXT_PIPELINE_PROTECTED_ACCESS_SPEC_VERSION = 1

VK_EXT_PIPELINE_PROTECTED_ACCESS_EXTENSION_NAME = "VK_EXT_pipeline_protected_access"

VK_EXT_EXTENSION_468_SPEC_VERSION = 0

VK_EXT_EXTENSION_468_EXTENSION_NAME = "VK_EXT_extension_468"

VK_ANDROID_EXTERNAL_FORMAT_RESOLVE_SPEC_VERSION = 1

VK_ANDROID_EXTERNAL_FORMAT_RESOLVE_EXTENSION_NAME = "VK_ANDROID_external_format_resolve"

VK_AMD_EXTENSION_470_SPEC_VERSION = 0

VK_AMD_EXTENSION_470_EXTENSION_NAME = "VK_AMD_extension_470"

VK_KHR_MAINTENANCE_5_SPEC_VERSION = 1

VK_KHR_MAINTENANCE_5_EXTENSION_NAME = "VK_KHR_maintenance5"

VK_AMD_EXTENSION_472_SPEC_VERSION = 0

VK_AMD_EXTENSION_472_EXTENSION_NAME = "VK_AMD_extension_472"

VK_AMD_EXTENSION_473_SPEC_VERSION = 0

VK_AMD_EXTENSION_473_EXTENSION_NAME = "VK_AMD_extension_473"

VK_AMD_EXTENSION_474_SPEC_VERSION = 0

VK_AMD_EXTENSION_474_EXTENSION_NAME = "VK_AMD_extension_474"

VK_AMD_EXTENSION_475_SPEC_VERSION = 0

VK_AMD_EXTENSION_475_EXTENSION_NAME = "VK_AMD_extension_475"

VK_AMD_EXTENSION_476_SPEC_VERSION = 0

VK_AMD_EXTENSION_476_EXTENSION_NAME = "VK_AMD_extension_476"

VK_AMD_EXTENSION_477_SPEC_VERSION = 0

VK_AMD_EXTENSION_477_EXTENSION_NAME = "VK_AMD_extension_477"

VK_AMD_EXTENSION_478_SPEC_VERSION = 0

VK_AMD_EXTENSION_478_EXTENSION_NAME = "VK_AMD_extension_478"

VK_AMD_EXTENSION_479_SPEC_VERSION = 0

VK_AMD_EXTENSION_479_EXTENSION_NAME = "VK_AMD_extension_479"

VK_EXT_EXTENSION_480_SPEC_VERSION = 0

VK_EXT_EXTENSION_480_EXTENSION_NAME = "VK_EXT_extension_480"

VK_EXT_EXTENSION_481_SPEC_VERSION = 0

VK_EXT_EXTENSION_481_EXTENSION_NAME = "VK_EXT_extension_481"

VK_KHR_RAY_TRACING_POSITION_FETCH_SPEC_VERSION = 1

VK_KHR_RAY_TRACING_POSITION_FETCH_EXTENSION_NAME = "VK_KHR_ray_tracing_position_fetch"

VK_EXT_SHADER_OBJECT_SPEC_VERSION = 1

VK_EXT_SHADER_OBJECT_EXTENSION_NAME = "VK_EXT_shader_object"

VK_EXT_EXTENSION_484_SPEC_VERSION = 0

VK_EXT_EXTENSION_484_EXTENSION_NAME = "VK_EXT_extension_484"

VK_QCOM_TILE_PROPERTIES_SPEC_VERSION = 1

VK_QCOM_TILE_PROPERTIES_EXTENSION_NAME = "VK_QCOM_tile_properties"

VK_SEC_AMIGO_PROFILING_SPEC_VERSION = 1

VK_SEC_AMIGO_PROFILING_EXTENSION_NAME = "VK_SEC_amigo_profiling"

VK_EXT_EXTENSION_487_SPEC_VERSION = 0

VK_EXT_EXTENSION_487_EXTENSION_NAME = "VK_EXT_extension_487"

VK_EXT_EXTENSION_488_SPEC_VERSION = 0

VK_EXT_EXTENSION_488_EXTENSION_NAME = "VK_EXT_extension_488"

VK_QCOM_MULTIVIEW_PER_VIEW_VIEWPORTS_SPEC_VERSION = 1

VK_QCOM_MULTIVIEW_PER_VIEW_VIEWPORTS_EXTENSION_NAME = "VK_QCOM_multiview_per_view_viewports"

VK_NV_EXTERNAL_SCI_SYNC_2_SPEC_VERSION = 1

VK_NV_EXTERNAL_SCI_SYNC_2_EXTENSION_NAME = "VK_NV_external_sci_sync2"

VK_NV_RAY_TRACING_INVOCATION_REORDER_SPEC_VERSION = 1

VK_NV_RAY_TRACING_INVOCATION_REORDER_EXTENSION_NAME = "VK_NV_ray_tracing_invocation_reorder"

VK_NV_EXTENSION_492_SPEC_VERSION = 0

VK_NV_EXTENSION_492_EXTENSION_NAME = "VK_NV_extension_492"

VK_NV_EXTENDED_SPARSE_ADDRESS_SPACE_SPEC_VERSION = 1

VK_NV_EXTENDED_SPARSE_ADDRESS_SPACE_EXTENSION_NAME = "VK_NV_extended_sparse_address_space"

VK_NV_EXTENSION_494_SPEC_VERSION = 0

VK_NV_EXTENSION_494_EXTENSION_NAME = "VK_NV_extension_494"

VK_EXT_MUTABLE_DESCRIPTOR_TYPE_SPEC_VERSION = 1

VK_EXT_MUTABLE_DESCRIPTOR_TYPE_EXTENSION_NAME = "VK_EXT_mutable_descriptor_type"

VK_EXT_EXTENSION_496_SPEC_VERSION = 0

VK_EXT_EXTENSION_496_EXTENSION_NAME = "VK_EXT_extension_496"

VK_EXT_LAYER_SETTINGS_SPEC_VERSION = 2

VK_EXT_LAYER_SETTINGS_EXTENSION_NAME = "VK_EXT_layer_settings"

VK_ARM_SHADER_CORE_BUILTINS_SPEC_VERSION = 2

VK_ARM_SHADER_CORE_BUILTINS_EXTENSION_NAME = "VK_ARM_shader_core_builtins"

VK_EXT_PIPELINE_LIBRARY_GROUP_HANDLES_SPEC_VERSION = 1

VK_EXT_PIPELINE_LIBRARY_GROUP_HANDLES_EXTENSION_NAME = "VK_EXT_pipeline_library_group_handles"

VK_EXT_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_SPEC_VERSION = 1

VK_EXT_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_EXTENSION_NAME = "VK_EXT_dynamic_rendering_unused_attachments"

VK_EXT_EXTENSION_501_SPEC_VERSION = 0

VK_EXT_EXTENSION_501_EXTENSION_NAME = "VK_EXT_extension_501"

VK_EXT_EXTENSION_502_SPEC_VERSION = 0

VK_EXT_EXTENSION_502_EXTENSION_NAME = "VK_EXT_extension_502"

VK_EXT_EXTENSION_503_SPEC_VERSION = 0

VK_EXT_EXTENSION_503_EXTENSION_NAME = "VK_EXT_extension_503"

VK_NV_EXTENSION_504_SPEC_VERSION = 0

VK_NV_EXTENSION_504_EXTENSION_NAME = "VK_NV_extension_504"

VK_EXT_EXTENSION_505_SPEC_VERSION = 0

VK_EXT_EXTENSION_505_EXTENSION_NAME = "VK_EXT_extension_505"

VK_NV_LOW_LATENCY_2_SPEC_VERSION = 2

VK_NV_LOW_LATENCY_2_EXTENSION_NAME = "VK_NV_low_latency2"

VK_KHR_COOPERATIVE_MATRIX_SPEC_VERSION = 2

VK_KHR_COOPERATIVE_MATRIX_EXTENSION_NAME = "VK_KHR_cooperative_matrix"

VK_EXT_EXTENSION_508_SPEC_VERSION = 0

VK_EXT_EXTENSION_508_EXTENSION_NAME = "VK_EXT_extension_508"

VK_EXT_EXTENSION_509_SPEC_VERSION = 0

VK_EXT_EXTENSION_509_EXTENSION_NAME = "VK_EXT_extension_509"

VK_MESA_EXTENSION_510_SPEC_VERSION = 0

VK_MESA_EXTENSION_510_EXTENSION_NAME = "VK_MESA_extension_510"

VK_QCOM_MULTIVIEW_PER_VIEW_RENDER_AREAS_SPEC_VERSION = 1

VK_QCOM_MULTIVIEW_PER_VIEW_RENDER_AREAS_EXTENSION_NAME = "VK_QCOM_multiview_per_view_render_areas"

VK_EXT_EXTENSION_512_SPEC_VERSION = 0

VK_EXT_EXTENSION_512_EXTENSION_NAME = "VK_EXT_extension_512"

VK_KHR_EXTENSION_513_SPEC_VERSION = 0

VK_KHR_EXTENSION_513_EXTENSION_NAME = "VK_KHR_extension_513"

VK_KHR_EXTENSION_514_SPEC_VERSION = 0

VK_KHR_EXTENSION_514_EXTENSION_NAME = "VK_KHR_extension_514"

VK_KHR_EXTENSION_515_SPEC_VERSION = 0

VK_KHR_EXTENSION_515_EXTENSION_NAME = "VK_KHR_extension_515"

VK_KHR_VIDEO_MAINTENANCE_1_SPEC_VERSION = 1

VK_KHR_VIDEO_MAINTENANCE_1_EXTENSION_NAME = "VK_KHR_video_maintenance1"

VK_NV_PER_STAGE_DESCRIPTOR_SET_SPEC_VERSION = 1

VK_NV_PER_STAGE_DESCRIPTOR_SET_EXTENSION_NAME = "VK_NV_per_stage_descriptor_set"

VK_MESA_EXTENSION_518_SPEC_VERSION = 0

VK_MESA_EXTENSION_518_EXTENSION_NAME = "VK_MESA_extension_518"

VK_QCOM_IMAGE_PROCESSING_2_SPEC_VERSION = 1

VK_QCOM_IMAGE_PROCESSING_2_EXTENSION_NAME = "VK_QCOM_image_processing2"

VK_QCOM_FILTER_CUBIC_WEIGHTS_SPEC_VERSION = 1

VK_QCOM_FILTER_CUBIC_WEIGHTS_EXTENSION_NAME = "VK_QCOM_filter_cubic_weights"

VK_QCOM_YCBCR_DEGAMMA_SPEC_VERSION = 1

VK_QCOM_YCBCR_DEGAMMA_EXTENSION_NAME = "VK_QCOM_ycbcr_degamma"

VK_QCOM_FILTER_CUBIC_CLAMP_SPEC_VERSION = 1

VK_QCOM_FILTER_CUBIC_CLAMP_EXTENSION_NAME = "VK_QCOM_filter_cubic_clamp"

VK_EXT_EXTENSION_523_SPEC_VERSION = 0

VK_EXT_EXTENSION_523_EXTENSION_NAME = "VK_EXT_extension_523"

VK_EXT_EXTENSION_524_SPEC_VERSION = 0

VK_EXT_EXTENSION_524_EXTENSION_NAME = "VK_EXT_extension_524"

VK_EXT_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_SPEC_VERSION = 1

VK_EXT_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_EXTENSION_NAME = "VK_EXT_attachment_feedback_loop_dynamic_state"

VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION = 1

VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME = "VK_KHR_vertex_attribute_divisor"

VK_EXT_EXTENSION_527_SPEC_VERSION = 0

VK_EXT_EXTENSION_527_EXTENSION_NAME = "VK_EXT_extension_527"

VK_EXT_EXTENSION_528_SPEC_VERSION = 0

VK_EXT_EXTENSION_528_EXTENSION_NAME = "VK_EXT_extension_528"

VK_KHR_EXTENSION_529_SPEC_VERSION = 0

VK_KHR_EXTENSION_529_EXTENSION_NAME = "VK_KHR_extension_529"

VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_SPEC_VERSION = 1

VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_EXTENSION_NAME = "VK_QNX_external_memory_screen_buffer"

VK_MSFT_LAYERED_DRIVER_SPEC_VERSION = 1

VK_MSFT_LAYERED_DRIVER_EXTENSION_NAME = "VK_MSFT_layered_driver"

VK_KHR_EXTENSION_532_SPEC_VERSION = 0

VK_KHR_EXTENSION_532_EXTENSION_NAME = "VK_KHR_extension_532"

VK_EXT_EXTENSION_533_SPEC_VERSION = 0

VK_EXT_EXTENSION_533_EXTENSION_NAME = "VK_EXT_extension_533"

VK_KHR_EXTENSION_534_SPEC_VERSION = 0

VK_KHR_EXTENSION_534_EXTENSION_NAME = "VK_KHR_extension_534"

VK_KHR_EXTENSION_535_SPEC_VERSION = 0

VK_KHR_EXTENSION_535_EXTENSION_NAME = "VK_KHR_extension_535"

VK_QCOM_EXTENSION_536_SPEC_VERSION = 0

VK_QCOM_EXTENSION_536_EXTENSION_NAME = "VK_QCOM_extension_536"

VK_EXT_EXTENSION_537_SPEC_VERSION = 0

VK_EXT_EXTENSION_537_EXTENSION_NAME = "VK_EXT_extension_537"

VK_EXT_EXTENSION_538_SPEC_VERSION = 0

VK_EXT_EXTENSION_538_EXTENSION_NAME = "VK_EXT_extension_538"

VK_EXT_EXTENSION_539_SPEC_VERSION = 0

VK_EXT_EXTENSION_539_EXTENSION_NAME = "VK_EXT_extension_539"

VK_EXT_EXTENSION_540_SPEC_VERSION = 0

VK_EXT_EXTENSION_540_EXTENSION_NAME = "VK_EXT_extension_540"

VK_EXT_EXTENSION_541_SPEC_VERSION = 0

VK_EXT_EXTENSION_541_EXTENSION_NAME = "VK_EXT_extension_541"

VK_EXT_EXTENSION_542_SPEC_VERSION = 0

VK_EXT_EXTENSION_542_EXTENSION_NAME = "VK_EXT_extension_542"

VK_EXT_EXTENSION_543_SPEC_VERSION = 0

VK_EXT_EXTENSION_543_EXTENSION_NAME = "VK_EXT_extension_543"

VK_KHR_CALIBRATED_TIMESTAMPS_SPEC_VERSION = 1

VK_KHR_CALIBRATED_TIMESTAMPS_EXTENSION_NAME = "VK_KHR_calibrated_timestamps"

VK_KHR_EXTENSION_545_SPEC_VERSION = 0

VK_KHR_EXTENSION_545_EXTENSION_NAME = "VK_KHR_extension_545"

VK_KHR_MAINTENANCE_6_SPEC_VERSION = 1

VK_KHR_MAINTENANCE_6_EXTENSION_NAME = "VK_KHR_maintenance6"

VK_NV_DESCRIPTOR_POOL_OVERALLOCATION_SPEC_VERSION = 1

VK_NV_DESCRIPTOR_POOL_OVERALLOCATION_EXTENSION_NAME = "VK_NV_descriptor_pool_overallocation"

VK_QCOM_EXTENSION_548_SPEC_VERSION = 0

VK_QCOM_EXTENSION_548_EXTENSION_NAME = "VK_QCOM_extension_548"

VK_NV_EXTENSION_549_SPEC_VERSION = 0

VK_NV_EXTENSION_549_EXTENSION_NAME = "VK_NV_extension_549"

VK_NV_EXTENSION_550_SPEC_VERSION = 0

VK_NV_EXTENSION_550_EXTENSION_NAME = "VK_NV_extension_550"

VK_NV_EXTENSION_551_SPEC_VERSION = 0

VK_NV_EXTENSION_551_EXTENSION_NAME = "VK_NV_extension_551"

VK_NV_EXTENSION_552_SPEC_VERSION = 0

VK_NV_EXTENSION_552_EXTENSION_NAME = "VK_NV_extension_552"

VK_KHR_EXTENSION_553_SPEC_VERSION = 0

VK_KHR_EXTENSION_553_EXTENSION_NAME = "VK_KHR_extension_553"

VK_KHR_EXTENSION_554_SPEC_VERSION = 0

VK_KHR_EXTENSION_554_EXTENSION_NAME = "VK_KHR_extension_554"

VK_IMG_EXTENSION_555_SPEC_VERSION = 0

VK_IMG_EXTENSION_555_EXTENSION_NAME = "VK_IMG_extension_555"

VK_NV_EXTENSION_556_SPEC_VERSION = 1

VK_NV_EXTENSION_556_EXTENSION_NAME = "VK_NV_extension_556"

RETURN_CODES.update({
    result_field.value: result_field.name
    for result_field in VkResult
    if isinstance(result_field.value, int)
})

__all__ = (
    "VK_MAKE_VIDEO_STD_VERSION",
    "VK_STD_VULKAN_VIDEO_CODEC_H264_DECODE_API_VERSION_1_0_0",
    "VK_STD_VULKAN_VIDEO_CODEC_H264_ENCODE_API_VERSION_1_0_0",
    "VK_STD_VULKAN_VIDEO_CODEC_H265_DECODE_API_VERSION_1_0_0",
    "VK_STD_VULKAN_VIDEO_CODEC_H265_ENCODE_API_VERSION_1_0_0",
    "StdVideoH264ChromaFormatIdc",
    "StdVideoH264ProfileIdc",
    "StdVideoH264LevelIdc",
    "StdVideoH264PocType",
    "StdVideoH264AspectRatioIdc",
    "StdVideoH264WeightedBipredIdc",
    "StdVideoH264ModificationOfPicNumsIdc",
    "StdVideoH264MemMgmtControlOp",
    "StdVideoH264CabacInitIdc",
    "StdVideoH264DisableDeblockingFilterIdc",
    "StdVideoH264SliceType",
    "StdVideoH264PictureType",
    "StdVideoH264NonVclNaluType",
    "StdVideoH264SpsVuiFlags",
    "StdVideoH264HrdParameters",
    "StdVideoH264SequenceParameterSetVui",
    "StdVideoH264SpsFlags",
    "StdVideoH264ScalingLists",
    "StdVideoH264SequenceParameterSet",
    "StdVideoH264PpsFlags",
    "StdVideoH264PictureParameterSet",
    "StdVideoDecodeH264FieldOrderCount",
    "StdVideoDecodeH264PictureInfoFlags",
    "StdVideoDecodeH264PictureInfo",
    "StdVideoDecodeH264ReferenceInfoFlags",
    "StdVideoDecodeH264ReferenceInfo",
    "StdVideoEncodeH264WeightTableFlags",
    "StdVideoEncodeH264WeightTable",
    "StdVideoEncodeH264SliceHeaderFlags",
    "StdVideoEncodeH264PictureInfoFlags",
    "StdVideoEncodeH264ReferenceInfoFlags",
    "StdVideoEncodeH264ReferenceListsInfoFlags",
    "StdVideoEncodeH264RefListModEntry",
    "StdVideoEncodeH264RefPicMarkingEntry",
    "StdVideoEncodeH264ReferenceListsInfo",
    "StdVideoEncodeH264PictureInfo",
    "StdVideoEncodeH264ReferenceInfo",
    "StdVideoEncodeH264SliceHeader",
    "StdVideoH265ChromaFormatIdc",
    "StdVideoH265ProfileIdc",
    "StdVideoH265LevelIdc",
    "StdVideoH265SliceType",
    "StdVideoH265PictureType",
    "StdVideoH265AspectRatioIdc",
    "StdVideoH265ProfileTierLevelFlags",
    "StdVideoH265ProfileTierLevel",
    "StdVideoH265DecPicBufMgr",
    "StdVideoH265SubLayerHrdParameters",
    "StdVideoH265HrdFlags",
    "StdVideoH265HrdParameters",
    "StdVideoH265VpsFlags",
    "StdVideoH265VideoParameterSet",
    "StdVideoH265ScalingLists",
    "StdVideoH265ShortTermRefPicSetFlags",
    "StdVideoH265ShortTermRefPicSet",
    "StdVideoH265LongTermRefPicsSps",
    "StdVideoH265SpsVuiFlags",
    "StdVideoH265SequenceParameterSetVui",
    "StdVideoH265PredictorPaletteEntries",
    "StdVideoH265SpsFlags",
    "StdVideoH265SequenceParameterSet",
    "StdVideoH265PpsFlags",
    "StdVideoH265PictureParameterSet",
    "StdVideoDecodeH265PictureInfoFlags",
    "StdVideoDecodeH265PictureInfo",
    "StdVideoDecodeH265ReferenceInfoFlags",
    "StdVideoDecodeH265ReferenceInfo",
    "StdVideoEncodeH265WeightTableFlags",
    "StdVideoEncodeH265WeightTable",
    "StdVideoEncodeH265LongTermRefPics",
    "StdVideoEncodeH265SliceSegmentHeaderFlags",
    "StdVideoEncodeH265SliceSegmentHeader",
    "StdVideoEncodeH265ReferenceListsInfoFlags",
    "StdVideoEncodeH265ReferenceListsInfo",
    "StdVideoEncodeH265PictureInfoFlags",
    "StdVideoEncodeH265PictureInfo",
    "StdVideoEncodeH265ReferenceInfoFlags",
    "StdVideoEncodeH265ReferenceInfo",
    "STD_VIDEO_H264_CPB_CNT_LIST_SIZE",
    "STD_VIDEO_H264_SCALING_LIST_4X4_NUM_LISTS",
    "STD_VIDEO_H264_SCALING_LIST_4X4_NUM_ELEMENTS",
    "STD_VIDEO_H264_SCALING_LIST_8X8_NUM_LISTS",
    "STD_VIDEO_H264_SCALING_LIST_8X8_NUM_ELEMENTS",
    "STD_VIDEO_H264_MAX_NUM_LIST_REF",
    "STD_VIDEO_H264_MAX_CHROMA_PLANES",
    "STD_VIDEO_H264_NO_REFERENCE_PICTURE",
    "VK_STD_VULKAN_VIDEO_CODEC_H264_DECODE_SPEC_VERSION",
    "VK_STD_VULKAN_VIDEO_CODEC_H264_DECODE_EXTENSION_NAME",
    "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_LIST_SIZE",
    "VK_STD_VULKAN_VIDEO_CODEC_H264_ENCODE_SPEC_VERSION",
    "VK_STD_VULKAN_VIDEO_CODEC_H264_ENCODE_EXTENSION_NAME",
    "STD_VIDEO_H265_CPB_CNT_LIST_SIZE",
    "STD_VIDEO_H265_SUBLAYERS_LIST_SIZE",
    "STD_VIDEO_H265_SCALING_LIST_4X4_NUM_LISTS",
    "STD_VIDEO_H265_SCALING_LIST_4X4_NUM_ELEMENTS",
    "STD_VIDEO_H265_SCALING_LIST_8X8_NUM_LISTS",
    "STD_VIDEO_H265_SCALING_LIST_8X8_NUM_ELEMENTS",
    "STD_VIDEO_H265_SCALING_LIST_16X16_NUM_LISTS",
    "STD_VIDEO_H265_SCALING_LIST_16X16_NUM_ELEMENTS",
    "STD_VIDEO_H265_SCALING_LIST_32X32_NUM_LISTS",
    "STD_VIDEO_H265_SCALING_LIST_32X32_NUM_ELEMENTS",
    "STD_VIDEO_H265_CHROMA_QP_OFFSET_LIST_SIZE",
    "STD_VIDEO_H265_CHROMA_QP_OFFSET_TILE_COLS_LIST_SIZE",
    "STD_VIDEO_H265_CHROMA_QP_OFFSET_TILE_ROWS_LIST_SIZE",
    "STD_VIDEO_H265_PREDICTOR_PALETTE_COMPONENTS_LIST_SIZE",
    "STD_VIDEO_H265_PREDICTOR_PALETTE_COMP_ENTRIES_LIST_SIZE",
    "STD_VIDEO_H265_MAX_NUM_LIST_REF",
    "STD_VIDEO_H265_MAX_CHROMA_PLANES",
    "STD_VIDEO_H265_MAX_SHORT_TERM_REF_PIC_SETS",
    "STD_VIDEO_H265_MAX_DPB_SIZE",
    "STD_VIDEO_H265_MAX_LONG_TERM_REF_PICS_SPS",
    "STD_VIDEO_H265_MAX_LONG_TERM_PICS",
    "STD_VIDEO_H265_MAX_DELTA_POC",
    "STD_VIDEO_H265_NO_REFERENCE_PICTURE",
    "VK_STD_VULKAN_VIDEO_CODEC_H265_DECODE_SPEC_VERSION",
    "VK_STD_VULKAN_VIDEO_CODEC_H265_DECODE_EXTENSION_NAME",
    "STD_VIDEO_DECODE_H265_REF_PIC_SET_LIST_SIZE",
    "VK_STD_VULKAN_VIDEO_CODEC_H265_ENCODE_SPEC_VERSION",
    "VK_STD_VULKAN_VIDEO_CODEC_H265_ENCODE_EXTENSION_NAME",
    "VK_MAKE_VERSION",
    "VK_VERSION_MAJOR",
    "VK_VERSION_MINOR",
    "VK_VERSION_PATCH",
    "VK_MAKE_API_VERSION",
    "VK_API_VERSION_VARIANT",
    "VK_API_VERSION_MAJOR",
    "VK_API_VERSION_MINOR",
    "VK_API_VERSION_PATCH",
    "VK_API_VERSION",
    "VK_API_VERSION_1_0",
    "VK_API_VERSION_1_1",
    "VK_API_VERSION_1_2",
    "VK_API_VERSION_1_3",
    "VKSC_API_VERSION_1_0",
    "VK_HEADER_VERSION",
    "VKSC_API_VARIANT",
    "VK_HEADER_VERSION_COMPLETE",
    "VK_DEFINE_HANDLE",
    "VK_USE_64_BIT_PTR_DEFINES",
    "VK_NULL_HANDLE",
    "VK_DEFINE_NON_DISPATCHABLE_HANDLE",
    "VkSampleMask",
    "VkBool32",
    "VkFlags",
    "VkFlags64",
    "VkDeviceSize",
    "VkDeviceAddress",
    "VkFramebufferCreateFlags",
    "VkQueryPoolCreateFlags",
    "VkRenderPassCreateFlags",
    "VkSamplerCreateFlags",
    "VkPipelineLayoutCreateFlags",
    "VkPipelineCacheCreateFlags",
    "VkPipelineDepthStencilStateCreateFlags",
    "VkPipelineDynamicStateCreateFlags",
    "VkPipelineColorBlendStateCreateFlags",
    "VkPipelineMultisampleStateCreateFlags",
    "VkPipelineRasterizationStateCreateFlags",
    "VkPipelineViewportStateCreateFlags",
    "VkPipelineTessellationStateCreateFlags",
    "VkPipelineInputAssemblyStateCreateFlags",
    "VkPipelineVertexInputStateCreateFlags",
    "VkPipelineShaderStageCreateFlags",
    "VkDescriptorSetLayoutCreateFlags",
    "VkBufferViewCreateFlags",
    "VkInstanceCreateFlags",
    "VkDeviceCreateFlags",
    "VkDeviceQueueCreateFlags",
    "VkQueueFlags",
    "VkMemoryPropertyFlags",
    "VkMemoryHeapFlags",
    "VkAccessFlags",
    "VkBufferUsageFlags",
    "VkBufferCreateFlags",
    "VkShaderStageFlags",
    "VkImageUsageFlags",
    "VkImageCreateFlags",
    "VkImageViewCreateFlags",
    "VkPipelineCreateFlags",
    "VkColorComponentFlags",
    "VkFenceCreateFlags",
    "VkSemaphoreCreateFlags",
    "VkFormatFeatureFlags",
    "VkQueryControlFlags",
    "VkQueryResultFlags",
    "VkShaderModuleCreateFlags",
    "VkEventCreateFlags",
    "VkCommandPoolCreateFlags",
    "VkCommandPoolResetFlags",
    "VkCommandBufferResetFlags",
    "VkCommandBufferUsageFlags",
    "VkQueryPipelineStatisticFlags",
    "VkMemoryMapFlags",
    "VkMemoryUnmapFlagsKHR",
    "VkImageAspectFlags",
    "VkSparseMemoryBindFlags",
    "VkSparseImageFormatFlags",
    "VkSubpassDescriptionFlags",
    "VkPipelineStageFlags",
    "VkSampleCountFlags",
    "VkAttachmentDescriptionFlags",
    "VkStencilFaceFlags",
    "VkCullModeFlags",
    "VkDescriptorPoolCreateFlags",
    "VkDescriptorPoolResetFlags",
    "VkDependencyFlags",
    "VkSubgroupFeatureFlags",
    "VkIndirectCommandsLayoutUsageFlagsNV",
    "VkIndirectStateFlagsNV",
    "VkGeometryFlagsKHR",
    "VkGeometryFlagsNV",
    "VkGeometryInstanceFlagsKHR",
    "VkGeometryInstanceFlagsNV",
    "VkBuildAccelerationStructureFlagsKHR",
    "VkBuildAccelerationStructureFlagsNV",
    "VkPrivateDataSlotCreateFlags",
    "VkPrivateDataSlotCreateFlagsEXT",
    "VkAccelerationStructureCreateFlagsKHR",
    "VkDescriptorUpdateTemplateCreateFlags",
    "VkDescriptorUpdateTemplateCreateFlagsKHR",
    "VkPipelineCreationFeedbackFlags",
    "VkPipelineCreationFeedbackFlagsEXT",
    "VkPerformanceCounterDescriptionFlagsKHR",
    "VkAcquireProfilingLockFlagsKHR",
    "VkSemaphoreWaitFlags",
    "VkSemaphoreWaitFlagsKHR",
    "VkPipelineCompilerControlFlagsAMD",
    "VkShaderCorePropertiesFlagsAMD",
    "VkDeviceDiagnosticsConfigFlagsNV",
    "VkRefreshObjectFlagsKHR",
    "VkAccessFlags2",
    "VkAccessFlags2KHR",
    "VkPipelineStageFlags2",
    "VkPipelineStageFlags2KHR",
    "VkAccelerationStructureMotionInfoFlagsNV",
    "VkAccelerationStructureMotionInstanceFlagsNV",
    "VkFormatFeatureFlags2",
    "VkFormatFeatureFlags2KHR",
    "VkRenderingFlags",
    "VkMemoryDecompressionMethodFlagsNV",
    "VkRenderingFlagsKHR",
    "VkBuildMicromapFlagsEXT",
    "VkMicromapCreateFlagsEXT",
    "VkDirectDriverLoadingFlagsLUNARG",
    "VkPipelineCreateFlags2KHR",
    "VkBufferUsageFlags2KHR",
    "VkCompositeAlphaFlagsKHR",
    "VkDisplayPlaneAlphaFlagsKHR",
    "VkSurfaceTransformFlagsKHR",
    "VkSwapchainCreateFlagsKHR",
    "VkDisplayModeCreateFlagsKHR",
    "VkDisplaySurfaceCreateFlagsKHR",
    "VkAndroidSurfaceCreateFlagsKHR",
    "VkViSurfaceCreateFlagsNN",
    "VkWaylandSurfaceCreateFlagsKHR",
    "VkWin32SurfaceCreateFlagsKHR",
    "VkXlibSurfaceCreateFlagsKHR",
    "VkXcbSurfaceCreateFlagsKHR",
    "VkDirectFBSurfaceCreateFlagsEXT",
    "VkIOSSurfaceCreateFlagsMVK",
    "VkMacOSSurfaceCreateFlagsMVK",
    "VkMetalSurfaceCreateFlagsEXT",
    "VkImagePipeSurfaceCreateFlagsFUCHSIA",
    "VkStreamDescriptorSurfaceCreateFlagsGGP",
    "VkHeadlessSurfaceCreateFlagsEXT",
    "VkScreenSurfaceCreateFlagsQNX",
    "VkPeerMemoryFeatureFlags",
    "VkPeerMemoryFeatureFlagsKHR",
    "VkMemoryAllocateFlags",
    "VkMemoryAllocateFlagsKHR",
    "VkDeviceGroupPresentModeFlagsKHR",
    "VkDebugReportFlagsEXT",
    "VkCommandPoolTrimFlags",
    "VkCommandPoolTrimFlagsKHR",
    "VkExternalMemoryHandleTypeFlagsNV",
    "VkExternalMemoryFeatureFlagsNV",
    "VkExternalMemoryHandleTypeFlags",
    "VkExternalMemoryHandleTypeFlagsKHR",
    "VkExternalMemoryFeatureFlags",
    "VkExternalMemoryFeatureFlagsKHR",
    "VkExternalSemaphoreHandleTypeFlags",
    "VkExternalSemaphoreHandleTypeFlagsKHR",
    "VkExternalSemaphoreFeatureFlags",
    "VkExternalSemaphoreFeatureFlagsKHR",
    "VkSemaphoreImportFlags",
    "VkSemaphoreImportFlagsKHR",
    "VkExternalFenceHandleTypeFlags",
    "VkExternalFenceHandleTypeFlagsKHR",
    "VkExternalFenceFeatureFlags",
    "VkExternalFenceFeatureFlagsKHR",
    "VkFenceImportFlags",
    "VkFenceImportFlagsKHR",
    "VkSurfaceCounterFlagsEXT",
    "VkPipelineViewportSwizzleStateCreateFlagsNV",
    "VkPipelineDiscardRectangleStateCreateFlagsEXT",
    "VkPipelineCoverageToColorStateCreateFlagsNV",
    "VkPipelineCoverageModulationStateCreateFlagsNV",
    "VkPipelineCoverageReductionStateCreateFlagsNV",
    "VkValidationCacheCreateFlagsEXT",
    "VkDebugUtilsMessageSeverityFlagsEXT",
    "VkDebugUtilsMessageTypeFlagsEXT",
    "VkDebugUtilsMessengerCreateFlagsEXT",
    "VkDebugUtilsMessengerCallbackDataFlagsEXT",
    "VkDeviceMemoryReportFlagsEXT",
    "VkPipelineRasterizationConservativeStateCreateFlagsEXT",
    "VkDescriptorBindingFlags",
    "VkDescriptorBindingFlagsEXT",
    "VkConditionalRenderingFlagsEXT",
    "VkResolveModeFlags",
    "VkResolveModeFlagsKHR",
    "VkPipelineRasterizationStateStreamCreateFlagsEXT",
    "VkPipelineRasterizationDepthClipStateCreateFlagsEXT",
    "VkSwapchainImageUsageFlagsANDROID",
    "VkToolPurposeFlags",
    "VkToolPurposeFlagsEXT",
    "VkSubmitFlags",
    "VkSubmitFlagsKHR",
    "VkImageFormatConstraintsFlagsFUCHSIA",
    "VkHostImageCopyFlagsEXT",
    "VkImageConstraintsInfoFlagsFUCHSIA",
    "VkGraphicsPipelineLibraryFlagsEXT",
    "VkImageCompressionFlagsEXT",
    "VkImageCompressionFixedRateFlagsEXT",
    "VkExportMetalObjectTypeFlagsEXT",
    "VkDeviceAddressBindingFlagsEXT",
    "VkOpticalFlowGridSizeFlagsNV",
    "VkOpticalFlowUsageFlagsNV",
    "VkOpticalFlowSessionCreateFlagsNV",
    "VkOpticalFlowExecuteFlagsNV",
    "VkFrameBoundaryFlagsEXT",
    "VkPresentScalingFlagsEXT",
    "VkPresentGravityFlagsEXT",
    "VkShaderCreateFlagsEXT",
    "VkPhysicalDeviceSchedulingControlsFlagsARM",
    "VkVideoCodecOperationFlagsKHR",
    "VkVideoCapabilityFlagsKHR",
    "VkVideoSessionCreateFlagsKHR",
    "VkVideoSessionParametersCreateFlagsKHR",
    "VkVideoBeginCodingFlagsKHR",
    "VkVideoEndCodingFlagsKHR",
    "VkVideoCodingControlFlagsKHR",
    "VkVideoDecodeUsageFlagsKHR",
    "VkVideoDecodeCapabilityFlagsKHR",
    "VkVideoDecodeFlagsKHR",
    "VkVideoDecodeH264PictureLayoutFlagsKHR",
    "VkVideoEncodeFlagsKHR",
    "VkVideoEncodeUsageFlagsKHR",
    "VkVideoEncodeContentFlagsKHR",
    "VkVideoEncodeCapabilityFlagsKHR",
    "VkVideoEncodeFeedbackFlagsKHR",
    "VkVideoEncodeRateControlFlagsKHR",
    "VkVideoEncodeRateControlModeFlagsKHR",
    "VkVideoChromaSubsamplingFlagsKHR",
    "VkVideoComponentBitDepthFlagsKHR",
    "VkVideoEncodeH264CapabilityFlagsKHR",
    "VkVideoEncodeH264StdFlagsKHR",
    "VkVideoEncodeH264RateControlFlagsKHR",
    "VkVideoEncodeH265CapabilityFlagsKHR",
    "VkVideoEncodeH265StdFlagsKHR",
    "VkVideoEncodeH265RateControlFlagsKHR",
    "VkVideoEncodeH265CtbSizeFlagsKHR",
    "VkVideoEncodeH265TransformBlockSizeFlagsKHR",
    "VkInstance",
    "VkPhysicalDevice",
    "VkDevice",
    "VkQueue",
    "VkCommandBuffer",
    "VkDeviceMemory",
    "VkCommandPool",
    "VkBuffer",
    "VkBufferView",
    "VkImage",
    "VkImageView",
    "VkShaderModule",
    "VkPipeline",
    "VkPipelineLayout",
    "VkSampler",
    "VkDescriptorSet",
    "VkDescriptorSetLayout",
    "VkDescriptorPool",
    "VkFence",
    "VkSemaphore",
    "VkEvent",
    "VkQueryPool",
    "VkFramebuffer",
    "VkRenderPass",
    "VkPipelineCache",
    "VkIndirectCommandsLayoutNV",
    "VkDescriptorUpdateTemplate",
    "VkDescriptorUpdateTemplateKHR",
    "VkSamplerYcbcrConversion",
    "VkSamplerYcbcrConversionKHR",
    "VkValidationCacheEXT",
    "VkAccelerationStructureKHR",
    "VkAccelerationStructureNV",
    "VkPerformanceConfigurationINTEL",
    "VkBufferCollectionFUCHSIA",
    "VkDeferredOperationKHR",
    "VkPrivateDataSlot",
    "VkPrivateDataSlotEXT",
    "VkCuModuleNVX",
    "VkCuFunctionNVX",
    "VkOpticalFlowSessionNV",
    "VkMicromapEXT",
    "VkShaderEXT",
    "VkDisplayKHR",
    "VkDisplayModeKHR",
    "VkSurfaceKHR",
    "VkSwapchainKHR",
    "VkDebugReportCallbackEXT",
    "VkDebugUtilsMessengerEXT",
    "VkVideoSessionKHR",
    "VkVideoSessionParametersKHR",
    "VkSemaphoreSciSyncPoolNV",
    "VkAttachmentLoadOp",
    "VkAttachmentStoreOp",
    "VkBlendFactor",
    "VkBlendOp",
    "VkBorderColor",
    "VkFramebufferCreateFlagBits",
    "VkQueryPoolCreateFlagBits",
    "VkRenderPassCreateFlagBits",
    "VkSamplerCreateFlagBits",
    "VkPipelineCacheHeaderVersion",
    "VkPipelineCacheCreateFlagBits",
    "VkPipelineShaderStageCreateFlagBits",
    "VkDescriptorSetLayoutCreateFlagBits",
    "VkInstanceCreateFlagBits",
    "VkDeviceQueueCreateFlagBits",
    "VkBufferCreateFlagBits",
    "VkBufferUsageFlagBits",
    "VkColorComponentFlagBits",
    "VkComponentSwizzle",
    "VkCommandPoolCreateFlagBits",
    "VkCommandPoolResetFlagBits",
    "VkCommandBufferResetFlagBits",
    "VkCommandBufferLevel",
    "VkCommandBufferUsageFlagBits",
    "VkCompareOp",
    "VkCullModeFlagBits",
    "VkDescriptorType",
    "VkDeviceCreateFlagBits",
    "VkDynamicState",
    "VkFenceCreateFlagBits",
    "VkPolygonMode",
    "VkFormat",
    "VkFormatFeatureFlagBits",
    "VkFrontFace",
    "VkImageAspectFlagBits",
    "VkImageCreateFlagBits",
    "VkImageLayout",
    "VkImageTiling",
    "VkImageType",
    "VkImageUsageFlagBits",
    "VkImageViewCreateFlagBits",
    "VkImageViewType",
    "VkSharingMode",
    "VkIndexType",
    "VkLogicOp",
    "VkMemoryHeapFlagBits",
    "VkAccessFlagBits",
    "VkMemoryPropertyFlagBits",
    "VkPhysicalDeviceType",
    "VkPipelineBindPoint",
    "VkPipelineCreateFlagBits",
    "VkPrimitiveTopology",
    "VkQueryControlFlagBits",
    "VkQueryPipelineStatisticFlagBits",
    "VkQueryResultFlagBits",
    "VkQueryType",
    "VkQueueFlagBits",
    "VkSubpassContents",
    "VkResult",
    "VkShaderStageFlagBits",
    "VkSparseMemoryBindFlagBits",
    "VkStencilFaceFlagBits",
    "VkStencilOp",
    "VkStructureType",
    "VkSystemAllocationScope",
    "VkInternalAllocationType",
    "VkSamplerAddressMode",
    "VkFilter",
    "VkSamplerMipmapMode",
    "VkVertexInputRate",
    "VkPipelineStageFlagBits",
    "VkSparseImageFormatFlagBits",
    "VkSampleCountFlagBits",
    "VkAttachmentDescriptionFlagBits",
    "VkDescriptorPoolCreateFlagBits",
    "VkDependencyFlagBits",
    "VkObjectType",
    "VkEventCreateFlagBits",
    "VkPipelineLayoutCreateFlagBits",
    "VkSemaphoreCreateFlagBits",
    "VkRayTracingInvocationReorderModeNV",
    "VkIndirectCommandsLayoutUsageFlagBitsNV",
    "VkIndirectCommandsTokenTypeNV",
    "VkIndirectStateFlagBitsNV",
    "VkPrivateDataSlotCreateFlagBits",
    "VkPrivateDataSlotCreateFlagBitsEXT",
    "VkDescriptorUpdateTemplateType",
    "VkDescriptorUpdateTemplateTypeKHR",
    "VkViewportCoordinateSwizzleNV",
    "VkDiscardRectangleModeEXT",
    "VkSubpassDescriptionFlagBits",
    "VkPointClippingBehavior",
    "VkPointClippingBehaviorKHR",
    "VkCoverageModulationModeNV",
    "VkCoverageReductionModeNV",
    "VkValidationCacheHeaderVersionEXT",
    "VkShaderInfoTypeAMD",
    "VkQueueGlobalPriorityKHR",
    "VkQueueGlobalPriorityEXT",
    "VkTimeDomainKHR",
    "VkTimeDomainEXT",
    "VkConservativeRasterizationModeEXT",
    "VkResolveModeFlagBits",
    "VkResolveModeFlagBitsKHR",
    "VkDescriptorBindingFlagBits",
    "VkDescriptorBindingFlagBitsEXT",
    "VkConditionalRenderingFlagBitsEXT",
    "VkSemaphoreType",
    "VkSemaphoreTypeKHR",
    "VkGeometryFlagBitsKHR",
    "VkGeometryFlagBitsNV",
    "VkGeometryInstanceFlagBitsKHR",
    "VkGeometryInstanceFlagBitsNV",
    "VkBuildAccelerationStructureFlagBitsKHR",
    "VkBuildAccelerationStructureFlagBitsNV",
    "VkAccelerationStructureCreateFlagBitsKHR",
    "VkBuildAccelerationStructureModeKHR",
    "VkCopyAccelerationStructureModeKHR",
    "VkCopyAccelerationStructureModeNV",
    "VkAccelerationStructureTypeKHR",
    "VkAccelerationStructureTypeNV",
    "VkGeometryTypeKHR",
    "VkGeometryTypeNV",
    "VkRayTracingShaderGroupTypeKHR",
    "VkRayTracingShaderGroupTypeNV",
    "VkAccelerationStructureMemoryRequirementsTypeNV",
    "VkAccelerationStructureBuildTypeKHR",
    "VkAccelerationStructureCompatibilityKHR",
    "VkShaderGroupShaderKHR",
    "VkMemoryOverallocationBehaviorAMD",
    "VkDeviceDiagnosticsConfigFlagBitsNV",
    "VkPipelineCreationFeedbackFlagBits",
    "VkPipelineCreationFeedbackFlagBitsEXT",
    "VkPerformanceCounterScopeKHR",
    "VkPerformanceCounterUnitKHR",
    "VkPerformanceCounterStorageKHR",
    "VkPerformanceCounterDescriptionFlagBitsKHR",
    "VkAcquireProfilingLockFlagBitsKHR",
    "VkSemaphoreWaitFlagBits",
    "VkSemaphoreWaitFlagBitsKHR",
    "VkPerformanceConfigurationTypeINTEL",
    "VkQueryPoolSamplingModeINTEL",
    "VkPerformanceOverrideTypeINTEL",
    "VkPerformanceParameterTypeINTEL",
    "VkPerformanceValueTypeINTEL",
    "VkLineRasterizationModeEXT",
    "VkShaderModuleCreateFlagBits",
    "VkPipelineCompilerControlFlagBitsAMD",
    "VkShaderCorePropertiesFlagBitsAMD",
    "VkRefreshObjectFlagBitsKHR",
    "VkFaultLevel",
    "VkFaultType",
    "VkFaultQueryBehavior",
    "VkPipelineMatchControl",
    "VkSciSyncClientTypeNV",
    "VkSciSyncPrimitiveTypeNV",
    "VkToolPurposeFlagBits",
    "VkToolPurposeFlagBitsEXT",
    "VkFragmentShadingRateNV",
    "VkFragmentShadingRateTypeNV",
    "VkSubpassMergeStatusEXT",
    "VkAccessFlagBits2",
    "VkAccessFlagBits2KHR",
    "VkPipelineStageFlagBits2",
    "VkPipelineStageFlagBits2KHR",
    "VkProvokingVertexModeEXT",
    "VkPipelineCacheValidationVersion",
    "VkImageFormatConstraintsFlagBitsFUCHSIA",
    "VkHostImageCopyFlagBitsEXT",
    "VkImageConstraintsInfoFlagBitsFUCHSIA",
    "VkFormatFeatureFlagBits2",
    "VkFormatFeatureFlagBits2KHR",
    "VkRenderingFlagBits",
    "VkRenderingFlagBitsKHR",
    "VkPipelineDepthStencilStateCreateFlagBits",
    "VkPipelineColorBlendStateCreateFlagBits",
    "VkImageCompressionFlagBitsEXT",
    "VkImageCompressionFixedRateFlagBitsEXT",
    "VkExportMetalObjectTypeFlagBitsEXT",
    "VkPipelineRobustnessBufferBehaviorEXT",
    "VkPipelineRobustnessImageBehaviorEXT",
    "VkDeviceAddressBindingFlagBitsEXT",
    "VkDeviceAddressBindingTypeEXT",
    "VkMicromapTypeEXT",
    "VkBuildMicromapModeEXT",
    "VkCopyMicromapModeEXT",
    "VkBuildMicromapFlagBitsEXT",
    "VkMicromapCreateFlagBitsEXT",
    "VkOpacityMicromapFormatEXT",
    "VkOpacityMicromapSpecialIndexEXT",
    "VkDeviceFaultVendorBinaryHeaderVersionEXT",
    "VkFrameBoundaryFlagBitsEXT",
    "VkMemoryDecompressionMethodFlagBitsNV",
    "VkDepthBiasRepresentationEXT",
    "VkDirectDriverLoadingModeLUNARG",
    "VkPipelineCreateFlagBits2KHR",
    "VkBufferUsageFlagBits2KHR",
    "VkDisplacementMicromapFormatNV",
    "VkShaderCreateFlagBitsEXT",
    "VkShaderCodeTypeEXT",
    "VkScopeKHR",
    "VkComponentTypeKHR",
    "VkScopeNV",
    "VkComponentTypeNV",
    "VkCubicFilterWeightsQCOM",
    "VkBlockMatchWindowCompareModeQCOM",
    "VkLayeredDriverUnderlyingApiMSFT",
    "VkColorSpaceKHR",
    "VkCompositeAlphaFlagBitsKHR",
    "VkDisplayPlaneAlphaFlagBitsKHR",
    "VkPresentModeKHR",
    "VkSurfaceTransformFlagBitsKHR",
    "VkDebugReportFlagBitsEXT",
    "VkDebugReportObjectTypeEXT",
    "VkDeviceMemoryReportEventTypeEXT",
    "VkRasterizationOrderAMD",
    "VkExternalMemoryHandleTypeFlagBitsNV",
    "VkExternalMemoryFeatureFlagBitsNV",
    "VkValidationCheckEXT",
    "VkValidationFeatureEnableEXT",
    "VkValidationFeatureDisableEXT",
    "VkExternalMemoryHandleTypeFlagBits",
    "VkExternalMemoryHandleTypeFlagBitsKHR",
    "VkExternalMemoryFeatureFlagBits",
    "VkExternalMemoryFeatureFlagBitsKHR",
    "VkExternalSemaphoreHandleTypeFlagBits",
    "VkExternalSemaphoreHandleTypeFlagBitsKHR",
    "VkExternalSemaphoreFeatureFlagBits",
    "VkExternalSemaphoreFeatureFlagBitsKHR",
    "VkSemaphoreImportFlagBits",
    "VkSemaphoreImportFlagBitsKHR",
    "VkExternalFenceHandleTypeFlagBits",
    "VkExternalFenceHandleTypeFlagBitsKHR",
    "VkExternalFenceFeatureFlagBits",
    "VkExternalFenceFeatureFlagBitsKHR",
    "VkFenceImportFlagBits",
    "VkFenceImportFlagBitsKHR",
    "VkSurfaceCounterFlagBitsEXT",
    "VkDisplayPowerStateEXT",
    "VkDeviceEventTypeEXT",
    "VkDisplayEventTypeEXT",
    "VkPeerMemoryFeatureFlagBits",
    "VkPeerMemoryFeatureFlagBitsKHR",
    "VkMemoryAllocateFlagBits",
    "VkMemoryAllocateFlagBitsKHR",
    "VkDeviceGroupPresentModeFlagBitsKHR",
    "VkSwapchainCreateFlagBitsKHR",
    "VkSubgroupFeatureFlagBits",
    "VkTessellationDomainOrigin",
    "VkTessellationDomainOriginKHR",
    "VkSamplerYcbcrModelConversion",
    "VkSamplerYcbcrModelConversionKHR",
    "VkSamplerYcbcrRange",
    "VkSamplerYcbcrRangeKHR",
    "VkChromaLocation",
    "VkChromaLocationKHR",
    "VkSamplerReductionMode",
    "VkSamplerReductionModeEXT",
    "VkBlendOverlapEXT",
    "VkDebugUtilsMessageSeverityFlagBitsEXT",
    "VkDebugUtilsMessageTypeFlagBitsEXT",
    "VkFullScreenExclusiveEXT",
    "VkShaderFloatControlsIndependence",
    "VkShaderFloatControlsIndependenceKHR",
    "VkSwapchainImageUsageFlagBitsANDROID",
    "VkFragmentShadingRateCombinerOpKHR",
    "VkSubmitFlagBits",
    "VkSubmitFlagBitsKHR",
    "VkGraphicsPipelineLibraryFlagBitsEXT",
    "VkOpticalFlowGridSizeFlagBitsNV",
    "VkOpticalFlowUsageFlagBitsNV",
    "VkOpticalFlowPerformanceLevelNV",
    "VkOpticalFlowSessionBindingPointNV",
    "VkOpticalFlowSessionCreateFlagBitsNV",
    "VkOpticalFlowExecuteFlagBitsNV",
    "VkDeviceFaultAddressTypeEXT",
    "VkPresentScalingFlagBitsEXT",
    "VkPresentGravityFlagBitsEXT",
    "VkLayerSettingTypeEXT",
    "VkLatencyMarkerNV",
    "VkOutOfBandQueueTypeNV",
    "VkPhysicalDeviceSchedulingControlsFlagBitsARM",
    "VkVendorId",
    "VkDriverId",
    "VkDriverIdKHR",
    "VkShadingRatePaletteEntryNV",
    "VkCoarseSampleOrderTypeNV",
    "VkPipelineExecutableStatisticFormatKHR",
    "VkVideoCodecOperationFlagBitsKHR",
    "VkVideoChromaSubsamplingFlagBitsKHR",
    "VkVideoComponentBitDepthFlagBitsKHR",
    "VkVideoCapabilityFlagBitsKHR",
    "VkVideoSessionCreateFlagBitsKHR",
    "VkVideoCodingControlFlagBitsKHR",
    "VkQueryResultStatusKHR",
    "VkVideoDecodeUsageFlagBitsKHR",
    "VkVideoDecodeCapabilityFlagBitsKHR",
    "VkVideoDecodeH264PictureLayoutFlagBitsKHR",
    "VkVideoEncodeUsageFlagBitsKHR",
    "VkVideoEncodeContentFlagBitsKHR",
    "VkVideoEncodeTuningModeKHR",
    "VkVideoEncodeCapabilityFlagBitsKHR",
    "VkVideoEncodeFeedbackFlagBitsKHR",
    "VkVideoEncodeRateControlModeFlagBitsKHR",
    "VkVideoEncodeH264CapabilityFlagBitsKHR",
    "VkVideoEncodeH264StdFlagBitsKHR",
    "VkVideoEncodeH264RateControlFlagBitsKHR",
    "VkVideoEncodeH265CapabilityFlagBitsKHR",
    "VkVideoEncodeH265StdFlagBitsKHR",
    "VkVideoEncodeH265RateControlFlagBitsKHR",
    "VkVideoEncodeH265CtbSizeFlagBitsKHR",
    "VkVideoEncodeH265TransformBlockSizeFlagBitsKHR",
    "PFN_vkInternalAllocationNotification",
    "PFN_vkInternalFreeNotification",
    "PFN_vkReallocationFunction",
    "PFN_vkAllocationFunction",
    "PFN_vkFreeFunction",
    "PFN_vkVoidFunction",
    "PFN_vkDebugReportCallbackEXT",
    "PFN_vkDebugUtilsMessengerCallbackEXT",
    "PFN_vkFaultCallbackFunction",
    "PFN_vkDeviceMemoryReportCallbackEXT",
    "PFN_vkGetInstanceProcAddrLUNARG",
    "VkBaseOutStructure",
    "VkBaseInStructure",
    "VkOffset2D",
    "VkOffset3D",
    "VkExtent2D",
    "VkExtent3D",
    "VkViewport",
    "VkRect2D",
    "VkClearRect",
    "VkComponentMapping",
    "VkPhysicalDeviceProperties",
    "VkExtensionProperties",
    "VkLayerProperties",
    "VkApplicationInfo",
    "VkAllocationCallbacks",
    "VkDeviceQueueCreateInfo",
    "VkDeviceCreateInfo",
    "VkInstanceCreateInfo",
    "VkQueueFamilyProperties",
    "VkPhysicalDeviceMemoryProperties",
    "VkMemoryAllocateInfo",
    "VkMemoryRequirements",
    "VkSparseImageFormatProperties",
    "VkSparseImageMemoryRequirements",
    "VkMemoryType",
    "VkMemoryHeap",
    "VkMappedMemoryRange",
    "VkFormatProperties",
    "VkImageFormatProperties",
    "VkDescriptorBufferInfo",
    "VkDescriptorImageInfo",
    "VkWriteDescriptorSet",
    "VkCopyDescriptorSet",
    "VkBufferUsageFlags2CreateInfoKHR",
    "VkBufferCreateInfo",
    "VkBufferViewCreateInfo",
    "VkImageSubresource",
    "VkImageSubresourceLayers",
    "VkImageSubresourceRange",
    "VkMemoryBarrier",
    "VkBufferMemoryBarrier",
    "VkImageMemoryBarrier",
    "VkImageCreateInfo",
    "VkSubresourceLayout",
    "VkImageViewCreateInfo",
    "VkBufferCopy",
    "VkSparseMemoryBind",
    "VkSparseImageMemoryBind",
    "VkSparseBufferMemoryBindInfo",
    "VkSparseImageOpaqueMemoryBindInfo",
    "VkSparseImageMemoryBindInfo",
    "VkBindSparseInfo",
    "VkImageCopy",
    "VkImageBlit",
    "VkBufferImageCopy",
    "VkCopyMemoryIndirectCommandNV",
    "VkCopyMemoryToImageIndirectCommandNV",
    "VkImageResolve",
    "VkShaderModuleCreateInfo",
    "VkDescriptorSetLayoutBinding",
    "VkDescriptorSetLayoutCreateInfo",
    "VkDescriptorPoolSize",
    "VkDescriptorPoolCreateInfo",
    "VkDescriptorSetAllocateInfo",
    "VkSpecializationMapEntry",
    "VkSpecializationInfo",
    "VkPipelineShaderStageCreateInfo",
    "VkComputePipelineCreateInfo",
    "VkComputePipelineIndirectBufferInfoNV",
    "VkPipelineCreateFlags2CreateInfoKHR",
    "VkVertexInputBindingDescription",
    "VkVertexInputAttributeDescription",
    "VkPipelineVertexInputStateCreateInfo",
    "VkPipelineInputAssemblyStateCreateInfo",
    "VkPipelineTessellationStateCreateInfo",
    "VkPipelineViewportStateCreateInfo",
    "VkPipelineRasterizationStateCreateInfo",
    "VkPipelineMultisampleStateCreateInfo",
    "VkPipelineColorBlendAttachmentState",
    "VkPipelineColorBlendStateCreateInfo",
    "VkPipelineDynamicStateCreateInfo",
    "VkStencilOpState",
    "VkPipelineDepthStencilStateCreateInfo",
    "VkGraphicsPipelineCreateInfo",
    "VkPipelineCacheCreateInfo",
    "VkPipelineCacheHeaderVersionOne",
    "VkPipelineCacheStageValidationIndexEntry",
    "VkPipelineCacheSafetyCriticalIndexEntry",
    "VkPipelineCacheHeaderVersionSafetyCriticalOne",
    "VkPushConstantRange",
    "VkPipelineLayoutCreateInfo",
    "VkSamplerCreateInfo",
    "VkCommandPoolCreateInfo",
    "VkCommandBufferAllocateInfo",
    "VkCommandBufferInheritanceInfo",
    "VkCommandBufferBeginInfo",
    "VkRenderPassBeginInfo",
    "VkClearColorValue",
    "VkClearDepthStencilValue",
    "VkClearValue",
    "VkClearAttachment",
    "VkAttachmentDescription",
    "VkAttachmentReference",
    "VkSubpassDescription",
    "VkSubpassDependency",
    "VkRenderPassCreateInfo",
    "VkEventCreateInfo",
    "VkFenceCreateInfo",
    "VkPhysicalDeviceFeatures",
    "VkPhysicalDeviceSparseProperties",
    "VkPhysicalDeviceLimits",
    "VkSemaphoreCreateInfo",
    "VkQueryPoolCreateInfo",
    "VkFramebufferCreateInfo",
    "VkDrawIndirectCommand",
    "VkDrawIndexedIndirectCommand",
    "VkDispatchIndirectCommand",
    "VkMultiDrawInfoEXT",
    "VkMultiDrawIndexedInfoEXT",
    "VkSubmitInfo",
    "VkDisplayPropertiesKHR",
    "VkDisplayPlanePropertiesKHR",
    "VkDisplayModeParametersKHR",
    "VkDisplayModePropertiesKHR",
    "VkDisplayModeCreateInfoKHR",
    "VkDisplayPlaneCapabilitiesKHR",
    "VkDisplaySurfaceCreateInfoKHR",
    "VkDisplayPresentInfoKHR",
    "VkSurfaceCapabilitiesKHR",
    "VkAndroidSurfaceCreateInfoKHR",
    "VkViSurfaceCreateInfoNN",
    "VkWaylandSurfaceCreateInfoKHR",
    "VkWin32SurfaceCreateInfoKHR",
    "VkXlibSurfaceCreateInfoKHR",
    "VkXcbSurfaceCreateInfoKHR",
    "VkDirectFBSurfaceCreateInfoEXT",
    "VkImagePipeSurfaceCreateInfoFUCHSIA",
    "VkStreamDescriptorSurfaceCreateInfoGGP",
    "VkScreenSurfaceCreateInfoQNX",
    "VkSurfaceFormatKHR",
    "VkSwapchainCreateInfoKHR",
    "VkPresentInfoKHR",
    "VkDebugReportCallbackCreateInfoEXT",
    "VkValidationFlagsEXT",
    "VkValidationFeaturesEXT",
    "VkLayerSettingsCreateInfoEXT",
    "VkLayerSettingEXT",
    "VkApplicationParametersEXT",
    "VkPipelineRasterizationStateRasterizationOrderAMD",
    "VkDebugMarkerObjectNameInfoEXT",
    "VkDebugMarkerObjectTagInfoEXT",
    "VkDebugMarkerMarkerInfoEXT",
    "VkDedicatedAllocationImageCreateInfoNV",
    "VkDedicatedAllocationBufferCreateInfoNV",
    "VkDedicatedAllocationMemoryAllocateInfoNV",
    "VkExternalImageFormatPropertiesNV",
    "VkExternalMemoryImageCreateInfoNV",
    "VkExportMemoryAllocateInfoNV",
    "VkImportMemoryWin32HandleInfoNV",
    "VkExportMemoryWin32HandleInfoNV",
    "VkExportMemorySciBufInfoNV",
    "VkImportMemorySciBufInfoNV",
    "VkMemoryGetSciBufInfoNV",
    "VkMemorySciBufPropertiesNV",
    "VkPhysicalDeviceExternalMemorySciBufFeaturesNV",
    "VkPhysicalDeviceExternalSciBufFeaturesNV",
    "VkWin32KeyedMutexAcquireReleaseInfoNV",
    "VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV",
    "VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV",
    "VkDevicePrivateDataCreateInfo",
    "VkDevicePrivateDataCreateInfoEXT",
    "VkPrivateDataSlotCreateInfo",
    "VkPrivateDataSlotCreateInfoEXT",
    "VkPhysicalDevicePrivateDataFeatures",
    "VkPhysicalDevicePrivateDataFeaturesEXT",
    "VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV",
    "VkPhysicalDeviceMultiDrawPropertiesEXT",
    "VkGraphicsShaderGroupCreateInfoNV",
    "VkGraphicsPipelineShaderGroupsCreateInfoNV",
    "VkBindShaderGroupIndirectCommandNV",
    "VkBindIndexBufferIndirectCommandNV",
    "VkBindVertexBufferIndirectCommandNV",
    "VkSetStateFlagsIndirectCommandNV",
    "VkIndirectCommandsStreamNV",
    "VkIndirectCommandsLayoutTokenNV",
    "VkIndirectCommandsLayoutCreateInfoNV",
    "VkGeneratedCommandsInfoNV",
    "VkGeneratedCommandsMemoryRequirementsInfoNV",
    "VkPipelineIndirectDeviceAddressInfoNV",
    "VkBindPipelineIndirectCommandNV",
    "VkPhysicalDeviceFeatures2",
    "VkPhysicalDeviceFeatures2KHR",
    "VkPhysicalDeviceProperties2",
    "VkPhysicalDeviceProperties2KHR",
    "VkFormatProperties2",
    "VkFormatProperties2KHR",
    "VkImageFormatProperties2",
    "VkImageFormatProperties2KHR",
    "VkPhysicalDeviceImageFormatInfo2",
    "VkPhysicalDeviceImageFormatInfo2KHR",
    "VkQueueFamilyProperties2",
    "VkQueueFamilyProperties2KHR",
    "VkPhysicalDeviceMemoryProperties2",
    "VkPhysicalDeviceMemoryProperties2KHR",
    "VkSparseImageFormatProperties2",
    "VkSparseImageFormatProperties2KHR",
    "VkPhysicalDeviceSparseImageFormatInfo2",
    "VkPhysicalDeviceSparseImageFormatInfo2KHR",
    "VkPhysicalDevicePushDescriptorPropertiesKHR",
    "VkConformanceVersion",
    "VkConformanceVersionKHR",
    "VkPhysicalDeviceDriverProperties",
    "VkPhysicalDeviceDriverPropertiesKHR",
    "VkPresentRegionsKHR",
    "VkPresentRegionKHR",
    "VkRectLayerKHR",
    "VkPhysicalDeviceVariablePointersFeatures",
    "VkPhysicalDeviceVariablePointersFeaturesKHR",
    "VkPhysicalDeviceVariablePointerFeaturesKHR",
    "VkPhysicalDeviceVariablePointerFeatures",
    "VkExternalMemoryProperties",
    "VkExternalMemoryPropertiesKHR",
    "VkPhysicalDeviceExternalImageFormatInfo",
    "VkPhysicalDeviceExternalImageFormatInfoKHR",
    "VkExternalImageFormatProperties",
    "VkExternalImageFormatPropertiesKHR",
    "VkPhysicalDeviceExternalBufferInfo",
    "VkPhysicalDeviceExternalBufferInfoKHR",
    "VkExternalBufferProperties",
    "VkExternalBufferPropertiesKHR",
    "VkPhysicalDeviceIDProperties",
    "VkPhysicalDeviceIDPropertiesKHR",
    "VkExternalMemoryImageCreateInfo",
    "VkExternalMemoryImageCreateInfoKHR",
    "VkExternalMemoryBufferCreateInfo",
    "VkExternalMemoryBufferCreateInfoKHR",
    "VkExportMemoryAllocateInfo",
    "VkExportMemoryAllocateInfoKHR",
    "VkImportMemoryWin32HandleInfoKHR",
    "VkExportMemoryWin32HandleInfoKHR",
    "VkImportMemoryZirconHandleInfoFUCHSIA",
    "VkMemoryZirconHandlePropertiesFUCHSIA",
    "VkMemoryGetZirconHandleInfoFUCHSIA",
    "VkMemoryWin32HandlePropertiesKHR",
    "VkMemoryGetWin32HandleInfoKHR",
    "VkImportMemoryFdInfoKHR",
    "VkMemoryFdPropertiesKHR",
    "VkMemoryGetFdInfoKHR",
    "VkWin32KeyedMutexAcquireReleaseInfoKHR",
    "VkPhysicalDeviceExternalSemaphoreInfo",
    "VkPhysicalDeviceExternalSemaphoreInfoKHR",
    "VkExternalSemaphoreProperties",
    "VkExternalSemaphorePropertiesKHR",
    "VkExportSemaphoreCreateInfo",
    "VkExportSemaphoreCreateInfoKHR",
    "VkImportSemaphoreWin32HandleInfoKHR",
    "VkExportSemaphoreWin32HandleInfoKHR",
    "VkD3D12FenceSubmitInfoKHR",
    "VkSemaphoreGetWin32HandleInfoKHR",
    "VkImportSemaphoreFdInfoKHR",
    "VkSemaphoreGetFdInfoKHR",
    "VkImportSemaphoreZirconHandleInfoFUCHSIA",
    "VkSemaphoreGetZirconHandleInfoFUCHSIA",
    "VkPhysicalDeviceExternalFenceInfo",
    "VkPhysicalDeviceExternalFenceInfoKHR",
    "VkExternalFenceProperties",
    "VkExternalFencePropertiesKHR",
    "VkExportFenceCreateInfo",
    "VkExportFenceCreateInfoKHR",
    "VkImportFenceWin32HandleInfoKHR",
    "VkExportFenceWin32HandleInfoKHR",
    "VkFenceGetWin32HandleInfoKHR",
    "VkImportFenceFdInfoKHR",
    "VkFenceGetFdInfoKHR",
    "VkExportFenceSciSyncInfoNV",
    "VkImportFenceSciSyncInfoNV",
    "VkFenceGetSciSyncInfoNV",
    "VkExportSemaphoreSciSyncInfoNV",
    "VkImportSemaphoreSciSyncInfoNV",
    "VkSemaphoreGetSciSyncInfoNV",
    "VkSciSyncAttributesInfoNV",
    "VkPhysicalDeviceExternalSciSyncFeaturesNV",
    "VkPhysicalDeviceExternalSciSync2FeaturesNV",
    "VkSemaphoreSciSyncPoolCreateInfoNV",
    "VkSemaphoreSciSyncCreateInfoNV",
    "VkDeviceSemaphoreSciSyncPoolReservationCreateInfoNV",
    "VkPhysicalDeviceMultiviewFeatures",
    "VkPhysicalDeviceMultiviewFeaturesKHR",
    "VkPhysicalDeviceMultiviewProperties",
    "VkPhysicalDeviceMultiviewPropertiesKHR",
    "VkRenderPassMultiviewCreateInfo",
    "VkRenderPassMultiviewCreateInfoKHR",
    "VkSurfaceCapabilities2EXT",
    "VkDisplayPowerInfoEXT",
    "VkDeviceEventInfoEXT",
    "VkDisplayEventInfoEXT",
    "VkSwapchainCounterCreateInfoEXT",
    "VkPhysicalDeviceGroupProperties",
    "VkPhysicalDeviceGroupPropertiesKHR",
    "VkMemoryAllocateFlagsInfo",
    "VkMemoryAllocateFlagsInfoKHR",
    "VkBindBufferMemoryInfo",
    "VkBindBufferMemoryInfoKHR",
    "VkBindBufferMemoryDeviceGroupInfo",
    "VkBindBufferMemoryDeviceGroupInfoKHR",
    "VkBindImageMemoryInfo",
    "VkBindImageMemoryInfoKHR",
    "VkBindImageMemoryDeviceGroupInfo",
    "VkBindImageMemoryDeviceGroupInfoKHR",
    "VkDeviceGroupRenderPassBeginInfo",
    "VkDeviceGroupRenderPassBeginInfoKHR",
    "VkDeviceGroupCommandBufferBeginInfo",
    "VkDeviceGroupCommandBufferBeginInfoKHR",
    "VkDeviceGroupSubmitInfo",
    "VkDeviceGroupSubmitInfoKHR",
    "VkDeviceGroupBindSparseInfo",
    "VkDeviceGroupBindSparseInfoKHR",
    "VkDeviceGroupPresentCapabilitiesKHR",
    "VkImageSwapchainCreateInfoKHR",
    "VkBindImageMemorySwapchainInfoKHR",
    "VkAcquireNextImageInfoKHR",
    "VkDeviceGroupPresentInfoKHR",
    "VkDeviceGroupDeviceCreateInfo",
    "VkDeviceGroupDeviceCreateInfoKHR",
    "VkDeviceGroupSwapchainCreateInfoKHR",
    "VkDescriptorUpdateTemplateEntry",
    "VkDescriptorUpdateTemplateEntryKHR",
    "VkDescriptorUpdateTemplateCreateInfo",
    "VkDescriptorUpdateTemplateCreateInfoKHR",
    "VkXYColorEXT",
    "VkPhysicalDevicePresentIdFeaturesKHR",
    "VkPresentIdKHR",
    "VkPhysicalDevicePresentWaitFeaturesKHR",
    "VkHdrMetadataEXT",
    "VkDisplayNativeHdrSurfaceCapabilitiesAMD",
    "VkSwapchainDisplayNativeHdrCreateInfoAMD",
    "VkRefreshCycleDurationGOOGLE",
    "VkPastPresentationTimingGOOGLE",
    "VkPresentTimesInfoGOOGLE",
    "VkPresentTimeGOOGLE",
    "VkIOSSurfaceCreateInfoMVK",
    "VkMacOSSurfaceCreateInfoMVK",
    "VkMetalSurfaceCreateInfoEXT",
    "VkViewportWScalingNV",
    "VkPipelineViewportWScalingStateCreateInfoNV",
    "VkViewportSwizzleNV",
    "VkPipelineViewportSwizzleStateCreateInfoNV",
    "VkPhysicalDeviceDiscardRectanglePropertiesEXT",
    "VkPipelineDiscardRectangleStateCreateInfoEXT",
    "VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX",
    "VkInputAttachmentAspectReference",
    "VkInputAttachmentAspectReferenceKHR",
    "VkRenderPassInputAttachmentAspectCreateInfo",
    "VkRenderPassInputAttachmentAspectCreateInfoKHR",
    "VkPhysicalDeviceSurfaceInfo2KHR",
    "VkSurfaceCapabilities2KHR",
    "VkSurfaceFormat2KHR",
    "VkDisplayProperties2KHR",
    "VkDisplayPlaneProperties2KHR",
    "VkDisplayModeProperties2KHR",
    "VkDisplayPlaneInfo2KHR",
    "VkDisplayPlaneCapabilities2KHR",
    "VkSharedPresentSurfaceCapabilitiesKHR",
    "VkPhysicalDevice16BitStorageFeatures",
    "VkPhysicalDevice16BitStorageFeaturesKHR",
    "VkPhysicalDeviceSubgroupProperties",
    "VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures",
    "VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR",
    "VkBufferMemoryRequirementsInfo2",
    "VkBufferMemoryRequirementsInfo2KHR",
    "VkDeviceBufferMemoryRequirements",
    "VkDeviceBufferMemoryRequirementsKHR",
    "VkImageMemoryRequirementsInfo2",
    "VkImageMemoryRequirementsInfo2KHR",
    "VkImageSparseMemoryRequirementsInfo2",
    "VkImageSparseMemoryRequirementsInfo2KHR",
    "VkDeviceImageMemoryRequirements",
    "VkDeviceImageMemoryRequirementsKHR",
    "VkMemoryRequirements2",
    "VkMemoryRequirements2KHR",
    "VkSparseImageMemoryRequirements2",
    "VkSparseImageMemoryRequirements2KHR",
    "VkPhysicalDevicePointClippingProperties",
    "VkPhysicalDevicePointClippingPropertiesKHR",
    "VkMemoryDedicatedRequirements",
    "VkMemoryDedicatedRequirementsKHR",
    "VkMemoryDedicatedAllocateInfo",
    "VkMemoryDedicatedAllocateInfoKHR",
    "VkImageViewUsageCreateInfo",
    "VkImageViewSlicedCreateInfoEXT",
    "VkImageViewUsageCreateInfoKHR",
    "VkPipelineTessellationDomainOriginStateCreateInfo",
    "VkPipelineTessellationDomainOriginStateCreateInfoKHR",
    "VkSamplerYcbcrConversionInfo",
    "VkSamplerYcbcrConversionInfoKHR",
    "VkSamplerYcbcrConversionCreateInfo",
    "VkSamplerYcbcrConversionCreateInfoKHR",
    "VkBindImagePlaneMemoryInfo",
    "VkBindImagePlaneMemoryInfoKHR",
    "VkImagePlaneMemoryRequirementsInfo",
    "VkImagePlaneMemoryRequirementsInfoKHR",
    "VkPhysicalDeviceSamplerYcbcrConversionFeatures",
    "VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR",
    "VkSamplerYcbcrConversionImageFormatProperties",
    "VkSamplerYcbcrConversionImageFormatPropertiesKHR",
    "VkTextureLODGatherFormatPropertiesAMD",
    "VkConditionalRenderingBeginInfoEXT",
    "VkProtectedSubmitInfo",
    "VkPhysicalDeviceProtectedMemoryFeatures",
    "VkPhysicalDeviceProtectedMemoryProperties",
    "VkDeviceQueueInfo2",
    "VkPipelineCoverageToColorStateCreateInfoNV",
    "VkPhysicalDeviceSamplerFilterMinmaxProperties",
    "VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT",
    "VkSampleLocationEXT",
    "VkSampleLocationsInfoEXT",
    "VkAttachmentSampleLocationsEXT",
    "VkSubpassSampleLocationsEXT",
    "VkRenderPassSampleLocationsBeginInfoEXT",
    "VkPipelineSampleLocationsStateCreateInfoEXT",
    "VkPhysicalDeviceSampleLocationsPropertiesEXT",
    "VkMultisamplePropertiesEXT",
    "VkSamplerReductionModeCreateInfo",
    "VkSamplerReductionModeCreateInfoEXT",
    "VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT",
    "VkPhysicalDeviceMultiDrawFeaturesEXT",
    "VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT",
    "VkPipelineColorBlendAdvancedStateCreateInfoEXT",
    "VkPhysicalDeviceInlineUniformBlockFeatures",
    "VkPhysicalDeviceInlineUniformBlockFeaturesEXT",
    "VkPhysicalDeviceInlineUniformBlockProperties",
    "VkPhysicalDeviceInlineUniformBlockPropertiesEXT",
    "VkWriteDescriptorSetInlineUniformBlock",
    "VkWriteDescriptorSetInlineUniformBlockEXT",
    "VkDescriptorPoolInlineUniformBlockCreateInfo",
    "VkDescriptorPoolInlineUniformBlockCreateInfoEXT",
    "VkPipelineCoverageModulationStateCreateInfoNV",
    "VkImageFormatListCreateInfo",
    "VkImageFormatListCreateInfoKHR",
    "VkValidationCacheCreateInfoEXT",
    "VkShaderModuleValidationCacheCreateInfoEXT",
    "VkPhysicalDeviceMaintenance3Properties",
    "VkPhysicalDeviceMaintenance3PropertiesKHR",
    "VkPhysicalDeviceMaintenance4Features",
    "VkPhysicalDeviceMaintenance4FeaturesKHR",
    "VkPhysicalDeviceMaintenance4Properties",
    "VkPhysicalDeviceMaintenance4PropertiesKHR",
    "VkPhysicalDeviceMaintenance5FeaturesKHR",
    "VkPhysicalDeviceMaintenance5PropertiesKHR",
    "VkPhysicalDeviceMaintenance6FeaturesKHR",
    "VkPhysicalDeviceMaintenance6PropertiesKHR",
    "VkRenderingAreaInfoKHR",
    "VkDescriptorSetLayoutSupport",
    "VkDescriptorSetLayoutSupportKHR",
    "VkPhysicalDeviceShaderDrawParametersFeatures",
    "VkPhysicalDeviceShaderDrawParameterFeatures",
    "VkPhysicalDeviceShaderFloat16Int8Features",
    "VkPhysicalDeviceShaderFloat16Int8FeaturesKHR",
    "VkPhysicalDeviceFloat16Int8FeaturesKHR",
    "VkPhysicalDeviceFloatControlsProperties",
    "VkPhysicalDeviceFloatControlsPropertiesKHR",
    "VkPhysicalDeviceHostQueryResetFeatures",
    "VkPhysicalDeviceHostQueryResetFeaturesEXT",
    "VkNativeBufferUsage2ANDROID",
    "VkNativeBufferANDROID",
    "VkSwapchainImageCreateInfoANDROID",
    "VkPhysicalDevicePresentationPropertiesANDROID",
    "VkShaderResourceUsageAMD",
    "VkShaderStatisticsInfoAMD",
    "VkDeviceQueueGlobalPriorityCreateInfoKHR",
    "VkDeviceQueueGlobalPriorityCreateInfoEXT",
    "VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR",
    "VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT",
    "VkQueueFamilyGlobalPriorityPropertiesKHR",
    "VkQueueFamilyGlobalPriorityPropertiesEXT",
    "VkDebugUtilsObjectNameInfoEXT",
    "VkDebugUtilsObjectTagInfoEXT",
    "VkDebugUtilsLabelEXT",
    "VkDebugUtilsMessengerCreateInfoEXT",
    "VkDebugUtilsMessengerCallbackDataEXT",
    "VkPhysicalDeviceDeviceMemoryReportFeaturesEXT",
    "VkDeviceDeviceMemoryReportCreateInfoEXT",
    "VkDeviceMemoryReportCallbackDataEXT",
    "VkImportMemoryHostPointerInfoEXT",
    "VkMemoryHostPointerPropertiesEXT",
    "VkPhysicalDeviceExternalMemoryHostPropertiesEXT",
    "VkPhysicalDeviceConservativeRasterizationPropertiesEXT",
    "VkCalibratedTimestampInfoKHR",
    "VkCalibratedTimestampInfoEXT",
    "VkPhysicalDeviceShaderCorePropertiesAMD",
    "VkPhysicalDeviceShaderCoreProperties2AMD",
    "VkPipelineRasterizationConservativeStateCreateInfoEXT",
    "VkPhysicalDeviceDescriptorIndexingFeatures",
    "VkPhysicalDeviceDescriptorIndexingFeaturesEXT",
    "VkPhysicalDeviceDescriptorIndexingProperties",
    "VkPhysicalDeviceDescriptorIndexingPropertiesEXT",
    "VkDescriptorSetLayoutBindingFlagsCreateInfo",
    "VkDescriptorSetLayoutBindingFlagsCreateInfoEXT",
    "VkDescriptorSetVariableDescriptorCountAllocateInfo",
    "VkDescriptorSetVariableDescriptorCountAllocateInfoEXT",
    "VkDescriptorSetVariableDescriptorCountLayoutSupport",
    "VkDescriptorSetVariableDescriptorCountLayoutSupportEXT",
    "VkAttachmentDescription2",
    "VkAttachmentDescription2KHR",
    "VkAttachmentReference2",
    "VkAttachmentReference2KHR",
    "VkSubpassDescription2",
    "VkSubpassDescription2KHR",
    "VkSubpassDependency2",
    "VkSubpassDependency2KHR",
    "VkRenderPassCreateInfo2",
    "VkRenderPassCreateInfo2KHR",
    "VkSubpassBeginInfo",
    "VkSubpassBeginInfoKHR",
    "VkSubpassEndInfo",
    "VkSubpassEndInfoKHR",
    "VkPhysicalDeviceTimelineSemaphoreFeatures",
    "VkPhysicalDeviceTimelineSemaphoreFeaturesKHR",
    "VkPhysicalDeviceTimelineSemaphoreProperties",
    "VkPhysicalDeviceTimelineSemaphorePropertiesKHR",
    "VkSemaphoreTypeCreateInfo",
    "VkSemaphoreTypeCreateInfoKHR",
    "VkTimelineSemaphoreSubmitInfo",
    "VkTimelineSemaphoreSubmitInfoKHR",
    "VkSemaphoreWaitInfo",
    "VkSemaphoreWaitInfoKHR",
    "VkSemaphoreSignalInfo",
    "VkSemaphoreSignalInfoKHR",
    "VkVertexInputBindingDivisorDescriptionKHR",
    "VkVertexInputBindingDivisorDescriptionEXT",
    "VkPipelineVertexInputDivisorStateCreateInfoKHR",
    "VkPipelineVertexInputDivisorStateCreateInfoEXT",
    "VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT",
    "VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR",
    "VkPhysicalDevicePCIBusInfoPropertiesEXT",
    "VkImportAndroidHardwareBufferInfoANDROID",
    "VkAndroidHardwareBufferUsageANDROID",
    "VkAndroidHardwareBufferPropertiesANDROID",
    "VkMemoryGetAndroidHardwareBufferInfoANDROID",
    "VkAndroidHardwareBufferFormatPropertiesANDROID",
    "VkCommandBufferInheritanceConditionalRenderingInfoEXT",
    "VkExternalFormatANDROID",
    "VkPhysicalDevice8BitStorageFeatures",
    "VkPhysicalDevice8BitStorageFeaturesKHR",
    "VkPhysicalDeviceConditionalRenderingFeaturesEXT",
    "VkPhysicalDeviceVulkanMemoryModelFeatures",
    "VkPhysicalDeviceVulkanMemoryModelFeaturesKHR",
    "VkPhysicalDeviceShaderAtomicInt64Features",
    "VkPhysicalDeviceShaderAtomicInt64FeaturesKHR",
    "VkPhysicalDeviceShaderAtomicFloatFeaturesEXT",
    "VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT",
    "VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR",
    "VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT",
    "VkQueueFamilyCheckpointPropertiesNV",
    "VkCheckpointDataNV",
    "VkPhysicalDeviceDepthStencilResolveProperties",
    "VkPhysicalDeviceDepthStencilResolvePropertiesKHR",
    "VkSubpassDescriptionDepthStencilResolve",
    "VkSubpassDescriptionDepthStencilResolveKHR",
    "VkImageViewASTCDecodeModeEXT",
    "VkPhysicalDeviceASTCDecodeFeaturesEXT",
    "VkPhysicalDeviceTransformFeedbackFeaturesEXT",
    "VkPhysicalDeviceTransformFeedbackPropertiesEXT",
    "VkPipelineRasterizationStateStreamCreateInfoEXT",
    "VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV",
    "VkPipelineRepresentativeFragmentTestStateCreateInfoNV",
    "VkPhysicalDeviceExclusiveScissorFeaturesNV",
    "VkPipelineViewportExclusiveScissorStateCreateInfoNV",
    "VkPhysicalDeviceCornerSampledImageFeaturesNV",
    "VkPhysicalDeviceComputeShaderDerivativesFeaturesNV",
    "VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV",
    "VkPhysicalDeviceShaderImageFootprintFeaturesNV",
    "VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV",
    "VkPhysicalDeviceCopyMemoryIndirectFeaturesNV",
    "VkPhysicalDeviceCopyMemoryIndirectPropertiesNV",
    "VkPhysicalDeviceMemoryDecompressionFeaturesNV",
    "VkPhysicalDeviceMemoryDecompressionPropertiesNV",
    "VkShadingRatePaletteNV",
    "VkPipelineViewportShadingRateImageStateCreateInfoNV",
    "VkPhysicalDeviceShadingRateImageFeaturesNV",
    "VkPhysicalDeviceShadingRateImagePropertiesNV",
    "VkPhysicalDeviceInvocationMaskFeaturesHUAWEI",
    "VkCoarseSampleLocationNV",
    "VkCoarseSampleOrderCustomNV",
    "VkPipelineViewportCoarseSampleOrderStateCreateInfoNV",
    "VkPhysicalDeviceMeshShaderFeaturesNV",
    "VkPhysicalDeviceMeshShaderPropertiesNV",
    "VkDrawMeshTasksIndirectCommandNV",
    "VkPhysicalDeviceMeshShaderFeaturesEXT",
    "VkPhysicalDeviceMeshShaderPropertiesEXT",
    "VkDrawMeshTasksIndirectCommandEXT",
    "VkRayTracingShaderGroupCreateInfoNV",
    "VkRayTracingShaderGroupCreateInfoKHR",
    "VkRayTracingPipelineCreateInfoNV",
    "VkRayTracingPipelineCreateInfoKHR",
    "VkGeometryTrianglesNV",
    "VkGeometryAABBNV",
    "VkGeometryDataNV",
    "VkGeometryNV",
    "VkAccelerationStructureInfoNV",
    "VkAccelerationStructureCreateInfoNV",
    "VkBindAccelerationStructureMemoryInfoNV",
    "VkWriteDescriptorSetAccelerationStructureKHR",
    "VkWriteDescriptorSetAccelerationStructureNV",
    "VkAccelerationStructureMemoryRequirementsInfoNV",
    "VkPhysicalDeviceAccelerationStructureFeaturesKHR",
    "VkPhysicalDeviceRayTracingPipelineFeaturesKHR",
    "VkPhysicalDeviceRayQueryFeaturesKHR",
    "VkPhysicalDeviceAccelerationStructurePropertiesKHR",
    "VkPhysicalDeviceRayTracingPipelinePropertiesKHR",
    "VkPhysicalDeviceRayTracingPropertiesNV",
    "VkStridedDeviceAddressRegionKHR",
    "VkTraceRaysIndirectCommandKHR",
    "VkTraceRaysIndirectCommand2KHR",
    "VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR",
    "VkDrmFormatModifierPropertiesListEXT",
    "VkDrmFormatModifierPropertiesEXT",
    "VkPhysicalDeviceImageDrmFormatModifierInfoEXT",
    "VkImageDrmFormatModifierListCreateInfoEXT",
    "VkImageDrmFormatModifierExplicitCreateInfoEXT",
    "VkImageDrmFormatModifierPropertiesEXT",
    "VkImageStencilUsageCreateInfo",
    "VkImageStencilUsageCreateInfoEXT",
    "VkDeviceMemoryOverallocationCreateInfoAMD",
    "VkPhysicalDeviceFragmentDensityMapFeaturesEXT",
    "VkPhysicalDeviceFragmentDensityMap2FeaturesEXT",
    "VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM",
    "VkPhysicalDeviceFragmentDensityMapPropertiesEXT",
    "VkPhysicalDeviceFragmentDensityMap2PropertiesEXT",
    "VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM",
    "VkRenderPassFragmentDensityMapCreateInfoEXT",
    "VkSubpassFragmentDensityMapOffsetEndInfoQCOM",
    "VkPhysicalDeviceScalarBlockLayoutFeatures",
    "VkPhysicalDeviceScalarBlockLayoutFeaturesEXT",
    "VkSurfaceProtectedCapabilitiesKHR",
    "VkPhysicalDeviceUniformBufferStandardLayoutFeatures",
    "VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR",
    "VkPhysicalDeviceDepthClipEnableFeaturesEXT",
    "VkPipelineRasterizationDepthClipStateCreateInfoEXT",
    "VkPhysicalDeviceMemoryBudgetPropertiesEXT",
    "VkPhysicalDeviceMemoryPriorityFeaturesEXT",
    "VkMemoryPriorityAllocateInfoEXT",
    "VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT",
    "VkPhysicalDeviceBufferDeviceAddressFeatures",
    "VkPhysicalDeviceBufferDeviceAddressFeaturesKHR",
    "VkPhysicalDeviceBufferDeviceAddressFeaturesEXT",
    "VkPhysicalDeviceBufferAddressFeaturesEXT",
    "VkBufferDeviceAddressInfo",
    "VkBufferDeviceAddressInfoKHR",
    "VkBufferDeviceAddressInfoEXT",
    "VkBufferOpaqueCaptureAddressCreateInfo",
    "VkBufferOpaqueCaptureAddressCreateInfoKHR",
    "VkBufferDeviceAddressCreateInfoEXT",
    "VkPhysicalDeviceImageViewImageFormatInfoEXT",
    "VkFilterCubicImageViewImageFormatPropertiesEXT",
    "VkPhysicalDeviceImagelessFramebufferFeatures",
    "VkPhysicalDeviceImagelessFramebufferFeaturesKHR",
    "VkFramebufferAttachmentsCreateInfo",
    "VkFramebufferAttachmentsCreateInfoKHR",
    "VkFramebufferAttachmentImageInfo",
    "VkFramebufferAttachmentImageInfoKHR",
    "VkRenderPassAttachmentBeginInfo",
    "VkRenderPassAttachmentBeginInfoKHR",
    "VkPhysicalDeviceTextureCompressionASTCHDRFeatures",
    "VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT",
    "VkPhysicalDeviceCooperativeMatrixFeaturesNV",
    "VkPhysicalDeviceCooperativeMatrixPropertiesNV",
    "VkCooperativeMatrixPropertiesNV",
    "VkPhysicalDeviceYcbcrImageArraysFeaturesEXT",
    "VkImageViewHandleInfoNVX",
    "VkImageViewAddressPropertiesNVX",
    "VkPresentFrameTokenGGP",
    "VkPipelineCreationFeedback",
    "VkPipelineCreationFeedbackEXT",
    "VkPipelineCreationFeedbackCreateInfo",
    "VkPipelineCreationFeedbackCreateInfoEXT",
    "VkSurfaceFullScreenExclusiveInfoEXT",
    "VkSurfaceFullScreenExclusiveWin32InfoEXT",
    "VkSurfaceCapabilitiesFullScreenExclusiveEXT",
    "VkPhysicalDevicePresentBarrierFeaturesNV",
    "VkSurfaceCapabilitiesPresentBarrierNV",
    "VkSwapchainPresentBarrierCreateInfoNV",
    "VkPhysicalDevicePerformanceQueryFeaturesKHR",
    "VkPhysicalDevicePerformanceQueryPropertiesKHR",
    "VkPerformanceCounterKHR",
    "VkPerformanceCounterDescriptionKHR",
    "VkQueryPoolPerformanceCreateInfoKHR",
    "VkPerformanceCounterResultKHR",
    "VkAcquireProfilingLockInfoKHR",
    "VkPerformanceQuerySubmitInfoKHR",
    "VkPerformanceQueryReservationInfoKHR",
    "VkHeadlessSurfaceCreateInfoEXT",
    "VkPhysicalDeviceCoverageReductionModeFeaturesNV",
    "VkPipelineCoverageReductionStateCreateInfoNV",
    "VkFramebufferMixedSamplesCombinationNV",
    "VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL",
    "VkPerformanceValueDataINTEL",
    "VkPerformanceValueINTEL",
    "VkInitializePerformanceApiInfoINTEL",
    "VkQueryPoolPerformanceQueryCreateInfoINTEL",
    "VkQueryPoolCreateInfoINTEL",
    "VkPerformanceMarkerInfoINTEL",
    "VkPerformanceStreamMarkerInfoINTEL",
    "VkPerformanceOverrideInfoINTEL",
    "VkPerformanceConfigurationAcquireInfoINTEL",
    "VkPhysicalDeviceShaderClockFeaturesKHR",
    "VkPhysicalDeviceIndexTypeUint8FeaturesEXT",
    "VkPhysicalDeviceShaderSMBuiltinsPropertiesNV",
    "VkPhysicalDeviceShaderSMBuiltinsFeaturesNV",
    "VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT",
    "VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures",
    "VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR",
    "VkAttachmentReferenceStencilLayout",
    "VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT",
    "VkAttachmentReferenceStencilLayoutKHR",
    "VkAttachmentDescriptionStencilLayout",
    "VkAttachmentDescriptionStencilLayoutKHR",
    "VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR",
    "VkPipelineInfoKHR",
    "VkPipelineInfoEXT",
    "VkPipelineExecutablePropertiesKHR",
    "VkPipelineExecutableInfoKHR",
    "VkPipelineExecutableStatisticValueKHR",
    "VkPipelineExecutableStatisticKHR",
    "VkPipelineExecutableInternalRepresentationKHR",
    "VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures",
    "VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT",
    "VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT",
    "VkPhysicalDeviceTexelBufferAlignmentProperties",
    "VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT",
    "VkPhysicalDeviceSubgroupSizeControlFeatures",
    "VkPhysicalDeviceSubgroupSizeControlFeaturesEXT",
    "VkPhysicalDeviceSubgroupSizeControlProperties",
    "VkPhysicalDeviceSubgroupSizeControlPropertiesEXT",
    "VkPipelineShaderStageRequiredSubgroupSizeCreateInfo",
    "VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT",
    "VkShaderRequiredSubgroupSizeCreateInfoEXT",
    "VkSubpassShadingPipelineCreateInfoHUAWEI",
    "VkPhysicalDeviceSubpassShadingPropertiesHUAWEI",
    "VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI",
    "VkMemoryOpaqueCaptureAddressAllocateInfo",
    "VkMemoryOpaqueCaptureAddressAllocateInfoKHR",
    "VkDeviceMemoryOpaqueCaptureAddressInfo",
    "VkDeviceMemoryOpaqueCaptureAddressInfoKHR",
    "VkPhysicalDeviceLineRasterizationFeaturesEXT",
    "VkPhysicalDeviceLineRasterizationPropertiesEXT",
    "VkPipelineRasterizationLineStateCreateInfoEXT",
    "VkPhysicalDevicePipelineCreationCacheControlFeatures",
    "VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT",
    "VkPhysicalDeviceVulkan11Features",
    "VkPhysicalDeviceVulkan11Properties",
    "VkPhysicalDeviceVulkan12Features",
    "VkPhysicalDeviceVulkan12Properties",
    "VkPhysicalDeviceVulkan13Features",
    "VkPhysicalDeviceVulkan13Properties",
    "VkPipelineCompilerControlCreateInfoAMD",
    "VkPhysicalDeviceCoherentMemoryFeaturesAMD",
    "VkFaultData",
    "VkFaultCallbackInfo",
    "VkPhysicalDeviceToolProperties",
    "VkPhysicalDeviceToolPropertiesEXT",
    "VkSamplerCustomBorderColorCreateInfoEXT",
    "VkPhysicalDeviceCustomBorderColorPropertiesEXT",
    "VkPhysicalDeviceCustomBorderColorFeaturesEXT",
    "VkSamplerBorderColorComponentMappingCreateInfoEXT",
    "VkPhysicalDeviceBorderColorSwizzleFeaturesEXT",
    "VkDeviceOrHostAddressKHR",
    "VkDeviceOrHostAddressConstKHR",
    "VkDeviceOrHostAddressConstAMDX",
    "VkAccelerationStructureGeometryTrianglesDataKHR",
    "VkAccelerationStructureGeometryAabbsDataKHR",
    "VkAccelerationStructureGeometryInstancesDataKHR",
    "VkAccelerationStructureGeometryDataKHR",
    "VkAccelerationStructureGeometryKHR",
    "VkAccelerationStructureBuildGeometryInfoKHR",
    "VkAccelerationStructureBuildRangeInfoKHR",
    "VkAccelerationStructureCreateInfoKHR",
    "VkAabbPositionsKHR",
    "VkAabbPositionsNV",
    "VkTransformMatrixKHR",
    "VkTransformMatrixNV",
    "VkAccelerationStructureInstanceKHR",
    "VkAccelerationStructureInstanceNV",
    "VkAccelerationStructureDeviceAddressInfoKHR",
    "VkAccelerationStructureVersionInfoKHR",
    "VkCopyAccelerationStructureInfoKHR",
    "VkCopyAccelerationStructureToMemoryInfoKHR",
    "VkCopyMemoryToAccelerationStructureInfoKHR",
    "VkRayTracingPipelineInterfaceCreateInfoKHR",
    "VkPipelineLibraryCreateInfoKHR",
    "VkRefreshObjectKHR",
    "VkRefreshObjectListKHR",
    "VkPhysicalDeviceExtendedDynamicStateFeaturesEXT",
    "VkPhysicalDeviceExtendedDynamicState2FeaturesEXT",
    "VkPhysicalDeviceExtendedDynamicState3FeaturesEXT",
    "VkPhysicalDeviceExtendedDynamicState3PropertiesEXT",
    "VkColorBlendEquationEXT",
    "VkColorBlendAdvancedEXT",
    "VkRenderPassTransformBeginInfoQCOM",
    "VkCopyCommandTransformInfoQCOM",
    "VkCommandBufferInheritanceRenderPassTransformInfoQCOM",
    "VkPhysicalDeviceDiagnosticsConfigFeaturesNV",
    "VkDeviceDiagnosticsConfigCreateInfoNV",
    "VkPipelineOfflineCreateInfo",
    "VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures",
    "VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR",
    "VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR",
    "VkPhysicalDeviceRobustness2FeaturesEXT",
    "VkPhysicalDeviceRobustness2PropertiesEXT",
    "VkPhysicalDeviceImageRobustnessFeatures",
    "VkPhysicalDeviceImageRobustnessFeaturesEXT",
    "VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR",
    "VkPhysicalDevicePortabilitySubsetFeaturesKHR",
    "VkPhysicalDevicePortabilitySubsetPropertiesKHR",
    "VkPhysicalDevice4444FormatsFeaturesEXT",
    "VkPhysicalDeviceSubpassShadingFeaturesHUAWEI",
    "VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI",
    "VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI",
    "VkBufferCopy2",
    "VkBufferCopy2KHR",
    "VkImageCopy2",
    "VkImageCopy2KHR",
    "VkImageBlit2",
    "VkImageBlit2KHR",
    "VkBufferImageCopy2",
    "VkBufferImageCopy2KHR",
    "VkImageResolve2",
    "VkImageResolve2KHR",
    "VkCopyBufferInfo2",
    "VkCopyBufferInfo2KHR",
    "VkCopyImageInfo2",
    "VkCopyImageInfo2KHR",
    "VkBlitImageInfo2",
    "VkBlitImageInfo2KHR",
    "VkCopyBufferToImageInfo2",
    "VkCopyBufferToImageInfo2KHR",
    "VkCopyImageToBufferInfo2",
    "VkCopyImageToBufferInfo2KHR",
    "VkResolveImageInfo2",
    "VkResolveImageInfo2KHR",
    "VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT",
    "VkFragmentShadingRateAttachmentInfoKHR",
    "VkPipelineFragmentShadingRateStateCreateInfoKHR",
    "VkPhysicalDeviceFragmentShadingRateFeaturesKHR",
    "VkPhysicalDeviceFragmentShadingRatePropertiesKHR",
    "VkPhysicalDeviceFragmentShadingRateKHR",
    "VkPhysicalDeviceShaderTerminateInvocationFeatures",
    "VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR",
    "VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV",
    "VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV",
    "VkPipelineFragmentShadingRateEnumStateCreateInfoNV",
    "VkAccelerationStructureBuildSizesInfoKHR",
    "VkPhysicalDeviceImage2DViewOf3DFeaturesEXT",
    "VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT",
    "VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT",
    "VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT",
    "VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE",
    "VkMutableDescriptorTypeListEXT",
    "VkMutableDescriptorTypeListVALVE",
    "VkMutableDescriptorTypeCreateInfoEXT",
    "VkMutableDescriptorTypeCreateInfoVALVE",
    "VkPhysicalDeviceDepthClipControlFeaturesEXT",
    "VkPipelineViewportDepthClipControlCreateInfoEXT",
    "VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT",
    "VkPhysicalDeviceExternalMemoryRDMAFeaturesNV",
    "VkVertexInputBindingDescription2EXT",
    "VkVertexInputAttributeDescription2EXT",
    "VkPhysicalDeviceColorWriteEnableFeaturesEXT",
    "VkPipelineColorWriteCreateInfoEXT",
    "VkMemoryBarrier2",
    "VkMemoryBarrier2KHR",
    "VkImageMemoryBarrier2",
    "VkImageMemoryBarrier2KHR",
    "VkBufferMemoryBarrier2",
    "VkBufferMemoryBarrier2KHR",
    "VkDependencyInfo",
    "VkDependencyInfoKHR",
    "VkSemaphoreSubmitInfo",
    "VkSemaphoreSubmitInfoKHR",
    "VkCommandBufferSubmitInfo",
    "VkCommandBufferSubmitInfoKHR",
    "VkSubmitInfo2",
    "VkSubmitInfo2KHR",
    "VkQueueFamilyCheckpointProperties2NV",
    "VkCheckpointData2NV",
    "VkPhysicalDeviceSynchronization2Features",
    "VkPhysicalDeviceSynchronization2FeaturesKHR",
    "VkPhysicalDeviceHostImageCopyFeaturesEXT",
    "VkPhysicalDeviceHostImageCopyPropertiesEXT",
    "VkMemoryToImageCopyEXT",
    "VkImageToMemoryCopyEXT",
    "VkCopyMemoryToImageInfoEXT",
    "VkCopyImageToMemoryInfoEXT",
    "VkCopyImageToImageInfoEXT",
    "VkHostImageLayoutTransitionInfoEXT",
    "VkSubresourceHostMemcpySizeEXT",
    "VkHostImageCopyDevicePerformanceQueryEXT",
    "VkPhysicalDeviceVulkanSC10Properties",
    "VkPipelinePoolSize",
    "VkDeviceObjectReservationCreateInfo",
    "VkCommandPoolMemoryReservationCreateInfo",
    "VkCommandPoolMemoryConsumption",
    "VkPhysicalDeviceVulkanSC10Features",
    "VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT",
    "VkPhysicalDeviceLegacyDitheringFeaturesEXT",
    "VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT",
    "VkSubpassResolvePerformanceQueryEXT",
    "VkMultisampledRenderToSingleSampledInfoEXT",
    "VkPhysicalDevicePipelineProtectedAccessFeaturesEXT",
    "VkQueueFamilyVideoPropertiesKHR",
    "VkQueueFamilyQueryResultStatusPropertiesKHR",
    "VkVideoProfileListInfoKHR",
    "VkPhysicalDeviceVideoFormatInfoKHR",
    "VkVideoFormatPropertiesKHR",
    "VkVideoProfileInfoKHR",
    "VkVideoCapabilitiesKHR",
    "VkVideoSessionMemoryRequirementsKHR",
    "VkBindVideoSessionMemoryInfoKHR",
    "VkVideoPictureResourceInfoKHR",
    "VkVideoReferenceSlotInfoKHR",
    "VkVideoDecodeCapabilitiesKHR",
    "VkVideoDecodeUsageInfoKHR",
    "VkVideoDecodeInfoKHR",
    "VkPhysicalDeviceVideoMaintenance1FeaturesKHR",
    "VkVideoInlineQueryInfoKHR",
    "VkVideoDecodeH264ProfileInfoKHR",
    "VkVideoDecodeH264CapabilitiesKHR",
    "VkVideoDecodeH264SessionParametersAddInfoKHR",
    "VkVideoDecodeH264SessionParametersCreateInfoKHR",
    "VkVideoDecodeH264PictureInfoKHR",
    "VkVideoDecodeH264DpbSlotInfoKHR",
    "VkVideoDecodeH265ProfileInfoKHR",
    "VkVideoDecodeH265CapabilitiesKHR",
    "VkVideoDecodeH265SessionParametersAddInfoKHR",
    "VkVideoDecodeH265SessionParametersCreateInfoKHR",
    "VkVideoDecodeH265PictureInfoKHR",
    "VkVideoDecodeH265DpbSlotInfoKHR",
    "VkVideoSessionCreateInfoKHR",
    "VkVideoSessionParametersCreateInfoKHR",
    "VkVideoSessionParametersUpdateInfoKHR",
    "VkVideoEncodeSessionParametersGetInfoKHR",
    "VkVideoEncodeSessionParametersFeedbackInfoKHR",
    "VkVideoBeginCodingInfoKHR",
    "VkVideoEndCodingInfoKHR",
    "VkVideoCodingControlInfoKHR",
    "VkVideoEncodeUsageInfoKHR",
    "VkVideoEncodeInfoKHR",
    "VkQueryPoolVideoEncodeFeedbackCreateInfoKHR",
    "VkVideoEncodeQualityLevelInfoKHR",
    "VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR",
    "VkVideoEncodeQualityLevelPropertiesKHR",
    "VkVideoEncodeRateControlInfoKHR",
    "VkVideoEncodeRateControlLayerInfoKHR",
    "VkVideoEncodeCapabilitiesKHR",
    "VkVideoEncodeH264CapabilitiesKHR",
    "VkVideoEncodeH264QualityLevelPropertiesKHR",
    "VkVideoEncodeH264SessionCreateInfoKHR",
    "VkVideoEncodeH264SessionParametersAddInfoKHR",
    "VkVideoEncodeH264SessionParametersCreateInfoKHR",
    "VkVideoEncodeH264SessionParametersGetInfoKHR",
    "VkVideoEncodeH264SessionParametersFeedbackInfoKHR",
    "VkVideoEncodeH264DpbSlotInfoKHR",
    "VkVideoEncodeH264PictureInfoKHR",
    "VkVideoEncodeH264ProfileInfoKHR",
    "VkVideoEncodeH264NaluSliceInfoKHR",
    "VkVideoEncodeH264RateControlInfoKHR",
    "VkVideoEncodeH264QpKHR",
    "VkVideoEncodeH264FrameSizeKHR",
    "VkVideoEncodeH264GopRemainingFrameInfoKHR",
    "VkVideoEncodeH264RateControlLayerInfoKHR",
    "VkVideoEncodeH265CapabilitiesKHR",
    "VkVideoEncodeH265QualityLevelPropertiesKHR",
    "VkVideoEncodeH265SessionCreateInfoKHR",
    "VkVideoEncodeH265SessionParametersAddInfoKHR",
    "VkVideoEncodeH265SessionParametersCreateInfoKHR",
    "VkVideoEncodeH265SessionParametersGetInfoKHR",
    "VkVideoEncodeH265SessionParametersFeedbackInfoKHR",
    "VkVideoEncodeH265PictureInfoKHR",
    "VkVideoEncodeH265NaluSliceSegmentInfoKHR",
    "VkVideoEncodeH265RateControlInfoKHR",
    "VkVideoEncodeH265QpKHR",
    "VkVideoEncodeH265FrameSizeKHR",
    "VkVideoEncodeH265GopRemainingFrameInfoKHR",
    "VkVideoEncodeH265RateControlLayerInfoKHR",
    "VkVideoEncodeH265ProfileInfoKHR",
    "VkVideoEncodeH265DpbSlotInfoKHR",
    "VkPhysicalDeviceInheritedViewportScissorFeaturesNV",
    "VkCommandBufferInheritanceViewportScissorInfoNV",
    "VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT",
    "VkPhysicalDeviceProvokingVertexFeaturesEXT",
    "VkPhysicalDeviceProvokingVertexPropertiesEXT",
    "VkPipelineRasterizationProvokingVertexStateCreateInfoEXT",
    "VkCuModuleCreateInfoNVX",
    "VkCuFunctionCreateInfoNVX",
    "VkCuLaunchInfoNVX",
    "VkPhysicalDeviceDescriptorBufferFeaturesEXT",
    "VkPhysicalDeviceDescriptorBufferPropertiesEXT",
    "VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT",
    "VkDescriptorAddressInfoEXT",
    "VkDescriptorBufferBindingInfoEXT",
    "VkDescriptorBufferBindingPushDescriptorBufferHandleEXT",
    "VkDescriptorDataEXT",
    "VkDescriptorGetInfoEXT",
    "VkBufferCaptureDescriptorDataInfoEXT",
    "VkImageCaptureDescriptorDataInfoEXT",
    "VkImageViewCaptureDescriptorDataInfoEXT",
    "VkSamplerCaptureDescriptorDataInfoEXT",
    "VkAccelerationStructureCaptureDescriptorDataInfoEXT",
    "VkOpaqueCaptureDescriptorDataCreateInfoEXT",
    "VkPhysicalDeviceShaderIntegerDotProductFeatures",
    "VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR",
    "VkPhysicalDeviceShaderIntegerDotProductProperties",
    "VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR",
    "VkPhysicalDeviceDrmPropertiesEXT",
    "VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR",
    "VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR",
    "VkPhysicalDeviceRayTracingMotionBlurFeaturesNV",
    "VkAccelerationStructureMotionInstanceTypeNV",
    "VkAccelerationStructureGeometryMotionTrianglesDataNV",
    "VkAccelerationStructureMotionInfoNV",
    "VkSRTDataNV",
    "VkAccelerationStructureSRTMotionInstanceNV",
    "VkAccelerationStructureMatrixMotionInstanceNV",
    "VkAccelerationStructureMotionInstanceDataNV",
    "VkAccelerationStructureMotionInstanceNV",
    "VkMemoryGetRemoteAddressInfoNV",
    "VkImportMemoryBufferCollectionFUCHSIA",
    "VkBufferCollectionImageCreateInfoFUCHSIA",
    "VkBufferCollectionBufferCreateInfoFUCHSIA",
    "VkBufferCollectionCreateInfoFUCHSIA",
    "VkBufferCollectionPropertiesFUCHSIA",
    "VkBufferConstraintsInfoFUCHSIA",
    "VkSysmemColorSpaceFUCHSIA",
    "VkImageFormatConstraintsInfoFUCHSIA",
    "VkImageConstraintsInfoFUCHSIA",
    "VkBufferCollectionConstraintsInfoFUCHSIA",
    "VkCudaModuleNV",
    "VkCudaFunctionNV",
    "VkCudaModuleCreateInfoNV",
    "VkCudaFunctionCreateInfoNV",
    "VkCudaLaunchInfoNV",
    "VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT",
    "VkFormatProperties3",
    "VkFormatProperties3KHR",
    "VkDrmFormatModifierPropertiesList2EXT",
    "VkDrmFormatModifierProperties2EXT",
    "VkAndroidHardwareBufferFormatProperties2ANDROID",
    "VkPipelineRenderingCreateInfo",
    "VkPipelineRenderingCreateInfoKHR",
    "VkRenderingInfo",
    "VkRenderingInfoKHR",
    "VkRenderingAttachmentInfo",
    "VkRenderingAttachmentInfoKHR",
    "VkRenderingFragmentShadingRateAttachmentInfoKHR",
    "VkRenderingFragmentDensityMapAttachmentInfoEXT",
    "VkPhysicalDeviceDynamicRenderingFeatures",
    "VkPhysicalDeviceDynamicRenderingFeaturesKHR",
    "VkCommandBufferInheritanceRenderingInfo",
    "VkCommandBufferInheritanceRenderingInfoKHR",
    "VkAttachmentSampleCountInfoAMD",
    "VkAttachmentSampleCountInfoNV",
    "VkMultiviewPerViewAttributesInfoNVX",
    "VkPhysicalDeviceImageViewMinLodFeaturesEXT",
    "VkImageViewMinLodCreateInfoEXT",
    "VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT",
    "VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM",
    "VkPhysicalDeviceLinearColorAttachmentFeaturesNV",
    "VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT",
    "VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT",
    "VkGraphicsPipelineLibraryCreateInfoEXT",
    "VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE",
    "VkDescriptorSetBindingReferenceVALVE",
    "VkDescriptorSetLayoutHostMappingInfoVALVE",
    "VkPhysicalDeviceNestedCommandBufferFeaturesEXT",
    "VkPhysicalDeviceNestedCommandBufferPropertiesEXT",
    "VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT",
    "VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT",
    "VkPipelineShaderStageModuleIdentifierCreateInfoEXT",
    "VkShaderModuleIdentifierEXT",
    "VkImageCompressionControlEXT",
    "VkPhysicalDeviceImageCompressionControlFeaturesEXT",
    "VkImageCompressionPropertiesEXT",
    "VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT",
    "VkImageSubresource2KHR",
    "VkImageSubresource2EXT",
    "VkSubresourceLayout2KHR",
    "VkSubresourceLayout2EXT",
    "VkRenderPassCreationControlEXT",
    "VkRenderPassCreationFeedbackInfoEXT",
    "VkRenderPassCreationFeedbackCreateInfoEXT",
    "VkRenderPassSubpassFeedbackInfoEXT",
    "VkRenderPassSubpassFeedbackCreateInfoEXT",
    "VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT",
    "VkMicromapBuildInfoEXT",
    "VkMicromapCreateInfoEXT",
    "VkMicromapVersionInfoEXT",
    "VkCopyMicromapInfoEXT",
    "VkCopyMicromapToMemoryInfoEXT",
    "VkCopyMemoryToMicromapInfoEXT",
    "VkMicromapBuildSizesInfoEXT",
    "VkMicromapUsageEXT",
    "VkMicromapTriangleEXT",
    "VkPhysicalDeviceOpacityMicromapFeaturesEXT",
    "VkPhysicalDeviceOpacityMicromapPropertiesEXT",
    "VkAccelerationStructureTrianglesOpacityMicromapEXT",
    "VkPhysicalDeviceDisplacementMicromapFeaturesNV",
    "VkPhysicalDeviceDisplacementMicromapPropertiesNV",
    "VkAccelerationStructureTrianglesDisplacementMicromapNV",
    "VkPipelinePropertiesIdentifierEXT",
    "VkPhysicalDevicePipelinePropertiesFeaturesEXT",
    "VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD",
    "VkExternalMemoryAcquireUnmodifiedEXT",
    "VkExportMetalObjectCreateInfoEXT",
    "VkExportMetalObjectsInfoEXT",
    "VkExportMetalDeviceInfoEXT",
    "VkExportMetalCommandQueueInfoEXT",
    "VkExportMetalBufferInfoEXT",
    "VkImportMetalBufferInfoEXT",
    "VkExportMetalTextureInfoEXT",
    "VkImportMetalTextureInfoEXT",
    "VkExportMetalIOSurfaceInfoEXT",
    "VkImportMetalIOSurfaceInfoEXT",
    "VkExportMetalSharedEventInfoEXT",
    "VkImportMetalSharedEventInfoEXT",
    "VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT",
    "VkPhysicalDevicePipelineRobustnessFeaturesEXT",
    "VkPipelineRobustnessCreateInfoEXT",
    "VkPhysicalDevicePipelineRobustnessPropertiesEXT",
    "VkImageViewSampleWeightCreateInfoQCOM",
    "VkPhysicalDeviceImageProcessingFeaturesQCOM",
    "VkPhysicalDeviceImageProcessingPropertiesQCOM",
    "VkPhysicalDeviceTilePropertiesFeaturesQCOM",
    "VkTilePropertiesQCOM",
    "VkPhysicalDeviceAmigoProfilingFeaturesSEC",
    "VkAmigoProfilingSubmitInfoSEC",
    "VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT",
    "VkPhysicalDeviceDepthClampZeroOneFeaturesEXT",
    "VkPhysicalDeviceAddressBindingReportFeaturesEXT",
    "VkDeviceAddressBindingCallbackDataEXT",
    "VkPhysicalDeviceOpticalFlowFeaturesNV",
    "VkPhysicalDeviceOpticalFlowPropertiesNV",
    "VkOpticalFlowImageFormatInfoNV",
    "VkOpticalFlowImageFormatPropertiesNV",
    "VkOpticalFlowSessionCreateInfoNV",
    "VkOpticalFlowSessionCreatePrivateDataInfoNV",
    "VkOpticalFlowExecuteInfoNV",
    "VkPhysicalDeviceFaultFeaturesEXT",
    "VkDeviceFaultAddressInfoEXT",
    "VkDeviceFaultVendorInfoEXT",
    "VkDeviceFaultCountsEXT",
    "VkDeviceFaultInfoEXT",
    "VkDeviceFaultVendorBinaryHeaderVersionOneEXT",
    "VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT",
    "VkDepthBiasInfoEXT",
    "VkDepthBiasRepresentationInfoEXT",
    "VkDecompressMemoryRegionNV",
    "VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM",
    "VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM",
    "VkFrameBoundaryEXT",
    "VkPhysicalDeviceFrameBoundaryFeaturesEXT",
    "VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT",
    "VkSurfacePresentModeEXT",
    "VkSurfacePresentScalingCapabilitiesEXT",
    "VkSurfacePresentModeCompatibilityEXT",
    "VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT",
    "VkSwapchainPresentFenceInfoEXT",
    "VkSwapchainPresentModesCreateInfoEXT",
    "VkSwapchainPresentModeInfoEXT",
    "VkSwapchainPresentScalingCreateInfoEXT",
    "VkReleaseSwapchainImagesInfoEXT",
    "VkPhysicalDeviceDepthBiasControlFeaturesEXT",
    "VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV",
    "VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV",
    "VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV",
    "VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV",
    "VkDirectDriverLoadingInfoLUNARG",
    "VkDirectDriverLoadingListLUNARG",
    "VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM",
    "VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR",
    "VkDeviceImageSubresourceInfoKHR",
    "VkPhysicalDeviceShaderCorePropertiesARM",
    "VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM",
    "VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM",
    "VkQueryLowLatencySupportNV",
    "VkMemoryMapInfoKHR",
    "VkMemoryUnmapInfoKHR",
    "VkPhysicalDeviceShaderObjectFeaturesEXT",
    "VkPhysicalDeviceShaderObjectPropertiesEXT",
    "VkShaderCreateInfoEXT",
    "VkPhysicalDeviceShaderTileImageFeaturesEXT",
    "VkPhysicalDeviceShaderTileImagePropertiesEXT",
    "VkImportScreenBufferInfoQNX",
    "VkScreenBufferPropertiesQNX",
    "VkScreenBufferFormatPropertiesQNX",
    "VkExternalFormatQNX",
    "VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX",
    "VkPhysicalDeviceCooperativeMatrixFeaturesKHR",
    "VkCooperativeMatrixPropertiesKHR",
    "VkPhysicalDeviceCooperativeMatrixPropertiesKHR",
    "VkPhysicalDeviceShaderEnqueuePropertiesAMDX",
    "VkPhysicalDeviceShaderEnqueueFeaturesAMDX",
    "VkExecutionGraphPipelineCreateInfoAMDX",
    "VkPipelineShaderStageNodeCreateInfoAMDX",
    "VkExecutionGraphPipelineScratchSizeAMDX",
    "VkDispatchGraphInfoAMDX",
    "VkDispatchGraphCountInfoAMDX",
    "VkBindMemoryStatusKHR",
    "VkBindDescriptorSetsInfoKHR",
    "VkPushConstantsInfoKHR",
    "VkPushDescriptorSetInfoKHR",
    "VkPushDescriptorSetWithTemplateInfoKHR",
    "VkSetDescriptorBufferOffsetsInfoEXT",
    "VkBindDescriptorBufferEmbeddedSamplersInfoEXT",
    "VkPhysicalDeviceCubicClampFeaturesQCOM",
    "VkPhysicalDeviceYcbcrDegammaFeaturesQCOM",
    "VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM",
    "VkPhysicalDeviceCubicWeightsFeaturesQCOM",
    "VkSamplerCubicWeightsCreateInfoQCOM",
    "VkBlitImageCubicWeightsInfoQCOM",
    "VkPhysicalDeviceImageProcessing2FeaturesQCOM",
    "VkPhysicalDeviceImageProcessing2PropertiesQCOM",
    "VkSamplerBlockMatchWindowCreateInfoQCOM",
    "VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV",
    "VkPhysicalDeviceLayeredDriverPropertiesMSFT",
    "VkPhysicalDevicePerStageDescriptorSetFeaturesNV",
    "VkPhysicalDeviceExternalFormatResolveFeaturesANDROID",
    "VkPhysicalDeviceExternalFormatResolvePropertiesANDROID",
    "VkAndroidHardwareBufferFormatResolvePropertiesANDROID",
    "VkLatencySleepModeInfoNV",
    "VkLatencySleepInfoNV",
    "VkSetLatencyMarkerInfoNV",
    "VkGetLatencyMarkerInfoNV",
    "VkLatencyTimingsFrameReportNV",
    "VkOutOfBandQueueTypeInfoNV",
    "VkLatencySubmissionPresentIdNV",
    "VkSwapchainLatencyCreateInfoNV",
    "VkLatencySurfaceCapabilitiesNV",
    "VkPhysicalDeviceCudaKernelLaunchFeaturesNV",
    "VkPhysicalDeviceCudaKernelLaunchPropertiesNV",
    "VkDeviceQueueShaderCoreControlCreateInfoARM",
    "VkPhysicalDeviceSchedulingControlsFeaturesARM",
    "VkPhysicalDeviceSchedulingControlsPropertiesARM",
    "VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG",
    "VkPhysicalDeviceRenderPassStripedFeaturesARM",
    "VkPhysicalDeviceRenderPassStripedPropertiesARM",
    "VkRenderPassStripeInfoARM",
    "VkRenderPassStripeBeginInfoARM",
    "VkRenderPassStripeSubmitInfoARM",
    "VK_MAX_PHYSICAL_DEVICE_NAME_SIZE",
    "VK_UUID_SIZE",
    "VK_LUID_SIZE",
    "VK_LUID_SIZE_KHR",
    "VK_MAX_EXTENSION_NAME_SIZE",
    "VK_MAX_DESCRIPTION_SIZE",
    "VK_MAX_MEMORY_TYPES",
    "VK_MAX_MEMORY_HEAPS",
    "VK_LOD_CLAMP_NONE",
    "VK_REMAINING_MIP_LEVELS",
    "VK_REMAINING_ARRAY_LAYERS",
    "VK_REMAINING_3D_SLICES_EXT",
    "VK_WHOLE_SIZE",
    "VK_ATTACHMENT_UNUSED",
    "VK_TRUE",
    "VK_FALSE",
    "VK_QUEUE_FAMILY_IGNORED",
    "VK_QUEUE_FAMILY_EXTERNAL",
    "VK_QUEUE_FAMILY_EXTERNAL_KHR",
    "VK_QUEUE_FAMILY_FOREIGN_EXT",
    "VK_SUBPASS_EXTERNAL",
    "VK_MAX_DEVICE_GROUP_SIZE",
    "VK_MAX_DEVICE_GROUP_SIZE_KHR",
    "VK_MAX_DRIVER_NAME_SIZE",
    "VK_MAX_DRIVER_NAME_SIZE_KHR",
    "VK_MAX_DRIVER_INFO_SIZE",
    "VK_MAX_DRIVER_INFO_SIZE_KHR",
    "VK_SHADER_UNUSED_KHR",
    "VK_SHADER_UNUSED_NV",
    "VK_MAX_GLOBAL_PRIORITY_SIZE_KHR",
    "VK_MAX_GLOBAL_PRIORITY_SIZE_EXT",
    "VK_MAX_SHADER_MODULE_IDENTIFIER_SIZE_EXT",
    "VK_SHADER_INDEX_UNUSED_AMDX",
    "vkCreateInstance",
    "vkDestroyInstance",
    "vkEnumeratePhysicalDevices",
    "vkGetDeviceProcAddr",
    "vkGetInstanceProcAddr",
    "vkGetPhysicalDeviceProperties",
    "vkGetPhysicalDeviceQueueFamilyProperties",
    "vkGetPhysicalDeviceMemoryProperties",
    "vkGetPhysicalDeviceFeatures",
    "vkGetPhysicalDeviceFormatProperties",
    "vkGetPhysicalDeviceImageFormatProperties",
    "vkCreateDevice",
    "vkDestroyDevice",
    "vkEnumerateInstanceVersion",
    "vkEnumerateInstanceLayerProperties",
    "vkEnumerateInstanceExtensionProperties",
    "vkEnumerateDeviceLayerProperties",
    "vkEnumerateDeviceExtensionProperties",
    "vkGetDeviceQueue",
    "vkQueueSubmit",
    "vkQueueWaitIdle",
    "vkDeviceWaitIdle",
    "vkAllocateMemory",
    "vkFreeMemory",
    "vkMapMemory",
    "vkUnmapMemory",
    "vkFlushMappedMemoryRanges",
    "vkInvalidateMappedMemoryRanges",
    "vkGetDeviceMemoryCommitment",
    "vkGetBufferMemoryRequirements",
    "vkBindBufferMemory",
    "vkGetImageMemoryRequirements",
    "vkBindImageMemory",
    "vkGetImageSparseMemoryRequirements",
    "vkGetPhysicalDeviceSparseImageFormatProperties",
    "vkQueueBindSparse",
    "vkCreateFence",
    "vkDestroyFence",
    "vkResetFences",
    "vkGetFenceStatus",
    "vkWaitForFences",
    "vkCreateSemaphore",
    "vkDestroySemaphore",
    "vkCreateEvent",
    "vkDestroyEvent",
    "vkGetEventStatus",
    "vkSetEvent",
    "vkResetEvent",
    "vkCreateQueryPool",
    "vkDestroyQueryPool",
    "vkGetQueryPoolResults",
    "vkResetQueryPool",
    "vkResetQueryPoolEXT",
    "vkCreateBuffer",
    "vkDestroyBuffer",
    "vkCreateBufferView",
    "vkDestroyBufferView",
    "vkCreateImage",
    "vkDestroyImage",
    "vkGetImageSubresourceLayout",
    "vkCreateImageView",
    "vkDestroyImageView",
    "vkCreateShaderModule",
    "vkDestroyShaderModule",
    "vkCreatePipelineCache",
    "vkDestroyPipelineCache",
    "vkGetPipelineCacheData",
    "vkMergePipelineCaches",
    "vkCreateGraphicsPipelines",
    "vkCreateComputePipelines",
    "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI",
    "vkDestroyPipeline",
    "vkCreatePipelineLayout",
    "vkDestroyPipelineLayout",
    "vkCreateSampler",
    "vkDestroySampler",
    "vkCreateDescriptorSetLayout",
    "vkDestroyDescriptorSetLayout",
    "vkCreateDescriptorPool",
    "vkDestroyDescriptorPool",
    "vkResetDescriptorPool",
    "vkAllocateDescriptorSets",
    "vkFreeDescriptorSets",
    "vkUpdateDescriptorSets",
    "vkCreateFramebuffer",
    "vkDestroyFramebuffer",
    "vkCreateRenderPass",
    "vkDestroyRenderPass",
    "vkGetRenderAreaGranularity",
    "vkGetRenderingAreaGranularityKHR",
    "vkCreateCommandPool",
    "vkDestroyCommandPool",
    "vkResetCommandPool",
    "vkAllocateCommandBuffers",
    "vkFreeCommandBuffers",
    "vkBeginCommandBuffer",
    "vkEndCommandBuffer",
    "vkResetCommandBuffer",
    "vkCmdBindPipeline",
    "vkCmdSetAttachmentFeedbackLoopEnableEXT",
    "vkCmdSetViewport",
    "vkCmdSetScissor",
    "vkCmdSetLineWidth",
    "vkCmdSetDepthBias",
    "vkCmdSetBlendConstants",
    "vkCmdSetDepthBounds",
    "vkCmdSetStencilCompareMask",
    "vkCmdSetStencilWriteMask",
    "vkCmdSetStencilReference",
    "vkCmdBindDescriptorSets",
    "vkCmdBindIndexBuffer",
    "vkCmdBindVertexBuffers",
    "vkCmdDraw",
    "vkCmdDrawIndexed",
    "vkCmdDrawMultiEXT",
    "vkCmdDrawMultiIndexedEXT",
    "vkCmdDrawIndirect",
    "vkCmdDrawIndexedIndirect",
    "vkCmdDispatch",
    "vkCmdDispatchIndirect",
    "vkCmdSubpassShadingHUAWEI",
    "vkCmdDrawClusterHUAWEI",
    "vkCmdDrawClusterIndirectHUAWEI",
    "vkCmdUpdatePipelineIndirectBufferNV",
    "vkCmdCopyBuffer",
    "vkCmdCopyImage",
    "vkCmdBlitImage",
    "vkCmdCopyBufferToImage",
    "vkCmdCopyImageToBuffer",
    "vkCmdCopyMemoryIndirectNV",
    "vkCmdCopyMemoryToImageIndirectNV",
    "vkCmdUpdateBuffer",
    "vkCmdFillBuffer",
    "vkCmdClearColorImage",
    "vkCmdClearDepthStencilImage",
    "vkCmdClearAttachments",
    "vkCmdResolveImage",
    "vkCmdSetEvent",
    "vkCmdResetEvent",
    "vkCmdWaitEvents",
    "vkCmdPipelineBarrier",
    "vkCmdBeginQuery",
    "vkCmdEndQuery",
    "vkCmdBeginConditionalRenderingEXT",
    "vkCmdEndConditionalRenderingEXT",
    "vkCmdResetQueryPool",
    "vkCmdWriteTimestamp",
    "vkCmdCopyQueryPoolResults",
    "vkCmdPushConstants",
    "vkCmdBeginRenderPass",
    "vkCmdNextSubpass",
    "vkCmdEndRenderPass",
    "vkCmdExecuteCommands",
    "vkCreateAndroidSurfaceKHR",
    "vkGetPhysicalDeviceDisplayPropertiesKHR",
    "vkGetPhysicalDeviceDisplayPlanePropertiesKHR",
    "vkGetDisplayPlaneSupportedDisplaysKHR",
    "vkGetDisplayModePropertiesKHR",
    "vkCreateDisplayModeKHR",
    "vkGetDisplayPlaneCapabilitiesKHR",
    "vkCreateDisplayPlaneSurfaceKHR",
    "vkCreateSharedSwapchainsKHR",
    "vkDestroySurfaceKHR",
    "vkGetPhysicalDeviceSurfaceSupportKHR",
    "vkGetPhysicalDeviceSurfaceCapabilitiesKHR",
    "vkGetPhysicalDeviceSurfaceFormatsKHR",
    "vkGetPhysicalDeviceSurfacePresentModesKHR",
    "vkCreateSwapchainKHR",
    "vkDestroySwapchainKHR",
    "vkGetSwapchainImagesKHR",
    "vkAcquireNextImageKHR",
    "vkQueuePresentKHR",
    "vkCreateViSurfaceNN",
    "vkCreateWaylandSurfaceKHR",
    "vkGetPhysicalDeviceWaylandPresentationSupportKHR",
    "vkCreateWin32SurfaceKHR",
    "vkGetPhysicalDeviceWin32PresentationSupportKHR",
    "vkCreateXlibSurfaceKHR",
    "vkGetPhysicalDeviceXlibPresentationSupportKHR",
    "vkCreateXcbSurfaceKHR",
    "vkGetPhysicalDeviceXcbPresentationSupportKHR",
    "vkCreateDirectFBSurfaceEXT",
    "vkGetPhysicalDeviceDirectFBPresentationSupportEXT",
    "vkCreateImagePipeSurfaceFUCHSIA",
    "vkCreateStreamDescriptorSurfaceGGP",
    "vkCreateScreenSurfaceQNX",
    "vkGetPhysicalDeviceScreenPresentationSupportQNX",
    "vkCreateDebugReportCallbackEXT",
    "vkDestroyDebugReportCallbackEXT",
    "vkDebugReportMessageEXT",
    "vkDebugMarkerSetObjectNameEXT",
    "vkDebugMarkerSetObjectTagEXT",
    "vkCmdDebugMarkerBeginEXT",
    "vkCmdDebugMarkerEndEXT",
    "vkCmdDebugMarkerInsertEXT",
    "vkGetPhysicalDeviceExternalImageFormatPropertiesNV",
    "vkGetMemoryWin32HandleNV",
    "vkCmdExecuteGeneratedCommandsNV",
    "vkCmdPreprocessGeneratedCommandsNV",
    "vkCmdBindPipelineShaderGroupNV",
    "vkGetGeneratedCommandsMemoryRequirementsNV",
    "vkCreateIndirectCommandsLayoutNV",
    "vkDestroyIndirectCommandsLayoutNV",
    "vkGetPhysicalDeviceFeatures2",
    "vkGetPhysicalDeviceFeatures2KHR",
    "vkGetPhysicalDeviceProperties2",
    "vkGetPhysicalDeviceProperties2KHR",
    "vkGetPhysicalDeviceFormatProperties2",
    "vkGetPhysicalDeviceFormatProperties2KHR",
    "vkGetPhysicalDeviceImageFormatProperties2",
    "vkGetPhysicalDeviceImageFormatProperties2KHR",
    "vkGetPhysicalDeviceQueueFamilyProperties2",
    "vkGetPhysicalDeviceQueueFamilyProperties2KHR",
    "vkGetPhysicalDeviceMemoryProperties2",
    "vkGetPhysicalDeviceMemoryProperties2KHR",
    "vkGetPhysicalDeviceSparseImageFormatProperties2",
    "vkGetPhysicalDeviceSparseImageFormatProperties2KHR",
    "vkCmdPushDescriptorSetKHR",
    "vkTrimCommandPool",
    "vkTrimCommandPoolKHR",
    "vkGetPhysicalDeviceExternalBufferProperties",
    "vkGetPhysicalDeviceExternalBufferPropertiesKHR",
    "vkGetMemoryWin32HandleKHR",
    "vkGetMemoryWin32HandlePropertiesKHR",
    "vkGetMemoryFdKHR",
    "vkGetMemoryFdPropertiesKHR",
    "vkGetMemoryZirconHandleFUCHSIA",
    "vkGetMemoryZirconHandlePropertiesFUCHSIA",
    "vkGetMemoryRemoteAddressNV",
    "vkGetMemorySciBufNV",
    "vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV",
    "vkGetPhysicalDeviceSciBufAttributesNV",
    "vkGetPhysicalDeviceExternalSemaphoreProperties",
    "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR",
    "vkGetSemaphoreWin32HandleKHR",
    "vkImportSemaphoreWin32HandleKHR",
    "vkGetSemaphoreFdKHR",
    "vkImportSemaphoreFdKHR",
    "vkGetSemaphoreZirconHandleFUCHSIA",
    "vkImportSemaphoreZirconHandleFUCHSIA",
    "vkGetPhysicalDeviceExternalFenceProperties",
    "vkGetPhysicalDeviceExternalFencePropertiesKHR",
    "vkGetFenceWin32HandleKHR",
    "vkImportFenceWin32HandleKHR",
    "vkGetFenceFdKHR",
    "vkImportFenceFdKHR",
    "vkGetFenceSciSyncFenceNV",
    "vkGetFenceSciSyncObjNV",
    "vkImportFenceSciSyncFenceNV",
    "vkImportFenceSciSyncObjNV",
    "vkGetSemaphoreSciSyncObjNV",
    "vkImportSemaphoreSciSyncObjNV",
    "vkGetPhysicalDeviceSciSyncAttributesNV",
    "vkCreateSemaphoreSciSyncPoolNV",
    "vkDestroySemaphoreSciSyncPoolNV",
    "vkReleaseDisplayEXT",
    "vkAcquireXlibDisplayEXT",
    "vkGetRandROutputDisplayEXT",
    "vkAcquireWinrtDisplayNV",
    "vkGetWinrtDisplayNV",
    "vkDisplayPowerControlEXT",
    "vkRegisterDeviceEventEXT",
    "vkRegisterDisplayEventEXT",
    "vkGetSwapchainCounterEXT",
    "vkGetPhysicalDeviceSurfaceCapabilities2EXT",
    "vkEnumeratePhysicalDeviceGroups",
    "vkEnumeratePhysicalDeviceGroupsKHR",
    "vkGetDeviceGroupPeerMemoryFeatures",
    "vkGetDeviceGroupPeerMemoryFeaturesKHR",
    "vkBindBufferMemory2",
    "vkBindBufferMemory2KHR",
    "vkBindImageMemory2",
    "vkBindImageMemory2KHR",
    "vkCmdSetDeviceMask",
    "vkCmdSetDeviceMaskKHR",
    "vkGetDeviceGroupPresentCapabilitiesKHR",
    "vkGetDeviceGroupSurfacePresentModesKHR",
    "vkAcquireNextImage2KHR",
    "vkCmdDispatchBase",
    "vkCmdDispatchBaseKHR",
    "vkGetPhysicalDevicePresentRectanglesKHR",
    "vkCreateDescriptorUpdateTemplate",
    "vkCreateDescriptorUpdateTemplateKHR",
    "vkDestroyDescriptorUpdateTemplate",
    "vkDestroyDescriptorUpdateTemplateKHR",
    "vkUpdateDescriptorSetWithTemplate",
    "vkUpdateDescriptorSetWithTemplateKHR",
    "vkCmdPushDescriptorSetWithTemplateKHR",
    "vkSetHdrMetadataEXT",
    "vkGetSwapchainStatusKHR",
    "vkGetRefreshCycleDurationGOOGLE",
    "vkGetPastPresentationTimingGOOGLE",
    "vkCreateIOSSurfaceMVK",
    "vkCreateMacOSSurfaceMVK",
    "vkCreateMetalSurfaceEXT",
    "vkCmdSetViewportWScalingNV",
    "vkCmdSetDiscardRectangleEXT",
    "vkCmdSetDiscardRectangleEnableEXT",
    "vkCmdSetDiscardRectangleModeEXT",
    "vkCmdSetSampleLocationsEXT",
    "vkGetPhysicalDeviceMultisamplePropertiesEXT",
    "vkGetPhysicalDeviceSurfaceCapabilities2KHR",
    "vkGetPhysicalDeviceSurfaceFormats2KHR",
    "vkGetPhysicalDeviceDisplayProperties2KHR",
    "vkGetPhysicalDeviceDisplayPlaneProperties2KHR",
    "vkGetDisplayModeProperties2KHR",
    "vkGetDisplayPlaneCapabilities2KHR",
    "vkGetBufferMemoryRequirements2",
    "vkGetBufferMemoryRequirements2KHR",
    "vkGetImageMemoryRequirements2",
    "vkGetImageMemoryRequirements2KHR",
    "vkGetImageSparseMemoryRequirements2",
    "vkGetImageSparseMemoryRequirements2KHR",
    "vkGetDeviceBufferMemoryRequirements",
    "vkGetDeviceBufferMemoryRequirementsKHR",
    "vkGetDeviceImageMemoryRequirements",
    "vkGetDeviceImageMemoryRequirementsKHR",
    "vkGetDeviceImageSparseMemoryRequirements",
    "vkGetDeviceImageSparseMemoryRequirementsKHR",
    "vkCreateSamplerYcbcrConversion",
    "vkCreateSamplerYcbcrConversionKHR",
    "vkDestroySamplerYcbcrConversion",
    "vkDestroySamplerYcbcrConversionKHR",
    "vkGetDeviceQueue2",
    "vkCreateValidationCacheEXT",
    "vkDestroyValidationCacheEXT",
    "vkGetValidationCacheDataEXT",
    "vkMergeValidationCachesEXT",
    "vkGetDescriptorSetLayoutSupport",
    "vkGetDescriptorSetLayoutSupportKHR",
    "vkGetSwapchainGrallocUsageANDROID",
    "vkGetSwapchainGrallocUsage2ANDROID",
    "vkAcquireImageANDROID",
    "vkQueueSignalReleaseImageANDROID",
    "vkGetShaderInfoAMD",
    "vkSetLocalDimmingAMD",
    "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR",
    "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT",
    "vkGetCalibratedTimestampsKHR",
    "vkGetCalibratedTimestampsEXT",
    "vkSetDebugUtilsObjectNameEXT",
    "vkSetDebugUtilsObjectTagEXT",
    "vkQueueBeginDebugUtilsLabelEXT",
    "vkQueueEndDebugUtilsLabelEXT",
    "vkQueueInsertDebugUtilsLabelEXT",
    "vkCmdBeginDebugUtilsLabelEXT",
    "vkCmdEndDebugUtilsLabelEXT",
    "vkCmdInsertDebugUtilsLabelEXT",
    "vkCreateDebugUtilsMessengerEXT",
    "vkDestroyDebugUtilsMessengerEXT",
    "vkSubmitDebugUtilsMessageEXT",
    "vkGetMemoryHostPointerPropertiesEXT",
    "vkCmdWriteBufferMarkerAMD",
    "vkCreateRenderPass2",
    "vkCreateRenderPass2KHR",
    "vkCmdBeginRenderPass2",
    "vkCmdBeginRenderPass2KHR",
    "vkCmdNextSubpass2",
    "vkCmdNextSubpass2KHR",
    "vkCmdEndRenderPass2",
    "vkCmdEndRenderPass2KHR",
    "vkGetSemaphoreCounterValue",
    "vkGetSemaphoreCounterValueKHR",
    "vkWaitSemaphores",
    "vkWaitSemaphoresKHR",
    "vkSignalSemaphore",
    "vkSignalSemaphoreKHR",
    "vkGetAndroidHardwareBufferPropertiesANDROID",
    "vkGetMemoryAndroidHardwareBufferANDROID",
    "vkCmdDrawIndirectCount",
    "vkCmdDrawIndirectCountKHR",
    "vkCmdDrawIndirectCountAMD",
    "vkCmdDrawIndexedIndirectCount",
    "vkCmdDrawIndexedIndirectCountKHR",
    "vkCmdDrawIndexedIndirectCountAMD",
    "vkCmdSetCheckpointNV",
    "vkGetQueueCheckpointDataNV",
    "vkCmdBindTransformFeedbackBuffersEXT",
    "vkCmdBeginTransformFeedbackEXT",
    "vkCmdEndTransformFeedbackEXT",
    "vkCmdBeginQueryIndexedEXT",
    "vkCmdEndQueryIndexedEXT",
    "vkCmdDrawIndirectByteCountEXT",
    "vkCmdSetExclusiveScissorNV",
    "vkCmdSetExclusiveScissorEnableNV",
    "vkCmdBindShadingRateImageNV",
    "vkCmdSetViewportShadingRatePaletteNV",
    "vkCmdSetCoarseSampleOrderNV",
    "vkCmdDrawMeshTasksNV",
    "vkCmdDrawMeshTasksIndirectNV",
    "vkCmdDrawMeshTasksIndirectCountNV",
    "vkCmdDrawMeshTasksEXT",
    "vkCmdDrawMeshTasksIndirectEXT",
    "vkCmdDrawMeshTasksIndirectCountEXT",
    "vkCompileDeferredNV",
    "vkCreateAccelerationStructureNV",
    "vkCmdBindInvocationMaskHUAWEI",
    "vkDestroyAccelerationStructureKHR",
    "vkDestroyAccelerationStructureNV",
    "vkGetAccelerationStructureMemoryRequirementsNV",
    "vkBindAccelerationStructureMemoryNV",
    "vkCmdCopyAccelerationStructureNV",
    "vkCmdCopyAccelerationStructureKHR",
    "vkCopyAccelerationStructureKHR",
    "vkCmdCopyAccelerationStructureToMemoryKHR",
    "vkCopyAccelerationStructureToMemoryKHR",
    "vkCmdCopyMemoryToAccelerationStructureKHR",
    "vkCopyMemoryToAccelerationStructureKHR",
    "vkCmdWriteAccelerationStructuresPropertiesKHR",
    "vkCmdWriteAccelerationStructuresPropertiesNV",
    "vkCmdBuildAccelerationStructureNV",
    "vkWriteAccelerationStructuresPropertiesKHR",
    "vkCmdTraceRaysKHR",
    "vkCmdTraceRaysNV",
    "vkGetRayTracingShaderGroupHandlesKHR",
    "vkGetRayTracingShaderGroupHandlesNV",
    "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR",
    "vkGetAccelerationStructureHandleNV",
    "vkCreateRayTracingPipelinesNV",
    "vkCreateRayTracingPipelinesKHR",
    "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV",
    "vkCmdTraceRaysIndirectKHR",
    "vkCmdTraceRaysIndirect2KHR",
    "vkGetDeviceAccelerationStructureCompatibilityKHR",
    "vkGetRayTracingShaderGroupStackSizeKHR",
    "vkCmdSetRayTracingPipelineStackSizeKHR",
    "vkGetImageViewHandleNVX",
    "vkGetImageViewAddressNVX",
    "vkGetPhysicalDeviceSurfacePresentModes2EXT",
    "vkGetDeviceGroupSurfacePresentModes2EXT",
    "vkAcquireFullScreenExclusiveModeEXT",
    "vkReleaseFullScreenExclusiveModeEXT",
    "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR",
    "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR",
    "vkAcquireProfilingLockKHR",
    "vkReleaseProfilingLockKHR",
    "vkGetImageDrmFormatModifierPropertiesEXT",
    "vkGetBufferOpaqueCaptureAddress",
    "vkGetBufferOpaqueCaptureAddressKHR",
    "vkGetBufferDeviceAddress",
    "vkGetBufferDeviceAddressKHR",
    "vkGetBufferDeviceAddressEXT",
    "vkCreateHeadlessSurfaceEXT",
    "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV",
    "vkInitializePerformanceApiINTEL",
    "vkUninitializePerformanceApiINTEL",
    "vkCmdSetPerformanceMarkerINTEL",
    "vkCmdSetPerformanceStreamMarkerINTEL",
    "vkCmdSetPerformanceOverrideINTEL",
    "vkAcquirePerformanceConfigurationINTEL",
    "vkReleasePerformanceConfigurationINTEL",
    "vkQueueSetPerformanceConfigurationINTEL",
    "vkGetPerformanceParameterINTEL",
    "vkGetDeviceMemoryOpaqueCaptureAddress",
    "vkGetDeviceMemoryOpaqueCaptureAddressKHR",
    "vkGetPipelineExecutablePropertiesKHR",
    "vkGetPipelineExecutableStatisticsKHR",
    "vkGetPipelineExecutableInternalRepresentationsKHR",
    "vkCmdSetLineStippleEXT",
    "vkGetFaultData",
    "vkGetPhysicalDeviceToolProperties",
    "vkGetPhysicalDeviceToolPropertiesEXT",
    "vkCreateAccelerationStructureKHR",
    "vkCmdBuildAccelerationStructuresKHR",
    "vkCmdBuildAccelerationStructuresIndirectKHR",
    "vkBuildAccelerationStructuresKHR",
    "vkGetAccelerationStructureDeviceAddressKHR",
    "vkCreateDeferredOperationKHR",
    "vkDestroyDeferredOperationKHR",
    "vkGetDeferredOperationMaxConcurrencyKHR",
    "vkGetDeferredOperationResultKHR",
    "vkDeferredOperationJoinKHR",
    "vkGetPipelineIndirectMemoryRequirementsNV",
    "vkGetPipelineIndirectDeviceAddressNV",
    "vkCmdSetCullMode",
    "vkCmdSetCullModeEXT",
    "vkCmdSetFrontFace",
    "vkCmdSetFrontFaceEXT",
    "vkCmdSetPrimitiveTopology",
    "vkCmdSetPrimitiveTopologyEXT",
    "vkCmdSetViewportWithCount",
    "vkCmdSetViewportWithCountEXT",
    "vkCmdSetScissorWithCount",
    "vkCmdSetScissorWithCountEXT",
    "vkCmdBindIndexBuffer2KHR",
    "vkCmdBindVertexBuffers2",
    "vkCmdBindVertexBuffers2EXT",
    "vkCmdSetDepthTestEnable",
    "vkCmdSetDepthTestEnableEXT",
    "vkCmdSetDepthWriteEnable",
    "vkCmdSetDepthWriteEnableEXT",
    "vkCmdSetDepthCompareOp",
    "vkCmdSetDepthCompareOpEXT",
    "vkCmdSetDepthBoundsTestEnable",
    "vkCmdSetDepthBoundsTestEnableEXT",
    "vkCmdSetStencilTestEnable",
    "vkCmdSetStencilTestEnableEXT",
    "vkCmdSetStencilOp",
    "vkCmdSetStencilOpEXT",
    "vkCmdSetPatchControlPointsEXT",
    "vkCmdSetRasterizerDiscardEnable",
    "vkCmdSetRasterizerDiscardEnableEXT",
    "vkCmdSetDepthBiasEnable",
    "vkCmdSetDepthBiasEnableEXT",
    "vkCmdSetLogicOpEXT",
    "vkCmdSetPrimitiveRestartEnable",
    "vkCmdSetPrimitiveRestartEnableEXT",
    "vkCmdSetTessellationDomainOriginEXT",
    "vkCmdSetDepthClampEnableEXT",
    "vkCmdSetPolygonModeEXT",
    "vkCmdSetRasterizationSamplesEXT",
    "vkCmdSetSampleMaskEXT",
    "vkCmdSetAlphaToCoverageEnableEXT",
    "vkCmdSetAlphaToOneEnableEXT",
    "vkCmdSetLogicOpEnableEXT",
    "vkCmdSetColorBlendEnableEXT",
    "vkCmdSetColorBlendEquationEXT",
    "vkCmdSetColorWriteMaskEXT",
    "vkCmdSetRasterizationStreamEXT",
    "vkCmdSetConservativeRasterizationModeEXT",
    "vkCmdSetExtraPrimitiveOverestimationSizeEXT",
    "vkCmdSetDepthClipEnableEXT",
    "vkCmdSetSampleLocationsEnableEXT",
    "vkCmdSetColorBlendAdvancedEXT",
    "vkCmdSetProvokingVertexModeEXT",
    "vkCmdSetLineRasterizationModeEXT",
    "vkCmdSetLineStippleEnableEXT",
    "vkCmdSetDepthClipNegativeOneToOneEXT",
    "vkCmdSetViewportWScalingEnableNV",
    "vkCmdSetViewportSwizzleNV",
    "vkCmdSetCoverageToColorEnableNV",
    "vkCmdSetCoverageToColorLocationNV",
    "vkCmdSetCoverageModulationModeNV",
    "vkCmdSetCoverageModulationTableEnableNV",
    "vkCmdSetCoverageModulationTableNV",
    "vkCmdSetShadingRateImageEnableNV",
    "vkCmdSetCoverageReductionModeNV",
    "vkCmdSetRepresentativeFragmentTestEnableNV",
    "vkCreatePrivateDataSlot",
    "vkCreatePrivateDataSlotEXT",
    "vkDestroyPrivateDataSlot",
    "vkDestroyPrivateDataSlotEXT",
    "vkSetPrivateData",
    "vkSetPrivateDataEXT",
    "vkGetPrivateData",
    "vkGetPrivateDataEXT",
    "vkCmdCopyBuffer2",
    "vkCmdCopyBuffer2KHR",
    "vkCmdCopyImage2",
    "vkCmdCopyImage2KHR",
    "vkCmdBlitImage2",
    "vkCmdBlitImage2KHR",
    "vkCmdCopyBufferToImage2",
    "vkCmdCopyBufferToImage2KHR",
    "vkCmdCopyImageToBuffer2",
    "vkCmdCopyImageToBuffer2KHR",
    "vkCmdResolveImage2",
    "vkCmdResolveImage2KHR",
    "vkCmdRefreshObjectsKHR",
    "vkGetPhysicalDeviceRefreshableObjectTypesKHR",
    "vkCmdSetFragmentShadingRateKHR",
    "vkGetPhysicalDeviceFragmentShadingRatesKHR",
    "vkCmdSetFragmentShadingRateEnumNV",
    "vkGetAccelerationStructureBuildSizesKHR",
    "vkCmdSetVertexInputEXT",
    "vkCmdSetColorWriteEnableEXT",
    "vkCmdSetEvent2",
    "vkCmdSetEvent2KHR",
    "vkCmdResetEvent2",
    "vkCmdResetEvent2KHR",
    "vkCmdWaitEvents2",
    "vkCmdWaitEvents2KHR",
    "vkCmdPipelineBarrier2",
    "vkCmdPipelineBarrier2KHR",
    "vkQueueSubmit2",
    "vkQueueSubmit2KHR",
    "vkCmdWriteTimestamp2",
    "vkCmdWriteTimestamp2KHR",
    "vkCmdWriteBufferMarker2AMD",
    "vkGetQueueCheckpointData2NV",
    "vkCopyMemoryToImageEXT",
    "vkCopyImageToMemoryEXT",
    "vkCopyImageToImageEXT",
    "vkTransitionImageLayoutEXT",
    "vkGetCommandPoolMemoryConsumption",
    "vkGetPhysicalDeviceVideoCapabilitiesKHR",
    "vkGetPhysicalDeviceVideoFormatPropertiesKHR",
    "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR",
    "vkCreateVideoSessionKHR",
    "vkDestroyVideoSessionKHR",
    "vkCreateVideoSessionParametersKHR",
    "vkUpdateVideoSessionParametersKHR",
    "vkGetEncodedVideoSessionParametersKHR",
    "vkDestroyVideoSessionParametersKHR",
    "vkGetVideoSessionMemoryRequirementsKHR",
    "vkBindVideoSessionMemoryKHR",
    "vkCmdDecodeVideoKHR",
    "vkCmdBeginVideoCodingKHR",
    "vkCmdControlVideoCodingKHR",
    "vkCmdEndVideoCodingKHR",
    "vkCmdEncodeVideoKHR",
    "vkCmdDecompressMemoryNV",
    "vkCmdDecompressMemoryIndirectCountNV",
    "vkCreateCuModuleNVX",
    "vkCreateCuFunctionNVX",
    "vkDestroyCuModuleNVX",
    "vkDestroyCuFunctionNVX",
    "vkCmdCuLaunchKernelNVX",
    "vkGetDescriptorSetLayoutSizeEXT",
    "vkGetDescriptorSetLayoutBindingOffsetEXT",
    "vkGetDescriptorEXT",
    "vkCmdBindDescriptorBuffersEXT",
    "vkCmdSetDescriptorBufferOffsetsEXT",
    "vkCmdBindDescriptorBufferEmbeddedSamplersEXT",
    "vkGetBufferOpaqueCaptureDescriptorDataEXT",
    "vkGetImageOpaqueCaptureDescriptorDataEXT",
    "vkGetImageViewOpaqueCaptureDescriptorDataEXT",
    "vkGetSamplerOpaqueCaptureDescriptorDataEXT",
    "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT",
    "vkSetDeviceMemoryPriorityEXT",
    "vkAcquireDrmDisplayEXT",
    "vkGetDrmDisplayEXT",
    "vkWaitForPresentKHR",
    "vkCreateBufferCollectionFUCHSIA",
    "vkSetBufferCollectionBufferConstraintsFUCHSIA",
    "vkSetBufferCollectionImageConstraintsFUCHSIA",
    "vkDestroyBufferCollectionFUCHSIA",
    "vkGetBufferCollectionPropertiesFUCHSIA",
    "vkCreateCudaModuleNV",
    "vkGetCudaModuleCacheNV",
    "vkCreateCudaFunctionNV",
    "vkDestroyCudaModuleNV",
    "vkDestroyCudaFunctionNV",
    "vkCmdCudaLaunchKernelNV",
    "vkCmdBeginRendering",
    "vkCmdBeginRenderingKHR",
    "vkCmdEndRendering",
    "vkCmdEndRenderingKHR",
    "vkGetDescriptorSetLayoutHostMappingInfoVALVE",
    "vkGetDescriptorSetHostMappingVALVE",
    "vkCreateMicromapEXT",
    "vkCmdBuildMicromapsEXT",
    "vkBuildMicromapsEXT",
    "vkDestroyMicromapEXT",
    "vkCmdCopyMicromapEXT",
    "vkCopyMicromapEXT",
    "vkCmdCopyMicromapToMemoryEXT",
    "vkCopyMicromapToMemoryEXT",
    "vkCmdCopyMemoryToMicromapEXT",
    "vkCopyMemoryToMicromapEXT",
    "vkCmdWriteMicromapsPropertiesEXT",
    "vkWriteMicromapsPropertiesEXT",
    "vkGetDeviceMicromapCompatibilityEXT",
    "vkGetMicromapBuildSizesEXT",
    "vkGetShaderModuleIdentifierEXT",
    "vkGetShaderModuleCreateInfoIdentifierEXT",
    "vkGetImageSubresourceLayout2KHR",
    "vkGetImageSubresourceLayout2EXT",
    "vkGetPipelinePropertiesEXT",
    "vkExportMetalObjectsEXT",
    "vkGetFramebufferTilePropertiesQCOM",
    "vkGetDynamicRenderingTilePropertiesQCOM",
    "vkGetPhysicalDeviceOpticalFlowImageFormatsNV",
    "vkCreateOpticalFlowSessionNV",
    "vkDestroyOpticalFlowSessionNV",
    "vkBindOpticalFlowSessionImageNV",
    "vkCmdOpticalFlowExecuteNV",
    "vkGetDeviceFaultInfoEXT",
    "vkCmdSetDepthBias2EXT",
    "vkReleaseSwapchainImagesEXT",
    "vkGetDeviceImageSubresourceLayoutKHR",
    "vkMapMemory2KHR",
    "vkUnmapMemory2KHR",
    "vkCreateShadersEXT",
    "vkDestroyShaderEXT",
    "vkGetShaderBinaryDataEXT",
    "vkCmdBindShadersEXT",
    "vkGetScreenBufferPropertiesQNX",
    "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR",
    "vkGetExecutionGraphPipelineScratchSizeAMDX",
    "vkGetExecutionGraphPipelineNodeIndexAMDX",
    "vkCreateExecutionGraphPipelinesAMDX",
    "vkCmdInitializeGraphScratchMemoryAMDX",
    "vkCmdDispatchGraphAMDX",
    "vkCmdDispatchGraphIndirectAMDX",
    "vkCmdDispatchGraphIndirectCountAMDX",
    "vkCmdBindDescriptorSets2KHR",
    "vkCmdPushConstants2KHR",
    "vkCmdPushDescriptorSet2KHR",
    "vkCmdPushDescriptorSetWithTemplate2KHR",
    "vkCmdSetDescriptorBufferOffsets2EXT",
    "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT",
    "vkSetLatencySleepModeNV",
    "vkLatencySleepNV",
    "vkSetLatencyMarkerNV",
    "vkGetLatencyTimingsNV",
    "vkQueueNotifyOutOfBandNV",
    "VK_KHR_SURFACE_SPEC_VERSION",
    "VK_KHR_SURFACE_EXTENSION_NAME",
    "VK_KHR_SWAPCHAIN_SPEC_VERSION",
    "VK_KHR_SWAPCHAIN_EXTENSION_NAME",
    "VK_KHR_DISPLAY_SPEC_VERSION",
    "VK_KHR_DISPLAY_EXTENSION_NAME",
    "VK_KHR_DISPLAY_SWAPCHAIN_SPEC_VERSION",
    "VK_KHR_DISPLAY_SWAPCHAIN_EXTENSION_NAME",
    "VK_KHR_XLIB_SURFACE_SPEC_VERSION",
    "VK_KHR_XLIB_SURFACE_EXTENSION_NAME",
    "VK_KHR_XCB_SURFACE_SPEC_VERSION",
    "VK_KHR_XCB_SURFACE_EXTENSION_NAME",
    "VK_KHR_WAYLAND_SURFACE_SPEC_VERSION",
    "VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME",
    "VK_KHR_MIR_SURFACE_SPEC_VERSION",
    "VK_KHR_MIR_SURFACE_EXTENSION_NAME",
    "VK_KHR_ANDROID_SURFACE_SPEC_VERSION",
    "VK_KHR_ANDROID_SURFACE_EXTENSION_NAME",
    "VK_KHR_WIN32_SURFACE_SPEC_VERSION",
    "VK_KHR_WIN32_SURFACE_EXTENSION_NAME",
    "VK_ANDROID_NATIVE_BUFFER_SPEC_VERSION",
    "VK_ANDROID_NATIVE_BUFFER_NUMBER",
    "VK_ANDROID_NATIVE_BUFFER_EXTENSION_NAME",
    "VK_ANDROID_NATIVE_BUFFER_NAME",
    "VK_EXT_DEBUG_REPORT_SPEC_VERSION",
    "VK_EXT_DEBUG_REPORT_EXTENSION_NAME",
    "VK_NV_GLSL_SHADER_SPEC_VERSION",
    "VK_NV_GLSL_SHADER_EXTENSION_NAME",
    "VK_EXT_DEPTH_RANGE_UNRESTRICTED_SPEC_VERSION",
    "VK_EXT_DEPTH_RANGE_UNRESTRICTED_EXTENSION_NAME",
    "VK_KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_SPEC_VERSION",
    "VK_KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_EXTENSION_NAME",
    "VK_IMG_FILTER_CUBIC_SPEC_VERSION",
    "VK_IMG_FILTER_CUBIC_EXTENSION_NAME",
    "VK_AMD_EXTENSION_17_SPEC_VERSION",
    "VK_AMD_EXTENSION_17_EXTENSION_NAME",
    "VK_AMD_EXTENSION_18_SPEC_VERSION",
    "VK_AMD_EXTENSION_18_EXTENSION_NAME",
    "VK_AMD_RASTERIZATION_ORDER_SPEC_VERSION",
    "VK_AMD_RASTERIZATION_ORDER_EXTENSION_NAME",
    "VK_AMD_EXTENSION_20_SPEC_VERSION",
    "VK_AMD_EXTENSION_20_EXTENSION_NAME",
    "VK_AMD_SHADER_TRINARY_MINMAX_SPEC_VERSION",
    "VK_AMD_SHADER_TRINARY_MINMAX_EXTENSION_NAME",
    "VK_AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_SPEC_VERSION",
    "VK_AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_EXTENSION_NAME",
    "VK_EXT_DEBUG_MARKER_SPEC_VERSION",
    "VK_EXT_DEBUG_MARKER_EXTENSION_NAME",
    "VK_KHR_VIDEO_QUEUE_SPEC_VERSION",
    "VK_KHR_VIDEO_QUEUE_EXTENSION_NAME",
    "VK_KHR_VIDEO_DECODE_QUEUE_SPEC_VERSION",
    "VK_KHR_VIDEO_DECODE_QUEUE_EXTENSION_NAME",
    "VK_AMD_GCN_SHADER_SPEC_VERSION",
    "VK_AMD_GCN_SHADER_EXTENSION_NAME",
    "VK_NV_DEDICATED_ALLOCATION_SPEC_VERSION",
    "VK_NV_DEDICATED_ALLOCATION_EXTENSION_NAME",
    "VK_EXT_EXTENSION_28_SPEC_VERSION",
    "VK_EXT_EXTENSION_28_EXTENSION_NAME",
    "VK_EXT_TRANSFORM_FEEDBACK_SPEC_VERSION",
    "VK_EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME",
    "VK_NVX_BINARY_IMPORT_SPEC_VERSION",
    "VK_NVX_BINARY_IMPORT_EXTENSION_NAME",
    "VK_NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION",
    "VK_NVX_IMAGE_VIEW_HANDLE_EXTENSION_NAME",
    "VK_AMD_EXTENSION_32_SPEC_VERSION",
    "VK_AMD_EXTENSION_32_EXTENSION_NAME",
    "VK_AMD_EXTENSION_33_SPEC_VERSION",
    "VK_AMD_EXTENSION_33_EXTENSION_NAME",
    "VK_AMD_DRAW_INDIRECT_COUNT_SPEC_VERSION",
    "VK_AMD_DRAW_INDIRECT_COUNT_EXTENSION_NAME",
    "VK_AMD_EXTENSION_35_SPEC_VERSION",
    "VK_AMD_EXTENSION_35_EXTENSION_NAME",
    "VK_AMD_NEGATIVE_VIEWPORT_HEIGHT_SPEC_VERSION",
    "VK_AMD_NEGATIVE_VIEWPORT_HEIGHT_EXTENSION_NAME",
    "VK_AMD_GPU_SHADER_HALF_FLOAT_SPEC_VERSION",
    "VK_AMD_GPU_SHADER_HALF_FLOAT_EXTENSION_NAME",
    "VK_AMD_SHADER_BALLOT_SPEC_VERSION",
    "VK_AMD_SHADER_BALLOT_EXTENSION_NAME",
    "VK_KHR_VIDEO_ENCODE_H264_SPEC_VERSION",
    "VK_KHR_VIDEO_ENCODE_H264_EXTENSION_NAME",
    "VK_KHR_VIDEO_ENCODE_H265_SPEC_VERSION",
    "VK_KHR_VIDEO_ENCODE_H265_EXTENSION_NAME",
    "VK_KHR_VIDEO_DECODE_H264_SPEC_VERSION",
    "VK_KHR_VIDEO_DECODE_H264_EXTENSION_NAME",
    "VK_AMD_TEXTURE_GATHER_BIAS_LOD_SPEC_VERSION",
    "VK_AMD_TEXTURE_GATHER_BIAS_LOD_EXTENSION_NAME",
    "VK_AMD_SHADER_INFO_SPEC_VERSION",
    "VK_AMD_SHADER_INFO_EXTENSION_NAME",
    "VK_AMD_EXTENSION_44_SPEC_VERSION",
    "VK_AMD_EXTENSION_44_EXTENSION_NAME",
    "VK_KHR_DYNAMIC_RENDERING_SPEC_VERSION",
    "VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME",
    "VK_AMD_EXTENSION_46_SPEC_VERSION",
    "VK_AMD_EXTENSION_46_EXTENSION_NAME",
    "VK_AMD_SHADER_IMAGE_LOAD_STORE_LOD_SPEC_VERSION",
    "VK_AMD_SHADER_IMAGE_LOAD_STORE_LOD_EXTENSION_NAME",
    "VK_NVX_EXTENSION_48_SPEC_VERSION",
    "VK_NVX_EXTENSION_48_EXTENSION_NAME",
    "VK_GOOGLE_EXTENSION_49_SPEC_VERSION",
    "VK_GOOGLE_EXTENSION_49_EXTENSION_NAME",
    "VK_GGP_STREAM_DESCRIPTOR_SURFACE_SPEC_VERSION",
    "VK_GGP_STREAM_DESCRIPTOR_SURFACE_EXTENSION_NAME",
    "VK_NV_CORNER_SAMPLED_IMAGE_SPEC_VERSION",
    "VK_NV_CORNER_SAMPLED_IMAGE_EXTENSION_NAME",
    "VK_NV_PRIVATE_VENDOR_INFO_SPEC_VERSION",
    "VK_NV_PRIVATE_VENDOR_INFO_EXTENSION_NAME",
    "VK_NV_EXTENSION_53_SPEC_VERSION",
    "VK_NV_EXTENSION_53_EXTENSION_NAME",
    "VK_KHR_MULTIVIEW_SPEC_VERSION",
    "VK_KHR_MULTIVIEW_EXTENSION_NAME",
    "VK_IMG_FORMAT_PVRTC_SPEC_VERSION",
    "VK_IMG_FORMAT_PVRTC_EXTENSION_NAME",
    "VK_NV_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION",
    "VK_NV_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME",
    "VK_NV_EXTERNAL_MEMORY_SPEC_VERSION",
    "VK_NV_EXTERNAL_MEMORY_EXTENSION_NAME",
    "VK_NV_EXTERNAL_MEMORY_WIN32_SPEC_VERSION",
    "VK_NV_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME",
    "VK_NV_WIN32_KEYED_MUTEX_SPEC_VERSION",
    "VK_NV_WIN32_KEYED_MUTEX_EXTENSION_NAME",
    "VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_SPEC_VERSION",
    "VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME",
    "VK_KHR_DEVICE_GROUP_SPEC_VERSION",
    "VK_KHR_DEVICE_GROUP_EXTENSION_NAME",
    "VK_EXT_VALIDATION_FLAGS_SPEC_VERSION",
    "VK_EXT_VALIDATION_FLAGS_EXTENSION_NAME",
    "VK_NN_VI_SURFACE_SPEC_VERSION",
    "VK_NN_VI_SURFACE_EXTENSION_NAME",
    "VK_KHR_SHADER_DRAW_PARAMETERS_SPEC_VERSION",
    "VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME",
    "VK_EXT_SHADER_SUBGROUP_BALLOT_SPEC_VERSION",
    "VK_EXT_SHADER_SUBGROUP_BALLOT_EXTENSION_NAME",
    "VK_EXT_SHADER_SUBGROUP_VOTE_SPEC_VERSION",
    "VK_EXT_SHADER_SUBGROUP_VOTE_EXTENSION_NAME",
    "VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_SPEC_VERSION",
    "VK_EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME",
    "VK_EXT_ASTC_DECODE_MODE_SPEC_VERSION",
    "VK_EXT_ASTC_DECODE_MODE_EXTENSION_NAME",
    "VK_EXT_PIPELINE_ROBUSTNESS_SPEC_VERSION",
    "VK_EXT_PIPELINE_ROBUSTNESS_EXTENSION_NAME",
    "VK_KHR_MAINTENANCE_1_SPEC_VERSION",
    "VK_KHR_MAINTENANCE_1_EXTENSION_NAME",
    "VK_KHR_MAINTENANCE1_SPEC_VERSION",
    "VK_KHR_MAINTENANCE1_EXTENSION_NAME",
    "VK_KHR_DEVICE_GROUP_CREATION_SPEC_VERSION",
    "VK_KHR_DEVICE_GROUP_CREATION_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION",
    "VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_MEMORY_SPEC_VERSION",
    "VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_MEMORY_WIN32_SPEC_VERSION",
    "VK_KHR_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_MEMORY_FD_SPEC_VERSION",
    "VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME",
    "VK_KHR_WIN32_KEYED_MUTEX_SPEC_VERSION",
    "VK_KHR_WIN32_KEYED_MUTEX_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_SPEC_VERSION",
    "VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_SEMAPHORE_SPEC_VERSION",
    "VK_KHR_EXTERNAL_SEMAPHORE_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_SEMAPHORE_WIN32_SPEC_VERSION",
    "VK_KHR_EXTERNAL_SEMAPHORE_WIN32_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_SEMAPHORE_FD_SPEC_VERSION",
    "VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME",
    "VK_KHR_PUSH_DESCRIPTOR_SPEC_VERSION",
    "VK_KHR_PUSH_DESCRIPTOR_EXTENSION_NAME",
    "VK_EXT_CONDITIONAL_RENDERING_SPEC_VERSION",
    "VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME",
    "VK_KHR_SHADER_FLOAT16_INT8_SPEC_VERSION",
    "VK_KHR_SHADER_FLOAT16_INT8_EXTENSION_NAME",
    "VK_KHR_16BIT_STORAGE_SPEC_VERSION",
    "VK_KHR_16BIT_STORAGE_EXTENSION_NAME",
    "VK_KHR_INCREMENTAL_PRESENT_SPEC_VERSION",
    "VK_KHR_INCREMENTAL_PRESENT_EXTENSION_NAME",
    "VK_KHR_DESCRIPTOR_UPDATE_TEMPLATE_SPEC_VERSION",
    "VK_KHR_DESCRIPTOR_UPDATE_TEMPLATE_EXTENSION_NAME",
    "VK_NVX_DEVICE_GENERATED_COMMANDS_SPEC_VERSION",
    "VK_NVX_DEVICE_GENERATED_COMMANDS_EXTENSION_NAME",
    "VK_NV_CLIP_SPACE_W_SCALING_SPEC_VERSION",
    "VK_NV_CLIP_SPACE_W_SCALING_EXTENSION_NAME",
    "VK_EXT_DIRECT_MODE_DISPLAY_SPEC_VERSION",
    "VK_EXT_DIRECT_MODE_DISPLAY_EXTENSION_NAME",
    "VK_EXT_ACQUIRE_XLIB_DISPLAY_SPEC_VERSION",
    "VK_EXT_ACQUIRE_XLIB_DISPLAY_EXTENSION_NAME",
    "VK_EXT_DISPLAY_SURFACE_COUNTER_SPEC_VERSION",
    "VK_EXT_DISPLAY_SURFACE_COUNTER_EXTENSION_NAME",
    "VK_EXT_DISPLAY_CONTROL_SPEC_VERSION",
    "VK_EXT_DISPLAY_CONTROL_EXTENSION_NAME",
    "VK_GOOGLE_DISPLAY_TIMING_SPEC_VERSION",
    "VK_GOOGLE_DISPLAY_TIMING_EXTENSION_NAME",
    "VK_RESERVED_DO_NOT_USE_94_SPEC_VERSION",
    "VK_RESERVED_DO_NOT_USE_94_EXTENSION_NAME",
    "VK_NV_SAMPLE_MASK_OVERRIDE_COVERAGE_SPEC_VERSION",
    "VK_NV_SAMPLE_MASK_OVERRIDE_COVERAGE_EXTENSION_NAME",
    "VK_NV_GEOMETRY_SHADER_PASSTHROUGH_SPEC_VERSION",
    "VK_NV_GEOMETRY_SHADER_PASSTHROUGH_EXTENSION_NAME",
    "VK_NV_VIEWPORT_ARRAY_2_SPEC_VERSION",
    "VK_NV_VIEWPORT_ARRAY_2_EXTENSION_NAME",
    "VK_NV_VIEWPORT_ARRAY2_SPEC_VERSION",
    "VK_NV_VIEWPORT_ARRAY2_EXTENSION_NAME",
    "VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_SPEC_VERSION",
    "VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_EXTENSION_NAME",
    "VK_NV_VIEWPORT_SWIZZLE_SPEC_VERSION",
    "VK_NV_VIEWPORT_SWIZZLE_EXTENSION_NAME",
    "VK_EXT_DISCARD_RECTANGLES_SPEC_VERSION",
    "VK_EXT_DISCARD_RECTANGLES_EXTENSION_NAME",
    "VK_NV_EXTENSION_101_SPEC_VERSION",
    "VK_NV_EXTENSION_101_EXTENSION_NAME",
    "VK_EXT_CONSERVATIVE_RASTERIZATION_SPEC_VERSION",
    "VK_EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME",
    "VK_EXT_DEPTH_CLIP_ENABLE_SPEC_VERSION",
    "VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME",
    "VK_NV_EXTENSION_104_SPEC_VERSION",
    "VK_NV_EXTENSION_104_EXTENSION_NAME",
    "VK_EXT_SWAPCHAIN_COLOR_SPACE_SPEC_VERSION",
    "VK_EXT_SWAPCHAIN_COLOR_SPACE_EXTENSION_NAME",
    "VK_EXT_HDR_METADATA_SPEC_VERSION",
    "VK_EXT_HDR_METADATA_EXTENSION_NAME",
    "VK_IMG_EXTENSION_107_SPEC_VERSION",
    "VK_IMG_EXTENSION_107_EXTENSION_NAME",
    "VK_IMG_EXTENSION_108_SPEC_VERSION",
    "VK_IMG_EXTENSION_108_EXTENSION_NAME",
    "VK_KHR_IMAGELESS_FRAMEBUFFER_SPEC_VERSION",
    "VK_KHR_IMAGELESS_FRAMEBUFFER_EXTENSION_NAME",
    "VK_KHR_CREATE_RENDERPASS_2_SPEC_VERSION",
    "VK_KHR_CREATE_RENDERPASS_2_EXTENSION_NAME",
    "VK_IMG_RELAXED_LINE_RASTERIZATION_SPEC_VERSION",
    "VK_IMG_RELAXED_LINE_RASTERIZATION_EXTENSION_NAME",
    "VK_KHR_SHARED_PRESENTABLE_IMAGE_SPEC_VERSION",
    "VK_KHR_SHARED_PRESENTABLE_IMAGE_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_FENCE_CAPABILITIES_SPEC_VERSION",
    "VK_KHR_EXTERNAL_FENCE_CAPABILITIES_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_FENCE_SPEC_VERSION",
    "VK_KHR_EXTERNAL_FENCE_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_FENCE_WIN32_SPEC_VERSION",
    "VK_KHR_EXTERNAL_FENCE_WIN32_EXTENSION_NAME",
    "VK_KHR_EXTERNAL_FENCE_FD_SPEC_VERSION",
    "VK_KHR_EXTERNAL_FENCE_FD_EXTENSION_NAME",
    "VK_KHR_PERFORMANCE_QUERY_SPEC_VERSION",
    "VK_KHR_PERFORMANCE_QUERY_EXTENSION_NAME",
    "VK_KHR_MAINTENANCE_2_SPEC_VERSION",
    "VK_KHR_MAINTENANCE_2_EXTENSION_NAME",
    "VK_KHR_MAINTENANCE2_SPEC_VERSION",
    "VK_KHR_MAINTENANCE2_EXTENSION_NAME",
    "VK_KHR_EXTENSION_119_SPEC_VERSION",
    "VK_KHR_EXTENSION_119_EXTENSION_NAME",
    "VK_KHR_GET_SURFACE_CAPABILITIES_2_SPEC_VERSION",
    "VK_KHR_GET_SURFACE_CAPABILITIES_2_EXTENSION_NAME",
    "VK_KHR_VARIABLE_POINTERS_SPEC_VERSION",
    "VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME",
    "VK_KHR_GET_DISPLAY_PROPERTIES_2_SPEC_VERSION",
    "VK_KHR_GET_DISPLAY_PROPERTIES_2_EXTENSION_NAME",
    "VK_MVK_IOS_SURFACE_SPEC_VERSION",
    "VK_MVK_IOS_SURFACE_EXTENSION_NAME",
    "VK_MVK_MACOS_SURFACE_SPEC_VERSION",
    "VK_MVK_MACOS_SURFACE_EXTENSION_NAME",
    "VK_MVK_MOLTENVK_SPEC_VERSION",
    "VK_MVK_MOLTENVK_EXTENSION_NAME",
    "VK_EXT_EXTERNAL_MEMORY_DMA_BUF_SPEC_VERSION",
    "VK_EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME",
    "VK_EXT_QUEUE_FAMILY_FOREIGN_SPEC_VERSION",
    "VK_EXT_QUEUE_FAMILY_FOREIGN_EXTENSION_NAME",
    "VK_KHR_DEDICATED_ALLOCATION_SPEC_VERSION",
    "VK_KHR_DEDICATED_ALLOCATION_EXTENSION_NAME",
    "VK_EXT_DEBUG_UTILS_SPEC_VERSION",
    "VK_EXT_DEBUG_UTILS_EXTENSION_NAME",
    "VK_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_SPEC_VERSION",
    "VK_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_EXTENSION_NAME",
    "VK_EXT_SAMPLER_FILTER_MINMAX_SPEC_VERSION",
    "VK_EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME",
    "VK_KHR_STORAGE_BUFFER_STORAGE_CLASS_SPEC_VERSION",
    "VK_KHR_STORAGE_BUFFER_STORAGE_CLASS_EXTENSION_NAME",
    "VK_AMD_GPU_SHADER_INT16_SPEC_VERSION",
    "VK_AMD_GPU_SHADER_INT16_EXTENSION_NAME",
    "VK_AMD_EXTENSION_134_SPEC_VERSION",
    "VK_AMD_EXTENSION_134_EXTENSION_NAME",
    "VK_AMDX_SHADER_ENQUEUE_SPEC_VERSION",
    "VK_AMDX_SHADER_ENQUEUE_EXTENSION_NAME",
    "VK_KHR_EXTENSION_136_SPEC_VERSION",
    "VK_KHR_EXTENSION_136_EXTENSION_NAME",
    "VK_AMD_MIXED_ATTACHMENT_SAMPLES_SPEC_VERSION",
    "VK_AMD_MIXED_ATTACHMENT_SAMPLES_EXTENSION_NAME",
    "VK_AMD_SHADER_FRAGMENT_MASK_SPEC_VERSION",
    "VK_AMD_SHADER_FRAGMENT_MASK_EXTENSION_NAME",
    "VK_EXT_INLINE_UNIFORM_BLOCK_SPEC_VERSION",
    "VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME",
    "VK_AMD_EXTENSION_140_SPEC_VERSION",
    "VK_AMD_EXTENSION_140_EXTENSION_NAME",
    "VK_EXT_SHADER_STENCIL_EXPORT_SPEC_VERSION",
    "VK_EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME",
    "VK_AMD_EXTENSION_142_SPEC_VERSION",
    "VK_AMD_EXTENSION_142_EXTENSION_NAME",
    "VK_AMD_EXTENSION_143_SPEC_VERSION",
    "VK_AMD_EXTENSION_143_EXTENSION_NAME",
    "VK_EXT_SAMPLE_LOCATIONS_SPEC_VERSION",
    "VK_EXT_SAMPLE_LOCATIONS_EXTENSION_NAME",
    "VK_KHR_RELAXED_BLOCK_LAYOUT_SPEC_VERSION",
    "VK_KHR_RELAXED_BLOCK_LAYOUT_EXTENSION_NAME",
    "VK_RESERVED_DO_NOT_USE_146_SPEC_VERSION",
    "VK_RESERVED_DO_NOT_USE_146_EXTENSION_NAME",
    "VK_KHR_GET_MEMORY_REQUIREMENTS_2_SPEC_VERSION",
    "VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME",
    "VK_KHR_IMAGE_FORMAT_LIST_SPEC_VERSION",
    "VK_KHR_IMAGE_FORMAT_LIST_EXTENSION_NAME",
    "VK_EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION",
    "VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME",
    "VK_NV_FRAGMENT_COVERAGE_TO_COLOR_SPEC_VERSION",
    "VK_NV_FRAGMENT_COVERAGE_TO_COLOR_EXTENSION_NAME",
    "VK_KHR_ACCELERATION_STRUCTURE_SPEC_VERSION",
    "VK_KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME",
    "VK_KHR_RAY_TRACING_PIPELINE_SPEC_VERSION",
    "VK_KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME",
    "VK_KHR_RAY_QUERY_SPEC_VERSION",
    "VK_KHR_RAY_QUERY_EXTENSION_NAME",
    "VK_NV_EXTENSION_152_SPEC_VERSION",
    "VK_NV_EXTENSION_152_EXTENSION_NAME",
    "VK_NV_FRAMEBUFFER_MIXED_SAMPLES_SPEC_VERSION",
    "VK_NV_FRAMEBUFFER_MIXED_SAMPLES_EXTENSION_NAME",
    "VK_NV_FILL_RECTANGLE_SPEC_VERSION",
    "VK_NV_FILL_RECTANGLE_EXTENSION_NAME",
    "VK_NV_SHADER_SM_BUILTINS_SPEC_VERSION",
    "VK_NV_SHADER_SM_BUILTINS_EXTENSION_NAME",
    "VK_EXT_POST_DEPTH_COVERAGE_SPEC_VERSION",
    "VK_EXT_POST_DEPTH_COVERAGE_EXTENSION_NAME",
    "VK_KHR_SAMPLER_YCBCR_CONVERSION_SPEC_VERSION",
    "VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME",
    "VK_KHR_BIND_MEMORY_2_SPEC_VERSION",
    "VK_KHR_BIND_MEMORY_2_EXTENSION_NAME",
    "VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_SPEC_VERSION",
    "VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME",
    "VK_EXT_EXTENSION_160_SPEC_VERSION",
    "VK_EXT_EXTENSION_160_EXTENSION_NAME",
    "VK_EXT_VALIDATION_CACHE_SPEC_VERSION",
    "VK_EXT_VALIDATION_CACHE_EXTENSION_NAME",
    "VK_EXT_DESCRIPTOR_INDEXING_SPEC_VERSION",
    "VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME",
    "VK_EXT_SHADER_VIEWPORT_INDEX_LAYER_SPEC_VERSION",
    "VK_EXT_SHADER_VIEWPORT_INDEX_LAYER_EXTENSION_NAME",
    "VK_KHR_PORTABILITY_SUBSET_SPEC_VERSION",
    "VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME",
    "VK_NV_SHADING_RATE_IMAGE_SPEC_VERSION",
    "VK_NV_SHADING_RATE_IMAGE_EXTENSION_NAME",
    "VK_NV_RAY_TRACING_SPEC_VERSION",
    "VK_NV_RAY_TRACING_EXTENSION_NAME",
    "VK_NV_REPRESENTATIVE_FRAGMENT_TEST_SPEC_VERSION",
    "VK_NV_REPRESENTATIVE_FRAGMENT_TEST_EXTENSION_NAME",
    "VK_NV_EXTENSION_168_SPEC_VERSION",
    "VK_NV_EXTENSION_168_EXTENSION_NAME",
    "VK_KHR_MAINTENANCE_3_SPEC_VERSION",
    "VK_KHR_MAINTENANCE_3_EXTENSION_NAME",
    "VK_KHR_MAINTENANCE3_SPEC_VERSION",
    "VK_KHR_MAINTENANCE3_EXTENSION_NAME",
    "VK_KHR_DRAW_INDIRECT_COUNT_SPEC_VERSION",
    "VK_KHR_DRAW_INDIRECT_COUNT_EXTENSION_NAME",
    "VK_EXT_FILTER_CUBIC_SPEC_VERSION",
    "VK_EXT_FILTER_CUBIC_EXTENSION_NAME",
    "VK_QCOM_RENDER_PASS_SHADER_RESOLVE_SPEC_VERSION",
    "VK_QCOM_RENDER_PASS_SHADER_RESOLVE_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_173_SPEC_VERSION",
    "VK_QCOM_EXTENSION_173_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_174_SPEC_VERSION",
    "VK_QCOM_EXTENSION_174_EXTENSION_NAME",
    "VK_EXT_GLOBAL_PRIORITY_SPEC_VERSION",
    "VK_EXT_GLOBAL_PRIORITY_EXTENSION_NAME",
    "VK_KHR_SHADER_SUBGROUP_EXTENDED_TYPES_SPEC_VERSION",
    "VK_KHR_SHADER_SUBGROUP_EXTENDED_TYPES_EXTENSION_NAME",
    "VK_EXT_EXTENSION_177_SPEC_VERSION",
    "VK_EXT_EXTENSION_177_EXTENSION_NAME",
    "VK_KHR_8BIT_STORAGE_SPEC_VERSION",
    "VK_KHR_8BIT_STORAGE_EXTENSION_NAME",
    "VK_EXT_EXTERNAL_MEMORY_HOST_SPEC_VERSION",
    "VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME",
    "VK_AMD_BUFFER_MARKER_SPEC_VERSION",
    "VK_AMD_BUFFER_MARKER_EXTENSION_NAME",
    "VK_KHR_SHADER_ATOMIC_INT64_SPEC_VERSION",
    "VK_KHR_SHADER_ATOMIC_INT64_EXTENSION_NAME",
    "VK_KHR_SHADER_CLOCK_SPEC_VERSION",
    "VK_KHR_SHADER_CLOCK_EXTENSION_NAME",
    "VK_AMD_EXTENSION_183_SPEC_VERSION",
    "VK_AMD_EXTENSION_183_EXTENSION_NAME",
    "VK_AMD_PIPELINE_COMPILER_CONTROL_SPEC_VERSION",
    "VK_AMD_PIPELINE_COMPILER_CONTROL_EXTENSION_NAME",
    "VK_EXT_CALIBRATED_TIMESTAMPS_SPEC_VERSION",
    "VK_EXT_CALIBRATED_TIMESTAMPS_EXTENSION_NAME",
    "VK_AMD_SHADER_CORE_PROPERTIES_SPEC_VERSION",
    "VK_AMD_SHADER_CORE_PROPERTIES_EXTENSION_NAME",
    "VK_AMD_EXTENSION_187_SPEC_VERSION",
    "VK_AMD_EXTENSION_187_EXTENSION_NAME",
    "VK_KHR_VIDEO_DECODE_H265_SPEC_VERSION",
    "VK_KHR_VIDEO_DECODE_H265_EXTENSION_NAME",
    "VK_KHR_GLOBAL_PRIORITY_SPEC_VERSION",
    "VK_KHR_GLOBAL_PRIORITY_EXTENSION_NAME",
    "VK_AMD_MEMORY_OVERALLOCATION_BEHAVIOR_SPEC_VERSION",
    "VK_AMD_MEMORY_OVERALLOCATION_BEHAVIOR_EXTENSION_NAME",
    "VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION",
    "VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME",
    "VK_GGP_FRAME_TOKEN_SPEC_VERSION",
    "VK_GGP_FRAME_TOKEN_EXTENSION_NAME",
    "VK_EXT_PIPELINE_CREATION_FEEDBACK_SPEC_VERSION",
    "VK_EXT_PIPELINE_CREATION_FEEDBACK_EXTENSION_NAME",
    "VK_GOOGLE_EXTENSION_194_SPEC_VERSION",
    "VK_GOOGLE_EXTENSION_194_EXTENSION_NAME",
    "VK_GOOGLE_EXTENSION_195_SPEC_VERSION",
    "VK_GOOGLE_EXTENSION_195_EXTENSION_NAME",
    "VK_GOOGLE_EXTENSION_196_SPEC_VERSION",
    "VK_GOOGLE_EXTENSION_196_EXTENSION_NAME",
    "VK_KHR_DRIVER_PROPERTIES_SPEC_VERSION",
    "VK_KHR_DRIVER_PROPERTIES_EXTENSION_NAME",
    "VK_KHR_SHADER_FLOAT_CONTROLS_SPEC_VERSION",
    "VK_KHR_SHADER_FLOAT_CONTROLS_EXTENSION_NAME",
    "VK_NV_SHADER_SUBGROUP_PARTITIONED_SPEC_VERSION",
    "VK_NV_SHADER_SUBGROUP_PARTITIONED_EXTENSION_NAME",
    "VK_KHR_DEPTH_STENCIL_RESOLVE_SPEC_VERSION",
    "VK_KHR_DEPTH_STENCIL_RESOLVE_EXTENSION_NAME",
    "VK_KHR_SWAPCHAIN_MUTABLE_FORMAT_SPEC_VERSION",
    "VK_KHR_SWAPCHAIN_MUTABLE_FORMAT_EXTENSION_NAME",
    "VK_NV_COMPUTE_SHADER_DERIVATIVES_SPEC_VERSION",
    "VK_NV_COMPUTE_SHADER_DERIVATIVES_EXTENSION_NAME",
    "VK_NV_MESH_SHADER_SPEC_VERSION",
    "VK_NV_MESH_SHADER_EXTENSION_NAME",
    "VK_NV_FRAGMENT_SHADER_BARYCENTRIC_SPEC_VERSION",
    "VK_NV_FRAGMENT_SHADER_BARYCENTRIC_EXTENSION_NAME",
    "VK_NV_SHADER_IMAGE_FOOTPRINT_SPEC_VERSION",
    "VK_NV_SHADER_IMAGE_FOOTPRINT_EXTENSION_NAME",
    "VK_NV_SCISSOR_EXCLUSIVE_SPEC_VERSION",
    "VK_NV_SCISSOR_EXCLUSIVE_EXTENSION_NAME",
    "VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_SPEC_VERSION",
    "VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME",
    "VK_KHR_TIMELINE_SEMAPHORE_SPEC_VERSION",
    "VK_KHR_TIMELINE_SEMAPHORE_EXTENSION_NAME",
    "VK_KHR_EXTENSION_209_SPEC_VERSION",
    "VK_KHR_EXTENSION_209_EXTENSION_NAME",
    "VK_INTEL_SHADER_INTEGER_FUNCTIONS_2_SPEC_VERSION",
    "VK_INTEL_SHADER_INTEGER_FUNCTIONS_2_EXTENSION_NAME",
    "VK_INTEL_PERFORMANCE_QUERY_SPEC_VERSION",
    "VK_INTEL_PERFORMANCE_QUERY_EXTENSION_NAME",
    "VK_KHR_VULKAN_MEMORY_MODEL_SPEC_VERSION",
    "VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME",
    "VK_EXT_PCI_BUS_INFO_SPEC_VERSION",
    "VK_EXT_PCI_BUS_INFO_EXTENSION_NAME",
    "VK_AMD_DISPLAY_NATIVE_HDR_SPEC_VERSION",
    "VK_AMD_DISPLAY_NATIVE_HDR_EXTENSION_NAME",
    "VK_FUCHSIA_IMAGEPIPE_SURFACE_SPEC_VERSION",
    "VK_FUCHSIA_IMAGEPIPE_SURFACE_EXTENSION_NAME",
    "VK_KHR_SHADER_TERMINATE_INVOCATION_SPEC_VERSION",
    "VK_KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME",
    "VK_GOOGLE_EXTENSION_217_SPEC_VERSION",
    "VK_GOOGLE_EXTENSION_217_EXTENSION_NAME",
    "VK_EXT_METAL_SURFACE_SPEC_VERSION",
    "VK_EXT_METAL_SURFACE_EXTENSION_NAME",
    "VK_EXT_FRAGMENT_DENSITY_MAP_SPEC_VERSION",
    "VK_EXT_FRAGMENT_DENSITY_MAP_EXTENSION_NAME",
    "VK_EXT_EXTENSION_220_SPEC_VERSION",
    "VK_EXT_EXTENSION_220_EXTENSION_NAME",
    "VK_KHR_EXTENSION_221_SPEC_VERSION",
    "VK_KHR_EXTENSION_221_EXTENSION_NAME",
    "VK_EXT_SCALAR_BLOCK_LAYOUT_SPEC_VERSION",
    "VK_EXT_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME",
    "VK_EXT_EXTENSION_223_SPEC_VERSION",
    "VK_EXT_EXTENSION_223_EXTENSION_NAME",
    "VK_GOOGLE_HLSL_FUNCTIONALITY_1_SPEC_VERSION",
    "VK_GOOGLE_HLSL_FUNCTIONALITY_1_EXTENSION_NAME",
    "VK_GOOGLE_HLSL_FUNCTIONALITY1_SPEC_VERSION",
    "VK_GOOGLE_HLSL_FUNCTIONALITY1_EXTENSION_NAME",
    "VK_GOOGLE_DECORATE_STRING_SPEC_VERSION",
    "VK_GOOGLE_DECORATE_STRING_EXTENSION_NAME",
    "VK_EXT_SUBGROUP_SIZE_CONTROL_SPEC_VERSION",
    "VK_EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME",
    "VK_KHR_FRAGMENT_SHADING_RATE_SPEC_VERSION",
    "VK_KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME",
    "VK_AMD_SHADER_CORE_PROPERTIES_2_SPEC_VERSION",
    "VK_AMD_SHADER_CORE_PROPERTIES_2_EXTENSION_NAME",
    "VK_AMD_EXTENSION_229_SPEC_VERSION",
    "VK_AMD_EXTENSION_229_EXTENSION_NAME",
    "VK_AMD_DEVICE_COHERENT_MEMORY_SPEC_VERSION",
    "VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME",
    "VK_AMD_EXTENSION_231_SPEC_VERSION",
    "VK_AMD_EXTENSION_231_EXTENSION_NAME",
    "VK_AMD_EXTENSION_232_SPEC_VERSION",
    "VK_AMD_EXTENSION_232_EXTENSION_NAME",
    "VK_AMD_EXTENSION_233_SPEC_VERSION",
    "VK_AMD_EXTENSION_233_EXTENSION_NAME",
    "VK_AMD_EXTENSION_234_SPEC_VERSION",
    "VK_AMD_EXTENSION_234_EXTENSION_NAME",
    "VK_EXT_SHADER_IMAGE_ATOMIC_INT64_SPEC_VERSION",
    "VK_EXT_SHADER_IMAGE_ATOMIC_INT64_EXTENSION_NAME",
    "VK_AMD_EXTENSION_236_SPEC_VERSION",
    "VK_AMD_EXTENSION_236_EXTENSION_NAME",
    "VK_KHR_SPIRV_1_4_SPEC_VERSION",
    "VK_KHR_SPIRV_1_4_EXTENSION_NAME",
    "VK_EXT_MEMORY_BUDGET_SPEC_VERSION",
    "VK_EXT_MEMORY_BUDGET_EXTENSION_NAME",
    "VK_EXT_MEMORY_PRIORITY_SPEC_VERSION",
    "VK_EXT_MEMORY_PRIORITY_EXTENSION_NAME",
    "VK_KHR_SURFACE_PROTECTED_CAPABILITIES_SPEC_VERSION",
    "VK_KHR_SURFACE_PROTECTED_CAPABILITIES_EXTENSION_NAME",
    "VK_NV_DEDICATED_ALLOCATION_IMAGE_ALIASING_SPEC_VERSION",
    "VK_NV_DEDICATED_ALLOCATION_IMAGE_ALIASING_EXTENSION_NAME",
    "VK_KHR_SEPARATE_DEPTH_STENCIL_LAYOUTS_SPEC_VERSION",
    "VK_KHR_SEPARATE_DEPTH_STENCIL_LAYOUTS_EXTENSION_NAME",
    "VK_INTEL_EXTENSION_243_SPEC_VERSION",
    "VK_INTEL_EXTENSION_243_EXTENSION_NAME",
    "VK_MESA_EXTENSION_244_SPEC_VERSION",
    "VK_MESA_EXTENSION_244_EXTENSION_NAME",
    "VK_EXT_BUFFER_DEVICE_ADDRESS_SPEC_VERSION",
    "VK_EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME",
    "VK_EXT_TOOLING_INFO_SPEC_VERSION",
    "VK_EXT_TOOLING_INFO_EXTENSION_NAME",
    "VK_EXT_SEPARATE_STENCIL_USAGE_SPEC_VERSION",
    "VK_EXT_SEPARATE_STENCIL_USAGE_EXTENSION_NAME",
    "VK_EXT_VALIDATION_FEATURES_SPEC_VERSION",
    "VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME",
    "VK_KHR_PRESENT_WAIT_SPEC_VERSION",
    "VK_KHR_PRESENT_WAIT_EXTENSION_NAME",
    "VK_NV_COOPERATIVE_MATRIX_SPEC_VERSION",
    "VK_NV_COOPERATIVE_MATRIX_EXTENSION_NAME",
    "VK_NV_COVERAGE_REDUCTION_MODE_SPEC_VERSION",
    "VK_NV_COVERAGE_REDUCTION_MODE_EXTENSION_NAME",
    "VK_EXT_FRAGMENT_SHADER_INTERLOCK_SPEC_VERSION",
    "VK_EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME",
    "VK_EXT_YCBCR_IMAGE_ARRAYS_SPEC_VERSION",
    "VK_EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME",
    "VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_SPEC_VERSION",
    "VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME",
    "VK_EXT_PROVOKING_VERTEX_SPEC_VERSION",
    "VK_EXT_PROVOKING_VERTEX_EXTENSION_NAME",
    "VK_EXT_FULL_SCREEN_EXCLUSIVE_SPEC_VERSION",
    "VK_EXT_FULL_SCREEN_EXCLUSIVE_EXTENSION_NAME",
    "VK_EXT_HEADLESS_SURFACE_SPEC_VERSION",
    "VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME",
    "VK_KHR_BUFFER_DEVICE_ADDRESS_SPEC_VERSION",
    "VK_KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME",
    "VK_EXT_EXTENSION_259_SPEC_VERSION",
    "VK_EXT_EXTENSION_259_EXTENSION_NAME",
    "VK_EXT_LINE_RASTERIZATION_SPEC_VERSION",
    "VK_EXT_LINE_RASTERIZATION_EXTENSION_NAME",
    "VK_EXT_SHADER_ATOMIC_FLOAT_SPEC_VERSION",
    "VK_EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME",
    "VK_EXT_HOST_QUERY_RESET_SPEC_VERSION",
    "VK_EXT_HOST_QUERY_RESET_EXTENSION_NAME",
    "VK_GGP_EXTENSION_263_SPEC_VERSION",
    "VK_GGP_EXTENSION_263_EXTENSION_NAME",
    "VK_BRCM_EXTENSION_264_SPEC_VERSION",
    "VK_BRCM_EXTENSION_264_EXTENSION_NAME",
    "VK_BRCM_EXTENSION_265_SPEC_VERSION",
    "VK_BRCM_EXTENSION_265_EXTENSION_NAME",
    "VK_EXT_INDEX_TYPE_UINT8_SPEC_VERSION",
    "VK_EXT_INDEX_TYPE_UINT8_EXTENSION_NAME",
    "VK_EXT_EXTENSION_267_SPEC_VERSION",
    "VK_EXT_EXTENSION_267_EXTENSION_NAME",
    "VK_EXT_EXTENDED_DYNAMIC_STATE_SPEC_VERSION",
    "VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME",
    "VK_KHR_DEFERRED_HOST_OPERATIONS_SPEC_VERSION",
    "VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME",
    "VK_KHR_PIPELINE_EXECUTABLE_PROPERTIES_SPEC_VERSION",
    "VK_KHR_PIPELINE_EXECUTABLE_PROPERTIES_EXTENSION_NAME",
    "VK_EXT_HOST_IMAGE_COPY_SPEC_VERSION",
    "VK_EXT_HOST_IMAGE_COPY_EXTENSION_NAME",
    "VK_KHR_MAP_MEMORY_2_SPEC_VERSION",
    "VK_KHR_MAP_MEMORY_2_EXTENSION_NAME",
    "VK_INTEL_EXTENSION_273_SPEC_VERSION",
    "VK_INTEL_EXTENSION_273_EXTENSION_NAME",
    "VK_EXT_SHADER_ATOMIC_FLOAT_2_SPEC_VERSION",
    "VK_EXT_SHADER_ATOMIC_FLOAT_2_EXTENSION_NAME",
    "VK_EXT_SURFACE_MAINTENANCE_1_SPEC_VERSION",
    "VK_EXT_SURFACE_MAINTENANCE_1_EXTENSION_NAME",
    "VK_EXT_SWAPCHAIN_MAINTENANCE_1_SPEC_VERSION",
    "VK_EXT_SWAPCHAIN_MAINTENANCE_1_EXTENSION_NAME",
    "VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_SPEC_VERSION",
    "VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME",
    "VK_NV_DEVICE_GENERATED_COMMANDS_SPEC_VERSION",
    "VK_NV_DEVICE_GENERATED_COMMANDS_EXTENSION_NAME",
    "VK_NV_INHERITED_VIEWPORT_SCISSOR_SPEC_VERSION",
    "VK_NV_INHERITED_VIEWPORT_SCISSOR_EXTENSION_NAME",
    "VK_KHR_EXTENSION_280_SPEC_VERSION",
    "VK_KHR_EXTENSION_280_EXTENSION_NAME",
    "VK_KHR_SHADER_INTEGER_DOT_PRODUCT_SPEC_VERSION",
    "VK_KHR_SHADER_INTEGER_DOT_PRODUCT_EXTENSION_NAME",
    "VK_EXT_TEXEL_BUFFER_ALIGNMENT_SPEC_VERSION",
    "VK_EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME",
    "VK_QCOM_RENDER_PASS_TRANSFORM_SPEC_VERSION",
    "VK_QCOM_RENDER_PASS_TRANSFORM_EXTENSION_NAME",
    "VK_EXT_DEPTH_BIAS_CONTROL_SPEC_VERSION",
    "VK_EXT_DEPTH_BIAS_CONTROL_EXTENSION_NAME",
    "VK_EXT_DEVICE_MEMORY_REPORT_SPEC_VERSION",
    "VK_EXT_DEVICE_MEMORY_REPORT_EXTENSION_NAME",
    "VK_EXT_ACQUIRE_DRM_DISPLAY_SPEC_VERSION",
    "VK_EXT_ACQUIRE_DRM_DISPLAY_EXTENSION_NAME",
    "VK_EXT_ROBUSTNESS_2_SPEC_VERSION",
    "VK_EXT_ROBUSTNESS_2_EXTENSION_NAME",
    "VK_EXT_CUSTOM_BORDER_COLOR_SPEC_VERSION",
    "VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME",
    "VK_EXT_EXTENSION_289_SPEC_VERSION",
    "VK_EXT_EXTENSION_289_EXTENSION_NAME",
    "VK_GOOGLE_USER_TYPE_SPEC_VERSION",
    "VK_GOOGLE_USER_TYPE_EXTENSION_NAME",
    "VK_KHR_PIPELINE_LIBRARY_SPEC_VERSION",
    "VK_KHR_PIPELINE_LIBRARY_EXTENSION_NAME",
    "VK_NV_EXTENSION_292_SPEC_VERSION",
    "VK_NV_EXTENSION_292_EXTENSION_NAME",
    "VK_NV_PRESENT_BARRIER_SPEC_VERSION",
    "VK_NV_PRESENT_BARRIER_EXTENSION_NAME",
    "VK_KHR_SHADER_NON_SEMANTIC_INFO_SPEC_VERSION",
    "VK_KHR_SHADER_NON_SEMANTIC_INFO_EXTENSION_NAME",
    "VK_KHR_PRESENT_ID_SPEC_VERSION",
    "VK_KHR_PRESENT_ID_EXTENSION_NAME",
    "VK_EXT_PRIVATE_DATA_SPEC_VERSION",
    "VK_EXT_PRIVATE_DATA_EXTENSION_NAME",
    "VK_KHR_EXTENSION_297_SPEC_VERSION",
    "VK_KHR_EXTENSION_297_EXTENSION_NAME",
    "VK_EXT_PIPELINE_CREATION_CACHE_CONTROL_SPEC_VERSION",
    "VK_EXT_PIPELINE_CREATION_CACHE_CONTROL_EXTENSION_NAME",
    "VK_KHR_EXTENSION_299_SPEC_VERSION",
    "VK_KHR_EXTENSION_299_EXTENSION_NAME",
    "VK_KHR_VIDEO_ENCODE_QUEUE_SPEC_VERSION",
    "VK_KHR_VIDEO_ENCODE_QUEUE_EXTENSION_NAME",
    "VK_NV_DEVICE_DIAGNOSTICS_CONFIG_SPEC_VERSION",
    "VK_NV_DEVICE_DIAGNOSTICS_CONFIG_EXTENSION_NAME",
    "VK_QCOM_RENDER_PASS_STORE_OPS_SPEC_VERSION",
    "VK_QCOM_RENDER_PASS_STORE_OPS_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_303_SPEC_VERSION",
    "VK_QCOM_EXTENSION_303_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_304_SPEC_VERSION",
    "VK_QCOM_EXTENSION_304_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_305_SPEC_VERSION",
    "VK_QCOM_EXTENSION_305_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_306_SPEC_VERSION",
    "VK_QCOM_EXTENSION_306_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_307_SPEC_VERSION",
    "VK_QCOM_EXTENSION_307_EXTENSION_NAME",
    "VK_NV_CUDA_KERNEL_LAUNCH_SPEC_VERSION",
    "VK_NV_CUDA_KERNEL_LAUNCH_EXTENSION_NAME",
    "VK_KHR_OBJECT_REFRESH_SPEC_VERSION",
    "VK_KHR_OBJECT_REFRESH_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_310_SPEC_VERSION",
    "VK_QCOM_EXTENSION_310_EXTENSION_NAME",
    "VK_NV_LOW_LATENCY_SPEC_VERSION",
    "VK_NV_LOW_LATENCY_EXTENSION_NAME",
    "VK_EXT_METAL_OBJECTS_SPEC_VERSION",
    "VK_EXT_METAL_OBJECTS_EXTENSION_NAME",
    "VK_EXT_EXTENSION_313_SPEC_VERSION",
    "VK_EXT_EXTENSION_313_EXTENSION_NAME",
    "VK_AMD_EXTENSION_314_SPEC_VERSION",
    "VK_AMD_EXTENSION_314_EXTENSION_NAME",
    "VK_KHR_SYNCHRONIZATION_2_SPEC_VERSION",
    "VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME",
    "VK_AMD_EXTENSION_316_SPEC_VERSION",
    "VK_AMD_EXTENSION_316_EXTENSION_NAME",
    "VK_EXT_DESCRIPTOR_BUFFER_SPEC_VERSION",
    "VK_EXT_DESCRIPTOR_BUFFER_EXTENSION_NAME",
    "VK_AMD_EXTENSION_318_SPEC_VERSION",
    "VK_AMD_EXTENSION_318_EXTENSION_NAME",
    "VK_AMD_EXTENSION_319_SPEC_VERSION",
    "VK_AMD_EXTENSION_319_EXTENSION_NAME",
    "VK_AMD_EXTENSION_320_SPEC_VERSION",
    "VK_AMD_EXTENSION_320_EXTENSION_NAME",
    "VK_EXT_GRAPHICS_PIPELINE_LIBRARY_SPEC_VERSION",
    "VK_EXT_GRAPHICS_PIPELINE_LIBRARY_EXTENSION_NAME",
    "VK_AMD_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_SPEC_VERSION",
    "VK_AMD_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_EXTENSION_NAME",
    "VK_KHR_FRAGMENT_SHADER_BARYCENTRIC_SPEC_VERSION",
    "VK_KHR_FRAGMENT_SHADER_BARYCENTRIC_EXTENSION_NAME",
    "VK_KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_SPEC_VERSION",
    "VK_KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_EXTENSION_NAME",
    "VK_KHR_EXTENSION_325_SPEC_VERSION",
    "VK_KHR_EXTENSION_325_EXTENSION_NAME",
    "VK_KHR_ZERO_INITIALIZE_WORKGROUP_MEMORY_SPEC_VERSION",
    "VK_KHR_ZERO_INITIALIZE_WORKGROUP_MEMORY_EXTENSION_NAME",
    "VK_NV_FRAGMENT_SHADING_RATE_ENUMS_SPEC_VERSION",
    "VK_NV_FRAGMENT_SHADING_RATE_ENUMS_EXTENSION_NAME",
    "VK_NV_RAY_TRACING_MOTION_BLUR_SPEC_VERSION",
    "VK_NV_RAY_TRACING_MOTION_BLUR_EXTENSION_NAME",
    "VK_EXT_MESH_SHADER_SPEC_VERSION",
    "VK_EXT_MESH_SHADER_EXTENSION_NAME",
    "VK_NV_EXTENSION_330_SPEC_VERSION",
    "VK_NV_EXTENSION_330_EXTENSION_NAME",
    "VK_EXT_YCBCR_2PLANE_444_FORMATS_SPEC_VERSION",
    "VK_EXT_YCBCR_2PLANE_444_FORMATS_EXTENSION_NAME",
    "VK_NV_EXTENSION_332_SPEC_VERSION",
    "VK_NV_EXTENSION_332_EXTENSION_NAME",
    "VK_EXT_FRAGMENT_DENSITY_MAP_2_SPEC_VERSION",
    "VK_EXT_FRAGMENT_DENSITY_MAP_2_EXTENSION_NAME",
    "VK_QCOM_ROTATED_COPY_COMMANDS_SPEC_VERSION",
    "VK_QCOM_ROTATED_COPY_COMMANDS_EXTENSION_NAME",
    "VK_KHR_EXTENSION_335_SPEC_VERSION",
    "VK_KHR_EXTENSION_335_EXTENSION_NAME",
    "VK_EXT_IMAGE_ROBUSTNESS_SPEC_VERSION",
    "VK_EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME",
    "VK_KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_SPEC_VERSION",
    "VK_KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_EXTENSION_NAME",
    "VK_KHR_COPY_COMMANDS_2_SPEC_VERSION",
    "VK_KHR_COPY_COMMANDS_2_EXTENSION_NAME",
    "VK_EXT_IMAGE_COMPRESSION_CONTROL_SPEC_VERSION",
    "VK_EXT_IMAGE_COMPRESSION_CONTROL_EXTENSION_NAME",
    "VK_EXT_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_SPEC_VERSION",
    "VK_EXT_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_EXTENSION_NAME",
    "VK_EXT_4444_FORMATS_SPEC_VERSION",
    "VK_EXT_4444_FORMATS_EXTENSION_NAME",
    "VK_EXT_DEVICE_FAULT_SPEC_VERSION",
    "VK_EXT_DEVICE_FAULT_EXTENSION_NAME",
    "VK_ARM_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_SPEC_VERSION",
    "VK_ARM_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXTENSION_NAME",
    "VK_ARM_EXTENSION_344_SPEC_VERSION",
    "VK_ARM_EXTENSION_344_EXTENSION_NAME",
    "VK_EXT_RGBA10X6_FORMATS_SPEC_VERSION",
    "VK_EXT_RGBA10X6_FORMATS_EXTENSION_NAME",
    "VK_NV_ACQUIRE_WINRT_DISPLAY_SPEC_VERSION",
    "VK_NV_ACQUIRE_WINRT_DISPLAY_EXTENSION_NAME",
    "VK_EXT_DIRECTFB_SURFACE_SPEC_VERSION",
    "VK_EXT_DIRECTFB_SURFACE_EXTENSION_NAME",
    "VK_KHR_EXTENSION_350_SPEC_VERSION",
    "VK_KHR_EXTENSION_350_EXTENSION_NAME",
    "VK_NV_EXTENSION_351_SPEC_VERSION",
    "VK_NV_EXTENSION_351_EXTENSION_NAME",
    "VK_VALVE_MUTABLE_DESCRIPTOR_TYPE_SPEC_VERSION",
    "VK_VALVE_MUTABLE_DESCRIPTOR_TYPE_EXTENSION_NAME",
    "VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_SPEC_VERSION",
    "VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME",
    "VK_EXT_PHYSICAL_DEVICE_DRM_SPEC_VERSION",
    "VK_EXT_PHYSICAL_DEVICE_DRM_EXTENSION_NAME",
    "VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_SPEC_VERSION",
    "VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME",
    "VK_EXT_DEPTH_CLIP_CONTROL_SPEC_VERSION",
    "VK_EXT_DEPTH_CLIP_CONTROL_EXTENSION_NAME",
    "VK_EXT_PRIMITIVE_TOPOLOGY_LIST_RESTART_SPEC_VERSION",
    "VK_EXT_PRIMITIVE_TOPOLOGY_LIST_RESTART_EXTENSION_NAME",
    "VK_KHR_EXTENSION_358_SPEC_VERSION",
    "VK_KHR_EXTENSION_358_EXTENSION_NAME",
    "VK_EXT_EXTENSION_359_SPEC_VERSION",
    "VK_EXT_EXTENSION_359_EXTENSION_NAME",
    "VK_EXT_EXTENSION_360_SPEC_VERSION",
    "VK_EXT_EXTENSION_360_EXTENSION_NAME",
    "VK_KHR_FORMAT_FEATURE_FLAGS_2_SPEC_VERSION",
    "VK_KHR_FORMAT_FEATURE_FLAGS_2_EXTENSION_NAME",
    "VK_EXT_EXTENSION_362_SPEC_VERSION",
    "VK_EXT_EXTENSION_362_EXTENSION_NAME",
    "VK_EXT_EXTENSION_363_SPEC_VERSION",
    "VK_EXT_EXTENSION_363_EXTENSION_NAME",
    "VK_FUCHSIA_EXTENSION_364_SPEC_VERSION",
    "VK_FUCHSIA_EXTENSION_364_EXTENSION_NAME",
    "VK_FUCHSIA_EXTERNAL_MEMORY_SPEC_VERSION",
    "VK_FUCHSIA_EXTERNAL_MEMORY_EXTENSION_NAME",
    "VK_FUCHSIA_EXTERNAL_SEMAPHORE_SPEC_VERSION",
    "VK_FUCHSIA_EXTERNAL_SEMAPHORE_EXTENSION_NAME",
    "VK_FUCHSIA_BUFFER_COLLECTION_SPEC_VERSION",
    "VK_FUCHSIA_BUFFER_COLLECTION_EXTENSION_NAME",
    "VK_FUCHSIA_EXTENSION_368_SPEC_VERSION",
    "VK_FUCHSIA_EXTENSION_368_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_369_SPEC_VERSION",
    "VK_QCOM_EXTENSION_369_EXTENSION_NAME",
    "VK_HUAWEI_SUBPASS_SHADING_SPEC_VERSION",
    "VK_HUAWEI_SUBPASS_SHADING_EXTENSION_NAME",
    "VK_HUAWEI_INVOCATION_MASK_SPEC_VERSION",
    "VK_HUAWEI_INVOCATION_MASK_EXTENSION_NAME",
    "VK_NV_EXTERNAL_MEMORY_RDMA_SPEC_VERSION",
    "VK_NV_EXTERNAL_MEMORY_RDMA_EXTENSION_NAME",
    "VK_EXT_PIPELINE_PROPERTIES_SPEC_VERSION",
    "VK_EXT_PIPELINE_PROPERTIES_EXTENSION_NAME",
    "VK_NV_EXTERNAL_SCI_SYNC_SPEC_VERSION",
    "VK_NV_EXTERNAL_SCI_SYNC_EXTENSION_NAME",
    "VK_NV_EXTERNAL_MEMORY_SCI_BUF_SPEC_VERSION",
    "VK_NV_EXTERNAL_MEMORY_SCI_BUF_EXTENSION_NAME",
    "VK_EXT_FRAME_BOUNDARY_SPEC_VERSION",
    "VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME",
    "VK_EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_SPEC_VERSION",
    "VK_EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_EXTENSION_NAME",
    "VK_EXT_EXTENDED_DYNAMIC_STATE_2_SPEC_VERSION",
    "VK_EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME",
    "VK_QNX_SCREEN_SURFACE_SPEC_VERSION",
    "VK_QNX_SCREEN_SURFACE_EXTENSION_NAME",
    "VK_KHR_EXTENSION_380_SPEC_VERSION",
    "VK_KHR_EXTENSION_380_EXTENSION_NAME",
    "VK_KHR_EXTENSION_381_SPEC_VERSION",
    "VK_KHR_EXTENSION_381_EXTENSION_NAME",
    "VK_EXT_COLOR_WRITE_ENABLE_SPEC_VERSION",
    "VK_EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME",
    "VK_EXT_PRIMITIVES_GENERATED_QUERY_SPEC_VERSION",
    "VK_EXT_PRIMITIVES_GENERATED_QUERY_EXTENSION_NAME",
    "VK_EXT_EXTENSION_384_SPEC_VERSION",
    "VK_EXT_EXTENSION_384_EXTENSION_NAME",
    "VK_MESA_EXTENSION_385_SPEC_VERSION",
    "VK_MESA_EXTENSION_385_EXTENSION_NAME",
    "VK_GOOGLE_EXTENSION_386_SPEC_VERSION",
    "VK_GOOGLE_EXTENSION_386_EXTENSION_NAME",
    "VK_KHR_RAY_TRACING_MAINTENANCE_1_SPEC_VERSION",
    "VK_KHR_RAY_TRACING_MAINTENANCE_1_EXTENSION_NAME",
    "VK_EXT_EXTENSION_388_SPEC_VERSION",
    "VK_EXT_EXTENSION_388_EXTENSION_NAME",
    "VK_EXT_GLOBAL_PRIORITY_QUERY_SPEC_VERSION",
    "VK_EXT_GLOBAL_PRIORITY_QUERY_EXTENSION_NAME",
    "VK_EXT_EXTENSION_390_SPEC_VERSION",
    "VK_EXT_EXTENSION_390_EXTENSION_NAME",
    "VK_EXT_EXTENSION_391_SPEC_VERSION",
    "VK_EXT_EXTENSION_391_EXTENSION_NAME",
    "VK_EXT_IMAGE_VIEW_MIN_LOD_SPEC_VERSION",
    "VK_EXT_IMAGE_VIEW_MIN_LOD_EXTENSION_NAME",
    "VK_EXT_MULTI_DRAW_SPEC_VERSION",
    "VK_EXT_MULTI_DRAW_EXTENSION_NAME",
    "VK_EXT_IMAGE_2D_VIEW_OF_3D_SPEC_VERSION",
    "VK_EXT_IMAGE_2D_VIEW_OF_3D_EXTENSION_NAME",
    "VK_KHR_PORTABILITY_ENUMERATION_SPEC_VERSION",
    "VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME",
    "VK_EXT_SHADER_TILE_IMAGE_SPEC_VERSION",
    "VK_EXT_SHADER_TILE_IMAGE_EXTENSION_NAME",
    "VK_EXT_OPACITY_MICROMAP_SPEC_VERSION",
    "VK_EXT_OPACITY_MICROMAP_EXTENSION_NAME",
    "VK_NV_DISPLACEMENT_MICROMAP_SPEC_VERSION",
    "VK_NV_DISPLACEMENT_MICROMAP_EXTENSION_NAME",
    "VK_JUICE_EXTENSION_399_SPEC_VERSION",
    "VK_JUICE_EXTENSION_399_EXTENSION_NAME",
    "VK_JUICE_EXTENSION_400_SPEC_VERSION",
    "VK_JUICE_EXTENSION_400_EXTENSION_NAME",
    "VK_EXT_LOAD_STORE_OP_NONE_SPEC_VERSION",
    "VK_EXT_LOAD_STORE_OP_NONE_EXTENSION_NAME",
    "VK_FB_EXTENSION_402_SPEC_VERSION",
    "VK_FB_EXTENSION_402_EXTENSION_NAME",
    "VK_FB_EXTENSION_403_SPEC_VERSION",
    "VK_FB_EXTENSION_403_EXTENSION_NAME",
    "VK_FB_EXTENSION_404_SPEC_VERSION",
    "VK_FB_EXTENSION_404_EXTENSION_NAME",
    "VK_HUAWEI_CLUSTER_CULLING_SHADER_SPEC_VERSION",
    "VK_HUAWEI_CLUSTER_CULLING_SHADER_EXTENSION_NAME",
    "VK_HUAWEI_EXTENSION_406_SPEC_VERSION",
    "VK_HUAWEI_EXTENSION_406_EXTENSION_NAME",
    "VK_GGP_EXTENSION_407_SPEC_VERSION",
    "VK_GGP_EXTENSION_407_EXTENSION_NAME",
    "VK_GGP_EXTENSION_408_SPEC_VERSION",
    "VK_GGP_EXTENSION_408_EXTENSION_NAME",
    "VK_GGP_EXTENSION_409_SPEC_VERSION",
    "VK_GGP_EXTENSION_409_EXTENSION_NAME",
    "VK_GGP_EXTENSION_410_SPEC_VERSION",
    "VK_GGP_EXTENSION_410_EXTENSION_NAME",
    "VK_GGP_EXTENSION_411_SPEC_VERSION",
    "VK_GGP_EXTENSION_411_EXTENSION_NAME",
    "VK_EXT_BORDER_COLOR_SWIZZLE_SPEC_VERSION",
    "VK_EXT_BORDER_COLOR_SWIZZLE_EXTENSION_NAME",
    "VK_EXT_PAGEABLE_DEVICE_LOCAL_MEMORY_SPEC_VERSION",
    "VK_EXT_PAGEABLE_DEVICE_LOCAL_MEMORY_EXTENSION_NAME",
    "VK_KHR_MAINTENANCE_4_SPEC_VERSION",
    "VK_KHR_MAINTENANCE_4_EXTENSION_NAME",
    "VK_HUAWEI_EXTENSION_415_SPEC_VERSION",
    "VK_HUAWEI_EXTENSION_415_EXTENSION_NAME",
    "VK_ARM_SHADER_CORE_PROPERTIES_SPEC_VERSION",
    "VK_ARM_SHADER_CORE_PROPERTIES_EXTENSION_NAME",
    "VK_KHR_EXTENSION_417_SPEC_VERSION",
    "VK_KHR_EXTENSION_417_EXTENSION_NAME",
    "VK_ARM_SCHEDULING_CONTROLS_SPEC_VERSION",
    "VK_ARM_SCHEDULING_CONTROLS_EXTENSION_NAME",
    "VK_EXT_IMAGE_SLICED_VIEW_OF_3D_SPEC_VERSION",
    "VK_EXT_IMAGE_SLICED_VIEW_OF_3D_EXTENSION_NAME",
    "VK_EXT_EXTENSION_420_SPEC_VERSION",
    "VK_EXT_EXTENSION_420_EXTENSION_NAME",
    "VK_VALVE_DESCRIPTOR_SET_HOST_MAPPING_SPEC_VERSION",
    "VK_VALVE_DESCRIPTOR_SET_HOST_MAPPING_EXTENSION_NAME",
    "VK_EXT_DEPTH_CLAMP_ZERO_ONE_SPEC_VERSION",
    "VK_EXT_DEPTH_CLAMP_ZERO_ONE_EXTENSION_NAME",
    "VK_EXT_NON_SEAMLESS_CUBE_MAP_SPEC_VERSION",
    "VK_EXT_NON_SEAMLESS_CUBE_MAP_EXTENSION_NAME",
    "VK_ARM_EXTENSION_424_SPEC_VERSION",
    "VK_ARM_EXTENSION_424_EXTENSION_NAME",
    "VK_ARM_RENDER_PASS_STRIPED_SPEC_VERSION",
    "VK_ARM_RENDER_PASS_STRIPED_EXTENSION_NAME",
    "VK_QCOM_FRAGMENT_DENSITY_MAP_OFFSET_SPEC_VERSION",
    "VK_QCOM_FRAGMENT_DENSITY_MAP_OFFSET_EXTENSION_NAME",
    "VK_NV_COPY_MEMORY_INDIRECT_SPEC_VERSION",
    "VK_NV_COPY_MEMORY_INDIRECT_EXTENSION_NAME",
    "VK_NV_MEMORY_DECOMPRESSION_SPEC_VERSION",
    "VK_NV_MEMORY_DECOMPRESSION_EXTENSION_NAME",
    "VK_NV_DEVICE_GENERATED_COMMANDS_COMPUTE_SPEC_VERSION",
    "VK_NV_DEVICE_GENERATED_COMMANDS_COMPUTE_EXTENSION_NAME",
    "VK_NV_EXTENSION_430_SPEC_VERSION",
    "VK_NV_EXTENSION_430_EXTENSION_NAME",
    "VK_NV_LINEAR_COLOR_ATTACHMENT_SPEC_VERSION",
    "VK_NV_LINEAR_COLOR_ATTACHMENT_EXTENSION_NAME",
    "VK_NV_EXTENSION_432_SPEC_VERSION",
    "VK_NV_EXTENSION_432_EXTENSION_NAME",
    "VK_NV_EXTENSION_433_SPEC_VERSION",
    "VK_NV_EXTENSION_433_EXTENSION_NAME",
    "VK_GOOGLE_SURFACELESS_QUERY_SPEC_VERSION",
    "VK_GOOGLE_SURFACELESS_QUERY_EXTENSION_NAME",
    "VK_KHR_EXTENSION_435_SPEC_VERSION",
    "VK_KHR_EXTENSION_435_EXTENSION_NAME",
    "VK_EXT_APPLICATION_PARAMETERS_SPEC_VERSION",
    "VK_EXT_APPLICATION_PARAMETERS_EXTENSION_NAME",
    "VK_EXT_EXTENSION_437_SPEC_VERSION",
    "VK_EXT_EXTENSION_437_EXTENSION_NAME",
    "VK_EXT_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_SPEC_VERSION",
    "VK_EXT_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_EXTENSION_NAME",
    "VK_SEC_EXTENSION_439_SPEC_VERSION",
    "VK_SEC_EXTENSION_439_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_440_SPEC_VERSION",
    "VK_QCOM_EXTENSION_440_EXTENSION_NAME",
    "VK_QCOM_IMAGE_PROCESSING_SPEC_VERSION",
    "VK_QCOM_IMAGE_PROCESSING_EXTENSION_NAME",
    "VK_COREAVI_EXTENSION_442_SPEC_VERSION",
    "VK_COREAVI_EXTENSION_442_EXTENSION_NAME",
    "VK_COREAVI_EXTENSION_443_SPEC_VERSION",
    "VK_COREAVI_EXTENSION_443_EXTENSION_NAME",
    "VK_COREAVI_EXTENSION_444_SPEC_VERSION",
    "VK_COREAVI_EXTENSION_444_EXTENSION_NAME",
    "VK_COREAVI_EXTENSION_445_SPEC_VERSION",
    "VK_COREAVI_EXTENSION_445_EXTENSION_NAME",
    "VK_COREAVI_EXTENSION_446_SPEC_VERSION",
    "VK_COREAVI_EXTENSION_446_EXTENSION_NAME",
    "VK_COREAVI_EXTENSION_447_SPEC_VERSION",
    "VK_COREAVI_EXTENSION_447_EXTENSION_NAME",
    "VK_SEC_EXTENSION_448_SPEC_VERSION",
    "VK_SEC_EXTENSION_448_EXTENSION_NAME",
    "VK_SEC_EXTENSION_449_SPEC_VERSION",
    "VK_SEC_EXTENSION_449_EXTENSION_NAME",
    "VK_SEC_EXTENSION_450_SPEC_VERSION",
    "VK_SEC_EXTENSION_450_EXTENSION_NAME",
    "VK_SEC_EXTENSION_451_SPEC_VERSION",
    "VK_SEC_EXTENSION_451_EXTENSION_NAME",
    "VK_EXT_NESTED_COMMAND_BUFFER_SPEC_VERSION",
    "VK_EXT_NESTED_COMMAND_BUFFER_EXTENSION_NAME",
    "VK_ARM_EXTENSION_453_SPEC_VERSION",
    "VK_ARM_EXTENSION_453_EXTENSION_NAME",
    "VK_EXT_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_SPEC_VERSION",
    "VK_EXT_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXTENSION_NAME",
    "VK_GOOGLE_EXTENSION_455_SPEC_VERSION",
    "VK_GOOGLE_EXTENSION_455_EXTENSION_NAME",
    "VK_EXT_EXTENDED_DYNAMIC_STATE_3_SPEC_VERSION",
    "VK_EXT_EXTENDED_DYNAMIC_STATE_3_EXTENSION_NAME",
    "VK_EXT_EXTENSION_457_SPEC_VERSION",
    "VK_EXT_EXTENSION_457_EXTENSION_NAME",
    "VK_EXT_EXTENSION_458_SPEC_VERSION",
    "VK_EXT_EXTENSION_458_EXTENSION_NAME",
    "VK_EXT_SUBPASS_MERGE_FEEDBACK_SPEC_VERSION",
    "VK_EXT_SUBPASS_MERGE_FEEDBACK_EXTENSION_NAME",
    "VK_LUNARG_DIRECT_DRIVER_LOADING_SPEC_VERSION",
    "VK_LUNARG_DIRECT_DRIVER_LOADING_EXTENSION_NAME",
    "VK_EXT_EXTENSION_461_SPEC_VERSION",
    "VK_EXT_EXTENSION_461_EXTENSION_NAME",
    "VK_EXT_EXTENSION_462_SPEC_VERSION",
    "VK_EXT_EXTENSION_462_EXTENSION_NAME",
    "VK_EXT_SHADER_MODULE_IDENTIFIER_SPEC_VERSION",
    "VK_EXT_SHADER_MODULE_IDENTIFIER_EXTENSION_NAME",
    "VK_EXT_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_SPEC_VERSION",
    "VK_EXT_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXTENSION_NAME",
    "VK_NV_OPTICAL_FLOW_SPEC_VERSION",
    "VK_NV_OPTICAL_FLOW_EXTENSION_NAME",
    "VK_EXT_LEGACY_DITHERING_SPEC_VERSION",
    "VK_EXT_LEGACY_DITHERING_EXTENSION_NAME",
    "VK_EXT_PIPELINE_PROTECTED_ACCESS_SPEC_VERSION",
    "VK_EXT_PIPELINE_PROTECTED_ACCESS_EXTENSION_NAME",
    "VK_EXT_EXTENSION_468_SPEC_VERSION",
    "VK_EXT_EXTENSION_468_EXTENSION_NAME",
    "VK_ANDROID_EXTERNAL_FORMAT_RESOLVE_SPEC_VERSION",
    "VK_ANDROID_EXTERNAL_FORMAT_RESOLVE_EXTENSION_NAME",
    "VK_AMD_EXTENSION_470_SPEC_VERSION",
    "VK_AMD_EXTENSION_470_EXTENSION_NAME",
    "VK_KHR_MAINTENANCE_5_SPEC_VERSION",
    "VK_KHR_MAINTENANCE_5_EXTENSION_NAME",
    "VK_AMD_EXTENSION_472_SPEC_VERSION",
    "VK_AMD_EXTENSION_472_EXTENSION_NAME",
    "VK_AMD_EXTENSION_473_SPEC_VERSION",
    "VK_AMD_EXTENSION_473_EXTENSION_NAME",
    "VK_AMD_EXTENSION_474_SPEC_VERSION",
    "VK_AMD_EXTENSION_474_EXTENSION_NAME",
    "VK_AMD_EXTENSION_475_SPEC_VERSION",
    "VK_AMD_EXTENSION_475_EXTENSION_NAME",
    "VK_AMD_EXTENSION_476_SPEC_VERSION",
    "VK_AMD_EXTENSION_476_EXTENSION_NAME",
    "VK_AMD_EXTENSION_477_SPEC_VERSION",
    "VK_AMD_EXTENSION_477_EXTENSION_NAME",
    "VK_AMD_EXTENSION_478_SPEC_VERSION",
    "VK_AMD_EXTENSION_478_EXTENSION_NAME",
    "VK_AMD_EXTENSION_479_SPEC_VERSION",
    "VK_AMD_EXTENSION_479_EXTENSION_NAME",
    "VK_EXT_EXTENSION_480_SPEC_VERSION",
    "VK_EXT_EXTENSION_480_EXTENSION_NAME",
    "VK_EXT_EXTENSION_481_SPEC_VERSION",
    "VK_EXT_EXTENSION_481_EXTENSION_NAME",
    "VK_KHR_RAY_TRACING_POSITION_FETCH_SPEC_VERSION",
    "VK_KHR_RAY_TRACING_POSITION_FETCH_EXTENSION_NAME",
    "VK_EXT_SHADER_OBJECT_SPEC_VERSION",
    "VK_EXT_SHADER_OBJECT_EXTENSION_NAME",
    "VK_EXT_EXTENSION_484_SPEC_VERSION",
    "VK_EXT_EXTENSION_484_EXTENSION_NAME",
    "VK_QCOM_TILE_PROPERTIES_SPEC_VERSION",
    "VK_QCOM_TILE_PROPERTIES_EXTENSION_NAME",
    "VK_SEC_AMIGO_PROFILING_SPEC_VERSION",
    "VK_SEC_AMIGO_PROFILING_EXTENSION_NAME",
    "VK_EXT_EXTENSION_487_SPEC_VERSION",
    "VK_EXT_EXTENSION_487_EXTENSION_NAME",
    "VK_EXT_EXTENSION_488_SPEC_VERSION",
    "VK_EXT_EXTENSION_488_EXTENSION_NAME",
    "VK_QCOM_MULTIVIEW_PER_VIEW_VIEWPORTS_SPEC_VERSION",
    "VK_QCOM_MULTIVIEW_PER_VIEW_VIEWPORTS_EXTENSION_NAME",
    "VK_NV_EXTERNAL_SCI_SYNC_2_SPEC_VERSION",
    "VK_NV_EXTERNAL_SCI_SYNC_2_EXTENSION_NAME",
    "VK_NV_RAY_TRACING_INVOCATION_REORDER_SPEC_VERSION",
    "VK_NV_RAY_TRACING_INVOCATION_REORDER_EXTENSION_NAME",
    "VK_NV_EXTENSION_492_SPEC_VERSION",
    "VK_NV_EXTENSION_492_EXTENSION_NAME",
    "VK_NV_EXTENDED_SPARSE_ADDRESS_SPACE_SPEC_VERSION",
    "VK_NV_EXTENDED_SPARSE_ADDRESS_SPACE_EXTENSION_NAME",
    "VK_NV_EXTENSION_494_SPEC_VERSION",
    "VK_NV_EXTENSION_494_EXTENSION_NAME",
    "VK_EXT_MUTABLE_DESCRIPTOR_TYPE_SPEC_VERSION",
    "VK_EXT_MUTABLE_DESCRIPTOR_TYPE_EXTENSION_NAME",
    "VK_EXT_EXTENSION_496_SPEC_VERSION",
    "VK_EXT_EXTENSION_496_EXTENSION_NAME",
    "VK_EXT_LAYER_SETTINGS_SPEC_VERSION",
    "VK_EXT_LAYER_SETTINGS_EXTENSION_NAME",
    "VK_ARM_SHADER_CORE_BUILTINS_SPEC_VERSION",
    "VK_ARM_SHADER_CORE_BUILTINS_EXTENSION_NAME",
    "VK_EXT_PIPELINE_LIBRARY_GROUP_HANDLES_SPEC_VERSION",
    "VK_EXT_PIPELINE_LIBRARY_GROUP_HANDLES_EXTENSION_NAME",
    "VK_EXT_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_SPEC_VERSION",
    "VK_EXT_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_EXTENSION_NAME",
    "VK_EXT_EXTENSION_501_SPEC_VERSION",
    "VK_EXT_EXTENSION_501_EXTENSION_NAME",
    "VK_EXT_EXTENSION_502_SPEC_VERSION",
    "VK_EXT_EXTENSION_502_EXTENSION_NAME",
    "VK_EXT_EXTENSION_503_SPEC_VERSION",
    "VK_EXT_EXTENSION_503_EXTENSION_NAME",
    "VK_NV_EXTENSION_504_SPEC_VERSION",
    "VK_NV_EXTENSION_504_EXTENSION_NAME",
    "VK_EXT_EXTENSION_505_SPEC_VERSION",
    "VK_EXT_EXTENSION_505_EXTENSION_NAME",
    "VK_NV_LOW_LATENCY_2_SPEC_VERSION",
    "VK_NV_LOW_LATENCY_2_EXTENSION_NAME",
    "VK_KHR_COOPERATIVE_MATRIX_SPEC_VERSION",
    "VK_KHR_COOPERATIVE_MATRIX_EXTENSION_NAME",
    "VK_EXT_EXTENSION_508_SPEC_VERSION",
    "VK_EXT_EXTENSION_508_EXTENSION_NAME",
    "VK_EXT_EXTENSION_509_SPEC_VERSION",
    "VK_EXT_EXTENSION_509_EXTENSION_NAME",
    "VK_MESA_EXTENSION_510_SPEC_VERSION",
    "VK_MESA_EXTENSION_510_EXTENSION_NAME",
    "VK_QCOM_MULTIVIEW_PER_VIEW_RENDER_AREAS_SPEC_VERSION",
    "VK_QCOM_MULTIVIEW_PER_VIEW_RENDER_AREAS_EXTENSION_NAME",
    "VK_EXT_EXTENSION_512_SPEC_VERSION",
    "VK_EXT_EXTENSION_512_EXTENSION_NAME",
    "VK_KHR_EXTENSION_513_SPEC_VERSION",
    "VK_KHR_EXTENSION_513_EXTENSION_NAME",
    "VK_KHR_EXTENSION_514_SPEC_VERSION",
    "VK_KHR_EXTENSION_514_EXTENSION_NAME",
    "VK_KHR_EXTENSION_515_SPEC_VERSION",
    "VK_KHR_EXTENSION_515_EXTENSION_NAME",
    "VK_KHR_VIDEO_MAINTENANCE_1_SPEC_VERSION",
    "VK_KHR_VIDEO_MAINTENANCE_1_EXTENSION_NAME",
    "VK_NV_PER_STAGE_DESCRIPTOR_SET_SPEC_VERSION",
    "VK_NV_PER_STAGE_DESCRIPTOR_SET_EXTENSION_NAME",
    "VK_MESA_EXTENSION_518_SPEC_VERSION",
    "VK_MESA_EXTENSION_518_EXTENSION_NAME",
    "VK_QCOM_IMAGE_PROCESSING_2_SPEC_VERSION",
    "VK_QCOM_IMAGE_PROCESSING_2_EXTENSION_NAME",
    "VK_QCOM_FILTER_CUBIC_WEIGHTS_SPEC_VERSION",
    "VK_QCOM_FILTER_CUBIC_WEIGHTS_EXTENSION_NAME",
    "VK_QCOM_YCBCR_DEGAMMA_SPEC_VERSION",
    "VK_QCOM_YCBCR_DEGAMMA_EXTENSION_NAME",
    "VK_QCOM_FILTER_CUBIC_CLAMP_SPEC_VERSION",
    "VK_QCOM_FILTER_CUBIC_CLAMP_EXTENSION_NAME",
    "VK_EXT_EXTENSION_523_SPEC_VERSION",
    "VK_EXT_EXTENSION_523_EXTENSION_NAME",
    "VK_EXT_EXTENSION_524_SPEC_VERSION",
    "VK_EXT_EXTENSION_524_EXTENSION_NAME",
    "VK_EXT_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_SPEC_VERSION",
    "VK_EXT_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_EXTENSION_NAME",
    "VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION",
    "VK_KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME",
    "VK_EXT_EXTENSION_527_SPEC_VERSION",
    "VK_EXT_EXTENSION_527_EXTENSION_NAME",
    "VK_EXT_EXTENSION_528_SPEC_VERSION",
    "VK_EXT_EXTENSION_528_EXTENSION_NAME",
    "VK_KHR_EXTENSION_529_SPEC_VERSION",
    "VK_KHR_EXTENSION_529_EXTENSION_NAME",
    "VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_SPEC_VERSION",
    "VK_QNX_EXTERNAL_MEMORY_SCREEN_BUFFER_EXTENSION_NAME",
    "VK_MSFT_LAYERED_DRIVER_SPEC_VERSION",
    "VK_MSFT_LAYERED_DRIVER_EXTENSION_NAME",
    "VK_KHR_EXTENSION_532_SPEC_VERSION",
    "VK_KHR_EXTENSION_532_EXTENSION_NAME",
    "VK_EXT_EXTENSION_533_SPEC_VERSION",
    "VK_EXT_EXTENSION_533_EXTENSION_NAME",
    "VK_KHR_EXTENSION_534_SPEC_VERSION",
    "VK_KHR_EXTENSION_534_EXTENSION_NAME",
    "VK_KHR_EXTENSION_535_SPEC_VERSION",
    "VK_KHR_EXTENSION_535_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_536_SPEC_VERSION",
    "VK_QCOM_EXTENSION_536_EXTENSION_NAME",
    "VK_EXT_EXTENSION_537_SPEC_VERSION",
    "VK_EXT_EXTENSION_537_EXTENSION_NAME",
    "VK_EXT_EXTENSION_538_SPEC_VERSION",
    "VK_EXT_EXTENSION_538_EXTENSION_NAME",
    "VK_EXT_EXTENSION_539_SPEC_VERSION",
    "VK_EXT_EXTENSION_539_EXTENSION_NAME",
    "VK_EXT_EXTENSION_540_SPEC_VERSION",
    "VK_EXT_EXTENSION_540_EXTENSION_NAME",
    "VK_EXT_EXTENSION_541_SPEC_VERSION",
    "VK_EXT_EXTENSION_541_EXTENSION_NAME",
    "VK_EXT_EXTENSION_542_SPEC_VERSION",
    "VK_EXT_EXTENSION_542_EXTENSION_NAME",
    "VK_EXT_EXTENSION_543_SPEC_VERSION",
    "VK_EXT_EXTENSION_543_EXTENSION_NAME",
    "VK_KHR_CALIBRATED_TIMESTAMPS_SPEC_VERSION",
    "VK_KHR_CALIBRATED_TIMESTAMPS_EXTENSION_NAME",
    "VK_KHR_EXTENSION_545_SPEC_VERSION",
    "VK_KHR_EXTENSION_545_EXTENSION_NAME",
    "VK_KHR_MAINTENANCE_6_SPEC_VERSION",
    "VK_KHR_MAINTENANCE_6_EXTENSION_NAME",
    "VK_NV_DESCRIPTOR_POOL_OVERALLOCATION_SPEC_VERSION",
    "VK_NV_DESCRIPTOR_POOL_OVERALLOCATION_EXTENSION_NAME",
    "VK_QCOM_EXTENSION_548_SPEC_VERSION",
    "VK_QCOM_EXTENSION_548_EXTENSION_NAME",
    "VK_NV_EXTENSION_549_SPEC_VERSION",
    "VK_NV_EXTENSION_549_EXTENSION_NAME",
    "VK_NV_EXTENSION_550_SPEC_VERSION",
    "VK_NV_EXTENSION_550_EXTENSION_NAME",
    "VK_NV_EXTENSION_551_SPEC_VERSION",
    "VK_NV_EXTENSION_551_EXTENSION_NAME",
    "VK_NV_EXTENSION_552_SPEC_VERSION",
    "VK_NV_EXTENSION_552_EXTENSION_NAME",
    "VK_KHR_EXTENSION_553_SPEC_VERSION",
    "VK_KHR_EXTENSION_553_EXTENSION_NAME",
    "VK_KHR_EXTENSION_554_SPEC_VERSION",
    "VK_KHR_EXTENSION_554_EXTENSION_NAME",
    "VK_IMG_EXTENSION_555_SPEC_VERSION",
    "VK_IMG_EXTENSION_555_EXTENSION_NAME",
    "VK_NV_EXTENSION_556_SPEC_VERSION",
    "VK_NV_EXTENSION_556_EXTENSION_NAME",
)
