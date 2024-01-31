#include <pybind11/pybind11.h>
#include <vulkan/vulkan.hpp>

namespace py = pybind11;

PYBIND11_MODULE(pyvulkan, m) {
    py::module n_vk = m.def_submodule("vk");
    py::enum_<::vk::AccessFlagBits> e_vk_AccessFlagBits(n_vk, "AccessFlagBits");
    py::enum_<::vk::AttachmentDescriptionFlagBits> e_vk_AttachmentDescriptionFlagBits(n_vk, "AttachmentDescriptionFlagBits");
    py::enum_<::vk::AttachmentLoadOp> e_vk_AttachmentLoadOp(n_vk, "AttachmentLoadOp");
    py::enum_<::vk::AttachmentStoreOp> e_vk_AttachmentStoreOp(n_vk, "AttachmentStoreOp");
    py::enum_<::vk::BlendFactor> e_vk_BlendFactor(n_vk, "BlendFactor");
    py::enum_<::vk::BlendOp> e_vk_BlendOp(n_vk, "BlendOp");
    py::enum_<::vk::BorderColor> e_vk_BorderColor(n_vk, "BorderColor");
    py::enum_<::vk::BufferCreateFlagBits> e_vk_BufferCreateFlagBits(n_vk, "BufferCreateFlagBits");
    py::enum_<::vk::BufferUsageFlagBits> e_vk_BufferUsageFlagBits(n_vk, "BufferUsageFlagBits");
    py::enum_<::vk::BufferViewCreateFlagBits> e_vk_BufferViewCreateFlagBits(n_vk, "BufferViewCreateFlagBits");
    py::enum_<::vk::ColorComponentFlagBits> e_vk_ColorComponentFlagBits(n_vk, "ColorComponentFlagBits");
    py::enum_<::vk::CommandBufferLevel> e_vk_CommandBufferLevel(n_vk, "CommandBufferLevel");
    py::enum_<::vk::CommandBufferResetFlagBits> e_vk_CommandBufferResetFlagBits(n_vk, "CommandBufferResetFlagBits");
    py::enum_<::vk::CommandBufferUsageFlagBits> e_vk_CommandBufferUsageFlagBits(n_vk, "CommandBufferUsageFlagBits");
    py::enum_<::vk::CommandPoolCreateFlagBits> e_vk_CommandPoolCreateFlagBits(n_vk, "CommandPoolCreateFlagBits");
    py::enum_<::vk::CommandPoolResetFlagBits> e_vk_CommandPoolResetFlagBits(n_vk, "CommandPoolResetFlagBits");
    py::enum_<::vk::CompareOp> e_vk_CompareOp(n_vk, "CompareOp");
    py::enum_<::vk::ComponentSwizzle> e_vk_ComponentSwizzle(n_vk, "ComponentSwizzle");
    py::enum_<::vk::CullModeFlagBits> e_vk_CullModeFlagBits(n_vk, "CullModeFlagBits");
    py::enum_<::vk::DependencyFlagBits> e_vk_DependencyFlagBits(n_vk, "DependencyFlagBits");
    py::enum_<::vk::DescriptorPoolCreateFlagBits> e_vk_DescriptorPoolCreateFlagBits(n_vk, "DescriptorPoolCreateFlagBits");
    py::enum_<::vk::DescriptorPoolResetFlagBits> e_vk_DescriptorPoolResetFlagBits(n_vk, "DescriptorPoolResetFlagBits");
    py::enum_<::vk::DescriptorSetLayoutCreateFlagBits> e_vk_DescriptorSetLayoutCreateFlagBits(n_vk, "DescriptorSetLayoutCreateFlagBits");
    py::enum_<::vk::DescriptorType> e_vk_DescriptorType(n_vk, "DescriptorType");
    py::enum_<::vk::DeviceCreateFlagBits> e_vk_DeviceCreateFlagBits(n_vk, "DeviceCreateFlagBits");
    py::enum_<::vk::DeviceQueueCreateFlagBits> e_vk_DeviceQueueCreateFlagBits(n_vk, "DeviceQueueCreateFlagBits");
    py::enum_<::vk::DynamicState> e_vk_DynamicState(n_vk, "DynamicState");
    py::enum_<::vk::EventCreateFlagBits> e_vk_EventCreateFlagBits(n_vk, "EventCreateFlagBits");
    py::enum_<::vk::FenceCreateFlagBits> e_vk_FenceCreateFlagBits(n_vk, "FenceCreateFlagBits");
    py::enum_<::vk::Filter> e_vk_Filter(n_vk, "Filter");
    py::enum_<::vk::Format> e_vk_Format(n_vk, "Format");
    py::enum_<::vk::FormatFeatureFlagBits> e_vk_FormatFeatureFlagBits(n_vk, "FormatFeatureFlagBits");
    py::enum_<::vk::FramebufferCreateFlagBits> e_vk_FramebufferCreateFlagBits(n_vk, "FramebufferCreateFlagBits");
    py::enum_<::vk::FrontFace> e_vk_FrontFace(n_vk, "FrontFace");
    py::enum_<::vk::ImageAspectFlagBits> e_vk_ImageAspectFlagBits(n_vk, "ImageAspectFlagBits");
    py::enum_<::vk::ImageCreateFlagBits> e_vk_ImageCreateFlagBits(n_vk, "ImageCreateFlagBits");
    py::enum_<::vk::ImageLayout> e_vk_ImageLayout(n_vk, "ImageLayout");
    py::enum_<::vk::ImageTiling> e_vk_ImageTiling(n_vk, "ImageTiling");
    py::enum_<::vk::ImageType> e_vk_ImageType(n_vk, "ImageType");
    py::enum_<::vk::ImageUsageFlagBits> e_vk_ImageUsageFlagBits(n_vk, "ImageUsageFlagBits");
    py::enum_<::vk::ImageViewCreateFlagBits> e_vk_ImageViewCreateFlagBits(n_vk, "ImageViewCreateFlagBits");
    py::enum_<::vk::ImageViewType> e_vk_ImageViewType(n_vk, "ImageViewType");
    py::enum_<::vk::IndexType> e_vk_IndexType(n_vk, "IndexType");
    py::enum_<::vk::InstanceCreateFlagBits> e_vk_InstanceCreateFlagBits(n_vk, "InstanceCreateFlagBits");
    py::enum_<::vk::InternalAllocationType> e_vk_InternalAllocationType(n_vk, "InternalAllocationType");
    py::enum_<::vk::LogicOp> e_vk_LogicOp(n_vk, "LogicOp");
    py::enum_<::vk::MemoryHeapFlagBits> e_vk_MemoryHeapFlagBits(n_vk, "MemoryHeapFlagBits");
    py::enum_<::vk::MemoryMapFlagBits> e_vk_MemoryMapFlagBits(n_vk, "MemoryMapFlagBits");
    py::enum_<::vk::MemoryPropertyFlagBits> e_vk_MemoryPropertyFlagBits(n_vk, "MemoryPropertyFlagBits");
    py::enum_<::vk::ObjectType> e_vk_ObjectType(n_vk, "ObjectType");
    py::enum_<::vk::PhysicalDeviceType> e_vk_PhysicalDeviceType(n_vk, "PhysicalDeviceType");
    py::enum_<::vk::PipelineBindPoint> e_vk_PipelineBindPoint(n_vk, "PipelineBindPoint");
    py::enum_<::vk::PipelineCacheCreateFlagBits> e_vk_PipelineCacheCreateFlagBits(n_vk, "PipelineCacheCreateFlagBits");
    py::enum_<::vk::PipelineCacheHeaderVersion> e_vk_PipelineCacheHeaderVersion(n_vk, "PipelineCacheHeaderVersion");
    py::enum_<::vk::PipelineColorBlendStateCreateFlagBits> e_vk_PipelineColorBlendStateCreateFlagBits(n_vk, "PipelineColorBlendStateCreateFlagBits");
    py::enum_<::vk::PipelineCreateFlagBits> e_vk_PipelineCreateFlagBits(n_vk, "PipelineCreateFlagBits");
    py::enum_<::vk::PipelineDepthStencilStateCreateFlagBits> e_vk_PipelineDepthStencilStateCreateFlagBits(n_vk, "PipelineDepthStencilStateCreateFlagBits");
    py::enum_<::vk::PipelineDynamicStateCreateFlagBits> e_vk_PipelineDynamicStateCreateFlagBits(n_vk, "PipelineDynamicStateCreateFlagBits");
    py::enum_<::vk::PipelineInputAssemblyStateCreateFlagBits> e_vk_PipelineInputAssemblyStateCreateFlagBits(n_vk, "PipelineInputAssemblyStateCreateFlagBits");
    py::enum_<::vk::PipelineLayoutCreateFlagBits> e_vk_PipelineLayoutCreateFlagBits(n_vk, "PipelineLayoutCreateFlagBits");
    py::enum_<::vk::PipelineMultisampleStateCreateFlagBits> e_vk_PipelineMultisampleStateCreateFlagBits(n_vk, "PipelineMultisampleStateCreateFlagBits");
    py::enum_<::vk::PipelineRasterizationStateCreateFlagBits> e_vk_PipelineRasterizationStateCreateFlagBits(n_vk, "PipelineRasterizationStateCreateFlagBits");
    py::enum_<::vk::PipelineShaderStageCreateFlagBits> e_vk_PipelineShaderStageCreateFlagBits(n_vk, "PipelineShaderStageCreateFlagBits");
    py::enum_<::vk::PipelineStageFlagBits> e_vk_PipelineStageFlagBits(n_vk, "PipelineStageFlagBits");
    py::enum_<::vk::PipelineTessellationStateCreateFlagBits> e_vk_PipelineTessellationStateCreateFlagBits(n_vk, "PipelineTessellationStateCreateFlagBits");
    py::enum_<::vk::PipelineVertexInputStateCreateFlagBits> e_vk_PipelineVertexInputStateCreateFlagBits(n_vk, "PipelineVertexInputStateCreateFlagBits");
    py::enum_<::vk::PipelineViewportStateCreateFlagBits> e_vk_PipelineViewportStateCreateFlagBits(n_vk, "PipelineViewportStateCreateFlagBits");
    py::enum_<::vk::PolygonMode> e_vk_PolygonMode(n_vk, "PolygonMode");
    py::enum_<::vk::PrimitiveTopology> e_vk_PrimitiveTopology(n_vk, "PrimitiveTopology");
    py::enum_<::vk::QueryControlFlagBits> e_vk_QueryControlFlagBits(n_vk, "QueryControlFlagBits");
    py::enum_<::vk::QueryPipelineStatisticFlagBits> e_vk_QueryPipelineStatisticFlagBits(n_vk, "QueryPipelineStatisticFlagBits");
    py::enum_<::vk::QueryPoolCreateFlagBits> e_vk_QueryPoolCreateFlagBits(n_vk, "QueryPoolCreateFlagBits");
    py::enum_<::vk::QueryResultFlagBits> e_vk_QueryResultFlagBits(n_vk, "QueryResultFlagBits");
    py::enum_<::vk::QueryType> e_vk_QueryType(n_vk, "QueryType");
    py::enum_<::vk::QueueFlagBits> e_vk_QueueFlagBits(n_vk, "QueueFlagBits");
    py::enum_<::vk::RenderPassCreateFlagBits> e_vk_RenderPassCreateFlagBits(n_vk, "RenderPassCreateFlagBits");
    py::enum_<::vk::Result> e_vk_Result(n_vk, "Result");
    py::enum_<::vk::SampleCountFlagBits> e_vk_SampleCountFlagBits(n_vk, "SampleCountFlagBits");
    py::enum_<::vk::SamplerAddressMode> e_vk_SamplerAddressMode(n_vk, "SamplerAddressMode");
    py::enum_<::vk::SamplerCreateFlagBits> e_vk_SamplerCreateFlagBits(n_vk, "SamplerCreateFlagBits");
    py::enum_<::vk::SamplerMipmapMode> e_vk_SamplerMipmapMode(n_vk, "SamplerMipmapMode");
    py::enum_<::vk::SemaphoreCreateFlagBits> e_vk_SemaphoreCreateFlagBits(n_vk, "SemaphoreCreateFlagBits");
    py::enum_<::vk::ShaderModuleCreateFlagBits> e_vk_ShaderModuleCreateFlagBits(n_vk, "ShaderModuleCreateFlagBits");
    py::enum_<::vk::ShaderStageFlagBits> e_vk_ShaderStageFlagBits(n_vk, "ShaderStageFlagBits");
    py::enum_<::vk::SharingMode> e_vk_SharingMode(n_vk, "SharingMode");
    py::enum_<::vk::SparseImageFormatFlagBits> e_vk_SparseImageFormatFlagBits(n_vk, "SparseImageFormatFlagBits");
    py::enum_<::vk::SparseMemoryBindFlagBits> e_vk_SparseMemoryBindFlagBits(n_vk, "SparseMemoryBindFlagBits");
    py::enum_<::vk::StencilFaceFlagBits> e_vk_StencilFaceFlagBits(n_vk, "StencilFaceFlagBits");
    py::enum_<::vk::StencilOp> e_vk_StencilOp(n_vk, "StencilOp");
    py::enum_<::vk::StructureType> e_vk_StructureType(n_vk, "StructureType");
    py::enum_<::vk::SubpassContents> e_vk_SubpassContents(n_vk, "SubpassContents");
    py::enum_<::vk::SubpassDescriptionFlagBits> e_vk_SubpassDescriptionFlagBits(n_vk, "SubpassDescriptionFlagBits");
    py::enum_<::vk::SystemAllocationScope> e_vk_SystemAllocationScope(n_vk, "SystemAllocationScope");
    py::enum_<::vk::VendorId> e_vk_VendorId(n_vk, "VendorId");
    py::enum_<::vk::VertexInputRate> e_vk_VertexInputRate(n_vk, "VertexInputRate");
    py::enum_<::vk::ChromaLocation> e_vk_ChromaLocation(n_vk, "ChromaLocation");
    py::enum_<::vk::CommandPoolTrimFlagBits> e_vk_CommandPoolTrimFlagBits(n_vk, "CommandPoolTrimFlagBits");
    py::enum_<::vk::DescriptorUpdateTemplateCreateFlagBits> e_vk_DescriptorUpdateTemplateCreateFlagBits(n_vk, "DescriptorUpdateTemplateCreateFlagBits");
    py::enum_<::vk::DescriptorUpdateTemplateType> e_vk_DescriptorUpdateTemplateType(n_vk, "DescriptorUpdateTemplateType");
    py::enum_<::vk::ExternalFenceFeatureFlagBits> e_vk_ExternalFenceFeatureFlagBits(n_vk, "ExternalFenceFeatureFlagBits");
    py::enum_<::vk::ExternalFenceHandleTypeFlagBits> e_vk_ExternalFenceHandleTypeFlagBits(n_vk, "ExternalFenceHandleTypeFlagBits");
    py::enum_<::vk::ExternalMemoryFeatureFlagBits> e_vk_ExternalMemoryFeatureFlagBits(n_vk, "ExternalMemoryFeatureFlagBits");
    py::enum_<::vk::ExternalMemoryHandleTypeFlagBits> e_vk_ExternalMemoryHandleTypeFlagBits(n_vk, "ExternalMemoryHandleTypeFlagBits");
    py::enum_<::vk::ExternalSemaphoreFeatureFlagBits> e_vk_ExternalSemaphoreFeatureFlagBits(n_vk, "ExternalSemaphoreFeatureFlagBits");
    py::enum_<::vk::ExternalSemaphoreHandleTypeFlagBits> e_vk_ExternalSemaphoreHandleTypeFlagBits(n_vk, "ExternalSemaphoreHandleTypeFlagBits");
    py::enum_<::vk::FenceImportFlagBits> e_vk_FenceImportFlagBits(n_vk, "FenceImportFlagBits");
    py::enum_<::vk::MemoryAllocateFlagBits> e_vk_MemoryAllocateFlagBits(n_vk, "MemoryAllocateFlagBits");
    py::enum_<::vk::PeerMemoryFeatureFlagBits> e_vk_PeerMemoryFeatureFlagBits(n_vk, "PeerMemoryFeatureFlagBits");
    py::enum_<::vk::PointClippingBehavior> e_vk_PointClippingBehavior(n_vk, "PointClippingBehavior");
    py::enum_<::vk::SamplerYcbcrModelConversion> e_vk_SamplerYcbcrModelConversion(n_vk, "SamplerYcbcrModelConversion");
    py::enum_<::vk::SamplerYcbcrRange> e_vk_SamplerYcbcrRange(n_vk, "SamplerYcbcrRange");
    py::enum_<::vk::SemaphoreImportFlagBits> e_vk_SemaphoreImportFlagBits(n_vk, "SemaphoreImportFlagBits");
    py::enum_<::vk::SubgroupFeatureFlagBits> e_vk_SubgroupFeatureFlagBits(n_vk, "SubgroupFeatureFlagBits");
    py::enum_<::vk::TessellationDomainOrigin> e_vk_TessellationDomainOrigin(n_vk, "TessellationDomainOrigin");
    py::enum_<::vk::DescriptorBindingFlagBits> e_vk_DescriptorBindingFlagBits(n_vk, "DescriptorBindingFlagBits");
    py::enum_<::vk::DriverId> e_vk_DriverId(n_vk, "DriverId");
    py::enum_<::vk::ResolveModeFlagBits> e_vk_ResolveModeFlagBits(n_vk, "ResolveModeFlagBits");
    py::enum_<::vk::SamplerReductionMode> e_vk_SamplerReductionMode(n_vk, "SamplerReductionMode");
    py::enum_<::vk::SemaphoreType> e_vk_SemaphoreType(n_vk, "SemaphoreType");
    py::enum_<::vk::SemaphoreWaitFlagBits> e_vk_SemaphoreWaitFlagBits(n_vk, "SemaphoreWaitFlagBits");
    py::enum_<::vk::ShaderFloatControlsIndependence> e_vk_ShaderFloatControlsIndependence(n_vk, "ShaderFloatControlsIndependence");
    py::enum_<::vk::AccessFlagBits2> e_vk_AccessFlagBits2(n_vk, "AccessFlagBits2");
    py::enum_<::vk::FormatFeatureFlagBits2> e_vk_FormatFeatureFlagBits2(n_vk, "FormatFeatureFlagBits2");
    py::enum_<::vk::PipelineCreationFeedbackFlagBits> e_vk_PipelineCreationFeedbackFlagBits(n_vk, "PipelineCreationFeedbackFlagBits");
    py::enum_<::vk::PipelineStageFlagBits2> e_vk_PipelineStageFlagBits2(n_vk, "PipelineStageFlagBits2");
    py::enum_<::vk::PrivateDataSlotCreateFlagBits> e_vk_PrivateDataSlotCreateFlagBits(n_vk, "PrivateDataSlotCreateFlagBits");
    py::enum_<::vk::RenderingFlagBits> e_vk_RenderingFlagBits(n_vk, "RenderingFlagBits");
    py::enum_<::vk::SubmitFlagBits> e_vk_SubmitFlagBits(n_vk, "SubmitFlagBits");
    py::enum_<::vk::ToolPurposeFlagBits> e_vk_ToolPurposeFlagBits(n_vk, "ToolPurposeFlagBits");
    py::enum_<::vk::ColorSpaceKHR> e_vk_ColorSpaceKHR(n_vk, "ColorSpaceKHR");
    py::enum_<::vk::CompositeAlphaFlagBitsKHR> e_vk_CompositeAlphaFlagBitsKHR(n_vk, "CompositeAlphaFlagBitsKHR");
    py::enum_<::vk::PresentModeKHR> e_vk_PresentModeKHR(n_vk, "PresentModeKHR");
    py::enum_<::vk::SurfaceTransformFlagBitsKHR> e_vk_SurfaceTransformFlagBitsKHR(n_vk, "SurfaceTransformFlagBitsKHR");
    py::enum_<::vk::DeviceGroupPresentModeFlagBitsKHR> e_vk_DeviceGroupPresentModeFlagBitsKHR(n_vk, "DeviceGroupPresentModeFlagBitsKHR");
    py::enum_<::vk::SwapchainCreateFlagBitsKHR> e_vk_SwapchainCreateFlagBitsKHR(n_vk, "SwapchainCreateFlagBitsKHR");
    py::enum_<::vk::DisplayModeCreateFlagBitsKHR> e_vk_DisplayModeCreateFlagBitsKHR(n_vk, "DisplayModeCreateFlagBitsKHR");
    py::enum_<::vk::DisplayPlaneAlphaFlagBitsKHR> e_vk_DisplayPlaneAlphaFlagBitsKHR(n_vk, "DisplayPlaneAlphaFlagBitsKHR");
    py::enum_<::vk::DisplaySurfaceCreateFlagBitsKHR> e_vk_DisplaySurfaceCreateFlagBitsKHR(n_vk, "DisplaySurfaceCreateFlagBitsKHR");
    py::enum_<::vk::DebugReportFlagBitsEXT> e_vk_DebugReportFlagBitsEXT(n_vk, "DebugReportFlagBitsEXT");
    py::enum_<::vk::DebugReportObjectTypeEXT> e_vk_DebugReportObjectTypeEXT(n_vk, "DebugReportObjectTypeEXT");
    py::enum_<::vk::RasterizationOrderAMD> e_vk_RasterizationOrderAMD(n_vk, "RasterizationOrderAMD");
    py::enum_<::vk::QueryResultStatusKHR> e_vk_QueryResultStatusKHR(n_vk, "QueryResultStatusKHR");
    py::enum_<::vk::VideoBeginCodingFlagBitsKHR> e_vk_VideoBeginCodingFlagBitsKHR(n_vk, "VideoBeginCodingFlagBitsKHR");
    py::enum_<::vk::VideoCapabilityFlagBitsKHR> e_vk_VideoCapabilityFlagBitsKHR(n_vk, "VideoCapabilityFlagBitsKHR");
    py::enum_<::vk::VideoChromaSubsamplingFlagBitsKHR> e_vk_VideoChromaSubsamplingFlagBitsKHR(n_vk, "VideoChromaSubsamplingFlagBitsKHR");
    py::enum_<::vk::VideoCodecOperationFlagBitsKHR> e_vk_VideoCodecOperationFlagBitsKHR(n_vk, "VideoCodecOperationFlagBitsKHR");
    py::enum_<::vk::VideoCodingControlFlagBitsKHR> e_vk_VideoCodingControlFlagBitsKHR(n_vk, "VideoCodingControlFlagBitsKHR");
    py::enum_<::vk::VideoComponentBitDepthFlagBitsKHR> e_vk_VideoComponentBitDepthFlagBitsKHR(n_vk, "VideoComponentBitDepthFlagBitsKHR");
    py::enum_<::vk::VideoEndCodingFlagBitsKHR> e_vk_VideoEndCodingFlagBitsKHR(n_vk, "VideoEndCodingFlagBitsKHR");
    py::enum_<::vk::VideoSessionCreateFlagBitsKHR> e_vk_VideoSessionCreateFlagBitsKHR(n_vk, "VideoSessionCreateFlagBitsKHR");
    py::enum_<::vk::VideoSessionParametersCreateFlagBitsKHR> e_vk_VideoSessionParametersCreateFlagBitsKHR(n_vk, "VideoSessionParametersCreateFlagBitsKHR");
    py::enum_<::vk::VideoDecodeCapabilityFlagBitsKHR> e_vk_VideoDecodeCapabilityFlagBitsKHR(n_vk, "VideoDecodeCapabilityFlagBitsKHR");
    py::enum_<::vk::VideoDecodeFlagBitsKHR> e_vk_VideoDecodeFlagBitsKHR(n_vk, "VideoDecodeFlagBitsKHR");
    py::enum_<::vk::VideoDecodeUsageFlagBitsKHR> e_vk_VideoDecodeUsageFlagBitsKHR(n_vk, "VideoDecodeUsageFlagBitsKHR");
    py::enum_<::vk::PipelineRasterizationStateStreamCreateFlagBitsEXT> e_vk_PipelineRasterizationStateStreamCreateFlagBitsEXT(n_vk, "PipelineRasterizationStateStreamCreateFlagBitsEXT");
    py::enum_<::vk::VideoEncodeH264CapabilityFlagBitsKHR> e_vk_VideoEncodeH264CapabilityFlagBitsKHR(n_vk, "VideoEncodeH264CapabilityFlagBitsKHR");
    py::enum_<::vk::VideoEncodeH264RateControlFlagBitsKHR> e_vk_VideoEncodeH264RateControlFlagBitsKHR(n_vk, "VideoEncodeH264RateControlFlagBitsKHR");
    py::enum_<::vk::VideoEncodeH264StdFlagBitsKHR> e_vk_VideoEncodeH264StdFlagBitsKHR(n_vk, "VideoEncodeH264StdFlagBitsKHR");
    py::enum_<::vk::VideoEncodeH265CapabilityFlagBitsKHR> e_vk_VideoEncodeH265CapabilityFlagBitsKHR(n_vk, "VideoEncodeH265CapabilityFlagBitsKHR");
    py::enum_<::vk::VideoEncodeH265CtbSizeFlagBitsKHR> e_vk_VideoEncodeH265CtbSizeFlagBitsKHR(n_vk, "VideoEncodeH265CtbSizeFlagBitsKHR");
    py::enum_<::vk::VideoEncodeH265RateControlFlagBitsKHR> e_vk_VideoEncodeH265RateControlFlagBitsKHR(n_vk, "VideoEncodeH265RateControlFlagBitsKHR");
    py::enum_<::vk::VideoEncodeH265StdFlagBitsKHR> e_vk_VideoEncodeH265StdFlagBitsKHR(n_vk, "VideoEncodeH265StdFlagBitsKHR");
    py::enum_<::vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR> e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR(n_vk, "VideoEncodeH265TransformBlockSizeFlagBitsKHR");
    py::enum_<::vk::VideoDecodeH264PictureLayoutFlagBitsKHR> e_vk_VideoDecodeH264PictureLayoutFlagBitsKHR(n_vk, "VideoDecodeH264PictureLayoutFlagBitsKHR");
    py::enum_<::vk::ShaderInfoTypeAMD> e_vk_ShaderInfoTypeAMD(n_vk, "ShaderInfoTypeAMD");
    py::enum_<::vk::ExternalMemoryFeatureFlagBitsNV> e_vk_ExternalMemoryFeatureFlagBitsNV(n_vk, "ExternalMemoryFeatureFlagBitsNV");
    py::enum_<::vk::ExternalMemoryHandleTypeFlagBitsNV> e_vk_ExternalMemoryHandleTypeFlagBitsNV(n_vk, "ExternalMemoryHandleTypeFlagBitsNV");
    py::enum_<::vk::ValidationCheckEXT> e_vk_ValidationCheckEXT(n_vk, "ValidationCheckEXT");
    py::enum_<::vk::PipelineRobustnessBufferBehaviorEXT> e_vk_PipelineRobustnessBufferBehaviorEXT(n_vk, "PipelineRobustnessBufferBehaviorEXT");
    py::enum_<::vk::PipelineRobustnessImageBehaviorEXT> e_vk_PipelineRobustnessImageBehaviorEXT(n_vk, "PipelineRobustnessImageBehaviorEXT");
    py::enum_<::vk::ConditionalRenderingFlagBitsEXT> e_vk_ConditionalRenderingFlagBitsEXT(n_vk, "ConditionalRenderingFlagBitsEXT");
    py::enum_<::vk::SurfaceCounterFlagBitsEXT> e_vk_SurfaceCounterFlagBitsEXT(n_vk, "SurfaceCounterFlagBitsEXT");
    py::enum_<::vk::DeviceEventTypeEXT> e_vk_DeviceEventTypeEXT(n_vk, "DeviceEventTypeEXT");
    py::enum_<::vk::DisplayEventTypeEXT> e_vk_DisplayEventTypeEXT(n_vk, "DisplayEventTypeEXT");
    py::enum_<::vk::DisplayPowerStateEXT> e_vk_DisplayPowerStateEXT(n_vk, "DisplayPowerStateEXT");
    py::enum_<::vk::PipelineViewportSwizzleStateCreateFlagBitsNV> e_vk_PipelineViewportSwizzleStateCreateFlagBitsNV(n_vk, "PipelineViewportSwizzleStateCreateFlagBitsNV");
    py::enum_<::vk::ViewportCoordinateSwizzleNV> e_vk_ViewportCoordinateSwizzleNV(n_vk, "ViewportCoordinateSwizzleNV");
    py::enum_<::vk::DiscardRectangleModeEXT> e_vk_DiscardRectangleModeEXT(n_vk, "DiscardRectangleModeEXT");
    py::enum_<::vk::PipelineDiscardRectangleStateCreateFlagBitsEXT> e_vk_PipelineDiscardRectangleStateCreateFlagBitsEXT(n_vk, "PipelineDiscardRectangleStateCreateFlagBitsEXT");
    py::enum_<::vk::ConservativeRasterizationModeEXT> e_vk_ConservativeRasterizationModeEXT(n_vk, "ConservativeRasterizationModeEXT");
    py::enum_<::vk::PipelineRasterizationConservativeStateCreateFlagBitsEXT> e_vk_PipelineRasterizationConservativeStateCreateFlagBitsEXT(n_vk, "PipelineRasterizationConservativeStateCreateFlagBitsEXT");
    py::enum_<::vk::PipelineRasterizationDepthClipStateCreateFlagBitsEXT> e_vk_PipelineRasterizationDepthClipStateCreateFlagBitsEXT(n_vk, "PipelineRasterizationDepthClipStateCreateFlagBitsEXT");
    py::enum_<::vk::AcquireProfilingLockFlagBitsKHR> e_vk_AcquireProfilingLockFlagBitsKHR(n_vk, "AcquireProfilingLockFlagBitsKHR");
    py::enum_<::vk::PerformanceCounterDescriptionFlagBitsKHR> e_vk_PerformanceCounterDescriptionFlagBitsKHR(n_vk, "PerformanceCounterDescriptionFlagBitsKHR");
    py::enum_<::vk::PerformanceCounterScopeKHR> e_vk_PerformanceCounterScopeKHR(n_vk, "PerformanceCounterScopeKHR");
    py::enum_<::vk::PerformanceCounterStorageKHR> e_vk_PerformanceCounterStorageKHR(n_vk, "PerformanceCounterStorageKHR");
    py::enum_<::vk::PerformanceCounterUnitKHR> e_vk_PerformanceCounterUnitKHR(n_vk, "PerformanceCounterUnitKHR");
    py::enum_<::vk::DebugUtilsMessageSeverityFlagBitsEXT> e_vk_DebugUtilsMessageSeverityFlagBitsEXT(n_vk, "DebugUtilsMessageSeverityFlagBitsEXT");
    py::enum_<::vk::DebugUtilsMessageTypeFlagBitsEXT> e_vk_DebugUtilsMessageTypeFlagBitsEXT(n_vk, "DebugUtilsMessageTypeFlagBitsEXT");
    py::enum_<::vk::DebugUtilsMessengerCallbackDataFlagBitsEXT> e_vk_DebugUtilsMessengerCallbackDataFlagBitsEXT(n_vk, "DebugUtilsMessengerCallbackDataFlagBitsEXT");
    py::enum_<::vk::DebugUtilsMessengerCreateFlagBitsEXT> e_vk_DebugUtilsMessengerCreateFlagBitsEXT(n_vk, "DebugUtilsMessengerCreateFlagBitsEXT");
    py::enum_<::vk::BlendOverlapEXT> e_vk_BlendOverlapEXT(n_vk, "BlendOverlapEXT");
    py::enum_<::vk::PipelineCoverageToColorStateCreateFlagBitsNV> e_vk_PipelineCoverageToColorStateCreateFlagBitsNV(n_vk, "PipelineCoverageToColorStateCreateFlagBitsNV");
    py::enum_<::vk::AccelerationStructureBuildTypeKHR> e_vk_AccelerationStructureBuildTypeKHR(n_vk, "AccelerationStructureBuildTypeKHR");
    py::enum_<::vk::AccelerationStructureCompatibilityKHR> e_vk_AccelerationStructureCompatibilityKHR(n_vk, "AccelerationStructureCompatibilityKHR");
    py::enum_<::vk::AccelerationStructureCreateFlagBitsKHR> e_vk_AccelerationStructureCreateFlagBitsKHR(n_vk, "AccelerationStructureCreateFlagBitsKHR");
    py::enum_<::vk::AccelerationStructureTypeKHR> e_vk_AccelerationStructureTypeKHR(n_vk, "AccelerationStructureTypeKHR");
    py::enum_<::vk::BuildAccelerationStructureFlagBitsKHR> e_vk_BuildAccelerationStructureFlagBitsKHR(n_vk, "BuildAccelerationStructureFlagBitsKHR");
    py::enum_<::vk::BuildAccelerationStructureModeKHR> e_vk_BuildAccelerationStructureModeKHR(n_vk, "BuildAccelerationStructureModeKHR");
    py::enum_<::vk::CopyAccelerationStructureModeKHR> e_vk_CopyAccelerationStructureModeKHR(n_vk, "CopyAccelerationStructureModeKHR");
    py::enum_<::vk::GeometryFlagBitsKHR> e_vk_GeometryFlagBitsKHR(n_vk, "GeometryFlagBitsKHR");
    py::enum_<::vk::GeometryInstanceFlagBitsKHR> e_vk_GeometryInstanceFlagBitsKHR(n_vk, "GeometryInstanceFlagBitsKHR");
    py::enum_<::vk::GeometryTypeKHR> e_vk_GeometryTypeKHR(n_vk, "GeometryTypeKHR");
    py::enum_<::vk::RayTracingShaderGroupTypeKHR> e_vk_RayTracingShaderGroupTypeKHR(n_vk, "RayTracingShaderGroupTypeKHR");
    py::enum_<::vk::ShaderGroupShaderKHR> e_vk_ShaderGroupShaderKHR(n_vk, "ShaderGroupShaderKHR");
    py::enum_<::vk::CoverageModulationModeNV> e_vk_CoverageModulationModeNV(n_vk, "CoverageModulationModeNV");
    py::enum_<::vk::PipelineCoverageModulationStateCreateFlagBitsNV> e_vk_PipelineCoverageModulationStateCreateFlagBitsNV(n_vk, "PipelineCoverageModulationStateCreateFlagBitsNV");
    py::enum_<::vk::ValidationCacheCreateFlagBitsEXT> e_vk_ValidationCacheCreateFlagBitsEXT(n_vk, "ValidationCacheCreateFlagBitsEXT");
    py::enum_<::vk::ValidationCacheHeaderVersionEXT> e_vk_ValidationCacheHeaderVersionEXT(n_vk, "ValidationCacheHeaderVersionEXT");
    py::enum_<::vk::CoarseSampleOrderTypeNV> e_vk_CoarseSampleOrderTypeNV(n_vk, "CoarseSampleOrderTypeNV");
    py::enum_<::vk::ShadingRatePaletteEntryNV> e_vk_ShadingRatePaletteEntryNV(n_vk, "ShadingRatePaletteEntryNV");
    py::enum_<::vk::AccelerationStructureMemoryRequirementsTypeNV> e_vk_AccelerationStructureMemoryRequirementsTypeNV(n_vk, "AccelerationStructureMemoryRequirementsTypeNV");
    py::enum_<::vk::PipelineCompilerControlFlagBitsAMD> e_vk_PipelineCompilerControlFlagBitsAMD(n_vk, "PipelineCompilerControlFlagBitsAMD");
    py::enum_<::vk::QueueGlobalPriorityKHR> e_vk_QueueGlobalPriorityKHR(n_vk, "QueueGlobalPriorityKHR");
    py::enum_<::vk::MemoryOverallocationBehaviorAMD> e_vk_MemoryOverallocationBehaviorAMD(n_vk, "MemoryOverallocationBehaviorAMD");
    py::enum_<::vk::PerformanceConfigurationTypeINTEL> e_vk_PerformanceConfigurationTypeINTEL(n_vk, "PerformanceConfigurationTypeINTEL");
    py::enum_<::vk::PerformanceOverrideTypeINTEL> e_vk_PerformanceOverrideTypeINTEL(n_vk, "PerformanceOverrideTypeINTEL");
    py::enum_<::vk::PerformanceParameterTypeINTEL> e_vk_PerformanceParameterTypeINTEL(n_vk, "PerformanceParameterTypeINTEL");
    py::enum_<::vk::PerformanceValueTypeINTEL> e_vk_PerformanceValueTypeINTEL(n_vk, "PerformanceValueTypeINTEL");
    py::enum_<::vk::QueryPoolSamplingModeINTEL> e_vk_QueryPoolSamplingModeINTEL(n_vk, "QueryPoolSamplingModeINTEL");
    py::enum_<::vk::FragmentShadingRateCombinerOpKHR> e_vk_FragmentShadingRateCombinerOpKHR(n_vk, "FragmentShadingRateCombinerOpKHR");
    py::enum_<::vk::ShaderCorePropertiesFlagBitsAMD> e_vk_ShaderCorePropertiesFlagBitsAMD(n_vk, "ShaderCorePropertiesFlagBitsAMD");
    py::enum_<::vk::ValidationFeatureDisableEXT> e_vk_ValidationFeatureDisableEXT(n_vk, "ValidationFeatureDisableEXT");
    py::enum_<::vk::ValidationFeatureEnableEXT> e_vk_ValidationFeatureEnableEXT(n_vk, "ValidationFeatureEnableEXT");
    py::enum_<::vk::CoverageReductionModeNV> e_vk_CoverageReductionModeNV(n_vk, "CoverageReductionModeNV");
    py::enum_<::vk::PipelineCoverageReductionStateCreateFlagBitsNV> e_vk_PipelineCoverageReductionStateCreateFlagBitsNV(n_vk, "PipelineCoverageReductionStateCreateFlagBitsNV");
    py::enum_<::vk::ProvokingVertexModeEXT> e_vk_ProvokingVertexModeEXT(n_vk, "ProvokingVertexModeEXT");
    py::enum_<::vk::HeadlessSurfaceCreateFlagBitsEXT> e_vk_HeadlessSurfaceCreateFlagBitsEXT(n_vk, "HeadlessSurfaceCreateFlagBitsEXT");
    py::enum_<::vk::LineRasterizationModeEXT> e_vk_LineRasterizationModeEXT(n_vk, "LineRasterizationModeEXT");
    py::enum_<::vk::PipelineExecutableStatisticFormatKHR> e_vk_PipelineExecutableStatisticFormatKHR(n_vk, "PipelineExecutableStatisticFormatKHR");
    py::enum_<::vk::HostImageCopyFlagBitsEXT> e_vk_HostImageCopyFlagBitsEXT(n_vk, "HostImageCopyFlagBitsEXT");
    py::enum_<::vk::MemoryUnmapFlagBitsKHR> e_vk_MemoryUnmapFlagBitsKHR(n_vk, "MemoryUnmapFlagBitsKHR");
    py::enum_<::vk::PresentGravityFlagBitsEXT> e_vk_PresentGravityFlagBitsEXT(n_vk, "PresentGravityFlagBitsEXT");
    py::enum_<::vk::PresentScalingFlagBitsEXT> e_vk_PresentScalingFlagBitsEXT(n_vk, "PresentScalingFlagBitsEXT");
    py::enum_<::vk::IndirectCommandsLayoutUsageFlagBitsNV> e_vk_IndirectCommandsLayoutUsageFlagBitsNV(n_vk, "IndirectCommandsLayoutUsageFlagBitsNV");
    py::enum_<::vk::IndirectCommandsTokenTypeNV> e_vk_IndirectCommandsTokenTypeNV(n_vk, "IndirectCommandsTokenTypeNV");
    py::enum_<::vk::IndirectStateFlagBitsNV> e_vk_IndirectStateFlagBitsNV(n_vk, "IndirectStateFlagBitsNV");
    py::enum_<::vk::DepthBiasRepresentationEXT> e_vk_DepthBiasRepresentationEXT(n_vk, "DepthBiasRepresentationEXT");
    py::enum_<::vk::DeviceMemoryReportEventTypeEXT> e_vk_DeviceMemoryReportEventTypeEXT(n_vk, "DeviceMemoryReportEventTypeEXT");
    py::enum_<::vk::DeviceMemoryReportFlagBitsEXT> e_vk_DeviceMemoryReportFlagBitsEXT(n_vk, "DeviceMemoryReportFlagBitsEXT");
    py::enum_<::vk::VideoEncodeCapabilityFlagBitsKHR> e_vk_VideoEncodeCapabilityFlagBitsKHR(n_vk, "VideoEncodeCapabilityFlagBitsKHR");
    py::enum_<::vk::VideoEncodeContentFlagBitsKHR> e_vk_VideoEncodeContentFlagBitsKHR(n_vk, "VideoEncodeContentFlagBitsKHR");
    py::enum_<::vk::VideoEncodeFeedbackFlagBitsKHR> e_vk_VideoEncodeFeedbackFlagBitsKHR(n_vk, "VideoEncodeFeedbackFlagBitsKHR");
    py::enum_<::vk::VideoEncodeFlagBitsKHR> e_vk_VideoEncodeFlagBitsKHR(n_vk, "VideoEncodeFlagBitsKHR");
    py::enum_<::vk::VideoEncodeRateControlFlagBitsKHR> e_vk_VideoEncodeRateControlFlagBitsKHR(n_vk, "VideoEncodeRateControlFlagBitsKHR");
    py::enum_<::vk::VideoEncodeRateControlModeFlagBitsKHR> e_vk_VideoEncodeRateControlModeFlagBitsKHR(n_vk, "VideoEncodeRateControlModeFlagBitsKHR");
    py::enum_<::vk::VideoEncodeTuningModeKHR> e_vk_VideoEncodeTuningModeKHR(n_vk, "VideoEncodeTuningModeKHR");
    py::enum_<::vk::VideoEncodeUsageFlagBitsKHR> e_vk_VideoEncodeUsageFlagBitsKHR(n_vk, "VideoEncodeUsageFlagBitsKHR");
    py::enum_<::vk::DeviceDiagnosticsConfigFlagBitsNV> e_vk_DeviceDiagnosticsConfigFlagBitsNV(n_vk, "DeviceDiagnosticsConfigFlagBitsNV");
    py::enum_<::vk::GraphicsPipelineLibraryFlagBitsEXT> e_vk_GraphicsPipelineLibraryFlagBitsEXT(n_vk, "GraphicsPipelineLibraryFlagBitsEXT");
    py::enum_<::vk::FragmentShadingRateNV> e_vk_FragmentShadingRateNV(n_vk, "FragmentShadingRateNV");
    py::enum_<::vk::FragmentShadingRateTypeNV> e_vk_FragmentShadingRateTypeNV(n_vk, "FragmentShadingRateTypeNV");
    py::enum_<::vk::AccelerationStructureMotionInfoFlagBitsNV> e_vk_AccelerationStructureMotionInfoFlagBitsNV(n_vk, "AccelerationStructureMotionInfoFlagBitsNV");
    py::enum_<::vk::AccelerationStructureMotionInstanceFlagBitsNV> e_vk_AccelerationStructureMotionInstanceFlagBitsNV(n_vk, "AccelerationStructureMotionInstanceFlagBitsNV");
    py::enum_<::vk::AccelerationStructureMotionInstanceTypeNV> e_vk_AccelerationStructureMotionInstanceTypeNV(n_vk, "AccelerationStructureMotionInstanceTypeNV");
    py::enum_<::vk::ImageCompressionFixedRateFlagBitsEXT> e_vk_ImageCompressionFixedRateFlagBitsEXT(n_vk, "ImageCompressionFixedRateFlagBitsEXT");
    py::enum_<::vk::ImageCompressionFlagBitsEXT> e_vk_ImageCompressionFlagBitsEXT(n_vk, "ImageCompressionFlagBitsEXT");
    py::enum_<::vk::DeviceFaultAddressTypeEXT> e_vk_DeviceFaultAddressTypeEXT(n_vk, "DeviceFaultAddressTypeEXT");
    py::enum_<::vk::DeviceFaultVendorBinaryHeaderVersionEXT> e_vk_DeviceFaultVendorBinaryHeaderVersionEXT(n_vk, "DeviceFaultVendorBinaryHeaderVersionEXT");
    py::enum_<::vk::DeviceAddressBindingFlagBitsEXT> e_vk_DeviceAddressBindingFlagBitsEXT(n_vk, "DeviceAddressBindingFlagBitsEXT");
    py::enum_<::vk::DeviceAddressBindingTypeEXT> e_vk_DeviceAddressBindingTypeEXT(n_vk, "DeviceAddressBindingTypeEXT");
    py::enum_<::vk::FrameBoundaryFlagBitsEXT> e_vk_FrameBoundaryFlagBitsEXT(n_vk, "FrameBoundaryFlagBitsEXT");
    py::enum_<::vk::BuildMicromapFlagBitsEXT> e_vk_BuildMicromapFlagBitsEXT(n_vk, "BuildMicromapFlagBitsEXT");
    py::enum_<::vk::BuildMicromapModeEXT> e_vk_BuildMicromapModeEXT(n_vk, "BuildMicromapModeEXT");
    py::enum_<::vk::CopyMicromapModeEXT> e_vk_CopyMicromapModeEXT(n_vk, "CopyMicromapModeEXT");
    py::enum_<::vk::MicromapCreateFlagBitsEXT> e_vk_MicromapCreateFlagBitsEXT(n_vk, "MicromapCreateFlagBitsEXT");
    py::enum_<::vk::MicromapTypeEXT> e_vk_MicromapTypeEXT(n_vk, "MicromapTypeEXT");
    py::enum_<::vk::OpacityMicromapFormatEXT> e_vk_OpacityMicromapFormatEXT(n_vk, "OpacityMicromapFormatEXT");
    py::enum_<::vk::OpacityMicromapSpecialIndexEXT> e_vk_OpacityMicromapSpecialIndexEXT(n_vk, "OpacityMicromapSpecialIndexEXT");
    py::enum_<::vk::PhysicalDeviceSchedulingControlsFlagBitsARM> e_vk_PhysicalDeviceSchedulingControlsFlagBitsARM(n_vk, "PhysicalDeviceSchedulingControlsFlagBitsARM");
    py::enum_<::vk::MemoryDecompressionMethodFlagBitsNV> e_vk_MemoryDecompressionMethodFlagBitsNV(n_vk, "MemoryDecompressionMethodFlagBitsNV");
    py::enum_<::vk::SubpassMergeStatusEXT> e_vk_SubpassMergeStatusEXT(n_vk, "SubpassMergeStatusEXT");
    py::enum_<::vk::DirectDriverLoadingFlagBitsLUNARG> e_vk_DirectDriverLoadingFlagBitsLUNARG(n_vk, "DirectDriverLoadingFlagBitsLUNARG");
    py::enum_<::vk::DirectDriverLoadingModeLUNARG> e_vk_DirectDriverLoadingModeLUNARG(n_vk, "DirectDriverLoadingModeLUNARG");
    py::enum_<::vk::OpticalFlowExecuteFlagBitsNV> e_vk_OpticalFlowExecuteFlagBitsNV(n_vk, "OpticalFlowExecuteFlagBitsNV");
    py::enum_<::vk::OpticalFlowGridSizeFlagBitsNV> e_vk_OpticalFlowGridSizeFlagBitsNV(n_vk, "OpticalFlowGridSizeFlagBitsNV");
    py::enum_<::vk::OpticalFlowPerformanceLevelNV> e_vk_OpticalFlowPerformanceLevelNV(n_vk, "OpticalFlowPerformanceLevelNV");
    py::enum_<::vk::OpticalFlowSessionBindingPointNV> e_vk_OpticalFlowSessionBindingPointNV(n_vk, "OpticalFlowSessionBindingPointNV");
    py::enum_<::vk::OpticalFlowSessionCreateFlagBitsNV> e_vk_OpticalFlowSessionCreateFlagBitsNV(n_vk, "OpticalFlowSessionCreateFlagBitsNV");
    py::enum_<::vk::OpticalFlowUsageFlagBitsNV> e_vk_OpticalFlowUsageFlagBitsNV(n_vk, "OpticalFlowUsageFlagBitsNV");
    py::enum_<::vk::BufferUsageFlagBits2KHR> e_vk_BufferUsageFlagBits2KHR(n_vk, "BufferUsageFlagBits2KHR");
    py::enum_<::vk::PipelineCreateFlagBits2KHR> e_vk_PipelineCreateFlagBits2KHR(n_vk, "PipelineCreateFlagBits2KHR");
    py::enum_<::vk::ShaderCodeTypeEXT> e_vk_ShaderCodeTypeEXT(n_vk, "ShaderCodeTypeEXT");
    py::enum_<::vk::ShaderCreateFlagBitsEXT> e_vk_ShaderCreateFlagBitsEXT(n_vk, "ShaderCreateFlagBitsEXT");
    py::enum_<::vk::RayTracingInvocationReorderModeNV> e_vk_RayTracingInvocationReorderModeNV(n_vk, "RayTracingInvocationReorderModeNV");
    py::enum_<::vk::LayerSettingTypeEXT> e_vk_LayerSettingTypeEXT(n_vk, "LayerSettingTypeEXT");
    py::enum_<::vk::LatencyMarkerNV> e_vk_LatencyMarkerNV(n_vk, "LatencyMarkerNV");
    py::enum_<::vk::OutOfBandQueueTypeNV> e_vk_OutOfBandQueueTypeNV(n_vk, "OutOfBandQueueTypeNV");
    py::enum_<::vk::ComponentTypeKHR> e_vk_ComponentTypeKHR(n_vk, "ComponentTypeKHR");
    py::enum_<::vk::ScopeKHR> e_vk_ScopeKHR(n_vk, "ScopeKHR");
    py::enum_<::vk::BlockMatchWindowCompareModeQCOM> e_vk_BlockMatchWindowCompareModeQCOM(n_vk, "BlockMatchWindowCompareModeQCOM");
    py::enum_<::vk::CubicFilterWeightsQCOM> e_vk_CubicFilterWeightsQCOM(n_vk, "CubicFilterWeightsQCOM");
    py::enum_<::vk::LayeredDriverUnderlyingApiMSFT> e_vk_LayeredDriverUnderlyingApiMSFT(n_vk, "LayeredDriverUnderlyingApiMSFT");
    py::enum_<::vk::TimeDomainKHR> e_vk_TimeDomainKHR(n_vk, "TimeDomainKHR");
    n_vk.attr("ATTACHMENT_UNUSED") = py::cast(::vk::AttachmentUnused);
    n_vk.attr("FALSE") = py::cast(::vk::False);
    n_vk.attr("LOD_CLAMP_NONE") = py::cast(::vk::LodClampNone);
    n_vk.attr("MAX_DESCRIPTION_SIZE") = py::cast(::vk::MaxDescriptionSize);
    n_vk.attr("MAX_EXTENSION_NAME_SIZE") = py::cast(::vk::MaxExtensionNameSize);
    n_vk.attr("MAX_MEMORY_HEAPS") = py::cast(::vk::MaxMemoryHeaps);
    n_vk.attr("MAX_MEMORY_TYPES") = py::cast(::vk::MaxMemoryTypes);
    n_vk.attr("MAX_PHYSICAL_DEVICE_NAME_SIZE") = py::cast(::vk::MaxPhysicalDeviceNameSize);
    n_vk.attr("QUEUE_FAMILY_IGNORED") = py::cast(::vk::QueueFamilyIgnored);
    n_vk.attr("REMAINING_ARRAY_LAYERS") = py::cast(::vk::RemainingArrayLayers);
    n_vk.attr("REMAINING_MIP_LEVELS") = py::cast(::vk::RemainingMipLevels);
    n_vk.attr("SUBPASS_EXTERNAL") = py::cast(::vk::SubpassExternal);
    n_vk.attr("TRUE") = py::cast(::vk::True);
    n_vk.attr("UUID_SIZE") = py::cast(::vk::UuidSize);
    n_vk.attr("WHOLE_SIZE") = py::cast(::vk::WholeSize);
    n_vk.attr("LUID_SIZE") = py::cast(::vk::LuidSize);
    n_vk.attr("MAX_DEVICE_GROUP_SIZE") = py::cast(::vk::MaxDeviceGroupSize);
    n_vk.attr("QUEUE_FAMILY_EXTERNAL") = py::cast(::vk::QueueFamilyExternal);
    n_vk.attr("MAX_DRIVER_INFO_SIZE") = py::cast(::vk::MaxDriverInfoSize);
    n_vk.attr("MAX_DRIVER_NAME_SIZE") = py::cast(::vk::MaxDriverNameSize);
    n_vk.attr("KHR_SURFACE_EXTENSION_NAME") = py::cast(::vk::KHRSurfaceExtensionName);
    n_vk.attr("KHR_SURFACE_SPEC_VERSION") = py::cast(::vk::KHRSurfaceSpecVersion);
    n_vk.attr("KHR_SWAPCHAIN_EXTENSION_NAME") = py::cast(::vk::KHRSwapchainExtensionName);
    n_vk.attr("KHR_SWAPCHAIN_SPEC_VERSION") = py::cast(::vk::KHRSwapchainSpecVersion);
    n_vk.attr("KHR_DISPLAY_EXTENSION_NAME") = py::cast(::vk::KHRDisplayExtensionName);
    n_vk.attr("KHR_DISPLAY_SPEC_VERSION") = py::cast(::vk::KHRDisplaySpecVersion);
    n_vk.attr("KHR_DISPLAY_SWAPCHAIN_EXTENSION_NAME") = py::cast(::vk::KHRDisplaySwapchainExtensionName);
    n_vk.attr("KHR_DISPLAY_SWAPCHAIN_SPEC_VERSION") = py::cast(::vk::KHRDisplaySwapchainSpecVersion);
    n_vk.attr("EXT_DEBUG_REPORT_EXTENSION_NAME") = py::cast(::vk::EXTDebugReportExtensionName);
    n_vk.attr("EXT_DEBUG_REPORT_SPEC_VERSION") = py::cast(::vk::EXTDebugReportSpecVersion);
    n_vk.attr("NV_GLSL_SHADER_EXTENSION_NAME") = py::cast(::vk::NVGlslShaderExtensionName);
    n_vk.attr("NV_GLSL_SHADER_SPEC_VERSION") = py::cast(::vk::NVGlslShaderSpecVersion);
    n_vk.attr("EXT_DEPTH_RANGE_UNRESTRICTED_EXTENSION_NAME") = py::cast(::vk::EXTDepthRangeUnrestrictedExtensionName);
    n_vk.attr("EXT_DEPTH_RANGE_UNRESTRICTED_SPEC_VERSION") = py::cast(::vk::EXTDepthRangeUnrestrictedSpecVersion);
    n_vk.attr("KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_EXTENSION_NAME") = py::cast(::vk::KHRSamplerMirrorClampToEdgeExtensionName);
    n_vk.attr("KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_SPEC_VERSION") = py::cast(::vk::KHRSamplerMirrorClampToEdgeSpecVersion);
    n_vk.attr("IMG_FILTER_CUBIC_EXTENSION_NAME") = py::cast(::vk::IMGFilterCubicExtensionName);
    n_vk.attr("IMG_FILTER_CUBIC_SPEC_VERSION") = py::cast(::vk::IMGFilterCubicSpecVersion);
    n_vk.attr("AMD_RASTERIZATION_ORDER_EXTENSION_NAME") = py::cast(::vk::AMDRasterizationOrderExtensionName);
    n_vk.attr("AMD_RASTERIZATION_ORDER_SPEC_VERSION") = py::cast(::vk::AMDRasterizationOrderSpecVersion);
    n_vk.attr("AMD_SHADER_TRINARY_MINMAX_EXTENSION_NAME") = py::cast(::vk::AMDShaderTrinaryMinmaxExtensionName);
    n_vk.attr("AMD_SHADER_TRINARY_MINMAX_SPEC_VERSION") = py::cast(::vk::AMDShaderTrinaryMinmaxSpecVersion);
    n_vk.attr("AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_EXTENSION_NAME") = py::cast(::vk::AMDShaderExplicitVertexParameterExtensionName);
    n_vk.attr("AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_SPEC_VERSION") = py::cast(::vk::AMDShaderExplicitVertexParameterSpecVersion);
    n_vk.attr("EXT_DEBUG_MARKER_EXTENSION_NAME") = py::cast(::vk::EXTDebugMarkerExtensionName);
    n_vk.attr("EXT_DEBUG_MARKER_SPEC_VERSION") = py::cast(::vk::EXTDebugMarkerSpecVersion);
    n_vk.attr("KHR_VIDEO_QUEUE_EXTENSION_NAME") = py::cast(::vk::KHRVideoQueueExtensionName);
    n_vk.attr("KHR_VIDEO_QUEUE_SPEC_VERSION") = py::cast(::vk::KHRVideoQueueSpecVersion);
    n_vk.attr("KHR_VIDEO_DECODE_QUEUE_EXTENSION_NAME") = py::cast(::vk::KHRVideoDecodeQueueExtensionName);
    n_vk.attr("KHR_VIDEO_DECODE_QUEUE_SPEC_VERSION") = py::cast(::vk::KHRVideoDecodeQueueSpecVersion);
    n_vk.attr("AMD_GCN_SHADER_EXTENSION_NAME") = py::cast(::vk::AMDGcnShaderExtensionName);
    n_vk.attr("AMD_GCN_SHADER_SPEC_VERSION") = py::cast(::vk::AMDGcnShaderSpecVersion);
    n_vk.attr("NV_DEDICATED_ALLOCATION_EXTENSION_NAME") = py::cast(::vk::NVDedicatedAllocationExtensionName);
    n_vk.attr("NV_DEDICATED_ALLOCATION_SPEC_VERSION") = py::cast(::vk::NVDedicatedAllocationSpecVersion);
    n_vk.attr("EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME") = py::cast(::vk::EXTTransformFeedbackExtensionName);
    n_vk.attr("EXT_TRANSFORM_FEEDBACK_SPEC_VERSION") = py::cast(::vk::EXTTransformFeedbackSpecVersion);
    n_vk.attr("NVX_BINARY_IMPORT_EXTENSION_NAME") = py::cast(::vk::NVXBinaryImportExtensionName);
    n_vk.attr("NVX_BINARY_IMPORT_SPEC_VERSION") = py::cast(::vk::NVXBinaryImportSpecVersion);
    n_vk.attr("NVX_IMAGE_VIEW_HANDLE_EXTENSION_NAME") = py::cast(::vk::NVXImageViewHandleExtensionName);
    n_vk.attr("NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION") = py::cast(::vk::NVXImageViewHandleSpecVersion);
    n_vk.attr("AMD_DRAW_INDIRECT_COUNT_EXTENSION_NAME") = py::cast(::vk::AMDDrawIndirectCountExtensionName);
    n_vk.attr("AMD_DRAW_INDIRECT_COUNT_SPEC_VERSION") = py::cast(::vk::AMDDrawIndirectCountSpecVersion);
    n_vk.attr("AMD_NEGATIVE_VIEWPORT_HEIGHT_EXTENSION_NAME") = py::cast(::vk::AMDNegativeViewportHeightExtensionName);
    n_vk.attr("AMD_NEGATIVE_VIEWPORT_HEIGHT_SPEC_VERSION") = py::cast(::vk::AMDNegativeViewportHeightSpecVersion);
    n_vk.attr("AMD_GPU_SHADER_HALF_FLOAT_EXTENSION_NAME") = py::cast(::vk::AMDGpuShaderHalfFloatExtensionName);
    n_vk.attr("AMD_GPU_SHADER_HALF_FLOAT_SPEC_VERSION") = py::cast(::vk::AMDGpuShaderHalfFloatSpecVersion);
    n_vk.attr("AMD_SHADER_BALLOT_EXTENSION_NAME") = py::cast(::vk::AMDShaderBallotExtensionName);
    n_vk.attr("AMD_SHADER_BALLOT_SPEC_VERSION") = py::cast(::vk::AMDShaderBallotSpecVersion);
    n_vk.attr("KHR_VIDEO_ENCODE_H264_EXTENSION_NAME") = py::cast(::vk::KHRVideoEncodeH264ExtensionName);
    n_vk.attr("KHR_VIDEO_ENCODE_H264_SPEC_VERSION") = py::cast(::vk::KHRVideoEncodeH264SpecVersion);
    n_vk.attr("KHR_VIDEO_ENCODE_H265_EXTENSION_NAME") = py::cast(::vk::KHRVideoEncodeH265ExtensionName);
    n_vk.attr("KHR_VIDEO_ENCODE_H265_SPEC_VERSION") = py::cast(::vk::KHRVideoEncodeH265SpecVersion);
    n_vk.attr("KHR_VIDEO_DECODE_H264_EXTENSION_NAME") = py::cast(::vk::KHRVideoDecodeH264ExtensionName);
    n_vk.attr("KHR_VIDEO_DECODE_H264_SPEC_VERSION") = py::cast(::vk::KHRVideoDecodeH264SpecVersion);
    n_vk.attr("AMD_TEXTURE_GATHER_BIAS_LOD_EXTENSION_NAME") = py::cast(::vk::AMDTextureGatherBiasLodExtensionName);
    n_vk.attr("AMD_TEXTURE_GATHER_BIAS_LOD_SPEC_VERSION") = py::cast(::vk::AMDTextureGatherBiasLodSpecVersion);
    n_vk.attr("AMD_SHADER_INFO_EXTENSION_NAME") = py::cast(::vk::AMDShaderInfoExtensionName);
    n_vk.attr("AMD_SHADER_INFO_SPEC_VERSION") = py::cast(::vk::AMDShaderInfoSpecVersion);
    n_vk.attr("KHR_DYNAMIC_RENDERING_EXTENSION_NAME") = py::cast(::vk::KHRDynamicRenderingExtensionName);
    n_vk.attr("KHR_DYNAMIC_RENDERING_SPEC_VERSION") = py::cast(::vk::KHRDynamicRenderingSpecVersion);
    n_vk.attr("AMD_SHADER_IMAGE_LOAD_STORE_LOD_EXTENSION_NAME") = py::cast(::vk::AMDShaderImageLoadStoreLodExtensionName);
    n_vk.attr("AMD_SHADER_IMAGE_LOAD_STORE_LOD_SPEC_VERSION") = py::cast(::vk::AMDShaderImageLoadStoreLodSpecVersion);
    n_vk.attr("NV_CORNER_SAMPLED_IMAGE_EXTENSION_NAME") = py::cast(::vk::NVCornerSampledImageExtensionName);
    n_vk.attr("NV_CORNER_SAMPLED_IMAGE_SPEC_VERSION") = py::cast(::vk::NVCornerSampledImageSpecVersion);
    n_vk.attr("KHR_MULTIVIEW_EXTENSION_NAME") = py::cast(::vk::KHRMultiviewExtensionName);
    n_vk.attr("KHR_MULTIVIEW_SPEC_VERSION") = py::cast(::vk::KHRMultiviewSpecVersion);
    n_vk.attr("IMG_FORMAT_PVRTC_EXTENSION_NAME") = py::cast(::vk::IMGFormatPvrtcExtensionName);
    n_vk.attr("IMG_FORMAT_PVRTC_SPEC_VERSION") = py::cast(::vk::IMGFormatPvrtcSpecVersion);
    n_vk.attr("NV_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME") = py::cast(::vk::NVExternalMemoryCapabilitiesExtensionName);
    n_vk.attr("NV_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION") = py::cast(::vk::NVExternalMemoryCapabilitiesSpecVersion);
    n_vk.attr("NV_EXTERNAL_MEMORY_EXTENSION_NAME") = py::cast(::vk::NVExternalMemoryExtensionName);
    n_vk.attr("NV_EXTERNAL_MEMORY_SPEC_VERSION") = py::cast(::vk::NVExternalMemorySpecVersion);
    n_vk.attr("KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME") = py::cast(::vk::KHRGetPhysicalDeviceProperties2ExtensionName);
    n_vk.attr("KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_SPEC_VERSION") = py::cast(::vk::KHRGetPhysicalDeviceProperties2SpecVersion);
    n_vk.attr("KHR_DEVICE_GROUP_EXTENSION_NAME") = py::cast(::vk::KHRDeviceGroupExtensionName);
    n_vk.attr("KHR_DEVICE_GROUP_SPEC_VERSION") = py::cast(::vk::KHRDeviceGroupSpecVersion);
    n_vk.attr("EXT_VALIDATION_FLAGS_EXTENSION_NAME") = py::cast(::vk::EXTValidationFlagsExtensionName);
    n_vk.attr("EXT_VALIDATION_FLAGS_SPEC_VERSION") = py::cast(::vk::EXTValidationFlagsSpecVersion);
    n_vk.attr("KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME") = py::cast(::vk::KHRShaderDrawParametersExtensionName);
    n_vk.attr("KHR_SHADER_DRAW_PARAMETERS_SPEC_VERSION") = py::cast(::vk::KHRShaderDrawParametersSpecVersion);
    n_vk.attr("EXT_SHADER_SUBGROUP_BALLOT_EXTENSION_NAME") = py::cast(::vk::EXTShaderSubgroupBallotExtensionName);
    n_vk.attr("EXT_SHADER_SUBGROUP_BALLOT_SPEC_VERSION") = py::cast(::vk::EXTShaderSubgroupBallotSpecVersion);
    n_vk.attr("EXT_SHADER_SUBGROUP_VOTE_EXTENSION_NAME") = py::cast(::vk::EXTShaderSubgroupVoteExtensionName);
    n_vk.attr("EXT_SHADER_SUBGROUP_VOTE_SPEC_VERSION") = py::cast(::vk::EXTShaderSubgroupVoteSpecVersion);
    n_vk.attr("EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME") = py::cast(::vk::EXTTextureCompressionAstcHdrExtensionName);
    n_vk.attr("EXT_TEXTURE_COMPRESSION_ASTC_HDR_SPEC_VERSION") = py::cast(::vk::EXTTextureCompressionAstcHdrSpecVersion);
    n_vk.attr("EXT_ASTC_DECODE_MODE_EXTENSION_NAME") = py::cast(::vk::EXTAstcDecodeModeExtensionName);
    n_vk.attr("EXT_ASTC_DECODE_MODE_SPEC_VERSION") = py::cast(::vk::EXTAstcDecodeModeSpecVersion);
    n_vk.attr("EXT_PIPELINE_ROBUSTNESS_EXTENSION_NAME") = py::cast(::vk::EXTPipelineRobustnessExtensionName);
    n_vk.attr("EXT_PIPELINE_ROBUSTNESS_SPEC_VERSION") = py::cast(::vk::EXTPipelineRobustnessSpecVersion);
    n_vk.attr("KHR_MAINTENANCE_1_EXTENSION_NAME") = py::cast(::vk::KHRMaintenance1ExtensionName);
    n_vk.attr("KHR_MAINTENANCE_1_SPEC_VERSION") = py::cast(::vk::KHRMaintenance1SpecVersion);
    n_vk.attr("KHR_DEVICE_GROUP_CREATION_EXTENSION_NAME") = py::cast(::vk::KHRDeviceGroupCreationExtensionName);
    n_vk.attr("KHR_DEVICE_GROUP_CREATION_SPEC_VERSION") = py::cast(::vk::KHRDeviceGroupCreationSpecVersion);
    n_vk.attr("MAX_DEVICE_GROUP_SIZE_KHR") = py::cast(::vk::MaxDeviceGroupSizeKHR);
    n_vk.attr("KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME") = py::cast(::vk::KHRExternalMemoryCapabilitiesExtensionName);
    n_vk.attr("KHR_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION") = py::cast(::vk::KHRExternalMemoryCapabilitiesSpecVersion);
    n_vk.attr("LUID_SIZE_KHR") = py::cast(::vk::LuidSizeKHR);
    n_vk.attr("KHR_EXTERNAL_MEMORY_EXTENSION_NAME") = py::cast(::vk::KHRExternalMemoryExtensionName);
    n_vk.attr("KHR_EXTERNAL_MEMORY_SPEC_VERSION") = py::cast(::vk::KHRExternalMemorySpecVersion);
    n_vk.attr("QUEUE_FAMILY_EXTERNAL_KHR") = py::cast(::vk::QueueFamilyExternalKHR);
    n_vk.attr("KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME") = py::cast(::vk::KHRExternalMemoryFdExtensionName);
    n_vk.attr("KHR_EXTERNAL_MEMORY_FD_SPEC_VERSION") = py::cast(::vk::KHRExternalMemoryFdSpecVersion);
    n_vk.attr("KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_EXTENSION_NAME") = py::cast(::vk::KHRExternalSemaphoreCapabilitiesExtensionName);
    n_vk.attr("KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_SPEC_VERSION") = py::cast(::vk::KHRExternalSemaphoreCapabilitiesSpecVersion);
    n_vk.attr("KHR_EXTERNAL_SEMAPHORE_EXTENSION_NAME") = py::cast(::vk::KHRExternalSemaphoreExtensionName);
    n_vk.attr("KHR_EXTERNAL_SEMAPHORE_SPEC_VERSION") = py::cast(::vk::KHRExternalSemaphoreSpecVersion);
    n_vk.attr("KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME") = py::cast(::vk::KHRExternalSemaphoreFdExtensionName);
    n_vk.attr("KHR_EXTERNAL_SEMAPHORE_FD_SPEC_VERSION") = py::cast(::vk::KHRExternalSemaphoreFdSpecVersion);
    n_vk.attr("KHR_PUSH_DESCRIPTOR_EXTENSION_NAME") = py::cast(::vk::KHRPushDescriptorExtensionName);
    n_vk.attr("KHR_PUSH_DESCRIPTOR_SPEC_VERSION") = py::cast(::vk::KHRPushDescriptorSpecVersion);
    n_vk.attr("EXT_CONDITIONAL_RENDERING_EXTENSION_NAME") = py::cast(::vk::EXTConditionalRenderingExtensionName);
    n_vk.attr("EXT_CONDITIONAL_RENDERING_SPEC_VERSION") = py::cast(::vk::EXTConditionalRenderingSpecVersion);
    n_vk.attr("KHR_SHADER_FLOAT_16_INT_8_EXTENSION_NAME") = py::cast(::vk::KHRShaderFloat16Int8ExtensionName);
    n_vk.attr("KHR_SHADER_FLOAT_16_INT_8_SPEC_VERSION") = py::cast(::vk::KHRShaderFloat16Int8SpecVersion);
    n_vk.attr("KHR16_BIT_STORAGE_EXTENSION_NAME") = py::cast(::vk::KHR16BitStorageExtensionName);
    n_vk.attr("KHR16_BIT_STORAGE_SPEC_VERSION") = py::cast(::vk::KHR16BitStorageSpecVersion);
    n_vk.attr("KHR_INCREMENTAL_PRESENT_EXTENSION_NAME") = py::cast(::vk::KHRIncrementalPresentExtensionName);
    n_vk.attr("KHR_INCREMENTAL_PRESENT_SPEC_VERSION") = py::cast(::vk::KHRIncrementalPresentSpecVersion);
    n_vk.attr("KHR_DESCRIPTOR_UPDATE_TEMPLATE_EXTENSION_NAME") = py::cast(::vk::KHRDescriptorUpdateTemplateExtensionName);
    n_vk.attr("KHR_DESCRIPTOR_UPDATE_TEMPLATE_SPEC_VERSION") = py::cast(::vk::KHRDescriptorUpdateTemplateSpecVersion);
    n_vk.attr("NV_CLIP_SPACE_W_SCALING_EXTENSION_NAME") = py::cast(::vk::NVClipSpaceWScalingExtensionName);
    n_vk.attr("NV_CLIP_SPACE_W_SCALING_SPEC_VERSION") = py::cast(::vk::NVClipSpaceWScalingSpecVersion);
    n_vk.attr("EXT_DIRECT_MODE_DISPLAY_EXTENSION_NAME") = py::cast(::vk::EXTDirectModeDisplayExtensionName);
    n_vk.attr("EXT_DIRECT_MODE_DISPLAY_SPEC_VERSION") = py::cast(::vk::EXTDirectModeDisplaySpecVersion);
    n_vk.attr("EXT_DISPLAY_SURFACE_COUNTER_EXTENSION_NAME") = py::cast(::vk::EXTDisplaySurfaceCounterExtensionName);
    n_vk.attr("EXT_DISPLAY_SURFACE_COUNTER_SPEC_VERSION") = py::cast(::vk::EXTDisplaySurfaceCounterSpecVersion);
    n_vk.attr("EXT_DISPLAY_CONTROL_EXTENSION_NAME") = py::cast(::vk::EXTDisplayControlExtensionName);
    n_vk.attr("EXT_DISPLAY_CONTROL_SPEC_VERSION") = py::cast(::vk::EXTDisplayControlSpecVersion);
    n_vk.attr("GOOGLE_DISPLAY_TIMING_EXTENSION_NAME") = py::cast(::vk::GOOGLEDisplayTimingExtensionName);
    n_vk.attr("GOOGLE_DISPLAY_TIMING_SPEC_VERSION") = py::cast(::vk::GOOGLEDisplayTimingSpecVersion);
    n_vk.attr("NV_SAMPLE_MASK_OVERRIDE_COVERAGE_EXTENSION_NAME") = py::cast(::vk::NVSampleMaskOverrideCoverageExtensionName);
    n_vk.attr("NV_SAMPLE_MASK_OVERRIDE_COVERAGE_SPEC_VERSION") = py::cast(::vk::NVSampleMaskOverrideCoverageSpecVersion);
    n_vk.attr("NV_GEOMETRY_SHADER_PASSTHROUGH_EXTENSION_NAME") = py::cast(::vk::NVGeometryShaderPassthroughExtensionName);
    n_vk.attr("NV_GEOMETRY_SHADER_PASSTHROUGH_SPEC_VERSION") = py::cast(::vk::NVGeometryShaderPassthroughSpecVersion);
    n_vk.attr("NV_VIEWPORT_ARRAY_2_EXTENSION_NAME") = py::cast(::vk::NVViewportArray2ExtensionName);
    n_vk.attr("NV_VIEWPORT_ARRAY_2_SPEC_VERSION") = py::cast(::vk::NVViewportArray2SpecVersion);
    n_vk.attr("NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_EXTENSION_NAME") = py::cast(::vk::NVXMultiviewPerViewAttributesExtensionName);
    n_vk.attr("NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_SPEC_VERSION") = py::cast(::vk::NVXMultiviewPerViewAttributesSpecVersion);
    n_vk.attr("NV_VIEWPORT_SWIZZLE_EXTENSION_NAME") = py::cast(::vk::NVViewportSwizzleExtensionName);
    n_vk.attr("NV_VIEWPORT_SWIZZLE_SPEC_VERSION") = py::cast(::vk::NVViewportSwizzleSpecVersion);
    n_vk.attr("EXT_DISCARD_RECTANGLES_EXTENSION_NAME") = py::cast(::vk::EXTDiscardRectanglesExtensionName);
    n_vk.attr("EXT_DISCARD_RECTANGLES_SPEC_VERSION") = py::cast(::vk::EXTDiscardRectanglesSpecVersion);
    n_vk.attr("EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME") = py::cast(::vk::EXTConservativeRasterizationExtensionName);
    n_vk.attr("EXT_CONSERVATIVE_RASTERIZATION_SPEC_VERSION") = py::cast(::vk::EXTConservativeRasterizationSpecVersion);
    n_vk.attr("EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME") = py::cast(::vk::EXTDepthClipEnableExtensionName);
    n_vk.attr("EXT_DEPTH_CLIP_ENABLE_SPEC_VERSION") = py::cast(::vk::EXTDepthClipEnableSpecVersion);
    n_vk.attr("EXT_SWAPCHAIN_COLOR_SPACE_EXTENSION_NAME") = py::cast(::vk::EXTSwapchainColorSpaceExtensionName);
    n_vk.attr("EXT_SWAPCHAIN_COLOR_SPACE_SPEC_VERSION") = py::cast(::vk::EXTSwapchainColorSpaceSpecVersion);
    n_vk.attr("EXT_HDR_METADATA_EXTENSION_NAME") = py::cast(::vk::EXTHdrMetadataExtensionName);
    n_vk.attr("EXT_HDR_METADATA_SPEC_VERSION") = py::cast(::vk::EXTHdrMetadataSpecVersion);
    n_vk.attr("KHR_IMAGELESS_FRAMEBUFFER_EXTENSION_NAME") = py::cast(::vk::KHRImagelessFramebufferExtensionName);
    n_vk.attr("KHR_IMAGELESS_FRAMEBUFFER_SPEC_VERSION") = py::cast(::vk::KHRImagelessFramebufferSpecVersion);
    n_vk.attr("KHR_CREATE_RENDERPASS_2_EXTENSION_NAME") = py::cast(::vk::KHRCreateRenderpass2ExtensionName);
    n_vk.attr("KHR_CREATE_RENDERPASS_2_SPEC_VERSION") = py::cast(::vk::KHRCreateRenderpass2SpecVersion);
    n_vk.attr("IMG_RELAXED_LINE_RASTERIZATION_EXTENSION_NAME") = py::cast(::vk::IMGRelaxedLineRasterizationExtensionName);
    n_vk.attr("IMG_RELAXED_LINE_RASTERIZATION_SPEC_VERSION") = py::cast(::vk::IMGRelaxedLineRasterizationSpecVersion);
    n_vk.attr("KHR_SHARED_PRESENTABLE_IMAGE_EXTENSION_NAME") = py::cast(::vk::KHRSharedPresentableImageExtensionName);
    n_vk.attr("KHR_SHARED_PRESENTABLE_IMAGE_SPEC_VERSION") = py::cast(::vk::KHRSharedPresentableImageSpecVersion);
    n_vk.attr("KHR_EXTERNAL_FENCE_CAPABILITIES_EXTENSION_NAME") = py::cast(::vk::KHRExternalFenceCapabilitiesExtensionName);
    n_vk.attr("KHR_EXTERNAL_FENCE_CAPABILITIES_SPEC_VERSION") = py::cast(::vk::KHRExternalFenceCapabilitiesSpecVersion);
    n_vk.attr("KHR_EXTERNAL_FENCE_EXTENSION_NAME") = py::cast(::vk::KHRExternalFenceExtensionName);
    n_vk.attr("KHR_EXTERNAL_FENCE_SPEC_VERSION") = py::cast(::vk::KHRExternalFenceSpecVersion);
    n_vk.attr("KHR_EXTERNAL_FENCE_FD_EXTENSION_NAME") = py::cast(::vk::KHRExternalFenceFdExtensionName);
    n_vk.attr("KHR_EXTERNAL_FENCE_FD_SPEC_VERSION") = py::cast(::vk::KHRExternalFenceFdSpecVersion);
    n_vk.attr("KHR_PERFORMANCE_QUERY_EXTENSION_NAME") = py::cast(::vk::KHRPerformanceQueryExtensionName);
    n_vk.attr("KHR_PERFORMANCE_QUERY_SPEC_VERSION") = py::cast(::vk::KHRPerformanceQuerySpecVersion);
    n_vk.attr("KHR_MAINTENANCE_2_EXTENSION_NAME") = py::cast(::vk::KHRMaintenance2ExtensionName);
    n_vk.attr("KHR_MAINTENANCE_2_SPEC_VERSION") = py::cast(::vk::KHRMaintenance2SpecVersion);
    n_vk.attr("KHR_GET_SURFACE_CAPABILITIES_2_EXTENSION_NAME") = py::cast(::vk::KHRGetSurfaceCapabilities2ExtensionName);
    n_vk.attr("KHR_GET_SURFACE_CAPABILITIES_2_SPEC_VERSION") = py::cast(::vk::KHRGetSurfaceCapabilities2SpecVersion);
    n_vk.attr("KHR_VARIABLE_POINTERS_EXTENSION_NAME") = py::cast(::vk::KHRVariablePointersExtensionName);
    n_vk.attr("KHR_VARIABLE_POINTERS_SPEC_VERSION") = py::cast(::vk::KHRVariablePointersSpecVersion);
    n_vk.attr("KHR_GET_DISPLAY_PROPERTIES_2_EXTENSION_NAME") = py::cast(::vk::KHRGetDisplayProperties2ExtensionName);
    n_vk.attr("KHR_GET_DISPLAY_PROPERTIES_2_SPEC_VERSION") = py::cast(::vk::KHRGetDisplayProperties2SpecVersion);
    n_vk.attr("EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME") = py::cast(::vk::EXTExternalMemoryDmaBufExtensionName);
    n_vk.attr("EXT_EXTERNAL_MEMORY_DMA_BUF_SPEC_VERSION") = py::cast(::vk::EXTExternalMemoryDmaBufSpecVersion);
    n_vk.attr("EXT_QUEUE_FAMILY_FOREIGN_EXTENSION_NAME") = py::cast(::vk::EXTQueueFamilyForeignExtensionName);
    n_vk.attr("EXT_QUEUE_FAMILY_FOREIGN_SPEC_VERSION") = py::cast(::vk::EXTQueueFamilyForeignSpecVersion);
    n_vk.attr("QUEUE_FAMILY_FOREIGN_EXT") = py::cast(::vk::QueueFamilyForeignEXT);
    n_vk.attr("KHR_DEDICATED_ALLOCATION_EXTENSION_NAME") = py::cast(::vk::KHRDedicatedAllocationExtensionName);
    n_vk.attr("KHR_DEDICATED_ALLOCATION_SPEC_VERSION") = py::cast(::vk::KHRDedicatedAllocationSpecVersion);
    n_vk.attr("EXT_DEBUG_UTILS_EXTENSION_NAME") = py::cast(::vk::EXTDebugUtilsExtensionName);
    n_vk.attr("EXT_DEBUG_UTILS_SPEC_VERSION") = py::cast(::vk::EXTDebugUtilsSpecVersion);
    n_vk.attr("EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME") = py::cast(::vk::EXTSamplerFilterMinmaxExtensionName);
    n_vk.attr("EXT_SAMPLER_FILTER_MINMAX_SPEC_VERSION") = py::cast(::vk::EXTSamplerFilterMinmaxSpecVersion);
    n_vk.attr("KHR_STORAGE_BUFFER_STORAGE_CLASS_EXTENSION_NAME") = py::cast(::vk::KHRStorageBufferStorageClassExtensionName);
    n_vk.attr("KHR_STORAGE_BUFFER_STORAGE_CLASS_SPEC_VERSION") = py::cast(::vk::KHRStorageBufferStorageClassSpecVersion);
    n_vk.attr("AMD_GPU_SHADER_INT_16_EXTENSION_NAME") = py::cast(::vk::AMDGpuShaderInt16ExtensionName);
    n_vk.attr("AMD_GPU_SHADER_INT_16_SPEC_VERSION") = py::cast(::vk::AMDGpuShaderInt16SpecVersion);
    n_vk.attr("AMD_MIXED_ATTACHMENT_SAMPLES_EXTENSION_NAME") = py::cast(::vk::AMDMixedAttachmentSamplesExtensionName);
    n_vk.attr("AMD_MIXED_ATTACHMENT_SAMPLES_SPEC_VERSION") = py::cast(::vk::AMDMixedAttachmentSamplesSpecVersion);
    n_vk.attr("AMD_SHADER_FRAGMENT_MASK_EXTENSION_NAME") = py::cast(::vk::AMDShaderFragmentMaskExtensionName);
    n_vk.attr("AMD_SHADER_FRAGMENT_MASK_SPEC_VERSION") = py::cast(::vk::AMDShaderFragmentMaskSpecVersion);
    n_vk.attr("EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME") = py::cast(::vk::EXTInlineUniformBlockExtensionName);
    n_vk.attr("EXT_INLINE_UNIFORM_BLOCK_SPEC_VERSION") = py::cast(::vk::EXTInlineUniformBlockSpecVersion);
    n_vk.attr("EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME") = py::cast(::vk::EXTShaderStencilExportExtensionName);
    n_vk.attr("EXT_SHADER_STENCIL_EXPORT_SPEC_VERSION") = py::cast(::vk::EXTShaderStencilExportSpecVersion);
    n_vk.attr("EXT_SAMPLE_LOCATIONS_EXTENSION_NAME") = py::cast(::vk::EXTSampleLocationsExtensionName);
    n_vk.attr("EXT_SAMPLE_LOCATIONS_SPEC_VERSION") = py::cast(::vk::EXTSampleLocationsSpecVersion);
    n_vk.attr("KHR_RELAXED_BLOCK_LAYOUT_EXTENSION_NAME") = py::cast(::vk::KHRRelaxedBlockLayoutExtensionName);
    n_vk.attr("KHR_RELAXED_BLOCK_LAYOUT_SPEC_VERSION") = py::cast(::vk::KHRRelaxedBlockLayoutSpecVersion);
    n_vk.attr("KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME") = py::cast(::vk::KHRGetMemoryRequirements2ExtensionName);
    n_vk.attr("KHR_GET_MEMORY_REQUIREMENTS_2_SPEC_VERSION") = py::cast(::vk::KHRGetMemoryRequirements2SpecVersion);
    n_vk.attr("KHR_IMAGE_FORMAT_LIST_EXTENSION_NAME") = py::cast(::vk::KHRImageFormatListExtensionName);
    n_vk.attr("KHR_IMAGE_FORMAT_LIST_SPEC_VERSION") = py::cast(::vk::KHRImageFormatListSpecVersion);
    n_vk.attr("EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME") = py::cast(::vk::EXTBlendOperationAdvancedExtensionName);
    n_vk.attr("EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION") = py::cast(::vk::EXTBlendOperationAdvancedSpecVersion);
    n_vk.attr("NV_FRAGMENT_COVERAGE_TO_COLOR_EXTENSION_NAME") = py::cast(::vk::NVFragmentCoverageToColorExtensionName);
    n_vk.attr("NV_FRAGMENT_COVERAGE_TO_COLOR_SPEC_VERSION") = py::cast(::vk::NVFragmentCoverageToColorSpecVersion);
    n_vk.attr("KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME") = py::cast(::vk::KHRAccelerationStructureExtensionName);
    n_vk.attr("KHR_ACCELERATION_STRUCTURE_SPEC_VERSION") = py::cast(::vk::KHRAccelerationStructureSpecVersion);
    n_vk.attr("KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME") = py::cast(::vk::KHRRayTracingPipelineExtensionName);
    n_vk.attr("KHR_RAY_TRACING_PIPELINE_SPEC_VERSION") = py::cast(::vk::KHRRayTracingPipelineSpecVersion);
    n_vk.attr("SHADER_UNUSED_KHR") = py::cast(::vk::ShaderUnusedKHR);
    n_vk.attr("KHR_RAY_QUERY_EXTENSION_NAME") = py::cast(::vk::KHRRayQueryExtensionName);
    n_vk.attr("KHR_RAY_QUERY_SPEC_VERSION") = py::cast(::vk::KHRRayQuerySpecVersion);
    n_vk.attr("NV_FRAMEBUFFER_MIXED_SAMPLES_EXTENSION_NAME") = py::cast(::vk::NVFramebufferMixedSamplesExtensionName);
    n_vk.attr("NV_FRAMEBUFFER_MIXED_SAMPLES_SPEC_VERSION") = py::cast(::vk::NVFramebufferMixedSamplesSpecVersion);
    n_vk.attr("NV_FILL_RECTANGLE_EXTENSION_NAME") = py::cast(::vk::NVFillRectangleExtensionName);
    n_vk.attr("NV_FILL_RECTANGLE_SPEC_VERSION") = py::cast(::vk::NVFillRectangleSpecVersion);
    n_vk.attr("NV_SHADER_SM_BUILTINS_EXTENSION_NAME") = py::cast(::vk::NVShaderSmBuiltinsExtensionName);
    n_vk.attr("NV_SHADER_SM_BUILTINS_SPEC_VERSION") = py::cast(::vk::NVShaderSmBuiltinsSpecVersion);
    n_vk.attr("EXT_POST_DEPTH_COVERAGE_EXTENSION_NAME") = py::cast(::vk::EXTPostDepthCoverageExtensionName);
    n_vk.attr("EXT_POST_DEPTH_COVERAGE_SPEC_VERSION") = py::cast(::vk::EXTPostDepthCoverageSpecVersion);
    n_vk.attr("KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME") = py::cast(::vk::KHRSamplerYcbcrConversionExtensionName);
    n_vk.attr("KHR_SAMPLER_YCBCR_CONVERSION_SPEC_VERSION") = py::cast(::vk::KHRSamplerYcbcrConversionSpecVersion);
    n_vk.attr("KHR_BIND_MEMORY_2_EXTENSION_NAME") = py::cast(::vk::KHRBindMemory2ExtensionName);
    n_vk.attr("KHR_BIND_MEMORY_2_SPEC_VERSION") = py::cast(::vk::KHRBindMemory2SpecVersion);
    n_vk.attr("EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME") = py::cast(::vk::EXTImageDrmFormatModifierExtensionName);
    n_vk.attr("EXT_IMAGE_DRM_FORMAT_MODIFIER_SPEC_VERSION") = py::cast(::vk::EXTImageDrmFormatModifierSpecVersion);
    n_vk.attr("EXT_VALIDATION_CACHE_EXTENSION_NAME") = py::cast(::vk::EXTValidationCacheExtensionName);
    n_vk.attr("EXT_VALIDATION_CACHE_SPEC_VERSION") = py::cast(::vk::EXTValidationCacheSpecVersion);
    n_vk.attr("EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME") = py::cast(::vk::EXTDescriptorIndexingExtensionName);
    n_vk.attr("EXT_DESCRIPTOR_INDEXING_SPEC_VERSION") = py::cast(::vk::EXTDescriptorIndexingSpecVersion);
    n_vk.attr("EXT_SHADER_VIEWPORT_INDEX_LAYER_EXTENSION_NAME") = py::cast(::vk::EXTShaderViewportIndexLayerExtensionName);
    n_vk.attr("EXT_SHADER_VIEWPORT_INDEX_LAYER_SPEC_VERSION") = py::cast(::vk::EXTShaderViewportIndexLayerSpecVersion);
    n_vk.attr("NV_SHADING_RATE_IMAGE_EXTENSION_NAME") = py::cast(::vk::NVShadingRateImageExtensionName);
    n_vk.attr("NV_SHADING_RATE_IMAGE_SPEC_VERSION") = py::cast(::vk::NVShadingRateImageSpecVersion);
    n_vk.attr("NV_RAY_TRACING_EXTENSION_NAME") = py::cast(::vk::NVRayTracingExtensionName);
    n_vk.attr("NV_RAY_TRACING_SPEC_VERSION") = py::cast(::vk::NVRayTracingSpecVersion);
    n_vk.attr("SHADER_UNUSED_NV") = py::cast(::vk::ShaderUnusedNV);
    n_vk.attr("NV_REPRESENTATIVE_FRAGMENT_TEST_EXTENSION_NAME") = py::cast(::vk::NVRepresentativeFragmentTestExtensionName);
    n_vk.attr("NV_REPRESENTATIVE_FRAGMENT_TEST_SPEC_VERSION") = py::cast(::vk::NVRepresentativeFragmentTestSpecVersion);
    n_vk.attr("KHR_MAINTENANCE_3_EXTENSION_NAME") = py::cast(::vk::KHRMaintenance3ExtensionName);
    n_vk.attr("KHR_MAINTENANCE_3_SPEC_VERSION") = py::cast(::vk::KHRMaintenance3SpecVersion);
    n_vk.attr("KHR_DRAW_INDIRECT_COUNT_EXTENSION_NAME") = py::cast(::vk::KHRDrawIndirectCountExtensionName);
    n_vk.attr("KHR_DRAW_INDIRECT_COUNT_SPEC_VERSION") = py::cast(::vk::KHRDrawIndirectCountSpecVersion);
    n_vk.attr("EXT_FILTER_CUBIC_EXTENSION_NAME") = py::cast(::vk::EXTFilterCubicExtensionName);
    n_vk.attr("EXT_FILTER_CUBIC_SPEC_VERSION") = py::cast(::vk::EXTFilterCubicSpecVersion);
    n_vk.attr("QCOM_RENDER_PASS_SHADER_RESOLVE_EXTENSION_NAME") = py::cast(::vk::QCOMRenderPassShaderResolveExtensionName);
    n_vk.attr("QCOM_RENDER_PASS_SHADER_RESOLVE_SPEC_VERSION") = py::cast(::vk::QCOMRenderPassShaderResolveSpecVersion);
    n_vk.attr("EXT_GLOBAL_PRIORITY_EXTENSION_NAME") = py::cast(::vk::EXTGlobalPriorityExtensionName);
    n_vk.attr("EXT_GLOBAL_PRIORITY_SPEC_VERSION") = py::cast(::vk::EXTGlobalPrioritySpecVersion);
    n_vk.attr("KHR_SHADER_SUBGROUP_EXTENDED_TYPES_EXTENSION_NAME") = py::cast(::vk::KHRShaderSubgroupExtendedTypesExtensionName);
    n_vk.attr("KHR_SHADER_SUBGROUP_EXTENDED_TYPES_SPEC_VERSION") = py::cast(::vk::KHRShaderSubgroupExtendedTypesSpecVersion);
    n_vk.attr("KHR8_BIT_STORAGE_EXTENSION_NAME") = py::cast(::vk::KHR8BitStorageExtensionName);
    n_vk.attr("KHR8_BIT_STORAGE_SPEC_VERSION") = py::cast(::vk::KHR8BitStorageSpecVersion);
    n_vk.attr("EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME") = py::cast(::vk::EXTExternalMemoryHostExtensionName);
    n_vk.attr("EXT_EXTERNAL_MEMORY_HOST_SPEC_VERSION") = py::cast(::vk::EXTExternalMemoryHostSpecVersion);
    n_vk.attr("AMD_BUFFER_MARKER_EXTENSION_NAME") = py::cast(::vk::AMDBufferMarkerExtensionName);
    n_vk.attr("AMD_BUFFER_MARKER_SPEC_VERSION") = py::cast(::vk::AMDBufferMarkerSpecVersion);
    n_vk.attr("KHR_SHADER_ATOMIC_INT_64_EXTENSION_NAME") = py::cast(::vk::KHRShaderAtomicInt64ExtensionName);
    n_vk.attr("KHR_SHADER_ATOMIC_INT_64_SPEC_VERSION") = py::cast(::vk::KHRShaderAtomicInt64SpecVersion);
    n_vk.attr("KHR_SHADER_CLOCK_EXTENSION_NAME") = py::cast(::vk::KHRShaderClockExtensionName);
    n_vk.attr("KHR_SHADER_CLOCK_SPEC_VERSION") = py::cast(::vk::KHRShaderClockSpecVersion);
    n_vk.attr("AMD_PIPELINE_COMPILER_CONTROL_EXTENSION_NAME") = py::cast(::vk::AMDPipelineCompilerControlExtensionName);
    n_vk.attr("AMD_PIPELINE_COMPILER_CONTROL_SPEC_VERSION") = py::cast(::vk::AMDPipelineCompilerControlSpecVersion);
    n_vk.attr("EXT_CALIBRATED_TIMESTAMPS_EXTENSION_NAME") = py::cast(::vk::EXTCalibratedTimestampsExtensionName);
    n_vk.attr("EXT_CALIBRATED_TIMESTAMPS_SPEC_VERSION") = py::cast(::vk::EXTCalibratedTimestampsSpecVersion);
    n_vk.attr("AMD_SHADER_CORE_PROPERTIES_EXTENSION_NAME") = py::cast(::vk::AMDShaderCorePropertiesExtensionName);
    n_vk.attr("AMD_SHADER_CORE_PROPERTIES_SPEC_VERSION") = py::cast(::vk::AMDShaderCorePropertiesSpecVersion);
    n_vk.attr("KHR_VIDEO_DECODE_H265_EXTENSION_NAME") = py::cast(::vk::KHRVideoDecodeH265ExtensionName);
    n_vk.attr("KHR_VIDEO_DECODE_H265_SPEC_VERSION") = py::cast(::vk::KHRVideoDecodeH265SpecVersion);
    n_vk.attr("KHR_GLOBAL_PRIORITY_EXTENSION_NAME") = py::cast(::vk::KHRGlobalPriorityExtensionName);
    n_vk.attr("KHR_GLOBAL_PRIORITY_SPEC_VERSION") = py::cast(::vk::KHRGlobalPrioritySpecVersion);
    n_vk.attr("MAX_GLOBAL_PRIORITY_SIZE_KHR") = py::cast(::vk::MaxGlobalPrioritySizeKHR);
    n_vk.attr("AMD_MEMORY_OVERALLOCATION_BEHAVIOR_EXTENSION_NAME") = py::cast(::vk::AMDMemoryOverallocationBehaviorExtensionName);
    n_vk.attr("AMD_MEMORY_OVERALLOCATION_BEHAVIOR_SPEC_VERSION") = py::cast(::vk::AMDMemoryOverallocationBehaviorSpecVersion);
    n_vk.attr("EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME") = py::cast(::vk::EXTVertexAttributeDivisorExtensionName);
    n_vk.attr("EXT_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION") = py::cast(::vk::EXTVertexAttributeDivisorSpecVersion);
    n_vk.attr("EXT_PIPELINE_CREATION_FEEDBACK_EXTENSION_NAME") = py::cast(::vk::EXTPipelineCreationFeedbackExtensionName);
    n_vk.attr("EXT_PIPELINE_CREATION_FEEDBACK_SPEC_VERSION") = py::cast(::vk::EXTPipelineCreationFeedbackSpecVersion);
    n_vk.attr("KHR_DRIVER_PROPERTIES_EXTENSION_NAME") = py::cast(::vk::KHRDriverPropertiesExtensionName);
    n_vk.attr("KHR_DRIVER_PROPERTIES_SPEC_VERSION") = py::cast(::vk::KHRDriverPropertiesSpecVersion);
    n_vk.attr("MAX_DRIVER_INFO_SIZE_KHR") = py::cast(::vk::MaxDriverInfoSizeKHR);
    n_vk.attr("MAX_DRIVER_NAME_SIZE_KHR") = py::cast(::vk::MaxDriverNameSizeKHR);
    n_vk.attr("KHR_SHADER_FLOAT_CONTROLS_EXTENSION_NAME") = py::cast(::vk::KHRShaderFloatControlsExtensionName);
    n_vk.attr("KHR_SHADER_FLOAT_CONTROLS_SPEC_VERSION") = py::cast(::vk::KHRShaderFloatControlsSpecVersion);
    n_vk.attr("NV_SHADER_SUBGROUP_PARTITIONED_EXTENSION_NAME") = py::cast(::vk::NVShaderSubgroupPartitionedExtensionName);
    n_vk.attr("NV_SHADER_SUBGROUP_PARTITIONED_SPEC_VERSION") = py::cast(::vk::NVShaderSubgroupPartitionedSpecVersion);
    n_vk.attr("KHR_DEPTH_STENCIL_RESOLVE_EXTENSION_NAME") = py::cast(::vk::KHRDepthStencilResolveExtensionName);
    n_vk.attr("KHR_DEPTH_STENCIL_RESOLVE_SPEC_VERSION") = py::cast(::vk::KHRDepthStencilResolveSpecVersion);
    n_vk.attr("KHR_SWAPCHAIN_MUTABLE_FORMAT_EXTENSION_NAME") = py::cast(::vk::KHRSwapchainMutableFormatExtensionName);
    n_vk.attr("KHR_SWAPCHAIN_MUTABLE_FORMAT_SPEC_VERSION") = py::cast(::vk::KHRSwapchainMutableFormatSpecVersion);
    n_vk.attr("NV_COMPUTE_SHADER_DERIVATIVES_EXTENSION_NAME") = py::cast(::vk::NVComputeShaderDerivativesExtensionName);
    n_vk.attr("NV_COMPUTE_SHADER_DERIVATIVES_SPEC_VERSION") = py::cast(::vk::NVComputeShaderDerivativesSpecVersion);
    n_vk.attr("NV_MESH_SHADER_EXTENSION_NAME") = py::cast(::vk::NVMeshShaderExtensionName);
    n_vk.attr("NV_MESH_SHADER_SPEC_VERSION") = py::cast(::vk::NVMeshShaderSpecVersion);
    n_vk.attr("NV_FRAGMENT_SHADER_BARYCENTRIC_EXTENSION_NAME") = py::cast(::vk::NVFragmentShaderBarycentricExtensionName);
    n_vk.attr("NV_FRAGMENT_SHADER_BARYCENTRIC_SPEC_VERSION") = py::cast(::vk::NVFragmentShaderBarycentricSpecVersion);
    n_vk.attr("NV_SHADER_IMAGE_FOOTPRINT_EXTENSION_NAME") = py::cast(::vk::NVShaderImageFootprintExtensionName);
    n_vk.attr("NV_SHADER_IMAGE_FOOTPRINT_SPEC_VERSION") = py::cast(::vk::NVShaderImageFootprintSpecVersion);
    n_vk.attr("NV_SCISSOR_EXCLUSIVE_EXTENSION_NAME") = py::cast(::vk::NVScissorExclusiveExtensionName);
    n_vk.attr("NV_SCISSOR_EXCLUSIVE_SPEC_VERSION") = py::cast(::vk::NVScissorExclusiveSpecVersion);
    n_vk.attr("NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME") = py::cast(::vk::NVDeviceDiagnosticCheckpointsExtensionName);
    n_vk.attr("NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_SPEC_VERSION") = py::cast(::vk::NVDeviceDiagnosticCheckpointsSpecVersion);
    n_vk.attr("KHR_TIMELINE_SEMAPHORE_EXTENSION_NAME") = py::cast(::vk::KHRTimelineSemaphoreExtensionName);
    n_vk.attr("KHR_TIMELINE_SEMAPHORE_SPEC_VERSION") = py::cast(::vk::KHRTimelineSemaphoreSpecVersion);
    n_vk.attr("INTEL_SHADER_INTEGER_FUNCTIONS_2_EXTENSION_NAME") = py::cast(::vk::INTELShaderIntegerFunctions2ExtensionName);
    n_vk.attr("INTEL_SHADER_INTEGER_FUNCTIONS_2_SPEC_VERSION") = py::cast(::vk::INTELShaderIntegerFunctions2SpecVersion);
    n_vk.attr("INTEL_PERFORMANCE_QUERY_EXTENSION_NAME") = py::cast(::vk::INTELPerformanceQueryExtensionName);
    n_vk.attr("INTEL_PERFORMANCE_QUERY_SPEC_VERSION") = py::cast(::vk::INTELPerformanceQuerySpecVersion);
    n_vk.attr("KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME") = py::cast(::vk::KHRVulkanMemoryModelExtensionName);
    n_vk.attr("KHR_VULKAN_MEMORY_MODEL_SPEC_VERSION") = py::cast(::vk::KHRVulkanMemoryModelSpecVersion);
    n_vk.attr("EXT_PCI_BUS_INFO_EXTENSION_NAME") = py::cast(::vk::EXTPciBusInfoExtensionName);
    n_vk.attr("EXT_PCI_BUS_INFO_SPEC_VERSION") = py::cast(::vk::EXTPciBusInfoSpecVersion);
    n_vk.attr("AMD_DISPLAY_NATIVE_HDR_EXTENSION_NAME") = py::cast(::vk::AMDDisplayNativeHdrExtensionName);
    n_vk.attr("AMD_DISPLAY_NATIVE_HDR_SPEC_VERSION") = py::cast(::vk::AMDDisplayNativeHdrSpecVersion);
    n_vk.attr("KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME") = py::cast(::vk::KHRShaderTerminateInvocationExtensionName);
    n_vk.attr("KHR_SHADER_TERMINATE_INVOCATION_SPEC_VERSION") = py::cast(::vk::KHRShaderTerminateInvocationSpecVersion);
    n_vk.attr("EXT_FRAGMENT_DENSITY_MAP_EXTENSION_NAME") = py::cast(::vk::EXTFragmentDensityMapExtensionName);
    n_vk.attr("EXT_FRAGMENT_DENSITY_MAP_SPEC_VERSION") = py::cast(::vk::EXTFragmentDensityMapSpecVersion);
    n_vk.attr("EXT_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME") = py::cast(::vk::EXTScalarBlockLayoutExtensionName);
    n_vk.attr("EXT_SCALAR_BLOCK_LAYOUT_SPEC_VERSION") = py::cast(::vk::EXTScalarBlockLayoutSpecVersion);
    n_vk.attr("GOOGLE_HLSL_FUNCTIONALITY_1_EXTENSION_NAME") = py::cast(::vk::GOOGLEHlslFunctionality1ExtensionName);
    n_vk.attr("GOOGLE_HLSL_FUNCTIONALITY_1_SPEC_VERSION") = py::cast(::vk::GOOGLEHlslFunctionality1SpecVersion);
    n_vk.attr("GOOGLE_DECORATE_STRING_EXTENSION_NAME") = py::cast(::vk::GOOGLEDecorateStringExtensionName);
    n_vk.attr("GOOGLE_DECORATE_STRING_SPEC_VERSION") = py::cast(::vk::GOOGLEDecorateStringSpecVersion);
    n_vk.attr("EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME") = py::cast(::vk::EXTSubgroupSizeControlExtensionName);
    n_vk.attr("EXT_SUBGROUP_SIZE_CONTROL_SPEC_VERSION") = py::cast(::vk::EXTSubgroupSizeControlSpecVersion);
    n_vk.attr("KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME") = py::cast(::vk::KHRFragmentShadingRateExtensionName);
    n_vk.attr("KHR_FRAGMENT_SHADING_RATE_SPEC_VERSION") = py::cast(::vk::KHRFragmentShadingRateSpecVersion);
    n_vk.attr("AMD_SHADER_CORE_PROPERTIES_2_EXTENSION_NAME") = py::cast(::vk::AMDShaderCoreProperties2ExtensionName);
    n_vk.attr("AMD_SHADER_CORE_PROPERTIES_2_SPEC_VERSION") = py::cast(::vk::AMDShaderCoreProperties2SpecVersion);
    n_vk.attr("AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME") = py::cast(::vk::AMDDeviceCoherentMemoryExtensionName);
    n_vk.attr("AMD_DEVICE_COHERENT_MEMORY_SPEC_VERSION") = py::cast(::vk::AMDDeviceCoherentMemorySpecVersion);
    n_vk.attr("EXT_SHADER_IMAGE_ATOMIC_INT_64_EXTENSION_NAME") = py::cast(::vk::EXTShaderImageAtomicInt64ExtensionName);
    n_vk.attr("EXT_SHADER_IMAGE_ATOMIC_INT_64_SPEC_VERSION") = py::cast(::vk::EXTShaderImageAtomicInt64SpecVersion);
    n_vk.attr("KHR_SPIRV_14_EXTENSION_NAME") = py::cast(::vk::KHRSpirv14ExtensionName);
    n_vk.attr("KHR_SPIRV_14_SPEC_VERSION") = py::cast(::vk::KHRSpirv14SpecVersion);
    n_vk.attr("EXT_MEMORY_BUDGET_EXTENSION_NAME") = py::cast(::vk::EXTMemoryBudgetExtensionName);
    n_vk.attr("EXT_MEMORY_BUDGET_SPEC_VERSION") = py::cast(::vk::EXTMemoryBudgetSpecVersion);
    n_vk.attr("EXT_MEMORY_PRIORITY_EXTENSION_NAME") = py::cast(::vk::EXTMemoryPriorityExtensionName);
    n_vk.attr("EXT_MEMORY_PRIORITY_SPEC_VERSION") = py::cast(::vk::EXTMemoryPrioritySpecVersion);
    n_vk.attr("KHR_SURFACE_PROTECTED_CAPABILITIES_EXTENSION_NAME") = py::cast(::vk::KHRSurfaceProtectedCapabilitiesExtensionName);
    n_vk.attr("KHR_SURFACE_PROTECTED_CAPABILITIES_SPEC_VERSION") = py::cast(::vk::KHRSurfaceProtectedCapabilitiesSpecVersion);
    n_vk.attr("NV_DEDICATED_ALLOCATION_IMAGE_ALIASING_EXTENSION_NAME") = py::cast(::vk::NVDedicatedAllocationImageAliasingExtensionName);
    n_vk.attr("NV_DEDICATED_ALLOCATION_IMAGE_ALIASING_SPEC_VERSION") = py::cast(::vk::NVDedicatedAllocationImageAliasingSpecVersion);
    n_vk.attr("KHR_SEPARATE_DEPTH_STENCIL_LAYOUTS_EXTENSION_NAME") = py::cast(::vk::KHRSeparateDepthStencilLayoutsExtensionName);
    n_vk.attr("KHR_SEPARATE_DEPTH_STENCIL_LAYOUTS_SPEC_VERSION") = py::cast(::vk::KHRSeparateDepthStencilLayoutsSpecVersion);
    n_vk.attr("EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME") = py::cast(::vk::EXTBufferDeviceAddressExtensionName);
    n_vk.attr("EXT_BUFFER_DEVICE_ADDRESS_SPEC_VERSION") = py::cast(::vk::EXTBufferDeviceAddressSpecVersion);
    n_vk.attr("EXT_TOOLING_INFO_EXTENSION_NAME") = py::cast(::vk::EXTToolingInfoExtensionName);
    n_vk.attr("EXT_TOOLING_INFO_SPEC_VERSION") = py::cast(::vk::EXTToolingInfoSpecVersion);
    n_vk.attr("EXT_SEPARATE_STENCIL_USAGE_EXTENSION_NAME") = py::cast(::vk::EXTSeparateStencilUsageExtensionName);
    n_vk.attr("EXT_SEPARATE_STENCIL_USAGE_SPEC_VERSION") = py::cast(::vk::EXTSeparateStencilUsageSpecVersion);
    n_vk.attr("EXT_VALIDATION_FEATURES_EXTENSION_NAME") = py::cast(::vk::EXTValidationFeaturesExtensionName);
    n_vk.attr("EXT_VALIDATION_FEATURES_SPEC_VERSION") = py::cast(::vk::EXTValidationFeaturesSpecVersion);
    n_vk.attr("KHR_PRESENT_WAIT_EXTENSION_NAME") = py::cast(::vk::KHRPresentWaitExtensionName);
    n_vk.attr("KHR_PRESENT_WAIT_SPEC_VERSION") = py::cast(::vk::KHRPresentWaitSpecVersion);
    n_vk.attr("NV_COOPERATIVE_MATRIX_EXTENSION_NAME") = py::cast(::vk::NVCooperativeMatrixExtensionName);
    n_vk.attr("NV_COOPERATIVE_MATRIX_SPEC_VERSION") = py::cast(::vk::NVCooperativeMatrixSpecVersion);
    n_vk.attr("NV_COVERAGE_REDUCTION_MODE_EXTENSION_NAME") = py::cast(::vk::NVCoverageReductionModeExtensionName);
    n_vk.attr("NV_COVERAGE_REDUCTION_MODE_SPEC_VERSION") = py::cast(::vk::NVCoverageReductionModeSpecVersion);
    n_vk.attr("EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME") = py::cast(::vk::EXTFragmentShaderInterlockExtensionName);
    n_vk.attr("EXT_FRAGMENT_SHADER_INTERLOCK_SPEC_VERSION") = py::cast(::vk::EXTFragmentShaderInterlockSpecVersion);
    n_vk.attr("EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME") = py::cast(::vk::EXTYcbcrImageArraysExtensionName);
    n_vk.attr("EXT_YCBCR_IMAGE_ARRAYS_SPEC_VERSION") = py::cast(::vk::EXTYcbcrImageArraysSpecVersion);
    n_vk.attr("KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME") = py::cast(::vk::KHRUniformBufferStandardLayoutExtensionName);
    n_vk.attr("KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_SPEC_VERSION") = py::cast(::vk::KHRUniformBufferStandardLayoutSpecVersion);
    n_vk.attr("EXT_PROVOKING_VERTEX_EXTENSION_NAME") = py::cast(::vk::EXTProvokingVertexExtensionName);
    n_vk.attr("EXT_PROVOKING_VERTEX_SPEC_VERSION") = py::cast(::vk::EXTProvokingVertexSpecVersion);
    n_vk.attr("EXT_HEADLESS_SURFACE_EXTENSION_NAME") = py::cast(::vk::EXTHeadlessSurfaceExtensionName);
    n_vk.attr("EXT_HEADLESS_SURFACE_SPEC_VERSION") = py::cast(::vk::EXTHeadlessSurfaceSpecVersion);
    n_vk.attr("KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME") = py::cast(::vk::KHRBufferDeviceAddressExtensionName);
    n_vk.attr("KHR_BUFFER_DEVICE_ADDRESS_SPEC_VERSION") = py::cast(::vk::KHRBufferDeviceAddressSpecVersion);
    n_vk.attr("EXT_LINE_RASTERIZATION_EXTENSION_NAME") = py::cast(::vk::EXTLineRasterizationExtensionName);
    n_vk.attr("EXT_LINE_RASTERIZATION_SPEC_VERSION") = py::cast(::vk::EXTLineRasterizationSpecVersion);
    n_vk.attr("EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME") = py::cast(::vk::EXTShaderAtomicFloatExtensionName);
    n_vk.attr("EXT_SHADER_ATOMIC_FLOAT_SPEC_VERSION") = py::cast(::vk::EXTShaderAtomicFloatSpecVersion);
    n_vk.attr("EXT_HOST_QUERY_RESET_EXTENSION_NAME") = py::cast(::vk::EXTHostQueryResetExtensionName);
    n_vk.attr("EXT_HOST_QUERY_RESET_SPEC_VERSION") = py::cast(::vk::EXTHostQueryResetSpecVersion);
    n_vk.attr("EXT_INDEX_TYPE_UINT_8_EXTENSION_NAME") = py::cast(::vk::EXTIndexTypeUint8ExtensionName);
    n_vk.attr("EXT_INDEX_TYPE_UINT_8_SPEC_VERSION") = py::cast(::vk::EXTIndexTypeUint8SpecVersion);
    n_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME") = py::cast(::vk::EXTExtendedDynamicStateExtensionName);
    n_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_SPEC_VERSION") = py::cast(::vk::EXTExtendedDynamicStateSpecVersion);
    n_vk.attr("KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME") = py::cast(::vk::KHRDeferredHostOperationsExtensionName);
    n_vk.attr("KHR_DEFERRED_HOST_OPERATIONS_SPEC_VERSION") = py::cast(::vk::KHRDeferredHostOperationsSpecVersion);
    n_vk.attr("KHR_PIPELINE_EXECUTABLE_PROPERTIES_EXTENSION_NAME") = py::cast(::vk::KHRPipelineExecutablePropertiesExtensionName);
    n_vk.attr("KHR_PIPELINE_EXECUTABLE_PROPERTIES_SPEC_VERSION") = py::cast(::vk::KHRPipelineExecutablePropertiesSpecVersion);
    n_vk.attr("EXT_HOST_IMAGE_COPY_EXTENSION_NAME") = py::cast(::vk::EXTHostImageCopyExtensionName);
    n_vk.attr("EXT_HOST_IMAGE_COPY_SPEC_VERSION") = py::cast(::vk::EXTHostImageCopySpecVersion);
    n_vk.attr("KHR_MAP_MEMORY_2_EXTENSION_NAME") = py::cast(::vk::KHRMapMemory2ExtensionName);
    n_vk.attr("KHR_MAP_MEMORY_2_SPEC_VERSION") = py::cast(::vk::KHRMapMemory2SpecVersion);
    n_vk.attr("EXT_SHADER_ATOMIC_FLOAT_2_EXTENSION_NAME") = py::cast(::vk::EXTShaderAtomicFloat2ExtensionName);
    n_vk.attr("EXT_SHADER_ATOMIC_FLOAT_2_SPEC_VERSION") = py::cast(::vk::EXTShaderAtomicFloat2SpecVersion);
    n_vk.attr("EXT_SURFACE_MAINTENANCE_1_EXTENSION_NAME") = py::cast(::vk::EXTSurfaceMaintenance1ExtensionName);
    n_vk.attr("EXT_SURFACE_MAINTENANCE_1_SPEC_VERSION") = py::cast(::vk::EXTSurfaceMaintenance1SpecVersion);
    n_vk.attr("EXT_SWAPCHAIN_MAINTENANCE_1_EXTENSION_NAME") = py::cast(::vk::EXTSwapchainMaintenance1ExtensionName);
    n_vk.attr("EXT_SWAPCHAIN_MAINTENANCE_1_SPEC_VERSION") = py::cast(::vk::EXTSwapchainMaintenance1SpecVersion);
    n_vk.attr("EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME") = py::cast(::vk::EXTShaderDemoteToHelperInvocationExtensionName);
    n_vk.attr("EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_SPEC_VERSION") = py::cast(::vk::EXTShaderDemoteToHelperInvocationSpecVersion);
    n_vk.attr("NV_DEVICE_GENERATED_COMMANDS_EXTENSION_NAME") = py::cast(::vk::NVDeviceGeneratedCommandsExtensionName);
    n_vk.attr("NV_DEVICE_GENERATED_COMMANDS_SPEC_VERSION") = py::cast(::vk::NVDeviceGeneratedCommandsSpecVersion);
    n_vk.attr("NV_INHERITED_VIEWPORT_SCISSOR_EXTENSION_NAME") = py::cast(::vk::NVInheritedViewportScissorExtensionName);
    n_vk.attr("NV_INHERITED_VIEWPORT_SCISSOR_SPEC_VERSION") = py::cast(::vk::NVInheritedViewportScissorSpecVersion);
    n_vk.attr("KHR_SHADER_INTEGER_DOT_PRODUCT_EXTENSION_NAME") = py::cast(::vk::KHRShaderIntegerDotProductExtensionName);
    n_vk.attr("KHR_SHADER_INTEGER_DOT_PRODUCT_SPEC_VERSION") = py::cast(::vk::KHRShaderIntegerDotProductSpecVersion);
    n_vk.attr("EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME") = py::cast(::vk::EXTTexelBufferAlignmentExtensionName);
    n_vk.attr("EXT_TEXEL_BUFFER_ALIGNMENT_SPEC_VERSION") = py::cast(::vk::EXTTexelBufferAlignmentSpecVersion);
    n_vk.attr("QCOM_RENDER_PASS_TRANSFORM_EXTENSION_NAME") = py::cast(::vk::QCOMRenderPassTransformExtensionName);
    n_vk.attr("QCOM_RENDER_PASS_TRANSFORM_SPEC_VERSION") = py::cast(::vk::QCOMRenderPassTransformSpecVersion);
    n_vk.attr("EXT_DEPTH_BIAS_CONTROL_EXTENSION_NAME") = py::cast(::vk::EXTDepthBiasControlExtensionName);
    n_vk.attr("EXT_DEPTH_BIAS_CONTROL_SPEC_VERSION") = py::cast(::vk::EXTDepthBiasControlSpecVersion);
    n_vk.attr("EXT_DEVICE_MEMORY_REPORT_EXTENSION_NAME") = py::cast(::vk::EXTDeviceMemoryReportExtensionName);
    n_vk.attr("EXT_DEVICE_MEMORY_REPORT_SPEC_VERSION") = py::cast(::vk::EXTDeviceMemoryReportSpecVersion);
    n_vk.attr("EXT_ACQUIRE_DRM_DISPLAY_EXTENSION_NAME") = py::cast(::vk::EXTAcquireDrmDisplayExtensionName);
    n_vk.attr("EXT_ACQUIRE_DRM_DISPLAY_SPEC_VERSION") = py::cast(::vk::EXTAcquireDrmDisplaySpecVersion);
    n_vk.attr("EXT_ROBUSTNESS_2_EXTENSION_NAME") = py::cast(::vk::EXTRobustness2ExtensionName);
    n_vk.attr("EXT_ROBUSTNESS_2_SPEC_VERSION") = py::cast(::vk::EXTRobustness2SpecVersion);
    n_vk.attr("EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME") = py::cast(::vk::EXTCustomBorderColorExtensionName);
    n_vk.attr("EXT_CUSTOM_BORDER_COLOR_SPEC_VERSION") = py::cast(::vk::EXTCustomBorderColorSpecVersion);
    n_vk.attr("GOOGLE_USER_TYPE_EXTENSION_NAME") = py::cast(::vk::GOOGLEUserTypeExtensionName);
    n_vk.attr("GOOGLE_USER_TYPE_SPEC_VERSION") = py::cast(::vk::GOOGLEUserTypeSpecVersion);
    n_vk.attr("KHR_PIPELINE_LIBRARY_EXTENSION_NAME") = py::cast(::vk::KHRPipelineLibraryExtensionName);
    n_vk.attr("KHR_PIPELINE_LIBRARY_SPEC_VERSION") = py::cast(::vk::KHRPipelineLibrarySpecVersion);
    n_vk.attr("NV_PRESENT_BARRIER_EXTENSION_NAME") = py::cast(::vk::NVPresentBarrierExtensionName);
    n_vk.attr("NV_PRESENT_BARRIER_SPEC_VERSION") = py::cast(::vk::NVPresentBarrierSpecVersion);
    n_vk.attr("KHR_SHADER_NON_SEMANTIC_INFO_EXTENSION_NAME") = py::cast(::vk::KHRShaderNonSemanticInfoExtensionName);
    n_vk.attr("KHR_SHADER_NON_SEMANTIC_INFO_SPEC_VERSION") = py::cast(::vk::KHRShaderNonSemanticInfoSpecVersion);
    n_vk.attr("KHR_PRESENT_ID_EXTENSION_NAME") = py::cast(::vk::KHRPresentIdExtensionName);
    n_vk.attr("KHR_PRESENT_ID_SPEC_VERSION") = py::cast(::vk::KHRPresentIdSpecVersion);
    n_vk.attr("EXT_PRIVATE_DATA_EXTENSION_NAME") = py::cast(::vk::EXTPrivateDataExtensionName);
    n_vk.attr("EXT_PRIVATE_DATA_SPEC_VERSION") = py::cast(::vk::EXTPrivateDataSpecVersion);
    n_vk.attr("EXT_PIPELINE_CREATION_CACHE_CONTROL_EXTENSION_NAME") = py::cast(::vk::EXTPipelineCreationCacheControlExtensionName);
    n_vk.attr("EXT_PIPELINE_CREATION_CACHE_CONTROL_SPEC_VERSION") = py::cast(::vk::EXTPipelineCreationCacheControlSpecVersion);
    n_vk.attr("KHR_VIDEO_ENCODE_QUEUE_EXTENSION_NAME") = py::cast(::vk::KHRVideoEncodeQueueExtensionName);
    n_vk.attr("KHR_VIDEO_ENCODE_QUEUE_SPEC_VERSION") = py::cast(::vk::KHRVideoEncodeQueueSpecVersion);
    n_vk.attr("NV_DEVICE_DIAGNOSTICS_CONFIG_EXTENSION_NAME") = py::cast(::vk::NVDeviceDiagnosticsConfigExtensionName);
    n_vk.attr("NV_DEVICE_DIAGNOSTICS_CONFIG_SPEC_VERSION") = py::cast(::vk::NVDeviceDiagnosticsConfigSpecVersion);
    n_vk.attr("QCOM_RENDER_PASS_STORE_OPS_EXTENSION_NAME") = py::cast(::vk::QCOMRenderPassStoreOpsExtensionName);
    n_vk.attr("QCOM_RENDER_PASS_STORE_OPS_SPEC_VERSION") = py::cast(::vk::QCOMRenderPassStoreOpsSpecVersion);
    n_vk.attr("NV_LOW_LATENCY_EXTENSION_NAME") = py::cast(::vk::NVLowLatencyExtensionName);
    n_vk.attr("NV_LOW_LATENCY_SPEC_VERSION") = py::cast(::vk::NVLowLatencySpecVersion);
    n_vk.attr("KHR_SYNCHRONIZATION_2_EXTENSION_NAME") = py::cast(::vk::KHRSynchronization2ExtensionName);
    n_vk.attr("KHR_SYNCHRONIZATION_2_SPEC_VERSION") = py::cast(::vk::KHRSynchronization2SpecVersion);
    n_vk.attr("EXT_DESCRIPTOR_BUFFER_EXTENSION_NAME") = py::cast(::vk::EXTDescriptorBufferExtensionName);
    n_vk.attr("EXT_DESCRIPTOR_BUFFER_SPEC_VERSION") = py::cast(::vk::EXTDescriptorBufferSpecVersion);
    n_vk.attr("EXT_GRAPHICS_PIPELINE_LIBRARY_EXTENSION_NAME") = py::cast(::vk::EXTGraphicsPipelineLibraryExtensionName);
    n_vk.attr("EXT_GRAPHICS_PIPELINE_LIBRARY_SPEC_VERSION") = py::cast(::vk::EXTGraphicsPipelineLibrarySpecVersion);
    n_vk.attr("AMD_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_EXTENSION_NAME") = py::cast(::vk::AMDShaderEarlyAndLateFragmentTestsExtensionName);
    n_vk.attr("AMD_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_SPEC_VERSION") = py::cast(::vk::AMDShaderEarlyAndLateFragmentTestsSpecVersion);
    n_vk.attr("KHR_FRAGMENT_SHADER_BARYCENTRIC_EXTENSION_NAME") = py::cast(::vk::KHRFragmentShaderBarycentricExtensionName);
    n_vk.attr("KHR_FRAGMENT_SHADER_BARYCENTRIC_SPEC_VERSION") = py::cast(::vk::KHRFragmentShaderBarycentricSpecVersion);
    n_vk.attr("KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_EXTENSION_NAME") = py::cast(::vk::KHRShaderSubgroupUniformControlFlowExtensionName);
    n_vk.attr("KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_SPEC_VERSION") = py::cast(::vk::KHRShaderSubgroupUniformControlFlowSpecVersion);
    n_vk.attr("KHR_ZERO_INITIALIZE_WORKGROUP_MEMORY_EXTENSION_NAME") = py::cast(::vk::KHRZeroInitializeWorkgroupMemoryExtensionName);
    n_vk.attr("KHR_ZERO_INITIALIZE_WORKGROUP_MEMORY_SPEC_VERSION") = py::cast(::vk::KHRZeroInitializeWorkgroupMemorySpecVersion);
    n_vk.attr("NV_FRAGMENT_SHADING_RATE_ENUMS_EXTENSION_NAME") = py::cast(::vk::NVFragmentShadingRateEnumsExtensionName);
    n_vk.attr("NV_FRAGMENT_SHADING_RATE_ENUMS_SPEC_VERSION") = py::cast(::vk::NVFragmentShadingRateEnumsSpecVersion);
    n_vk.attr("NV_RAY_TRACING_MOTION_BLUR_EXTENSION_NAME") = py::cast(::vk::NVRayTracingMotionBlurExtensionName);
    n_vk.attr("NV_RAY_TRACING_MOTION_BLUR_SPEC_VERSION") = py::cast(::vk::NVRayTracingMotionBlurSpecVersion);
    n_vk.attr("EXT_MESH_SHADER_EXTENSION_NAME") = py::cast(::vk::EXTMeshShaderExtensionName);
    n_vk.attr("EXT_MESH_SHADER_SPEC_VERSION") = py::cast(::vk::EXTMeshShaderSpecVersion);
    n_vk.attr("EXT_YCBCR_2_PLANE_444_FORMATS_EXTENSION_NAME") = py::cast(::vk::EXTYcbcr2Plane444FormatsExtensionName);
    n_vk.attr("EXT_YCBCR_2_PLANE_444_FORMATS_SPEC_VERSION") = py::cast(::vk::EXTYcbcr2Plane444FormatsSpecVersion);
    n_vk.attr("EXT_FRAGMENT_DENSITY_MAP_2_EXTENSION_NAME") = py::cast(::vk::EXTFragmentDensityMap2ExtensionName);
    n_vk.attr("EXT_FRAGMENT_DENSITY_MAP_2_SPEC_VERSION") = py::cast(::vk::EXTFragmentDensityMap2SpecVersion);
    n_vk.attr("QCOM_ROTATED_COPY_COMMANDS_EXTENSION_NAME") = py::cast(::vk::QCOMRotatedCopyCommandsExtensionName);
    n_vk.attr("QCOM_ROTATED_COPY_COMMANDS_SPEC_VERSION") = py::cast(::vk::QCOMRotatedCopyCommandsSpecVersion);
    n_vk.attr("EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME") = py::cast(::vk::EXTImageRobustnessExtensionName);
    n_vk.attr("EXT_IMAGE_ROBUSTNESS_SPEC_VERSION") = py::cast(::vk::EXTImageRobustnessSpecVersion);
    n_vk.attr("KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_EXTENSION_NAME") = py::cast(::vk::KHRWorkgroupMemoryExplicitLayoutExtensionName);
    n_vk.attr("KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_SPEC_VERSION") = py::cast(::vk::KHRWorkgroupMemoryExplicitLayoutSpecVersion);
    n_vk.attr("KHR_COPY_COMMANDS_2_EXTENSION_NAME") = py::cast(::vk::KHRCopyCommands2ExtensionName);
    n_vk.attr("KHR_COPY_COMMANDS_2_SPEC_VERSION") = py::cast(::vk::KHRCopyCommands2SpecVersion);
    n_vk.attr("EXT_IMAGE_COMPRESSION_CONTROL_EXTENSION_NAME") = py::cast(::vk::EXTImageCompressionControlExtensionName);
    n_vk.attr("EXT_IMAGE_COMPRESSION_CONTROL_SPEC_VERSION") = py::cast(::vk::EXTImageCompressionControlSpecVersion);
    n_vk.attr("EXT_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_EXTENSION_NAME") = py::cast(::vk::EXTAttachmentFeedbackLoopLayoutExtensionName);
    n_vk.attr("EXT_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_SPEC_VERSION") = py::cast(::vk::EXTAttachmentFeedbackLoopLayoutSpecVersion);
    n_vk.attr("EXT4444_FORMATS_EXTENSION_NAME") = py::cast(::vk::EXT4444FormatsExtensionName);
    n_vk.attr("EXT4444_FORMATS_SPEC_VERSION") = py::cast(::vk::EXT4444FormatsSpecVersion);
    n_vk.attr("EXT_DEVICE_FAULT_EXTENSION_NAME") = py::cast(::vk::EXTDeviceFaultExtensionName);
    n_vk.attr("EXT_DEVICE_FAULT_SPEC_VERSION") = py::cast(::vk::EXTDeviceFaultSpecVersion);
    n_vk.attr("ARM_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXTENSION_NAME") = py::cast(::vk::ARMRasterizationOrderAttachmentAccessExtensionName);
    n_vk.attr("ARM_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_SPEC_VERSION") = py::cast(::vk::ARMRasterizationOrderAttachmentAccessSpecVersion);
    n_vk.attr("EXT_RGBA_10X6_FORMATS_EXTENSION_NAME") = py::cast(::vk::EXTRgba10X6FormatsExtensionName);
    n_vk.attr("EXT_RGBA_10X6_FORMATS_SPEC_VERSION") = py::cast(::vk::EXTRgba10X6FormatsSpecVersion);
    n_vk.attr("VALVE_MUTABLE_DESCRIPTOR_TYPE_EXTENSION_NAME") = py::cast(::vk::VALVEMutableDescriptorTypeExtensionName);
    n_vk.attr("VALVE_MUTABLE_DESCRIPTOR_TYPE_SPEC_VERSION") = py::cast(::vk::VALVEMutableDescriptorTypeSpecVersion);
    n_vk.attr("EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME") = py::cast(::vk::EXTVertexInputDynamicStateExtensionName);
    n_vk.attr("EXT_VERTEX_INPUT_DYNAMIC_STATE_SPEC_VERSION") = py::cast(::vk::EXTVertexInputDynamicStateSpecVersion);
    n_vk.attr("EXT_PHYSICAL_DEVICE_DRM_EXTENSION_NAME") = py::cast(::vk::EXTPhysicalDeviceDrmExtensionName);
    n_vk.attr("EXT_PHYSICAL_DEVICE_DRM_SPEC_VERSION") = py::cast(::vk::EXTPhysicalDeviceDrmSpecVersion);
    n_vk.attr("EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME") = py::cast(::vk::EXTDeviceAddressBindingReportExtensionName);
    n_vk.attr("EXT_DEVICE_ADDRESS_BINDING_REPORT_SPEC_VERSION") = py::cast(::vk::EXTDeviceAddressBindingReportSpecVersion);
    n_vk.attr("EXT_DEPTH_CLIP_CONTROL_EXTENSION_NAME") = py::cast(::vk::EXTDepthClipControlExtensionName);
    n_vk.attr("EXT_DEPTH_CLIP_CONTROL_SPEC_VERSION") = py::cast(::vk::EXTDepthClipControlSpecVersion);
    n_vk.attr("EXT_PRIMITIVE_TOPOLOGY_LIST_RESTART_EXTENSION_NAME") = py::cast(::vk::EXTPrimitiveTopologyListRestartExtensionName);
    n_vk.attr("EXT_PRIMITIVE_TOPOLOGY_LIST_RESTART_SPEC_VERSION") = py::cast(::vk::EXTPrimitiveTopologyListRestartSpecVersion);
    n_vk.attr("KHR_FORMAT_FEATURE_FLAGS_2_EXTENSION_NAME") = py::cast(::vk::KHRFormatFeatureFlags2ExtensionName);
    n_vk.attr("KHR_FORMAT_FEATURE_FLAGS_2_SPEC_VERSION") = py::cast(::vk::KHRFormatFeatureFlags2SpecVersion);
    n_vk.attr("HUAWEI_SUBPASS_SHADING_EXTENSION_NAME") = py::cast(::vk::HUAWEISubpassShadingExtensionName);
    n_vk.attr("HUAWEI_SUBPASS_SHADING_SPEC_VERSION") = py::cast(::vk::HUAWEISubpassShadingSpecVersion);
    n_vk.attr("HUAWEI_INVOCATION_MASK_EXTENSION_NAME") = py::cast(::vk::HUAWEIInvocationMaskExtensionName);
    n_vk.attr("HUAWEI_INVOCATION_MASK_SPEC_VERSION") = py::cast(::vk::HUAWEIInvocationMaskSpecVersion);
    n_vk.attr("NV_EXTERNAL_MEMORY_RDMA_EXTENSION_NAME") = py::cast(::vk::NVExternalMemoryRdmaExtensionName);
    n_vk.attr("NV_EXTERNAL_MEMORY_RDMA_SPEC_VERSION") = py::cast(::vk::NVExternalMemoryRdmaSpecVersion);
    n_vk.attr("EXT_PIPELINE_PROPERTIES_EXTENSION_NAME") = py::cast(::vk::EXTPipelinePropertiesExtensionName);
    n_vk.attr("EXT_PIPELINE_PROPERTIES_SPEC_VERSION") = py::cast(::vk::EXTPipelinePropertiesSpecVersion);
    n_vk.attr("EXT_FRAME_BOUNDARY_EXTENSION_NAME") = py::cast(::vk::EXTFrameBoundaryExtensionName);
    n_vk.attr("EXT_FRAME_BOUNDARY_SPEC_VERSION") = py::cast(::vk::EXTFrameBoundarySpecVersion);
    n_vk.attr("EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_EXTENSION_NAME") = py::cast(::vk::EXTMultisampledRenderToSingleSampledExtensionName);
    n_vk.attr("EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_SPEC_VERSION") = py::cast(::vk::EXTMultisampledRenderToSingleSampledSpecVersion);
    n_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME") = py::cast(::vk::EXTExtendedDynamicState2ExtensionName);
    n_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_2_SPEC_VERSION") = py::cast(::vk::EXTExtendedDynamicState2SpecVersion);
    n_vk.attr("EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME") = py::cast(::vk::EXTColorWriteEnableExtensionName);
    n_vk.attr("EXT_COLOR_WRITE_ENABLE_SPEC_VERSION") = py::cast(::vk::EXTColorWriteEnableSpecVersion);
    n_vk.attr("EXT_PRIMITIVES_GENERATED_QUERY_EXTENSION_NAME") = py::cast(::vk::EXTPrimitivesGeneratedQueryExtensionName);
    n_vk.attr("EXT_PRIMITIVES_GENERATED_QUERY_SPEC_VERSION") = py::cast(::vk::EXTPrimitivesGeneratedQuerySpecVersion);
    n_vk.attr("KHR_RAY_TRACING_MAINTENANCE_1_EXTENSION_NAME") = py::cast(::vk::KHRRayTracingMaintenance1ExtensionName);
    n_vk.attr("KHR_RAY_TRACING_MAINTENANCE_1_SPEC_VERSION") = py::cast(::vk::KHRRayTracingMaintenance1SpecVersion);
    n_vk.attr("EXT_GLOBAL_PRIORITY_QUERY_EXTENSION_NAME") = py::cast(::vk::EXTGlobalPriorityQueryExtensionName);
    n_vk.attr("EXT_GLOBAL_PRIORITY_QUERY_SPEC_VERSION") = py::cast(::vk::EXTGlobalPriorityQuerySpecVersion);
    n_vk.attr("MAX_GLOBAL_PRIORITY_SIZE_EXT") = py::cast(::vk::MaxGlobalPrioritySizeEXT);
    n_vk.attr("EXT_IMAGE_VIEW_MIN_LOD_EXTENSION_NAME") = py::cast(::vk::EXTImageViewMinLodExtensionName);
    n_vk.attr("EXT_IMAGE_VIEW_MIN_LOD_SPEC_VERSION") = py::cast(::vk::EXTImageViewMinLodSpecVersion);
    n_vk.attr("EXT_MULTI_DRAW_EXTENSION_NAME") = py::cast(::vk::EXTMultiDrawExtensionName);
    n_vk.attr("EXT_MULTI_DRAW_SPEC_VERSION") = py::cast(::vk::EXTMultiDrawSpecVersion);
    n_vk.attr("EXT_IMAGE_2D_VIEW_OF_3D_EXTENSION_NAME") = py::cast(::vk::EXTImage2DViewOf3DExtensionName);
    n_vk.attr("EXT_IMAGE_2D_VIEW_OF_3D_SPEC_VERSION") = py::cast(::vk::EXTImage2DViewOf3DSpecVersion);
    n_vk.attr("KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME") = py::cast(::vk::KHRPortabilityEnumerationExtensionName);
    n_vk.attr("KHR_PORTABILITY_ENUMERATION_SPEC_VERSION") = py::cast(::vk::KHRPortabilityEnumerationSpecVersion);
    n_vk.attr("EXT_SHADER_TILE_IMAGE_EXTENSION_NAME") = py::cast(::vk::EXTShaderTileImageExtensionName);
    n_vk.attr("EXT_SHADER_TILE_IMAGE_SPEC_VERSION") = py::cast(::vk::EXTShaderTileImageSpecVersion);
    n_vk.attr("EXT_OPACITY_MICROMAP_EXTENSION_NAME") = py::cast(::vk::EXTOpacityMicromapExtensionName);
    n_vk.attr("EXT_OPACITY_MICROMAP_SPEC_VERSION") = py::cast(::vk::EXTOpacityMicromapSpecVersion);
    n_vk.attr("EXT_LOAD_STORE_OP_NONE_EXTENSION_NAME") = py::cast(::vk::EXTLoadStoreOpNoneExtensionName);
    n_vk.attr("EXT_LOAD_STORE_OP_NONE_SPEC_VERSION") = py::cast(::vk::EXTLoadStoreOpNoneSpecVersion);
    n_vk.attr("HUAWEI_CLUSTER_CULLING_SHADER_EXTENSION_NAME") = py::cast(::vk::HUAWEIClusterCullingShaderExtensionName);
    n_vk.attr("HUAWEI_CLUSTER_CULLING_SHADER_SPEC_VERSION") = py::cast(::vk::HUAWEIClusterCullingShaderSpecVersion);
    n_vk.attr("EXT_BORDER_COLOR_SWIZZLE_EXTENSION_NAME") = py::cast(::vk::EXTBorderColorSwizzleExtensionName);
    n_vk.attr("EXT_BORDER_COLOR_SWIZZLE_SPEC_VERSION") = py::cast(::vk::EXTBorderColorSwizzleSpecVersion);
    n_vk.attr("EXT_PAGEABLE_DEVICE_LOCAL_MEMORY_EXTENSION_NAME") = py::cast(::vk::EXTPageableDeviceLocalMemoryExtensionName);
    n_vk.attr("EXT_PAGEABLE_DEVICE_LOCAL_MEMORY_SPEC_VERSION") = py::cast(::vk::EXTPageableDeviceLocalMemorySpecVersion);
    n_vk.attr("KHR_MAINTENANCE_4_EXTENSION_NAME") = py::cast(::vk::KHRMaintenance4ExtensionName);
    n_vk.attr("KHR_MAINTENANCE_4_SPEC_VERSION") = py::cast(::vk::KHRMaintenance4SpecVersion);
    n_vk.attr("ARM_SHADER_CORE_PROPERTIES_EXTENSION_NAME") = py::cast(::vk::ARMShaderCorePropertiesExtensionName);
    n_vk.attr("ARM_SHADER_CORE_PROPERTIES_SPEC_VERSION") = py::cast(::vk::ARMShaderCorePropertiesSpecVersion);
    n_vk.attr("ARM_SCHEDULING_CONTROLS_EXTENSION_NAME") = py::cast(::vk::ARMSchedulingControlsExtensionName);
    n_vk.attr("ARM_SCHEDULING_CONTROLS_SPEC_VERSION") = py::cast(::vk::ARMSchedulingControlsSpecVersion);
    n_vk.attr("EXT_IMAGE_SLICED_VIEW_OF_3D_EXTENSION_NAME") = py::cast(::vk::EXTImageSlicedViewOf3DExtensionName);
    n_vk.attr("EXT_IMAGE_SLICED_VIEW_OF_3D_SPEC_VERSION") = py::cast(::vk::EXTImageSlicedViewOf3DSpecVersion);
    n_vk.attr("REMAINING_3D_SLICES_EXT") = py::cast(::vk::Remaining3DSlicesEXT);
    n_vk.attr("VALVE_DESCRIPTOR_SET_HOST_MAPPING_EXTENSION_NAME") = py::cast(::vk::VALVEDescriptorSetHostMappingExtensionName);
    n_vk.attr("VALVE_DESCRIPTOR_SET_HOST_MAPPING_SPEC_VERSION") = py::cast(::vk::VALVEDescriptorSetHostMappingSpecVersion);
    n_vk.attr("EXT_DEPTH_CLAMP_ZERO_ONE_EXTENSION_NAME") = py::cast(::vk::EXTDepthClampZeroOneExtensionName);
    n_vk.attr("EXT_DEPTH_CLAMP_ZERO_ONE_SPEC_VERSION") = py::cast(::vk::EXTDepthClampZeroOneSpecVersion);
    n_vk.attr("EXT_NON_SEAMLESS_CUBE_MAP_EXTENSION_NAME") = py::cast(::vk::EXTNonSeamlessCubeMapExtensionName);
    n_vk.attr("EXT_NON_SEAMLESS_CUBE_MAP_SPEC_VERSION") = py::cast(::vk::EXTNonSeamlessCubeMapSpecVersion);
    n_vk.attr("ARM_RENDER_PASS_STRIPED_EXTENSION_NAME") = py::cast(::vk::ARMRenderPassStripedExtensionName);
    n_vk.attr("ARM_RENDER_PASS_STRIPED_SPEC_VERSION") = py::cast(::vk::ARMRenderPassStripedSpecVersion);
    n_vk.attr("QCOM_FRAGMENT_DENSITY_MAP_OFFSET_EXTENSION_NAME") = py::cast(::vk::QCOMFragmentDensityMapOffsetExtensionName);
    n_vk.attr("QCOM_FRAGMENT_DENSITY_MAP_OFFSET_SPEC_VERSION") = py::cast(::vk::QCOMFragmentDensityMapOffsetSpecVersion);
    n_vk.attr("NV_COPY_MEMORY_INDIRECT_EXTENSION_NAME") = py::cast(::vk::NVCopyMemoryIndirectExtensionName);
    n_vk.attr("NV_COPY_MEMORY_INDIRECT_SPEC_VERSION") = py::cast(::vk::NVCopyMemoryIndirectSpecVersion);
    n_vk.attr("NV_MEMORY_DECOMPRESSION_EXTENSION_NAME") = py::cast(::vk::NVMemoryDecompressionExtensionName);
    n_vk.attr("NV_MEMORY_DECOMPRESSION_SPEC_VERSION") = py::cast(::vk::NVMemoryDecompressionSpecVersion);
    n_vk.attr("NV_DEVICE_GENERATED_COMMANDS_COMPUTE_EXTENSION_NAME") = py::cast(::vk::NVDeviceGeneratedCommandsComputeExtensionName);
    n_vk.attr("NV_DEVICE_GENERATED_COMMANDS_COMPUTE_SPEC_VERSION") = py::cast(::vk::NVDeviceGeneratedCommandsComputeSpecVersion);
    n_vk.attr("NV_LINEAR_COLOR_ATTACHMENT_EXTENSION_NAME") = py::cast(::vk::NVLinearColorAttachmentExtensionName);
    n_vk.attr("NV_LINEAR_COLOR_ATTACHMENT_SPEC_VERSION") = py::cast(::vk::NVLinearColorAttachmentSpecVersion);
    n_vk.attr("GOOGLE_SURFACELESS_QUERY_EXTENSION_NAME") = py::cast(::vk::GOOGLESurfacelessQueryExtensionName);
    n_vk.attr("GOOGLE_SURFACELESS_QUERY_SPEC_VERSION") = py::cast(::vk::GOOGLESurfacelessQuerySpecVersion);
    n_vk.attr("EXT_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_EXTENSION_NAME") = py::cast(::vk::EXTImageCompressionControlSwapchainExtensionName);
    n_vk.attr("EXT_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_SPEC_VERSION") = py::cast(::vk::EXTImageCompressionControlSwapchainSpecVersion);
    n_vk.attr("QCOM_IMAGE_PROCESSING_EXTENSION_NAME") = py::cast(::vk::QCOMImageProcessingExtensionName);
    n_vk.attr("QCOM_IMAGE_PROCESSING_SPEC_VERSION") = py::cast(::vk::QCOMImageProcessingSpecVersion);
    n_vk.attr("EXT_NESTED_COMMAND_BUFFER_EXTENSION_NAME") = py::cast(::vk::EXTNestedCommandBufferExtensionName);
    n_vk.attr("EXT_NESTED_COMMAND_BUFFER_SPEC_VERSION") = py::cast(::vk::EXTNestedCommandBufferSpecVersion);
    n_vk.attr("EXT_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXTENSION_NAME") = py::cast(::vk::EXTExternalMemoryAcquireUnmodifiedExtensionName);
    n_vk.attr("EXT_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_SPEC_VERSION") = py::cast(::vk::EXTExternalMemoryAcquireUnmodifiedSpecVersion);
    n_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_3_EXTENSION_NAME") = py::cast(::vk::EXTExtendedDynamicState3ExtensionName);
    n_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_3_SPEC_VERSION") = py::cast(::vk::EXTExtendedDynamicState3SpecVersion);
    n_vk.attr("EXT_SUBPASS_MERGE_FEEDBACK_EXTENSION_NAME") = py::cast(::vk::EXTSubpassMergeFeedbackExtensionName);
    n_vk.attr("EXT_SUBPASS_MERGE_FEEDBACK_SPEC_VERSION") = py::cast(::vk::EXTSubpassMergeFeedbackSpecVersion);
    n_vk.attr("LUNARG_DIRECT_DRIVER_LOADING_EXTENSION_NAME") = py::cast(::vk::LUNARGDirectDriverLoadingExtensionName);
    n_vk.attr("LUNARG_DIRECT_DRIVER_LOADING_SPEC_VERSION") = py::cast(::vk::LUNARGDirectDriverLoadingSpecVersion);
    n_vk.attr("EXT_SHADER_MODULE_IDENTIFIER_EXTENSION_NAME") = py::cast(::vk::EXTShaderModuleIdentifierExtensionName);
    n_vk.attr("EXT_SHADER_MODULE_IDENTIFIER_SPEC_VERSION") = py::cast(::vk::EXTShaderModuleIdentifierSpecVersion);
    n_vk.attr("MAX_SHADER_MODULE_IDENTIFIER_SIZE_EXT") = py::cast(::vk::MaxShaderModuleIdentifierSizeEXT);
    n_vk.attr("EXT_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXTENSION_NAME") = py::cast(::vk::EXTRasterizationOrderAttachmentAccessExtensionName);
    n_vk.attr("EXT_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_SPEC_VERSION") = py::cast(::vk::EXTRasterizationOrderAttachmentAccessSpecVersion);
    n_vk.attr("NV_OPTICAL_FLOW_EXTENSION_NAME") = py::cast(::vk::NVOpticalFlowExtensionName);
    n_vk.attr("NV_OPTICAL_FLOW_SPEC_VERSION") = py::cast(::vk::NVOpticalFlowSpecVersion);
    n_vk.attr("EXT_LEGACY_DITHERING_EXTENSION_NAME") = py::cast(::vk::EXTLegacyDitheringExtensionName);
    n_vk.attr("EXT_LEGACY_DITHERING_SPEC_VERSION") = py::cast(::vk::EXTLegacyDitheringSpecVersion);
    n_vk.attr("EXT_PIPELINE_PROTECTED_ACCESS_EXTENSION_NAME") = py::cast(::vk::EXTPipelineProtectedAccessExtensionName);
    n_vk.attr("EXT_PIPELINE_PROTECTED_ACCESS_SPEC_VERSION") = py::cast(::vk::EXTPipelineProtectedAccessSpecVersion);
    n_vk.attr("KHR_MAINTENANCE_5_EXTENSION_NAME") = py::cast(::vk::KHRMaintenance5ExtensionName);
    n_vk.attr("KHR_MAINTENANCE_5_SPEC_VERSION") = py::cast(::vk::KHRMaintenance5SpecVersion);
    n_vk.attr("KHR_RAY_TRACING_POSITION_FETCH_EXTENSION_NAME") = py::cast(::vk::KHRRayTracingPositionFetchExtensionName);
    n_vk.attr("KHR_RAY_TRACING_POSITION_FETCH_SPEC_VERSION") = py::cast(::vk::KHRRayTracingPositionFetchSpecVersion);
    n_vk.attr("EXT_SHADER_OBJECT_EXTENSION_NAME") = py::cast(::vk::EXTShaderObjectExtensionName);
    n_vk.attr("EXT_SHADER_OBJECT_SPEC_VERSION") = py::cast(::vk::EXTShaderObjectSpecVersion);
    n_vk.attr("QCOM_TILE_PROPERTIES_EXTENSION_NAME") = py::cast(::vk::QCOMTilePropertiesExtensionName);
    n_vk.attr("QCOM_TILE_PROPERTIES_SPEC_VERSION") = py::cast(::vk::QCOMTilePropertiesSpecVersion);
    n_vk.attr("SEC_AMIGO_PROFILING_EXTENSION_NAME") = py::cast(::vk::SECAmigoProfilingExtensionName);
    n_vk.attr("SEC_AMIGO_PROFILING_SPEC_VERSION") = py::cast(::vk::SECAmigoProfilingSpecVersion);
    n_vk.attr("QCOM_MULTIVIEW_PER_VIEW_VIEWPORTS_EXTENSION_NAME") = py::cast(::vk::QCOMMultiviewPerViewViewportsExtensionName);
    n_vk.attr("QCOM_MULTIVIEW_PER_VIEW_VIEWPORTS_SPEC_VERSION") = py::cast(::vk::QCOMMultiviewPerViewViewportsSpecVersion);
    n_vk.attr("NV_RAY_TRACING_INVOCATION_REORDER_EXTENSION_NAME") = py::cast(::vk::NVRayTracingInvocationReorderExtensionName);
    n_vk.attr("NV_RAY_TRACING_INVOCATION_REORDER_SPEC_VERSION") = py::cast(::vk::NVRayTracingInvocationReorderSpecVersion);
    n_vk.attr("NV_EXTENDED_SPARSE_ADDRESS_SPACE_EXTENSION_NAME") = py::cast(::vk::NVExtendedSparseAddressSpaceExtensionName);
    n_vk.attr("NV_EXTENDED_SPARSE_ADDRESS_SPACE_SPEC_VERSION") = py::cast(::vk::NVExtendedSparseAddressSpaceSpecVersion);
    n_vk.attr("EXT_MUTABLE_DESCRIPTOR_TYPE_EXTENSION_NAME") = py::cast(::vk::EXTMutableDescriptorTypeExtensionName);
    n_vk.attr("EXT_MUTABLE_DESCRIPTOR_TYPE_SPEC_VERSION") = py::cast(::vk::EXTMutableDescriptorTypeSpecVersion);
    n_vk.attr("EXT_LAYER_SETTINGS_EXTENSION_NAME") = py::cast(::vk::EXTLayerSettingsExtensionName);
    n_vk.attr("EXT_LAYER_SETTINGS_SPEC_VERSION") = py::cast(::vk::EXTLayerSettingsSpecVersion);
    n_vk.attr("ARM_SHADER_CORE_BUILTINS_EXTENSION_NAME") = py::cast(::vk::ARMShaderCoreBuiltinsExtensionName);
    n_vk.attr("ARM_SHADER_CORE_BUILTINS_SPEC_VERSION") = py::cast(::vk::ARMShaderCoreBuiltinsSpecVersion);
    n_vk.attr("EXT_PIPELINE_LIBRARY_GROUP_HANDLES_EXTENSION_NAME") = py::cast(::vk::EXTPipelineLibraryGroupHandlesExtensionName);
    n_vk.attr("EXT_PIPELINE_LIBRARY_GROUP_HANDLES_SPEC_VERSION") = py::cast(::vk::EXTPipelineLibraryGroupHandlesSpecVersion);
    n_vk.attr("EXT_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_EXTENSION_NAME") = py::cast(::vk::EXTDynamicRenderingUnusedAttachmentsExtensionName);
    n_vk.attr("EXT_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_SPEC_VERSION") = py::cast(::vk::EXTDynamicRenderingUnusedAttachmentsSpecVersion);
    n_vk.attr("NV_LOW_LATENCY_2_EXTENSION_NAME") = py::cast(::vk::NVLowLatency2ExtensionName);
    n_vk.attr("NV_LOW_LATENCY_2_SPEC_VERSION") = py::cast(::vk::NVLowLatency2SpecVersion);
    n_vk.attr("KHR_COOPERATIVE_MATRIX_EXTENSION_NAME") = py::cast(::vk::KHRCooperativeMatrixExtensionName);
    n_vk.attr("KHR_COOPERATIVE_MATRIX_SPEC_VERSION") = py::cast(::vk::KHRCooperativeMatrixSpecVersion);
    n_vk.attr("QCOM_MULTIVIEW_PER_VIEW_RENDER_AREAS_EXTENSION_NAME") = py::cast(::vk::QCOMMultiviewPerViewRenderAreasExtensionName);
    n_vk.attr("QCOM_MULTIVIEW_PER_VIEW_RENDER_AREAS_SPEC_VERSION") = py::cast(::vk::QCOMMultiviewPerViewRenderAreasSpecVersion);
    n_vk.attr("KHR_VIDEO_MAINTENANCE_1_EXTENSION_NAME") = py::cast(::vk::KHRVideoMaintenance1ExtensionName);
    n_vk.attr("KHR_VIDEO_MAINTENANCE_1_SPEC_VERSION") = py::cast(::vk::KHRVideoMaintenance1SpecVersion);
    n_vk.attr("NV_PER_STAGE_DESCRIPTOR_SET_EXTENSION_NAME") = py::cast(::vk::NVPerStageDescriptorSetExtensionName);
    n_vk.attr("NV_PER_STAGE_DESCRIPTOR_SET_SPEC_VERSION") = py::cast(::vk::NVPerStageDescriptorSetSpecVersion);
    n_vk.attr("QCOM_IMAGE_PROCESSING_2_EXTENSION_NAME") = py::cast(::vk::QCOMImageProcessing2ExtensionName);
    n_vk.attr("QCOM_IMAGE_PROCESSING_2_SPEC_VERSION") = py::cast(::vk::QCOMImageProcessing2SpecVersion);
    n_vk.attr("QCOM_FILTER_CUBIC_WEIGHTS_EXTENSION_NAME") = py::cast(::vk::QCOMFilterCubicWeightsExtensionName);
    n_vk.attr("QCOM_FILTER_CUBIC_WEIGHTS_SPEC_VERSION") = py::cast(::vk::QCOMFilterCubicWeightsSpecVersion);
    n_vk.attr("QCOM_YCBCR_DEGAMMA_EXTENSION_NAME") = py::cast(::vk::QCOMYcbcrDegammaExtensionName);
    n_vk.attr("QCOM_YCBCR_DEGAMMA_SPEC_VERSION") = py::cast(::vk::QCOMYcbcrDegammaSpecVersion);
    n_vk.attr("QCOM_FILTER_CUBIC_CLAMP_EXTENSION_NAME") = py::cast(::vk::QCOMFilterCubicClampExtensionName);
    n_vk.attr("QCOM_FILTER_CUBIC_CLAMP_SPEC_VERSION") = py::cast(::vk::QCOMFilterCubicClampSpecVersion);
    n_vk.attr("EXT_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_EXTENSION_NAME") = py::cast(::vk::EXTAttachmentFeedbackLoopDynamicStateExtensionName);
    n_vk.attr("EXT_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_SPEC_VERSION") = py::cast(::vk::EXTAttachmentFeedbackLoopDynamicStateSpecVersion);
    n_vk.attr("KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME") = py::cast(::vk::KHRVertexAttributeDivisorExtensionName);
    n_vk.attr("KHR_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION") = py::cast(::vk::KHRVertexAttributeDivisorSpecVersion);
    n_vk.attr("MSFT_LAYERED_DRIVER_EXTENSION_NAME") = py::cast(::vk::MSFTLayeredDriverExtensionName);
    n_vk.attr("MSFT_LAYERED_DRIVER_SPEC_VERSION") = py::cast(::vk::MSFTLayeredDriverSpecVersion);
    n_vk.attr("KHR_CALIBRATED_TIMESTAMPS_EXTENSION_NAME") = py::cast(::vk::KHRCalibratedTimestampsExtensionName);
    n_vk.attr("KHR_CALIBRATED_TIMESTAMPS_SPEC_VERSION") = py::cast(::vk::KHRCalibratedTimestampsSpecVersion);
    n_vk.attr("KHR_MAINTENANCE_6_EXTENSION_NAME") = py::cast(::vk::KHRMaintenance6ExtensionName);
    n_vk.attr("KHR_MAINTENANCE_6_SPEC_VERSION") = py::cast(::vk::KHRMaintenance6SpecVersion);
    n_vk.attr("NV_DESCRIPTOR_POOL_OVERALLOCATION_EXTENSION_NAME") = py::cast(::vk::NVDescriptorPoolOverallocationExtensionName);
    n_vk.attr("NV_DESCRIPTOR_POOL_OVERALLOCATION_SPEC_VERSION") = py::cast(::vk::NVDescriptorPoolOverallocationSpecVersion);
    n_vk.attr("HEADER_VERSION") = py::cast(::vk::HeaderVersion);
    n_vk.attr("API_VERSION") = py::cast(::vk::ApiVersion);
    n_vk.attr("API_VERSION_10") = py::cast(::vk::ApiVersion10);
    n_vk.attr("API_VERSION_11") = py::cast(::vk::ApiVersion11);
    n_vk.attr("API_VERSION_12") = py::cast(::vk::ApiVersion12);
    n_vk.attr("API_VERSION_13") = py::cast(::vk::ApiVersion13);
    n_vk.attr("HEADER_VERSION_COMPLETE") = py::cast(::vk::HeaderVersionComplete);
    py::class_<::vk::AllocationCallbacks> s_vk_AllocationCallbacks(n_vk, "AllocationCallbacks");
    py::class_<::vk::ApplicationInfo> s_vk_ApplicationInfo(n_vk, "ApplicationInfo");
    py::class_<::vk::AttachmentDescription> s_vk_AttachmentDescription(n_vk, "AttachmentDescription");
    py::class_<::vk::AttachmentReference> s_vk_AttachmentReference(n_vk, "AttachmentReference");
    py::class_<::vk::BaseInStructure> s_vk_BaseInStructure(n_vk, "BaseInStructure");
    py::class_<::vk::BaseOutStructure> s_vk_BaseOutStructure(n_vk, "BaseOutStructure");
    py::class_<::vk::BindSparseInfo> s_vk_BindSparseInfo(n_vk, "BindSparseInfo");
    py::class_<::vk::BufferCopy> s_vk_BufferCopy(n_vk, "BufferCopy");
    py::class_<::vk::BufferCreateInfo> s_vk_BufferCreateInfo(n_vk, "BufferCreateInfo");
    py::class_<::vk::BufferImageCopy> s_vk_BufferImageCopy(n_vk, "BufferImageCopy");
    py::class_<::vk::BufferMemoryBarrier> s_vk_BufferMemoryBarrier(n_vk, "BufferMemoryBarrier");
    py::class_<::vk::BufferViewCreateInfo> s_vk_BufferViewCreateInfo(n_vk, "BufferViewCreateInfo");
    py::class_<::vk::ClearAttachment> s_vk_ClearAttachment(n_vk, "ClearAttachment");
    py::class_<::vk::ClearDepthStencilValue> s_vk_ClearDepthStencilValue(n_vk, "ClearDepthStencilValue");
    py::class_<::vk::ClearRect> s_vk_ClearRect(n_vk, "ClearRect");
    py::class_<::vk::CommandBufferAllocateInfo> s_vk_CommandBufferAllocateInfo(n_vk, "CommandBufferAllocateInfo");
    py::class_<::vk::CommandBufferBeginInfo> s_vk_CommandBufferBeginInfo(n_vk, "CommandBufferBeginInfo");
    py::class_<::vk::CommandBufferInheritanceInfo> s_vk_CommandBufferInheritanceInfo(n_vk, "CommandBufferInheritanceInfo");
    py::class_<::vk::CommandPoolCreateInfo> s_vk_CommandPoolCreateInfo(n_vk, "CommandPoolCreateInfo");
    py::class_<::vk::ComponentMapping> s_vk_ComponentMapping(n_vk, "ComponentMapping");
    py::class_<::vk::ComputePipelineCreateInfo> s_vk_ComputePipelineCreateInfo(n_vk, "ComputePipelineCreateInfo");
    py::class_<::vk::CopyDescriptorSet> s_vk_CopyDescriptorSet(n_vk, "CopyDescriptorSet");
    py::class_<::vk::DescriptorBufferInfo> s_vk_DescriptorBufferInfo(n_vk, "DescriptorBufferInfo");
    py::class_<::vk::DescriptorImageInfo> s_vk_DescriptorImageInfo(n_vk, "DescriptorImageInfo");
    py::class_<::vk::DescriptorPoolCreateInfo> s_vk_DescriptorPoolCreateInfo(n_vk, "DescriptorPoolCreateInfo");
    py::class_<::vk::DescriptorPoolSize> s_vk_DescriptorPoolSize(n_vk, "DescriptorPoolSize");
    py::class_<::vk::DescriptorSetAllocateInfo> s_vk_DescriptorSetAllocateInfo(n_vk, "DescriptorSetAllocateInfo");
    py::class_<::vk::DescriptorSetLayoutBinding> s_vk_DescriptorSetLayoutBinding(n_vk, "DescriptorSetLayoutBinding");
    py::class_<::vk::DescriptorSetLayoutCreateInfo> s_vk_DescriptorSetLayoutCreateInfo(n_vk, "DescriptorSetLayoutCreateInfo");
    py::class_<::vk::DeviceCreateInfo> s_vk_DeviceCreateInfo(n_vk, "DeviceCreateInfo");
    py::class_<::vk::DeviceQueueCreateInfo> s_vk_DeviceQueueCreateInfo(n_vk, "DeviceQueueCreateInfo");
    py::class_<::vk::DispatchIndirectCommand> s_vk_DispatchIndirectCommand(n_vk, "DispatchIndirectCommand");
    py::class_<::vk::DrawIndexedIndirectCommand> s_vk_DrawIndexedIndirectCommand(n_vk, "DrawIndexedIndirectCommand");
    py::class_<::vk::DrawIndirectCommand> s_vk_DrawIndirectCommand(n_vk, "DrawIndirectCommand");
    py::class_<::vk::EventCreateInfo> s_vk_EventCreateInfo(n_vk, "EventCreateInfo");
    py::class_<::vk::ExtensionProperties> s_vk_ExtensionProperties(n_vk, "ExtensionProperties");
    py::class_<::vk::Extent2D> s_vk_Extent2D(n_vk, "Extent2D");
    py::class_<::vk::Extent3D> s_vk_Extent3D(n_vk, "Extent3D");
    py::class_<::vk::FenceCreateInfo> s_vk_FenceCreateInfo(n_vk, "FenceCreateInfo");
    py::class_<::vk::FormatProperties> s_vk_FormatProperties(n_vk, "FormatProperties");
    py::class_<::vk::FramebufferCreateInfo> s_vk_FramebufferCreateInfo(n_vk, "FramebufferCreateInfo");
    py::class_<::vk::GraphicsPipelineCreateInfo> s_vk_GraphicsPipelineCreateInfo(n_vk, "GraphicsPipelineCreateInfo");
    py::class_<::vk::ImageBlit> s_vk_ImageBlit(n_vk, "ImageBlit");
    py::class_<::vk::ImageCopy> s_vk_ImageCopy(n_vk, "ImageCopy");
    py::class_<::vk::ImageCreateInfo> s_vk_ImageCreateInfo(n_vk, "ImageCreateInfo");
    py::class_<::vk::ImageFormatProperties> s_vk_ImageFormatProperties(n_vk, "ImageFormatProperties");
    py::class_<::vk::ImageMemoryBarrier> s_vk_ImageMemoryBarrier(n_vk, "ImageMemoryBarrier");
    py::class_<::vk::ImageResolve> s_vk_ImageResolve(n_vk, "ImageResolve");
    py::class_<::vk::ImageSubresource> s_vk_ImageSubresource(n_vk, "ImageSubresource");
    py::class_<::vk::ImageSubresourceLayers> s_vk_ImageSubresourceLayers(n_vk, "ImageSubresourceLayers");
    py::class_<::vk::ImageSubresourceRange> s_vk_ImageSubresourceRange(n_vk, "ImageSubresourceRange");
    py::class_<::vk::ImageViewCreateInfo> s_vk_ImageViewCreateInfo(n_vk, "ImageViewCreateInfo");
    py::class_<::vk::InstanceCreateInfo> s_vk_InstanceCreateInfo(n_vk, "InstanceCreateInfo");
    py::class_<::vk::LayerProperties> s_vk_LayerProperties(n_vk, "LayerProperties");
    py::class_<::vk::MappedMemoryRange> s_vk_MappedMemoryRange(n_vk, "MappedMemoryRange");
    py::class_<::vk::MemoryAllocateInfo> s_vk_MemoryAllocateInfo(n_vk, "MemoryAllocateInfo");
    py::class_<::vk::MemoryBarrier> s_vk_MemoryBarrier(n_vk, "MemoryBarrier");
    py::class_<::vk::MemoryHeap> s_vk_MemoryHeap(n_vk, "MemoryHeap");
    py::class_<::vk::MemoryRequirements> s_vk_MemoryRequirements(n_vk, "MemoryRequirements");
    py::class_<::vk::MemoryType> s_vk_MemoryType(n_vk, "MemoryType");
    py::class_<::vk::Offset2D> s_vk_Offset2D(n_vk, "Offset2D");
    py::class_<::vk::Offset3D> s_vk_Offset3D(n_vk, "Offset3D");
    py::class_<::vk::PhysicalDeviceFeatures> s_vk_PhysicalDeviceFeatures(n_vk, "PhysicalDeviceFeatures");
    py::class_<::vk::PhysicalDeviceLimits> s_vk_PhysicalDeviceLimits(n_vk, "PhysicalDeviceLimits");
    py::class_<::vk::PhysicalDeviceMemoryProperties> s_vk_PhysicalDeviceMemoryProperties(n_vk, "PhysicalDeviceMemoryProperties");
    py::class_<::vk::PhysicalDeviceProperties> s_vk_PhysicalDeviceProperties(n_vk, "PhysicalDeviceProperties");
    py::class_<::vk::PhysicalDeviceSparseProperties> s_vk_PhysicalDeviceSparseProperties(n_vk, "PhysicalDeviceSparseProperties");
    py::class_<::vk::PipelineCacheCreateInfo> s_vk_PipelineCacheCreateInfo(n_vk, "PipelineCacheCreateInfo");
    py::class_<::vk::PipelineCacheHeaderVersionOne> s_vk_PipelineCacheHeaderVersionOne(n_vk, "PipelineCacheHeaderVersionOne");
    py::class_<::vk::PipelineColorBlendAttachmentState> s_vk_PipelineColorBlendAttachmentState(n_vk, "PipelineColorBlendAttachmentState");
    py::class_<::vk::PipelineColorBlendStateCreateInfo> s_vk_PipelineColorBlendStateCreateInfo(n_vk, "PipelineColorBlendStateCreateInfo");
    py::class_<::vk::PipelineDepthStencilStateCreateInfo> s_vk_PipelineDepthStencilStateCreateInfo(n_vk, "PipelineDepthStencilStateCreateInfo");
    py::class_<::vk::PipelineDynamicStateCreateInfo> s_vk_PipelineDynamicStateCreateInfo(n_vk, "PipelineDynamicStateCreateInfo");
    py::class_<::vk::PipelineInputAssemblyStateCreateInfo> s_vk_PipelineInputAssemblyStateCreateInfo(n_vk, "PipelineInputAssemblyStateCreateInfo");
    py::class_<::vk::PipelineLayoutCreateInfo> s_vk_PipelineLayoutCreateInfo(n_vk, "PipelineLayoutCreateInfo");
    py::class_<::vk::PipelineMultisampleStateCreateInfo> s_vk_PipelineMultisampleStateCreateInfo(n_vk, "PipelineMultisampleStateCreateInfo");
    py::class_<::vk::PipelineRasterizationStateCreateInfo> s_vk_PipelineRasterizationStateCreateInfo(n_vk, "PipelineRasterizationStateCreateInfo");
    py::class_<::vk::PipelineShaderStageCreateInfo> s_vk_PipelineShaderStageCreateInfo(n_vk, "PipelineShaderStageCreateInfo");
    py::class_<::vk::PipelineTessellationStateCreateInfo> s_vk_PipelineTessellationStateCreateInfo(n_vk, "PipelineTessellationStateCreateInfo");
    py::class_<::vk::PipelineVertexInputStateCreateInfo> s_vk_PipelineVertexInputStateCreateInfo(n_vk, "PipelineVertexInputStateCreateInfo");
    py::class_<::vk::PipelineViewportStateCreateInfo> s_vk_PipelineViewportStateCreateInfo(n_vk, "PipelineViewportStateCreateInfo");
    py::class_<::vk::PushConstantRange> s_vk_PushConstantRange(n_vk, "PushConstantRange");
    py::class_<::vk::QueryPoolCreateInfo> s_vk_QueryPoolCreateInfo(n_vk, "QueryPoolCreateInfo");
    py::class_<::vk::QueueFamilyProperties> s_vk_QueueFamilyProperties(n_vk, "QueueFamilyProperties");
    py::class_<::vk::Rect2D> s_vk_Rect2D(n_vk, "Rect2D");
    py::class_<::vk::RenderPassBeginInfo> s_vk_RenderPassBeginInfo(n_vk, "RenderPassBeginInfo");
    py::class_<::vk::RenderPassCreateInfo> s_vk_RenderPassCreateInfo(n_vk, "RenderPassCreateInfo");
    py::class_<::vk::SamplerCreateInfo> s_vk_SamplerCreateInfo(n_vk, "SamplerCreateInfo");
    py::class_<::vk::SemaphoreCreateInfo> s_vk_SemaphoreCreateInfo(n_vk, "SemaphoreCreateInfo");
    py::class_<::vk::ShaderModuleCreateInfo> s_vk_ShaderModuleCreateInfo(n_vk, "ShaderModuleCreateInfo");
    py::class_<::vk::SparseBufferMemoryBindInfo> s_vk_SparseBufferMemoryBindInfo(n_vk, "SparseBufferMemoryBindInfo");
    py::class_<::vk::SparseImageFormatProperties> s_vk_SparseImageFormatProperties(n_vk, "SparseImageFormatProperties");
    py::class_<::vk::SparseImageMemoryBind> s_vk_SparseImageMemoryBind(n_vk, "SparseImageMemoryBind");
    py::class_<::vk::SparseImageMemoryBindInfo> s_vk_SparseImageMemoryBindInfo(n_vk, "SparseImageMemoryBindInfo");
    py::class_<::vk::SparseImageMemoryRequirements> s_vk_SparseImageMemoryRequirements(n_vk, "SparseImageMemoryRequirements");
    py::class_<::vk::SparseImageOpaqueMemoryBindInfo> s_vk_SparseImageOpaqueMemoryBindInfo(n_vk, "SparseImageOpaqueMemoryBindInfo");
    py::class_<::vk::SparseMemoryBind> s_vk_SparseMemoryBind(n_vk, "SparseMemoryBind");
    py::class_<::vk::SpecializationInfo> s_vk_SpecializationInfo(n_vk, "SpecializationInfo");
    py::class_<::vk::SpecializationMapEntry> s_vk_SpecializationMapEntry(n_vk, "SpecializationMapEntry");
    py::class_<::vk::StencilOpState> s_vk_StencilOpState(n_vk, "StencilOpState");
    py::class_<::vk::SubmitInfo> s_vk_SubmitInfo(n_vk, "SubmitInfo");
    py::class_<::vk::SubpassDependency> s_vk_SubpassDependency(n_vk, "SubpassDependency");
    py::class_<::vk::SubpassDescription> s_vk_SubpassDescription(n_vk, "SubpassDescription");
    py::class_<::vk::SubresourceLayout> s_vk_SubresourceLayout(n_vk, "SubresourceLayout");
    py::class_<::vk::VertexInputAttributeDescription> s_vk_VertexInputAttributeDescription(n_vk, "VertexInputAttributeDescription");
    py::class_<::vk::VertexInputBindingDescription> s_vk_VertexInputBindingDescription(n_vk, "VertexInputBindingDescription");
    py::class_<::vk::Viewport> s_vk_Viewport(n_vk, "Viewport");
    py::class_<::vk::WriteDescriptorSet> s_vk_WriteDescriptorSet(n_vk, "WriteDescriptorSet");
    py::class_<::vk::BindBufferMemoryDeviceGroupInfo> s_vk_BindBufferMemoryDeviceGroupInfo(n_vk, "BindBufferMemoryDeviceGroupInfo");
    py::class_<::vk::BindBufferMemoryInfo> s_vk_BindBufferMemoryInfo(n_vk, "BindBufferMemoryInfo");
    py::class_<::vk::BindImageMemoryDeviceGroupInfo> s_vk_BindImageMemoryDeviceGroupInfo(n_vk, "BindImageMemoryDeviceGroupInfo");
    py::class_<::vk::BindImageMemoryInfo> s_vk_BindImageMemoryInfo(n_vk, "BindImageMemoryInfo");
    py::class_<::vk::BindImagePlaneMemoryInfo> s_vk_BindImagePlaneMemoryInfo(n_vk, "BindImagePlaneMemoryInfo");
    py::class_<::vk::BufferMemoryRequirementsInfo2> s_vk_BufferMemoryRequirementsInfo2(n_vk, "BufferMemoryRequirementsInfo2");
    py::class_<::vk::DescriptorSetLayoutSupport> s_vk_DescriptorSetLayoutSupport(n_vk, "DescriptorSetLayoutSupport");
    py::class_<::vk::DescriptorUpdateTemplateCreateInfo> s_vk_DescriptorUpdateTemplateCreateInfo(n_vk, "DescriptorUpdateTemplateCreateInfo");
    py::class_<::vk::DescriptorUpdateTemplateEntry> s_vk_DescriptorUpdateTemplateEntry(n_vk, "DescriptorUpdateTemplateEntry");
    py::class_<::vk::DeviceGroupBindSparseInfo> s_vk_DeviceGroupBindSparseInfo(n_vk, "DeviceGroupBindSparseInfo");
    py::class_<::vk::DeviceGroupCommandBufferBeginInfo> s_vk_DeviceGroupCommandBufferBeginInfo(n_vk, "DeviceGroupCommandBufferBeginInfo");
    py::class_<::vk::DeviceGroupDeviceCreateInfo> s_vk_DeviceGroupDeviceCreateInfo(n_vk, "DeviceGroupDeviceCreateInfo");
    py::class_<::vk::DeviceGroupRenderPassBeginInfo> s_vk_DeviceGroupRenderPassBeginInfo(n_vk, "DeviceGroupRenderPassBeginInfo");
    py::class_<::vk::DeviceGroupSubmitInfo> s_vk_DeviceGroupSubmitInfo(n_vk, "DeviceGroupSubmitInfo");
    py::class_<::vk::DeviceQueueInfo2> s_vk_DeviceQueueInfo2(n_vk, "DeviceQueueInfo2");
    py::class_<::vk::ExportFenceCreateInfo> s_vk_ExportFenceCreateInfo(n_vk, "ExportFenceCreateInfo");
    py::class_<::vk::ExportMemoryAllocateInfo> s_vk_ExportMemoryAllocateInfo(n_vk, "ExportMemoryAllocateInfo");
    py::class_<::vk::ExportSemaphoreCreateInfo> s_vk_ExportSemaphoreCreateInfo(n_vk, "ExportSemaphoreCreateInfo");
    py::class_<::vk::ExternalBufferProperties> s_vk_ExternalBufferProperties(n_vk, "ExternalBufferProperties");
    py::class_<::vk::ExternalFenceProperties> s_vk_ExternalFenceProperties(n_vk, "ExternalFenceProperties");
    py::class_<::vk::ExternalImageFormatProperties> s_vk_ExternalImageFormatProperties(n_vk, "ExternalImageFormatProperties");
    py::class_<::vk::ExternalMemoryBufferCreateInfo> s_vk_ExternalMemoryBufferCreateInfo(n_vk, "ExternalMemoryBufferCreateInfo");
    py::class_<::vk::ExternalMemoryImageCreateInfo> s_vk_ExternalMemoryImageCreateInfo(n_vk, "ExternalMemoryImageCreateInfo");
    py::class_<::vk::ExternalMemoryProperties> s_vk_ExternalMemoryProperties(n_vk, "ExternalMemoryProperties");
    py::class_<::vk::ExternalSemaphoreProperties> s_vk_ExternalSemaphoreProperties(n_vk, "ExternalSemaphoreProperties");
    py::class_<::vk::FormatProperties2> s_vk_FormatProperties2(n_vk, "FormatProperties2");
    py::class_<::vk::ImageFormatProperties2> s_vk_ImageFormatProperties2(n_vk, "ImageFormatProperties2");
    py::class_<::vk::ImageMemoryRequirementsInfo2> s_vk_ImageMemoryRequirementsInfo2(n_vk, "ImageMemoryRequirementsInfo2");
    py::class_<::vk::ImagePlaneMemoryRequirementsInfo> s_vk_ImagePlaneMemoryRequirementsInfo(n_vk, "ImagePlaneMemoryRequirementsInfo");
    py::class_<::vk::ImageSparseMemoryRequirementsInfo2> s_vk_ImageSparseMemoryRequirementsInfo2(n_vk, "ImageSparseMemoryRequirementsInfo2");
    py::class_<::vk::ImageViewUsageCreateInfo> s_vk_ImageViewUsageCreateInfo(n_vk, "ImageViewUsageCreateInfo");
    py::class_<::vk::InputAttachmentAspectReference> s_vk_InputAttachmentAspectReference(n_vk, "InputAttachmentAspectReference");
    py::class_<::vk::MemoryAllocateFlagsInfo> s_vk_MemoryAllocateFlagsInfo(n_vk, "MemoryAllocateFlagsInfo");
    py::class_<::vk::MemoryDedicatedAllocateInfo> s_vk_MemoryDedicatedAllocateInfo(n_vk, "MemoryDedicatedAllocateInfo");
    py::class_<::vk::MemoryDedicatedRequirements> s_vk_MemoryDedicatedRequirements(n_vk, "MemoryDedicatedRequirements");
    py::class_<::vk::MemoryRequirements2> s_vk_MemoryRequirements2(n_vk, "MemoryRequirements2");
    py::class_<::vk::PhysicalDevice16BitStorageFeatures> s_vk_PhysicalDevice16BitStorageFeatures(n_vk, "PhysicalDevice16BitStorageFeatures");
    py::class_<::vk::PhysicalDeviceExternalBufferInfo> s_vk_PhysicalDeviceExternalBufferInfo(n_vk, "PhysicalDeviceExternalBufferInfo");
    py::class_<::vk::PhysicalDeviceExternalFenceInfo> s_vk_PhysicalDeviceExternalFenceInfo(n_vk, "PhysicalDeviceExternalFenceInfo");
    py::class_<::vk::PhysicalDeviceExternalImageFormatInfo> s_vk_PhysicalDeviceExternalImageFormatInfo(n_vk, "PhysicalDeviceExternalImageFormatInfo");
    py::class_<::vk::PhysicalDeviceExternalSemaphoreInfo> s_vk_PhysicalDeviceExternalSemaphoreInfo(n_vk, "PhysicalDeviceExternalSemaphoreInfo");
    py::class_<::vk::PhysicalDeviceFeatures2> s_vk_PhysicalDeviceFeatures2(n_vk, "PhysicalDeviceFeatures2");
    py::class_<::vk::PhysicalDeviceGroupProperties> s_vk_PhysicalDeviceGroupProperties(n_vk, "PhysicalDeviceGroupProperties");
    py::class_<::vk::PhysicalDeviceIDProperties> s_vk_PhysicalDeviceIDProperties(n_vk, "PhysicalDeviceIDProperties");
    py::class_<::vk::PhysicalDeviceImageFormatInfo2> s_vk_PhysicalDeviceImageFormatInfo2(n_vk, "PhysicalDeviceImageFormatInfo2");
    py::class_<::vk::PhysicalDeviceMaintenance3Properties> s_vk_PhysicalDeviceMaintenance3Properties(n_vk, "PhysicalDeviceMaintenance3Properties");
    py::class_<::vk::PhysicalDeviceMemoryProperties2> s_vk_PhysicalDeviceMemoryProperties2(n_vk, "PhysicalDeviceMemoryProperties2");
    py::class_<::vk::PhysicalDeviceMultiviewFeatures> s_vk_PhysicalDeviceMultiviewFeatures(n_vk, "PhysicalDeviceMultiviewFeatures");
    py::class_<::vk::PhysicalDeviceMultiviewProperties> s_vk_PhysicalDeviceMultiviewProperties(n_vk, "PhysicalDeviceMultiviewProperties");
    py::class_<::vk::PhysicalDevicePointClippingProperties> s_vk_PhysicalDevicePointClippingProperties(n_vk, "PhysicalDevicePointClippingProperties");
    py::class_<::vk::PhysicalDeviceProperties2> s_vk_PhysicalDeviceProperties2(n_vk, "PhysicalDeviceProperties2");
    py::class_<::vk::PhysicalDeviceProtectedMemoryFeatures> s_vk_PhysicalDeviceProtectedMemoryFeatures(n_vk, "PhysicalDeviceProtectedMemoryFeatures");
    py::class_<::vk::PhysicalDeviceProtectedMemoryProperties> s_vk_PhysicalDeviceProtectedMemoryProperties(n_vk, "PhysicalDeviceProtectedMemoryProperties");
    py::class_<::vk::PhysicalDeviceSamplerYcbcrConversionFeatures> s_vk_PhysicalDeviceSamplerYcbcrConversionFeatures(n_vk, "PhysicalDeviceSamplerYcbcrConversionFeatures");
    py::class_<::vk::PhysicalDeviceShaderDrawParametersFeatures> s_vk_PhysicalDeviceShaderDrawParametersFeatures(n_vk, "PhysicalDeviceShaderDrawParametersFeatures");
    py::class_<::vk::PhysicalDeviceSparseImageFormatInfo2> s_vk_PhysicalDeviceSparseImageFormatInfo2(n_vk, "PhysicalDeviceSparseImageFormatInfo2");
    py::class_<::vk::PhysicalDeviceSubgroupProperties> s_vk_PhysicalDeviceSubgroupProperties(n_vk, "PhysicalDeviceSubgroupProperties");
    py::class_<::vk::PhysicalDeviceVariablePointersFeatures> s_vk_PhysicalDeviceVariablePointersFeatures(n_vk, "PhysicalDeviceVariablePointersFeatures");
    py::class_<::vk::PipelineTessellationDomainOriginStateCreateInfo> s_vk_PipelineTessellationDomainOriginStateCreateInfo(n_vk, "PipelineTessellationDomainOriginStateCreateInfo");
    py::class_<::vk::ProtectedSubmitInfo> s_vk_ProtectedSubmitInfo(n_vk, "ProtectedSubmitInfo");
    py::class_<::vk::QueueFamilyProperties2> s_vk_QueueFamilyProperties2(n_vk, "QueueFamilyProperties2");
    py::class_<::vk::RenderPassInputAttachmentAspectCreateInfo> s_vk_RenderPassInputAttachmentAspectCreateInfo(n_vk, "RenderPassInputAttachmentAspectCreateInfo");
    py::class_<::vk::RenderPassMultiviewCreateInfo> s_vk_RenderPassMultiviewCreateInfo(n_vk, "RenderPassMultiviewCreateInfo");
    py::class_<::vk::SamplerYcbcrConversionCreateInfo> s_vk_SamplerYcbcrConversionCreateInfo(n_vk, "SamplerYcbcrConversionCreateInfo");
    py::class_<::vk::SamplerYcbcrConversionImageFormatProperties> s_vk_SamplerYcbcrConversionImageFormatProperties(n_vk, "SamplerYcbcrConversionImageFormatProperties");
    py::class_<::vk::SamplerYcbcrConversionInfo> s_vk_SamplerYcbcrConversionInfo(n_vk, "SamplerYcbcrConversionInfo");
    py::class_<::vk::SparseImageFormatProperties2> s_vk_SparseImageFormatProperties2(n_vk, "SparseImageFormatProperties2");
    py::class_<::vk::SparseImageMemoryRequirements2> s_vk_SparseImageMemoryRequirements2(n_vk, "SparseImageMemoryRequirements2");
    py::class_<::vk::AttachmentDescription2> s_vk_AttachmentDescription2(n_vk, "AttachmentDescription2");
    py::class_<::vk::AttachmentDescriptionStencilLayout> s_vk_AttachmentDescriptionStencilLayout(n_vk, "AttachmentDescriptionStencilLayout");
    py::class_<::vk::AttachmentReference2> s_vk_AttachmentReference2(n_vk, "AttachmentReference2");
    py::class_<::vk::AttachmentReferenceStencilLayout> s_vk_AttachmentReferenceStencilLayout(n_vk, "AttachmentReferenceStencilLayout");
    py::class_<::vk::BufferDeviceAddressInfo> s_vk_BufferDeviceAddressInfo(n_vk, "BufferDeviceAddressInfo");
    py::class_<::vk::BufferOpaqueCaptureAddressCreateInfo> s_vk_BufferOpaqueCaptureAddressCreateInfo(n_vk, "BufferOpaqueCaptureAddressCreateInfo");
    py::class_<::vk::ConformanceVersion> s_vk_ConformanceVersion(n_vk, "ConformanceVersion");
    py::class_<::vk::DescriptorSetLayoutBindingFlagsCreateInfo> s_vk_DescriptorSetLayoutBindingFlagsCreateInfo(n_vk, "DescriptorSetLayoutBindingFlagsCreateInfo");
    py::class_<::vk::DescriptorSetVariableDescriptorCountAllocateInfo> s_vk_DescriptorSetVariableDescriptorCountAllocateInfo(n_vk, "DescriptorSetVariableDescriptorCountAllocateInfo");
    py::class_<::vk::DescriptorSetVariableDescriptorCountLayoutSupport> s_vk_DescriptorSetVariableDescriptorCountLayoutSupport(n_vk, "DescriptorSetVariableDescriptorCountLayoutSupport");
    py::class_<::vk::DeviceMemoryOpaqueCaptureAddressInfo> s_vk_DeviceMemoryOpaqueCaptureAddressInfo(n_vk, "DeviceMemoryOpaqueCaptureAddressInfo");
    py::class_<::vk::FramebufferAttachmentImageInfo> s_vk_FramebufferAttachmentImageInfo(n_vk, "FramebufferAttachmentImageInfo");
    py::class_<::vk::FramebufferAttachmentsCreateInfo> s_vk_FramebufferAttachmentsCreateInfo(n_vk, "FramebufferAttachmentsCreateInfo");
    py::class_<::vk::ImageFormatListCreateInfo> s_vk_ImageFormatListCreateInfo(n_vk, "ImageFormatListCreateInfo");
    py::class_<::vk::ImageStencilUsageCreateInfo> s_vk_ImageStencilUsageCreateInfo(n_vk, "ImageStencilUsageCreateInfo");
    py::class_<::vk::MemoryOpaqueCaptureAddressAllocateInfo> s_vk_MemoryOpaqueCaptureAddressAllocateInfo(n_vk, "MemoryOpaqueCaptureAddressAllocateInfo");
    py::class_<::vk::PhysicalDevice8BitStorageFeatures> s_vk_PhysicalDevice8BitStorageFeatures(n_vk, "PhysicalDevice8BitStorageFeatures");
    py::class_<::vk::PhysicalDeviceBufferDeviceAddressFeatures> s_vk_PhysicalDeviceBufferDeviceAddressFeatures(n_vk, "PhysicalDeviceBufferDeviceAddressFeatures");
    py::class_<::vk::PhysicalDeviceDepthStencilResolveProperties> s_vk_PhysicalDeviceDepthStencilResolveProperties(n_vk, "PhysicalDeviceDepthStencilResolveProperties");
    py::class_<::vk::PhysicalDeviceDescriptorIndexingFeatures> s_vk_PhysicalDeviceDescriptorIndexingFeatures(n_vk, "PhysicalDeviceDescriptorIndexingFeatures");
    py::class_<::vk::PhysicalDeviceDescriptorIndexingProperties> s_vk_PhysicalDeviceDescriptorIndexingProperties(n_vk, "PhysicalDeviceDescriptorIndexingProperties");
    py::class_<::vk::PhysicalDeviceDriverProperties> s_vk_PhysicalDeviceDriverProperties(n_vk, "PhysicalDeviceDriverProperties");
    py::class_<::vk::PhysicalDeviceFloatControlsProperties> s_vk_PhysicalDeviceFloatControlsProperties(n_vk, "PhysicalDeviceFloatControlsProperties");
    py::class_<::vk::PhysicalDeviceHostQueryResetFeatures> s_vk_PhysicalDeviceHostQueryResetFeatures(n_vk, "PhysicalDeviceHostQueryResetFeatures");
    py::class_<::vk::PhysicalDeviceImagelessFramebufferFeatures> s_vk_PhysicalDeviceImagelessFramebufferFeatures(n_vk, "PhysicalDeviceImagelessFramebufferFeatures");
    py::class_<::vk::PhysicalDeviceSamplerFilterMinmaxProperties> s_vk_PhysicalDeviceSamplerFilterMinmaxProperties(n_vk, "PhysicalDeviceSamplerFilterMinmaxProperties");
    py::class_<::vk::PhysicalDeviceScalarBlockLayoutFeatures> s_vk_PhysicalDeviceScalarBlockLayoutFeatures(n_vk, "PhysicalDeviceScalarBlockLayoutFeatures");
    py::class_<::vk::PhysicalDeviceSeparateDepthStencilLayoutsFeatures> s_vk_PhysicalDeviceSeparateDepthStencilLayoutsFeatures(n_vk, "PhysicalDeviceSeparateDepthStencilLayoutsFeatures");
    py::class_<::vk::PhysicalDeviceShaderAtomicInt64Features> s_vk_PhysicalDeviceShaderAtomicInt64Features(n_vk, "PhysicalDeviceShaderAtomicInt64Features");
    py::class_<::vk::PhysicalDeviceShaderFloat16Int8Features> s_vk_PhysicalDeviceShaderFloat16Int8Features(n_vk, "PhysicalDeviceShaderFloat16Int8Features");
    py::class_<::vk::PhysicalDeviceShaderSubgroupExtendedTypesFeatures> s_vk_PhysicalDeviceShaderSubgroupExtendedTypesFeatures(n_vk, "PhysicalDeviceShaderSubgroupExtendedTypesFeatures");
    py::class_<::vk::PhysicalDeviceTimelineSemaphoreFeatures> s_vk_PhysicalDeviceTimelineSemaphoreFeatures(n_vk, "PhysicalDeviceTimelineSemaphoreFeatures");
    py::class_<::vk::PhysicalDeviceTimelineSemaphoreProperties> s_vk_PhysicalDeviceTimelineSemaphoreProperties(n_vk, "PhysicalDeviceTimelineSemaphoreProperties");
    py::class_<::vk::PhysicalDeviceUniformBufferStandardLayoutFeatures> s_vk_PhysicalDeviceUniformBufferStandardLayoutFeatures(n_vk, "PhysicalDeviceUniformBufferStandardLayoutFeatures");
    py::class_<::vk::PhysicalDeviceVulkan11Features> s_vk_PhysicalDeviceVulkan11Features(n_vk, "PhysicalDeviceVulkan11Features");
    py::class_<::vk::PhysicalDeviceVulkan11Properties> s_vk_PhysicalDeviceVulkan11Properties(n_vk, "PhysicalDeviceVulkan11Properties");
    py::class_<::vk::PhysicalDeviceVulkan12Features> s_vk_PhysicalDeviceVulkan12Features(n_vk, "PhysicalDeviceVulkan12Features");
    py::class_<::vk::PhysicalDeviceVulkan12Properties> s_vk_PhysicalDeviceVulkan12Properties(n_vk, "PhysicalDeviceVulkan12Properties");
    py::class_<::vk::PhysicalDeviceVulkanMemoryModelFeatures> s_vk_PhysicalDeviceVulkanMemoryModelFeatures(n_vk, "PhysicalDeviceVulkanMemoryModelFeatures");
    py::class_<::vk::RenderPassAttachmentBeginInfo> s_vk_RenderPassAttachmentBeginInfo(n_vk, "RenderPassAttachmentBeginInfo");
    py::class_<::vk::RenderPassCreateInfo2> s_vk_RenderPassCreateInfo2(n_vk, "RenderPassCreateInfo2");
    py::class_<::vk::SamplerReductionModeCreateInfo> s_vk_SamplerReductionModeCreateInfo(n_vk, "SamplerReductionModeCreateInfo");
    py::class_<::vk::SemaphoreSignalInfo> s_vk_SemaphoreSignalInfo(n_vk, "SemaphoreSignalInfo");
    py::class_<::vk::SemaphoreTypeCreateInfo> s_vk_SemaphoreTypeCreateInfo(n_vk, "SemaphoreTypeCreateInfo");
    py::class_<::vk::SemaphoreWaitInfo> s_vk_SemaphoreWaitInfo(n_vk, "SemaphoreWaitInfo");
    py::class_<::vk::SubpassBeginInfo> s_vk_SubpassBeginInfo(n_vk, "SubpassBeginInfo");
    py::class_<::vk::SubpassDependency2> s_vk_SubpassDependency2(n_vk, "SubpassDependency2");
    py::class_<::vk::SubpassDescription2> s_vk_SubpassDescription2(n_vk, "SubpassDescription2");
    py::class_<::vk::SubpassDescriptionDepthStencilResolve> s_vk_SubpassDescriptionDepthStencilResolve(n_vk, "SubpassDescriptionDepthStencilResolve");
    py::class_<::vk::SubpassEndInfo> s_vk_SubpassEndInfo(n_vk, "SubpassEndInfo");
    py::class_<::vk::TimelineSemaphoreSubmitInfo> s_vk_TimelineSemaphoreSubmitInfo(n_vk, "TimelineSemaphoreSubmitInfo");
    py::class_<::vk::BlitImageInfo2> s_vk_BlitImageInfo2(n_vk, "BlitImageInfo2");
    py::class_<::vk::BufferCopy2> s_vk_BufferCopy2(n_vk, "BufferCopy2");
    py::class_<::vk::BufferImageCopy2> s_vk_BufferImageCopy2(n_vk, "BufferImageCopy2");
    py::class_<::vk::BufferMemoryBarrier2> s_vk_BufferMemoryBarrier2(n_vk, "BufferMemoryBarrier2");
    py::class_<::vk::CommandBufferInheritanceRenderingInfo> s_vk_CommandBufferInheritanceRenderingInfo(n_vk, "CommandBufferInheritanceRenderingInfo");
    py::class_<::vk::CommandBufferSubmitInfo> s_vk_CommandBufferSubmitInfo(n_vk, "CommandBufferSubmitInfo");
    py::class_<::vk::CopyBufferInfo2> s_vk_CopyBufferInfo2(n_vk, "CopyBufferInfo2");
    py::class_<::vk::CopyBufferToImageInfo2> s_vk_CopyBufferToImageInfo2(n_vk, "CopyBufferToImageInfo2");
    py::class_<::vk::CopyImageInfo2> s_vk_CopyImageInfo2(n_vk, "CopyImageInfo2");
    py::class_<::vk::CopyImageToBufferInfo2> s_vk_CopyImageToBufferInfo2(n_vk, "CopyImageToBufferInfo2");
    py::class_<::vk::DependencyInfo> s_vk_DependencyInfo(n_vk, "DependencyInfo");
    py::class_<::vk::DescriptorPoolInlineUniformBlockCreateInfo> s_vk_DescriptorPoolInlineUniformBlockCreateInfo(n_vk, "DescriptorPoolInlineUniformBlockCreateInfo");
    py::class_<::vk::DeviceBufferMemoryRequirements> s_vk_DeviceBufferMemoryRequirements(n_vk, "DeviceBufferMemoryRequirements");
    py::class_<::vk::DeviceImageMemoryRequirements> s_vk_DeviceImageMemoryRequirements(n_vk, "DeviceImageMemoryRequirements");
    py::class_<::vk::DevicePrivateDataCreateInfo> s_vk_DevicePrivateDataCreateInfo(n_vk, "DevicePrivateDataCreateInfo");
    py::class_<::vk::FormatProperties3> s_vk_FormatProperties3(n_vk, "FormatProperties3");
    py::class_<::vk::ImageBlit2> s_vk_ImageBlit2(n_vk, "ImageBlit2");
    py::class_<::vk::ImageCopy2> s_vk_ImageCopy2(n_vk, "ImageCopy2");
    py::class_<::vk::ImageMemoryBarrier2> s_vk_ImageMemoryBarrier2(n_vk, "ImageMemoryBarrier2");
    py::class_<::vk::ImageResolve2> s_vk_ImageResolve2(n_vk, "ImageResolve2");
    py::class_<::vk::MemoryBarrier2> s_vk_MemoryBarrier2(n_vk, "MemoryBarrier2");
    py::class_<::vk::PhysicalDeviceDynamicRenderingFeatures> s_vk_PhysicalDeviceDynamicRenderingFeatures(n_vk, "PhysicalDeviceDynamicRenderingFeatures");
    py::class_<::vk::PhysicalDeviceImageRobustnessFeatures> s_vk_PhysicalDeviceImageRobustnessFeatures(n_vk, "PhysicalDeviceImageRobustnessFeatures");
    py::class_<::vk::PhysicalDeviceInlineUniformBlockFeatures> s_vk_PhysicalDeviceInlineUniformBlockFeatures(n_vk, "PhysicalDeviceInlineUniformBlockFeatures");
    py::class_<::vk::PhysicalDeviceInlineUniformBlockProperties> s_vk_PhysicalDeviceInlineUniformBlockProperties(n_vk, "PhysicalDeviceInlineUniformBlockProperties");
    py::class_<::vk::PhysicalDeviceMaintenance4Features> s_vk_PhysicalDeviceMaintenance4Features(n_vk, "PhysicalDeviceMaintenance4Features");
    py::class_<::vk::PhysicalDeviceMaintenance4Properties> s_vk_PhysicalDeviceMaintenance4Properties(n_vk, "PhysicalDeviceMaintenance4Properties");
    py::class_<::vk::PhysicalDevicePipelineCreationCacheControlFeatures> s_vk_PhysicalDevicePipelineCreationCacheControlFeatures(n_vk, "PhysicalDevicePipelineCreationCacheControlFeatures");
    py::class_<::vk::PhysicalDevicePrivateDataFeatures> s_vk_PhysicalDevicePrivateDataFeatures(n_vk, "PhysicalDevicePrivateDataFeatures");
    py::class_<::vk::PhysicalDeviceShaderDemoteToHelperInvocationFeatures> s_vk_PhysicalDeviceShaderDemoteToHelperInvocationFeatures(n_vk, "PhysicalDeviceShaderDemoteToHelperInvocationFeatures");
    py::class_<::vk::PhysicalDeviceShaderIntegerDotProductFeatures> s_vk_PhysicalDeviceShaderIntegerDotProductFeatures(n_vk, "PhysicalDeviceShaderIntegerDotProductFeatures");
    py::class_<::vk::PhysicalDeviceShaderIntegerDotProductProperties> s_vk_PhysicalDeviceShaderIntegerDotProductProperties(n_vk, "PhysicalDeviceShaderIntegerDotProductProperties");
    py::class_<::vk::PhysicalDeviceShaderTerminateInvocationFeatures> s_vk_PhysicalDeviceShaderTerminateInvocationFeatures(n_vk, "PhysicalDeviceShaderTerminateInvocationFeatures");
    py::class_<::vk::PhysicalDeviceSubgroupSizeControlFeatures> s_vk_PhysicalDeviceSubgroupSizeControlFeatures(n_vk, "PhysicalDeviceSubgroupSizeControlFeatures");
    py::class_<::vk::PhysicalDeviceSubgroupSizeControlProperties> s_vk_PhysicalDeviceSubgroupSizeControlProperties(n_vk, "PhysicalDeviceSubgroupSizeControlProperties");
    py::class_<::vk::PhysicalDeviceSynchronization2Features> s_vk_PhysicalDeviceSynchronization2Features(n_vk, "PhysicalDeviceSynchronization2Features");
    py::class_<::vk::PhysicalDeviceTexelBufferAlignmentProperties> s_vk_PhysicalDeviceTexelBufferAlignmentProperties(n_vk, "PhysicalDeviceTexelBufferAlignmentProperties");
    py::class_<::vk::PhysicalDeviceTextureCompressionASTCHDRFeatures> s_vk_PhysicalDeviceTextureCompressionASTCHDRFeatures(n_vk, "PhysicalDeviceTextureCompressionASTCHDRFeatures");
    py::class_<::vk::PhysicalDeviceToolProperties> s_vk_PhysicalDeviceToolProperties(n_vk, "PhysicalDeviceToolProperties");
    py::class_<::vk::PhysicalDeviceVulkan13Features> s_vk_PhysicalDeviceVulkan13Features(n_vk, "PhysicalDeviceVulkan13Features");
    py::class_<::vk::PhysicalDeviceVulkan13Properties> s_vk_PhysicalDeviceVulkan13Properties(n_vk, "PhysicalDeviceVulkan13Properties");
    py::class_<::vk::PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures> s_vk_PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures(n_vk, "PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures");
    py::class_<::vk::PipelineCreationFeedback> s_vk_PipelineCreationFeedback(n_vk, "PipelineCreationFeedback");
    py::class_<::vk::PipelineCreationFeedbackCreateInfo> s_vk_PipelineCreationFeedbackCreateInfo(n_vk, "PipelineCreationFeedbackCreateInfo");
    py::class_<::vk::PipelineRenderingCreateInfo> s_vk_PipelineRenderingCreateInfo(n_vk, "PipelineRenderingCreateInfo");
    py::class_<::vk::PipelineShaderStageRequiredSubgroupSizeCreateInfo> s_vk_PipelineShaderStageRequiredSubgroupSizeCreateInfo(n_vk, "PipelineShaderStageRequiredSubgroupSizeCreateInfo");
    py::class_<::vk::PrivateDataSlotCreateInfo> s_vk_PrivateDataSlotCreateInfo(n_vk, "PrivateDataSlotCreateInfo");
    py::class_<::vk::RenderingAttachmentInfo> s_vk_RenderingAttachmentInfo(n_vk, "RenderingAttachmentInfo");
    py::class_<::vk::RenderingInfo> s_vk_RenderingInfo(n_vk, "RenderingInfo");
    py::class_<::vk::ResolveImageInfo2> s_vk_ResolveImageInfo2(n_vk, "ResolveImageInfo2");
    py::class_<::vk::SemaphoreSubmitInfo> s_vk_SemaphoreSubmitInfo(n_vk, "SemaphoreSubmitInfo");
    py::class_<::vk::SubmitInfo2> s_vk_SubmitInfo2(n_vk, "SubmitInfo2");
    py::class_<::vk::WriteDescriptorSetInlineUniformBlock> s_vk_WriteDescriptorSetInlineUniformBlock(n_vk, "WriteDescriptorSetInlineUniformBlock");
    py::class_<::vk::SurfaceCapabilitiesKHR> s_vk_SurfaceCapabilitiesKHR(n_vk, "SurfaceCapabilitiesKHR");
    py::class_<::vk::SurfaceFormatKHR> s_vk_SurfaceFormatKHR(n_vk, "SurfaceFormatKHR");
    py::class_<::vk::AcquireNextImageInfoKHR> s_vk_AcquireNextImageInfoKHR(n_vk, "AcquireNextImageInfoKHR");
    py::class_<::vk::BindImageMemorySwapchainInfoKHR> s_vk_BindImageMemorySwapchainInfoKHR(n_vk, "BindImageMemorySwapchainInfoKHR");
    py::class_<::vk::DeviceGroupPresentCapabilitiesKHR> s_vk_DeviceGroupPresentCapabilitiesKHR(n_vk, "DeviceGroupPresentCapabilitiesKHR");
    py::class_<::vk::DeviceGroupPresentInfoKHR> s_vk_DeviceGroupPresentInfoKHR(n_vk, "DeviceGroupPresentInfoKHR");
    py::class_<::vk::DeviceGroupSwapchainCreateInfoKHR> s_vk_DeviceGroupSwapchainCreateInfoKHR(n_vk, "DeviceGroupSwapchainCreateInfoKHR");
    py::class_<::vk::ImageSwapchainCreateInfoKHR> s_vk_ImageSwapchainCreateInfoKHR(n_vk, "ImageSwapchainCreateInfoKHR");
    py::class_<::vk::PresentInfoKHR> s_vk_PresentInfoKHR(n_vk, "PresentInfoKHR");
    py::class_<::vk::SwapchainCreateInfoKHR> s_vk_SwapchainCreateInfoKHR(n_vk, "SwapchainCreateInfoKHR");
    py::class_<::vk::DisplayModeCreateInfoKHR> s_vk_DisplayModeCreateInfoKHR(n_vk, "DisplayModeCreateInfoKHR");
    py::class_<::vk::DisplayModeParametersKHR> s_vk_DisplayModeParametersKHR(n_vk, "DisplayModeParametersKHR");
    py::class_<::vk::DisplayModePropertiesKHR> s_vk_DisplayModePropertiesKHR(n_vk, "DisplayModePropertiesKHR");
    py::class_<::vk::DisplayPlaneCapabilitiesKHR> s_vk_DisplayPlaneCapabilitiesKHR(n_vk, "DisplayPlaneCapabilitiesKHR");
    py::class_<::vk::DisplayPlanePropertiesKHR> s_vk_DisplayPlanePropertiesKHR(n_vk, "DisplayPlanePropertiesKHR");
    py::class_<::vk::DisplayPropertiesKHR> s_vk_DisplayPropertiesKHR(n_vk, "DisplayPropertiesKHR");
    py::class_<::vk::DisplaySurfaceCreateInfoKHR> s_vk_DisplaySurfaceCreateInfoKHR(n_vk, "DisplaySurfaceCreateInfoKHR");
    py::class_<::vk::DisplayPresentInfoKHR> s_vk_DisplayPresentInfoKHR(n_vk, "DisplayPresentInfoKHR");
    py::class_<::vk::DebugReportCallbackCreateInfoEXT> s_vk_DebugReportCallbackCreateInfoEXT(n_vk, "DebugReportCallbackCreateInfoEXT");
    py::class_<::vk::PipelineRasterizationStateRasterizationOrderAMD> s_vk_PipelineRasterizationStateRasterizationOrderAMD(n_vk, "PipelineRasterizationStateRasterizationOrderAMD");
    py::class_<::vk::DebugMarkerMarkerInfoEXT> s_vk_DebugMarkerMarkerInfoEXT(n_vk, "DebugMarkerMarkerInfoEXT");
    py::class_<::vk::DebugMarkerObjectNameInfoEXT> s_vk_DebugMarkerObjectNameInfoEXT(n_vk, "DebugMarkerObjectNameInfoEXT");
    py::class_<::vk::DebugMarkerObjectTagInfoEXT> s_vk_DebugMarkerObjectTagInfoEXT(n_vk, "DebugMarkerObjectTagInfoEXT");
    py::class_<::vk::BindVideoSessionMemoryInfoKHR> s_vk_BindVideoSessionMemoryInfoKHR(n_vk, "BindVideoSessionMemoryInfoKHR");
    py::class_<::vk::PhysicalDeviceVideoFormatInfoKHR> s_vk_PhysicalDeviceVideoFormatInfoKHR(n_vk, "PhysicalDeviceVideoFormatInfoKHR");
    py::class_<::vk::QueueFamilyQueryResultStatusPropertiesKHR> s_vk_QueueFamilyQueryResultStatusPropertiesKHR(n_vk, "QueueFamilyQueryResultStatusPropertiesKHR");
    py::class_<::vk::QueueFamilyVideoPropertiesKHR> s_vk_QueueFamilyVideoPropertiesKHR(n_vk, "QueueFamilyVideoPropertiesKHR");
    py::class_<::vk::VideoBeginCodingInfoKHR> s_vk_VideoBeginCodingInfoKHR(n_vk, "VideoBeginCodingInfoKHR");
    py::class_<::vk::VideoCapabilitiesKHR> s_vk_VideoCapabilitiesKHR(n_vk, "VideoCapabilitiesKHR");
    py::class_<::vk::VideoCodingControlInfoKHR> s_vk_VideoCodingControlInfoKHR(n_vk, "VideoCodingControlInfoKHR");
    py::class_<::vk::VideoEndCodingInfoKHR> s_vk_VideoEndCodingInfoKHR(n_vk, "VideoEndCodingInfoKHR");
    py::class_<::vk::VideoFormatPropertiesKHR> s_vk_VideoFormatPropertiesKHR(n_vk, "VideoFormatPropertiesKHR");
    py::class_<::vk::VideoPictureResourceInfoKHR> s_vk_VideoPictureResourceInfoKHR(n_vk, "VideoPictureResourceInfoKHR");
    py::class_<::vk::VideoProfileInfoKHR> s_vk_VideoProfileInfoKHR(n_vk, "VideoProfileInfoKHR");
    py::class_<::vk::VideoProfileListInfoKHR> s_vk_VideoProfileListInfoKHR(n_vk, "VideoProfileListInfoKHR");
    py::class_<::vk::VideoReferenceSlotInfoKHR> s_vk_VideoReferenceSlotInfoKHR(n_vk, "VideoReferenceSlotInfoKHR");
    py::class_<::vk::VideoSessionCreateInfoKHR> s_vk_VideoSessionCreateInfoKHR(n_vk, "VideoSessionCreateInfoKHR");
    py::class_<::vk::VideoSessionMemoryRequirementsKHR> s_vk_VideoSessionMemoryRequirementsKHR(n_vk, "VideoSessionMemoryRequirementsKHR");
    py::class_<::vk::VideoSessionParametersCreateInfoKHR> s_vk_VideoSessionParametersCreateInfoKHR(n_vk, "VideoSessionParametersCreateInfoKHR");
    py::class_<::vk::VideoSessionParametersUpdateInfoKHR> s_vk_VideoSessionParametersUpdateInfoKHR(n_vk, "VideoSessionParametersUpdateInfoKHR");
    py::class_<::vk::VideoDecodeCapabilitiesKHR> s_vk_VideoDecodeCapabilitiesKHR(n_vk, "VideoDecodeCapabilitiesKHR");
    py::class_<::vk::VideoDecodeInfoKHR> s_vk_VideoDecodeInfoKHR(n_vk, "VideoDecodeInfoKHR");
    py::class_<::vk::VideoDecodeUsageInfoKHR> s_vk_VideoDecodeUsageInfoKHR(n_vk, "VideoDecodeUsageInfoKHR");
    py::class_<::vk::DedicatedAllocationBufferCreateInfoNV> s_vk_DedicatedAllocationBufferCreateInfoNV(n_vk, "DedicatedAllocationBufferCreateInfoNV");
    py::class_<::vk::DedicatedAllocationImageCreateInfoNV> s_vk_DedicatedAllocationImageCreateInfoNV(n_vk, "DedicatedAllocationImageCreateInfoNV");
    py::class_<::vk::DedicatedAllocationMemoryAllocateInfoNV> s_vk_DedicatedAllocationMemoryAllocateInfoNV(n_vk, "DedicatedAllocationMemoryAllocateInfoNV");
    py::class_<::vk::PhysicalDeviceTransformFeedbackFeaturesEXT> s_vk_PhysicalDeviceTransformFeedbackFeaturesEXT(n_vk, "PhysicalDeviceTransformFeedbackFeaturesEXT");
    py::class_<::vk::PhysicalDeviceTransformFeedbackPropertiesEXT> s_vk_PhysicalDeviceTransformFeedbackPropertiesEXT(n_vk, "PhysicalDeviceTransformFeedbackPropertiesEXT");
    py::class_<::vk::PipelineRasterizationStateStreamCreateInfoEXT> s_vk_PipelineRasterizationStateStreamCreateInfoEXT(n_vk, "PipelineRasterizationStateStreamCreateInfoEXT");
    py::class_<::vk::CuFunctionCreateInfoNVX> s_vk_CuFunctionCreateInfoNVX(n_vk, "CuFunctionCreateInfoNVX");
    py::class_<::vk::CuLaunchInfoNVX> s_vk_CuLaunchInfoNVX(n_vk, "CuLaunchInfoNVX");
    py::class_<::vk::CuModuleCreateInfoNVX> s_vk_CuModuleCreateInfoNVX(n_vk, "CuModuleCreateInfoNVX");
    py::class_<::vk::ImageViewAddressPropertiesNVX> s_vk_ImageViewAddressPropertiesNVX(n_vk, "ImageViewAddressPropertiesNVX");
    py::class_<::vk::ImageViewHandleInfoNVX> s_vk_ImageViewHandleInfoNVX(n_vk, "ImageViewHandleInfoNVX");
    py::class_<::vk::VideoEncodeH264CapabilitiesKHR> s_vk_VideoEncodeH264CapabilitiesKHR(n_vk, "VideoEncodeH264CapabilitiesKHR");
    py::class_<::vk::VideoEncodeH264DpbSlotInfoKHR> s_vk_VideoEncodeH264DpbSlotInfoKHR(n_vk, "VideoEncodeH264DpbSlotInfoKHR");
    py::class_<::vk::VideoEncodeH264FrameSizeKHR> s_vk_VideoEncodeH264FrameSizeKHR(n_vk, "VideoEncodeH264FrameSizeKHR");
    py::class_<::vk::VideoEncodeH264GopRemainingFrameInfoKHR> s_vk_VideoEncodeH264GopRemainingFrameInfoKHR(n_vk, "VideoEncodeH264GopRemainingFrameInfoKHR");
    py::class_<::vk::VideoEncodeH264NaluSliceInfoKHR> s_vk_VideoEncodeH264NaluSliceInfoKHR(n_vk, "VideoEncodeH264NaluSliceInfoKHR");
    py::class_<::vk::VideoEncodeH264PictureInfoKHR> s_vk_VideoEncodeH264PictureInfoKHR(n_vk, "VideoEncodeH264PictureInfoKHR");
    py::class_<::vk::VideoEncodeH264ProfileInfoKHR> s_vk_VideoEncodeH264ProfileInfoKHR(n_vk, "VideoEncodeH264ProfileInfoKHR");
    py::class_<::vk::VideoEncodeH264QpKHR> s_vk_VideoEncodeH264QpKHR(n_vk, "VideoEncodeH264QpKHR");
    py::class_<::vk::VideoEncodeH264QualityLevelPropertiesKHR> s_vk_VideoEncodeH264QualityLevelPropertiesKHR(n_vk, "VideoEncodeH264QualityLevelPropertiesKHR");
    py::class_<::vk::VideoEncodeH264RateControlInfoKHR> s_vk_VideoEncodeH264RateControlInfoKHR(n_vk, "VideoEncodeH264RateControlInfoKHR");
    py::class_<::vk::VideoEncodeH264RateControlLayerInfoKHR> s_vk_VideoEncodeH264RateControlLayerInfoKHR(n_vk, "VideoEncodeH264RateControlLayerInfoKHR");
    py::class_<::vk::VideoEncodeH264SessionCreateInfoKHR> s_vk_VideoEncodeH264SessionCreateInfoKHR(n_vk, "VideoEncodeH264SessionCreateInfoKHR");
    py::class_<::vk::VideoEncodeH264SessionParametersAddInfoKHR> s_vk_VideoEncodeH264SessionParametersAddInfoKHR(n_vk, "VideoEncodeH264SessionParametersAddInfoKHR");
    py::class_<::vk::VideoEncodeH264SessionParametersCreateInfoKHR> s_vk_VideoEncodeH264SessionParametersCreateInfoKHR(n_vk, "VideoEncodeH264SessionParametersCreateInfoKHR");
    py::class_<::vk::VideoEncodeH264SessionParametersFeedbackInfoKHR> s_vk_VideoEncodeH264SessionParametersFeedbackInfoKHR(n_vk, "VideoEncodeH264SessionParametersFeedbackInfoKHR");
    py::class_<::vk::VideoEncodeH264SessionParametersGetInfoKHR> s_vk_VideoEncodeH264SessionParametersGetInfoKHR(n_vk, "VideoEncodeH264SessionParametersGetInfoKHR");
    py::class_<::vk::VideoEncodeH265CapabilitiesKHR> s_vk_VideoEncodeH265CapabilitiesKHR(n_vk, "VideoEncodeH265CapabilitiesKHR");
    py::class_<::vk::VideoEncodeH265DpbSlotInfoKHR> s_vk_VideoEncodeH265DpbSlotInfoKHR(n_vk, "VideoEncodeH265DpbSlotInfoKHR");
    py::class_<::vk::VideoEncodeH265FrameSizeKHR> s_vk_VideoEncodeH265FrameSizeKHR(n_vk, "VideoEncodeH265FrameSizeKHR");
    py::class_<::vk::VideoEncodeH265GopRemainingFrameInfoKHR> s_vk_VideoEncodeH265GopRemainingFrameInfoKHR(n_vk, "VideoEncodeH265GopRemainingFrameInfoKHR");
    py::class_<::vk::VideoEncodeH265NaluSliceSegmentInfoKHR> s_vk_VideoEncodeH265NaluSliceSegmentInfoKHR(n_vk, "VideoEncodeH265NaluSliceSegmentInfoKHR");
    py::class_<::vk::VideoEncodeH265PictureInfoKHR> s_vk_VideoEncodeH265PictureInfoKHR(n_vk, "VideoEncodeH265PictureInfoKHR");
    py::class_<::vk::VideoEncodeH265ProfileInfoKHR> s_vk_VideoEncodeH265ProfileInfoKHR(n_vk, "VideoEncodeH265ProfileInfoKHR");
    py::class_<::vk::VideoEncodeH265QpKHR> s_vk_VideoEncodeH265QpKHR(n_vk, "VideoEncodeH265QpKHR");
    py::class_<::vk::VideoEncodeH265QualityLevelPropertiesKHR> s_vk_VideoEncodeH265QualityLevelPropertiesKHR(n_vk, "VideoEncodeH265QualityLevelPropertiesKHR");
    py::class_<::vk::VideoEncodeH265RateControlInfoKHR> s_vk_VideoEncodeH265RateControlInfoKHR(n_vk, "VideoEncodeH265RateControlInfoKHR");
    py::class_<::vk::VideoEncodeH265RateControlLayerInfoKHR> s_vk_VideoEncodeH265RateControlLayerInfoKHR(n_vk, "VideoEncodeH265RateControlLayerInfoKHR");
    py::class_<::vk::VideoEncodeH265SessionCreateInfoKHR> s_vk_VideoEncodeH265SessionCreateInfoKHR(n_vk, "VideoEncodeH265SessionCreateInfoKHR");
    py::class_<::vk::VideoEncodeH265SessionParametersAddInfoKHR> s_vk_VideoEncodeH265SessionParametersAddInfoKHR(n_vk, "VideoEncodeH265SessionParametersAddInfoKHR");
    py::class_<::vk::VideoEncodeH265SessionParametersCreateInfoKHR> s_vk_VideoEncodeH265SessionParametersCreateInfoKHR(n_vk, "VideoEncodeH265SessionParametersCreateInfoKHR");
    py::class_<::vk::VideoEncodeH265SessionParametersFeedbackInfoKHR> s_vk_VideoEncodeH265SessionParametersFeedbackInfoKHR(n_vk, "VideoEncodeH265SessionParametersFeedbackInfoKHR");
    py::class_<::vk::VideoEncodeH265SessionParametersGetInfoKHR> s_vk_VideoEncodeH265SessionParametersGetInfoKHR(n_vk, "VideoEncodeH265SessionParametersGetInfoKHR");
    py::class_<::vk::VideoDecodeH264CapabilitiesKHR> s_vk_VideoDecodeH264CapabilitiesKHR(n_vk, "VideoDecodeH264CapabilitiesKHR");
    py::class_<::vk::VideoDecodeH264DpbSlotInfoKHR> s_vk_VideoDecodeH264DpbSlotInfoKHR(n_vk, "VideoDecodeH264DpbSlotInfoKHR");
    py::class_<::vk::VideoDecodeH264PictureInfoKHR> s_vk_VideoDecodeH264PictureInfoKHR(n_vk, "VideoDecodeH264PictureInfoKHR");
    py::class_<::vk::VideoDecodeH264ProfileInfoKHR> s_vk_VideoDecodeH264ProfileInfoKHR(n_vk, "VideoDecodeH264ProfileInfoKHR");
    py::class_<::vk::VideoDecodeH264SessionParametersAddInfoKHR> s_vk_VideoDecodeH264SessionParametersAddInfoKHR(n_vk, "VideoDecodeH264SessionParametersAddInfoKHR");
    py::class_<::vk::VideoDecodeH264SessionParametersCreateInfoKHR> s_vk_VideoDecodeH264SessionParametersCreateInfoKHR(n_vk, "VideoDecodeH264SessionParametersCreateInfoKHR");
    py::class_<::vk::TextureLODGatherFormatPropertiesAMD> s_vk_TextureLODGatherFormatPropertiesAMD(n_vk, "TextureLODGatherFormatPropertiesAMD");
    py::class_<::vk::ShaderResourceUsageAMD> s_vk_ShaderResourceUsageAMD(n_vk, "ShaderResourceUsageAMD");
    py::class_<::vk::ShaderStatisticsInfoAMD> s_vk_ShaderStatisticsInfoAMD(n_vk, "ShaderStatisticsInfoAMD");
    py::class_<::vk::AttachmentSampleCountInfoAMD> s_vk_AttachmentSampleCountInfoAMD(n_vk, "AttachmentSampleCountInfoAMD");
    py::class_<::vk::MultiviewPerViewAttributesInfoNVX> s_vk_MultiviewPerViewAttributesInfoNVX(n_vk, "MultiviewPerViewAttributesInfoNVX");
    py::class_<::vk::RenderingFragmentDensityMapAttachmentInfoEXT> s_vk_RenderingFragmentDensityMapAttachmentInfoEXT(n_vk, "RenderingFragmentDensityMapAttachmentInfoEXT");
    py::class_<::vk::RenderingFragmentShadingRateAttachmentInfoKHR> s_vk_RenderingFragmentShadingRateAttachmentInfoKHR(n_vk, "RenderingFragmentShadingRateAttachmentInfoKHR");
    py::class_<::vk::PhysicalDeviceCornerSampledImageFeaturesNV> s_vk_PhysicalDeviceCornerSampledImageFeaturesNV(n_vk, "PhysicalDeviceCornerSampledImageFeaturesNV");
    py::class_<::vk::ExternalImageFormatPropertiesNV> s_vk_ExternalImageFormatPropertiesNV(n_vk, "ExternalImageFormatPropertiesNV");
    py::class_<::vk::ExportMemoryAllocateInfoNV> s_vk_ExportMemoryAllocateInfoNV(n_vk, "ExportMemoryAllocateInfoNV");
    py::class_<::vk::ExternalMemoryImageCreateInfoNV> s_vk_ExternalMemoryImageCreateInfoNV(n_vk, "ExternalMemoryImageCreateInfoNV");
    py::class_<::vk::ValidationFlagsEXT> s_vk_ValidationFlagsEXT(n_vk, "ValidationFlagsEXT");
    py::class_<::vk::ImageViewASTCDecodeModeEXT> s_vk_ImageViewASTCDecodeModeEXT(n_vk, "ImageViewASTCDecodeModeEXT");
    py::class_<::vk::PhysicalDeviceASTCDecodeFeaturesEXT> s_vk_PhysicalDeviceASTCDecodeFeaturesEXT(n_vk, "PhysicalDeviceASTCDecodeFeaturesEXT");
    py::class_<::vk::PhysicalDevicePipelineRobustnessFeaturesEXT> s_vk_PhysicalDevicePipelineRobustnessFeaturesEXT(n_vk, "PhysicalDevicePipelineRobustnessFeaturesEXT");
    py::class_<::vk::PhysicalDevicePipelineRobustnessPropertiesEXT> s_vk_PhysicalDevicePipelineRobustnessPropertiesEXT(n_vk, "PhysicalDevicePipelineRobustnessPropertiesEXT");
    py::class_<::vk::PipelineRobustnessCreateInfoEXT> s_vk_PipelineRobustnessCreateInfoEXT(n_vk, "PipelineRobustnessCreateInfoEXT");
    py::class_<::vk::ImportMemoryFdInfoKHR> s_vk_ImportMemoryFdInfoKHR(n_vk, "ImportMemoryFdInfoKHR");
    py::class_<::vk::MemoryFdPropertiesKHR> s_vk_MemoryFdPropertiesKHR(n_vk, "MemoryFdPropertiesKHR");
    py::class_<::vk::MemoryGetFdInfoKHR> s_vk_MemoryGetFdInfoKHR(n_vk, "MemoryGetFdInfoKHR");
    py::class_<::vk::ImportSemaphoreFdInfoKHR> s_vk_ImportSemaphoreFdInfoKHR(n_vk, "ImportSemaphoreFdInfoKHR");
    py::class_<::vk::SemaphoreGetFdInfoKHR> s_vk_SemaphoreGetFdInfoKHR(n_vk, "SemaphoreGetFdInfoKHR");
    py::class_<::vk::PhysicalDevicePushDescriptorPropertiesKHR> s_vk_PhysicalDevicePushDescriptorPropertiesKHR(n_vk, "PhysicalDevicePushDescriptorPropertiesKHR");
    py::class_<::vk::CommandBufferInheritanceConditionalRenderingInfoEXT> s_vk_CommandBufferInheritanceConditionalRenderingInfoEXT(n_vk, "CommandBufferInheritanceConditionalRenderingInfoEXT");
    py::class_<::vk::ConditionalRenderingBeginInfoEXT> s_vk_ConditionalRenderingBeginInfoEXT(n_vk, "ConditionalRenderingBeginInfoEXT");
    py::class_<::vk::PhysicalDeviceConditionalRenderingFeaturesEXT> s_vk_PhysicalDeviceConditionalRenderingFeaturesEXT(n_vk, "PhysicalDeviceConditionalRenderingFeaturesEXT");
    py::class_<::vk::PresentRegionKHR> s_vk_PresentRegionKHR(n_vk, "PresentRegionKHR");
    py::class_<::vk::PresentRegionsKHR> s_vk_PresentRegionsKHR(n_vk, "PresentRegionsKHR");
    py::class_<::vk::RectLayerKHR> s_vk_RectLayerKHR(n_vk, "RectLayerKHR");
    py::class_<::vk::PipelineViewportWScalingStateCreateInfoNV> s_vk_PipelineViewportWScalingStateCreateInfoNV(n_vk, "PipelineViewportWScalingStateCreateInfoNV");
    py::class_<::vk::ViewportWScalingNV> s_vk_ViewportWScalingNV(n_vk, "ViewportWScalingNV");
    py::class_<::vk::SurfaceCapabilities2EXT> s_vk_SurfaceCapabilities2EXT(n_vk, "SurfaceCapabilities2EXT");
    py::class_<::vk::DeviceEventInfoEXT> s_vk_DeviceEventInfoEXT(n_vk, "DeviceEventInfoEXT");
    py::class_<::vk::DisplayEventInfoEXT> s_vk_DisplayEventInfoEXT(n_vk, "DisplayEventInfoEXT");
    py::class_<::vk::DisplayPowerInfoEXT> s_vk_DisplayPowerInfoEXT(n_vk, "DisplayPowerInfoEXT");
    py::class_<::vk::SwapchainCounterCreateInfoEXT> s_vk_SwapchainCounterCreateInfoEXT(n_vk, "SwapchainCounterCreateInfoEXT");
    py::class_<::vk::PastPresentationTimingGOOGLE> s_vk_PastPresentationTimingGOOGLE(n_vk, "PastPresentationTimingGOOGLE");
    py::class_<::vk::PresentTimeGOOGLE> s_vk_PresentTimeGOOGLE(n_vk, "PresentTimeGOOGLE");
    py::class_<::vk::PresentTimesInfoGOOGLE> s_vk_PresentTimesInfoGOOGLE(n_vk, "PresentTimesInfoGOOGLE");
    py::class_<::vk::RefreshCycleDurationGOOGLE> s_vk_RefreshCycleDurationGOOGLE(n_vk, "RefreshCycleDurationGOOGLE");
    py::class_<::vk::PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX> s_vk_PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(n_vk, "PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX");
    py::class_<::vk::PipelineViewportSwizzleStateCreateInfoNV> s_vk_PipelineViewportSwizzleStateCreateInfoNV(n_vk, "PipelineViewportSwizzleStateCreateInfoNV");
    py::class_<::vk::ViewportSwizzleNV> s_vk_ViewportSwizzleNV(n_vk, "ViewportSwizzleNV");
    py::class_<::vk::PhysicalDeviceDiscardRectanglePropertiesEXT> s_vk_PhysicalDeviceDiscardRectanglePropertiesEXT(n_vk, "PhysicalDeviceDiscardRectanglePropertiesEXT");
    py::class_<::vk::PipelineDiscardRectangleStateCreateInfoEXT> s_vk_PipelineDiscardRectangleStateCreateInfoEXT(n_vk, "PipelineDiscardRectangleStateCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceConservativeRasterizationPropertiesEXT> s_vk_PhysicalDeviceConservativeRasterizationPropertiesEXT(n_vk, "PhysicalDeviceConservativeRasterizationPropertiesEXT");
    py::class_<::vk::PipelineRasterizationConservativeStateCreateInfoEXT> s_vk_PipelineRasterizationConservativeStateCreateInfoEXT(n_vk, "PipelineRasterizationConservativeStateCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceDepthClipEnableFeaturesEXT> s_vk_PhysicalDeviceDepthClipEnableFeaturesEXT(n_vk, "PhysicalDeviceDepthClipEnableFeaturesEXT");
    py::class_<::vk::PipelineRasterizationDepthClipStateCreateInfoEXT> s_vk_PipelineRasterizationDepthClipStateCreateInfoEXT(n_vk, "PipelineRasterizationDepthClipStateCreateInfoEXT");
    py::class_<::vk::HdrMetadataEXT> s_vk_HdrMetadataEXT(n_vk, "HdrMetadataEXT");
    py::class_<::vk::XYColorEXT> s_vk_XYColorEXT(n_vk, "XYColorEXT");
    py::class_<::vk::PhysicalDeviceRelaxedLineRasterizationFeaturesIMG> s_vk_PhysicalDeviceRelaxedLineRasterizationFeaturesIMG(n_vk, "PhysicalDeviceRelaxedLineRasterizationFeaturesIMG");
    py::class_<::vk::SharedPresentSurfaceCapabilitiesKHR> s_vk_SharedPresentSurfaceCapabilitiesKHR(n_vk, "SharedPresentSurfaceCapabilitiesKHR");
    py::class_<::vk::FenceGetFdInfoKHR> s_vk_FenceGetFdInfoKHR(n_vk, "FenceGetFdInfoKHR");
    py::class_<::vk::ImportFenceFdInfoKHR> s_vk_ImportFenceFdInfoKHR(n_vk, "ImportFenceFdInfoKHR");
    py::class_<::vk::AcquireProfilingLockInfoKHR> s_vk_AcquireProfilingLockInfoKHR(n_vk, "AcquireProfilingLockInfoKHR");
    py::class_<::vk::PerformanceCounterDescriptionKHR> s_vk_PerformanceCounterDescriptionKHR(n_vk, "PerformanceCounterDescriptionKHR");
    py::class_<::vk::PerformanceCounterKHR> s_vk_PerformanceCounterKHR(n_vk, "PerformanceCounterKHR");
    py::class_<::vk::PerformanceQuerySubmitInfoKHR> s_vk_PerformanceQuerySubmitInfoKHR(n_vk, "PerformanceQuerySubmitInfoKHR");
    py::class_<::vk::PhysicalDevicePerformanceQueryFeaturesKHR> s_vk_PhysicalDevicePerformanceQueryFeaturesKHR(n_vk, "PhysicalDevicePerformanceQueryFeaturesKHR");
    py::class_<::vk::PhysicalDevicePerformanceQueryPropertiesKHR> s_vk_PhysicalDevicePerformanceQueryPropertiesKHR(n_vk, "PhysicalDevicePerformanceQueryPropertiesKHR");
    py::class_<::vk::QueryPoolPerformanceCreateInfoKHR> s_vk_QueryPoolPerformanceCreateInfoKHR(n_vk, "QueryPoolPerformanceCreateInfoKHR");
    py::class_<::vk::PhysicalDeviceSurfaceInfo2KHR> s_vk_PhysicalDeviceSurfaceInfo2KHR(n_vk, "PhysicalDeviceSurfaceInfo2KHR");
    py::class_<::vk::SurfaceCapabilities2KHR> s_vk_SurfaceCapabilities2KHR(n_vk, "SurfaceCapabilities2KHR");
    py::class_<::vk::SurfaceFormat2KHR> s_vk_SurfaceFormat2KHR(n_vk, "SurfaceFormat2KHR");
    py::class_<::vk::DisplayModeProperties2KHR> s_vk_DisplayModeProperties2KHR(n_vk, "DisplayModeProperties2KHR");
    py::class_<::vk::DisplayPlaneCapabilities2KHR> s_vk_DisplayPlaneCapabilities2KHR(n_vk, "DisplayPlaneCapabilities2KHR");
    py::class_<::vk::DisplayPlaneInfo2KHR> s_vk_DisplayPlaneInfo2KHR(n_vk, "DisplayPlaneInfo2KHR");
    py::class_<::vk::DisplayPlaneProperties2KHR> s_vk_DisplayPlaneProperties2KHR(n_vk, "DisplayPlaneProperties2KHR");
    py::class_<::vk::DisplayProperties2KHR> s_vk_DisplayProperties2KHR(n_vk, "DisplayProperties2KHR");
    py::class_<::vk::DebugUtilsLabelEXT> s_vk_DebugUtilsLabelEXT(n_vk, "DebugUtilsLabelEXT");
    py::class_<::vk::DebugUtilsMessengerCallbackDataEXT> s_vk_DebugUtilsMessengerCallbackDataEXT(n_vk, "DebugUtilsMessengerCallbackDataEXT");
    py::class_<::vk::DebugUtilsMessengerCreateInfoEXT> s_vk_DebugUtilsMessengerCreateInfoEXT(n_vk, "DebugUtilsMessengerCreateInfoEXT");
    py::class_<::vk::DebugUtilsObjectNameInfoEXT> s_vk_DebugUtilsObjectNameInfoEXT(n_vk, "DebugUtilsObjectNameInfoEXT");
    py::class_<::vk::DebugUtilsObjectTagInfoEXT> s_vk_DebugUtilsObjectTagInfoEXT(n_vk, "DebugUtilsObjectTagInfoEXT");
    py::class_<::vk::AttachmentSampleLocationsEXT> s_vk_AttachmentSampleLocationsEXT(n_vk, "AttachmentSampleLocationsEXT");
    py::class_<::vk::MultisamplePropertiesEXT> s_vk_MultisamplePropertiesEXT(n_vk, "MultisamplePropertiesEXT");
    py::class_<::vk::PhysicalDeviceSampleLocationsPropertiesEXT> s_vk_PhysicalDeviceSampleLocationsPropertiesEXT(n_vk, "PhysicalDeviceSampleLocationsPropertiesEXT");
    py::class_<::vk::PipelineSampleLocationsStateCreateInfoEXT> s_vk_PipelineSampleLocationsStateCreateInfoEXT(n_vk, "PipelineSampleLocationsStateCreateInfoEXT");
    py::class_<::vk::RenderPassSampleLocationsBeginInfoEXT> s_vk_RenderPassSampleLocationsBeginInfoEXT(n_vk, "RenderPassSampleLocationsBeginInfoEXT");
    py::class_<::vk::SampleLocationEXT> s_vk_SampleLocationEXT(n_vk, "SampleLocationEXT");
    py::class_<::vk::SampleLocationsInfoEXT> s_vk_SampleLocationsInfoEXT(n_vk, "SampleLocationsInfoEXT");
    py::class_<::vk::SubpassSampleLocationsEXT> s_vk_SubpassSampleLocationsEXT(n_vk, "SubpassSampleLocationsEXT");
    py::class_<::vk::PhysicalDeviceBlendOperationAdvancedFeaturesEXT> s_vk_PhysicalDeviceBlendOperationAdvancedFeaturesEXT(n_vk, "PhysicalDeviceBlendOperationAdvancedFeaturesEXT");
    py::class_<::vk::PhysicalDeviceBlendOperationAdvancedPropertiesEXT> s_vk_PhysicalDeviceBlendOperationAdvancedPropertiesEXT(n_vk, "PhysicalDeviceBlendOperationAdvancedPropertiesEXT");
    py::class_<::vk::PipelineColorBlendAdvancedStateCreateInfoEXT> s_vk_PipelineColorBlendAdvancedStateCreateInfoEXT(n_vk, "PipelineColorBlendAdvancedStateCreateInfoEXT");
    py::class_<::vk::PipelineCoverageToColorStateCreateInfoNV> s_vk_PipelineCoverageToColorStateCreateInfoNV(n_vk, "PipelineCoverageToColorStateCreateInfoNV");
    py::class_<::vk::AabbPositionsKHR> s_vk_AabbPositionsKHR(n_vk, "AabbPositionsKHR");
    py::class_<::vk::AccelerationStructureBuildGeometryInfoKHR> s_vk_AccelerationStructureBuildGeometryInfoKHR(n_vk, "AccelerationStructureBuildGeometryInfoKHR");
    py::class_<::vk::AccelerationStructureBuildRangeInfoKHR> s_vk_AccelerationStructureBuildRangeInfoKHR(n_vk, "AccelerationStructureBuildRangeInfoKHR");
    py::class_<::vk::AccelerationStructureBuildSizesInfoKHR> s_vk_AccelerationStructureBuildSizesInfoKHR(n_vk, "AccelerationStructureBuildSizesInfoKHR");
    py::class_<::vk::AccelerationStructureCreateInfoKHR> s_vk_AccelerationStructureCreateInfoKHR(n_vk, "AccelerationStructureCreateInfoKHR");
    py::class_<::vk::AccelerationStructureDeviceAddressInfoKHR> s_vk_AccelerationStructureDeviceAddressInfoKHR(n_vk, "AccelerationStructureDeviceAddressInfoKHR");
    py::class_<::vk::AccelerationStructureGeometryAabbsDataKHR> s_vk_AccelerationStructureGeometryAabbsDataKHR(n_vk, "AccelerationStructureGeometryAabbsDataKHR");
    py::class_<::vk::AccelerationStructureGeometryInstancesDataKHR> s_vk_AccelerationStructureGeometryInstancesDataKHR(n_vk, "AccelerationStructureGeometryInstancesDataKHR");
    py::class_<::vk::AccelerationStructureGeometryKHR> s_vk_AccelerationStructureGeometryKHR(n_vk, "AccelerationStructureGeometryKHR");
    py::class_<::vk::AccelerationStructureGeometryTrianglesDataKHR> s_vk_AccelerationStructureGeometryTrianglesDataKHR(n_vk, "AccelerationStructureGeometryTrianglesDataKHR");
    py::class_<::vk::AccelerationStructureInstanceKHR> s_vk_AccelerationStructureInstanceKHR(n_vk, "AccelerationStructureInstanceKHR");
    py::class_<::vk::AccelerationStructureVersionInfoKHR> s_vk_AccelerationStructureVersionInfoKHR(n_vk, "AccelerationStructureVersionInfoKHR");
    py::class_<::vk::CopyAccelerationStructureInfoKHR> s_vk_CopyAccelerationStructureInfoKHR(n_vk, "CopyAccelerationStructureInfoKHR");
    py::class_<::vk::CopyAccelerationStructureToMemoryInfoKHR> s_vk_CopyAccelerationStructureToMemoryInfoKHR(n_vk, "CopyAccelerationStructureToMemoryInfoKHR");
    py::class_<::vk::CopyMemoryToAccelerationStructureInfoKHR> s_vk_CopyMemoryToAccelerationStructureInfoKHR(n_vk, "CopyMemoryToAccelerationStructureInfoKHR");
    py::class_<::vk::PhysicalDeviceAccelerationStructureFeaturesKHR> s_vk_PhysicalDeviceAccelerationStructureFeaturesKHR(n_vk, "PhysicalDeviceAccelerationStructureFeaturesKHR");
    py::class_<::vk::PhysicalDeviceAccelerationStructurePropertiesKHR> s_vk_PhysicalDeviceAccelerationStructurePropertiesKHR(n_vk, "PhysicalDeviceAccelerationStructurePropertiesKHR");
    py::class_<::vk::TransformMatrixKHR> s_vk_TransformMatrixKHR(n_vk, "TransformMatrixKHR");
    py::class_<::vk::WriteDescriptorSetAccelerationStructureKHR> s_vk_WriteDescriptorSetAccelerationStructureKHR(n_vk, "WriteDescriptorSetAccelerationStructureKHR");
    py::class_<::vk::PhysicalDeviceRayTracingPipelineFeaturesKHR> s_vk_PhysicalDeviceRayTracingPipelineFeaturesKHR(n_vk, "PhysicalDeviceRayTracingPipelineFeaturesKHR");
    py::class_<::vk::PhysicalDeviceRayTracingPipelinePropertiesKHR> s_vk_PhysicalDeviceRayTracingPipelinePropertiesKHR(n_vk, "PhysicalDeviceRayTracingPipelinePropertiesKHR");
    py::class_<::vk::RayTracingPipelineCreateInfoKHR> s_vk_RayTracingPipelineCreateInfoKHR(n_vk, "RayTracingPipelineCreateInfoKHR");
    py::class_<::vk::RayTracingPipelineInterfaceCreateInfoKHR> s_vk_RayTracingPipelineInterfaceCreateInfoKHR(n_vk, "RayTracingPipelineInterfaceCreateInfoKHR");
    py::class_<::vk::RayTracingShaderGroupCreateInfoKHR> s_vk_RayTracingShaderGroupCreateInfoKHR(n_vk, "RayTracingShaderGroupCreateInfoKHR");
    py::class_<::vk::StridedDeviceAddressRegionKHR> s_vk_StridedDeviceAddressRegionKHR(n_vk, "StridedDeviceAddressRegionKHR");
    py::class_<::vk::TraceRaysIndirectCommandKHR> s_vk_TraceRaysIndirectCommandKHR(n_vk, "TraceRaysIndirectCommandKHR");
    py::class_<::vk::PhysicalDeviceRayQueryFeaturesKHR> s_vk_PhysicalDeviceRayQueryFeaturesKHR(n_vk, "PhysicalDeviceRayQueryFeaturesKHR");
    py::class_<::vk::PipelineCoverageModulationStateCreateInfoNV> s_vk_PipelineCoverageModulationStateCreateInfoNV(n_vk, "PipelineCoverageModulationStateCreateInfoNV");
    py::class_<::vk::PhysicalDeviceShaderSMBuiltinsFeaturesNV> s_vk_PhysicalDeviceShaderSMBuiltinsFeaturesNV(n_vk, "PhysicalDeviceShaderSMBuiltinsFeaturesNV");
    py::class_<::vk::PhysicalDeviceShaderSMBuiltinsPropertiesNV> s_vk_PhysicalDeviceShaderSMBuiltinsPropertiesNV(n_vk, "PhysicalDeviceShaderSMBuiltinsPropertiesNV");
    py::class_<::vk::DrmFormatModifierProperties2EXT> s_vk_DrmFormatModifierProperties2EXT(n_vk, "DrmFormatModifierProperties2EXT");
    py::class_<::vk::DrmFormatModifierPropertiesEXT> s_vk_DrmFormatModifierPropertiesEXT(n_vk, "DrmFormatModifierPropertiesEXT");
    py::class_<::vk::DrmFormatModifierPropertiesList2EXT> s_vk_DrmFormatModifierPropertiesList2EXT(n_vk, "DrmFormatModifierPropertiesList2EXT");
    py::class_<::vk::DrmFormatModifierPropertiesListEXT> s_vk_DrmFormatModifierPropertiesListEXT(n_vk, "DrmFormatModifierPropertiesListEXT");
    py::class_<::vk::ImageDrmFormatModifierExplicitCreateInfoEXT> s_vk_ImageDrmFormatModifierExplicitCreateInfoEXT(n_vk, "ImageDrmFormatModifierExplicitCreateInfoEXT");
    py::class_<::vk::ImageDrmFormatModifierListCreateInfoEXT> s_vk_ImageDrmFormatModifierListCreateInfoEXT(n_vk, "ImageDrmFormatModifierListCreateInfoEXT");
    py::class_<::vk::ImageDrmFormatModifierPropertiesEXT> s_vk_ImageDrmFormatModifierPropertiesEXT(n_vk, "ImageDrmFormatModifierPropertiesEXT");
    py::class_<::vk::PhysicalDeviceImageDrmFormatModifierInfoEXT> s_vk_PhysicalDeviceImageDrmFormatModifierInfoEXT(n_vk, "PhysicalDeviceImageDrmFormatModifierInfoEXT");
    py::class_<::vk::ShaderModuleValidationCacheCreateInfoEXT> s_vk_ShaderModuleValidationCacheCreateInfoEXT(n_vk, "ShaderModuleValidationCacheCreateInfoEXT");
    py::class_<::vk::ValidationCacheCreateInfoEXT> s_vk_ValidationCacheCreateInfoEXT(n_vk, "ValidationCacheCreateInfoEXT");
    py::class_<::vk::CoarseSampleLocationNV> s_vk_CoarseSampleLocationNV(n_vk, "CoarseSampleLocationNV");
    py::class_<::vk::CoarseSampleOrderCustomNV> s_vk_CoarseSampleOrderCustomNV(n_vk, "CoarseSampleOrderCustomNV");
    py::class_<::vk::PhysicalDeviceShadingRateImageFeaturesNV> s_vk_PhysicalDeviceShadingRateImageFeaturesNV(n_vk, "PhysicalDeviceShadingRateImageFeaturesNV");
    py::class_<::vk::PhysicalDeviceShadingRateImagePropertiesNV> s_vk_PhysicalDeviceShadingRateImagePropertiesNV(n_vk, "PhysicalDeviceShadingRateImagePropertiesNV");
    py::class_<::vk::PipelineViewportCoarseSampleOrderStateCreateInfoNV> s_vk_PipelineViewportCoarseSampleOrderStateCreateInfoNV(n_vk, "PipelineViewportCoarseSampleOrderStateCreateInfoNV");
    py::class_<::vk::PipelineViewportShadingRateImageStateCreateInfoNV> s_vk_PipelineViewportShadingRateImageStateCreateInfoNV(n_vk, "PipelineViewportShadingRateImageStateCreateInfoNV");
    py::class_<::vk::ShadingRatePaletteNV> s_vk_ShadingRatePaletteNV(n_vk, "ShadingRatePaletteNV");
    py::class_<::vk::AccelerationStructureCreateInfoNV> s_vk_AccelerationStructureCreateInfoNV(n_vk, "AccelerationStructureCreateInfoNV");
    py::class_<::vk::AccelerationStructureInfoNV> s_vk_AccelerationStructureInfoNV(n_vk, "AccelerationStructureInfoNV");
    py::class_<::vk::AccelerationStructureMemoryRequirementsInfoNV> s_vk_AccelerationStructureMemoryRequirementsInfoNV(n_vk, "AccelerationStructureMemoryRequirementsInfoNV");
    py::class_<::vk::BindAccelerationStructureMemoryInfoNV> s_vk_BindAccelerationStructureMemoryInfoNV(n_vk, "BindAccelerationStructureMemoryInfoNV");
    py::class_<::vk::GeometryAABBNV> s_vk_GeometryAABBNV(n_vk, "GeometryAABBNV");
    py::class_<::vk::GeometryDataNV> s_vk_GeometryDataNV(n_vk, "GeometryDataNV");
    py::class_<::vk::GeometryNV> s_vk_GeometryNV(n_vk, "GeometryNV");
    py::class_<::vk::GeometryTrianglesNV> s_vk_GeometryTrianglesNV(n_vk, "GeometryTrianglesNV");
    py::class_<::vk::PhysicalDeviceRayTracingPropertiesNV> s_vk_PhysicalDeviceRayTracingPropertiesNV(n_vk, "PhysicalDeviceRayTracingPropertiesNV");
    py::class_<::vk::RayTracingPipelineCreateInfoNV> s_vk_RayTracingPipelineCreateInfoNV(n_vk, "RayTracingPipelineCreateInfoNV");
    py::class_<::vk::RayTracingShaderGroupCreateInfoNV> s_vk_RayTracingShaderGroupCreateInfoNV(n_vk, "RayTracingShaderGroupCreateInfoNV");
    py::class_<::vk::WriteDescriptorSetAccelerationStructureNV> s_vk_WriteDescriptorSetAccelerationStructureNV(n_vk, "WriteDescriptorSetAccelerationStructureNV");
    py::class_<::vk::PhysicalDeviceRepresentativeFragmentTestFeaturesNV> s_vk_PhysicalDeviceRepresentativeFragmentTestFeaturesNV(n_vk, "PhysicalDeviceRepresentativeFragmentTestFeaturesNV");
    py::class_<::vk::PipelineRepresentativeFragmentTestStateCreateInfoNV> s_vk_PipelineRepresentativeFragmentTestStateCreateInfoNV(n_vk, "PipelineRepresentativeFragmentTestStateCreateInfoNV");
    py::class_<::vk::FilterCubicImageViewImageFormatPropertiesEXT> s_vk_FilterCubicImageViewImageFormatPropertiesEXT(n_vk, "FilterCubicImageViewImageFormatPropertiesEXT");
    py::class_<::vk::PhysicalDeviceImageViewImageFormatInfoEXT> s_vk_PhysicalDeviceImageViewImageFormatInfoEXT(n_vk, "PhysicalDeviceImageViewImageFormatInfoEXT");
    py::class_<::vk::ImportMemoryHostPointerInfoEXT> s_vk_ImportMemoryHostPointerInfoEXT(n_vk, "ImportMemoryHostPointerInfoEXT");
    py::class_<::vk::MemoryHostPointerPropertiesEXT> s_vk_MemoryHostPointerPropertiesEXT(n_vk, "MemoryHostPointerPropertiesEXT");
    py::class_<::vk::PhysicalDeviceExternalMemoryHostPropertiesEXT> s_vk_PhysicalDeviceExternalMemoryHostPropertiesEXT(n_vk, "PhysicalDeviceExternalMemoryHostPropertiesEXT");
    py::class_<::vk::PhysicalDeviceShaderClockFeaturesKHR> s_vk_PhysicalDeviceShaderClockFeaturesKHR(n_vk, "PhysicalDeviceShaderClockFeaturesKHR");
    py::class_<::vk::PipelineCompilerControlCreateInfoAMD> s_vk_PipelineCompilerControlCreateInfoAMD(n_vk, "PipelineCompilerControlCreateInfoAMD");
    py::class_<::vk::PhysicalDeviceShaderCorePropertiesAMD> s_vk_PhysicalDeviceShaderCorePropertiesAMD(n_vk, "PhysicalDeviceShaderCorePropertiesAMD");
    py::class_<::vk::VideoDecodeH265CapabilitiesKHR> s_vk_VideoDecodeH265CapabilitiesKHR(n_vk, "VideoDecodeH265CapabilitiesKHR");
    py::class_<::vk::VideoDecodeH265DpbSlotInfoKHR> s_vk_VideoDecodeH265DpbSlotInfoKHR(n_vk, "VideoDecodeH265DpbSlotInfoKHR");
    py::class_<::vk::VideoDecodeH265PictureInfoKHR> s_vk_VideoDecodeH265PictureInfoKHR(n_vk, "VideoDecodeH265PictureInfoKHR");
    py::class_<::vk::VideoDecodeH265ProfileInfoKHR> s_vk_VideoDecodeH265ProfileInfoKHR(n_vk, "VideoDecodeH265ProfileInfoKHR");
    py::class_<::vk::VideoDecodeH265SessionParametersAddInfoKHR> s_vk_VideoDecodeH265SessionParametersAddInfoKHR(n_vk, "VideoDecodeH265SessionParametersAddInfoKHR");
    py::class_<::vk::VideoDecodeH265SessionParametersCreateInfoKHR> s_vk_VideoDecodeH265SessionParametersCreateInfoKHR(n_vk, "VideoDecodeH265SessionParametersCreateInfoKHR");
    py::class_<::vk::DeviceQueueGlobalPriorityCreateInfoKHR> s_vk_DeviceQueueGlobalPriorityCreateInfoKHR(n_vk, "DeviceQueueGlobalPriorityCreateInfoKHR");
    py::class_<::vk::PhysicalDeviceGlobalPriorityQueryFeaturesKHR> s_vk_PhysicalDeviceGlobalPriorityQueryFeaturesKHR(n_vk, "PhysicalDeviceGlobalPriorityQueryFeaturesKHR");
    py::class_<::vk::QueueFamilyGlobalPriorityPropertiesKHR> s_vk_QueueFamilyGlobalPriorityPropertiesKHR(n_vk, "QueueFamilyGlobalPriorityPropertiesKHR");
    py::class_<::vk::DeviceMemoryOverallocationCreateInfoAMD> s_vk_DeviceMemoryOverallocationCreateInfoAMD(n_vk, "DeviceMemoryOverallocationCreateInfoAMD");
    py::class_<::vk::PhysicalDeviceVertexAttributeDivisorPropertiesEXT> s_vk_PhysicalDeviceVertexAttributeDivisorPropertiesEXT(n_vk, "PhysicalDeviceVertexAttributeDivisorPropertiesEXT");
    py::class_<::vk::PhysicalDeviceComputeShaderDerivativesFeaturesNV> s_vk_PhysicalDeviceComputeShaderDerivativesFeaturesNV(n_vk, "PhysicalDeviceComputeShaderDerivativesFeaturesNV");
    py::class_<::vk::DrawMeshTasksIndirectCommandNV> s_vk_DrawMeshTasksIndirectCommandNV(n_vk, "DrawMeshTasksIndirectCommandNV");
    py::class_<::vk::PhysicalDeviceMeshShaderFeaturesNV> s_vk_PhysicalDeviceMeshShaderFeaturesNV(n_vk, "PhysicalDeviceMeshShaderFeaturesNV");
    py::class_<::vk::PhysicalDeviceMeshShaderPropertiesNV> s_vk_PhysicalDeviceMeshShaderPropertiesNV(n_vk, "PhysicalDeviceMeshShaderPropertiesNV");
    py::class_<::vk::PhysicalDeviceShaderImageFootprintFeaturesNV> s_vk_PhysicalDeviceShaderImageFootprintFeaturesNV(n_vk, "PhysicalDeviceShaderImageFootprintFeaturesNV");
    py::class_<::vk::PhysicalDeviceExclusiveScissorFeaturesNV> s_vk_PhysicalDeviceExclusiveScissorFeaturesNV(n_vk, "PhysicalDeviceExclusiveScissorFeaturesNV");
    py::class_<::vk::PipelineViewportExclusiveScissorStateCreateInfoNV> s_vk_PipelineViewportExclusiveScissorStateCreateInfoNV(n_vk, "PipelineViewportExclusiveScissorStateCreateInfoNV");
    py::class_<::vk::CheckpointDataNV> s_vk_CheckpointDataNV(n_vk, "CheckpointDataNV");
    py::class_<::vk::QueueFamilyCheckpointPropertiesNV> s_vk_QueueFamilyCheckpointPropertiesNV(n_vk, "QueueFamilyCheckpointPropertiesNV");
    py::class_<::vk::PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL> s_vk_PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL(n_vk, "PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL");
    py::class_<::vk::InitializePerformanceApiInfoINTEL> s_vk_InitializePerformanceApiInfoINTEL(n_vk, "InitializePerformanceApiInfoINTEL");
    py::class_<::vk::PerformanceConfigurationAcquireInfoINTEL> s_vk_PerformanceConfigurationAcquireInfoINTEL(n_vk, "PerformanceConfigurationAcquireInfoINTEL");
    py::class_<::vk::PerformanceMarkerInfoINTEL> s_vk_PerformanceMarkerInfoINTEL(n_vk, "PerformanceMarkerInfoINTEL");
    py::class_<::vk::PerformanceOverrideInfoINTEL> s_vk_PerformanceOverrideInfoINTEL(n_vk, "PerformanceOverrideInfoINTEL");
    py::class_<::vk::PerformanceStreamMarkerInfoINTEL> s_vk_PerformanceStreamMarkerInfoINTEL(n_vk, "PerformanceStreamMarkerInfoINTEL");
    py::class_<::vk::PerformanceValueINTEL> s_vk_PerformanceValueINTEL(n_vk, "PerformanceValueINTEL");
    py::class_<::vk::QueryPoolPerformanceQueryCreateInfoINTEL> s_vk_QueryPoolPerformanceQueryCreateInfoINTEL(n_vk, "QueryPoolPerformanceQueryCreateInfoINTEL");
    py::class_<::vk::PhysicalDevicePCIBusInfoPropertiesEXT> s_vk_PhysicalDevicePCIBusInfoPropertiesEXT(n_vk, "PhysicalDevicePCIBusInfoPropertiesEXT");
    py::class_<::vk::DisplayNativeHdrSurfaceCapabilitiesAMD> s_vk_DisplayNativeHdrSurfaceCapabilitiesAMD(n_vk, "DisplayNativeHdrSurfaceCapabilitiesAMD");
    py::class_<::vk::SwapchainDisplayNativeHdrCreateInfoAMD> s_vk_SwapchainDisplayNativeHdrCreateInfoAMD(n_vk, "SwapchainDisplayNativeHdrCreateInfoAMD");
    py::class_<::vk::PhysicalDeviceFragmentDensityMapFeaturesEXT> s_vk_PhysicalDeviceFragmentDensityMapFeaturesEXT(n_vk, "PhysicalDeviceFragmentDensityMapFeaturesEXT");
    py::class_<::vk::PhysicalDeviceFragmentDensityMapPropertiesEXT> s_vk_PhysicalDeviceFragmentDensityMapPropertiesEXT(n_vk, "PhysicalDeviceFragmentDensityMapPropertiesEXT");
    py::class_<::vk::RenderPassFragmentDensityMapCreateInfoEXT> s_vk_RenderPassFragmentDensityMapCreateInfoEXT(n_vk, "RenderPassFragmentDensityMapCreateInfoEXT");
    py::class_<::vk::FragmentShadingRateAttachmentInfoKHR> s_vk_FragmentShadingRateAttachmentInfoKHR(n_vk, "FragmentShadingRateAttachmentInfoKHR");
    py::class_<::vk::PhysicalDeviceFragmentShadingRateFeaturesKHR> s_vk_PhysicalDeviceFragmentShadingRateFeaturesKHR(n_vk, "PhysicalDeviceFragmentShadingRateFeaturesKHR");
    py::class_<::vk::PhysicalDeviceFragmentShadingRateKHR> s_vk_PhysicalDeviceFragmentShadingRateKHR(n_vk, "PhysicalDeviceFragmentShadingRateKHR");
    py::class_<::vk::PhysicalDeviceFragmentShadingRatePropertiesKHR> s_vk_PhysicalDeviceFragmentShadingRatePropertiesKHR(n_vk, "PhysicalDeviceFragmentShadingRatePropertiesKHR");
    py::class_<::vk::PipelineFragmentShadingRateStateCreateInfoKHR> s_vk_PipelineFragmentShadingRateStateCreateInfoKHR(n_vk, "PipelineFragmentShadingRateStateCreateInfoKHR");
    py::class_<::vk::PhysicalDeviceShaderCoreProperties2AMD> s_vk_PhysicalDeviceShaderCoreProperties2AMD(n_vk, "PhysicalDeviceShaderCoreProperties2AMD");
    py::class_<::vk::PhysicalDeviceCoherentMemoryFeaturesAMD> s_vk_PhysicalDeviceCoherentMemoryFeaturesAMD(n_vk, "PhysicalDeviceCoherentMemoryFeaturesAMD");
    py::class_<::vk::PhysicalDeviceShaderImageAtomicInt64FeaturesEXT> s_vk_PhysicalDeviceShaderImageAtomicInt64FeaturesEXT(n_vk, "PhysicalDeviceShaderImageAtomicInt64FeaturesEXT");
    py::class_<::vk::PhysicalDeviceMemoryBudgetPropertiesEXT> s_vk_PhysicalDeviceMemoryBudgetPropertiesEXT(n_vk, "PhysicalDeviceMemoryBudgetPropertiesEXT");
    py::class_<::vk::MemoryPriorityAllocateInfoEXT> s_vk_MemoryPriorityAllocateInfoEXT(n_vk, "MemoryPriorityAllocateInfoEXT");
    py::class_<::vk::PhysicalDeviceMemoryPriorityFeaturesEXT> s_vk_PhysicalDeviceMemoryPriorityFeaturesEXT(n_vk, "PhysicalDeviceMemoryPriorityFeaturesEXT");
    py::class_<::vk::SurfaceProtectedCapabilitiesKHR> s_vk_SurfaceProtectedCapabilitiesKHR(n_vk, "SurfaceProtectedCapabilitiesKHR");
    py::class_<::vk::PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV> s_vk_PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(n_vk, "PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV");
    py::class_<::vk::BufferDeviceAddressCreateInfoEXT> s_vk_BufferDeviceAddressCreateInfoEXT(n_vk, "BufferDeviceAddressCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceBufferDeviceAddressFeaturesEXT> s_vk_PhysicalDeviceBufferDeviceAddressFeaturesEXT(n_vk, "PhysicalDeviceBufferDeviceAddressFeaturesEXT");
    py::class_<::vk::ValidationFeaturesEXT> s_vk_ValidationFeaturesEXT(n_vk, "ValidationFeaturesEXT");
    py::class_<::vk::PhysicalDevicePresentWaitFeaturesKHR> s_vk_PhysicalDevicePresentWaitFeaturesKHR(n_vk, "PhysicalDevicePresentWaitFeaturesKHR");
    py::class_<::vk::CooperativeMatrixPropertiesNV> s_vk_CooperativeMatrixPropertiesNV(n_vk, "CooperativeMatrixPropertiesNV");
    py::class_<::vk::PhysicalDeviceCooperativeMatrixFeaturesNV> s_vk_PhysicalDeviceCooperativeMatrixFeaturesNV(n_vk, "PhysicalDeviceCooperativeMatrixFeaturesNV");
    py::class_<::vk::PhysicalDeviceCooperativeMatrixPropertiesNV> s_vk_PhysicalDeviceCooperativeMatrixPropertiesNV(n_vk, "PhysicalDeviceCooperativeMatrixPropertiesNV");
    py::class_<::vk::FramebufferMixedSamplesCombinationNV> s_vk_FramebufferMixedSamplesCombinationNV(n_vk, "FramebufferMixedSamplesCombinationNV");
    py::class_<::vk::PhysicalDeviceCoverageReductionModeFeaturesNV> s_vk_PhysicalDeviceCoverageReductionModeFeaturesNV(n_vk, "PhysicalDeviceCoverageReductionModeFeaturesNV");
    py::class_<::vk::PipelineCoverageReductionStateCreateInfoNV> s_vk_PipelineCoverageReductionStateCreateInfoNV(n_vk, "PipelineCoverageReductionStateCreateInfoNV");
    py::class_<::vk::PhysicalDeviceFragmentShaderInterlockFeaturesEXT> s_vk_PhysicalDeviceFragmentShaderInterlockFeaturesEXT(n_vk, "PhysicalDeviceFragmentShaderInterlockFeaturesEXT");
    py::class_<::vk::PhysicalDeviceYcbcrImageArraysFeaturesEXT> s_vk_PhysicalDeviceYcbcrImageArraysFeaturesEXT(n_vk, "PhysicalDeviceYcbcrImageArraysFeaturesEXT");
    py::class_<::vk::PhysicalDeviceProvokingVertexFeaturesEXT> s_vk_PhysicalDeviceProvokingVertexFeaturesEXT(n_vk, "PhysicalDeviceProvokingVertexFeaturesEXT");
    py::class_<::vk::PhysicalDeviceProvokingVertexPropertiesEXT> s_vk_PhysicalDeviceProvokingVertexPropertiesEXT(n_vk, "PhysicalDeviceProvokingVertexPropertiesEXT");
    py::class_<::vk::PipelineRasterizationProvokingVertexStateCreateInfoEXT> s_vk_PipelineRasterizationProvokingVertexStateCreateInfoEXT(n_vk, "PipelineRasterizationProvokingVertexStateCreateInfoEXT");
    py::class_<::vk::HeadlessSurfaceCreateInfoEXT> s_vk_HeadlessSurfaceCreateInfoEXT(n_vk, "HeadlessSurfaceCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceLineRasterizationFeaturesEXT> s_vk_PhysicalDeviceLineRasterizationFeaturesEXT(n_vk, "PhysicalDeviceLineRasterizationFeaturesEXT");
    py::class_<::vk::PhysicalDeviceLineRasterizationPropertiesEXT> s_vk_PhysicalDeviceLineRasterizationPropertiesEXT(n_vk, "PhysicalDeviceLineRasterizationPropertiesEXT");
    py::class_<::vk::PipelineRasterizationLineStateCreateInfoEXT> s_vk_PipelineRasterizationLineStateCreateInfoEXT(n_vk, "PipelineRasterizationLineStateCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceShaderAtomicFloatFeaturesEXT> s_vk_PhysicalDeviceShaderAtomicFloatFeaturesEXT(n_vk, "PhysicalDeviceShaderAtomicFloatFeaturesEXT");
    py::class_<::vk::PhysicalDeviceIndexTypeUint8FeaturesEXT> s_vk_PhysicalDeviceIndexTypeUint8FeaturesEXT(n_vk, "PhysicalDeviceIndexTypeUint8FeaturesEXT");
    py::class_<::vk::PhysicalDeviceExtendedDynamicStateFeaturesEXT> s_vk_PhysicalDeviceExtendedDynamicStateFeaturesEXT(n_vk, "PhysicalDeviceExtendedDynamicStateFeaturesEXT");
    py::class_<::vk::PhysicalDevicePipelineExecutablePropertiesFeaturesKHR> s_vk_PhysicalDevicePipelineExecutablePropertiesFeaturesKHR(n_vk, "PhysicalDevicePipelineExecutablePropertiesFeaturesKHR");
    py::class_<::vk::PipelineExecutableInfoKHR> s_vk_PipelineExecutableInfoKHR(n_vk, "PipelineExecutableInfoKHR");
    py::class_<::vk::PipelineExecutableInternalRepresentationKHR> s_vk_PipelineExecutableInternalRepresentationKHR(n_vk, "PipelineExecutableInternalRepresentationKHR");
    py::class_<::vk::PipelineExecutablePropertiesKHR> s_vk_PipelineExecutablePropertiesKHR(n_vk, "PipelineExecutablePropertiesKHR");
    py::class_<::vk::PipelineExecutableStatisticKHR> s_vk_PipelineExecutableStatisticKHR(n_vk, "PipelineExecutableStatisticKHR");
    py::class_<::vk::PipelineInfoKHR> s_vk_PipelineInfoKHR(n_vk, "PipelineInfoKHR");
    py::class_<::vk::CopyImageToImageInfoEXT> s_vk_CopyImageToImageInfoEXT(n_vk, "CopyImageToImageInfoEXT");
    py::class_<::vk::CopyImageToMemoryInfoEXT> s_vk_CopyImageToMemoryInfoEXT(n_vk, "CopyImageToMemoryInfoEXT");
    py::class_<::vk::CopyMemoryToImageInfoEXT> s_vk_CopyMemoryToImageInfoEXT(n_vk, "CopyMemoryToImageInfoEXT");
    py::class_<::vk::HostImageCopyDevicePerformanceQueryEXT> s_vk_HostImageCopyDevicePerformanceQueryEXT(n_vk, "HostImageCopyDevicePerformanceQueryEXT");
    py::class_<::vk::HostImageLayoutTransitionInfoEXT> s_vk_HostImageLayoutTransitionInfoEXT(n_vk, "HostImageLayoutTransitionInfoEXT");
    py::class_<::vk::ImageToMemoryCopyEXT> s_vk_ImageToMemoryCopyEXT(n_vk, "ImageToMemoryCopyEXT");
    py::class_<::vk::MemoryToImageCopyEXT> s_vk_MemoryToImageCopyEXT(n_vk, "MemoryToImageCopyEXT");
    py::class_<::vk::PhysicalDeviceHostImageCopyFeaturesEXT> s_vk_PhysicalDeviceHostImageCopyFeaturesEXT(n_vk, "PhysicalDeviceHostImageCopyFeaturesEXT");
    py::class_<::vk::PhysicalDeviceHostImageCopyPropertiesEXT> s_vk_PhysicalDeviceHostImageCopyPropertiesEXT(n_vk, "PhysicalDeviceHostImageCopyPropertiesEXT");
    py::class_<::vk::SubresourceHostMemcpySizeEXT> s_vk_SubresourceHostMemcpySizeEXT(n_vk, "SubresourceHostMemcpySizeEXT");
    py::class_<::vk::MemoryMapInfoKHR> s_vk_MemoryMapInfoKHR(n_vk, "MemoryMapInfoKHR");
    py::class_<::vk::MemoryUnmapInfoKHR> s_vk_MemoryUnmapInfoKHR(n_vk, "MemoryUnmapInfoKHR");
    py::class_<::vk::PhysicalDeviceShaderAtomicFloat2FeaturesEXT> s_vk_PhysicalDeviceShaderAtomicFloat2FeaturesEXT(n_vk, "PhysicalDeviceShaderAtomicFloat2FeaturesEXT");
    py::class_<::vk::SurfacePresentModeCompatibilityEXT> s_vk_SurfacePresentModeCompatibilityEXT(n_vk, "SurfacePresentModeCompatibilityEXT");
    py::class_<::vk::SurfacePresentModeEXT> s_vk_SurfacePresentModeEXT(n_vk, "SurfacePresentModeEXT");
    py::class_<::vk::SurfacePresentScalingCapabilitiesEXT> s_vk_SurfacePresentScalingCapabilitiesEXT(n_vk, "SurfacePresentScalingCapabilitiesEXT");
    py::class_<::vk::PhysicalDeviceSwapchainMaintenance1FeaturesEXT> s_vk_PhysicalDeviceSwapchainMaintenance1FeaturesEXT(n_vk, "PhysicalDeviceSwapchainMaintenance1FeaturesEXT");
    py::class_<::vk::ReleaseSwapchainImagesInfoEXT> s_vk_ReleaseSwapchainImagesInfoEXT(n_vk, "ReleaseSwapchainImagesInfoEXT");
    py::class_<::vk::SwapchainPresentFenceInfoEXT> s_vk_SwapchainPresentFenceInfoEXT(n_vk, "SwapchainPresentFenceInfoEXT");
    py::class_<::vk::SwapchainPresentModeInfoEXT> s_vk_SwapchainPresentModeInfoEXT(n_vk, "SwapchainPresentModeInfoEXT");
    py::class_<::vk::SwapchainPresentModesCreateInfoEXT> s_vk_SwapchainPresentModesCreateInfoEXT(n_vk, "SwapchainPresentModesCreateInfoEXT");
    py::class_<::vk::SwapchainPresentScalingCreateInfoEXT> s_vk_SwapchainPresentScalingCreateInfoEXT(n_vk, "SwapchainPresentScalingCreateInfoEXT");
    py::class_<::vk::BindIndexBufferIndirectCommandNV> s_vk_BindIndexBufferIndirectCommandNV(n_vk, "BindIndexBufferIndirectCommandNV");
    py::class_<::vk::BindShaderGroupIndirectCommandNV> s_vk_BindShaderGroupIndirectCommandNV(n_vk, "BindShaderGroupIndirectCommandNV");
    py::class_<::vk::BindVertexBufferIndirectCommandNV> s_vk_BindVertexBufferIndirectCommandNV(n_vk, "BindVertexBufferIndirectCommandNV");
    py::class_<::vk::GeneratedCommandsInfoNV> s_vk_GeneratedCommandsInfoNV(n_vk, "GeneratedCommandsInfoNV");
    py::class_<::vk::GeneratedCommandsMemoryRequirementsInfoNV> s_vk_GeneratedCommandsMemoryRequirementsInfoNV(n_vk, "GeneratedCommandsMemoryRequirementsInfoNV");
    py::class_<::vk::GraphicsPipelineShaderGroupsCreateInfoNV> s_vk_GraphicsPipelineShaderGroupsCreateInfoNV(n_vk, "GraphicsPipelineShaderGroupsCreateInfoNV");
    py::class_<::vk::GraphicsShaderGroupCreateInfoNV> s_vk_GraphicsShaderGroupCreateInfoNV(n_vk, "GraphicsShaderGroupCreateInfoNV");
    py::class_<::vk::IndirectCommandsLayoutCreateInfoNV> s_vk_IndirectCommandsLayoutCreateInfoNV(n_vk, "IndirectCommandsLayoutCreateInfoNV");
    py::class_<::vk::IndirectCommandsLayoutTokenNV> s_vk_IndirectCommandsLayoutTokenNV(n_vk, "IndirectCommandsLayoutTokenNV");
    py::class_<::vk::IndirectCommandsStreamNV> s_vk_IndirectCommandsStreamNV(n_vk, "IndirectCommandsStreamNV");
    py::class_<::vk::PhysicalDeviceDeviceGeneratedCommandsFeaturesNV> s_vk_PhysicalDeviceDeviceGeneratedCommandsFeaturesNV(n_vk, "PhysicalDeviceDeviceGeneratedCommandsFeaturesNV");
    py::class_<::vk::PhysicalDeviceDeviceGeneratedCommandsPropertiesNV> s_vk_PhysicalDeviceDeviceGeneratedCommandsPropertiesNV(n_vk, "PhysicalDeviceDeviceGeneratedCommandsPropertiesNV");
    py::class_<::vk::SetStateFlagsIndirectCommandNV> s_vk_SetStateFlagsIndirectCommandNV(n_vk, "SetStateFlagsIndirectCommandNV");
    py::class_<::vk::CommandBufferInheritanceViewportScissorInfoNV> s_vk_CommandBufferInheritanceViewportScissorInfoNV(n_vk, "CommandBufferInheritanceViewportScissorInfoNV");
    py::class_<::vk::PhysicalDeviceInheritedViewportScissorFeaturesNV> s_vk_PhysicalDeviceInheritedViewportScissorFeaturesNV(n_vk, "PhysicalDeviceInheritedViewportScissorFeaturesNV");
    py::class_<::vk::PhysicalDeviceTexelBufferAlignmentFeaturesEXT> s_vk_PhysicalDeviceTexelBufferAlignmentFeaturesEXT(n_vk, "PhysicalDeviceTexelBufferAlignmentFeaturesEXT");
    py::class_<::vk::CommandBufferInheritanceRenderPassTransformInfoQCOM> s_vk_CommandBufferInheritanceRenderPassTransformInfoQCOM(n_vk, "CommandBufferInheritanceRenderPassTransformInfoQCOM");
    py::class_<::vk::RenderPassTransformBeginInfoQCOM> s_vk_RenderPassTransformBeginInfoQCOM(n_vk, "RenderPassTransformBeginInfoQCOM");
    py::class_<::vk::DepthBiasInfoEXT> s_vk_DepthBiasInfoEXT(n_vk, "DepthBiasInfoEXT");
    py::class_<::vk::DepthBiasRepresentationInfoEXT> s_vk_DepthBiasRepresentationInfoEXT(n_vk, "DepthBiasRepresentationInfoEXT");
    py::class_<::vk::PhysicalDeviceDepthBiasControlFeaturesEXT> s_vk_PhysicalDeviceDepthBiasControlFeaturesEXT(n_vk, "PhysicalDeviceDepthBiasControlFeaturesEXT");
    py::class_<::vk::DeviceDeviceMemoryReportCreateInfoEXT> s_vk_DeviceDeviceMemoryReportCreateInfoEXT(n_vk, "DeviceDeviceMemoryReportCreateInfoEXT");
    py::class_<::vk::DeviceMemoryReportCallbackDataEXT> s_vk_DeviceMemoryReportCallbackDataEXT(n_vk, "DeviceMemoryReportCallbackDataEXT");
    py::class_<::vk::PhysicalDeviceDeviceMemoryReportFeaturesEXT> s_vk_PhysicalDeviceDeviceMemoryReportFeaturesEXT(n_vk, "PhysicalDeviceDeviceMemoryReportFeaturesEXT");
    py::class_<::vk::PhysicalDeviceRobustness2FeaturesEXT> s_vk_PhysicalDeviceRobustness2FeaturesEXT(n_vk, "PhysicalDeviceRobustness2FeaturesEXT");
    py::class_<::vk::PhysicalDeviceRobustness2PropertiesEXT> s_vk_PhysicalDeviceRobustness2PropertiesEXT(n_vk, "PhysicalDeviceRobustness2PropertiesEXT");
    py::class_<::vk::PhysicalDeviceCustomBorderColorFeaturesEXT> s_vk_PhysicalDeviceCustomBorderColorFeaturesEXT(n_vk, "PhysicalDeviceCustomBorderColorFeaturesEXT");
    py::class_<::vk::PhysicalDeviceCustomBorderColorPropertiesEXT> s_vk_PhysicalDeviceCustomBorderColorPropertiesEXT(n_vk, "PhysicalDeviceCustomBorderColorPropertiesEXT");
    py::class_<::vk::SamplerCustomBorderColorCreateInfoEXT> s_vk_SamplerCustomBorderColorCreateInfoEXT(n_vk, "SamplerCustomBorderColorCreateInfoEXT");
    py::class_<::vk::PipelineLibraryCreateInfoKHR> s_vk_PipelineLibraryCreateInfoKHR(n_vk, "PipelineLibraryCreateInfoKHR");
    py::class_<::vk::PhysicalDevicePresentBarrierFeaturesNV> s_vk_PhysicalDevicePresentBarrierFeaturesNV(n_vk, "PhysicalDevicePresentBarrierFeaturesNV");
    py::class_<::vk::SurfaceCapabilitiesPresentBarrierNV> s_vk_SurfaceCapabilitiesPresentBarrierNV(n_vk, "SurfaceCapabilitiesPresentBarrierNV");
    py::class_<::vk::SwapchainPresentBarrierCreateInfoNV> s_vk_SwapchainPresentBarrierCreateInfoNV(n_vk, "SwapchainPresentBarrierCreateInfoNV");
    py::class_<::vk::PhysicalDevicePresentIdFeaturesKHR> s_vk_PhysicalDevicePresentIdFeaturesKHR(n_vk, "PhysicalDevicePresentIdFeaturesKHR");
    py::class_<::vk::PresentIdKHR> s_vk_PresentIdKHR(n_vk, "PresentIdKHR");
    py::class_<::vk::PhysicalDeviceVideoEncodeQualityLevelInfoKHR> s_vk_PhysicalDeviceVideoEncodeQualityLevelInfoKHR(n_vk, "PhysicalDeviceVideoEncodeQualityLevelInfoKHR");
    py::class_<::vk::QueryPoolVideoEncodeFeedbackCreateInfoKHR> s_vk_QueryPoolVideoEncodeFeedbackCreateInfoKHR(n_vk, "QueryPoolVideoEncodeFeedbackCreateInfoKHR");
    py::class_<::vk::VideoEncodeCapabilitiesKHR> s_vk_VideoEncodeCapabilitiesKHR(n_vk, "VideoEncodeCapabilitiesKHR");
    py::class_<::vk::VideoEncodeInfoKHR> s_vk_VideoEncodeInfoKHR(n_vk, "VideoEncodeInfoKHR");
    py::class_<::vk::VideoEncodeQualityLevelInfoKHR> s_vk_VideoEncodeQualityLevelInfoKHR(n_vk, "VideoEncodeQualityLevelInfoKHR");
    py::class_<::vk::VideoEncodeQualityLevelPropertiesKHR> s_vk_VideoEncodeQualityLevelPropertiesKHR(n_vk, "VideoEncodeQualityLevelPropertiesKHR");
    py::class_<::vk::VideoEncodeRateControlInfoKHR> s_vk_VideoEncodeRateControlInfoKHR(n_vk, "VideoEncodeRateControlInfoKHR");
    py::class_<::vk::VideoEncodeRateControlLayerInfoKHR> s_vk_VideoEncodeRateControlLayerInfoKHR(n_vk, "VideoEncodeRateControlLayerInfoKHR");
    py::class_<::vk::VideoEncodeSessionParametersFeedbackInfoKHR> s_vk_VideoEncodeSessionParametersFeedbackInfoKHR(n_vk, "VideoEncodeSessionParametersFeedbackInfoKHR");
    py::class_<::vk::VideoEncodeSessionParametersGetInfoKHR> s_vk_VideoEncodeSessionParametersGetInfoKHR(n_vk, "VideoEncodeSessionParametersGetInfoKHR");
    py::class_<::vk::VideoEncodeUsageInfoKHR> s_vk_VideoEncodeUsageInfoKHR(n_vk, "VideoEncodeUsageInfoKHR");
    py::class_<::vk::DeviceDiagnosticsConfigCreateInfoNV> s_vk_DeviceDiagnosticsConfigCreateInfoNV(n_vk, "DeviceDiagnosticsConfigCreateInfoNV");
    py::class_<::vk::PhysicalDeviceDiagnosticsConfigFeaturesNV> s_vk_PhysicalDeviceDiagnosticsConfigFeaturesNV(n_vk, "PhysicalDeviceDiagnosticsConfigFeaturesNV");
    py::class_<::vk::QueryLowLatencySupportNV> s_vk_QueryLowLatencySupportNV(n_vk, "QueryLowLatencySupportNV");
    py::class_<::vk::CheckpointData2NV> s_vk_CheckpointData2NV(n_vk, "CheckpointData2NV");
    py::class_<::vk::QueueFamilyCheckpointProperties2NV> s_vk_QueueFamilyCheckpointProperties2NV(n_vk, "QueueFamilyCheckpointProperties2NV");
    py::class_<::vk::AccelerationStructureCaptureDescriptorDataInfoEXT> s_vk_AccelerationStructureCaptureDescriptorDataInfoEXT(n_vk, "AccelerationStructureCaptureDescriptorDataInfoEXT");
    py::class_<::vk::BufferCaptureDescriptorDataInfoEXT> s_vk_BufferCaptureDescriptorDataInfoEXT(n_vk, "BufferCaptureDescriptorDataInfoEXT");
    py::class_<::vk::DescriptorAddressInfoEXT> s_vk_DescriptorAddressInfoEXT(n_vk, "DescriptorAddressInfoEXT");
    py::class_<::vk::DescriptorBufferBindingInfoEXT> s_vk_DescriptorBufferBindingInfoEXT(n_vk, "DescriptorBufferBindingInfoEXT");
    py::class_<::vk::DescriptorBufferBindingPushDescriptorBufferHandleEXT> s_vk_DescriptorBufferBindingPushDescriptorBufferHandleEXT(n_vk, "DescriptorBufferBindingPushDescriptorBufferHandleEXT");
    py::class_<::vk::DescriptorGetInfoEXT> s_vk_DescriptorGetInfoEXT(n_vk, "DescriptorGetInfoEXT");
    py::class_<::vk::ImageCaptureDescriptorDataInfoEXT> s_vk_ImageCaptureDescriptorDataInfoEXT(n_vk, "ImageCaptureDescriptorDataInfoEXT");
    py::class_<::vk::ImageViewCaptureDescriptorDataInfoEXT> s_vk_ImageViewCaptureDescriptorDataInfoEXT(n_vk, "ImageViewCaptureDescriptorDataInfoEXT");
    py::class_<::vk::OpaqueCaptureDescriptorDataCreateInfoEXT> s_vk_OpaqueCaptureDescriptorDataCreateInfoEXT(n_vk, "OpaqueCaptureDescriptorDataCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT> s_vk_PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT(n_vk, "PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT");
    py::class_<::vk::PhysicalDeviceDescriptorBufferFeaturesEXT> s_vk_PhysicalDeviceDescriptorBufferFeaturesEXT(n_vk, "PhysicalDeviceDescriptorBufferFeaturesEXT");
    py::class_<::vk::PhysicalDeviceDescriptorBufferPropertiesEXT> s_vk_PhysicalDeviceDescriptorBufferPropertiesEXT(n_vk, "PhysicalDeviceDescriptorBufferPropertiesEXT");
    py::class_<::vk::SamplerCaptureDescriptorDataInfoEXT> s_vk_SamplerCaptureDescriptorDataInfoEXT(n_vk, "SamplerCaptureDescriptorDataInfoEXT");
    py::class_<::vk::GraphicsPipelineLibraryCreateInfoEXT> s_vk_GraphicsPipelineLibraryCreateInfoEXT(n_vk, "GraphicsPipelineLibraryCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT> s_vk_PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT(n_vk, "PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT");
    py::class_<::vk::PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT> s_vk_PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT(n_vk, "PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT");
    py::class_<::vk::PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD> s_vk_PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD(n_vk, "PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD");
    py::class_<::vk::PhysicalDeviceFragmentShaderBarycentricFeaturesKHR> s_vk_PhysicalDeviceFragmentShaderBarycentricFeaturesKHR(n_vk, "PhysicalDeviceFragmentShaderBarycentricFeaturesKHR");
    py::class_<::vk::PhysicalDeviceFragmentShaderBarycentricPropertiesKHR> s_vk_PhysicalDeviceFragmentShaderBarycentricPropertiesKHR(n_vk, "PhysicalDeviceFragmentShaderBarycentricPropertiesKHR");
    py::class_<::vk::PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR> s_vk_PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR(n_vk, "PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR");
    py::class_<::vk::PhysicalDeviceFragmentShadingRateEnumsFeaturesNV> s_vk_PhysicalDeviceFragmentShadingRateEnumsFeaturesNV(n_vk, "PhysicalDeviceFragmentShadingRateEnumsFeaturesNV");
    py::class_<::vk::PhysicalDeviceFragmentShadingRateEnumsPropertiesNV> s_vk_PhysicalDeviceFragmentShadingRateEnumsPropertiesNV(n_vk, "PhysicalDeviceFragmentShadingRateEnumsPropertiesNV");
    py::class_<::vk::PipelineFragmentShadingRateEnumStateCreateInfoNV> s_vk_PipelineFragmentShadingRateEnumStateCreateInfoNV(n_vk, "PipelineFragmentShadingRateEnumStateCreateInfoNV");
    py::class_<::vk::AccelerationStructureGeometryMotionTrianglesDataNV> s_vk_AccelerationStructureGeometryMotionTrianglesDataNV(n_vk, "AccelerationStructureGeometryMotionTrianglesDataNV");
    py::class_<::vk::AccelerationStructureMatrixMotionInstanceNV> s_vk_AccelerationStructureMatrixMotionInstanceNV(n_vk, "AccelerationStructureMatrixMotionInstanceNV");
    py::class_<::vk::AccelerationStructureMotionInfoNV> s_vk_AccelerationStructureMotionInfoNV(n_vk, "AccelerationStructureMotionInfoNV");
    py::class_<::vk::AccelerationStructureMotionInstanceNV> s_vk_AccelerationStructureMotionInstanceNV(n_vk, "AccelerationStructureMotionInstanceNV");
    py::class_<::vk::AccelerationStructureSRTMotionInstanceNV> s_vk_AccelerationStructureSRTMotionInstanceNV(n_vk, "AccelerationStructureSRTMotionInstanceNV");
    py::class_<::vk::PhysicalDeviceRayTracingMotionBlurFeaturesNV> s_vk_PhysicalDeviceRayTracingMotionBlurFeaturesNV(n_vk, "PhysicalDeviceRayTracingMotionBlurFeaturesNV");
    py::class_<::vk::SRTDataNV> s_vk_SRTDataNV(n_vk, "SRTDataNV");
    py::class_<::vk::DrawMeshTasksIndirectCommandEXT> s_vk_DrawMeshTasksIndirectCommandEXT(n_vk, "DrawMeshTasksIndirectCommandEXT");
    py::class_<::vk::PhysicalDeviceMeshShaderFeaturesEXT> s_vk_PhysicalDeviceMeshShaderFeaturesEXT(n_vk, "PhysicalDeviceMeshShaderFeaturesEXT");
    py::class_<::vk::PhysicalDeviceMeshShaderPropertiesEXT> s_vk_PhysicalDeviceMeshShaderPropertiesEXT(n_vk, "PhysicalDeviceMeshShaderPropertiesEXT");
    py::class_<::vk::PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT> s_vk_PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT(n_vk, "PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT");
    py::class_<::vk::PhysicalDeviceFragmentDensityMap2FeaturesEXT> s_vk_PhysicalDeviceFragmentDensityMap2FeaturesEXT(n_vk, "PhysicalDeviceFragmentDensityMap2FeaturesEXT");
    py::class_<::vk::PhysicalDeviceFragmentDensityMap2PropertiesEXT> s_vk_PhysicalDeviceFragmentDensityMap2PropertiesEXT(n_vk, "PhysicalDeviceFragmentDensityMap2PropertiesEXT");
    py::class_<::vk::CopyCommandTransformInfoQCOM> s_vk_CopyCommandTransformInfoQCOM(n_vk, "CopyCommandTransformInfoQCOM");
    py::class_<::vk::PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR> s_vk_PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR(n_vk, "PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR");
    py::class_<::vk::ImageCompressionControlEXT> s_vk_ImageCompressionControlEXT(n_vk, "ImageCompressionControlEXT");
    py::class_<::vk::ImageCompressionPropertiesEXT> s_vk_ImageCompressionPropertiesEXT(n_vk, "ImageCompressionPropertiesEXT");
    py::class_<::vk::PhysicalDeviceImageCompressionControlFeaturesEXT> s_vk_PhysicalDeviceImageCompressionControlFeaturesEXT(n_vk, "PhysicalDeviceImageCompressionControlFeaturesEXT");
    py::class_<::vk::PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT> s_vk_PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT(n_vk, "PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT");
    py::class_<::vk::PhysicalDevice4444FormatsFeaturesEXT> s_vk_PhysicalDevice4444FormatsFeaturesEXT(n_vk, "PhysicalDevice4444FormatsFeaturesEXT");
    py::class_<::vk::DeviceFaultAddressInfoEXT> s_vk_DeviceFaultAddressInfoEXT(n_vk, "DeviceFaultAddressInfoEXT");
    py::class_<::vk::DeviceFaultCountsEXT> s_vk_DeviceFaultCountsEXT(n_vk, "DeviceFaultCountsEXT");
    py::class_<::vk::DeviceFaultInfoEXT> s_vk_DeviceFaultInfoEXT(n_vk, "DeviceFaultInfoEXT");
    py::class_<::vk::DeviceFaultVendorBinaryHeaderVersionOneEXT> s_vk_DeviceFaultVendorBinaryHeaderVersionOneEXT(n_vk, "DeviceFaultVendorBinaryHeaderVersionOneEXT");
    py::class_<::vk::DeviceFaultVendorInfoEXT> s_vk_DeviceFaultVendorInfoEXT(n_vk, "DeviceFaultVendorInfoEXT");
    py::class_<::vk::PhysicalDeviceFaultFeaturesEXT> s_vk_PhysicalDeviceFaultFeaturesEXT(n_vk, "PhysicalDeviceFaultFeaturesEXT");
    py::class_<::vk::PhysicalDeviceRGBA10X6FormatsFeaturesEXT> s_vk_PhysicalDeviceRGBA10X6FormatsFeaturesEXT(n_vk, "PhysicalDeviceRGBA10X6FormatsFeaturesEXT");
    py::class_<::vk::PhysicalDeviceVertexInputDynamicStateFeaturesEXT> s_vk_PhysicalDeviceVertexInputDynamicStateFeaturesEXT(n_vk, "PhysicalDeviceVertexInputDynamicStateFeaturesEXT");
    py::class_<::vk::VertexInputAttributeDescription2EXT> s_vk_VertexInputAttributeDescription2EXT(n_vk, "VertexInputAttributeDescription2EXT");
    py::class_<::vk::VertexInputBindingDescription2EXT> s_vk_VertexInputBindingDescription2EXT(n_vk, "VertexInputBindingDescription2EXT");
    py::class_<::vk::PhysicalDeviceDrmPropertiesEXT> s_vk_PhysicalDeviceDrmPropertiesEXT(n_vk, "PhysicalDeviceDrmPropertiesEXT");
    py::class_<::vk::DeviceAddressBindingCallbackDataEXT> s_vk_DeviceAddressBindingCallbackDataEXT(n_vk, "DeviceAddressBindingCallbackDataEXT");
    py::class_<::vk::PhysicalDeviceAddressBindingReportFeaturesEXT> s_vk_PhysicalDeviceAddressBindingReportFeaturesEXT(n_vk, "PhysicalDeviceAddressBindingReportFeaturesEXT");
    py::class_<::vk::PhysicalDeviceDepthClipControlFeaturesEXT> s_vk_PhysicalDeviceDepthClipControlFeaturesEXT(n_vk, "PhysicalDeviceDepthClipControlFeaturesEXT");
    py::class_<::vk::PipelineViewportDepthClipControlCreateInfoEXT> s_vk_PipelineViewportDepthClipControlCreateInfoEXT(n_vk, "PipelineViewportDepthClipControlCreateInfoEXT");
    py::class_<::vk::PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT> s_vk_PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT(n_vk, "PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT");
    py::class_<::vk::PhysicalDeviceSubpassShadingFeaturesHUAWEI> s_vk_PhysicalDeviceSubpassShadingFeaturesHUAWEI(n_vk, "PhysicalDeviceSubpassShadingFeaturesHUAWEI");
    py::class_<::vk::PhysicalDeviceSubpassShadingPropertiesHUAWEI> s_vk_PhysicalDeviceSubpassShadingPropertiesHUAWEI(n_vk, "PhysicalDeviceSubpassShadingPropertiesHUAWEI");
    py::class_<::vk::SubpassShadingPipelineCreateInfoHUAWEI> s_vk_SubpassShadingPipelineCreateInfoHUAWEI(n_vk, "SubpassShadingPipelineCreateInfoHUAWEI");
    py::class_<::vk::PhysicalDeviceInvocationMaskFeaturesHUAWEI> s_vk_PhysicalDeviceInvocationMaskFeaturesHUAWEI(n_vk, "PhysicalDeviceInvocationMaskFeaturesHUAWEI");
    py::class_<::vk::MemoryGetRemoteAddressInfoNV> s_vk_MemoryGetRemoteAddressInfoNV(n_vk, "MemoryGetRemoteAddressInfoNV");
    py::class_<::vk::PhysicalDeviceExternalMemoryRDMAFeaturesNV> s_vk_PhysicalDeviceExternalMemoryRDMAFeaturesNV(n_vk, "PhysicalDeviceExternalMemoryRDMAFeaturesNV");
    py::class_<::vk::PhysicalDevicePipelinePropertiesFeaturesEXT> s_vk_PhysicalDevicePipelinePropertiesFeaturesEXT(n_vk, "PhysicalDevicePipelinePropertiesFeaturesEXT");
    py::class_<::vk::PipelinePropertiesIdentifierEXT> s_vk_PipelinePropertiesIdentifierEXT(n_vk, "PipelinePropertiesIdentifierEXT");
    py::class_<::vk::FrameBoundaryEXT> s_vk_FrameBoundaryEXT(n_vk, "FrameBoundaryEXT");
    py::class_<::vk::PhysicalDeviceFrameBoundaryFeaturesEXT> s_vk_PhysicalDeviceFrameBoundaryFeaturesEXT(n_vk, "PhysicalDeviceFrameBoundaryFeaturesEXT");
    py::class_<::vk::MultisampledRenderToSingleSampledInfoEXT> s_vk_MultisampledRenderToSingleSampledInfoEXT(n_vk, "MultisampledRenderToSingleSampledInfoEXT");
    py::class_<::vk::PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT> s_vk_PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT(n_vk, "PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT");
    py::class_<::vk::SubpassResolvePerformanceQueryEXT> s_vk_SubpassResolvePerformanceQueryEXT(n_vk, "SubpassResolvePerformanceQueryEXT");
    py::class_<::vk::PhysicalDeviceExtendedDynamicState2FeaturesEXT> s_vk_PhysicalDeviceExtendedDynamicState2FeaturesEXT(n_vk, "PhysicalDeviceExtendedDynamicState2FeaturesEXT");
    py::class_<::vk::PhysicalDeviceColorWriteEnableFeaturesEXT> s_vk_PhysicalDeviceColorWriteEnableFeaturesEXT(n_vk, "PhysicalDeviceColorWriteEnableFeaturesEXT");
    py::class_<::vk::PipelineColorWriteCreateInfoEXT> s_vk_PipelineColorWriteCreateInfoEXT(n_vk, "PipelineColorWriteCreateInfoEXT");
    py::class_<::vk::PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT> s_vk_PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT(n_vk, "PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT");
    py::class_<::vk::PhysicalDeviceRayTracingMaintenance1FeaturesKHR> s_vk_PhysicalDeviceRayTracingMaintenance1FeaturesKHR(n_vk, "PhysicalDeviceRayTracingMaintenance1FeaturesKHR");
    py::class_<::vk::TraceRaysIndirectCommand2KHR> s_vk_TraceRaysIndirectCommand2KHR(n_vk, "TraceRaysIndirectCommand2KHR");
    py::class_<::vk::ImageViewMinLodCreateInfoEXT> s_vk_ImageViewMinLodCreateInfoEXT(n_vk, "ImageViewMinLodCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceImageViewMinLodFeaturesEXT> s_vk_PhysicalDeviceImageViewMinLodFeaturesEXT(n_vk, "PhysicalDeviceImageViewMinLodFeaturesEXT");
    py::class_<::vk::MultiDrawIndexedInfoEXT> s_vk_MultiDrawIndexedInfoEXT(n_vk, "MultiDrawIndexedInfoEXT");
    py::class_<::vk::MultiDrawInfoEXT> s_vk_MultiDrawInfoEXT(n_vk, "MultiDrawInfoEXT");
    py::class_<::vk::PhysicalDeviceMultiDrawFeaturesEXT> s_vk_PhysicalDeviceMultiDrawFeaturesEXT(n_vk, "PhysicalDeviceMultiDrawFeaturesEXT");
    py::class_<::vk::PhysicalDeviceMultiDrawPropertiesEXT> s_vk_PhysicalDeviceMultiDrawPropertiesEXT(n_vk, "PhysicalDeviceMultiDrawPropertiesEXT");
    py::class_<::vk::PhysicalDeviceImage2DViewOf3DFeaturesEXT> s_vk_PhysicalDeviceImage2DViewOf3DFeaturesEXT(n_vk, "PhysicalDeviceImage2DViewOf3DFeaturesEXT");
    py::class_<::vk::PhysicalDeviceShaderTileImageFeaturesEXT> s_vk_PhysicalDeviceShaderTileImageFeaturesEXT(n_vk, "PhysicalDeviceShaderTileImageFeaturesEXT");
    py::class_<::vk::PhysicalDeviceShaderTileImagePropertiesEXT> s_vk_PhysicalDeviceShaderTileImagePropertiesEXT(n_vk, "PhysicalDeviceShaderTileImagePropertiesEXT");
    py::class_<::vk::AccelerationStructureTrianglesOpacityMicromapEXT> s_vk_AccelerationStructureTrianglesOpacityMicromapEXT(n_vk, "AccelerationStructureTrianglesOpacityMicromapEXT");
    py::class_<::vk::CopyMemoryToMicromapInfoEXT> s_vk_CopyMemoryToMicromapInfoEXT(n_vk, "CopyMemoryToMicromapInfoEXT");
    py::class_<::vk::CopyMicromapInfoEXT> s_vk_CopyMicromapInfoEXT(n_vk, "CopyMicromapInfoEXT");
    py::class_<::vk::CopyMicromapToMemoryInfoEXT> s_vk_CopyMicromapToMemoryInfoEXT(n_vk, "CopyMicromapToMemoryInfoEXT");
    py::class_<::vk::MicromapBuildInfoEXT> s_vk_MicromapBuildInfoEXT(n_vk, "MicromapBuildInfoEXT");
    py::class_<::vk::MicromapBuildSizesInfoEXT> s_vk_MicromapBuildSizesInfoEXT(n_vk, "MicromapBuildSizesInfoEXT");
    py::class_<::vk::MicromapCreateInfoEXT> s_vk_MicromapCreateInfoEXT(n_vk, "MicromapCreateInfoEXT");
    py::class_<::vk::MicromapTriangleEXT> s_vk_MicromapTriangleEXT(n_vk, "MicromapTriangleEXT");
    py::class_<::vk::MicromapUsageEXT> s_vk_MicromapUsageEXT(n_vk, "MicromapUsageEXT");
    py::class_<::vk::MicromapVersionInfoEXT> s_vk_MicromapVersionInfoEXT(n_vk, "MicromapVersionInfoEXT");
    py::class_<::vk::PhysicalDeviceOpacityMicromapFeaturesEXT> s_vk_PhysicalDeviceOpacityMicromapFeaturesEXT(n_vk, "PhysicalDeviceOpacityMicromapFeaturesEXT");
    py::class_<::vk::PhysicalDeviceOpacityMicromapPropertiesEXT> s_vk_PhysicalDeviceOpacityMicromapPropertiesEXT(n_vk, "PhysicalDeviceOpacityMicromapPropertiesEXT");
    py::class_<::vk::PhysicalDeviceClusterCullingShaderFeaturesHUAWEI> s_vk_PhysicalDeviceClusterCullingShaderFeaturesHUAWEI(n_vk, "PhysicalDeviceClusterCullingShaderFeaturesHUAWEI");
    py::class_<::vk::PhysicalDeviceClusterCullingShaderPropertiesHUAWEI> s_vk_PhysicalDeviceClusterCullingShaderPropertiesHUAWEI(n_vk, "PhysicalDeviceClusterCullingShaderPropertiesHUAWEI");
    py::class_<::vk::PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI> s_vk_PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI(n_vk, "PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI");
    py::class_<::vk::PhysicalDeviceBorderColorSwizzleFeaturesEXT> s_vk_PhysicalDeviceBorderColorSwizzleFeaturesEXT(n_vk, "PhysicalDeviceBorderColorSwizzleFeaturesEXT");
    py::class_<::vk::SamplerBorderColorComponentMappingCreateInfoEXT> s_vk_SamplerBorderColorComponentMappingCreateInfoEXT(n_vk, "SamplerBorderColorComponentMappingCreateInfoEXT");
    py::class_<::vk::PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT> s_vk_PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT(n_vk, "PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT");
    py::class_<::vk::PhysicalDeviceShaderCorePropertiesARM> s_vk_PhysicalDeviceShaderCorePropertiesARM(n_vk, "PhysicalDeviceShaderCorePropertiesARM");
    py::class_<::vk::DeviceQueueShaderCoreControlCreateInfoARM> s_vk_DeviceQueueShaderCoreControlCreateInfoARM(n_vk, "DeviceQueueShaderCoreControlCreateInfoARM");
    py::class_<::vk::PhysicalDeviceSchedulingControlsFeaturesARM> s_vk_PhysicalDeviceSchedulingControlsFeaturesARM(n_vk, "PhysicalDeviceSchedulingControlsFeaturesARM");
    py::class_<::vk::PhysicalDeviceSchedulingControlsPropertiesARM> s_vk_PhysicalDeviceSchedulingControlsPropertiesARM(n_vk, "PhysicalDeviceSchedulingControlsPropertiesARM");
    py::class_<::vk::ImageViewSlicedCreateInfoEXT> s_vk_ImageViewSlicedCreateInfoEXT(n_vk, "ImageViewSlicedCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceImageSlicedViewOf3DFeaturesEXT> s_vk_PhysicalDeviceImageSlicedViewOf3DFeaturesEXT(n_vk, "PhysicalDeviceImageSlicedViewOf3DFeaturesEXT");
    py::class_<::vk::DescriptorSetBindingReferenceVALVE> s_vk_DescriptorSetBindingReferenceVALVE(n_vk, "DescriptorSetBindingReferenceVALVE");
    py::class_<::vk::DescriptorSetLayoutHostMappingInfoVALVE> s_vk_DescriptorSetLayoutHostMappingInfoVALVE(n_vk, "DescriptorSetLayoutHostMappingInfoVALVE");
    py::class_<::vk::PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE> s_vk_PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE(n_vk, "PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE");
    py::class_<::vk::PhysicalDeviceDepthClampZeroOneFeaturesEXT> s_vk_PhysicalDeviceDepthClampZeroOneFeaturesEXT(n_vk, "PhysicalDeviceDepthClampZeroOneFeaturesEXT");
    py::class_<::vk::PhysicalDeviceNonSeamlessCubeMapFeaturesEXT> s_vk_PhysicalDeviceNonSeamlessCubeMapFeaturesEXT(n_vk, "PhysicalDeviceNonSeamlessCubeMapFeaturesEXT");
    py::class_<::vk::PhysicalDeviceRenderPassStripedFeaturesARM> s_vk_PhysicalDeviceRenderPassStripedFeaturesARM(n_vk, "PhysicalDeviceRenderPassStripedFeaturesARM");
    py::class_<::vk::PhysicalDeviceRenderPassStripedPropertiesARM> s_vk_PhysicalDeviceRenderPassStripedPropertiesARM(n_vk, "PhysicalDeviceRenderPassStripedPropertiesARM");
    py::class_<::vk::RenderPassStripeBeginInfoARM> s_vk_RenderPassStripeBeginInfoARM(n_vk, "RenderPassStripeBeginInfoARM");
    py::class_<::vk::RenderPassStripeInfoARM> s_vk_RenderPassStripeInfoARM(n_vk, "RenderPassStripeInfoARM");
    py::class_<::vk::RenderPassStripeSubmitInfoARM> s_vk_RenderPassStripeSubmitInfoARM(n_vk, "RenderPassStripeSubmitInfoARM");
    py::class_<::vk::PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM> s_vk_PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM(n_vk, "PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM");
    py::class_<::vk::PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM> s_vk_PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM(n_vk, "PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM");
    py::class_<::vk::SubpassFragmentDensityMapOffsetEndInfoQCOM> s_vk_SubpassFragmentDensityMapOffsetEndInfoQCOM(n_vk, "SubpassFragmentDensityMapOffsetEndInfoQCOM");
    py::class_<::vk::CopyMemoryIndirectCommandNV> s_vk_CopyMemoryIndirectCommandNV(n_vk, "CopyMemoryIndirectCommandNV");
    py::class_<::vk::CopyMemoryToImageIndirectCommandNV> s_vk_CopyMemoryToImageIndirectCommandNV(n_vk, "CopyMemoryToImageIndirectCommandNV");
    py::class_<::vk::PhysicalDeviceCopyMemoryIndirectFeaturesNV> s_vk_PhysicalDeviceCopyMemoryIndirectFeaturesNV(n_vk, "PhysicalDeviceCopyMemoryIndirectFeaturesNV");
    py::class_<::vk::PhysicalDeviceCopyMemoryIndirectPropertiesNV> s_vk_PhysicalDeviceCopyMemoryIndirectPropertiesNV(n_vk, "PhysicalDeviceCopyMemoryIndirectPropertiesNV");
    py::class_<::vk::DecompressMemoryRegionNV> s_vk_DecompressMemoryRegionNV(n_vk, "DecompressMemoryRegionNV");
    py::class_<::vk::PhysicalDeviceMemoryDecompressionFeaturesNV> s_vk_PhysicalDeviceMemoryDecompressionFeaturesNV(n_vk, "PhysicalDeviceMemoryDecompressionFeaturesNV");
    py::class_<::vk::PhysicalDeviceMemoryDecompressionPropertiesNV> s_vk_PhysicalDeviceMemoryDecompressionPropertiesNV(n_vk, "PhysicalDeviceMemoryDecompressionPropertiesNV");
    py::class_<::vk::BindPipelineIndirectCommandNV> s_vk_BindPipelineIndirectCommandNV(n_vk, "BindPipelineIndirectCommandNV");
    py::class_<::vk::ComputePipelineIndirectBufferInfoNV> s_vk_ComputePipelineIndirectBufferInfoNV(n_vk, "ComputePipelineIndirectBufferInfoNV");
    py::class_<::vk::PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV> s_vk_PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV(n_vk, "PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV");
    py::class_<::vk::PipelineIndirectDeviceAddressInfoNV> s_vk_PipelineIndirectDeviceAddressInfoNV(n_vk, "PipelineIndirectDeviceAddressInfoNV");
    py::class_<::vk::PhysicalDeviceLinearColorAttachmentFeaturesNV> s_vk_PhysicalDeviceLinearColorAttachmentFeaturesNV(n_vk, "PhysicalDeviceLinearColorAttachmentFeaturesNV");
    py::class_<::vk::PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT> s_vk_PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT(n_vk, "PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT");
    py::class_<::vk::ImageViewSampleWeightCreateInfoQCOM> s_vk_ImageViewSampleWeightCreateInfoQCOM(n_vk, "ImageViewSampleWeightCreateInfoQCOM");
    py::class_<::vk::PhysicalDeviceImageProcessingFeaturesQCOM> s_vk_PhysicalDeviceImageProcessingFeaturesQCOM(n_vk, "PhysicalDeviceImageProcessingFeaturesQCOM");
    py::class_<::vk::PhysicalDeviceImageProcessingPropertiesQCOM> s_vk_PhysicalDeviceImageProcessingPropertiesQCOM(n_vk, "PhysicalDeviceImageProcessingPropertiesQCOM");
    py::class_<::vk::PhysicalDeviceNestedCommandBufferFeaturesEXT> s_vk_PhysicalDeviceNestedCommandBufferFeaturesEXT(n_vk, "PhysicalDeviceNestedCommandBufferFeaturesEXT");
    py::class_<::vk::PhysicalDeviceNestedCommandBufferPropertiesEXT> s_vk_PhysicalDeviceNestedCommandBufferPropertiesEXT(n_vk, "PhysicalDeviceNestedCommandBufferPropertiesEXT");
    py::class_<::vk::ExternalMemoryAcquireUnmodifiedEXT> s_vk_ExternalMemoryAcquireUnmodifiedEXT(n_vk, "ExternalMemoryAcquireUnmodifiedEXT");
    py::class_<::vk::ColorBlendAdvancedEXT> s_vk_ColorBlendAdvancedEXT(n_vk, "ColorBlendAdvancedEXT");
    py::class_<::vk::ColorBlendEquationEXT> s_vk_ColorBlendEquationEXT(n_vk, "ColorBlendEquationEXT");
    py::class_<::vk::PhysicalDeviceExtendedDynamicState3FeaturesEXT> s_vk_PhysicalDeviceExtendedDynamicState3FeaturesEXT(n_vk, "PhysicalDeviceExtendedDynamicState3FeaturesEXT");
    py::class_<::vk::PhysicalDeviceExtendedDynamicState3PropertiesEXT> s_vk_PhysicalDeviceExtendedDynamicState3PropertiesEXT(n_vk, "PhysicalDeviceExtendedDynamicState3PropertiesEXT");
    py::class_<::vk::PhysicalDeviceSubpassMergeFeedbackFeaturesEXT> s_vk_PhysicalDeviceSubpassMergeFeedbackFeaturesEXT(n_vk, "PhysicalDeviceSubpassMergeFeedbackFeaturesEXT");
    py::class_<::vk::RenderPassCreationControlEXT> s_vk_RenderPassCreationControlEXT(n_vk, "RenderPassCreationControlEXT");
    py::class_<::vk::RenderPassCreationFeedbackCreateInfoEXT> s_vk_RenderPassCreationFeedbackCreateInfoEXT(n_vk, "RenderPassCreationFeedbackCreateInfoEXT");
    py::class_<::vk::RenderPassCreationFeedbackInfoEXT> s_vk_RenderPassCreationFeedbackInfoEXT(n_vk, "RenderPassCreationFeedbackInfoEXT");
    py::class_<::vk::RenderPassSubpassFeedbackCreateInfoEXT> s_vk_RenderPassSubpassFeedbackCreateInfoEXT(n_vk, "RenderPassSubpassFeedbackCreateInfoEXT");
    py::class_<::vk::RenderPassSubpassFeedbackInfoEXT> s_vk_RenderPassSubpassFeedbackInfoEXT(n_vk, "RenderPassSubpassFeedbackInfoEXT");
    py::class_<::vk::DirectDriverLoadingInfoLUNARG> s_vk_DirectDriverLoadingInfoLUNARG(n_vk, "DirectDriverLoadingInfoLUNARG");
    py::class_<::vk::DirectDriverLoadingListLUNARG> s_vk_DirectDriverLoadingListLUNARG(n_vk, "DirectDriverLoadingListLUNARG");
    py::class_<::vk::PhysicalDeviceShaderModuleIdentifierFeaturesEXT> s_vk_PhysicalDeviceShaderModuleIdentifierFeaturesEXT(n_vk, "PhysicalDeviceShaderModuleIdentifierFeaturesEXT");
    py::class_<::vk::PhysicalDeviceShaderModuleIdentifierPropertiesEXT> s_vk_PhysicalDeviceShaderModuleIdentifierPropertiesEXT(n_vk, "PhysicalDeviceShaderModuleIdentifierPropertiesEXT");
    py::class_<::vk::PipelineShaderStageModuleIdentifierCreateInfoEXT> s_vk_PipelineShaderStageModuleIdentifierCreateInfoEXT(n_vk, "PipelineShaderStageModuleIdentifierCreateInfoEXT");
    py::class_<::vk::ShaderModuleIdentifierEXT> s_vk_ShaderModuleIdentifierEXT(n_vk, "ShaderModuleIdentifierEXT");
    py::class_<::vk::PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT> s_vk_PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT(n_vk, "PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT");
    py::class_<::vk::OpticalFlowExecuteInfoNV> s_vk_OpticalFlowExecuteInfoNV(n_vk, "OpticalFlowExecuteInfoNV");
    py::class_<::vk::OpticalFlowImageFormatInfoNV> s_vk_OpticalFlowImageFormatInfoNV(n_vk, "OpticalFlowImageFormatInfoNV");
    py::class_<::vk::OpticalFlowImageFormatPropertiesNV> s_vk_OpticalFlowImageFormatPropertiesNV(n_vk, "OpticalFlowImageFormatPropertiesNV");
    py::class_<::vk::OpticalFlowSessionCreateInfoNV> s_vk_OpticalFlowSessionCreateInfoNV(n_vk, "OpticalFlowSessionCreateInfoNV");
    py::class_<::vk::OpticalFlowSessionCreatePrivateDataInfoNV> s_vk_OpticalFlowSessionCreatePrivateDataInfoNV(n_vk, "OpticalFlowSessionCreatePrivateDataInfoNV");
    py::class_<::vk::PhysicalDeviceOpticalFlowFeaturesNV> s_vk_PhysicalDeviceOpticalFlowFeaturesNV(n_vk, "PhysicalDeviceOpticalFlowFeaturesNV");
    py::class_<::vk::PhysicalDeviceOpticalFlowPropertiesNV> s_vk_PhysicalDeviceOpticalFlowPropertiesNV(n_vk, "PhysicalDeviceOpticalFlowPropertiesNV");
    py::class_<::vk::PhysicalDeviceLegacyDitheringFeaturesEXT> s_vk_PhysicalDeviceLegacyDitheringFeaturesEXT(n_vk, "PhysicalDeviceLegacyDitheringFeaturesEXT");
    py::class_<::vk::PhysicalDevicePipelineProtectedAccessFeaturesEXT> s_vk_PhysicalDevicePipelineProtectedAccessFeaturesEXT(n_vk, "PhysicalDevicePipelineProtectedAccessFeaturesEXT");
    py::class_<::vk::BufferUsageFlags2CreateInfoKHR> s_vk_BufferUsageFlags2CreateInfoKHR(n_vk, "BufferUsageFlags2CreateInfoKHR");
    py::class_<::vk::DeviceImageSubresourceInfoKHR> s_vk_DeviceImageSubresourceInfoKHR(n_vk, "DeviceImageSubresourceInfoKHR");
    py::class_<::vk::ImageSubresource2KHR> s_vk_ImageSubresource2KHR(n_vk, "ImageSubresource2KHR");
    py::class_<::vk::PhysicalDeviceMaintenance5FeaturesKHR> s_vk_PhysicalDeviceMaintenance5FeaturesKHR(n_vk, "PhysicalDeviceMaintenance5FeaturesKHR");
    py::class_<::vk::PhysicalDeviceMaintenance5PropertiesKHR> s_vk_PhysicalDeviceMaintenance5PropertiesKHR(n_vk, "PhysicalDeviceMaintenance5PropertiesKHR");
    py::class_<::vk::PipelineCreateFlags2CreateInfoKHR> s_vk_PipelineCreateFlags2CreateInfoKHR(n_vk, "PipelineCreateFlags2CreateInfoKHR");
    py::class_<::vk::RenderingAreaInfoKHR> s_vk_RenderingAreaInfoKHR(n_vk, "RenderingAreaInfoKHR");
    py::class_<::vk::SubresourceLayout2KHR> s_vk_SubresourceLayout2KHR(n_vk, "SubresourceLayout2KHR");
    py::class_<::vk::PhysicalDeviceRayTracingPositionFetchFeaturesKHR> s_vk_PhysicalDeviceRayTracingPositionFetchFeaturesKHR(n_vk, "PhysicalDeviceRayTracingPositionFetchFeaturesKHR");
    py::class_<::vk::PhysicalDeviceShaderObjectFeaturesEXT> s_vk_PhysicalDeviceShaderObjectFeaturesEXT(n_vk, "PhysicalDeviceShaderObjectFeaturesEXT");
    py::class_<::vk::PhysicalDeviceShaderObjectPropertiesEXT> s_vk_PhysicalDeviceShaderObjectPropertiesEXT(n_vk, "PhysicalDeviceShaderObjectPropertiesEXT");
    py::class_<::vk::ShaderCreateInfoEXT> s_vk_ShaderCreateInfoEXT(n_vk, "ShaderCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceTilePropertiesFeaturesQCOM> s_vk_PhysicalDeviceTilePropertiesFeaturesQCOM(n_vk, "PhysicalDeviceTilePropertiesFeaturesQCOM");
    py::class_<::vk::TilePropertiesQCOM> s_vk_TilePropertiesQCOM(n_vk, "TilePropertiesQCOM");
    py::class_<::vk::AmigoProfilingSubmitInfoSEC> s_vk_AmigoProfilingSubmitInfoSEC(n_vk, "AmigoProfilingSubmitInfoSEC");
    py::class_<::vk::PhysicalDeviceAmigoProfilingFeaturesSEC> s_vk_PhysicalDeviceAmigoProfilingFeaturesSEC(n_vk, "PhysicalDeviceAmigoProfilingFeaturesSEC");
    py::class_<::vk::PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM> s_vk_PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM(n_vk, "PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM");
    py::class_<::vk::PhysicalDeviceRayTracingInvocationReorderFeaturesNV> s_vk_PhysicalDeviceRayTracingInvocationReorderFeaturesNV(n_vk, "PhysicalDeviceRayTracingInvocationReorderFeaturesNV");
    py::class_<::vk::PhysicalDeviceRayTracingInvocationReorderPropertiesNV> s_vk_PhysicalDeviceRayTracingInvocationReorderPropertiesNV(n_vk, "PhysicalDeviceRayTracingInvocationReorderPropertiesNV");
    py::class_<::vk::PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV> s_vk_PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV(n_vk, "PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV");
    py::class_<::vk::PhysicalDeviceExtendedSparseAddressSpacePropertiesNV> s_vk_PhysicalDeviceExtendedSparseAddressSpacePropertiesNV(n_vk, "PhysicalDeviceExtendedSparseAddressSpacePropertiesNV");
    py::class_<::vk::MutableDescriptorTypeCreateInfoEXT> s_vk_MutableDescriptorTypeCreateInfoEXT(n_vk, "MutableDescriptorTypeCreateInfoEXT");
    py::class_<::vk::MutableDescriptorTypeListEXT> s_vk_MutableDescriptorTypeListEXT(n_vk, "MutableDescriptorTypeListEXT");
    py::class_<::vk::PhysicalDeviceMutableDescriptorTypeFeaturesEXT> s_vk_PhysicalDeviceMutableDescriptorTypeFeaturesEXT(n_vk, "PhysicalDeviceMutableDescriptorTypeFeaturesEXT");
    py::class_<::vk::LayerSettingEXT> s_vk_LayerSettingEXT(n_vk, "LayerSettingEXT");
    py::class_<::vk::LayerSettingsCreateInfoEXT> s_vk_LayerSettingsCreateInfoEXT(n_vk, "LayerSettingsCreateInfoEXT");
    py::class_<::vk::PhysicalDeviceShaderCoreBuiltinsFeaturesARM> s_vk_PhysicalDeviceShaderCoreBuiltinsFeaturesARM(n_vk, "PhysicalDeviceShaderCoreBuiltinsFeaturesARM");
    py::class_<::vk::PhysicalDeviceShaderCoreBuiltinsPropertiesARM> s_vk_PhysicalDeviceShaderCoreBuiltinsPropertiesARM(n_vk, "PhysicalDeviceShaderCoreBuiltinsPropertiesARM");
    py::class_<::vk::PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT> s_vk_PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT(n_vk, "PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT");
    py::class_<::vk::PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT> s_vk_PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT(n_vk, "PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT");
    py::class_<::vk::GetLatencyMarkerInfoNV> s_vk_GetLatencyMarkerInfoNV(n_vk, "GetLatencyMarkerInfoNV");
    py::class_<::vk::LatencySleepInfoNV> s_vk_LatencySleepInfoNV(n_vk, "LatencySleepInfoNV");
    py::class_<::vk::LatencySleepModeInfoNV> s_vk_LatencySleepModeInfoNV(n_vk, "LatencySleepModeInfoNV");
    py::class_<::vk::LatencySubmissionPresentIdNV> s_vk_LatencySubmissionPresentIdNV(n_vk, "LatencySubmissionPresentIdNV");
    py::class_<::vk::LatencySurfaceCapabilitiesNV> s_vk_LatencySurfaceCapabilitiesNV(n_vk, "LatencySurfaceCapabilitiesNV");
    py::class_<::vk::LatencyTimingsFrameReportNV> s_vk_LatencyTimingsFrameReportNV(n_vk, "LatencyTimingsFrameReportNV");
    py::class_<::vk::OutOfBandQueueTypeInfoNV> s_vk_OutOfBandQueueTypeInfoNV(n_vk, "OutOfBandQueueTypeInfoNV");
    py::class_<::vk::SetLatencyMarkerInfoNV> s_vk_SetLatencyMarkerInfoNV(n_vk, "SetLatencyMarkerInfoNV");
    py::class_<::vk::SwapchainLatencyCreateInfoNV> s_vk_SwapchainLatencyCreateInfoNV(n_vk, "SwapchainLatencyCreateInfoNV");
    py::class_<::vk::CooperativeMatrixPropertiesKHR> s_vk_CooperativeMatrixPropertiesKHR(n_vk, "CooperativeMatrixPropertiesKHR");
    py::class_<::vk::PhysicalDeviceCooperativeMatrixFeaturesKHR> s_vk_PhysicalDeviceCooperativeMatrixFeaturesKHR(n_vk, "PhysicalDeviceCooperativeMatrixFeaturesKHR");
    py::class_<::vk::PhysicalDeviceCooperativeMatrixPropertiesKHR> s_vk_PhysicalDeviceCooperativeMatrixPropertiesKHR(n_vk, "PhysicalDeviceCooperativeMatrixPropertiesKHR");
    py::class_<::vk::MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM> s_vk_MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM(n_vk, "MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM");
    py::class_<::vk::PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM> s_vk_PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM(n_vk, "PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM");
    py::class_<::vk::PhysicalDeviceVideoMaintenance1FeaturesKHR> s_vk_PhysicalDeviceVideoMaintenance1FeaturesKHR(n_vk, "PhysicalDeviceVideoMaintenance1FeaturesKHR");
    py::class_<::vk::VideoInlineQueryInfoKHR> s_vk_VideoInlineQueryInfoKHR(n_vk, "VideoInlineQueryInfoKHR");
    py::class_<::vk::PhysicalDevicePerStageDescriptorSetFeaturesNV> s_vk_PhysicalDevicePerStageDescriptorSetFeaturesNV(n_vk, "PhysicalDevicePerStageDescriptorSetFeaturesNV");
    py::class_<::vk::PhysicalDeviceImageProcessing2FeaturesQCOM> s_vk_PhysicalDeviceImageProcessing2FeaturesQCOM(n_vk, "PhysicalDeviceImageProcessing2FeaturesQCOM");
    py::class_<::vk::PhysicalDeviceImageProcessing2PropertiesQCOM> s_vk_PhysicalDeviceImageProcessing2PropertiesQCOM(n_vk, "PhysicalDeviceImageProcessing2PropertiesQCOM");
    py::class_<::vk::SamplerBlockMatchWindowCreateInfoQCOM> s_vk_SamplerBlockMatchWindowCreateInfoQCOM(n_vk, "SamplerBlockMatchWindowCreateInfoQCOM");
    py::class_<::vk::BlitImageCubicWeightsInfoQCOM> s_vk_BlitImageCubicWeightsInfoQCOM(n_vk, "BlitImageCubicWeightsInfoQCOM");
    py::class_<::vk::PhysicalDeviceCubicWeightsFeaturesQCOM> s_vk_PhysicalDeviceCubicWeightsFeaturesQCOM(n_vk, "PhysicalDeviceCubicWeightsFeaturesQCOM");
    py::class_<::vk::SamplerCubicWeightsCreateInfoQCOM> s_vk_SamplerCubicWeightsCreateInfoQCOM(n_vk, "SamplerCubicWeightsCreateInfoQCOM");
    py::class_<::vk::PhysicalDeviceYcbcrDegammaFeaturesQCOM> s_vk_PhysicalDeviceYcbcrDegammaFeaturesQCOM(n_vk, "PhysicalDeviceYcbcrDegammaFeaturesQCOM");
    py::class_<::vk::SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM> s_vk_SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM(n_vk, "SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM");
    py::class_<::vk::PhysicalDeviceCubicClampFeaturesQCOM> s_vk_PhysicalDeviceCubicClampFeaturesQCOM(n_vk, "PhysicalDeviceCubicClampFeaturesQCOM");
    py::class_<::vk::PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT> s_vk_PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT(n_vk, "PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT");
    py::class_<::vk::PhysicalDeviceVertexAttributeDivisorFeaturesKHR> s_vk_PhysicalDeviceVertexAttributeDivisorFeaturesKHR(n_vk, "PhysicalDeviceVertexAttributeDivisorFeaturesKHR");
    py::class_<::vk::PhysicalDeviceVertexAttributeDivisorPropertiesKHR> s_vk_PhysicalDeviceVertexAttributeDivisorPropertiesKHR(n_vk, "PhysicalDeviceVertexAttributeDivisorPropertiesKHR");
    py::class_<::vk::PipelineVertexInputDivisorStateCreateInfoKHR> s_vk_PipelineVertexInputDivisorStateCreateInfoKHR(n_vk, "PipelineVertexInputDivisorStateCreateInfoKHR");
    py::class_<::vk::VertexInputBindingDivisorDescriptionKHR> s_vk_VertexInputBindingDivisorDescriptionKHR(n_vk, "VertexInputBindingDivisorDescriptionKHR");
    py::class_<::vk::PhysicalDeviceLayeredDriverPropertiesMSFT> s_vk_PhysicalDeviceLayeredDriverPropertiesMSFT(n_vk, "PhysicalDeviceLayeredDriverPropertiesMSFT");
    py::class_<::vk::CalibratedTimestampInfoKHR> s_vk_CalibratedTimestampInfoKHR(n_vk, "CalibratedTimestampInfoKHR");
    py::class_<::vk::BindDescriptorBufferEmbeddedSamplersInfoEXT> s_vk_BindDescriptorBufferEmbeddedSamplersInfoEXT(n_vk, "BindDescriptorBufferEmbeddedSamplersInfoEXT");
    py::class_<::vk::BindDescriptorSetsInfoKHR> s_vk_BindDescriptorSetsInfoKHR(n_vk, "BindDescriptorSetsInfoKHR");
    py::class_<::vk::BindMemoryStatusKHR> s_vk_BindMemoryStatusKHR(n_vk, "BindMemoryStatusKHR");
    py::class_<::vk::PhysicalDeviceMaintenance6FeaturesKHR> s_vk_PhysicalDeviceMaintenance6FeaturesKHR(n_vk, "PhysicalDeviceMaintenance6FeaturesKHR");
    py::class_<::vk::PhysicalDeviceMaintenance6PropertiesKHR> s_vk_PhysicalDeviceMaintenance6PropertiesKHR(n_vk, "PhysicalDeviceMaintenance6PropertiesKHR");
    py::class_<::vk::PushConstantsInfoKHR> s_vk_PushConstantsInfoKHR(n_vk, "PushConstantsInfoKHR");
    py::class_<::vk::PushDescriptorSetInfoKHR> s_vk_PushDescriptorSetInfoKHR(n_vk, "PushDescriptorSetInfoKHR");
    py::class_<::vk::PushDescriptorSetWithTemplateInfoKHR> s_vk_PushDescriptorSetWithTemplateInfoKHR(n_vk, "PushDescriptorSetWithTemplateInfoKHR");
    py::class_<::vk::SetDescriptorBufferOffsetsInfoEXT> s_vk_SetDescriptorBufferOffsetsInfoEXT(n_vk, "SetDescriptorBufferOffsetsInfoEXT");
    py::class_<::vk::PhysicalDeviceDescriptorPoolOverallocationFeaturesNV> s_vk_PhysicalDeviceDescriptorPoolOverallocationFeaturesNV(n_vk, "PhysicalDeviceDescriptorPoolOverallocationFeaturesNV");
    py::module n_vk_raii = n_vk.def_submodule("raii");

    e_vk_AccessFlagBits.value("INDIRECT_COMMAND_READ", ::vk::AccessFlagBits::eIndirectCommandRead);
    e_vk_AccessFlagBits.value("INDEX_READ", ::vk::AccessFlagBits::eIndexRead);
    e_vk_AccessFlagBits.value("VERTEX_ATTRIBUTE_READ", ::vk::AccessFlagBits::eVertexAttributeRead);
    e_vk_AccessFlagBits.value("UNIFORM_READ", ::vk::AccessFlagBits::eUniformRead);
    e_vk_AccessFlagBits.value("INPUT_ATTACHMENT_READ", ::vk::AccessFlagBits::eInputAttachmentRead);
    e_vk_AccessFlagBits.value("SHADER_READ", ::vk::AccessFlagBits::eShaderRead);
    e_vk_AccessFlagBits.value("SHADER_WRITE", ::vk::AccessFlagBits::eShaderWrite);
    e_vk_AccessFlagBits.value("COLOR_ATTACHMENT_READ", ::vk::AccessFlagBits::eColorAttachmentRead);
    e_vk_AccessFlagBits.value("COLOR_ATTACHMENT_WRITE", ::vk::AccessFlagBits::eColorAttachmentWrite);
    e_vk_AccessFlagBits.value("DEPTH_STENCIL_ATTACHMENT_READ", ::vk::AccessFlagBits::eDepthStencilAttachmentRead);
    e_vk_AccessFlagBits.value("DEPTH_STENCIL_ATTACHMENT_WRITE", ::vk::AccessFlagBits::eDepthStencilAttachmentWrite);
    e_vk_AccessFlagBits.value("TRANSFER_READ", ::vk::AccessFlagBits::eTransferRead);
    e_vk_AccessFlagBits.value("TRANSFER_WRITE", ::vk::AccessFlagBits::eTransferWrite);
    e_vk_AccessFlagBits.value("HOST_READ", ::vk::AccessFlagBits::eHostRead);
    e_vk_AccessFlagBits.value("HOST_WRITE", ::vk::AccessFlagBits::eHostWrite);
    e_vk_AccessFlagBits.value("MEMORY_READ", ::vk::AccessFlagBits::eMemoryRead);
    e_vk_AccessFlagBits.value("MEMORY_WRITE", ::vk::AccessFlagBits::eMemoryWrite);
    e_vk_AccessFlagBits.value("NONE", ::vk::AccessFlagBits::eNone);
    e_vk_AccessFlagBits.value("TRANSFORM_FEEDBACK_WRITE_EXT", ::vk::AccessFlagBits::eTransformFeedbackWriteEXT);
    e_vk_AccessFlagBits.value("TRANSFORM_FEEDBACK_COUNTER_READ_EXT", ::vk::AccessFlagBits::eTransformFeedbackCounterReadEXT);
    e_vk_AccessFlagBits.value("TRANSFORM_FEEDBACK_COUNTER_WRITE_EXT", ::vk::AccessFlagBits::eTransformFeedbackCounterWriteEXT);
    e_vk_AccessFlagBits.value("CONDITIONAL_RENDERING_READ_EXT", ::vk::AccessFlagBits::eConditionalRenderingReadEXT);
    e_vk_AccessFlagBits.value("COLOR_ATTACHMENT_READ_NONCOHERENT_EXT", ::vk::AccessFlagBits::eColorAttachmentReadNoncoherentEXT);
    e_vk_AccessFlagBits.value("ACCELERATION_STRUCTURE_READ_KHR", ::vk::AccessFlagBits::eAccelerationStructureReadKHR);
    e_vk_AccessFlagBits.value("ACCELERATION_STRUCTURE_WRITE_KHR", ::vk::AccessFlagBits::eAccelerationStructureWriteKHR);
    e_vk_AccessFlagBits.value("SHADING_RATE_IMAGE_READ_NV", ::vk::AccessFlagBits::eShadingRateImageReadNV);
    e_vk_AccessFlagBits.value("ACCELERATION_STRUCTURE_READ_NV", ::vk::AccessFlagBits::eAccelerationStructureReadNV);
    e_vk_AccessFlagBits.value("ACCELERATION_STRUCTURE_WRITE_NV", ::vk::AccessFlagBits::eAccelerationStructureWriteNV);
    e_vk_AccessFlagBits.value("FRAGMENT_DENSITY_MAP_READ_EXT", ::vk::AccessFlagBits::eFragmentDensityMapReadEXT);
    e_vk_AccessFlagBits.value("FRAGMENT_SHADING_RATE_ATTACHMENT_READ_KHR", ::vk::AccessFlagBits::eFragmentShadingRateAttachmentReadKHR);
    e_vk_AccessFlagBits.value("COMMAND_PREPROCESS_READ_NV", ::vk::AccessFlagBits::eCommandPreprocessReadNV);
    e_vk_AccessFlagBits.value("COMMAND_PREPROCESS_WRITE_NV", ::vk::AccessFlagBits::eCommandPreprocessWriteNV);
    e_vk_AccessFlagBits.value("NONE_KHR", ::vk::AccessFlagBits::eNoneKHR);

    e_vk_AttachmentDescriptionFlagBits.value("MAY_ALIAS", ::vk::AttachmentDescriptionFlagBits::eMayAlias);

    e_vk_AttachmentLoadOp.value("LOAD", ::vk::AttachmentLoadOp::eLoad);
    e_vk_AttachmentLoadOp.value("CLEAR", ::vk::AttachmentLoadOp::eClear);
    e_vk_AttachmentLoadOp.value("DONT_CARE", ::vk::AttachmentLoadOp::eDontCare);
    e_vk_AttachmentLoadOp.value("NONE_EXT", ::vk::AttachmentLoadOp::eNoneEXT);

    e_vk_AttachmentStoreOp.value("STORE", ::vk::AttachmentStoreOp::eStore);
    e_vk_AttachmentStoreOp.value("DONT_CARE", ::vk::AttachmentStoreOp::eDontCare);
    e_vk_AttachmentStoreOp.value("NONE", ::vk::AttachmentStoreOp::eNone);
    e_vk_AttachmentStoreOp.value("NONE_KHR", ::vk::AttachmentStoreOp::eNoneKHR);
    e_vk_AttachmentStoreOp.value("NONE_QCOM", ::vk::AttachmentStoreOp::eNoneQCOM);
    e_vk_AttachmentStoreOp.value("NONE_EXT", ::vk::AttachmentStoreOp::eNoneEXT);

    e_vk_BlendFactor.value("ZERO", ::vk::BlendFactor::eZero);
    e_vk_BlendFactor.value("ONE", ::vk::BlendFactor::eOne);
    e_vk_BlendFactor.value("SRC_COLOR", ::vk::BlendFactor::eSrcColor);
    e_vk_BlendFactor.value("ONE_MINUS_SRC_COLOR", ::vk::BlendFactor::eOneMinusSrcColor);
    e_vk_BlendFactor.value("DST_COLOR", ::vk::BlendFactor::eDstColor);
    e_vk_BlendFactor.value("ONE_MINUS_DST_COLOR", ::vk::BlendFactor::eOneMinusDstColor);
    e_vk_BlendFactor.value("SRC_ALPHA", ::vk::BlendFactor::eSrcAlpha);
    e_vk_BlendFactor.value("ONE_MINUS_SRC_ALPHA", ::vk::BlendFactor::eOneMinusSrcAlpha);
    e_vk_BlendFactor.value("DST_ALPHA", ::vk::BlendFactor::eDstAlpha);
    e_vk_BlendFactor.value("ONE_MINUS_DST_ALPHA", ::vk::BlendFactor::eOneMinusDstAlpha);
    e_vk_BlendFactor.value("CONSTANT_COLOR", ::vk::BlendFactor::eConstantColor);
    e_vk_BlendFactor.value("ONE_MINUS_CONSTANT_COLOR", ::vk::BlendFactor::eOneMinusConstantColor);
    e_vk_BlendFactor.value("CONSTANT_ALPHA", ::vk::BlendFactor::eConstantAlpha);
    e_vk_BlendFactor.value("ONE_MINUS_CONSTANT_ALPHA", ::vk::BlendFactor::eOneMinusConstantAlpha);
    e_vk_BlendFactor.value("SRC_ALPHA_SATURATE", ::vk::BlendFactor::eSrcAlphaSaturate);
    e_vk_BlendFactor.value("SRC_1_COLOR", ::vk::BlendFactor::eSrc1Color);
    e_vk_BlendFactor.value("ONE_MINUS_SRC_1_COLOR", ::vk::BlendFactor::eOneMinusSrc1Color);
    e_vk_BlendFactor.value("SRC_1_ALPHA", ::vk::BlendFactor::eSrc1Alpha);
    e_vk_BlendFactor.value("ONE_MINUS_SRC_1_ALPHA", ::vk::BlendFactor::eOneMinusSrc1Alpha);

    e_vk_BlendOp.value("ADD", ::vk::BlendOp::eAdd);
    e_vk_BlendOp.value("SUBTRACT", ::vk::BlendOp::eSubtract);
    e_vk_BlendOp.value("REVERSE_SUBTRACT", ::vk::BlendOp::eReverseSubtract);
    e_vk_BlendOp.value("MIN", ::vk::BlendOp::eMin);
    e_vk_BlendOp.value("MAX", ::vk::BlendOp::eMax);
    e_vk_BlendOp.value("ZERO_EXT", ::vk::BlendOp::eZeroEXT);
    e_vk_BlendOp.value("SRC_EXT", ::vk::BlendOp::eSrcEXT);
    e_vk_BlendOp.value("DST_EXT", ::vk::BlendOp::eDstEXT);
    e_vk_BlendOp.value("SRC_OVER_EXT", ::vk::BlendOp::eSrcOverEXT);
    e_vk_BlendOp.value("DST_OVER_EXT", ::vk::BlendOp::eDstOverEXT);
    e_vk_BlendOp.value("SRC_IN_EXT", ::vk::BlendOp::eSrcInEXT);
    e_vk_BlendOp.value("DST_IN_EXT", ::vk::BlendOp::eDstInEXT);
    e_vk_BlendOp.value("SRC_OUT_EXT", ::vk::BlendOp::eSrcOutEXT);
    e_vk_BlendOp.value("DST_OUT_EXT", ::vk::BlendOp::eDstOutEXT);
    e_vk_BlendOp.value("SRC_ATOP_EXT", ::vk::BlendOp::eSrcAtopEXT);
    e_vk_BlendOp.value("DST_ATOP_EXT", ::vk::BlendOp::eDstAtopEXT);
    e_vk_BlendOp.value("XOR_EXT", ::vk::BlendOp::eXorEXT);
    e_vk_BlendOp.value("MULTIPLY_EXT", ::vk::BlendOp::eMultiplyEXT);
    e_vk_BlendOp.value("SCREEN_EXT", ::vk::BlendOp::eScreenEXT);
    e_vk_BlendOp.value("OVERLAY_EXT", ::vk::BlendOp::eOverlayEXT);
    e_vk_BlendOp.value("DARKEN_EXT", ::vk::BlendOp::eDarkenEXT);
    e_vk_BlendOp.value("LIGHTEN_EXT", ::vk::BlendOp::eLightenEXT);
    e_vk_BlendOp.value("COLORDODGE_EXT", ::vk::BlendOp::eColordodgeEXT);
    e_vk_BlendOp.value("COLORBURN_EXT", ::vk::BlendOp::eColorburnEXT);
    e_vk_BlendOp.value("HARDLIGHT_EXT", ::vk::BlendOp::eHardlightEXT);
    e_vk_BlendOp.value("SOFTLIGHT_EXT", ::vk::BlendOp::eSoftlightEXT);
    e_vk_BlendOp.value("DIFFERENCE_EXT", ::vk::BlendOp::eDifferenceEXT);
    e_vk_BlendOp.value("EXCLUSION_EXT", ::vk::BlendOp::eExclusionEXT);
    e_vk_BlendOp.value("INVERT_EXT", ::vk::BlendOp::eInvertEXT);
    e_vk_BlendOp.value("INVERT_RGB_EXT", ::vk::BlendOp::eInvertRgbEXT);
    e_vk_BlendOp.value("LINEARDODGE_EXT", ::vk::BlendOp::eLineardodgeEXT);
    e_vk_BlendOp.value("LINEARBURN_EXT", ::vk::BlendOp::eLinearburnEXT);
    e_vk_BlendOp.value("VIVIDLIGHT_EXT", ::vk::BlendOp::eVividlightEXT);
    e_vk_BlendOp.value("LINEARLIGHT_EXT", ::vk::BlendOp::eLinearlightEXT);
    e_vk_BlendOp.value("PINLIGHT_EXT", ::vk::BlendOp::ePinlightEXT);
    e_vk_BlendOp.value("HARDMIX_EXT", ::vk::BlendOp::eHardmixEXT);
    e_vk_BlendOp.value("HSL_HUE_EXT", ::vk::BlendOp::eHslHueEXT);
    e_vk_BlendOp.value("HSL_SATURATION_EXT", ::vk::BlendOp::eHslSaturationEXT);
    e_vk_BlendOp.value("HSL_COLOR_EXT", ::vk::BlendOp::eHslColorEXT);
    e_vk_BlendOp.value("HSL_LUMINOSITY_EXT", ::vk::BlendOp::eHslLuminosityEXT);
    e_vk_BlendOp.value("PLUS_EXT", ::vk::BlendOp::ePlusEXT);
    e_vk_BlendOp.value("PLUS_CLAMPED_EXT", ::vk::BlendOp::ePlusClampedEXT);
    e_vk_BlendOp.value("PLUS_CLAMPED_ALPHA_EXT", ::vk::BlendOp::ePlusClampedAlphaEXT);
    e_vk_BlendOp.value("PLUS_DARKER_EXT", ::vk::BlendOp::ePlusDarkerEXT);
    e_vk_BlendOp.value("MINUS_EXT", ::vk::BlendOp::eMinusEXT);
    e_vk_BlendOp.value("MINUS_CLAMPED_EXT", ::vk::BlendOp::eMinusClampedEXT);
    e_vk_BlendOp.value("CONTRAST_EXT", ::vk::BlendOp::eContrastEXT);
    e_vk_BlendOp.value("INVERT_OVG_EXT", ::vk::BlendOp::eInvertOvgEXT);
    e_vk_BlendOp.value("RED_EXT", ::vk::BlendOp::eRedEXT);
    e_vk_BlendOp.value("GREEN_EXT", ::vk::BlendOp::eGreenEXT);
    e_vk_BlendOp.value("BLUE_EXT", ::vk::BlendOp::eBlueEXT);

    e_vk_BorderColor.value("FLOAT_TRANSPARENT_BLACK", ::vk::BorderColor::eFloatTransparentBlack);
    e_vk_BorderColor.value("INT_TRANSPARENT_BLACK", ::vk::BorderColor::eIntTransparentBlack);
    e_vk_BorderColor.value("FLOAT_OPAQUE_BLACK", ::vk::BorderColor::eFloatOpaqueBlack);
    e_vk_BorderColor.value("INT_OPAQUE_BLACK", ::vk::BorderColor::eIntOpaqueBlack);
    e_vk_BorderColor.value("FLOAT_OPAQUE_WHITE", ::vk::BorderColor::eFloatOpaqueWhite);
    e_vk_BorderColor.value("INT_OPAQUE_WHITE", ::vk::BorderColor::eIntOpaqueWhite);
    e_vk_BorderColor.value("FLOAT_CUSTOM_EXT", ::vk::BorderColor::eFloatCustomEXT);
    e_vk_BorderColor.value("INT_CUSTOM_EXT", ::vk::BorderColor::eIntCustomEXT);

    e_vk_BufferCreateFlagBits.value("SPARSE_BINDING", ::vk::BufferCreateFlagBits::eSparseBinding);
    e_vk_BufferCreateFlagBits.value("SPARSE_RESIDENCY", ::vk::BufferCreateFlagBits::eSparseResidency);
    e_vk_BufferCreateFlagBits.value("SPARSE_ALIASED", ::vk::BufferCreateFlagBits::eSparseAliased);
    e_vk_BufferCreateFlagBits.value("PROTECTED", ::vk::BufferCreateFlagBits::eProtected);
    e_vk_BufferCreateFlagBits.value("DEVICE_ADDRESS_CAPTURE_REPLAY", ::vk::BufferCreateFlagBits::eDeviceAddressCaptureReplay);
    e_vk_BufferCreateFlagBits.value("DEVICE_ADDRESS_CAPTURE_REPLAY_EXT", ::vk::BufferCreateFlagBits::eDeviceAddressCaptureReplayEXT);
    e_vk_BufferCreateFlagBits.value("DEVICE_ADDRESS_CAPTURE_REPLAY_KHR", ::vk::BufferCreateFlagBits::eDeviceAddressCaptureReplayKHR);
    e_vk_BufferCreateFlagBits.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", ::vk::BufferCreateFlagBits::eDescriptorBufferCaptureReplayEXT);
    e_vk_BufferCreateFlagBits.value("VIDEO_PROFILE_INDEPENDENT_KHR", ::vk::BufferCreateFlagBits::eVideoProfileIndependentKHR);

    e_vk_BufferUsageFlagBits.value("TRANSFER_SRC", ::vk::BufferUsageFlagBits::eTransferSrc);
    e_vk_BufferUsageFlagBits.value("TRANSFER_DST", ::vk::BufferUsageFlagBits::eTransferDst);
    e_vk_BufferUsageFlagBits.value("UNIFORM_TEXEL_BUFFER", ::vk::BufferUsageFlagBits::eUniformTexelBuffer);
    e_vk_BufferUsageFlagBits.value("STORAGE_TEXEL_BUFFER", ::vk::BufferUsageFlagBits::eStorageTexelBuffer);
    e_vk_BufferUsageFlagBits.value("UNIFORM_BUFFER", ::vk::BufferUsageFlagBits::eUniformBuffer);
    e_vk_BufferUsageFlagBits.value("STORAGE_BUFFER", ::vk::BufferUsageFlagBits::eStorageBuffer);
    e_vk_BufferUsageFlagBits.value("INDEX_BUFFER", ::vk::BufferUsageFlagBits::eIndexBuffer);
    e_vk_BufferUsageFlagBits.value("VERTEX_BUFFER", ::vk::BufferUsageFlagBits::eVertexBuffer);
    e_vk_BufferUsageFlagBits.value("INDIRECT_BUFFER", ::vk::BufferUsageFlagBits::eIndirectBuffer);
    e_vk_BufferUsageFlagBits.value("SHADER_DEVICE_ADDRESS", ::vk::BufferUsageFlagBits::eShaderDeviceAddress);
    e_vk_BufferUsageFlagBits.value("VIDEO_DECODE_SRC_KHR", ::vk::BufferUsageFlagBits::eVideoDecodeSrcKHR);
    e_vk_BufferUsageFlagBits.value("VIDEO_DECODE_DST_KHR", ::vk::BufferUsageFlagBits::eVideoDecodeDstKHR);
    e_vk_BufferUsageFlagBits.value("TRANSFORM_FEEDBACK_BUFFER_EXT", ::vk::BufferUsageFlagBits::eTransformFeedbackBufferEXT);
    e_vk_BufferUsageFlagBits.value("TRANSFORM_FEEDBACK_COUNTER_BUFFER_EXT", ::vk::BufferUsageFlagBits::eTransformFeedbackCounterBufferEXT);
    e_vk_BufferUsageFlagBits.value("CONDITIONAL_RENDERING_EXT", ::vk::BufferUsageFlagBits::eConditionalRenderingEXT);
    e_vk_BufferUsageFlagBits.value("ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_KHR", ::vk::BufferUsageFlagBits::eAccelerationStructureBuildInputReadOnlyKHR);
    e_vk_BufferUsageFlagBits.value("ACCELERATION_STRUCTURE_STORAGE_KHR", ::vk::BufferUsageFlagBits::eAccelerationStructureStorageKHR);
    e_vk_BufferUsageFlagBits.value("SHADER_BINDING_TABLE_KHR", ::vk::BufferUsageFlagBits::eShaderBindingTableKHR);
    e_vk_BufferUsageFlagBits.value("RAY_TRACING_NV", ::vk::BufferUsageFlagBits::eRayTracingNV);
    e_vk_BufferUsageFlagBits.value("SHADER_DEVICE_ADDRESS_EXT", ::vk::BufferUsageFlagBits::eShaderDeviceAddressEXT);
    e_vk_BufferUsageFlagBits.value("SHADER_DEVICE_ADDRESS_KHR", ::vk::BufferUsageFlagBits::eShaderDeviceAddressKHR);
    e_vk_BufferUsageFlagBits.value("VIDEO_ENCODE_DST_KHR", ::vk::BufferUsageFlagBits::eVideoEncodeDstKHR);
    e_vk_BufferUsageFlagBits.value("VIDEO_ENCODE_SRC_KHR", ::vk::BufferUsageFlagBits::eVideoEncodeSrcKHR);
    e_vk_BufferUsageFlagBits.value("SAMPLER_DESCRIPTOR_BUFFER_EXT", ::vk::BufferUsageFlagBits::eSamplerDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits.value("RESOURCE_DESCRIPTOR_BUFFER_EXT", ::vk::BufferUsageFlagBits::eResourceDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits.value("PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_EXT", ::vk::BufferUsageFlagBits::ePushDescriptorsDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits.value("MICROMAP_BUILD_INPUT_READ_ONLY_EXT", ::vk::BufferUsageFlagBits::eMicromapBuildInputReadOnlyEXT);
    e_vk_BufferUsageFlagBits.value("MICROMAP_STORAGE_EXT", ::vk::BufferUsageFlagBits::eMicromapStorageEXT);


    e_vk_ColorComponentFlagBits.value("eR", ::vk::ColorComponentFlagBits::eR);
    e_vk_ColorComponentFlagBits.value("eG", ::vk::ColorComponentFlagBits::eG);
    e_vk_ColorComponentFlagBits.value("eB", ::vk::ColorComponentFlagBits::eB);
    e_vk_ColorComponentFlagBits.value("eA", ::vk::ColorComponentFlagBits::eA);

    e_vk_CommandBufferLevel.value("PRIMARY", ::vk::CommandBufferLevel::ePrimary);
    e_vk_CommandBufferLevel.value("SECONDARY", ::vk::CommandBufferLevel::eSecondary);

    e_vk_CommandBufferResetFlagBits.value("RELEASE_RESOURCES", ::vk::CommandBufferResetFlagBits::eReleaseResources);

    e_vk_CommandBufferUsageFlagBits.value("ONE_TIME_SUBMIT", ::vk::CommandBufferUsageFlagBits::eOneTimeSubmit);
    e_vk_CommandBufferUsageFlagBits.value("RENDER_PASS_CONTINUE", ::vk::CommandBufferUsageFlagBits::eRenderPassContinue);
    e_vk_CommandBufferUsageFlagBits.value("SIMULTANEOUS_USE", ::vk::CommandBufferUsageFlagBits::eSimultaneousUse);

    e_vk_CommandPoolCreateFlagBits.value("TRANSIENT", ::vk::CommandPoolCreateFlagBits::eTransient);
    e_vk_CommandPoolCreateFlagBits.value("RESET_COMMAND_BUFFER", ::vk::CommandPoolCreateFlagBits::eResetCommandBuffer);
    e_vk_CommandPoolCreateFlagBits.value("PROTECTED", ::vk::CommandPoolCreateFlagBits::eProtected);

    e_vk_CommandPoolResetFlagBits.value("RELEASE_RESOURCES", ::vk::CommandPoolResetFlagBits::eReleaseResources);

    e_vk_CompareOp.value("NEVER", ::vk::CompareOp::eNever);
    e_vk_CompareOp.value("LESS", ::vk::CompareOp::eLess);
    e_vk_CompareOp.value("EQUAL", ::vk::CompareOp::eEqual);
    e_vk_CompareOp.value("LESS_OR_EQUAL", ::vk::CompareOp::eLessOrEqual);
    e_vk_CompareOp.value("GREATER", ::vk::CompareOp::eGreater);
    e_vk_CompareOp.value("NOT_EQUAL", ::vk::CompareOp::eNotEqual);
    e_vk_CompareOp.value("GREATER_OR_EQUAL", ::vk::CompareOp::eGreaterOrEqual);
    e_vk_CompareOp.value("ALWAYS", ::vk::CompareOp::eAlways);

    e_vk_ComponentSwizzle.value("IDENTITY", ::vk::ComponentSwizzle::eIdentity);
    e_vk_ComponentSwizzle.value("ZERO", ::vk::ComponentSwizzle::eZero);
    e_vk_ComponentSwizzle.value("ONE", ::vk::ComponentSwizzle::eOne);
    e_vk_ComponentSwizzle.value("eR", ::vk::ComponentSwizzle::eR);
    e_vk_ComponentSwizzle.value("eG", ::vk::ComponentSwizzle::eG);
    e_vk_ComponentSwizzle.value("eB", ::vk::ComponentSwizzle::eB);
    e_vk_ComponentSwizzle.value("eA", ::vk::ComponentSwizzle::eA);

    e_vk_CullModeFlagBits.value("NONE", ::vk::CullModeFlagBits::eNone);
    e_vk_CullModeFlagBits.value("FRONT", ::vk::CullModeFlagBits::eFront);
    e_vk_CullModeFlagBits.value("BACK", ::vk::CullModeFlagBits::eBack);
    e_vk_CullModeFlagBits.value("FRONT_AND_BACK", ::vk::CullModeFlagBits::eFrontAndBack);

    e_vk_DependencyFlagBits.value("BY_REGION", ::vk::DependencyFlagBits::eByRegion);
    e_vk_DependencyFlagBits.value("DEVICE_GROUP", ::vk::DependencyFlagBits::eDeviceGroup);
    e_vk_DependencyFlagBits.value("VIEW_LOCAL", ::vk::DependencyFlagBits::eViewLocal);
    e_vk_DependencyFlagBits.value("VIEW_LOCAL_KHR", ::vk::DependencyFlagBits::eViewLocalKHR);
    e_vk_DependencyFlagBits.value("DEVICE_GROUP_KHR", ::vk::DependencyFlagBits::eDeviceGroupKHR);
    e_vk_DependencyFlagBits.value("FEEDBACK_LOOP_EXT", ::vk::DependencyFlagBits::eFeedbackLoopEXT);

    e_vk_DescriptorPoolCreateFlagBits.value("FREE_DESCRIPTOR_SET", ::vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet);
    e_vk_DescriptorPoolCreateFlagBits.value("UPDATE_AFTER_BIND", ::vk::DescriptorPoolCreateFlagBits::eUpdateAfterBind);
    e_vk_DescriptorPoolCreateFlagBits.value("UPDATE_AFTER_BIND_EXT", ::vk::DescriptorPoolCreateFlagBits::eUpdateAfterBindEXT);
    e_vk_DescriptorPoolCreateFlagBits.value("HOST_ONLY_VALVE", ::vk::DescriptorPoolCreateFlagBits::eHostOnlyVALVE);
    e_vk_DescriptorPoolCreateFlagBits.value("HOST_ONLY_EXT", ::vk::DescriptorPoolCreateFlagBits::eHostOnlyEXT);
    e_vk_DescriptorPoolCreateFlagBits.value("ALLOW_OVERALLOCATION_SETS_NV", ::vk::DescriptorPoolCreateFlagBits::eAllowOverallocationSetsNV);
    e_vk_DescriptorPoolCreateFlagBits.value("ALLOW_OVERALLOCATION_POOLS_NV", ::vk::DescriptorPoolCreateFlagBits::eAllowOverallocationPoolsNV);


    e_vk_DescriptorSetLayoutCreateFlagBits.value("UPDATE_AFTER_BIND_POOL", ::vk::DescriptorSetLayoutCreateFlagBits::eUpdateAfterBindPool);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("PUSH_DESCRIPTOR_KHR", ::vk::DescriptorSetLayoutCreateFlagBits::ePushDescriptorKHR);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("UPDATE_AFTER_BIND_POOL_EXT", ::vk::DescriptorSetLayoutCreateFlagBits::eUpdateAfterBindPoolEXT);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("DESCRIPTOR_BUFFER_EXT", ::vk::DescriptorSetLayoutCreateFlagBits::eDescriptorBufferEXT);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("EMBEDDED_IMMUTABLE_SAMPLERS_EXT", ::vk::DescriptorSetLayoutCreateFlagBits::eEmbeddedImmutableSamplersEXT);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("HOST_ONLY_POOL_VALVE", ::vk::DescriptorSetLayoutCreateFlagBits::eHostOnlyPoolVALVE);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("INDIRECT_BINDABLE_NV", ::vk::DescriptorSetLayoutCreateFlagBits::eIndirectBindableNV);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("HOST_ONLY_POOL_EXT", ::vk::DescriptorSetLayoutCreateFlagBits::eHostOnlyPoolEXT);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("PER_STAGE_NV", ::vk::DescriptorSetLayoutCreateFlagBits::ePerStageNV);

    e_vk_DescriptorType.value("SAMPLER", ::vk::DescriptorType::eSampler);
    e_vk_DescriptorType.value("COMBINED_IMAGE_SAMPLER", ::vk::DescriptorType::eCombinedImageSampler);
    e_vk_DescriptorType.value("SAMPLED_IMAGE", ::vk::DescriptorType::eSampledImage);
    e_vk_DescriptorType.value("STORAGE_IMAGE", ::vk::DescriptorType::eStorageImage);
    e_vk_DescriptorType.value("UNIFORM_TEXEL_BUFFER", ::vk::DescriptorType::eUniformTexelBuffer);
    e_vk_DescriptorType.value("STORAGE_TEXEL_BUFFER", ::vk::DescriptorType::eStorageTexelBuffer);
    e_vk_DescriptorType.value("UNIFORM_BUFFER", ::vk::DescriptorType::eUniformBuffer);
    e_vk_DescriptorType.value("STORAGE_BUFFER", ::vk::DescriptorType::eStorageBuffer);
    e_vk_DescriptorType.value("UNIFORM_BUFFER_DYNAMIC", ::vk::DescriptorType::eUniformBufferDynamic);
    e_vk_DescriptorType.value("STORAGE_BUFFER_DYNAMIC", ::vk::DescriptorType::eStorageBufferDynamic);
    e_vk_DescriptorType.value("INPUT_ATTACHMENT", ::vk::DescriptorType::eInputAttachment);
    e_vk_DescriptorType.value("INLINE_UNIFORM_BLOCK", ::vk::DescriptorType::eInlineUniformBlock);
    e_vk_DescriptorType.value("INLINE_UNIFORM_BLOCK_EXT", ::vk::DescriptorType::eInlineUniformBlockEXT);
    e_vk_DescriptorType.value("ACCELERATION_STRUCTURE_KHR", ::vk::DescriptorType::eAccelerationStructureKHR);
    e_vk_DescriptorType.value("ACCELERATION_STRUCTURE_NV", ::vk::DescriptorType::eAccelerationStructureNV);
    e_vk_DescriptorType.value("MUTABLE_VALVE", ::vk::DescriptorType::eMutableVALVE);
    e_vk_DescriptorType.value("SAMPLE_WEIGHT_IMAGE_QCOM", ::vk::DescriptorType::eSampleWeightImageQCOM);
    e_vk_DescriptorType.value("BLOCK_MATCH_IMAGE_QCOM", ::vk::DescriptorType::eBlockMatchImageQCOM);
    e_vk_DescriptorType.value("MUTABLE_EXT", ::vk::DescriptorType::eMutableEXT);


    e_vk_DeviceQueueCreateFlagBits.value("PROTECTED", ::vk::DeviceQueueCreateFlagBits::eProtected);

    e_vk_DynamicState.value("VIEWPORT", ::vk::DynamicState::eViewport);
    e_vk_DynamicState.value("SCISSOR", ::vk::DynamicState::eScissor);
    e_vk_DynamicState.value("LINE_WIDTH", ::vk::DynamicState::eLineWidth);
    e_vk_DynamicState.value("DEPTH_BIAS", ::vk::DynamicState::eDepthBias);
    e_vk_DynamicState.value("BLEND_CONSTANTS", ::vk::DynamicState::eBlendConstants);
    e_vk_DynamicState.value("DEPTH_BOUNDS", ::vk::DynamicState::eDepthBounds);
    e_vk_DynamicState.value("STENCIL_COMPARE_MASK", ::vk::DynamicState::eStencilCompareMask);
    e_vk_DynamicState.value("STENCIL_WRITE_MASK", ::vk::DynamicState::eStencilWriteMask);
    e_vk_DynamicState.value("STENCIL_REFERENCE", ::vk::DynamicState::eStencilReference);
    e_vk_DynamicState.value("CULL_MODE", ::vk::DynamicState::eCullMode);
    e_vk_DynamicState.value("FRONT_FACE", ::vk::DynamicState::eFrontFace);
    e_vk_DynamicState.value("PRIMITIVE_TOPOLOGY", ::vk::DynamicState::ePrimitiveTopology);
    e_vk_DynamicState.value("VIEWPORT_WITH_COUNT", ::vk::DynamicState::eViewportWithCount);
    e_vk_DynamicState.value("SCISSOR_WITH_COUNT", ::vk::DynamicState::eScissorWithCount);
    e_vk_DynamicState.value("VERTEX_INPUT_BINDING_STRIDE", ::vk::DynamicState::eVertexInputBindingStride);
    e_vk_DynamicState.value("DEPTH_TEST_ENABLE", ::vk::DynamicState::eDepthTestEnable);
    e_vk_DynamicState.value("DEPTH_WRITE_ENABLE", ::vk::DynamicState::eDepthWriteEnable);
    e_vk_DynamicState.value("DEPTH_COMPARE_OP", ::vk::DynamicState::eDepthCompareOp);
    e_vk_DynamicState.value("DEPTH_BOUNDS_TEST_ENABLE", ::vk::DynamicState::eDepthBoundsTestEnable);
    e_vk_DynamicState.value("STENCIL_TEST_ENABLE", ::vk::DynamicState::eStencilTestEnable);
    e_vk_DynamicState.value("STENCIL_OP", ::vk::DynamicState::eStencilOp);
    e_vk_DynamicState.value("RASTERIZER_DISCARD_ENABLE", ::vk::DynamicState::eRasterizerDiscardEnable);
    e_vk_DynamicState.value("DEPTH_BIAS_ENABLE", ::vk::DynamicState::eDepthBiasEnable);
    e_vk_DynamicState.value("PRIMITIVE_RESTART_ENABLE", ::vk::DynamicState::ePrimitiveRestartEnable);
    e_vk_DynamicState.value("VIEWPORT_W_SCALING_NV", ::vk::DynamicState::eViewportWScalingNV);
    e_vk_DynamicState.value("DISCARD_RECTANGLE_EXT", ::vk::DynamicState::eDiscardRectangleEXT);
    e_vk_DynamicState.value("DISCARD_RECTANGLE_ENABLE_EXT", ::vk::DynamicState::eDiscardRectangleEnableEXT);
    e_vk_DynamicState.value("DISCARD_RECTANGLE_MODE_EXT", ::vk::DynamicState::eDiscardRectangleModeEXT);
    e_vk_DynamicState.value("SAMPLE_LOCATIONS_EXT", ::vk::DynamicState::eSampleLocationsEXT);
    e_vk_DynamicState.value("RAY_TRACING_PIPELINE_STACK_SIZE_KHR", ::vk::DynamicState::eRayTracingPipelineStackSizeKHR);
    e_vk_DynamicState.value("VIEWPORT_SHADING_RATE_PALETTE_NV", ::vk::DynamicState::eViewportShadingRatePaletteNV);
    e_vk_DynamicState.value("VIEWPORT_COARSE_SAMPLE_ORDER_NV", ::vk::DynamicState::eViewportCoarseSampleOrderNV);
    e_vk_DynamicState.value("EXCLUSIVE_SCISSOR_ENABLE_NV", ::vk::DynamicState::eExclusiveScissorEnableNV);
    e_vk_DynamicState.value("EXCLUSIVE_SCISSOR_NV", ::vk::DynamicState::eExclusiveScissorNV);
    e_vk_DynamicState.value("FRAGMENT_SHADING_RATE_KHR", ::vk::DynamicState::eFragmentShadingRateKHR);
    e_vk_DynamicState.value("LINE_STIPPLE_EXT", ::vk::DynamicState::eLineStippleEXT);
    e_vk_DynamicState.value("CULL_MODE_EXT", ::vk::DynamicState::eCullModeEXT);
    e_vk_DynamicState.value("FRONT_FACE_EXT", ::vk::DynamicState::eFrontFaceEXT);
    e_vk_DynamicState.value("PRIMITIVE_TOPOLOGY_EXT", ::vk::DynamicState::ePrimitiveTopologyEXT);
    e_vk_DynamicState.value("VIEWPORT_WITH_COUNT_EXT", ::vk::DynamicState::eViewportWithCountEXT);
    e_vk_DynamicState.value("SCISSOR_WITH_COUNT_EXT", ::vk::DynamicState::eScissorWithCountEXT);
    e_vk_DynamicState.value("VERTEX_INPUT_BINDING_STRIDE_EXT", ::vk::DynamicState::eVertexInputBindingStrideEXT);
    e_vk_DynamicState.value("DEPTH_TEST_ENABLE_EXT", ::vk::DynamicState::eDepthTestEnableEXT);
    e_vk_DynamicState.value("DEPTH_WRITE_ENABLE_EXT", ::vk::DynamicState::eDepthWriteEnableEXT);
    e_vk_DynamicState.value("DEPTH_COMPARE_OP_EXT", ::vk::DynamicState::eDepthCompareOpEXT);
    e_vk_DynamicState.value("DEPTH_BOUNDS_TEST_ENABLE_EXT", ::vk::DynamicState::eDepthBoundsTestEnableEXT);
    e_vk_DynamicState.value("STENCIL_TEST_ENABLE_EXT", ::vk::DynamicState::eStencilTestEnableEXT);
    e_vk_DynamicState.value("STENCIL_OP_EXT", ::vk::DynamicState::eStencilOpEXT);
    e_vk_DynamicState.value("VERTEX_INPUT_EXT", ::vk::DynamicState::eVertexInputEXT);
    e_vk_DynamicState.value("PATCH_CONTROL_POINTS_EXT", ::vk::DynamicState::ePatchControlPointsEXT);
    e_vk_DynamicState.value("RASTERIZER_DISCARD_ENABLE_EXT", ::vk::DynamicState::eRasterizerDiscardEnableEXT);
    e_vk_DynamicState.value("DEPTH_BIAS_ENABLE_EXT", ::vk::DynamicState::eDepthBiasEnableEXT);
    e_vk_DynamicState.value("LOGIC_OP_EXT", ::vk::DynamicState::eLogicOpEXT);
    e_vk_DynamicState.value("PRIMITIVE_RESTART_ENABLE_EXT", ::vk::DynamicState::ePrimitiveRestartEnableEXT);
    e_vk_DynamicState.value("COLOR_WRITE_ENABLE_EXT", ::vk::DynamicState::eColorWriteEnableEXT);
    e_vk_DynamicState.value("TESSELLATION_DOMAIN_ORIGIN_EXT", ::vk::DynamicState::eTessellationDomainOriginEXT);
    e_vk_DynamicState.value("DEPTH_CLAMP_ENABLE_EXT", ::vk::DynamicState::eDepthClampEnableEXT);
    e_vk_DynamicState.value("POLYGON_MODE_EXT", ::vk::DynamicState::ePolygonModeEXT);
    e_vk_DynamicState.value("RASTERIZATION_SAMPLES_EXT", ::vk::DynamicState::eRasterizationSamplesEXT);
    e_vk_DynamicState.value("SAMPLE_MASK_EXT", ::vk::DynamicState::eSampleMaskEXT);
    e_vk_DynamicState.value("ALPHA_TO_COVERAGE_ENABLE_EXT", ::vk::DynamicState::eAlphaToCoverageEnableEXT);
    e_vk_DynamicState.value("ALPHA_TO_ONE_ENABLE_EXT", ::vk::DynamicState::eAlphaToOneEnableEXT);
    e_vk_DynamicState.value("LOGIC_OP_ENABLE_EXT", ::vk::DynamicState::eLogicOpEnableEXT);
    e_vk_DynamicState.value("COLOR_BLEND_ENABLE_EXT", ::vk::DynamicState::eColorBlendEnableEXT);
    e_vk_DynamicState.value("COLOR_BLEND_EQUATION_EXT", ::vk::DynamicState::eColorBlendEquationEXT);
    e_vk_DynamicState.value("COLOR_WRITE_MASK_EXT", ::vk::DynamicState::eColorWriteMaskEXT);
    e_vk_DynamicState.value("RASTERIZATION_STREAM_EXT", ::vk::DynamicState::eRasterizationStreamEXT);
    e_vk_DynamicState.value("CONSERVATIVE_RASTERIZATION_MODE_EXT", ::vk::DynamicState::eConservativeRasterizationModeEXT);
    e_vk_DynamicState.value("EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT", ::vk::DynamicState::eExtraPrimitiveOverestimationSizeEXT);
    e_vk_DynamicState.value("DEPTH_CLIP_ENABLE_EXT", ::vk::DynamicState::eDepthClipEnableEXT);
    e_vk_DynamicState.value("SAMPLE_LOCATIONS_ENABLE_EXT", ::vk::DynamicState::eSampleLocationsEnableEXT);
    e_vk_DynamicState.value("COLOR_BLEND_ADVANCED_EXT", ::vk::DynamicState::eColorBlendAdvancedEXT);
    e_vk_DynamicState.value("PROVOKING_VERTEX_MODE_EXT", ::vk::DynamicState::eProvokingVertexModeEXT);
    e_vk_DynamicState.value("LINE_RASTERIZATION_MODE_EXT", ::vk::DynamicState::eLineRasterizationModeEXT);
    e_vk_DynamicState.value("LINE_STIPPLE_ENABLE_EXT", ::vk::DynamicState::eLineStippleEnableEXT);
    e_vk_DynamicState.value("DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT", ::vk::DynamicState::eDepthClipNegativeOneToOneEXT);
    e_vk_DynamicState.value("VIEWPORT_W_SCALING_ENABLE_NV", ::vk::DynamicState::eViewportWScalingEnableNV);
    e_vk_DynamicState.value("VIEWPORT_SWIZZLE_NV", ::vk::DynamicState::eViewportSwizzleNV);
    e_vk_DynamicState.value("COVERAGE_TO_COLOR_ENABLE_NV", ::vk::DynamicState::eCoverageToColorEnableNV);
    e_vk_DynamicState.value("COVERAGE_TO_COLOR_LOCATION_NV", ::vk::DynamicState::eCoverageToColorLocationNV);
    e_vk_DynamicState.value("COVERAGE_MODULATION_MODE_NV", ::vk::DynamicState::eCoverageModulationModeNV);
    e_vk_DynamicState.value("COVERAGE_MODULATION_TABLE_ENABLE_NV", ::vk::DynamicState::eCoverageModulationTableEnableNV);
    e_vk_DynamicState.value("COVERAGE_MODULATION_TABLE_NV", ::vk::DynamicState::eCoverageModulationTableNV);
    e_vk_DynamicState.value("SHADING_RATE_IMAGE_ENABLE_NV", ::vk::DynamicState::eShadingRateImageEnableNV);
    e_vk_DynamicState.value("REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV", ::vk::DynamicState::eRepresentativeFragmentTestEnableNV);
    e_vk_DynamicState.value("COVERAGE_REDUCTION_MODE_NV", ::vk::DynamicState::eCoverageReductionModeNV);
    e_vk_DynamicState.value("ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT", ::vk::DynamicState::eAttachmentFeedbackLoopEnableEXT);

    e_vk_EventCreateFlagBits.value("DEVICE_ONLY", ::vk::EventCreateFlagBits::eDeviceOnly);
    e_vk_EventCreateFlagBits.value("DEVICE_ONLY_KHR", ::vk::EventCreateFlagBits::eDeviceOnlyKHR);

    e_vk_FenceCreateFlagBits.value("SIGNALED", ::vk::FenceCreateFlagBits::eSignaled);

    e_vk_Filter.value("NEAREST", ::vk::Filter::eNearest);
    e_vk_Filter.value("LINEAR", ::vk::Filter::eLinear);
    e_vk_Filter.value("CUBIC_IMG", ::vk::Filter::eCubicIMG);
    e_vk_Filter.value("CUBIC_EXT", ::vk::Filter::eCubicEXT);

    e_vk_Format.value("UNDEFINED", ::vk::Format::eUndefined);
    e_vk_Format.value("eR4G4_UNORM_PACK_8", ::vk::Format::eR4G4UnormPack8);
    e_vk_Format.value("eR4G4B4A4_UNORM_PACK_16", ::vk::Format::eR4G4B4A4UnormPack16);
    e_vk_Format.value("eB4G4R4A4_UNORM_PACK_16", ::vk::Format::eB4G4R4A4UnormPack16);
    e_vk_Format.value("eR5G6B5_UNORM_PACK_16", ::vk::Format::eR5G6B5UnormPack16);
    e_vk_Format.value("eB5G6R5_UNORM_PACK_16", ::vk::Format::eB5G6R5UnormPack16);
    e_vk_Format.value("eR5G5B5A1_UNORM_PACK_16", ::vk::Format::eR5G5B5A1UnormPack16);
    e_vk_Format.value("eB5G5R5A1_UNORM_PACK_16", ::vk::Format::eB5G5R5A1UnormPack16);
    e_vk_Format.value("eA1R5G5B5_UNORM_PACK_16", ::vk::Format::eA1R5G5B5UnormPack16);
    e_vk_Format.value("eR8_UNORM", ::vk::Format::eR8Unorm);
    e_vk_Format.value("eR8_SNORM", ::vk::Format::eR8Snorm);
    e_vk_Format.value("eR8_USCALED", ::vk::Format::eR8Uscaled);
    e_vk_Format.value("eR8_SSCALED", ::vk::Format::eR8Sscaled);
    e_vk_Format.value("eR8_UINT", ::vk::Format::eR8Uint);
    e_vk_Format.value("eR8_SINT", ::vk::Format::eR8Sint);
    e_vk_Format.value("eR8_SRGB", ::vk::Format::eR8Srgb);
    e_vk_Format.value("eR8G8_UNORM", ::vk::Format::eR8G8Unorm);
    e_vk_Format.value("eR8G8_SNORM", ::vk::Format::eR8G8Snorm);
    e_vk_Format.value("eR8G8_USCALED", ::vk::Format::eR8G8Uscaled);
    e_vk_Format.value("eR8G8_SSCALED", ::vk::Format::eR8G8Sscaled);
    e_vk_Format.value("eR8G8_UINT", ::vk::Format::eR8G8Uint);
    e_vk_Format.value("eR8G8_SINT", ::vk::Format::eR8G8Sint);
    e_vk_Format.value("eR8G8_SRGB", ::vk::Format::eR8G8Srgb);
    e_vk_Format.value("eR8G8B8_UNORM", ::vk::Format::eR8G8B8Unorm);
    e_vk_Format.value("eR8G8B8_SNORM", ::vk::Format::eR8G8B8Snorm);
    e_vk_Format.value("eR8G8B8_USCALED", ::vk::Format::eR8G8B8Uscaled);
    e_vk_Format.value("eR8G8B8_SSCALED", ::vk::Format::eR8G8B8Sscaled);
    e_vk_Format.value("eR8G8B8_UINT", ::vk::Format::eR8G8B8Uint);
    e_vk_Format.value("eR8G8B8_SINT", ::vk::Format::eR8G8B8Sint);
    e_vk_Format.value("eR8G8B8_SRGB", ::vk::Format::eR8G8B8Srgb);
    e_vk_Format.value("eB8G8R8_UNORM", ::vk::Format::eB8G8R8Unorm);
    e_vk_Format.value("eB8G8R8_SNORM", ::vk::Format::eB8G8R8Snorm);
    e_vk_Format.value("eB8G8R8_USCALED", ::vk::Format::eB8G8R8Uscaled);
    e_vk_Format.value("eB8G8R8_SSCALED", ::vk::Format::eB8G8R8Sscaled);
    e_vk_Format.value("eB8G8R8_UINT", ::vk::Format::eB8G8R8Uint);
    e_vk_Format.value("eB8G8R8_SINT", ::vk::Format::eB8G8R8Sint);
    e_vk_Format.value("eB8G8R8_SRGB", ::vk::Format::eB8G8R8Srgb);
    e_vk_Format.value("eR8G8B8A8_UNORM", ::vk::Format::eR8G8B8A8Unorm);
    e_vk_Format.value("eR8G8B8A8_SNORM", ::vk::Format::eR8G8B8A8Snorm);
    e_vk_Format.value("eR8G8B8A8_USCALED", ::vk::Format::eR8G8B8A8Uscaled);
    e_vk_Format.value("eR8G8B8A8_SSCALED", ::vk::Format::eR8G8B8A8Sscaled);
    e_vk_Format.value("eR8G8B8A8_UINT", ::vk::Format::eR8G8B8A8Uint);
    e_vk_Format.value("eR8G8B8A8_SINT", ::vk::Format::eR8G8B8A8Sint);
    e_vk_Format.value("eR8G8B8A8_SRGB", ::vk::Format::eR8G8B8A8Srgb);
    e_vk_Format.value("eB8G8R8A8_UNORM", ::vk::Format::eB8G8R8A8Unorm);
    e_vk_Format.value("eB8G8R8A8_SNORM", ::vk::Format::eB8G8R8A8Snorm);
    e_vk_Format.value("eB8G8R8A8_USCALED", ::vk::Format::eB8G8R8A8Uscaled);
    e_vk_Format.value("eB8G8R8A8_SSCALED", ::vk::Format::eB8G8R8A8Sscaled);
    e_vk_Format.value("eB8G8R8A8_UINT", ::vk::Format::eB8G8R8A8Uint);
    e_vk_Format.value("eB8G8R8A8_SINT", ::vk::Format::eB8G8R8A8Sint);
    e_vk_Format.value("eB8G8R8A8_SRGB", ::vk::Format::eB8G8R8A8Srgb);
    e_vk_Format.value("eA8B8G8R8_UNORM_PACK_32", ::vk::Format::eA8B8G8R8UnormPack32);
    e_vk_Format.value("eA8B8G8R8_SNORM_PACK_32", ::vk::Format::eA8B8G8R8SnormPack32);
    e_vk_Format.value("eA8B8G8R8_USCALED_PACK_32", ::vk::Format::eA8B8G8R8UscaledPack32);
    e_vk_Format.value("eA8B8G8R8_SSCALED_PACK_32", ::vk::Format::eA8B8G8R8SscaledPack32);
    e_vk_Format.value("eA8B8G8R8_UINT_PACK_32", ::vk::Format::eA8B8G8R8UintPack32);
    e_vk_Format.value("eA8B8G8R8_SINT_PACK_32", ::vk::Format::eA8B8G8R8SintPack32);
    e_vk_Format.value("eA8B8G8R8_SRGB_PACK_32", ::vk::Format::eA8B8G8R8SrgbPack32);
    e_vk_Format.value("eA2R10G10B10_UNORM_PACK_32", ::vk::Format::eA2R10G10B10UnormPack32);
    e_vk_Format.value("eA2R10G10B10_SNORM_PACK_32", ::vk::Format::eA2R10G10B10SnormPack32);
    e_vk_Format.value("eA2R10G10B10_USCALED_PACK_32", ::vk::Format::eA2R10G10B10UscaledPack32);
    e_vk_Format.value("eA2R10G10B10_SSCALED_PACK_32", ::vk::Format::eA2R10G10B10SscaledPack32);
    e_vk_Format.value("eA2R10G10B10_UINT_PACK_32", ::vk::Format::eA2R10G10B10UintPack32);
    e_vk_Format.value("eA2R10G10B10_SINT_PACK_32", ::vk::Format::eA2R10G10B10SintPack32);
    e_vk_Format.value("eA2B10G10R10_UNORM_PACK_32", ::vk::Format::eA2B10G10R10UnormPack32);
    e_vk_Format.value("eA2B10G10R10_SNORM_PACK_32", ::vk::Format::eA2B10G10R10SnormPack32);
    e_vk_Format.value("eA2B10G10R10_USCALED_PACK_32", ::vk::Format::eA2B10G10R10UscaledPack32);
    e_vk_Format.value("eA2B10G10R10_SSCALED_PACK_32", ::vk::Format::eA2B10G10R10SscaledPack32);
    e_vk_Format.value("eA2B10G10R10_UINT_PACK_32", ::vk::Format::eA2B10G10R10UintPack32);
    e_vk_Format.value("eA2B10G10R10_SINT_PACK_32", ::vk::Format::eA2B10G10R10SintPack32);
    e_vk_Format.value("eR16_UNORM", ::vk::Format::eR16Unorm);
    e_vk_Format.value("eR16_SNORM", ::vk::Format::eR16Snorm);
    e_vk_Format.value("eR16_USCALED", ::vk::Format::eR16Uscaled);
    e_vk_Format.value("eR16_SSCALED", ::vk::Format::eR16Sscaled);
    e_vk_Format.value("eR16_UINT", ::vk::Format::eR16Uint);
    e_vk_Format.value("eR16_SINT", ::vk::Format::eR16Sint);
    e_vk_Format.value("eR16_SFLOAT", ::vk::Format::eR16Sfloat);
    e_vk_Format.value("eR16G16_UNORM", ::vk::Format::eR16G16Unorm);
    e_vk_Format.value("eR16G16_SNORM", ::vk::Format::eR16G16Snorm);
    e_vk_Format.value("eR16G16_USCALED", ::vk::Format::eR16G16Uscaled);
    e_vk_Format.value("eR16G16_SSCALED", ::vk::Format::eR16G16Sscaled);
    e_vk_Format.value("eR16G16_UINT", ::vk::Format::eR16G16Uint);
    e_vk_Format.value("eR16G16_SINT", ::vk::Format::eR16G16Sint);
    e_vk_Format.value("eR16G16_SFLOAT", ::vk::Format::eR16G16Sfloat);
    e_vk_Format.value("eR16G16B16_UNORM", ::vk::Format::eR16G16B16Unorm);
    e_vk_Format.value("eR16G16B16_SNORM", ::vk::Format::eR16G16B16Snorm);
    e_vk_Format.value("eR16G16B16_USCALED", ::vk::Format::eR16G16B16Uscaled);
    e_vk_Format.value("eR16G16B16_SSCALED", ::vk::Format::eR16G16B16Sscaled);
    e_vk_Format.value("eR16G16B16_UINT", ::vk::Format::eR16G16B16Uint);
    e_vk_Format.value("eR16G16B16_SINT", ::vk::Format::eR16G16B16Sint);
    e_vk_Format.value("eR16G16B16_SFLOAT", ::vk::Format::eR16G16B16Sfloat);
    e_vk_Format.value("eR16G16B16A16_UNORM", ::vk::Format::eR16G16B16A16Unorm);
    e_vk_Format.value("eR16G16B16A16_SNORM", ::vk::Format::eR16G16B16A16Snorm);
    e_vk_Format.value("eR16G16B16A16_USCALED", ::vk::Format::eR16G16B16A16Uscaled);
    e_vk_Format.value("eR16G16B16A16_SSCALED", ::vk::Format::eR16G16B16A16Sscaled);
    e_vk_Format.value("eR16G16B16A16_UINT", ::vk::Format::eR16G16B16A16Uint);
    e_vk_Format.value("eR16G16B16A16_SINT", ::vk::Format::eR16G16B16A16Sint);
    e_vk_Format.value("eR16G16B16A16_SFLOAT", ::vk::Format::eR16G16B16A16Sfloat);
    e_vk_Format.value("eR32_UINT", ::vk::Format::eR32Uint);
    e_vk_Format.value("eR32_SINT", ::vk::Format::eR32Sint);
    e_vk_Format.value("eR32_SFLOAT", ::vk::Format::eR32Sfloat);
    e_vk_Format.value("eR32G32_UINT", ::vk::Format::eR32G32Uint);
    e_vk_Format.value("eR32G32_SINT", ::vk::Format::eR32G32Sint);
    e_vk_Format.value("eR32G32_SFLOAT", ::vk::Format::eR32G32Sfloat);
    e_vk_Format.value("eR32G32B32_UINT", ::vk::Format::eR32G32B32Uint);
    e_vk_Format.value("eR32G32B32_SINT", ::vk::Format::eR32G32B32Sint);
    e_vk_Format.value("eR32G32B32_SFLOAT", ::vk::Format::eR32G32B32Sfloat);
    e_vk_Format.value("eR32G32B32A32_UINT", ::vk::Format::eR32G32B32A32Uint);
    e_vk_Format.value("eR32G32B32A32_SINT", ::vk::Format::eR32G32B32A32Sint);
    e_vk_Format.value("eR32G32B32A32_SFLOAT", ::vk::Format::eR32G32B32A32Sfloat);
    e_vk_Format.value("eR64_UINT", ::vk::Format::eR64Uint);
    e_vk_Format.value("eR64_SINT", ::vk::Format::eR64Sint);
    e_vk_Format.value("eR64_SFLOAT", ::vk::Format::eR64Sfloat);
    e_vk_Format.value("eR64G64_UINT", ::vk::Format::eR64G64Uint);
    e_vk_Format.value("eR64G64_SINT", ::vk::Format::eR64G64Sint);
    e_vk_Format.value("eR64G64_SFLOAT", ::vk::Format::eR64G64Sfloat);
    e_vk_Format.value("eR64G64B64_UINT", ::vk::Format::eR64G64B64Uint);
    e_vk_Format.value("eR64G64B64_SINT", ::vk::Format::eR64G64B64Sint);
    e_vk_Format.value("eR64G64B64_SFLOAT", ::vk::Format::eR64G64B64Sfloat);
    e_vk_Format.value("eR64G64B64A64_UINT", ::vk::Format::eR64G64B64A64Uint);
    e_vk_Format.value("eR64G64B64A64_SINT", ::vk::Format::eR64G64B64A64Sint);
    e_vk_Format.value("eR64G64B64A64_SFLOAT", ::vk::Format::eR64G64B64A64Sfloat);
    e_vk_Format.value("eB10G11R11_UFLOAT_PACK_32", ::vk::Format::eB10G11R11UfloatPack32);
    e_vk_Format.value("eE5B9G9R9_UFLOAT_PACK_32", ::vk::Format::eE5B9G9R9UfloatPack32);
    e_vk_Format.value("eD16_UNORM", ::vk::Format::eD16Unorm);
    e_vk_Format.value("eX8D24_UNORM_PACK_32", ::vk::Format::eX8D24UnormPack32);
    e_vk_Format.value("eD32_SFLOAT", ::vk::Format::eD32Sfloat);
    e_vk_Format.value("eS8_UINT", ::vk::Format::eS8Uint);
    e_vk_Format.value("eD16_UNORM_S8_UINT", ::vk::Format::eD16UnormS8Uint);
    e_vk_Format.value("eD24_UNORM_S8_UINT", ::vk::Format::eD24UnormS8Uint);
    e_vk_Format.value("eD32_SFLOAT_S8_UINT", ::vk::Format::eD32SfloatS8Uint);
    e_vk_Format.value("BC_1_RGB_UNORM_BLOCK", ::vk::Format::eBc1RgbUnormBlock);
    e_vk_Format.value("BC_1_RGB_SRGB_BLOCK", ::vk::Format::eBc1RgbSrgbBlock);
    e_vk_Format.value("BC_1_RGBA_UNORM_BLOCK", ::vk::Format::eBc1RgbaUnormBlock);
    e_vk_Format.value("BC_1_RGBA_SRGB_BLOCK", ::vk::Format::eBc1RgbaSrgbBlock);
    e_vk_Format.value("BC_2_UNORM_BLOCK", ::vk::Format::eBc2UnormBlock);
    e_vk_Format.value("BC_2_SRGB_BLOCK", ::vk::Format::eBc2SrgbBlock);
    e_vk_Format.value("BC_3_UNORM_BLOCK", ::vk::Format::eBc3UnormBlock);
    e_vk_Format.value("BC_3_SRGB_BLOCK", ::vk::Format::eBc3SrgbBlock);
    e_vk_Format.value("BC_4_UNORM_BLOCK", ::vk::Format::eBc4UnormBlock);
    e_vk_Format.value("BC_4_SNORM_BLOCK", ::vk::Format::eBc4SnormBlock);
    e_vk_Format.value("BC_5_UNORM_BLOCK", ::vk::Format::eBc5UnormBlock);
    e_vk_Format.value("BC_5_SNORM_BLOCK", ::vk::Format::eBc5SnormBlock);
    e_vk_Format.value("BC_6H_UFLOAT_BLOCK", ::vk::Format::eBc6HUfloatBlock);
    e_vk_Format.value("BC_6H_SFLOAT_BLOCK", ::vk::Format::eBc6HSfloatBlock);
    e_vk_Format.value("BC_7_UNORM_BLOCK", ::vk::Format::eBc7UnormBlock);
    e_vk_Format.value("BC_7_SRGB_BLOCK", ::vk::Format::eBc7SrgbBlock);
    e_vk_Format.value("ETC_2R8G8B8_UNORM_BLOCK", ::vk::Format::eEtc2R8G8B8UnormBlock);
    e_vk_Format.value("ETC_2R8G8B8_SRGB_BLOCK", ::vk::Format::eEtc2R8G8B8SrgbBlock);
    e_vk_Format.value("ETC_2R8G8B8A1_UNORM_BLOCK", ::vk::Format::eEtc2R8G8B8A1UnormBlock);
    e_vk_Format.value("ETC_2R8G8B8A1_SRGB_BLOCK", ::vk::Format::eEtc2R8G8B8A1SrgbBlock);
    e_vk_Format.value("ETC_2R8G8B8A8_UNORM_BLOCK", ::vk::Format::eEtc2R8G8B8A8UnormBlock);
    e_vk_Format.value("ETC_2R8G8B8A8_SRGB_BLOCK", ::vk::Format::eEtc2R8G8B8A8SrgbBlock);
    e_vk_Format.value("EAC_R11_UNORM_BLOCK", ::vk::Format::eEacR11UnormBlock);
    e_vk_Format.value("EAC_R11_SNORM_BLOCK", ::vk::Format::eEacR11SnormBlock);
    e_vk_Format.value("EAC_R11G11_UNORM_BLOCK", ::vk::Format::eEacR11G11UnormBlock);
    e_vk_Format.value("EAC_R11G11_SNORM_BLOCK", ::vk::Format::eEacR11G11SnormBlock);
    e_vk_Format.value("ASTC_4x4_UNORM_BLOCK", ::vk::Format::eAstc4x4UnormBlock);
    e_vk_Format.value("ASTC_4x4_SRGB_BLOCK", ::vk::Format::eAstc4x4SrgbBlock);
    e_vk_Format.value("ASTC_5x4_UNORM_BLOCK", ::vk::Format::eAstc5x4UnormBlock);
    e_vk_Format.value("ASTC_5x4_SRGB_BLOCK", ::vk::Format::eAstc5x4SrgbBlock);
    e_vk_Format.value("ASTC_5x5_UNORM_BLOCK", ::vk::Format::eAstc5x5UnormBlock);
    e_vk_Format.value("ASTC_5x5_SRGB_BLOCK", ::vk::Format::eAstc5x5SrgbBlock);
    e_vk_Format.value("ASTC_6x5_UNORM_BLOCK", ::vk::Format::eAstc6x5UnormBlock);
    e_vk_Format.value("ASTC_6x5_SRGB_BLOCK", ::vk::Format::eAstc6x5SrgbBlock);
    e_vk_Format.value("ASTC_6x6_UNORM_BLOCK", ::vk::Format::eAstc6x6UnormBlock);
    e_vk_Format.value("ASTC_6x6_SRGB_BLOCK", ::vk::Format::eAstc6x6SrgbBlock);
    e_vk_Format.value("ASTC_8x5_UNORM_BLOCK", ::vk::Format::eAstc8x5UnormBlock);
    e_vk_Format.value("ASTC_8x5_SRGB_BLOCK", ::vk::Format::eAstc8x5SrgbBlock);
    e_vk_Format.value("ASTC_8x6_UNORM_BLOCK", ::vk::Format::eAstc8x6UnormBlock);
    e_vk_Format.value("ASTC_8x6_SRGB_BLOCK", ::vk::Format::eAstc8x6SrgbBlock);
    e_vk_Format.value("ASTC_8x8_UNORM_BLOCK", ::vk::Format::eAstc8x8UnormBlock);
    e_vk_Format.value("ASTC_8x8_SRGB_BLOCK", ::vk::Format::eAstc8x8SrgbBlock);
    e_vk_Format.value("ASTC_10x5_UNORM_BLOCK", ::vk::Format::eAstc10x5UnormBlock);
    e_vk_Format.value("ASTC_10x5_SRGB_BLOCK", ::vk::Format::eAstc10x5SrgbBlock);
    e_vk_Format.value("ASTC_10x6_UNORM_BLOCK", ::vk::Format::eAstc10x6UnormBlock);
    e_vk_Format.value("ASTC_10x6_SRGB_BLOCK", ::vk::Format::eAstc10x6SrgbBlock);
    e_vk_Format.value("ASTC_10x8_UNORM_BLOCK", ::vk::Format::eAstc10x8UnormBlock);
    e_vk_Format.value("ASTC_10x8_SRGB_BLOCK", ::vk::Format::eAstc10x8SrgbBlock);
    e_vk_Format.value("ASTC_10x10_UNORM_BLOCK", ::vk::Format::eAstc10x10UnormBlock);
    e_vk_Format.value("ASTC_10x10_SRGB_BLOCK", ::vk::Format::eAstc10x10SrgbBlock);
    e_vk_Format.value("ASTC_12x10_UNORM_BLOCK", ::vk::Format::eAstc12x10UnormBlock);
    e_vk_Format.value("ASTC_12x10_SRGB_BLOCK", ::vk::Format::eAstc12x10SrgbBlock);
    e_vk_Format.value("ASTC_12x12_UNORM_BLOCK", ::vk::Format::eAstc12x12UnormBlock);
    e_vk_Format.value("ASTC_12x12_SRGB_BLOCK", ::vk::Format::eAstc12x12SrgbBlock);
    e_vk_Format.value("eG8B8G8R8422_UNORM", ::vk::Format::eG8B8G8R8422Unorm);
    e_vk_Format.value("eB8G8R8G8422_UNORM", ::vk::Format::eB8G8R8G8422Unorm);
    e_vk_Format.value("eG8B8R83_PLANE_420_UNORM", ::vk::Format::eG8B8R83Plane420Unorm);
    e_vk_Format.value("eG8B8R82_PLANE_420_UNORM", ::vk::Format::eG8B8R82Plane420Unorm);
    e_vk_Format.value("eG8B8R83_PLANE_422_UNORM", ::vk::Format::eG8B8R83Plane422Unorm);
    e_vk_Format.value("eG8B8R82_PLANE_422_UNORM", ::vk::Format::eG8B8R82Plane422Unorm);
    e_vk_Format.value("eG8B8R83_PLANE_444_UNORM", ::vk::Format::eG8B8R83Plane444Unorm);
    e_vk_Format.value("eR10X6_UNORM_PACK_16", ::vk::Format::eR10X6UnormPack16);
    e_vk_Format.value("eR10X6G10X6_UNORM_2_PACK_16", ::vk::Format::eR10X6G10X6Unorm2Pack16);
    e_vk_Format.value("eR10X6G10X6B10X6A10X6_UNORM_4_PACK_16", ::vk::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16);
    e_vk_Format.value("eG10X6B10X6G10X6R10X6422_UNORM_4_PACK_16", ::vk::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16);
    e_vk_Format.value("eB10X6G10X6R10X6G10X6422_UNORM_4_PACK_16", ::vk::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16);
    e_vk_Format.value("eG10X6B10X6R10X63_PLANE_420_UNORM_3_PACK_16", ::vk::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16);
    e_vk_Format.value("eG10X6B10X6R10X62_PLANE_420_UNORM_3_PACK_16", ::vk::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16);
    e_vk_Format.value("eG10X6B10X6R10X63_PLANE_422_UNORM_3_PACK_16", ::vk::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16);
    e_vk_Format.value("eG10X6B10X6R10X62_PLANE_422_UNORM_3_PACK_16", ::vk::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16);
    e_vk_Format.value("eG10X6B10X6R10X63_PLANE_444_UNORM_3_PACK_16", ::vk::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16);
    e_vk_Format.value("eR12X4_UNORM_PACK_16", ::vk::Format::eR12X4UnormPack16);
    e_vk_Format.value("eR12X4G12X4_UNORM_2_PACK_16", ::vk::Format::eR12X4G12X4Unorm2Pack16);
    e_vk_Format.value("eR12X4G12X4B12X4A12X4_UNORM_4_PACK_16", ::vk::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16);
    e_vk_Format.value("eG12X4B12X4G12X4R12X4422_UNORM_4_PACK_16", ::vk::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16);
    e_vk_Format.value("eB12X4G12X4R12X4G12X4422_UNORM_4_PACK_16", ::vk::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16);
    e_vk_Format.value("eG12X4B12X4R12X43_PLANE_420_UNORM_3_PACK_16", ::vk::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16);
    e_vk_Format.value("eG12X4B12X4R12X42_PLANE_420_UNORM_3_PACK_16", ::vk::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16);
    e_vk_Format.value("eG12X4B12X4R12X43_PLANE_422_UNORM_3_PACK_16", ::vk::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16);
    e_vk_Format.value("eG12X4B12X4R12X42_PLANE_422_UNORM_3_PACK_16", ::vk::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16);
    e_vk_Format.value("eG12X4B12X4R12X43_PLANE_444_UNORM_3_PACK_16", ::vk::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16);
    e_vk_Format.value("eG16B16G16R16422_UNORM", ::vk::Format::eG16B16G16R16422Unorm);
    e_vk_Format.value("eB16G16R16G16422_UNORM", ::vk::Format::eB16G16R16G16422Unorm);
    e_vk_Format.value("eG16B16R163_PLANE_420_UNORM", ::vk::Format::eG16B16R163Plane420Unorm);
    e_vk_Format.value("eG16B16R162_PLANE_420_UNORM", ::vk::Format::eG16B16R162Plane420Unorm);
    e_vk_Format.value("eG16B16R163_PLANE_422_UNORM", ::vk::Format::eG16B16R163Plane422Unorm);
    e_vk_Format.value("eG16B16R162_PLANE_422_UNORM", ::vk::Format::eG16B16R162Plane422Unorm);
    e_vk_Format.value("eG16B16R163_PLANE_444_UNORM", ::vk::Format::eG16B16R163Plane444Unorm);
    e_vk_Format.value("eG8B8R82_PLANE_444_UNORM", ::vk::Format::eG8B8R82Plane444Unorm);
    e_vk_Format.value("eG10X6B10X6R10X62_PLANE_444_UNORM_3_PACK_16", ::vk::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16);
    e_vk_Format.value("eG12X4B12X4R12X42_PLANE_444_UNORM_3_PACK_16", ::vk::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16);
    e_vk_Format.value("eG16B16R162_PLANE_444_UNORM", ::vk::Format::eG16B16R162Plane444Unorm);
    e_vk_Format.value("eA4R4G4B4_UNORM_PACK_16", ::vk::Format::eA4R4G4B4UnormPack16);
    e_vk_Format.value("eA4B4G4R4_UNORM_PACK_16", ::vk::Format::eA4B4G4R4UnormPack16);
    e_vk_Format.value("ASTC_4x4_SFLOAT_BLOCK", ::vk::Format::eAstc4x4SfloatBlock);
    e_vk_Format.value("ASTC_5x4_SFLOAT_BLOCK", ::vk::Format::eAstc5x4SfloatBlock);
    e_vk_Format.value("ASTC_5x5_SFLOAT_BLOCK", ::vk::Format::eAstc5x5SfloatBlock);
    e_vk_Format.value("ASTC_6x5_SFLOAT_BLOCK", ::vk::Format::eAstc6x5SfloatBlock);
    e_vk_Format.value("ASTC_6x6_SFLOAT_BLOCK", ::vk::Format::eAstc6x6SfloatBlock);
    e_vk_Format.value("ASTC_8x5_SFLOAT_BLOCK", ::vk::Format::eAstc8x5SfloatBlock);
    e_vk_Format.value("ASTC_8x6_SFLOAT_BLOCK", ::vk::Format::eAstc8x6SfloatBlock);
    e_vk_Format.value("ASTC_8x8_SFLOAT_BLOCK", ::vk::Format::eAstc8x8SfloatBlock);
    e_vk_Format.value("ASTC_10x5_SFLOAT_BLOCK", ::vk::Format::eAstc10x5SfloatBlock);
    e_vk_Format.value("ASTC_10x6_SFLOAT_BLOCK", ::vk::Format::eAstc10x6SfloatBlock);
    e_vk_Format.value("ASTC_10x8_SFLOAT_BLOCK", ::vk::Format::eAstc10x8SfloatBlock);
    e_vk_Format.value("ASTC_10x10_SFLOAT_BLOCK", ::vk::Format::eAstc10x10SfloatBlock);
    e_vk_Format.value("ASTC_12x10_SFLOAT_BLOCK", ::vk::Format::eAstc12x10SfloatBlock);
    e_vk_Format.value("ASTC_12x12_SFLOAT_BLOCK", ::vk::Format::eAstc12x12SfloatBlock);
    e_vk_Format.value("PVRTC_12_BPP_UNORM_BLOCK_IMG", ::vk::Format::ePvrtc12BppUnormBlockIMG);
    e_vk_Format.value("PVRTC_14_BPP_UNORM_BLOCK_IMG", ::vk::Format::ePvrtc14BppUnormBlockIMG);
    e_vk_Format.value("PVRTC_22_BPP_UNORM_BLOCK_IMG", ::vk::Format::ePvrtc22BppUnormBlockIMG);
    e_vk_Format.value("PVRTC_24_BPP_UNORM_BLOCK_IMG", ::vk::Format::ePvrtc24BppUnormBlockIMG);
    e_vk_Format.value("PVRTC_12_BPP_SRGB_BLOCK_IMG", ::vk::Format::ePvrtc12BppSrgbBlockIMG);
    e_vk_Format.value("PVRTC_14_BPP_SRGB_BLOCK_IMG", ::vk::Format::ePvrtc14BppSrgbBlockIMG);
    e_vk_Format.value("PVRTC_22_BPP_SRGB_BLOCK_IMG", ::vk::Format::ePvrtc22BppSrgbBlockIMG);
    e_vk_Format.value("PVRTC_24_BPP_SRGB_BLOCK_IMG", ::vk::Format::ePvrtc24BppSrgbBlockIMG);
    e_vk_Format.value("ASTC_4x4_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc4x4SfloatBlockEXT);
    e_vk_Format.value("ASTC_5x4_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc5x4SfloatBlockEXT);
    e_vk_Format.value("ASTC_5x5_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc5x5SfloatBlockEXT);
    e_vk_Format.value("ASTC_6x5_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc6x5SfloatBlockEXT);
    e_vk_Format.value("ASTC_6x6_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc6x6SfloatBlockEXT);
    e_vk_Format.value("ASTC_8x5_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc8x5SfloatBlockEXT);
    e_vk_Format.value("ASTC_8x6_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc8x6SfloatBlockEXT);
    e_vk_Format.value("ASTC_8x8_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc8x8SfloatBlockEXT);
    e_vk_Format.value("ASTC_10x5_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc10x5SfloatBlockEXT);
    e_vk_Format.value("ASTC_10x6_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc10x6SfloatBlockEXT);
    e_vk_Format.value("ASTC_10x8_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc10x8SfloatBlockEXT);
    e_vk_Format.value("ASTC_10x10_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc10x10SfloatBlockEXT);
    e_vk_Format.value("ASTC_12x10_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc12x10SfloatBlockEXT);
    e_vk_Format.value("ASTC_12x12_SFLOAT_BLOCK_EXT", ::vk::Format::eAstc12x12SfloatBlockEXT);
    e_vk_Format.value("eG8B8G8R8422_UNORM_KHR", ::vk::Format::eG8B8G8R8422UnormKHR);
    e_vk_Format.value("eB8G8R8G8422_UNORM_KHR", ::vk::Format::eB8G8R8G8422UnormKHR);
    e_vk_Format.value("eG8B8R83_PLANE_420_UNORM_KHR", ::vk::Format::eG8B8R83Plane420UnormKHR);
    e_vk_Format.value("eG8B8R82_PLANE_420_UNORM_KHR", ::vk::Format::eG8B8R82Plane420UnormKHR);
    e_vk_Format.value("eG8B8R83_PLANE_422_UNORM_KHR", ::vk::Format::eG8B8R83Plane422UnormKHR);
    e_vk_Format.value("eG8B8R82_PLANE_422_UNORM_KHR", ::vk::Format::eG8B8R82Plane422UnormKHR);
    e_vk_Format.value("eG8B8R83_PLANE_444_UNORM_KHR", ::vk::Format::eG8B8R83Plane444UnormKHR);
    e_vk_Format.value("eR10X6_UNORM_PACK_16KHR", ::vk::Format::eR10X6UnormPack16KHR);
    e_vk_Format.value("eR10X6G10X6_UNORM_2_PACK_16KHR", ::vk::Format::eR10X6G10X6Unorm2Pack16KHR);
    e_vk_Format.value("eR10X6G10X6B10X6A10X6_UNORM_4_PACK_16KHR", ::vk::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16KHR);
    e_vk_Format.value("eG10X6B10X6G10X6R10X6422_UNORM_4_PACK_16KHR", ::vk::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16KHR);
    e_vk_Format.value("eB10X6G10X6R10X6G10X6422_UNORM_4_PACK_16KHR", ::vk::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16KHR);
    e_vk_Format.value("eG10X6B10X6R10X63_PLANE_420_UNORM_3_PACK_16KHR", ::vk::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16KHR);
    e_vk_Format.value("eG10X6B10X6R10X62_PLANE_420_UNORM_3_PACK_16KHR", ::vk::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16KHR);
    e_vk_Format.value("eG10X6B10X6R10X63_PLANE_422_UNORM_3_PACK_16KHR", ::vk::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16KHR);
    e_vk_Format.value("eG10X6B10X6R10X62_PLANE_422_UNORM_3_PACK_16KHR", ::vk::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16KHR);
    e_vk_Format.value("eG10X6B10X6R10X63_PLANE_444_UNORM_3_PACK_16KHR", ::vk::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16KHR);
    e_vk_Format.value("eR12X4_UNORM_PACK_16KHR", ::vk::Format::eR12X4UnormPack16KHR);
    e_vk_Format.value("eR12X4G12X4_UNORM_2_PACK_16KHR", ::vk::Format::eR12X4G12X4Unorm2Pack16KHR);
    e_vk_Format.value("eR12X4G12X4B12X4A12X4_UNORM_4_PACK_16KHR", ::vk::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16KHR);
    e_vk_Format.value("eG12X4B12X4G12X4R12X4422_UNORM_4_PACK_16KHR", ::vk::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16KHR);
    e_vk_Format.value("eB12X4G12X4R12X4G12X4422_UNORM_4_PACK_16KHR", ::vk::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16KHR);
    e_vk_Format.value("eG12X4B12X4R12X43_PLANE_420_UNORM_3_PACK_16KHR", ::vk::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16KHR);
    e_vk_Format.value("eG12X4B12X4R12X42_PLANE_420_UNORM_3_PACK_16KHR", ::vk::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16KHR);
    e_vk_Format.value("eG12X4B12X4R12X43_PLANE_422_UNORM_3_PACK_16KHR", ::vk::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16KHR);
    e_vk_Format.value("eG12X4B12X4R12X42_PLANE_422_UNORM_3_PACK_16KHR", ::vk::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16KHR);
    e_vk_Format.value("eG12X4B12X4R12X43_PLANE_444_UNORM_3_PACK_16KHR", ::vk::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16KHR);
    e_vk_Format.value("eG16B16G16R16422_UNORM_KHR", ::vk::Format::eG16B16G16R16422UnormKHR);
    e_vk_Format.value("eB16G16R16G16422_UNORM_KHR", ::vk::Format::eB16G16R16G16422UnormKHR);
    e_vk_Format.value("eG16B16R163_PLANE_420_UNORM_KHR", ::vk::Format::eG16B16R163Plane420UnormKHR);
    e_vk_Format.value("eG16B16R162_PLANE_420_UNORM_KHR", ::vk::Format::eG16B16R162Plane420UnormKHR);
    e_vk_Format.value("eG16B16R163_PLANE_422_UNORM_KHR", ::vk::Format::eG16B16R163Plane422UnormKHR);
    e_vk_Format.value("eG16B16R162_PLANE_422_UNORM_KHR", ::vk::Format::eG16B16R162Plane422UnormKHR);
    e_vk_Format.value("eG16B16R163_PLANE_444_UNORM_KHR", ::vk::Format::eG16B16R163Plane444UnormKHR);
    e_vk_Format.value("eG8B8R82_PLANE_444_UNORM_EXT", ::vk::Format::eG8B8R82Plane444UnormEXT);
    e_vk_Format.value("eG10X6B10X6R10X62_PLANE_444_UNORM_3_PACK_16EXT", ::vk::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16EXT);
    e_vk_Format.value("eG12X4B12X4R12X42_PLANE_444_UNORM_3_PACK_16EXT", ::vk::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16EXT);
    e_vk_Format.value("eG16B16R162_PLANE_444_UNORM_EXT", ::vk::Format::eG16B16R162Plane444UnormEXT);
    e_vk_Format.value("eA4R4G4B4_UNORM_PACK_16EXT", ::vk::Format::eA4R4G4B4UnormPack16EXT);
    e_vk_Format.value("eA4B4G4R4_UNORM_PACK_16EXT", ::vk::Format::eA4B4G4R4UnormPack16EXT);
    e_vk_Format.value("eR16G16S105NV", ::vk::Format::eR16G16S105NV);
    e_vk_Format.value("eA1B5G5R5_UNORM_PACK_16KHR", ::vk::Format::eA1B5G5R5UnormPack16KHR);
    e_vk_Format.value("eA8_UNORM_KHR", ::vk::Format::eA8UnormKHR);

    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE", ::vk::FormatFeatureFlagBits::eSampledImage);
    e_vk_FormatFeatureFlagBits.value("STORAGE_IMAGE", ::vk::FormatFeatureFlagBits::eStorageImage);
    e_vk_FormatFeatureFlagBits.value("STORAGE_IMAGE_ATOMIC", ::vk::FormatFeatureFlagBits::eStorageImageAtomic);
    e_vk_FormatFeatureFlagBits.value("UNIFORM_TEXEL_BUFFER", ::vk::FormatFeatureFlagBits::eUniformTexelBuffer);
    e_vk_FormatFeatureFlagBits.value("STORAGE_TEXEL_BUFFER", ::vk::FormatFeatureFlagBits::eStorageTexelBuffer);
    e_vk_FormatFeatureFlagBits.value("STORAGE_TEXEL_BUFFER_ATOMIC", ::vk::FormatFeatureFlagBits::eStorageTexelBufferAtomic);
    e_vk_FormatFeatureFlagBits.value("VERTEX_BUFFER", ::vk::FormatFeatureFlagBits::eVertexBuffer);
    e_vk_FormatFeatureFlagBits.value("COLOR_ATTACHMENT", ::vk::FormatFeatureFlagBits::eColorAttachment);
    e_vk_FormatFeatureFlagBits.value("COLOR_ATTACHMENT_BLEND", ::vk::FormatFeatureFlagBits::eColorAttachmentBlend);
    e_vk_FormatFeatureFlagBits.value("DEPTH_STENCIL_ATTACHMENT", ::vk::FormatFeatureFlagBits::eDepthStencilAttachment);
    e_vk_FormatFeatureFlagBits.value("BLIT_SRC", ::vk::FormatFeatureFlagBits::eBlitSrc);
    e_vk_FormatFeatureFlagBits.value("BLIT_DST", ::vk::FormatFeatureFlagBits::eBlitDst);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_LINEAR", ::vk::FormatFeatureFlagBits::eSampledImageFilterLinear);
    e_vk_FormatFeatureFlagBits.value("TRANSFER_SRC", ::vk::FormatFeatureFlagBits::eTransferSrc);
    e_vk_FormatFeatureFlagBits.value("TRANSFER_DST", ::vk::FormatFeatureFlagBits::eTransferDst);
    e_vk_FormatFeatureFlagBits.value("MIDPOINT_CHROMA_SAMPLES", ::vk::FormatFeatureFlagBits::eMidpointChromaSamples);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER", ::vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionLinearFilter);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER", ::vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionSeparateReconstructionFilter);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT", ::vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionChromaReconstructionExplicit);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE", ::vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionChromaReconstructionExplicitForceable);
    e_vk_FormatFeatureFlagBits.value("DISJOINT", ::vk::FormatFeatureFlagBits::eDisjoint);
    e_vk_FormatFeatureFlagBits.value("COSITED_CHROMA_SAMPLES", ::vk::FormatFeatureFlagBits::eCositedChromaSamples);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_MINMAX", ::vk::FormatFeatureFlagBits::eSampledImageFilterMinmax);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_CUBIC_IMG", ::vk::FormatFeatureFlagBits::eSampledImageFilterCubicIMG);
    e_vk_FormatFeatureFlagBits.value("VIDEO_DECODE_OUTPUT_KHR", ::vk::FormatFeatureFlagBits::eVideoDecodeOutputKHR);
    e_vk_FormatFeatureFlagBits.value("VIDEO_DECODE_DPB_KHR", ::vk::FormatFeatureFlagBits::eVideoDecodeDpbKHR);
    e_vk_FormatFeatureFlagBits.value("TRANSFER_SRC_KHR", ::vk::FormatFeatureFlagBits::eTransferSrcKHR);
    e_vk_FormatFeatureFlagBits.value("TRANSFER_DST_KHR", ::vk::FormatFeatureFlagBits::eTransferDstKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_MINMAX_EXT", ::vk::FormatFeatureFlagBits::eSampledImageFilterMinmaxEXT);
    e_vk_FormatFeatureFlagBits.value("ACCELERATION_STRUCTURE_VERTEX_BUFFER_KHR", ::vk::FormatFeatureFlagBits::eAccelerationStructureVertexBufferKHR);
    e_vk_FormatFeatureFlagBits.value("MIDPOINT_CHROMA_SAMPLES_KHR", ::vk::FormatFeatureFlagBits::eMidpointChromaSamplesKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_KHR", ::vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionLinearFilterKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_KHR", ::vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionSeparateReconstructionFilterKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_KHR", ::vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionChromaReconstructionExplicitKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_KHR", ::vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionChromaReconstructionExplicitForceableKHR);
    e_vk_FormatFeatureFlagBits.value("DISJOINT_KHR", ::vk::FormatFeatureFlagBits::eDisjointKHR);
    e_vk_FormatFeatureFlagBits.value("COSITED_CHROMA_SAMPLES_KHR", ::vk::FormatFeatureFlagBits::eCositedChromaSamplesKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_CUBIC_EXT", ::vk::FormatFeatureFlagBits::eSampledImageFilterCubicEXT);
    e_vk_FormatFeatureFlagBits.value("FRAGMENT_DENSITY_MAP_EXT", ::vk::FormatFeatureFlagBits::eFragmentDensityMapEXT);
    e_vk_FormatFeatureFlagBits.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", ::vk::FormatFeatureFlagBits::eFragmentShadingRateAttachmentKHR);
    e_vk_FormatFeatureFlagBits.value("VIDEO_ENCODE_INPUT_KHR", ::vk::FormatFeatureFlagBits::eVideoEncodeInputKHR);
    e_vk_FormatFeatureFlagBits.value("VIDEO_ENCODE_DPB_KHR", ::vk::FormatFeatureFlagBits::eVideoEncodeDpbKHR);

    e_vk_FramebufferCreateFlagBits.value("IMAGELESS", ::vk::FramebufferCreateFlagBits::eImageless);
    e_vk_FramebufferCreateFlagBits.value("IMAGELESS_KHR", ::vk::FramebufferCreateFlagBits::eImagelessKHR);

    e_vk_FrontFace.value("COUNTER_CLOCKWISE", ::vk::FrontFace::eCounterClockwise);
    e_vk_FrontFace.value("CLOCKWISE", ::vk::FrontFace::eClockwise);

    e_vk_ImageAspectFlagBits.value("COLOR", ::vk::ImageAspectFlagBits::eColor);
    e_vk_ImageAspectFlagBits.value("DEPTH", ::vk::ImageAspectFlagBits::eDepth);
    e_vk_ImageAspectFlagBits.value("STENCIL", ::vk::ImageAspectFlagBits::eStencil);
    e_vk_ImageAspectFlagBits.value("METADATA", ::vk::ImageAspectFlagBits::eMetadata);
    e_vk_ImageAspectFlagBits.value("PLANE_0", ::vk::ImageAspectFlagBits::ePlane0);
    e_vk_ImageAspectFlagBits.value("PLANE_1", ::vk::ImageAspectFlagBits::ePlane1);
    e_vk_ImageAspectFlagBits.value("PLANE_2", ::vk::ImageAspectFlagBits::ePlane2);
    e_vk_ImageAspectFlagBits.value("NONE", ::vk::ImageAspectFlagBits::eNone);
    e_vk_ImageAspectFlagBits.value("PLANE_0KHR", ::vk::ImageAspectFlagBits::ePlane0KHR);
    e_vk_ImageAspectFlagBits.value("PLANE_1KHR", ::vk::ImageAspectFlagBits::ePlane1KHR);
    e_vk_ImageAspectFlagBits.value("PLANE_2KHR", ::vk::ImageAspectFlagBits::ePlane2KHR);
    e_vk_ImageAspectFlagBits.value("MEMORY_PLANE_0EXT", ::vk::ImageAspectFlagBits::eMemoryPlane0EXT);
    e_vk_ImageAspectFlagBits.value("MEMORY_PLANE_1EXT", ::vk::ImageAspectFlagBits::eMemoryPlane1EXT);
    e_vk_ImageAspectFlagBits.value("MEMORY_PLANE_2EXT", ::vk::ImageAspectFlagBits::eMemoryPlane2EXT);
    e_vk_ImageAspectFlagBits.value("MEMORY_PLANE_3EXT", ::vk::ImageAspectFlagBits::eMemoryPlane3EXT);
    e_vk_ImageAspectFlagBits.value("NONE_KHR", ::vk::ImageAspectFlagBits::eNoneKHR);

    e_vk_ImageCreateFlagBits.value("SPARSE_BINDING", ::vk::ImageCreateFlagBits::eSparseBinding);
    e_vk_ImageCreateFlagBits.value("SPARSE_RESIDENCY", ::vk::ImageCreateFlagBits::eSparseResidency);
    e_vk_ImageCreateFlagBits.value("SPARSE_ALIASED", ::vk::ImageCreateFlagBits::eSparseAliased);
    e_vk_ImageCreateFlagBits.value("MUTABLE_FORMAT", ::vk::ImageCreateFlagBits::eMutableFormat);
    e_vk_ImageCreateFlagBits.value("CUBE_COMPATIBLE", ::vk::ImageCreateFlagBits::eCubeCompatible);
    e_vk_ImageCreateFlagBits.value("ALIAS", ::vk::ImageCreateFlagBits::eAlias);
    e_vk_ImageCreateFlagBits.value("SPLIT_INSTANCE_BIND_REGIONS", ::vk::ImageCreateFlagBits::eSplitInstanceBindRegions);
    e_vk_ImageCreateFlagBits.value("e2D_ARRAY_COMPATIBLE", ::vk::ImageCreateFlagBits::e2DArrayCompatible);
    e_vk_ImageCreateFlagBits.value("BLOCK_TEXEL_VIEW_COMPATIBLE", ::vk::ImageCreateFlagBits::eBlockTexelViewCompatible);
    e_vk_ImageCreateFlagBits.value("EXTENDED_USAGE", ::vk::ImageCreateFlagBits::eExtendedUsage);
    e_vk_ImageCreateFlagBits.value("PROTECTED", ::vk::ImageCreateFlagBits::eProtected);
    e_vk_ImageCreateFlagBits.value("DISJOINT", ::vk::ImageCreateFlagBits::eDisjoint);
    e_vk_ImageCreateFlagBits.value("CORNER_SAMPLED_NV", ::vk::ImageCreateFlagBits::eCornerSampledNV);
    e_vk_ImageCreateFlagBits.value("SPLIT_INSTANCE_BIND_REGIONS_KHR", ::vk::ImageCreateFlagBits::eSplitInstanceBindRegionsKHR);
    e_vk_ImageCreateFlagBits.value("e2D_ARRAY_COMPATIBLE_KHR", ::vk::ImageCreateFlagBits::e2DArrayCompatibleKHR);
    e_vk_ImageCreateFlagBits.value("BLOCK_TEXEL_VIEW_COMPATIBLE_KHR", ::vk::ImageCreateFlagBits::eBlockTexelViewCompatibleKHR);
    e_vk_ImageCreateFlagBits.value("EXTENDED_USAGE_KHR", ::vk::ImageCreateFlagBits::eExtendedUsageKHR);
    e_vk_ImageCreateFlagBits.value("SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_EXT", ::vk::ImageCreateFlagBits::eSampleLocationsCompatibleDepthEXT);
    e_vk_ImageCreateFlagBits.value("DISJOINT_KHR", ::vk::ImageCreateFlagBits::eDisjointKHR);
    e_vk_ImageCreateFlagBits.value("ALIAS_KHR", ::vk::ImageCreateFlagBits::eAliasKHR);
    e_vk_ImageCreateFlagBits.value("SUBSAMPLED_EXT", ::vk::ImageCreateFlagBits::eSubsampledEXT);
    e_vk_ImageCreateFlagBits.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", ::vk::ImageCreateFlagBits::eDescriptorBufferCaptureReplayEXT);
    e_vk_ImageCreateFlagBits.value("MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_EXT", ::vk::ImageCreateFlagBits::eMultisampledRenderToSingleSampledEXT);
    e_vk_ImageCreateFlagBits.value("e2D_VIEW_COMPATIBLE_EXT", ::vk::ImageCreateFlagBits::e2DViewCompatibleEXT);
    e_vk_ImageCreateFlagBits.value("FRAGMENT_DENSITY_MAP_OFFSET_QCOM", ::vk::ImageCreateFlagBits::eFragmentDensityMapOffsetQCOM);
    e_vk_ImageCreateFlagBits.value("VIDEO_PROFILE_INDEPENDENT_KHR", ::vk::ImageCreateFlagBits::eVideoProfileIndependentKHR);

    e_vk_ImageLayout.value("UNDEFINED", ::vk::ImageLayout::eUndefined);
    e_vk_ImageLayout.value("GENERAL", ::vk::ImageLayout::eGeneral);
    e_vk_ImageLayout.value("COLOR_ATTACHMENT_OPTIMAL", ::vk::ImageLayout::eColorAttachmentOptimal);
    e_vk_ImageLayout.value("DEPTH_STENCIL_ATTACHMENT_OPTIMAL", ::vk::ImageLayout::eDepthStencilAttachmentOptimal);
    e_vk_ImageLayout.value("DEPTH_STENCIL_READ_ONLY_OPTIMAL", ::vk::ImageLayout::eDepthStencilReadOnlyOptimal);
    e_vk_ImageLayout.value("SHADER_READ_ONLY_OPTIMAL", ::vk::ImageLayout::eShaderReadOnlyOptimal);
    e_vk_ImageLayout.value("TRANSFER_SRC_OPTIMAL", ::vk::ImageLayout::eTransferSrcOptimal);
    e_vk_ImageLayout.value("TRANSFER_DST_OPTIMAL", ::vk::ImageLayout::eTransferDstOptimal);
    e_vk_ImageLayout.value("PREINITIALIZED", ::vk::ImageLayout::ePreinitialized);
    e_vk_ImageLayout.value("DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL", ::vk::ImageLayout::eDepthReadOnlyStencilAttachmentOptimal);
    e_vk_ImageLayout.value("DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL", ::vk::ImageLayout::eDepthAttachmentStencilReadOnlyOptimal);
    e_vk_ImageLayout.value("DEPTH_ATTACHMENT_OPTIMAL", ::vk::ImageLayout::eDepthAttachmentOptimal);
    e_vk_ImageLayout.value("DEPTH_READ_ONLY_OPTIMAL", ::vk::ImageLayout::eDepthReadOnlyOptimal);
    e_vk_ImageLayout.value("STENCIL_ATTACHMENT_OPTIMAL", ::vk::ImageLayout::eStencilAttachmentOptimal);
    e_vk_ImageLayout.value("STENCIL_READ_ONLY_OPTIMAL", ::vk::ImageLayout::eStencilReadOnlyOptimal);
    e_vk_ImageLayout.value("READ_ONLY_OPTIMAL", ::vk::ImageLayout::eReadOnlyOptimal);
    e_vk_ImageLayout.value("ATTACHMENT_OPTIMAL", ::vk::ImageLayout::eAttachmentOptimal);
    e_vk_ImageLayout.value("PRESENT_SRC_KHR", ::vk::ImageLayout::ePresentSrcKHR);
    e_vk_ImageLayout.value("VIDEO_DECODE_DST_KHR", ::vk::ImageLayout::eVideoDecodeDstKHR);
    e_vk_ImageLayout.value("VIDEO_DECODE_SRC_KHR", ::vk::ImageLayout::eVideoDecodeSrcKHR);
    e_vk_ImageLayout.value("VIDEO_DECODE_DPB_KHR", ::vk::ImageLayout::eVideoDecodeDpbKHR);
    e_vk_ImageLayout.value("SHARED_PRESENT_KHR", ::vk::ImageLayout::eSharedPresentKHR);
    e_vk_ImageLayout.value("DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR", ::vk::ImageLayout::eDepthReadOnlyStencilAttachmentOptimalKHR);
    e_vk_ImageLayout.value("DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR", ::vk::ImageLayout::eDepthAttachmentStencilReadOnlyOptimalKHR);
    e_vk_ImageLayout.value("SHADING_RATE_OPTIMAL_NV", ::vk::ImageLayout::eShadingRateOptimalNV);
    e_vk_ImageLayout.value("FRAGMENT_DENSITY_MAP_OPTIMAL_EXT", ::vk::ImageLayout::eFragmentDensityMapOptimalEXT);
    e_vk_ImageLayout.value("FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR", ::vk::ImageLayout::eFragmentShadingRateAttachmentOptimalKHR);
    e_vk_ImageLayout.value("DEPTH_ATTACHMENT_OPTIMAL_KHR", ::vk::ImageLayout::eDepthAttachmentOptimalKHR);
    e_vk_ImageLayout.value("DEPTH_READ_ONLY_OPTIMAL_KHR", ::vk::ImageLayout::eDepthReadOnlyOptimalKHR);
    e_vk_ImageLayout.value("STENCIL_ATTACHMENT_OPTIMAL_KHR", ::vk::ImageLayout::eStencilAttachmentOptimalKHR);
    e_vk_ImageLayout.value("STENCIL_READ_ONLY_OPTIMAL_KHR", ::vk::ImageLayout::eStencilReadOnlyOptimalKHR);
    e_vk_ImageLayout.value("VIDEO_ENCODE_DST_KHR", ::vk::ImageLayout::eVideoEncodeDstKHR);
    e_vk_ImageLayout.value("VIDEO_ENCODE_SRC_KHR", ::vk::ImageLayout::eVideoEncodeSrcKHR);
    e_vk_ImageLayout.value("VIDEO_ENCODE_DPB_KHR", ::vk::ImageLayout::eVideoEncodeDpbKHR);
    e_vk_ImageLayout.value("READ_ONLY_OPTIMAL_KHR", ::vk::ImageLayout::eReadOnlyOptimalKHR);
    e_vk_ImageLayout.value("ATTACHMENT_OPTIMAL_KHR", ::vk::ImageLayout::eAttachmentOptimalKHR);
    e_vk_ImageLayout.value("ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT", ::vk::ImageLayout::eAttachmentFeedbackLoopOptimalEXT);

    e_vk_ImageTiling.value("OPTIMAL", ::vk::ImageTiling::eOptimal);
    e_vk_ImageTiling.value("LINEAR", ::vk::ImageTiling::eLinear);
    e_vk_ImageTiling.value("DRM_FORMAT_MODIFIER_EXT", ::vk::ImageTiling::eDrmFormatModifierEXT);

    e_vk_ImageType.value("e1D", ::vk::ImageType::e1D);
    e_vk_ImageType.value("e2D", ::vk::ImageType::e2D);
    e_vk_ImageType.value("e3D", ::vk::ImageType::e3D);

    e_vk_ImageUsageFlagBits.value("TRANSFER_SRC", ::vk::ImageUsageFlagBits::eTransferSrc);
    e_vk_ImageUsageFlagBits.value("TRANSFER_DST", ::vk::ImageUsageFlagBits::eTransferDst);
    e_vk_ImageUsageFlagBits.value("SAMPLED", ::vk::ImageUsageFlagBits::eSampled);
    e_vk_ImageUsageFlagBits.value("STORAGE", ::vk::ImageUsageFlagBits::eStorage);
    e_vk_ImageUsageFlagBits.value("COLOR_ATTACHMENT", ::vk::ImageUsageFlagBits::eColorAttachment);
    e_vk_ImageUsageFlagBits.value("DEPTH_STENCIL_ATTACHMENT", ::vk::ImageUsageFlagBits::eDepthStencilAttachment);
    e_vk_ImageUsageFlagBits.value("TRANSIENT_ATTACHMENT", ::vk::ImageUsageFlagBits::eTransientAttachment);
    e_vk_ImageUsageFlagBits.value("INPUT_ATTACHMENT", ::vk::ImageUsageFlagBits::eInputAttachment);
    e_vk_ImageUsageFlagBits.value("VIDEO_DECODE_DST_KHR", ::vk::ImageUsageFlagBits::eVideoDecodeDstKHR);
    e_vk_ImageUsageFlagBits.value("VIDEO_DECODE_SRC_KHR", ::vk::ImageUsageFlagBits::eVideoDecodeSrcKHR);
    e_vk_ImageUsageFlagBits.value("VIDEO_DECODE_DPB_KHR", ::vk::ImageUsageFlagBits::eVideoDecodeDpbKHR);
    e_vk_ImageUsageFlagBits.value("SHADING_RATE_IMAGE_NV", ::vk::ImageUsageFlagBits::eShadingRateImageNV);
    e_vk_ImageUsageFlagBits.value("FRAGMENT_DENSITY_MAP_EXT", ::vk::ImageUsageFlagBits::eFragmentDensityMapEXT);
    e_vk_ImageUsageFlagBits.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", ::vk::ImageUsageFlagBits::eFragmentShadingRateAttachmentKHR);
    e_vk_ImageUsageFlagBits.value("HOST_TRANSFER_EXT", ::vk::ImageUsageFlagBits::eHostTransferEXT);
    e_vk_ImageUsageFlagBits.value("VIDEO_ENCODE_DST_KHR", ::vk::ImageUsageFlagBits::eVideoEncodeDstKHR);
    e_vk_ImageUsageFlagBits.value("VIDEO_ENCODE_SRC_KHR", ::vk::ImageUsageFlagBits::eVideoEncodeSrcKHR);
    e_vk_ImageUsageFlagBits.value("VIDEO_ENCODE_DPB_KHR", ::vk::ImageUsageFlagBits::eVideoEncodeDpbKHR);
    e_vk_ImageUsageFlagBits.value("ATTACHMENT_FEEDBACK_LOOP_EXT", ::vk::ImageUsageFlagBits::eAttachmentFeedbackLoopEXT);
    e_vk_ImageUsageFlagBits.value("INVOCATION_MASK_HUAWEI", ::vk::ImageUsageFlagBits::eInvocationMaskHUAWEI);
    e_vk_ImageUsageFlagBits.value("SAMPLE_WEIGHT_QCOM", ::vk::ImageUsageFlagBits::eSampleWeightQCOM);
    e_vk_ImageUsageFlagBits.value("SAMPLE_BLOCK_MATCH_QCOM", ::vk::ImageUsageFlagBits::eSampleBlockMatchQCOM);

    e_vk_ImageViewCreateFlagBits.value("FRAGMENT_DENSITY_MAP_DYNAMIC_EXT", ::vk::ImageViewCreateFlagBits::eFragmentDensityMapDynamicEXT);
    e_vk_ImageViewCreateFlagBits.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", ::vk::ImageViewCreateFlagBits::eDescriptorBufferCaptureReplayEXT);
    e_vk_ImageViewCreateFlagBits.value("FRAGMENT_DENSITY_MAP_DEFERRED_EXT", ::vk::ImageViewCreateFlagBits::eFragmentDensityMapDeferredEXT);

    e_vk_ImageViewType.value("e1D", ::vk::ImageViewType::e1D);
    e_vk_ImageViewType.value("e2D", ::vk::ImageViewType::e2D);
    e_vk_ImageViewType.value("e3D", ::vk::ImageViewType::e3D);
    e_vk_ImageViewType.value("CUBE", ::vk::ImageViewType::eCube);
    e_vk_ImageViewType.value("e1D_ARRAY", ::vk::ImageViewType::e1DArray);
    e_vk_ImageViewType.value("e2D_ARRAY", ::vk::ImageViewType::e2DArray);
    e_vk_ImageViewType.value("CUBE_ARRAY", ::vk::ImageViewType::eCubeArray);

    e_vk_IndexType.value("UINT_16", ::vk::IndexType::eUint16);
    e_vk_IndexType.value("UINT_32", ::vk::IndexType::eUint32);
    e_vk_IndexType.value("NONE_KHR", ::vk::IndexType::eNoneKHR);
    e_vk_IndexType.value("NONE_NV", ::vk::IndexType::eNoneNV);
    e_vk_IndexType.value("UINT_8EXT", ::vk::IndexType::eUint8EXT);

    e_vk_InstanceCreateFlagBits.value("ENUMERATE_PORTABILITY_KHR", ::vk::InstanceCreateFlagBits::eEnumeratePortabilityKHR);

    e_vk_InternalAllocationType.value("EXECUTABLE", ::vk::InternalAllocationType::eExecutable);

    e_vk_LogicOp.value("CLEAR", ::vk::LogicOp::eClear);
    e_vk_LogicOp.value("AND", ::vk::LogicOp::eAnd);
    e_vk_LogicOp.value("AND_REVERSE", ::vk::LogicOp::eAndReverse);
    e_vk_LogicOp.value("COPY", ::vk::LogicOp::eCopy);
    e_vk_LogicOp.value("AND_INVERTED", ::vk::LogicOp::eAndInverted);
    e_vk_LogicOp.value("NO_OP", ::vk::LogicOp::eNoOp);
    e_vk_LogicOp.value("XOR", ::vk::LogicOp::eXor);
    e_vk_LogicOp.value("OR", ::vk::LogicOp::eOr);
    e_vk_LogicOp.value("NOR", ::vk::LogicOp::eNor);
    e_vk_LogicOp.value("EQUIVALENT", ::vk::LogicOp::eEquivalent);
    e_vk_LogicOp.value("INVERT", ::vk::LogicOp::eInvert);
    e_vk_LogicOp.value("OR_REVERSE", ::vk::LogicOp::eOrReverse);
    e_vk_LogicOp.value("COPY_INVERTED", ::vk::LogicOp::eCopyInverted);
    e_vk_LogicOp.value("OR_INVERTED", ::vk::LogicOp::eOrInverted);
    e_vk_LogicOp.value("NAND", ::vk::LogicOp::eNand);
    e_vk_LogicOp.value("SET", ::vk::LogicOp::eSet);

    e_vk_MemoryHeapFlagBits.value("DEVICE_LOCAL", ::vk::MemoryHeapFlagBits::eDeviceLocal);
    e_vk_MemoryHeapFlagBits.value("MULTI_INSTANCE", ::vk::MemoryHeapFlagBits::eMultiInstance);
    e_vk_MemoryHeapFlagBits.value("MULTI_INSTANCE_KHR", ::vk::MemoryHeapFlagBits::eMultiInstanceKHR);


    e_vk_MemoryPropertyFlagBits.value("DEVICE_LOCAL", ::vk::MemoryPropertyFlagBits::eDeviceLocal);
    e_vk_MemoryPropertyFlagBits.value("HOST_VISIBLE", ::vk::MemoryPropertyFlagBits::eHostVisible);
    e_vk_MemoryPropertyFlagBits.value("HOST_COHERENT", ::vk::MemoryPropertyFlagBits::eHostCoherent);
    e_vk_MemoryPropertyFlagBits.value("HOST_CACHED", ::vk::MemoryPropertyFlagBits::eHostCached);
    e_vk_MemoryPropertyFlagBits.value("LAZILY_ALLOCATED", ::vk::MemoryPropertyFlagBits::eLazilyAllocated);
    e_vk_MemoryPropertyFlagBits.value("PROTECTED", ::vk::MemoryPropertyFlagBits::eProtected);
    e_vk_MemoryPropertyFlagBits.value("DEVICE_COHERENT_AMD", ::vk::MemoryPropertyFlagBits::eDeviceCoherentAMD);
    e_vk_MemoryPropertyFlagBits.value("DEVICE_UNCACHED_AMD", ::vk::MemoryPropertyFlagBits::eDeviceUncachedAMD);
    e_vk_MemoryPropertyFlagBits.value("RDMA_CAPABLE_NV", ::vk::MemoryPropertyFlagBits::eRdmaCapableNV);

    e_vk_ObjectType.value("UNKNOWN", ::vk::ObjectType::eUnknown);
    e_vk_ObjectType.value("INSTANCE", ::vk::ObjectType::eInstance);
    e_vk_ObjectType.value("PHYSICAL_DEVICE", ::vk::ObjectType::ePhysicalDevice);
    e_vk_ObjectType.value("DEVICE", ::vk::ObjectType::eDevice);
    e_vk_ObjectType.value("QUEUE", ::vk::ObjectType::eQueue);
    e_vk_ObjectType.value("SEMAPHORE", ::vk::ObjectType::eSemaphore);
    e_vk_ObjectType.value("COMMAND_BUFFER", ::vk::ObjectType::eCommandBuffer);
    e_vk_ObjectType.value("FENCE", ::vk::ObjectType::eFence);
    e_vk_ObjectType.value("DEVICE_MEMORY", ::vk::ObjectType::eDeviceMemory);
    e_vk_ObjectType.value("BUFFER", ::vk::ObjectType::eBuffer);
    e_vk_ObjectType.value("IMAGE", ::vk::ObjectType::eImage);
    e_vk_ObjectType.value("EVENT", ::vk::ObjectType::eEvent);
    e_vk_ObjectType.value("QUERY_POOL", ::vk::ObjectType::eQueryPool);
    e_vk_ObjectType.value("BUFFER_VIEW", ::vk::ObjectType::eBufferView);
    e_vk_ObjectType.value("IMAGE_VIEW", ::vk::ObjectType::eImageView);
    e_vk_ObjectType.value("SHADER_MODULE", ::vk::ObjectType::eShaderModule);
    e_vk_ObjectType.value("PIPELINE_CACHE", ::vk::ObjectType::ePipelineCache);
    e_vk_ObjectType.value("PIPELINE_LAYOUT", ::vk::ObjectType::ePipelineLayout);
    e_vk_ObjectType.value("RENDER_PASS", ::vk::ObjectType::eRenderPass);
    e_vk_ObjectType.value("PIPELINE", ::vk::ObjectType::ePipeline);
    e_vk_ObjectType.value("DESCRIPTOR_SET_LAYOUT", ::vk::ObjectType::eDescriptorSetLayout);
    e_vk_ObjectType.value("SAMPLER", ::vk::ObjectType::eSampler);
    e_vk_ObjectType.value("DESCRIPTOR_POOL", ::vk::ObjectType::eDescriptorPool);
    e_vk_ObjectType.value("DESCRIPTOR_SET", ::vk::ObjectType::eDescriptorSet);
    e_vk_ObjectType.value("FRAMEBUFFER", ::vk::ObjectType::eFramebuffer);
    e_vk_ObjectType.value("COMMAND_POOL", ::vk::ObjectType::eCommandPool);
    e_vk_ObjectType.value("SAMPLER_YCBCR_CONVERSION", ::vk::ObjectType::eSamplerYcbcrConversion);
    e_vk_ObjectType.value("DESCRIPTOR_UPDATE_TEMPLATE", ::vk::ObjectType::eDescriptorUpdateTemplate);
    e_vk_ObjectType.value("PRIVATE_DATA_SLOT", ::vk::ObjectType::ePrivateDataSlot);
    e_vk_ObjectType.value("SURFACE_KHR", ::vk::ObjectType::eSurfaceKHR);
    e_vk_ObjectType.value("SWAPCHAIN_KHR", ::vk::ObjectType::eSwapchainKHR);
    e_vk_ObjectType.value("DISPLAY_KHR", ::vk::ObjectType::eDisplayKHR);
    e_vk_ObjectType.value("DISPLAY_MODE_KHR", ::vk::ObjectType::eDisplayModeKHR);
    e_vk_ObjectType.value("DEBUG_REPORT_CALLBACK_EXT", ::vk::ObjectType::eDebugReportCallbackEXT);
    e_vk_ObjectType.value("VIDEO_SESSION_KHR", ::vk::ObjectType::eVideoSessionKHR);
    e_vk_ObjectType.value("VIDEO_SESSION_PARAMETERS_KHR", ::vk::ObjectType::eVideoSessionParametersKHR);
    e_vk_ObjectType.value("CU_MODULE_NVX", ::vk::ObjectType::eCuModuleNVX);
    e_vk_ObjectType.value("CU_FUNCTION_NVX", ::vk::ObjectType::eCuFunctionNVX);
    e_vk_ObjectType.value("DESCRIPTOR_UPDATE_TEMPLATE_KHR", ::vk::ObjectType::eDescriptorUpdateTemplateKHR);
    e_vk_ObjectType.value("DEBUG_UTILS_MESSENGER_EXT", ::vk::ObjectType::eDebugUtilsMessengerEXT);
    e_vk_ObjectType.value("ACCELERATION_STRUCTURE_KHR", ::vk::ObjectType::eAccelerationStructureKHR);
    e_vk_ObjectType.value("SAMPLER_YCBCR_CONVERSION_KHR", ::vk::ObjectType::eSamplerYcbcrConversionKHR);
    e_vk_ObjectType.value("VALIDATION_CACHE_EXT", ::vk::ObjectType::eValidationCacheEXT);
    e_vk_ObjectType.value("ACCELERATION_STRUCTURE_NV", ::vk::ObjectType::eAccelerationStructureNV);
    e_vk_ObjectType.value("PERFORMANCE_CONFIGURATION_INTEL", ::vk::ObjectType::ePerformanceConfigurationINTEL);
    e_vk_ObjectType.value("DEFERRED_OPERATION_KHR", ::vk::ObjectType::eDeferredOperationKHR);
    e_vk_ObjectType.value("INDIRECT_COMMANDS_LAYOUT_NV", ::vk::ObjectType::eIndirectCommandsLayoutNV);
    e_vk_ObjectType.value("PRIVATE_DATA_SLOT_EXT", ::vk::ObjectType::ePrivateDataSlotEXT);
    e_vk_ObjectType.value("MICROMAP_EXT", ::vk::ObjectType::eMicromapEXT);
    e_vk_ObjectType.value("OPTICAL_FLOW_SESSION_NV", ::vk::ObjectType::eOpticalFlowSessionNV);
    e_vk_ObjectType.value("SHADER_EXT", ::vk::ObjectType::eShaderEXT);

    e_vk_PhysicalDeviceType.value("OTHER", ::vk::PhysicalDeviceType::eOther);
    e_vk_PhysicalDeviceType.value("INTEGRATED_GPU", ::vk::PhysicalDeviceType::eIntegratedGpu);
    e_vk_PhysicalDeviceType.value("DISCRETE_GPU", ::vk::PhysicalDeviceType::eDiscreteGpu);
    e_vk_PhysicalDeviceType.value("VIRTUAL_GPU", ::vk::PhysicalDeviceType::eVirtualGpu);
    e_vk_PhysicalDeviceType.value("CPU", ::vk::PhysicalDeviceType::eCpu);

    e_vk_PipelineBindPoint.value("GRAPHICS", ::vk::PipelineBindPoint::eGraphics);
    e_vk_PipelineBindPoint.value("COMPUTE", ::vk::PipelineBindPoint::eCompute);
    e_vk_PipelineBindPoint.value("RAY_TRACING_KHR", ::vk::PipelineBindPoint::eRayTracingKHR);
    e_vk_PipelineBindPoint.value("RAY_TRACING_NV", ::vk::PipelineBindPoint::eRayTracingNV);
    e_vk_PipelineBindPoint.value("SUBPASS_SHADING_HUAWEI", ::vk::PipelineBindPoint::eSubpassShadingHUAWEI);

    e_vk_PipelineCacheCreateFlagBits.value("EXTERNALLY_SYNCHRONIZED", ::vk::PipelineCacheCreateFlagBits::eExternallySynchronized);
    e_vk_PipelineCacheCreateFlagBits.value("EXTERNALLY_SYNCHRONIZED_EXT", ::vk::PipelineCacheCreateFlagBits::eExternallySynchronizedEXT);

    e_vk_PipelineCacheHeaderVersion.value("ONE", ::vk::PipelineCacheHeaderVersion::eOne);

    e_vk_PipelineColorBlendStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_ACCESS_ARM", ::vk::PipelineColorBlendStateCreateFlagBits::eRasterizationOrderAttachmentAccessARM);
    e_vk_PipelineColorBlendStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXT", ::vk::PipelineColorBlendStateCreateFlagBits::eRasterizationOrderAttachmentAccessEXT);

    e_vk_PipelineCreateFlagBits.value("DISABLE_OPTIMIZATION", ::vk::PipelineCreateFlagBits::eDisableOptimization);
    e_vk_PipelineCreateFlagBits.value("ALLOW_DERIVATIVES", ::vk::PipelineCreateFlagBits::eAllowDerivatives);
    e_vk_PipelineCreateFlagBits.value("DERIVATIVE", ::vk::PipelineCreateFlagBits::eDerivative);
    e_vk_PipelineCreateFlagBits.value("VIEW_INDEX_FROM_DEVICE_INDEX", ::vk::PipelineCreateFlagBits::eViewIndexFromDeviceIndex);
    e_vk_PipelineCreateFlagBits.value("DISPATCH_BASE", ::vk::PipelineCreateFlagBits::eDispatchBase);
    e_vk_PipelineCreateFlagBits.value("FAIL_ON_PIPELINE_COMPILE_REQUIRED", ::vk::PipelineCreateFlagBits::eFailOnPipelineCompileRequired);
    e_vk_PipelineCreateFlagBits.value("EARLY_RETURN_ON_FAILURE", ::vk::PipelineCreateFlagBits::eEarlyReturnOnFailure);
    e_vk_PipelineCreateFlagBits.value("RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", ::vk::PipelineCreateFlagBits::eRenderingFragmentShadingRateAttachmentKHR);
    e_vk_PipelineCreateFlagBits.value("VK_PIPELINE_RASTERIZATION_STATE_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", ::vk::PipelineCreateFlagBits::eVkPipelineRasterizationStateCreateFragmentShadingRateAttachmentKHR);
    e_vk_PipelineCreateFlagBits.value("RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_EXT", ::vk::PipelineCreateFlagBits::eRenderingFragmentDensityMapAttachmentEXT);
    e_vk_PipelineCreateFlagBits.value("VK_PIPELINE_RASTERIZATION_STATE_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_EXT", ::vk::PipelineCreateFlagBits::eVkPipelineRasterizationStateCreateFragmentDensityMapAttachmentEXT);
    e_vk_PipelineCreateFlagBits.value("VIEW_INDEX_FROM_DEVICE_INDEX_KHR", ::vk::PipelineCreateFlagBits::eViewIndexFromDeviceIndexKHR);
    e_vk_PipelineCreateFlagBits.value("DISPATCH_BASE_KHR", ::vk::PipelineCreateFlagBits::eDispatchBaseKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_KHR", ::vk::PipelineCreateFlagBits::eRayTracingNoNullAnyHitShadersKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_KHR", ::vk::PipelineCreateFlagBits::eRayTracingNoNullClosestHitShadersKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_NO_NULL_MISS_SHADERS_KHR", ::vk::PipelineCreateFlagBits::eRayTracingNoNullMissShadersKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_KHR", ::vk::PipelineCreateFlagBits::eRayTracingNoNullIntersectionShadersKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_SKIP_TRIANGLES_KHR", ::vk::PipelineCreateFlagBits::eRayTracingSkipTrianglesKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_SKIP_AABBS_KHR", ::vk::PipelineCreateFlagBits::eRayTracingSkipAabbsKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_KHR", ::vk::PipelineCreateFlagBits::eRayTracingShaderGroupHandleCaptureReplayKHR);
    e_vk_PipelineCreateFlagBits.value("DEFER_COMPILE_NV", ::vk::PipelineCreateFlagBits::eDeferCompileNV);
    e_vk_PipelineCreateFlagBits.value("CAPTURE_STATISTICS_KHR", ::vk::PipelineCreateFlagBits::eCaptureStatisticsKHR);
    e_vk_PipelineCreateFlagBits.value("CAPTURE_INTERNAL_REPRESENTATIONS_KHR", ::vk::PipelineCreateFlagBits::eCaptureInternalRepresentationsKHR);
    e_vk_PipelineCreateFlagBits.value("INDIRECT_BINDABLE_NV", ::vk::PipelineCreateFlagBits::eIndirectBindableNV);
    e_vk_PipelineCreateFlagBits.value("LIBRARY_KHR", ::vk::PipelineCreateFlagBits::eLibraryKHR);
    e_vk_PipelineCreateFlagBits.value("FAIL_ON_PIPELINE_COMPILE_REQUIRED_EXT", ::vk::PipelineCreateFlagBits::eFailOnPipelineCompileRequiredEXT);
    e_vk_PipelineCreateFlagBits.value("EARLY_RETURN_ON_FAILURE_EXT", ::vk::PipelineCreateFlagBits::eEarlyReturnOnFailureEXT);
    e_vk_PipelineCreateFlagBits.value("DESCRIPTOR_BUFFER_EXT", ::vk::PipelineCreateFlagBits::eDescriptorBufferEXT);
    e_vk_PipelineCreateFlagBits.value("RETAIN_LINK_TIME_OPTIMIZATION_INFO_EXT", ::vk::PipelineCreateFlagBits::eRetainLinkTimeOptimizationInfoEXT);
    e_vk_PipelineCreateFlagBits.value("LINK_TIME_OPTIMIZATION_EXT", ::vk::PipelineCreateFlagBits::eLinkTimeOptimizationEXT);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_ALLOW_MOTION_NV", ::vk::PipelineCreateFlagBits::eRayTracingAllowMotionNV);
    e_vk_PipelineCreateFlagBits.value("COLOR_ATTACHMENT_FEEDBACK_LOOP_EXT", ::vk::PipelineCreateFlagBits::eColorAttachmentFeedbackLoopEXT);
    e_vk_PipelineCreateFlagBits.value("DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_EXT", ::vk::PipelineCreateFlagBits::eDepthStencilAttachmentFeedbackLoopEXT);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_OPACITY_MICROMAP_EXT", ::vk::PipelineCreateFlagBits::eRayTracingOpacityMicromapEXT);
    e_vk_PipelineCreateFlagBits.value("NO_PROTECTED_ACCESS_EXT", ::vk::PipelineCreateFlagBits::eNoProtectedAccessEXT);
    e_vk_PipelineCreateFlagBits.value("PROTECTED_ACCESS_ONLY_EXT", ::vk::PipelineCreateFlagBits::eProtectedAccessOnlyEXT);

    e_vk_PipelineDepthStencilStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_ARM", ::vk::PipelineDepthStencilStateCreateFlagBits::eRasterizationOrderAttachmentDepthAccessARM);
    e_vk_PipelineDepthStencilStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_ARM", ::vk::PipelineDepthStencilStateCreateFlagBits::eRasterizationOrderAttachmentStencilAccessARM);
    e_vk_PipelineDepthStencilStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_EXT", ::vk::PipelineDepthStencilStateCreateFlagBits::eRasterizationOrderAttachmentDepthAccessEXT);
    e_vk_PipelineDepthStencilStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_EXT", ::vk::PipelineDepthStencilStateCreateFlagBits::eRasterizationOrderAttachmentStencilAccessEXT);



    e_vk_PipelineLayoutCreateFlagBits.value("INDEPENDENT_SETS_EXT", ::vk::PipelineLayoutCreateFlagBits::eIndependentSetsEXT);



    e_vk_PipelineShaderStageCreateFlagBits.value("ALLOW_VARYING_SUBGROUP_SIZE", ::vk::PipelineShaderStageCreateFlagBits::eAllowVaryingSubgroupSize);
    e_vk_PipelineShaderStageCreateFlagBits.value("REQUIRE_FULL_SUBGROUPS", ::vk::PipelineShaderStageCreateFlagBits::eRequireFullSubgroups);
    e_vk_PipelineShaderStageCreateFlagBits.value("ALLOW_VARYING_SUBGROUP_SIZE_EXT", ::vk::PipelineShaderStageCreateFlagBits::eAllowVaryingSubgroupSizeEXT);
    e_vk_PipelineShaderStageCreateFlagBits.value("REQUIRE_FULL_SUBGROUPS_EXT", ::vk::PipelineShaderStageCreateFlagBits::eRequireFullSubgroupsEXT);

    e_vk_PipelineStageFlagBits.value("TOP_OF_PIPE", ::vk::PipelineStageFlagBits::eTopOfPipe);
    e_vk_PipelineStageFlagBits.value("DRAW_INDIRECT", ::vk::PipelineStageFlagBits::eDrawIndirect);
    e_vk_PipelineStageFlagBits.value("VERTEX_INPUT", ::vk::PipelineStageFlagBits::eVertexInput);
    e_vk_PipelineStageFlagBits.value("VERTEX_SHADER", ::vk::PipelineStageFlagBits::eVertexShader);
    e_vk_PipelineStageFlagBits.value("TESSELLATION_CONTROL_SHADER", ::vk::PipelineStageFlagBits::eTessellationControlShader);
    e_vk_PipelineStageFlagBits.value("TESSELLATION_EVALUATION_SHADER", ::vk::PipelineStageFlagBits::eTessellationEvaluationShader);
    e_vk_PipelineStageFlagBits.value("GEOMETRY_SHADER", ::vk::PipelineStageFlagBits::eGeometryShader);
    e_vk_PipelineStageFlagBits.value("FRAGMENT_SHADER", ::vk::PipelineStageFlagBits::eFragmentShader);
    e_vk_PipelineStageFlagBits.value("EARLY_FRAGMENT_TESTS", ::vk::PipelineStageFlagBits::eEarlyFragmentTests);
    e_vk_PipelineStageFlagBits.value("LATE_FRAGMENT_TESTS", ::vk::PipelineStageFlagBits::eLateFragmentTests);
    e_vk_PipelineStageFlagBits.value("COLOR_ATTACHMENT_OUTPUT", ::vk::PipelineStageFlagBits::eColorAttachmentOutput);
    e_vk_PipelineStageFlagBits.value("COMPUTE_SHADER", ::vk::PipelineStageFlagBits::eComputeShader);
    e_vk_PipelineStageFlagBits.value("TRANSFER", ::vk::PipelineStageFlagBits::eTransfer);
    e_vk_PipelineStageFlagBits.value("BOTTOM_OF_PIPE", ::vk::PipelineStageFlagBits::eBottomOfPipe);
    e_vk_PipelineStageFlagBits.value("HOST", ::vk::PipelineStageFlagBits::eHost);
    e_vk_PipelineStageFlagBits.value("ALL_GRAPHICS", ::vk::PipelineStageFlagBits::eAllGraphics);
    e_vk_PipelineStageFlagBits.value("ALL_COMMANDS", ::vk::PipelineStageFlagBits::eAllCommands);
    e_vk_PipelineStageFlagBits.value("NONE", ::vk::PipelineStageFlagBits::eNone);
    e_vk_PipelineStageFlagBits.value("TRANSFORM_FEEDBACK_EXT", ::vk::PipelineStageFlagBits::eTransformFeedbackEXT);
    e_vk_PipelineStageFlagBits.value("CONDITIONAL_RENDERING_EXT", ::vk::PipelineStageFlagBits::eConditionalRenderingEXT);
    e_vk_PipelineStageFlagBits.value("ACCELERATION_STRUCTURE_BUILD_KHR", ::vk::PipelineStageFlagBits::eAccelerationStructureBuildKHR);
    e_vk_PipelineStageFlagBits.value("RAY_TRACING_SHADER_KHR", ::vk::PipelineStageFlagBits::eRayTracingShaderKHR);
    e_vk_PipelineStageFlagBits.value("SHADING_RATE_IMAGE_NV", ::vk::PipelineStageFlagBits::eShadingRateImageNV);
    e_vk_PipelineStageFlagBits.value("RAY_TRACING_SHADER_NV", ::vk::PipelineStageFlagBits::eRayTracingShaderNV);
    e_vk_PipelineStageFlagBits.value("ACCELERATION_STRUCTURE_BUILD_NV", ::vk::PipelineStageFlagBits::eAccelerationStructureBuildNV);
    e_vk_PipelineStageFlagBits.value("TASK_SHADER_NV", ::vk::PipelineStageFlagBits::eTaskShaderNV);
    e_vk_PipelineStageFlagBits.value("MESH_SHADER_NV", ::vk::PipelineStageFlagBits::eMeshShaderNV);
    e_vk_PipelineStageFlagBits.value("FRAGMENT_DENSITY_PROCESS_EXT", ::vk::PipelineStageFlagBits::eFragmentDensityProcessEXT);
    e_vk_PipelineStageFlagBits.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", ::vk::PipelineStageFlagBits::eFragmentShadingRateAttachmentKHR);
    e_vk_PipelineStageFlagBits.value("COMMAND_PREPROCESS_NV", ::vk::PipelineStageFlagBits::eCommandPreprocessNV);
    e_vk_PipelineStageFlagBits.value("NONE_KHR", ::vk::PipelineStageFlagBits::eNoneKHR);
    e_vk_PipelineStageFlagBits.value("TASK_SHADER_EXT", ::vk::PipelineStageFlagBits::eTaskShaderEXT);
    e_vk_PipelineStageFlagBits.value("MESH_SHADER_EXT", ::vk::PipelineStageFlagBits::eMeshShaderEXT);




    e_vk_PolygonMode.value("FILL", ::vk::PolygonMode::eFill);
    e_vk_PolygonMode.value("LINE", ::vk::PolygonMode::eLine);
    e_vk_PolygonMode.value("POINT", ::vk::PolygonMode::ePoint);
    e_vk_PolygonMode.value("FILL_RECTANGLE_NV", ::vk::PolygonMode::eFillRectangleNV);

    e_vk_PrimitiveTopology.value("POINT_LIST", ::vk::PrimitiveTopology::ePointList);
    e_vk_PrimitiveTopology.value("LINE_LIST", ::vk::PrimitiveTopology::eLineList);
    e_vk_PrimitiveTopology.value("LINE_STRIP", ::vk::PrimitiveTopology::eLineStrip);
    e_vk_PrimitiveTopology.value("TRIANGLE_LIST", ::vk::PrimitiveTopology::eTriangleList);
    e_vk_PrimitiveTopology.value("TRIANGLE_STRIP", ::vk::PrimitiveTopology::eTriangleStrip);
    e_vk_PrimitiveTopology.value("TRIANGLE_FAN", ::vk::PrimitiveTopology::eTriangleFan);
    e_vk_PrimitiveTopology.value("LINE_LIST_WITH_ADJACENCY", ::vk::PrimitiveTopology::eLineListWithAdjacency);
    e_vk_PrimitiveTopology.value("LINE_STRIP_WITH_ADJACENCY", ::vk::PrimitiveTopology::eLineStripWithAdjacency);
    e_vk_PrimitiveTopology.value("TRIANGLE_LIST_WITH_ADJACENCY", ::vk::PrimitiveTopology::eTriangleListWithAdjacency);
    e_vk_PrimitiveTopology.value("TRIANGLE_STRIP_WITH_ADJACENCY", ::vk::PrimitiveTopology::eTriangleStripWithAdjacency);
    e_vk_PrimitiveTopology.value("PATCH_LIST", ::vk::PrimitiveTopology::ePatchList);

    e_vk_QueryControlFlagBits.value("PRECISE", ::vk::QueryControlFlagBits::ePrecise);

    e_vk_QueryPipelineStatisticFlagBits.value("INPUT_ASSEMBLY_VERTICES", ::vk::QueryPipelineStatisticFlagBits::eInputAssemblyVertices);
    e_vk_QueryPipelineStatisticFlagBits.value("INPUT_ASSEMBLY_PRIMITIVES", ::vk::QueryPipelineStatisticFlagBits::eInputAssemblyPrimitives);
    e_vk_QueryPipelineStatisticFlagBits.value("VERTEX_SHADER_INVOCATIONS", ::vk::QueryPipelineStatisticFlagBits::eVertexShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("GEOMETRY_SHADER_INVOCATIONS", ::vk::QueryPipelineStatisticFlagBits::eGeometryShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("GEOMETRY_SHADER_PRIMITIVES", ::vk::QueryPipelineStatisticFlagBits::eGeometryShaderPrimitives);
    e_vk_QueryPipelineStatisticFlagBits.value("CLIPPING_INVOCATIONS", ::vk::QueryPipelineStatisticFlagBits::eClippingInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("CLIPPING_PRIMITIVES", ::vk::QueryPipelineStatisticFlagBits::eClippingPrimitives);
    e_vk_QueryPipelineStatisticFlagBits.value("FRAGMENT_SHADER_INVOCATIONS", ::vk::QueryPipelineStatisticFlagBits::eFragmentShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("TESSELLATION_CONTROL_SHADER_PATCHES", ::vk::QueryPipelineStatisticFlagBits::eTessellationControlShaderPatches);
    e_vk_QueryPipelineStatisticFlagBits.value("TESSELLATION_EVALUATION_SHADER_INVOCATIONS", ::vk::QueryPipelineStatisticFlagBits::eTessellationEvaluationShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("COMPUTE_SHADER_INVOCATIONS", ::vk::QueryPipelineStatisticFlagBits::eComputeShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("TASK_SHADER_INVOCATIONS_EXT", ::vk::QueryPipelineStatisticFlagBits::eTaskShaderInvocationsEXT);
    e_vk_QueryPipelineStatisticFlagBits.value("MESH_SHADER_INVOCATIONS_EXT", ::vk::QueryPipelineStatisticFlagBits::eMeshShaderInvocationsEXT);
    e_vk_QueryPipelineStatisticFlagBits.value("CLUSTER_CULLING_SHADER_INVOCATIONS_HUAWEI", ::vk::QueryPipelineStatisticFlagBits::eClusterCullingShaderInvocationsHUAWEI);


    e_vk_QueryResultFlagBits.value("e64", ::vk::QueryResultFlagBits::e64);
    e_vk_QueryResultFlagBits.value("WAIT", ::vk::QueryResultFlagBits::eWait);
    e_vk_QueryResultFlagBits.value("WITH_AVAILABILITY", ::vk::QueryResultFlagBits::eWithAvailability);
    e_vk_QueryResultFlagBits.value("PARTIAL", ::vk::QueryResultFlagBits::ePartial);
    e_vk_QueryResultFlagBits.value("WITH_STATUS_KHR", ::vk::QueryResultFlagBits::eWithStatusKHR);

    e_vk_QueryType.value("OCCLUSION", ::vk::QueryType::eOcclusion);
    e_vk_QueryType.value("PIPELINE_STATISTICS", ::vk::QueryType::ePipelineStatistics);
    e_vk_QueryType.value("TIMESTAMP", ::vk::QueryType::eTimestamp);
    e_vk_QueryType.value("RESULT_STATUS_ONLY_KHR", ::vk::QueryType::eResultStatusOnlyKHR);
    e_vk_QueryType.value("TRANSFORM_FEEDBACK_STREAM_EXT", ::vk::QueryType::eTransformFeedbackStreamEXT);
    e_vk_QueryType.value("PERFORMANCE_QUERY_KHR", ::vk::QueryType::ePerformanceQueryKHR);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR", ::vk::QueryType::eAccelerationStructureCompactedSizeKHR);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR", ::vk::QueryType::eAccelerationStructureSerializationSizeKHR);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV", ::vk::QueryType::eAccelerationStructureCompactedSizeNV);
    e_vk_QueryType.value("PERFORMANCE_QUERY_INTEL", ::vk::QueryType::ePerformanceQueryINTEL);
    e_vk_QueryType.value("VIDEO_ENCODE_FEEDBACK_KHR", ::vk::QueryType::eVideoEncodeFeedbackKHR);
    e_vk_QueryType.value("MESH_PRIMITIVES_GENERATED_EXT", ::vk::QueryType::eMeshPrimitivesGeneratedEXT);
    e_vk_QueryType.value("PRIMITIVES_GENERATED_EXT", ::vk::QueryType::ePrimitivesGeneratedEXT);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_SERIALIZATION_BOTTOM_LEVEL_POINTERS_KHR", ::vk::QueryType::eAccelerationStructureSerializationBottomLevelPointersKHR);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_SIZE_KHR", ::vk::QueryType::eAccelerationStructureSizeKHR);
    e_vk_QueryType.value("MICROMAP_SERIALIZATION_SIZE_EXT", ::vk::QueryType::eMicromapSerializationSizeEXT);
    e_vk_QueryType.value("MICROMAP_COMPACTED_SIZE_EXT", ::vk::QueryType::eMicromapCompactedSizeEXT);

    e_vk_QueueFlagBits.value("GRAPHICS", ::vk::QueueFlagBits::eGraphics);
    e_vk_QueueFlagBits.value("COMPUTE", ::vk::QueueFlagBits::eCompute);
    e_vk_QueueFlagBits.value("TRANSFER", ::vk::QueueFlagBits::eTransfer);
    e_vk_QueueFlagBits.value("SPARSE_BINDING", ::vk::QueueFlagBits::eSparseBinding);
    e_vk_QueueFlagBits.value("PROTECTED", ::vk::QueueFlagBits::eProtected);
    e_vk_QueueFlagBits.value("VIDEO_DECODE_KHR", ::vk::QueueFlagBits::eVideoDecodeKHR);
    e_vk_QueueFlagBits.value("VIDEO_ENCODE_KHR", ::vk::QueueFlagBits::eVideoEncodeKHR);
    e_vk_QueueFlagBits.value("OPTICAL_FLOW_NV", ::vk::QueueFlagBits::eOpticalFlowNV);

    e_vk_RenderPassCreateFlagBits.value("TRANSFORM_QCOM", ::vk::RenderPassCreateFlagBits::eTransformQCOM);

    e_vk_Result.value("SUCCESS", ::vk::Result::eSuccess);
    e_vk_Result.value("NOT_READY", ::vk::Result::eNotReady);
    e_vk_Result.value("TIMEOUT", ::vk::Result::eTimeout);
    e_vk_Result.value("EVENT_SET", ::vk::Result::eEventSet);
    e_vk_Result.value("EVENT_RESET", ::vk::Result::eEventReset);
    e_vk_Result.value("INCOMPLETE", ::vk::Result::eIncomplete);
    e_vk_Result.value("ERROR_OUT_OF_HOST_MEMORY", ::vk::Result::eErrorOutOfHostMemory);
    e_vk_Result.value("ERROR_OUT_OF_DEVICE_MEMORY", ::vk::Result::eErrorOutOfDeviceMemory);
    e_vk_Result.value("ERROR_INITIALIZATION_FAILED", ::vk::Result::eErrorInitializationFailed);
    e_vk_Result.value("ERROR_DEVICE_LOST", ::vk::Result::eErrorDeviceLost);
    e_vk_Result.value("ERROR_MEMORY_MAP_FAILED", ::vk::Result::eErrorMemoryMapFailed);
    e_vk_Result.value("ERROR_LAYER_NOT_PRESENT", ::vk::Result::eErrorLayerNotPresent);
    e_vk_Result.value("ERROR_EXTENSION_NOT_PRESENT", ::vk::Result::eErrorExtensionNotPresent);
    e_vk_Result.value("ERROR_FEATURE_NOT_PRESENT", ::vk::Result::eErrorFeatureNotPresent);
    e_vk_Result.value("ERROR_INCOMPATIBLE_DRIVER", ::vk::Result::eErrorIncompatibleDriver);
    e_vk_Result.value("ERROR_TOO_MANY_OBJECTS", ::vk::Result::eErrorTooManyObjects);
    e_vk_Result.value("ERROR_FORMAT_NOT_SUPPORTED", ::vk::Result::eErrorFormatNotSupported);
    e_vk_Result.value("ERROR_FRAGMENTED_POOL", ::vk::Result::eErrorFragmentedPool);
    e_vk_Result.value("ERROR_UNKNOWN", ::vk::Result::eErrorUnknown);
    e_vk_Result.value("ERROR_OUT_OF_POOL_MEMORY", ::vk::Result::eErrorOutOfPoolMemory);
    e_vk_Result.value("ERROR_INVALID_EXTERNAL_HANDLE", ::vk::Result::eErrorInvalidExternalHandle);
    e_vk_Result.value("ERROR_FRAGMENTATION", ::vk::Result::eErrorFragmentation);
    e_vk_Result.value("ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS", ::vk::Result::eErrorInvalidOpaqueCaptureAddress);
    e_vk_Result.value("PIPELINE_COMPILE_REQUIRED", ::vk::Result::ePipelineCompileRequired);
    e_vk_Result.value("ERROR_SURFACE_LOST_KHR", ::vk::Result::eErrorSurfaceLostKHR);
    e_vk_Result.value("ERROR_NATIVE_WINDOW_IN_USE_KHR", ::vk::Result::eErrorNativeWindowInUseKHR);
    e_vk_Result.value("SUBOPTIMAL_KHR", ::vk::Result::eSuboptimalKHR);
    e_vk_Result.value("ERROR_OUT_OF_DATE_KHR", ::vk::Result::eErrorOutOfDateKHR);
    e_vk_Result.value("ERROR_INCOMPATIBLE_DISPLAY_KHR", ::vk::Result::eErrorIncompatibleDisplayKHR);
    e_vk_Result.value("ERROR_VALIDATION_FAILED_EXT", ::vk::Result::eErrorValidationFailedEXT);
    e_vk_Result.value("ERROR_INVALID_SHADER_NV", ::vk::Result::eErrorInvalidShaderNV);
    e_vk_Result.value("ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR", ::vk::Result::eErrorImageUsageNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR", ::vk::Result::eErrorVideoPictureLayoutNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR", ::vk::Result::eErrorVideoProfileOperationNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR", ::vk::Result::eErrorVideoProfileFormatNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR", ::vk::Result::eErrorVideoProfileCodecNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR", ::vk::Result::eErrorVideoStdVersionNotSupportedKHR);
    e_vk_Result.value("ERROR_OUT_OF_POOL_MEMORY_KHR", ::vk::Result::eErrorOutOfPoolMemoryKHR);
    e_vk_Result.value("ERROR_INVALID_EXTERNAL_HANDLE_KHR", ::vk::Result::eErrorInvalidExternalHandleKHR);
    e_vk_Result.value("ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT", ::vk::Result::eErrorInvalidDrmFormatModifierPlaneLayoutEXT);
    e_vk_Result.value("ERROR_FRAGMENTATION_EXT", ::vk::Result::eErrorFragmentationEXT);
    e_vk_Result.value("ERROR_NOT_PERMITTED_EXT", ::vk::Result::eErrorNotPermittedEXT);
    e_vk_Result.value("ERROR_NOT_PERMITTED_KHR", ::vk::Result::eErrorNotPermittedKHR);
    e_vk_Result.value("ERROR_INVALID_DEVICE_ADDRESS_EXT", ::vk::Result::eErrorInvalidDeviceAddressEXT);
    e_vk_Result.value("ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR", ::vk::Result::eErrorInvalidOpaqueCaptureAddressKHR);
    e_vk_Result.value("THREAD_IDLE_KHR", ::vk::Result::eThreadIdleKHR);
    e_vk_Result.value("THREAD_DONE_KHR", ::vk::Result::eThreadDoneKHR);
    e_vk_Result.value("OPERATION_DEFERRED_KHR", ::vk::Result::eOperationDeferredKHR);
    e_vk_Result.value("OPERATION_NOT_DEFERRED_KHR", ::vk::Result::eOperationNotDeferredKHR);
    e_vk_Result.value("PIPELINE_COMPILE_REQUIRED_EXT", ::vk::Result::ePipelineCompileRequiredEXT);
    e_vk_Result.value("ERROR_PIPELINE_COMPILE_REQUIRED_EXT", ::vk::Result::eErrorPipelineCompileRequiredEXT);
    e_vk_Result.value("ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR", ::vk::Result::eErrorInvalidVideoStdParametersKHR);
    e_vk_Result.value("ERROR_COMPRESSION_EXHAUSTED_EXT", ::vk::Result::eErrorCompressionExhaustedEXT);
    e_vk_Result.value("ERROR_INCOMPATIBLE_SHADER_BINARY_EXT", ::vk::Result::eErrorIncompatibleShaderBinaryEXT);

    e_vk_SampleCountFlagBits.value("e1", ::vk::SampleCountFlagBits::e1);
    e_vk_SampleCountFlagBits.value("e2", ::vk::SampleCountFlagBits::e2);
    e_vk_SampleCountFlagBits.value("e4", ::vk::SampleCountFlagBits::e4);
    e_vk_SampleCountFlagBits.value("e8", ::vk::SampleCountFlagBits::e8);
    e_vk_SampleCountFlagBits.value("e16", ::vk::SampleCountFlagBits::e16);
    e_vk_SampleCountFlagBits.value("e32", ::vk::SampleCountFlagBits::e32);
    e_vk_SampleCountFlagBits.value("e64", ::vk::SampleCountFlagBits::e64);

    e_vk_SamplerAddressMode.value("REPEAT", ::vk::SamplerAddressMode::eRepeat);
    e_vk_SamplerAddressMode.value("MIRRORED_REPEAT", ::vk::SamplerAddressMode::eMirroredRepeat);
    e_vk_SamplerAddressMode.value("CLAMP_TO_EDGE", ::vk::SamplerAddressMode::eClampToEdge);
    e_vk_SamplerAddressMode.value("CLAMP_TO_BORDER", ::vk::SamplerAddressMode::eClampToBorder);
    e_vk_SamplerAddressMode.value("MIRROR_CLAMP_TO_EDGE", ::vk::SamplerAddressMode::eMirrorClampToEdge);
    e_vk_SamplerAddressMode.value("MIRROR_CLAMP_TO_EDGE_KHR", ::vk::SamplerAddressMode::eMirrorClampToEdgeKHR);

    e_vk_SamplerCreateFlagBits.value("SUBSAMPLED_EXT", ::vk::SamplerCreateFlagBits::eSubsampledEXT);
    e_vk_SamplerCreateFlagBits.value("SUBSAMPLED_COARSE_RECONSTRUCTION_EXT", ::vk::SamplerCreateFlagBits::eSubsampledCoarseReconstructionEXT);
    e_vk_SamplerCreateFlagBits.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", ::vk::SamplerCreateFlagBits::eDescriptorBufferCaptureReplayEXT);
    e_vk_SamplerCreateFlagBits.value("NON_SEAMLESS_CUBE_MAP_EXT", ::vk::SamplerCreateFlagBits::eNonSeamlessCubeMapEXT);
    e_vk_SamplerCreateFlagBits.value("IMAGE_PROCESSING_QCOM", ::vk::SamplerCreateFlagBits::eImageProcessingQCOM);

    e_vk_SamplerMipmapMode.value("NEAREST", ::vk::SamplerMipmapMode::eNearest);
    e_vk_SamplerMipmapMode.value("LINEAR", ::vk::SamplerMipmapMode::eLinear);



    e_vk_ShaderStageFlagBits.value("VERTEX", ::vk::ShaderStageFlagBits::eVertex);
    e_vk_ShaderStageFlagBits.value("TESSELLATION_CONTROL", ::vk::ShaderStageFlagBits::eTessellationControl);
    e_vk_ShaderStageFlagBits.value("TESSELLATION_EVALUATION", ::vk::ShaderStageFlagBits::eTessellationEvaluation);
    e_vk_ShaderStageFlagBits.value("GEOMETRY", ::vk::ShaderStageFlagBits::eGeometry);
    e_vk_ShaderStageFlagBits.value("FRAGMENT", ::vk::ShaderStageFlagBits::eFragment);
    e_vk_ShaderStageFlagBits.value("COMPUTE", ::vk::ShaderStageFlagBits::eCompute);
    e_vk_ShaderStageFlagBits.value("ALL_GRAPHICS", ::vk::ShaderStageFlagBits::eAllGraphics);
    e_vk_ShaderStageFlagBits.value("ALL", ::vk::ShaderStageFlagBits::eAll);
    e_vk_ShaderStageFlagBits.value("RAYGEN_KHR", ::vk::ShaderStageFlagBits::eRaygenKHR);
    e_vk_ShaderStageFlagBits.value("ANY_HIT_KHR", ::vk::ShaderStageFlagBits::eAnyHitKHR);
    e_vk_ShaderStageFlagBits.value("CLOSEST_HIT_KHR", ::vk::ShaderStageFlagBits::eClosestHitKHR);
    e_vk_ShaderStageFlagBits.value("MISS_KHR", ::vk::ShaderStageFlagBits::eMissKHR);
    e_vk_ShaderStageFlagBits.value("INTERSECTION_KHR", ::vk::ShaderStageFlagBits::eIntersectionKHR);
    e_vk_ShaderStageFlagBits.value("CALLABLE_KHR", ::vk::ShaderStageFlagBits::eCallableKHR);
    e_vk_ShaderStageFlagBits.value("RAYGEN_NV", ::vk::ShaderStageFlagBits::eRaygenNV);
    e_vk_ShaderStageFlagBits.value("ANY_HIT_NV", ::vk::ShaderStageFlagBits::eAnyHitNV);
    e_vk_ShaderStageFlagBits.value("CLOSEST_HIT_NV", ::vk::ShaderStageFlagBits::eClosestHitNV);
    e_vk_ShaderStageFlagBits.value("MISS_NV", ::vk::ShaderStageFlagBits::eMissNV);
    e_vk_ShaderStageFlagBits.value("INTERSECTION_NV", ::vk::ShaderStageFlagBits::eIntersectionNV);
    e_vk_ShaderStageFlagBits.value("CALLABLE_NV", ::vk::ShaderStageFlagBits::eCallableNV);
    e_vk_ShaderStageFlagBits.value("TASK_NV", ::vk::ShaderStageFlagBits::eTaskNV);
    e_vk_ShaderStageFlagBits.value("MESH_NV", ::vk::ShaderStageFlagBits::eMeshNV);
    e_vk_ShaderStageFlagBits.value("TASK_EXT", ::vk::ShaderStageFlagBits::eTaskEXT);
    e_vk_ShaderStageFlagBits.value("MESH_EXT", ::vk::ShaderStageFlagBits::eMeshEXT);
    e_vk_ShaderStageFlagBits.value("SUBPASS_SHADING_HUAWEI", ::vk::ShaderStageFlagBits::eSubpassShadingHUAWEI);
    e_vk_ShaderStageFlagBits.value("CLUSTER_CULLING_HUAWEI", ::vk::ShaderStageFlagBits::eClusterCullingHUAWEI);

    e_vk_SharingMode.value("EXCLUSIVE", ::vk::SharingMode::eExclusive);
    e_vk_SharingMode.value("CONCURRENT", ::vk::SharingMode::eConcurrent);

    e_vk_SparseImageFormatFlagBits.value("SINGLE_MIPTAIL", ::vk::SparseImageFormatFlagBits::eSingleMiptail);
    e_vk_SparseImageFormatFlagBits.value("ALIGNED_MIP_SIZE", ::vk::SparseImageFormatFlagBits::eAlignedMipSize);
    e_vk_SparseImageFormatFlagBits.value("NONSTANDARD_BLOCK_SIZE", ::vk::SparseImageFormatFlagBits::eNonstandardBlockSize);

    e_vk_SparseMemoryBindFlagBits.value("METADATA", ::vk::SparseMemoryBindFlagBits::eMetadata);

    e_vk_StencilFaceFlagBits.value("FRONT", ::vk::StencilFaceFlagBits::eFront);
    e_vk_StencilFaceFlagBits.value("BACK", ::vk::StencilFaceFlagBits::eBack);
    e_vk_StencilFaceFlagBits.value("FRONT_AND_BACK", ::vk::StencilFaceFlagBits::eFrontAndBack);
    e_vk_StencilFaceFlagBits.value("VK_STENCIL_FRONT_AND_BACK", ::vk::StencilFaceFlagBits::eVkStencilFrontAndBack);

    e_vk_StencilOp.value("KEEP", ::vk::StencilOp::eKeep);
    e_vk_StencilOp.value("ZERO", ::vk::StencilOp::eZero);
    e_vk_StencilOp.value("REPLACE", ::vk::StencilOp::eReplace);
    e_vk_StencilOp.value("INCREMENT_AND_CLAMP", ::vk::StencilOp::eIncrementAndClamp);
    e_vk_StencilOp.value("DECREMENT_AND_CLAMP", ::vk::StencilOp::eDecrementAndClamp);
    e_vk_StencilOp.value("INVERT", ::vk::StencilOp::eInvert);
    e_vk_StencilOp.value("INCREMENT_AND_WRAP", ::vk::StencilOp::eIncrementAndWrap);
    e_vk_StencilOp.value("DECREMENT_AND_WRAP", ::vk::StencilOp::eDecrementAndWrap);

    e_vk_StructureType.value("APPLICATION_INFO", ::vk::StructureType::eApplicationInfo);
    e_vk_StructureType.value("INSTANCE_CREATE_INFO", ::vk::StructureType::eInstanceCreateInfo);
    e_vk_StructureType.value("DEVICE_QUEUE_CREATE_INFO", ::vk::StructureType::eDeviceQueueCreateInfo);
    e_vk_StructureType.value("DEVICE_CREATE_INFO", ::vk::StructureType::eDeviceCreateInfo);
    e_vk_StructureType.value("SUBMIT_INFO", ::vk::StructureType::eSubmitInfo);
    e_vk_StructureType.value("MEMORY_ALLOCATE_INFO", ::vk::StructureType::eMemoryAllocateInfo);
    e_vk_StructureType.value("MAPPED_MEMORY_RANGE", ::vk::StructureType::eMappedMemoryRange);
    e_vk_StructureType.value("BIND_SPARSE_INFO", ::vk::StructureType::eBindSparseInfo);
    e_vk_StructureType.value("FENCE_CREATE_INFO", ::vk::StructureType::eFenceCreateInfo);
    e_vk_StructureType.value("SEMAPHORE_CREATE_INFO", ::vk::StructureType::eSemaphoreCreateInfo);
    e_vk_StructureType.value("EVENT_CREATE_INFO", ::vk::StructureType::eEventCreateInfo);
    e_vk_StructureType.value("QUERY_POOL_CREATE_INFO", ::vk::StructureType::eQueryPoolCreateInfo);
    e_vk_StructureType.value("BUFFER_CREATE_INFO", ::vk::StructureType::eBufferCreateInfo);
    e_vk_StructureType.value("BUFFER_VIEW_CREATE_INFO", ::vk::StructureType::eBufferViewCreateInfo);
    e_vk_StructureType.value("IMAGE_CREATE_INFO", ::vk::StructureType::eImageCreateInfo);
    e_vk_StructureType.value("IMAGE_VIEW_CREATE_INFO", ::vk::StructureType::eImageViewCreateInfo);
    e_vk_StructureType.value("SHADER_MODULE_CREATE_INFO", ::vk::StructureType::eShaderModuleCreateInfo);
    e_vk_StructureType.value("PIPELINE_CACHE_CREATE_INFO", ::vk::StructureType::ePipelineCacheCreateInfo);
    e_vk_StructureType.value("PIPELINE_SHADER_STAGE_CREATE_INFO", ::vk::StructureType::ePipelineShaderStageCreateInfo);
    e_vk_StructureType.value("PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO", ::vk::StructureType::ePipelineVertexInputStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO", ::vk::StructureType::ePipelineInputAssemblyStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_TESSELLATION_STATE_CREATE_INFO", ::vk::StructureType::ePipelineTessellationStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_STATE_CREATE_INFO", ::vk::StructureType::ePipelineViewportStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_STATE_CREATE_INFO", ::vk::StructureType::ePipelineRasterizationStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_MULTISAMPLE_STATE_CREATE_INFO", ::vk::StructureType::ePipelineMultisampleStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO", ::vk::StructureType::ePipelineDepthStencilStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_COLOR_BLEND_STATE_CREATE_INFO", ::vk::StructureType::ePipelineColorBlendStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_DYNAMIC_STATE_CREATE_INFO", ::vk::StructureType::ePipelineDynamicStateCreateInfo);
    e_vk_StructureType.value("GRAPHICS_PIPELINE_CREATE_INFO", ::vk::StructureType::eGraphicsPipelineCreateInfo);
    e_vk_StructureType.value("COMPUTE_PIPELINE_CREATE_INFO", ::vk::StructureType::eComputePipelineCreateInfo);
    e_vk_StructureType.value("PIPELINE_LAYOUT_CREATE_INFO", ::vk::StructureType::ePipelineLayoutCreateInfo);
    e_vk_StructureType.value("SAMPLER_CREATE_INFO", ::vk::StructureType::eSamplerCreateInfo);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_CREATE_INFO", ::vk::StructureType::eDescriptorSetLayoutCreateInfo);
    e_vk_StructureType.value("DESCRIPTOR_POOL_CREATE_INFO", ::vk::StructureType::eDescriptorPoolCreateInfo);
    e_vk_StructureType.value("DESCRIPTOR_SET_ALLOCATE_INFO", ::vk::StructureType::eDescriptorSetAllocateInfo);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET", ::vk::StructureType::eWriteDescriptorSet);
    e_vk_StructureType.value("COPY_DESCRIPTOR_SET", ::vk::StructureType::eCopyDescriptorSet);
    e_vk_StructureType.value("FRAMEBUFFER_CREATE_INFO", ::vk::StructureType::eFramebufferCreateInfo);
    e_vk_StructureType.value("RENDER_PASS_CREATE_INFO", ::vk::StructureType::eRenderPassCreateInfo);
    e_vk_StructureType.value("COMMAND_POOL_CREATE_INFO", ::vk::StructureType::eCommandPoolCreateInfo);
    e_vk_StructureType.value("COMMAND_BUFFER_ALLOCATE_INFO", ::vk::StructureType::eCommandBufferAllocateInfo);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_INFO", ::vk::StructureType::eCommandBufferInheritanceInfo);
    e_vk_StructureType.value("COMMAND_BUFFER_BEGIN_INFO", ::vk::StructureType::eCommandBufferBeginInfo);
    e_vk_StructureType.value("RENDER_PASS_BEGIN_INFO", ::vk::StructureType::eRenderPassBeginInfo);
    e_vk_StructureType.value("BUFFER_MEMORY_BARRIER", ::vk::StructureType::eBufferMemoryBarrier);
    e_vk_StructureType.value("IMAGE_MEMORY_BARRIER", ::vk::StructureType::eImageMemoryBarrier);
    e_vk_StructureType.value("MEMORY_BARRIER", ::vk::StructureType::eMemoryBarrier);
    e_vk_StructureType.value("LOADER_INSTANCE_CREATE_INFO", ::vk::StructureType::eLoaderInstanceCreateInfo);
    e_vk_StructureType.value("LOADER_DEVICE_CREATE_INFO", ::vk::StructureType::eLoaderDeviceCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_PROPERTIES", ::vk::StructureType::ePhysicalDeviceSubgroupProperties);
    e_vk_StructureType.value("BIND_BUFFER_MEMORY_INFO", ::vk::StructureType::eBindBufferMemoryInfo);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_INFO", ::vk::StructureType::eBindImageMemoryInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_16_BIT_STORAGE_FEATURES", ::vk::StructureType::ePhysicalDevice16BitStorageFeatures);
    e_vk_StructureType.value("MEMORY_DEDICATED_REQUIREMENTS", ::vk::StructureType::eMemoryDedicatedRequirements);
    e_vk_StructureType.value("MEMORY_DEDICATED_ALLOCATE_INFO", ::vk::StructureType::eMemoryDedicatedAllocateInfo);
    e_vk_StructureType.value("MEMORY_ALLOCATE_FLAGS_INFO", ::vk::StructureType::eMemoryAllocateFlagsInfo);
    e_vk_StructureType.value("DEVICE_GROUP_RENDER_PASS_BEGIN_INFO", ::vk::StructureType::eDeviceGroupRenderPassBeginInfo);
    e_vk_StructureType.value("DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO", ::vk::StructureType::eDeviceGroupCommandBufferBeginInfo);
    e_vk_StructureType.value("DEVICE_GROUP_SUBMIT_INFO", ::vk::StructureType::eDeviceGroupSubmitInfo);
    e_vk_StructureType.value("DEVICE_GROUP_BIND_SPARSE_INFO", ::vk::StructureType::eDeviceGroupBindSparseInfo);
    e_vk_StructureType.value("BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO", ::vk::StructureType::eBindBufferMemoryDeviceGroupInfo);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO", ::vk::StructureType::eBindImageMemoryDeviceGroupInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GROUP_PROPERTIES", ::vk::StructureType::ePhysicalDeviceGroupProperties);
    e_vk_StructureType.value("DEVICE_GROUP_DEVICE_CREATE_INFO", ::vk::StructureType::eDeviceGroupDeviceCreateInfo);
    e_vk_StructureType.value("BUFFER_MEMORY_REQUIREMENTS_INFO_2", ::vk::StructureType::eBufferMemoryRequirementsInfo2);
    e_vk_StructureType.value("IMAGE_MEMORY_REQUIREMENTS_INFO_2", ::vk::StructureType::eImageMemoryRequirementsInfo2);
    e_vk_StructureType.value("IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2", ::vk::StructureType::eImageSparseMemoryRequirementsInfo2);
    e_vk_StructureType.value("MEMORY_REQUIREMENTS_2", ::vk::StructureType::eMemoryRequirements2);
    e_vk_StructureType.value("SPARSE_IMAGE_MEMORY_REQUIREMENTS_2", ::vk::StructureType::eSparseImageMemoryRequirements2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FEATURES_2", ::vk::StructureType::ePhysicalDeviceFeatures2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROPERTIES_2", ::vk::StructureType::ePhysicalDeviceProperties2);
    e_vk_StructureType.value("FORMAT_PROPERTIES_2", ::vk::StructureType::eFormatProperties2);
    e_vk_StructureType.value("IMAGE_FORMAT_PROPERTIES_2", ::vk::StructureType::eImageFormatProperties2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2", ::vk::StructureType::ePhysicalDeviceImageFormatInfo2);
    e_vk_StructureType.value("QUEUE_FAMILY_PROPERTIES_2", ::vk::StructureType::eQueueFamilyProperties2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_PROPERTIES_2", ::vk::StructureType::ePhysicalDeviceMemoryProperties2);
    e_vk_StructureType.value("SPARSE_IMAGE_FORMAT_PROPERTIES_2", ::vk::StructureType::eSparseImageFormatProperties2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2", ::vk::StructureType::ePhysicalDeviceSparseImageFormatInfo2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES", ::vk::StructureType::ePhysicalDevicePointClippingProperties);
    e_vk_StructureType.value("RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO", ::vk::StructureType::eRenderPassInputAttachmentAspectCreateInfo);
    e_vk_StructureType.value("IMAGE_VIEW_USAGE_CREATE_INFO", ::vk::StructureType::eImageViewUsageCreateInfo);
    e_vk_StructureType.value("PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO", ::vk::StructureType::ePipelineTessellationDomainOriginStateCreateInfo);
    e_vk_StructureType.value("RENDER_PASS_MULTIVIEW_CREATE_INFO", ::vk::StructureType::eRenderPassMultiviewCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_FEATURES", ::vk::StructureType::ePhysicalDeviceMultiviewFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES", ::vk::StructureType::ePhysicalDeviceMultiviewProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES", ::vk::StructureType::ePhysicalDeviceVariablePointersFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES", ::vk::StructureType::ePhysicalDeviceVariablePointerFeatures);
    e_vk_StructureType.value("PROTECTED_SUBMIT_INFO", ::vk::StructureType::eProtectedSubmitInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES", ::vk::StructureType::ePhysicalDeviceProtectedMemoryFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES", ::vk::StructureType::ePhysicalDeviceProtectedMemoryProperties);
    e_vk_StructureType.value("DEVICE_QUEUE_INFO_2", ::vk::StructureType::eDeviceQueueInfo2);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_CREATE_INFO", ::vk::StructureType::eSamplerYcbcrConversionCreateInfo);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_INFO", ::vk::StructureType::eSamplerYcbcrConversionInfo);
    e_vk_StructureType.value("BIND_IMAGE_PLANE_MEMORY_INFO", ::vk::StructureType::eBindImagePlaneMemoryInfo);
    e_vk_StructureType.value("IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO", ::vk::StructureType::eImagePlaneMemoryRequirementsInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES", ::vk::StructureType::ePhysicalDeviceSamplerYcbcrConversionFeatures);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES", ::vk::StructureType::eSamplerYcbcrConversionImageFormatProperties);
    e_vk_StructureType.value("DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO", ::vk::StructureType::eDescriptorUpdateTemplateCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO", ::vk::StructureType::ePhysicalDeviceExternalImageFormatInfo);
    e_vk_StructureType.value("EXTERNAL_IMAGE_FORMAT_PROPERTIES", ::vk::StructureType::eExternalImageFormatProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO", ::vk::StructureType::ePhysicalDeviceExternalBufferInfo);
    e_vk_StructureType.value("EXTERNAL_BUFFER_PROPERTIES", ::vk::StructureType::eExternalBufferProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ID_PROPERTIES", ::vk::StructureType::ePhysicalDeviceIdProperties);
    e_vk_StructureType.value("EXTERNAL_MEMORY_BUFFER_CREATE_INFO", ::vk::StructureType::eExternalMemoryBufferCreateInfo);
    e_vk_StructureType.value("EXTERNAL_MEMORY_IMAGE_CREATE_INFO", ::vk::StructureType::eExternalMemoryImageCreateInfo);
    e_vk_StructureType.value("EXPORT_MEMORY_ALLOCATE_INFO", ::vk::StructureType::eExportMemoryAllocateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO", ::vk::StructureType::ePhysicalDeviceExternalFenceInfo);
    e_vk_StructureType.value("EXTERNAL_FENCE_PROPERTIES", ::vk::StructureType::eExternalFenceProperties);
    e_vk_StructureType.value("EXPORT_FENCE_CREATE_INFO", ::vk::StructureType::eExportFenceCreateInfo);
    e_vk_StructureType.value("EXPORT_SEMAPHORE_CREATE_INFO", ::vk::StructureType::eExportSemaphoreCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO", ::vk::StructureType::ePhysicalDeviceExternalSemaphoreInfo);
    e_vk_StructureType.value("EXTERNAL_SEMAPHORE_PROPERTIES", ::vk::StructureType::eExternalSemaphoreProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES", ::vk::StructureType::ePhysicalDeviceMaintenance3Properties);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_SUPPORT", ::vk::StructureType::eDescriptorSetLayoutSupport);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES", ::vk::StructureType::ePhysicalDeviceShaderDrawParametersFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES", ::vk::StructureType::ePhysicalDeviceShaderDrawParameterFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_11_FEATURES", ::vk::StructureType::ePhysicalDeviceVulkan11Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_11_PROPERTIES", ::vk::StructureType::ePhysicalDeviceVulkan11Properties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_12_FEATURES", ::vk::StructureType::ePhysicalDeviceVulkan12Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_12_PROPERTIES", ::vk::StructureType::ePhysicalDeviceVulkan12Properties);
    e_vk_StructureType.value("IMAGE_FORMAT_LIST_CREATE_INFO", ::vk::StructureType::eImageFormatListCreateInfo);
    e_vk_StructureType.value("ATTACHMENT_DESCRIPTION_2", ::vk::StructureType::eAttachmentDescription2);
    e_vk_StructureType.value("ATTACHMENT_REFERENCE_2", ::vk::StructureType::eAttachmentReference2);
    e_vk_StructureType.value("SUBPASS_DESCRIPTION_2", ::vk::StructureType::eSubpassDescription2);
    e_vk_StructureType.value("SUBPASS_DEPENDENCY_2", ::vk::StructureType::eSubpassDependency2);
    e_vk_StructureType.value("RENDER_PASS_CREATE_INFO_2", ::vk::StructureType::eRenderPassCreateInfo2);
    e_vk_StructureType.value("SUBPASS_BEGIN_INFO", ::vk::StructureType::eSubpassBeginInfo);
    e_vk_StructureType.value("SUBPASS_END_INFO", ::vk::StructureType::eSubpassEndInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_8_BIT_STORAGE_FEATURES", ::vk::StructureType::ePhysicalDevice8BitStorageFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DRIVER_PROPERTIES", ::vk::StructureType::ePhysicalDeviceDriverProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_ATOMIC_INT_64_FEATURES", ::vk::StructureType::ePhysicalDeviceShaderAtomicInt64Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_FLOAT_16_INT_8_FEATURES", ::vk::StructureType::ePhysicalDeviceShaderFloat16Int8Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES", ::vk::StructureType::ePhysicalDeviceFloatControlsProperties);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO", ::vk::StructureType::eDescriptorSetLayoutBindingFlagsCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES", ::vk::StructureType::ePhysicalDeviceDescriptorIndexingFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES", ::vk::StructureType::ePhysicalDeviceDescriptorIndexingProperties);
    e_vk_StructureType.value("DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO", ::vk::StructureType::eDescriptorSetVariableDescriptorCountAllocateInfo);
    e_vk_StructureType.value("DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT", ::vk::StructureType::eDescriptorSetVariableDescriptorCountLayoutSupport);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES", ::vk::StructureType::ePhysicalDeviceDepthStencilResolveProperties);
    e_vk_StructureType.value("SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE", ::vk::StructureType::eSubpassDescriptionDepthStencilResolve);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES", ::vk::StructureType::ePhysicalDeviceScalarBlockLayoutFeatures);
    e_vk_StructureType.value("IMAGE_STENCIL_USAGE_CREATE_INFO", ::vk::StructureType::eImageStencilUsageCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES", ::vk::StructureType::ePhysicalDeviceSamplerFilterMinmaxProperties);
    e_vk_StructureType.value("SAMPLER_REDUCTION_MODE_CREATE_INFO", ::vk::StructureType::eSamplerReductionModeCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES", ::vk::StructureType::ePhysicalDeviceVulkanMemoryModelFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES", ::vk::StructureType::ePhysicalDeviceImagelessFramebufferFeatures);
    e_vk_StructureType.value("FRAMEBUFFER_ATTACHMENTS_CREATE_INFO", ::vk::StructureType::eFramebufferAttachmentsCreateInfo);
    e_vk_StructureType.value("FRAMEBUFFER_ATTACHMENT_IMAGE_INFO", ::vk::StructureType::eFramebufferAttachmentImageInfo);
    e_vk_StructureType.value("RENDER_PASS_ATTACHMENT_BEGIN_INFO", ::vk::StructureType::eRenderPassAttachmentBeginInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES", ::vk::StructureType::ePhysicalDeviceUniformBufferStandardLayoutFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES", ::vk::StructureType::ePhysicalDeviceShaderSubgroupExtendedTypesFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES", ::vk::StructureType::ePhysicalDeviceSeparateDepthStencilLayoutsFeatures);
    e_vk_StructureType.value("ATTACHMENT_REFERENCE_STENCIL_LAYOUT", ::vk::StructureType::eAttachmentReferenceStencilLayout);
    e_vk_StructureType.value("ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT", ::vk::StructureType::eAttachmentDescriptionStencilLayout);
    e_vk_StructureType.value("PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES", ::vk::StructureType::ePhysicalDeviceHostQueryResetFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES", ::vk::StructureType::ePhysicalDeviceTimelineSemaphoreFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES", ::vk::StructureType::ePhysicalDeviceTimelineSemaphoreProperties);
    e_vk_StructureType.value("SEMAPHORE_TYPE_CREATE_INFO", ::vk::StructureType::eSemaphoreTypeCreateInfo);
    e_vk_StructureType.value("TIMELINE_SEMAPHORE_SUBMIT_INFO", ::vk::StructureType::eTimelineSemaphoreSubmitInfo);
    e_vk_StructureType.value("SEMAPHORE_WAIT_INFO", ::vk::StructureType::eSemaphoreWaitInfo);
    e_vk_StructureType.value("SEMAPHORE_SIGNAL_INFO", ::vk::StructureType::eSemaphoreSignalInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES", ::vk::StructureType::ePhysicalDeviceBufferDeviceAddressFeatures);
    e_vk_StructureType.value("BUFFER_DEVICE_ADDRESS_INFO", ::vk::StructureType::eBufferDeviceAddressInfo);
    e_vk_StructureType.value("BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO", ::vk::StructureType::eBufferOpaqueCaptureAddressCreateInfo);
    e_vk_StructureType.value("MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO", ::vk::StructureType::eMemoryOpaqueCaptureAddressAllocateInfo);
    e_vk_StructureType.value("DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO", ::vk::StructureType::eDeviceMemoryOpaqueCaptureAddressInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_13_FEATURES", ::vk::StructureType::ePhysicalDeviceVulkan13Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_13_PROPERTIES", ::vk::StructureType::ePhysicalDeviceVulkan13Properties);
    e_vk_StructureType.value("PIPELINE_CREATION_FEEDBACK_CREATE_INFO", ::vk::StructureType::ePipelineCreationFeedbackCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES", ::vk::StructureType::ePhysicalDeviceShaderTerminateInvocationFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TOOL_PROPERTIES", ::vk::StructureType::ePhysicalDeviceToolProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES", ::vk::StructureType::ePhysicalDeviceShaderDemoteToHelperInvocationFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES", ::vk::StructureType::ePhysicalDevicePrivateDataFeatures);
    e_vk_StructureType.value("DEVICE_PRIVATE_DATA_CREATE_INFO", ::vk::StructureType::eDevicePrivateDataCreateInfo);
    e_vk_StructureType.value("PRIVATE_DATA_SLOT_CREATE_INFO", ::vk::StructureType::ePrivateDataSlotCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES", ::vk::StructureType::ePhysicalDevicePipelineCreationCacheControlFeatures);
    e_vk_StructureType.value("MEMORY_BARRIER_2", ::vk::StructureType::eMemoryBarrier2);
    e_vk_StructureType.value("BUFFER_MEMORY_BARRIER_2", ::vk::StructureType::eBufferMemoryBarrier2);
    e_vk_StructureType.value("IMAGE_MEMORY_BARRIER_2", ::vk::StructureType::eImageMemoryBarrier2);
    e_vk_StructureType.value("DEPENDENCY_INFO", ::vk::StructureType::eDependencyInfo);
    e_vk_StructureType.value("SUBMIT_INFO_2", ::vk::StructureType::eSubmitInfo2);
    e_vk_StructureType.value("SEMAPHORE_SUBMIT_INFO", ::vk::StructureType::eSemaphoreSubmitInfo);
    e_vk_StructureType.value("COMMAND_BUFFER_SUBMIT_INFO", ::vk::StructureType::eCommandBufferSubmitInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES", ::vk::StructureType::ePhysicalDeviceSynchronization2Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES", ::vk::StructureType::ePhysicalDeviceZeroInitializeWorkgroupMemoryFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES", ::vk::StructureType::ePhysicalDeviceImageRobustnessFeatures);
    e_vk_StructureType.value("COPY_BUFFER_INFO_2", ::vk::StructureType::eCopyBufferInfo2);
    e_vk_StructureType.value("COPY_IMAGE_INFO_2", ::vk::StructureType::eCopyImageInfo2);
    e_vk_StructureType.value("COPY_BUFFER_TO_IMAGE_INFO_2", ::vk::StructureType::eCopyBufferToImageInfo2);
    e_vk_StructureType.value("COPY_IMAGE_TO_BUFFER_INFO_2", ::vk::StructureType::eCopyImageToBufferInfo2);
    e_vk_StructureType.value("BLIT_IMAGE_INFO_2", ::vk::StructureType::eBlitImageInfo2);
    e_vk_StructureType.value("RESOLVE_IMAGE_INFO_2", ::vk::StructureType::eResolveImageInfo2);
    e_vk_StructureType.value("BUFFER_COPY_2", ::vk::StructureType::eBufferCopy2);
    e_vk_StructureType.value("IMAGE_COPY_2", ::vk::StructureType::eImageCopy2);
    e_vk_StructureType.value("IMAGE_BLIT_2", ::vk::StructureType::eImageBlit2);
    e_vk_StructureType.value("BUFFER_IMAGE_COPY_2", ::vk::StructureType::eBufferImageCopy2);
    e_vk_StructureType.value("IMAGE_RESOLVE_2", ::vk::StructureType::eImageResolve2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES", ::vk::StructureType::ePhysicalDeviceSubgroupSizeControlProperties);
    e_vk_StructureType.value("PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO", ::vk::StructureType::ePipelineShaderStageRequiredSubgroupSizeCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES", ::vk::StructureType::ePhysicalDeviceSubgroupSizeControlFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES", ::vk::StructureType::ePhysicalDeviceInlineUniformBlockFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES", ::vk::StructureType::ePhysicalDeviceInlineUniformBlockProperties);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK", ::vk::StructureType::eWriteDescriptorSetInlineUniformBlock);
    e_vk_StructureType.value("DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO", ::vk::StructureType::eDescriptorPoolInlineUniformBlockCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES", ::vk::StructureType::ePhysicalDeviceTextureCompressionAstcHdrFeatures);
    e_vk_StructureType.value("RENDERING_INFO", ::vk::StructureType::eRenderingInfo);
    e_vk_StructureType.value("RENDERING_ATTACHMENT_INFO", ::vk::StructureType::eRenderingAttachmentInfo);
    e_vk_StructureType.value("PIPELINE_RENDERING_CREATE_INFO", ::vk::StructureType::ePipelineRenderingCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES", ::vk::StructureType::ePhysicalDeviceDynamicRenderingFeatures);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_RENDERING_INFO", ::vk::StructureType::eCommandBufferInheritanceRenderingInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES", ::vk::StructureType::ePhysicalDeviceShaderIntegerDotProductFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES", ::vk::StructureType::ePhysicalDeviceShaderIntegerDotProductProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES", ::vk::StructureType::ePhysicalDeviceTexelBufferAlignmentProperties);
    e_vk_StructureType.value("FORMAT_PROPERTIES_3", ::vk::StructureType::eFormatProperties3);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES", ::vk::StructureType::ePhysicalDeviceMaintenance4Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES", ::vk::StructureType::ePhysicalDeviceMaintenance4Properties);
    e_vk_StructureType.value("DEVICE_BUFFER_MEMORY_REQUIREMENTS", ::vk::StructureType::eDeviceBufferMemoryRequirements);
    e_vk_StructureType.value("DEVICE_IMAGE_MEMORY_REQUIREMENTS", ::vk::StructureType::eDeviceImageMemoryRequirements);
    e_vk_StructureType.value("SWAPCHAIN_CREATE_INFO_KHR", ::vk::StructureType::eSwapchainCreateInfoKHR);
    e_vk_StructureType.value("PRESENT_INFO_KHR", ::vk::StructureType::ePresentInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_PRESENT_CAPABILITIES_KHR", ::vk::StructureType::eDeviceGroupPresentCapabilitiesKHR);
    e_vk_StructureType.value("IMAGE_SWAPCHAIN_CREATE_INFO_KHR", ::vk::StructureType::eImageSwapchainCreateInfoKHR);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR", ::vk::StructureType::eBindImageMemorySwapchainInfoKHR);
    e_vk_StructureType.value("ACQUIRE_NEXT_IMAGE_INFO_KHR", ::vk::StructureType::eAcquireNextImageInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_PRESENT_INFO_KHR", ::vk::StructureType::eDeviceGroupPresentInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR", ::vk::StructureType::eDeviceGroupSwapchainCreateInfoKHR);
    e_vk_StructureType.value("DISPLAY_MODE_CREATE_INFO_KHR", ::vk::StructureType::eDisplayModeCreateInfoKHR);
    e_vk_StructureType.value("DISPLAY_SURFACE_CREATE_INFO_KHR", ::vk::StructureType::eDisplaySurfaceCreateInfoKHR);
    e_vk_StructureType.value("DISPLAY_PRESENT_INFO_KHR", ::vk::StructureType::eDisplayPresentInfoKHR);
    e_vk_StructureType.value("DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT", ::vk::StructureType::eDebugReportCallbackCreateInfoEXT);
    e_vk_StructureType.value("DEBUG_REPORT_CREATE_INFO_EXT", ::vk::StructureType::eDebugReportCreateInfoEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD", ::vk::StructureType::ePipelineRasterizationStateRasterizationOrderAMD);
    e_vk_StructureType.value("DEBUG_MARKER_OBJECT_NAME_INFO_EXT", ::vk::StructureType::eDebugMarkerObjectNameInfoEXT);
    e_vk_StructureType.value("DEBUG_MARKER_OBJECT_TAG_INFO_EXT", ::vk::StructureType::eDebugMarkerObjectTagInfoEXT);
    e_vk_StructureType.value("DEBUG_MARKER_MARKER_INFO_EXT", ::vk::StructureType::eDebugMarkerMarkerInfoEXT);
    e_vk_StructureType.value("VIDEO_PROFILE_INFO_KHR", ::vk::StructureType::eVideoProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_CAPABILITIES_KHR", ::vk::StructureType::eVideoCapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_PICTURE_RESOURCE_INFO_KHR", ::vk::StructureType::eVideoPictureResourceInfoKHR);
    e_vk_StructureType.value("VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR", ::vk::StructureType::eVideoSessionMemoryRequirementsKHR);
    e_vk_StructureType.value("BIND_VIDEO_SESSION_MEMORY_INFO_KHR", ::vk::StructureType::eBindVideoSessionMemoryInfoKHR);
    e_vk_StructureType.value("VIDEO_SESSION_CREATE_INFO_KHR", ::vk::StructureType::eVideoSessionCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR", ::vk::StructureType::eVideoSessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR", ::vk::StructureType::eVideoSessionParametersUpdateInfoKHR);
    e_vk_StructureType.value("VIDEO_BEGIN_CODING_INFO_KHR", ::vk::StructureType::eVideoBeginCodingInfoKHR);
    e_vk_StructureType.value("VIDEO_END_CODING_INFO_KHR", ::vk::StructureType::eVideoEndCodingInfoKHR);
    e_vk_StructureType.value("VIDEO_CODING_CONTROL_INFO_KHR", ::vk::StructureType::eVideoCodingControlInfoKHR);
    e_vk_StructureType.value("VIDEO_REFERENCE_SLOT_INFO_KHR", ::vk::StructureType::eVideoReferenceSlotInfoKHR);
    e_vk_StructureType.value("QUEUE_FAMILY_VIDEO_PROPERTIES_KHR", ::vk::StructureType::eQueueFamilyVideoPropertiesKHR);
    e_vk_StructureType.value("VIDEO_PROFILE_LIST_INFO_KHR", ::vk::StructureType::eVideoProfileListInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR", ::vk::StructureType::ePhysicalDeviceVideoFormatInfoKHR);
    e_vk_StructureType.value("VIDEO_FORMAT_PROPERTIES_KHR", ::vk::StructureType::eVideoFormatPropertiesKHR);
    e_vk_StructureType.value("QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR", ::vk::StructureType::eQueueFamilyQueryResultStatusPropertiesKHR);
    e_vk_StructureType.value("VIDEO_DECODE_INFO_KHR", ::vk::StructureType::eVideoDecodeInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_CAPABILITIES_KHR", ::vk::StructureType::eVideoDecodeCapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_DECODE_USAGE_INFO_KHR", ::vk::StructureType::eVideoDecodeUsageInfoKHR);
    e_vk_StructureType.value("DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV", ::vk::StructureType::eDedicatedAllocationImageCreateInfoNV);
    e_vk_StructureType.value("DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV", ::vk::StructureType::eDedicatedAllocationBufferCreateInfoNV);
    e_vk_StructureType.value("DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV", ::vk::StructureType::eDedicatedAllocationMemoryAllocateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceTransformFeedbackFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceTransformFeedbackPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT", ::vk::StructureType::ePipelineRasterizationStateStreamCreateInfoEXT);
    e_vk_StructureType.value("CU_MODULE_CREATE_INFO_NVX", ::vk::StructureType::eCuModuleCreateInfoNVX);
    e_vk_StructureType.value("CU_FUNCTION_CREATE_INFO_NVX", ::vk::StructureType::eCuFunctionCreateInfoNVX);
    e_vk_StructureType.value("CU_LAUNCH_INFO_NVX", ::vk::StructureType::eCuLaunchInfoNVX);
    e_vk_StructureType.value("IMAGE_VIEW_HANDLE_INFO_NVX", ::vk::StructureType::eImageViewHandleInfoNVX);
    e_vk_StructureType.value("IMAGE_VIEW_ADDRESS_PROPERTIES_NVX", ::vk::StructureType::eImageViewAddressPropertiesNVX);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_CAPABILITIES_KHR", ::vk::StructureType::eVideoEncodeH264CapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR", ::vk::StructureType::eVideoEncodeH264SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR", ::vk::StructureType::eVideoEncodeH264SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_PICTURE_INFO_KHR", ::vk::StructureType::eVideoEncodeH264PictureInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR", ::vk::StructureType::eVideoEncodeH264DpbSlotInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR", ::vk::StructureType::eVideoEncodeH264NaluSliceInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR", ::vk::StructureType::eVideoEncodeH264GopRemainingFrameInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_PROFILE_INFO_KHR", ::vk::StructureType::eVideoEncodeH264ProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR", ::vk::StructureType::eVideoEncodeH264RateControlInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR", ::vk::StructureType::eVideoEncodeH264RateControlLayerInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR", ::vk::StructureType::eVideoEncodeH264SessionCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR", ::vk::StructureType::eVideoEncodeH264QualityLevelPropertiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR", ::vk::StructureType::eVideoEncodeH264SessionParametersGetInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR", ::vk::StructureType::eVideoEncodeH264SessionParametersFeedbackInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_CAPABILITIES_KHR", ::vk::StructureType::eVideoEncodeH265CapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR", ::vk::StructureType::eVideoEncodeH265SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR", ::vk::StructureType::eVideoEncodeH265SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_PICTURE_INFO_KHR", ::vk::StructureType::eVideoEncodeH265PictureInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR", ::vk::StructureType::eVideoEncodeH265DpbSlotInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR", ::vk::StructureType::eVideoEncodeH265NaluSliceSegmentInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR", ::vk::StructureType::eVideoEncodeH265GopRemainingFrameInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_PROFILE_INFO_KHR", ::vk::StructureType::eVideoEncodeH265ProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR", ::vk::StructureType::eVideoEncodeH265RateControlInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR", ::vk::StructureType::eVideoEncodeH265RateControlLayerInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR", ::vk::StructureType::eVideoEncodeH265SessionCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR", ::vk::StructureType::eVideoEncodeH265QualityLevelPropertiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR", ::vk::StructureType::eVideoEncodeH265SessionParametersGetInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR", ::vk::StructureType::eVideoEncodeH265SessionParametersFeedbackInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_CAPABILITIES_KHR", ::vk::StructureType::eVideoDecodeH264CapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_PICTURE_INFO_KHR", ::vk::StructureType::eVideoDecodeH264PictureInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_PROFILE_INFO_KHR", ::vk::StructureType::eVideoDecodeH264ProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR", ::vk::StructureType::eVideoDecodeH264SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR", ::vk::StructureType::eVideoDecodeH264SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR", ::vk::StructureType::eVideoDecodeH264DpbSlotInfoKHR);
    e_vk_StructureType.value("TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD", ::vk::StructureType::eTextureLodGatherFormatPropertiesAMD);
    e_vk_StructureType.value("RENDERING_INFO_KHR", ::vk::StructureType::eRenderingInfoKHR);
    e_vk_StructureType.value("RENDERING_ATTACHMENT_INFO_KHR", ::vk::StructureType::eRenderingAttachmentInfoKHR);
    e_vk_StructureType.value("PIPELINE_RENDERING_CREATE_INFO_KHR", ::vk::StructureType::ePipelineRenderingCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceDynamicRenderingFeaturesKHR);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_RENDERING_INFO_KHR", ::vk::StructureType::eCommandBufferInheritanceRenderingInfoKHR);
    e_vk_StructureType.value("RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR", ::vk::StructureType::eRenderingFragmentShadingRateAttachmentInfoKHR);
    e_vk_StructureType.value("RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT", ::vk::StructureType::eRenderingFragmentDensityMapAttachmentInfoEXT);
    e_vk_StructureType.value("ATTACHMENT_SAMPLE_COUNT_INFO_AMD", ::vk::StructureType::eAttachmentSampleCountInfoAMD);
    e_vk_StructureType.value("ATTACHMENT_SAMPLE_COUNT_INFO_NV", ::vk::StructureType::eAttachmentSampleCountInfoNV);
    e_vk_StructureType.value("MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX", ::vk::StructureType::eMultiviewPerViewAttributesInfoNVX);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceCornerSampledImageFeaturesNV);
    e_vk_StructureType.value("RENDER_PASS_MULTIVIEW_CREATE_INFO_KHR", ::vk::StructureType::eRenderPassMultiviewCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceMultiviewFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceMultiviewPropertiesKHR);
    e_vk_StructureType.value("EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV", ::vk::StructureType::eExternalMemoryImageCreateInfoNV);
    e_vk_StructureType.value("EXPORT_MEMORY_ALLOCATE_INFO_NV", ::vk::StructureType::eExportMemoryAllocateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FEATURES_2KHR", ::vk::StructureType::ePhysicalDeviceFeatures2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROPERTIES_2KHR", ::vk::StructureType::ePhysicalDeviceProperties2KHR);
    e_vk_StructureType.value("FORMAT_PROPERTIES_2KHR", ::vk::StructureType::eFormatProperties2KHR);
    e_vk_StructureType.value("IMAGE_FORMAT_PROPERTIES_2KHR", ::vk::StructureType::eImageFormatProperties2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2KHR", ::vk::StructureType::ePhysicalDeviceImageFormatInfo2KHR);
    e_vk_StructureType.value("QUEUE_FAMILY_PROPERTIES_2KHR", ::vk::StructureType::eQueueFamilyProperties2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_PROPERTIES_2KHR", ::vk::StructureType::ePhysicalDeviceMemoryProperties2KHR);
    e_vk_StructureType.value("SPARSE_IMAGE_FORMAT_PROPERTIES_2KHR", ::vk::StructureType::eSparseImageFormatProperties2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2KHR", ::vk::StructureType::ePhysicalDeviceSparseImageFormatInfo2KHR);
    e_vk_StructureType.value("MEMORY_ALLOCATE_FLAGS_INFO_KHR", ::vk::StructureType::eMemoryAllocateFlagsInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_RENDER_PASS_BEGIN_INFO_KHR", ::vk::StructureType::eDeviceGroupRenderPassBeginInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO_KHR", ::vk::StructureType::eDeviceGroupCommandBufferBeginInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_SUBMIT_INFO_KHR", ::vk::StructureType::eDeviceGroupSubmitInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_BIND_SPARSE_INFO_KHR", ::vk::StructureType::eDeviceGroupBindSparseInfoKHR);
    e_vk_StructureType.value("BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO_KHR", ::vk::StructureType::eBindBufferMemoryDeviceGroupInfoKHR);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO_KHR", ::vk::StructureType::eBindImageMemoryDeviceGroupInfoKHR);
    e_vk_StructureType.value("VALIDATION_FLAGS_EXT", ::vk::StructureType::eValidationFlagsEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceTextureCompressionAstcHdrFeaturesEXT);
    e_vk_StructureType.value("IMAGE_VIEW_ASTC_DECODE_MODE_EXT", ::vk::StructureType::eImageViewAstcDecodeModeEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceAstcDecodeFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_ROBUSTNESS_CREATE_INFO_EXT", ::vk::StructureType::ePipelineRobustnessCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT", ::vk::StructureType::ePhysicalDevicePipelineRobustnessFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDevicePipelineRobustnessPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GROUP_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceGroupPropertiesKHR);
    e_vk_StructureType.value("DEVICE_GROUP_DEVICE_CREATE_INFO_KHR", ::vk::StructureType::eDeviceGroupDeviceCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR", ::vk::StructureType::ePhysicalDeviceExternalImageFormatInfoKHR);
    e_vk_StructureType.value("EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR", ::vk::StructureType::eExternalImageFormatPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR", ::vk::StructureType::ePhysicalDeviceExternalBufferInfoKHR);
    e_vk_StructureType.value("EXTERNAL_BUFFER_PROPERTIES_KHR", ::vk::StructureType::eExternalBufferPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ID_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceIdPropertiesKHR);
    e_vk_StructureType.value("EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR", ::vk::StructureType::eExternalMemoryBufferCreateInfoKHR);
    e_vk_StructureType.value("EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR", ::vk::StructureType::eExternalMemoryImageCreateInfoKHR);
    e_vk_StructureType.value("EXPORT_MEMORY_ALLOCATE_INFO_KHR", ::vk::StructureType::eExportMemoryAllocateInfoKHR);
    e_vk_StructureType.value("IMPORT_MEMORY_FD_INFO_KHR", ::vk::StructureType::eImportMemoryFdInfoKHR);
    e_vk_StructureType.value("MEMORY_FD_PROPERTIES_KHR", ::vk::StructureType::eMemoryFdPropertiesKHR);
    e_vk_StructureType.value("MEMORY_GET_FD_INFO_KHR", ::vk::StructureType::eMemoryGetFdInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR", ::vk::StructureType::ePhysicalDeviceExternalSemaphoreInfoKHR);
    e_vk_StructureType.value("EXTERNAL_SEMAPHORE_PROPERTIES_KHR", ::vk::StructureType::eExternalSemaphorePropertiesKHR);
    e_vk_StructureType.value("EXPORT_SEMAPHORE_CREATE_INFO_KHR", ::vk::StructureType::eExportSemaphoreCreateInfoKHR);
    e_vk_StructureType.value("IMPORT_SEMAPHORE_FD_INFO_KHR", ::vk::StructureType::eImportSemaphoreFdInfoKHR);
    e_vk_StructureType.value("SEMAPHORE_GET_FD_INFO_KHR", ::vk::StructureType::eSemaphoreGetFdInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDevicePushDescriptorPropertiesKHR);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT", ::vk::StructureType::eCommandBufferInheritanceConditionalRenderingInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceConditionalRenderingFeaturesEXT);
    e_vk_StructureType.value("CONDITIONAL_RENDERING_BEGIN_INFO_EXT", ::vk::StructureType::eConditionalRenderingBeginInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_FLOAT_16_INT_8_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceShaderFloat16Int8FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FLOAT_16_INT_8_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceFloat16Int8FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_16_BIT_STORAGE_FEATURES_KHR", ::vk::StructureType::ePhysicalDevice16BitStorageFeaturesKHR);
    e_vk_StructureType.value("PRESENT_REGIONS_KHR", ::vk::StructureType::ePresentRegionsKHR);
    e_vk_StructureType.value("DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO_KHR", ::vk::StructureType::eDescriptorUpdateTemplateCreateInfoKHR);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineViewportWScalingStateCreateInfoNV);
    e_vk_StructureType.value("SURFACE_CAPABILITIES_2EXT", ::vk::StructureType::eSurfaceCapabilities2EXT);
    e_vk_StructureType.value("DISPLAY_POWER_INFO_EXT", ::vk::StructureType::eDisplayPowerInfoEXT);
    e_vk_StructureType.value("DEVICE_EVENT_INFO_EXT", ::vk::StructureType::eDeviceEventInfoEXT);
    e_vk_StructureType.value("DISPLAY_EVENT_INFO_EXT", ::vk::StructureType::eDisplayEventInfoEXT);
    e_vk_StructureType.value("SWAPCHAIN_COUNTER_CREATE_INFO_EXT", ::vk::StructureType::eSwapchainCounterCreateInfoEXT);
    e_vk_StructureType.value("PRESENT_TIMES_INFO_GOOGLE", ::vk::StructureType::ePresentTimesInfoGOOGLE);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX", ::vk::StructureType::ePhysicalDeviceMultiviewPerViewAttributesPropertiesNVX);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineViewportSwizzleStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceDiscardRectanglePropertiesEXT);
    e_vk_StructureType.value("PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineDiscardRectangleStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceConservativeRasterizationPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineRasterizationConservativeStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceDepthClipEnableFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineRasterizationDepthClipStateCreateInfoEXT);
    e_vk_StructureType.value("HDR_METADATA_EXT", ::vk::StructureType::eHdrMetadataEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceImagelessFramebufferFeaturesKHR);
    e_vk_StructureType.value("FRAMEBUFFER_ATTACHMENTS_CREATE_INFO_KHR", ::vk::StructureType::eFramebufferAttachmentsCreateInfoKHR);
    e_vk_StructureType.value("FRAMEBUFFER_ATTACHMENT_IMAGE_INFO_KHR", ::vk::StructureType::eFramebufferAttachmentImageInfoKHR);
    e_vk_StructureType.value("RENDER_PASS_ATTACHMENT_BEGIN_INFO_KHR", ::vk::StructureType::eRenderPassAttachmentBeginInfoKHR);
    e_vk_StructureType.value("ATTACHMENT_DESCRIPTION_2KHR", ::vk::StructureType::eAttachmentDescription2KHR);
    e_vk_StructureType.value("ATTACHMENT_REFERENCE_2KHR", ::vk::StructureType::eAttachmentReference2KHR);
    e_vk_StructureType.value("SUBPASS_DESCRIPTION_2KHR", ::vk::StructureType::eSubpassDescription2KHR);
    e_vk_StructureType.value("SUBPASS_DEPENDENCY_2KHR", ::vk::StructureType::eSubpassDependency2KHR);
    e_vk_StructureType.value("RENDER_PASS_CREATE_INFO_2KHR", ::vk::StructureType::eRenderPassCreateInfo2KHR);
    e_vk_StructureType.value("SUBPASS_BEGIN_INFO_KHR", ::vk::StructureType::eSubpassBeginInfoKHR);
    e_vk_StructureType.value("SUBPASS_END_INFO_KHR", ::vk::StructureType::eSubpassEndInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG", ::vk::StructureType::ePhysicalDeviceRelaxedLineRasterizationFeaturesIMG);
    e_vk_StructureType.value("SHARED_PRESENT_SURFACE_CAPABILITIES_KHR", ::vk::StructureType::eSharedPresentSurfaceCapabilitiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR", ::vk::StructureType::ePhysicalDeviceExternalFenceInfoKHR);
    e_vk_StructureType.value("EXTERNAL_FENCE_PROPERTIES_KHR", ::vk::StructureType::eExternalFencePropertiesKHR);
    e_vk_StructureType.value("EXPORT_FENCE_CREATE_INFO_KHR", ::vk::StructureType::eExportFenceCreateInfoKHR);
    e_vk_StructureType.value("IMPORT_FENCE_FD_INFO_KHR", ::vk::StructureType::eImportFenceFdInfoKHR);
    e_vk_StructureType.value("FENCE_GET_FD_INFO_KHR", ::vk::StructureType::eFenceGetFdInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR", ::vk::StructureType::ePhysicalDevicePerformanceQueryFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDevicePerformanceQueryPropertiesKHR);
    e_vk_StructureType.value("QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR", ::vk::StructureType::eQueryPoolPerformanceCreateInfoKHR);
    e_vk_StructureType.value("PERFORMANCE_QUERY_SUBMIT_INFO_KHR", ::vk::StructureType::ePerformanceQuerySubmitInfoKHR);
    e_vk_StructureType.value("ACQUIRE_PROFILING_LOCK_INFO_KHR", ::vk::StructureType::eAcquireProfilingLockInfoKHR);
    e_vk_StructureType.value("PERFORMANCE_COUNTER_KHR", ::vk::StructureType::ePerformanceCounterKHR);
    e_vk_StructureType.value("PERFORMANCE_COUNTER_DESCRIPTION_KHR", ::vk::StructureType::ePerformanceCounterDescriptionKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDevicePointClippingPropertiesKHR);
    e_vk_StructureType.value("RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO_KHR", ::vk::StructureType::eRenderPassInputAttachmentAspectCreateInfoKHR);
    e_vk_StructureType.value("IMAGE_VIEW_USAGE_CREATE_INFO_KHR", ::vk::StructureType::eImageViewUsageCreateInfoKHR);
    e_vk_StructureType.value("PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO_KHR", ::vk::StructureType::ePipelineTessellationDomainOriginStateCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SURFACE_INFO_2KHR", ::vk::StructureType::ePhysicalDeviceSurfaceInfo2KHR);
    e_vk_StructureType.value("SURFACE_CAPABILITIES_2KHR", ::vk::StructureType::eSurfaceCapabilities2KHR);
    e_vk_StructureType.value("SURFACE_FORMAT_2KHR", ::vk::StructureType::eSurfaceFormat2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceVariablePointersFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceVariablePointerFeaturesKHR);
    e_vk_StructureType.value("DISPLAY_PROPERTIES_2KHR", ::vk::StructureType::eDisplayProperties2KHR);
    e_vk_StructureType.value("DISPLAY_PLANE_PROPERTIES_2KHR", ::vk::StructureType::eDisplayPlaneProperties2KHR);
    e_vk_StructureType.value("DISPLAY_MODE_PROPERTIES_2KHR", ::vk::StructureType::eDisplayModeProperties2KHR);
    e_vk_StructureType.value("DISPLAY_PLANE_INFO_2KHR", ::vk::StructureType::eDisplayPlaneInfo2KHR);
    e_vk_StructureType.value("DISPLAY_PLANE_CAPABILITIES_2KHR", ::vk::StructureType::eDisplayPlaneCapabilities2KHR);
    e_vk_StructureType.value("MEMORY_DEDICATED_REQUIREMENTS_KHR", ::vk::StructureType::eMemoryDedicatedRequirementsKHR);
    e_vk_StructureType.value("MEMORY_DEDICATED_ALLOCATE_INFO_KHR", ::vk::StructureType::eMemoryDedicatedAllocateInfoKHR);
    e_vk_StructureType.value("DEBUG_UTILS_OBJECT_NAME_INFO_EXT", ::vk::StructureType::eDebugUtilsObjectNameInfoEXT);
    e_vk_StructureType.value("DEBUG_UTILS_OBJECT_TAG_INFO_EXT", ::vk::StructureType::eDebugUtilsObjectTagInfoEXT);
    e_vk_StructureType.value("DEBUG_UTILS_LABEL_EXT", ::vk::StructureType::eDebugUtilsLabelEXT);
    e_vk_StructureType.value("DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT", ::vk::StructureType::eDebugUtilsMessengerCallbackDataEXT);
    e_vk_StructureType.value("DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT", ::vk::StructureType::eDebugUtilsMessengerCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceSamplerFilterMinmaxPropertiesEXT);
    e_vk_StructureType.value("SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT", ::vk::StructureType::eSamplerReductionModeCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceInlineUniformBlockFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceInlineUniformBlockPropertiesEXT);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT", ::vk::StructureType::eWriteDescriptorSetInlineUniformBlockEXT);
    e_vk_StructureType.value("DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT", ::vk::StructureType::eDescriptorPoolInlineUniformBlockCreateInfoEXT);
    e_vk_StructureType.value("SAMPLE_LOCATIONS_INFO_EXT", ::vk::StructureType::eSampleLocationsInfoEXT);
    e_vk_StructureType.value("RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT", ::vk::StructureType::eRenderPassSampleLocationsBeginInfoEXT);
    e_vk_StructureType.value("PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineSampleLocationsStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceSampleLocationsPropertiesEXT);
    e_vk_StructureType.value("MULTISAMPLE_PROPERTIES_EXT", ::vk::StructureType::eMultisamplePropertiesEXT);
    e_vk_StructureType.value("BUFFER_MEMORY_REQUIREMENTS_INFO_2KHR", ::vk::StructureType::eBufferMemoryRequirementsInfo2KHR);
    e_vk_StructureType.value("IMAGE_MEMORY_REQUIREMENTS_INFO_2KHR", ::vk::StructureType::eImageMemoryRequirementsInfo2KHR);
    e_vk_StructureType.value("IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2KHR", ::vk::StructureType::eImageSparseMemoryRequirementsInfo2KHR);
    e_vk_StructureType.value("MEMORY_REQUIREMENTS_2KHR", ::vk::StructureType::eMemoryRequirements2KHR);
    e_vk_StructureType.value("SPARSE_IMAGE_MEMORY_REQUIREMENTS_2KHR", ::vk::StructureType::eSparseImageMemoryRequirements2KHR);
    e_vk_StructureType.value("IMAGE_FORMAT_LIST_CREATE_INFO_KHR", ::vk::StructureType::eImageFormatListCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceBlendOperationAdvancedFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceBlendOperationAdvancedPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineColorBlendAdvancedStateCreateInfoEXT);
    e_vk_StructureType.value("PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineCoverageToColorStateCreateInfoNV);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR", ::vk::StructureType::eWriteDescriptorSetAccelerationStructureKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR", ::vk::StructureType::eAccelerationStructureBuildGeometryInfoKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR", ::vk::StructureType::eAccelerationStructureDeviceAddressInfoKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR", ::vk::StructureType::eAccelerationStructureGeometryAabbsDataKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR", ::vk::StructureType::eAccelerationStructureGeometryInstancesDataKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR", ::vk::StructureType::eAccelerationStructureGeometryTrianglesDataKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_KHR", ::vk::StructureType::eAccelerationStructureGeometryKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_VERSION_INFO_KHR", ::vk::StructureType::eAccelerationStructureVersionInfoKHR);
    e_vk_StructureType.value("COPY_ACCELERATION_STRUCTURE_INFO_KHR", ::vk::StructureType::eCopyAccelerationStructureInfoKHR);
    e_vk_StructureType.value("COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR", ::vk::StructureType::eCopyAccelerationStructureToMemoryInfoKHR);
    e_vk_StructureType.value("COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR", ::vk::StructureType::eCopyMemoryToAccelerationStructureInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceAccelerationStructureFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceAccelerationStructurePropertiesKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_CREATE_INFO_KHR", ::vk::StructureType::eAccelerationStructureCreateInfoKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR", ::vk::StructureType::eAccelerationStructureBuildSizesInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceRayTracingPipelineFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceRayTracingPipelinePropertiesKHR);
    e_vk_StructureType.value("RAY_TRACING_PIPELINE_CREATE_INFO_KHR", ::vk::StructureType::eRayTracingPipelineCreateInfoKHR);
    e_vk_StructureType.value("RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR", ::vk::StructureType::eRayTracingShaderGroupCreateInfoKHR);
    e_vk_StructureType.value("RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR", ::vk::StructureType::eRayTracingPipelineInterfaceCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceRayQueryFeaturesKHR);
    e_vk_StructureType.value("PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineCoverageModulationStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceShaderSmBuiltinsFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceShaderSmBuiltinsPropertiesNV);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_CREATE_INFO_KHR", ::vk::StructureType::eSamplerYcbcrConversionCreateInfoKHR);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_INFO_KHR", ::vk::StructureType::eSamplerYcbcrConversionInfoKHR);
    e_vk_StructureType.value("BIND_IMAGE_PLANE_MEMORY_INFO_KHR", ::vk::StructureType::eBindImagePlaneMemoryInfoKHR);
    e_vk_StructureType.value("IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO_KHR", ::vk::StructureType::eImagePlaneMemoryRequirementsInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceSamplerYcbcrConversionFeaturesKHR);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES_KHR", ::vk::StructureType::eSamplerYcbcrConversionImageFormatPropertiesKHR);
    e_vk_StructureType.value("BIND_BUFFER_MEMORY_INFO_KHR", ::vk::StructureType::eBindBufferMemoryInfoKHR);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_INFO_KHR", ::vk::StructureType::eBindImageMemoryInfoKHR);
    e_vk_StructureType.value("DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT", ::vk::StructureType::eDrmFormatModifierPropertiesListEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT", ::vk::StructureType::ePhysicalDeviceImageDrmFormatModifierInfoEXT);
    e_vk_StructureType.value("IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT", ::vk::StructureType::eImageDrmFormatModifierListCreateInfoEXT);
    e_vk_StructureType.value("IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT", ::vk::StructureType::eImageDrmFormatModifierExplicitCreateInfoEXT);
    e_vk_StructureType.value("IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT", ::vk::StructureType::eImageDrmFormatModifierPropertiesEXT);
    e_vk_StructureType.value("DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2EXT", ::vk::StructureType::eDrmFormatModifierPropertiesList2EXT);
    e_vk_StructureType.value("VALIDATION_CACHE_CREATE_INFO_EXT", ::vk::StructureType::eValidationCacheCreateInfoEXT);
    e_vk_StructureType.value("SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT", ::vk::StructureType::eShaderModuleValidationCacheCreateInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT", ::vk::StructureType::eDescriptorSetLayoutBindingFlagsCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceDescriptorIndexingFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceDescriptorIndexingPropertiesEXT);
    e_vk_StructureType.value("DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT", ::vk::StructureType::eDescriptorSetVariableDescriptorCountAllocateInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT", ::vk::StructureType::eDescriptorSetVariableDescriptorCountLayoutSupportEXT);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineViewportShadingRateImageStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceShadingRateImageFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceShadingRateImagePropertiesNV);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineViewportCoarseSampleOrderStateCreateInfoNV);
    e_vk_StructureType.value("RAY_TRACING_PIPELINE_CREATE_INFO_NV", ::vk::StructureType::eRayTracingPipelineCreateInfoNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_CREATE_INFO_NV", ::vk::StructureType::eAccelerationStructureCreateInfoNV);
    e_vk_StructureType.value("GEOMETRY_NV", ::vk::StructureType::eGeometryNV);
    e_vk_StructureType.value("GEOMETRY_TRIANGLES_NV", ::vk::StructureType::eGeometryTrianglesNV);
    e_vk_StructureType.value("GEOMETRY_AABB_NV", ::vk::StructureType::eGeometryAabbNV);
    e_vk_StructureType.value("BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV", ::vk::StructureType::eBindAccelerationStructureMemoryInfoNV);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV", ::vk::StructureType::eWriteDescriptorSetAccelerationStructureNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV", ::vk::StructureType::eAccelerationStructureMemoryRequirementsInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceRayTracingPropertiesNV);
    e_vk_StructureType.value("RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV", ::vk::StructureType::eRayTracingShaderGroupCreateInfoNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_INFO_NV", ::vk::StructureType::eAccelerationStructureInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceRepresentativeFragmentTestFeaturesNV);
    e_vk_StructureType.value("PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineRepresentativeFragmentTestStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceMaintenance3PropertiesKHR);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_SUPPORT_KHR", ::vk::StructureType::eDescriptorSetLayoutSupportKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT", ::vk::StructureType::ePhysicalDeviceImageViewImageFormatInfoEXT);
    e_vk_StructureType.value("FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT", ::vk::StructureType::eFilterCubicImageViewImageFormatPropertiesEXT);
    e_vk_StructureType.value("DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT", ::vk::StructureType::eDeviceQueueGlobalPriorityCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_8_BIT_STORAGE_FEATURES_KHR", ::vk::StructureType::ePhysicalDevice8BitStorageFeaturesKHR);
    e_vk_StructureType.value("IMPORT_MEMORY_HOST_POINTER_INFO_EXT", ::vk::StructureType::eImportMemoryHostPointerInfoEXT);
    e_vk_StructureType.value("MEMORY_HOST_POINTER_PROPERTIES_EXT", ::vk::StructureType::eMemoryHostPointerPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceExternalMemoryHostPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_ATOMIC_INT_64_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceShaderAtomicInt64FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceShaderClockFeaturesKHR);
    e_vk_StructureType.value("PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD", ::vk::StructureType::ePipelineCompilerControlCreateInfoAMD);
    e_vk_StructureType.value("CALIBRATED_TIMESTAMP_INFO_EXT", ::vk::StructureType::eCalibratedTimestampInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD", ::vk::StructureType::ePhysicalDeviceShaderCorePropertiesAMD);
    e_vk_StructureType.value("VIDEO_DECODE_H265_CAPABILITIES_KHR", ::vk::StructureType::eVideoDecodeH265CapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR", ::vk::StructureType::eVideoDecodeH265SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR", ::vk::StructureType::eVideoDecodeH265SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_PROFILE_INFO_KHR", ::vk::StructureType::eVideoDecodeH265ProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_PICTURE_INFO_KHR", ::vk::StructureType::eVideoDecodeH265PictureInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR", ::vk::StructureType::eVideoDecodeH265DpbSlotInfoKHR);
    e_vk_StructureType.value("DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR", ::vk::StructureType::eDeviceQueueGlobalPriorityCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceGlobalPriorityQueryFeaturesKHR);
    e_vk_StructureType.value("QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR", ::vk::StructureType::eQueueFamilyGlobalPriorityPropertiesKHR);
    e_vk_StructureType.value("DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD", ::vk::StructureType::eDeviceMemoryOverallocationCreateInfoAMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceVertexAttributeDivisorPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineVertexInputDivisorStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceVertexAttributeDivisorFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT", ::vk::StructureType::ePipelineCreationFeedbackCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceDriverPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceFloatControlsPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceDepthStencilResolvePropertiesKHR);
    e_vk_StructureType.value("SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR", ::vk::StructureType::eSubpassDescriptionDepthStencilResolveKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceComputeShaderDerivativesFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceMeshShaderFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceMeshShaderPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceFragmentShaderBarycentricFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceShaderImageFootprintFeaturesNV);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineViewportExclusiveScissorStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceExclusiveScissorFeaturesNV);
    e_vk_StructureType.value("CHECKPOINT_DATA_NV", ::vk::StructureType::eCheckpointDataNV);
    e_vk_StructureType.value("QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV", ::vk::StructureType::eQueueFamilyCheckpointPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceTimelineSemaphoreFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceTimelineSemaphorePropertiesKHR);
    e_vk_StructureType.value("SEMAPHORE_TYPE_CREATE_INFO_KHR", ::vk::StructureType::eSemaphoreTypeCreateInfoKHR);
    e_vk_StructureType.value("TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR", ::vk::StructureType::eTimelineSemaphoreSubmitInfoKHR);
    e_vk_StructureType.value("SEMAPHORE_WAIT_INFO_KHR", ::vk::StructureType::eSemaphoreWaitInfoKHR);
    e_vk_StructureType.value("SEMAPHORE_SIGNAL_INFO_KHR", ::vk::StructureType::eSemaphoreSignalInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL", ::vk::StructureType::ePhysicalDeviceShaderIntegerFunctions2FeaturesINTEL);
    e_vk_StructureType.value("QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL", ::vk::StructureType::eQueryPoolPerformanceQueryCreateInfoINTEL);
    e_vk_StructureType.value("QUERY_POOL_CREATE_INFO_INTEL", ::vk::StructureType::eQueryPoolCreateInfoINTEL);
    e_vk_StructureType.value("INITIALIZE_PERFORMANCE_API_INFO_INTEL", ::vk::StructureType::eInitializePerformanceApiInfoINTEL);
    e_vk_StructureType.value("PERFORMANCE_MARKER_INFO_INTEL", ::vk::StructureType::ePerformanceMarkerInfoINTEL);
    e_vk_StructureType.value("PERFORMANCE_STREAM_MARKER_INFO_INTEL", ::vk::StructureType::ePerformanceStreamMarkerInfoINTEL);
    e_vk_StructureType.value("PERFORMANCE_OVERRIDE_INFO_INTEL", ::vk::StructureType::ePerformanceOverrideInfoINTEL);
    e_vk_StructureType.value("PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL", ::vk::StructureType::ePerformanceConfigurationAcquireInfoINTEL);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceVulkanMemoryModelFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDevicePciBusInfoPropertiesEXT);
    e_vk_StructureType.value("DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD", ::vk::StructureType::eDisplayNativeHdrSurfaceCapabilitiesAMD);
    e_vk_StructureType.value("SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD", ::vk::StructureType::eSwapchainDisplayNativeHdrCreateInfoAMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceShaderTerminateInvocationFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceFragmentDensityMapFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceFragmentDensityMapPropertiesEXT);
    e_vk_StructureType.value("RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT", ::vk::StructureType::eRenderPassFragmentDensityMapCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceScalarBlockLayoutFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceSubgroupSizeControlPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineShaderStageRequiredSubgroupSizeCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceSubgroupSizeControlFeaturesEXT);
    e_vk_StructureType.value("FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR", ::vk::StructureType::eFragmentShadingRateAttachmentInfoKHR);
    e_vk_StructureType.value("PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR", ::vk::StructureType::ePipelineFragmentShadingRateStateCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceFragmentShadingRatePropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceFragmentShadingRateFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR", ::vk::StructureType::ePhysicalDeviceFragmentShadingRateKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2AMD", ::vk::StructureType::ePhysicalDeviceShaderCoreProperties2AMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD", ::vk::StructureType::ePhysicalDeviceCoherentMemoryFeaturesAMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT_64_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceShaderImageAtomicInt64FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceMemoryBudgetPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceMemoryPriorityFeaturesEXT);
    e_vk_StructureType.value("MEMORY_PRIORITY_ALLOCATE_INFO_EXT", ::vk::StructureType::eMemoryPriorityAllocateInfoEXT);
    e_vk_StructureType.value("SURFACE_PROTECTED_CAPABILITIES_KHR", ::vk::StructureType::eSurfaceProtectedCapabilitiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR);
    e_vk_StructureType.value("ATTACHMENT_REFERENCE_STENCIL_LAYOUT_KHR", ::vk::StructureType::eAttachmentReferenceStencilLayoutKHR);
    e_vk_StructureType.value("ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT_KHR", ::vk::StructureType::eAttachmentDescriptionStencilLayoutKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceBufferDeviceAddressFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceBufferAddressFeaturesEXT);
    e_vk_StructureType.value("BUFFER_DEVICE_ADDRESS_INFO_EXT", ::vk::StructureType::eBufferDeviceAddressInfoEXT);
    e_vk_StructureType.value("BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT", ::vk::StructureType::eBufferDeviceAddressCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceToolPropertiesEXT);
    e_vk_StructureType.value("IMAGE_STENCIL_USAGE_CREATE_INFO_EXT", ::vk::StructureType::eImageStencilUsageCreateInfoEXT);
    e_vk_StructureType.value("VALIDATION_FEATURES_EXT", ::vk::StructureType::eValidationFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR", ::vk::StructureType::ePhysicalDevicePresentWaitFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceCooperativeMatrixFeaturesNV);
    e_vk_StructureType.value("COOPERATIVE_MATRIX_PROPERTIES_NV", ::vk::StructureType::eCooperativeMatrixPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceCooperativeMatrixPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceCoverageReductionModeFeaturesNV);
    e_vk_StructureType.value("PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineCoverageReductionStateCreateInfoNV);
    e_vk_StructureType.value("FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV", ::vk::StructureType::eFramebufferMixedSamplesCombinationNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceFragmentShaderInterlockFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceYcbcrImageArraysFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceUniformBufferStandardLayoutFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceProvokingVertexFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineRasterizationProvokingVertexStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceProvokingVertexPropertiesEXT);
    e_vk_StructureType.value("HEADLESS_SURFACE_CREATE_INFO_EXT", ::vk::StructureType::eHeadlessSurfaceCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceBufferDeviceAddressFeaturesKHR);
    e_vk_StructureType.value("BUFFER_DEVICE_ADDRESS_INFO_KHR", ::vk::StructureType::eBufferDeviceAddressInfoKHR);
    e_vk_StructureType.value("BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO_KHR", ::vk::StructureType::eBufferOpaqueCaptureAddressCreateInfoKHR);
    e_vk_StructureType.value("MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO_KHR", ::vk::StructureType::eMemoryOpaqueCaptureAddressAllocateInfoKHR);
    e_vk_StructureType.value("DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO_KHR", ::vk::StructureType::eDeviceMemoryOpaqueCaptureAddressInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceLineRasterizationFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineRasterizationLineStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceLineRasterizationPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceShaderAtomicFloatFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceHostQueryResetFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INDEX_TYPE_UINT_8_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceIndexTypeUint8FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceExtendedDynamicStateFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR", ::vk::StructureType::ePhysicalDevicePipelineExecutablePropertiesFeaturesKHR);
    e_vk_StructureType.value("PIPELINE_INFO_KHR", ::vk::StructureType::ePipelineInfoKHR);
    e_vk_StructureType.value("PIPELINE_EXECUTABLE_PROPERTIES_KHR", ::vk::StructureType::ePipelineExecutablePropertiesKHR);
    e_vk_StructureType.value("PIPELINE_EXECUTABLE_INFO_KHR", ::vk::StructureType::ePipelineExecutableInfoKHR);
    e_vk_StructureType.value("PIPELINE_EXECUTABLE_STATISTIC_KHR", ::vk::StructureType::ePipelineExecutableStatisticKHR);
    e_vk_StructureType.value("PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR", ::vk::StructureType::ePipelineExecutableInternalRepresentationKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceHostImageCopyFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceHostImageCopyPropertiesEXT);
    e_vk_StructureType.value("MEMORY_TO_IMAGE_COPY_EXT", ::vk::StructureType::eMemoryToImageCopyEXT);
    e_vk_StructureType.value("IMAGE_TO_MEMORY_COPY_EXT", ::vk::StructureType::eImageToMemoryCopyEXT);
    e_vk_StructureType.value("COPY_IMAGE_TO_MEMORY_INFO_EXT", ::vk::StructureType::eCopyImageToMemoryInfoEXT);
    e_vk_StructureType.value("COPY_MEMORY_TO_IMAGE_INFO_EXT", ::vk::StructureType::eCopyMemoryToImageInfoEXT);
    e_vk_StructureType.value("HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT", ::vk::StructureType::eHostImageLayoutTransitionInfoEXT);
    e_vk_StructureType.value("COPY_IMAGE_TO_IMAGE_INFO_EXT", ::vk::StructureType::eCopyImageToImageInfoEXT);
    e_vk_StructureType.value("SUBRESOURCE_HOST_MEMCPY_SIZE_EXT", ::vk::StructureType::eSubresourceHostMemcpySizeEXT);
    e_vk_StructureType.value("HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT", ::vk::StructureType::eHostImageCopyDevicePerformanceQueryEXT);
    e_vk_StructureType.value("MEMORY_MAP_INFO_KHR", ::vk::StructureType::eMemoryMapInfoKHR);
    e_vk_StructureType.value("MEMORY_UNMAP_INFO_KHR", ::vk::StructureType::eMemoryUnmapInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceShaderAtomicFloat2FeaturesEXT);
    e_vk_StructureType.value("SURFACE_PRESENT_MODE_EXT", ::vk::StructureType::eSurfacePresentModeEXT);
    e_vk_StructureType.value("SURFACE_PRESENT_SCALING_CAPABILITIES_EXT", ::vk::StructureType::eSurfacePresentScalingCapabilitiesEXT);
    e_vk_StructureType.value("SURFACE_PRESENT_MODE_COMPATIBILITY_EXT", ::vk::StructureType::eSurfacePresentModeCompatibilityEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceSwapchainMaintenance1FeaturesEXT);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_FENCE_INFO_EXT", ::vk::StructureType::eSwapchainPresentFenceInfoEXT);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT", ::vk::StructureType::eSwapchainPresentModesCreateInfoEXT);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_MODE_INFO_EXT", ::vk::StructureType::eSwapchainPresentModeInfoEXT);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT", ::vk::StructureType::eSwapchainPresentScalingCreateInfoEXT);
    e_vk_StructureType.value("RELEASE_SWAPCHAIN_IMAGES_INFO_EXT", ::vk::StructureType::eReleaseSwapchainImagesInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceDeviceGeneratedCommandsPropertiesNV);
    e_vk_StructureType.value("GRAPHICS_SHADER_GROUP_CREATE_INFO_NV", ::vk::StructureType::eGraphicsShaderGroupCreateInfoNV);
    e_vk_StructureType.value("GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV", ::vk::StructureType::eGraphicsPipelineShaderGroupsCreateInfoNV);
    e_vk_StructureType.value("INDIRECT_COMMANDS_LAYOUT_TOKEN_NV", ::vk::StructureType::eIndirectCommandsLayoutTokenNV);
    e_vk_StructureType.value("INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV", ::vk::StructureType::eIndirectCommandsLayoutCreateInfoNV);
    e_vk_StructureType.value("GENERATED_COMMANDS_INFO_NV", ::vk::StructureType::eGeneratedCommandsInfoNV);
    e_vk_StructureType.value("GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV", ::vk::StructureType::eGeneratedCommandsMemoryRequirementsInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceDeviceGeneratedCommandsFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceInheritedViewportScissorFeaturesNV);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV", ::vk::StructureType::eCommandBufferInheritanceViewportScissorInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceShaderIntegerDotProductFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceShaderIntegerDotProductPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceTexelBufferAlignmentFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceTexelBufferAlignmentPropertiesEXT);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM", ::vk::StructureType::eCommandBufferInheritanceRenderPassTransformInfoQCOM);
    e_vk_StructureType.value("RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM", ::vk::StructureType::eRenderPassTransformBeginInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceDepthBiasControlFeaturesEXT);
    e_vk_StructureType.value("DEPTH_BIAS_INFO_EXT", ::vk::StructureType::eDepthBiasInfoEXT);
    e_vk_StructureType.value("DEPTH_BIAS_REPRESENTATION_INFO_EXT", ::vk::StructureType::eDepthBiasRepresentationInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceDeviceMemoryReportFeaturesEXT);
    e_vk_StructureType.value("DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT", ::vk::StructureType::eDeviceDeviceMemoryReportCreateInfoEXT);
    e_vk_StructureType.value("DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT", ::vk::StructureType::eDeviceMemoryReportCallbackDataEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceRobustness2FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceRobustness2PropertiesEXT);
    e_vk_StructureType.value("SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT", ::vk::StructureType::eSamplerCustomBorderColorCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceCustomBorderColorPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceCustomBorderColorFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_LIBRARY_CREATE_INFO_KHR", ::vk::StructureType::ePipelineLibraryCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV", ::vk::StructureType::ePhysicalDevicePresentBarrierFeaturesNV);
    e_vk_StructureType.value("SURFACE_CAPABILITIES_PRESENT_BARRIER_NV", ::vk::StructureType::eSurfaceCapabilitiesPresentBarrierNV);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV", ::vk::StructureType::eSwapchainPresentBarrierCreateInfoNV);
    e_vk_StructureType.value("PRESENT_ID_KHR", ::vk::StructureType::ePresentIdKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR", ::vk::StructureType::ePhysicalDevicePresentIdFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT", ::vk::StructureType::ePhysicalDevicePrivateDataFeaturesEXT);
    e_vk_StructureType.value("DEVICE_PRIVATE_DATA_CREATE_INFO_EXT", ::vk::StructureType::eDevicePrivateDataCreateInfoEXT);
    e_vk_StructureType.value("PRIVATE_DATA_SLOT_CREATE_INFO_EXT", ::vk::StructureType::ePrivateDataSlotCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT", ::vk::StructureType::ePhysicalDevicePipelineCreationCacheControlFeaturesEXT);
    e_vk_StructureType.value("VIDEO_ENCODE_INFO_KHR", ::vk::StructureType::eVideoEncodeInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_RATE_CONTROL_INFO_KHR", ::vk::StructureType::eVideoEncodeRateControlInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR", ::vk::StructureType::eVideoEncodeRateControlLayerInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_CAPABILITIES_KHR", ::vk::StructureType::eVideoEncodeCapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_USAGE_INFO_KHR", ::vk::StructureType::eVideoEncodeUsageInfoKHR);
    e_vk_StructureType.value("QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR", ::vk::StructureType::eQueryPoolVideoEncodeFeedbackCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR", ::vk::StructureType::ePhysicalDeviceVideoEncodeQualityLevelInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR", ::vk::StructureType::eVideoEncodeQualityLevelPropertiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR", ::vk::StructureType::eVideoEncodeQualityLevelInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR", ::vk::StructureType::eVideoEncodeSessionParametersGetInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR", ::vk::StructureType::eVideoEncodeSessionParametersFeedbackInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceDiagnosticsConfigFeaturesNV);
    e_vk_StructureType.value("DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV", ::vk::StructureType::eDeviceDiagnosticsConfigCreateInfoNV);
    e_vk_StructureType.value("QUERY_LOW_LATENCY_SUPPORT_NV", ::vk::StructureType::eQueryLowLatencySupportNV);
    e_vk_StructureType.value("MEMORY_BARRIER_2KHR", ::vk::StructureType::eMemoryBarrier2KHR);
    e_vk_StructureType.value("BUFFER_MEMORY_BARRIER_2KHR", ::vk::StructureType::eBufferMemoryBarrier2KHR);
    e_vk_StructureType.value("IMAGE_MEMORY_BARRIER_2KHR", ::vk::StructureType::eImageMemoryBarrier2KHR);
    e_vk_StructureType.value("DEPENDENCY_INFO_KHR", ::vk::StructureType::eDependencyInfoKHR);
    e_vk_StructureType.value("SUBMIT_INFO_2KHR", ::vk::StructureType::eSubmitInfo2KHR);
    e_vk_StructureType.value("SEMAPHORE_SUBMIT_INFO_KHR", ::vk::StructureType::eSemaphoreSubmitInfoKHR);
    e_vk_StructureType.value("COMMAND_BUFFER_SUBMIT_INFO_KHR", ::vk::StructureType::eCommandBufferSubmitInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceSynchronization2FeaturesKHR);
    e_vk_StructureType.value("QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2NV", ::vk::StructureType::eQueueFamilyCheckpointProperties2NV);
    e_vk_StructureType.value("CHECKPOINT_DATA_2NV", ::vk::StructureType::eCheckpointData2NV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceDescriptorBufferPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceDescriptorBufferDensityMapPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceDescriptorBufferFeaturesEXT);
    e_vk_StructureType.value("DESCRIPTOR_ADDRESS_INFO_EXT", ::vk::StructureType::eDescriptorAddressInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_GET_INFO_EXT", ::vk::StructureType::eDescriptorGetInfoEXT);
    e_vk_StructureType.value("BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", ::vk::StructureType::eBufferCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", ::vk::StructureType::eImageCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", ::vk::StructureType::eImageViewCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", ::vk::StructureType::eSamplerCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT", ::vk::StructureType::eOpaqueCaptureDescriptorDataCreateInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_BUFFER_BINDING_INFO_EXT", ::vk::StructureType::eDescriptorBufferBindingInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT", ::vk::StructureType::eDescriptorBufferBindingPushDescriptorBufferHandleEXT);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", ::vk::StructureType::eAccelerationStructureCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceGraphicsPipelineLibraryFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceGraphicsPipelineLibraryPropertiesEXT);
    e_vk_StructureType.value("GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT", ::vk::StructureType::eGraphicsPipelineLibraryCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD", ::vk::StructureType::ePhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceFragmentShaderBarycentricFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceFragmentShaderBarycentricPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceFragmentShadingRateEnumsPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceFragmentShadingRateEnumsFeaturesNV);
    e_vk_StructureType.value("PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV", ::vk::StructureType::ePipelineFragmentShadingRateEnumStateCreateInfoNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV", ::vk::StructureType::eAccelerationStructureGeometryMotionTrianglesDataNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceRayTracingMotionBlurFeaturesNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_MOTION_INFO_NV", ::vk::StructureType::eAccelerationStructureMotionInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceMeshShaderFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceMeshShaderPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceFragmentDensityMap2FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceFragmentDensityMap2PropertiesEXT);
    e_vk_StructureType.value("COPY_COMMAND_TRANSFORM_INFO_QCOM", ::vk::StructureType::eCopyCommandTransformInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceImageRobustnessFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR);
    e_vk_StructureType.value("COPY_BUFFER_INFO_2KHR", ::vk::StructureType::eCopyBufferInfo2KHR);
    e_vk_StructureType.value("COPY_IMAGE_INFO_2KHR", ::vk::StructureType::eCopyImageInfo2KHR);
    e_vk_StructureType.value("COPY_BUFFER_TO_IMAGE_INFO_2KHR", ::vk::StructureType::eCopyBufferToImageInfo2KHR);
    e_vk_StructureType.value("COPY_IMAGE_TO_BUFFER_INFO_2KHR", ::vk::StructureType::eCopyImageToBufferInfo2KHR);
    e_vk_StructureType.value("BLIT_IMAGE_INFO_2KHR", ::vk::StructureType::eBlitImageInfo2KHR);
    e_vk_StructureType.value("RESOLVE_IMAGE_INFO_2KHR", ::vk::StructureType::eResolveImageInfo2KHR);
    e_vk_StructureType.value("BUFFER_COPY_2KHR", ::vk::StructureType::eBufferCopy2KHR);
    e_vk_StructureType.value("IMAGE_COPY_2KHR", ::vk::StructureType::eImageCopy2KHR);
    e_vk_StructureType.value("IMAGE_BLIT_2KHR", ::vk::StructureType::eImageBlit2KHR);
    e_vk_StructureType.value("BUFFER_IMAGE_COPY_2KHR", ::vk::StructureType::eBufferImageCopy2KHR);
    e_vk_StructureType.value("IMAGE_RESOLVE_2KHR", ::vk::StructureType::eImageResolve2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceImageCompressionControlFeaturesEXT);
    e_vk_StructureType.value("IMAGE_COMPRESSION_CONTROL_EXT", ::vk::StructureType::eImageCompressionControlEXT);
    e_vk_StructureType.value("SUBRESOURCE_LAYOUT_2EXT", ::vk::StructureType::eSubresourceLayout2EXT);
    e_vk_StructureType.value("IMAGE_SUBRESOURCE_2EXT", ::vk::StructureType::eImageSubresource2EXT);
    e_vk_StructureType.value("IMAGE_COMPRESSION_PROPERTIES_EXT", ::vk::StructureType::eImageCompressionPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT", ::vk::StructureType::ePhysicalDevice4444FormatsFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FAULT_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceFaultFeaturesEXT);
    e_vk_StructureType.value("DEVICE_FAULT_COUNTS_EXT", ::vk::StructureType::eDeviceFaultCountsEXT);
    e_vk_StructureType.value("DEVICE_FAULT_INFO_EXT", ::vk::StructureType::eDeviceFaultInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_ARM", ::vk::StructureType::ePhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RGBA_10X6_FORMATS_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceRgba10X6FormatsFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE", ::vk::StructureType::ePhysicalDeviceMutableDescriptorTypeFeaturesVALVE);
    e_vk_StructureType.value("MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE", ::vk::StructureType::eMutableDescriptorTypeCreateInfoVALVE);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceVertexInputDynamicStateFeaturesEXT);
    e_vk_StructureType.value("VERTEX_INPUT_BINDING_DESCRIPTION_2EXT", ::vk::StructureType::eVertexInputBindingDescription2EXT);
    e_vk_StructureType.value("VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2EXT", ::vk::StructureType::eVertexInputAttributeDescription2EXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DRM_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceDrmPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceAddressBindingReportFeaturesEXT);
    e_vk_StructureType.value("DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT", ::vk::StructureType::eDeviceAddressBindingCallbackDataEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceDepthClipControlFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT", ::vk::StructureType::ePipelineViewportDepthClipControlCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT", ::vk::StructureType::ePhysicalDevicePrimitiveTopologyListRestartFeaturesEXT);
    e_vk_StructureType.value("FORMAT_PROPERTIES_3KHR", ::vk::StructureType::eFormatProperties3KHR);
    e_vk_StructureType.value("SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI", ::vk::StructureType::eSubpassShadingPipelineCreateInfoHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI", ::vk::StructureType::ePhysicalDeviceSubpassShadingFeaturesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI", ::vk::StructureType::ePhysicalDeviceSubpassShadingPropertiesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI", ::vk::StructureType::ePhysicalDeviceInvocationMaskFeaturesHUAWEI);
    e_vk_StructureType.value("MEMORY_GET_REMOTE_ADDRESS_INFO_NV", ::vk::StructureType::eMemoryGetRemoteAddressInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceExternalMemoryRdmaFeaturesNV);
    e_vk_StructureType.value("PIPELINE_PROPERTIES_IDENTIFIER_EXT", ::vk::StructureType::ePipelinePropertiesIdentifierEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT", ::vk::StructureType::ePhysicalDevicePipelinePropertiesFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_INFO_EXT", ::vk::StructureType::ePipelineInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceFrameBoundaryFeaturesEXT);
    e_vk_StructureType.value("FRAME_BOUNDARY_EXT", ::vk::StructureType::eFrameBoundaryEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT);
    e_vk_StructureType.value("SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT", ::vk::StructureType::eSubpassResolvePerformanceQueryEXT);
    e_vk_StructureType.value("MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT", ::vk::StructureType::eMultisampledRenderToSingleSampledInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceExtendedDynamicState2FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceColorWriteEnableFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_COLOR_WRITE_CREATE_INFO_EXT", ::vk::StructureType::ePipelineColorWriteCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT", ::vk::StructureType::ePhysicalDevicePrimitivesGeneratedQueryFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceRayTracingMaintenance1FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceGlobalPriorityQueryFeaturesEXT);
    e_vk_StructureType.value("QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_EXT", ::vk::StructureType::eQueueFamilyGlobalPriorityPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceImageViewMinLodFeaturesEXT);
    e_vk_StructureType.value("IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT", ::vk::StructureType::eImageViewMinLodCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceMultiDrawFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceMultiDrawPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceImage2DViewOf3DFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceShaderTileImageFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceShaderTileImagePropertiesEXT);
    e_vk_StructureType.value("MICROMAP_BUILD_INFO_EXT", ::vk::StructureType::eMicromapBuildInfoEXT);
    e_vk_StructureType.value("MICROMAP_VERSION_INFO_EXT", ::vk::StructureType::eMicromapVersionInfoEXT);
    e_vk_StructureType.value("COPY_MICROMAP_INFO_EXT", ::vk::StructureType::eCopyMicromapInfoEXT);
    e_vk_StructureType.value("COPY_MICROMAP_TO_MEMORY_INFO_EXT", ::vk::StructureType::eCopyMicromapToMemoryInfoEXT);
    e_vk_StructureType.value("COPY_MEMORY_TO_MICROMAP_INFO_EXT", ::vk::StructureType::eCopyMemoryToMicromapInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceOpacityMicromapFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceOpacityMicromapPropertiesEXT);
    e_vk_StructureType.value("MICROMAP_CREATE_INFO_EXT", ::vk::StructureType::eMicromapCreateInfoEXT);
    e_vk_StructureType.value("MICROMAP_BUILD_SIZES_INFO_EXT", ::vk::StructureType::eMicromapBuildSizesInfoEXT);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT", ::vk::StructureType::eAccelerationStructureTrianglesOpacityMicromapEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI", ::vk::StructureType::ePhysicalDeviceClusterCullingShaderFeaturesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI", ::vk::StructureType::ePhysicalDeviceClusterCullingShaderPropertiesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI", ::vk::StructureType::ePhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceBorderColorSwizzleFeaturesEXT);
    e_vk_StructureType.value("SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT", ::vk::StructureType::eSamplerBorderColorComponentMappingCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT", ::vk::StructureType::ePhysicalDevicePageableDeviceLocalMemoryFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceMaintenance4FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceMaintenance4PropertiesKHR);
    e_vk_StructureType.value("DEVICE_BUFFER_MEMORY_REQUIREMENTS_KHR", ::vk::StructureType::eDeviceBufferMemoryRequirementsKHR);
    e_vk_StructureType.value("DEVICE_IMAGE_MEMORY_REQUIREMENTS_KHR", ::vk::StructureType::eDeviceImageMemoryRequirementsKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM", ::vk::StructureType::ePhysicalDeviceShaderCorePropertiesARM);
    e_vk_StructureType.value("DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM", ::vk::StructureType::eDeviceQueueShaderCoreControlCreateInfoARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM", ::vk::StructureType::ePhysicalDeviceSchedulingControlsFeaturesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM", ::vk::StructureType::ePhysicalDeviceSchedulingControlsPropertiesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceImageSlicedViewOf3DFeaturesEXT);
    e_vk_StructureType.value("IMAGE_VIEW_SLICED_CREATE_INFO_EXT", ::vk::StructureType::eImageViewSlicedCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE", ::vk::StructureType::ePhysicalDeviceDescriptorSetHostMappingFeaturesVALVE);
    e_vk_StructureType.value("DESCRIPTOR_SET_BINDING_REFERENCE_VALVE", ::vk::StructureType::eDescriptorSetBindingReferenceVALVE);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE", ::vk::StructureType::eDescriptorSetLayoutHostMappingInfoVALVE);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceDepthClampZeroOneFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceNonSeamlessCubeMapFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM", ::vk::StructureType::ePhysicalDeviceRenderPassStripedFeaturesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM", ::vk::StructureType::ePhysicalDeviceRenderPassStripedPropertiesARM);
    e_vk_StructureType.value("RENDER_PASS_STRIPE_BEGIN_INFO_ARM", ::vk::StructureType::eRenderPassStripeBeginInfoARM);
    e_vk_StructureType.value("RENDER_PASS_STRIPE_INFO_ARM", ::vk::StructureType::eRenderPassStripeInfoARM);
    e_vk_StructureType.value("RENDER_PASS_STRIPE_SUBMIT_INFO_ARM", ::vk::StructureType::eRenderPassStripeSubmitInfoARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM", ::vk::StructureType::ePhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM", ::vk::StructureType::ePhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM);
    e_vk_StructureType.value("SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM", ::vk::StructureType::eSubpassFragmentDensityMapOffsetEndInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceCopyMemoryIndirectFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceCopyMemoryIndirectPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceMemoryDecompressionFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceMemoryDecompressionPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV);
    e_vk_StructureType.value("COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV", ::vk::StructureType::eComputePipelineIndirectBufferInfoNV);
    e_vk_StructureType.value("PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV", ::vk::StructureType::ePipelineIndirectDeviceAddressInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceLinearColorAttachmentFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceImageCompressionControlSwapchainFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM", ::vk::StructureType::ePhysicalDeviceImageProcessingFeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM", ::vk::StructureType::ePhysicalDeviceImageProcessingPropertiesQCOM);
    e_vk_StructureType.value("IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM", ::vk::StructureType::eImageViewSampleWeightCreateInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceNestedCommandBufferFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceNestedCommandBufferPropertiesEXT);
    e_vk_StructureType.value("EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT", ::vk::StructureType::eExternalMemoryAcquireUnmodifiedEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceExtendedDynamicState3FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceExtendedDynamicState3PropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceSubpassMergeFeedbackFeaturesEXT);
    e_vk_StructureType.value("RENDER_PASS_CREATION_CONTROL_EXT", ::vk::StructureType::eRenderPassCreationControlEXT);
    e_vk_StructureType.value("RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT", ::vk::StructureType::eRenderPassCreationFeedbackCreateInfoEXT);
    e_vk_StructureType.value("RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT", ::vk::StructureType::eRenderPassSubpassFeedbackCreateInfoEXT);
    e_vk_StructureType.value("DIRECT_DRIVER_LOADING_INFO_LUNARG", ::vk::StructureType::eDirectDriverLoadingInfoLUNARG);
    e_vk_StructureType.value("DIRECT_DRIVER_LOADING_LIST_LUNARG", ::vk::StructureType::eDirectDriverLoadingListLUNARG);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceShaderModuleIdentifierFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceShaderModuleIdentifierPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT", ::vk::StructureType::ePipelineShaderStageModuleIdentifierCreateInfoEXT);
    e_vk_StructureType.value("SHADER_MODULE_IDENTIFIER_EXT", ::vk::StructureType::eShaderModuleIdentifierEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceOpticalFlowFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceOpticalFlowPropertiesNV);
    e_vk_StructureType.value("OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV", ::vk::StructureType::eOpticalFlowImageFormatInfoNV);
    e_vk_StructureType.value("OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV", ::vk::StructureType::eOpticalFlowImageFormatPropertiesNV);
    e_vk_StructureType.value("OPTICAL_FLOW_SESSION_CREATE_INFO_NV", ::vk::StructureType::eOpticalFlowSessionCreateInfoNV);
    e_vk_StructureType.value("OPTICAL_FLOW_EXECUTE_INFO_NV", ::vk::StructureType::eOpticalFlowExecuteInfoNV);
    e_vk_StructureType.value("OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV", ::vk::StructureType::eOpticalFlowSessionCreatePrivateDataInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceLegacyDitheringFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT", ::vk::StructureType::ePhysicalDevicePipelineProtectedAccessFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceMaintenance5FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceMaintenance5PropertiesKHR);
    e_vk_StructureType.value("RENDERING_AREA_INFO_KHR", ::vk::StructureType::eRenderingAreaInfoKHR);
    e_vk_StructureType.value("DEVICE_IMAGE_SUBRESOURCE_INFO_KHR", ::vk::StructureType::eDeviceImageSubresourceInfoKHR);
    e_vk_StructureType.value("SUBRESOURCE_LAYOUT_2KHR", ::vk::StructureType::eSubresourceLayout2KHR);
    e_vk_StructureType.value("IMAGE_SUBRESOURCE_2KHR", ::vk::StructureType::eImageSubresource2KHR);
    e_vk_StructureType.value("PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR", ::vk::StructureType::ePipelineCreateFlags2CreateInfoKHR);
    e_vk_StructureType.value("BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR", ::vk::StructureType::eBufferUsageFlags2CreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceRayTracingPositionFetchFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceShaderObjectFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT", ::vk::StructureType::ePhysicalDeviceShaderObjectPropertiesEXT);
    e_vk_StructureType.value("SHADER_CREATE_INFO_EXT", ::vk::StructureType::eShaderCreateInfoEXT);
    e_vk_StructureType.value("SHADER_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT", ::vk::StructureType::eShaderRequiredSubgroupSizeCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM", ::vk::StructureType::ePhysicalDeviceTilePropertiesFeaturesQCOM);
    e_vk_StructureType.value("TILE_PROPERTIES_QCOM", ::vk::StructureType::eTilePropertiesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC", ::vk::StructureType::ePhysicalDeviceAmigoProfilingFeaturesSEC);
    e_vk_StructureType.value("AMIGO_PROFILING_SUBMIT_INFO_SEC", ::vk::StructureType::eAmigoProfilingSubmitInfoSEC);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM", ::vk::StructureType::ePhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceRayTracingInvocationReorderFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceRayTracingInvocationReorderPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceExtendedSparseAddressSpaceFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV", ::vk::StructureType::ePhysicalDeviceExtendedSparseAddressSpacePropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceMutableDescriptorTypeFeaturesEXT);
    e_vk_StructureType.value("MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT", ::vk::StructureType::eMutableDescriptorTypeCreateInfoEXT);
    e_vk_StructureType.value("LAYER_SETTINGS_CREATE_INFO_EXT", ::vk::StructureType::eLayerSettingsCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM", ::vk::StructureType::ePhysicalDeviceShaderCoreBuiltinsFeaturesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM", ::vk::StructureType::ePhysicalDeviceShaderCoreBuiltinsPropertiesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT", ::vk::StructureType::ePhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT);
    e_vk_StructureType.value("LATENCY_SLEEP_MODE_INFO_NV", ::vk::StructureType::eLatencySleepModeInfoNV);
    e_vk_StructureType.value("LATENCY_SLEEP_INFO_NV", ::vk::StructureType::eLatencySleepInfoNV);
    e_vk_StructureType.value("SET_LATENCY_MARKER_INFO_NV", ::vk::StructureType::eSetLatencyMarkerInfoNV);
    e_vk_StructureType.value("GET_LATENCY_MARKER_INFO_NV", ::vk::StructureType::eGetLatencyMarkerInfoNV);
    e_vk_StructureType.value("LATENCY_TIMINGS_FRAME_REPORT_NV", ::vk::StructureType::eLatencyTimingsFrameReportNV);
    e_vk_StructureType.value("LATENCY_SUBMISSION_PRESENT_ID_NV", ::vk::StructureType::eLatencySubmissionPresentIdNV);
    e_vk_StructureType.value("OUT_OF_BAND_QUEUE_TYPE_INFO_NV", ::vk::StructureType::eOutOfBandQueueTypeInfoNV);
    e_vk_StructureType.value("SWAPCHAIN_LATENCY_CREATE_INFO_NV", ::vk::StructureType::eSwapchainLatencyCreateInfoNV);
    e_vk_StructureType.value("LATENCY_SURFACE_CAPABILITIES_NV", ::vk::StructureType::eLatencySurfaceCapabilitiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceCooperativeMatrixFeaturesKHR);
    e_vk_StructureType.value("COOPERATIVE_MATRIX_PROPERTIES_KHR", ::vk::StructureType::eCooperativeMatrixPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceCooperativeMatrixPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM", ::vk::StructureType::ePhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM);
    e_vk_StructureType.value("MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM", ::vk::StructureType::eMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceVideoMaintenance1FeaturesKHR);
    e_vk_StructureType.value("VIDEO_INLINE_QUERY_INFO_KHR", ::vk::StructureType::eVideoInlineQueryInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV", ::vk::StructureType::ePhysicalDevicePerStageDescriptorSetFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM", ::vk::StructureType::ePhysicalDeviceImageProcessing2FeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM", ::vk::StructureType::ePhysicalDeviceImageProcessing2PropertiesQCOM);
    e_vk_StructureType.value("SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM", ::vk::StructureType::eSamplerBlockMatchWindowCreateInfoQCOM);
    e_vk_StructureType.value("SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM", ::vk::StructureType::eSamplerCubicWeightsCreateInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM", ::vk::StructureType::ePhysicalDeviceCubicWeightsFeaturesQCOM);
    e_vk_StructureType.value("BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM", ::vk::StructureType::eBlitImageCubicWeightsInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM", ::vk::StructureType::ePhysicalDeviceYcbcrDegammaFeaturesQCOM);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM", ::vk::StructureType::eSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM", ::vk::StructureType::ePhysicalDeviceCubicClampFeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT", ::vk::StructureType::ePhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceVertexAttributeDivisorPropertiesKHR);
    e_vk_StructureType.value("PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR", ::vk::StructureType::ePipelineVertexInputDivisorStateCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceVertexAttributeDivisorFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT", ::vk::StructureType::ePhysicalDeviceLayeredDriverPropertiesMSFT);
    e_vk_StructureType.value("CALIBRATED_TIMESTAMP_INFO_KHR", ::vk::StructureType::eCalibratedTimestampInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR", ::vk::StructureType::ePhysicalDeviceMaintenance6FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR", ::vk::StructureType::ePhysicalDeviceMaintenance6PropertiesKHR);
    e_vk_StructureType.value("BIND_MEMORY_STATUS_KHR", ::vk::StructureType::eBindMemoryStatusKHR);
    e_vk_StructureType.value("BIND_DESCRIPTOR_SETS_INFO_KHR", ::vk::StructureType::eBindDescriptorSetsInfoKHR);
    e_vk_StructureType.value("PUSH_CONSTANTS_INFO_KHR", ::vk::StructureType::ePushConstantsInfoKHR);
    e_vk_StructureType.value("PUSH_DESCRIPTOR_SET_INFO_KHR", ::vk::StructureType::ePushDescriptorSetInfoKHR);
    e_vk_StructureType.value("PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR", ::vk::StructureType::ePushDescriptorSetWithTemplateInfoKHR);
    e_vk_StructureType.value("SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT", ::vk::StructureType::eSetDescriptorBufferOffsetsInfoEXT);
    e_vk_StructureType.value("BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT", ::vk::StructureType::eBindDescriptorBufferEmbeddedSamplersInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV", ::vk::StructureType::ePhysicalDeviceDescriptorPoolOverallocationFeaturesNV);

    e_vk_SubpassContents.value("INLINE", ::vk::SubpassContents::eInline);
    e_vk_SubpassContents.value("SECONDARY_COMMAND_BUFFERS", ::vk::SubpassContents::eSecondaryCommandBuffers);
    e_vk_SubpassContents.value("INLINE_AND_SECONDARY_COMMAND_BUFFERS_EXT", ::vk::SubpassContents::eInlineAndSecondaryCommandBuffersEXT);

    e_vk_SubpassDescriptionFlagBits.value("PER_VIEW_ATTRIBUTES_NVX", ::vk::SubpassDescriptionFlagBits::ePerViewAttributesNVX);
    e_vk_SubpassDescriptionFlagBits.value("PER_VIEW_POSITION_X_ONLY_NVX", ::vk::SubpassDescriptionFlagBits::ePerViewPositionXOnlyNVX);
    e_vk_SubpassDescriptionFlagBits.value("FRAGMENT_REGION_QCOM", ::vk::SubpassDescriptionFlagBits::eFragmentRegionQCOM);
    e_vk_SubpassDescriptionFlagBits.value("SHADER_RESOLVE_QCOM", ::vk::SubpassDescriptionFlagBits::eShaderResolveQCOM);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_ARM", ::vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentColorAccessARM);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_ARM", ::vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentDepthAccessARM);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_ARM", ::vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentStencilAccessARM);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_EXT", ::vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentColorAccessEXT);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_EXT", ::vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentDepthAccessEXT);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_EXT", ::vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentStencilAccessEXT);
    e_vk_SubpassDescriptionFlagBits.value("ENABLE_LEGACY_DITHERING_EXT", ::vk::SubpassDescriptionFlagBits::eEnableLegacyDitheringEXT);

    e_vk_SystemAllocationScope.value("COMMAND", ::vk::SystemAllocationScope::eCommand);
    e_vk_SystemAllocationScope.value("OBJECT", ::vk::SystemAllocationScope::eObject);
    e_vk_SystemAllocationScope.value("CACHE", ::vk::SystemAllocationScope::eCache);
    e_vk_SystemAllocationScope.value("DEVICE", ::vk::SystemAllocationScope::eDevice);
    e_vk_SystemAllocationScope.value("INSTANCE", ::vk::SystemAllocationScope::eInstance);

    e_vk_VendorId.value("eVIV", ::vk::VendorId::eVIV);
    e_vk_VendorId.value("eVSI", ::vk::VendorId::eVSI);
    e_vk_VendorId.value("KAZAN", ::vk::VendorId::eKazan);
    e_vk_VendorId.value("CODEPLAY", ::vk::VendorId::eCodeplay);
    e_vk_VendorId.value("eMESA", ::vk::VendorId::eMESA);
    e_vk_VendorId.value("POCL", ::vk::VendorId::ePocl);
    e_vk_VendorId.value("MOBILEYE", ::vk::VendorId::eMobileye);

    e_vk_VertexInputRate.value("VERTEX", ::vk::VertexInputRate::eVertex);
    e_vk_VertexInputRate.value("INSTANCE", ::vk::VertexInputRate::eInstance);

    e_vk_ChromaLocation.value("COSITED_EVEN", ::vk::ChromaLocation::eCositedEven);
    e_vk_ChromaLocation.value("MIDPOINT", ::vk::ChromaLocation::eMidpoint);



    e_vk_DescriptorUpdateTemplateType.value("DESCRIPTOR_SET", ::vk::DescriptorUpdateTemplateType::eDescriptorSet);
    e_vk_DescriptorUpdateTemplateType.value("PUSH_DESCRIPTORS_KHR", ::vk::DescriptorUpdateTemplateType::ePushDescriptorsKHR);

    e_vk_ExternalFenceFeatureFlagBits.value("EXPORTABLE", ::vk::ExternalFenceFeatureFlagBits::eExportable);
    e_vk_ExternalFenceFeatureFlagBits.value("IMPORTABLE", ::vk::ExternalFenceFeatureFlagBits::eImportable);

    e_vk_ExternalFenceHandleTypeFlagBits.value("OPAQUE_FD", ::vk::ExternalFenceHandleTypeFlagBits::eOpaqueFd);
    e_vk_ExternalFenceHandleTypeFlagBits.value("OPAQUE_WIN_32", ::vk::ExternalFenceHandleTypeFlagBits::eOpaqueWin32);
    e_vk_ExternalFenceHandleTypeFlagBits.value("OPAQUE_WIN_32_KMT", ::vk::ExternalFenceHandleTypeFlagBits::eOpaqueWin32Kmt);
    e_vk_ExternalFenceHandleTypeFlagBits.value("SYNC_FD", ::vk::ExternalFenceHandleTypeFlagBits::eSyncFd);

    e_vk_ExternalMemoryFeatureFlagBits.value("DEDICATED_ONLY", ::vk::ExternalMemoryFeatureFlagBits::eDedicatedOnly);
    e_vk_ExternalMemoryFeatureFlagBits.value("EXPORTABLE", ::vk::ExternalMemoryFeatureFlagBits::eExportable);
    e_vk_ExternalMemoryFeatureFlagBits.value("IMPORTABLE", ::vk::ExternalMemoryFeatureFlagBits::eImportable);

    e_vk_ExternalMemoryHandleTypeFlagBits.value("OPAQUE_FD", ::vk::ExternalMemoryHandleTypeFlagBits::eOpaqueFd);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("OPAQUE_WIN_32", ::vk::ExternalMemoryHandleTypeFlagBits::eOpaqueWin32);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("OPAQUE_WIN_32_KMT", ::vk::ExternalMemoryHandleTypeFlagBits::eOpaqueWin32Kmt);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("eD3D11_TEXTURE", ::vk::ExternalMemoryHandleTypeFlagBits::eD3D11Texture);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("eD3D11_TEXTURE_KMT", ::vk::ExternalMemoryHandleTypeFlagBits::eD3D11TextureKmt);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("eD3D12_HEAP", ::vk::ExternalMemoryHandleTypeFlagBits::eD3D12Heap);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("eD3D12_RESOURCE", ::vk::ExternalMemoryHandleTypeFlagBits::eD3D12Resource);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("DMA_BUF_EXT", ::vk::ExternalMemoryHandleTypeFlagBits::eDmaBufEXT);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("HOST_ALLOCATION_EXT", ::vk::ExternalMemoryHandleTypeFlagBits::eHostAllocationEXT);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("HOST_MAPPED_FOREIGN_MEMORY_EXT", ::vk::ExternalMemoryHandleTypeFlagBits::eHostMappedForeignMemoryEXT);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("RDMA_ADDRESS_NV", ::vk::ExternalMemoryHandleTypeFlagBits::eRdmaAddressNV);

    e_vk_ExternalSemaphoreFeatureFlagBits.value("EXPORTABLE", ::vk::ExternalSemaphoreFeatureFlagBits::eExportable);
    e_vk_ExternalSemaphoreFeatureFlagBits.value("IMPORTABLE", ::vk::ExternalSemaphoreFeatureFlagBits::eImportable);

    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("OPAQUE_FD", ::vk::ExternalSemaphoreHandleTypeFlagBits::eOpaqueFd);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("OPAQUE_WIN_32", ::vk::ExternalSemaphoreHandleTypeFlagBits::eOpaqueWin32);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("OPAQUE_WIN_32_KMT", ::vk::ExternalSemaphoreHandleTypeFlagBits::eOpaqueWin32Kmt);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("eD3D12_FENCE", ::vk::ExternalSemaphoreHandleTypeFlagBits::eD3D12Fence);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("eD3D11_FENCE", ::vk::ExternalSemaphoreHandleTypeFlagBits::eD3D11Fence);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("SYNC_FD", ::vk::ExternalSemaphoreHandleTypeFlagBits::eSyncFd);

    e_vk_FenceImportFlagBits.value("TEMPORARY", ::vk::FenceImportFlagBits::eTemporary);

    e_vk_MemoryAllocateFlagBits.value("DEVICE_MASK", ::vk::MemoryAllocateFlagBits::eDeviceMask);
    e_vk_MemoryAllocateFlagBits.value("DEVICE_ADDRESS", ::vk::MemoryAllocateFlagBits::eDeviceAddress);
    e_vk_MemoryAllocateFlagBits.value("DEVICE_ADDRESS_CAPTURE_REPLAY", ::vk::MemoryAllocateFlagBits::eDeviceAddressCaptureReplay);

    e_vk_PeerMemoryFeatureFlagBits.value("COPY_SRC", ::vk::PeerMemoryFeatureFlagBits::eCopySrc);
    e_vk_PeerMemoryFeatureFlagBits.value("COPY_DST", ::vk::PeerMemoryFeatureFlagBits::eCopyDst);
    e_vk_PeerMemoryFeatureFlagBits.value("GENERIC_SRC", ::vk::PeerMemoryFeatureFlagBits::eGenericSrc);
    e_vk_PeerMemoryFeatureFlagBits.value("GENERIC_DST", ::vk::PeerMemoryFeatureFlagBits::eGenericDst);

    e_vk_PointClippingBehavior.value("ALL_CLIP_PLANES", ::vk::PointClippingBehavior::eAllClipPlanes);
    e_vk_PointClippingBehavior.value("USER_CLIP_PLANES_ONLY", ::vk::PointClippingBehavior::eUserClipPlanesOnly);

    e_vk_SamplerYcbcrModelConversion.value("RGB_IDENTITY", ::vk::SamplerYcbcrModelConversion::eRgbIdentity);
    e_vk_SamplerYcbcrModelConversion.value("YCBCR_IDENTITY", ::vk::SamplerYcbcrModelConversion::eYcbcrIdentity);
    e_vk_SamplerYcbcrModelConversion.value("YCBCR_709", ::vk::SamplerYcbcrModelConversion::eYcbcr709);
    e_vk_SamplerYcbcrModelConversion.value("YCBCR_601", ::vk::SamplerYcbcrModelConversion::eYcbcr601);
    e_vk_SamplerYcbcrModelConversion.value("YCBCR_2020", ::vk::SamplerYcbcrModelConversion::eYcbcr2020);

    e_vk_SamplerYcbcrRange.value("ITU_FULL", ::vk::SamplerYcbcrRange::eItuFull);
    e_vk_SamplerYcbcrRange.value("ITU_NARROW", ::vk::SamplerYcbcrRange::eItuNarrow);

    e_vk_SemaphoreImportFlagBits.value("TEMPORARY", ::vk::SemaphoreImportFlagBits::eTemporary);

    e_vk_SubgroupFeatureFlagBits.value("BASIC", ::vk::SubgroupFeatureFlagBits::eBasic);
    e_vk_SubgroupFeatureFlagBits.value("VOTE", ::vk::SubgroupFeatureFlagBits::eVote);
    e_vk_SubgroupFeatureFlagBits.value("ARITHMETIC", ::vk::SubgroupFeatureFlagBits::eArithmetic);
    e_vk_SubgroupFeatureFlagBits.value("BALLOT", ::vk::SubgroupFeatureFlagBits::eBallot);
    e_vk_SubgroupFeatureFlagBits.value("SHUFFLE", ::vk::SubgroupFeatureFlagBits::eShuffle);
    e_vk_SubgroupFeatureFlagBits.value("SHUFFLE_RELATIVE", ::vk::SubgroupFeatureFlagBits::eShuffleRelative);
    e_vk_SubgroupFeatureFlagBits.value("CLUSTERED", ::vk::SubgroupFeatureFlagBits::eClustered);
    e_vk_SubgroupFeatureFlagBits.value("QUAD", ::vk::SubgroupFeatureFlagBits::eQuad);
    e_vk_SubgroupFeatureFlagBits.value("PARTITIONED_NV", ::vk::SubgroupFeatureFlagBits::ePartitionedNV);

    e_vk_TessellationDomainOrigin.value("UPPER_LEFT", ::vk::TessellationDomainOrigin::eUpperLeft);
    e_vk_TessellationDomainOrigin.value("LOWER_LEFT", ::vk::TessellationDomainOrigin::eLowerLeft);

    e_vk_DescriptorBindingFlagBits.value("UPDATE_AFTER_BIND", ::vk::DescriptorBindingFlagBits::eUpdateAfterBind);
    e_vk_DescriptorBindingFlagBits.value("UPDATE_UNUSED_WHILE_PENDING", ::vk::DescriptorBindingFlagBits::eUpdateUnusedWhilePending);
    e_vk_DescriptorBindingFlagBits.value("PARTIALLY_BOUND", ::vk::DescriptorBindingFlagBits::ePartiallyBound);
    e_vk_DescriptorBindingFlagBits.value("VARIABLE_DESCRIPTOR_COUNT", ::vk::DescriptorBindingFlagBits::eVariableDescriptorCount);

    e_vk_DriverId.value("AMD_PROPRIETARY", ::vk::DriverId::eAmdProprietary);
    e_vk_DriverId.value("AMD_OPEN_SOURCE", ::vk::DriverId::eAmdOpenSource);
    e_vk_DriverId.value("MESA_RADV", ::vk::DriverId::eMesaRadv);
    e_vk_DriverId.value("NVIDIA_PROPRIETARY", ::vk::DriverId::eNvidiaProprietary);
    e_vk_DriverId.value("INTEL_PROPRIETARY_WINDOWS", ::vk::DriverId::eIntelProprietaryWindows);
    e_vk_DriverId.value("INTEL_OPEN_SOURCE_MESA", ::vk::DriverId::eIntelOpenSourceMESA);
    e_vk_DriverId.value("IMAGINATION_PROPRIETARY", ::vk::DriverId::eImaginationProprietary);
    e_vk_DriverId.value("QUALCOMM_PROPRIETARY", ::vk::DriverId::eQualcommProprietary);
    e_vk_DriverId.value("ARM_PROPRIETARY", ::vk::DriverId::eArmProprietary);
    e_vk_DriverId.value("GOOGLE_SWIFTSHADER", ::vk::DriverId::eGoogleSwiftshader);
    e_vk_DriverId.value("GGP_PROPRIETARY", ::vk::DriverId::eGgpProprietary);
    e_vk_DriverId.value("BROADCOM_PROPRIETARY", ::vk::DriverId::eBroadcomProprietary);
    e_vk_DriverId.value("MESA_LLVMPIPE", ::vk::DriverId::eMesaLlvmpipe);
    e_vk_DriverId.value("MOLTENVK", ::vk::DriverId::eMoltenvk);
    e_vk_DriverId.value("COREAVI_PROPRIETARY", ::vk::DriverId::eCoreaviProprietary);
    e_vk_DriverId.value("JUICE_PROPRIETARY", ::vk::DriverId::eJuiceProprietary);
    e_vk_DriverId.value("VERISILICON_PROPRIETARY", ::vk::DriverId::eVerisiliconProprietary);
    e_vk_DriverId.value("MESA_TURNIP", ::vk::DriverId::eMesaTurnip);
    e_vk_DriverId.value("MESA_V3_DV", ::vk::DriverId::eMesaV3Dv);
    e_vk_DriverId.value("MESA_PANVK", ::vk::DriverId::eMesaPanvk);
    e_vk_DriverId.value("SAMSUNG_PROPRIETARY", ::vk::DriverId::eSamsungProprietary);
    e_vk_DriverId.value("MESA_VENUS", ::vk::DriverId::eMesaVenus);
    e_vk_DriverId.value("MESA_DOZEN", ::vk::DriverId::eMesaDozen);
    e_vk_DriverId.value("MESA_NVK", ::vk::DriverId::eMesaNvk);
    e_vk_DriverId.value("IMAGINATION_OPEN_SOURCE_MESA", ::vk::DriverId::eImaginationOpenSourceMESA);
    e_vk_DriverId.value("MESA_AGXV", ::vk::DriverId::eMesaAgxv);

    e_vk_ResolveModeFlagBits.value("NONE", ::vk::ResolveModeFlagBits::eNone);
    e_vk_ResolveModeFlagBits.value("SAMPLE_ZERO", ::vk::ResolveModeFlagBits::eSampleZero);
    e_vk_ResolveModeFlagBits.value("AVERAGE", ::vk::ResolveModeFlagBits::eAverage);
    e_vk_ResolveModeFlagBits.value("MIN", ::vk::ResolveModeFlagBits::eMin);
    e_vk_ResolveModeFlagBits.value("MAX", ::vk::ResolveModeFlagBits::eMax);

    e_vk_SamplerReductionMode.value("WEIGHTED_AVERAGE", ::vk::SamplerReductionMode::eWeightedAverage);
    e_vk_SamplerReductionMode.value("MIN", ::vk::SamplerReductionMode::eMin);
    e_vk_SamplerReductionMode.value("MAX", ::vk::SamplerReductionMode::eMax);
    e_vk_SamplerReductionMode.value("WEIGHTED_AVERAGE_RANGECLAMP_QCOM", ::vk::SamplerReductionMode::eWeightedAverageRangeclampQCOM);

    e_vk_SemaphoreType.value("BINARY", ::vk::SemaphoreType::eBinary);
    e_vk_SemaphoreType.value("TIMELINE", ::vk::SemaphoreType::eTimeline);

    e_vk_SemaphoreWaitFlagBits.value("ANY", ::vk::SemaphoreWaitFlagBits::eAny);

    e_vk_ShaderFloatControlsIndependence.value("e32_BIT_ONLY", ::vk::ShaderFloatControlsIndependence::e32BitOnly);
    e_vk_ShaderFloatControlsIndependence.value("ALL", ::vk::ShaderFloatControlsIndependence::eAll);
    e_vk_ShaderFloatControlsIndependence.value("NONE", ::vk::ShaderFloatControlsIndependence::eNone);

    e_vk_AccessFlagBits2.value("NONE", ::vk::AccessFlagBits2::eNone);
    e_vk_AccessFlagBits2.value("INDIRECT_COMMAND_READ", ::vk::AccessFlagBits2::eIndirectCommandRead);
    e_vk_AccessFlagBits2.value("INDEX_READ", ::vk::AccessFlagBits2::eIndexRead);
    e_vk_AccessFlagBits2.value("VERTEX_ATTRIBUTE_READ", ::vk::AccessFlagBits2::eVertexAttributeRead);
    e_vk_AccessFlagBits2.value("UNIFORM_READ", ::vk::AccessFlagBits2::eUniformRead);
    e_vk_AccessFlagBits2.value("INPUT_ATTACHMENT_READ", ::vk::AccessFlagBits2::eInputAttachmentRead);
    e_vk_AccessFlagBits2.value("SHADER_READ", ::vk::AccessFlagBits2::eShaderRead);
    e_vk_AccessFlagBits2.value("SHADER_WRITE", ::vk::AccessFlagBits2::eShaderWrite);
    e_vk_AccessFlagBits2.value("COLOR_ATTACHMENT_READ", ::vk::AccessFlagBits2::eColorAttachmentRead);
    e_vk_AccessFlagBits2.value("COLOR_ATTACHMENT_WRITE", ::vk::AccessFlagBits2::eColorAttachmentWrite);
    e_vk_AccessFlagBits2.value("DEPTH_STENCIL_ATTACHMENT_READ", ::vk::AccessFlagBits2::eDepthStencilAttachmentRead);
    e_vk_AccessFlagBits2.value("DEPTH_STENCIL_ATTACHMENT_WRITE", ::vk::AccessFlagBits2::eDepthStencilAttachmentWrite);
    e_vk_AccessFlagBits2.value("TRANSFER_READ", ::vk::AccessFlagBits2::eTransferRead);
    e_vk_AccessFlagBits2.value("TRANSFER_WRITE", ::vk::AccessFlagBits2::eTransferWrite);
    e_vk_AccessFlagBits2.value("HOST_READ", ::vk::AccessFlagBits2::eHostRead);
    e_vk_AccessFlagBits2.value("HOST_WRITE", ::vk::AccessFlagBits2::eHostWrite);
    e_vk_AccessFlagBits2.value("MEMORY_READ", ::vk::AccessFlagBits2::eMemoryRead);
    e_vk_AccessFlagBits2.value("MEMORY_WRITE", ::vk::AccessFlagBits2::eMemoryWrite);
    e_vk_AccessFlagBits2.value("SHADER_SAMPLED_READ", ::vk::AccessFlagBits2::eShaderSampledRead);
    e_vk_AccessFlagBits2.value("SHADER_STORAGE_READ", ::vk::AccessFlagBits2::eShaderStorageRead);
    e_vk_AccessFlagBits2.value("SHADER_STORAGE_WRITE", ::vk::AccessFlagBits2::eShaderStorageWrite);
    e_vk_AccessFlagBits2.value("VIDEO_DECODE_READ_KHR", ::vk::AccessFlagBits2::eVideoDecodeReadKHR);
    e_vk_AccessFlagBits2.value("VIDEO_DECODE_WRITE_KHR", ::vk::AccessFlagBits2::eVideoDecodeWriteKHR);
    e_vk_AccessFlagBits2.value("VIDEO_ENCODE_READ_KHR", ::vk::AccessFlagBits2::eVideoEncodeReadKHR);
    e_vk_AccessFlagBits2.value("VIDEO_ENCODE_WRITE_KHR", ::vk::AccessFlagBits2::eVideoEncodeWriteKHR);
    e_vk_AccessFlagBits2.value("TRANSFORM_FEEDBACK_WRITE_EXT", ::vk::AccessFlagBits2::eTransformFeedbackWriteEXT);
    e_vk_AccessFlagBits2.value("TRANSFORM_FEEDBACK_COUNTER_READ_EXT", ::vk::AccessFlagBits2::eTransformFeedbackCounterReadEXT);
    e_vk_AccessFlagBits2.value("TRANSFORM_FEEDBACK_COUNTER_WRITE_EXT", ::vk::AccessFlagBits2::eTransformFeedbackCounterWriteEXT);
    e_vk_AccessFlagBits2.value("CONDITIONAL_RENDERING_READ_EXT", ::vk::AccessFlagBits2::eConditionalRenderingReadEXT);
    e_vk_AccessFlagBits2.value("COMMAND_PREPROCESS_READ_NV", ::vk::AccessFlagBits2::eCommandPreprocessReadNV);
    e_vk_AccessFlagBits2.value("COMMAND_PREPROCESS_WRITE_NV", ::vk::AccessFlagBits2::eCommandPreprocessWriteNV);
    e_vk_AccessFlagBits2.value("FRAGMENT_SHADING_RATE_ATTACHMENT_READ_KHR", ::vk::AccessFlagBits2::eFragmentShadingRateAttachmentReadKHR);
    e_vk_AccessFlagBits2.value("SHADING_RATE_IMAGE_READ_NV", ::vk::AccessFlagBits2::eShadingRateImageReadNV);
    e_vk_AccessFlagBits2.value("ACCELERATION_STRUCTURE_READ_KHR", ::vk::AccessFlagBits2::eAccelerationStructureReadKHR);
    e_vk_AccessFlagBits2.value("ACCELERATION_STRUCTURE_WRITE_KHR", ::vk::AccessFlagBits2::eAccelerationStructureWriteKHR);
    e_vk_AccessFlagBits2.value("ACCELERATION_STRUCTURE_READ_NV", ::vk::AccessFlagBits2::eAccelerationStructureReadNV);
    e_vk_AccessFlagBits2.value("ACCELERATION_STRUCTURE_WRITE_NV", ::vk::AccessFlagBits2::eAccelerationStructureWriteNV);
    e_vk_AccessFlagBits2.value("FRAGMENT_DENSITY_MAP_READ_EXT", ::vk::AccessFlagBits2::eFragmentDensityMapReadEXT);
    e_vk_AccessFlagBits2.value("COLOR_ATTACHMENT_READ_NONCOHERENT_EXT", ::vk::AccessFlagBits2::eColorAttachmentReadNoncoherentEXT);
    e_vk_AccessFlagBits2.value("DESCRIPTOR_BUFFER_READ_EXT", ::vk::AccessFlagBits2::eDescriptorBufferReadEXT);
    e_vk_AccessFlagBits2.value("INVOCATION_MASK_READ_HUAWEI", ::vk::AccessFlagBits2::eInvocationMaskReadHUAWEI);
    e_vk_AccessFlagBits2.value("SHADER_BINDING_TABLE_READ_KHR", ::vk::AccessFlagBits2::eShaderBindingTableReadKHR);
    e_vk_AccessFlagBits2.value("MICROMAP_READ_EXT", ::vk::AccessFlagBits2::eMicromapReadEXT);
    e_vk_AccessFlagBits2.value("MICROMAP_WRITE_EXT", ::vk::AccessFlagBits2::eMicromapWriteEXT);
    e_vk_AccessFlagBits2.value("OPTICAL_FLOW_READ_NV", ::vk::AccessFlagBits2::eOpticalFlowReadNV);
    e_vk_AccessFlagBits2.value("OPTICAL_FLOW_WRITE_NV", ::vk::AccessFlagBits2::eOpticalFlowWriteNV);

    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE", ::vk::FormatFeatureFlagBits2::eSampledImage);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_IMAGE", ::vk::FormatFeatureFlagBits2::eStorageImage);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_IMAGE_ATOMIC", ::vk::FormatFeatureFlagBits2::eStorageImageAtomic);
    e_vk_FormatFeatureFlagBits2.value("UNIFORM_TEXEL_BUFFER", ::vk::FormatFeatureFlagBits2::eUniformTexelBuffer);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_TEXEL_BUFFER", ::vk::FormatFeatureFlagBits2::eStorageTexelBuffer);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_TEXEL_BUFFER_ATOMIC", ::vk::FormatFeatureFlagBits2::eStorageTexelBufferAtomic);
    e_vk_FormatFeatureFlagBits2.value("VERTEX_BUFFER", ::vk::FormatFeatureFlagBits2::eVertexBuffer);
    e_vk_FormatFeatureFlagBits2.value("COLOR_ATTACHMENT", ::vk::FormatFeatureFlagBits2::eColorAttachment);
    e_vk_FormatFeatureFlagBits2.value("COLOR_ATTACHMENT_BLEND", ::vk::FormatFeatureFlagBits2::eColorAttachmentBlend);
    e_vk_FormatFeatureFlagBits2.value("DEPTH_STENCIL_ATTACHMENT", ::vk::FormatFeatureFlagBits2::eDepthStencilAttachment);
    e_vk_FormatFeatureFlagBits2.value("BLIT_SRC", ::vk::FormatFeatureFlagBits2::eBlitSrc);
    e_vk_FormatFeatureFlagBits2.value("BLIT_DST", ::vk::FormatFeatureFlagBits2::eBlitDst);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_FILTER_LINEAR", ::vk::FormatFeatureFlagBits2::eSampledImageFilterLinear);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_FILTER_CUBIC", ::vk::FormatFeatureFlagBits2::eSampledImageFilterCubic);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_FILTER_CUBIC_EXT", ::vk::FormatFeatureFlagBits2::eSampledImageFilterCubicEXT);
    e_vk_FormatFeatureFlagBits2.value("TRANSFER_SRC", ::vk::FormatFeatureFlagBits2::eTransferSrc);
    e_vk_FormatFeatureFlagBits2.value("TRANSFER_DST", ::vk::FormatFeatureFlagBits2::eTransferDst);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_FILTER_MINMAX", ::vk::FormatFeatureFlagBits2::eSampledImageFilterMinmax);
    e_vk_FormatFeatureFlagBits2.value("MIDPOINT_CHROMA_SAMPLES", ::vk::FormatFeatureFlagBits2::eMidpointChromaSamples);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER", ::vk::FormatFeatureFlagBits2::eSampledImageYcbcrConversionLinearFilter);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER", ::vk::FormatFeatureFlagBits2::eSampledImageYcbcrConversionSeparateReconstructionFilter);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT", ::vk::FormatFeatureFlagBits2::eSampledImageYcbcrConversionChromaReconstructionExplicit);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE", ::vk::FormatFeatureFlagBits2::eSampledImageYcbcrConversionChromaReconstructionExplicitForceable);
    e_vk_FormatFeatureFlagBits2.value("DISJOINT", ::vk::FormatFeatureFlagBits2::eDisjoint);
    e_vk_FormatFeatureFlagBits2.value("COSITED_CHROMA_SAMPLES", ::vk::FormatFeatureFlagBits2::eCositedChromaSamples);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_READ_WITHOUT_FORMAT", ::vk::FormatFeatureFlagBits2::eStorageReadWithoutFormat);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_WRITE_WITHOUT_FORMAT", ::vk::FormatFeatureFlagBits2::eStorageWriteWithoutFormat);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_DEPTH_COMPARISON", ::vk::FormatFeatureFlagBits2::eSampledImageDepthComparison);
    e_vk_FormatFeatureFlagBits2.value("VIDEO_DECODE_OUTPUT_KHR", ::vk::FormatFeatureFlagBits2::eVideoDecodeOutputKHR);
    e_vk_FormatFeatureFlagBits2.value("VIDEO_DECODE_DPB_KHR", ::vk::FormatFeatureFlagBits2::eVideoDecodeDpbKHR);
    e_vk_FormatFeatureFlagBits2.value("ACCELERATION_STRUCTURE_VERTEX_BUFFER_KHR", ::vk::FormatFeatureFlagBits2::eAccelerationStructureVertexBufferKHR);
    e_vk_FormatFeatureFlagBits2.value("FRAGMENT_DENSITY_MAP_EXT", ::vk::FormatFeatureFlagBits2::eFragmentDensityMapEXT);
    e_vk_FormatFeatureFlagBits2.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", ::vk::FormatFeatureFlagBits2::eFragmentShadingRateAttachmentKHR);
    e_vk_FormatFeatureFlagBits2.value("HOST_IMAGE_TRANSFER_EXT", ::vk::FormatFeatureFlagBits2::eHostImageTransferEXT);
    e_vk_FormatFeatureFlagBits2.value("VIDEO_ENCODE_INPUT_KHR", ::vk::FormatFeatureFlagBits2::eVideoEncodeInputKHR);
    e_vk_FormatFeatureFlagBits2.value("VIDEO_ENCODE_DPB_KHR", ::vk::FormatFeatureFlagBits2::eVideoEncodeDpbKHR);
    e_vk_FormatFeatureFlagBits2.value("LINEAR_COLOR_ATTACHMENT_NV", ::vk::FormatFeatureFlagBits2::eLinearColorAttachmentNV);
    e_vk_FormatFeatureFlagBits2.value("WEIGHT_IMAGE_QCOM", ::vk::FormatFeatureFlagBits2::eWeightImageQCOM);
    e_vk_FormatFeatureFlagBits2.value("WEIGHT_SAMPLED_IMAGE_QCOM", ::vk::FormatFeatureFlagBits2::eWeightSampledImageQCOM);
    e_vk_FormatFeatureFlagBits2.value("BLOCK_MATCHING_QCOM", ::vk::FormatFeatureFlagBits2::eBlockMatchingQCOM);
    e_vk_FormatFeatureFlagBits2.value("BOX_FILTER_SAMPLED_QCOM", ::vk::FormatFeatureFlagBits2::eBoxFilterSampledQCOM);
    e_vk_FormatFeatureFlagBits2.value("OPTICAL_FLOW_IMAGE_NV", ::vk::FormatFeatureFlagBits2::eOpticalFlowImageNV);
    e_vk_FormatFeatureFlagBits2.value("OPTICAL_FLOW_VECTOR_NV", ::vk::FormatFeatureFlagBits2::eOpticalFlowVectorNV);
    e_vk_FormatFeatureFlagBits2.value("OPTICAL_FLOW_COST_NV", ::vk::FormatFeatureFlagBits2::eOpticalFlowCostNV);

    e_vk_PipelineCreationFeedbackFlagBits.value("VALID", ::vk::PipelineCreationFeedbackFlagBits::eValid);
    e_vk_PipelineCreationFeedbackFlagBits.value("APPLICATION_PIPELINE_CACHE_HIT", ::vk::PipelineCreationFeedbackFlagBits::eApplicationPipelineCacheHit);
    e_vk_PipelineCreationFeedbackFlagBits.value("BASE_PIPELINE_ACCELERATION", ::vk::PipelineCreationFeedbackFlagBits::eBasePipelineAcceleration);

    e_vk_PipelineStageFlagBits2.value("NONE", ::vk::PipelineStageFlagBits2::eNone);
    e_vk_PipelineStageFlagBits2.value("TOP_OF_PIPE", ::vk::PipelineStageFlagBits2::eTopOfPipe);
    e_vk_PipelineStageFlagBits2.value("DRAW_INDIRECT", ::vk::PipelineStageFlagBits2::eDrawIndirect);
    e_vk_PipelineStageFlagBits2.value("VERTEX_INPUT", ::vk::PipelineStageFlagBits2::eVertexInput);
    e_vk_PipelineStageFlagBits2.value("VERTEX_SHADER", ::vk::PipelineStageFlagBits2::eVertexShader);
    e_vk_PipelineStageFlagBits2.value("TESSELLATION_CONTROL_SHADER", ::vk::PipelineStageFlagBits2::eTessellationControlShader);
    e_vk_PipelineStageFlagBits2.value("TESSELLATION_EVALUATION_SHADER", ::vk::PipelineStageFlagBits2::eTessellationEvaluationShader);
    e_vk_PipelineStageFlagBits2.value("GEOMETRY_SHADER", ::vk::PipelineStageFlagBits2::eGeometryShader);
    e_vk_PipelineStageFlagBits2.value("FRAGMENT_SHADER", ::vk::PipelineStageFlagBits2::eFragmentShader);
    e_vk_PipelineStageFlagBits2.value("EARLY_FRAGMENT_TESTS", ::vk::PipelineStageFlagBits2::eEarlyFragmentTests);
    e_vk_PipelineStageFlagBits2.value("LATE_FRAGMENT_TESTS", ::vk::PipelineStageFlagBits2::eLateFragmentTests);
    e_vk_PipelineStageFlagBits2.value("COLOR_ATTACHMENT_OUTPUT", ::vk::PipelineStageFlagBits2::eColorAttachmentOutput);
    e_vk_PipelineStageFlagBits2.value("COMPUTE_SHADER", ::vk::PipelineStageFlagBits2::eComputeShader);
    e_vk_PipelineStageFlagBits2.value("ALL_TRANSFER", ::vk::PipelineStageFlagBits2::eAllTransfer);
    e_vk_PipelineStageFlagBits2.value("TRANSFER", ::vk::PipelineStageFlagBits2::eTransfer);
    e_vk_PipelineStageFlagBits2.value("BOTTOM_OF_PIPE", ::vk::PipelineStageFlagBits2::eBottomOfPipe);
    e_vk_PipelineStageFlagBits2.value("HOST", ::vk::PipelineStageFlagBits2::eHost);
    e_vk_PipelineStageFlagBits2.value("ALL_GRAPHICS", ::vk::PipelineStageFlagBits2::eAllGraphics);
    e_vk_PipelineStageFlagBits2.value("ALL_COMMANDS", ::vk::PipelineStageFlagBits2::eAllCommands);
    e_vk_PipelineStageFlagBits2.value("COPY", ::vk::PipelineStageFlagBits2::eCopy);
    e_vk_PipelineStageFlagBits2.value("RESOLVE", ::vk::PipelineStageFlagBits2::eResolve);
    e_vk_PipelineStageFlagBits2.value("BLIT", ::vk::PipelineStageFlagBits2::eBlit);
    e_vk_PipelineStageFlagBits2.value("CLEAR", ::vk::PipelineStageFlagBits2::eClear);
    e_vk_PipelineStageFlagBits2.value("INDEX_INPUT", ::vk::PipelineStageFlagBits2::eIndexInput);
    e_vk_PipelineStageFlagBits2.value("VERTEX_ATTRIBUTE_INPUT", ::vk::PipelineStageFlagBits2::eVertexAttributeInput);
    e_vk_PipelineStageFlagBits2.value("PRE_RASTERIZATION_SHADERS", ::vk::PipelineStageFlagBits2::ePreRasterizationShaders);
    e_vk_PipelineStageFlagBits2.value("VIDEO_DECODE_KHR", ::vk::PipelineStageFlagBits2::eVideoDecodeKHR);
    e_vk_PipelineStageFlagBits2.value("VIDEO_ENCODE_KHR", ::vk::PipelineStageFlagBits2::eVideoEncodeKHR);
    e_vk_PipelineStageFlagBits2.value("TRANSFORM_FEEDBACK_EXT", ::vk::PipelineStageFlagBits2::eTransformFeedbackEXT);
    e_vk_PipelineStageFlagBits2.value("CONDITIONAL_RENDERING_EXT", ::vk::PipelineStageFlagBits2::eConditionalRenderingEXT);
    e_vk_PipelineStageFlagBits2.value("COMMAND_PREPROCESS_NV", ::vk::PipelineStageFlagBits2::eCommandPreprocessNV);
    e_vk_PipelineStageFlagBits2.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", ::vk::PipelineStageFlagBits2::eFragmentShadingRateAttachmentKHR);
    e_vk_PipelineStageFlagBits2.value("SHADING_RATE_IMAGE_NV", ::vk::PipelineStageFlagBits2::eShadingRateImageNV);
    e_vk_PipelineStageFlagBits2.value("ACCELERATION_STRUCTURE_BUILD_KHR", ::vk::PipelineStageFlagBits2::eAccelerationStructureBuildKHR);
    e_vk_PipelineStageFlagBits2.value("RAY_TRACING_SHADER_KHR", ::vk::PipelineStageFlagBits2::eRayTracingShaderKHR);
    e_vk_PipelineStageFlagBits2.value("RAY_TRACING_SHADER_NV", ::vk::PipelineStageFlagBits2::eRayTracingShaderNV);
    e_vk_PipelineStageFlagBits2.value("ACCELERATION_STRUCTURE_BUILD_NV", ::vk::PipelineStageFlagBits2::eAccelerationStructureBuildNV);
    e_vk_PipelineStageFlagBits2.value("FRAGMENT_DENSITY_PROCESS_EXT", ::vk::PipelineStageFlagBits2::eFragmentDensityProcessEXT);
    e_vk_PipelineStageFlagBits2.value("TASK_SHADER_NV", ::vk::PipelineStageFlagBits2::eTaskShaderNV);
    e_vk_PipelineStageFlagBits2.value("MESH_SHADER_NV", ::vk::PipelineStageFlagBits2::eMeshShaderNV);
    e_vk_PipelineStageFlagBits2.value("TASK_SHADER_EXT", ::vk::PipelineStageFlagBits2::eTaskShaderEXT);
    e_vk_PipelineStageFlagBits2.value("MESH_SHADER_EXT", ::vk::PipelineStageFlagBits2::eMeshShaderEXT);
    e_vk_PipelineStageFlagBits2.value("SUBPASS_SHADER_HUAWEI", ::vk::PipelineStageFlagBits2::eSubpassShaderHUAWEI);
    e_vk_PipelineStageFlagBits2.value("SUBPASS_SHADING_HUAWEI", ::vk::PipelineStageFlagBits2::eSubpassShadingHUAWEI);
    e_vk_PipelineStageFlagBits2.value("INVOCATION_MASK_HUAWEI", ::vk::PipelineStageFlagBits2::eInvocationMaskHUAWEI);
    e_vk_PipelineStageFlagBits2.value("ACCELERATION_STRUCTURE_COPY_KHR", ::vk::PipelineStageFlagBits2::eAccelerationStructureCopyKHR);
    e_vk_PipelineStageFlagBits2.value("MICROMAP_BUILD_EXT", ::vk::PipelineStageFlagBits2::eMicromapBuildEXT);
    e_vk_PipelineStageFlagBits2.value("CLUSTER_CULLING_SHADER_HUAWEI", ::vk::PipelineStageFlagBits2::eClusterCullingShaderHUAWEI);
    e_vk_PipelineStageFlagBits2.value("OPTICAL_FLOW_NV", ::vk::PipelineStageFlagBits2::eOpticalFlowNV);


    e_vk_RenderingFlagBits.value("CONTENTS_SECONDARY_COMMAND_BUFFERS", ::vk::RenderingFlagBits::eContentsSecondaryCommandBuffers);
    e_vk_RenderingFlagBits.value("SUSPENDING", ::vk::RenderingFlagBits::eSuspending);
    e_vk_RenderingFlagBits.value("RESUMING", ::vk::RenderingFlagBits::eResuming);
    e_vk_RenderingFlagBits.value("CONTENTS_INLINE_EXT", ::vk::RenderingFlagBits::eContentsInlineEXT);
    e_vk_RenderingFlagBits.value("ENABLE_LEGACY_DITHERING_EXT", ::vk::RenderingFlagBits::eEnableLegacyDitheringEXT);

    e_vk_SubmitFlagBits.value("PROTECTED", ::vk::SubmitFlagBits::eProtected);

    e_vk_ToolPurposeFlagBits.value("VALIDATION", ::vk::ToolPurposeFlagBits::eValidation);
    e_vk_ToolPurposeFlagBits.value("PROFILING", ::vk::ToolPurposeFlagBits::eProfiling);
    e_vk_ToolPurposeFlagBits.value("TRACING", ::vk::ToolPurposeFlagBits::eTracing);
    e_vk_ToolPurposeFlagBits.value("ADDITIONAL_FEATURES", ::vk::ToolPurposeFlagBits::eAdditionalFeatures);
    e_vk_ToolPurposeFlagBits.value("MODIFYING_FEATURES", ::vk::ToolPurposeFlagBits::eModifyingFeatures);
    e_vk_ToolPurposeFlagBits.value("DEBUG_REPORTING_EXT", ::vk::ToolPurposeFlagBits::eDebugReportingEXT);
    e_vk_ToolPurposeFlagBits.value("DEBUG_MARKERS_EXT", ::vk::ToolPurposeFlagBits::eDebugMarkersEXT);

    e_vk_ColorSpaceKHR.value("SRGB_NONLINEAR", ::vk::ColorSpaceKHR::eSrgbNonlinear);
    e_vk_ColorSpaceKHR.value("VK_COLORSPACE_SRGB_NONLINEAR", ::vk::ColorSpaceKHR::eVkColorspaceSrgbNonlinear);
    e_vk_ColorSpaceKHR.value("DISPLAY_P3_NONLINEAR_EXT", ::vk::ColorSpaceKHR::eDisplayP3NonlinearEXT);
    e_vk_ColorSpaceKHR.value("EXTENDED_SRGB_LINEAR_EXT", ::vk::ColorSpaceKHR::eExtendedSrgbLinearEXT);
    e_vk_ColorSpaceKHR.value("DISPLAY_P3_LINEAR_EXT", ::vk::ColorSpaceKHR::eDisplayP3LinearEXT);
    e_vk_ColorSpaceKHR.value("DCI_P3_NONLINEAR_EXT", ::vk::ColorSpaceKHR::eDciP3NonlinearEXT);
    e_vk_ColorSpaceKHR.value("BT_709_LINEAR_EXT", ::vk::ColorSpaceKHR::eBt709LinearEXT);
    e_vk_ColorSpaceKHR.value("BT_709_NONLINEAR_EXT", ::vk::ColorSpaceKHR::eBt709NonlinearEXT);
    e_vk_ColorSpaceKHR.value("BT_2020_LINEAR_EXT", ::vk::ColorSpaceKHR::eBt2020LinearEXT);
    e_vk_ColorSpaceKHR.value("HDR_10_ST_2084EXT", ::vk::ColorSpaceKHR::eHdr10St2084EXT);
    e_vk_ColorSpaceKHR.value("DOLBYVISION_EXT", ::vk::ColorSpaceKHR::eDolbyvisionEXT);
    e_vk_ColorSpaceKHR.value("HDR_10_HLG_EXT", ::vk::ColorSpaceKHR::eHdr10HlgEXT);
    e_vk_ColorSpaceKHR.value("ADOBERGB_LINEAR_EXT", ::vk::ColorSpaceKHR::eAdobergbLinearEXT);
    e_vk_ColorSpaceKHR.value("ADOBERGB_NONLINEAR_EXT", ::vk::ColorSpaceKHR::eAdobergbNonlinearEXT);
    e_vk_ColorSpaceKHR.value("PASS_THROUGH_EXT", ::vk::ColorSpaceKHR::ePassThroughEXT);
    e_vk_ColorSpaceKHR.value("EXTENDED_SRGB_NONLINEAR_EXT", ::vk::ColorSpaceKHR::eExtendedSrgbNonlinearEXT);
    e_vk_ColorSpaceKHR.value("DCI_P3_LINEAR_EXT", ::vk::ColorSpaceKHR::eDciP3LinearEXT);
    e_vk_ColorSpaceKHR.value("DISPLAY_NATIVE_AMD", ::vk::ColorSpaceKHR::eDisplayNativeAMD);

    e_vk_CompositeAlphaFlagBitsKHR.value("OPAQUE", ::vk::CompositeAlphaFlagBitsKHR::eOpaque);
    e_vk_CompositeAlphaFlagBitsKHR.value("PRE_MULTIPLIED", ::vk::CompositeAlphaFlagBitsKHR::ePreMultiplied);
    e_vk_CompositeAlphaFlagBitsKHR.value("POST_MULTIPLIED", ::vk::CompositeAlphaFlagBitsKHR::ePostMultiplied);
    e_vk_CompositeAlphaFlagBitsKHR.value("INHERIT", ::vk::CompositeAlphaFlagBitsKHR::eInherit);

    e_vk_PresentModeKHR.value("IMMEDIATE", ::vk::PresentModeKHR::eImmediate);
    e_vk_PresentModeKHR.value("MAILBOX", ::vk::PresentModeKHR::eMailbox);
    e_vk_PresentModeKHR.value("FIFO", ::vk::PresentModeKHR::eFifo);
    e_vk_PresentModeKHR.value("FIFO_RELAXED", ::vk::PresentModeKHR::eFifoRelaxed);
    e_vk_PresentModeKHR.value("SHARED_DEMAND_REFRESH", ::vk::PresentModeKHR::eSharedDemandRefresh);
    e_vk_PresentModeKHR.value("SHARED_CONTINUOUS_REFRESH", ::vk::PresentModeKHR::eSharedContinuousRefresh);

    e_vk_SurfaceTransformFlagBitsKHR.value("IDENTITY", ::vk::SurfaceTransformFlagBitsKHR::eIdentity);
    e_vk_SurfaceTransformFlagBitsKHR.value("ROTATE_90", ::vk::SurfaceTransformFlagBitsKHR::eRotate90);
    e_vk_SurfaceTransformFlagBitsKHR.value("ROTATE_180", ::vk::SurfaceTransformFlagBitsKHR::eRotate180);
    e_vk_SurfaceTransformFlagBitsKHR.value("ROTATE_270", ::vk::SurfaceTransformFlagBitsKHR::eRotate270);
    e_vk_SurfaceTransformFlagBitsKHR.value("HORIZONTAL_MIRROR", ::vk::SurfaceTransformFlagBitsKHR::eHorizontalMirror);
    e_vk_SurfaceTransformFlagBitsKHR.value("HORIZONTAL_MIRROR_ROTATE_90", ::vk::SurfaceTransformFlagBitsKHR::eHorizontalMirrorRotate90);
    e_vk_SurfaceTransformFlagBitsKHR.value("HORIZONTAL_MIRROR_ROTATE_180", ::vk::SurfaceTransformFlagBitsKHR::eHorizontalMirrorRotate180);
    e_vk_SurfaceTransformFlagBitsKHR.value("HORIZONTAL_MIRROR_ROTATE_270", ::vk::SurfaceTransformFlagBitsKHR::eHorizontalMirrorRotate270);
    e_vk_SurfaceTransformFlagBitsKHR.value("INHERIT", ::vk::SurfaceTransformFlagBitsKHR::eInherit);

    e_vk_DeviceGroupPresentModeFlagBitsKHR.value("LOCAL", ::vk::DeviceGroupPresentModeFlagBitsKHR::eLocal);
    e_vk_DeviceGroupPresentModeFlagBitsKHR.value("REMOTE", ::vk::DeviceGroupPresentModeFlagBitsKHR::eRemote);
    e_vk_DeviceGroupPresentModeFlagBitsKHR.value("SUM", ::vk::DeviceGroupPresentModeFlagBitsKHR::eSum);
    e_vk_DeviceGroupPresentModeFlagBitsKHR.value("LOCAL_MULTI_DEVICE", ::vk::DeviceGroupPresentModeFlagBitsKHR::eLocalMultiDevice);

    e_vk_SwapchainCreateFlagBitsKHR.value("SPLIT_INSTANCE_BIND_REGIONS", ::vk::SwapchainCreateFlagBitsKHR::eSplitInstanceBindRegions);
    e_vk_SwapchainCreateFlagBitsKHR.value("PROTECTED", ::vk::SwapchainCreateFlagBitsKHR::eProtected);
    e_vk_SwapchainCreateFlagBitsKHR.value("MUTABLE_FORMAT", ::vk::SwapchainCreateFlagBitsKHR::eMutableFormat);
    e_vk_SwapchainCreateFlagBitsKHR.value("DEFERRED_MEMORY_ALLOCATION_EXT", ::vk::SwapchainCreateFlagBitsKHR::eDeferredMemoryAllocationEXT);


    e_vk_DisplayPlaneAlphaFlagBitsKHR.value("OPAQUE", ::vk::DisplayPlaneAlphaFlagBitsKHR::eOpaque);
    e_vk_DisplayPlaneAlphaFlagBitsKHR.value("GLOBAL", ::vk::DisplayPlaneAlphaFlagBitsKHR::eGlobal);
    e_vk_DisplayPlaneAlphaFlagBitsKHR.value("PER_PIXEL", ::vk::DisplayPlaneAlphaFlagBitsKHR::ePerPixel);
    e_vk_DisplayPlaneAlphaFlagBitsKHR.value("PER_PIXEL_PREMULTIPLIED", ::vk::DisplayPlaneAlphaFlagBitsKHR::ePerPixelPremultiplied);


    e_vk_DebugReportFlagBitsEXT.value("INFORMATION", ::vk::DebugReportFlagBitsEXT::eInformation);
    e_vk_DebugReportFlagBitsEXT.value("WARNING", ::vk::DebugReportFlagBitsEXT::eWarning);
    e_vk_DebugReportFlagBitsEXT.value("PERFORMANCE_WARNING", ::vk::DebugReportFlagBitsEXT::ePerformanceWarning);
    e_vk_DebugReportFlagBitsEXT.value("ERROR", ::vk::DebugReportFlagBitsEXT::eError);
    e_vk_DebugReportFlagBitsEXT.value("DEBUG", ::vk::DebugReportFlagBitsEXT::eDebug);

    e_vk_DebugReportObjectTypeEXT.value("UNKNOWN", ::vk::DebugReportObjectTypeEXT::eUnknown);
    e_vk_DebugReportObjectTypeEXT.value("INSTANCE", ::vk::DebugReportObjectTypeEXT::eInstance);
    e_vk_DebugReportObjectTypeEXT.value("PHYSICAL_DEVICE", ::vk::DebugReportObjectTypeEXT::ePhysicalDevice);
    e_vk_DebugReportObjectTypeEXT.value("DEVICE", ::vk::DebugReportObjectTypeEXT::eDevice);
    e_vk_DebugReportObjectTypeEXT.value("QUEUE", ::vk::DebugReportObjectTypeEXT::eQueue);
    e_vk_DebugReportObjectTypeEXT.value("SEMAPHORE", ::vk::DebugReportObjectTypeEXT::eSemaphore);
    e_vk_DebugReportObjectTypeEXT.value("COMMAND_BUFFER", ::vk::DebugReportObjectTypeEXT::eCommandBuffer);
    e_vk_DebugReportObjectTypeEXT.value("FENCE", ::vk::DebugReportObjectTypeEXT::eFence);
    e_vk_DebugReportObjectTypeEXT.value("DEVICE_MEMORY", ::vk::DebugReportObjectTypeEXT::eDeviceMemory);
    e_vk_DebugReportObjectTypeEXT.value("BUFFER", ::vk::DebugReportObjectTypeEXT::eBuffer);
    e_vk_DebugReportObjectTypeEXT.value("IMAGE", ::vk::DebugReportObjectTypeEXT::eImage);
    e_vk_DebugReportObjectTypeEXT.value("EVENT", ::vk::DebugReportObjectTypeEXT::eEvent);
    e_vk_DebugReportObjectTypeEXT.value("QUERY_POOL", ::vk::DebugReportObjectTypeEXT::eQueryPool);
    e_vk_DebugReportObjectTypeEXT.value("BUFFER_VIEW", ::vk::DebugReportObjectTypeEXT::eBufferView);
    e_vk_DebugReportObjectTypeEXT.value("IMAGE_VIEW", ::vk::DebugReportObjectTypeEXT::eImageView);
    e_vk_DebugReportObjectTypeEXT.value("SHADER_MODULE", ::vk::DebugReportObjectTypeEXT::eShaderModule);
    e_vk_DebugReportObjectTypeEXT.value("PIPELINE_CACHE", ::vk::DebugReportObjectTypeEXT::ePipelineCache);
    e_vk_DebugReportObjectTypeEXT.value("PIPELINE_LAYOUT", ::vk::DebugReportObjectTypeEXT::ePipelineLayout);
    e_vk_DebugReportObjectTypeEXT.value("RENDER_PASS", ::vk::DebugReportObjectTypeEXT::eRenderPass);
    e_vk_DebugReportObjectTypeEXT.value("PIPELINE", ::vk::DebugReportObjectTypeEXT::ePipeline);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_SET_LAYOUT", ::vk::DebugReportObjectTypeEXT::eDescriptorSetLayout);
    e_vk_DebugReportObjectTypeEXT.value("SAMPLER", ::vk::DebugReportObjectTypeEXT::eSampler);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_POOL", ::vk::DebugReportObjectTypeEXT::eDescriptorPool);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_SET", ::vk::DebugReportObjectTypeEXT::eDescriptorSet);
    e_vk_DebugReportObjectTypeEXT.value("FRAMEBUFFER", ::vk::DebugReportObjectTypeEXT::eFramebuffer);
    e_vk_DebugReportObjectTypeEXT.value("COMMAND_POOL", ::vk::DebugReportObjectTypeEXT::eCommandPool);
    e_vk_DebugReportObjectTypeEXT.value("SURFACE_KHR", ::vk::DebugReportObjectTypeEXT::eSurfaceKHR);
    e_vk_DebugReportObjectTypeEXT.value("SWAPCHAIN_KHR", ::vk::DebugReportObjectTypeEXT::eSwapchainKHR);
    e_vk_DebugReportObjectTypeEXT.value("DEBUG_REPORT_CALLBACK_EXT", ::vk::DebugReportObjectTypeEXT::eDebugReportCallbackEXT);
    e_vk_DebugReportObjectTypeEXT.value("DEBUG_REPORT", ::vk::DebugReportObjectTypeEXT::eDebugReport);
    e_vk_DebugReportObjectTypeEXT.value("DISPLAY_KHR", ::vk::DebugReportObjectTypeEXT::eDisplayKHR);
    e_vk_DebugReportObjectTypeEXT.value("DISPLAY_MODE_KHR", ::vk::DebugReportObjectTypeEXT::eDisplayModeKHR);
    e_vk_DebugReportObjectTypeEXT.value("VALIDATION_CACHE_EXT", ::vk::DebugReportObjectTypeEXT::eValidationCacheEXT);
    e_vk_DebugReportObjectTypeEXT.value("VALIDATION_CACHE", ::vk::DebugReportObjectTypeEXT::eValidationCache);
    e_vk_DebugReportObjectTypeEXT.value("SAMPLER_YCBCR_CONVERSION", ::vk::DebugReportObjectTypeEXT::eSamplerYcbcrConversion);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_UPDATE_TEMPLATE", ::vk::DebugReportObjectTypeEXT::eDescriptorUpdateTemplate);
    e_vk_DebugReportObjectTypeEXT.value("CU_MODULE_NVX", ::vk::DebugReportObjectTypeEXT::eCuModuleNVX);
    e_vk_DebugReportObjectTypeEXT.value("CU_FUNCTION_NVX", ::vk::DebugReportObjectTypeEXT::eCuFunctionNVX);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_UPDATE_TEMPLATE_KHR", ::vk::DebugReportObjectTypeEXT::eDescriptorUpdateTemplateKHR);
    e_vk_DebugReportObjectTypeEXT.value("ACCELERATION_STRUCTURE_KHR", ::vk::DebugReportObjectTypeEXT::eAccelerationStructureKHR);
    e_vk_DebugReportObjectTypeEXT.value("SAMPLER_YCBCR_CONVERSION_KHR", ::vk::DebugReportObjectTypeEXT::eSamplerYcbcrConversionKHR);
    e_vk_DebugReportObjectTypeEXT.value("ACCELERATION_STRUCTURE_NV", ::vk::DebugReportObjectTypeEXT::eAccelerationStructureNV);

    e_vk_RasterizationOrderAMD.value("STRICT", ::vk::RasterizationOrderAMD::eStrict);
    e_vk_RasterizationOrderAMD.value("RELAXED", ::vk::RasterizationOrderAMD::eRelaxed);

    e_vk_QueryResultStatusKHR.value("ERROR", ::vk::QueryResultStatusKHR::eError);
    e_vk_QueryResultStatusKHR.value("NOT_READY", ::vk::QueryResultStatusKHR::eNotReady);
    e_vk_QueryResultStatusKHR.value("COMPLETE", ::vk::QueryResultStatusKHR::eComplete);
    e_vk_QueryResultStatusKHR.value("INSUFFICIENT_BITSTREAM_BUFFER_RANGE", ::vk::QueryResultStatusKHR::eInsufficientBitstreamBufferRange);


    e_vk_VideoCapabilityFlagBitsKHR.value("PROTECTED_CONTENT", ::vk::VideoCapabilityFlagBitsKHR::eProtectedContent);
    e_vk_VideoCapabilityFlagBitsKHR.value("SEPARATE_REFERENCE_IMAGES", ::vk::VideoCapabilityFlagBitsKHR::eSeparateReferenceImages);

    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("INVALID", ::vk::VideoChromaSubsamplingFlagBitsKHR::eInvalid);
    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("MONOCHROME", ::vk::VideoChromaSubsamplingFlagBitsKHR::eMonochrome);
    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("e420", ::vk::VideoChromaSubsamplingFlagBitsKHR::e420);
    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("e422", ::vk::VideoChromaSubsamplingFlagBitsKHR::e422);
    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("e444", ::vk::VideoChromaSubsamplingFlagBitsKHR::e444);

    e_vk_VideoCodecOperationFlagBitsKHR.value("NONE", ::vk::VideoCodecOperationFlagBitsKHR::eNone);
    e_vk_VideoCodecOperationFlagBitsKHR.value("ENCODE_H264", ::vk::VideoCodecOperationFlagBitsKHR::eEncodeH264);
    e_vk_VideoCodecOperationFlagBitsKHR.value("ENCODE_H265", ::vk::VideoCodecOperationFlagBitsKHR::eEncodeH265);
    e_vk_VideoCodecOperationFlagBitsKHR.value("DECODE_H264", ::vk::VideoCodecOperationFlagBitsKHR::eDecodeH264);
    e_vk_VideoCodecOperationFlagBitsKHR.value("DECODE_H265", ::vk::VideoCodecOperationFlagBitsKHR::eDecodeH265);

    e_vk_VideoCodingControlFlagBitsKHR.value("RESET", ::vk::VideoCodingControlFlagBitsKHR::eReset);
    e_vk_VideoCodingControlFlagBitsKHR.value("ENCODE_RATE_CONTROL", ::vk::VideoCodingControlFlagBitsKHR::eEncodeRateControl);
    e_vk_VideoCodingControlFlagBitsKHR.value("ENCODE_QUALITY_LEVEL", ::vk::VideoCodingControlFlagBitsKHR::eEncodeQualityLevel);

    e_vk_VideoComponentBitDepthFlagBitsKHR.value("INVALID", ::vk::VideoComponentBitDepthFlagBitsKHR::eInvalid);
    e_vk_VideoComponentBitDepthFlagBitsKHR.value("e8", ::vk::VideoComponentBitDepthFlagBitsKHR::e8);
    e_vk_VideoComponentBitDepthFlagBitsKHR.value("e10", ::vk::VideoComponentBitDepthFlagBitsKHR::e10);
    e_vk_VideoComponentBitDepthFlagBitsKHR.value("e12", ::vk::VideoComponentBitDepthFlagBitsKHR::e12);


    e_vk_VideoSessionCreateFlagBitsKHR.value("PROTECTED_CONTENT", ::vk::VideoSessionCreateFlagBitsKHR::eProtectedContent);
    e_vk_VideoSessionCreateFlagBitsKHR.value("ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS", ::vk::VideoSessionCreateFlagBitsKHR::eAllowEncodeParameterOptimizations);
    e_vk_VideoSessionCreateFlagBitsKHR.value("INLINE_QUERIES", ::vk::VideoSessionCreateFlagBitsKHR::eInlineQueries);


    e_vk_VideoDecodeCapabilityFlagBitsKHR.value("DPB_AND_OUTPUT_COINCIDE", ::vk::VideoDecodeCapabilityFlagBitsKHR::eDpbAndOutputCoincide);
    e_vk_VideoDecodeCapabilityFlagBitsKHR.value("DPB_AND_OUTPUT_DISTINCT", ::vk::VideoDecodeCapabilityFlagBitsKHR::eDpbAndOutputDistinct);


    e_vk_VideoDecodeUsageFlagBitsKHR.value("DEFAULT", ::vk::VideoDecodeUsageFlagBitsKHR::eDefault);
    e_vk_VideoDecodeUsageFlagBitsKHR.value("TRANSCODING", ::vk::VideoDecodeUsageFlagBitsKHR::eTranscoding);
    e_vk_VideoDecodeUsageFlagBitsKHR.value("OFFLINE", ::vk::VideoDecodeUsageFlagBitsKHR::eOffline);
    e_vk_VideoDecodeUsageFlagBitsKHR.value("STREAMING", ::vk::VideoDecodeUsageFlagBitsKHR::eStreaming);


    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("HRD_COMPLIANCE", ::vk::VideoEncodeH264CapabilityFlagBitsKHR::eHrdCompliance);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("PREDICTION_WEIGHT_TABLE_GENERATED", ::vk::VideoEncodeH264CapabilityFlagBitsKHR::ePredictionWeightTableGenerated);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("ROW_UNALIGNED_SLICE", ::vk::VideoEncodeH264CapabilityFlagBitsKHR::eRowUnalignedSlice);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("DIFFERENT_SLICE_TYPE", ::vk::VideoEncodeH264CapabilityFlagBitsKHR::eDifferentSliceType);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("eB_FRAME_IN_L0_LIST", ::vk::VideoEncodeH264CapabilityFlagBitsKHR::eBFrameInL0List);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("eB_FRAME_IN_L1_LIST", ::vk::VideoEncodeH264CapabilityFlagBitsKHR::eBFrameInL1List);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("PER_PICTURE_TYPE_MIN_MAX_QP", ::vk::VideoEncodeH264CapabilityFlagBitsKHR::ePerPictureTypeMinMaxQp);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("PER_SLICE_CONSTANT_QP", ::vk::VideoEncodeH264CapabilityFlagBitsKHR::ePerSliceConstantQp);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("GENERATE_PREFIX_NALU", ::vk::VideoEncodeH264CapabilityFlagBitsKHR::eGeneratePrefixNalu);

    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("ATTEMPT_HRD_COMPLIANCE", ::vk::VideoEncodeH264RateControlFlagBitsKHR::eAttemptHrdCompliance);
    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("REGULAR_GOP", ::vk::VideoEncodeH264RateControlFlagBitsKHR::eRegularGop);
    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("REFERENCE_PATTERN_FLAT", ::vk::VideoEncodeH264RateControlFlagBitsKHR::eReferencePatternFlat);
    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("REFERENCE_PATTERN_DYADIC", ::vk::VideoEncodeH264RateControlFlagBitsKHR::eReferencePatternDyadic);
    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("TEMPORAL_LAYER_PATTERN_DYADIC", ::vk::VideoEncodeH264RateControlFlagBitsKHR::eTemporalLayerPatternDyadic);

    e_vk_VideoEncodeH264StdFlagBitsKHR.value("SEPARATE_COLOR_PLANE_FLAG_SET", ::vk::VideoEncodeH264StdFlagBitsKHR::eSeparateColorPlaneFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET", ::vk::VideoEncodeH264StdFlagBitsKHR::eQpprimeYZeroTransformBypassFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("SCALING_MATRIX_PRESENT_FLAG_SET", ::vk::VideoEncodeH264StdFlagBitsKHR::eScalingMatrixPresentFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("CHROMA_QP_INDEX_OFFSET", ::vk::VideoEncodeH264StdFlagBitsKHR::eChromaQpIndexOffset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("SECOND_CHROMA_QP_INDEX_OFFSET", ::vk::VideoEncodeH264StdFlagBitsKHR::eSecondChromaQpIndexOffset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("PIC_INIT_QP_MINUS_26", ::vk::VideoEncodeH264StdFlagBitsKHR::ePicInitQpMinus26);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("WEIGHTED_PRED_FLAG_SET", ::vk::VideoEncodeH264StdFlagBitsKHR::eWeightedPredFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("WEIGHTED_BIPRED_IDC_EXPLICIT", ::vk::VideoEncodeH264StdFlagBitsKHR::eWeightedBipredIdcExplicit);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("WEIGHTED_BIPRED_IDC_IMPLICIT", ::vk::VideoEncodeH264StdFlagBitsKHR::eWeightedBipredIdcImplicit);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("TRANSFORM_8X8_MODE_FLAG_SET", ::vk::VideoEncodeH264StdFlagBitsKHR::eTransform8X8ModeFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DIRECT_SPATIAL_MV_PRED_FLAG_UNSET", ::vk::VideoEncodeH264StdFlagBitsKHR::eDirectSpatialMvPredFlagUnset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("ENTROPY_CODING_MODE_FLAG_UNSET", ::vk::VideoEncodeH264StdFlagBitsKHR::eEntropyCodingModeFlagUnset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("ENTROPY_CODING_MODE_FLAG_SET", ::vk::VideoEncodeH264StdFlagBitsKHR::eEntropyCodingModeFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DIRECT_8X8_INFERENCE_FLAG_UNSET", ::vk::VideoEncodeH264StdFlagBitsKHR::eDirect8X8InferenceFlagUnset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("CONSTRAINED_INTRA_PRED_FLAG_SET", ::vk::VideoEncodeH264StdFlagBitsKHR::eConstrainedIntraPredFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DEBLOCKING_FILTER_DISABLED", ::vk::VideoEncodeH264StdFlagBitsKHR::eDeblockingFilterDisabled);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DEBLOCKING_FILTER_ENABLED", ::vk::VideoEncodeH264StdFlagBitsKHR::eDeblockingFilterEnabled);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DEBLOCKING_FILTER_PARTIAL", ::vk::VideoEncodeH264StdFlagBitsKHR::eDeblockingFilterPartial);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("SLICE_QP_DELTA", ::vk::VideoEncodeH264StdFlagBitsKHR::eSliceQpDelta);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DIFFERENT_SLICE_QP_DELTA", ::vk::VideoEncodeH264StdFlagBitsKHR::eDifferentSliceQpDelta);

    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("HRD_COMPLIANCE", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::eHrdCompliance);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("PREDICTION_WEIGHT_TABLE_GENERATED", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::ePredictionWeightTableGenerated);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("ROW_UNALIGNED_SLICE_SEGMENT", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::eRowUnalignedSliceSegment);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("DIFFERENT_SLICE_SEGMENT_TYPE", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::eDifferentSliceSegmentType);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("eB_FRAME_IN_L0_LIST", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::eBFrameInL0List);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("eB_FRAME_IN_L1_LIST", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::eBFrameInL1List);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("PER_PICTURE_TYPE_MIN_MAX_QP", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::ePerPictureTypeMinMaxQp);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("PER_SLICE_SEGMENT_CONSTANT_QP", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::ePerSliceSegmentConstantQp);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("MULTIPLE_TILES_PER_SLICE_SEGMENT", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::eMultipleTilesPerSliceSegment);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("MULTIPLE_SLICE_SEGMENTS_PER_TILE", ::vk::VideoEncodeH265CapabilityFlagBitsKHR::eMultipleSliceSegmentsPerTile);

    e_vk_VideoEncodeH265CtbSizeFlagBitsKHR.value("e16", ::vk::VideoEncodeH265CtbSizeFlagBitsKHR::e16);
    e_vk_VideoEncodeH265CtbSizeFlagBitsKHR.value("e32", ::vk::VideoEncodeH265CtbSizeFlagBitsKHR::e32);
    e_vk_VideoEncodeH265CtbSizeFlagBitsKHR.value("e64", ::vk::VideoEncodeH265CtbSizeFlagBitsKHR::e64);

    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("ATTEMPT_HRD_COMPLIANCE", ::vk::VideoEncodeH265RateControlFlagBitsKHR::eAttemptHrdCompliance);
    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("REGULAR_GOP", ::vk::VideoEncodeH265RateControlFlagBitsKHR::eRegularGop);
    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("REFERENCE_PATTERN_FLAT", ::vk::VideoEncodeH265RateControlFlagBitsKHR::eReferencePatternFlat);
    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("REFERENCE_PATTERN_DYADIC", ::vk::VideoEncodeH265RateControlFlagBitsKHR::eReferencePatternDyadic);
    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("TEMPORAL_SUB_LAYER_PATTERN_DYADIC", ::vk::VideoEncodeH265RateControlFlagBitsKHR::eTemporalSubLayerPatternDyadic);

    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SEPARATE_COLOR_PLANE_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eSeparateColorPlaneFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eSampleAdaptiveOffsetEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SCALING_LIST_DATA_PRESENT_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eScalingListDataPresentFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("PCM_ENABLED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::ePcmEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SPS_TEMPORAL_MVP_ENABLED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eSpsTemporalMvpEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("INIT_QP_MINUS_26", ::vk::VideoEncodeH265StdFlagBitsKHR::eInitQpMinus26);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("WEIGHTED_PRED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eWeightedPredFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("WEIGHTED_BIPRED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eWeightedBipredFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("LOG_2_PARALLEL_MERGE_LEVEL_MINUS_2", ::vk::VideoEncodeH265StdFlagBitsKHR::eLog2ParallelMergeLevelMinus2);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SIGN_DATA_HIDING_ENABLED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eSignDataHidingEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("TRANSFORM_SKIP_ENABLED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eTransformSkipEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("TRANSFORM_SKIP_ENABLED_FLAG_UNSET", ::vk::VideoEncodeH265StdFlagBitsKHR::eTransformSkipEnabledFlagUnset);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::ePpsSliceChromaQpOffsetsPresentFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("TRANSQUANT_BYPASS_ENABLED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eTransquantBypassEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("CONSTRAINED_INTRA_PRED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eConstrainedIntraPredFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("ENTROPY_CODING_SYNC_ENABLED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eEntropyCodingSyncEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eDeblockingFilterOverrideEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eDependentSliceSegmentsEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("DEPENDENT_SLICE_SEGMENT_FLAG_SET", ::vk::VideoEncodeH265StdFlagBitsKHR::eDependentSliceSegmentFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SLICE_QP_DELTA", ::vk::VideoEncodeH265StdFlagBitsKHR::eSliceQpDelta);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("DIFFERENT_SLICE_QP_DELTA", ::vk::VideoEncodeH265StdFlagBitsKHR::eDifferentSliceQpDelta);

    e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR.value("e4", ::vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR::e4);
    e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR.value("e8", ::vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR::e8);
    e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR.value("e16", ::vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR::e16);
    e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR.value("e32", ::vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR::e32);

    e_vk_VideoDecodeH264PictureLayoutFlagBitsKHR.value("PROGRESSIVE", ::vk::VideoDecodeH264PictureLayoutFlagBitsKHR::eProgressive);
    e_vk_VideoDecodeH264PictureLayoutFlagBitsKHR.value("INTERLACED_INTERLEAVED_LINES", ::vk::VideoDecodeH264PictureLayoutFlagBitsKHR::eInterlacedInterleavedLines);
    e_vk_VideoDecodeH264PictureLayoutFlagBitsKHR.value("INTERLACED_SEPARATE_PLANES", ::vk::VideoDecodeH264PictureLayoutFlagBitsKHR::eInterlacedSeparatePlanes);

    e_vk_ShaderInfoTypeAMD.value("STATISTICS", ::vk::ShaderInfoTypeAMD::eStatistics);
    e_vk_ShaderInfoTypeAMD.value("BINARY", ::vk::ShaderInfoTypeAMD::eBinary);
    e_vk_ShaderInfoTypeAMD.value("DISASSEMBLY", ::vk::ShaderInfoTypeAMD::eDisassembly);

    e_vk_ExternalMemoryFeatureFlagBitsNV.value("DEDICATED_ONLY", ::vk::ExternalMemoryFeatureFlagBitsNV::eDedicatedOnly);
    e_vk_ExternalMemoryFeatureFlagBitsNV.value("EXPORTABLE", ::vk::ExternalMemoryFeatureFlagBitsNV::eExportable);
    e_vk_ExternalMemoryFeatureFlagBitsNV.value("IMPORTABLE", ::vk::ExternalMemoryFeatureFlagBitsNV::eImportable);

    e_vk_ExternalMemoryHandleTypeFlagBitsNV.value("OPAQUE_WIN_32", ::vk::ExternalMemoryHandleTypeFlagBitsNV::eOpaqueWin32);
    e_vk_ExternalMemoryHandleTypeFlagBitsNV.value("OPAQUE_WIN_32_KMT", ::vk::ExternalMemoryHandleTypeFlagBitsNV::eOpaqueWin32Kmt);
    e_vk_ExternalMemoryHandleTypeFlagBitsNV.value("eD3D11_IMAGE", ::vk::ExternalMemoryHandleTypeFlagBitsNV::eD3D11Image);
    e_vk_ExternalMemoryHandleTypeFlagBitsNV.value("eD3D11_IMAGE_KMT", ::vk::ExternalMemoryHandleTypeFlagBitsNV::eD3D11ImageKmt);

    e_vk_ValidationCheckEXT.value("ALL", ::vk::ValidationCheckEXT::eAll);
    e_vk_ValidationCheckEXT.value("SHADERS", ::vk::ValidationCheckEXT::eShaders);

    e_vk_PipelineRobustnessBufferBehaviorEXT.value("DEVICE_DEFAULT", ::vk::PipelineRobustnessBufferBehaviorEXT::eDeviceDefault);
    e_vk_PipelineRobustnessBufferBehaviorEXT.value("DISABLED", ::vk::PipelineRobustnessBufferBehaviorEXT::eDisabled);
    e_vk_PipelineRobustnessBufferBehaviorEXT.value("ROBUST_BUFFER_ACCESS", ::vk::PipelineRobustnessBufferBehaviorEXT::eRobustBufferAccess);
    e_vk_PipelineRobustnessBufferBehaviorEXT.value("ROBUST_BUFFER_ACCESS_2", ::vk::PipelineRobustnessBufferBehaviorEXT::eRobustBufferAccess2);

    e_vk_PipelineRobustnessImageBehaviorEXT.value("DEVICE_DEFAULT", ::vk::PipelineRobustnessImageBehaviorEXT::eDeviceDefault);
    e_vk_PipelineRobustnessImageBehaviorEXT.value("DISABLED", ::vk::PipelineRobustnessImageBehaviorEXT::eDisabled);
    e_vk_PipelineRobustnessImageBehaviorEXT.value("ROBUST_IMAGE_ACCESS", ::vk::PipelineRobustnessImageBehaviorEXT::eRobustImageAccess);
    e_vk_PipelineRobustnessImageBehaviorEXT.value("ROBUST_IMAGE_ACCESS_2", ::vk::PipelineRobustnessImageBehaviorEXT::eRobustImageAccess2);

    e_vk_ConditionalRenderingFlagBitsEXT.value("INVERTED", ::vk::ConditionalRenderingFlagBitsEXT::eInverted);

    e_vk_SurfaceCounterFlagBitsEXT.value("VBLANK", ::vk::SurfaceCounterFlagBitsEXT::eVblank);

    e_vk_DeviceEventTypeEXT.value("DISPLAY_HOTPLUG", ::vk::DeviceEventTypeEXT::eDisplayHotplug);

    e_vk_DisplayEventTypeEXT.value("FIRST_PIXEL_OUT", ::vk::DisplayEventTypeEXT::eFirstPixelOut);

    e_vk_DisplayPowerStateEXT.value("OFF", ::vk::DisplayPowerStateEXT::eOff);
    e_vk_DisplayPowerStateEXT.value("SUSPEND", ::vk::DisplayPowerStateEXT::eSuspend);
    e_vk_DisplayPowerStateEXT.value("ON", ::vk::DisplayPowerStateEXT::eOn);


    e_vk_ViewportCoordinateSwizzleNV.value("POSITIVE_X", ::vk::ViewportCoordinateSwizzleNV::ePositiveX);
    e_vk_ViewportCoordinateSwizzleNV.value("NEGATIVE_X", ::vk::ViewportCoordinateSwizzleNV::eNegativeX);
    e_vk_ViewportCoordinateSwizzleNV.value("POSITIVE_Y", ::vk::ViewportCoordinateSwizzleNV::ePositiveY);
    e_vk_ViewportCoordinateSwizzleNV.value("NEGATIVE_Y", ::vk::ViewportCoordinateSwizzleNV::eNegativeY);
    e_vk_ViewportCoordinateSwizzleNV.value("POSITIVE_Z", ::vk::ViewportCoordinateSwizzleNV::ePositiveZ);
    e_vk_ViewportCoordinateSwizzleNV.value("NEGATIVE_Z", ::vk::ViewportCoordinateSwizzleNV::eNegativeZ);
    e_vk_ViewportCoordinateSwizzleNV.value("POSITIVE_W", ::vk::ViewportCoordinateSwizzleNV::ePositiveW);
    e_vk_ViewportCoordinateSwizzleNV.value("NEGATIVE_W", ::vk::ViewportCoordinateSwizzleNV::eNegativeW);

    e_vk_DiscardRectangleModeEXT.value("INCLUSIVE", ::vk::DiscardRectangleModeEXT::eInclusive);
    e_vk_DiscardRectangleModeEXT.value("EXCLUSIVE", ::vk::DiscardRectangleModeEXT::eExclusive);


    e_vk_ConservativeRasterizationModeEXT.value("DISABLED", ::vk::ConservativeRasterizationModeEXT::eDisabled);
    e_vk_ConservativeRasterizationModeEXT.value("OVERESTIMATE", ::vk::ConservativeRasterizationModeEXT::eOverestimate);
    e_vk_ConservativeRasterizationModeEXT.value("UNDERESTIMATE", ::vk::ConservativeRasterizationModeEXT::eUnderestimate);




    e_vk_PerformanceCounterDescriptionFlagBitsKHR.value("PERFORMANCE_IMPACTING", ::vk::PerformanceCounterDescriptionFlagBitsKHR::ePerformanceImpacting);
    e_vk_PerformanceCounterDescriptionFlagBitsKHR.value("CONCURRENTLY_IMPACTED", ::vk::PerformanceCounterDescriptionFlagBitsKHR::eConcurrentlyImpacted);

    e_vk_PerformanceCounterScopeKHR.value("COMMAND_BUFFER", ::vk::PerformanceCounterScopeKHR::eCommandBuffer);
    e_vk_PerformanceCounterScopeKHR.value("RENDER_PASS", ::vk::PerformanceCounterScopeKHR::eRenderPass);
    e_vk_PerformanceCounterScopeKHR.value("COMMAND", ::vk::PerformanceCounterScopeKHR::eCommand);
    e_vk_PerformanceCounterScopeKHR.value("VK_QUERY_SCOPE_COMMAND_BUFFER", ::vk::PerformanceCounterScopeKHR::eVkQueryScopeCommandBuffer);
    e_vk_PerformanceCounterScopeKHR.value("VK_QUERY_SCOPE_RENDER_PASS", ::vk::PerformanceCounterScopeKHR::eVkQueryScopeRenderPass);
    e_vk_PerformanceCounterScopeKHR.value("VK_QUERY_SCOPE_COMMAND", ::vk::PerformanceCounterScopeKHR::eVkQueryScopeCommand);

    e_vk_PerformanceCounterStorageKHR.value("INT_32", ::vk::PerformanceCounterStorageKHR::eInt32);
    e_vk_PerformanceCounterStorageKHR.value("INT_64", ::vk::PerformanceCounterStorageKHR::eInt64);
    e_vk_PerformanceCounterStorageKHR.value("UINT_32", ::vk::PerformanceCounterStorageKHR::eUint32);
    e_vk_PerformanceCounterStorageKHR.value("UINT_64", ::vk::PerformanceCounterStorageKHR::eUint64);
    e_vk_PerformanceCounterStorageKHR.value("FLOAT_32", ::vk::PerformanceCounterStorageKHR::eFloat32);
    e_vk_PerformanceCounterStorageKHR.value("FLOAT_64", ::vk::PerformanceCounterStorageKHR::eFloat64);

    e_vk_PerformanceCounterUnitKHR.value("GENERIC", ::vk::PerformanceCounterUnitKHR::eGeneric);
    e_vk_PerformanceCounterUnitKHR.value("PERCENTAGE", ::vk::PerformanceCounterUnitKHR::ePercentage);
    e_vk_PerformanceCounterUnitKHR.value("NANOSECONDS", ::vk::PerformanceCounterUnitKHR::eNanoseconds);
    e_vk_PerformanceCounterUnitKHR.value("BYTES", ::vk::PerformanceCounterUnitKHR::eBytes);
    e_vk_PerformanceCounterUnitKHR.value("BYTES_PER_SECOND", ::vk::PerformanceCounterUnitKHR::eBytesPerSecond);
    e_vk_PerformanceCounterUnitKHR.value("KELVIN", ::vk::PerformanceCounterUnitKHR::eKelvin);
    e_vk_PerformanceCounterUnitKHR.value("WATTS", ::vk::PerformanceCounterUnitKHR::eWatts);
    e_vk_PerformanceCounterUnitKHR.value("VOLTS", ::vk::PerformanceCounterUnitKHR::eVolts);
    e_vk_PerformanceCounterUnitKHR.value("AMPS", ::vk::PerformanceCounterUnitKHR::eAmps);
    e_vk_PerformanceCounterUnitKHR.value("HERTZ", ::vk::PerformanceCounterUnitKHR::eHertz);
    e_vk_PerformanceCounterUnitKHR.value("CYCLES", ::vk::PerformanceCounterUnitKHR::eCycles);

    e_vk_DebugUtilsMessageSeverityFlagBitsEXT.value("VERBOSE", ::vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose);
    e_vk_DebugUtilsMessageSeverityFlagBitsEXT.value("INFO", ::vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo);
    e_vk_DebugUtilsMessageSeverityFlagBitsEXT.value("WARNING", ::vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning);
    e_vk_DebugUtilsMessageSeverityFlagBitsEXT.value("ERROR", ::vk::DebugUtilsMessageSeverityFlagBitsEXT::eError);

    e_vk_DebugUtilsMessageTypeFlagBitsEXT.value("GENERAL", ::vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral);
    e_vk_DebugUtilsMessageTypeFlagBitsEXT.value("VALIDATION", ::vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation);
    e_vk_DebugUtilsMessageTypeFlagBitsEXT.value("PERFORMANCE", ::vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance);
    e_vk_DebugUtilsMessageTypeFlagBitsEXT.value("DEVICE_ADDRESS_BINDING", ::vk::DebugUtilsMessageTypeFlagBitsEXT::eDeviceAddressBinding);



    e_vk_BlendOverlapEXT.value("UNCORRELATED", ::vk::BlendOverlapEXT::eUncorrelated);
    e_vk_BlendOverlapEXT.value("DISJOINT", ::vk::BlendOverlapEXT::eDisjoint);
    e_vk_BlendOverlapEXT.value("CONJOINT", ::vk::BlendOverlapEXT::eConjoint);


    e_vk_AccelerationStructureBuildTypeKHR.value("HOST", ::vk::AccelerationStructureBuildTypeKHR::eHost);
    e_vk_AccelerationStructureBuildTypeKHR.value("DEVICE", ::vk::AccelerationStructureBuildTypeKHR::eDevice);
    e_vk_AccelerationStructureBuildTypeKHR.value("HOST_OR_DEVICE", ::vk::AccelerationStructureBuildTypeKHR::eHostOrDevice);

    e_vk_AccelerationStructureCompatibilityKHR.value("COMPATIBLE", ::vk::AccelerationStructureCompatibilityKHR::eCompatible);
    e_vk_AccelerationStructureCompatibilityKHR.value("INCOMPATIBLE", ::vk::AccelerationStructureCompatibilityKHR::eIncompatible);

    e_vk_AccelerationStructureCreateFlagBitsKHR.value("DEVICE_ADDRESS_CAPTURE_REPLAY", ::vk::AccelerationStructureCreateFlagBitsKHR::eDeviceAddressCaptureReplay);
    e_vk_AccelerationStructureCreateFlagBitsKHR.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", ::vk::AccelerationStructureCreateFlagBitsKHR::eDescriptorBufferCaptureReplayEXT);
    e_vk_AccelerationStructureCreateFlagBitsKHR.value("MOTION_NV", ::vk::AccelerationStructureCreateFlagBitsKHR::eMotionNV);

    e_vk_AccelerationStructureTypeKHR.value("TOP_LEVEL", ::vk::AccelerationStructureTypeKHR::eTopLevel);
    e_vk_AccelerationStructureTypeKHR.value("BOTTOM_LEVEL", ::vk::AccelerationStructureTypeKHR::eBottomLevel);
    e_vk_AccelerationStructureTypeKHR.value("GENERIC", ::vk::AccelerationStructureTypeKHR::eGeneric);

    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_UPDATE", ::vk::BuildAccelerationStructureFlagBitsKHR::eAllowUpdate);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_COMPACTION", ::vk::BuildAccelerationStructureFlagBitsKHR::eAllowCompaction);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("PREFER_FAST_TRACE", ::vk::BuildAccelerationStructureFlagBitsKHR::ePreferFastTrace);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("PREFER_FAST_BUILD", ::vk::BuildAccelerationStructureFlagBitsKHR::ePreferFastBuild);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("LOW_MEMORY", ::vk::BuildAccelerationStructureFlagBitsKHR::eLowMemory);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("MOTION_NV", ::vk::BuildAccelerationStructureFlagBitsKHR::eMotionNV);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_OPACITY_MICROMAP_UPDATE_EXT", ::vk::BuildAccelerationStructureFlagBitsKHR::eAllowOpacityMicromapUpdateEXT);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_DISABLE_OPACITY_MICROMAPS_EXT", ::vk::BuildAccelerationStructureFlagBitsKHR::eAllowDisableOpacityMicromapsEXT);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_OPACITY_MICROMAP_DATA_UPDATE_EXT", ::vk::BuildAccelerationStructureFlagBitsKHR::eAllowOpacityMicromapDataUpdateEXT);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_DATA_ACCESS", ::vk::BuildAccelerationStructureFlagBitsKHR::eAllowDataAccess);

    e_vk_BuildAccelerationStructureModeKHR.value("BUILD", ::vk::BuildAccelerationStructureModeKHR::eBuild);
    e_vk_BuildAccelerationStructureModeKHR.value("UPDATE", ::vk::BuildAccelerationStructureModeKHR::eUpdate);

    e_vk_CopyAccelerationStructureModeKHR.value("CLONE", ::vk::CopyAccelerationStructureModeKHR::eClone);
    e_vk_CopyAccelerationStructureModeKHR.value("COMPACT", ::vk::CopyAccelerationStructureModeKHR::eCompact);
    e_vk_CopyAccelerationStructureModeKHR.value("SERIALIZE", ::vk::CopyAccelerationStructureModeKHR::eSerialize);
    e_vk_CopyAccelerationStructureModeKHR.value("DESERIALIZE", ::vk::CopyAccelerationStructureModeKHR::eDeserialize);

    e_vk_GeometryFlagBitsKHR.value("OPAQUE", ::vk::GeometryFlagBitsKHR::eOpaque);
    e_vk_GeometryFlagBitsKHR.value("NO_DUPLICATE_ANY_HIT_INVOCATION", ::vk::GeometryFlagBitsKHR::eNoDuplicateAnyHitInvocation);

    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_FACING_CULL_DISABLE", ::vk::GeometryInstanceFlagBitsKHR::eTriangleFacingCullDisable);
    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_FLIP_FACING", ::vk::GeometryInstanceFlagBitsKHR::eTriangleFlipFacing);
    e_vk_GeometryInstanceFlagBitsKHR.value("FORCE_OPAQUE", ::vk::GeometryInstanceFlagBitsKHR::eForceOpaque);
    e_vk_GeometryInstanceFlagBitsKHR.value("FORCE_NO_OPAQUE", ::vk::GeometryInstanceFlagBitsKHR::eForceNoOpaque);
    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_FRONT_COUNTERCLOCKWISE_KHR", ::vk::GeometryInstanceFlagBitsKHR::eTriangleFrontCounterclockwiseKHR);
    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_CULL_DISABLE", ::vk::GeometryInstanceFlagBitsKHR::eTriangleCullDisable);
    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_FRONT_COUNTERCLOCKWISE", ::vk::GeometryInstanceFlagBitsKHR::eTriangleFrontCounterclockwise);
    e_vk_GeometryInstanceFlagBitsKHR.value("FORCE_OPACITY_MICROMAP_2_STATE_EXT", ::vk::GeometryInstanceFlagBitsKHR::eForceOpacityMicromap2StateEXT);
    e_vk_GeometryInstanceFlagBitsKHR.value("DISABLE_OPACITY_MICROMAPS_EXT", ::vk::GeometryInstanceFlagBitsKHR::eDisableOpacityMicromapsEXT);

    e_vk_GeometryTypeKHR.value("TRIANGLES", ::vk::GeometryTypeKHR::eTriangles);
    e_vk_GeometryTypeKHR.value("AABBS", ::vk::GeometryTypeKHR::eAabbs);
    e_vk_GeometryTypeKHR.value("INSTANCES", ::vk::GeometryTypeKHR::eInstances);

    e_vk_RayTracingShaderGroupTypeKHR.value("GENERAL", ::vk::RayTracingShaderGroupTypeKHR::eGeneral);
    e_vk_RayTracingShaderGroupTypeKHR.value("TRIANGLES_HIT_GROUP", ::vk::RayTracingShaderGroupTypeKHR::eTrianglesHitGroup);
    e_vk_RayTracingShaderGroupTypeKHR.value("PROCEDURAL_HIT_GROUP", ::vk::RayTracingShaderGroupTypeKHR::eProceduralHitGroup);

    e_vk_ShaderGroupShaderKHR.value("GENERAL", ::vk::ShaderGroupShaderKHR::eGeneral);
    e_vk_ShaderGroupShaderKHR.value("CLOSEST_HIT", ::vk::ShaderGroupShaderKHR::eClosestHit);
    e_vk_ShaderGroupShaderKHR.value("ANY_HIT", ::vk::ShaderGroupShaderKHR::eAnyHit);
    e_vk_ShaderGroupShaderKHR.value("INTERSECTION", ::vk::ShaderGroupShaderKHR::eIntersection);

    e_vk_CoverageModulationModeNV.value("NONE", ::vk::CoverageModulationModeNV::eNone);
    e_vk_CoverageModulationModeNV.value("RGB", ::vk::CoverageModulationModeNV::eRgb);
    e_vk_CoverageModulationModeNV.value("ALPHA", ::vk::CoverageModulationModeNV::eAlpha);
    e_vk_CoverageModulationModeNV.value("RGBA", ::vk::CoverageModulationModeNV::eRgba);



    e_vk_ValidationCacheHeaderVersionEXT.value("ONE", ::vk::ValidationCacheHeaderVersionEXT::eOne);

    e_vk_CoarseSampleOrderTypeNV.value("DEFAULT", ::vk::CoarseSampleOrderTypeNV::eDefault);
    e_vk_CoarseSampleOrderTypeNV.value("CUSTOM", ::vk::CoarseSampleOrderTypeNV::eCustom);
    e_vk_CoarseSampleOrderTypeNV.value("PIXEL_MAJOR", ::vk::CoarseSampleOrderTypeNV::ePixelMajor);
    e_vk_CoarseSampleOrderTypeNV.value("SAMPLE_MAJOR", ::vk::CoarseSampleOrderTypeNV::eSampleMajor);

    e_vk_ShadingRatePaletteEntryNV.value("NO_INVOCATIONS", ::vk::ShadingRatePaletteEntryNV::eNoInvocations);
    e_vk_ShadingRatePaletteEntryNV.value("e16_INVOCATIONS_PER_PIXEL", ::vk::ShadingRatePaletteEntryNV::e16InvocationsPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("e8_INVOCATIONS_PER_PIXEL", ::vk::ShadingRatePaletteEntryNV::e8InvocationsPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("e4_INVOCATIONS_PER_PIXEL", ::vk::ShadingRatePaletteEntryNV::e4InvocationsPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("e2_INVOCATIONS_PER_PIXEL", ::vk::ShadingRatePaletteEntryNV::e2InvocationsPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("e1_INVOCATION_PER_PIXEL", ::vk::ShadingRatePaletteEntryNV::e1InvocationPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("e1_INVOCATION_PER_2X1_PIXELS", ::vk::ShadingRatePaletteEntryNV::e1InvocationPer2X1Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("e1_INVOCATION_PER_1X2_PIXELS", ::vk::ShadingRatePaletteEntryNV::e1InvocationPer1X2Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("e1_INVOCATION_PER_2X2_PIXELS", ::vk::ShadingRatePaletteEntryNV::e1InvocationPer2X2Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("e1_INVOCATION_PER_4X2_PIXELS", ::vk::ShadingRatePaletteEntryNV::e1InvocationPer4X2Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("e1_INVOCATION_PER_2X4_PIXELS", ::vk::ShadingRatePaletteEntryNV::e1InvocationPer2X4Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("e1_INVOCATION_PER_4X4_PIXELS", ::vk::ShadingRatePaletteEntryNV::e1InvocationPer4X4Pixels);

    e_vk_AccelerationStructureMemoryRequirementsTypeNV.value("OBJECT", ::vk::AccelerationStructureMemoryRequirementsTypeNV::eObject);
    e_vk_AccelerationStructureMemoryRequirementsTypeNV.value("BUILD_SCRATCH", ::vk::AccelerationStructureMemoryRequirementsTypeNV::eBuildScratch);
    e_vk_AccelerationStructureMemoryRequirementsTypeNV.value("UPDATE_SCRATCH", ::vk::AccelerationStructureMemoryRequirementsTypeNV::eUpdateScratch);


    e_vk_QueueGlobalPriorityKHR.value("LOW", ::vk::QueueGlobalPriorityKHR::eLow);
    e_vk_QueueGlobalPriorityKHR.value("MEDIUM", ::vk::QueueGlobalPriorityKHR::eMedium);
    e_vk_QueueGlobalPriorityKHR.value("HIGH", ::vk::QueueGlobalPriorityKHR::eHigh);
    e_vk_QueueGlobalPriorityKHR.value("REALTIME", ::vk::QueueGlobalPriorityKHR::eRealtime);

    e_vk_MemoryOverallocationBehaviorAMD.value("DEFAULT", ::vk::MemoryOverallocationBehaviorAMD::eDefault);
    e_vk_MemoryOverallocationBehaviorAMD.value("ALLOWED", ::vk::MemoryOverallocationBehaviorAMD::eAllowed);
    e_vk_MemoryOverallocationBehaviorAMD.value("DISALLOWED", ::vk::MemoryOverallocationBehaviorAMD::eDisallowed);

    e_vk_PerformanceConfigurationTypeINTEL.value("COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED", ::vk::PerformanceConfigurationTypeINTEL::eCommandQueueMetricsDiscoveryActivated);

    e_vk_PerformanceOverrideTypeINTEL.value("NULL_HARDWARE", ::vk::PerformanceOverrideTypeINTEL::eNullHardware);
    e_vk_PerformanceOverrideTypeINTEL.value("FLUSH_GPU_CACHES", ::vk::PerformanceOverrideTypeINTEL::eFlushGpuCaches);

    e_vk_PerformanceParameterTypeINTEL.value("HW_COUNTERS_SUPPORTED", ::vk::PerformanceParameterTypeINTEL::eHwCountersSupported);
    e_vk_PerformanceParameterTypeINTEL.value("STREAM_MARKER_VALID_BITS", ::vk::PerformanceParameterTypeINTEL::eStreamMarkerValidBits);

    e_vk_PerformanceValueTypeINTEL.value("UINT_32", ::vk::PerformanceValueTypeINTEL::eUint32);
    e_vk_PerformanceValueTypeINTEL.value("UINT_64", ::vk::PerformanceValueTypeINTEL::eUint64);
    e_vk_PerformanceValueTypeINTEL.value("FLOAT", ::vk::PerformanceValueTypeINTEL::eFloat);
    e_vk_PerformanceValueTypeINTEL.value("BOOL", ::vk::PerformanceValueTypeINTEL::eBool);
    e_vk_PerformanceValueTypeINTEL.value("STRING", ::vk::PerformanceValueTypeINTEL::eString);

    e_vk_QueryPoolSamplingModeINTEL.value("MANUAL", ::vk::QueryPoolSamplingModeINTEL::eManual);

    e_vk_FragmentShadingRateCombinerOpKHR.value("KEEP", ::vk::FragmentShadingRateCombinerOpKHR::eKeep);
    e_vk_FragmentShadingRateCombinerOpKHR.value("REPLACE", ::vk::FragmentShadingRateCombinerOpKHR::eReplace);
    e_vk_FragmentShadingRateCombinerOpKHR.value("MIN", ::vk::FragmentShadingRateCombinerOpKHR::eMin);
    e_vk_FragmentShadingRateCombinerOpKHR.value("MAX", ::vk::FragmentShadingRateCombinerOpKHR::eMax);
    e_vk_FragmentShadingRateCombinerOpKHR.value("MUL", ::vk::FragmentShadingRateCombinerOpKHR::eMul);


    e_vk_ValidationFeatureDisableEXT.value("ALL", ::vk::ValidationFeatureDisableEXT::eAll);
    e_vk_ValidationFeatureDisableEXT.value("SHADERS", ::vk::ValidationFeatureDisableEXT::eShaders);
    e_vk_ValidationFeatureDisableEXT.value("THREAD_SAFETY", ::vk::ValidationFeatureDisableEXT::eThreadSafety);
    e_vk_ValidationFeatureDisableEXT.value("API_PARAMETERS", ::vk::ValidationFeatureDisableEXT::eApiParameters);
    e_vk_ValidationFeatureDisableEXT.value("OBJECT_LIFETIMES", ::vk::ValidationFeatureDisableEXT::eObjectLifetimes);
    e_vk_ValidationFeatureDisableEXT.value("CORE_CHECKS", ::vk::ValidationFeatureDisableEXT::eCoreChecks);
    e_vk_ValidationFeatureDisableEXT.value("UNIQUE_HANDLES", ::vk::ValidationFeatureDisableEXT::eUniqueHandles);
    e_vk_ValidationFeatureDisableEXT.value("SHADER_VALIDATION_CACHE", ::vk::ValidationFeatureDisableEXT::eShaderValidationCache);

    e_vk_ValidationFeatureEnableEXT.value("GPU_ASSISTED", ::vk::ValidationFeatureEnableEXT::eGpuAssisted);
    e_vk_ValidationFeatureEnableEXT.value("GPU_ASSISTED_RESERVE_BINDING_SLOT", ::vk::ValidationFeatureEnableEXT::eGpuAssistedReserveBindingSlot);
    e_vk_ValidationFeatureEnableEXT.value("BEST_PRACTICES", ::vk::ValidationFeatureEnableEXT::eBestPractices);
    e_vk_ValidationFeatureEnableEXT.value("DEBUG_PRINTF", ::vk::ValidationFeatureEnableEXT::eDebugPrintf);
    e_vk_ValidationFeatureEnableEXT.value("SYNCHRONIZATION_VALIDATION", ::vk::ValidationFeatureEnableEXT::eSynchronizationValidation);

    e_vk_CoverageReductionModeNV.value("MERGE", ::vk::CoverageReductionModeNV::eMerge);
    e_vk_CoverageReductionModeNV.value("TRUNCATE", ::vk::CoverageReductionModeNV::eTruncate);


    e_vk_ProvokingVertexModeEXT.value("FIRST_VERTEX", ::vk::ProvokingVertexModeEXT::eFirstVertex);
    e_vk_ProvokingVertexModeEXT.value("LAST_VERTEX", ::vk::ProvokingVertexModeEXT::eLastVertex);


    e_vk_LineRasterizationModeEXT.value("DEFAULT", ::vk::LineRasterizationModeEXT::eDefault);
    e_vk_LineRasterizationModeEXT.value("RECTANGULAR", ::vk::LineRasterizationModeEXT::eRectangular);
    e_vk_LineRasterizationModeEXT.value("BRESENHAM", ::vk::LineRasterizationModeEXT::eBresenham);
    e_vk_LineRasterizationModeEXT.value("RECTANGULAR_SMOOTH", ::vk::LineRasterizationModeEXT::eRectangularSmooth);

    e_vk_PipelineExecutableStatisticFormatKHR.value("BOOL_32", ::vk::PipelineExecutableStatisticFormatKHR::eBool32);
    e_vk_PipelineExecutableStatisticFormatKHR.value("INT_64", ::vk::PipelineExecutableStatisticFormatKHR::eInt64);
    e_vk_PipelineExecutableStatisticFormatKHR.value("UINT_64", ::vk::PipelineExecutableStatisticFormatKHR::eUint64);
    e_vk_PipelineExecutableStatisticFormatKHR.value("FLOAT_64", ::vk::PipelineExecutableStatisticFormatKHR::eFloat64);

    e_vk_HostImageCopyFlagBitsEXT.value("MEMCPY", ::vk::HostImageCopyFlagBitsEXT::eMemcpy);


    e_vk_PresentGravityFlagBitsEXT.value("MIN", ::vk::PresentGravityFlagBitsEXT::eMin);
    e_vk_PresentGravityFlagBitsEXT.value("MAX", ::vk::PresentGravityFlagBitsEXT::eMax);
    e_vk_PresentGravityFlagBitsEXT.value("CENTERED", ::vk::PresentGravityFlagBitsEXT::eCentered);

    e_vk_PresentScalingFlagBitsEXT.value("ONE_TO_ONE", ::vk::PresentScalingFlagBitsEXT::eOneToOne);
    e_vk_PresentScalingFlagBitsEXT.value("ASPECT_RATIO_STRETCH", ::vk::PresentScalingFlagBitsEXT::eAspectRatioStretch);
    e_vk_PresentScalingFlagBitsEXT.value("STRETCH", ::vk::PresentScalingFlagBitsEXT::eStretch);

    e_vk_IndirectCommandsLayoutUsageFlagBitsNV.value("EXPLICIT_PREPROCESS", ::vk::IndirectCommandsLayoutUsageFlagBitsNV::eExplicitPreprocess);
    e_vk_IndirectCommandsLayoutUsageFlagBitsNV.value("INDEXED_SEQUENCES", ::vk::IndirectCommandsLayoutUsageFlagBitsNV::eIndexedSequences);
    e_vk_IndirectCommandsLayoutUsageFlagBitsNV.value("UNORDERED_SEQUENCES", ::vk::IndirectCommandsLayoutUsageFlagBitsNV::eUnorderedSequences);

    e_vk_IndirectCommandsTokenTypeNV.value("SHADER_GROUP", ::vk::IndirectCommandsTokenTypeNV::eShaderGroup);
    e_vk_IndirectCommandsTokenTypeNV.value("STATE_FLAGS", ::vk::IndirectCommandsTokenTypeNV::eStateFlags);
    e_vk_IndirectCommandsTokenTypeNV.value("INDEX_BUFFER", ::vk::IndirectCommandsTokenTypeNV::eIndexBuffer);
    e_vk_IndirectCommandsTokenTypeNV.value("VERTEX_BUFFER", ::vk::IndirectCommandsTokenTypeNV::eVertexBuffer);
    e_vk_IndirectCommandsTokenTypeNV.value("PUSH_CONSTANT", ::vk::IndirectCommandsTokenTypeNV::ePushConstant);
    e_vk_IndirectCommandsTokenTypeNV.value("DRAW_INDEXED", ::vk::IndirectCommandsTokenTypeNV::eDrawIndexed);
    e_vk_IndirectCommandsTokenTypeNV.value("DRAW", ::vk::IndirectCommandsTokenTypeNV::eDraw);
    e_vk_IndirectCommandsTokenTypeNV.value("DRAW_TASKS", ::vk::IndirectCommandsTokenTypeNV::eDrawTasks);
    e_vk_IndirectCommandsTokenTypeNV.value("DRAW_MESH_TASKS", ::vk::IndirectCommandsTokenTypeNV::eDrawMeshTasks);
    e_vk_IndirectCommandsTokenTypeNV.value("PIPELINE", ::vk::IndirectCommandsTokenTypeNV::ePipeline);
    e_vk_IndirectCommandsTokenTypeNV.value("DISPATCH", ::vk::IndirectCommandsTokenTypeNV::eDispatch);

    e_vk_IndirectStateFlagBitsNV.value("FLAG_FRONTFACE", ::vk::IndirectStateFlagBitsNV::eFlagFrontface);

    e_vk_DepthBiasRepresentationEXT.value("LEAST_REPRESENTABLE_VALUE_FORMAT", ::vk::DepthBiasRepresentationEXT::eLeastRepresentableValueFormat);
    e_vk_DepthBiasRepresentationEXT.value("LEAST_REPRESENTABLE_VALUE_FORCE_UNORM", ::vk::DepthBiasRepresentationEXT::eLeastRepresentableValueForceUnorm);
    e_vk_DepthBiasRepresentationEXT.value("FLOAT", ::vk::DepthBiasRepresentationEXT::eFloat);

    e_vk_DeviceMemoryReportEventTypeEXT.value("ALLOCATE", ::vk::DeviceMemoryReportEventTypeEXT::eAllocate);
    e_vk_DeviceMemoryReportEventTypeEXT.value("FREE", ::vk::DeviceMemoryReportEventTypeEXT::eFree);
    e_vk_DeviceMemoryReportEventTypeEXT.value("IMPORT", ::vk::DeviceMemoryReportEventTypeEXT::eImport);
    e_vk_DeviceMemoryReportEventTypeEXT.value("UNIMPORT", ::vk::DeviceMemoryReportEventTypeEXT::eUnimport);
    e_vk_DeviceMemoryReportEventTypeEXT.value("ALLOCATION_FAILED", ::vk::DeviceMemoryReportEventTypeEXT::eAllocationFailed);


    e_vk_VideoEncodeCapabilityFlagBitsKHR.value("PRECEDING_EXTERNALLY_ENCODED_BYTES", ::vk::VideoEncodeCapabilityFlagBitsKHR::ePrecedingExternallyEncodedBytes);
    e_vk_VideoEncodeCapabilityFlagBitsKHR.value("INSUFFICIENTSTREAM_BUFFER_RANGE_DETECTION_BIT", ::vk::VideoEncodeCapabilityFlagBitsKHR::eInsufficientstreamBufferRangeDetectionBit);

    e_vk_VideoEncodeContentFlagBitsKHR.value("DEFAULT", ::vk::VideoEncodeContentFlagBitsKHR::eDefault);
    e_vk_VideoEncodeContentFlagBitsKHR.value("CAMERA", ::vk::VideoEncodeContentFlagBitsKHR::eCamera);
    e_vk_VideoEncodeContentFlagBitsKHR.value("DESKTOP", ::vk::VideoEncodeContentFlagBitsKHR::eDesktop);
    e_vk_VideoEncodeContentFlagBitsKHR.value("RENDERED", ::vk::VideoEncodeContentFlagBitsKHR::eRendered);

    e_vk_VideoEncodeFeedbackFlagBitsKHR.value("estream_BUFFER_OFFSET_BIT", ::vk::VideoEncodeFeedbackFlagBitsKHR::estreamBufferOffsetBit);
    e_vk_VideoEncodeFeedbackFlagBitsKHR.value("estream_BYTES_WRITTEN_BIT", ::vk::VideoEncodeFeedbackFlagBitsKHR::estreamBytesWrittenBit);
    e_vk_VideoEncodeFeedbackFlagBitsKHR.value("estream_HAS_OVERRIDES_BIT", ::vk::VideoEncodeFeedbackFlagBitsKHR::estreamHasOverridesBit);



    e_vk_VideoEncodeRateControlModeFlagBitsKHR.value("DEFAULT", ::vk::VideoEncodeRateControlModeFlagBitsKHR::eDefault);
    e_vk_VideoEncodeRateControlModeFlagBitsKHR.value("DISABLED", ::vk::VideoEncodeRateControlModeFlagBitsKHR::eDisabled);
    e_vk_VideoEncodeRateControlModeFlagBitsKHR.value("CBR", ::vk::VideoEncodeRateControlModeFlagBitsKHR::eCbr);
    e_vk_VideoEncodeRateControlModeFlagBitsKHR.value("VBR", ::vk::VideoEncodeRateControlModeFlagBitsKHR::eVbr);

    e_vk_VideoEncodeTuningModeKHR.value("DEFAULT", ::vk::VideoEncodeTuningModeKHR::eDefault);
    e_vk_VideoEncodeTuningModeKHR.value("HIGH_QUALITY", ::vk::VideoEncodeTuningModeKHR::eHighQuality);
    e_vk_VideoEncodeTuningModeKHR.value("LOW_LATENCY", ::vk::VideoEncodeTuningModeKHR::eLowLatency);
    e_vk_VideoEncodeTuningModeKHR.value("ULTRA_LOW_LATENCY", ::vk::VideoEncodeTuningModeKHR::eUltraLowLatency);
    e_vk_VideoEncodeTuningModeKHR.value("LOSSLESS", ::vk::VideoEncodeTuningModeKHR::eLossless);

    e_vk_VideoEncodeUsageFlagBitsKHR.value("DEFAULT", ::vk::VideoEncodeUsageFlagBitsKHR::eDefault);
    e_vk_VideoEncodeUsageFlagBitsKHR.value("TRANSCODING", ::vk::VideoEncodeUsageFlagBitsKHR::eTranscoding);
    e_vk_VideoEncodeUsageFlagBitsKHR.value("STREAMING", ::vk::VideoEncodeUsageFlagBitsKHR::eStreaming);
    e_vk_VideoEncodeUsageFlagBitsKHR.value("RECORDING", ::vk::VideoEncodeUsageFlagBitsKHR::eRecording);
    e_vk_VideoEncodeUsageFlagBitsKHR.value("CONFERENCING", ::vk::VideoEncodeUsageFlagBitsKHR::eConferencing);

    e_vk_DeviceDiagnosticsConfigFlagBitsNV.value("ENABLE_SHADER_DEBUG_INFO", ::vk::DeviceDiagnosticsConfigFlagBitsNV::eEnableShaderDebugInfo);
    e_vk_DeviceDiagnosticsConfigFlagBitsNV.value("ENABLE_RESOURCE_TRACKING", ::vk::DeviceDiagnosticsConfigFlagBitsNV::eEnableResourceTracking);
    e_vk_DeviceDiagnosticsConfigFlagBitsNV.value("ENABLE_AUTOMATIC_CHECKPOINTS", ::vk::DeviceDiagnosticsConfigFlagBitsNV::eEnableAutomaticCheckpoints);
    e_vk_DeviceDiagnosticsConfigFlagBitsNV.value("ENABLE_SHADER_ERROR_REPORTING", ::vk::DeviceDiagnosticsConfigFlagBitsNV::eEnableShaderErrorReporting);

    e_vk_GraphicsPipelineLibraryFlagBitsEXT.value("VERTEX_INPUT_INTERFACE", ::vk::GraphicsPipelineLibraryFlagBitsEXT::eVertexInputInterface);
    e_vk_GraphicsPipelineLibraryFlagBitsEXT.value("PRE_RASTERIZATION_SHADERS", ::vk::GraphicsPipelineLibraryFlagBitsEXT::ePreRasterizationShaders);
    e_vk_GraphicsPipelineLibraryFlagBitsEXT.value("FRAGMENT_SHADER", ::vk::GraphicsPipelineLibraryFlagBitsEXT::eFragmentShader);
    e_vk_GraphicsPipelineLibraryFlagBitsEXT.value("FRAGMENT_OUTPUT_INTERFACE", ::vk::GraphicsPipelineLibraryFlagBitsEXT::eFragmentOutputInterface);

    e_vk_FragmentShadingRateNV.value("e1_INVOCATION_PER_PIXEL", ::vk::FragmentShadingRateNV::e1InvocationPerPixel);
    e_vk_FragmentShadingRateNV.value("e1_INVOCATION_PER_1X2_PIXELS", ::vk::FragmentShadingRateNV::e1InvocationPer1X2Pixels);
    e_vk_FragmentShadingRateNV.value("e1_INVOCATION_PER_2X1_PIXELS", ::vk::FragmentShadingRateNV::e1InvocationPer2X1Pixels);
    e_vk_FragmentShadingRateNV.value("e1_INVOCATION_PER_2X2_PIXELS", ::vk::FragmentShadingRateNV::e1InvocationPer2X2Pixels);
    e_vk_FragmentShadingRateNV.value("e1_INVOCATION_PER_2X4_PIXELS", ::vk::FragmentShadingRateNV::e1InvocationPer2X4Pixels);
    e_vk_FragmentShadingRateNV.value("e1_INVOCATION_PER_4X2_PIXELS", ::vk::FragmentShadingRateNV::e1InvocationPer4X2Pixels);
    e_vk_FragmentShadingRateNV.value("e1_INVOCATION_PER_4X4_PIXELS", ::vk::FragmentShadingRateNV::e1InvocationPer4X4Pixels);
    e_vk_FragmentShadingRateNV.value("e2_INVOCATIONS_PER_PIXEL", ::vk::FragmentShadingRateNV::e2InvocationsPerPixel);
    e_vk_FragmentShadingRateNV.value("e4_INVOCATIONS_PER_PIXEL", ::vk::FragmentShadingRateNV::e4InvocationsPerPixel);
    e_vk_FragmentShadingRateNV.value("e8_INVOCATIONS_PER_PIXEL", ::vk::FragmentShadingRateNV::e8InvocationsPerPixel);
    e_vk_FragmentShadingRateNV.value("e16_INVOCATIONS_PER_PIXEL", ::vk::FragmentShadingRateNV::e16InvocationsPerPixel);
    e_vk_FragmentShadingRateNV.value("NO_INVOCATIONS", ::vk::FragmentShadingRateNV::eNoInvocations);

    e_vk_FragmentShadingRateTypeNV.value("FRAGMENT_SIZE", ::vk::FragmentShadingRateTypeNV::eFragmentSize);
    e_vk_FragmentShadingRateTypeNV.value("ENUMS", ::vk::FragmentShadingRateTypeNV::eEnums);



    e_vk_AccelerationStructureMotionInstanceTypeNV.value("STATIC", ::vk::AccelerationStructureMotionInstanceTypeNV::eStatic);
    e_vk_AccelerationStructureMotionInstanceTypeNV.value("MATRIX_MOTION", ::vk::AccelerationStructureMotionInstanceTypeNV::eMatrixMotion);
    e_vk_AccelerationStructureMotionInstanceTypeNV.value("SRT_MOTION", ::vk::AccelerationStructureMotionInstanceTypeNV::eSrtMotion);

    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("NONE", ::vk::ImageCompressionFixedRateFlagBitsEXT::eNone);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e1_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e1Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e2_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e2Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e3_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e3Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e4_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e4Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e5_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e5Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e6_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e6Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e7_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e7Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e8_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e8Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e9_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e9Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e10_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e10Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e11_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e11Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e12_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e12Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e13_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e13Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e14_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e14Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e15_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e15Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e16_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e16Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e17_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e17Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e18_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e18Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e19_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e19Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e20_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e20Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e21_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e21Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e22_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e22Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e23_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e23Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("e24_BPC", ::vk::ImageCompressionFixedRateFlagBitsEXT::e24Bpc);

    e_vk_ImageCompressionFlagBitsEXT.value("DEFAULT", ::vk::ImageCompressionFlagBitsEXT::eDefault);
    e_vk_ImageCompressionFlagBitsEXT.value("FIXED_RATE_DEFAULT", ::vk::ImageCompressionFlagBitsEXT::eFixedRateDefault);
    e_vk_ImageCompressionFlagBitsEXT.value("FIXED_RATE_EXPLICIT", ::vk::ImageCompressionFlagBitsEXT::eFixedRateExplicit);
    e_vk_ImageCompressionFlagBitsEXT.value("DISABLED", ::vk::ImageCompressionFlagBitsEXT::eDisabled);

    e_vk_DeviceFaultAddressTypeEXT.value("NONE", ::vk::DeviceFaultAddressTypeEXT::eNone);
    e_vk_DeviceFaultAddressTypeEXT.value("READ_INVALID", ::vk::DeviceFaultAddressTypeEXT::eReadInvalid);
    e_vk_DeviceFaultAddressTypeEXT.value("WRITE_INVALID", ::vk::DeviceFaultAddressTypeEXT::eWriteInvalid);
    e_vk_DeviceFaultAddressTypeEXT.value("EXECUTE_INVALID", ::vk::DeviceFaultAddressTypeEXT::eExecuteInvalid);
    e_vk_DeviceFaultAddressTypeEXT.value("INSTRUCTION_POINTER_UNKNOWN", ::vk::DeviceFaultAddressTypeEXT::eInstructionPointerUnknown);
    e_vk_DeviceFaultAddressTypeEXT.value("INSTRUCTION_POINTER_INVALID", ::vk::DeviceFaultAddressTypeEXT::eInstructionPointerInvalid);
    e_vk_DeviceFaultAddressTypeEXT.value("INSTRUCTION_POINTER_FAULT", ::vk::DeviceFaultAddressTypeEXT::eInstructionPointerFault);

    e_vk_DeviceFaultVendorBinaryHeaderVersionEXT.value("ONE", ::vk::DeviceFaultVendorBinaryHeaderVersionEXT::eOne);

    e_vk_DeviceAddressBindingFlagBitsEXT.value("INTERNAL_OBJECT", ::vk::DeviceAddressBindingFlagBitsEXT::eInternalObject);

    e_vk_DeviceAddressBindingTypeEXT.value("BIND", ::vk::DeviceAddressBindingTypeEXT::eBind);
    e_vk_DeviceAddressBindingTypeEXT.value("UNBIND", ::vk::DeviceAddressBindingTypeEXT::eUnbind);

    e_vk_FrameBoundaryFlagBitsEXT.value("FRAME_END", ::vk::FrameBoundaryFlagBitsEXT::eFrameEnd);

    e_vk_BuildMicromapFlagBitsEXT.value("PREFER_FAST_TRACE", ::vk::BuildMicromapFlagBitsEXT::ePreferFastTrace);
    e_vk_BuildMicromapFlagBitsEXT.value("PREFER_FAST_BUILD", ::vk::BuildMicromapFlagBitsEXT::ePreferFastBuild);
    e_vk_BuildMicromapFlagBitsEXT.value("ALLOW_COMPACTION", ::vk::BuildMicromapFlagBitsEXT::eAllowCompaction);

    e_vk_BuildMicromapModeEXT.value("BUILD", ::vk::BuildMicromapModeEXT::eBuild);

    e_vk_CopyMicromapModeEXT.value("CLONE", ::vk::CopyMicromapModeEXT::eClone);
    e_vk_CopyMicromapModeEXT.value("SERIALIZE", ::vk::CopyMicromapModeEXT::eSerialize);
    e_vk_CopyMicromapModeEXT.value("DESERIALIZE", ::vk::CopyMicromapModeEXT::eDeserialize);
    e_vk_CopyMicromapModeEXT.value("COMPACT", ::vk::CopyMicromapModeEXT::eCompact);

    e_vk_MicromapCreateFlagBitsEXT.value("DEVICE_ADDRESS_CAPTURE_REPLAY", ::vk::MicromapCreateFlagBitsEXT::eDeviceAddressCaptureReplay);

    e_vk_MicromapTypeEXT.value("OPACITY_MICROMAP", ::vk::MicromapTypeEXT::eOpacityMicromap);

    e_vk_OpacityMicromapFormatEXT.value("e2_STATE", ::vk::OpacityMicromapFormatEXT::e2State);
    e_vk_OpacityMicromapFormatEXT.value("e4_STATE", ::vk::OpacityMicromapFormatEXT::e4State);

    e_vk_OpacityMicromapSpecialIndexEXT.value("FULLY_TRANSPARENT", ::vk::OpacityMicromapSpecialIndexEXT::eFullyTransparent);
    e_vk_OpacityMicromapSpecialIndexEXT.value("FULLY_OPAQUE", ::vk::OpacityMicromapSpecialIndexEXT::eFullyOpaque);
    e_vk_OpacityMicromapSpecialIndexEXT.value("FULLY_UNKNOWN_TRANSPARENT", ::vk::OpacityMicromapSpecialIndexEXT::eFullyUnknownTransparent);
    e_vk_OpacityMicromapSpecialIndexEXT.value("FULLY_UNKNOWN_OPAQUE", ::vk::OpacityMicromapSpecialIndexEXT::eFullyUnknownOpaque);

    e_vk_PhysicalDeviceSchedulingControlsFlagBitsARM.value("SHADER_CORE_COUNT", ::vk::PhysicalDeviceSchedulingControlsFlagBitsARM::eShaderCoreCount);

    e_vk_MemoryDecompressionMethodFlagBitsNV.value("GDEFLATE_10", ::vk::MemoryDecompressionMethodFlagBitsNV::eGdeflate10);

    e_vk_SubpassMergeStatusEXT.value("MERGED", ::vk::SubpassMergeStatusEXT::eMerged);
    e_vk_SubpassMergeStatusEXT.value("DISALLOWED", ::vk::SubpassMergeStatusEXT::eDisallowed);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_SIDE_EFFECTS", ::vk::SubpassMergeStatusEXT::eNotMergedSideEffects);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_SAMPLES_MISMATCH", ::vk::SubpassMergeStatusEXT::eNotMergedSamplesMismatch);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_VIEWS_MISMATCH", ::vk::SubpassMergeStatusEXT::eNotMergedViewsMismatch);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_ALIASING", ::vk::SubpassMergeStatusEXT::eNotMergedAliasing);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_DEPENDENCIES", ::vk::SubpassMergeStatusEXT::eNotMergedDependencies);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT", ::vk::SubpassMergeStatusEXT::eNotMergedIncompatibleInputAttachment);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_TOO_MANY_ATTACHMENTS", ::vk::SubpassMergeStatusEXT::eNotMergedTooManyAttachments);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_INSUFFICIENT_STORAGE", ::vk::SubpassMergeStatusEXT::eNotMergedInsufficientStorage);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_DEPTH_STENCIL_COUNT", ::vk::SubpassMergeStatusEXT::eNotMergedDepthStencilCount);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_RESOLVE_ATTACHMENT_REUSE", ::vk::SubpassMergeStatusEXT::eNotMergedResolveAttachmentReuse);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_SINGLE_SUBPASS", ::vk::SubpassMergeStatusEXT::eNotMergedSingleSubpass);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_UNSPECIFIED", ::vk::SubpassMergeStatusEXT::eNotMergedUnspecified);


    e_vk_DirectDriverLoadingModeLUNARG.value("EXCLUSIVE", ::vk::DirectDriverLoadingModeLUNARG::eExclusive);
    e_vk_DirectDriverLoadingModeLUNARG.value("INCLUSIVE", ::vk::DirectDriverLoadingModeLUNARG::eInclusive);

    e_vk_OpticalFlowExecuteFlagBitsNV.value("DISABLE_TEMPORAL_HINTS", ::vk::OpticalFlowExecuteFlagBitsNV::eDisableTemporalHints);

    e_vk_OpticalFlowGridSizeFlagBitsNV.value("UNKNOWN", ::vk::OpticalFlowGridSizeFlagBitsNV::eUnknown);
    e_vk_OpticalFlowGridSizeFlagBitsNV.value("e1X1", ::vk::OpticalFlowGridSizeFlagBitsNV::e1X1);
    e_vk_OpticalFlowGridSizeFlagBitsNV.value("e2X2", ::vk::OpticalFlowGridSizeFlagBitsNV::e2X2);
    e_vk_OpticalFlowGridSizeFlagBitsNV.value("e4X4", ::vk::OpticalFlowGridSizeFlagBitsNV::e4X4);
    e_vk_OpticalFlowGridSizeFlagBitsNV.value("e8X8", ::vk::OpticalFlowGridSizeFlagBitsNV::e8X8);

    e_vk_OpticalFlowPerformanceLevelNV.value("UNKNOWN", ::vk::OpticalFlowPerformanceLevelNV::eUnknown);
    e_vk_OpticalFlowPerformanceLevelNV.value("SLOW", ::vk::OpticalFlowPerformanceLevelNV::eSlow);
    e_vk_OpticalFlowPerformanceLevelNV.value("MEDIUM", ::vk::OpticalFlowPerformanceLevelNV::eMedium);
    e_vk_OpticalFlowPerformanceLevelNV.value("FAST", ::vk::OpticalFlowPerformanceLevelNV::eFast);

    e_vk_OpticalFlowSessionBindingPointNV.value("UNKNOWN", ::vk::OpticalFlowSessionBindingPointNV::eUnknown);
    e_vk_OpticalFlowSessionBindingPointNV.value("INPUT", ::vk::OpticalFlowSessionBindingPointNV::eInput);
    e_vk_OpticalFlowSessionBindingPointNV.value("REFERENCE", ::vk::OpticalFlowSessionBindingPointNV::eReference);
    e_vk_OpticalFlowSessionBindingPointNV.value("HINT", ::vk::OpticalFlowSessionBindingPointNV::eHint);
    e_vk_OpticalFlowSessionBindingPointNV.value("FLOW_VECTOR", ::vk::OpticalFlowSessionBindingPointNV::eFlowVector);
    e_vk_OpticalFlowSessionBindingPointNV.value("BACKWARD_FLOW_VECTOR", ::vk::OpticalFlowSessionBindingPointNV::eBackwardFlowVector);
    e_vk_OpticalFlowSessionBindingPointNV.value("COST", ::vk::OpticalFlowSessionBindingPointNV::eCost);
    e_vk_OpticalFlowSessionBindingPointNV.value("BACKWARD_COST", ::vk::OpticalFlowSessionBindingPointNV::eBackwardCost);
    e_vk_OpticalFlowSessionBindingPointNV.value("GLOBAL_FLOW", ::vk::OpticalFlowSessionBindingPointNV::eGlobalFlow);

    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("ENABLE_HINT", ::vk::OpticalFlowSessionCreateFlagBitsNV::eEnableHint);
    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("ENABLE_COST", ::vk::OpticalFlowSessionCreateFlagBitsNV::eEnableCost);
    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("ENABLE_GLOBAL_FLOW", ::vk::OpticalFlowSessionCreateFlagBitsNV::eEnableGlobalFlow);
    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("ALLOW_REGIONS", ::vk::OpticalFlowSessionCreateFlagBitsNV::eAllowRegions);
    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("BOTH_DIRECTIONS", ::vk::OpticalFlowSessionCreateFlagBitsNV::eBothDirections);

    e_vk_OpticalFlowUsageFlagBitsNV.value("UNKNOWN", ::vk::OpticalFlowUsageFlagBitsNV::eUnknown);
    e_vk_OpticalFlowUsageFlagBitsNV.value("INPUT", ::vk::OpticalFlowUsageFlagBitsNV::eInput);
    e_vk_OpticalFlowUsageFlagBitsNV.value("OUTPUT", ::vk::OpticalFlowUsageFlagBitsNV::eOutput);
    e_vk_OpticalFlowUsageFlagBitsNV.value("HINT", ::vk::OpticalFlowUsageFlagBitsNV::eHint);
    e_vk_OpticalFlowUsageFlagBitsNV.value("COST", ::vk::OpticalFlowUsageFlagBitsNV::eCost);
    e_vk_OpticalFlowUsageFlagBitsNV.value("GLOBAL_FLOW", ::vk::OpticalFlowUsageFlagBitsNV::eGlobalFlow);

    e_vk_BufferUsageFlagBits2KHR.value("TRANSFER_SRC", ::vk::BufferUsageFlagBits2KHR::eTransferSrc);
    e_vk_BufferUsageFlagBits2KHR.value("TRANSFER_DST", ::vk::BufferUsageFlagBits2KHR::eTransferDst);
    e_vk_BufferUsageFlagBits2KHR.value("UNIFORM_TEXEL_BUFFER", ::vk::BufferUsageFlagBits2KHR::eUniformTexelBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("STORAGE_TEXEL_BUFFER", ::vk::BufferUsageFlagBits2KHR::eStorageTexelBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("UNIFORM_BUFFER", ::vk::BufferUsageFlagBits2KHR::eUniformBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("STORAGE_BUFFER", ::vk::BufferUsageFlagBits2KHR::eStorageBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("INDEX_BUFFER", ::vk::BufferUsageFlagBits2KHR::eIndexBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("VERTEX_BUFFER", ::vk::BufferUsageFlagBits2KHR::eVertexBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("INDIRECT_BUFFER", ::vk::BufferUsageFlagBits2KHR::eIndirectBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("CONDITIONAL_RENDERING_EXT", ::vk::BufferUsageFlagBits2KHR::eConditionalRenderingEXT);
    e_vk_BufferUsageFlagBits2KHR.value("SHADER_BINDING_TABLE", ::vk::BufferUsageFlagBits2KHR::eShaderBindingTable);
    e_vk_BufferUsageFlagBits2KHR.value("RAY_TRACING_NV", ::vk::BufferUsageFlagBits2KHR::eRayTracingNV);
    e_vk_BufferUsageFlagBits2KHR.value("TRANSFORM_FEEDBACK_BUFFER_EXT", ::vk::BufferUsageFlagBits2KHR::eTransformFeedbackBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("TRANSFORM_FEEDBACK_COUNTER_BUFFER_EXT", ::vk::BufferUsageFlagBits2KHR::eTransformFeedbackCounterBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("VIDEO_DECODE_SRC", ::vk::BufferUsageFlagBits2KHR::eVideoDecodeSrc);
    e_vk_BufferUsageFlagBits2KHR.value("VIDEO_DECODE_DST", ::vk::BufferUsageFlagBits2KHR::eVideoDecodeDst);
    e_vk_BufferUsageFlagBits2KHR.value("SHADER_DEVICE_ADDRESS", ::vk::BufferUsageFlagBits2KHR::eShaderDeviceAddress);
    e_vk_BufferUsageFlagBits2KHR.value("ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY", ::vk::BufferUsageFlagBits2KHR::eAccelerationStructureBuildInputReadOnly);
    e_vk_BufferUsageFlagBits2KHR.value("ACCELERATION_STRUCTURE_STORAGE", ::vk::BufferUsageFlagBits2KHR::eAccelerationStructureStorage);
    e_vk_BufferUsageFlagBits2KHR.value("SAMPLER_DESCRIPTOR_BUFFER_EXT", ::vk::BufferUsageFlagBits2KHR::eSamplerDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("RESOURCE_DESCRIPTOR_BUFFER_EXT", ::vk::BufferUsageFlagBits2KHR::eResourceDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_EXT", ::vk::BufferUsageFlagBits2KHR::ePushDescriptorsDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("MICROMAP_BUILD_INPUT_READ_ONLY_EXT", ::vk::BufferUsageFlagBits2KHR::eMicromapBuildInputReadOnlyEXT);
    e_vk_BufferUsageFlagBits2KHR.value("MICROMAP_STORAGE_EXT", ::vk::BufferUsageFlagBits2KHR::eMicromapStorageEXT);

    e_vk_PipelineCreateFlagBits2KHR.value("DISABLE_OPTIMIZATION", ::vk::PipelineCreateFlagBits2KHR::eDisableOptimization);
    e_vk_PipelineCreateFlagBits2KHR.value("ALLOW_DERIVATIVES", ::vk::PipelineCreateFlagBits2KHR::eAllowDerivatives);
    e_vk_PipelineCreateFlagBits2KHR.value("DERIVATIVE", ::vk::PipelineCreateFlagBits2KHR::eDerivative);
    e_vk_PipelineCreateFlagBits2KHR.value("VIEW_INDEX_FROM_DEVICE_INDEX", ::vk::PipelineCreateFlagBits2KHR::eViewIndexFromDeviceIndex);
    e_vk_PipelineCreateFlagBits2KHR.value("DISPATCH_BASE", ::vk::PipelineCreateFlagBits2KHR::eDispatchBase);
    e_vk_PipelineCreateFlagBits2KHR.value("DEFER_COMPILE_NV", ::vk::PipelineCreateFlagBits2KHR::eDeferCompileNV);
    e_vk_PipelineCreateFlagBits2KHR.value("CAPTURE_STATISTICS", ::vk::PipelineCreateFlagBits2KHR::eCaptureStatistics);
    e_vk_PipelineCreateFlagBits2KHR.value("CAPTURE_INTERNAL_REPRESENTATIONS", ::vk::PipelineCreateFlagBits2KHR::eCaptureInternalRepresentations);
    e_vk_PipelineCreateFlagBits2KHR.value("FAIL_ON_PIPELINE_COMPILE_REQUIRED", ::vk::PipelineCreateFlagBits2KHR::eFailOnPipelineCompileRequired);
    e_vk_PipelineCreateFlagBits2KHR.value("EARLY_RETURN_ON_FAILURE", ::vk::PipelineCreateFlagBits2KHR::eEarlyReturnOnFailure);
    e_vk_PipelineCreateFlagBits2KHR.value("LINK_TIME_OPTIMIZATION_EXT", ::vk::PipelineCreateFlagBits2KHR::eLinkTimeOptimizationEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("RETAIN_LINK_TIME_OPTIMIZATION_INFO_EXT", ::vk::PipelineCreateFlagBits2KHR::eRetainLinkTimeOptimizationInfoEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("LIBRARY", ::vk::PipelineCreateFlagBits2KHR::eLibrary);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_SKIP_TRIANGLES", ::vk::PipelineCreateFlagBits2KHR::eRayTracingSkipTriangles);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_SKIP_AABBS", ::vk::PipelineCreateFlagBits2KHR::eRayTracingSkipAabbs);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_NO_NULL_ANY_HIT_SHADERS", ::vk::PipelineCreateFlagBits2KHR::eRayTracingNoNullAnyHitShaders);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS", ::vk::PipelineCreateFlagBits2KHR::eRayTracingNoNullClosestHitShaders);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_NO_NULL_MISS_SHADERS", ::vk::PipelineCreateFlagBits2KHR::eRayTracingNoNullMissShaders);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_NO_NULL_INTERSECTION_SHADERS", ::vk::PipelineCreateFlagBits2KHR::eRayTracingNoNullIntersectionShaders);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY", ::vk::PipelineCreateFlagBits2KHR::eRayTracingShaderGroupHandleCaptureReplay);
    e_vk_PipelineCreateFlagBits2KHR.value("INDIRECT_BINDABLE_NV", ::vk::PipelineCreateFlagBits2KHR::eIndirectBindableNV);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_ALLOW_MOTION_NV", ::vk::PipelineCreateFlagBits2KHR::eRayTracingAllowMotionNV);
    e_vk_PipelineCreateFlagBits2KHR.value("RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT", ::vk::PipelineCreateFlagBits2KHR::eRenderingFragmentShadingRateAttachment);
    e_vk_PipelineCreateFlagBits2KHR.value("RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_EXT", ::vk::PipelineCreateFlagBits2KHR::eRenderingFragmentDensityMapAttachmentEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_OPACITY_MICROMAP_EXT", ::vk::PipelineCreateFlagBits2KHR::eRayTracingOpacityMicromapEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("COLOR_ATTACHMENT_FEEDBACK_LOOP_EXT", ::vk::PipelineCreateFlagBits2KHR::eColorAttachmentFeedbackLoopEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_EXT", ::vk::PipelineCreateFlagBits2KHR::eDepthStencilAttachmentFeedbackLoopEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("NO_PROTECTED_ACCESS_EXT", ::vk::PipelineCreateFlagBits2KHR::eNoProtectedAccessEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("PROTECTED_ACCESS_ONLY_EXT", ::vk::PipelineCreateFlagBits2KHR::eProtectedAccessOnlyEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_DISPLACEMENT_MICROMAP_NV", ::vk::PipelineCreateFlagBits2KHR::eRayTracingDisplacementMicromapNV);
    e_vk_PipelineCreateFlagBits2KHR.value("DESCRIPTOR_BUFFER_EXT", ::vk::PipelineCreateFlagBits2KHR::eDescriptorBufferEXT);

    e_vk_ShaderCodeTypeEXT.value("BINARY", ::vk::ShaderCodeTypeEXT::eBinary);
    e_vk_ShaderCodeTypeEXT.value("SPIRV", ::vk::ShaderCodeTypeEXT::eSpirv);

    e_vk_ShaderCreateFlagBitsEXT.value("LINK_STAGE", ::vk::ShaderCreateFlagBitsEXT::eLinkStage);
    e_vk_ShaderCreateFlagBitsEXT.value("ALLOW_VARYING_SUBGROUP_SIZE", ::vk::ShaderCreateFlagBitsEXT::eAllowVaryingSubgroupSize);
    e_vk_ShaderCreateFlagBitsEXT.value("REQUIRE_FULL_SUBGROUPS", ::vk::ShaderCreateFlagBitsEXT::eRequireFullSubgroups);
    e_vk_ShaderCreateFlagBitsEXT.value("NO_TASK_SHADER", ::vk::ShaderCreateFlagBitsEXT::eNoTaskShader);
    e_vk_ShaderCreateFlagBitsEXT.value("DISPATCH_BASE", ::vk::ShaderCreateFlagBitsEXT::eDispatchBase);
    e_vk_ShaderCreateFlagBitsEXT.value("FRAGMENT_SHADING_RATE_ATTACHMENT", ::vk::ShaderCreateFlagBitsEXT::eFragmentShadingRateAttachment);
    e_vk_ShaderCreateFlagBitsEXT.value("FRAGMENT_DENSITY_MAP_ATTACHMENT", ::vk::ShaderCreateFlagBitsEXT::eFragmentDensityMapAttachment);

    e_vk_RayTracingInvocationReorderModeNV.value("NONE", ::vk::RayTracingInvocationReorderModeNV::eNone);
    e_vk_RayTracingInvocationReorderModeNV.value("REORDER", ::vk::RayTracingInvocationReorderModeNV::eReorder);

    e_vk_LayerSettingTypeEXT.value("BOOL_32", ::vk::LayerSettingTypeEXT::eBool32);
    e_vk_LayerSettingTypeEXT.value("INT_32", ::vk::LayerSettingTypeEXT::eInt32);
    e_vk_LayerSettingTypeEXT.value("INT_64", ::vk::LayerSettingTypeEXT::eInt64);
    e_vk_LayerSettingTypeEXT.value("UINT_32", ::vk::LayerSettingTypeEXT::eUint32);
    e_vk_LayerSettingTypeEXT.value("UINT_64", ::vk::LayerSettingTypeEXT::eUint64);
    e_vk_LayerSettingTypeEXT.value("FLOAT_32", ::vk::LayerSettingTypeEXT::eFloat32);
    e_vk_LayerSettingTypeEXT.value("FLOAT_64", ::vk::LayerSettingTypeEXT::eFloat64);
    e_vk_LayerSettingTypeEXT.value("STRING", ::vk::LayerSettingTypeEXT::eString);

    e_vk_LatencyMarkerNV.value("SIMULATION_START", ::vk::LatencyMarkerNV::eSimulationStart);
    e_vk_LatencyMarkerNV.value("SIMULATION_END", ::vk::LatencyMarkerNV::eSimulationEnd);
    e_vk_LatencyMarkerNV.value("RENDERSUBMIT_START", ::vk::LatencyMarkerNV::eRendersubmitStart);
    e_vk_LatencyMarkerNV.value("RENDERSUBMIT_END", ::vk::LatencyMarkerNV::eRendersubmitEnd);
    e_vk_LatencyMarkerNV.value("PRESENT_START", ::vk::LatencyMarkerNV::ePresentStart);
    e_vk_LatencyMarkerNV.value("PRESENT_END", ::vk::LatencyMarkerNV::ePresentEnd);
    e_vk_LatencyMarkerNV.value("INPUT_SAMPLE", ::vk::LatencyMarkerNV::eInputSample);
    e_vk_LatencyMarkerNV.value("TRIGGER_FLASH", ::vk::LatencyMarkerNV::eTriggerFlash);
    e_vk_LatencyMarkerNV.value("OUT_OF_BAND_RENDERSUBMIT_START", ::vk::LatencyMarkerNV::eOutOfBandRendersubmitStart);
    e_vk_LatencyMarkerNV.value("OUT_OF_BAND_RENDERSUBMIT_END", ::vk::LatencyMarkerNV::eOutOfBandRendersubmitEnd);
    e_vk_LatencyMarkerNV.value("OUT_OF_BAND_PRESENT_START", ::vk::LatencyMarkerNV::eOutOfBandPresentStart);
    e_vk_LatencyMarkerNV.value("OUT_OF_BAND_PRESENT_END", ::vk::LatencyMarkerNV::eOutOfBandPresentEnd);

    e_vk_OutOfBandQueueTypeNV.value("RENDER", ::vk::OutOfBandQueueTypeNV::eRender);
    e_vk_OutOfBandQueueTypeNV.value("PRESENT", ::vk::OutOfBandQueueTypeNV::ePresent);

    e_vk_ComponentTypeKHR.value("FLOAT_16", ::vk::ComponentTypeKHR::eFloat16);
    e_vk_ComponentTypeKHR.value("FLOAT_32", ::vk::ComponentTypeKHR::eFloat32);
    e_vk_ComponentTypeKHR.value("FLOAT_64", ::vk::ComponentTypeKHR::eFloat64);
    e_vk_ComponentTypeKHR.value("SINT_8", ::vk::ComponentTypeKHR::eSint8);
    e_vk_ComponentTypeKHR.value("SINT_16", ::vk::ComponentTypeKHR::eSint16);
    e_vk_ComponentTypeKHR.value("SINT_32", ::vk::ComponentTypeKHR::eSint32);
    e_vk_ComponentTypeKHR.value("SINT_64", ::vk::ComponentTypeKHR::eSint64);
    e_vk_ComponentTypeKHR.value("UINT_8", ::vk::ComponentTypeKHR::eUint8);
    e_vk_ComponentTypeKHR.value("UINT_16", ::vk::ComponentTypeKHR::eUint16);
    e_vk_ComponentTypeKHR.value("UINT_32", ::vk::ComponentTypeKHR::eUint32);
    e_vk_ComponentTypeKHR.value("UINT_64", ::vk::ComponentTypeKHR::eUint64);

    e_vk_ScopeKHR.value("DEVICE", ::vk::ScopeKHR::eDevice);
    e_vk_ScopeKHR.value("WORKGROUP", ::vk::ScopeKHR::eWorkgroup);
    e_vk_ScopeKHR.value("SUBGROUP", ::vk::ScopeKHR::eSubgroup);
    e_vk_ScopeKHR.value("QUEUE_FAMILY", ::vk::ScopeKHR::eQueueFamily);

    e_vk_BlockMatchWindowCompareModeQCOM.value("MIN", ::vk::BlockMatchWindowCompareModeQCOM::eMin);
    e_vk_BlockMatchWindowCompareModeQCOM.value("MAX", ::vk::BlockMatchWindowCompareModeQCOM::eMax);

    e_vk_CubicFilterWeightsQCOM.value("CATMULL_ROM", ::vk::CubicFilterWeightsQCOM::eCatmullRom);
    e_vk_CubicFilterWeightsQCOM.value("ZERO_TANGENT_CARDINAL", ::vk::CubicFilterWeightsQCOM::eZeroTangentCardinal);
    e_vk_CubicFilterWeightsQCOM.value("eB_SPLINE", ::vk::CubicFilterWeightsQCOM::eBSpline);
    e_vk_CubicFilterWeightsQCOM.value("MITCHELL_NETRAVALI", ::vk::CubicFilterWeightsQCOM::eMitchellNetravali);

    e_vk_LayeredDriverUnderlyingApiMSFT.value("NONE", ::vk::LayeredDriverUnderlyingApiMSFT::eNone);
    e_vk_LayeredDriverUnderlyingApiMSFT.value("eD3D12", ::vk::LayeredDriverUnderlyingApiMSFT::eD3D12);

    e_vk_TimeDomainKHR.value("DEVICE", ::vk::TimeDomainKHR::eDevice);
    e_vk_TimeDomainKHR.value("CLOCK_MONOTONIC", ::vk::TimeDomainKHR::eClockMonotonic);
    e_vk_TimeDomainKHR.value("CLOCK_MONOTONIC_RAW", ::vk::TimeDomainKHR::eClockMonotonicRaw);
    e_vk_TimeDomainKHR.value("QUERY_PERFORMANCE_COUNTER", ::vk::TimeDomainKHR::eQueryPerformanceCounter);

    s_vk_AllocationCallbacks.def(py::init<void *, PFN_vkAllocationFunction, PFN_vkReallocationFunction, PFN_vkFreeFunction, PFN_vkInternalAllocationNotification, PFN_vkInternalFreeNotification>(), py::arg("p_user_data") = nullptr, py::arg("pfn_allocation") = PFN_vkAllocationFunction{}, py::arg("pfn_reallocation") = PFN_vkReallocationFunction{}, py::arg("pfn_free") = PFN_vkFreeFunction{}, py::arg("pfn_internal_allocation") = PFN_vkInternalAllocationNotification{}, py::arg("pfn_internal_free") = PFN_vkInternalFreeNotification{});

    s_vk_ApplicationInfo.def(py::init<const char *, uint32_t, const char *, uint32_t, uint32_t, const void *>(), py::arg("p_application_name") = nullptr, py::arg("application_version") = uint32_t{}, py::arg("p_engine_name") = nullptr, py::arg("engine_version") = uint32_t{}, py::arg("api_version") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_AttachmentDescription.def(py::init<vk::AttachmentDescriptionFlags, vk::Format, vk::SampleCountFlagBits, vk::AttachmentLoadOp, vk::AttachmentStoreOp, vk::AttachmentLoadOp, vk::AttachmentStoreOp, vk::ImageLayout, vk::ImageLayout>(), py::arg("flags") = vk::AttachmentDescriptionFlags{}, py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("samples") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("load_op") = VULKAN_HPP_NAMESPACE::AttachmentLoadOp::eLoad, py::arg("store_op") = VULKAN_HPP_NAMESPACE::AttachmentStoreOp::eStore, py::arg("stencil_load_op") = VULKAN_HPP_NAMESPACE::AttachmentLoadOp::eLoad, py::arg("stencil_store_op") = VULKAN_HPP_NAMESPACE::AttachmentStoreOp::eStore, py::arg("initial_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("final_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined);

    s_vk_AttachmentReference.def(py::init<uint32_t, vk::ImageLayout>(), py::arg("attachment") = uint32_t{}, py::arg("layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined);

    s_vk_BaseInStructure.def(py::init<vk::StructureType, const struct vk::BaseInStructure *>(), py::arg("s_type") = VULKAN_HPP_NAMESPACE::StructureType::eApplicationInfo, py::arg("p_next") = nullptr);

    s_vk_BaseOutStructure.def(py::init<vk::StructureType, struct vk::BaseOutStructure *>(), py::arg("s_type") = VULKAN_HPP_NAMESPACE::StructureType::eApplicationInfo, py::arg("p_next") = nullptr);

    s_vk_BindSparseInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Semaphore> &, const vk::ArrayProxyNoTemporaries<const vk::SparseBufferMemoryBindInfo> &, const vk::ArrayProxyNoTemporaries<const vk::SparseImageOpaqueMemoryBindInfo> &, const vk::ArrayProxyNoTemporaries<const vk::SparseImageMemoryBindInfo> &, const vk::ArrayProxyNoTemporaries<const vk::Semaphore> &, const void *>(), py::arg("wait_semaphores"), py::arg("buffer_binds") = vk::ArrayProxyNoTemporaries<const vk::SparseBufferMemoryBindInfo>{}, py::arg("image_opaque_binds") = vk::ArrayProxyNoTemporaries<const vk::SparseImageOpaqueMemoryBindInfo>{}, py::arg("image_binds") = vk::ArrayProxyNoTemporaries<const vk::SparseImageMemoryBindInfo>{}, py::arg("signal_semaphores") = vk::ArrayProxyNoTemporaries<const vk::Semaphore>{}, py::arg("p_next") = nullptr);

    s_vk_BufferCopy.def(py::init<vk::DeviceSize, vk::DeviceSize, vk::DeviceSize>(), py::arg("src_offset") = vk::DeviceSize{}, py::arg("dst_offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{});

    s_vk_BufferCreateInfo.def(py::init<vk::BufferCreateFlags, vk::DeviceSize, vk::BufferUsageFlags, vk::SharingMode, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("flags"), py::arg("size"), py::arg("usage"), py::arg("sharing_mode"), py::arg("queue_family_indices"), py::arg("p_next") = nullptr);

    s_vk_BufferImageCopy.def(py::init<vk::DeviceSize, uint32_t, uint32_t, vk::ImageSubresourceLayers, vk::Offset3D, vk::Extent3D>(), py::arg("buffer_offset") = vk::DeviceSize{}, py::arg("buffer_row_length") = uint32_t{}, py::arg("buffer_image_height") = uint32_t{}, py::arg("image_subresource") = vk::ImageSubresourceLayers{}, py::arg("image_offset") = vk::Offset3D{}, py::arg("image_extent") = vk::Extent3D{});

    s_vk_BufferMemoryBarrier.def(py::init<vk::AccessFlags, vk::AccessFlags, uint32_t, uint32_t, vk::Buffer, vk::DeviceSize, vk::DeviceSize, const void *>(), py::arg("src_access_mask") = vk::AccessFlags{}, py::arg("dst_access_mask") = vk::AccessFlags{}, py::arg("src_queue_family_index") = uint32_t{}, py::arg("dst_queue_family_index") = uint32_t{}, py::arg("buffer") = vk::Buffer{}, py::arg("offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_BufferViewCreateInfo.def(py::init<vk::BufferViewCreateFlags, vk::Buffer, vk::Format, vk::DeviceSize, vk::DeviceSize, const void *>(), py::arg("flags") = vk::BufferViewCreateFlags{}, py::arg("buffer") = vk::Buffer{}, py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("offset") = vk::DeviceSize{}, py::arg("range") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_ClearAttachment.def(py::init<vk::ImageAspectFlags, uint32_t, vk::ClearValue>(), py::arg("aspect_mask") = vk::ImageAspectFlags{}, py::arg("color_attachment") = uint32_t{}, py::arg("clear_value") = vk::ClearValue{});

    s_vk_ClearDepthStencilValue.def(py::init<float, uint32_t>(), py::arg("depth") = float{}, py::arg("stencil") = uint32_t{});

    s_vk_ClearRect.def(py::init<vk::Rect2D, uint32_t, uint32_t>(), py::arg("rect") = vk::Rect2D{}, py::arg("base_array_layer") = uint32_t{}, py::arg("layer_count") = uint32_t{});

    s_vk_CommandBufferAllocateInfo.def(py::init<vk::CommandPool, vk::CommandBufferLevel, uint32_t, const void *>(), py::arg("command_pool") = vk::CommandPool{}, py::arg("level") = VULKAN_HPP_NAMESPACE::CommandBufferLevel::ePrimary, py::arg("command_buffer_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_CommandBufferBeginInfo.def(py::init<vk::CommandBufferUsageFlags, const vk::CommandBufferInheritanceInfo *, const void *>(), py::arg("flags") = vk::CommandBufferUsageFlags{}, py::arg("p_inheritance_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_CommandBufferInheritanceInfo.def(py::init<vk::RenderPass, uint32_t, vk::Framebuffer, vk::Bool32, vk::QueryControlFlags, vk::QueryPipelineStatisticFlags, const void *>(), py::arg("render_pass") = vk::RenderPass{}, py::arg("subpass") = uint32_t{}, py::arg("framebuffer") = vk::Framebuffer{}, py::arg("occlusion_query_enable") = vk::Bool32{}, py::arg("query_flags") = vk::QueryControlFlags{}, py::arg("pipeline_statistics") = vk::QueryPipelineStatisticFlags{}, py::arg("p_next") = nullptr);

    s_vk_CommandPoolCreateInfo.def(py::init<vk::CommandPoolCreateFlags, uint32_t, const void *>(), py::arg("flags") = vk::CommandPoolCreateFlags{}, py::arg("queue_family_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_ComponentMapping.def(py::init<vk::ComponentSwizzle, vk::ComponentSwizzle, vk::ComponentSwizzle, vk::ComponentSwizzle>(), py::arg("r") = VULKAN_HPP_NAMESPACE::ComponentSwizzle::eIdentity, py::arg("g") = VULKAN_HPP_NAMESPACE::ComponentSwizzle::eIdentity, py::arg("b") = VULKAN_HPP_NAMESPACE::ComponentSwizzle::eIdentity, py::arg("a") = VULKAN_HPP_NAMESPACE::ComponentSwizzle::eIdentity);

    s_vk_ComputePipelineCreateInfo.def(py::init<vk::PipelineCreateFlags, vk::PipelineShaderStageCreateInfo, vk::PipelineLayout, vk::Pipeline, int32_t, const void *>(), py::arg("flags") = vk::PipelineCreateFlags{}, py::arg("stage") = vk::PipelineShaderStageCreateInfo{}, py::arg("layout") = vk::PipelineLayout{}, py::arg("base_pipeline_handle") = vk::Pipeline{}, py::arg("base_pipeline_index") = int32_t{}, py::arg("p_next") = nullptr);

    s_vk_CopyDescriptorSet.def(py::init<vk::DescriptorSet, uint32_t, uint32_t, vk::DescriptorSet, uint32_t, uint32_t, uint32_t, const void *>(), py::arg("src_set") = vk::DescriptorSet{}, py::arg("src_binding") = uint32_t{}, py::arg("src_array_element") = uint32_t{}, py::arg("dst_set") = vk::DescriptorSet{}, py::arg("dst_binding") = uint32_t{}, py::arg("dst_array_element") = uint32_t{}, py::arg("descriptor_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorBufferInfo.def(py::init<vk::Buffer, vk::DeviceSize, vk::DeviceSize>(), py::arg("buffer") = vk::Buffer{}, py::arg("offset") = vk::DeviceSize{}, py::arg("range") = vk::DeviceSize{});

    s_vk_DescriptorImageInfo.def(py::init<vk::Sampler, vk::ImageView, vk::ImageLayout>(), py::arg("sampler") = vk::Sampler{}, py::arg("image_view") = vk::ImageView{}, py::arg("image_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined);

    s_vk_DescriptorPoolCreateInfo.def(py::init<vk::DescriptorPoolCreateFlags, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::DescriptorPoolSize> &, const void *>(), py::arg("flags"), py::arg("max_sets"), py::arg("pool_sizes"), py::arg("p_next") = nullptr);

    s_vk_DescriptorPoolSize.def(py::init<vk::DescriptorType, uint32_t>(), py::arg("type") = VULKAN_HPP_NAMESPACE::DescriptorType::eSampler, py::arg("descriptor_count") = uint32_t{});

    s_vk_DescriptorSetAllocateInfo.def(py::init<vk::DescriptorPool, const vk::ArrayProxyNoTemporaries<const vk::DescriptorSetLayout> &, const void *>(), py::arg("descriptor_pool"), py::arg("set_layouts"), py::arg("p_next") = nullptr);

    s_vk_DescriptorSetLayoutBinding.def(py::init<uint32_t, vk::DescriptorType, vk::ShaderStageFlags, const vk::ArrayProxyNoTemporaries<const vk::Sampler> &>(), py::arg("binding"), py::arg("descriptor_type"), py::arg("stage_flags"), py::arg("immutable_samplers"));

    s_vk_DescriptorSetLayoutCreateInfo.def(py::init<vk::DescriptorSetLayoutCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::DescriptorSetLayoutBinding> &, const void *>(), py::arg("flags"), py::arg("bindings"), py::arg("p_next") = nullptr);

    s_vk_DeviceCreateInfo.def(py::init<vk::DeviceCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::DeviceQueueCreateInfo> &, const vk::ArrayProxyNoTemporaries<const char *const> &, const vk::ArrayProxyNoTemporaries<const char *const> &, const vk::PhysicalDeviceFeatures *, const void *>(), py::arg("flags"), py::arg("queue_create_infos"), py::arg("p_enabled_layer_names") = vk::ArrayProxyNoTemporaries<const char *const>{}, py::arg("p_enabled_extension_names") = vk::ArrayProxyNoTemporaries<const char *const>{}, py::arg("p_enabled_features") = nullptr, py::arg("p_next") = nullptr);

    s_vk_DeviceQueueCreateInfo.def(py::init<vk::DeviceQueueCreateFlags, uint32_t, const vk::ArrayProxyNoTemporaries<const float> &, const void *>(), py::arg("flags"), py::arg("queue_family_index"), py::arg("queue_priorities"), py::arg("p_next") = nullptr);

    s_vk_DispatchIndirectCommand.def(py::init<uint32_t, uint32_t, uint32_t>(), py::arg("x") = uint32_t{}, py::arg("y") = uint32_t{}, py::arg("z") = uint32_t{});

    s_vk_DrawIndexedIndirectCommand.def(py::init<uint32_t, uint32_t, uint32_t, int32_t, uint32_t>(), py::arg("index_count") = uint32_t{}, py::arg("instance_count") = uint32_t{}, py::arg("first_index") = uint32_t{}, py::arg("vertex_offset") = int32_t{}, py::arg("first_instance") = uint32_t{});

    s_vk_DrawIndirectCommand.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t>(), py::arg("vertex_count") = uint32_t{}, py::arg("instance_count") = uint32_t{}, py::arg("first_vertex") = uint32_t{}, py::arg("first_instance") = uint32_t{});

    s_vk_EventCreateInfo.def(py::init<vk::EventCreateFlags, const void *>(), py::arg("flags") = vk::EventCreateFlags{}, py::arg("p_next") = nullptr);

    s_vk_ExtensionProperties.def(py::init<const std::array<char, 256U> &, uint32_t>(), py::arg("extension_name") = std::array<char, 256U>{}, py::arg("spec_version") = uint32_t{});

    s_vk_Extent2D.def(py::init<uint32_t, uint32_t>(), py::arg("width") = uint32_t{}, py::arg("height") = uint32_t{});

    s_vk_Extent3D.def(py::init<const ::vk::Extent2D &, uint32_t>(), py::arg("extent2D"), py::arg("depth") = uint32_t{});

    s_vk_FenceCreateInfo.def(py::init<vk::FenceCreateFlags, const void *>(), py::arg("flags") = vk::FenceCreateFlags{}, py::arg("p_next") = nullptr);

    s_vk_FormatProperties.def(py::init<vk::FormatFeatureFlags, vk::FormatFeatureFlags, vk::FormatFeatureFlags>(), py::arg("linear_tiling_features") = vk::FormatFeatureFlags{}, py::arg("optimal_tiling_features") = vk::FormatFeatureFlags{}, py::arg("buffer_features") = vk::FormatFeatureFlags{});

    s_vk_FramebufferCreateInfo.def(py::init<vk::FramebufferCreateFlags, vk::RenderPass, const vk::ArrayProxyNoTemporaries<const vk::ImageView> &, uint32_t, uint32_t, uint32_t, const void *>(), py::arg("flags"), py::arg("render_pass"), py::arg("attachments"), py::arg("width") = uint32_t{}, py::arg("height") = uint32_t{}, py::arg("layers") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_GraphicsPipelineCreateInfo.def(py::init<vk::PipelineCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::PipelineShaderStageCreateInfo> &, const vk::PipelineVertexInputStateCreateInfo *, const vk::PipelineInputAssemblyStateCreateInfo *, const vk::PipelineTessellationStateCreateInfo *, const vk::PipelineViewportStateCreateInfo *, const vk::PipelineRasterizationStateCreateInfo *, const vk::PipelineMultisampleStateCreateInfo *, const vk::PipelineDepthStencilStateCreateInfo *, const vk::PipelineColorBlendStateCreateInfo *, const vk::PipelineDynamicStateCreateInfo *, vk::PipelineLayout, vk::RenderPass, uint32_t, vk::Pipeline, int32_t, const void *>(), py::arg("flags"), py::arg("stages"), py::arg("p_vertex_input_state") = nullptr, py::arg("p_input_assembly_state") = nullptr, py::arg("p_tessellation_state") = nullptr, py::arg("p_viewport_state") = nullptr, py::arg("p_rasterization_state") = nullptr, py::arg("p_multisample_state") = nullptr, py::arg("p_depth_stencil_state") = nullptr, py::arg("p_color_blend_state") = nullptr, py::arg("p_dynamic_state") = nullptr, py::arg("layout") = vk::PipelineLayout{}, py::arg("render_pass") = vk::RenderPass{}, py::arg("subpass") = uint32_t{}, py::arg("base_pipeline_handle") = vk::Pipeline{}, py::arg("base_pipeline_index") = int32_t{}, py::arg("p_next") = nullptr);

    s_vk_ImageBlit.def(py::init<vk::ImageSubresourceLayers, const std::array<vk::Offset3D, 2> &, vk::ImageSubresourceLayers, const std::array<vk::Offset3D, 2> &>(), py::arg("src_subresource") = vk::ImageSubresourceLayers{}, py::arg("src_offsets") = std::array<vk::Offset3D, 2>{}, py::arg("dst_subresource") = vk::ImageSubresourceLayers{}, py::arg("dst_offsets") = std::array<vk::Offset3D, 2>{});

    s_vk_ImageCopy.def(py::init<vk::ImageSubresourceLayers, vk::Offset3D, vk::ImageSubresourceLayers, vk::Offset3D, vk::Extent3D>(), py::arg("src_subresource") = vk::ImageSubresourceLayers{}, py::arg("src_offset") = vk::Offset3D{}, py::arg("dst_subresource") = vk::ImageSubresourceLayers{}, py::arg("dst_offset") = vk::Offset3D{}, py::arg("extent") = vk::Extent3D{});

    s_vk_ImageCreateInfo.def(py::init<vk::ImageCreateFlags, vk::ImageType, vk::Format, vk::Extent3D, uint32_t, uint32_t, vk::SampleCountFlagBits, vk::ImageTiling, vk::ImageUsageFlags, vk::SharingMode, const vk::ArrayProxyNoTemporaries<const uint32_t> &, vk::ImageLayout, const void *>(), py::arg("flags"), py::arg("image_type"), py::arg("format"), py::arg("extent"), py::arg("mip_levels"), py::arg("array_layers"), py::arg("samples"), py::arg("tiling"), py::arg("usage"), py::arg("sharing_mode"), py::arg("queue_family_indices"), py::arg("initial_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("p_next") = nullptr);

    s_vk_ImageFormatProperties.def(py::init<vk::Extent3D, uint32_t, uint32_t, vk::SampleCountFlags, vk::DeviceSize>(), py::arg("max_extent") = vk::Extent3D{}, py::arg("max_mip_levels") = uint32_t{}, py::arg("max_array_layers") = uint32_t{}, py::arg("sample_counts") = vk::SampleCountFlags{}, py::arg("max_resource_size") = vk::DeviceSize{});

    s_vk_ImageMemoryBarrier.def(py::init<vk::AccessFlags, vk::AccessFlags, vk::ImageLayout, vk::ImageLayout, uint32_t, uint32_t, vk::Image, vk::ImageSubresourceRange, const void *>(), py::arg("src_access_mask") = vk::AccessFlags{}, py::arg("dst_access_mask") = vk::AccessFlags{}, py::arg("old_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("new_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("src_queue_family_index") = uint32_t{}, py::arg("dst_queue_family_index") = uint32_t{}, py::arg("image") = vk::Image{}, py::arg("subresource_range") = vk::ImageSubresourceRange{}, py::arg("p_next") = nullptr);

    s_vk_ImageResolve.def(py::init<vk::ImageSubresourceLayers, vk::Offset3D, vk::ImageSubresourceLayers, vk::Offset3D, vk::Extent3D>(), py::arg("src_subresource") = vk::ImageSubresourceLayers{}, py::arg("src_offset") = vk::Offset3D{}, py::arg("dst_subresource") = vk::ImageSubresourceLayers{}, py::arg("dst_offset") = vk::Offset3D{}, py::arg("extent") = vk::Extent3D{});

    s_vk_ImageSubresource.def(py::init<vk::ImageAspectFlags, uint32_t, uint32_t>(), py::arg("aspect_mask") = vk::ImageAspectFlags{}, py::arg("mip_level") = uint32_t{}, py::arg("array_layer") = uint32_t{});

    s_vk_ImageSubresourceLayers.def(py::init<vk::ImageAspectFlags, uint32_t, uint32_t, uint32_t>(), py::arg("aspect_mask") = vk::ImageAspectFlags{}, py::arg("mip_level") = uint32_t{}, py::arg("base_array_layer") = uint32_t{}, py::arg("layer_count") = uint32_t{});

    s_vk_ImageSubresourceRange.def(py::init<vk::ImageAspectFlags, uint32_t, uint32_t, uint32_t, uint32_t>(), py::arg("aspect_mask") = vk::ImageAspectFlags{}, py::arg("base_mip_level") = uint32_t{}, py::arg("level_count") = uint32_t{}, py::arg("base_array_layer") = uint32_t{}, py::arg("layer_count") = uint32_t{});

    s_vk_ImageViewCreateInfo.def(py::init<vk::ImageViewCreateFlags, vk::Image, vk::ImageViewType, vk::Format, vk::ComponentMapping, vk::ImageSubresourceRange, const void *>(), py::arg("flags") = vk::ImageViewCreateFlags{}, py::arg("image") = vk::Image{}, py::arg("view_type") = VULKAN_HPP_NAMESPACE::ImageViewType::e1D, py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("components") = vk::ComponentMapping{}, py::arg("subresource_range") = vk::ImageSubresourceRange{}, py::arg("p_next") = nullptr);

    s_vk_InstanceCreateInfo.def(py::init<vk::InstanceCreateFlags, const vk::ApplicationInfo *, const vk::ArrayProxyNoTemporaries<const char *const> &, const vk::ArrayProxyNoTemporaries<const char *const> &, const void *>(), py::arg("flags"), py::arg("p_application_info"), py::arg("p_enabled_layer_names"), py::arg("p_enabled_extension_names") = vk::ArrayProxyNoTemporaries<const char *const>{}, py::arg("p_next") = nullptr);

    s_vk_LayerProperties.def(py::init<const std::array<char, 256U> &, uint32_t, uint32_t, const std::array<char, 256U> &>(), py::arg("layer_name") = std::array<char, 256U>{}, py::arg("spec_version") = uint32_t{}, py::arg("implementation_version") = uint32_t{}, py::arg("description") = std::array<char, 256U>{});

    s_vk_MappedMemoryRange.def(py::init<vk::DeviceMemory, vk::DeviceSize, vk::DeviceSize, const void *>(), py::arg("memory") = vk::DeviceMemory{}, py::arg("offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_MemoryAllocateInfo.def(py::init<vk::DeviceSize, uint32_t, const void *>(), py::arg("allocation_size") = vk::DeviceSize{}, py::arg("memory_type_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_MemoryBarrier.def(py::init<vk::AccessFlags, vk::AccessFlags, const void *>(), py::arg("src_access_mask") = vk::AccessFlags{}, py::arg("dst_access_mask") = vk::AccessFlags{}, py::arg("p_next") = nullptr);

    s_vk_MemoryHeap.def(py::init<vk::DeviceSize, vk::MemoryHeapFlags>(), py::arg("size") = vk::DeviceSize{}, py::arg("flags") = vk::MemoryHeapFlags{});

    s_vk_MemoryRequirements.def(py::init<vk::DeviceSize, vk::DeviceSize, uint32_t>(), py::arg("size") = vk::DeviceSize{}, py::arg("alignment") = vk::DeviceSize{}, py::arg("memory_type_bits") = uint32_t{});

    s_vk_MemoryType.def(py::init<vk::MemoryPropertyFlags, uint32_t>(), py::arg("property_flags") = vk::MemoryPropertyFlags{}, py::arg("heap_index") = uint32_t{});

    s_vk_Offset2D.def(py::init<int32_t, int32_t>(), py::arg("x") = int32_t{}, py::arg("y") = int32_t{});

    s_vk_Offset3D.def(py::init<const ::vk::Offset2D &, int32_t>(), py::arg("offset2D"), py::arg("z") = int32_t{});

    s_vk_PhysicalDeviceFeatures.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32>(), py::arg("robust_buffer_access") = vk::Bool32{}, py::arg("full_draw_index_uint_32") = vk::Bool32{}, py::arg("image_cube_array") = vk::Bool32{}, py::arg("independent_blend") = vk::Bool32{}, py::arg("geometry_shader") = vk::Bool32{}, py::arg("tessellation_shader") = vk::Bool32{}, py::arg("sample_rate_shading") = vk::Bool32{}, py::arg("dual_src_blend") = vk::Bool32{}, py::arg("logic_op") = vk::Bool32{}, py::arg("multi_draw_indirect") = vk::Bool32{}, py::arg("draw_indirect_first_instance") = vk::Bool32{}, py::arg("depth_clamp") = vk::Bool32{}, py::arg("depth_bias_clamp") = vk::Bool32{}, py::arg("fill_mode_non_solid") = vk::Bool32{}, py::arg("depth_bounds") = vk::Bool32{}, py::arg("wide_lines") = vk::Bool32{}, py::arg("large_points") = vk::Bool32{}, py::arg("alpha_to_one") = vk::Bool32{}, py::arg("multi_viewport") = vk::Bool32{}, py::arg("sampler_anisotropy") = vk::Bool32{}, py::arg("texture_compression_ETC2") = vk::Bool32{}, py::arg("texture_compression_ASTC_LDR") = vk::Bool32{}, py::arg("texture_compression_BC") = vk::Bool32{}, py::arg("occlusion_query_precise") = vk::Bool32{}, py::arg("pipeline_statistics_query") = vk::Bool32{}, py::arg("vertex_pipeline_stores_and_atomics") = vk::Bool32{}, py::arg("fragment_stores_and_atomics") = vk::Bool32{}, py::arg("shader_tessellation_and_geometry_point_size") = vk::Bool32{}, py::arg("shader_image_gather_extended") = vk::Bool32{}, py::arg("shader_storage_image_extended_formats") = vk::Bool32{}, py::arg("shader_storage_image_multisample") = vk::Bool32{}, py::arg("shader_storage_image_read_without_format") = vk::Bool32{}, py::arg("shader_storage_image_write_without_format") = vk::Bool32{}, py::arg("shader_uniform_buffer_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_sampled_image_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_storage_buffer_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_storage_image_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_clip_distance") = vk::Bool32{}, py::arg("shader_cull_distance") = vk::Bool32{}, py::arg("shader_float_64") = vk::Bool32{}, py::arg("shader_int_64") = vk::Bool32{}, py::arg("shader_int_16") = vk::Bool32{}, py::arg("shader_resource_residency") = vk::Bool32{}, py::arg("shader_resource_min_lod") = vk::Bool32{}, py::arg("sparse_binding") = vk::Bool32{}, py::arg("sparse_residency_buffer") = vk::Bool32{}, py::arg("sparse_residency_image_2d") = vk::Bool32{}, py::arg("sparse_residency_image_3d") = vk::Bool32{}, py::arg("sparse_residency_2_samples") = vk::Bool32{}, py::arg("sparse_residency_4_samples") = vk::Bool32{}, py::arg("sparse_residency_8_samples") = vk::Bool32{}, py::arg("sparse_residency_16_samples") = vk::Bool32{}, py::arg("sparse_residency_aliased") = vk::Bool32{}, py::arg("variable_multisample_rate") = vk::Bool32{}, py::arg("inherited_queries") = vk::Bool32{});

    s_vk_PhysicalDeviceLimits.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, vk::DeviceSize, vk::DeviceSize, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, const std::array<uint32_t, 3> &, uint32_t, const std::array<uint32_t, 3> &, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, float, float, uint32_t, const std::array<uint32_t, 2> &, const std::array<float, 2> &, uint32_t, size_t, vk::DeviceSize, vk::DeviceSize, vk::DeviceSize, int32_t, uint32_t, int32_t, uint32_t, float, float, uint32_t, uint32_t, uint32_t, uint32_t, vk::SampleCountFlags, vk::SampleCountFlags, vk::SampleCountFlags, vk::SampleCountFlags, uint32_t, vk::SampleCountFlags, vk::SampleCountFlags, vk::SampleCountFlags, vk::SampleCountFlags, vk::SampleCountFlags, uint32_t, vk::Bool32, float, uint32_t, uint32_t, uint32_t, uint32_t, const std::array<float, 2> &, const std::array<float, 2> &, float, float, vk::Bool32, vk::Bool32, vk::DeviceSize, vk::DeviceSize, vk::DeviceSize>(), py::arg("max_image_dimension_1d") = uint32_t{}, py::arg("max_image_dimension_2d") = uint32_t{}, py::arg("max_image_dimension_3d") = uint32_t{}, py::arg("max_image_dimension_cube") = uint32_t{}, py::arg("max_image_array_layers") = uint32_t{}, py::arg("max_texel_buffer_elements") = uint32_t{}, py::arg("max_uniform_buffer_range") = uint32_t{}, py::arg("max_storage_buffer_range") = uint32_t{}, py::arg("max_push_constants_size") = uint32_t{}, py::arg("max_memory_allocation_count") = uint32_t{}, py::arg("max_sampler_allocation_count") = uint32_t{}, py::arg("buffer_image_granularity") = vk::DeviceSize{}, py::arg("sparse_address_space_size") = vk::DeviceSize{}, py::arg("max_bound_descriptor_sets") = uint32_t{}, py::arg("max_per_stage_descriptor_samplers") = uint32_t{}, py::arg("max_per_stage_descriptor_uniform_buffers") = uint32_t{}, py::arg("max_per_stage_descriptor_storage_buffers") = uint32_t{}, py::arg("max_per_stage_descriptor_sampled_images") = uint32_t{}, py::arg("max_per_stage_descriptor_storage_images") = uint32_t{}, py::arg("max_per_stage_descriptor_input_attachments") = uint32_t{}, py::arg("max_per_stage_resources") = uint32_t{}, py::arg("max_descriptor_set_samplers") = uint32_t{}, py::arg("max_descriptor_set_uniform_buffers") = uint32_t{}, py::arg("max_descriptor_set_uniform_buffers_dynamic") = uint32_t{}, py::arg("max_descriptor_set_storage_buffers") = uint32_t{}, py::arg("max_descriptor_set_storage_buffers_dynamic") = uint32_t{}, py::arg("max_descriptor_set_sampled_images") = uint32_t{}, py::arg("max_descriptor_set_storage_images") = uint32_t{}, py::arg("max_descriptor_set_input_attachments") = uint32_t{}, py::arg("max_vertex_input_attributes") = uint32_t{}, py::arg("max_vertex_input_bindings") = uint32_t{}, py::arg("max_vertex_input_attribute_offset") = uint32_t{}, py::arg("max_vertex_input_binding_stride") = uint32_t{}, py::arg("max_vertex_output_components") = uint32_t{}, py::arg("max_tessellation_generation_level") = uint32_t{}, py::arg("max_tessellation_patch_size") = uint32_t{}, py::arg("max_tessellation_control_per_vertex_input_components") = uint32_t{}, py::arg("max_tessellation_control_per_vertex_output_components") = uint32_t{}, py::arg("max_tessellation_control_per_patch_output_components") = uint32_t{}, py::arg("max_tessellation_control_total_output_components") = uint32_t{}, py::arg("max_tessellation_evaluation_input_components") = uint32_t{}, py::arg("max_tessellation_evaluation_output_components") = uint32_t{}, py::arg("max_geometry_shader_invocations") = uint32_t{}, py::arg("max_geometry_input_components") = uint32_t{}, py::arg("max_geometry_output_components") = uint32_t{}, py::arg("max_geometry_output_vertices") = uint32_t{}, py::arg("max_geometry_total_output_components") = uint32_t{}, py::arg("max_fragment_input_components") = uint32_t{}, py::arg("max_fragment_output_attachments") = uint32_t{}, py::arg("max_fragment_dual_src_attachments") = uint32_t{}, py::arg("max_fragment_combined_output_resources") = uint32_t{}, py::arg("max_compute_shared_memory_size") = uint32_t{}, py::arg("max_compute_work_group_count") = std::array<uint32_t, 3>{}, py::arg("max_compute_work_group_invocations") = uint32_t{}, py::arg("max_compute_work_group_size") = std::array<uint32_t, 3>{}, py::arg("sub_pixel_precision_bits") = uint32_t{}, py::arg("sub_texel_precision_bits") = uint32_t{}, py::arg("mipmap_precision_bits") = uint32_t{}, py::arg("max_draw_indexed_index_value") = uint32_t{}, py::arg("max_draw_indirect_count") = uint32_t{}, py::arg("max_sampler_lod_bias") = float{}, py::arg("max_sampler_anisotropy") = float{}, py::arg("max_viewports") = uint32_t{}, py::arg("max_viewport_dimensions") = std::array<uint32_t, 2>{}, py::arg("viewport_bounds_range") = std::array<float, 2>{}, py::arg("viewport_sub_pixel_bits") = uint32_t{}, py::arg("min_memory_map_alignment") = size_t{}, py::arg("min_texel_buffer_offset_alignment") = vk::DeviceSize{}, py::arg("min_uniform_buffer_offset_alignment") = vk::DeviceSize{}, py::arg("min_storage_buffer_offset_alignment") = vk::DeviceSize{}, py::arg("min_texel_offset") = int32_t{}, py::arg("max_texel_offset") = uint32_t{}, py::arg("min_texel_gather_offset") = int32_t{}, py::arg("max_texel_gather_offset") = uint32_t{}, py::arg("min_interpolation_offset") = float{}, py::arg("max_interpolation_offset") = float{}, py::arg("sub_pixel_interpolation_offset_bits") = uint32_t{}, py::arg("max_framebuffer_width") = uint32_t{}, py::arg("max_framebuffer_height") = uint32_t{}, py::arg("max_framebuffer_layers") = uint32_t{}, py::arg("framebuffer_color_sample_counts") = vk::SampleCountFlags{}, py::arg("framebuffer_depth_sample_counts") = vk::SampleCountFlags{}, py::arg("framebuffer_stencil_sample_counts") = vk::SampleCountFlags{}, py::arg("framebuffer_no_attachments_sample_counts") = vk::SampleCountFlags{}, py::arg("max_color_attachments") = uint32_t{}, py::arg("sampled_image_color_sample_counts") = vk::SampleCountFlags{}, py::arg("sampled_image_integer_sample_counts") = vk::SampleCountFlags{}, py::arg("sampled_image_depth_sample_counts") = vk::SampleCountFlags{}, py::arg("sampled_image_stencil_sample_counts") = vk::SampleCountFlags{}, py::arg("storage_image_sample_counts") = vk::SampleCountFlags{}, py::arg("max_sample_mask_words") = uint32_t{}, py::arg("timestamp_compute_and_graphics") = vk::Bool32{}, py::arg("timestamp_period") = float{}, py::arg("max_clip_distances") = uint32_t{}, py::arg("max_cull_distances") = uint32_t{}, py::arg("max_combined_clip_and_cull_distances") = uint32_t{}, py::arg("discrete_queue_priorities") = uint32_t{}, py::arg("point_size_range") = std::array<float, 2>{}, py::arg("line_width_range") = std::array<float, 2>{}, py::arg("point_size_granularity") = float{}, py::arg("line_width_granularity") = float{}, py::arg("strict_lines") = vk::Bool32{}, py::arg("standard_sample_locations") = vk::Bool32{}, py::arg("optimal_buffer_copy_offset_alignment") = vk::DeviceSize{}, py::arg("optimal_buffer_copy_row_pitch_alignment") = vk::DeviceSize{}, py::arg("non_coherent_atom_size") = vk::DeviceSize{});

    s_vk_PhysicalDeviceMemoryProperties.def(py::init<uint32_t, const std::array<vk::MemoryType, 32U> &, uint32_t, const std::array<vk::MemoryHeap, 16U> &>(), py::arg("memory_type_count") = uint32_t{}, py::arg("memory_types") = std::array<vk::MemoryType, 32U>{}, py::arg("memory_heap_count") = uint32_t{}, py::arg("memory_heaps") = std::array<vk::MemoryHeap, 16U>{});

    s_vk_PhysicalDeviceProperties.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, vk::PhysicalDeviceType, const std::array<char, 256U> &, const std::array<uint8_t, 16U> &, vk::PhysicalDeviceLimits, vk::PhysicalDeviceSparseProperties>(), py::arg("api_version") = uint32_t{}, py::arg("driver_version") = uint32_t{}, py::arg("vendorID") = uint32_t{}, py::arg("deviceID") = uint32_t{}, py::arg("device_type") = VULKAN_HPP_NAMESPACE::PhysicalDeviceType::eOther, py::arg("device_name") = std::array<char, 256U>{}, py::arg("pipeline_cache_UUID") = std::array<uint8_t, 16U>{}, py::arg("limits") = vk::PhysicalDeviceLimits{}, py::arg("sparse_properties") = vk::PhysicalDeviceSparseProperties{});

    s_vk_PhysicalDeviceSparseProperties.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32>(), py::arg("residency_standard_2d_block_shape") = vk::Bool32{}, py::arg("residency_standard_2d_multisample_block_shape") = vk::Bool32{}, py::arg("residency_standard_3d_block_shape") = vk::Bool32{}, py::arg("residency_aligned_mip_size") = vk::Bool32{}, py::arg("residency_non_resident_strict") = vk::Bool32{});

    s_vk_PipelineCacheCreateInfo.def(py::init<vk::PipelineCacheCreateFlags, size_t, const void *, const void *>(), py::arg("flags") = vk::PipelineCacheCreateFlags{}, py::arg("initial_data_size") = size_t{}, py::arg("p_initial_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PipelineCacheHeaderVersionOne.def(py::init<uint32_t, vk::PipelineCacheHeaderVersion, uint32_t, uint32_t, const std::array<uint8_t, 16U> &>(), py::arg("header_size") = uint32_t{}, py::arg("header_version") = VULKAN_HPP_NAMESPACE::PipelineCacheHeaderVersion::eOne, py::arg("vendorID") = uint32_t{}, py::arg("deviceID") = uint32_t{}, py::arg("pipeline_cache_UUID") = std::array<uint8_t, 16U>{});

    s_vk_PipelineColorBlendAttachmentState.def(py::init<vk::Bool32, vk::BlendFactor, vk::BlendFactor, vk::BlendOp, vk::BlendFactor, vk::BlendFactor, vk::BlendOp, vk::ColorComponentFlags>(), py::arg("blend_enable") = vk::Bool32{}, py::arg("src_color_blend_factor") = VULKAN_HPP_NAMESPACE::BlendFactor::eZero, py::arg("dst_color_blend_factor") = VULKAN_HPP_NAMESPACE::BlendFactor::eZero, py::arg("color_blend_op") = VULKAN_HPP_NAMESPACE::BlendOp::eAdd, py::arg("src_alpha_blend_factor") = VULKAN_HPP_NAMESPACE::BlendFactor::eZero, py::arg("dst_alpha_blend_factor") = VULKAN_HPP_NAMESPACE::BlendFactor::eZero, py::arg("alpha_blend_op") = VULKAN_HPP_NAMESPACE::BlendOp::eAdd, py::arg("color_write_mask") = vk::ColorComponentFlags{});

    s_vk_PipelineColorBlendStateCreateInfo.def(py::init<vk::PipelineColorBlendStateCreateFlags, vk::Bool32, vk::LogicOp, const vk::ArrayProxyNoTemporaries<const vk::PipelineColorBlendAttachmentState> &, const std::array<float, 4> &, const void *>(), py::arg("flags"), py::arg("logic_op_enable"), py::arg("logic_op"), py::arg("attachments"), py::arg("blend_constants") = std::array<float, 4>{}, py::arg("p_next") = nullptr);

    s_vk_PipelineDepthStencilStateCreateInfo.def(py::init<vk::PipelineDepthStencilStateCreateFlags, vk::Bool32, vk::Bool32, vk::CompareOp, vk::Bool32, vk::Bool32, vk::StencilOpState, vk::StencilOpState, float, float, const void *>(), py::arg("flags") = vk::PipelineDepthStencilStateCreateFlags{}, py::arg("depth_test_enable") = vk::Bool32{}, py::arg("depth_write_enable") = vk::Bool32{}, py::arg("depth_compare_op") = VULKAN_HPP_NAMESPACE::CompareOp::eNever, py::arg("depth_bounds_test_enable") = vk::Bool32{}, py::arg("stencil_test_enable") = vk::Bool32{}, py::arg("front") = vk::StencilOpState{}, py::arg("back") = vk::StencilOpState{}, py::arg("min_depth_bounds") = float{}, py::arg("max_depth_bounds") = float{}, py::arg("p_next") = nullptr);

    s_vk_PipelineDynamicStateCreateInfo.def(py::init<vk::PipelineDynamicStateCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::DynamicState> &, const void *>(), py::arg("flags"), py::arg("dynamic_states"), py::arg("p_next") = nullptr);

    s_vk_PipelineInputAssemblyStateCreateInfo.def(py::init<vk::PipelineInputAssemblyStateCreateFlags, vk::PrimitiveTopology, vk::Bool32, const void *>(), py::arg("flags") = vk::PipelineInputAssemblyStateCreateFlags{}, py::arg("topology") = VULKAN_HPP_NAMESPACE::PrimitiveTopology::ePointList, py::arg("primitive_restart_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineLayoutCreateInfo.def(py::init<vk::PipelineLayoutCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::DescriptorSetLayout> &, const vk::ArrayProxyNoTemporaries<const vk::PushConstantRange> &, const void *>(), py::arg("flags"), py::arg("set_layouts"), py::arg("push_constant_ranges") = vk::ArrayProxyNoTemporaries<const vk::PushConstantRange>{}, py::arg("p_next") = nullptr);

    s_vk_PipelineMultisampleStateCreateInfo.def(py::init<vk::PipelineMultisampleStateCreateFlags, vk::SampleCountFlagBits, vk::Bool32, float, const vk::SampleMask *, vk::Bool32, vk::Bool32, const void *>(), py::arg("flags") = vk::PipelineMultisampleStateCreateFlags{}, py::arg("rasterization_samples") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("sample_shading_enable") = vk::Bool32{}, py::arg("min_sample_shading") = float{}, py::arg("p_sample_mask") = nullptr, py::arg("alpha_to_coverage_enable") = vk::Bool32{}, py::arg("alpha_to_one_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineRasterizationStateCreateInfo.def(py::init<vk::PipelineRasterizationStateCreateFlags, vk::Bool32, vk::Bool32, vk::PolygonMode, vk::CullModeFlags, vk::FrontFace, vk::Bool32, float, float, float, float, const void *>(), py::arg("flags") = vk::PipelineRasterizationStateCreateFlags{}, py::arg("depth_clamp_enable") = vk::Bool32{}, py::arg("rasterizer_discard_enable") = vk::Bool32{}, py::arg("polygon_mode") = VULKAN_HPP_NAMESPACE::PolygonMode::eFill, py::arg("cull_mode") = vk::CullModeFlags{}, py::arg("front_face") = VULKAN_HPP_NAMESPACE::FrontFace::eCounterClockwise, py::arg("depth_bias_enable") = vk::Bool32{}, py::arg("depth_bias_constant_factor") = float{}, py::arg("depth_bias_clamp") = float{}, py::arg("depth_bias_slope_factor") = float{}, py::arg("line_width") = float{}, py::arg("p_next") = nullptr);

    s_vk_PipelineShaderStageCreateInfo.def(py::init<vk::PipelineShaderStageCreateFlags, vk::ShaderStageFlagBits, vk::ShaderModule, const char *, const vk::SpecializationInfo *, const void *>(), py::arg("flags") = vk::PipelineShaderStageCreateFlags{}, py::arg("stage") = VULKAN_HPP_NAMESPACE::ShaderStageFlagBits::eVertex, py::arg("module") = vk::ShaderModule{}, py::arg("p_name") = nullptr, py::arg("p_specialization_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PipelineTessellationStateCreateInfo.def(py::init<vk::PipelineTessellationStateCreateFlags, uint32_t, const void *>(), py::arg("flags") = vk::PipelineTessellationStateCreateFlags{}, py::arg("patch_control_points") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PipelineVertexInputStateCreateInfo.def(py::init<vk::PipelineVertexInputStateCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::VertexInputBindingDescription> &, const vk::ArrayProxyNoTemporaries<const vk::VertexInputAttributeDescription> &, const void *>(), py::arg("flags"), py::arg("vertex_binding_descriptions"), py::arg("vertex_attribute_descriptions") = vk::ArrayProxyNoTemporaries<const vk::VertexInputAttributeDescription>{}, py::arg("p_next") = nullptr);

    s_vk_PipelineViewportStateCreateInfo.def(py::init<vk::PipelineViewportStateCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::Viewport> &, const vk::ArrayProxyNoTemporaries<const vk::Rect2D> &, const void *>(), py::arg("flags"), py::arg("viewports"), py::arg("scissors") = vk::ArrayProxyNoTemporaries<const vk::Rect2D>{}, py::arg("p_next") = nullptr);

    s_vk_PushConstantRange.def(py::init<vk::ShaderStageFlags, uint32_t, uint32_t>(), py::arg("stage_flags") = vk::ShaderStageFlags{}, py::arg("offset") = uint32_t{}, py::arg("size") = uint32_t{});

    s_vk_QueryPoolCreateInfo.def(py::init<vk::QueryPoolCreateFlags, vk::QueryType, uint32_t, vk::QueryPipelineStatisticFlags, const void *>(), py::arg("flags") = vk::QueryPoolCreateFlags{}, py::arg("query_type") = VULKAN_HPP_NAMESPACE::QueryType::eOcclusion, py::arg("query_count") = uint32_t{}, py::arg("pipeline_statistics") = vk::QueryPipelineStatisticFlags{}, py::arg("p_next") = nullptr);

    s_vk_QueueFamilyProperties.def(py::init<vk::QueueFlags, uint32_t, uint32_t, vk::Extent3D>(), py::arg("queue_flags") = vk::QueueFlags{}, py::arg("queue_count") = uint32_t{}, py::arg("timestamp_valid_bits") = uint32_t{}, py::arg("min_image_transfer_granularity") = vk::Extent3D{});

    s_vk_Rect2D.def(py::init<vk::Offset2D, vk::Extent2D>(), py::arg("offset") = vk::Offset2D{}, py::arg("extent") = vk::Extent2D{});

    s_vk_RenderPassBeginInfo.def(py::init<vk::RenderPass, vk::Framebuffer, vk::Rect2D, const vk::ArrayProxyNoTemporaries<const vk::ClearValue> &, const void *>(), py::arg("render_pass"), py::arg("framebuffer"), py::arg("render_area"), py::arg("clear_values"), py::arg("p_next") = nullptr);

    s_vk_RenderPassCreateInfo.def(py::init<vk::RenderPassCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::AttachmentDescription> &, const vk::ArrayProxyNoTemporaries<const vk::SubpassDescription> &, const vk::ArrayProxyNoTemporaries<const vk::SubpassDependency> &, const void *>(), py::arg("flags"), py::arg("attachments"), py::arg("subpasses") = vk::ArrayProxyNoTemporaries<const vk::SubpassDescription>{}, py::arg("dependencies") = vk::ArrayProxyNoTemporaries<const vk::SubpassDependency>{}, py::arg("p_next") = nullptr);

    s_vk_SamplerCreateInfo.def(py::init<vk::SamplerCreateFlags, vk::Filter, vk::Filter, vk::SamplerMipmapMode, vk::SamplerAddressMode, vk::SamplerAddressMode, vk::SamplerAddressMode, float, vk::Bool32, float, vk::Bool32, vk::CompareOp, float, float, vk::BorderColor, vk::Bool32, const void *>(), py::arg("flags") = vk::SamplerCreateFlags{}, py::arg("mag_filter") = VULKAN_HPP_NAMESPACE::Filter::eNearest, py::arg("min_filter") = VULKAN_HPP_NAMESPACE::Filter::eNearest, py::arg("mipmap_mode") = VULKAN_HPP_NAMESPACE::SamplerMipmapMode::eNearest, py::arg("address_mode_u") = VULKAN_HPP_NAMESPACE::SamplerAddressMode::eRepeat, py::arg("address_mode_v") = VULKAN_HPP_NAMESPACE::SamplerAddressMode::eRepeat, py::arg("address_mode_w") = VULKAN_HPP_NAMESPACE::SamplerAddressMode::eRepeat, py::arg("mip_lod_bias") = float{}, py::arg("anisotropy_enable") = vk::Bool32{}, py::arg("max_anisotropy") = float{}, py::arg("compare_enable") = vk::Bool32{}, py::arg("compare_op") = VULKAN_HPP_NAMESPACE::CompareOp::eNever, py::arg("min_lod") = float{}, py::arg("max_lod") = float{}, py::arg("border_color") = VULKAN_HPP_NAMESPACE::BorderColor::eFloatTransparentBlack, py::arg("unnormalized_coordinates") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SemaphoreCreateInfo.def(py::init<vk::SemaphoreCreateFlags, const void *>(), py::arg("flags") = vk::SemaphoreCreateFlags{}, py::arg("p_next") = nullptr);

    s_vk_ShaderModuleCreateInfo.def(py::init<vk::ShaderModuleCreateFlags, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("flags"), py::arg("code"), py::arg("p_next") = nullptr);

    s_vk_SparseBufferMemoryBindInfo.def(py::init<vk::Buffer, const vk::ArrayProxyNoTemporaries<const vk::SparseMemoryBind> &>(), py::arg("buffer"), py::arg("binds"));

    s_vk_SparseImageFormatProperties.def(py::init<vk::ImageAspectFlags, vk::Extent3D, vk::SparseImageFormatFlags>(), py::arg("aspect_mask") = vk::ImageAspectFlags{}, py::arg("image_granularity") = vk::Extent3D{}, py::arg("flags") = vk::SparseImageFormatFlags{});

    s_vk_SparseImageMemoryBind.def(py::init<vk::ImageSubresource, vk::Offset3D, vk::Extent3D, vk::DeviceMemory, vk::DeviceSize, vk::SparseMemoryBindFlags>(), py::arg("subresource") = vk::ImageSubresource{}, py::arg("offset") = vk::Offset3D{}, py::arg("extent") = vk::Extent3D{}, py::arg("memory") = vk::DeviceMemory{}, py::arg("memory_offset") = vk::DeviceSize{}, py::arg("flags") = vk::SparseMemoryBindFlags{});

    s_vk_SparseImageMemoryBindInfo.def(py::init<vk::Image, const vk::ArrayProxyNoTemporaries<const vk::SparseImageMemoryBind> &>(), py::arg("image"), py::arg("binds"));

    s_vk_SparseImageMemoryRequirements.def(py::init<vk::SparseImageFormatProperties, uint32_t, vk::DeviceSize, vk::DeviceSize, vk::DeviceSize>(), py::arg("format_properties") = vk::SparseImageFormatProperties{}, py::arg("image_mip_tail_first_lod") = uint32_t{}, py::arg("image_mip_tail_size") = vk::DeviceSize{}, py::arg("image_mip_tail_offset") = vk::DeviceSize{}, py::arg("image_mip_tail_stride") = vk::DeviceSize{});

    s_vk_SparseImageOpaqueMemoryBindInfo.def(py::init<vk::Image, const vk::ArrayProxyNoTemporaries<const vk::SparseMemoryBind> &>(), py::arg("image"), py::arg("binds"));

    s_vk_SparseMemoryBind.def(py::init<vk::DeviceSize, vk::DeviceSize, vk::DeviceMemory, vk::DeviceSize, vk::SparseMemoryBindFlags>(), py::arg("resource_offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{}, py::arg("memory") = vk::DeviceMemory{}, py::arg("memory_offset") = vk::DeviceSize{}, py::arg("flags") = vk::SparseMemoryBindFlags{});

    s_vk_SpecializationInfo.def(py::init<uint32_t, const vk::SpecializationMapEntry *, size_t, const void *>(), py::arg("map_entry_count") = uint32_t{}, py::arg("p_map_entries") = nullptr, py::arg("data_size") = size_t{}, py::arg("p_data") = nullptr);

    s_vk_SpecializationMapEntry.def(py::init<uint32_t, uint32_t, size_t>(), py::arg("constantID") = uint32_t{}, py::arg("offset") = uint32_t{}, py::arg("size") = size_t{});

    s_vk_StencilOpState.def(py::init<vk::StencilOp, vk::StencilOp, vk::StencilOp, vk::CompareOp, uint32_t, uint32_t, uint32_t>(), py::arg("fail_op") = VULKAN_HPP_NAMESPACE::StencilOp::eKeep, py::arg("pass_op") = VULKAN_HPP_NAMESPACE::StencilOp::eKeep, py::arg("depth_fail_op") = VULKAN_HPP_NAMESPACE::StencilOp::eKeep, py::arg("compare_op") = VULKAN_HPP_NAMESPACE::CompareOp::eNever, py::arg("compare_mask") = uint32_t{}, py::arg("write_mask") = uint32_t{}, py::arg("reference") = uint32_t{});

    s_vk_SubmitInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Semaphore> &, const vk::ArrayProxyNoTemporaries<const vk::PipelineStageFlags> &, const vk::ArrayProxyNoTemporaries<const vk::CommandBuffer> &, const vk::ArrayProxyNoTemporaries<const vk::Semaphore> &, const void *>(), py::arg("wait_semaphores"), py::arg("wait_dst_stage_mask") = vk::ArrayProxyNoTemporaries<const vk::PipelineStageFlags>{}, py::arg("command_buffers") = vk::ArrayProxyNoTemporaries<const vk::CommandBuffer>{}, py::arg("signal_semaphores") = vk::ArrayProxyNoTemporaries<const vk::Semaphore>{}, py::arg("p_next") = nullptr);

    s_vk_SubpassDependency.def(py::init<uint32_t, uint32_t, vk::PipelineStageFlags, vk::PipelineStageFlags, vk::AccessFlags, vk::AccessFlags, vk::DependencyFlags>(), py::arg("src_subpass") = uint32_t{}, py::arg("dst_subpass") = uint32_t{}, py::arg("src_stage_mask") = vk::PipelineStageFlags{}, py::arg("dst_stage_mask") = vk::PipelineStageFlags{}, py::arg("src_access_mask") = vk::AccessFlags{}, py::arg("dst_access_mask") = vk::AccessFlags{}, py::arg("dependency_flags") = vk::DependencyFlags{});

    s_vk_SubpassDescription.def(py::init<vk::SubpassDescriptionFlags, vk::PipelineBindPoint, const vk::ArrayProxyNoTemporaries<const vk::AttachmentReference> &, const vk::ArrayProxyNoTemporaries<const vk::AttachmentReference> &, const vk::ArrayProxyNoTemporaries<const vk::AttachmentReference> &, const vk::AttachmentReference *, const vk::ArrayProxyNoTemporaries<const uint32_t> &>(), py::arg("flags"), py::arg("pipeline_bind_point"), py::arg("input_attachments"), py::arg("color_attachments") = vk::ArrayProxyNoTemporaries<const vk::AttachmentReference>{}, py::arg("resolve_attachments") = vk::ArrayProxyNoTemporaries<const vk::AttachmentReference>{}, py::arg("p_depth_stencil_attachment") = nullptr, py::arg("preserve_attachments") = vk::ArrayProxyNoTemporaries<const uint32_t>{});

    s_vk_SubresourceLayout.def(py::init<vk::DeviceSize, vk::DeviceSize, vk::DeviceSize, vk::DeviceSize, vk::DeviceSize>(), py::arg("offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{}, py::arg("row_pitch") = vk::DeviceSize{}, py::arg("array_pitch") = vk::DeviceSize{}, py::arg("depth_pitch") = vk::DeviceSize{});

    s_vk_VertexInputAttributeDescription.def(py::init<uint32_t, uint32_t, vk::Format, uint32_t>(), py::arg("location") = uint32_t{}, py::arg("binding") = uint32_t{}, py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("offset") = uint32_t{});

    s_vk_VertexInputBindingDescription.def(py::init<uint32_t, uint32_t, vk::VertexInputRate>(), py::arg("binding") = uint32_t{}, py::arg("stride") = uint32_t{}, py::arg("input_rate") = VULKAN_HPP_NAMESPACE::VertexInputRate::eVertex);

    s_vk_Viewport.def(py::init<float, float, float, float, float, float>(), py::arg("x") = float{}, py::arg("y") = float{}, py::arg("width") = float{}, py::arg("height") = float{}, py::arg("min_depth") = float{}, py::arg("max_depth") = float{});

    s_vk_WriteDescriptorSet.def(py::init<vk::DescriptorSet, uint32_t, uint32_t, vk::DescriptorType, const vk::ArrayProxyNoTemporaries<const vk::DescriptorImageInfo> &, const vk::ArrayProxyNoTemporaries<const vk::DescriptorBufferInfo> &, const vk::ArrayProxyNoTemporaries<const vk::BufferView> &, const void *>(), py::arg("dst_set"), py::arg("dst_binding"), py::arg("dst_array_element"), py::arg("descriptor_type"), py::arg("image_info"), py::arg("buffer_info") = vk::ArrayProxyNoTemporaries<const vk::DescriptorBufferInfo>{}, py::arg("texel_buffer_view") = vk::ArrayProxyNoTemporaries<const vk::BufferView>{}, py::arg("p_next") = nullptr);

    s_vk_BindBufferMemoryDeviceGroupInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("device_indices"), py::arg("p_next") = nullptr);

    s_vk_BindBufferMemoryInfo.def(py::init<vk::Buffer, vk::DeviceMemory, vk::DeviceSize, const void *>(), py::arg("buffer") = vk::Buffer{}, py::arg("memory") = vk::DeviceMemory{}, py::arg("memory_offset") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_BindImageMemoryDeviceGroupInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const uint32_t> &, const vk::ArrayProxyNoTemporaries<const vk::Rect2D> &, const void *>(), py::arg("device_indices"), py::arg("split_instance_bind_regions") = vk::ArrayProxyNoTemporaries<const vk::Rect2D>{}, py::arg("p_next") = nullptr);

    s_vk_BindImageMemoryInfo.def(py::init<vk::Image, vk::DeviceMemory, vk::DeviceSize, const void *>(), py::arg("image") = vk::Image{}, py::arg("memory") = vk::DeviceMemory{}, py::arg("memory_offset") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_BindImagePlaneMemoryInfo.def(py::init<vk::ImageAspectFlagBits, const void *>(), py::arg("plane_aspect") = VULKAN_HPP_NAMESPACE::ImageAspectFlagBits::eColor, py::arg("p_next") = nullptr);

    s_vk_BufferMemoryRequirementsInfo2.def(py::init<vk::Buffer, const void *>(), py::arg("buffer") = vk::Buffer{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorSetLayoutSupport.def(py::init<vk::Bool32, void *>(), py::arg("supported") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorUpdateTemplateCreateInfo.def(py::init<vk::DescriptorUpdateTemplateCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::DescriptorUpdateTemplateEntry> &, vk::DescriptorUpdateTemplateType, vk::DescriptorSetLayout, vk::PipelineBindPoint, vk::PipelineLayout, uint32_t, const void *>(), py::arg("flags"), py::arg("descriptor_update_entries"), py::arg("template_type") = VULKAN_HPP_NAMESPACE::DescriptorUpdateTemplateType::eDescriptorSet, py::arg("descriptor_set_layout") = vk::DescriptorSetLayout{}, py::arg("pipeline_bind_point") = VULKAN_HPP_NAMESPACE::PipelineBindPoint::eGraphics, py::arg("pipeline_layout") = vk::PipelineLayout{}, py::arg("set") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorUpdateTemplateEntry.def(py::init<uint32_t, uint32_t, uint32_t, vk::DescriptorType, size_t, size_t>(), py::arg("dst_binding") = uint32_t{}, py::arg("dst_array_element") = uint32_t{}, py::arg("descriptor_count") = uint32_t{}, py::arg("descriptor_type") = VULKAN_HPP_NAMESPACE::DescriptorType::eSampler, py::arg("offset") = size_t{}, py::arg("stride") = size_t{});

    s_vk_DeviceGroupBindSparseInfo.def(py::init<uint32_t, uint32_t, const void *>(), py::arg("resource_device_index") = uint32_t{}, py::arg("memory_device_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DeviceGroupCommandBufferBeginInfo.def(py::init<uint32_t, const void *>(), py::arg("device_mask") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DeviceGroupDeviceCreateInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::PhysicalDevice> &, const void *>(), py::arg("physical_devices"), py::arg("p_next") = nullptr);

    s_vk_DeviceGroupRenderPassBeginInfo.def(py::init<uint32_t, const vk::ArrayProxyNoTemporaries<const vk::Rect2D> &, const void *>(), py::arg("device_mask"), py::arg("device_render_areas"), py::arg("p_next") = nullptr);

    s_vk_DeviceGroupSubmitInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const uint32_t> &, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("wait_semaphore_device_indices"), py::arg("command_buffer_device_masks") = vk::ArrayProxyNoTemporaries<const uint32_t>{}, py::arg("signal_semaphore_device_indices") = vk::ArrayProxyNoTemporaries<const uint32_t>{}, py::arg("p_next") = nullptr);

    s_vk_DeviceQueueInfo2.def(py::init<vk::DeviceQueueCreateFlags, uint32_t, uint32_t, const void *>(), py::arg("flags") = vk::DeviceQueueCreateFlags{}, py::arg("queue_family_index") = uint32_t{}, py::arg("queue_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_ExportFenceCreateInfo.def(py::init<vk::ExternalFenceHandleTypeFlags, const void *>(), py::arg("handle_types") = vk::ExternalFenceHandleTypeFlags{}, py::arg("p_next") = nullptr);

    s_vk_ExportMemoryAllocateInfo.def(py::init<vk::ExternalMemoryHandleTypeFlags, const void *>(), py::arg("handle_types") = vk::ExternalMemoryHandleTypeFlags{}, py::arg("p_next") = nullptr);

    s_vk_ExportSemaphoreCreateInfo.def(py::init<vk::ExternalSemaphoreHandleTypeFlags, const void *>(), py::arg("handle_types") = vk::ExternalSemaphoreHandleTypeFlags{}, py::arg("p_next") = nullptr);

    s_vk_ExternalBufferProperties.def(py::init<vk::ExternalMemoryProperties, void *>(), py::arg("external_memory_properties") = vk::ExternalMemoryProperties{}, py::arg("p_next") = nullptr);

    s_vk_ExternalFenceProperties.def(py::init<vk::ExternalFenceHandleTypeFlags, vk::ExternalFenceHandleTypeFlags, vk::ExternalFenceFeatureFlags, void *>(), py::arg("export_from_imported_handle_types") = vk::ExternalFenceHandleTypeFlags{}, py::arg("compatible_handle_types") = vk::ExternalFenceHandleTypeFlags{}, py::arg("external_fence_features") = vk::ExternalFenceFeatureFlags{}, py::arg("p_next") = nullptr);

    s_vk_ExternalImageFormatProperties.def(py::init<vk::ExternalMemoryProperties, void *>(), py::arg("external_memory_properties") = vk::ExternalMemoryProperties{}, py::arg("p_next") = nullptr);

    s_vk_ExternalMemoryBufferCreateInfo.def(py::init<vk::ExternalMemoryHandleTypeFlags, const void *>(), py::arg("handle_types") = vk::ExternalMemoryHandleTypeFlags{}, py::arg("p_next") = nullptr);

    s_vk_ExternalMemoryImageCreateInfo.def(py::init<vk::ExternalMemoryHandleTypeFlags, const void *>(), py::arg("handle_types") = vk::ExternalMemoryHandleTypeFlags{}, py::arg("p_next") = nullptr);

    s_vk_ExternalMemoryProperties.def(py::init<vk::ExternalMemoryFeatureFlags, vk::ExternalMemoryHandleTypeFlags, vk::ExternalMemoryHandleTypeFlags>(), py::arg("external_memory_features") = vk::ExternalMemoryFeatureFlags{}, py::arg("export_from_imported_handle_types") = vk::ExternalMemoryHandleTypeFlags{}, py::arg("compatible_handle_types") = vk::ExternalMemoryHandleTypeFlags{});

    s_vk_ExternalSemaphoreProperties.def(py::init<vk::ExternalSemaphoreHandleTypeFlags, vk::ExternalSemaphoreHandleTypeFlags, vk::ExternalSemaphoreFeatureFlags, void *>(), py::arg("export_from_imported_handle_types") = vk::ExternalSemaphoreHandleTypeFlags{}, py::arg("compatible_handle_types") = vk::ExternalSemaphoreHandleTypeFlags{}, py::arg("external_semaphore_features") = vk::ExternalSemaphoreFeatureFlags{}, py::arg("p_next") = nullptr);

    s_vk_FormatProperties2.def(py::init<vk::FormatProperties, void *>(), py::arg("format_properties") = vk::FormatProperties{}, py::arg("p_next") = nullptr);

    s_vk_ImageFormatProperties2.def(py::init<vk::ImageFormatProperties, void *>(), py::arg("image_format_properties") = vk::ImageFormatProperties{}, py::arg("p_next") = nullptr);

    s_vk_ImageMemoryRequirementsInfo2.def(py::init<vk::Image, const void *>(), py::arg("image") = vk::Image{}, py::arg("p_next") = nullptr);

    s_vk_ImagePlaneMemoryRequirementsInfo.def(py::init<vk::ImageAspectFlagBits, const void *>(), py::arg("plane_aspect") = VULKAN_HPP_NAMESPACE::ImageAspectFlagBits::eColor, py::arg("p_next") = nullptr);

    s_vk_ImageSparseMemoryRequirementsInfo2.def(py::init<vk::Image, const void *>(), py::arg("image") = vk::Image{}, py::arg("p_next") = nullptr);

    s_vk_ImageViewUsageCreateInfo.def(py::init<vk::ImageUsageFlags, const void *>(), py::arg("usage") = vk::ImageUsageFlags{}, py::arg("p_next") = nullptr);

    s_vk_InputAttachmentAspectReference.def(py::init<uint32_t, uint32_t, vk::ImageAspectFlags>(), py::arg("subpass") = uint32_t{}, py::arg("input_attachment_index") = uint32_t{}, py::arg("aspect_mask") = vk::ImageAspectFlags{});

    s_vk_MemoryAllocateFlagsInfo.def(py::init<vk::MemoryAllocateFlags, uint32_t, const void *>(), py::arg("flags") = vk::MemoryAllocateFlags{}, py::arg("device_mask") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_MemoryDedicatedAllocateInfo.def(py::init<vk::Image, vk::Buffer, const void *>(), py::arg("image") = vk::Image{}, py::arg("buffer") = vk::Buffer{}, py::arg("p_next") = nullptr);

    s_vk_MemoryDedicatedRequirements.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("prefers_dedicated_allocation") = vk::Bool32{}, py::arg("requires_dedicated_allocation") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_MemoryRequirements2.def(py::init<vk::MemoryRequirements, void *>(), py::arg("memory_requirements") = vk::MemoryRequirements{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevice16BitStorageFeatures.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("storage_buffer_16_bit_access") = vk::Bool32{}, py::arg("uniform_and_storage_buffer_16_bit_access") = vk::Bool32{}, py::arg("storage_push_constant_16") = vk::Bool32{}, py::arg("storage_input_output_16") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExternalBufferInfo.def(py::init<vk::BufferCreateFlags, vk::BufferUsageFlags, vk::ExternalMemoryHandleTypeFlagBits, const void *>(), py::arg("flags") = vk::BufferCreateFlags{}, py::arg("usage") = vk::BufferUsageFlags{}, py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalMemoryHandleTypeFlagBits::eOpaqueFd, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExternalFenceInfo.def(py::init<vk::ExternalFenceHandleTypeFlagBits, const void *>(), py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalFenceHandleTypeFlagBits::eOpaqueFd, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExternalImageFormatInfo.def(py::init<vk::ExternalMemoryHandleTypeFlagBits, const void *>(), py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalMemoryHandleTypeFlagBits::eOpaqueFd, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExternalSemaphoreInfo.def(py::init<vk::ExternalSemaphoreHandleTypeFlagBits, const void *>(), py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalSemaphoreHandleTypeFlagBits::eOpaqueFd, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFeatures2.def(py::init<vk::PhysicalDeviceFeatures, void *>(), py::arg("features") = vk::PhysicalDeviceFeatures{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceGroupProperties.def(py::init<uint32_t, const std::array<vk::PhysicalDevice, 32U> &, vk::Bool32, void *>(), py::arg("physical_device_count") = uint32_t{}, py::arg("physical_devices") = std::array<vk::PhysicalDevice, 32U>{}, py::arg("subset_allocation") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceIDProperties.def(py::init<const std::array<uint8_t, 16U> &, const std::array<uint8_t, 16U> &, const std::array<uint8_t, 8U> &, uint32_t, vk::Bool32, void *>(), py::arg("deviceUUID") = std::array<uint8_t, 16U>{}, py::arg("driverUUID") = std::array<uint8_t, 16U>{}, py::arg("deviceLUID") = std::array<uint8_t, 8U>{}, py::arg("device_node_mask") = uint32_t{}, py::arg("deviceLUID_valid") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageFormatInfo2.def(py::init<vk::Format, vk::ImageType, vk::ImageTiling, vk::ImageUsageFlags, vk::ImageCreateFlags, const void *>(), py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("type") = VULKAN_HPP_NAMESPACE::ImageType::e1D, py::arg("tiling") = VULKAN_HPP_NAMESPACE::ImageTiling::eOptimal, py::arg("usage") = vk::ImageUsageFlags{}, py::arg("flags") = vk::ImageCreateFlags{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMaintenance3Properties.def(py::init<uint32_t, vk::DeviceSize, void *>(), py::arg("max_per_set_descriptors") = uint32_t{}, py::arg("max_memory_allocation_size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMemoryProperties2.def(py::init<vk::PhysicalDeviceMemoryProperties, void *>(), py::arg("memory_properties") = vk::PhysicalDeviceMemoryProperties{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMultiviewFeatures.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("multiview") = vk::Bool32{}, py::arg("multiview_geometry_shader") = vk::Bool32{}, py::arg("multiview_tessellation_shader") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMultiviewProperties.def(py::init<uint32_t, uint32_t, void *>(), py::arg("max_multiview_view_count") = uint32_t{}, py::arg("max_multiview_instance_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePointClippingProperties.def(py::init<vk::PointClippingBehavior, void *>(), py::arg("point_clipping_behavior") = VULKAN_HPP_NAMESPACE::PointClippingBehavior::eAllClipPlanes, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceProperties2.def(py::init<vk::PhysicalDeviceProperties, void *>(), py::arg("properties") = vk::PhysicalDeviceProperties{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceProtectedMemoryFeatures.def(py::init<vk::Bool32, void *>(), py::arg("protected_memory") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceProtectedMemoryProperties.def(py::init<vk::Bool32, void *>(), py::arg("protected_no_fault") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSamplerYcbcrConversionFeatures.def(py::init<vk::Bool32, void *>(), py::arg("sampler_ycbcr_conversion") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderDrawParametersFeatures.def(py::init<vk::Bool32, void *>(), py::arg("shader_draw_parameters") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSparseImageFormatInfo2.def(py::init<vk::Format, vk::ImageType, vk::SampleCountFlagBits, vk::ImageUsageFlags, vk::ImageTiling, const void *>(), py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("type") = VULKAN_HPP_NAMESPACE::ImageType::e1D, py::arg("samples") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("usage") = vk::ImageUsageFlags{}, py::arg("tiling") = VULKAN_HPP_NAMESPACE::ImageTiling::eOptimal, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSubgroupProperties.def(py::init<uint32_t, vk::ShaderStageFlags, vk::SubgroupFeatureFlags, vk::Bool32, void *>(), py::arg("subgroup_size") = uint32_t{}, py::arg("supported_stages") = vk::ShaderStageFlags{}, py::arg("supported_operations") = vk::SubgroupFeatureFlags{}, py::arg("quad_operations_in_all_stages") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVariablePointersFeatures.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("variable_pointers_storage_buffer") = vk::Bool32{}, py::arg("variable_pointers") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineTessellationDomainOriginStateCreateInfo.def(py::init<vk::TessellationDomainOrigin, const void *>(), py::arg("domain_origin") = VULKAN_HPP_NAMESPACE::TessellationDomainOrigin::eUpperLeft, py::arg("p_next") = nullptr);

    s_vk_ProtectedSubmitInfo.def(py::init<vk::Bool32, const void *>(), py::arg("protected_submit") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_QueueFamilyProperties2.def(py::init<vk::QueueFamilyProperties, void *>(), py::arg("queue_family_properties") = vk::QueueFamilyProperties{}, py::arg("p_next") = nullptr);

    s_vk_RenderPassInputAttachmentAspectCreateInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::InputAttachmentAspectReference> &, const void *>(), py::arg("aspect_references"), py::arg("p_next") = nullptr);

    s_vk_RenderPassMultiviewCreateInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const uint32_t> &, const vk::ArrayProxyNoTemporaries<const int32_t> &, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("view_masks"), py::arg("view_offsets") = vk::ArrayProxyNoTemporaries<const int32_t>{}, py::arg("correlation_masks") = vk::ArrayProxyNoTemporaries<const uint32_t>{}, py::arg("p_next") = nullptr);

    s_vk_SamplerYcbcrConversionCreateInfo.def(py::init<vk::Format, vk::SamplerYcbcrModelConversion, vk::SamplerYcbcrRange, vk::ComponentMapping, vk::ChromaLocation, vk::ChromaLocation, vk::Filter, vk::Bool32, const void *>(), py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("ycbcr_model") = VULKAN_HPP_NAMESPACE::SamplerYcbcrModelConversion::eRgbIdentity, py::arg("ycbcr_range") = VULKAN_HPP_NAMESPACE::SamplerYcbcrRange::eItuFull, py::arg("components") = vk::ComponentMapping{}, py::arg("x_chroma_offset") = VULKAN_HPP_NAMESPACE::ChromaLocation::eCositedEven, py::arg("y_chroma_offset") = VULKAN_HPP_NAMESPACE::ChromaLocation::eCositedEven, py::arg("chroma_filter") = VULKAN_HPP_NAMESPACE::Filter::eNearest, py::arg("force_explicit_reconstruction") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SamplerYcbcrConversionImageFormatProperties.def(py::init<uint32_t, void *>(), py::arg("combined_image_sampler_descriptor_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_SamplerYcbcrConversionInfo.def(py::init<vk::SamplerYcbcrConversion, const void *>(), py::arg("conversion") = vk::SamplerYcbcrConversion{}, py::arg("p_next") = nullptr);

    s_vk_SparseImageFormatProperties2.def(py::init<vk::SparseImageFormatProperties, void *>(), py::arg("properties") = vk::SparseImageFormatProperties{}, py::arg("p_next") = nullptr);

    s_vk_SparseImageMemoryRequirements2.def(py::init<vk::SparseImageMemoryRequirements, void *>(), py::arg("memory_requirements") = vk::SparseImageMemoryRequirements{}, py::arg("p_next") = nullptr);

    s_vk_AttachmentDescription2.def(py::init<vk::AttachmentDescriptionFlags, vk::Format, vk::SampleCountFlagBits, vk::AttachmentLoadOp, vk::AttachmentStoreOp, vk::AttachmentLoadOp, vk::AttachmentStoreOp, vk::ImageLayout, vk::ImageLayout, const void *>(), py::arg("flags") = vk::AttachmentDescriptionFlags{}, py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("samples") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("load_op") = VULKAN_HPP_NAMESPACE::AttachmentLoadOp::eLoad, py::arg("store_op") = VULKAN_HPP_NAMESPACE::AttachmentStoreOp::eStore, py::arg("stencil_load_op") = VULKAN_HPP_NAMESPACE::AttachmentLoadOp::eLoad, py::arg("stencil_store_op") = VULKAN_HPP_NAMESPACE::AttachmentStoreOp::eStore, py::arg("initial_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("final_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("p_next") = nullptr);

    s_vk_AttachmentDescriptionStencilLayout.def(py::init<vk::ImageLayout, vk::ImageLayout, void *>(), py::arg("stencil_initial_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("stencil_final_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("p_next") = nullptr);

    s_vk_AttachmentReference2.def(py::init<uint32_t, vk::ImageLayout, vk::ImageAspectFlags, const void *>(), py::arg("attachment") = uint32_t{}, py::arg("layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("aspect_mask") = vk::ImageAspectFlags{}, py::arg("p_next") = nullptr);

    s_vk_AttachmentReferenceStencilLayout.def(py::init<vk::ImageLayout, void *>(), py::arg("stencil_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("p_next") = nullptr);

    s_vk_BufferDeviceAddressInfo.def(py::init<vk::Buffer, const void *>(), py::arg("buffer") = vk::Buffer{}, py::arg("p_next") = nullptr);

    s_vk_BufferOpaqueCaptureAddressCreateInfo.def(py::init<uint64_t, const void *>(), py::arg("opaque_capture_address") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_ConformanceVersion.def(py::init<uint8_t, uint8_t, uint8_t, uint8_t>(), py::arg("major") = uint8_t{}, py::arg("minor") = uint8_t{}, py::arg("subminor") = uint8_t{}, py::arg("patch") = uint8_t{});

    s_vk_DescriptorSetLayoutBindingFlagsCreateInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::DescriptorBindingFlags> &, const void *>(), py::arg("binding_flags"), py::arg("p_next") = nullptr);

    s_vk_DescriptorSetVariableDescriptorCountAllocateInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("descriptor_counts"), py::arg("p_next") = nullptr);

    s_vk_DescriptorSetVariableDescriptorCountLayoutSupport.def(py::init<uint32_t, void *>(), py::arg("max_variable_descriptor_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DeviceMemoryOpaqueCaptureAddressInfo.def(py::init<vk::DeviceMemory, const void *>(), py::arg("memory") = vk::DeviceMemory{}, py::arg("p_next") = nullptr);

    s_vk_FramebufferAttachmentImageInfo.def(py::init<vk::ImageCreateFlags, vk::ImageUsageFlags, uint32_t, uint32_t, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::Format> &, const void *>(), py::arg("flags"), py::arg("usage"), py::arg("width"), py::arg("height"), py::arg("layer_count"), py::arg("view_formats"), py::arg("p_next") = nullptr);

    s_vk_FramebufferAttachmentsCreateInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::FramebufferAttachmentImageInfo> &, const void *>(), py::arg("attachment_image_infos"), py::arg("p_next") = nullptr);

    s_vk_ImageFormatListCreateInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Format> &, const void *>(), py::arg("view_formats"), py::arg("p_next") = nullptr);

    s_vk_ImageStencilUsageCreateInfo.def(py::init<vk::ImageUsageFlags, const void *>(), py::arg("stencil_usage") = vk::ImageUsageFlags{}, py::arg("p_next") = nullptr);

    s_vk_MemoryOpaqueCaptureAddressAllocateInfo.def(py::init<uint64_t, const void *>(), py::arg("opaque_capture_address") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevice8BitStorageFeatures.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("storage_buffer_8_bit_access") = vk::Bool32{}, py::arg("uniform_and_storage_buffer_8_bit_access") = vk::Bool32{}, py::arg("storage_push_constant_8") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceBufferDeviceAddressFeatures.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("buffer_device_address") = vk::Bool32{}, py::arg("buffer_device_address_capture_replay") = vk::Bool32{}, py::arg("buffer_device_address_multi_device") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDepthStencilResolveProperties.def(py::init<vk::ResolveModeFlags, vk::ResolveModeFlags, vk::Bool32, vk::Bool32, void *>(), py::arg("supported_depth_resolve_modes") = vk::ResolveModeFlags{}, py::arg("supported_stencil_resolve_modes") = vk::ResolveModeFlags{}, py::arg("independent_resolve_none") = vk::Bool32{}, py::arg("independent_resolve") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDescriptorIndexingFeatures.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("shader_input_attachment_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_uniform_texel_buffer_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_storage_texel_buffer_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_uniform_buffer_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_sampled_image_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_storage_buffer_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_storage_image_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_input_attachment_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_uniform_texel_buffer_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_storage_texel_buffer_array_non_uniform_indexing") = vk::Bool32{}, py::arg("descriptor_binding_uniform_buffer_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_sampled_image_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_storage_image_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_storage_buffer_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_uniform_texel_buffer_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_storage_texel_buffer_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_update_unused_while_pending") = vk::Bool32{}, py::arg("descriptor_binding_partially_bound") = vk::Bool32{}, py::arg("descriptor_binding_variable_descriptor_count") = vk::Bool32{}, py::arg("runtime_descriptor_array") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDescriptorIndexingProperties.def(py::init<uint32_t, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void *>(), py::arg("max_update_after_bind_descriptors_in_all_pools") = uint32_t{}, py::arg("shader_uniform_buffer_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("shader_sampled_image_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("shader_storage_buffer_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("shader_storage_image_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("shader_input_attachment_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("robust_buffer_access_update_after_bind") = vk::Bool32{}, py::arg("quad_divergent_implicit_lod") = vk::Bool32{}, py::arg("max_per_stage_descriptor_update_after_bind_samplers") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_uniform_buffers") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_storage_buffers") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_sampled_images") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_storage_images") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_input_attachments") = uint32_t{}, py::arg("max_per_stage_update_after_bind_resources") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_samplers") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_uniform_buffers") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_uniform_buffers_dynamic") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_storage_buffers") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_storage_buffers_dynamic") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_sampled_images") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_storage_images") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_input_attachments") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDriverProperties.def(py::init<vk::DriverId, const std::array<char, 256U> &, const std::array<char, 256U> &, vk::ConformanceVersion, void *>(), py::arg("driverID") = VULKAN_HPP_NAMESPACE::DriverId::eAmdProprietary, py::arg("driver_name") = std::array<char, 256U>{}, py::arg("driver_info") = std::array<char, 256U>{}, py::arg("conformance_version") = vk::ConformanceVersion{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFloatControlsProperties.def(py::init<vk::ShaderFloatControlsIndependence, vk::ShaderFloatControlsIndependence, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("denorm_behavior_independence") = VULKAN_HPP_NAMESPACE::ShaderFloatControlsIndependence::e32BitOnly, py::arg("rounding_mode_independence") = VULKAN_HPP_NAMESPACE::ShaderFloatControlsIndependence::e32BitOnly, py::arg("shader_signed_zero_inf_nan_preserve_float_16") = vk::Bool32{}, py::arg("shader_signed_zero_inf_nan_preserve_float_32") = vk::Bool32{}, py::arg("shader_signed_zero_inf_nan_preserve_float_64") = vk::Bool32{}, py::arg("shader_denorm_preserve_float_16") = vk::Bool32{}, py::arg("shader_denorm_preserve_float_32") = vk::Bool32{}, py::arg("shader_denorm_preserve_float_64") = vk::Bool32{}, py::arg("shader_denorm_flush_to_zero_float_16") = vk::Bool32{}, py::arg("shader_denorm_flush_to_zero_float_32") = vk::Bool32{}, py::arg("shader_denorm_flush_to_zero_float_64") = vk::Bool32{}, py::arg("shader_rounding_mode_RTE_float_16") = vk::Bool32{}, py::arg("shader_rounding_mode_RTE_float_32") = vk::Bool32{}, py::arg("shader_rounding_mode_RTE_float_64") = vk::Bool32{}, py::arg("shader_rounding_mode_RTZ_float_16") = vk::Bool32{}, py::arg("shader_rounding_mode_RTZ_float_32") = vk::Bool32{}, py::arg("shader_rounding_mode_RTZ_float_64") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceHostQueryResetFeatures.def(py::init<vk::Bool32, void *>(), py::arg("host_query_reset") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImagelessFramebufferFeatures.def(py::init<vk::Bool32, void *>(), py::arg("imageless_framebuffer") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSamplerFilterMinmaxProperties.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("filter_minmax_single_component_formats") = vk::Bool32{}, py::arg("filter_minmax_image_component_mapping") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceScalarBlockLayoutFeatures.def(py::init<vk::Bool32, void *>(), py::arg("scalar_block_layout") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSeparateDepthStencilLayoutsFeatures.def(py::init<vk::Bool32, void *>(), py::arg("separate_depth_stencil_layouts") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderAtomicInt64Features.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("shader_buffer_int_64_atomics") = vk::Bool32{}, py::arg("shader_shared_int_64_atomics") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderFloat16Int8Features.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("shader_float_16") = vk::Bool32{}, py::arg("shader_int_8") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderSubgroupExtendedTypesFeatures.def(py::init<vk::Bool32, void *>(), py::arg("shader_subgroup_extended_types") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceTimelineSemaphoreFeatures.def(py::init<vk::Bool32, void *>(), py::arg("timeline_semaphore") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceTimelineSemaphoreProperties.def(py::init<uint64_t, void *>(), py::arg("max_timeline_semaphore_value_difference") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceUniformBufferStandardLayoutFeatures.def(py::init<vk::Bool32, void *>(), py::arg("uniform_buffer_standard_layout") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVulkan11Features.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("storage_buffer_16_bit_access") = vk::Bool32{}, py::arg("uniform_and_storage_buffer_16_bit_access") = vk::Bool32{}, py::arg("storage_push_constant_16") = vk::Bool32{}, py::arg("storage_input_output_16") = vk::Bool32{}, py::arg("multiview") = vk::Bool32{}, py::arg("multiview_geometry_shader") = vk::Bool32{}, py::arg("multiview_tessellation_shader") = vk::Bool32{}, py::arg("variable_pointers_storage_buffer") = vk::Bool32{}, py::arg("variable_pointers") = vk::Bool32{}, py::arg("protected_memory") = vk::Bool32{}, py::arg("sampler_ycbcr_conversion") = vk::Bool32{}, py::arg("shader_draw_parameters") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVulkan11Properties.def(py::init<const std::array<uint8_t, 16U> &, const std::array<uint8_t, 16U> &, const std::array<uint8_t, 8U> &, uint32_t, vk::Bool32, uint32_t, vk::ShaderStageFlags, vk::SubgroupFeatureFlags, vk::Bool32, vk::PointClippingBehavior, uint32_t, uint32_t, vk::Bool32, uint32_t, vk::DeviceSize, void *>(), py::arg("deviceUUID") = std::array<uint8_t, 16U>{}, py::arg("driverUUID") = std::array<uint8_t, 16U>{}, py::arg("deviceLUID") = std::array<uint8_t, 8U>{}, py::arg("device_node_mask") = uint32_t{}, py::arg("deviceLUID_valid") = vk::Bool32{}, py::arg("subgroup_size") = uint32_t{}, py::arg("subgroup_supported_stages") = vk::ShaderStageFlags{}, py::arg("subgroup_supported_operations") = vk::SubgroupFeatureFlags{}, py::arg("subgroup_quad_operations_in_all_stages") = vk::Bool32{}, py::arg("point_clipping_behavior") = VULKAN_HPP_NAMESPACE::PointClippingBehavior::eAllClipPlanes, py::arg("max_multiview_view_count") = uint32_t{}, py::arg("max_multiview_instance_index") = uint32_t{}, py::arg("protected_no_fault") = vk::Bool32{}, py::arg("max_per_set_descriptors") = uint32_t{}, py::arg("max_memory_allocation_size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVulkan12Features.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("sampler_mirror_clamp_to_edge") = vk::Bool32{}, py::arg("draw_indirect_count") = vk::Bool32{}, py::arg("storage_buffer_8_bit_access") = vk::Bool32{}, py::arg("uniform_and_storage_buffer_8_bit_access") = vk::Bool32{}, py::arg("storage_push_constant_8") = vk::Bool32{}, py::arg("shader_buffer_int_64_atomics") = vk::Bool32{}, py::arg("shader_shared_int_64_atomics") = vk::Bool32{}, py::arg("shader_float_16") = vk::Bool32{}, py::arg("shader_int_8") = vk::Bool32{}, py::arg("descriptor_indexing") = vk::Bool32{}, py::arg("shader_input_attachment_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_uniform_texel_buffer_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_storage_texel_buffer_array_dynamic_indexing") = vk::Bool32{}, py::arg("shader_uniform_buffer_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_sampled_image_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_storage_buffer_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_storage_image_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_input_attachment_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_uniform_texel_buffer_array_non_uniform_indexing") = vk::Bool32{}, py::arg("shader_storage_texel_buffer_array_non_uniform_indexing") = vk::Bool32{}, py::arg("descriptor_binding_uniform_buffer_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_sampled_image_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_storage_image_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_storage_buffer_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_uniform_texel_buffer_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_storage_texel_buffer_update_after_bind") = vk::Bool32{}, py::arg("descriptor_binding_update_unused_while_pending") = vk::Bool32{}, py::arg("descriptor_binding_partially_bound") = vk::Bool32{}, py::arg("descriptor_binding_variable_descriptor_count") = vk::Bool32{}, py::arg("runtime_descriptor_array") = vk::Bool32{}, py::arg("sampler_filter_minmax") = vk::Bool32{}, py::arg("scalar_block_layout") = vk::Bool32{}, py::arg("imageless_framebuffer") = vk::Bool32{}, py::arg("uniform_buffer_standard_layout") = vk::Bool32{}, py::arg("shader_subgroup_extended_types") = vk::Bool32{}, py::arg("separate_depth_stencil_layouts") = vk::Bool32{}, py::arg("host_query_reset") = vk::Bool32{}, py::arg("timeline_semaphore") = vk::Bool32{}, py::arg("buffer_device_address") = vk::Bool32{}, py::arg("buffer_device_address_capture_replay") = vk::Bool32{}, py::arg("buffer_device_address_multi_device") = vk::Bool32{}, py::arg("vulkan_memory_model") = vk::Bool32{}, py::arg("vulkan_memory_model_device_scope") = vk::Bool32{}, py::arg("vulkan_memory_model_availability_visibility_chains") = vk::Bool32{}, py::arg("shader_output_viewport_index") = vk::Bool32{}, py::arg("shader_output_layer") = vk::Bool32{}, py::arg("subgroup_broadcast_dynamic_id") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVulkan12Properties.def(py::init<vk::DriverId, const std::array<char, 256U> &, const std::array<char, 256U> &, vk::ConformanceVersion, vk::ShaderFloatControlsIndependence, vk::ShaderFloatControlsIndependence, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, uint32_t, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, vk::ResolveModeFlags, vk::ResolveModeFlags, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, uint64_t, vk::SampleCountFlags, void *>(), py::arg("driverID") = VULKAN_HPP_NAMESPACE::DriverId::eAmdProprietary, py::arg("driver_name") = std::array<char, 256U>{}, py::arg("driver_info") = std::array<char, 256U>{}, py::arg("conformance_version") = vk::ConformanceVersion{}, py::arg("denorm_behavior_independence") = VULKAN_HPP_NAMESPACE::ShaderFloatControlsIndependence::e32BitOnly, py::arg("rounding_mode_independence") = VULKAN_HPP_NAMESPACE::ShaderFloatControlsIndependence::e32BitOnly, py::arg("shader_signed_zero_inf_nan_preserve_float_16") = vk::Bool32{}, py::arg("shader_signed_zero_inf_nan_preserve_float_32") = vk::Bool32{}, py::arg("shader_signed_zero_inf_nan_preserve_float_64") = vk::Bool32{}, py::arg("shader_denorm_preserve_float_16") = vk::Bool32{}, py::arg("shader_denorm_preserve_float_32") = vk::Bool32{}, py::arg("shader_denorm_preserve_float_64") = vk::Bool32{}, py::arg("shader_denorm_flush_to_zero_float_16") = vk::Bool32{}, py::arg("shader_denorm_flush_to_zero_float_32") = vk::Bool32{}, py::arg("shader_denorm_flush_to_zero_float_64") = vk::Bool32{}, py::arg("shader_rounding_mode_RTE_float_16") = vk::Bool32{}, py::arg("shader_rounding_mode_RTE_float_32") = vk::Bool32{}, py::arg("shader_rounding_mode_RTE_float_64") = vk::Bool32{}, py::arg("shader_rounding_mode_RTZ_float_16") = vk::Bool32{}, py::arg("shader_rounding_mode_RTZ_float_32") = vk::Bool32{}, py::arg("shader_rounding_mode_RTZ_float_64") = vk::Bool32{}, py::arg("max_update_after_bind_descriptors_in_all_pools") = uint32_t{}, py::arg("shader_uniform_buffer_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("shader_sampled_image_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("shader_storage_buffer_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("shader_storage_image_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("shader_input_attachment_array_non_uniform_indexing_native") = vk::Bool32{}, py::arg("robust_buffer_access_update_after_bind") = vk::Bool32{}, py::arg("quad_divergent_implicit_lod") = vk::Bool32{}, py::arg("max_per_stage_descriptor_update_after_bind_samplers") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_uniform_buffers") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_storage_buffers") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_sampled_images") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_storage_images") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_input_attachments") = uint32_t{}, py::arg("max_per_stage_update_after_bind_resources") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_samplers") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_uniform_buffers") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_uniform_buffers_dynamic") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_storage_buffers") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_storage_buffers_dynamic") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_sampled_images") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_storage_images") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_input_attachments") = uint32_t{}, py::arg("supported_depth_resolve_modes") = vk::ResolveModeFlags{}, py::arg("supported_stencil_resolve_modes") = vk::ResolveModeFlags{}, py::arg("independent_resolve_none") = vk::Bool32{}, py::arg("independent_resolve") = vk::Bool32{}, py::arg("filter_minmax_single_component_formats") = vk::Bool32{}, py::arg("filter_minmax_image_component_mapping") = vk::Bool32{}, py::arg("max_timeline_semaphore_value_difference") = uint64_t{}, py::arg("framebuffer_integer_color_sample_counts") = vk::SampleCountFlags{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVulkanMemoryModelFeatures.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("vulkan_memory_model") = vk::Bool32{}, py::arg("vulkan_memory_model_device_scope") = vk::Bool32{}, py::arg("vulkan_memory_model_availability_visibility_chains") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_RenderPassAttachmentBeginInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::ImageView> &, const void *>(), py::arg("attachments"), py::arg("p_next") = nullptr);

    s_vk_RenderPassCreateInfo2.def(py::init<vk::RenderPassCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::AttachmentDescription2> &, const vk::ArrayProxyNoTemporaries<const vk::SubpassDescription2> &, const vk::ArrayProxyNoTemporaries<const vk::SubpassDependency2> &, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("flags"), py::arg("attachments"), py::arg("subpasses") = vk::ArrayProxyNoTemporaries<const vk::SubpassDescription2>{}, py::arg("dependencies") = vk::ArrayProxyNoTemporaries<const vk::SubpassDependency2>{}, py::arg("correlated_view_masks") = vk::ArrayProxyNoTemporaries<const uint32_t>{}, py::arg("p_next") = nullptr);

    s_vk_SamplerReductionModeCreateInfo.def(py::init<vk::SamplerReductionMode, const void *>(), py::arg("reduction_mode") = VULKAN_HPP_NAMESPACE::SamplerReductionMode::eWeightedAverage, py::arg("p_next") = nullptr);

    s_vk_SemaphoreSignalInfo.def(py::init<vk::Semaphore, uint64_t, const void *>(), py::arg("semaphore") = vk::Semaphore{}, py::arg("value") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_SemaphoreTypeCreateInfo.def(py::init<vk::SemaphoreType, uint64_t, const void *>(), py::arg("semaphore_type") = VULKAN_HPP_NAMESPACE::SemaphoreType::eBinary, py::arg("initial_value") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_SemaphoreWaitInfo.def(py::init<vk::SemaphoreWaitFlags, const vk::ArrayProxyNoTemporaries<const vk::Semaphore> &, const vk::ArrayProxyNoTemporaries<const uint64_t> &, const void *>(), py::arg("flags"), py::arg("semaphores"), py::arg("values") = vk::ArrayProxyNoTemporaries<const uint64_t>{}, py::arg("p_next") = nullptr);

    s_vk_SubpassBeginInfo.def(py::init<vk::SubpassContents, const void *>(), py::arg("contents") = VULKAN_HPP_NAMESPACE::SubpassContents::eInline, py::arg("p_next") = nullptr);

    s_vk_SubpassDependency2.def(py::init<uint32_t, uint32_t, vk::PipelineStageFlags, vk::PipelineStageFlags, vk::AccessFlags, vk::AccessFlags, vk::DependencyFlags, int32_t, const void *>(), py::arg("src_subpass") = uint32_t{}, py::arg("dst_subpass") = uint32_t{}, py::arg("src_stage_mask") = vk::PipelineStageFlags{}, py::arg("dst_stage_mask") = vk::PipelineStageFlags{}, py::arg("src_access_mask") = vk::AccessFlags{}, py::arg("dst_access_mask") = vk::AccessFlags{}, py::arg("dependency_flags") = vk::DependencyFlags{}, py::arg("view_offset") = int32_t{}, py::arg("p_next") = nullptr);

    s_vk_SubpassDescription2.def(py::init<vk::SubpassDescriptionFlags, vk::PipelineBindPoint, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::AttachmentReference2> &, const vk::ArrayProxyNoTemporaries<const vk::AttachmentReference2> &, const vk::ArrayProxyNoTemporaries<const vk::AttachmentReference2> &, const vk::AttachmentReference2 *, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("flags"), py::arg("pipeline_bind_point"), py::arg("view_mask"), py::arg("input_attachments"), py::arg("color_attachments") = vk::ArrayProxyNoTemporaries<const vk::AttachmentReference2>{}, py::arg("resolve_attachments") = vk::ArrayProxyNoTemporaries<const vk::AttachmentReference2>{}, py::arg("p_depth_stencil_attachment") = nullptr, py::arg("preserve_attachments") = vk::ArrayProxyNoTemporaries<const uint32_t>{}, py::arg("p_next") = nullptr);

    s_vk_SubpassDescriptionDepthStencilResolve.def(py::init<vk::ResolveModeFlagBits, vk::ResolveModeFlagBits, const vk::AttachmentReference2 *, const void *>(), py::arg("depth_resolve_mode") = VULKAN_HPP_NAMESPACE::ResolveModeFlagBits::eNone, py::arg("stencil_resolve_mode") = VULKAN_HPP_NAMESPACE::ResolveModeFlagBits::eNone, py::arg("p_depth_stencil_resolve_attachment") = nullptr, py::arg("p_next") = nullptr);

    s_vk_SubpassEndInfo.def(py::init<const void *>(), py::arg("p_next") = nullptr);

    s_vk_TimelineSemaphoreSubmitInfo.def(py::init<const vk::ArrayProxyNoTemporaries<const uint64_t> &, const vk::ArrayProxyNoTemporaries<const uint64_t> &, const void *>(), py::arg("wait_semaphore_values"), py::arg("signal_semaphore_values") = vk::ArrayProxyNoTemporaries<const uint64_t>{}, py::arg("p_next") = nullptr);

    s_vk_BlitImageInfo2.def(py::init<vk::Image, vk::ImageLayout, vk::Image, vk::ImageLayout, const vk::ArrayProxyNoTemporaries<const vk::ImageBlit2> &, vk::Filter, const void *>(), py::arg("src_image"), py::arg("src_image_layout"), py::arg("dst_image"), py::arg("dst_image_layout"), py::arg("regions"), py::arg("filter") = VULKAN_HPP_NAMESPACE::Filter::eNearest, py::arg("p_next") = nullptr);

    s_vk_BufferCopy2.def(py::init<vk::DeviceSize, vk::DeviceSize, vk::DeviceSize, const void *>(), py::arg("src_offset") = vk::DeviceSize{}, py::arg("dst_offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_BufferImageCopy2.def(py::init<vk::DeviceSize, uint32_t, uint32_t, vk::ImageSubresourceLayers, vk::Offset3D, vk::Extent3D, const void *>(), py::arg("buffer_offset") = vk::DeviceSize{}, py::arg("buffer_row_length") = uint32_t{}, py::arg("buffer_image_height") = uint32_t{}, py::arg("image_subresource") = vk::ImageSubresourceLayers{}, py::arg("image_offset") = vk::Offset3D{}, py::arg("image_extent") = vk::Extent3D{}, py::arg("p_next") = nullptr);

    s_vk_BufferMemoryBarrier2.def(py::init<vk::PipelineStageFlags2, vk::AccessFlags2, vk::PipelineStageFlags2, vk::AccessFlags2, uint32_t, uint32_t, vk::Buffer, vk::DeviceSize, vk::DeviceSize, const void *>(), py::arg("src_stage_mask") = vk::PipelineStageFlags2{}, py::arg("src_access_mask") = vk::AccessFlags2{}, py::arg("dst_stage_mask") = vk::PipelineStageFlags2{}, py::arg("dst_access_mask") = vk::AccessFlags2{}, py::arg("src_queue_family_index") = uint32_t{}, py::arg("dst_queue_family_index") = uint32_t{}, py::arg("buffer") = vk::Buffer{}, py::arg("offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_CommandBufferInheritanceRenderingInfo.def(py::init<vk::RenderingFlags, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::Format> &, vk::Format, vk::Format, vk::SampleCountFlagBits, const void *>(), py::arg("flags"), py::arg("view_mask"), py::arg("color_attachment_formats"), py::arg("depth_attachment_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("stencil_attachment_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("rasterization_samples") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("p_next") = nullptr);

    s_vk_CommandBufferSubmitInfo.def(py::init<vk::CommandBuffer, uint32_t, const void *>(), py::arg("command_buffer") = vk::CommandBuffer{}, py::arg("device_mask") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_CopyBufferInfo2.def(py::init<vk::Buffer, vk::Buffer, const vk::ArrayProxyNoTemporaries<const vk::BufferCopy2> &, const void *>(), py::arg("src_buffer"), py::arg("dst_buffer"), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_CopyBufferToImageInfo2.def(py::init<vk::Buffer, vk::Image, vk::ImageLayout, const vk::ArrayProxyNoTemporaries<const vk::BufferImageCopy2> &, const void *>(), py::arg("src_buffer"), py::arg("dst_image"), py::arg("dst_image_layout"), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_CopyImageInfo2.def(py::init<vk::Image, vk::ImageLayout, vk::Image, vk::ImageLayout, const vk::ArrayProxyNoTemporaries<const vk::ImageCopy2> &, const void *>(), py::arg("src_image"), py::arg("src_image_layout"), py::arg("dst_image"), py::arg("dst_image_layout"), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_CopyImageToBufferInfo2.def(py::init<vk::Image, vk::ImageLayout, vk::Buffer, const vk::ArrayProxyNoTemporaries<const vk::BufferImageCopy2> &, const void *>(), py::arg("src_image"), py::arg("src_image_layout"), py::arg("dst_buffer"), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_DependencyInfo.def(py::init<vk::DependencyFlags, const vk::ArrayProxyNoTemporaries<const vk::MemoryBarrier2> &, const vk::ArrayProxyNoTemporaries<const vk::BufferMemoryBarrier2> &, const vk::ArrayProxyNoTemporaries<const vk::ImageMemoryBarrier2> &, const void *>(), py::arg("dependency_flags"), py::arg("memory_barriers"), py::arg("buffer_memory_barriers") = vk::ArrayProxyNoTemporaries<const vk::BufferMemoryBarrier2>{}, py::arg("image_memory_barriers") = vk::ArrayProxyNoTemporaries<const vk::ImageMemoryBarrier2>{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorPoolInlineUniformBlockCreateInfo.def(py::init<uint32_t, const void *>(), py::arg("max_inline_uniform_block_bindings") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DeviceBufferMemoryRequirements.def(py::init<const vk::BufferCreateInfo *, const void *>(), py::arg("p_create_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_DeviceImageMemoryRequirements.def(py::init<const vk::ImageCreateInfo *, vk::ImageAspectFlagBits, const void *>(), py::arg("p_create_info") = nullptr, py::arg("plane_aspect") = VULKAN_HPP_NAMESPACE::ImageAspectFlagBits::eColor, py::arg("p_next") = nullptr);

    s_vk_DevicePrivateDataCreateInfo.def(py::init<uint32_t, const void *>(), py::arg("private_data_slot_request_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_FormatProperties3.def(py::init<vk::FormatFeatureFlags2, vk::FormatFeatureFlags2, vk::FormatFeatureFlags2, void *>(), py::arg("linear_tiling_features") = vk::FormatFeatureFlags2{}, py::arg("optimal_tiling_features") = vk::FormatFeatureFlags2{}, py::arg("buffer_features") = vk::FormatFeatureFlags2{}, py::arg("p_next") = nullptr);

    s_vk_ImageBlit2.def(py::init<vk::ImageSubresourceLayers, const std::array<vk::Offset3D, 2> &, vk::ImageSubresourceLayers, const std::array<vk::Offset3D, 2> &, const void *>(), py::arg("src_subresource") = vk::ImageSubresourceLayers{}, py::arg("src_offsets") = std::array<vk::Offset3D, 2>{}, py::arg("dst_subresource") = vk::ImageSubresourceLayers{}, py::arg("dst_offsets") = std::array<vk::Offset3D, 2>{}, py::arg("p_next") = nullptr);

    s_vk_ImageCopy2.def(py::init<vk::ImageSubresourceLayers, vk::Offset3D, vk::ImageSubresourceLayers, vk::Offset3D, vk::Extent3D, const void *>(), py::arg("src_subresource") = vk::ImageSubresourceLayers{}, py::arg("src_offset") = vk::Offset3D{}, py::arg("dst_subresource") = vk::ImageSubresourceLayers{}, py::arg("dst_offset") = vk::Offset3D{}, py::arg("extent") = vk::Extent3D{}, py::arg("p_next") = nullptr);

    s_vk_ImageMemoryBarrier2.def(py::init<vk::PipelineStageFlags2, vk::AccessFlags2, vk::PipelineStageFlags2, vk::AccessFlags2, vk::ImageLayout, vk::ImageLayout, uint32_t, uint32_t, vk::Image, vk::ImageSubresourceRange, const void *>(), py::arg("src_stage_mask") = vk::PipelineStageFlags2{}, py::arg("src_access_mask") = vk::AccessFlags2{}, py::arg("dst_stage_mask") = vk::PipelineStageFlags2{}, py::arg("dst_access_mask") = vk::AccessFlags2{}, py::arg("old_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("new_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("src_queue_family_index") = uint32_t{}, py::arg("dst_queue_family_index") = uint32_t{}, py::arg("image") = vk::Image{}, py::arg("subresource_range") = vk::ImageSubresourceRange{}, py::arg("p_next") = nullptr);

    s_vk_ImageResolve2.def(py::init<vk::ImageSubresourceLayers, vk::Offset3D, vk::ImageSubresourceLayers, vk::Offset3D, vk::Extent3D, const void *>(), py::arg("src_subresource") = vk::ImageSubresourceLayers{}, py::arg("src_offset") = vk::Offset3D{}, py::arg("dst_subresource") = vk::ImageSubresourceLayers{}, py::arg("dst_offset") = vk::Offset3D{}, py::arg("extent") = vk::Extent3D{}, py::arg("p_next") = nullptr);

    s_vk_MemoryBarrier2.def(py::init<vk::PipelineStageFlags2, vk::AccessFlags2, vk::PipelineStageFlags2, vk::AccessFlags2, const void *>(), py::arg("src_stage_mask") = vk::PipelineStageFlags2{}, py::arg("src_access_mask") = vk::AccessFlags2{}, py::arg("dst_stage_mask") = vk::PipelineStageFlags2{}, py::arg("dst_access_mask") = vk::AccessFlags2{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDynamicRenderingFeatures.def(py::init<vk::Bool32, void *>(), py::arg("dynamic_rendering") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageRobustnessFeatures.def(py::init<vk::Bool32, void *>(), py::arg("robust_image_access") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceInlineUniformBlockFeatures.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("inline_uniform_block") = vk::Bool32{}, py::arg("descriptor_binding_inline_uniform_block_update_after_bind") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceInlineUniformBlockProperties.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void *>(), py::arg("max_inline_uniform_block_size") = uint32_t{}, py::arg("max_per_stage_descriptor_inline_uniform_blocks") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_inline_uniform_blocks") = uint32_t{}, py::arg("max_descriptor_set_inline_uniform_blocks") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_inline_uniform_blocks") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMaintenance4Features.def(py::init<vk::Bool32, void *>(), py::arg("maintenance4") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMaintenance4Properties.def(py::init<vk::DeviceSize, void *>(), py::arg("max_buffer_size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePipelineCreationCacheControlFeatures.def(py::init<vk::Bool32, void *>(), py::arg("pipeline_creation_cache_control") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePrivateDataFeatures.def(py::init<vk::Bool32, void *>(), py::arg("private_data") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderDemoteToHelperInvocationFeatures.def(py::init<vk::Bool32, void *>(), py::arg("shader_demote_to_helper_invocation") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderIntegerDotProductFeatures.def(py::init<vk::Bool32, void *>(), py::arg("shader_integer_dot_product") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderIntegerDotProductProperties.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("integer_dot_product_8_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_8_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_8_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_4x8_bit_packed_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_4x8_bit_packed_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_4x8_bit_packed_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_16_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_16_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_16_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_32_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_32_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_32_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_64_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_64_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_64_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_8_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_8_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_8_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_4x8_bit_packed_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_4x8_bit_packed_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_4x8_bit_packed_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_16_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_16_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_16_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_32_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_32_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_32_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_64_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_64_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_64_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderTerminateInvocationFeatures.def(py::init<vk::Bool32, void *>(), py::arg("shader_terminate_invocation") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSubgroupSizeControlFeatures.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("subgroup_size_control") = vk::Bool32{}, py::arg("compute_full_subgroups") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSubgroupSizeControlProperties.def(py::init<uint32_t, uint32_t, uint32_t, vk::ShaderStageFlags, void *>(), py::arg("min_subgroup_size") = uint32_t{}, py::arg("max_subgroup_size") = uint32_t{}, py::arg("max_compute_workgroup_subgroups") = uint32_t{}, py::arg("required_subgroup_size_stages") = vk::ShaderStageFlags{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSynchronization2Features.def(py::init<vk::Bool32, void *>(), py::arg("synchronization2") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceTexelBufferAlignmentProperties.def(py::init<vk::DeviceSize, vk::Bool32, vk::DeviceSize, vk::Bool32, void *>(), py::arg("storage_texel_buffer_offset_alignment_bytes") = vk::DeviceSize{}, py::arg("storage_texel_buffer_offset_single_texel_alignment") = vk::Bool32{}, py::arg("uniform_texel_buffer_offset_alignment_bytes") = vk::DeviceSize{}, py::arg("uniform_texel_buffer_offset_single_texel_alignment") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceTextureCompressionASTCHDRFeatures.def(py::init<vk::Bool32, void *>(), py::arg("texture_compression_ASTC_HDR") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceToolProperties.def(py::init<const std::array<char, 256U> &, const std::array<char, 256U> &, vk::ToolPurposeFlags, const std::array<char, 256U> &, const std::array<char, 256U> &, void *>(), py::arg("name") = std::array<char, 256U>{}, py::arg("version") = std::array<char, 256U>{}, py::arg("purposes") = vk::ToolPurposeFlags{}, py::arg("description") = std::array<char, 256U>{}, py::arg("layer") = std::array<char, 256U>{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVulkan13Features.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("robust_image_access") = vk::Bool32{}, py::arg("inline_uniform_block") = vk::Bool32{}, py::arg("descriptor_binding_inline_uniform_block_update_after_bind") = vk::Bool32{}, py::arg("pipeline_creation_cache_control") = vk::Bool32{}, py::arg("private_data") = vk::Bool32{}, py::arg("shader_demote_to_helper_invocation") = vk::Bool32{}, py::arg("shader_terminate_invocation") = vk::Bool32{}, py::arg("subgroup_size_control") = vk::Bool32{}, py::arg("compute_full_subgroups") = vk::Bool32{}, py::arg("synchronization2") = vk::Bool32{}, py::arg("texture_compression_ASTC_HDR") = vk::Bool32{}, py::arg("shader_zero_initialize_workgroup_memory") = vk::Bool32{}, py::arg("dynamic_rendering") = vk::Bool32{}, py::arg("shader_integer_dot_product") = vk::Bool32{}, py::arg("maintenance4") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVulkan13Properties.def(py::init<uint32_t, uint32_t, uint32_t, vk::ShaderStageFlags, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::DeviceSize, vk::Bool32, vk::DeviceSize, vk::Bool32, vk::DeviceSize, void *>(), py::arg("min_subgroup_size") = uint32_t{}, py::arg("max_subgroup_size") = uint32_t{}, py::arg("max_compute_workgroup_subgroups") = uint32_t{}, py::arg("required_subgroup_size_stages") = vk::ShaderStageFlags{}, py::arg("max_inline_uniform_block_size") = uint32_t{}, py::arg("max_per_stage_descriptor_inline_uniform_blocks") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_inline_uniform_blocks") = uint32_t{}, py::arg("max_descriptor_set_inline_uniform_blocks") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_inline_uniform_blocks") = uint32_t{}, py::arg("max_inline_uniform_total_size") = uint32_t{}, py::arg("integer_dot_product_8_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_8_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_8_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_4x8_bit_packed_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_4x8_bit_packed_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_4x8_bit_packed_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_16_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_16_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_16_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_32_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_32_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_32_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_64_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_64_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_64_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_8_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_8_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_8_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_4x8_bit_packed_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_4x8_bit_packed_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_4x8_bit_packed_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_16_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_16_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_16_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_32_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_32_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_32_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_64_bit_unsigned_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_64_bit_signed_accelerated") = vk::Bool32{}, py::arg("integer_dot_product_accumulating_saturating_64_bit_mixed_signedness_accelerated") = vk::Bool32{}, py::arg("storage_texel_buffer_offset_alignment_bytes") = vk::DeviceSize{}, py::arg("storage_texel_buffer_offset_single_texel_alignment") = vk::Bool32{}, py::arg("uniform_texel_buffer_offset_alignment_bytes") = vk::DeviceSize{}, py::arg("uniform_texel_buffer_offset_single_texel_alignment") = vk::Bool32{}, py::arg("max_buffer_size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures.def(py::init<vk::Bool32, void *>(), py::arg("shader_zero_initialize_workgroup_memory") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineCreationFeedback.def(py::init<vk::PipelineCreationFeedbackFlags, uint64_t>(), py::arg("flags") = vk::PipelineCreationFeedbackFlags{}, py::arg("duration") = uint64_t{});

    s_vk_PipelineCreationFeedbackCreateInfo.def(py::init<vk::PipelineCreationFeedback *, const vk::ArrayProxyNoTemporaries<vk::PipelineCreationFeedback> &, const void *>(), py::arg("p_pipeline_creation_feedback"), py::arg("pipeline_stage_creation_feedbacks"), py::arg("p_next") = nullptr);

    s_vk_PipelineRenderingCreateInfo.def(py::init<uint32_t, const vk::ArrayProxyNoTemporaries<const vk::Format> &, vk::Format, vk::Format, const void *>(), py::arg("view_mask"), py::arg("color_attachment_formats"), py::arg("depth_attachment_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("stencil_attachment_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("p_next") = nullptr);

    s_vk_PipelineShaderStageRequiredSubgroupSizeCreateInfo.def(py::init<uint32_t, void *>(), py::arg("required_subgroup_size") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PrivateDataSlotCreateInfo.def(py::init<vk::PrivateDataSlotCreateFlags, const void *>(), py::arg("flags") = vk::PrivateDataSlotCreateFlags{}, py::arg("p_next") = nullptr);

    s_vk_RenderingAttachmentInfo.def(py::init<vk::ImageView, vk::ImageLayout, vk::ResolveModeFlagBits, vk::ImageView, vk::ImageLayout, vk::AttachmentLoadOp, vk::AttachmentStoreOp, vk::ClearValue, const void *>(), py::arg("image_view") = vk::ImageView{}, py::arg("image_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("resolve_mode") = VULKAN_HPP_NAMESPACE::ResolveModeFlagBits::eNone, py::arg("resolve_image_view") = vk::ImageView{}, py::arg("resolve_image_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("load_op") = VULKAN_HPP_NAMESPACE::AttachmentLoadOp::eLoad, py::arg("store_op") = VULKAN_HPP_NAMESPACE::AttachmentStoreOp::eStore, py::arg("clear_value") = vk::ClearValue{}, py::arg("p_next") = nullptr);

    s_vk_RenderingInfo.def(py::init<vk::RenderingFlags, vk::Rect2D, uint32_t, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::RenderingAttachmentInfo> &, const vk::RenderingAttachmentInfo *, const vk::RenderingAttachmentInfo *, const void *>(), py::arg("flags"), py::arg("render_area"), py::arg("layer_count"), py::arg("view_mask"), py::arg("color_attachments"), py::arg("p_depth_attachment") = nullptr, py::arg("p_stencil_attachment") = nullptr, py::arg("p_next") = nullptr);

    s_vk_ResolveImageInfo2.def(py::init<vk::Image, vk::ImageLayout, vk::Image, vk::ImageLayout, const vk::ArrayProxyNoTemporaries<const vk::ImageResolve2> &, const void *>(), py::arg("src_image"), py::arg("src_image_layout"), py::arg("dst_image"), py::arg("dst_image_layout"), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_SemaphoreSubmitInfo.def(py::init<vk::Semaphore, uint64_t, vk::PipelineStageFlags2, uint32_t, const void *>(), py::arg("semaphore") = vk::Semaphore{}, py::arg("value") = uint64_t{}, py::arg("stage_mask") = vk::PipelineStageFlags2{}, py::arg("device_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_SubmitInfo2.def(py::init<vk::SubmitFlags, const vk::ArrayProxyNoTemporaries<const vk::SemaphoreSubmitInfo> &, const vk::ArrayProxyNoTemporaries<const vk::CommandBufferSubmitInfo> &, const vk::ArrayProxyNoTemporaries<const vk::SemaphoreSubmitInfo> &, const void *>(), py::arg("flags"), py::arg("wait_semaphore_infos"), py::arg("command_buffer_infos") = vk::ArrayProxyNoTemporaries<const vk::CommandBufferSubmitInfo>{}, py::arg("signal_semaphore_infos") = vk::ArrayProxyNoTemporaries<const vk::SemaphoreSubmitInfo>{}, py::arg("p_next") = nullptr);

    s_vk_WriteDescriptorSetInlineUniformBlock.def(py::init<uint32_t, const void *, const void *>(), py::arg("data_size") = uint32_t{}, py::arg("p_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_SurfaceCapabilitiesKHR.def(py::init<uint32_t, uint32_t, vk::Extent2D, vk::Extent2D, vk::Extent2D, uint32_t, vk::SurfaceTransformFlagsKHR, vk::SurfaceTransformFlagBitsKHR, vk::CompositeAlphaFlagsKHR, vk::ImageUsageFlags>(), py::arg("min_image_count") = uint32_t{}, py::arg("max_image_count") = uint32_t{}, py::arg("current_extent") = vk::Extent2D{}, py::arg("min_image_extent") = vk::Extent2D{}, py::arg("max_image_extent") = vk::Extent2D{}, py::arg("max_image_array_layers") = uint32_t{}, py::arg("supported_transforms") = vk::SurfaceTransformFlagsKHR{}, py::arg("current_transform") = VULKAN_HPP_NAMESPACE::SurfaceTransformFlagBitsKHR::eIdentity, py::arg("supported_composite_alpha") = vk::CompositeAlphaFlagsKHR{}, py::arg("supported_usage_flags") = vk::ImageUsageFlags{});

    s_vk_SurfaceFormatKHR.def(py::init<vk::Format, vk::ColorSpaceKHR>(), py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("color_space") = VULKAN_HPP_NAMESPACE::ColorSpaceKHR::eSrgbNonlinear);

    s_vk_AcquireNextImageInfoKHR.def(py::init<vk::SwapchainKHR, uint64_t, vk::Semaphore, vk::Fence, uint32_t, const void *>(), py::arg("swapchain") = vk::SwapchainKHR{}, py::arg("timeout") = uint64_t{}, py::arg("semaphore") = vk::Semaphore{}, py::arg("fence") = vk::Fence{}, py::arg("device_mask") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_BindImageMemorySwapchainInfoKHR.def(py::init<vk::SwapchainKHR, uint32_t, const void *>(), py::arg("swapchain") = vk::SwapchainKHR{}, py::arg("image_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DeviceGroupPresentCapabilitiesKHR.def(py::init<const std::array<uint32_t, 32U> &, vk::DeviceGroupPresentModeFlagsKHR, void *>(), py::arg("present_mask") = std::array<uint32_t, 32U>{}, py::arg("modes") = vk::DeviceGroupPresentModeFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_DeviceGroupPresentInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const uint32_t> &, vk::DeviceGroupPresentModeFlagBitsKHR, const void *>(), py::arg("device_masks"), py::arg("mode") = VULKAN_HPP_NAMESPACE::DeviceGroupPresentModeFlagBitsKHR::eLocal, py::arg("p_next") = nullptr);

    s_vk_DeviceGroupSwapchainCreateInfoKHR.def(py::init<vk::DeviceGroupPresentModeFlagsKHR, const void *>(), py::arg("modes") = vk::DeviceGroupPresentModeFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_ImageSwapchainCreateInfoKHR.def(py::init<vk::SwapchainKHR, const void *>(), py::arg("swapchain") = vk::SwapchainKHR{}, py::arg("p_next") = nullptr);

    s_vk_PresentInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Semaphore> &, const vk::ArrayProxyNoTemporaries<const vk::SwapchainKHR> &, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const vk::ArrayProxyNoTemporaries<vk::Result> &, const void *>(), py::arg("wait_semaphores"), py::arg("swapchains") = vk::ArrayProxyNoTemporaries<const vk::SwapchainKHR>{}, py::arg("image_indices") = vk::ArrayProxyNoTemporaries<const uint32_t>{}, py::arg("results") = vk::ArrayProxyNoTemporaries<vk::Result>{}, py::arg("p_next") = nullptr);

    s_vk_SwapchainCreateInfoKHR.def(py::init<vk::SwapchainCreateFlagsKHR, vk::SurfaceKHR, uint32_t, vk::Format, vk::ColorSpaceKHR, vk::Extent2D, uint32_t, vk::ImageUsageFlags, vk::SharingMode, const vk::ArrayProxyNoTemporaries<const uint32_t> &, vk::SurfaceTransformFlagBitsKHR, vk::CompositeAlphaFlagBitsKHR, vk::PresentModeKHR, vk::Bool32, vk::SwapchainKHR, const void *>(), py::arg("flags"), py::arg("surface"), py::arg("min_image_count"), py::arg("image_format"), py::arg("image_color_space"), py::arg("image_extent"), py::arg("image_array_layers"), py::arg("image_usage"), py::arg("image_sharing_mode"), py::arg("queue_family_indices"), py::arg("pre_transform") = VULKAN_HPP_NAMESPACE::SurfaceTransformFlagBitsKHR::eIdentity, py::arg("composite_alpha") = VULKAN_HPP_NAMESPACE::CompositeAlphaFlagBitsKHR::eOpaque, py::arg("present_mode") = VULKAN_HPP_NAMESPACE::PresentModeKHR::eImmediate, py::arg("clipped") = vk::Bool32{}, py::arg("old_swapchain") = vk::SwapchainKHR{}, py::arg("p_next") = nullptr);

    s_vk_DisplayModeCreateInfoKHR.def(py::init<vk::DisplayModeCreateFlagsKHR, vk::DisplayModeParametersKHR, const void *>(), py::arg("flags") = vk::DisplayModeCreateFlagsKHR{}, py::arg("parameters") = vk::DisplayModeParametersKHR{}, py::arg("p_next") = nullptr);

    s_vk_DisplayModeParametersKHR.def(py::init<vk::Extent2D, uint32_t>(), py::arg("visible_region") = vk::Extent2D{}, py::arg("refresh_rate") = uint32_t{});

    s_vk_DisplayModePropertiesKHR.def(py::init<vk::DisplayModeKHR, vk::DisplayModeParametersKHR>(), py::arg("display_mode") = vk::DisplayModeKHR{}, py::arg("parameters") = vk::DisplayModeParametersKHR{});

    s_vk_DisplayPlaneCapabilitiesKHR.def(py::init<vk::DisplayPlaneAlphaFlagsKHR, vk::Offset2D, vk::Offset2D, vk::Extent2D, vk::Extent2D, vk::Offset2D, vk::Offset2D, vk::Extent2D, vk::Extent2D>(), py::arg("supported_alpha") = vk::DisplayPlaneAlphaFlagsKHR{}, py::arg("min_src_position") = vk::Offset2D{}, py::arg("max_src_position") = vk::Offset2D{}, py::arg("min_src_extent") = vk::Extent2D{}, py::arg("max_src_extent") = vk::Extent2D{}, py::arg("min_dst_position") = vk::Offset2D{}, py::arg("max_dst_position") = vk::Offset2D{}, py::arg("min_dst_extent") = vk::Extent2D{}, py::arg("max_dst_extent") = vk::Extent2D{});

    s_vk_DisplayPlanePropertiesKHR.def(py::init<vk::DisplayKHR, uint32_t>(), py::arg("current_display") = vk::DisplayKHR{}, py::arg("current_stack_index") = uint32_t{});

    s_vk_DisplayPropertiesKHR.def(py::init<vk::DisplayKHR, const char *, vk::Extent2D, vk::Extent2D, vk::SurfaceTransformFlagsKHR, vk::Bool32, vk::Bool32>(), py::arg("display") = vk::DisplayKHR{}, py::arg("display_name") = nullptr, py::arg("physical_dimensions") = vk::Extent2D{}, py::arg("physical_resolution") = vk::Extent2D{}, py::arg("supported_transforms") = vk::SurfaceTransformFlagsKHR{}, py::arg("plane_reorder_possible") = vk::Bool32{}, py::arg("persistent_content") = vk::Bool32{});

    s_vk_DisplaySurfaceCreateInfoKHR.def(py::init<vk::DisplaySurfaceCreateFlagsKHR, vk::DisplayModeKHR, uint32_t, uint32_t, vk::SurfaceTransformFlagBitsKHR, float, vk::DisplayPlaneAlphaFlagBitsKHR, vk::Extent2D, const void *>(), py::arg("flags") = vk::DisplaySurfaceCreateFlagsKHR{}, py::arg("display_mode") = vk::DisplayModeKHR{}, py::arg("plane_index") = uint32_t{}, py::arg("plane_stack_index") = uint32_t{}, py::arg("transform") = VULKAN_HPP_NAMESPACE::SurfaceTransformFlagBitsKHR::eIdentity, py::arg("global_alpha") = float{}, py::arg("alpha_mode") = VULKAN_HPP_NAMESPACE::DisplayPlaneAlphaFlagBitsKHR::eOpaque, py::arg("image_extent") = vk::Extent2D{}, py::arg("p_next") = nullptr);

    s_vk_DisplayPresentInfoKHR.def(py::init<vk::Rect2D, vk::Rect2D, vk::Bool32, const void *>(), py::arg("src_rect") = vk::Rect2D{}, py::arg("dst_rect") = vk::Rect2D{}, py::arg("persistent") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_DebugReportCallbackCreateInfoEXT.def(py::init<vk::DebugReportFlagsEXT, PFN_vkDebugReportCallbackEXT, void *, const void *>(), py::arg("flags") = vk::DebugReportFlagsEXT{}, py::arg("pfn_callback") = PFN_vkDebugReportCallbackEXT{}, py::arg("p_user_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PipelineRasterizationStateRasterizationOrderAMD.def(py::init<vk::RasterizationOrderAMD, const void *>(), py::arg("rasterization_order") = VULKAN_HPP_NAMESPACE::RasterizationOrderAMD::eStrict, py::arg("p_next") = nullptr);

    s_vk_DebugMarkerMarkerInfoEXT.def(py::init<const char *, const std::array<float, 4> &, const void *>(), py::arg("p_marker_name") = nullptr, py::arg("color") = std::array<float, 4>{}, py::arg("p_next") = nullptr);

    s_vk_DebugMarkerObjectNameInfoEXT.def(py::init<vk::DebugReportObjectTypeEXT, uint64_t, const char *, const void *>(), py::arg("object_type") = VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT::eUnknown, py::arg("object") = uint64_t{}, py::arg("p_object_name") = nullptr, py::arg("p_next") = nullptr);

    s_vk_DebugMarkerObjectTagInfoEXT.def(py::init<vk::DebugReportObjectTypeEXT, uint64_t, uint64_t, size_t, const void *, const void *>(), py::arg("object_type") = VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT::eUnknown, py::arg("object") = uint64_t{}, py::arg("tag_name") = uint64_t{}, py::arg("tag_size") = size_t{}, py::arg("p_tag") = nullptr, py::arg("p_next") = nullptr);

    s_vk_BindVideoSessionMemoryInfoKHR.def(py::init<uint32_t, vk::DeviceMemory, vk::DeviceSize, vk::DeviceSize, const void *>(), py::arg("memory_bind_index") = uint32_t{}, py::arg("memory") = vk::DeviceMemory{}, py::arg("memory_offset") = vk::DeviceSize{}, py::arg("memory_size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVideoFormatInfoKHR.def(py::init<vk::ImageUsageFlags, const void *>(), py::arg("image_usage") = vk::ImageUsageFlags{}, py::arg("p_next") = nullptr);

    s_vk_QueueFamilyQueryResultStatusPropertiesKHR.def(py::init<vk::Bool32, void *>(), py::arg("query_result_status_support") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_QueueFamilyVideoPropertiesKHR.def(py::init<vk::VideoCodecOperationFlagsKHR, void *>(), py::arg("video_codec_operations") = vk::VideoCodecOperationFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoBeginCodingInfoKHR.def(py::init<vk::VideoBeginCodingFlagsKHR, vk::VideoSessionKHR, vk::VideoSessionParametersKHR, const vk::ArrayProxyNoTemporaries<const vk::VideoReferenceSlotInfoKHR> &, const void *>(), py::arg("flags"), py::arg("video_session"), py::arg("video_session_parameters"), py::arg("reference_slots"), py::arg("p_next") = nullptr);

    s_vk_VideoCapabilitiesKHR.def(py::init<vk::VideoCapabilityFlagsKHR, vk::DeviceSize, vk::DeviceSize, vk::Extent2D, vk::Extent2D, vk::Extent2D, uint32_t, uint32_t, vk::ExtensionProperties, void *>(), py::arg("flags") = vk::VideoCapabilityFlagsKHR{}, py::arg("min_bitstream_buffer_offset_alignment") = vk::DeviceSize{}, py::arg("min_bitstream_buffer_size_alignment") = vk::DeviceSize{}, py::arg("picture_access_granularity") = vk::Extent2D{}, py::arg("min_coded_extent") = vk::Extent2D{}, py::arg("max_coded_extent") = vk::Extent2D{}, py::arg("max_dpb_slots") = uint32_t{}, py::arg("max_active_reference_pictures") = uint32_t{}, py::arg("std_header_version") = vk::ExtensionProperties{}, py::arg("p_next") = nullptr);

    s_vk_VideoCodingControlInfoKHR.def(py::init<vk::VideoCodingControlFlagsKHR, const void *>(), py::arg("flags") = vk::VideoCodingControlFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoEndCodingInfoKHR.def(py::init<vk::VideoEndCodingFlagsKHR, const void *>(), py::arg("flags") = vk::VideoEndCodingFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoFormatPropertiesKHR.def(py::init<vk::Format, vk::ComponentMapping, vk::ImageCreateFlags, vk::ImageType, vk::ImageTiling, vk::ImageUsageFlags, void *>(), py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("component_mapping") = vk::ComponentMapping{}, py::arg("image_create_flags") = vk::ImageCreateFlags{}, py::arg("image_type") = VULKAN_HPP_NAMESPACE::ImageType::e1D, py::arg("image_tiling") = VULKAN_HPP_NAMESPACE::ImageTiling::eOptimal, py::arg("image_usage_flags") = vk::ImageUsageFlags{}, py::arg("p_next") = nullptr);

    s_vk_VideoPictureResourceInfoKHR.def(py::init<vk::Offset2D, vk::Extent2D, uint32_t, vk::ImageView, const void *>(), py::arg("coded_offset") = vk::Offset2D{}, py::arg("coded_extent") = vk::Extent2D{}, py::arg("base_array_layer") = uint32_t{}, py::arg("image_view_binding") = vk::ImageView{}, py::arg("p_next") = nullptr);

    s_vk_VideoProfileInfoKHR.def(py::init<vk::VideoCodecOperationFlagBitsKHR, vk::VideoChromaSubsamplingFlagsKHR, vk::VideoComponentBitDepthFlagsKHR, vk::VideoComponentBitDepthFlagsKHR, const void *>(), py::arg("video_codec_operation") = VULKAN_HPP_NAMESPACE::VideoCodecOperationFlagBitsKHR::eNone, py::arg("chroma_subsampling") = vk::VideoChromaSubsamplingFlagsKHR{}, py::arg("luma_bit_depth") = vk::VideoComponentBitDepthFlagsKHR{}, py::arg("chroma_bit_depth") = vk::VideoComponentBitDepthFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoProfileListInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::VideoProfileInfoKHR> &, const void *>(), py::arg("profiles"), py::arg("p_next") = nullptr);

    s_vk_VideoReferenceSlotInfoKHR.def(py::init<int32_t, const vk::VideoPictureResourceInfoKHR *, const void *>(), py::arg("slot_index") = int32_t{}, py::arg("p_picture_resource") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoSessionCreateInfoKHR.def(py::init<uint32_t, vk::VideoSessionCreateFlagsKHR, const vk::VideoProfileInfoKHR *, vk::Format, vk::Extent2D, vk::Format, uint32_t, uint32_t, const vk::ExtensionProperties *, const void *>(), py::arg("queue_family_index") = uint32_t{}, py::arg("flags") = vk::VideoSessionCreateFlagsKHR{}, py::arg("p_video_profile") = nullptr, py::arg("picture_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("max_coded_extent") = vk::Extent2D{}, py::arg("reference_picture_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("max_dpb_slots") = uint32_t{}, py::arg("max_active_reference_pictures") = uint32_t{}, py::arg("p_std_header_version") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoSessionMemoryRequirementsKHR.def(py::init<uint32_t, vk::MemoryRequirements, void *>(), py::arg("memory_bind_index") = uint32_t{}, py::arg("memory_requirements") = vk::MemoryRequirements{}, py::arg("p_next") = nullptr);

    s_vk_VideoSessionParametersCreateInfoKHR.def(py::init<vk::VideoSessionParametersCreateFlagsKHR, vk::VideoSessionParametersKHR, vk::VideoSessionKHR, const void *>(), py::arg("flags") = vk::VideoSessionParametersCreateFlagsKHR{}, py::arg("video_session_parameters_template") = vk::VideoSessionParametersKHR{}, py::arg("video_session") = vk::VideoSessionKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoSessionParametersUpdateInfoKHR.def(py::init<uint32_t, const void *>(), py::arg("update_sequence_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeCapabilitiesKHR.def(py::init<vk::VideoDecodeCapabilityFlagsKHR, void *>(), py::arg("flags") = vk::VideoDecodeCapabilityFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeInfoKHR.def(py::init<vk::VideoDecodeFlagsKHR, vk::Buffer, vk::DeviceSize, vk::DeviceSize, vk::VideoPictureResourceInfoKHR, const vk::VideoReferenceSlotInfoKHR *, const vk::ArrayProxyNoTemporaries<const vk::VideoReferenceSlotInfoKHR> &, const void *>(), py::arg("flags"), py::arg("src_buffer"), py::arg("src_buffer_offset"), py::arg("src_buffer_range"), py::arg("dst_picture_resource"), py::arg("p_setup_reference_slot"), py::arg("reference_slots"), py::arg("p_next") = nullptr);

    s_vk_VideoDecodeUsageInfoKHR.def(py::init<vk::VideoDecodeUsageFlagsKHR, const void *>(), py::arg("video_usage_hints") = vk::VideoDecodeUsageFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_DedicatedAllocationBufferCreateInfoNV.def(py::init<vk::Bool32, const void *>(), py::arg("dedicated_allocation") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_DedicatedAllocationImageCreateInfoNV.def(py::init<vk::Bool32, const void *>(), py::arg("dedicated_allocation") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_DedicatedAllocationMemoryAllocateInfoNV.def(py::init<vk::Image, vk::Buffer, const void *>(), py::arg("image") = vk::Image{}, py::arg("buffer") = vk::Buffer{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceTransformFeedbackFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("transform_feedback") = vk::Bool32{}, py::arg("geometry_streams") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceTransformFeedbackPropertiesEXT.def(py::init<uint32_t, uint32_t, vk::DeviceSize, uint32_t, uint32_t, uint32_t, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("max_transform_feedback_streams") = uint32_t{}, py::arg("max_transform_feedback_buffers") = uint32_t{}, py::arg("max_transform_feedback_buffer_size") = vk::DeviceSize{}, py::arg("max_transform_feedback_stream_data_size") = uint32_t{}, py::arg("max_transform_feedback_buffer_data_size") = uint32_t{}, py::arg("max_transform_feedback_buffer_data_stride") = uint32_t{}, py::arg("transform_feedback_queries") = vk::Bool32{}, py::arg("transform_feedback_streams_lines_triangles") = vk::Bool32{}, py::arg("transform_feedback_rasterization_stream_select") = vk::Bool32{}, py::arg("transform_feedback_draw") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineRasterizationStateStreamCreateInfoEXT.def(py::init<vk::PipelineRasterizationStateStreamCreateFlagsEXT, uint32_t, const void *>(), py::arg("flags") = vk::PipelineRasterizationStateStreamCreateFlagsEXT{}, py::arg("rasterization_stream") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_CuFunctionCreateInfoNVX.def(py::init<vk::CuModuleNVX, const char *, const void *>(), py::arg("module") = vk::CuModuleNVX{}, py::arg("p_name") = nullptr, py::arg("p_next") = nullptr);

    s_vk_CuLaunchInfoNVX.def(py::init<vk::CuFunctionNVX, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, const vk::ArrayProxyNoTemporaries<const void *const> &, const vk::ArrayProxyNoTemporaries<const void *const> &, const void *>(), py::arg("function"), py::arg("grid_dim_x"), py::arg("grid_dim_y"), py::arg("grid_dim_z"), py::arg("block_dim_x"), py::arg("block_dim_y"), py::arg("block_dim_z"), py::arg("shared_mem_bytes"), py::arg("params"), py::arg("extras") = vk::ArrayProxyNoTemporaries<const void *const>{}, py::arg("p_next") = nullptr);

    s_vk_CuModuleCreateInfoNVX.def(py::init<size_t, const void *, const void *>(), py::arg("data_size") = size_t{}, py::arg("p_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_ImageViewAddressPropertiesNVX.def(py::init<vk::DeviceAddress, vk::DeviceSize, void *>(), py::arg("device_address") = vk::DeviceAddress{}, py::arg("size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_ImageViewHandleInfoNVX.def(py::init<vk::ImageView, vk::DescriptorType, vk::Sampler, const void *>(), py::arg("image_view") = vk::ImageView{}, py::arg("descriptor_type") = VULKAN_HPP_NAMESPACE::DescriptorType::eSampler, py::arg("sampler") = vk::Sampler{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264CapabilitiesKHR.def(py::init<vk::VideoEncodeH264CapabilityFlagsKHR, StdVideoH264LevelIdc, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, vk::Bool32, int32_t, int32_t, vk::Bool32, vk::Bool32, vk::VideoEncodeH264StdFlagsKHR, void *>(), py::arg("flags") = vk::VideoEncodeH264CapabilityFlagsKHR{}, py::arg("max_level_idc") = StdVideoH264LevelIdc{}, py::arg("max_slice_count") = uint32_t{}, py::arg("maxP_picture_l0_reference_count") = uint32_t{}, py::arg("maxB_picture_l0_reference_count") = uint32_t{}, py::arg("maxL1_reference_count") = uint32_t{}, py::arg("max_temporal_layer_count") = uint32_t{}, py::arg("expect_dyadic_temporal_layer_pattern") = vk::Bool32{}, py::arg("min_qp") = int32_t{}, py::arg("max_qp") = int32_t{}, py::arg("prefers_gop_remaining_frames") = vk::Bool32{}, py::arg("requires_gop_remaining_frames") = vk::Bool32{}, py::arg("std_syntax_flags") = vk::VideoEncodeH264StdFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264DpbSlotInfoKHR.def(py::init<const StdVideoEncodeH264ReferenceInfo *, const void *>(), py::arg("p_std_reference_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264FrameSizeKHR.def(py::init<uint32_t, uint32_t, uint32_t>(), py::arg("frameI_size") = uint32_t{}, py::arg("frameP_size") = uint32_t{}, py::arg("frameB_size") = uint32_t{});

    s_vk_VideoEncodeH264GopRemainingFrameInfoKHR.def(py::init<vk::Bool32, uint32_t, uint32_t, uint32_t, const void *>(), py::arg("use_gop_remaining_frames") = vk::Bool32{}, py::arg("gop_remaining_i") = uint32_t{}, py::arg("gop_remaining_p") = uint32_t{}, py::arg("gop_remaining_b") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264NaluSliceInfoKHR.def(py::init<int32_t, const StdVideoEncodeH264SliceHeader *, const void *>(), py::arg("constant_qp") = int32_t{}, py::arg("p_std_slice_header") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264PictureInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::VideoEncodeH264NaluSliceInfoKHR> &, const StdVideoEncodeH264PictureInfo *, vk::Bool32, const void *>(), py::arg("nalu_slice_entries"), py::arg("p_std_picture_info") = nullptr, py::arg("generate_prefix_nalu") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264ProfileInfoKHR.def(py::init<StdVideoH264ProfileIdc, const void *>(), py::arg("std_profile_idc") = StdVideoH264ProfileIdc{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264QpKHR.def(py::init<int32_t, int32_t, int32_t>(), py::arg("qpI") = int32_t{}, py::arg("qpP") = int32_t{}, py::arg("qpB") = int32_t{});

    s_vk_VideoEncodeH264QualityLevelPropertiesKHR.def(py::init<vk::VideoEncodeH264RateControlFlagsKHR, uint32_t, uint32_t, uint32_t, uint32_t, vk::VideoEncodeH264QpKHR, uint32_t, uint32_t, vk::Bool32, void *>(), py::arg("preferred_rate_control_flags") = vk::VideoEncodeH264RateControlFlagsKHR{}, py::arg("preferred_gop_frame_count") = uint32_t{}, py::arg("preferred_idr_period") = uint32_t{}, py::arg("preferred_consecutive_b_frame_count") = uint32_t{}, py::arg("preferred_temporal_layer_count") = uint32_t{}, py::arg("preferred_constant_qp") = vk::VideoEncodeH264QpKHR{}, py::arg("preferred_max_l0_reference_count") = uint32_t{}, py::arg("preferred_max_l1_reference_count") = uint32_t{}, py::arg("preferred_std_entropy_coding_mode_flag") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264RateControlInfoKHR.def(py::init<vk::VideoEncodeH264RateControlFlagsKHR, uint32_t, uint32_t, uint32_t, uint32_t, const void *>(), py::arg("flags") = vk::VideoEncodeH264RateControlFlagsKHR{}, py::arg("gop_frame_count") = uint32_t{}, py::arg("idr_period") = uint32_t{}, py::arg("consecutiveB_frame_count") = uint32_t{}, py::arg("temporal_layer_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264RateControlLayerInfoKHR.def(py::init<vk::Bool32, vk::VideoEncodeH264QpKHR, vk::Bool32, vk::VideoEncodeH264QpKHR, vk::Bool32, vk::VideoEncodeH264FrameSizeKHR, const void *>(), py::arg("use_min_qp") = vk::Bool32{}, py::arg("min_qp") = vk::VideoEncodeH264QpKHR{}, py::arg("use_max_qp") = vk::Bool32{}, py::arg("max_qp") = vk::VideoEncodeH264QpKHR{}, py::arg("use_max_frame_size") = vk::Bool32{}, py::arg("max_frame_size") = vk::VideoEncodeH264FrameSizeKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264SessionCreateInfoKHR.def(py::init<vk::Bool32, StdVideoH264LevelIdc, const void *>(), py::arg("use_max_level_idc") = vk::Bool32{}, py::arg("max_level_idc") = StdVideoH264LevelIdc{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264SessionParametersAddInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const StdVideoH264SequenceParameterSet> &, const vk::ArrayProxyNoTemporaries<const StdVideoH264PictureParameterSet> &, const void *>(), py::arg("stdSP_ss"), py::arg("stdPP_ss") = vk::ArrayProxyNoTemporaries<const StdVideoH264PictureParameterSet>{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264SessionParametersCreateInfoKHR.def(py::init<uint32_t, uint32_t, const vk::VideoEncodeH264SessionParametersAddInfoKHR *, const void *>(), py::arg("max_std_SPS_count") = uint32_t{}, py::arg("max_std_PPS_count") = uint32_t{}, py::arg("p_parameters_add_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264SessionParametersFeedbackInfoKHR.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("has_std_SPS_overrides") = vk::Bool32{}, py::arg("has_std_PPS_overrides") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH264SessionParametersGetInfoKHR.def(py::init<vk::Bool32, vk::Bool32, uint32_t, uint32_t, const void *>(), py::arg("write_std_SPS") = vk::Bool32{}, py::arg("write_std_PPS") = vk::Bool32{}, py::arg("stdSPS_id") = uint32_t{}, py::arg("stdPPS_id") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265CapabilitiesKHR.def(py::init<vk::VideoEncodeH265CapabilityFlagsKHR, StdVideoH265LevelIdc, uint32_t, vk::Extent2D, vk::VideoEncodeH265CtbSizeFlagsKHR, vk::VideoEncodeH265TransformBlockSizeFlagsKHR, uint32_t, uint32_t, uint32_t, uint32_t, vk::Bool32, int32_t, int32_t, vk::Bool32, vk::Bool32, vk::VideoEncodeH265StdFlagsKHR, void *>(), py::arg("flags") = vk::VideoEncodeH265CapabilityFlagsKHR{}, py::arg("max_level_idc") = StdVideoH265LevelIdc{}, py::arg("max_slice_segment_count") = uint32_t{}, py::arg("max_tiles") = vk::Extent2D{}, py::arg("ctb_sizes") = vk::VideoEncodeH265CtbSizeFlagsKHR{}, py::arg("transform_block_sizes") = vk::VideoEncodeH265TransformBlockSizeFlagsKHR{}, py::arg("maxP_picture_l0_reference_count") = uint32_t{}, py::arg("maxB_picture_l0_reference_count") = uint32_t{}, py::arg("maxL1_reference_count") = uint32_t{}, py::arg("max_sub_layer_count") = uint32_t{}, py::arg("expect_dyadic_temporal_sub_layer_pattern") = vk::Bool32{}, py::arg("min_qp") = int32_t{}, py::arg("max_qp") = int32_t{}, py::arg("prefers_gop_remaining_frames") = vk::Bool32{}, py::arg("requires_gop_remaining_frames") = vk::Bool32{}, py::arg("std_syntax_flags") = vk::VideoEncodeH265StdFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265DpbSlotInfoKHR.def(py::init<const StdVideoEncodeH265ReferenceInfo *, const void *>(), py::arg("p_std_reference_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265FrameSizeKHR.def(py::init<uint32_t, uint32_t, uint32_t>(), py::arg("frameI_size") = uint32_t{}, py::arg("frameP_size") = uint32_t{}, py::arg("frameB_size") = uint32_t{});

    s_vk_VideoEncodeH265GopRemainingFrameInfoKHR.def(py::init<vk::Bool32, uint32_t, uint32_t, uint32_t, const void *>(), py::arg("use_gop_remaining_frames") = vk::Bool32{}, py::arg("gop_remaining_i") = uint32_t{}, py::arg("gop_remaining_p") = uint32_t{}, py::arg("gop_remaining_b") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265NaluSliceSegmentInfoKHR.def(py::init<int32_t, const StdVideoEncodeH265SliceSegmentHeader *, const void *>(), py::arg("constant_qp") = int32_t{}, py::arg("p_std_slice_segment_header") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265PictureInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::VideoEncodeH265NaluSliceSegmentInfoKHR> &, const StdVideoEncodeH265PictureInfo *, const void *>(), py::arg("nalu_slice_segment_entries"), py::arg("p_std_picture_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265ProfileInfoKHR.def(py::init<StdVideoH265ProfileIdc, const void *>(), py::arg("std_profile_idc") = StdVideoH265ProfileIdc{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265QpKHR.def(py::init<int32_t, int32_t, int32_t>(), py::arg("qpI") = int32_t{}, py::arg("qpP") = int32_t{}, py::arg("qpB") = int32_t{});

    s_vk_VideoEncodeH265QualityLevelPropertiesKHR.def(py::init<vk::VideoEncodeH265RateControlFlagsKHR, uint32_t, uint32_t, uint32_t, uint32_t, vk::VideoEncodeH265QpKHR, uint32_t, uint32_t, void *>(), py::arg("preferred_rate_control_flags") = vk::VideoEncodeH265RateControlFlagsKHR{}, py::arg("preferred_gop_frame_count") = uint32_t{}, py::arg("preferred_idr_period") = uint32_t{}, py::arg("preferred_consecutive_b_frame_count") = uint32_t{}, py::arg("preferred_sub_layer_count") = uint32_t{}, py::arg("preferred_constant_qp") = vk::VideoEncodeH265QpKHR{}, py::arg("preferred_max_l0_reference_count") = uint32_t{}, py::arg("preferred_max_l1_reference_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265RateControlInfoKHR.def(py::init<vk::VideoEncodeH265RateControlFlagsKHR, uint32_t, uint32_t, uint32_t, uint32_t, const void *>(), py::arg("flags") = vk::VideoEncodeH265RateControlFlagsKHR{}, py::arg("gop_frame_count") = uint32_t{}, py::arg("idr_period") = uint32_t{}, py::arg("consecutiveB_frame_count") = uint32_t{}, py::arg("sub_layer_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265RateControlLayerInfoKHR.def(py::init<vk::Bool32, vk::VideoEncodeH265QpKHR, vk::Bool32, vk::VideoEncodeH265QpKHR, vk::Bool32, vk::VideoEncodeH265FrameSizeKHR, const void *>(), py::arg("use_min_qp") = vk::Bool32{}, py::arg("min_qp") = vk::VideoEncodeH265QpKHR{}, py::arg("use_max_qp") = vk::Bool32{}, py::arg("max_qp") = vk::VideoEncodeH265QpKHR{}, py::arg("use_max_frame_size") = vk::Bool32{}, py::arg("max_frame_size") = vk::VideoEncodeH265FrameSizeKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265SessionCreateInfoKHR.def(py::init<vk::Bool32, StdVideoH265LevelIdc, const void *>(), py::arg("use_max_level_idc") = vk::Bool32{}, py::arg("max_level_idc") = StdVideoH265LevelIdc{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265SessionParametersAddInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const StdVideoH265VideoParameterSet> &, const vk::ArrayProxyNoTemporaries<const StdVideoH265SequenceParameterSet> &, const vk::ArrayProxyNoTemporaries<const StdVideoH265PictureParameterSet> &, const void *>(), py::arg("stdVP_ss"), py::arg("stdSP_ss") = vk::ArrayProxyNoTemporaries<const StdVideoH265SequenceParameterSet>{}, py::arg("stdPP_ss") = vk::ArrayProxyNoTemporaries<const StdVideoH265PictureParameterSet>{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265SessionParametersCreateInfoKHR.def(py::init<uint32_t, uint32_t, uint32_t, const vk::VideoEncodeH265SessionParametersAddInfoKHR *, const void *>(), py::arg("max_std_VPS_count") = uint32_t{}, py::arg("max_std_SPS_count") = uint32_t{}, py::arg("max_std_PPS_count") = uint32_t{}, py::arg("p_parameters_add_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265SessionParametersFeedbackInfoKHR.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("has_std_VPS_overrides") = vk::Bool32{}, py::arg("has_std_SPS_overrides") = vk::Bool32{}, py::arg("has_std_PPS_overrides") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeH265SessionParametersGetInfoKHR.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, uint32_t, uint32_t, uint32_t, const void *>(), py::arg("write_std_VPS") = vk::Bool32{}, py::arg("write_std_SPS") = vk::Bool32{}, py::arg("write_std_PPS") = vk::Bool32{}, py::arg("stdVPS_id") = uint32_t{}, py::arg("stdSPS_id") = uint32_t{}, py::arg("stdPPS_id") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH264CapabilitiesKHR.def(py::init<StdVideoH264LevelIdc, vk::Offset2D, void *>(), py::arg("max_level_idc") = StdVideoH264LevelIdc{}, py::arg("field_offset_granularity") = vk::Offset2D{}, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH264DpbSlotInfoKHR.def(py::init<const StdVideoDecodeH264ReferenceInfo *, const void *>(), py::arg("p_std_reference_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH264PictureInfoKHR.def(py::init<const StdVideoDecodeH264PictureInfo *, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("p_std_picture_info"), py::arg("slice_offsets"), py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH264ProfileInfoKHR.def(py::init<StdVideoH264ProfileIdc, vk::VideoDecodeH264PictureLayoutFlagBitsKHR, const void *>(), py::arg("std_profile_idc") = StdVideoH264ProfileIdc{}, py::arg("picture_layout") = VULKAN_HPP_NAMESPACE::VideoDecodeH264PictureLayoutFlagBitsKHR::eProgressive, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH264SessionParametersAddInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const StdVideoH264SequenceParameterSet> &, const vk::ArrayProxyNoTemporaries<const StdVideoH264PictureParameterSet> &, const void *>(), py::arg("stdSP_ss"), py::arg("stdPP_ss") = vk::ArrayProxyNoTemporaries<const StdVideoH264PictureParameterSet>{}, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH264SessionParametersCreateInfoKHR.def(py::init<uint32_t, uint32_t, const vk::VideoDecodeH264SessionParametersAddInfoKHR *, const void *>(), py::arg("max_std_SPS_count") = uint32_t{}, py::arg("max_std_PPS_count") = uint32_t{}, py::arg("p_parameters_add_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_TextureLODGatherFormatPropertiesAMD.def(py::init<vk::Bool32, void *>(), py::arg("supports_texture_gather_LOD_bias_AMD") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_ShaderResourceUsageAMD.def(py::init<uint32_t, uint32_t, uint32_t, size_t, size_t>(), py::arg("num_used_vgprs") = uint32_t{}, py::arg("num_used_sgprs") = uint32_t{}, py::arg("lds_size_per_local_work_group") = uint32_t{}, py::arg("lds_usage_size_in_bytes") = size_t{}, py::arg("scratch_mem_usage_in_bytes") = size_t{});

    s_vk_ShaderStatisticsInfoAMD.def(py::init<vk::ShaderStageFlags, vk::ShaderResourceUsageAMD, uint32_t, uint32_t, uint32_t, uint32_t, const std::array<uint32_t, 3> &>(), py::arg("shader_stage_mask") = vk::ShaderStageFlags{}, py::arg("resource_usage") = vk::ShaderResourceUsageAMD{}, py::arg("num_physical_vgprs") = uint32_t{}, py::arg("num_physical_sgprs") = uint32_t{}, py::arg("num_available_vgprs") = uint32_t{}, py::arg("num_available_sgprs") = uint32_t{}, py::arg("compute_work_group_size") = std::array<uint32_t, 3>{});

    s_vk_AttachmentSampleCountInfoAMD.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::SampleCountFlagBits> &, vk::SampleCountFlagBits, const void *>(), py::arg("color_attachment_samples"), py::arg("depth_stencil_attachment_samples") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("p_next") = nullptr);

    s_vk_MultiviewPerViewAttributesInfoNVX.def(py::init<vk::Bool32, vk::Bool32, const void *>(), py::arg("per_view_attributes") = vk::Bool32{}, py::arg("per_view_attributes_position_x_only") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_RenderingFragmentDensityMapAttachmentInfoEXT.def(py::init<vk::ImageView, vk::ImageLayout, const void *>(), py::arg("image_view") = vk::ImageView{}, py::arg("image_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("p_next") = nullptr);

    s_vk_RenderingFragmentShadingRateAttachmentInfoKHR.def(py::init<vk::ImageView, vk::ImageLayout, vk::Extent2D, const void *>(), py::arg("image_view") = vk::ImageView{}, py::arg("image_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("shading_rate_attachment_texel_size") = vk::Extent2D{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCornerSampledImageFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("corner_sampled_image") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_ExternalImageFormatPropertiesNV.def(py::init<vk::ImageFormatProperties, vk::ExternalMemoryFeatureFlagsNV, vk::ExternalMemoryHandleTypeFlagsNV, vk::ExternalMemoryHandleTypeFlagsNV>(), py::arg("image_format_properties") = vk::ImageFormatProperties{}, py::arg("external_memory_features") = vk::ExternalMemoryFeatureFlagsNV{}, py::arg("export_from_imported_handle_types") = vk::ExternalMemoryHandleTypeFlagsNV{}, py::arg("compatible_handle_types") = vk::ExternalMemoryHandleTypeFlagsNV{});

    s_vk_ExportMemoryAllocateInfoNV.def(py::init<vk::ExternalMemoryHandleTypeFlagsNV, const void *>(), py::arg("handle_types") = vk::ExternalMemoryHandleTypeFlagsNV{}, py::arg("p_next") = nullptr);

    s_vk_ExternalMemoryImageCreateInfoNV.def(py::init<vk::ExternalMemoryHandleTypeFlagsNV, const void *>(), py::arg("handle_types") = vk::ExternalMemoryHandleTypeFlagsNV{}, py::arg("p_next") = nullptr);

    s_vk_ValidationFlagsEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::ValidationCheckEXT> &, const void *>(), py::arg("disabled_validation_checks"), py::arg("p_next") = nullptr);

    s_vk_ImageViewASTCDecodeModeEXT.def(py::init<vk::Format, const void *>(), py::arg("decode_mode") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceASTCDecodeFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("decode_mode_shared_exponent") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePipelineRobustnessFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("pipeline_robustness") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePipelineRobustnessPropertiesEXT.def(py::init<vk::PipelineRobustnessBufferBehaviorEXT, vk::PipelineRobustnessBufferBehaviorEXT, vk::PipelineRobustnessBufferBehaviorEXT, vk::PipelineRobustnessImageBehaviorEXT, void *>(), py::arg("default_robustness_storage_buffers") = VULKAN_HPP_NAMESPACE::PipelineRobustnessBufferBehaviorEXT::eDeviceDefault, py::arg("default_robustness_uniform_buffers") = VULKAN_HPP_NAMESPACE::PipelineRobustnessBufferBehaviorEXT::eDeviceDefault, py::arg("default_robustness_vertex_inputs") = VULKAN_HPP_NAMESPACE::PipelineRobustnessBufferBehaviorEXT::eDeviceDefault, py::arg("default_robustness_images") = VULKAN_HPP_NAMESPACE::PipelineRobustnessImageBehaviorEXT::eDeviceDefault, py::arg("p_next") = nullptr);

    s_vk_PipelineRobustnessCreateInfoEXT.def(py::init<vk::PipelineRobustnessBufferBehaviorEXT, vk::PipelineRobustnessBufferBehaviorEXT, vk::PipelineRobustnessBufferBehaviorEXT, vk::PipelineRobustnessImageBehaviorEXT, const void *>(), py::arg("storage_buffers") = VULKAN_HPP_NAMESPACE::PipelineRobustnessBufferBehaviorEXT::eDeviceDefault, py::arg("uniform_buffers") = VULKAN_HPP_NAMESPACE::PipelineRobustnessBufferBehaviorEXT::eDeviceDefault, py::arg("vertex_inputs") = VULKAN_HPP_NAMESPACE::PipelineRobustnessBufferBehaviorEXT::eDeviceDefault, py::arg("images") = VULKAN_HPP_NAMESPACE::PipelineRobustnessImageBehaviorEXT::eDeviceDefault, py::arg("p_next") = nullptr);

    s_vk_ImportMemoryFdInfoKHR.def(py::init<vk::ExternalMemoryHandleTypeFlagBits, int, const void *>(), py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalMemoryHandleTypeFlagBits::eOpaqueFd, py::arg("fd") = int{}, py::arg("p_next") = nullptr);

    s_vk_MemoryFdPropertiesKHR.def(py::init<uint32_t, void *>(), py::arg("memory_type_bits") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_MemoryGetFdInfoKHR.def(py::init<vk::DeviceMemory, vk::ExternalMemoryHandleTypeFlagBits, const void *>(), py::arg("memory") = vk::DeviceMemory{}, py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalMemoryHandleTypeFlagBits::eOpaqueFd, py::arg("p_next") = nullptr);

    s_vk_ImportSemaphoreFdInfoKHR.def(py::init<vk::Semaphore, vk::SemaphoreImportFlags, vk::ExternalSemaphoreHandleTypeFlagBits, int, const void *>(), py::arg("semaphore") = vk::Semaphore{}, py::arg("flags") = vk::SemaphoreImportFlags{}, py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalSemaphoreHandleTypeFlagBits::eOpaqueFd, py::arg("fd") = int{}, py::arg("p_next") = nullptr);

    s_vk_SemaphoreGetFdInfoKHR.def(py::init<vk::Semaphore, vk::ExternalSemaphoreHandleTypeFlagBits, const void *>(), py::arg("semaphore") = vk::Semaphore{}, py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalSemaphoreHandleTypeFlagBits::eOpaqueFd, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePushDescriptorPropertiesKHR.def(py::init<uint32_t, void *>(), py::arg("max_push_descriptors") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_CommandBufferInheritanceConditionalRenderingInfoEXT.def(py::init<vk::Bool32, const void *>(), py::arg("conditional_rendering_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_ConditionalRenderingBeginInfoEXT.def(py::init<vk::Buffer, vk::DeviceSize, vk::ConditionalRenderingFlagsEXT, const void *>(), py::arg("buffer") = vk::Buffer{}, py::arg("offset") = vk::DeviceSize{}, py::arg("flags") = vk::ConditionalRenderingFlagsEXT{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceConditionalRenderingFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("conditional_rendering") = vk::Bool32{}, py::arg("inherited_conditional_rendering") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PresentRegionKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::RectLayerKHR> &>(), py::arg("rectangles"));

    s_vk_PresentRegionsKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::PresentRegionKHR> &, const void *>(), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_RectLayerKHR.def(py::init<const ::vk::Rect2D &, uint32_t>(), py::arg("rect2D"), py::arg("layer") = uint32_t{});

    s_vk_PipelineViewportWScalingStateCreateInfoNV.def(py::init<vk::Bool32, const vk::ArrayProxyNoTemporaries<const vk::ViewportWScalingNV> &, const void *>(), py::arg("viewportW_scaling_enable"), py::arg("viewportW_scalings"), py::arg("p_next") = nullptr);

    s_vk_ViewportWScalingNV.def(py::init<float, float>(), py::arg("xcoeff") = float{}, py::arg("ycoeff") = float{});

    s_vk_SurfaceCapabilities2EXT.def(py::init<uint32_t, uint32_t, vk::Extent2D, vk::Extent2D, vk::Extent2D, uint32_t, vk::SurfaceTransformFlagsKHR, vk::SurfaceTransformFlagBitsKHR, vk::CompositeAlphaFlagsKHR, vk::ImageUsageFlags, vk::SurfaceCounterFlagsEXT, void *>(), py::arg("min_image_count") = uint32_t{}, py::arg("max_image_count") = uint32_t{}, py::arg("current_extent") = vk::Extent2D{}, py::arg("min_image_extent") = vk::Extent2D{}, py::arg("max_image_extent") = vk::Extent2D{}, py::arg("max_image_array_layers") = uint32_t{}, py::arg("supported_transforms") = vk::SurfaceTransformFlagsKHR{}, py::arg("current_transform") = VULKAN_HPP_NAMESPACE::SurfaceTransformFlagBitsKHR::eIdentity, py::arg("supported_composite_alpha") = vk::CompositeAlphaFlagsKHR{}, py::arg("supported_usage_flags") = vk::ImageUsageFlags{}, py::arg("supported_surface_counters") = vk::SurfaceCounterFlagsEXT{}, py::arg("p_next") = nullptr);

    s_vk_DeviceEventInfoEXT.def(py::init<vk::DeviceEventTypeEXT, const void *>(), py::arg("device_event") = VULKAN_HPP_NAMESPACE::DeviceEventTypeEXT::eDisplayHotplug, py::arg("p_next") = nullptr);

    s_vk_DisplayEventInfoEXT.def(py::init<vk::DisplayEventTypeEXT, const void *>(), py::arg("display_event") = VULKAN_HPP_NAMESPACE::DisplayEventTypeEXT::eFirstPixelOut, py::arg("p_next") = nullptr);

    s_vk_DisplayPowerInfoEXT.def(py::init<vk::DisplayPowerStateEXT, const void *>(), py::arg("power_state") = VULKAN_HPP_NAMESPACE::DisplayPowerStateEXT::eOff, py::arg("p_next") = nullptr);

    s_vk_SwapchainCounterCreateInfoEXT.def(py::init<vk::SurfaceCounterFlagsEXT, const void *>(), py::arg("surface_counters") = vk::SurfaceCounterFlagsEXT{}, py::arg("p_next") = nullptr);

    s_vk_PastPresentationTimingGOOGLE.def(py::init<uint32_t, uint64_t, uint64_t, uint64_t, uint64_t>(), py::arg("presentID") = uint32_t{}, py::arg("desired_present_time") = uint64_t{}, py::arg("actual_present_time") = uint64_t{}, py::arg("earliest_present_time") = uint64_t{}, py::arg("present_margin") = uint64_t{});

    s_vk_PresentTimeGOOGLE.def(py::init<uint32_t, uint64_t>(), py::arg("presentID") = uint32_t{}, py::arg("desired_present_time") = uint64_t{});

    s_vk_PresentTimesInfoGOOGLE.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::PresentTimeGOOGLE> &, const void *>(), py::arg("times"), py::arg("p_next") = nullptr);

    s_vk_RefreshCycleDurationGOOGLE.def(py::init<uint64_t>(), py::arg("refresh_duration") = uint64_t{});

    s_vk_PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX.def(py::init<vk::Bool32, void *>(), py::arg("per_view_position_all_components") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineViewportSwizzleStateCreateInfoNV.def(py::init<vk::PipelineViewportSwizzleStateCreateFlagsNV, const vk::ArrayProxyNoTemporaries<const vk::ViewportSwizzleNV> &, const void *>(), py::arg("flags"), py::arg("viewport_swizzles"), py::arg("p_next") = nullptr);

    s_vk_ViewportSwizzleNV.def(py::init<vk::ViewportCoordinateSwizzleNV, vk::ViewportCoordinateSwizzleNV, vk::ViewportCoordinateSwizzleNV, vk::ViewportCoordinateSwizzleNV>(), py::arg("x") = VULKAN_HPP_NAMESPACE::ViewportCoordinateSwizzleNV::ePositiveX, py::arg("y") = VULKAN_HPP_NAMESPACE::ViewportCoordinateSwizzleNV::ePositiveX, py::arg("z") = VULKAN_HPP_NAMESPACE::ViewportCoordinateSwizzleNV::ePositiveX, py::arg("w") = VULKAN_HPP_NAMESPACE::ViewportCoordinateSwizzleNV::ePositiveX);

    s_vk_PhysicalDeviceDiscardRectanglePropertiesEXT.def(py::init<uint32_t, void *>(), py::arg("max_discard_rectangles") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PipelineDiscardRectangleStateCreateInfoEXT.def(py::init<vk::PipelineDiscardRectangleStateCreateFlagsEXT, vk::DiscardRectangleModeEXT, const vk::ArrayProxyNoTemporaries<const vk::Rect2D> &, const void *>(), py::arg("flags"), py::arg("discard_rectangle_mode"), py::arg("discard_rectangles"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceConservativeRasterizationPropertiesEXT.def(py::init<float, float, float, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("primitive_overestimation_size") = float{}, py::arg("max_extra_primitive_overestimation_size") = float{}, py::arg("extra_primitive_overestimation_size_granularity") = float{}, py::arg("primitive_underestimation") = vk::Bool32{}, py::arg("conservative_point_and_line_rasterization") = vk::Bool32{}, py::arg("degenerate_triangles_rasterized") = vk::Bool32{}, py::arg("degenerate_lines_rasterized") = vk::Bool32{}, py::arg("fully_covered_fragment_shader_input_variable") = vk::Bool32{}, py::arg("conservative_rasterization_post_depth_coverage") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineRasterizationConservativeStateCreateInfoEXT.def(py::init<vk::PipelineRasterizationConservativeStateCreateFlagsEXT, vk::ConservativeRasterizationModeEXT, float, const void *>(), py::arg("flags") = vk::PipelineRasterizationConservativeStateCreateFlagsEXT{}, py::arg("conservative_rasterization_mode") = VULKAN_HPP_NAMESPACE::ConservativeRasterizationModeEXT::eDisabled, py::arg("extra_primitive_overestimation_size") = float{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDepthClipEnableFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("depth_clip_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineRasterizationDepthClipStateCreateInfoEXT.def(py::init<vk::PipelineRasterizationDepthClipStateCreateFlagsEXT, vk::Bool32, const void *>(), py::arg("flags") = vk::PipelineRasterizationDepthClipStateCreateFlagsEXT{}, py::arg("depth_clip_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_HdrMetadataEXT.def(py::init<vk::XYColorEXT, vk::XYColorEXT, vk::XYColorEXT, vk::XYColorEXT, float, float, float, float, const void *>(), py::arg("display_primary_red") = vk::XYColorEXT{}, py::arg("display_primary_green") = vk::XYColorEXT{}, py::arg("display_primary_blue") = vk::XYColorEXT{}, py::arg("white_point") = vk::XYColorEXT{}, py::arg("max_luminance") = float{}, py::arg("min_luminance") = float{}, py::arg("max_content_light_level") = float{}, py::arg("max_frame_average_light_level") = float{}, py::arg("p_next") = nullptr);

    s_vk_XYColorEXT.def(py::init<float, float>(), py::arg("x") = float{}, py::arg("y") = float{});

    s_vk_PhysicalDeviceRelaxedLineRasterizationFeaturesIMG.def(py::init<vk::Bool32, void *>(), py::arg("relaxed_line_rasterization") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SharedPresentSurfaceCapabilitiesKHR.def(py::init<vk::ImageUsageFlags, void *>(), py::arg("shared_present_supported_usage_flags") = vk::ImageUsageFlags{}, py::arg("p_next") = nullptr);

    s_vk_FenceGetFdInfoKHR.def(py::init<vk::Fence, vk::ExternalFenceHandleTypeFlagBits, const void *>(), py::arg("fence") = vk::Fence{}, py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalFenceHandleTypeFlagBits::eOpaqueFd, py::arg("p_next") = nullptr);

    s_vk_ImportFenceFdInfoKHR.def(py::init<vk::Fence, vk::FenceImportFlags, vk::ExternalFenceHandleTypeFlagBits, int, const void *>(), py::arg("fence") = vk::Fence{}, py::arg("flags") = vk::FenceImportFlags{}, py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalFenceHandleTypeFlagBits::eOpaqueFd, py::arg("fd") = int{}, py::arg("p_next") = nullptr);

    s_vk_AcquireProfilingLockInfoKHR.def(py::init<vk::AcquireProfilingLockFlagsKHR, uint64_t, const void *>(), py::arg("flags") = vk::AcquireProfilingLockFlagsKHR{}, py::arg("timeout") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_PerformanceCounterDescriptionKHR.def(py::init<vk::PerformanceCounterDescriptionFlagsKHR, const std::array<char, 256U> &, const std::array<char, 256U> &, const std::array<char, 256U> &, void *>(), py::arg("flags") = vk::PerformanceCounterDescriptionFlagsKHR{}, py::arg("name") = std::array<char, 256U>{}, py::arg("category") = std::array<char, 256U>{}, py::arg("description") = std::array<char, 256U>{}, py::arg("p_next") = nullptr);

    s_vk_PerformanceCounterKHR.def(py::init<vk::PerformanceCounterUnitKHR, vk::PerformanceCounterScopeKHR, vk::PerformanceCounterStorageKHR, const std::array<uint8_t, 16U> &, void *>(), py::arg("unit") = VULKAN_HPP_NAMESPACE::PerformanceCounterUnitKHR::eGeneric, py::arg("scope") = VULKAN_HPP_NAMESPACE::PerformanceCounterScopeKHR::eCommandBuffer, py::arg("storage") = VULKAN_HPP_NAMESPACE::PerformanceCounterStorageKHR::eInt32, py::arg("uuid") = std::array<uint8_t, 16U>{}, py::arg("p_next") = nullptr);

    s_vk_PerformanceQuerySubmitInfoKHR.def(py::init<uint32_t, const void *>(), py::arg("counter_pass_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePerformanceQueryFeaturesKHR.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("performance_counter_query_pools") = vk::Bool32{}, py::arg("performance_counter_multiple_query_pools") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePerformanceQueryPropertiesKHR.def(py::init<vk::Bool32, void *>(), py::arg("allow_command_buffer_query_copies") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_QueryPoolPerformanceCreateInfoKHR.def(py::init<uint32_t, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("queue_family_index"), py::arg("counter_indices"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSurfaceInfo2KHR.def(py::init<vk::SurfaceKHR, const void *>(), py::arg("surface") = vk::SurfaceKHR{}, py::arg("p_next") = nullptr);

    s_vk_SurfaceCapabilities2KHR.def(py::init<vk::SurfaceCapabilitiesKHR, void *>(), py::arg("surface_capabilities") = vk::SurfaceCapabilitiesKHR{}, py::arg("p_next") = nullptr);

    s_vk_SurfaceFormat2KHR.def(py::init<vk::SurfaceFormatKHR, void *>(), py::arg("surface_format") = vk::SurfaceFormatKHR{}, py::arg("p_next") = nullptr);

    s_vk_DisplayModeProperties2KHR.def(py::init<vk::DisplayModePropertiesKHR, void *>(), py::arg("display_mode_properties") = vk::DisplayModePropertiesKHR{}, py::arg("p_next") = nullptr);

    s_vk_DisplayPlaneCapabilities2KHR.def(py::init<vk::DisplayPlaneCapabilitiesKHR, void *>(), py::arg("capabilities") = vk::DisplayPlaneCapabilitiesKHR{}, py::arg("p_next") = nullptr);

    s_vk_DisplayPlaneInfo2KHR.def(py::init<vk::DisplayModeKHR, uint32_t, const void *>(), py::arg("mode") = vk::DisplayModeKHR{}, py::arg("plane_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DisplayPlaneProperties2KHR.def(py::init<vk::DisplayPlanePropertiesKHR, void *>(), py::arg("display_plane_properties") = vk::DisplayPlanePropertiesKHR{}, py::arg("p_next") = nullptr);

    s_vk_DisplayProperties2KHR.def(py::init<vk::DisplayPropertiesKHR, void *>(), py::arg("display_properties") = vk::DisplayPropertiesKHR{}, py::arg("p_next") = nullptr);

    s_vk_DebugUtilsLabelEXT.def(py::init<const char *, const std::array<float, 4> &, const void *>(), py::arg("p_label_name") = nullptr, py::arg("color") = std::array<float, 4>{}, py::arg("p_next") = nullptr);

    s_vk_DebugUtilsMessengerCallbackDataEXT.def(py::init<vk::DebugUtilsMessengerCallbackDataFlagsEXT, const char *, int32_t, const char *, const vk::ArrayProxyNoTemporaries<const vk::DebugUtilsLabelEXT> &, const vk::ArrayProxyNoTemporaries<const vk::DebugUtilsLabelEXT> &, const vk::ArrayProxyNoTemporaries<const vk::DebugUtilsObjectNameInfoEXT> &, const void *>(), py::arg("flags"), py::arg("p_message_id_name"), py::arg("message_id_number"), py::arg("p_message"), py::arg("queue_labels"), py::arg("cmd_buf_labels") = vk::ArrayProxyNoTemporaries<const vk::DebugUtilsLabelEXT>{}, py::arg("objects") = vk::ArrayProxyNoTemporaries<const vk::DebugUtilsObjectNameInfoEXT>{}, py::arg("p_next") = nullptr);

    s_vk_DebugUtilsMessengerCreateInfoEXT.def(py::init<vk::DebugUtilsMessengerCreateFlagsEXT, vk::DebugUtilsMessageSeverityFlagsEXT, vk::DebugUtilsMessageTypeFlagsEXT, PFN_vkDebugUtilsMessengerCallbackEXT, void *, const void *>(), py::arg("flags") = vk::DebugUtilsMessengerCreateFlagsEXT{}, py::arg("message_severity") = vk::DebugUtilsMessageSeverityFlagsEXT{}, py::arg("message_type") = vk::DebugUtilsMessageTypeFlagsEXT{}, py::arg("pfn_user_callback") = PFN_vkDebugUtilsMessengerCallbackEXT{}, py::arg("p_user_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_DebugUtilsObjectNameInfoEXT.def(py::init<vk::ObjectType, uint64_t, const char *, const void *>(), py::arg("object_type") = VULKAN_HPP_NAMESPACE::ObjectType::eUnknown, py::arg("object_handle") = uint64_t{}, py::arg("p_object_name") = nullptr, py::arg("p_next") = nullptr);

    s_vk_DebugUtilsObjectTagInfoEXT.def(py::init<vk::ObjectType, uint64_t, uint64_t, size_t, const void *, const void *>(), py::arg("object_type") = VULKAN_HPP_NAMESPACE::ObjectType::eUnknown, py::arg("object_handle") = uint64_t{}, py::arg("tag_name") = uint64_t{}, py::arg("tag_size") = size_t{}, py::arg("p_tag") = nullptr, py::arg("p_next") = nullptr);

    s_vk_AttachmentSampleLocationsEXT.def(py::init<uint32_t, vk::SampleLocationsInfoEXT>(), py::arg("attachment_index") = uint32_t{}, py::arg("sample_locations_info") = vk::SampleLocationsInfoEXT{});

    s_vk_MultisamplePropertiesEXT.def(py::init<vk::Extent2D, void *>(), py::arg("max_sample_location_grid_size") = vk::Extent2D{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSampleLocationsPropertiesEXT.def(py::init<vk::SampleCountFlags, vk::Extent2D, const std::array<float, 2> &, uint32_t, vk::Bool32, void *>(), py::arg("sample_location_sample_counts") = vk::SampleCountFlags{}, py::arg("max_sample_location_grid_size") = vk::Extent2D{}, py::arg("sample_location_coordinate_range") = std::array<float, 2>{}, py::arg("sample_location_sub_pixel_bits") = uint32_t{}, py::arg("variable_sample_locations") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineSampleLocationsStateCreateInfoEXT.def(py::init<vk::Bool32, vk::SampleLocationsInfoEXT, const void *>(), py::arg("sample_locations_enable") = vk::Bool32{}, py::arg("sample_locations_info") = vk::SampleLocationsInfoEXT{}, py::arg("p_next") = nullptr);

    s_vk_RenderPassSampleLocationsBeginInfoEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::AttachmentSampleLocationsEXT> &, const vk::ArrayProxyNoTemporaries<const vk::SubpassSampleLocationsEXT> &, const void *>(), py::arg("attachment_initial_sample_locations"), py::arg("post_subpass_sample_locations") = vk::ArrayProxyNoTemporaries<const vk::SubpassSampleLocationsEXT>{}, py::arg("p_next") = nullptr);

    s_vk_SampleLocationEXT.def(py::init<float, float>(), py::arg("x") = float{}, py::arg("y") = float{});

    s_vk_SampleLocationsInfoEXT.def(py::init<vk::SampleCountFlagBits, vk::Extent2D, const vk::ArrayProxyNoTemporaries<const vk::SampleLocationEXT> &, const void *>(), py::arg("sample_locations_per_pixel"), py::arg("sample_location_grid_size"), py::arg("sample_locations"), py::arg("p_next") = nullptr);

    s_vk_SubpassSampleLocationsEXT.def(py::init<uint32_t, vk::SampleLocationsInfoEXT>(), py::arg("subpass_index") = uint32_t{}, py::arg("sample_locations_info") = vk::SampleLocationsInfoEXT{});

    s_vk_PhysicalDeviceBlendOperationAdvancedFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("advanced_blend_coherent_operations") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceBlendOperationAdvancedPropertiesEXT.def(py::init<uint32_t, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("advanced_blend_max_color_attachments") = uint32_t{}, py::arg("advanced_blend_independent_blend") = vk::Bool32{}, py::arg("advanced_blend_non_premultiplied_src_color") = vk::Bool32{}, py::arg("advanced_blend_non_premultiplied_dst_color") = vk::Bool32{}, py::arg("advanced_blend_correlated_overlap") = vk::Bool32{}, py::arg("advanced_blend_all_operations") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineColorBlendAdvancedStateCreateInfoEXT.def(py::init<vk::Bool32, vk::Bool32, vk::BlendOverlapEXT, const void *>(), py::arg("src_premultiplied") = vk::Bool32{}, py::arg("dst_premultiplied") = vk::Bool32{}, py::arg("blend_overlap") = VULKAN_HPP_NAMESPACE::BlendOverlapEXT::eUncorrelated, py::arg("p_next") = nullptr);

    s_vk_PipelineCoverageToColorStateCreateInfoNV.def(py::init<vk::PipelineCoverageToColorStateCreateFlagsNV, vk::Bool32, uint32_t, const void *>(), py::arg("flags") = vk::PipelineCoverageToColorStateCreateFlagsNV{}, py::arg("coverage_to_color_enable") = vk::Bool32{}, py::arg("coverage_to_color_location") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_AabbPositionsKHR.def(py::init<float, float, float, float, float, float>(), py::arg("minX") = float{}, py::arg("minY") = float{}, py::arg("minZ") = float{}, py::arg("maxX") = float{}, py::arg("maxY") = float{}, py::arg("maxZ") = float{});

    s_vk_AccelerationStructureBuildGeometryInfoKHR.def(py::init<vk::AccelerationStructureTypeKHR, vk::BuildAccelerationStructureFlagsKHR, vk::BuildAccelerationStructureModeKHR, vk::AccelerationStructureKHR, vk::AccelerationStructureKHR, const vk::ArrayProxyNoTemporaries<const vk::AccelerationStructureGeometryKHR> &, const vk::ArrayProxyNoTemporaries<const vk::AccelerationStructureGeometryKHR *const> &, vk::DeviceOrHostAddressKHR, const void *>(), py::arg("type"), py::arg("flags"), py::arg("mode"), py::arg("src_acceleration_structure"), py::arg("dst_acceleration_structure"), py::arg("geometries"), py::arg("p_geometries") = vk::ArrayProxyNoTemporaries<const vk::AccelerationStructureGeometryKHR *const>{}, py::arg("scratch_data") = vk::DeviceOrHostAddressKHR{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureBuildRangeInfoKHR.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t>(), py::arg("primitive_count") = uint32_t{}, py::arg("primitive_offset") = uint32_t{}, py::arg("first_vertex") = uint32_t{}, py::arg("transform_offset") = uint32_t{});

    s_vk_AccelerationStructureBuildSizesInfoKHR.def(py::init<vk::DeviceSize, vk::DeviceSize, vk::DeviceSize, const void *>(), py::arg("acceleration_structure_size") = vk::DeviceSize{}, py::arg("update_scratch_size") = vk::DeviceSize{}, py::arg("build_scratch_size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureCreateInfoKHR.def(py::init<vk::AccelerationStructureCreateFlagsKHR, vk::Buffer, vk::DeviceSize, vk::DeviceSize, vk::AccelerationStructureTypeKHR, vk::DeviceAddress, const void *>(), py::arg("create_flags") = vk::AccelerationStructureCreateFlagsKHR{}, py::arg("buffer") = vk::Buffer{}, py::arg("offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{}, py::arg("type") = VULKAN_HPP_NAMESPACE::AccelerationStructureTypeKHR::eTopLevel, py::arg("device_address") = vk::DeviceAddress{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureDeviceAddressInfoKHR.def(py::init<vk::AccelerationStructureKHR, const void *>(), py::arg("acceleration_structure") = vk::AccelerationStructureKHR{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureGeometryAabbsDataKHR.def(py::init<vk::DeviceOrHostAddressConstKHR, vk::DeviceSize, const void *>(), py::arg("data") = vk::DeviceOrHostAddressConstKHR{}, py::arg("stride") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureGeometryInstancesDataKHR.def(py::init<vk::Bool32, vk::DeviceOrHostAddressConstKHR, const void *>(), py::arg("array_of_pointers") = vk::Bool32{}, py::arg("data") = vk::DeviceOrHostAddressConstKHR{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureGeometryKHR.def(py::init<vk::GeometryTypeKHR, vk::AccelerationStructureGeometryDataKHR, vk::GeometryFlagsKHR, const void *>(), py::arg("geometry_type") = VULKAN_HPP_NAMESPACE::GeometryTypeKHR::eTriangles, py::arg("geometry") = vk::AccelerationStructureGeometryDataKHR{}, py::arg("flags") = vk::GeometryFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureGeometryTrianglesDataKHR.def(py::init<vk::Format, vk::DeviceOrHostAddressConstKHR, vk::DeviceSize, uint32_t, vk::IndexType, vk::DeviceOrHostAddressConstKHR, vk::DeviceOrHostAddressConstKHR, const void *>(), py::arg("vertex_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("vertex_data") = vk::DeviceOrHostAddressConstKHR{}, py::arg("vertex_stride") = vk::DeviceSize{}, py::arg("max_vertex") = uint32_t{}, py::arg("index_type") = VULKAN_HPP_NAMESPACE::IndexType::eUint16, py::arg("index_data") = vk::DeviceOrHostAddressConstKHR{}, py::arg("transform_data") = vk::DeviceOrHostAddressConstKHR{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureInstanceKHR.def(py::init<vk::TransformMatrixKHR, uint32_t, uint32_t, uint32_t, vk::GeometryInstanceFlagsKHR, uint64_t>(), py::arg("transform") = vk::TransformMatrixKHR{}, py::arg("instance_custom_index") = uint32_t{}, py::arg("mask") = uint32_t{}, py::arg("instance_shader_binding_table_record_offset") = uint32_t{}, py::arg("flags") = vk::GeometryInstanceFlagsKHR{}, py::arg("acceleration_structure_reference") = uint64_t{});

    s_vk_AccelerationStructureVersionInfoKHR.def(py::init<const uint8_t *, const void *>(), py::arg("p_version_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_CopyAccelerationStructureInfoKHR.def(py::init<vk::AccelerationStructureKHR, vk::AccelerationStructureKHR, vk::CopyAccelerationStructureModeKHR, const void *>(), py::arg("src") = vk::AccelerationStructureKHR{}, py::arg("dst") = vk::AccelerationStructureKHR{}, py::arg("mode") = VULKAN_HPP_NAMESPACE::CopyAccelerationStructureModeKHR::eClone, py::arg("p_next") = nullptr);

    s_vk_CopyAccelerationStructureToMemoryInfoKHR.def(py::init<vk::AccelerationStructureKHR, vk::DeviceOrHostAddressKHR, vk::CopyAccelerationStructureModeKHR, const void *>(), py::arg("src") = vk::AccelerationStructureKHR{}, py::arg("dst") = vk::DeviceOrHostAddressKHR{}, py::arg("mode") = VULKAN_HPP_NAMESPACE::CopyAccelerationStructureModeKHR::eClone, py::arg("p_next") = nullptr);

    s_vk_CopyMemoryToAccelerationStructureInfoKHR.def(py::init<vk::DeviceOrHostAddressConstKHR, vk::AccelerationStructureKHR, vk::CopyAccelerationStructureModeKHR, const void *>(), py::arg("src") = vk::DeviceOrHostAddressConstKHR{}, py::arg("dst") = vk::AccelerationStructureKHR{}, py::arg("mode") = VULKAN_HPP_NAMESPACE::CopyAccelerationStructureModeKHR::eClone, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceAccelerationStructureFeaturesKHR.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("acceleration_structure") = vk::Bool32{}, py::arg("acceleration_structure_capture_replay") = vk::Bool32{}, py::arg("acceleration_structure_indirect_build") = vk::Bool32{}, py::arg("acceleration_structure_host_commands") = vk::Bool32{}, py::arg("descriptor_binding_acceleration_structure_update_after_bind") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceAccelerationStructurePropertiesKHR.def(py::init<uint64_t, uint64_t, uint64_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void *>(), py::arg("max_geometry_count") = uint64_t{}, py::arg("max_instance_count") = uint64_t{}, py::arg("max_primitive_count") = uint64_t{}, py::arg("max_per_stage_descriptor_acceleration_structures") = uint32_t{}, py::arg("max_per_stage_descriptor_update_after_bind_acceleration_structures") = uint32_t{}, py::arg("max_descriptor_set_acceleration_structures") = uint32_t{}, py::arg("max_descriptor_set_update_after_bind_acceleration_structures") = uint32_t{}, py::arg("min_acceleration_structure_scratch_offset_alignment") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_TransformMatrixKHR.def(py::init<const std::array<std::array<float, 4>, 3> &>(), py::arg("matrix") = std::array<std::array<float, 4>, 3>{});

    s_vk_WriteDescriptorSetAccelerationStructureKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::AccelerationStructureKHR> &, const void *>(), py::arg("acceleration_structures"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRayTracingPipelineFeaturesKHR.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("ray_tracing_pipeline") = vk::Bool32{}, py::arg("ray_tracing_pipeline_shader_group_handle_capture_replay") = vk::Bool32{}, py::arg("ray_tracing_pipeline_shader_group_handle_capture_replay_mixed") = vk::Bool32{}, py::arg("ray_tracing_pipeline_trace_rays_indirect") = vk::Bool32{}, py::arg("ray_traversal_primitive_culling") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRayTracingPipelinePropertiesKHR.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void *>(), py::arg("shader_group_handle_size") = uint32_t{}, py::arg("max_ray_recursion_depth") = uint32_t{}, py::arg("max_shader_group_stride") = uint32_t{}, py::arg("shader_group_base_alignment") = uint32_t{}, py::arg("shader_group_handle_capture_replay_size") = uint32_t{}, py::arg("max_ray_dispatch_invocation_count") = uint32_t{}, py::arg("shader_group_handle_alignment") = uint32_t{}, py::arg("max_ray_hit_attribute_size") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_RayTracingPipelineCreateInfoKHR.def(py::init<vk::PipelineCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::PipelineShaderStageCreateInfo> &, const vk::ArrayProxyNoTemporaries<const vk::RayTracingShaderGroupCreateInfoKHR> &, uint32_t, const vk::PipelineLibraryCreateInfoKHR *, const vk::RayTracingPipelineInterfaceCreateInfoKHR *, const vk::PipelineDynamicStateCreateInfo *, vk::PipelineLayout, vk::Pipeline, int32_t, const void *>(), py::arg("flags"), py::arg("stages"), py::arg("groups") = vk::ArrayProxyNoTemporaries<const vk::RayTracingShaderGroupCreateInfoKHR>{}, py::arg("max_pipeline_ray_recursion_depth") = uint32_t{}, py::arg("p_library_info") = nullptr, py::arg("p_library_interface") = nullptr, py::arg("p_dynamic_state") = nullptr, py::arg("layout") = vk::PipelineLayout{}, py::arg("base_pipeline_handle") = vk::Pipeline{}, py::arg("base_pipeline_index") = int32_t{}, py::arg("p_next") = nullptr);

    s_vk_RayTracingPipelineInterfaceCreateInfoKHR.def(py::init<uint32_t, uint32_t, const void *>(), py::arg("max_pipeline_ray_payload_size") = uint32_t{}, py::arg("max_pipeline_ray_hit_attribute_size") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_RayTracingShaderGroupCreateInfoKHR.def(py::init<vk::RayTracingShaderGroupTypeKHR, uint32_t, uint32_t, uint32_t, uint32_t, const void *, const void *>(), py::arg("type") = VULKAN_HPP_NAMESPACE::RayTracingShaderGroupTypeKHR::eGeneral, py::arg("general_shader") = VULKAN_HPP_NAMESPACE::ShaderUnusedKHR, py::arg("closest_hit_shader") = VULKAN_HPP_NAMESPACE::ShaderUnusedKHR, py::arg("any_hit_shader") = VULKAN_HPP_NAMESPACE::ShaderUnusedKHR, py::arg("intersection_shader") = VULKAN_HPP_NAMESPACE::ShaderUnusedKHR, py::arg("p_shader_group_capture_replay_handle") = nullptr, py::arg("p_next") = nullptr);

    s_vk_StridedDeviceAddressRegionKHR.def(py::init<vk::DeviceAddress, vk::DeviceSize, vk::DeviceSize>(), py::arg("device_address") = vk::DeviceAddress{}, py::arg("stride") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{});

    s_vk_TraceRaysIndirectCommandKHR.def(py::init<const ::vk::Extent2D &, uint32_t>(), py::arg("extent2D"), py::arg("depth") = uint32_t{});

    s_vk_PhysicalDeviceRayQueryFeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("ray_query") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineCoverageModulationStateCreateInfoNV.def(py::init<vk::PipelineCoverageModulationStateCreateFlagsNV, vk::CoverageModulationModeNV, vk::Bool32, const vk::ArrayProxyNoTemporaries<const float> &, const void *>(), py::arg("flags"), py::arg("coverage_modulation_mode"), py::arg("coverage_modulation_table_enable"), py::arg("coverage_modulation_table"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderSMBuiltinsFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("shaderSM_builtins") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderSMBuiltinsPropertiesNV.def(py::init<uint32_t, uint32_t, void *>(), py::arg("shaderSM_count") = uint32_t{}, py::arg("shader_warps_per_SM") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DrmFormatModifierProperties2EXT.def(py::init<uint64_t, uint32_t, vk::FormatFeatureFlags2>(), py::arg("drm_format_modifier") = uint64_t{}, py::arg("drm_format_modifier_plane_count") = uint32_t{}, py::arg("drm_format_modifier_tiling_features") = vk::FormatFeatureFlags2{});

    s_vk_DrmFormatModifierPropertiesEXT.def(py::init<uint64_t, uint32_t, vk::FormatFeatureFlags>(), py::arg("drm_format_modifier") = uint64_t{}, py::arg("drm_format_modifier_plane_count") = uint32_t{}, py::arg("drm_format_modifier_tiling_features") = vk::FormatFeatureFlags{});

    s_vk_DrmFormatModifierPropertiesList2EXT.def(py::init<const vk::ArrayProxyNoTemporaries<vk::DrmFormatModifierProperties2EXT> &, void *>(), py::arg("drm_format_modifier_properties"), py::arg("p_next") = nullptr);

    s_vk_DrmFormatModifierPropertiesListEXT.def(py::init<const vk::ArrayProxyNoTemporaries<vk::DrmFormatModifierPropertiesEXT> &, void *>(), py::arg("drm_format_modifier_properties"), py::arg("p_next") = nullptr);

    s_vk_ImageDrmFormatModifierExplicitCreateInfoEXT.def(py::init<uint64_t, const vk::ArrayProxyNoTemporaries<const vk::SubresourceLayout> &, const void *>(), py::arg("drm_format_modifier"), py::arg("plane_layouts"), py::arg("p_next") = nullptr);

    s_vk_ImageDrmFormatModifierListCreateInfoEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const uint64_t> &, const void *>(), py::arg("drm_format_modifiers"), py::arg("p_next") = nullptr);

    s_vk_ImageDrmFormatModifierPropertiesEXT.def(py::init<uint64_t, void *>(), py::arg("drm_format_modifier") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageDrmFormatModifierInfoEXT.def(py::init<uint64_t, vk::SharingMode, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("drm_format_modifier"), py::arg("sharing_mode"), py::arg("queue_family_indices"), py::arg("p_next") = nullptr);

    s_vk_ShaderModuleValidationCacheCreateInfoEXT.def(py::init<vk::ValidationCacheEXT, const void *>(), py::arg("validation_cache") = vk::ValidationCacheEXT{}, py::arg("p_next") = nullptr);

    s_vk_ValidationCacheCreateInfoEXT.def(py::init<vk::ValidationCacheCreateFlagsEXT, size_t, const void *, const void *>(), py::arg("flags") = vk::ValidationCacheCreateFlagsEXT{}, py::arg("initial_data_size") = size_t{}, py::arg("p_initial_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_CoarseSampleLocationNV.def(py::init<uint32_t, uint32_t, uint32_t>(), py::arg("pixelX") = uint32_t{}, py::arg("pixelY") = uint32_t{}, py::arg("sample") = uint32_t{});

    s_vk_CoarseSampleOrderCustomNV.def(py::init<vk::ShadingRatePaletteEntryNV, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::CoarseSampleLocationNV> &>(), py::arg("shading_rate"), py::arg("sample_count"), py::arg("sample_locations"));

    s_vk_PhysicalDeviceShadingRateImageFeaturesNV.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("shading_rate_image") = vk::Bool32{}, py::arg("shading_rate_coarse_sample_order") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShadingRateImagePropertiesNV.def(py::init<vk::Extent2D, uint32_t, uint32_t, void *>(), py::arg("shading_rate_texel_size") = vk::Extent2D{}, py::arg("shading_rate_palette_size") = uint32_t{}, py::arg("shading_rate_max_coarse_samples") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PipelineViewportCoarseSampleOrderStateCreateInfoNV.def(py::init<vk::CoarseSampleOrderTypeNV, const vk::ArrayProxyNoTemporaries<const vk::CoarseSampleOrderCustomNV> &, const void *>(), py::arg("sample_order_type"), py::arg("custom_sample_orders"), py::arg("p_next") = nullptr);

    s_vk_PipelineViewportShadingRateImageStateCreateInfoNV.def(py::init<vk::Bool32, const vk::ArrayProxyNoTemporaries<const vk::ShadingRatePaletteNV> &, const void *>(), py::arg("shading_rate_image_enable"), py::arg("shading_rate_palettes"), py::arg("p_next") = nullptr);

    s_vk_ShadingRatePaletteNV.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::ShadingRatePaletteEntryNV> &>(), py::arg("shading_rate_palette_entries"));

    s_vk_AccelerationStructureCreateInfoNV.def(py::init<vk::DeviceSize, vk::AccelerationStructureInfoNV, const void *>(), py::arg("compacted_size") = vk::DeviceSize{}, py::arg("info") = vk::AccelerationStructureInfoNV{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureInfoNV.def(py::init<vk::AccelerationStructureTypeNV, vk::BuildAccelerationStructureFlagsNV, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::GeometryNV> &, const void *>(), py::arg("type"), py::arg("flags"), py::arg("instance_count"), py::arg("geometries"), py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureMemoryRequirementsInfoNV.def(py::init<vk::AccelerationStructureMemoryRequirementsTypeNV, vk::AccelerationStructureNV, const void *>(), py::arg("type") = VULKAN_HPP_NAMESPACE::AccelerationStructureMemoryRequirementsTypeNV::eObject, py::arg("acceleration_structure") = vk::AccelerationStructureNV{}, py::arg("p_next") = nullptr);

    s_vk_BindAccelerationStructureMemoryInfoNV.def(py::init<vk::AccelerationStructureNV, vk::DeviceMemory, vk::DeviceSize, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("acceleration_structure"), py::arg("memory"), py::arg("memory_offset"), py::arg("device_indices"), py::arg("p_next") = nullptr);

    s_vk_GeometryAABBNV.def(py::init<vk::Buffer, uint32_t, uint32_t, vk::DeviceSize, const void *>(), py::arg("aabb_data") = vk::Buffer{}, py::arg("numAAB_bs") = uint32_t{}, py::arg("stride") = uint32_t{}, py::arg("offset") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_GeometryDataNV.def(py::init<vk::GeometryTrianglesNV, vk::GeometryAABBNV>(), py::arg("triangles") = vk::GeometryTrianglesNV{}, py::arg("aabbs") = vk::GeometryAABBNV{});

    s_vk_GeometryNV.def(py::init<vk::GeometryTypeKHR, vk::GeometryDataNV, vk::GeometryFlagsKHR, const void *>(), py::arg("geometry_type") = VULKAN_HPP_NAMESPACE::GeometryTypeKHR::eTriangles, py::arg("geometry") = vk::GeometryDataNV{}, py::arg("flags") = vk::GeometryFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_GeometryTrianglesNV.def(py::init<vk::Buffer, vk::DeviceSize, uint32_t, vk::DeviceSize, vk::Format, vk::Buffer, vk::DeviceSize, uint32_t, vk::IndexType, vk::Buffer, vk::DeviceSize, const void *>(), py::arg("vertex_data") = vk::Buffer{}, py::arg("vertex_offset") = vk::DeviceSize{}, py::arg("vertex_count") = uint32_t{}, py::arg("vertex_stride") = vk::DeviceSize{}, py::arg("vertex_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("index_data") = vk::Buffer{}, py::arg("index_offset") = vk::DeviceSize{}, py::arg("index_count") = uint32_t{}, py::arg("index_type") = VULKAN_HPP_NAMESPACE::IndexType::eUint16, py::arg("transform_data") = vk::Buffer{}, py::arg("transform_offset") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRayTracingPropertiesNV.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint64_t, uint64_t, uint64_t, uint32_t, void *>(), py::arg("shader_group_handle_size") = uint32_t{}, py::arg("max_recursion_depth") = uint32_t{}, py::arg("max_shader_group_stride") = uint32_t{}, py::arg("shader_group_base_alignment") = uint32_t{}, py::arg("max_geometry_count") = uint64_t{}, py::arg("max_instance_count") = uint64_t{}, py::arg("max_triangle_count") = uint64_t{}, py::arg("max_descriptor_set_acceleration_structures") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_RayTracingPipelineCreateInfoNV.def(py::init<vk::PipelineCreateFlags, const vk::ArrayProxyNoTemporaries<const vk::PipelineShaderStageCreateInfo> &, const vk::ArrayProxyNoTemporaries<const vk::RayTracingShaderGroupCreateInfoNV> &, uint32_t, vk::PipelineLayout, vk::Pipeline, int32_t, const void *>(), py::arg("flags"), py::arg("stages"), py::arg("groups") = vk::ArrayProxyNoTemporaries<const vk::RayTracingShaderGroupCreateInfoNV>{}, py::arg("max_recursion_depth") = uint32_t{}, py::arg("layout") = vk::PipelineLayout{}, py::arg("base_pipeline_handle") = vk::Pipeline{}, py::arg("base_pipeline_index") = int32_t{}, py::arg("p_next") = nullptr);

    s_vk_RayTracingShaderGroupCreateInfoNV.def(py::init<vk::RayTracingShaderGroupTypeKHR, uint32_t, uint32_t, uint32_t, uint32_t, const void *>(), py::arg("type") = VULKAN_HPP_NAMESPACE::RayTracingShaderGroupTypeKHR::eGeneral, py::arg("general_shader") = VULKAN_HPP_NAMESPACE::ShaderUnusedNV, py::arg("closest_hit_shader") = VULKAN_HPP_NAMESPACE::ShaderUnusedNV, py::arg("any_hit_shader") = VULKAN_HPP_NAMESPACE::ShaderUnusedNV, py::arg("intersection_shader") = VULKAN_HPP_NAMESPACE::ShaderUnusedNV, py::arg("p_next") = nullptr);

    s_vk_WriteDescriptorSetAccelerationStructureNV.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::AccelerationStructureNV> &, const void *>(), py::arg("acceleration_structures"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRepresentativeFragmentTestFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("representative_fragment_test") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineRepresentativeFragmentTestStateCreateInfoNV.def(py::init<vk::Bool32, const void *>(), py::arg("representative_fragment_test_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_FilterCubicImageViewImageFormatPropertiesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("filter_cubic") = vk::Bool32{}, py::arg("filter_cubic_minmax") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageViewImageFormatInfoEXT.def(py::init<vk::ImageViewType, void *>(), py::arg("image_view_type") = VULKAN_HPP_NAMESPACE::ImageViewType::e1D, py::arg("p_next") = nullptr);

    s_vk_ImportMemoryHostPointerInfoEXT.def(py::init<vk::ExternalMemoryHandleTypeFlagBits, void *, const void *>(), py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalMemoryHandleTypeFlagBits::eOpaqueFd, py::arg("p_host_pointer") = nullptr, py::arg("p_next") = nullptr);

    s_vk_MemoryHostPointerPropertiesEXT.def(py::init<uint32_t, void *>(), py::arg("memory_type_bits") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExternalMemoryHostPropertiesEXT.def(py::init<vk::DeviceSize, void *>(), py::arg("min_imported_host_pointer_alignment") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderClockFeaturesKHR.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("shader_subgroup_clock") = vk::Bool32{}, py::arg("shader_device_clock") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineCompilerControlCreateInfoAMD.def(py::init<vk::PipelineCompilerControlFlagsAMD, const void *>(), py::arg("compiler_control_flags") = vk::PipelineCompilerControlFlagsAMD{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderCorePropertiesAMD.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void *>(), py::arg("shader_engine_count") = uint32_t{}, py::arg("shader_arrays_per_engine_count") = uint32_t{}, py::arg("compute_units_per_shader_array") = uint32_t{}, py::arg("simd_per_compute_unit") = uint32_t{}, py::arg("wavefronts_per_simd") = uint32_t{}, py::arg("wavefront_size") = uint32_t{}, py::arg("sgprs_per_simd") = uint32_t{}, py::arg("min_sgpr_allocation") = uint32_t{}, py::arg("max_sgpr_allocation") = uint32_t{}, py::arg("sgpr_allocation_granularity") = uint32_t{}, py::arg("vgprs_per_simd") = uint32_t{}, py::arg("min_vgpr_allocation") = uint32_t{}, py::arg("max_vgpr_allocation") = uint32_t{}, py::arg("vgpr_allocation_granularity") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH265CapabilitiesKHR.def(py::init<StdVideoH265LevelIdc, void *>(), py::arg("max_level_idc") = StdVideoH265LevelIdc{}, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH265DpbSlotInfoKHR.def(py::init<const StdVideoDecodeH265ReferenceInfo *, const void *>(), py::arg("p_std_reference_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH265PictureInfoKHR.def(py::init<const StdVideoDecodeH265PictureInfo *, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("p_std_picture_info"), py::arg("slice_segment_offsets"), py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH265ProfileInfoKHR.def(py::init<StdVideoH265ProfileIdc, const void *>(), py::arg("std_profile_idc") = StdVideoH265ProfileIdc{}, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH265SessionParametersAddInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const StdVideoH265VideoParameterSet> &, const vk::ArrayProxyNoTemporaries<const StdVideoH265SequenceParameterSet> &, const vk::ArrayProxyNoTemporaries<const StdVideoH265PictureParameterSet> &, const void *>(), py::arg("stdVP_ss"), py::arg("stdSP_ss") = vk::ArrayProxyNoTemporaries<const StdVideoH265SequenceParameterSet>{}, py::arg("stdPP_ss") = vk::ArrayProxyNoTemporaries<const StdVideoH265PictureParameterSet>{}, py::arg("p_next") = nullptr);

    s_vk_VideoDecodeH265SessionParametersCreateInfoKHR.def(py::init<uint32_t, uint32_t, uint32_t, const vk::VideoDecodeH265SessionParametersAddInfoKHR *, const void *>(), py::arg("max_std_VPS_count") = uint32_t{}, py::arg("max_std_SPS_count") = uint32_t{}, py::arg("max_std_PPS_count") = uint32_t{}, py::arg("p_parameters_add_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_DeviceQueueGlobalPriorityCreateInfoKHR.def(py::init<vk::QueueGlobalPriorityKHR, const void *>(), py::arg("global_priority") = VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceGlobalPriorityQueryFeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("global_priority_query") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_QueueFamilyGlobalPriorityPropertiesKHR.def(py::init<uint32_t, const std::array<vk::QueueGlobalPriorityKHR, 16U> &, void *>(), py::arg("priority_count") = uint32_t{}, py::arg("priorities") = std::array<vk::QueueGlobalPriorityKHR, 16U>{ { VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow, VULKAN_HPP_NAMESPACE::QueueGlobalPriorityKHR::eLow } }, py::arg("p_next") = nullptr);

    s_vk_DeviceMemoryOverallocationCreateInfoAMD.def(py::init<vk::MemoryOverallocationBehaviorAMD, const void *>(), py::arg("overallocation_behavior") = VULKAN_HPP_NAMESPACE::MemoryOverallocationBehaviorAMD::eDefault, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVertexAttributeDivisorPropertiesEXT.def(py::init<uint32_t, void *>(), py::arg("max_vertex_attrib_divisor") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceComputeShaderDerivativesFeaturesNV.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("compute_derivative_group_quads") = vk::Bool32{}, py::arg("compute_derivative_group_linear") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_DrawMeshTasksIndirectCommandNV.def(py::init<uint32_t, uint32_t>(), py::arg("task_count") = uint32_t{}, py::arg("first_task") = uint32_t{});

    s_vk_PhysicalDeviceMeshShaderFeaturesNV.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("task_shader") = vk::Bool32{}, py::arg("mesh_shader") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMeshShaderPropertiesNV.def(py::init<uint32_t, uint32_t, const std::array<uint32_t, 3> &, uint32_t, uint32_t, uint32_t, const std::array<uint32_t, 3> &, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void *>(), py::arg("max_draw_mesh_tasks_count") = uint32_t{}, py::arg("max_task_work_group_invocations") = uint32_t{}, py::arg("max_task_work_group_size") = std::array<uint32_t, 3>{}, py::arg("max_task_total_memory_size") = uint32_t{}, py::arg("max_task_output_count") = uint32_t{}, py::arg("max_mesh_work_group_invocations") = uint32_t{}, py::arg("max_mesh_work_group_size") = std::array<uint32_t, 3>{}, py::arg("max_mesh_total_memory_size") = uint32_t{}, py::arg("max_mesh_output_vertices") = uint32_t{}, py::arg("max_mesh_output_primitives") = uint32_t{}, py::arg("max_mesh_multiview_view_count") = uint32_t{}, py::arg("mesh_output_per_vertex_granularity") = uint32_t{}, py::arg("mesh_output_per_primitive_granularity") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderImageFootprintFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("image_footprint") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExclusiveScissorFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("exclusive_scissor") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineViewportExclusiveScissorStateCreateInfoNV.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Rect2D> &, const void *>(), py::arg("exclusive_scissors"), py::arg("p_next") = nullptr);

    s_vk_CheckpointDataNV.def(py::init<vk::PipelineStageFlagBits, void *, void *>(), py::arg("stage") = VULKAN_HPP_NAMESPACE::PipelineStageFlagBits::eTopOfPipe, py::arg("p_checkpoint_marker") = nullptr, py::arg("p_next") = nullptr);

    s_vk_QueueFamilyCheckpointPropertiesNV.def(py::init<vk::PipelineStageFlags, void *>(), py::arg("checkpoint_execution_stage_mask") = vk::PipelineStageFlags{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL.def(py::init<vk::Bool32, void *>(), py::arg("shader_integer_functions_2") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_InitializePerformanceApiInfoINTEL.def(py::init<void *, const void *>(), py::arg("p_user_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PerformanceConfigurationAcquireInfoINTEL.def(py::init<vk::PerformanceConfigurationTypeINTEL, const void *>(), py::arg("type") = VULKAN_HPP_NAMESPACE::PerformanceConfigurationTypeINTEL::eCommandQueueMetricsDiscoveryActivated, py::arg("p_next") = nullptr);

    s_vk_PerformanceMarkerInfoINTEL.def(py::init<uint64_t, const void *>(), py::arg("marker") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_PerformanceOverrideInfoINTEL.def(py::init<vk::PerformanceOverrideTypeINTEL, vk::Bool32, uint64_t, const void *>(), py::arg("type") = VULKAN_HPP_NAMESPACE::PerformanceOverrideTypeINTEL::eNullHardware, py::arg("enable") = vk::Bool32{}, py::arg("parameter") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_PerformanceStreamMarkerInfoINTEL.def(py::init<uint32_t, const void *>(), py::arg("marker") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PerformanceValueINTEL.def(py::init<vk::PerformanceValueTypeINTEL, vk::PerformanceValueDataINTEL>(), py::arg("type") = VULKAN_HPP_NAMESPACE::PerformanceValueTypeINTEL::eUint32, py::arg("data") = vk::PerformanceValueDataINTEL{});

    s_vk_QueryPoolPerformanceQueryCreateInfoINTEL.def(py::init<vk::QueryPoolSamplingModeINTEL, const void *>(), py::arg("performance_counters_sampling") = VULKAN_HPP_NAMESPACE::QueryPoolSamplingModeINTEL::eManual, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePCIBusInfoPropertiesEXT.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, void *>(), py::arg("pci_domain") = uint32_t{}, py::arg("pci_bus") = uint32_t{}, py::arg("pci_device") = uint32_t{}, py::arg("pci_function") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DisplayNativeHdrSurfaceCapabilitiesAMD.def(py::init<vk::Bool32, void *>(), py::arg("local_dimming_support") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SwapchainDisplayNativeHdrCreateInfoAMD.def(py::init<vk::Bool32, const void *>(), py::arg("local_dimming_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentDensityMapFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("fragment_density_map") = vk::Bool32{}, py::arg("fragment_density_map_dynamic") = vk::Bool32{}, py::arg("fragment_density_map_non_subsampled_images") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentDensityMapPropertiesEXT.def(py::init<vk::Extent2D, vk::Extent2D, vk::Bool32, void *>(), py::arg("min_fragment_density_texel_size") = vk::Extent2D{}, py::arg("max_fragment_density_texel_size") = vk::Extent2D{}, py::arg("fragment_density_invocations") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_RenderPassFragmentDensityMapCreateInfoEXT.def(py::init<vk::AttachmentReference, const void *>(), py::arg("fragment_density_map_attachment") = vk::AttachmentReference{}, py::arg("p_next") = nullptr);

    s_vk_FragmentShadingRateAttachmentInfoKHR.def(py::init<const vk::AttachmentReference2 *, vk::Extent2D, const void *>(), py::arg("p_fragment_shading_rate_attachment") = nullptr, py::arg("shading_rate_attachment_texel_size") = vk::Extent2D{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentShadingRateFeaturesKHR.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("pipeline_fragment_shading_rate") = vk::Bool32{}, py::arg("primitive_fragment_shading_rate") = vk::Bool32{}, py::arg("attachment_fragment_shading_rate") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentShadingRateKHR.def(py::init<vk::SampleCountFlags, vk::Extent2D, void *>(), py::arg("sample_counts") = vk::SampleCountFlags{}, py::arg("fragment_size") = vk::Extent2D{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentShadingRatePropertiesKHR.def(py::init<vk::Extent2D, vk::Extent2D, uint32_t, vk::Bool32, vk::Bool32, vk::Bool32, vk::Extent2D, uint32_t, uint32_t, vk::SampleCountFlagBits, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("min_fragment_shading_rate_attachment_texel_size") = vk::Extent2D{}, py::arg("max_fragment_shading_rate_attachment_texel_size") = vk::Extent2D{}, py::arg("max_fragment_shading_rate_attachment_texel_size_aspect_ratio") = uint32_t{}, py::arg("primitive_fragment_shading_rate_with_multiple_viewports") = vk::Bool32{}, py::arg("layered_shading_rate_attachments") = vk::Bool32{}, py::arg("fragment_shading_rate_non_trivial_combiner_ops") = vk::Bool32{}, py::arg("max_fragment_size") = vk::Extent2D{}, py::arg("max_fragment_size_aspect_ratio") = uint32_t{}, py::arg("max_fragment_shading_rate_coverage_samples") = uint32_t{}, py::arg("max_fragment_shading_rate_rasterization_samples") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("fragment_shading_rate_with_shader_depth_stencil_writes") = vk::Bool32{}, py::arg("fragment_shading_rate_with_sample_mask") = vk::Bool32{}, py::arg("fragment_shading_rate_with_shader_sample_mask") = vk::Bool32{}, py::arg("fragment_shading_rate_with_conservative_rasterization") = vk::Bool32{}, py::arg("fragment_shading_rate_with_fragment_shader_interlock") = vk::Bool32{}, py::arg("fragment_shading_rate_with_custom_sample_locations") = vk::Bool32{}, py::arg("fragment_shading_rate_strict_multiply_combiner") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineFragmentShadingRateStateCreateInfoKHR.def(py::init<vk::Extent2D, const std::array<vk::FragmentShadingRateCombinerOpKHR, 2> &, const void *>(), py::arg("fragment_size") = vk::Extent2D{}, py::arg("combiner_ops") = std::array<vk::FragmentShadingRateCombinerOpKHR, 2>{ { VULKAN_HPP_NAMESPACE::FragmentShadingRateCombinerOpKHR::eKeep, VULKAN_HPP_NAMESPACE::FragmentShadingRateCombinerOpKHR::eKeep } }, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderCoreProperties2AMD.def(py::init<vk::ShaderCorePropertiesFlagsAMD, uint32_t, void *>(), py::arg("shader_core_features") = vk::ShaderCorePropertiesFlagsAMD{}, py::arg("active_compute_unit_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCoherentMemoryFeaturesAMD.def(py::init<vk::Bool32, void *>(), py::arg("device_coherent_memory") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderImageAtomicInt64FeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("shader_image_int_64_atomics") = vk::Bool32{}, py::arg("sparse_image_int_64_atomics") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMemoryBudgetPropertiesEXT.def(py::init<const std::array<vk::DeviceSize, 16U> &, const std::array<vk::DeviceSize, 16U> &, void *>(), py::arg("heap_budget") = std::array<vk::DeviceSize, 16U>{}, py::arg("heap_usage") = std::array<vk::DeviceSize, 16U>{}, py::arg("p_next") = nullptr);

    s_vk_MemoryPriorityAllocateInfoEXT.def(py::init<float, const void *>(), py::arg("priority") = float{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMemoryPriorityFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("memory_priority") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SurfaceProtectedCapabilitiesKHR.def(py::init<vk::Bool32, const void *>(), py::arg("supports_protected") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("dedicated_allocation_image_aliasing") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_BufferDeviceAddressCreateInfoEXT.def(py::init<vk::DeviceAddress, const void *>(), py::arg("device_address") = vk::DeviceAddress{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceBufferDeviceAddressFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("buffer_device_address") = vk::Bool32{}, py::arg("buffer_device_address_capture_replay") = vk::Bool32{}, py::arg("buffer_device_address_multi_device") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_ValidationFeaturesEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::ValidationFeatureEnableEXT> &, const vk::ArrayProxyNoTemporaries<const vk::ValidationFeatureDisableEXT> &, const void *>(), py::arg("enabled_validation_features"), py::arg("disabled_validation_features") = vk::ArrayProxyNoTemporaries<const vk::ValidationFeatureDisableEXT>{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePresentWaitFeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("present_wait") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_CooperativeMatrixPropertiesNV.def(py::init<uint32_t, uint32_t, uint32_t, vk::ComponentTypeNV, vk::ComponentTypeNV, vk::ComponentTypeNV, vk::ComponentTypeNV, vk::ScopeNV, void *>(), py::arg("m_size") = uint32_t{}, py::arg("n_size") = uint32_t{}, py::arg("k_size") = uint32_t{}, py::arg("a_type") = vk::ComponentTypeNV{}, py::arg("b_type") = vk::ComponentTypeNV{}, py::arg("c_type") = vk::ComponentTypeNV{}, py::arg("d_type") = vk::ComponentTypeNV{}, py::arg("scope") = vk::ScopeNV{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCooperativeMatrixFeaturesNV.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("cooperative_matrix") = vk::Bool32{}, py::arg("cooperative_matrix_robust_buffer_access") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCooperativeMatrixPropertiesNV.def(py::init<vk::ShaderStageFlags, void *>(), py::arg("cooperative_matrix_supported_stages") = vk::ShaderStageFlags{}, py::arg("p_next") = nullptr);

    s_vk_FramebufferMixedSamplesCombinationNV.def(py::init<vk::CoverageReductionModeNV, vk::SampleCountFlagBits, vk::SampleCountFlags, vk::SampleCountFlags, void *>(), py::arg("coverage_reduction_mode") = VULKAN_HPP_NAMESPACE::CoverageReductionModeNV::eMerge, py::arg("rasterization_samples") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("depth_stencil_samples") = vk::SampleCountFlags{}, py::arg("color_samples") = vk::SampleCountFlags{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCoverageReductionModeFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("coverage_reduction_mode") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineCoverageReductionStateCreateInfoNV.def(py::init<vk::PipelineCoverageReductionStateCreateFlagsNV, vk::CoverageReductionModeNV, const void *>(), py::arg("flags") = vk::PipelineCoverageReductionStateCreateFlagsNV{}, py::arg("coverage_reduction_mode") = VULKAN_HPP_NAMESPACE::CoverageReductionModeNV::eMerge, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentShaderInterlockFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("fragment_shader_sample_interlock") = vk::Bool32{}, py::arg("fragment_shader_pixel_interlock") = vk::Bool32{}, py::arg("fragment_shader_shading_rate_interlock") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceYcbcrImageArraysFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("ycbcr_image_arrays") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceProvokingVertexFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("provoking_vertex_last") = vk::Bool32{}, py::arg("transform_feedback_preserves_provoking_vertex") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceProvokingVertexPropertiesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("provoking_vertex_mode_per_pipeline") = vk::Bool32{}, py::arg("transform_feedback_preserves_triangle_fan_provoking_vertex") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineRasterizationProvokingVertexStateCreateInfoEXT.def(py::init<vk::ProvokingVertexModeEXT, const void *>(), py::arg("provoking_vertex_mode") = VULKAN_HPP_NAMESPACE::ProvokingVertexModeEXT::eFirstVertex, py::arg("p_next") = nullptr);

    s_vk_HeadlessSurfaceCreateInfoEXT.def(py::init<vk::HeadlessSurfaceCreateFlagsEXT, const void *>(), py::arg("flags") = vk::HeadlessSurfaceCreateFlagsEXT{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceLineRasterizationFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("rectangular_lines") = vk::Bool32{}, py::arg("bresenham_lines") = vk::Bool32{}, py::arg("smooth_lines") = vk::Bool32{}, py::arg("stippled_rectangular_lines") = vk::Bool32{}, py::arg("stippled_bresenham_lines") = vk::Bool32{}, py::arg("stippled_smooth_lines") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceLineRasterizationPropertiesEXT.def(py::init<uint32_t, void *>(), py::arg("line_sub_pixel_precision_bits") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PipelineRasterizationLineStateCreateInfoEXT.def(py::init<vk::LineRasterizationModeEXT, vk::Bool32, uint32_t, uint16_t, const void *>(), py::arg("line_rasterization_mode") = VULKAN_HPP_NAMESPACE::LineRasterizationModeEXT::eDefault, py::arg("stippled_line_enable") = vk::Bool32{}, py::arg("line_stipple_factor") = uint32_t{}, py::arg("line_stipple_pattern") = uint16_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderAtomicFloatFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("shader_buffer_float_32_atomics") = vk::Bool32{}, py::arg("shader_buffer_float_32_atomic_add") = vk::Bool32{}, py::arg("shader_buffer_float_64_atomics") = vk::Bool32{}, py::arg("shader_buffer_float_64_atomic_add") = vk::Bool32{}, py::arg("shader_shared_float_32_atomics") = vk::Bool32{}, py::arg("shader_shared_float_32_atomic_add") = vk::Bool32{}, py::arg("shader_shared_float_64_atomics") = vk::Bool32{}, py::arg("shader_shared_float_64_atomic_add") = vk::Bool32{}, py::arg("shader_image_float_32_atomics") = vk::Bool32{}, py::arg("shader_image_float_32_atomic_add") = vk::Bool32{}, py::arg("sparse_image_float_32_atomics") = vk::Bool32{}, py::arg("sparse_image_float_32_atomic_add") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceIndexTypeUint8FeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("index_type_uint_8") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExtendedDynamicStateFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("extended_dynamic_state") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePipelineExecutablePropertiesFeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("pipeline_executable_info") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineExecutableInfoKHR.def(py::init<vk::Pipeline, uint32_t, const void *>(), py::arg("pipeline") = vk::Pipeline{}, py::arg("executable_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PipelineExecutableInternalRepresentationKHR.def(py::init<const std::array<char, 256U> &, const std::array<char, 256U> &, vk::Bool32, size_t, void *, void *>(), py::arg("name") = std::array<char, 256U>{}, py::arg("description") = std::array<char, 256U>{}, py::arg("is_text") = vk::Bool32{}, py::arg("data_size") = size_t{}, py::arg("p_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PipelineExecutablePropertiesKHR.def(py::init<vk::ShaderStageFlags, const std::array<char, 256U> &, const std::array<char, 256U> &, uint32_t, void *>(), py::arg("stages") = vk::ShaderStageFlags{}, py::arg("name") = std::array<char, 256U>{}, py::arg("description") = std::array<char, 256U>{}, py::arg("subgroup_size") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PipelineExecutableStatisticKHR.def(py::init<const std::array<char, 256U> &, const std::array<char, 256U> &, vk::PipelineExecutableStatisticFormatKHR, vk::PipelineExecutableStatisticValueKHR, void *>(), py::arg("name") = std::array<char, 256U>{}, py::arg("description") = std::array<char, 256U>{}, py::arg("format") = VULKAN_HPP_NAMESPACE::PipelineExecutableStatisticFormatKHR::eBool32, py::arg("value") = vk::PipelineExecutableStatisticValueKHR{}, py::arg("p_next") = nullptr);

    s_vk_PipelineInfoKHR.def(py::init<vk::Pipeline, const void *>(), py::arg("pipeline") = vk::Pipeline{}, py::arg("p_next") = nullptr);

    s_vk_CopyImageToImageInfoEXT.def(py::init<vk::HostImageCopyFlagsEXT, vk::Image, vk::ImageLayout, vk::Image, vk::ImageLayout, const vk::ArrayProxyNoTemporaries<const vk::ImageCopy2> &, const void *>(), py::arg("flags"), py::arg("src_image"), py::arg("src_image_layout"), py::arg("dst_image"), py::arg("dst_image_layout"), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_CopyImageToMemoryInfoEXT.def(py::init<vk::HostImageCopyFlagsEXT, vk::Image, vk::ImageLayout, const vk::ArrayProxyNoTemporaries<const vk::ImageToMemoryCopyEXT> &, const void *>(), py::arg("flags"), py::arg("src_image"), py::arg("src_image_layout"), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_CopyMemoryToImageInfoEXT.def(py::init<vk::HostImageCopyFlagsEXT, vk::Image, vk::ImageLayout, const vk::ArrayProxyNoTemporaries<const vk::MemoryToImageCopyEXT> &, const void *>(), py::arg("flags"), py::arg("dst_image"), py::arg("dst_image_layout"), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_HostImageCopyDevicePerformanceQueryEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("optimal_device_access") = vk::Bool32{}, py::arg("identical_memory_layout") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_HostImageLayoutTransitionInfoEXT.def(py::init<vk::Image, vk::ImageLayout, vk::ImageLayout, vk::ImageSubresourceRange, const void *>(), py::arg("image") = vk::Image{}, py::arg("old_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("new_layout") = VULKAN_HPP_NAMESPACE::ImageLayout::eUndefined, py::arg("subresource_range") = vk::ImageSubresourceRange{}, py::arg("p_next") = nullptr);

    s_vk_ImageToMemoryCopyEXT.def(py::init<void *, uint32_t, uint32_t, vk::ImageSubresourceLayers, vk::Offset3D, vk::Extent3D, const void *>(), py::arg("p_host_pointer") = nullptr, py::arg("memory_row_length") = uint32_t{}, py::arg("memory_image_height") = uint32_t{}, py::arg("image_subresource") = vk::ImageSubresourceLayers{}, py::arg("image_offset") = vk::Offset3D{}, py::arg("image_extent") = vk::Extent3D{}, py::arg("p_next") = nullptr);

    s_vk_MemoryToImageCopyEXT.def(py::init<const void *, uint32_t, uint32_t, vk::ImageSubresourceLayers, vk::Offset3D, vk::Extent3D, const void *>(), py::arg("p_host_pointer") = nullptr, py::arg("memory_row_length") = uint32_t{}, py::arg("memory_image_height") = uint32_t{}, py::arg("image_subresource") = vk::ImageSubresourceLayers{}, py::arg("image_offset") = vk::Offset3D{}, py::arg("image_extent") = vk::Extent3D{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceHostImageCopyFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("host_image_copy") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceHostImageCopyPropertiesEXT.def(py::init<const vk::ArrayProxyNoTemporaries<vk::ImageLayout> &, const vk::ArrayProxyNoTemporaries<vk::ImageLayout> &, const std::array<uint8_t, 16U> &, vk::Bool32, void *>(), py::arg("copy_src_layouts"), py::arg("copy_dst_layouts") = vk::ArrayProxyNoTemporaries<vk::ImageLayout>{}, py::arg("optimal_tiling_layout_UUID") = std::array<uint8_t, 16U>{}, py::arg("identical_memory_type_requirements") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SubresourceHostMemcpySizeEXT.def(py::init<vk::DeviceSize, void *>(), py::arg("size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_MemoryMapInfoKHR.def(py::init<vk::MemoryMapFlags, vk::DeviceMemory, vk::DeviceSize, vk::DeviceSize, const void *>(), py::arg("flags") = vk::MemoryMapFlags{}, py::arg("memory") = vk::DeviceMemory{}, py::arg("offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_MemoryUnmapInfoKHR.def(py::init<vk::MemoryUnmapFlagsKHR, vk::DeviceMemory, const void *>(), py::arg("flags") = vk::MemoryUnmapFlagsKHR{}, py::arg("memory") = vk::DeviceMemory{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderAtomicFloat2FeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("shader_buffer_float_16_atomics") = vk::Bool32{}, py::arg("shader_buffer_float_16_atomic_add") = vk::Bool32{}, py::arg("shader_buffer_float_16_atomic_min_max") = vk::Bool32{}, py::arg("shader_buffer_float_32_atomic_min_max") = vk::Bool32{}, py::arg("shader_buffer_float_64_atomic_min_max") = vk::Bool32{}, py::arg("shader_shared_float_16_atomics") = vk::Bool32{}, py::arg("shader_shared_float_16_atomic_add") = vk::Bool32{}, py::arg("shader_shared_float_16_atomic_min_max") = vk::Bool32{}, py::arg("shader_shared_float_32_atomic_min_max") = vk::Bool32{}, py::arg("shader_shared_float_64_atomic_min_max") = vk::Bool32{}, py::arg("shader_image_float_32_atomic_min_max") = vk::Bool32{}, py::arg("sparse_image_float_32_atomic_min_max") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SurfacePresentModeCompatibilityEXT.def(py::init<const vk::ArrayProxyNoTemporaries<vk::PresentModeKHR> &, void *>(), py::arg("present_modes"), py::arg("p_next") = nullptr);

    s_vk_SurfacePresentModeEXT.def(py::init<vk::PresentModeKHR, void *>(), py::arg("present_mode") = VULKAN_HPP_NAMESPACE::PresentModeKHR::eImmediate, py::arg("p_next") = nullptr);

    s_vk_SurfacePresentScalingCapabilitiesEXT.def(py::init<vk::PresentScalingFlagsEXT, vk::PresentGravityFlagsEXT, vk::PresentGravityFlagsEXT, vk::Extent2D, vk::Extent2D, void *>(), py::arg("supported_present_scaling") = vk::PresentScalingFlagsEXT{}, py::arg("supported_present_gravity_x") = vk::PresentGravityFlagsEXT{}, py::arg("supported_present_gravity_y") = vk::PresentGravityFlagsEXT{}, py::arg("min_scaled_image_extent") = vk::Extent2D{}, py::arg("max_scaled_image_extent") = vk::Extent2D{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSwapchainMaintenance1FeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("swapchain_maintenance_1") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_ReleaseSwapchainImagesInfoEXT.def(py::init<vk::SwapchainKHR, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("swapchain"), py::arg("image_indices"), py::arg("p_next") = nullptr);

    s_vk_SwapchainPresentFenceInfoEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Fence> &, const void *>(), py::arg("fences"), py::arg("p_next") = nullptr);

    s_vk_SwapchainPresentModeInfoEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::PresentModeKHR> &, const void *>(), py::arg("present_modes"), py::arg("p_next") = nullptr);

    s_vk_SwapchainPresentModesCreateInfoEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::PresentModeKHR> &, const void *>(), py::arg("present_modes"), py::arg("p_next") = nullptr);

    s_vk_SwapchainPresentScalingCreateInfoEXT.def(py::init<vk::PresentScalingFlagsEXT, vk::PresentGravityFlagsEXT, vk::PresentGravityFlagsEXT, const void *>(), py::arg("scaling_behavior") = vk::PresentScalingFlagsEXT{}, py::arg("present_gravity_x") = vk::PresentGravityFlagsEXT{}, py::arg("present_gravity_y") = vk::PresentGravityFlagsEXT{}, py::arg("p_next") = nullptr);

    s_vk_BindIndexBufferIndirectCommandNV.def(py::init<vk::DeviceAddress, uint32_t, vk::IndexType>(), py::arg("buffer_address") = vk::DeviceAddress{}, py::arg("size") = uint32_t{}, py::arg("index_type") = VULKAN_HPP_NAMESPACE::IndexType::eUint16);

    s_vk_BindShaderGroupIndirectCommandNV.def(py::init<uint32_t>(), py::arg("group_index") = uint32_t{});

    s_vk_BindVertexBufferIndirectCommandNV.def(py::init<vk::DeviceAddress, uint32_t, uint32_t>(), py::arg("buffer_address") = vk::DeviceAddress{}, py::arg("size") = uint32_t{}, py::arg("stride") = uint32_t{});

    s_vk_GeneratedCommandsInfoNV.def(py::init<vk::PipelineBindPoint, vk::Pipeline, vk::IndirectCommandsLayoutNV, const vk::ArrayProxyNoTemporaries<const vk::IndirectCommandsStreamNV> &, uint32_t, vk::Buffer, vk::DeviceSize, vk::DeviceSize, vk::Buffer, vk::DeviceSize, vk::Buffer, vk::DeviceSize, const void *>(), py::arg("pipeline_bind_point"), py::arg("pipeline"), py::arg("indirect_commands_layout"), py::arg("streams"), py::arg("sequences_count") = uint32_t{}, py::arg("preprocess_buffer") = vk::Buffer{}, py::arg("preprocess_offset") = vk::DeviceSize{}, py::arg("preprocess_size") = vk::DeviceSize{}, py::arg("sequences_count_buffer") = vk::Buffer{}, py::arg("sequences_count_offset") = vk::DeviceSize{}, py::arg("sequences_index_buffer") = vk::Buffer{}, py::arg("sequences_index_offset") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_GeneratedCommandsMemoryRequirementsInfoNV.def(py::init<vk::PipelineBindPoint, vk::Pipeline, vk::IndirectCommandsLayoutNV, uint32_t, const void *>(), py::arg("pipeline_bind_point") = VULKAN_HPP_NAMESPACE::PipelineBindPoint::eGraphics, py::arg("pipeline") = vk::Pipeline{}, py::arg("indirect_commands_layout") = vk::IndirectCommandsLayoutNV{}, py::arg("max_sequences_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_GraphicsPipelineShaderGroupsCreateInfoNV.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::GraphicsShaderGroupCreateInfoNV> &, const vk::ArrayProxyNoTemporaries<const vk::Pipeline> &, const void *>(), py::arg("groups"), py::arg("pipelines") = vk::ArrayProxyNoTemporaries<const vk::Pipeline>{}, py::arg("p_next") = nullptr);

    s_vk_GraphicsShaderGroupCreateInfoNV.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::PipelineShaderStageCreateInfo> &, const vk::PipelineVertexInputStateCreateInfo *, const vk::PipelineTessellationStateCreateInfo *, const void *>(), py::arg("stages"), py::arg("p_vertex_input_state") = nullptr, py::arg("p_tessellation_state") = nullptr, py::arg("p_next") = nullptr);

    s_vk_IndirectCommandsLayoutCreateInfoNV.def(py::init<vk::IndirectCommandsLayoutUsageFlagsNV, vk::PipelineBindPoint, const vk::ArrayProxyNoTemporaries<const vk::IndirectCommandsLayoutTokenNV> &, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("flags"), py::arg("pipeline_bind_point"), py::arg("tokens"), py::arg("stream_strides") = vk::ArrayProxyNoTemporaries<const uint32_t>{}, py::arg("p_next") = nullptr);

    s_vk_IndirectCommandsLayoutTokenNV.def(py::init<vk::IndirectCommandsTokenTypeNV, uint32_t, uint32_t, uint32_t, vk::Bool32, vk::PipelineLayout, vk::ShaderStageFlags, uint32_t, uint32_t, vk::IndirectStateFlagsNV, const vk::ArrayProxyNoTemporaries<const vk::IndexType> &, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("token_type"), py::arg("stream"), py::arg("offset"), py::arg("vertex_binding_unit"), py::arg("vertex_dynamic_stride"), py::arg("pushconstant_pipeline_layout"), py::arg("pushconstant_shader_stage_flags"), py::arg("pushconstant_offset"), py::arg("pushconstant_size"), py::arg("indirect_state_flags"), py::arg("index_types"), py::arg("index_type_values") = vk::ArrayProxyNoTemporaries<const uint32_t>{}, py::arg("p_next") = nullptr);

    s_vk_IndirectCommandsStreamNV.def(py::init<vk::Buffer, vk::DeviceSize>(), py::arg("buffer") = vk::Buffer{}, py::arg("offset") = vk::DeviceSize{});

    s_vk_PhysicalDeviceDeviceGeneratedCommandsFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("device_generated_commands") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDeviceGeneratedCommandsPropertiesNV.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void *>(), py::arg("max_graphics_shader_group_count") = uint32_t{}, py::arg("max_indirect_sequence_count") = uint32_t{}, py::arg("max_indirect_commands_token_count") = uint32_t{}, py::arg("max_indirect_commands_stream_count") = uint32_t{}, py::arg("max_indirect_commands_token_offset") = uint32_t{}, py::arg("max_indirect_commands_stream_stride") = uint32_t{}, py::arg("min_sequences_count_buffer_offset_alignment") = uint32_t{}, py::arg("min_sequences_index_buffer_offset_alignment") = uint32_t{}, py::arg("min_indirect_commands_buffer_offset_alignment") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_SetStateFlagsIndirectCommandNV.def(py::init<uint32_t>(), py::arg("data") = uint32_t{});

    s_vk_CommandBufferInheritanceViewportScissorInfoNV.def(py::init<vk::Bool32, uint32_t, const vk::Viewport *, const void *>(), py::arg("viewport_scissor_2d") = vk::Bool32{}, py::arg("viewport_depth_count") = uint32_t{}, py::arg("p_viewport_depths") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceInheritedViewportScissorFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("inherited_viewport_scissor_2d") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceTexelBufferAlignmentFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("texel_buffer_alignment") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_CommandBufferInheritanceRenderPassTransformInfoQCOM.def(py::init<vk::SurfaceTransformFlagBitsKHR, vk::Rect2D, void *>(), py::arg("transform") = VULKAN_HPP_NAMESPACE::SurfaceTransformFlagBitsKHR::eIdentity, py::arg("render_area") = vk::Rect2D{}, py::arg("p_next") = nullptr);

    s_vk_RenderPassTransformBeginInfoQCOM.def(py::init<vk::SurfaceTransformFlagBitsKHR, void *>(), py::arg("transform") = VULKAN_HPP_NAMESPACE::SurfaceTransformFlagBitsKHR::eIdentity, py::arg("p_next") = nullptr);

    s_vk_DepthBiasInfoEXT.def(py::init<float, float, float, const void *>(), py::arg("depth_bias_constant_factor") = float{}, py::arg("depth_bias_clamp") = float{}, py::arg("depth_bias_slope_factor") = float{}, py::arg("p_next") = nullptr);

    s_vk_DepthBiasRepresentationInfoEXT.def(py::init<vk::DepthBiasRepresentationEXT, vk::Bool32, const void *>(), py::arg("depth_bias_representation") = VULKAN_HPP_NAMESPACE::DepthBiasRepresentationEXT::eLeastRepresentableValueFormat, py::arg("depth_bias_exact") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDepthBiasControlFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("depth_bias_control") = vk::Bool32{}, py::arg("least_representable_value_force_unorm_representation") = vk::Bool32{}, py::arg("float_representation") = vk::Bool32{}, py::arg("depth_bias_exact") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_DeviceDeviceMemoryReportCreateInfoEXT.def(py::init<vk::DeviceMemoryReportFlagsEXT, PFN_vkDeviceMemoryReportCallbackEXT, void *, const void *>(), py::arg("flags") = vk::DeviceMemoryReportFlagsEXT{}, py::arg("pfn_user_callback") = PFN_vkDeviceMemoryReportCallbackEXT{}, py::arg("p_user_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_DeviceMemoryReportCallbackDataEXT.def(py::init<vk::DeviceMemoryReportFlagsEXT, vk::DeviceMemoryReportEventTypeEXT, uint64_t, vk::DeviceSize, vk::ObjectType, uint64_t, uint32_t, void *>(), py::arg("flags") = vk::DeviceMemoryReportFlagsEXT{}, py::arg("type") = VULKAN_HPP_NAMESPACE::DeviceMemoryReportEventTypeEXT::eAllocate, py::arg("memory_object_id") = uint64_t{}, py::arg("size") = vk::DeviceSize{}, py::arg("object_type") = VULKAN_HPP_NAMESPACE::ObjectType::eUnknown, py::arg("object_handle") = uint64_t{}, py::arg("heap_index") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDeviceMemoryReportFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("device_memory_report") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRobustness2FeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("robust_buffer_access_2") = vk::Bool32{}, py::arg("robust_image_access_2") = vk::Bool32{}, py::arg("null_descriptor") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRobustness2PropertiesEXT.def(py::init<vk::DeviceSize, vk::DeviceSize, void *>(), py::arg("robust_storage_buffer_access_size_alignment") = vk::DeviceSize{}, py::arg("robust_uniform_buffer_access_size_alignment") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCustomBorderColorFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("custom_border_colors") = vk::Bool32{}, py::arg("custom_border_color_without_format") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCustomBorderColorPropertiesEXT.def(py::init<uint32_t, void *>(), py::arg("max_custom_border_color_samplers") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_SamplerCustomBorderColorCreateInfoEXT.def(py::init<vk::ClearColorValue, vk::Format, const void *>(), py::arg("custom_border_color") = vk::ClearColorValue{}, py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("p_next") = nullptr);

    s_vk_PipelineLibraryCreateInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Pipeline> &, const void *>(), py::arg("libraries"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePresentBarrierFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("present_barrier") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SurfaceCapabilitiesPresentBarrierNV.def(py::init<vk::Bool32, void *>(), py::arg("present_barrier_supported") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SwapchainPresentBarrierCreateInfoNV.def(py::init<vk::Bool32, void *>(), py::arg("present_barrier_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePresentIdFeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("present_id") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PresentIdKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const uint64_t> &, const void *>(), py::arg("present_ids"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVideoEncodeQualityLevelInfoKHR.def(py::init<const vk::VideoProfileInfoKHR *, uint32_t, const void *>(), py::arg("p_video_profile") = nullptr, py::arg("quality_level") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_QueryPoolVideoEncodeFeedbackCreateInfoKHR.def(py::init<vk::VideoEncodeFeedbackFlagsKHR, const void *>(), py::arg("encode_feedback_flags") = vk::VideoEncodeFeedbackFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeCapabilitiesKHR.def(py::init<vk::VideoEncodeCapabilityFlagsKHR, vk::VideoEncodeRateControlModeFlagsKHR, uint32_t, uint64_t, uint32_t, vk::Extent2D, vk::VideoEncodeFeedbackFlagsKHR, void *>(), py::arg("flags") = vk::VideoEncodeCapabilityFlagsKHR{}, py::arg("rate_control_modes") = vk::VideoEncodeRateControlModeFlagsKHR{}, py::arg("max_rate_control_layers") = uint32_t{}, py::arg("max_bitrate") = uint64_t{}, py::arg("max_quality_levels") = uint32_t{}, py::arg("encode_input_picture_granularity") = vk::Extent2D{}, py::arg("supported_encode_feedback_flags") = vk::VideoEncodeFeedbackFlagsKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeInfoKHR.def(py::init<vk::VideoEncodeFlagsKHR, vk::Buffer, vk::DeviceSize, vk::DeviceSize, vk::VideoPictureResourceInfoKHR, const vk::VideoReferenceSlotInfoKHR *, const vk::ArrayProxyNoTemporaries<const vk::VideoReferenceSlotInfoKHR> &, uint32_t, const void *>(), py::arg("flags"), py::arg("dst_buffer"), py::arg("dst_buffer_offset"), py::arg("dst_buffer_range"), py::arg("src_picture_resource"), py::arg("p_setup_reference_slot"), py::arg("reference_slots"), py::arg("preceding_externally_encoded_bytes") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeQualityLevelInfoKHR.def(py::init<uint32_t, const void *>(), py::arg("quality_level") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeQualityLevelPropertiesKHR.def(py::init<vk::VideoEncodeRateControlModeFlagBitsKHR, uint32_t, void *>(), py::arg("preferred_rate_control_mode") = VULKAN_HPP_NAMESPACE::VideoEncodeRateControlModeFlagBitsKHR::eDefault, py::arg("preferred_rate_control_layer_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeRateControlInfoKHR.def(py::init<vk::VideoEncodeRateControlFlagsKHR, vk::VideoEncodeRateControlModeFlagBitsKHR, const vk::ArrayProxyNoTemporaries<const vk::VideoEncodeRateControlLayerInfoKHR> &, uint32_t, uint32_t, const void *>(), py::arg("flags"), py::arg("rate_control_mode"), py::arg("layers"), py::arg("virtual_buffer_size_in_ms") = uint32_t{}, py::arg("initial_virtual_buffer_size_in_ms") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeRateControlLayerInfoKHR.def(py::init<uint64_t, uint64_t, uint32_t, uint32_t, const void *>(), py::arg("average_bitrate") = uint64_t{}, py::arg("max_bitrate") = uint64_t{}, py::arg("frame_rate_numerator") = uint32_t{}, py::arg("frame_rate_denominator") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeSessionParametersFeedbackInfoKHR.def(py::init<vk::Bool32, void *>(), py::arg("has_overrides") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeSessionParametersGetInfoKHR.def(py::init<vk::VideoSessionParametersKHR, const void *>(), py::arg("video_session_parameters") = vk::VideoSessionParametersKHR{}, py::arg("p_next") = nullptr);

    s_vk_VideoEncodeUsageInfoKHR.def(py::init<vk::VideoEncodeUsageFlagsKHR, vk::VideoEncodeContentFlagsKHR, vk::VideoEncodeTuningModeKHR, const void *>(), py::arg("video_usage_hints") = vk::VideoEncodeUsageFlagsKHR{}, py::arg("video_content_hints") = vk::VideoEncodeContentFlagsKHR{}, py::arg("tuning_mode") = VULKAN_HPP_NAMESPACE::VideoEncodeTuningModeKHR::eDefault, py::arg("p_next") = nullptr);

    s_vk_DeviceDiagnosticsConfigCreateInfoNV.def(py::init<vk::DeviceDiagnosticsConfigFlagsNV, const void *>(), py::arg("flags") = vk::DeviceDiagnosticsConfigFlagsNV{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDiagnosticsConfigFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("diagnostics_config") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_QueryLowLatencySupportNV.def(py::init<void *, const void *>(), py::arg("p_queried_low_latency_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_CheckpointData2NV.def(py::init<vk::PipelineStageFlags2, void *, void *>(), py::arg("stage") = vk::PipelineStageFlags2{}, py::arg("p_checkpoint_marker") = nullptr, py::arg("p_next") = nullptr);

    s_vk_QueueFamilyCheckpointProperties2NV.def(py::init<vk::PipelineStageFlags2, void *>(), py::arg("checkpoint_execution_stage_mask") = vk::PipelineStageFlags2{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureCaptureDescriptorDataInfoEXT.def(py::init<vk::AccelerationStructureKHR, vk::AccelerationStructureNV, const void *>(), py::arg("acceleration_structure") = vk::AccelerationStructureKHR{}, py::arg("acceleration_structure_NV") = vk::AccelerationStructureNV{}, py::arg("p_next") = nullptr);

    s_vk_BufferCaptureDescriptorDataInfoEXT.def(py::init<vk::Buffer, const void *>(), py::arg("buffer") = vk::Buffer{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorAddressInfoEXT.def(py::init<vk::DeviceAddress, vk::DeviceSize, vk::Format, void *>(), py::arg("address") = vk::DeviceAddress{}, py::arg("range") = vk::DeviceSize{}, py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("p_next") = nullptr);

    s_vk_DescriptorBufferBindingInfoEXT.def(py::init<vk::DeviceAddress, vk::BufferUsageFlags, void *>(), py::arg("address") = vk::DeviceAddress{}, py::arg("usage") = vk::BufferUsageFlags{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorBufferBindingPushDescriptorBufferHandleEXT.def(py::init<vk::Buffer, void *>(), py::arg("buffer") = vk::Buffer{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorGetInfoEXT.def(py::init<vk::DescriptorType, vk::DescriptorDataEXT, const void *>(), py::arg("type") = VULKAN_HPP_NAMESPACE::DescriptorType::eSampler, py::arg("data") = vk::DescriptorDataEXT{}, py::arg("p_next") = nullptr);

    s_vk_ImageCaptureDescriptorDataInfoEXT.def(py::init<vk::Image, const void *>(), py::arg("image") = vk::Image{}, py::arg("p_next") = nullptr);

    s_vk_ImageViewCaptureDescriptorDataInfoEXT.def(py::init<vk::ImageView, const void *>(), py::arg("image_view") = vk::ImageView{}, py::arg("p_next") = nullptr);

    s_vk_OpaqueCaptureDescriptorDataCreateInfoEXT.def(py::init<const void *, const void *>(), py::arg("opaque_capture_descriptor_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT.def(py::init<size_t, void *>(), py::arg("combined_image_sampler_density_map_descriptor_size") = size_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDescriptorBufferFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("descriptor_buffer") = vk::Bool32{}, py::arg("descriptor_buffer_capture_replay") = vk::Bool32{}, py::arg("descriptor_buffer_image_layout_ignored") = vk::Bool32{}, py::arg("descriptor_buffer_push_descriptors") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDescriptorBufferPropertiesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::DeviceSize, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, size_t, vk::DeviceSize, vk::DeviceSize, vk::DeviceSize, vk::DeviceSize, vk::DeviceSize, void *>(), py::arg("combined_image_sampler_descriptor_single_array") = vk::Bool32{}, py::arg("bufferless_push_descriptors") = vk::Bool32{}, py::arg("allow_sampler_image_view_post_submit_creation") = vk::Bool32{}, py::arg("descriptor_buffer_offset_alignment") = vk::DeviceSize{}, py::arg("max_descriptor_buffer_bindings") = uint32_t{}, py::arg("max_resource_descriptor_buffer_bindings") = uint32_t{}, py::arg("max_sampler_descriptor_buffer_bindings") = uint32_t{}, py::arg("max_embedded_immutable_sampler_bindings") = uint32_t{}, py::arg("max_embedded_immutable_samplers") = uint32_t{}, py::arg("buffer_capture_replay_descriptor_data_size") = size_t{}, py::arg("image_capture_replay_descriptor_data_size") = size_t{}, py::arg("image_view_capture_replay_descriptor_data_size") = size_t{}, py::arg("sampler_capture_replay_descriptor_data_size") = size_t{}, py::arg("acceleration_structure_capture_replay_descriptor_data_size") = size_t{}, py::arg("sampler_descriptor_size") = size_t{}, py::arg("combined_image_sampler_descriptor_size") = size_t{}, py::arg("sampled_image_descriptor_size") = size_t{}, py::arg("storage_image_descriptor_size") = size_t{}, py::arg("uniform_texel_buffer_descriptor_size") = size_t{}, py::arg("robust_uniform_texel_buffer_descriptor_size") = size_t{}, py::arg("storage_texel_buffer_descriptor_size") = size_t{}, py::arg("robust_storage_texel_buffer_descriptor_size") = size_t{}, py::arg("uniform_buffer_descriptor_size") = size_t{}, py::arg("robust_uniform_buffer_descriptor_size") = size_t{}, py::arg("storage_buffer_descriptor_size") = size_t{}, py::arg("robust_storage_buffer_descriptor_size") = size_t{}, py::arg("input_attachment_descriptor_size") = size_t{}, py::arg("acceleration_structure_descriptor_size") = size_t{}, py::arg("max_sampler_descriptor_buffer_range") = vk::DeviceSize{}, py::arg("max_resource_descriptor_buffer_range") = vk::DeviceSize{}, py::arg("sampler_descriptor_buffer_address_space_size") = vk::DeviceSize{}, py::arg("resource_descriptor_buffer_address_space_size") = vk::DeviceSize{}, py::arg("descriptor_buffer_address_space_size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_SamplerCaptureDescriptorDataInfoEXT.def(py::init<vk::Sampler, const void *>(), py::arg("sampler") = vk::Sampler{}, py::arg("p_next") = nullptr);

    s_vk_GraphicsPipelineLibraryCreateInfoEXT.def(py::init<vk::GraphicsPipelineLibraryFlagsEXT, const void *>(), py::arg("flags") = vk::GraphicsPipelineLibraryFlagsEXT{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("graphics_pipeline_library") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("graphics_pipeline_library_fast_linking") = vk::Bool32{}, py::arg("graphics_pipeline_library_independent_interpolation_decoration") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD.def(py::init<vk::Bool32, void *>(), py::arg("shader_early_and_late_fragment_tests") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentShaderBarycentricFeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("fragment_shader_barycentric") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentShaderBarycentricPropertiesKHR.def(py::init<vk::Bool32, void *>(), py::arg("tri_strip_vertex_order_independent_of_provoking_vertex") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("shader_subgroup_uniform_control_flow") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentShadingRateEnumsFeaturesNV.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("fragment_shading_rate_enums") = vk::Bool32{}, py::arg("supersample_fragment_shading_rates") = vk::Bool32{}, py::arg("no_invocation_fragment_shading_rates") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentShadingRateEnumsPropertiesNV.def(py::init<vk::SampleCountFlagBits, void *>(), py::arg("max_fragment_shading_rate_invocation_count") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("p_next") = nullptr);

    s_vk_PipelineFragmentShadingRateEnumStateCreateInfoNV.def(py::init<vk::FragmentShadingRateTypeNV, vk::FragmentShadingRateNV, const std::array<vk::FragmentShadingRateCombinerOpKHR, 2> &, const void *>(), py::arg("shading_rate_type") = VULKAN_HPP_NAMESPACE::FragmentShadingRateTypeNV::eFragmentSize, py::arg("shading_rate") = VULKAN_HPP_NAMESPACE::FragmentShadingRateNV::e1InvocationPerPixel, py::arg("combiner_ops") = std::array<vk::FragmentShadingRateCombinerOpKHR, 2>{ { VULKAN_HPP_NAMESPACE::FragmentShadingRateCombinerOpKHR::eKeep, VULKAN_HPP_NAMESPACE::FragmentShadingRateCombinerOpKHR::eKeep } }, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureGeometryMotionTrianglesDataNV.def(py::init<vk::DeviceOrHostAddressConstKHR, const void *>(), py::arg("vertex_data") = vk::DeviceOrHostAddressConstKHR{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureMatrixMotionInstanceNV.def(py::init<vk::TransformMatrixKHR, vk::TransformMatrixKHR, uint32_t, uint32_t, uint32_t, vk::GeometryInstanceFlagsKHR, uint64_t>(), py::arg("transformT0") = vk::TransformMatrixKHR{}, py::arg("transformT1") = vk::TransformMatrixKHR{}, py::arg("instance_custom_index") = uint32_t{}, py::arg("mask") = uint32_t{}, py::arg("instance_shader_binding_table_record_offset") = uint32_t{}, py::arg("flags") = vk::GeometryInstanceFlagsKHR{}, py::arg("acceleration_structure_reference") = uint64_t{});

    s_vk_AccelerationStructureMotionInfoNV.def(py::init<uint32_t, vk::AccelerationStructureMotionInfoFlagsNV, const void *>(), py::arg("max_instances") = uint32_t{}, py::arg("flags") = vk::AccelerationStructureMotionInfoFlagsNV{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureMotionInstanceNV.def(py::init<vk::AccelerationStructureMotionInstanceTypeNV, vk::AccelerationStructureMotionInstanceFlagsNV, vk::AccelerationStructureMotionInstanceDataNV>(), py::arg("type") = VULKAN_HPP_NAMESPACE::AccelerationStructureMotionInstanceTypeNV::eStatic, py::arg("flags") = vk::AccelerationStructureMotionInstanceFlagsNV{}, py::arg("data") = vk::AccelerationStructureMotionInstanceDataNV{});

    s_vk_AccelerationStructureSRTMotionInstanceNV.def(py::init<vk::SRTDataNV, vk::SRTDataNV, uint32_t, uint32_t, uint32_t, vk::GeometryInstanceFlagsKHR, uint64_t>(), py::arg("transformT0") = vk::SRTDataNV{}, py::arg("transformT1") = vk::SRTDataNV{}, py::arg("instance_custom_index") = uint32_t{}, py::arg("mask") = uint32_t{}, py::arg("instance_shader_binding_table_record_offset") = uint32_t{}, py::arg("flags") = vk::GeometryInstanceFlagsKHR{}, py::arg("acceleration_structure_reference") = uint64_t{});

    s_vk_PhysicalDeviceRayTracingMotionBlurFeaturesNV.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("ray_tracing_motion_blur") = vk::Bool32{}, py::arg("ray_tracing_motion_blur_pipeline_trace_rays_indirect") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SRTDataNV.def(py::init<float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float>(), py::arg("sx") = float{}, py::arg("a") = float{}, py::arg("b") = float{}, py::arg("pvx") = float{}, py::arg("sy") = float{}, py::arg("c") = float{}, py::arg("pvy") = float{}, py::arg("sz") = float{}, py::arg("pvz") = float{}, py::arg("qx") = float{}, py::arg("qy") = float{}, py::arg("qz") = float{}, py::arg("qw") = float{}, py::arg("tx") = float{}, py::arg("ty") = float{}, py::arg("tz") = float{});

    s_vk_DrawMeshTasksIndirectCommandEXT.def(py::init<uint32_t, uint32_t, uint32_t>(), py::arg("group_count_x") = uint32_t{}, py::arg("group_count_y") = uint32_t{}, py::arg("group_count_z") = uint32_t{});

    s_vk_PhysicalDeviceMeshShaderFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("task_shader") = vk::Bool32{}, py::arg("mesh_shader") = vk::Bool32{}, py::arg("multiview_mesh_shader") = vk::Bool32{}, py::arg("primitive_fragment_shading_rate_mesh_shader") = vk::Bool32{}, py::arg("mesh_shader_queries") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMeshShaderPropertiesEXT.def(py::init<uint32_t, const std::array<uint32_t, 3> &, uint32_t, const std::array<uint32_t, 3> &, uint32_t, uint32_t, uint32_t, uint32_t, const std::array<uint32_t, 3> &, uint32_t, const std::array<uint32_t, 3> &, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("max_task_work_group_total_count") = uint32_t{}, py::arg("max_task_work_group_count") = std::array<uint32_t, 3>{}, py::arg("max_task_work_group_invocations") = uint32_t{}, py::arg("max_task_work_group_size") = std::array<uint32_t, 3>{}, py::arg("max_task_payload_size") = uint32_t{}, py::arg("max_task_shared_memory_size") = uint32_t{}, py::arg("max_task_payload_and_shared_memory_size") = uint32_t{}, py::arg("max_mesh_work_group_total_count") = uint32_t{}, py::arg("max_mesh_work_group_count") = std::array<uint32_t, 3>{}, py::arg("max_mesh_work_group_invocations") = uint32_t{}, py::arg("max_mesh_work_group_size") = std::array<uint32_t, 3>{}, py::arg("max_mesh_shared_memory_size") = uint32_t{}, py::arg("max_mesh_payload_and_shared_memory_size") = uint32_t{}, py::arg("max_mesh_output_memory_size") = uint32_t{}, py::arg("max_mesh_payload_and_output_memory_size") = uint32_t{}, py::arg("max_mesh_output_components") = uint32_t{}, py::arg("max_mesh_output_vertices") = uint32_t{}, py::arg("max_mesh_output_primitives") = uint32_t{}, py::arg("max_mesh_output_layers") = uint32_t{}, py::arg("max_mesh_multiview_view_count") = uint32_t{}, py::arg("mesh_output_per_vertex_granularity") = uint32_t{}, py::arg("mesh_output_per_primitive_granularity") = uint32_t{}, py::arg("max_preferred_task_work_group_invocations") = uint32_t{}, py::arg("max_preferred_mesh_work_group_invocations") = uint32_t{}, py::arg("prefers_local_invocation_vertex_output") = vk::Bool32{}, py::arg("prefers_local_invocation_primitive_output") = vk::Bool32{}, py::arg("prefers_compact_vertex_output") = vk::Bool32{}, py::arg("prefers_compact_primitive_output") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("ycbcr2plane444_formats") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentDensityMap2FeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("fragment_density_map_deferred") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentDensityMap2PropertiesEXT.def(py::init<vk::Bool32, vk::Bool32, uint32_t, uint32_t, void *>(), py::arg("subsampled_loads") = vk::Bool32{}, py::arg("subsampled_coarse_reconstruction_early_access") = vk::Bool32{}, py::arg("max_subsampled_array_layers") = uint32_t{}, py::arg("max_descriptor_set_subsampled_samplers") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_CopyCommandTransformInfoQCOM.def(py::init<vk::SurfaceTransformFlagBitsKHR, const void *>(), py::arg("transform") = VULKAN_HPP_NAMESPACE::SurfaceTransformFlagBitsKHR::eIdentity, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("workgroup_memory_explicit_layout") = vk::Bool32{}, py::arg("workgroup_memory_explicit_layout_scalar_block_layout") = vk::Bool32{}, py::arg("workgroup_memory_explicit_layout_8_bit_access") = vk::Bool32{}, py::arg("workgroup_memory_explicit_layout_16_bit_access") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_ImageCompressionControlEXT.def(py::init<vk::ImageCompressionFlagsEXT, const vk::ArrayProxyNoTemporaries<vk::ImageCompressionFixedRateFlagsEXT> &, const void *>(), py::arg("flags"), py::arg("fixed_rate_flags"), py::arg("p_next") = nullptr);

    s_vk_ImageCompressionPropertiesEXT.def(py::init<vk::ImageCompressionFlagsEXT, vk::ImageCompressionFixedRateFlagsEXT, void *>(), py::arg("image_compression_flags") = vk::ImageCompressionFlagsEXT{}, py::arg("image_compression_fixed_rate_flags") = vk::ImageCompressionFixedRateFlagsEXT{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageCompressionControlFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("image_compression_control") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("attachment_feedback_loop_layout") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevice4444FormatsFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("formatA4R4G4B4") = vk::Bool32{}, py::arg("formatA4B4G4R4") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_DeviceFaultAddressInfoEXT.def(py::init<vk::DeviceFaultAddressTypeEXT, vk::DeviceAddress, vk::DeviceSize>(), py::arg("address_type") = VULKAN_HPP_NAMESPACE::DeviceFaultAddressTypeEXT::eNone, py::arg("reported_address") = vk::DeviceAddress{}, py::arg("address_precision") = vk::DeviceSize{});

    s_vk_DeviceFaultCountsEXT.def(py::init<uint32_t, uint32_t, vk::DeviceSize, void *>(), py::arg("address_info_count") = uint32_t{}, py::arg("vendor_info_count") = uint32_t{}, py::arg("vendor_binary_size") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_DeviceFaultInfoEXT.def(py::init<const std::array<char, 256U> &, vk::DeviceFaultAddressInfoEXT *, vk::DeviceFaultVendorInfoEXT *, void *, void *>(), py::arg("description") = std::array<char, 256U>{}, py::arg("p_address_infos") = nullptr, py::arg("p_vendor_infos") = nullptr, py::arg("p_vendor_binary_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_DeviceFaultVendorBinaryHeaderVersionOneEXT.def(py::init<uint32_t, vk::DeviceFaultVendorBinaryHeaderVersionEXT, uint32_t, uint32_t, uint32_t, const std::array<uint8_t, 16U> &, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>(), py::arg("header_size") = uint32_t{}, py::arg("header_version") = VULKAN_HPP_NAMESPACE::DeviceFaultVendorBinaryHeaderVersionEXT::eOne, py::arg("vendorID") = uint32_t{}, py::arg("deviceID") = uint32_t{}, py::arg("driver_version") = uint32_t{}, py::arg("pipeline_cache_UUID") = std::array<uint8_t, 16U>{}, py::arg("application_name_offset") = uint32_t{}, py::arg("application_version") = uint32_t{}, py::arg("engine_name_offset") = uint32_t{}, py::arg("engine_version") = uint32_t{}, py::arg("api_version") = uint32_t{});

    s_vk_DeviceFaultVendorInfoEXT.def(py::init<const std::array<char, 256U> &, uint64_t, uint64_t>(), py::arg("description") = std::array<char, 256U>{}, py::arg("vendor_fault_code") = uint64_t{}, py::arg("vendor_fault_data") = uint64_t{});

    s_vk_PhysicalDeviceFaultFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("device_fault") = vk::Bool32{}, py::arg("device_fault_vendor_binary") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRGBA10X6FormatsFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("format_rgba_10x6_without_y_cb_cr_sampler") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVertexInputDynamicStateFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("vertex_input_dynamic_state") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_VertexInputAttributeDescription2EXT.def(py::init<uint32_t, uint32_t, vk::Format, uint32_t, void *>(), py::arg("location") = uint32_t{}, py::arg("binding") = uint32_t{}, py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("offset") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_VertexInputBindingDescription2EXT.def(py::init<uint32_t, uint32_t, vk::VertexInputRate, uint32_t, void *>(), py::arg("binding") = uint32_t{}, py::arg("stride") = uint32_t{}, py::arg("input_rate") = VULKAN_HPP_NAMESPACE::VertexInputRate::eVertex, py::arg("divisor") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDrmPropertiesEXT.def(py::init<vk::Bool32, vk::Bool32, int64_t, int64_t, int64_t, int64_t, void *>(), py::arg("has_primary") = vk::Bool32{}, py::arg("has_render") = vk::Bool32{}, py::arg("primary_major") = int64_t{}, py::arg("primary_minor") = int64_t{}, py::arg("render_major") = int64_t{}, py::arg("render_minor") = int64_t{}, py::arg("p_next") = nullptr);

    s_vk_DeviceAddressBindingCallbackDataEXT.def(py::init<vk::DeviceAddressBindingFlagsEXT, vk::DeviceAddress, vk::DeviceSize, vk::DeviceAddressBindingTypeEXT, void *>(), py::arg("flags") = vk::DeviceAddressBindingFlagsEXT{}, py::arg("base_address") = vk::DeviceAddress{}, py::arg("size") = vk::DeviceSize{}, py::arg("binding_type") = VULKAN_HPP_NAMESPACE::DeviceAddressBindingTypeEXT::eBind, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceAddressBindingReportFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("report_address_binding") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDepthClipControlFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("depth_clip_control") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineViewportDepthClipControlCreateInfoEXT.def(py::init<vk::Bool32, const void *>(), py::arg("negative_one_to_one") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("primitive_topology_list_restart") = vk::Bool32{}, py::arg("primitive_topology_patch_list_restart") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSubpassShadingFeaturesHUAWEI.def(py::init<vk::Bool32, void *>(), py::arg("subpass_shading") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSubpassShadingPropertiesHUAWEI.def(py::init<uint32_t, void *>(), py::arg("max_subpass_shading_workgroup_size_aspect_ratio") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_SubpassShadingPipelineCreateInfoHUAWEI.def(py::init<vk::RenderPass, uint32_t, void *>(), py::arg("render_pass") = vk::RenderPass{}, py::arg("subpass") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceInvocationMaskFeaturesHUAWEI.def(py::init<vk::Bool32, void *>(), py::arg("invocation_mask") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_MemoryGetRemoteAddressInfoNV.def(py::init<vk::DeviceMemory, vk::ExternalMemoryHandleTypeFlagBits, const void *>(), py::arg("memory") = vk::DeviceMemory{}, py::arg("handle_type") = VULKAN_HPP_NAMESPACE::ExternalMemoryHandleTypeFlagBits::eOpaqueFd, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExternalMemoryRDMAFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("external_memory_RDMA") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePipelinePropertiesFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("pipeline_properties_identifier") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelinePropertiesIdentifierEXT.def(py::init<const std::array<uint8_t, 16U> &, void *>(), py::arg("pipeline_identifier") = std::array<uint8_t, 16U>{}, py::arg("p_next") = nullptr);

    s_vk_FrameBoundaryEXT.def(py::init<vk::FrameBoundaryFlagsEXT, uint64_t, uint32_t, const vk::Image *, uint32_t, const vk::Buffer *, uint64_t, size_t, const void *, const void *>(), py::arg("flags") = vk::FrameBoundaryFlagsEXT{}, py::arg("frameID") = uint64_t{}, py::arg("image_count") = uint32_t{}, py::arg("p_images") = nullptr, py::arg("buffer_count") = uint32_t{}, py::arg("p_buffers") = nullptr, py::arg("tag_name") = uint64_t{}, py::arg("tag_size") = size_t{}, py::arg("p_tag") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFrameBoundaryFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("frame_boundary") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_MultisampledRenderToSingleSampledInfoEXT.def(py::init<vk::Bool32, vk::SampleCountFlagBits, const void *>(), py::arg("multisampled_render_to_single_sampled_enable") = vk::Bool32{}, py::arg("rasterization_samples") = VULKAN_HPP_NAMESPACE::SampleCountFlagBits::e1, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("multisampled_render_to_single_sampled") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SubpassResolvePerformanceQueryEXT.def(py::init<vk::Bool32, void *>(), py::arg("optimal") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExtendedDynamicState2FeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("extended_dynamic_state_2") = vk::Bool32{}, py::arg("extended_dynamic_state_2_logic_op") = vk::Bool32{}, py::arg("extended_dynamic_state_2_patch_control_points") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceColorWriteEnableFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("color_write_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineColorWriteCreateInfoEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Bool32> &, const void *>(), py::arg("color_write_enables"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("primitives_generated_query") = vk::Bool32{}, py::arg("primitives_generated_query_with_rasterizer_discard") = vk::Bool32{}, py::arg("primitives_generated_query_with_non_zero_streams") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRayTracingMaintenance1FeaturesKHR.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("ray_tracing_maintenance_1") = vk::Bool32{}, py::arg("ray_tracing_pipeline_trace_rays_indirect_2") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_TraceRaysIndirectCommand2KHR.def(py::init<vk::DeviceAddress, vk::DeviceSize, vk::DeviceAddress, vk::DeviceSize, vk::DeviceSize, vk::DeviceAddress, vk::DeviceSize, vk::DeviceSize, vk::DeviceAddress, vk::DeviceSize, vk::DeviceSize, uint32_t, uint32_t, uint32_t>(), py::arg("raygen_shader_record_address") = vk::DeviceAddress{}, py::arg("raygen_shader_record_size") = vk::DeviceSize{}, py::arg("miss_shader_binding_table_address") = vk::DeviceAddress{}, py::arg("miss_shader_binding_table_size") = vk::DeviceSize{}, py::arg("miss_shader_binding_table_stride") = vk::DeviceSize{}, py::arg("hit_shader_binding_table_address") = vk::DeviceAddress{}, py::arg("hit_shader_binding_table_size") = vk::DeviceSize{}, py::arg("hit_shader_binding_table_stride") = vk::DeviceSize{}, py::arg("callable_shader_binding_table_address") = vk::DeviceAddress{}, py::arg("callable_shader_binding_table_size") = vk::DeviceSize{}, py::arg("callable_shader_binding_table_stride") = vk::DeviceSize{}, py::arg("width") = uint32_t{}, py::arg("height") = uint32_t{}, py::arg("depth") = uint32_t{});

    s_vk_ImageViewMinLodCreateInfoEXT.def(py::init<float, const void *>(), py::arg("min_lod") = float{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageViewMinLodFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("min_lod") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_MultiDrawIndexedInfoEXT.def(py::init<uint32_t, uint32_t, int32_t>(), py::arg("first_index") = uint32_t{}, py::arg("index_count") = uint32_t{}, py::arg("vertex_offset") = int32_t{});

    s_vk_MultiDrawInfoEXT.def(py::init<uint32_t, uint32_t>(), py::arg("first_vertex") = uint32_t{}, py::arg("vertex_count") = uint32_t{});

    s_vk_PhysicalDeviceMultiDrawFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("multi_draw") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMultiDrawPropertiesEXT.def(py::init<uint32_t, void *>(), py::arg("max_multi_draw_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImage2DViewOf3DFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("image2D_view_of_3d") = vk::Bool32{}, py::arg("sampler2D_view_of_3d") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderTileImageFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("shader_tile_image_color_read_access") = vk::Bool32{}, py::arg("shader_tile_image_depth_read_access") = vk::Bool32{}, py::arg("shader_tile_image_stencil_read_access") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderTileImagePropertiesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("shader_tile_image_coherent_read_accelerated") = vk::Bool32{}, py::arg("shader_tile_image_read_sample_from_pixel_rate_invocation") = vk::Bool32{}, py::arg("shader_tile_image_read_from_helper_invocation") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_AccelerationStructureTrianglesOpacityMicromapEXT.def(py::init<vk::IndexType, vk::DeviceOrHostAddressConstKHR, vk::DeviceSize, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::MicromapUsageEXT> &, const vk::ArrayProxyNoTemporaries<const vk::MicromapUsageEXT *const> &, vk::MicromapEXT, void *>(), py::arg("index_type"), py::arg("index_buffer"), py::arg("index_stride"), py::arg("base_triangle"), py::arg("usage_counts"), py::arg("p_usage_counts") = vk::ArrayProxyNoTemporaries<const vk::MicromapUsageEXT *const>{}, py::arg("micromap") = vk::MicromapEXT{}, py::arg("p_next") = nullptr);

    s_vk_CopyMemoryToMicromapInfoEXT.def(py::init<vk::DeviceOrHostAddressConstKHR, vk::MicromapEXT, vk::CopyMicromapModeEXT, const void *>(), py::arg("src") = vk::DeviceOrHostAddressConstKHR{}, py::arg("dst") = vk::MicromapEXT{}, py::arg("mode") = VULKAN_HPP_NAMESPACE::CopyMicromapModeEXT::eClone, py::arg("p_next") = nullptr);

    s_vk_CopyMicromapInfoEXT.def(py::init<vk::MicromapEXT, vk::MicromapEXT, vk::CopyMicromapModeEXT, const void *>(), py::arg("src") = vk::MicromapEXT{}, py::arg("dst") = vk::MicromapEXT{}, py::arg("mode") = VULKAN_HPP_NAMESPACE::CopyMicromapModeEXT::eClone, py::arg("p_next") = nullptr);

    s_vk_CopyMicromapToMemoryInfoEXT.def(py::init<vk::MicromapEXT, vk::DeviceOrHostAddressKHR, vk::CopyMicromapModeEXT, const void *>(), py::arg("src") = vk::MicromapEXT{}, py::arg("dst") = vk::DeviceOrHostAddressKHR{}, py::arg("mode") = VULKAN_HPP_NAMESPACE::CopyMicromapModeEXT::eClone, py::arg("p_next") = nullptr);

    s_vk_MicromapBuildInfoEXT.def(py::init<vk::MicromapTypeEXT, vk::BuildMicromapFlagsEXT, vk::BuildMicromapModeEXT, vk::MicromapEXT, const vk::ArrayProxyNoTemporaries<const vk::MicromapUsageEXT> &, const vk::ArrayProxyNoTemporaries<const vk::MicromapUsageEXT *const> &, vk::DeviceOrHostAddressConstKHR, vk::DeviceOrHostAddressKHR, vk::DeviceOrHostAddressConstKHR, vk::DeviceSize, const void *>(), py::arg("type"), py::arg("flags"), py::arg("mode"), py::arg("dst_micromap"), py::arg("usage_counts"), py::arg("p_usage_counts") = vk::ArrayProxyNoTemporaries<const vk::MicromapUsageEXT *const>{}, py::arg("data") = vk::DeviceOrHostAddressConstKHR{}, py::arg("scratch_data") = vk::DeviceOrHostAddressKHR{}, py::arg("triangle_array") = vk::DeviceOrHostAddressConstKHR{}, py::arg("triangle_array_stride") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_MicromapBuildSizesInfoEXT.def(py::init<vk::DeviceSize, vk::DeviceSize, vk::Bool32, const void *>(), py::arg("micromap_size") = vk::DeviceSize{}, py::arg("build_scratch_size") = vk::DeviceSize{}, py::arg("discardable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_MicromapCreateInfoEXT.def(py::init<vk::MicromapCreateFlagsEXT, vk::Buffer, vk::DeviceSize, vk::DeviceSize, vk::MicromapTypeEXT, vk::DeviceAddress, const void *>(), py::arg("create_flags") = vk::MicromapCreateFlagsEXT{}, py::arg("buffer") = vk::Buffer{}, py::arg("offset") = vk::DeviceSize{}, py::arg("size") = vk::DeviceSize{}, py::arg("type") = VULKAN_HPP_NAMESPACE::MicromapTypeEXT::eOpacityMicromap, py::arg("device_address") = vk::DeviceAddress{}, py::arg("p_next") = nullptr);

    s_vk_MicromapTriangleEXT.def(py::init<uint32_t, uint16_t, uint16_t>(), py::arg("data_offset") = uint32_t{}, py::arg("subdivision_level") = uint16_t{}, py::arg("format") = uint16_t{});

    s_vk_MicromapUsageEXT.def(py::init<uint32_t, uint32_t, uint32_t>(), py::arg("count") = uint32_t{}, py::arg("subdivision_level") = uint32_t{}, py::arg("format") = uint32_t{});

    s_vk_MicromapVersionInfoEXT.def(py::init<const uint8_t *, const void *>(), py::arg("p_version_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceOpacityMicromapFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("micromap") = vk::Bool32{}, py::arg("micromap_capture_replay") = vk::Bool32{}, py::arg("micromap_host_commands") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceOpacityMicromapPropertiesEXT.def(py::init<uint32_t, uint32_t, void *>(), py::arg("max_opacity_2_state_subdivision_level") = uint32_t{}, py::arg("max_opacity_4_state_subdivision_level") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceClusterCullingShaderFeaturesHUAWEI.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("clusterculling_shader") = vk::Bool32{}, py::arg("multiview_cluster_culling_shader") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceClusterCullingShaderPropertiesHUAWEI.def(py::init<const std::array<uint32_t, 3> &, const std::array<uint32_t, 3> &, uint32_t, vk::DeviceSize, void *>(), py::arg("max_work_group_count") = std::array<uint32_t, 3>{}, py::arg("max_work_group_size") = std::array<uint32_t, 3>{}, py::arg("max_output_cluster_count") = uint32_t{}, py::arg("indirect_buffer_offset_alignment") = vk::DeviceSize{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI.def(py::init<vk::Bool32, void *>(), py::arg("cluster_shading_rate") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceBorderColorSwizzleFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("border_color_swizzle") = vk::Bool32{}, py::arg("border_color_swizzle_from_image") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SamplerBorderColorComponentMappingCreateInfoEXT.def(py::init<vk::ComponentMapping, vk::Bool32, const void *>(), py::arg("components") = vk::ComponentMapping{}, py::arg("srgb") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("pageable_device_local_memory") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderCorePropertiesARM.def(py::init<uint32_t, uint32_t, uint32_t, void *>(), py::arg("pixel_rate") = uint32_t{}, py::arg("texel_rate") = uint32_t{}, py::arg("fma_rate") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DeviceQueueShaderCoreControlCreateInfoARM.def(py::init<uint32_t, void *>(), py::arg("shader_core_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSchedulingControlsFeaturesARM.def(py::init<vk::Bool32, void *>(), py::arg("scheduling_controls") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSchedulingControlsPropertiesARM.def(py::init<vk::PhysicalDeviceSchedulingControlsFlagsARM, void *>(), py::arg("scheduling_controls_flags") = vk::PhysicalDeviceSchedulingControlsFlagsARM{}, py::arg("p_next") = nullptr);

    s_vk_ImageViewSlicedCreateInfoEXT.def(py::init<uint32_t, uint32_t, const void *>(), py::arg("slice_offset") = uint32_t{}, py::arg("slice_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageSlicedViewOf3DFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("image_sliced_view_of_3d") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorSetBindingReferenceVALVE.def(py::init<vk::DescriptorSetLayout, uint32_t, const void *>(), py::arg("descriptor_set_layout") = vk::DescriptorSetLayout{}, py::arg("binding") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_DescriptorSetLayoutHostMappingInfoVALVE.def(py::init<size_t, uint32_t, void *>(), py::arg("descriptor_offset") = size_t{}, py::arg("descriptor_size") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE.def(py::init<vk::Bool32, void *>(), py::arg("descriptor_set_host_mapping") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDepthClampZeroOneFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("depth_clamp_zero_one") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceNonSeamlessCubeMapFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("non_seamless_cube_map") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRenderPassStripedFeaturesARM.def(py::init<vk::Bool32, void *>(), py::arg("render_pass_striped") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRenderPassStripedPropertiesARM.def(py::init<vk::Extent2D, uint32_t, void *>(), py::arg("render_pass_stripe_granularity") = vk::Extent2D{}, py::arg("max_render_pass_stripes") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_RenderPassStripeBeginInfoARM.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::RenderPassStripeInfoARM> &, const void *>(), py::arg("stripe_infos"), py::arg("p_next") = nullptr);

    s_vk_RenderPassStripeInfoARM.def(py::init<vk::Rect2D, const void *>(), py::arg("stripe_area") = vk::Rect2D{}, py::arg("p_next") = nullptr);

    s_vk_RenderPassStripeSubmitInfoARM.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::SemaphoreSubmitInfo> &, const void *>(), py::arg("stripe_semaphore_infos"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM.def(py::init<vk::Bool32, void *>(), py::arg("fragment_density_map_offset") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM.def(py::init<vk::Extent2D, void *>(), py::arg("fragment_density_offset_granularity") = vk::Extent2D{}, py::arg("p_next") = nullptr);

    s_vk_SubpassFragmentDensityMapOffsetEndInfoQCOM.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Offset2D> &, const void *>(), py::arg("fragment_density_offsets"), py::arg("p_next") = nullptr);

    s_vk_CopyMemoryIndirectCommandNV.def(py::init<vk::DeviceAddress, vk::DeviceAddress, vk::DeviceSize>(), py::arg("src_address") = vk::DeviceAddress{}, py::arg("dst_address") = vk::DeviceAddress{}, py::arg("size") = vk::DeviceSize{});

    s_vk_CopyMemoryToImageIndirectCommandNV.def(py::init<vk::DeviceAddress, uint32_t, uint32_t, vk::ImageSubresourceLayers, vk::Offset3D, vk::Extent3D>(), py::arg("src_address") = vk::DeviceAddress{}, py::arg("buffer_row_length") = uint32_t{}, py::arg("buffer_image_height") = uint32_t{}, py::arg("image_subresource") = vk::ImageSubresourceLayers{}, py::arg("image_offset") = vk::Offset3D{}, py::arg("image_extent") = vk::Extent3D{});

    s_vk_PhysicalDeviceCopyMemoryIndirectFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("indirect_copy") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCopyMemoryIndirectPropertiesNV.def(py::init<vk::QueueFlags, void *>(), py::arg("supported_queues") = vk::QueueFlags{}, py::arg("p_next") = nullptr);

    s_vk_DecompressMemoryRegionNV.def(py::init<vk::DeviceAddress, vk::DeviceAddress, vk::DeviceSize, vk::DeviceSize, vk::MemoryDecompressionMethodFlagsNV>(), py::arg("src_address") = vk::DeviceAddress{}, py::arg("dst_address") = vk::DeviceAddress{}, py::arg("compressed_size") = vk::DeviceSize{}, py::arg("decompressed_size") = vk::DeviceSize{}, py::arg("decompression_method") = vk::MemoryDecompressionMethodFlagsNV{});

    s_vk_PhysicalDeviceMemoryDecompressionFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("memory_decompression") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMemoryDecompressionPropertiesNV.def(py::init<vk::MemoryDecompressionMethodFlagsNV, uint64_t, void *>(), py::arg("decompression_methods") = vk::MemoryDecompressionMethodFlagsNV{}, py::arg("max_decompression_indirect_count") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_BindPipelineIndirectCommandNV.def(py::init<vk::DeviceAddress>(), py::arg("pipeline_address") = vk::DeviceAddress{});

    s_vk_ComputePipelineIndirectBufferInfoNV.def(py::init<vk::DeviceAddress, vk::DeviceSize, vk::DeviceAddress, const void *>(), py::arg("device_address") = vk::DeviceAddress{}, py::arg("size") = vk::DeviceSize{}, py::arg("pipeline_device_address_capture_replay") = vk::DeviceAddress{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("device_generated_compute") = vk::Bool32{}, py::arg("device_generated_compute_pipelines") = vk::Bool32{}, py::arg("device_generated_compute_capture_replay") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineIndirectDeviceAddressInfoNV.def(py::init<vk::PipelineBindPoint, vk::Pipeline, const void *>(), py::arg("pipeline_bind_point") = VULKAN_HPP_NAMESPACE::PipelineBindPoint::eGraphics, py::arg("pipeline") = vk::Pipeline{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceLinearColorAttachmentFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("linear_color_attachment") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("image_compression_control_swapchain") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_ImageViewSampleWeightCreateInfoQCOM.def(py::init<vk::Offset2D, vk::Extent2D, uint32_t, const void *>(), py::arg("filter_center") = vk::Offset2D{}, py::arg("filter_size") = vk::Extent2D{}, py::arg("num_phases") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageProcessingFeaturesQCOM.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("texture_sample_weighted") = vk::Bool32{}, py::arg("texture_box_filter") = vk::Bool32{}, py::arg("texture_block_match") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageProcessingPropertiesQCOM.def(py::init<uint32_t, vk::Extent2D, vk::Extent2D, vk::Extent2D, void *>(), py::arg("max_weight_filter_phases") = uint32_t{}, py::arg("max_weight_filter_dimension") = vk::Extent2D{}, py::arg("max_block_match_region") = vk::Extent2D{}, py::arg("max_box_filter_block_size") = vk::Extent2D{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceNestedCommandBufferFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("nested_command_buffer") = vk::Bool32{}, py::arg("nested_command_buffer_rendering") = vk::Bool32{}, py::arg("nested_command_buffer_simultaneous_use") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceNestedCommandBufferPropertiesEXT.def(py::init<uint32_t, void *>(), py::arg("max_command_buffer_nesting_level") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_ExternalMemoryAcquireUnmodifiedEXT.def(py::init<vk::Bool32, const void *>(), py::arg("acquire_unmodified_memory") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_ColorBlendAdvancedEXT.def(py::init<vk::BlendOp, vk::Bool32, vk::Bool32, vk::BlendOverlapEXT, vk::Bool32>(), py::arg("advanced_blend_op") = VULKAN_HPP_NAMESPACE::BlendOp::eAdd, py::arg("src_premultiplied") = vk::Bool32{}, py::arg("dst_premultiplied") = vk::Bool32{}, py::arg("blend_overlap") = VULKAN_HPP_NAMESPACE::BlendOverlapEXT::eUncorrelated, py::arg("clamp_results") = vk::Bool32{});

    s_vk_ColorBlendEquationEXT.def(py::init<vk::BlendFactor, vk::BlendFactor, vk::BlendOp, vk::BlendFactor, vk::BlendFactor, vk::BlendOp>(), py::arg("src_color_blend_factor") = VULKAN_HPP_NAMESPACE::BlendFactor::eZero, py::arg("dst_color_blend_factor") = VULKAN_HPP_NAMESPACE::BlendFactor::eZero, py::arg("color_blend_op") = VULKAN_HPP_NAMESPACE::BlendOp::eAdd, py::arg("src_alpha_blend_factor") = VULKAN_HPP_NAMESPACE::BlendFactor::eZero, py::arg("dst_alpha_blend_factor") = VULKAN_HPP_NAMESPACE::BlendFactor::eZero, py::arg("alpha_blend_op") = VULKAN_HPP_NAMESPACE::BlendOp::eAdd);

    s_vk_PhysicalDeviceExtendedDynamicState3FeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("extended_dynamic_state_3_tessellation_domain_origin") = vk::Bool32{}, py::arg("extended_dynamic_state_3_depth_clamp_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_polygon_mode") = vk::Bool32{}, py::arg("extended_dynamic_state_3_rasterization_samples") = vk::Bool32{}, py::arg("extended_dynamic_state_3_sample_mask") = vk::Bool32{}, py::arg("extended_dynamic_state_3_alpha_to_coverage_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_alpha_to_one_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_logic_op_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_color_blend_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_color_blend_equation") = vk::Bool32{}, py::arg("extended_dynamic_state_3_color_write_mask") = vk::Bool32{}, py::arg("extended_dynamic_state_3_rasterization_stream") = vk::Bool32{}, py::arg("extended_dynamic_state_3_conservative_rasterization_mode") = vk::Bool32{}, py::arg("extended_dynamic_state_3_extra_primitive_overestimation_size") = vk::Bool32{}, py::arg("extended_dynamic_state_3_depth_clip_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_sample_locations_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_color_blend_advanced") = vk::Bool32{}, py::arg("extended_dynamic_state_3_provoking_vertex_mode") = vk::Bool32{}, py::arg("extended_dynamic_state_3_line_rasterization_mode") = vk::Bool32{}, py::arg("extended_dynamic_state_3_line_stipple_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_depth_clip_negative_one_to_one") = vk::Bool32{}, py::arg("extended_dynamic_state_3_viewport_w_scaling_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_viewport_swizzle") = vk::Bool32{}, py::arg("extended_dynamic_state_3_coverage_to_color_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_coverage_to_color_location") = vk::Bool32{}, py::arg("extended_dynamic_state_3_coverage_modulation_mode") = vk::Bool32{}, py::arg("extended_dynamic_state_3_coverage_modulation_table_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_coverage_modulation_table") = vk::Bool32{}, py::arg("extended_dynamic_state_3_coverage_reduction_mode") = vk::Bool32{}, py::arg("extended_dynamic_state_3_representative_fragment_test_enable") = vk::Bool32{}, py::arg("extended_dynamic_state_3_shading_rate_image_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExtendedDynamicState3PropertiesEXT.def(py::init<vk::Bool32, void *>(), py::arg("dynamic_primitive_topology_unrestricted") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceSubpassMergeFeedbackFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("subpass_merge_feedback") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_RenderPassCreationControlEXT.def(py::init<vk::Bool32, const void *>(), py::arg("disallow_merging") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_RenderPassCreationFeedbackCreateInfoEXT.def(py::init<vk::RenderPassCreationFeedbackInfoEXT *, const void *>(), py::arg("p_render_pass_feedback") = nullptr, py::arg("p_next") = nullptr);

    s_vk_RenderPassCreationFeedbackInfoEXT.def(py::init<uint32_t>(), py::arg("post_merge_subpass_count") = uint32_t{});

    s_vk_RenderPassSubpassFeedbackCreateInfoEXT.def(py::init<vk::RenderPassSubpassFeedbackInfoEXT *, const void *>(), py::arg("p_subpass_feedback") = nullptr, py::arg("p_next") = nullptr);

    s_vk_RenderPassSubpassFeedbackInfoEXT.def(py::init<vk::SubpassMergeStatusEXT, const std::array<char, 256U> &, uint32_t>(), py::arg("subpass_merge_status") = VULKAN_HPP_NAMESPACE::SubpassMergeStatusEXT::eMerged, py::arg("description") = std::array<char, 256U>{}, py::arg("post_merge_index") = uint32_t{});

    s_vk_DirectDriverLoadingInfoLUNARG.def(py::init<vk::DirectDriverLoadingFlagsLUNARG, PFN_vkGetInstanceProcAddrLUNARG, void *>(), py::arg("flags") = vk::DirectDriverLoadingFlagsLUNARG{}, py::arg("pfn_get_instance_proc_addr") = PFN_vkGetInstanceProcAddrLUNARG{}, py::arg("p_next") = nullptr);

    s_vk_DirectDriverLoadingListLUNARG.def(py::init<vk::DirectDriverLoadingModeLUNARG, const vk::ArrayProxyNoTemporaries<const vk::DirectDriverLoadingInfoLUNARG> &, const void *>(), py::arg("mode"), py::arg("drivers"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderModuleIdentifierFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("shader_module_identifier") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderModuleIdentifierPropertiesEXT.def(py::init<const std::array<uint8_t, 16U> &, void *>(), py::arg("shader_module_identifier_algorithm_UUID") = std::array<uint8_t, 16U>{}, py::arg("p_next") = nullptr);

    s_vk_PipelineShaderStageModuleIdentifierCreateInfoEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const uint8_t> &, const void *>(), py::arg("identifier"), py::arg("p_next") = nullptr);

    s_vk_ShaderModuleIdentifierEXT.def(py::init<uint32_t, const std::array<uint8_t, 32U> &, void *>(), py::arg("identifier_size") = uint32_t{}, py::arg("identifier") = std::array<uint8_t, 32U>{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("rasterization_order_color_attachment_access") = vk::Bool32{}, py::arg("rasterization_order_depth_attachment_access") = vk::Bool32{}, py::arg("rasterization_order_stencil_attachment_access") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_OpticalFlowExecuteInfoNV.def(py::init<vk::OpticalFlowExecuteFlagsNV, const vk::ArrayProxyNoTemporaries<const vk::Rect2D> &, void *>(), py::arg("flags"), py::arg("regions"), py::arg("p_next") = nullptr);

    s_vk_OpticalFlowImageFormatInfoNV.def(py::init<vk::OpticalFlowUsageFlagsNV, const void *>(), py::arg("usage") = vk::OpticalFlowUsageFlagsNV{}, py::arg("p_next") = nullptr);

    s_vk_OpticalFlowImageFormatPropertiesNV.def(py::init<vk::Format, const void *>(), py::arg("format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("p_next") = nullptr);

    s_vk_OpticalFlowSessionCreateInfoNV.def(py::init<uint32_t, uint32_t, vk::Format, vk::Format, vk::Format, vk::OpticalFlowGridSizeFlagsNV, vk::OpticalFlowGridSizeFlagsNV, vk::OpticalFlowPerformanceLevelNV, vk::OpticalFlowSessionCreateFlagsNV, void *>(), py::arg("width") = uint32_t{}, py::arg("height") = uint32_t{}, py::arg("image_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("flow_vector_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("cost_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("output_grid_size") = vk::OpticalFlowGridSizeFlagsNV{}, py::arg("hint_grid_size") = vk::OpticalFlowGridSizeFlagsNV{}, py::arg("performance_level") = VULKAN_HPP_NAMESPACE::OpticalFlowPerformanceLevelNV::eUnknown, py::arg("flags") = vk::OpticalFlowSessionCreateFlagsNV{}, py::arg("p_next") = nullptr);

    s_vk_OpticalFlowSessionCreatePrivateDataInfoNV.def(py::init<uint32_t, uint32_t, const void *, void *>(), py::arg("id") = uint32_t{}, py::arg("size") = uint32_t{}, py::arg("p_private_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceOpticalFlowFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("optical_flow") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceOpticalFlowPropertiesNV.def(py::init<vk::OpticalFlowGridSizeFlagsNV, vk::OpticalFlowGridSizeFlagsNV, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, void *>(), py::arg("supported_output_grid_sizes") = vk::OpticalFlowGridSizeFlagsNV{}, py::arg("supported_hint_grid_sizes") = vk::OpticalFlowGridSizeFlagsNV{}, py::arg("hint_supported") = vk::Bool32{}, py::arg("cost_supported") = vk::Bool32{}, py::arg("bidirectional_flow_supported") = vk::Bool32{}, py::arg("global_flow_supported") = vk::Bool32{}, py::arg("min_width") = uint32_t{}, py::arg("min_height") = uint32_t{}, py::arg("max_width") = uint32_t{}, py::arg("max_height") = uint32_t{}, py::arg("max_num_regions_of_interest") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceLegacyDitheringFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("legacy_dithering") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePipelineProtectedAccessFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("pipeline_protected_access") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_BufferUsageFlags2CreateInfoKHR.def(py::init<vk::BufferUsageFlags2KHR, const void *>(), py::arg("usage") = vk::BufferUsageFlags2KHR{}, py::arg("p_next") = nullptr);

    s_vk_DeviceImageSubresourceInfoKHR.def(py::init<const vk::ImageCreateInfo *, const vk::ImageSubresource2KHR *, const void *>(), py::arg("p_create_info") = nullptr, py::arg("p_subresource") = nullptr, py::arg("p_next") = nullptr);

    s_vk_ImageSubresource2KHR.def(py::init<vk::ImageSubresource, void *>(), py::arg("image_subresource") = vk::ImageSubresource{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMaintenance5FeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("maintenance5") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMaintenance5PropertiesKHR.def(py::init<vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, vk::Bool32, void *>(), py::arg("early_fragment_multisample_coverage_after_sample_counting") = vk::Bool32{}, py::arg("early_fragment_sample_mask_test_before_sample_counting") = vk::Bool32{}, py::arg("depth_stencil_swizzle_one_support") = vk::Bool32{}, py::arg("polygon_mode_point_size") = vk::Bool32{}, py::arg("non_strict_single_pixel_wide_lines_use_parallelogram") = vk::Bool32{}, py::arg("non_strict_wide_lines_use_parallelogram") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineCreateFlags2CreateInfoKHR.def(py::init<vk::PipelineCreateFlags2KHR, const void *>(), py::arg("flags") = vk::PipelineCreateFlags2KHR{}, py::arg("p_next") = nullptr);

    s_vk_RenderingAreaInfoKHR.def(py::init<uint32_t, const vk::ArrayProxyNoTemporaries<const vk::Format> &, vk::Format, vk::Format, const void *>(), py::arg("view_mask"), py::arg("color_attachment_formats"), py::arg("depth_attachment_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("stencil_attachment_format") = VULKAN_HPP_NAMESPACE::Format::eUndefined, py::arg("p_next") = nullptr);

    s_vk_SubresourceLayout2KHR.def(py::init<vk::SubresourceLayout, void *>(), py::arg("subresource_layout") = vk::SubresourceLayout{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRayTracingPositionFetchFeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("ray_tracing_position_fetch") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderObjectFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("shader_object") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderObjectPropertiesEXT.def(py::init<const std::array<uint8_t, 16U> &, uint32_t, void *>(), py::arg("shader_binary_UUID") = std::array<uint8_t, 16U>{}, py::arg("shader_binary_version") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_ShaderCreateInfoEXT.def(py::init<vk::ShaderCreateFlagsEXT, vk::ShaderStageFlagBits, vk::ShaderStageFlags, vk::ShaderCodeTypeEXT, size_t, const void *, const char *, uint32_t, const vk::DescriptorSetLayout *, uint32_t, const vk::PushConstantRange *, const vk::SpecializationInfo *, const void *>(), py::arg("flags") = vk::ShaderCreateFlagsEXT{}, py::arg("stage") = VULKAN_HPP_NAMESPACE::ShaderStageFlagBits::eVertex, py::arg("next_stage") = vk::ShaderStageFlags{}, py::arg("code_type") = VULKAN_HPP_NAMESPACE::ShaderCodeTypeEXT::eBinary, py::arg("code_size") = size_t{}, py::arg("p_code") = nullptr, py::arg("p_name") = nullptr, py::arg("set_layout_count") = uint32_t{}, py::arg("p_set_layouts") = nullptr, py::arg("push_constant_range_count") = uint32_t{}, py::arg("p_push_constant_ranges") = nullptr, py::arg("p_specialization_info") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceTilePropertiesFeaturesQCOM.def(py::init<vk::Bool32, void *>(), py::arg("tile_properties") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_TilePropertiesQCOM.def(py::init<vk::Extent3D, vk::Extent2D, vk::Offset2D, void *>(), py::arg("tile_size") = vk::Extent3D{}, py::arg("apron_size") = vk::Extent2D{}, py::arg("origin") = vk::Offset2D{}, py::arg("p_next") = nullptr);

    s_vk_AmigoProfilingSubmitInfoSEC.def(py::init<uint64_t, uint64_t, const void *>(), py::arg("first_draw_timestamp") = uint64_t{}, py::arg("swap_buffer_timestamp") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceAmigoProfilingFeaturesSEC.def(py::init<vk::Bool32, void *>(), py::arg("amigo_profiling") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM.def(py::init<vk::Bool32, void *>(), py::arg("multiview_per_view_viewports") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRayTracingInvocationReorderFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("ray_tracing_invocation_reorder") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceRayTracingInvocationReorderPropertiesNV.def(py::init<vk::RayTracingInvocationReorderModeNV, void *>(), py::arg("ray_tracing_invocation_reorder_reordering_hint") = VULKAN_HPP_NAMESPACE::RayTracingInvocationReorderModeNV::eNone, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("extended_sparse_address_space") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceExtendedSparseAddressSpacePropertiesNV.def(py::init<vk::DeviceSize, vk::ImageUsageFlags, vk::BufferUsageFlags, void *>(), py::arg("extended_sparse_address_space_size") = vk::DeviceSize{}, py::arg("extended_sparse_image_usage_flags") = vk::ImageUsageFlags{}, py::arg("extended_sparse_buffer_usage_flags") = vk::BufferUsageFlags{}, py::arg("p_next") = nullptr);

    s_vk_MutableDescriptorTypeCreateInfoEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::MutableDescriptorTypeListEXT> &, const void *>(), py::arg("mutable_descriptor_type_lists"), py::arg("p_next") = nullptr);

    s_vk_MutableDescriptorTypeListEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::DescriptorType> &>(), py::arg("descriptor_types"));

    s_vk_PhysicalDeviceMutableDescriptorTypeFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("mutable_descriptor_type") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_LayerSettingEXT.def(py::init<const char *, const char *, vk::LayerSettingTypeEXT, uint32_t, const void *>(), py::arg("p_layer_name") = nullptr, py::arg("p_setting_name") = nullptr, py::arg("type") = VULKAN_HPP_NAMESPACE::LayerSettingTypeEXT::eBool32, py::arg("value_count") = uint32_t{}, py::arg("p_values") = nullptr);

    s_vk_LayerSettingsCreateInfoEXT.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::LayerSettingEXT> &, const void *>(), py::arg("settings"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderCoreBuiltinsFeaturesARM.def(py::init<vk::Bool32, void *>(), py::arg("shader_core_builtins") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceShaderCoreBuiltinsPropertiesARM.def(py::init<uint64_t, uint32_t, uint32_t, void *>(), py::arg("shader_core_mask") = uint64_t{}, py::arg("shader_core_count") = uint32_t{}, py::arg("shader_warps_per_core") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("pipeline_library_group_handles") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("dynamic_rendering_unused_attachments") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_GetLatencyMarkerInfoNV.def(py::init<const vk::ArrayProxyNoTemporaries<vk::LatencyTimingsFrameReportNV> &, const void *>(), py::arg("timings"), py::arg("p_next") = nullptr);

    s_vk_LatencySleepInfoNV.def(py::init<vk::Semaphore, uint64_t, const void *>(), py::arg("signal_semaphore") = vk::Semaphore{}, py::arg("value") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_LatencySleepModeInfoNV.def(py::init<vk::Bool32, vk::Bool32, uint32_t, const void *>(), py::arg("low_latency_mode") = vk::Bool32{}, py::arg("low_latency_boost") = vk::Bool32{}, py::arg("minimum_interval_us") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_LatencySubmissionPresentIdNV.def(py::init<uint64_t, const void *>(), py::arg("presentID") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_LatencySurfaceCapabilitiesNV.def(py::init<const vk::ArrayProxyNoTemporaries<vk::PresentModeKHR> &, const void *>(), py::arg("present_modes"), py::arg("p_next") = nullptr);

    s_vk_LatencyTimingsFrameReportNV.def(py::init<uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, const void *>(), py::arg("presentID") = uint64_t{}, py::arg("input_sample_time_us") = uint64_t{}, py::arg("sim_start_time_us") = uint64_t{}, py::arg("sim_end_time_us") = uint64_t{}, py::arg("render_submit_start_time_us") = uint64_t{}, py::arg("render_submit_end_time_us") = uint64_t{}, py::arg("present_start_time_us") = uint64_t{}, py::arg("present_end_time_us") = uint64_t{}, py::arg("driver_start_time_us") = uint64_t{}, py::arg("driver_end_time_us") = uint64_t{}, py::arg("os_render_queue_start_time_us") = uint64_t{}, py::arg("os_render_queue_end_time_us") = uint64_t{}, py::arg("gpu_render_start_time_us") = uint64_t{}, py::arg("gpu_render_end_time_us") = uint64_t{}, py::arg("p_next") = nullptr);

    s_vk_OutOfBandQueueTypeInfoNV.def(py::init<vk::OutOfBandQueueTypeNV, const void *>(), py::arg("queue_type") = VULKAN_HPP_NAMESPACE::OutOfBandQueueTypeNV::eRender, py::arg("p_next") = nullptr);

    s_vk_SetLatencyMarkerInfoNV.def(py::init<uint64_t, vk::LatencyMarkerNV, const void *>(), py::arg("presentID") = uint64_t{}, py::arg("marker") = VULKAN_HPP_NAMESPACE::LatencyMarkerNV::eSimulationStart, py::arg("p_next") = nullptr);

    s_vk_SwapchainLatencyCreateInfoNV.def(py::init<vk::Bool32, const void *>(), py::arg("latency_mode_enable") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_CooperativeMatrixPropertiesKHR.def(py::init<uint32_t, uint32_t, uint32_t, vk::ComponentTypeKHR, vk::ComponentTypeKHR, vk::ComponentTypeKHR, vk::ComponentTypeKHR, vk::Bool32, vk::ScopeKHR, void *>(), py::arg("m_size") = uint32_t{}, py::arg("n_size") = uint32_t{}, py::arg("k_size") = uint32_t{}, py::arg("a_type") = VULKAN_HPP_NAMESPACE::ComponentTypeKHR::eFloat16, py::arg("b_type") = VULKAN_HPP_NAMESPACE::ComponentTypeKHR::eFloat16, py::arg("c_type") = VULKAN_HPP_NAMESPACE::ComponentTypeKHR::eFloat16, py::arg("result_type") = VULKAN_HPP_NAMESPACE::ComponentTypeKHR::eFloat16, py::arg("saturating_accumulation") = vk::Bool32{}, py::arg("scope") = VULKAN_HPP_NAMESPACE::ScopeKHR::eDevice, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCooperativeMatrixFeaturesKHR.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("cooperative_matrix") = vk::Bool32{}, py::arg("cooperative_matrix_robust_buffer_access") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCooperativeMatrixPropertiesKHR.def(py::init<vk::ShaderStageFlags, void *>(), py::arg("cooperative_matrix_supported_stages") = vk::ShaderStageFlags{}, py::arg("p_next") = nullptr);

    s_vk_MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::Rect2D> &, const void *>(), py::arg("per_view_render_areas"), py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM.def(py::init<vk::Bool32, void *>(), py::arg("multiview_per_view_render_areas") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVideoMaintenance1FeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("video_maintenance_1") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_VideoInlineQueryInfoKHR.def(py::init<vk::QueryPool, uint32_t, uint32_t, const void *>(), py::arg("query_pool") = vk::QueryPool{}, py::arg("first_query") = uint32_t{}, py::arg("query_count") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDevicePerStageDescriptorSetFeaturesNV.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("per_stage_descriptor_set") = vk::Bool32{}, py::arg("dynamic_pipeline_layout") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageProcessing2FeaturesQCOM.def(py::init<vk::Bool32, void *>(), py::arg("texture_block_match_2") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceImageProcessing2PropertiesQCOM.def(py::init<vk::Extent2D, void *>(), py::arg("max_block_match_window") = vk::Extent2D{}, py::arg("p_next") = nullptr);

    s_vk_SamplerBlockMatchWindowCreateInfoQCOM.def(py::init<vk::Extent2D, vk::BlockMatchWindowCompareModeQCOM, const void *>(), py::arg("window_extent") = vk::Extent2D{}, py::arg("window_compare_mode") = VULKAN_HPP_NAMESPACE::BlockMatchWindowCompareModeQCOM::eMin, py::arg("p_next") = nullptr);

    s_vk_BlitImageCubicWeightsInfoQCOM.def(py::init<vk::CubicFilterWeightsQCOM, const void *>(), py::arg("cubic_weights") = VULKAN_HPP_NAMESPACE::CubicFilterWeightsQCOM::eCatmullRom, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCubicWeightsFeaturesQCOM.def(py::init<vk::Bool32, void *>(), py::arg("selectable_cubic_weights") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SamplerCubicWeightsCreateInfoQCOM.def(py::init<vk::CubicFilterWeightsQCOM, const void *>(), py::arg("cubic_weights") = VULKAN_HPP_NAMESPACE::CubicFilterWeightsQCOM::eCatmullRom, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceYcbcrDegammaFeaturesQCOM.def(py::init<vk::Bool32, void *>(), py::arg("ycbcr_degamma") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("enableY_degamma") = vk::Bool32{}, py::arg("enable_cb_cr_degamma") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceCubicClampFeaturesQCOM.def(py::init<vk::Bool32, void *>(), py::arg("cubic_range_clamp") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT.def(py::init<vk::Bool32, void *>(), py::arg("attachment_feedback_loop_dynamic_state") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVertexAttributeDivisorFeaturesKHR.def(py::init<vk::Bool32, vk::Bool32, void *>(), py::arg("vertex_attribute_instance_rate_divisor") = vk::Bool32{}, py::arg("vertex_attribute_instance_rate_zero_divisor") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceVertexAttributeDivisorPropertiesKHR.def(py::init<uint32_t, vk::Bool32, void *>(), py::arg("max_vertex_attrib_divisor") = uint32_t{}, py::arg("supports_non_zero_first_instance") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PipelineVertexInputDivisorStateCreateInfoKHR.def(py::init<const vk::ArrayProxyNoTemporaries<const vk::VertexInputBindingDivisorDescriptionKHR> &, const void *>(), py::arg("vertex_binding_divisors"), py::arg("p_next") = nullptr);

    s_vk_VertexInputBindingDivisorDescriptionKHR.def(py::init<uint32_t, uint32_t>(), py::arg("binding") = uint32_t{}, py::arg("divisor") = uint32_t{});

    s_vk_PhysicalDeviceLayeredDriverPropertiesMSFT.def(py::init<vk::LayeredDriverUnderlyingApiMSFT, void *>(), py::arg("underlyingAPI") = VULKAN_HPP_NAMESPACE::LayeredDriverUnderlyingApiMSFT::eNone, py::arg("p_next") = nullptr);

    s_vk_CalibratedTimestampInfoKHR.def(py::init<vk::TimeDomainKHR, const void *>(), py::arg("time_domain") = VULKAN_HPP_NAMESPACE::TimeDomainKHR::eDevice, py::arg("p_next") = nullptr);

    s_vk_BindDescriptorBufferEmbeddedSamplersInfoEXT.def(py::init<vk::ShaderStageFlags, vk::PipelineLayout, uint32_t, const void *>(), py::arg("stage_flags") = vk::ShaderStageFlags{}, py::arg("layout") = vk::PipelineLayout{}, py::arg("set") = uint32_t{}, py::arg("p_next") = nullptr);

    s_vk_BindDescriptorSetsInfoKHR.def(py::init<vk::ShaderStageFlags, vk::PipelineLayout, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::DescriptorSet> &, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const void *>(), py::arg("stage_flags"), py::arg("layout"), py::arg("first_set"), py::arg("descriptor_sets"), py::arg("dynamic_offsets") = vk::ArrayProxyNoTemporaries<const uint32_t>{}, py::arg("p_next") = nullptr);

    s_vk_BindMemoryStatusKHR.def(py::init<vk::Result *, const void *>(), py::arg("p_result") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMaintenance6FeaturesKHR.def(py::init<vk::Bool32, void *>(), py::arg("maintenance6") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceMaintenance6PropertiesKHR.def(py::init<vk::Bool32, uint32_t, vk::Bool32, void *>(), py::arg("block_texel_view_compatible_multiple_layers") = vk::Bool32{}, py::arg("max_combined_image_sampler_descriptor_count") = uint32_t{}, py::arg("fragment_shading_rate_clamp_combiner_inputs") = vk::Bool32{}, py::arg("p_next") = nullptr);

    s_vk_PushConstantsInfoKHR.def(py::init<vk::PipelineLayout, vk::ShaderStageFlags, uint32_t, uint32_t, const void *, const void *>(), py::arg("layout") = vk::PipelineLayout{}, py::arg("stage_flags") = vk::ShaderStageFlags{}, py::arg("offset") = uint32_t{}, py::arg("size") = uint32_t{}, py::arg("p_values") = nullptr, py::arg("p_next") = nullptr);

    s_vk_PushDescriptorSetInfoKHR.def(py::init<vk::ShaderStageFlags, vk::PipelineLayout, uint32_t, const vk::ArrayProxyNoTemporaries<const vk::WriteDescriptorSet> &, const void *>(), py::arg("stage_flags"), py::arg("layout"), py::arg("set"), py::arg("descriptor_writes"), py::arg("p_next") = nullptr);

    s_vk_PushDescriptorSetWithTemplateInfoKHR.def(py::init<vk::DescriptorUpdateTemplate, vk::PipelineLayout, uint32_t, const void *, const void *>(), py::arg("descriptor_update_template") = vk::DescriptorUpdateTemplate{}, py::arg("layout") = vk::PipelineLayout{}, py::arg("set") = uint32_t{}, py::arg("p_data") = nullptr, py::arg("p_next") = nullptr);

    s_vk_SetDescriptorBufferOffsetsInfoEXT.def(py::init<vk::ShaderStageFlags, vk::PipelineLayout, uint32_t, const vk::ArrayProxyNoTemporaries<const uint32_t> &, const vk::ArrayProxyNoTemporaries<const vk::DeviceSize> &, const void *>(), py::arg("stage_flags"), py::arg("layout"), py::arg("first_set"), py::arg("buffer_indices"), py::arg("offsets") = vk::ArrayProxyNoTemporaries<const vk::DeviceSize>{}, py::arg("p_next") = nullptr);

    s_vk_PhysicalDeviceDescriptorPoolOverallocationFeaturesNV.def(py::init<vk::Bool32, void *>(), py::arg("descriptor_pool_overallocation") = vk::Bool32{}, py::arg("p_next") = nullptr);
}
