#include <pybind11/pybind11.h>
#include <vulkan/vulkan.hpp>

namespace py = pybind11;

PYBIND11_MODULE(pyvulkan, m) {
    py::module m_vk = m.def_submodule("vk");
    py::module m_raii = m_vk.def_submodule("raii");

    py::enum_<vk::AccessFlagBits> e_vk_AccessFlagBits(m_vk, "AccessFlagBits");
    e_vk_AccessFlagBits.value("INDIRECT_COMMAND_READ", vk::AccessFlagBits::eIndirectCommandRead);
    e_vk_AccessFlagBits.value("INDEX_READ", vk::AccessFlagBits::eIndexRead);
    e_vk_AccessFlagBits.value("VERTEX_ATTRIBUTE_READ", vk::AccessFlagBits::eVertexAttributeRead);
    e_vk_AccessFlagBits.value("UNIFORM_READ", vk::AccessFlagBits::eUniformRead);
    e_vk_AccessFlagBits.value("INPUT_ATTACHMENT_READ", vk::AccessFlagBits::eInputAttachmentRead);
    e_vk_AccessFlagBits.value("SHADER_READ", vk::AccessFlagBits::eShaderRead);
    e_vk_AccessFlagBits.value("SHADER_WRITE", vk::AccessFlagBits::eShaderWrite);
    e_vk_AccessFlagBits.value("COLOR_ATTACHMENT_READ", vk::AccessFlagBits::eColorAttachmentRead);
    e_vk_AccessFlagBits.value("COLOR_ATTACHMENT_WRITE", vk::AccessFlagBits::eColorAttachmentWrite);
    e_vk_AccessFlagBits.value("DEPTH_STENCIL_ATTACHMENT_READ", vk::AccessFlagBits::eDepthStencilAttachmentRead);
    e_vk_AccessFlagBits.value("DEPTH_STENCIL_ATTACHMENT_WRITE", vk::AccessFlagBits::eDepthStencilAttachmentWrite);
    e_vk_AccessFlagBits.value("TRANSFER_READ", vk::AccessFlagBits::eTransferRead);
    e_vk_AccessFlagBits.value("TRANSFER_WRITE", vk::AccessFlagBits::eTransferWrite);
    e_vk_AccessFlagBits.value("HOST_READ", vk::AccessFlagBits::eHostRead);
    e_vk_AccessFlagBits.value("HOST_WRITE", vk::AccessFlagBits::eHostWrite);
    e_vk_AccessFlagBits.value("MEMORY_READ", vk::AccessFlagBits::eMemoryRead);
    e_vk_AccessFlagBits.value("MEMORY_WRITE", vk::AccessFlagBits::eMemoryWrite);
    e_vk_AccessFlagBits.value("NONE", vk::AccessFlagBits::eNone);
    e_vk_AccessFlagBits.value("TRANSFORM_FEEDBACK_WRITE_EXT", vk::AccessFlagBits::eTransformFeedbackWriteEXT);
    e_vk_AccessFlagBits.value("TRANSFORM_FEEDBACK_COUNTER_READ_EXT", vk::AccessFlagBits::eTransformFeedbackCounterReadEXT);
    e_vk_AccessFlagBits.value("TRANSFORM_FEEDBACK_COUNTER_WRITE_EXT", vk::AccessFlagBits::eTransformFeedbackCounterWriteEXT);
    e_vk_AccessFlagBits.value("CONDITIONAL_RENDERING_READ_EXT", vk::AccessFlagBits::eConditionalRenderingReadEXT);
    e_vk_AccessFlagBits.value("COLOR_ATTACHMENT_READ_NONCOHERENT_EXT", vk::AccessFlagBits::eColorAttachmentReadNoncoherentEXT);
    e_vk_AccessFlagBits.value("ACCELERATION_STRUCTURE_READ_KHR", vk::AccessFlagBits::eAccelerationStructureReadKHR);
    e_vk_AccessFlagBits.value("ACCELERATION_STRUCTURE_WRITE_KHR", vk::AccessFlagBits::eAccelerationStructureWriteKHR);
    e_vk_AccessFlagBits.value("SHADING_RATE_IMAGE_READ_NV", vk::AccessFlagBits::eShadingRateImageReadNV);
    e_vk_AccessFlagBits.value("ACCELERATION_STRUCTURE_READ_NV", vk::AccessFlagBits::eAccelerationStructureReadNV);
    e_vk_AccessFlagBits.value("ACCELERATION_STRUCTURE_WRITE_NV", vk::AccessFlagBits::eAccelerationStructureWriteNV);
    e_vk_AccessFlagBits.value("FRAGMENT_DENSITY_MAP_READ_EXT", vk::AccessFlagBits::eFragmentDensityMapReadEXT);
    e_vk_AccessFlagBits.value("FRAGMENT_SHADING_RATE_ATTACHMENT_READ_KHR", vk::AccessFlagBits::eFragmentShadingRateAttachmentReadKHR);
    e_vk_AccessFlagBits.value("COMMAND_PREPROCESS_READ_NV", vk::AccessFlagBits::eCommandPreprocessReadNV);
    e_vk_AccessFlagBits.value("COMMAND_PREPROCESS_WRITE_NV", vk::AccessFlagBits::eCommandPreprocessWriteNV);
    e_vk_AccessFlagBits.value("NONE_KHR", vk::AccessFlagBits::eNoneKHR);

    py::enum_<vk::AttachmentDescriptionFlagBits> e_vk_AttachmentDescriptionFlagBits(m_vk, "AttachmentDescriptionFlagBits");
    e_vk_AttachmentDescriptionFlagBits.value("MAY_ALIAS", vk::AttachmentDescriptionFlagBits::eMayAlias);

    py::enum_<vk::AttachmentLoadOp> e_vk_AttachmentLoadOp(m_vk, "AttachmentLoadOp");
    e_vk_AttachmentLoadOp.value("LOAD", vk::AttachmentLoadOp::eLoad);
    e_vk_AttachmentLoadOp.value("CLEAR", vk::AttachmentLoadOp::eClear);
    e_vk_AttachmentLoadOp.value("DONT_CARE", vk::AttachmentLoadOp::eDontCare);
    e_vk_AttachmentLoadOp.value("NONE_EXT", vk::AttachmentLoadOp::eNoneEXT);

    py::enum_<vk::AttachmentStoreOp> e_vk_AttachmentStoreOp(m_vk, "AttachmentStoreOp");
    e_vk_AttachmentStoreOp.value("STORE", vk::AttachmentStoreOp::eStore);
    e_vk_AttachmentStoreOp.value("DONT_CARE", vk::AttachmentStoreOp::eDontCare);
    e_vk_AttachmentStoreOp.value("NONE", vk::AttachmentStoreOp::eNone);
    e_vk_AttachmentStoreOp.value("NONE_KHR", vk::AttachmentStoreOp::eNoneKHR);
    e_vk_AttachmentStoreOp.value("NONE_QCOM", vk::AttachmentStoreOp::eNoneQCOM);
    e_vk_AttachmentStoreOp.value("NONE_EXT", vk::AttachmentStoreOp::eNoneEXT);

    py::enum_<vk::BlendFactor> e_vk_BlendFactor(m_vk, "BlendFactor");
    e_vk_BlendFactor.value("ZERO", vk::BlendFactor::eZero);
    e_vk_BlendFactor.value("ONE", vk::BlendFactor::eOne);
    e_vk_BlendFactor.value("SRC_COLOR", vk::BlendFactor::eSrcColor);
    e_vk_BlendFactor.value("ONE_MINUS_SRC_COLOR", vk::BlendFactor::eOneMinusSrcColor);
    e_vk_BlendFactor.value("DST_COLOR", vk::BlendFactor::eDstColor);
    e_vk_BlendFactor.value("ONE_MINUS_DST_COLOR", vk::BlendFactor::eOneMinusDstColor);
    e_vk_BlendFactor.value("SRC_ALPHA", vk::BlendFactor::eSrcAlpha);
    e_vk_BlendFactor.value("ONE_MINUS_SRC_ALPHA", vk::BlendFactor::eOneMinusSrcAlpha);
    e_vk_BlendFactor.value("DST_ALPHA", vk::BlendFactor::eDstAlpha);
    e_vk_BlendFactor.value("ONE_MINUS_DST_ALPHA", vk::BlendFactor::eOneMinusDstAlpha);
    e_vk_BlendFactor.value("CONSTANT_COLOR", vk::BlendFactor::eConstantColor);
    e_vk_BlendFactor.value("ONE_MINUS_CONSTANT_COLOR", vk::BlendFactor::eOneMinusConstantColor);
    e_vk_BlendFactor.value("CONSTANT_ALPHA", vk::BlendFactor::eConstantAlpha);
    e_vk_BlendFactor.value("ONE_MINUS_CONSTANT_ALPHA", vk::BlendFactor::eOneMinusConstantAlpha);
    e_vk_BlendFactor.value("SRC_ALPHA_SATURATE", vk::BlendFactor::eSrcAlphaSaturate);
    e_vk_BlendFactor.value("SRC_1_COLOR", vk::BlendFactor::eSrc1Color);
    e_vk_BlendFactor.value("ONE_MINUS_SRC_1_COLOR", vk::BlendFactor::eOneMinusSrc1Color);
    e_vk_BlendFactor.value("SRC_1_ALPHA", vk::BlendFactor::eSrc1Alpha);
    e_vk_BlendFactor.value("ONE_MINUS_SRC_1_ALPHA", vk::BlendFactor::eOneMinusSrc1Alpha);

    py::enum_<vk::BlendOp> e_vk_BlendOp(m_vk, "BlendOp");
    e_vk_BlendOp.value("ADD", vk::BlendOp::eAdd);
    e_vk_BlendOp.value("SUBTRACT", vk::BlendOp::eSubtract);
    e_vk_BlendOp.value("REVERSE_SUBTRACT", vk::BlendOp::eReverseSubtract);
    e_vk_BlendOp.value("MIN", vk::BlendOp::eMin);
    e_vk_BlendOp.value("MAX", vk::BlendOp::eMax);
    e_vk_BlendOp.value("ZERO_EXT", vk::BlendOp::eZeroEXT);
    e_vk_BlendOp.value("SRC_EXT", vk::BlendOp::eSrcEXT);
    e_vk_BlendOp.value("DST_EXT", vk::BlendOp::eDstEXT);
    e_vk_BlendOp.value("SRC_OVER_EXT", vk::BlendOp::eSrcOverEXT);
    e_vk_BlendOp.value("DST_OVER_EXT", vk::BlendOp::eDstOverEXT);
    e_vk_BlendOp.value("SRC_IN_EXT", vk::BlendOp::eSrcInEXT);
    e_vk_BlendOp.value("DST_IN_EXT", vk::BlendOp::eDstInEXT);
    e_vk_BlendOp.value("SRC_OUT_EXT", vk::BlendOp::eSrcOutEXT);
    e_vk_BlendOp.value("DST_OUT_EXT", vk::BlendOp::eDstOutEXT);
    e_vk_BlendOp.value("SRC_ATOP_EXT", vk::BlendOp::eSrcAtopEXT);
    e_vk_BlendOp.value("DST_ATOP_EXT", vk::BlendOp::eDstAtopEXT);
    e_vk_BlendOp.value("XOR_EXT", vk::BlendOp::eXorEXT);
    e_vk_BlendOp.value("MULTIPLY_EXT", vk::BlendOp::eMultiplyEXT);
    e_vk_BlendOp.value("SCREEN_EXT", vk::BlendOp::eScreenEXT);
    e_vk_BlendOp.value("OVERLAY_EXT", vk::BlendOp::eOverlayEXT);
    e_vk_BlendOp.value("DARKEN_EXT", vk::BlendOp::eDarkenEXT);
    e_vk_BlendOp.value("LIGHTEN_EXT", vk::BlendOp::eLightenEXT);
    e_vk_BlendOp.value("COLORDODGE_EXT", vk::BlendOp::eColordodgeEXT);
    e_vk_BlendOp.value("COLORBURN_EXT", vk::BlendOp::eColorburnEXT);
    e_vk_BlendOp.value("HARDLIGHT_EXT", vk::BlendOp::eHardlightEXT);
    e_vk_BlendOp.value("SOFTLIGHT_EXT", vk::BlendOp::eSoftlightEXT);
    e_vk_BlendOp.value("DIFFERENCE_EXT", vk::BlendOp::eDifferenceEXT);
    e_vk_BlendOp.value("EXCLUSION_EXT", vk::BlendOp::eExclusionEXT);
    e_vk_BlendOp.value("INVERT_EXT", vk::BlendOp::eInvertEXT);
    e_vk_BlendOp.value("INVERT_RGB_EXT", vk::BlendOp::eInvertRgbEXT);
    e_vk_BlendOp.value("LINEARDODGE_EXT", vk::BlendOp::eLineardodgeEXT);
    e_vk_BlendOp.value("LINEARBURN_EXT", vk::BlendOp::eLinearburnEXT);
    e_vk_BlendOp.value("VIVIDLIGHT_EXT", vk::BlendOp::eVividlightEXT);
    e_vk_BlendOp.value("LINEARLIGHT_EXT", vk::BlendOp::eLinearlightEXT);
    e_vk_BlendOp.value("PINLIGHT_EXT", vk::BlendOp::ePinlightEXT);
    e_vk_BlendOp.value("HARDMIX_EXT", vk::BlendOp::eHardmixEXT);
    e_vk_BlendOp.value("HSL_HUE_EXT", vk::BlendOp::eHslHueEXT);
    e_vk_BlendOp.value("HSL_SATURATION_EXT", vk::BlendOp::eHslSaturationEXT);
    e_vk_BlendOp.value("HSL_COLOR_EXT", vk::BlendOp::eHslColorEXT);
    e_vk_BlendOp.value("HSL_LUMINOSITY_EXT", vk::BlendOp::eHslLuminosityEXT);
    e_vk_BlendOp.value("PLUS_EXT", vk::BlendOp::ePlusEXT);
    e_vk_BlendOp.value("PLUS_CLAMPED_EXT", vk::BlendOp::ePlusClampedEXT);
    e_vk_BlendOp.value("PLUS_CLAMPED_ALPHA_EXT", vk::BlendOp::ePlusClampedAlphaEXT);
    e_vk_BlendOp.value("PLUS_DARKER_EXT", vk::BlendOp::ePlusDarkerEXT);
    e_vk_BlendOp.value("MINUS_EXT", vk::BlendOp::eMinusEXT);
    e_vk_BlendOp.value("MINUS_CLAMPED_EXT", vk::BlendOp::eMinusClampedEXT);
    e_vk_BlendOp.value("CONTRAST_EXT", vk::BlendOp::eContrastEXT);
    e_vk_BlendOp.value("INVERT_OVG_EXT", vk::BlendOp::eInvertOvgEXT);
    e_vk_BlendOp.value("RED_EXT", vk::BlendOp::eRedEXT);
    e_vk_BlendOp.value("GREEN_EXT", vk::BlendOp::eGreenEXT);
    e_vk_BlendOp.value("BLUE_EXT", vk::BlendOp::eBlueEXT);

    py::enum_<vk::BorderColor> e_vk_BorderColor(m_vk, "BorderColor");
    e_vk_BorderColor.value("FLOAT_TRANSPARENT_BLACK", vk::BorderColor::eFloatTransparentBlack);
    e_vk_BorderColor.value("INT_TRANSPARENT_BLACK", vk::BorderColor::eIntTransparentBlack);
    e_vk_BorderColor.value("FLOAT_OPAQUE_BLACK", vk::BorderColor::eFloatOpaqueBlack);
    e_vk_BorderColor.value("INT_OPAQUE_BLACK", vk::BorderColor::eIntOpaqueBlack);
    e_vk_BorderColor.value("FLOAT_OPAQUE_WHITE", vk::BorderColor::eFloatOpaqueWhite);
    e_vk_BorderColor.value("INT_OPAQUE_WHITE", vk::BorderColor::eIntOpaqueWhite);
    e_vk_BorderColor.value("FLOAT_CUSTOM_EXT", vk::BorderColor::eFloatCustomEXT);
    e_vk_BorderColor.value("INT_CUSTOM_EXT", vk::BorderColor::eIntCustomEXT);

    py::enum_<vk::BufferCreateFlagBits> e_vk_BufferCreateFlagBits(m_vk, "BufferCreateFlagBits");
    e_vk_BufferCreateFlagBits.value("SPARSE_BINDING", vk::BufferCreateFlagBits::eSparseBinding);
    e_vk_BufferCreateFlagBits.value("SPARSE_RESIDENCY", vk::BufferCreateFlagBits::eSparseResidency);
    e_vk_BufferCreateFlagBits.value("SPARSE_ALIASED", vk::BufferCreateFlagBits::eSparseAliased);
    e_vk_BufferCreateFlagBits.value("PROTECTED", vk::BufferCreateFlagBits::eProtected);
    e_vk_BufferCreateFlagBits.value("DEVICE_ADDRESS_CAPTURE_REPLAY", vk::BufferCreateFlagBits::eDeviceAddressCaptureReplay);
    e_vk_BufferCreateFlagBits.value("DEVICE_ADDRESS_CAPTURE_REPLAY_EXT", vk::BufferCreateFlagBits::eDeviceAddressCaptureReplayEXT);
    e_vk_BufferCreateFlagBits.value("DEVICE_ADDRESS_CAPTURE_REPLAY_KHR", vk::BufferCreateFlagBits::eDeviceAddressCaptureReplayKHR);
    e_vk_BufferCreateFlagBits.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", vk::BufferCreateFlagBits::eDescriptorBufferCaptureReplayEXT);
    e_vk_BufferCreateFlagBits.value("VIDEO_PROFILE_INDEPENDENT_KHR", vk::BufferCreateFlagBits::eVideoProfileIndependentKHR);

    py::enum_<vk::BufferUsageFlagBits> e_vk_BufferUsageFlagBits(m_vk, "BufferUsageFlagBits");
    e_vk_BufferUsageFlagBits.value("TRANSFER_SRC", vk::BufferUsageFlagBits::eTransferSrc);
    e_vk_BufferUsageFlagBits.value("TRANSFER_DST", vk::BufferUsageFlagBits::eTransferDst);
    e_vk_BufferUsageFlagBits.value("UNIFORM_TEXEL_BUFFER", vk::BufferUsageFlagBits::eUniformTexelBuffer);
    e_vk_BufferUsageFlagBits.value("STORAGE_TEXEL_BUFFER", vk::BufferUsageFlagBits::eStorageTexelBuffer);
    e_vk_BufferUsageFlagBits.value("UNIFORM_BUFFER", vk::BufferUsageFlagBits::eUniformBuffer);
    e_vk_BufferUsageFlagBits.value("STORAGE_BUFFER", vk::BufferUsageFlagBits::eStorageBuffer);
    e_vk_BufferUsageFlagBits.value("INDEX_BUFFER", vk::BufferUsageFlagBits::eIndexBuffer);
    e_vk_BufferUsageFlagBits.value("VERTEX_BUFFER", vk::BufferUsageFlagBits::eVertexBuffer);
    e_vk_BufferUsageFlagBits.value("INDIRECT_BUFFER", vk::BufferUsageFlagBits::eIndirectBuffer);
    e_vk_BufferUsageFlagBits.value("SHADER_DEVICE_ADDRESS", vk::BufferUsageFlagBits::eShaderDeviceAddress);
    e_vk_BufferUsageFlagBits.value("VIDEO_DECODE_SRC_KHR", vk::BufferUsageFlagBits::eVideoDecodeSrcKHR);
    e_vk_BufferUsageFlagBits.value("VIDEO_DECODE_DST_KHR", vk::BufferUsageFlagBits::eVideoDecodeDstKHR);
    e_vk_BufferUsageFlagBits.value("TRANSFORM_FEEDBACK_BUFFER_EXT", vk::BufferUsageFlagBits::eTransformFeedbackBufferEXT);
    e_vk_BufferUsageFlagBits.value("TRANSFORM_FEEDBACK_COUNTER_BUFFER_EXT", vk::BufferUsageFlagBits::eTransformFeedbackCounterBufferEXT);
    e_vk_BufferUsageFlagBits.value("CONDITIONAL_RENDERING_EXT", vk::BufferUsageFlagBits::eConditionalRenderingEXT);
    e_vk_BufferUsageFlagBits.value("ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_KHR", vk::BufferUsageFlagBits::eAccelerationStructureBuildInputReadOnlyKHR);
    e_vk_BufferUsageFlagBits.value("ACCELERATION_STRUCTURE_STORAGE_KHR", vk::BufferUsageFlagBits::eAccelerationStructureStorageKHR);
    e_vk_BufferUsageFlagBits.value("SHADER_BINDING_TABLE_KHR", vk::BufferUsageFlagBits::eShaderBindingTableKHR);
    e_vk_BufferUsageFlagBits.value("RAY_TRACING_NV", vk::BufferUsageFlagBits::eRayTracingNV);
    e_vk_BufferUsageFlagBits.value("SHADER_DEVICE_ADDRESS_EXT", vk::BufferUsageFlagBits::eShaderDeviceAddressEXT);
    e_vk_BufferUsageFlagBits.value("SHADER_DEVICE_ADDRESS_KHR", vk::BufferUsageFlagBits::eShaderDeviceAddressKHR);
    e_vk_BufferUsageFlagBits.value("VIDEO_ENCODE_DST_KHR", vk::BufferUsageFlagBits::eVideoEncodeDstKHR);
    e_vk_BufferUsageFlagBits.value("VIDEO_ENCODE_SRC_KHR", vk::BufferUsageFlagBits::eVideoEncodeSrcKHR);
    e_vk_BufferUsageFlagBits.value("SAMPLER_DESCRIPTOR_BUFFER_EXT", vk::BufferUsageFlagBits::eSamplerDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits.value("RESOURCE_DESCRIPTOR_BUFFER_EXT", vk::BufferUsageFlagBits::eResourceDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits.value("PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_EXT", vk::BufferUsageFlagBits::ePushDescriptorsDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits.value("MICROMAP_BUILD_INPUT_READ_ONLY_EXT", vk::BufferUsageFlagBits::eMicromapBuildInputReadOnlyEXT);
    e_vk_BufferUsageFlagBits.value("MICROMAP_STORAGE_EXT", vk::BufferUsageFlagBits::eMicromapStorageEXT);

    py::enum_<vk::BufferViewCreateFlagBits> e_vk_BufferViewCreateFlagBits(m_vk, "BufferViewCreateFlagBits");

    py::enum_<vk::ColorComponentFlagBits> e_vk_ColorComponentFlagBits(m_vk, "ColorComponentFlagBits");
    e_vk_ColorComponentFlagBits.value("R", vk::ColorComponentFlagBits::eR);
    e_vk_ColorComponentFlagBits.value("G", vk::ColorComponentFlagBits::eG);
    e_vk_ColorComponentFlagBits.value("B", vk::ColorComponentFlagBits::eB);
    e_vk_ColorComponentFlagBits.value("A", vk::ColorComponentFlagBits::eA);

    py::enum_<vk::CommandBufferLevel> e_vk_CommandBufferLevel(m_vk, "CommandBufferLevel");
    e_vk_CommandBufferLevel.value("PRIMARY", vk::CommandBufferLevel::ePrimary);
    e_vk_CommandBufferLevel.value("SECONDARY", vk::CommandBufferLevel::eSecondary);

    py::enum_<vk::CommandBufferResetFlagBits> e_vk_CommandBufferResetFlagBits(m_vk, "CommandBufferResetFlagBits");
    e_vk_CommandBufferResetFlagBits.value("RELEASE_RESOURCES", vk::CommandBufferResetFlagBits::eReleaseResources);

    py::enum_<vk::CommandBufferUsageFlagBits> e_vk_CommandBufferUsageFlagBits(m_vk, "CommandBufferUsageFlagBits");
    e_vk_CommandBufferUsageFlagBits.value("ONE_TIME_SUBMIT", vk::CommandBufferUsageFlagBits::eOneTimeSubmit);
    e_vk_CommandBufferUsageFlagBits.value("RENDER_PASS_CONTINUE", vk::CommandBufferUsageFlagBits::eRenderPassContinue);
    e_vk_CommandBufferUsageFlagBits.value("SIMULTANEOUS_USE", vk::CommandBufferUsageFlagBits::eSimultaneousUse);

    py::enum_<vk::CommandPoolCreateFlagBits> e_vk_CommandPoolCreateFlagBits(m_vk, "CommandPoolCreateFlagBits");
    e_vk_CommandPoolCreateFlagBits.value("TRANSIENT", vk::CommandPoolCreateFlagBits::eTransient);
    e_vk_CommandPoolCreateFlagBits.value("RESET_COMMAND_BUFFER", vk::CommandPoolCreateFlagBits::eResetCommandBuffer);
    e_vk_CommandPoolCreateFlagBits.value("PROTECTED", vk::CommandPoolCreateFlagBits::eProtected);

    py::enum_<vk::CommandPoolResetFlagBits> e_vk_CommandPoolResetFlagBits(m_vk, "CommandPoolResetFlagBits");
    e_vk_CommandPoolResetFlagBits.value("RELEASE_RESOURCES", vk::CommandPoolResetFlagBits::eReleaseResources);

    py::enum_<vk::CompareOp> e_vk_CompareOp(m_vk, "CompareOp");
    e_vk_CompareOp.value("NEVER", vk::CompareOp::eNever);
    e_vk_CompareOp.value("LESS", vk::CompareOp::eLess);
    e_vk_CompareOp.value("EQUAL", vk::CompareOp::eEqual);
    e_vk_CompareOp.value("LESS_OR_EQUAL", vk::CompareOp::eLessOrEqual);
    e_vk_CompareOp.value("GREATER", vk::CompareOp::eGreater);
    e_vk_CompareOp.value("NOT_EQUAL", vk::CompareOp::eNotEqual);
    e_vk_CompareOp.value("GREATER_OR_EQUAL", vk::CompareOp::eGreaterOrEqual);
    e_vk_CompareOp.value("ALWAYS", vk::CompareOp::eAlways);

    py::enum_<vk::ComponentSwizzle> e_vk_ComponentSwizzle(m_vk, "ComponentSwizzle");
    e_vk_ComponentSwizzle.value("IDENTITY", vk::ComponentSwizzle::eIdentity);
    e_vk_ComponentSwizzle.value("ZERO", vk::ComponentSwizzle::eZero);
    e_vk_ComponentSwizzle.value("ONE", vk::ComponentSwizzle::eOne);
    e_vk_ComponentSwizzle.value("R", vk::ComponentSwizzle::eR);
    e_vk_ComponentSwizzle.value("G", vk::ComponentSwizzle::eG);
    e_vk_ComponentSwizzle.value("B", vk::ComponentSwizzle::eB);
    e_vk_ComponentSwizzle.value("A", vk::ComponentSwizzle::eA);

    py::enum_<vk::CullModeFlagBits> e_vk_CullModeFlagBits(m_vk, "CullModeFlagBits");
    e_vk_CullModeFlagBits.value("NONE", vk::CullModeFlagBits::eNone);
    e_vk_CullModeFlagBits.value("FRONT", vk::CullModeFlagBits::eFront);
    e_vk_CullModeFlagBits.value("BACK", vk::CullModeFlagBits::eBack);
    e_vk_CullModeFlagBits.value("FRONT_AND_BACK", vk::CullModeFlagBits::eFrontAndBack);

    py::enum_<vk::DependencyFlagBits> e_vk_DependencyFlagBits(m_vk, "DependencyFlagBits");
    e_vk_DependencyFlagBits.value("BY_REGION", vk::DependencyFlagBits::eByRegion);
    e_vk_DependencyFlagBits.value("DEVICE_GROUP", vk::DependencyFlagBits::eDeviceGroup);
    e_vk_DependencyFlagBits.value("VIEW_LOCAL", vk::DependencyFlagBits::eViewLocal);
    e_vk_DependencyFlagBits.value("VIEW_LOCAL_KHR", vk::DependencyFlagBits::eViewLocalKHR);
    e_vk_DependencyFlagBits.value("DEVICE_GROUP_KHR", vk::DependencyFlagBits::eDeviceGroupKHR);
    e_vk_DependencyFlagBits.value("FEEDBACK_LOOP_EXT", vk::DependencyFlagBits::eFeedbackLoopEXT);

    py::enum_<vk::DescriptorPoolCreateFlagBits> e_vk_DescriptorPoolCreateFlagBits(m_vk, "DescriptorPoolCreateFlagBits");
    e_vk_DescriptorPoolCreateFlagBits.value("FREE_DESCRIPTOR_SET", vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet);
    e_vk_DescriptorPoolCreateFlagBits.value("UPDATE_AFTER_BIND", vk::DescriptorPoolCreateFlagBits::eUpdateAfterBind);
    e_vk_DescriptorPoolCreateFlagBits.value("UPDATE_AFTER_BIND_EXT", vk::DescriptorPoolCreateFlagBits::eUpdateAfterBindEXT);
    e_vk_DescriptorPoolCreateFlagBits.value("HOST_ONLY_VALVE", vk::DescriptorPoolCreateFlagBits::eHostOnlyVALVE);
    e_vk_DescriptorPoolCreateFlagBits.value("HOST_ONLY_EXT", vk::DescriptorPoolCreateFlagBits::eHostOnlyEXT);
    e_vk_DescriptorPoolCreateFlagBits.value("ALLOW_OVERALLOCATION_SETS_NV", vk::DescriptorPoolCreateFlagBits::eAllowOverallocationSetsNV);
    e_vk_DescriptorPoolCreateFlagBits.value("ALLOW_OVERALLOCATION_POOLS_NV", vk::DescriptorPoolCreateFlagBits::eAllowOverallocationPoolsNV);

    py::enum_<vk::DescriptorPoolResetFlagBits> e_vk_DescriptorPoolResetFlagBits(m_vk, "DescriptorPoolResetFlagBits");

    py::enum_<vk::DescriptorSetLayoutCreateFlagBits> e_vk_DescriptorSetLayoutCreateFlagBits(m_vk, "DescriptorSetLayoutCreateFlagBits");
    e_vk_DescriptorSetLayoutCreateFlagBits.value("UPDATE_AFTER_BIND_POOL", vk::DescriptorSetLayoutCreateFlagBits::eUpdateAfterBindPool);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("PUSH_DESCRIPTOR_KHR", vk::DescriptorSetLayoutCreateFlagBits::ePushDescriptorKHR);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("UPDATE_AFTER_BIND_POOL_EXT", vk::DescriptorSetLayoutCreateFlagBits::eUpdateAfterBindPoolEXT);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("DESCRIPTOR_BUFFER_EXT", vk::DescriptorSetLayoutCreateFlagBits::eDescriptorBufferEXT);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("EMBEDDED_IMMUTABLE_SAMPLERS_EXT", vk::DescriptorSetLayoutCreateFlagBits::eEmbeddedImmutableSamplersEXT);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("HOST_ONLY_POOL_VALVE", vk::DescriptorSetLayoutCreateFlagBits::eHostOnlyPoolVALVE);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("INDIRECT_BINDABLE_NV", vk::DescriptorSetLayoutCreateFlagBits::eIndirectBindableNV);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("HOST_ONLY_POOL_EXT", vk::DescriptorSetLayoutCreateFlagBits::eHostOnlyPoolEXT);
    e_vk_DescriptorSetLayoutCreateFlagBits.value("PER_STAGE_NV", vk::DescriptorSetLayoutCreateFlagBits::ePerStageNV);

    py::enum_<vk::DescriptorType> e_vk_DescriptorType(m_vk, "DescriptorType");
    e_vk_DescriptorType.value("SAMPLER", vk::DescriptorType::eSampler);
    e_vk_DescriptorType.value("COMBINED_IMAGE_SAMPLER", vk::DescriptorType::eCombinedImageSampler);
    e_vk_DescriptorType.value("SAMPLED_IMAGE", vk::DescriptorType::eSampledImage);
    e_vk_DescriptorType.value("STORAGE_IMAGE", vk::DescriptorType::eStorageImage);
    e_vk_DescriptorType.value("UNIFORM_TEXEL_BUFFER", vk::DescriptorType::eUniformTexelBuffer);
    e_vk_DescriptorType.value("STORAGE_TEXEL_BUFFER", vk::DescriptorType::eStorageTexelBuffer);
    e_vk_DescriptorType.value("UNIFORM_BUFFER", vk::DescriptorType::eUniformBuffer);
    e_vk_DescriptorType.value("STORAGE_BUFFER", vk::DescriptorType::eStorageBuffer);
    e_vk_DescriptorType.value("UNIFORM_BUFFER_DYNAMIC", vk::DescriptorType::eUniformBufferDynamic);
    e_vk_DescriptorType.value("STORAGE_BUFFER_DYNAMIC", vk::DescriptorType::eStorageBufferDynamic);
    e_vk_DescriptorType.value("INPUT_ATTACHMENT", vk::DescriptorType::eInputAttachment);
    e_vk_DescriptorType.value("INLINE_UNIFORM_BLOCK", vk::DescriptorType::eInlineUniformBlock);
    e_vk_DescriptorType.value("INLINE_UNIFORM_BLOCK_EXT", vk::DescriptorType::eInlineUniformBlockEXT);
    e_vk_DescriptorType.value("ACCELERATION_STRUCTURE_KHR", vk::DescriptorType::eAccelerationStructureKHR);
    e_vk_DescriptorType.value("ACCELERATION_STRUCTURE_NV", vk::DescriptorType::eAccelerationStructureNV);
    e_vk_DescriptorType.value("MUTABLE_VALVE", vk::DescriptorType::eMutableVALVE);
    e_vk_DescriptorType.value("SAMPLE_WEIGHT_IMAGE_QCOM", vk::DescriptorType::eSampleWeightImageQCOM);
    e_vk_DescriptorType.value("BLOCK_MATCH_IMAGE_QCOM", vk::DescriptorType::eBlockMatchImageQCOM);
    e_vk_DescriptorType.value("MUTABLE_EXT", vk::DescriptorType::eMutableEXT);

    py::enum_<vk::DeviceCreateFlagBits> e_vk_DeviceCreateFlagBits(m_vk, "DeviceCreateFlagBits");

    py::enum_<vk::DeviceQueueCreateFlagBits> e_vk_DeviceQueueCreateFlagBits(m_vk, "DeviceQueueCreateFlagBits");
    e_vk_DeviceQueueCreateFlagBits.value("PROTECTED", vk::DeviceQueueCreateFlagBits::eProtected);

    py::enum_<vk::DynamicState> e_vk_DynamicState(m_vk, "DynamicState");
    e_vk_DynamicState.value("VIEWPORT", vk::DynamicState::eViewport);
    e_vk_DynamicState.value("SCISSOR", vk::DynamicState::eScissor);
    e_vk_DynamicState.value("LINE_WIDTH", vk::DynamicState::eLineWidth);
    e_vk_DynamicState.value("DEPTH_BIAS", vk::DynamicState::eDepthBias);
    e_vk_DynamicState.value("BLEND_CONSTANTS", vk::DynamicState::eBlendConstants);
    e_vk_DynamicState.value("DEPTH_BOUNDS", vk::DynamicState::eDepthBounds);
    e_vk_DynamicState.value("STENCIL_COMPARE_MASK", vk::DynamicState::eStencilCompareMask);
    e_vk_DynamicState.value("STENCIL_WRITE_MASK", vk::DynamicState::eStencilWriteMask);
    e_vk_DynamicState.value("STENCIL_REFERENCE", vk::DynamicState::eStencilReference);
    e_vk_DynamicState.value("CULL_MODE", vk::DynamicState::eCullMode);
    e_vk_DynamicState.value("FRONT_FACE", vk::DynamicState::eFrontFace);
    e_vk_DynamicState.value("PRIMITIVE_TOPOLOGY", vk::DynamicState::ePrimitiveTopology);
    e_vk_DynamicState.value("VIEWPORT_WITH_COUNT", vk::DynamicState::eViewportWithCount);
    e_vk_DynamicState.value("SCISSOR_WITH_COUNT", vk::DynamicState::eScissorWithCount);
    e_vk_DynamicState.value("VERTEX_INPUT_BINDING_STRIDE", vk::DynamicState::eVertexInputBindingStride);
    e_vk_DynamicState.value("DEPTH_TEST_ENABLE", vk::DynamicState::eDepthTestEnable);
    e_vk_DynamicState.value("DEPTH_WRITE_ENABLE", vk::DynamicState::eDepthWriteEnable);
    e_vk_DynamicState.value("DEPTH_COMPARE_OP", vk::DynamicState::eDepthCompareOp);
    e_vk_DynamicState.value("DEPTH_BOUNDS_TEST_ENABLE", vk::DynamicState::eDepthBoundsTestEnable);
    e_vk_DynamicState.value("STENCIL_TEST_ENABLE", vk::DynamicState::eStencilTestEnable);
    e_vk_DynamicState.value("STENCIL_OP", vk::DynamicState::eStencilOp);
    e_vk_DynamicState.value("RASTERIZER_DISCARD_ENABLE", vk::DynamicState::eRasterizerDiscardEnable);
    e_vk_DynamicState.value("DEPTH_BIAS_ENABLE", vk::DynamicState::eDepthBiasEnable);
    e_vk_DynamicState.value("PRIMITIVE_RESTART_ENABLE", vk::DynamicState::ePrimitiveRestartEnable);
    e_vk_DynamicState.value("VIEWPORT_W_SCALING_NV", vk::DynamicState::eViewportWScalingNV);
    e_vk_DynamicState.value("DISCARD_RECTANGLE_EXT", vk::DynamicState::eDiscardRectangleEXT);
    e_vk_DynamicState.value("DISCARD_RECTANGLE_ENABLE_EXT", vk::DynamicState::eDiscardRectangleEnableEXT);
    e_vk_DynamicState.value("DISCARD_RECTANGLE_MODE_EXT", vk::DynamicState::eDiscardRectangleModeEXT);
    e_vk_DynamicState.value("SAMPLE_LOCATIONS_EXT", vk::DynamicState::eSampleLocationsEXT);
    e_vk_DynamicState.value("RAY_TRACING_PIPELINE_STACK_SIZE_KHR", vk::DynamicState::eRayTracingPipelineStackSizeKHR);
    e_vk_DynamicState.value("VIEWPORT_SHADING_RATE_PALETTE_NV", vk::DynamicState::eViewportShadingRatePaletteNV);
    e_vk_DynamicState.value("VIEWPORT_COARSE_SAMPLE_ORDER_NV", vk::DynamicState::eViewportCoarseSampleOrderNV);
    e_vk_DynamicState.value("EXCLUSIVE_SCISSOR_ENABLE_NV", vk::DynamicState::eExclusiveScissorEnableNV);
    e_vk_DynamicState.value("EXCLUSIVE_SCISSOR_NV", vk::DynamicState::eExclusiveScissorNV);
    e_vk_DynamicState.value("FRAGMENT_SHADING_RATE_KHR", vk::DynamicState::eFragmentShadingRateKHR);
    e_vk_DynamicState.value("LINE_STIPPLE_EXT", vk::DynamicState::eLineStippleEXT);
    e_vk_DynamicState.value("CULL_MODE_EXT", vk::DynamicState::eCullModeEXT);
    e_vk_DynamicState.value("FRONT_FACE_EXT", vk::DynamicState::eFrontFaceEXT);
    e_vk_DynamicState.value("PRIMITIVE_TOPOLOGY_EXT", vk::DynamicState::ePrimitiveTopologyEXT);
    e_vk_DynamicState.value("VIEWPORT_WITH_COUNT_EXT", vk::DynamicState::eViewportWithCountEXT);
    e_vk_DynamicState.value("SCISSOR_WITH_COUNT_EXT", vk::DynamicState::eScissorWithCountEXT);
    e_vk_DynamicState.value("VERTEX_INPUT_BINDING_STRIDE_EXT", vk::DynamicState::eVertexInputBindingStrideEXT);
    e_vk_DynamicState.value("DEPTH_TEST_ENABLE_EXT", vk::DynamicState::eDepthTestEnableEXT);
    e_vk_DynamicState.value("DEPTH_WRITE_ENABLE_EXT", vk::DynamicState::eDepthWriteEnableEXT);
    e_vk_DynamicState.value("DEPTH_COMPARE_OP_EXT", vk::DynamicState::eDepthCompareOpEXT);
    e_vk_DynamicState.value("DEPTH_BOUNDS_TEST_ENABLE_EXT", vk::DynamicState::eDepthBoundsTestEnableEXT);
    e_vk_DynamicState.value("STENCIL_TEST_ENABLE_EXT", vk::DynamicState::eStencilTestEnableEXT);
    e_vk_DynamicState.value("STENCIL_OP_EXT", vk::DynamicState::eStencilOpEXT);
    e_vk_DynamicState.value("VERTEX_INPUT_EXT", vk::DynamicState::eVertexInputEXT);
    e_vk_DynamicState.value("PATCH_CONTROL_POINTS_EXT", vk::DynamicState::ePatchControlPointsEXT);
    e_vk_DynamicState.value("RASTERIZER_DISCARD_ENABLE_EXT", vk::DynamicState::eRasterizerDiscardEnableEXT);
    e_vk_DynamicState.value("DEPTH_BIAS_ENABLE_EXT", vk::DynamicState::eDepthBiasEnableEXT);
    e_vk_DynamicState.value("LOGIC_OP_EXT", vk::DynamicState::eLogicOpEXT);
    e_vk_DynamicState.value("PRIMITIVE_RESTART_ENABLE_EXT", vk::DynamicState::ePrimitiveRestartEnableEXT);
    e_vk_DynamicState.value("COLOR_WRITE_ENABLE_EXT", vk::DynamicState::eColorWriteEnableEXT);
    e_vk_DynamicState.value("TESSELLATION_DOMAIN_ORIGIN_EXT", vk::DynamicState::eTessellationDomainOriginEXT);
    e_vk_DynamicState.value("DEPTH_CLAMP_ENABLE_EXT", vk::DynamicState::eDepthClampEnableEXT);
    e_vk_DynamicState.value("POLYGON_MODE_EXT", vk::DynamicState::ePolygonModeEXT);
    e_vk_DynamicState.value("RASTERIZATION_SAMPLES_EXT", vk::DynamicState::eRasterizationSamplesEXT);
    e_vk_DynamicState.value("SAMPLE_MASK_EXT", vk::DynamicState::eSampleMaskEXT);
    e_vk_DynamicState.value("ALPHA_TO_COVERAGE_ENABLE_EXT", vk::DynamicState::eAlphaToCoverageEnableEXT);
    e_vk_DynamicState.value("ALPHA_TO_ONE_ENABLE_EXT", vk::DynamicState::eAlphaToOneEnableEXT);
    e_vk_DynamicState.value("LOGIC_OP_ENABLE_EXT", vk::DynamicState::eLogicOpEnableEXT);
    e_vk_DynamicState.value("COLOR_BLEND_ENABLE_EXT", vk::DynamicState::eColorBlendEnableEXT);
    e_vk_DynamicState.value("COLOR_BLEND_EQUATION_EXT", vk::DynamicState::eColorBlendEquationEXT);
    e_vk_DynamicState.value("COLOR_WRITE_MASK_EXT", vk::DynamicState::eColorWriteMaskEXT);
    e_vk_DynamicState.value("RASTERIZATION_STREAM_EXT", vk::DynamicState::eRasterizationStreamEXT);
    e_vk_DynamicState.value("CONSERVATIVE_RASTERIZATION_MODE_EXT", vk::DynamicState::eConservativeRasterizationModeEXT);
    e_vk_DynamicState.value("EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT", vk::DynamicState::eExtraPrimitiveOverestimationSizeEXT);
    e_vk_DynamicState.value("DEPTH_CLIP_ENABLE_EXT", vk::DynamicState::eDepthClipEnableEXT);
    e_vk_DynamicState.value("SAMPLE_LOCATIONS_ENABLE_EXT", vk::DynamicState::eSampleLocationsEnableEXT);
    e_vk_DynamicState.value("COLOR_BLEND_ADVANCED_EXT", vk::DynamicState::eColorBlendAdvancedEXT);
    e_vk_DynamicState.value("PROVOKING_VERTEX_MODE_EXT", vk::DynamicState::eProvokingVertexModeEXT);
    e_vk_DynamicState.value("LINE_RASTERIZATION_MODE_EXT", vk::DynamicState::eLineRasterizationModeEXT);
    e_vk_DynamicState.value("LINE_STIPPLE_ENABLE_EXT", vk::DynamicState::eLineStippleEnableEXT);
    e_vk_DynamicState.value("DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT", vk::DynamicState::eDepthClipNegativeOneToOneEXT);
    e_vk_DynamicState.value("VIEWPORT_W_SCALING_ENABLE_NV", vk::DynamicState::eViewportWScalingEnableNV);
    e_vk_DynamicState.value("VIEWPORT_SWIZZLE_NV", vk::DynamicState::eViewportSwizzleNV);
    e_vk_DynamicState.value("COVERAGE_TO_COLOR_ENABLE_NV", vk::DynamicState::eCoverageToColorEnableNV);
    e_vk_DynamicState.value("COVERAGE_TO_COLOR_LOCATION_NV", vk::DynamicState::eCoverageToColorLocationNV);
    e_vk_DynamicState.value("COVERAGE_MODULATION_MODE_NV", vk::DynamicState::eCoverageModulationModeNV);
    e_vk_DynamicState.value("COVERAGE_MODULATION_TABLE_ENABLE_NV", vk::DynamicState::eCoverageModulationTableEnableNV);
    e_vk_DynamicState.value("COVERAGE_MODULATION_TABLE_NV", vk::DynamicState::eCoverageModulationTableNV);
    e_vk_DynamicState.value("SHADING_RATE_IMAGE_ENABLE_NV", vk::DynamicState::eShadingRateImageEnableNV);
    e_vk_DynamicState.value("REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV", vk::DynamicState::eRepresentativeFragmentTestEnableNV);
    e_vk_DynamicState.value("COVERAGE_REDUCTION_MODE_NV", vk::DynamicState::eCoverageReductionModeNV);
    e_vk_DynamicState.value("ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT", vk::DynamicState::eAttachmentFeedbackLoopEnableEXT);

    py::enum_<vk::EventCreateFlagBits> e_vk_EventCreateFlagBits(m_vk, "EventCreateFlagBits");
    e_vk_EventCreateFlagBits.value("DEVICE_ONLY", vk::EventCreateFlagBits::eDeviceOnly);
    e_vk_EventCreateFlagBits.value("DEVICE_ONLY_KHR", vk::EventCreateFlagBits::eDeviceOnlyKHR);

    py::enum_<vk::FenceCreateFlagBits> e_vk_FenceCreateFlagBits(m_vk, "FenceCreateFlagBits");
    e_vk_FenceCreateFlagBits.value("SIGNALED", vk::FenceCreateFlagBits::eSignaled);

    py::enum_<vk::Filter> e_vk_Filter(m_vk, "Filter");
    e_vk_Filter.value("NEAREST", vk::Filter::eNearest);
    e_vk_Filter.value("LINEAR", vk::Filter::eLinear);
    e_vk_Filter.value("CUBIC_IMG", vk::Filter::eCubicIMG);
    e_vk_Filter.value("CUBIC_EXT", vk::Filter::eCubicEXT);

    py::enum_<vk::Format> e_vk_Format(m_vk, "Format");
    e_vk_Format.value("UNDEFINED", vk::Format::eUndefined);
    e_vk_Format.value("R4G4_UNORM_PACK_8", vk::Format::eR4G4UnormPack8);
    e_vk_Format.value("R4G4B4A4_UNORM_PACK_16", vk::Format::eR4G4B4A4UnormPack16);
    e_vk_Format.value("B4G4R4A4_UNORM_PACK_16", vk::Format::eB4G4R4A4UnormPack16);
    e_vk_Format.value("R5G6B5_UNORM_PACK_16", vk::Format::eR5G6B5UnormPack16);
    e_vk_Format.value("B5G6R5_UNORM_PACK_16", vk::Format::eB5G6R5UnormPack16);
    e_vk_Format.value("R5G5B5A1_UNORM_PACK_16", vk::Format::eR5G5B5A1UnormPack16);
    e_vk_Format.value("B5G5R5A1_UNORM_PACK_16", vk::Format::eB5G5R5A1UnormPack16);
    e_vk_Format.value("A1R5G5B5_UNORM_PACK_16", vk::Format::eA1R5G5B5UnormPack16);
    e_vk_Format.value("R8_UNORM", vk::Format::eR8Unorm);
    e_vk_Format.value("R8_SNORM", vk::Format::eR8Snorm);
    e_vk_Format.value("R8_USCALED", vk::Format::eR8Uscaled);
    e_vk_Format.value("R8_SSCALED", vk::Format::eR8Sscaled);
    e_vk_Format.value("R8_UINT", vk::Format::eR8Uint);
    e_vk_Format.value("R8_SINT", vk::Format::eR8Sint);
    e_vk_Format.value("R8_SRGB", vk::Format::eR8Srgb);
    e_vk_Format.value("R8G8_UNORM", vk::Format::eR8G8Unorm);
    e_vk_Format.value("R8G8_SNORM", vk::Format::eR8G8Snorm);
    e_vk_Format.value("R8G8_USCALED", vk::Format::eR8G8Uscaled);
    e_vk_Format.value("R8G8_SSCALED", vk::Format::eR8G8Sscaled);
    e_vk_Format.value("R8G8_UINT", vk::Format::eR8G8Uint);
    e_vk_Format.value("R8G8_SINT", vk::Format::eR8G8Sint);
    e_vk_Format.value("R8G8_SRGB", vk::Format::eR8G8Srgb);
    e_vk_Format.value("R8G8B8_UNORM", vk::Format::eR8G8B8Unorm);
    e_vk_Format.value("R8G8B8_SNORM", vk::Format::eR8G8B8Snorm);
    e_vk_Format.value("R8G8B8_USCALED", vk::Format::eR8G8B8Uscaled);
    e_vk_Format.value("R8G8B8_SSCALED", vk::Format::eR8G8B8Sscaled);
    e_vk_Format.value("R8G8B8_UINT", vk::Format::eR8G8B8Uint);
    e_vk_Format.value("R8G8B8_SINT", vk::Format::eR8G8B8Sint);
    e_vk_Format.value("R8G8B8_SRGB", vk::Format::eR8G8B8Srgb);
    e_vk_Format.value("B8G8R8_UNORM", vk::Format::eB8G8R8Unorm);
    e_vk_Format.value("B8G8R8_SNORM", vk::Format::eB8G8R8Snorm);
    e_vk_Format.value("B8G8R8_USCALED", vk::Format::eB8G8R8Uscaled);
    e_vk_Format.value("B8G8R8_SSCALED", vk::Format::eB8G8R8Sscaled);
    e_vk_Format.value("B8G8R8_UINT", vk::Format::eB8G8R8Uint);
    e_vk_Format.value("B8G8R8_SINT", vk::Format::eB8G8R8Sint);
    e_vk_Format.value("B8G8R8_SRGB", vk::Format::eB8G8R8Srgb);
    e_vk_Format.value("R8G8B8A8_UNORM", vk::Format::eR8G8B8A8Unorm);
    e_vk_Format.value("R8G8B8A8_SNORM", vk::Format::eR8G8B8A8Snorm);
    e_vk_Format.value("R8G8B8A8_USCALED", vk::Format::eR8G8B8A8Uscaled);
    e_vk_Format.value("R8G8B8A8_SSCALED", vk::Format::eR8G8B8A8Sscaled);
    e_vk_Format.value("R8G8B8A8_UINT", vk::Format::eR8G8B8A8Uint);
    e_vk_Format.value("R8G8B8A8_SINT", vk::Format::eR8G8B8A8Sint);
    e_vk_Format.value("R8G8B8A8_SRGB", vk::Format::eR8G8B8A8Srgb);
    e_vk_Format.value("B8G8R8A8_UNORM", vk::Format::eB8G8R8A8Unorm);
    e_vk_Format.value("B8G8R8A8_SNORM", vk::Format::eB8G8R8A8Snorm);
    e_vk_Format.value("B8G8R8A8_USCALED", vk::Format::eB8G8R8A8Uscaled);
    e_vk_Format.value("B8G8R8A8_SSCALED", vk::Format::eB8G8R8A8Sscaled);
    e_vk_Format.value("B8G8R8A8_UINT", vk::Format::eB8G8R8A8Uint);
    e_vk_Format.value("B8G8R8A8_SINT", vk::Format::eB8G8R8A8Sint);
    e_vk_Format.value("B8G8R8A8_SRGB", vk::Format::eB8G8R8A8Srgb);
    e_vk_Format.value("A8B8G8R8_UNORM_PACK_32", vk::Format::eA8B8G8R8UnormPack32);
    e_vk_Format.value("A8B8G8R8_SNORM_PACK_32", vk::Format::eA8B8G8R8SnormPack32);
    e_vk_Format.value("A8B8G8R8_USCALED_PACK_32", vk::Format::eA8B8G8R8UscaledPack32);
    e_vk_Format.value("A8B8G8R8_SSCALED_PACK_32", vk::Format::eA8B8G8R8SscaledPack32);
    e_vk_Format.value("A8B8G8R8_UINT_PACK_32", vk::Format::eA8B8G8R8UintPack32);
    e_vk_Format.value("A8B8G8R8_SINT_PACK_32", vk::Format::eA8B8G8R8SintPack32);
    e_vk_Format.value("A8B8G8R8_SRGB_PACK_32", vk::Format::eA8B8G8R8SrgbPack32);
    e_vk_Format.value("A2R10G10B10_UNORM_PACK_32", vk::Format::eA2R10G10B10UnormPack32);
    e_vk_Format.value("A2R10G10B10_SNORM_PACK_32", vk::Format::eA2R10G10B10SnormPack32);
    e_vk_Format.value("A2R10G10B10_USCALED_PACK_32", vk::Format::eA2R10G10B10UscaledPack32);
    e_vk_Format.value("A2R10G10B10_SSCALED_PACK_32", vk::Format::eA2R10G10B10SscaledPack32);
    e_vk_Format.value("A2R10G10B10_UINT_PACK_32", vk::Format::eA2R10G10B10UintPack32);
    e_vk_Format.value("A2R10G10B10_SINT_PACK_32", vk::Format::eA2R10G10B10SintPack32);
    e_vk_Format.value("A2B10G10R10_UNORM_PACK_32", vk::Format::eA2B10G10R10UnormPack32);
    e_vk_Format.value("A2B10G10R10_SNORM_PACK_32", vk::Format::eA2B10G10R10SnormPack32);
    e_vk_Format.value("A2B10G10R10_USCALED_PACK_32", vk::Format::eA2B10G10R10UscaledPack32);
    e_vk_Format.value("A2B10G10R10_SSCALED_PACK_32", vk::Format::eA2B10G10R10SscaledPack32);
    e_vk_Format.value("A2B10G10R10_UINT_PACK_32", vk::Format::eA2B10G10R10UintPack32);
    e_vk_Format.value("A2B10G10R10_SINT_PACK_32", vk::Format::eA2B10G10R10SintPack32);
    e_vk_Format.value("R16_UNORM", vk::Format::eR16Unorm);
    e_vk_Format.value("R16_SNORM", vk::Format::eR16Snorm);
    e_vk_Format.value("R16_USCALED", vk::Format::eR16Uscaled);
    e_vk_Format.value("R16_SSCALED", vk::Format::eR16Sscaled);
    e_vk_Format.value("R16_UINT", vk::Format::eR16Uint);
    e_vk_Format.value("R16_SINT", vk::Format::eR16Sint);
    e_vk_Format.value("R16_SFLOAT", vk::Format::eR16Sfloat);
    e_vk_Format.value("R16G16_UNORM", vk::Format::eR16G16Unorm);
    e_vk_Format.value("R16G16_SNORM", vk::Format::eR16G16Snorm);
    e_vk_Format.value("R16G16_USCALED", vk::Format::eR16G16Uscaled);
    e_vk_Format.value("R16G16_SSCALED", vk::Format::eR16G16Sscaled);
    e_vk_Format.value("R16G16_UINT", vk::Format::eR16G16Uint);
    e_vk_Format.value("R16G16_SINT", vk::Format::eR16G16Sint);
    e_vk_Format.value("R16G16_SFLOAT", vk::Format::eR16G16Sfloat);
    e_vk_Format.value("R16G16B16_UNORM", vk::Format::eR16G16B16Unorm);
    e_vk_Format.value("R16G16B16_SNORM", vk::Format::eR16G16B16Snorm);
    e_vk_Format.value("R16G16B16_USCALED", vk::Format::eR16G16B16Uscaled);
    e_vk_Format.value("R16G16B16_SSCALED", vk::Format::eR16G16B16Sscaled);
    e_vk_Format.value("R16G16B16_UINT", vk::Format::eR16G16B16Uint);
    e_vk_Format.value("R16G16B16_SINT", vk::Format::eR16G16B16Sint);
    e_vk_Format.value("R16G16B16_SFLOAT", vk::Format::eR16G16B16Sfloat);
    e_vk_Format.value("R16G16B16A16_UNORM", vk::Format::eR16G16B16A16Unorm);
    e_vk_Format.value("R16G16B16A16_SNORM", vk::Format::eR16G16B16A16Snorm);
    e_vk_Format.value("R16G16B16A16_USCALED", vk::Format::eR16G16B16A16Uscaled);
    e_vk_Format.value("R16G16B16A16_SSCALED", vk::Format::eR16G16B16A16Sscaled);
    e_vk_Format.value("R16G16B16A16_UINT", vk::Format::eR16G16B16A16Uint);
    e_vk_Format.value("R16G16B16A16_SINT", vk::Format::eR16G16B16A16Sint);
    e_vk_Format.value("R16G16B16A16_SFLOAT", vk::Format::eR16G16B16A16Sfloat);
    e_vk_Format.value("R32_UINT", vk::Format::eR32Uint);
    e_vk_Format.value("R32_SINT", vk::Format::eR32Sint);
    e_vk_Format.value("R32_SFLOAT", vk::Format::eR32Sfloat);
    e_vk_Format.value("R32G32_UINT", vk::Format::eR32G32Uint);
    e_vk_Format.value("R32G32_SINT", vk::Format::eR32G32Sint);
    e_vk_Format.value("R32G32_SFLOAT", vk::Format::eR32G32Sfloat);
    e_vk_Format.value("R32G32B32_UINT", vk::Format::eR32G32B32Uint);
    e_vk_Format.value("R32G32B32_SINT", vk::Format::eR32G32B32Sint);
    e_vk_Format.value("R32G32B32_SFLOAT", vk::Format::eR32G32B32Sfloat);
    e_vk_Format.value("R32G32B32A32_UINT", vk::Format::eR32G32B32A32Uint);
    e_vk_Format.value("R32G32B32A32_SINT", vk::Format::eR32G32B32A32Sint);
    e_vk_Format.value("R32G32B32A32_SFLOAT", vk::Format::eR32G32B32A32Sfloat);
    e_vk_Format.value("R64_UINT", vk::Format::eR64Uint);
    e_vk_Format.value("R64_SINT", vk::Format::eR64Sint);
    e_vk_Format.value("R64_SFLOAT", vk::Format::eR64Sfloat);
    e_vk_Format.value("R64G64_UINT", vk::Format::eR64G64Uint);
    e_vk_Format.value("R64G64_SINT", vk::Format::eR64G64Sint);
    e_vk_Format.value("R64G64_SFLOAT", vk::Format::eR64G64Sfloat);
    e_vk_Format.value("R64G64B64_UINT", vk::Format::eR64G64B64Uint);
    e_vk_Format.value("R64G64B64_SINT", vk::Format::eR64G64B64Sint);
    e_vk_Format.value("R64G64B64_SFLOAT", vk::Format::eR64G64B64Sfloat);
    e_vk_Format.value("R64G64B64A64_UINT", vk::Format::eR64G64B64A64Uint);
    e_vk_Format.value("R64G64B64A64_SINT", vk::Format::eR64G64B64A64Sint);
    e_vk_Format.value("R64G64B64A64_SFLOAT", vk::Format::eR64G64B64A64Sfloat);
    e_vk_Format.value("B10G11R11_UFLOAT_PACK_32", vk::Format::eB10G11R11UfloatPack32);
    e_vk_Format.value("E5B9G9R9_UFLOAT_PACK_32", vk::Format::eE5B9G9R9UfloatPack32);
    e_vk_Format.value("D16_UNORM", vk::Format::eD16Unorm);
    e_vk_Format.value("X8D24_UNORM_PACK_32", vk::Format::eX8D24UnormPack32);
    e_vk_Format.value("D32_SFLOAT", vk::Format::eD32Sfloat);
    e_vk_Format.value("S8_UINT", vk::Format::eS8Uint);
    e_vk_Format.value("D16_UNORM_S8_UINT", vk::Format::eD16UnormS8Uint);
    e_vk_Format.value("D24_UNORM_S8_UINT", vk::Format::eD24UnormS8Uint);
    e_vk_Format.value("D32_SFLOAT_S8_UINT", vk::Format::eD32SfloatS8Uint);
    e_vk_Format.value("BC_1_RGB_UNORM_BLOCK", vk::Format::eBc1RgbUnormBlock);
    e_vk_Format.value("BC_1_RGB_SRGB_BLOCK", vk::Format::eBc1RgbSrgbBlock);
    e_vk_Format.value("BC_1_RGBA_UNORM_BLOCK", vk::Format::eBc1RgbaUnormBlock);
    e_vk_Format.value("BC_1_RGBA_SRGB_BLOCK", vk::Format::eBc1RgbaSrgbBlock);
    e_vk_Format.value("BC_2_UNORM_BLOCK", vk::Format::eBc2UnormBlock);
    e_vk_Format.value("BC_2_SRGB_BLOCK", vk::Format::eBc2SrgbBlock);
    e_vk_Format.value("BC_3_UNORM_BLOCK", vk::Format::eBc3UnormBlock);
    e_vk_Format.value("BC_3_SRGB_BLOCK", vk::Format::eBc3SrgbBlock);
    e_vk_Format.value("BC_4_UNORM_BLOCK", vk::Format::eBc4UnormBlock);
    e_vk_Format.value("BC_4_SNORM_BLOCK", vk::Format::eBc4SnormBlock);
    e_vk_Format.value("BC_5_UNORM_BLOCK", vk::Format::eBc5UnormBlock);
    e_vk_Format.value("BC_5_SNORM_BLOCK", vk::Format::eBc5SnormBlock);
    e_vk_Format.value("BC_6H_UFLOAT_BLOCK", vk::Format::eBc6HUfloatBlock);
    e_vk_Format.value("BC_6H_SFLOAT_BLOCK", vk::Format::eBc6HSfloatBlock);
    e_vk_Format.value("BC_7_UNORM_BLOCK", vk::Format::eBc7UnormBlock);
    e_vk_Format.value("BC_7_SRGB_BLOCK", vk::Format::eBc7SrgbBlock);
    e_vk_Format.value("ETC_2R8G8B8_UNORM_BLOCK", vk::Format::eEtc2R8G8B8UnormBlock);
    e_vk_Format.value("ETC_2R8G8B8_SRGB_BLOCK", vk::Format::eEtc2R8G8B8SrgbBlock);
    e_vk_Format.value("ETC_2R8G8B8A1_UNORM_BLOCK", vk::Format::eEtc2R8G8B8A1UnormBlock);
    e_vk_Format.value("ETC_2R8G8B8A1_SRGB_BLOCK", vk::Format::eEtc2R8G8B8A1SrgbBlock);
    e_vk_Format.value("ETC_2R8G8B8A8_UNORM_BLOCK", vk::Format::eEtc2R8G8B8A8UnormBlock);
    e_vk_Format.value("ETC_2R8G8B8A8_SRGB_BLOCK", vk::Format::eEtc2R8G8B8A8SrgbBlock);
    e_vk_Format.value("EAC_R11_UNORM_BLOCK", vk::Format::eEacR11UnormBlock);
    e_vk_Format.value("EAC_R11_SNORM_BLOCK", vk::Format::eEacR11SnormBlock);
    e_vk_Format.value("EAC_R11G11_UNORM_BLOCK", vk::Format::eEacR11G11UnormBlock);
    e_vk_Format.value("EAC_R11G11_SNORM_BLOCK", vk::Format::eEacR11G11SnormBlock);
    e_vk_Format.value("ASTC_4x4_UNORM_BLOCK", vk::Format::eAstc4x4UnormBlock);
    e_vk_Format.value("ASTC_4x4_SRGB_BLOCK", vk::Format::eAstc4x4SrgbBlock);
    e_vk_Format.value("ASTC_5x4_UNORM_BLOCK", vk::Format::eAstc5x4UnormBlock);
    e_vk_Format.value("ASTC_5x4_SRGB_BLOCK", vk::Format::eAstc5x4SrgbBlock);
    e_vk_Format.value("ASTC_5x5_UNORM_BLOCK", vk::Format::eAstc5x5UnormBlock);
    e_vk_Format.value("ASTC_5x5_SRGB_BLOCK", vk::Format::eAstc5x5SrgbBlock);
    e_vk_Format.value("ASTC_6x5_UNORM_BLOCK", vk::Format::eAstc6x5UnormBlock);
    e_vk_Format.value("ASTC_6x5_SRGB_BLOCK", vk::Format::eAstc6x5SrgbBlock);
    e_vk_Format.value("ASTC_6x6_UNORM_BLOCK", vk::Format::eAstc6x6UnormBlock);
    e_vk_Format.value("ASTC_6x6_SRGB_BLOCK", vk::Format::eAstc6x6SrgbBlock);
    e_vk_Format.value("ASTC_8x5_UNORM_BLOCK", vk::Format::eAstc8x5UnormBlock);
    e_vk_Format.value("ASTC_8x5_SRGB_BLOCK", vk::Format::eAstc8x5SrgbBlock);
    e_vk_Format.value("ASTC_8x6_UNORM_BLOCK", vk::Format::eAstc8x6UnormBlock);
    e_vk_Format.value("ASTC_8x6_SRGB_BLOCK", vk::Format::eAstc8x6SrgbBlock);
    e_vk_Format.value("ASTC_8x8_UNORM_BLOCK", vk::Format::eAstc8x8UnormBlock);
    e_vk_Format.value("ASTC_8x8_SRGB_BLOCK", vk::Format::eAstc8x8SrgbBlock);
    e_vk_Format.value("ASTC_10x5_UNORM_BLOCK", vk::Format::eAstc10x5UnormBlock);
    e_vk_Format.value("ASTC_10x5_SRGB_BLOCK", vk::Format::eAstc10x5SrgbBlock);
    e_vk_Format.value("ASTC_10x6_UNORM_BLOCK", vk::Format::eAstc10x6UnormBlock);
    e_vk_Format.value("ASTC_10x6_SRGB_BLOCK", vk::Format::eAstc10x6SrgbBlock);
    e_vk_Format.value("ASTC_10x8_UNORM_BLOCK", vk::Format::eAstc10x8UnormBlock);
    e_vk_Format.value("ASTC_10x8_SRGB_BLOCK", vk::Format::eAstc10x8SrgbBlock);
    e_vk_Format.value("ASTC_10x10_UNORM_BLOCK", vk::Format::eAstc10x10UnormBlock);
    e_vk_Format.value("ASTC_10x10_SRGB_BLOCK", vk::Format::eAstc10x10SrgbBlock);
    e_vk_Format.value("ASTC_12x10_UNORM_BLOCK", vk::Format::eAstc12x10UnormBlock);
    e_vk_Format.value("ASTC_12x10_SRGB_BLOCK", vk::Format::eAstc12x10SrgbBlock);
    e_vk_Format.value("ASTC_12x12_UNORM_BLOCK", vk::Format::eAstc12x12UnormBlock);
    e_vk_Format.value("ASTC_12x12_SRGB_BLOCK", vk::Format::eAstc12x12SrgbBlock);
    e_vk_Format.value("G8B8G8R8422_UNORM", vk::Format::eG8B8G8R8422Unorm);
    e_vk_Format.value("B8G8R8G8422_UNORM", vk::Format::eB8G8R8G8422Unorm);
    e_vk_Format.value("G8B8R83_PLANE_420_UNORM", vk::Format::eG8B8R83Plane420Unorm);
    e_vk_Format.value("G8B8R82_PLANE_420_UNORM", vk::Format::eG8B8R82Plane420Unorm);
    e_vk_Format.value("G8B8R83_PLANE_422_UNORM", vk::Format::eG8B8R83Plane422Unorm);
    e_vk_Format.value("G8B8R82_PLANE_422_UNORM", vk::Format::eG8B8R82Plane422Unorm);
    e_vk_Format.value("G8B8R83_PLANE_444_UNORM", vk::Format::eG8B8R83Plane444Unorm);
    e_vk_Format.value("R10X6_UNORM_PACK_16", vk::Format::eR10X6UnormPack16);
    e_vk_Format.value("R10X6G10X6_UNORM_2_PACK_16", vk::Format::eR10X6G10X6Unorm2Pack16);
    e_vk_Format.value("R10X6G10X6B10X6A10X6_UNORM_4_PACK_16", vk::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16);
    e_vk_Format.value("G10X6B10X6G10X6R10X6422_UNORM_4_PACK_16", vk::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16);
    e_vk_Format.value("B10X6G10X6R10X6G10X6422_UNORM_4_PACK_16", vk::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16);
    e_vk_Format.value("G10X6B10X6R10X63_PLANE_420_UNORM_3_PACK_16", vk::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16);
    e_vk_Format.value("G10X6B10X6R10X62_PLANE_420_UNORM_3_PACK_16", vk::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16);
    e_vk_Format.value("G10X6B10X6R10X63_PLANE_422_UNORM_3_PACK_16", vk::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16);
    e_vk_Format.value("G10X6B10X6R10X62_PLANE_422_UNORM_3_PACK_16", vk::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16);
    e_vk_Format.value("G10X6B10X6R10X63_PLANE_444_UNORM_3_PACK_16", vk::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16);
    e_vk_Format.value("R12X4_UNORM_PACK_16", vk::Format::eR12X4UnormPack16);
    e_vk_Format.value("R12X4G12X4_UNORM_2_PACK_16", vk::Format::eR12X4G12X4Unorm2Pack16);
    e_vk_Format.value("R12X4G12X4B12X4A12X4_UNORM_4_PACK_16", vk::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16);
    e_vk_Format.value("G12X4B12X4G12X4R12X4422_UNORM_4_PACK_16", vk::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16);
    e_vk_Format.value("B12X4G12X4R12X4G12X4422_UNORM_4_PACK_16", vk::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16);
    e_vk_Format.value("G12X4B12X4R12X43_PLANE_420_UNORM_3_PACK_16", vk::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16);
    e_vk_Format.value("G12X4B12X4R12X42_PLANE_420_UNORM_3_PACK_16", vk::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16);
    e_vk_Format.value("G12X4B12X4R12X43_PLANE_422_UNORM_3_PACK_16", vk::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16);
    e_vk_Format.value("G12X4B12X4R12X42_PLANE_422_UNORM_3_PACK_16", vk::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16);
    e_vk_Format.value("G12X4B12X4R12X43_PLANE_444_UNORM_3_PACK_16", vk::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16);
    e_vk_Format.value("G16B16G16R16422_UNORM", vk::Format::eG16B16G16R16422Unorm);
    e_vk_Format.value("B16G16R16G16422_UNORM", vk::Format::eB16G16R16G16422Unorm);
    e_vk_Format.value("G16B16R163_PLANE_420_UNORM", vk::Format::eG16B16R163Plane420Unorm);
    e_vk_Format.value("G16B16R162_PLANE_420_UNORM", vk::Format::eG16B16R162Plane420Unorm);
    e_vk_Format.value("G16B16R163_PLANE_422_UNORM", vk::Format::eG16B16R163Plane422Unorm);
    e_vk_Format.value("G16B16R162_PLANE_422_UNORM", vk::Format::eG16B16R162Plane422Unorm);
    e_vk_Format.value("G16B16R163_PLANE_444_UNORM", vk::Format::eG16B16R163Plane444Unorm);
    e_vk_Format.value("G8B8R82_PLANE_444_UNORM", vk::Format::eG8B8R82Plane444Unorm);
    e_vk_Format.value("G10X6B10X6R10X62_PLANE_444_UNORM_3_PACK_16", vk::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16);
    e_vk_Format.value("G12X4B12X4R12X42_PLANE_444_UNORM_3_PACK_16", vk::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16);
    e_vk_Format.value("G16B16R162_PLANE_444_UNORM", vk::Format::eG16B16R162Plane444Unorm);
    e_vk_Format.value("A4R4G4B4_UNORM_PACK_16", vk::Format::eA4R4G4B4UnormPack16);
    e_vk_Format.value("A4B4G4R4_UNORM_PACK_16", vk::Format::eA4B4G4R4UnormPack16);
    e_vk_Format.value("ASTC_4x4_SFLOAT_BLOCK", vk::Format::eAstc4x4SfloatBlock);
    e_vk_Format.value("ASTC_5x4_SFLOAT_BLOCK", vk::Format::eAstc5x4SfloatBlock);
    e_vk_Format.value("ASTC_5x5_SFLOAT_BLOCK", vk::Format::eAstc5x5SfloatBlock);
    e_vk_Format.value("ASTC_6x5_SFLOAT_BLOCK", vk::Format::eAstc6x5SfloatBlock);
    e_vk_Format.value("ASTC_6x6_SFLOAT_BLOCK", vk::Format::eAstc6x6SfloatBlock);
    e_vk_Format.value("ASTC_8x5_SFLOAT_BLOCK", vk::Format::eAstc8x5SfloatBlock);
    e_vk_Format.value("ASTC_8x6_SFLOAT_BLOCK", vk::Format::eAstc8x6SfloatBlock);
    e_vk_Format.value("ASTC_8x8_SFLOAT_BLOCK", vk::Format::eAstc8x8SfloatBlock);
    e_vk_Format.value("ASTC_10x5_SFLOAT_BLOCK", vk::Format::eAstc10x5SfloatBlock);
    e_vk_Format.value("ASTC_10x6_SFLOAT_BLOCK", vk::Format::eAstc10x6SfloatBlock);
    e_vk_Format.value("ASTC_10x8_SFLOAT_BLOCK", vk::Format::eAstc10x8SfloatBlock);
    e_vk_Format.value("ASTC_10x10_SFLOAT_BLOCK", vk::Format::eAstc10x10SfloatBlock);
    e_vk_Format.value("ASTC_12x10_SFLOAT_BLOCK", vk::Format::eAstc12x10SfloatBlock);
    e_vk_Format.value("ASTC_12x12_SFLOAT_BLOCK", vk::Format::eAstc12x12SfloatBlock);
    e_vk_Format.value("PVRTC_12_BPP_UNORM_BLOCK_IMG", vk::Format::ePvrtc12BppUnormBlockIMG);
    e_vk_Format.value("PVRTC_14_BPP_UNORM_BLOCK_IMG", vk::Format::ePvrtc14BppUnormBlockIMG);
    e_vk_Format.value("PVRTC_22_BPP_UNORM_BLOCK_IMG", vk::Format::ePvrtc22BppUnormBlockIMG);
    e_vk_Format.value("PVRTC_24_BPP_UNORM_BLOCK_IMG", vk::Format::ePvrtc24BppUnormBlockIMG);
    e_vk_Format.value("PVRTC_12_BPP_SRGB_BLOCK_IMG", vk::Format::ePvrtc12BppSrgbBlockIMG);
    e_vk_Format.value("PVRTC_14_BPP_SRGB_BLOCK_IMG", vk::Format::ePvrtc14BppSrgbBlockIMG);
    e_vk_Format.value("PVRTC_22_BPP_SRGB_BLOCK_IMG", vk::Format::ePvrtc22BppSrgbBlockIMG);
    e_vk_Format.value("PVRTC_24_BPP_SRGB_BLOCK_IMG", vk::Format::ePvrtc24BppSrgbBlockIMG);
    e_vk_Format.value("ASTC_4x4_SFLOAT_BLOCK_EXT", vk::Format::eAstc4x4SfloatBlockEXT);
    e_vk_Format.value("ASTC_5x4_SFLOAT_BLOCK_EXT", vk::Format::eAstc5x4SfloatBlockEXT);
    e_vk_Format.value("ASTC_5x5_SFLOAT_BLOCK_EXT", vk::Format::eAstc5x5SfloatBlockEXT);
    e_vk_Format.value("ASTC_6x5_SFLOAT_BLOCK_EXT", vk::Format::eAstc6x5SfloatBlockEXT);
    e_vk_Format.value("ASTC_6x6_SFLOAT_BLOCK_EXT", vk::Format::eAstc6x6SfloatBlockEXT);
    e_vk_Format.value("ASTC_8x5_SFLOAT_BLOCK_EXT", vk::Format::eAstc8x5SfloatBlockEXT);
    e_vk_Format.value("ASTC_8x6_SFLOAT_BLOCK_EXT", vk::Format::eAstc8x6SfloatBlockEXT);
    e_vk_Format.value("ASTC_8x8_SFLOAT_BLOCK_EXT", vk::Format::eAstc8x8SfloatBlockEXT);
    e_vk_Format.value("ASTC_10x5_SFLOAT_BLOCK_EXT", vk::Format::eAstc10x5SfloatBlockEXT);
    e_vk_Format.value("ASTC_10x6_SFLOAT_BLOCK_EXT", vk::Format::eAstc10x6SfloatBlockEXT);
    e_vk_Format.value("ASTC_10x8_SFLOAT_BLOCK_EXT", vk::Format::eAstc10x8SfloatBlockEXT);
    e_vk_Format.value("ASTC_10x10_SFLOAT_BLOCK_EXT", vk::Format::eAstc10x10SfloatBlockEXT);
    e_vk_Format.value("ASTC_12x10_SFLOAT_BLOCK_EXT", vk::Format::eAstc12x10SfloatBlockEXT);
    e_vk_Format.value("ASTC_12x12_SFLOAT_BLOCK_EXT", vk::Format::eAstc12x12SfloatBlockEXT);
    e_vk_Format.value("G8B8G8R8422_UNORM_KHR", vk::Format::eG8B8G8R8422UnormKHR);
    e_vk_Format.value("B8G8R8G8422_UNORM_KHR", vk::Format::eB8G8R8G8422UnormKHR);
    e_vk_Format.value("G8B8R83_PLANE_420_UNORM_KHR", vk::Format::eG8B8R83Plane420UnormKHR);
    e_vk_Format.value("G8B8R82_PLANE_420_UNORM_KHR", vk::Format::eG8B8R82Plane420UnormKHR);
    e_vk_Format.value("G8B8R83_PLANE_422_UNORM_KHR", vk::Format::eG8B8R83Plane422UnormKHR);
    e_vk_Format.value("G8B8R82_PLANE_422_UNORM_KHR", vk::Format::eG8B8R82Plane422UnormKHR);
    e_vk_Format.value("G8B8R83_PLANE_444_UNORM_KHR", vk::Format::eG8B8R83Plane444UnormKHR);
    e_vk_Format.value("R10X6_UNORM_PACK_16KHR", vk::Format::eR10X6UnormPack16KHR);
    e_vk_Format.value("R10X6G10X6_UNORM_2_PACK_16KHR", vk::Format::eR10X6G10X6Unorm2Pack16KHR);
    e_vk_Format.value("R10X6G10X6B10X6A10X6_UNORM_4_PACK_16KHR", vk::Format::eR10X6G10X6B10X6A10X6Unorm4Pack16KHR);
    e_vk_Format.value("G10X6B10X6G10X6R10X6422_UNORM_4_PACK_16KHR", vk::Format::eG10X6B10X6G10X6R10X6422Unorm4Pack16KHR);
    e_vk_Format.value("B10X6G10X6R10X6G10X6422_UNORM_4_PACK_16KHR", vk::Format::eB10X6G10X6R10X6G10X6422Unorm4Pack16KHR);
    e_vk_Format.value("G10X6B10X6R10X63_PLANE_420_UNORM_3_PACK_16KHR", vk::Format::eG10X6B10X6R10X63Plane420Unorm3Pack16KHR);
    e_vk_Format.value("G10X6B10X6R10X62_PLANE_420_UNORM_3_PACK_16KHR", vk::Format::eG10X6B10X6R10X62Plane420Unorm3Pack16KHR);
    e_vk_Format.value("G10X6B10X6R10X63_PLANE_422_UNORM_3_PACK_16KHR", vk::Format::eG10X6B10X6R10X63Plane422Unorm3Pack16KHR);
    e_vk_Format.value("G10X6B10X6R10X62_PLANE_422_UNORM_3_PACK_16KHR", vk::Format::eG10X6B10X6R10X62Plane422Unorm3Pack16KHR);
    e_vk_Format.value("G10X6B10X6R10X63_PLANE_444_UNORM_3_PACK_16KHR", vk::Format::eG10X6B10X6R10X63Plane444Unorm3Pack16KHR);
    e_vk_Format.value("R12X4_UNORM_PACK_16KHR", vk::Format::eR12X4UnormPack16KHR);
    e_vk_Format.value("R12X4G12X4_UNORM_2_PACK_16KHR", vk::Format::eR12X4G12X4Unorm2Pack16KHR);
    e_vk_Format.value("R12X4G12X4B12X4A12X4_UNORM_4_PACK_16KHR", vk::Format::eR12X4G12X4B12X4A12X4Unorm4Pack16KHR);
    e_vk_Format.value("G12X4B12X4G12X4R12X4422_UNORM_4_PACK_16KHR", vk::Format::eG12X4B12X4G12X4R12X4422Unorm4Pack16KHR);
    e_vk_Format.value("B12X4G12X4R12X4G12X4422_UNORM_4_PACK_16KHR", vk::Format::eB12X4G12X4R12X4G12X4422Unorm4Pack16KHR);
    e_vk_Format.value("G12X4B12X4R12X43_PLANE_420_UNORM_3_PACK_16KHR", vk::Format::eG12X4B12X4R12X43Plane420Unorm3Pack16KHR);
    e_vk_Format.value("G12X4B12X4R12X42_PLANE_420_UNORM_3_PACK_16KHR", vk::Format::eG12X4B12X4R12X42Plane420Unorm3Pack16KHR);
    e_vk_Format.value("G12X4B12X4R12X43_PLANE_422_UNORM_3_PACK_16KHR", vk::Format::eG12X4B12X4R12X43Plane422Unorm3Pack16KHR);
    e_vk_Format.value("G12X4B12X4R12X42_PLANE_422_UNORM_3_PACK_16KHR", vk::Format::eG12X4B12X4R12X42Plane422Unorm3Pack16KHR);
    e_vk_Format.value("G12X4B12X4R12X43_PLANE_444_UNORM_3_PACK_16KHR", vk::Format::eG12X4B12X4R12X43Plane444Unorm3Pack16KHR);
    e_vk_Format.value("G16B16G16R16422_UNORM_KHR", vk::Format::eG16B16G16R16422UnormKHR);
    e_vk_Format.value("B16G16R16G16422_UNORM_KHR", vk::Format::eB16G16R16G16422UnormKHR);
    e_vk_Format.value("G16B16R163_PLANE_420_UNORM_KHR", vk::Format::eG16B16R163Plane420UnormKHR);
    e_vk_Format.value("G16B16R162_PLANE_420_UNORM_KHR", vk::Format::eG16B16R162Plane420UnormKHR);
    e_vk_Format.value("G16B16R163_PLANE_422_UNORM_KHR", vk::Format::eG16B16R163Plane422UnormKHR);
    e_vk_Format.value("G16B16R162_PLANE_422_UNORM_KHR", vk::Format::eG16B16R162Plane422UnormKHR);
    e_vk_Format.value("G16B16R163_PLANE_444_UNORM_KHR", vk::Format::eG16B16R163Plane444UnormKHR);
    e_vk_Format.value("G8B8R82_PLANE_444_UNORM_EXT", vk::Format::eG8B8R82Plane444UnormEXT);
    e_vk_Format.value("G10X6B10X6R10X62_PLANE_444_UNORM_3_PACK_16EXT", vk::Format::eG10X6B10X6R10X62Plane444Unorm3Pack16EXT);
    e_vk_Format.value("G12X4B12X4R12X42_PLANE_444_UNORM_3_PACK_16EXT", vk::Format::eG12X4B12X4R12X42Plane444Unorm3Pack16EXT);
    e_vk_Format.value("G16B16R162_PLANE_444_UNORM_EXT", vk::Format::eG16B16R162Plane444UnormEXT);
    e_vk_Format.value("A4R4G4B4_UNORM_PACK_16EXT", vk::Format::eA4R4G4B4UnormPack16EXT);
    e_vk_Format.value("A4B4G4R4_UNORM_PACK_16EXT", vk::Format::eA4B4G4R4UnormPack16EXT);
    e_vk_Format.value("R16G16S105NV", vk::Format::eR16G16S105NV);
    e_vk_Format.value("A1B5G5R5_UNORM_PACK_16KHR", vk::Format::eA1B5G5R5UnormPack16KHR);
    e_vk_Format.value("A8_UNORM_KHR", vk::Format::eA8UnormKHR);

    py::enum_<vk::FormatFeatureFlagBits> e_vk_FormatFeatureFlagBits(m_vk, "FormatFeatureFlagBits");
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE", vk::FormatFeatureFlagBits::eSampledImage);
    e_vk_FormatFeatureFlagBits.value("STORAGE_IMAGE", vk::FormatFeatureFlagBits::eStorageImage);
    e_vk_FormatFeatureFlagBits.value("STORAGE_IMAGE_ATOMIC", vk::FormatFeatureFlagBits::eStorageImageAtomic);
    e_vk_FormatFeatureFlagBits.value("UNIFORM_TEXEL_BUFFER", vk::FormatFeatureFlagBits::eUniformTexelBuffer);
    e_vk_FormatFeatureFlagBits.value("STORAGE_TEXEL_BUFFER", vk::FormatFeatureFlagBits::eStorageTexelBuffer);
    e_vk_FormatFeatureFlagBits.value("STORAGE_TEXEL_BUFFER_ATOMIC", vk::FormatFeatureFlagBits::eStorageTexelBufferAtomic);
    e_vk_FormatFeatureFlagBits.value("VERTEX_BUFFER", vk::FormatFeatureFlagBits::eVertexBuffer);
    e_vk_FormatFeatureFlagBits.value("COLOR_ATTACHMENT", vk::FormatFeatureFlagBits::eColorAttachment);
    e_vk_FormatFeatureFlagBits.value("COLOR_ATTACHMENT_BLEND", vk::FormatFeatureFlagBits::eColorAttachmentBlend);
    e_vk_FormatFeatureFlagBits.value("DEPTH_STENCIL_ATTACHMENT", vk::FormatFeatureFlagBits::eDepthStencilAttachment);
    e_vk_FormatFeatureFlagBits.value("BLIT_SRC", vk::FormatFeatureFlagBits::eBlitSrc);
    e_vk_FormatFeatureFlagBits.value("BLIT_DST", vk::FormatFeatureFlagBits::eBlitDst);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_LINEAR", vk::FormatFeatureFlagBits::eSampledImageFilterLinear);
    e_vk_FormatFeatureFlagBits.value("TRANSFER_SRC", vk::FormatFeatureFlagBits::eTransferSrc);
    e_vk_FormatFeatureFlagBits.value("TRANSFER_DST", vk::FormatFeatureFlagBits::eTransferDst);
    e_vk_FormatFeatureFlagBits.value("MIDPOINT_CHROMA_SAMPLES", vk::FormatFeatureFlagBits::eMidpointChromaSamples);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER", vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionLinearFilter);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER", vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionSeparateReconstructionFilter);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT", vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionChromaReconstructionExplicit);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE", vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionChromaReconstructionExplicitForceable);
    e_vk_FormatFeatureFlagBits.value("DISJOINT", vk::FormatFeatureFlagBits::eDisjoint);
    e_vk_FormatFeatureFlagBits.value("COSITED_CHROMA_SAMPLES", vk::FormatFeatureFlagBits::eCositedChromaSamples);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_MINMAX", vk::FormatFeatureFlagBits::eSampledImageFilterMinmax);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_CUBIC_IMG", vk::FormatFeatureFlagBits::eSampledImageFilterCubicIMG);
    e_vk_FormatFeatureFlagBits.value("VIDEO_DECODE_OUTPUT_KHR", vk::FormatFeatureFlagBits::eVideoDecodeOutputKHR);
    e_vk_FormatFeatureFlagBits.value("VIDEO_DECODE_DPB_KHR", vk::FormatFeatureFlagBits::eVideoDecodeDpbKHR);
    e_vk_FormatFeatureFlagBits.value("TRANSFER_SRC_KHR", vk::FormatFeatureFlagBits::eTransferSrcKHR);
    e_vk_FormatFeatureFlagBits.value("TRANSFER_DST_KHR", vk::FormatFeatureFlagBits::eTransferDstKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_MINMAX_EXT", vk::FormatFeatureFlagBits::eSampledImageFilterMinmaxEXT);
    e_vk_FormatFeatureFlagBits.value("ACCELERATION_STRUCTURE_VERTEX_BUFFER_KHR", vk::FormatFeatureFlagBits::eAccelerationStructureVertexBufferKHR);
    e_vk_FormatFeatureFlagBits.value("MIDPOINT_CHROMA_SAMPLES_KHR", vk::FormatFeatureFlagBits::eMidpointChromaSamplesKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_KHR", vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionLinearFilterKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_KHR", vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionSeparateReconstructionFilterKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_KHR", vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionChromaReconstructionExplicitKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_KHR", vk::FormatFeatureFlagBits::eSampledImageYcbcrConversionChromaReconstructionExplicitForceableKHR);
    e_vk_FormatFeatureFlagBits.value("DISJOINT_KHR", vk::FormatFeatureFlagBits::eDisjointKHR);
    e_vk_FormatFeatureFlagBits.value("COSITED_CHROMA_SAMPLES_KHR", vk::FormatFeatureFlagBits::eCositedChromaSamplesKHR);
    e_vk_FormatFeatureFlagBits.value("SAMPLED_IMAGE_FILTER_CUBIC_EXT", vk::FormatFeatureFlagBits::eSampledImageFilterCubicEXT);
    e_vk_FormatFeatureFlagBits.value("FRAGMENT_DENSITY_MAP_EXT", vk::FormatFeatureFlagBits::eFragmentDensityMapEXT);
    e_vk_FormatFeatureFlagBits.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", vk::FormatFeatureFlagBits::eFragmentShadingRateAttachmentKHR);
    e_vk_FormatFeatureFlagBits.value("VIDEO_ENCODE_INPUT_KHR", vk::FormatFeatureFlagBits::eVideoEncodeInputKHR);
    e_vk_FormatFeatureFlagBits.value("VIDEO_ENCODE_DPB_KHR", vk::FormatFeatureFlagBits::eVideoEncodeDpbKHR);

    py::enum_<vk::FramebufferCreateFlagBits> e_vk_FramebufferCreateFlagBits(m_vk, "FramebufferCreateFlagBits");
    e_vk_FramebufferCreateFlagBits.value("IMAGELESS", vk::FramebufferCreateFlagBits::eImageless);
    e_vk_FramebufferCreateFlagBits.value("IMAGELESS_KHR", vk::FramebufferCreateFlagBits::eImagelessKHR);

    py::enum_<vk::FrontFace> e_vk_FrontFace(m_vk, "FrontFace");
    e_vk_FrontFace.value("COUNTER_CLOCKWISE", vk::FrontFace::eCounterClockwise);
    e_vk_FrontFace.value("CLOCKWISE", vk::FrontFace::eClockwise);

    py::enum_<vk::ImageAspectFlagBits> e_vk_ImageAspectFlagBits(m_vk, "ImageAspectFlagBits");
    e_vk_ImageAspectFlagBits.value("COLOR", vk::ImageAspectFlagBits::eColor);
    e_vk_ImageAspectFlagBits.value("DEPTH", vk::ImageAspectFlagBits::eDepth);
    e_vk_ImageAspectFlagBits.value("STENCIL", vk::ImageAspectFlagBits::eStencil);
    e_vk_ImageAspectFlagBits.value("METADATA", vk::ImageAspectFlagBits::eMetadata);
    e_vk_ImageAspectFlagBits.value("PLANE_0", vk::ImageAspectFlagBits::ePlane0);
    e_vk_ImageAspectFlagBits.value("PLANE_1", vk::ImageAspectFlagBits::ePlane1);
    e_vk_ImageAspectFlagBits.value("PLANE_2", vk::ImageAspectFlagBits::ePlane2);
    e_vk_ImageAspectFlagBits.value("NONE", vk::ImageAspectFlagBits::eNone);
    e_vk_ImageAspectFlagBits.value("PLANE_0KHR", vk::ImageAspectFlagBits::ePlane0KHR);
    e_vk_ImageAspectFlagBits.value("PLANE_1KHR", vk::ImageAspectFlagBits::ePlane1KHR);
    e_vk_ImageAspectFlagBits.value("PLANE_2KHR", vk::ImageAspectFlagBits::ePlane2KHR);
    e_vk_ImageAspectFlagBits.value("MEMORY_PLANE_0EXT", vk::ImageAspectFlagBits::eMemoryPlane0EXT);
    e_vk_ImageAspectFlagBits.value("MEMORY_PLANE_1EXT", vk::ImageAspectFlagBits::eMemoryPlane1EXT);
    e_vk_ImageAspectFlagBits.value("MEMORY_PLANE_2EXT", vk::ImageAspectFlagBits::eMemoryPlane2EXT);
    e_vk_ImageAspectFlagBits.value("MEMORY_PLANE_3EXT", vk::ImageAspectFlagBits::eMemoryPlane3EXT);
    e_vk_ImageAspectFlagBits.value("NONE_KHR", vk::ImageAspectFlagBits::eNoneKHR);

    py::enum_<vk::ImageCreateFlagBits> e_vk_ImageCreateFlagBits(m_vk, "ImageCreateFlagBits");
    e_vk_ImageCreateFlagBits.value("SPARSE_BINDING", vk::ImageCreateFlagBits::eSparseBinding);
    e_vk_ImageCreateFlagBits.value("SPARSE_RESIDENCY", vk::ImageCreateFlagBits::eSparseResidency);
    e_vk_ImageCreateFlagBits.value("SPARSE_ALIASED", vk::ImageCreateFlagBits::eSparseAliased);
    e_vk_ImageCreateFlagBits.value("MUTABLE_FORMAT", vk::ImageCreateFlagBits::eMutableFormat);
    e_vk_ImageCreateFlagBits.value("CUBE_COMPATIBLE", vk::ImageCreateFlagBits::eCubeCompatible);
    e_vk_ImageCreateFlagBits.value("ALIAS", vk::ImageCreateFlagBits::eAlias);
    e_vk_ImageCreateFlagBits.value("SPLIT_INSTANCE_BIND_REGIONS", vk::ImageCreateFlagBits::eSplitInstanceBindRegions);
    e_vk_ImageCreateFlagBits.value("_2D_ARRAY_COMPATIBLE", vk::ImageCreateFlagBits::e2DArrayCompatible);
    e_vk_ImageCreateFlagBits.value("BLOCK_TEXEL_VIEW_COMPATIBLE", vk::ImageCreateFlagBits::eBlockTexelViewCompatible);
    e_vk_ImageCreateFlagBits.value("EXTENDED_USAGE", vk::ImageCreateFlagBits::eExtendedUsage);
    e_vk_ImageCreateFlagBits.value("PROTECTED", vk::ImageCreateFlagBits::eProtected);
    e_vk_ImageCreateFlagBits.value("DISJOINT", vk::ImageCreateFlagBits::eDisjoint);
    e_vk_ImageCreateFlagBits.value("CORNER_SAMPLED_NV", vk::ImageCreateFlagBits::eCornerSampledNV);
    e_vk_ImageCreateFlagBits.value("SPLIT_INSTANCE_BIND_REGIONS_KHR", vk::ImageCreateFlagBits::eSplitInstanceBindRegionsKHR);
    e_vk_ImageCreateFlagBits.value("_2D_ARRAY_COMPATIBLE_KHR", vk::ImageCreateFlagBits::e2DArrayCompatibleKHR);
    e_vk_ImageCreateFlagBits.value("BLOCK_TEXEL_VIEW_COMPATIBLE_KHR", vk::ImageCreateFlagBits::eBlockTexelViewCompatibleKHR);
    e_vk_ImageCreateFlagBits.value("EXTENDED_USAGE_KHR", vk::ImageCreateFlagBits::eExtendedUsageKHR);
    e_vk_ImageCreateFlagBits.value("SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_EXT", vk::ImageCreateFlagBits::eSampleLocationsCompatibleDepthEXT);
    e_vk_ImageCreateFlagBits.value("DISJOINT_KHR", vk::ImageCreateFlagBits::eDisjointKHR);
    e_vk_ImageCreateFlagBits.value("ALIAS_KHR", vk::ImageCreateFlagBits::eAliasKHR);
    e_vk_ImageCreateFlagBits.value("SUBSAMPLED_EXT", vk::ImageCreateFlagBits::eSubsampledEXT);
    e_vk_ImageCreateFlagBits.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", vk::ImageCreateFlagBits::eDescriptorBufferCaptureReplayEXT);
    e_vk_ImageCreateFlagBits.value("MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_EXT", vk::ImageCreateFlagBits::eMultisampledRenderToSingleSampledEXT);
    e_vk_ImageCreateFlagBits.value("_2D_VIEW_COMPATIBLE_EXT", vk::ImageCreateFlagBits::e2DViewCompatibleEXT);
    e_vk_ImageCreateFlagBits.value("FRAGMENT_DENSITY_MAP_OFFSET_QCOM", vk::ImageCreateFlagBits::eFragmentDensityMapOffsetQCOM);
    e_vk_ImageCreateFlagBits.value("VIDEO_PROFILE_INDEPENDENT_KHR", vk::ImageCreateFlagBits::eVideoProfileIndependentKHR);

    py::enum_<vk::ImageLayout> e_vk_ImageLayout(m_vk, "ImageLayout");
    e_vk_ImageLayout.value("UNDEFINED", vk::ImageLayout::eUndefined);
    e_vk_ImageLayout.value("GENERAL", vk::ImageLayout::eGeneral);
    e_vk_ImageLayout.value("COLOR_ATTACHMENT_OPTIMAL", vk::ImageLayout::eColorAttachmentOptimal);
    e_vk_ImageLayout.value("DEPTH_STENCIL_ATTACHMENT_OPTIMAL", vk::ImageLayout::eDepthStencilAttachmentOptimal);
    e_vk_ImageLayout.value("DEPTH_STENCIL_READ_ONLY_OPTIMAL", vk::ImageLayout::eDepthStencilReadOnlyOptimal);
    e_vk_ImageLayout.value("SHADER_READ_ONLY_OPTIMAL", vk::ImageLayout::eShaderReadOnlyOptimal);
    e_vk_ImageLayout.value("TRANSFER_SRC_OPTIMAL", vk::ImageLayout::eTransferSrcOptimal);
    e_vk_ImageLayout.value("TRANSFER_DST_OPTIMAL", vk::ImageLayout::eTransferDstOptimal);
    e_vk_ImageLayout.value("PREINITIALIZED", vk::ImageLayout::ePreinitialized);
    e_vk_ImageLayout.value("DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL", vk::ImageLayout::eDepthReadOnlyStencilAttachmentOptimal);
    e_vk_ImageLayout.value("DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL", vk::ImageLayout::eDepthAttachmentStencilReadOnlyOptimal);
    e_vk_ImageLayout.value("DEPTH_ATTACHMENT_OPTIMAL", vk::ImageLayout::eDepthAttachmentOptimal);
    e_vk_ImageLayout.value("DEPTH_READ_ONLY_OPTIMAL", vk::ImageLayout::eDepthReadOnlyOptimal);
    e_vk_ImageLayout.value("STENCIL_ATTACHMENT_OPTIMAL", vk::ImageLayout::eStencilAttachmentOptimal);
    e_vk_ImageLayout.value("STENCIL_READ_ONLY_OPTIMAL", vk::ImageLayout::eStencilReadOnlyOptimal);
    e_vk_ImageLayout.value("READ_ONLY_OPTIMAL", vk::ImageLayout::eReadOnlyOptimal);
    e_vk_ImageLayout.value("ATTACHMENT_OPTIMAL", vk::ImageLayout::eAttachmentOptimal);
    e_vk_ImageLayout.value("PRESENT_SRC_KHR", vk::ImageLayout::ePresentSrcKHR);
    e_vk_ImageLayout.value("VIDEO_DECODE_DST_KHR", vk::ImageLayout::eVideoDecodeDstKHR);
    e_vk_ImageLayout.value("VIDEO_DECODE_SRC_KHR", vk::ImageLayout::eVideoDecodeSrcKHR);
    e_vk_ImageLayout.value("VIDEO_DECODE_DPB_KHR", vk::ImageLayout::eVideoDecodeDpbKHR);
    e_vk_ImageLayout.value("SHARED_PRESENT_KHR", vk::ImageLayout::eSharedPresentKHR);
    e_vk_ImageLayout.value("DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR", vk::ImageLayout::eDepthReadOnlyStencilAttachmentOptimalKHR);
    e_vk_ImageLayout.value("DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR", vk::ImageLayout::eDepthAttachmentStencilReadOnlyOptimalKHR);
    e_vk_ImageLayout.value("SHADING_RATE_OPTIMAL_NV", vk::ImageLayout::eShadingRateOptimalNV);
    e_vk_ImageLayout.value("FRAGMENT_DENSITY_MAP_OPTIMAL_EXT", vk::ImageLayout::eFragmentDensityMapOptimalEXT);
    e_vk_ImageLayout.value("FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR", vk::ImageLayout::eFragmentShadingRateAttachmentOptimalKHR);
    e_vk_ImageLayout.value("DEPTH_ATTACHMENT_OPTIMAL_KHR", vk::ImageLayout::eDepthAttachmentOptimalKHR);
    e_vk_ImageLayout.value("DEPTH_READ_ONLY_OPTIMAL_KHR", vk::ImageLayout::eDepthReadOnlyOptimalKHR);
    e_vk_ImageLayout.value("STENCIL_ATTACHMENT_OPTIMAL_KHR", vk::ImageLayout::eStencilAttachmentOptimalKHR);
    e_vk_ImageLayout.value("STENCIL_READ_ONLY_OPTIMAL_KHR", vk::ImageLayout::eStencilReadOnlyOptimalKHR);
    e_vk_ImageLayout.value("VIDEO_ENCODE_DST_KHR", vk::ImageLayout::eVideoEncodeDstKHR);
    e_vk_ImageLayout.value("VIDEO_ENCODE_SRC_KHR", vk::ImageLayout::eVideoEncodeSrcKHR);
    e_vk_ImageLayout.value("VIDEO_ENCODE_DPB_KHR", vk::ImageLayout::eVideoEncodeDpbKHR);
    e_vk_ImageLayout.value("READ_ONLY_OPTIMAL_KHR", vk::ImageLayout::eReadOnlyOptimalKHR);
    e_vk_ImageLayout.value("ATTACHMENT_OPTIMAL_KHR", vk::ImageLayout::eAttachmentOptimalKHR);
    e_vk_ImageLayout.value("ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT", vk::ImageLayout::eAttachmentFeedbackLoopOptimalEXT);

    py::enum_<vk::ImageTiling> e_vk_ImageTiling(m_vk, "ImageTiling");
    e_vk_ImageTiling.value("OPTIMAL", vk::ImageTiling::eOptimal);
    e_vk_ImageTiling.value("LINEAR", vk::ImageTiling::eLinear);
    e_vk_ImageTiling.value("DRM_FORMAT_MODIFIER_EXT", vk::ImageTiling::eDrmFormatModifierEXT);

    py::enum_<vk::ImageType> e_vk_ImageType(m_vk, "ImageType");
    e_vk_ImageType.value("_1D", vk::ImageType::e1D);
    e_vk_ImageType.value("_2D", vk::ImageType::e2D);
    e_vk_ImageType.value("_3D", vk::ImageType::e3D);

    py::enum_<vk::ImageUsageFlagBits> e_vk_ImageUsageFlagBits(m_vk, "ImageUsageFlagBits");
    e_vk_ImageUsageFlagBits.value("TRANSFER_SRC", vk::ImageUsageFlagBits::eTransferSrc);
    e_vk_ImageUsageFlagBits.value("TRANSFER_DST", vk::ImageUsageFlagBits::eTransferDst);
    e_vk_ImageUsageFlagBits.value("SAMPLED", vk::ImageUsageFlagBits::eSampled);
    e_vk_ImageUsageFlagBits.value("STORAGE", vk::ImageUsageFlagBits::eStorage);
    e_vk_ImageUsageFlagBits.value("COLOR_ATTACHMENT", vk::ImageUsageFlagBits::eColorAttachment);
    e_vk_ImageUsageFlagBits.value("DEPTH_STENCIL_ATTACHMENT", vk::ImageUsageFlagBits::eDepthStencilAttachment);
    e_vk_ImageUsageFlagBits.value("TRANSIENT_ATTACHMENT", vk::ImageUsageFlagBits::eTransientAttachment);
    e_vk_ImageUsageFlagBits.value("INPUT_ATTACHMENT", vk::ImageUsageFlagBits::eInputAttachment);
    e_vk_ImageUsageFlagBits.value("VIDEO_DECODE_DST_KHR", vk::ImageUsageFlagBits::eVideoDecodeDstKHR);
    e_vk_ImageUsageFlagBits.value("VIDEO_DECODE_SRC_KHR", vk::ImageUsageFlagBits::eVideoDecodeSrcKHR);
    e_vk_ImageUsageFlagBits.value("VIDEO_DECODE_DPB_KHR", vk::ImageUsageFlagBits::eVideoDecodeDpbKHR);
    e_vk_ImageUsageFlagBits.value("SHADING_RATE_IMAGE_NV", vk::ImageUsageFlagBits::eShadingRateImageNV);
    e_vk_ImageUsageFlagBits.value("FRAGMENT_DENSITY_MAP_EXT", vk::ImageUsageFlagBits::eFragmentDensityMapEXT);
    e_vk_ImageUsageFlagBits.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", vk::ImageUsageFlagBits::eFragmentShadingRateAttachmentKHR);
    e_vk_ImageUsageFlagBits.value("HOST_TRANSFER_EXT", vk::ImageUsageFlagBits::eHostTransferEXT);
    e_vk_ImageUsageFlagBits.value("VIDEO_ENCODE_DST_KHR", vk::ImageUsageFlagBits::eVideoEncodeDstKHR);
    e_vk_ImageUsageFlagBits.value("VIDEO_ENCODE_SRC_KHR", vk::ImageUsageFlagBits::eVideoEncodeSrcKHR);
    e_vk_ImageUsageFlagBits.value("VIDEO_ENCODE_DPB_KHR", vk::ImageUsageFlagBits::eVideoEncodeDpbKHR);
    e_vk_ImageUsageFlagBits.value("ATTACHMENT_FEEDBACK_LOOP_EXT", vk::ImageUsageFlagBits::eAttachmentFeedbackLoopEXT);
    e_vk_ImageUsageFlagBits.value("INVOCATION_MASK_HUAWEI", vk::ImageUsageFlagBits::eInvocationMaskHUAWEI);
    e_vk_ImageUsageFlagBits.value("SAMPLE_WEIGHT_QCOM", vk::ImageUsageFlagBits::eSampleWeightQCOM);
    e_vk_ImageUsageFlagBits.value("SAMPLE_BLOCK_MATCH_QCOM", vk::ImageUsageFlagBits::eSampleBlockMatchQCOM);

    py::enum_<vk::ImageViewCreateFlagBits> e_vk_ImageViewCreateFlagBits(m_vk, "ImageViewCreateFlagBits");
    e_vk_ImageViewCreateFlagBits.value("FRAGMENT_DENSITY_MAP_DYNAMIC_EXT", vk::ImageViewCreateFlagBits::eFragmentDensityMapDynamicEXT);
    e_vk_ImageViewCreateFlagBits.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", vk::ImageViewCreateFlagBits::eDescriptorBufferCaptureReplayEXT);
    e_vk_ImageViewCreateFlagBits.value("FRAGMENT_DENSITY_MAP_DEFERRED_EXT", vk::ImageViewCreateFlagBits::eFragmentDensityMapDeferredEXT);

    py::enum_<vk::ImageViewType> e_vk_ImageViewType(m_vk, "ImageViewType");
    e_vk_ImageViewType.value("_1D", vk::ImageViewType::e1D);
    e_vk_ImageViewType.value("_2D", vk::ImageViewType::e2D);
    e_vk_ImageViewType.value("_3D", vk::ImageViewType::e3D);
    e_vk_ImageViewType.value("CUBE", vk::ImageViewType::eCube);
    e_vk_ImageViewType.value("_1D_ARRAY", vk::ImageViewType::e1DArray);
    e_vk_ImageViewType.value("_2D_ARRAY", vk::ImageViewType::e2DArray);
    e_vk_ImageViewType.value("CUBE_ARRAY", vk::ImageViewType::eCubeArray);

    py::enum_<vk::IndexType> e_vk_IndexType(m_vk, "IndexType");
    e_vk_IndexType.value("UINT_16", vk::IndexType::eUint16);
    e_vk_IndexType.value("UINT_32", vk::IndexType::eUint32);
    e_vk_IndexType.value("NONE_KHR", vk::IndexType::eNoneKHR);
    e_vk_IndexType.value("NONE_NV", vk::IndexType::eNoneNV);
    e_vk_IndexType.value("UINT_8EXT", vk::IndexType::eUint8EXT);

    py::enum_<vk::InstanceCreateFlagBits> e_vk_InstanceCreateFlagBits(m_vk, "InstanceCreateFlagBits");
    e_vk_InstanceCreateFlagBits.value("ENUMERATE_PORTABILITY_KHR", vk::InstanceCreateFlagBits::eEnumeratePortabilityKHR);

    py::enum_<vk::InternalAllocationType> e_vk_InternalAllocationType(m_vk, "InternalAllocationType");
    e_vk_InternalAllocationType.value("EXECUTABLE", vk::InternalAllocationType::eExecutable);

    py::enum_<vk::LogicOp> e_vk_LogicOp(m_vk, "LogicOp");
    e_vk_LogicOp.value("CLEAR", vk::LogicOp::eClear);
    e_vk_LogicOp.value("AND", vk::LogicOp::eAnd);
    e_vk_LogicOp.value("AND_REVERSE", vk::LogicOp::eAndReverse);
    e_vk_LogicOp.value("COPY", vk::LogicOp::eCopy);
    e_vk_LogicOp.value("AND_INVERTED", vk::LogicOp::eAndInverted);
    e_vk_LogicOp.value("NO_OP", vk::LogicOp::eNoOp);
    e_vk_LogicOp.value("XOR", vk::LogicOp::eXor);
    e_vk_LogicOp.value("OR", vk::LogicOp::eOr);
    e_vk_LogicOp.value("NOR", vk::LogicOp::eNor);
    e_vk_LogicOp.value("EQUIVALENT", vk::LogicOp::eEquivalent);
    e_vk_LogicOp.value("INVERT", vk::LogicOp::eInvert);
    e_vk_LogicOp.value("OR_REVERSE", vk::LogicOp::eOrReverse);
    e_vk_LogicOp.value("COPY_INVERTED", vk::LogicOp::eCopyInverted);
    e_vk_LogicOp.value("OR_INVERTED", vk::LogicOp::eOrInverted);
    e_vk_LogicOp.value("NAND", vk::LogicOp::eNand);
    e_vk_LogicOp.value("SET", vk::LogicOp::eSet);

    py::enum_<vk::MemoryHeapFlagBits> e_vk_MemoryHeapFlagBits(m_vk, "MemoryHeapFlagBits");
    e_vk_MemoryHeapFlagBits.value("DEVICE_LOCAL", vk::MemoryHeapFlagBits::eDeviceLocal);
    e_vk_MemoryHeapFlagBits.value("MULTI_INSTANCE", vk::MemoryHeapFlagBits::eMultiInstance);
    e_vk_MemoryHeapFlagBits.value("MULTI_INSTANCE_KHR", vk::MemoryHeapFlagBits::eMultiInstanceKHR);

    py::enum_<vk::MemoryMapFlagBits> e_vk_MemoryMapFlagBits(m_vk, "MemoryMapFlagBits");

    py::enum_<vk::MemoryPropertyFlagBits> e_vk_MemoryPropertyFlagBits(m_vk, "MemoryPropertyFlagBits");
    e_vk_MemoryPropertyFlagBits.value("DEVICE_LOCAL", vk::MemoryPropertyFlagBits::eDeviceLocal);
    e_vk_MemoryPropertyFlagBits.value("HOST_VISIBLE", vk::MemoryPropertyFlagBits::eHostVisible);
    e_vk_MemoryPropertyFlagBits.value("HOST_COHERENT", vk::MemoryPropertyFlagBits::eHostCoherent);
    e_vk_MemoryPropertyFlagBits.value("HOST_CACHED", vk::MemoryPropertyFlagBits::eHostCached);
    e_vk_MemoryPropertyFlagBits.value("LAZILY_ALLOCATED", vk::MemoryPropertyFlagBits::eLazilyAllocated);
    e_vk_MemoryPropertyFlagBits.value("PROTECTED", vk::MemoryPropertyFlagBits::eProtected);
    e_vk_MemoryPropertyFlagBits.value("DEVICE_COHERENT_AMD", vk::MemoryPropertyFlagBits::eDeviceCoherentAMD);
    e_vk_MemoryPropertyFlagBits.value("DEVICE_UNCACHED_AMD", vk::MemoryPropertyFlagBits::eDeviceUncachedAMD);
    e_vk_MemoryPropertyFlagBits.value("RDMA_CAPABLE_NV", vk::MemoryPropertyFlagBits::eRdmaCapableNV);

    py::enum_<vk::ObjectType> e_vk_ObjectType(m_vk, "ObjectType");
    e_vk_ObjectType.value("UNKNOWN", vk::ObjectType::eUnknown);
    e_vk_ObjectType.value("INSTANCE", vk::ObjectType::eInstance);
    e_vk_ObjectType.value("PHYSICAL_DEVICE", vk::ObjectType::ePhysicalDevice);
    e_vk_ObjectType.value("DEVICE", vk::ObjectType::eDevice);
    e_vk_ObjectType.value("QUEUE", vk::ObjectType::eQueue);
    e_vk_ObjectType.value("SEMAPHORE", vk::ObjectType::eSemaphore);
    e_vk_ObjectType.value("COMMAND_BUFFER", vk::ObjectType::eCommandBuffer);
    e_vk_ObjectType.value("FENCE", vk::ObjectType::eFence);
    e_vk_ObjectType.value("DEVICE_MEMORY", vk::ObjectType::eDeviceMemory);
    e_vk_ObjectType.value("BUFFER", vk::ObjectType::eBuffer);
    e_vk_ObjectType.value("IMAGE", vk::ObjectType::eImage);
    e_vk_ObjectType.value("EVENT", vk::ObjectType::eEvent);
    e_vk_ObjectType.value("QUERY_POOL", vk::ObjectType::eQueryPool);
    e_vk_ObjectType.value("BUFFER_VIEW", vk::ObjectType::eBufferView);
    e_vk_ObjectType.value("IMAGE_VIEW", vk::ObjectType::eImageView);
    e_vk_ObjectType.value("SHADER_MODULE", vk::ObjectType::eShaderModule);
    e_vk_ObjectType.value("PIPELINE_CACHE", vk::ObjectType::ePipelineCache);
    e_vk_ObjectType.value("PIPELINE_LAYOUT", vk::ObjectType::ePipelineLayout);
    e_vk_ObjectType.value("RENDER_PASS", vk::ObjectType::eRenderPass);
    e_vk_ObjectType.value("PIPELINE", vk::ObjectType::ePipeline);
    e_vk_ObjectType.value("DESCRIPTOR_SET_LAYOUT", vk::ObjectType::eDescriptorSetLayout);
    e_vk_ObjectType.value("SAMPLER", vk::ObjectType::eSampler);
    e_vk_ObjectType.value("DESCRIPTOR_POOL", vk::ObjectType::eDescriptorPool);
    e_vk_ObjectType.value("DESCRIPTOR_SET", vk::ObjectType::eDescriptorSet);
    e_vk_ObjectType.value("FRAMEBUFFER", vk::ObjectType::eFramebuffer);
    e_vk_ObjectType.value("COMMAND_POOL", vk::ObjectType::eCommandPool);
    e_vk_ObjectType.value("SAMPLER_YCBCR_CONVERSION", vk::ObjectType::eSamplerYcbcrConversion);
    e_vk_ObjectType.value("DESCRIPTOR_UPDATE_TEMPLATE", vk::ObjectType::eDescriptorUpdateTemplate);
    e_vk_ObjectType.value("PRIVATE_DATA_SLOT", vk::ObjectType::ePrivateDataSlot);
    e_vk_ObjectType.value("SURFACE_KHR", vk::ObjectType::eSurfaceKHR);
    e_vk_ObjectType.value("SWAPCHAIN_KHR", vk::ObjectType::eSwapchainKHR);
    e_vk_ObjectType.value("DISPLAY_KHR", vk::ObjectType::eDisplayKHR);
    e_vk_ObjectType.value("DISPLAY_MODE_KHR", vk::ObjectType::eDisplayModeKHR);
    e_vk_ObjectType.value("DEBUG_REPORT_CALLBACK_EXT", vk::ObjectType::eDebugReportCallbackEXT);
    e_vk_ObjectType.value("VIDEO_SESSION_KHR", vk::ObjectType::eVideoSessionKHR);
    e_vk_ObjectType.value("VIDEO_SESSION_PARAMETERS_KHR", vk::ObjectType::eVideoSessionParametersKHR);
    e_vk_ObjectType.value("CU_MODULE_NVX", vk::ObjectType::eCuModuleNVX);
    e_vk_ObjectType.value("CU_FUNCTION_NVX", vk::ObjectType::eCuFunctionNVX);
    e_vk_ObjectType.value("DESCRIPTOR_UPDATE_TEMPLATE_KHR", vk::ObjectType::eDescriptorUpdateTemplateKHR);
    e_vk_ObjectType.value("DEBUG_UTILS_MESSENGER_EXT", vk::ObjectType::eDebugUtilsMessengerEXT);
    e_vk_ObjectType.value("ACCELERATION_STRUCTURE_KHR", vk::ObjectType::eAccelerationStructureKHR);
    e_vk_ObjectType.value("SAMPLER_YCBCR_CONVERSION_KHR", vk::ObjectType::eSamplerYcbcrConversionKHR);
    e_vk_ObjectType.value("VALIDATION_CACHE_EXT", vk::ObjectType::eValidationCacheEXT);
    e_vk_ObjectType.value("ACCELERATION_STRUCTURE_NV", vk::ObjectType::eAccelerationStructureNV);
    e_vk_ObjectType.value("PERFORMANCE_CONFIGURATION_INTEL", vk::ObjectType::ePerformanceConfigurationINTEL);
    e_vk_ObjectType.value("DEFERRED_OPERATION_KHR", vk::ObjectType::eDeferredOperationKHR);
    e_vk_ObjectType.value("INDIRECT_COMMANDS_LAYOUT_NV", vk::ObjectType::eIndirectCommandsLayoutNV);
    e_vk_ObjectType.value("PRIVATE_DATA_SLOT_EXT", vk::ObjectType::ePrivateDataSlotEXT);
    e_vk_ObjectType.value("MICROMAP_EXT", vk::ObjectType::eMicromapEXT);
    e_vk_ObjectType.value("OPTICAL_FLOW_SESSION_NV", vk::ObjectType::eOpticalFlowSessionNV);
    e_vk_ObjectType.value("SHADER_EXT", vk::ObjectType::eShaderEXT);

    py::enum_<vk::PhysicalDeviceType> e_vk_PhysicalDeviceType(m_vk, "PhysicalDeviceType");
    e_vk_PhysicalDeviceType.value("OTHER", vk::PhysicalDeviceType::eOther);
    e_vk_PhysicalDeviceType.value("INTEGRATED_GPU", vk::PhysicalDeviceType::eIntegratedGpu);
    e_vk_PhysicalDeviceType.value("DISCRETE_GPU", vk::PhysicalDeviceType::eDiscreteGpu);
    e_vk_PhysicalDeviceType.value("VIRTUAL_GPU", vk::PhysicalDeviceType::eVirtualGpu);
    e_vk_PhysicalDeviceType.value("CPU", vk::PhysicalDeviceType::eCpu);

    py::enum_<vk::PipelineBindPoint> e_vk_PipelineBindPoint(m_vk, "PipelineBindPoint");
    e_vk_PipelineBindPoint.value("GRAPHICS", vk::PipelineBindPoint::eGraphics);
    e_vk_PipelineBindPoint.value("COMPUTE", vk::PipelineBindPoint::eCompute);
    e_vk_PipelineBindPoint.value("RAY_TRACING_KHR", vk::PipelineBindPoint::eRayTracingKHR);
    e_vk_PipelineBindPoint.value("RAY_TRACING_NV", vk::PipelineBindPoint::eRayTracingNV);
    e_vk_PipelineBindPoint.value("SUBPASS_SHADING_HUAWEI", vk::PipelineBindPoint::eSubpassShadingHUAWEI);

    py::enum_<vk::PipelineCacheCreateFlagBits> e_vk_PipelineCacheCreateFlagBits(m_vk, "PipelineCacheCreateFlagBits");
    e_vk_PipelineCacheCreateFlagBits.value("EXTERNALLY_SYNCHRONIZED", vk::PipelineCacheCreateFlagBits::eExternallySynchronized);
    e_vk_PipelineCacheCreateFlagBits.value("EXTERNALLY_SYNCHRONIZED_EXT", vk::PipelineCacheCreateFlagBits::eExternallySynchronizedEXT);

    py::enum_<vk::PipelineCacheHeaderVersion> e_vk_PipelineCacheHeaderVersion(m_vk, "PipelineCacheHeaderVersion");
    e_vk_PipelineCacheHeaderVersion.value("ONE", vk::PipelineCacheHeaderVersion::eOne);

    py::enum_<vk::PipelineColorBlendStateCreateFlagBits> e_vk_PipelineColorBlendStateCreateFlagBits(m_vk, "PipelineColorBlendStateCreateFlagBits");
    e_vk_PipelineColorBlendStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_ACCESS_ARM", vk::PipelineColorBlendStateCreateFlagBits::eRasterizationOrderAttachmentAccessARM);
    e_vk_PipelineColorBlendStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXT", vk::PipelineColorBlendStateCreateFlagBits::eRasterizationOrderAttachmentAccessEXT);

    py::enum_<vk::PipelineCreateFlagBits> e_vk_PipelineCreateFlagBits(m_vk, "PipelineCreateFlagBits");
    e_vk_PipelineCreateFlagBits.value("DISABLE_OPTIMIZATION", vk::PipelineCreateFlagBits::eDisableOptimization);
    e_vk_PipelineCreateFlagBits.value("ALLOW_DERIVATIVES", vk::PipelineCreateFlagBits::eAllowDerivatives);
    e_vk_PipelineCreateFlagBits.value("DERIVATIVE", vk::PipelineCreateFlagBits::eDerivative);
    e_vk_PipelineCreateFlagBits.value("VIEW_INDEX_FROM_DEVICE_INDEX", vk::PipelineCreateFlagBits::eViewIndexFromDeviceIndex);
    e_vk_PipelineCreateFlagBits.value("DISPATCH_BASE", vk::PipelineCreateFlagBits::eDispatchBase);
    e_vk_PipelineCreateFlagBits.value("FAIL_ON_PIPELINE_COMPILE_REQUIRED", vk::PipelineCreateFlagBits::eFailOnPipelineCompileRequired);
    e_vk_PipelineCreateFlagBits.value("EARLY_RETURN_ON_FAILURE", vk::PipelineCreateFlagBits::eEarlyReturnOnFailure);
    e_vk_PipelineCreateFlagBits.value("RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", vk::PipelineCreateFlagBits::eRenderingFragmentShadingRateAttachmentKHR);
    e_vk_PipelineCreateFlagBits.value("VK_PIPELINE_RASTERIZATION_STATE_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", vk::PipelineCreateFlagBits::eVkPipelineRasterizationStateCreateFragmentShadingRateAttachmentKHR);
    e_vk_PipelineCreateFlagBits.value("RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_EXT", vk::PipelineCreateFlagBits::eRenderingFragmentDensityMapAttachmentEXT);
    e_vk_PipelineCreateFlagBits.value("VK_PIPELINE_RASTERIZATION_STATE_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_EXT", vk::PipelineCreateFlagBits::eVkPipelineRasterizationStateCreateFragmentDensityMapAttachmentEXT);
    e_vk_PipelineCreateFlagBits.value("VIEW_INDEX_FROM_DEVICE_INDEX_KHR", vk::PipelineCreateFlagBits::eViewIndexFromDeviceIndexKHR);
    e_vk_PipelineCreateFlagBits.value("DISPATCH_BASE_KHR", vk::PipelineCreateFlagBits::eDispatchBaseKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_KHR", vk::PipelineCreateFlagBits::eRayTracingNoNullAnyHitShadersKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_KHR", vk::PipelineCreateFlagBits::eRayTracingNoNullClosestHitShadersKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_NO_NULL_MISS_SHADERS_KHR", vk::PipelineCreateFlagBits::eRayTracingNoNullMissShadersKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_KHR", vk::PipelineCreateFlagBits::eRayTracingNoNullIntersectionShadersKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_SKIP_TRIANGLES_KHR", vk::PipelineCreateFlagBits::eRayTracingSkipTrianglesKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_SKIP_AABBS_KHR", vk::PipelineCreateFlagBits::eRayTracingSkipAabbsKHR);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_KHR", vk::PipelineCreateFlagBits::eRayTracingShaderGroupHandleCaptureReplayKHR);
    e_vk_PipelineCreateFlagBits.value("DEFER_COMPILE_NV", vk::PipelineCreateFlagBits::eDeferCompileNV);
    e_vk_PipelineCreateFlagBits.value("CAPTURE_STATISTICS_KHR", vk::PipelineCreateFlagBits::eCaptureStatisticsKHR);
    e_vk_PipelineCreateFlagBits.value("CAPTURE_INTERNAL_REPRESENTATIONS_KHR", vk::PipelineCreateFlagBits::eCaptureInternalRepresentationsKHR);
    e_vk_PipelineCreateFlagBits.value("INDIRECT_BINDABLE_NV", vk::PipelineCreateFlagBits::eIndirectBindableNV);
    e_vk_PipelineCreateFlagBits.value("LIBRARY_KHR", vk::PipelineCreateFlagBits::eLibraryKHR);
    e_vk_PipelineCreateFlagBits.value("FAIL_ON_PIPELINE_COMPILE_REQUIRED_EXT", vk::PipelineCreateFlagBits::eFailOnPipelineCompileRequiredEXT);
    e_vk_PipelineCreateFlagBits.value("EARLY_RETURN_ON_FAILURE_EXT", vk::PipelineCreateFlagBits::eEarlyReturnOnFailureEXT);
    e_vk_PipelineCreateFlagBits.value("DESCRIPTOR_BUFFER_EXT", vk::PipelineCreateFlagBits::eDescriptorBufferEXT);
    e_vk_PipelineCreateFlagBits.value("RETAIN_LINK_TIME_OPTIMIZATION_INFO_EXT", vk::PipelineCreateFlagBits::eRetainLinkTimeOptimizationInfoEXT);
    e_vk_PipelineCreateFlagBits.value("LINK_TIME_OPTIMIZATION_EXT", vk::PipelineCreateFlagBits::eLinkTimeOptimizationEXT);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_ALLOW_MOTION_NV", vk::PipelineCreateFlagBits::eRayTracingAllowMotionNV);
    e_vk_PipelineCreateFlagBits.value("COLOR_ATTACHMENT_FEEDBACK_LOOP_EXT", vk::PipelineCreateFlagBits::eColorAttachmentFeedbackLoopEXT);
    e_vk_PipelineCreateFlagBits.value("DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_EXT", vk::PipelineCreateFlagBits::eDepthStencilAttachmentFeedbackLoopEXT);
    e_vk_PipelineCreateFlagBits.value("RAY_TRACING_OPACITY_MICROMAP_EXT", vk::PipelineCreateFlagBits::eRayTracingOpacityMicromapEXT);
    e_vk_PipelineCreateFlagBits.value("NO_PROTECTED_ACCESS_EXT", vk::PipelineCreateFlagBits::eNoProtectedAccessEXT);
    e_vk_PipelineCreateFlagBits.value("PROTECTED_ACCESS_ONLY_EXT", vk::PipelineCreateFlagBits::eProtectedAccessOnlyEXT);

    py::enum_<vk::PipelineDepthStencilStateCreateFlagBits> e_vk_PipelineDepthStencilStateCreateFlagBits(m_vk, "PipelineDepthStencilStateCreateFlagBits");
    e_vk_PipelineDepthStencilStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_ARM", vk::PipelineDepthStencilStateCreateFlagBits::eRasterizationOrderAttachmentDepthAccessARM);
    e_vk_PipelineDepthStencilStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_ARM", vk::PipelineDepthStencilStateCreateFlagBits::eRasterizationOrderAttachmentStencilAccessARM);
    e_vk_PipelineDepthStencilStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_EXT", vk::PipelineDepthStencilStateCreateFlagBits::eRasterizationOrderAttachmentDepthAccessEXT);
    e_vk_PipelineDepthStencilStateCreateFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_EXT", vk::PipelineDepthStencilStateCreateFlagBits::eRasterizationOrderAttachmentStencilAccessEXT);

    py::enum_<vk::PipelineDynamicStateCreateFlagBits> e_vk_PipelineDynamicStateCreateFlagBits(m_vk, "PipelineDynamicStateCreateFlagBits");

    py::enum_<vk::PipelineInputAssemblyStateCreateFlagBits> e_vk_PipelineInputAssemblyStateCreateFlagBits(m_vk, "PipelineInputAssemblyStateCreateFlagBits");

    py::enum_<vk::PipelineLayoutCreateFlagBits> e_vk_PipelineLayoutCreateFlagBits(m_vk, "PipelineLayoutCreateFlagBits");
    e_vk_PipelineLayoutCreateFlagBits.value("INDEPENDENT_SETS_EXT", vk::PipelineLayoutCreateFlagBits::eIndependentSetsEXT);

    py::enum_<vk::PipelineMultisampleStateCreateFlagBits> e_vk_PipelineMultisampleStateCreateFlagBits(m_vk, "PipelineMultisampleStateCreateFlagBits");

    py::enum_<vk::PipelineRasterizationStateCreateFlagBits> e_vk_PipelineRasterizationStateCreateFlagBits(m_vk, "PipelineRasterizationStateCreateFlagBits");

    py::enum_<vk::PipelineShaderStageCreateFlagBits> e_vk_PipelineShaderStageCreateFlagBits(m_vk, "PipelineShaderStageCreateFlagBits");
    e_vk_PipelineShaderStageCreateFlagBits.value("ALLOW_VARYING_SUBGROUP_SIZE", vk::PipelineShaderStageCreateFlagBits::eAllowVaryingSubgroupSize);
    e_vk_PipelineShaderStageCreateFlagBits.value("REQUIRE_FULL_SUBGROUPS", vk::PipelineShaderStageCreateFlagBits::eRequireFullSubgroups);
    e_vk_PipelineShaderStageCreateFlagBits.value("ALLOW_VARYING_SUBGROUP_SIZE_EXT", vk::PipelineShaderStageCreateFlagBits::eAllowVaryingSubgroupSizeEXT);
    e_vk_PipelineShaderStageCreateFlagBits.value("REQUIRE_FULL_SUBGROUPS_EXT", vk::PipelineShaderStageCreateFlagBits::eRequireFullSubgroupsEXT);

    py::enum_<vk::PipelineStageFlagBits> e_vk_PipelineStageFlagBits(m_vk, "PipelineStageFlagBits");
    e_vk_PipelineStageFlagBits.value("TOP_OF_PIPE", vk::PipelineStageFlagBits::eTopOfPipe);
    e_vk_PipelineStageFlagBits.value("DRAW_INDIRECT", vk::PipelineStageFlagBits::eDrawIndirect);
    e_vk_PipelineStageFlagBits.value("VERTEX_INPUT", vk::PipelineStageFlagBits::eVertexInput);
    e_vk_PipelineStageFlagBits.value("VERTEX_SHADER", vk::PipelineStageFlagBits::eVertexShader);
    e_vk_PipelineStageFlagBits.value("TESSELLATION_CONTROL_SHADER", vk::PipelineStageFlagBits::eTessellationControlShader);
    e_vk_PipelineStageFlagBits.value("TESSELLATION_EVALUATION_SHADER", vk::PipelineStageFlagBits::eTessellationEvaluationShader);
    e_vk_PipelineStageFlagBits.value("GEOMETRY_SHADER", vk::PipelineStageFlagBits::eGeometryShader);
    e_vk_PipelineStageFlagBits.value("FRAGMENT_SHADER", vk::PipelineStageFlagBits::eFragmentShader);
    e_vk_PipelineStageFlagBits.value("EARLY_FRAGMENT_TESTS", vk::PipelineStageFlagBits::eEarlyFragmentTests);
    e_vk_PipelineStageFlagBits.value("LATE_FRAGMENT_TESTS", vk::PipelineStageFlagBits::eLateFragmentTests);
    e_vk_PipelineStageFlagBits.value("COLOR_ATTACHMENT_OUTPUT", vk::PipelineStageFlagBits::eColorAttachmentOutput);
    e_vk_PipelineStageFlagBits.value("COMPUTE_SHADER", vk::PipelineStageFlagBits::eComputeShader);
    e_vk_PipelineStageFlagBits.value("TRANSFER", vk::PipelineStageFlagBits::eTransfer);
    e_vk_PipelineStageFlagBits.value("BOTTOM_OF_PIPE", vk::PipelineStageFlagBits::eBottomOfPipe);
    e_vk_PipelineStageFlagBits.value("HOST", vk::PipelineStageFlagBits::eHost);
    e_vk_PipelineStageFlagBits.value("ALL_GRAPHICS", vk::PipelineStageFlagBits::eAllGraphics);
    e_vk_PipelineStageFlagBits.value("ALL_COMMANDS", vk::PipelineStageFlagBits::eAllCommands);
    e_vk_PipelineStageFlagBits.value("NONE", vk::PipelineStageFlagBits::eNone);
    e_vk_PipelineStageFlagBits.value("TRANSFORM_FEEDBACK_EXT", vk::PipelineStageFlagBits::eTransformFeedbackEXT);
    e_vk_PipelineStageFlagBits.value("CONDITIONAL_RENDERING_EXT", vk::PipelineStageFlagBits::eConditionalRenderingEXT);
    e_vk_PipelineStageFlagBits.value("ACCELERATION_STRUCTURE_BUILD_KHR", vk::PipelineStageFlagBits::eAccelerationStructureBuildKHR);
    e_vk_PipelineStageFlagBits.value("RAY_TRACING_SHADER_KHR", vk::PipelineStageFlagBits::eRayTracingShaderKHR);
    e_vk_PipelineStageFlagBits.value("SHADING_RATE_IMAGE_NV", vk::PipelineStageFlagBits::eShadingRateImageNV);
    e_vk_PipelineStageFlagBits.value("RAY_TRACING_SHADER_NV", vk::PipelineStageFlagBits::eRayTracingShaderNV);
    e_vk_PipelineStageFlagBits.value("ACCELERATION_STRUCTURE_BUILD_NV", vk::PipelineStageFlagBits::eAccelerationStructureBuildNV);
    e_vk_PipelineStageFlagBits.value("TASK_SHADER_NV", vk::PipelineStageFlagBits::eTaskShaderNV);
    e_vk_PipelineStageFlagBits.value("MESH_SHADER_NV", vk::PipelineStageFlagBits::eMeshShaderNV);
    e_vk_PipelineStageFlagBits.value("FRAGMENT_DENSITY_PROCESS_EXT", vk::PipelineStageFlagBits::eFragmentDensityProcessEXT);
    e_vk_PipelineStageFlagBits.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", vk::PipelineStageFlagBits::eFragmentShadingRateAttachmentKHR);
    e_vk_PipelineStageFlagBits.value("COMMAND_PREPROCESS_NV", vk::PipelineStageFlagBits::eCommandPreprocessNV);
    e_vk_PipelineStageFlagBits.value("NONE_KHR", vk::PipelineStageFlagBits::eNoneKHR);
    e_vk_PipelineStageFlagBits.value("TASK_SHADER_EXT", vk::PipelineStageFlagBits::eTaskShaderEXT);
    e_vk_PipelineStageFlagBits.value("MESH_SHADER_EXT", vk::PipelineStageFlagBits::eMeshShaderEXT);

    py::enum_<vk::PipelineTessellationStateCreateFlagBits> e_vk_PipelineTessellationStateCreateFlagBits(m_vk, "PipelineTessellationStateCreateFlagBits");

    py::enum_<vk::PipelineVertexInputStateCreateFlagBits> e_vk_PipelineVertexInputStateCreateFlagBits(m_vk, "PipelineVertexInputStateCreateFlagBits");

    py::enum_<vk::PipelineViewportStateCreateFlagBits> e_vk_PipelineViewportStateCreateFlagBits(m_vk, "PipelineViewportStateCreateFlagBits");

    py::enum_<vk::PolygonMode> e_vk_PolygonMode(m_vk, "PolygonMode");
    e_vk_PolygonMode.value("FILL", vk::PolygonMode::eFill);
    e_vk_PolygonMode.value("LINE", vk::PolygonMode::eLine);
    e_vk_PolygonMode.value("POINT", vk::PolygonMode::ePoint);
    e_vk_PolygonMode.value("FILL_RECTANGLE_NV", vk::PolygonMode::eFillRectangleNV);

    py::enum_<vk::PrimitiveTopology> e_vk_PrimitiveTopology(m_vk, "PrimitiveTopology");
    e_vk_PrimitiveTopology.value("POINT_LIST", vk::PrimitiveTopology::ePointList);
    e_vk_PrimitiveTopology.value("LINE_LIST", vk::PrimitiveTopology::eLineList);
    e_vk_PrimitiveTopology.value("LINE_STRIP", vk::PrimitiveTopology::eLineStrip);
    e_vk_PrimitiveTopology.value("TRIANGLE_LIST", vk::PrimitiveTopology::eTriangleList);
    e_vk_PrimitiveTopology.value("TRIANGLE_STRIP", vk::PrimitiveTopology::eTriangleStrip);
    e_vk_PrimitiveTopology.value("TRIANGLE_FAN", vk::PrimitiveTopology::eTriangleFan);
    e_vk_PrimitiveTopology.value("LINE_LIST_WITH_ADJACENCY", vk::PrimitiveTopology::eLineListWithAdjacency);
    e_vk_PrimitiveTopology.value("LINE_STRIP_WITH_ADJACENCY", vk::PrimitiveTopology::eLineStripWithAdjacency);
    e_vk_PrimitiveTopology.value("TRIANGLE_LIST_WITH_ADJACENCY", vk::PrimitiveTopology::eTriangleListWithAdjacency);
    e_vk_PrimitiveTopology.value("TRIANGLE_STRIP_WITH_ADJACENCY", vk::PrimitiveTopology::eTriangleStripWithAdjacency);
    e_vk_PrimitiveTopology.value("PATCH_LIST", vk::PrimitiveTopology::ePatchList);

    py::enum_<vk::QueryControlFlagBits> e_vk_QueryControlFlagBits(m_vk, "QueryControlFlagBits");
    e_vk_QueryControlFlagBits.value("PRECISE", vk::QueryControlFlagBits::ePrecise);

    py::enum_<vk::QueryPipelineStatisticFlagBits> e_vk_QueryPipelineStatisticFlagBits(m_vk, "QueryPipelineStatisticFlagBits");
    e_vk_QueryPipelineStatisticFlagBits.value("INPUT_ASSEMBLY_VERTICES", vk::QueryPipelineStatisticFlagBits::eInputAssemblyVertices);
    e_vk_QueryPipelineStatisticFlagBits.value("INPUT_ASSEMBLY_PRIMITIVES", vk::QueryPipelineStatisticFlagBits::eInputAssemblyPrimitives);
    e_vk_QueryPipelineStatisticFlagBits.value("VERTEX_SHADER_INVOCATIONS", vk::QueryPipelineStatisticFlagBits::eVertexShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("GEOMETRY_SHADER_INVOCATIONS", vk::QueryPipelineStatisticFlagBits::eGeometryShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("GEOMETRY_SHADER_PRIMITIVES", vk::QueryPipelineStatisticFlagBits::eGeometryShaderPrimitives);
    e_vk_QueryPipelineStatisticFlagBits.value("CLIPPING_INVOCATIONS", vk::QueryPipelineStatisticFlagBits::eClippingInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("CLIPPING_PRIMITIVES", vk::QueryPipelineStatisticFlagBits::eClippingPrimitives);
    e_vk_QueryPipelineStatisticFlagBits.value("FRAGMENT_SHADER_INVOCATIONS", vk::QueryPipelineStatisticFlagBits::eFragmentShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("TESSELLATION_CONTROL_SHADER_PATCHES", vk::QueryPipelineStatisticFlagBits::eTessellationControlShaderPatches);
    e_vk_QueryPipelineStatisticFlagBits.value("TESSELLATION_EVALUATION_SHADER_INVOCATIONS", vk::QueryPipelineStatisticFlagBits::eTessellationEvaluationShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("COMPUTE_SHADER_INVOCATIONS", vk::QueryPipelineStatisticFlagBits::eComputeShaderInvocations);
    e_vk_QueryPipelineStatisticFlagBits.value("TASK_SHADER_INVOCATIONS_EXT", vk::QueryPipelineStatisticFlagBits::eTaskShaderInvocationsEXT);
    e_vk_QueryPipelineStatisticFlagBits.value("MESH_SHADER_INVOCATIONS_EXT", vk::QueryPipelineStatisticFlagBits::eMeshShaderInvocationsEXT);
    e_vk_QueryPipelineStatisticFlagBits.value("CLUSTER_CULLING_SHADER_INVOCATIONS_HUAWEI", vk::QueryPipelineStatisticFlagBits::eClusterCullingShaderInvocationsHUAWEI);

    py::enum_<vk::QueryPoolCreateFlagBits> e_vk_QueryPoolCreateFlagBits(m_vk, "QueryPoolCreateFlagBits");

    py::enum_<vk::QueryResultFlagBits> e_vk_QueryResultFlagBits(m_vk, "QueryResultFlagBits");
    e_vk_QueryResultFlagBits.value("_64", vk::QueryResultFlagBits::e64);
    e_vk_QueryResultFlagBits.value("WAIT", vk::QueryResultFlagBits::eWait);
    e_vk_QueryResultFlagBits.value("WITH_AVAILABILITY", vk::QueryResultFlagBits::eWithAvailability);
    e_vk_QueryResultFlagBits.value("PARTIAL", vk::QueryResultFlagBits::ePartial);
    e_vk_QueryResultFlagBits.value("WITH_STATUS_KHR", vk::QueryResultFlagBits::eWithStatusKHR);

    py::enum_<vk::QueryType> e_vk_QueryType(m_vk, "QueryType");
    e_vk_QueryType.value("OCCLUSION", vk::QueryType::eOcclusion);
    e_vk_QueryType.value("PIPELINE_STATISTICS", vk::QueryType::ePipelineStatistics);
    e_vk_QueryType.value("TIMESTAMP", vk::QueryType::eTimestamp);
    e_vk_QueryType.value("RESULT_STATUS_ONLY_KHR", vk::QueryType::eResultStatusOnlyKHR);
    e_vk_QueryType.value("TRANSFORM_FEEDBACK_STREAM_EXT", vk::QueryType::eTransformFeedbackStreamEXT);
    e_vk_QueryType.value("PERFORMANCE_QUERY_KHR", vk::QueryType::ePerformanceQueryKHR);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR", vk::QueryType::eAccelerationStructureCompactedSizeKHR);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR", vk::QueryType::eAccelerationStructureSerializationSizeKHR);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV", vk::QueryType::eAccelerationStructureCompactedSizeNV);
    e_vk_QueryType.value("PERFORMANCE_QUERY_INTEL", vk::QueryType::ePerformanceQueryINTEL);
    e_vk_QueryType.value("VIDEO_ENCODE_FEEDBACK_KHR", vk::QueryType::eVideoEncodeFeedbackKHR);
    e_vk_QueryType.value("MESH_PRIMITIVES_GENERATED_EXT", vk::QueryType::eMeshPrimitivesGeneratedEXT);
    e_vk_QueryType.value("PRIMITIVES_GENERATED_EXT", vk::QueryType::ePrimitivesGeneratedEXT);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_SERIALIZATION_BOTTOM_LEVEL_POINTERS_KHR", vk::QueryType::eAccelerationStructureSerializationBottomLevelPointersKHR);
    e_vk_QueryType.value("ACCELERATION_STRUCTURE_SIZE_KHR", vk::QueryType::eAccelerationStructureSizeKHR);
    e_vk_QueryType.value("MICROMAP_SERIALIZATION_SIZE_EXT", vk::QueryType::eMicromapSerializationSizeEXT);
    e_vk_QueryType.value("MICROMAP_COMPACTED_SIZE_EXT", vk::QueryType::eMicromapCompactedSizeEXT);

    py::enum_<vk::QueueFlagBits> e_vk_QueueFlagBits(m_vk, "QueueFlagBits");
    e_vk_QueueFlagBits.value("GRAPHICS", vk::QueueFlagBits::eGraphics);
    e_vk_QueueFlagBits.value("COMPUTE", vk::QueueFlagBits::eCompute);
    e_vk_QueueFlagBits.value("TRANSFER", vk::QueueFlagBits::eTransfer);
    e_vk_QueueFlagBits.value("SPARSE_BINDING", vk::QueueFlagBits::eSparseBinding);
    e_vk_QueueFlagBits.value("PROTECTED", vk::QueueFlagBits::eProtected);
    e_vk_QueueFlagBits.value("VIDEO_DECODE_KHR", vk::QueueFlagBits::eVideoDecodeKHR);
    e_vk_QueueFlagBits.value("VIDEO_ENCODE_KHR", vk::QueueFlagBits::eVideoEncodeKHR);
    e_vk_QueueFlagBits.value("OPTICAL_FLOW_NV", vk::QueueFlagBits::eOpticalFlowNV);

    py::enum_<vk::RenderPassCreateFlagBits> e_vk_RenderPassCreateFlagBits(m_vk, "RenderPassCreateFlagBits");
    e_vk_RenderPassCreateFlagBits.value("TRANSFORM_QCOM", vk::RenderPassCreateFlagBits::eTransformQCOM);

    py::enum_<vk::Result> e_vk_Result(m_vk, "Result");
    e_vk_Result.value("SUCCESS", vk::Result::eSuccess);
    e_vk_Result.value("NOT_READY", vk::Result::eNotReady);
    e_vk_Result.value("TIMEOUT", vk::Result::eTimeout);
    e_vk_Result.value("EVENT_SET", vk::Result::eEventSet);
    e_vk_Result.value("EVENT_RESET", vk::Result::eEventReset);
    e_vk_Result.value("INCOMPLETE", vk::Result::eIncomplete);
    e_vk_Result.value("ERROR_OUT_OF_HOST_MEMORY", vk::Result::eErrorOutOfHostMemory);
    e_vk_Result.value("ERROR_OUT_OF_DEVICE_MEMORY", vk::Result::eErrorOutOfDeviceMemory);
    e_vk_Result.value("ERROR_INITIALIZATION_FAILED", vk::Result::eErrorInitializationFailed);
    e_vk_Result.value("ERROR_DEVICE_LOST", vk::Result::eErrorDeviceLost);
    e_vk_Result.value("ERROR_MEMORY_MAP_FAILED", vk::Result::eErrorMemoryMapFailed);
    e_vk_Result.value("ERROR_LAYER_NOT_PRESENT", vk::Result::eErrorLayerNotPresent);
    e_vk_Result.value("ERROR_EXTENSION_NOT_PRESENT", vk::Result::eErrorExtensionNotPresent);
    e_vk_Result.value("ERROR_FEATURE_NOT_PRESENT", vk::Result::eErrorFeatureNotPresent);
    e_vk_Result.value("ERROR_INCOMPATIBLE_DRIVER", vk::Result::eErrorIncompatibleDriver);
    e_vk_Result.value("ERROR_TOO_MANY_OBJECTS", vk::Result::eErrorTooManyObjects);
    e_vk_Result.value("ERROR_FORMAT_NOT_SUPPORTED", vk::Result::eErrorFormatNotSupported);
    e_vk_Result.value("ERROR_FRAGMENTED_POOL", vk::Result::eErrorFragmentedPool);
    e_vk_Result.value("ERROR_UNKNOWN", vk::Result::eErrorUnknown);
    e_vk_Result.value("ERROR_OUT_OF_POOL_MEMORY", vk::Result::eErrorOutOfPoolMemory);
    e_vk_Result.value("ERROR_INVALID_EXTERNAL_HANDLE", vk::Result::eErrorInvalidExternalHandle);
    e_vk_Result.value("ERROR_FRAGMENTATION", vk::Result::eErrorFragmentation);
    e_vk_Result.value("ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS", vk::Result::eErrorInvalidOpaqueCaptureAddress);
    e_vk_Result.value("PIPELINE_COMPILE_REQUIRED", vk::Result::ePipelineCompileRequired);
    e_vk_Result.value("ERROR_SURFACE_LOST_KHR", vk::Result::eErrorSurfaceLostKHR);
    e_vk_Result.value("ERROR_NATIVE_WINDOW_IN_USE_KHR", vk::Result::eErrorNativeWindowInUseKHR);
    e_vk_Result.value("SUBOPTIMAL_KHR", vk::Result::eSuboptimalKHR);
    e_vk_Result.value("ERROR_OUT_OF_DATE_KHR", vk::Result::eErrorOutOfDateKHR);
    e_vk_Result.value("ERROR_INCOMPATIBLE_DISPLAY_KHR", vk::Result::eErrorIncompatibleDisplayKHR);
    e_vk_Result.value("ERROR_VALIDATION_FAILED_EXT", vk::Result::eErrorValidationFailedEXT);
    e_vk_Result.value("ERROR_INVALID_SHADER_NV", vk::Result::eErrorInvalidShaderNV);
    e_vk_Result.value("ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR", vk::Result::eErrorImageUsageNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR", vk::Result::eErrorVideoPictureLayoutNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR", vk::Result::eErrorVideoProfileOperationNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR", vk::Result::eErrorVideoProfileFormatNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR", vk::Result::eErrorVideoProfileCodecNotSupportedKHR);
    e_vk_Result.value("ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR", vk::Result::eErrorVideoStdVersionNotSupportedKHR);
    e_vk_Result.value("ERROR_OUT_OF_POOL_MEMORY_KHR", vk::Result::eErrorOutOfPoolMemoryKHR);
    e_vk_Result.value("ERROR_INVALID_EXTERNAL_HANDLE_KHR", vk::Result::eErrorInvalidExternalHandleKHR);
    e_vk_Result.value("ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT", vk::Result::eErrorInvalidDrmFormatModifierPlaneLayoutEXT);
    e_vk_Result.value("ERROR_FRAGMENTATION_EXT", vk::Result::eErrorFragmentationEXT);
    e_vk_Result.value("ERROR_NOT_PERMITTED_EXT", vk::Result::eErrorNotPermittedEXT);
    e_vk_Result.value("ERROR_NOT_PERMITTED_KHR", vk::Result::eErrorNotPermittedKHR);
    e_vk_Result.value("ERROR_INVALID_DEVICE_ADDRESS_EXT", vk::Result::eErrorInvalidDeviceAddressEXT);
    e_vk_Result.value("ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR", vk::Result::eErrorInvalidOpaqueCaptureAddressKHR);
    e_vk_Result.value("THREAD_IDLE_KHR", vk::Result::eThreadIdleKHR);
    e_vk_Result.value("THREAD_DONE_KHR", vk::Result::eThreadDoneKHR);
    e_vk_Result.value("OPERATION_DEFERRED_KHR", vk::Result::eOperationDeferredKHR);
    e_vk_Result.value("OPERATION_NOT_DEFERRED_KHR", vk::Result::eOperationNotDeferredKHR);
    e_vk_Result.value("PIPELINE_COMPILE_REQUIRED_EXT", vk::Result::ePipelineCompileRequiredEXT);
    e_vk_Result.value("ERROR_PIPELINE_COMPILE_REQUIRED_EXT", vk::Result::eErrorPipelineCompileRequiredEXT);
    e_vk_Result.value("ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR", vk::Result::eErrorInvalidVideoStdParametersKHR);
    e_vk_Result.value("ERROR_COMPRESSION_EXHAUSTED_EXT", vk::Result::eErrorCompressionExhaustedEXT);
    e_vk_Result.value("ERROR_INCOMPATIBLE_SHADER_BINARY_EXT", vk::Result::eErrorIncompatibleShaderBinaryEXT);

    py::enum_<vk::SampleCountFlagBits> e_vk_SampleCountFlagBits(m_vk, "SampleCountFlagBits");
    e_vk_SampleCountFlagBits.value("_1", vk::SampleCountFlagBits::e1);
    e_vk_SampleCountFlagBits.value("_2", vk::SampleCountFlagBits::e2);
    e_vk_SampleCountFlagBits.value("_4", vk::SampleCountFlagBits::e4);
    e_vk_SampleCountFlagBits.value("_8", vk::SampleCountFlagBits::e8);
    e_vk_SampleCountFlagBits.value("_16", vk::SampleCountFlagBits::e16);
    e_vk_SampleCountFlagBits.value("_32", vk::SampleCountFlagBits::e32);
    e_vk_SampleCountFlagBits.value("_64", vk::SampleCountFlagBits::e64);

    py::enum_<vk::SamplerAddressMode> e_vk_SamplerAddressMode(m_vk, "SamplerAddressMode");
    e_vk_SamplerAddressMode.value("REPEAT", vk::SamplerAddressMode::eRepeat);
    e_vk_SamplerAddressMode.value("MIRRORED_REPEAT", vk::SamplerAddressMode::eMirroredRepeat);
    e_vk_SamplerAddressMode.value("CLAMP_TO_EDGE", vk::SamplerAddressMode::eClampToEdge);
    e_vk_SamplerAddressMode.value("CLAMP_TO_BORDER", vk::SamplerAddressMode::eClampToBorder);
    e_vk_SamplerAddressMode.value("MIRROR_CLAMP_TO_EDGE", vk::SamplerAddressMode::eMirrorClampToEdge);
    e_vk_SamplerAddressMode.value("MIRROR_CLAMP_TO_EDGE_KHR", vk::SamplerAddressMode::eMirrorClampToEdgeKHR);

    py::enum_<vk::SamplerCreateFlagBits> e_vk_SamplerCreateFlagBits(m_vk, "SamplerCreateFlagBits");
    e_vk_SamplerCreateFlagBits.value("SUBSAMPLED_EXT", vk::SamplerCreateFlagBits::eSubsampledEXT);
    e_vk_SamplerCreateFlagBits.value("SUBSAMPLED_COARSE_RECONSTRUCTION_EXT", vk::SamplerCreateFlagBits::eSubsampledCoarseReconstructionEXT);
    e_vk_SamplerCreateFlagBits.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", vk::SamplerCreateFlagBits::eDescriptorBufferCaptureReplayEXT);
    e_vk_SamplerCreateFlagBits.value("NON_SEAMLESS_CUBE_MAP_EXT", vk::SamplerCreateFlagBits::eNonSeamlessCubeMapEXT);
    e_vk_SamplerCreateFlagBits.value("IMAGE_PROCESSING_QCOM", vk::SamplerCreateFlagBits::eImageProcessingQCOM);

    py::enum_<vk::SamplerMipmapMode> e_vk_SamplerMipmapMode(m_vk, "SamplerMipmapMode");
    e_vk_SamplerMipmapMode.value("NEAREST", vk::SamplerMipmapMode::eNearest);
    e_vk_SamplerMipmapMode.value("LINEAR", vk::SamplerMipmapMode::eLinear);

    py::enum_<vk::SemaphoreCreateFlagBits> e_vk_SemaphoreCreateFlagBits(m_vk, "SemaphoreCreateFlagBits");

    py::enum_<vk::ShaderModuleCreateFlagBits> e_vk_ShaderModuleCreateFlagBits(m_vk, "ShaderModuleCreateFlagBits");

    py::enum_<vk::ShaderStageFlagBits> e_vk_ShaderStageFlagBits(m_vk, "ShaderStageFlagBits");
    e_vk_ShaderStageFlagBits.value("VERTEX", vk::ShaderStageFlagBits::eVertex);
    e_vk_ShaderStageFlagBits.value("TESSELLATION_CONTROL", vk::ShaderStageFlagBits::eTessellationControl);
    e_vk_ShaderStageFlagBits.value("TESSELLATION_EVALUATION", vk::ShaderStageFlagBits::eTessellationEvaluation);
    e_vk_ShaderStageFlagBits.value("GEOMETRY", vk::ShaderStageFlagBits::eGeometry);
    e_vk_ShaderStageFlagBits.value("FRAGMENT", vk::ShaderStageFlagBits::eFragment);
    e_vk_ShaderStageFlagBits.value("COMPUTE", vk::ShaderStageFlagBits::eCompute);
    e_vk_ShaderStageFlagBits.value("ALL_GRAPHICS", vk::ShaderStageFlagBits::eAllGraphics);
    e_vk_ShaderStageFlagBits.value("ALL", vk::ShaderStageFlagBits::eAll);
    e_vk_ShaderStageFlagBits.value("RAYGEN_KHR", vk::ShaderStageFlagBits::eRaygenKHR);
    e_vk_ShaderStageFlagBits.value("ANY_HIT_KHR", vk::ShaderStageFlagBits::eAnyHitKHR);
    e_vk_ShaderStageFlagBits.value("CLOSEST_HIT_KHR", vk::ShaderStageFlagBits::eClosestHitKHR);
    e_vk_ShaderStageFlagBits.value("MISS_KHR", vk::ShaderStageFlagBits::eMissKHR);
    e_vk_ShaderStageFlagBits.value("INTERSECTION_KHR", vk::ShaderStageFlagBits::eIntersectionKHR);
    e_vk_ShaderStageFlagBits.value("CALLABLE_KHR", vk::ShaderStageFlagBits::eCallableKHR);
    e_vk_ShaderStageFlagBits.value("RAYGEN_NV", vk::ShaderStageFlagBits::eRaygenNV);
    e_vk_ShaderStageFlagBits.value("ANY_HIT_NV", vk::ShaderStageFlagBits::eAnyHitNV);
    e_vk_ShaderStageFlagBits.value("CLOSEST_HIT_NV", vk::ShaderStageFlagBits::eClosestHitNV);
    e_vk_ShaderStageFlagBits.value("MISS_NV", vk::ShaderStageFlagBits::eMissNV);
    e_vk_ShaderStageFlagBits.value("INTERSECTION_NV", vk::ShaderStageFlagBits::eIntersectionNV);
    e_vk_ShaderStageFlagBits.value("CALLABLE_NV", vk::ShaderStageFlagBits::eCallableNV);
    e_vk_ShaderStageFlagBits.value("TASK_NV", vk::ShaderStageFlagBits::eTaskNV);
    e_vk_ShaderStageFlagBits.value("MESH_NV", vk::ShaderStageFlagBits::eMeshNV);
    e_vk_ShaderStageFlagBits.value("TASK_EXT", vk::ShaderStageFlagBits::eTaskEXT);
    e_vk_ShaderStageFlagBits.value("MESH_EXT", vk::ShaderStageFlagBits::eMeshEXT);
    e_vk_ShaderStageFlagBits.value("SUBPASS_SHADING_HUAWEI", vk::ShaderStageFlagBits::eSubpassShadingHUAWEI);
    e_vk_ShaderStageFlagBits.value("CLUSTER_CULLING_HUAWEI", vk::ShaderStageFlagBits::eClusterCullingHUAWEI);

    py::enum_<vk::SharingMode> e_vk_SharingMode(m_vk, "SharingMode");
    e_vk_SharingMode.value("EXCLUSIVE", vk::SharingMode::eExclusive);
    e_vk_SharingMode.value("CONCURRENT", vk::SharingMode::eConcurrent);

    py::enum_<vk::SparseImageFormatFlagBits> e_vk_SparseImageFormatFlagBits(m_vk, "SparseImageFormatFlagBits");
    e_vk_SparseImageFormatFlagBits.value("SINGLE_MIPTAIL", vk::SparseImageFormatFlagBits::eSingleMiptail);
    e_vk_SparseImageFormatFlagBits.value("ALIGNED_MIP_SIZE", vk::SparseImageFormatFlagBits::eAlignedMipSize);
    e_vk_SparseImageFormatFlagBits.value("NONSTANDARD_BLOCK_SIZE", vk::SparseImageFormatFlagBits::eNonstandardBlockSize);

    py::enum_<vk::SparseMemoryBindFlagBits> e_vk_SparseMemoryBindFlagBits(m_vk, "SparseMemoryBindFlagBits");
    e_vk_SparseMemoryBindFlagBits.value("METADATA", vk::SparseMemoryBindFlagBits::eMetadata);

    py::enum_<vk::StencilFaceFlagBits> e_vk_StencilFaceFlagBits(m_vk, "StencilFaceFlagBits");
    e_vk_StencilFaceFlagBits.value("FRONT", vk::StencilFaceFlagBits::eFront);
    e_vk_StencilFaceFlagBits.value("BACK", vk::StencilFaceFlagBits::eBack);
    e_vk_StencilFaceFlagBits.value("FRONT_AND_BACK", vk::StencilFaceFlagBits::eFrontAndBack);
    e_vk_StencilFaceFlagBits.value("VK_STENCIL_FRONT_AND_BACK", vk::StencilFaceFlagBits::eVkStencilFrontAndBack);

    py::enum_<vk::StencilOp> e_vk_StencilOp(m_vk, "StencilOp");
    e_vk_StencilOp.value("KEEP", vk::StencilOp::eKeep);
    e_vk_StencilOp.value("ZERO", vk::StencilOp::eZero);
    e_vk_StencilOp.value("REPLACE", vk::StencilOp::eReplace);
    e_vk_StencilOp.value("INCREMENT_AND_CLAMP", vk::StencilOp::eIncrementAndClamp);
    e_vk_StencilOp.value("DECREMENT_AND_CLAMP", vk::StencilOp::eDecrementAndClamp);
    e_vk_StencilOp.value("INVERT", vk::StencilOp::eInvert);
    e_vk_StencilOp.value("INCREMENT_AND_WRAP", vk::StencilOp::eIncrementAndWrap);
    e_vk_StencilOp.value("DECREMENT_AND_WRAP", vk::StencilOp::eDecrementAndWrap);

    py::enum_<vk::StructureType> e_vk_StructureType(m_vk, "StructureType");
    e_vk_StructureType.value("APPLICATION_INFO", vk::StructureType::eApplicationInfo);
    e_vk_StructureType.value("INSTANCE_CREATE_INFO", vk::StructureType::eInstanceCreateInfo);
    e_vk_StructureType.value("DEVICE_QUEUE_CREATE_INFO", vk::StructureType::eDeviceQueueCreateInfo);
    e_vk_StructureType.value("DEVICE_CREATE_INFO", vk::StructureType::eDeviceCreateInfo);
    e_vk_StructureType.value("SUBMIT_INFO", vk::StructureType::eSubmitInfo);
    e_vk_StructureType.value("MEMORY_ALLOCATE_INFO", vk::StructureType::eMemoryAllocateInfo);
    e_vk_StructureType.value("MAPPED_MEMORY_RANGE", vk::StructureType::eMappedMemoryRange);
    e_vk_StructureType.value("BIND_SPARSE_INFO", vk::StructureType::eBindSparseInfo);
    e_vk_StructureType.value("FENCE_CREATE_INFO", vk::StructureType::eFenceCreateInfo);
    e_vk_StructureType.value("SEMAPHORE_CREATE_INFO", vk::StructureType::eSemaphoreCreateInfo);
    e_vk_StructureType.value("EVENT_CREATE_INFO", vk::StructureType::eEventCreateInfo);
    e_vk_StructureType.value("QUERY_POOL_CREATE_INFO", vk::StructureType::eQueryPoolCreateInfo);
    e_vk_StructureType.value("BUFFER_CREATE_INFO", vk::StructureType::eBufferCreateInfo);
    e_vk_StructureType.value("BUFFER_VIEW_CREATE_INFO", vk::StructureType::eBufferViewCreateInfo);
    e_vk_StructureType.value("IMAGE_CREATE_INFO", vk::StructureType::eImageCreateInfo);
    e_vk_StructureType.value("IMAGE_VIEW_CREATE_INFO", vk::StructureType::eImageViewCreateInfo);
    e_vk_StructureType.value("SHADER_MODULE_CREATE_INFO", vk::StructureType::eShaderModuleCreateInfo);
    e_vk_StructureType.value("PIPELINE_CACHE_CREATE_INFO", vk::StructureType::ePipelineCacheCreateInfo);
    e_vk_StructureType.value("PIPELINE_SHADER_STAGE_CREATE_INFO", vk::StructureType::ePipelineShaderStageCreateInfo);
    e_vk_StructureType.value("PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO", vk::StructureType::ePipelineVertexInputStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO", vk::StructureType::ePipelineInputAssemblyStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_TESSELLATION_STATE_CREATE_INFO", vk::StructureType::ePipelineTessellationStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_STATE_CREATE_INFO", vk::StructureType::ePipelineViewportStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_STATE_CREATE_INFO", vk::StructureType::ePipelineRasterizationStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_MULTISAMPLE_STATE_CREATE_INFO", vk::StructureType::ePipelineMultisampleStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO", vk::StructureType::ePipelineDepthStencilStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_COLOR_BLEND_STATE_CREATE_INFO", vk::StructureType::ePipelineColorBlendStateCreateInfo);
    e_vk_StructureType.value("PIPELINE_DYNAMIC_STATE_CREATE_INFO", vk::StructureType::ePipelineDynamicStateCreateInfo);
    e_vk_StructureType.value("GRAPHICS_PIPELINE_CREATE_INFO", vk::StructureType::eGraphicsPipelineCreateInfo);
    e_vk_StructureType.value("COMPUTE_PIPELINE_CREATE_INFO", vk::StructureType::eComputePipelineCreateInfo);
    e_vk_StructureType.value("PIPELINE_LAYOUT_CREATE_INFO", vk::StructureType::ePipelineLayoutCreateInfo);
    e_vk_StructureType.value("SAMPLER_CREATE_INFO", vk::StructureType::eSamplerCreateInfo);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_CREATE_INFO", vk::StructureType::eDescriptorSetLayoutCreateInfo);
    e_vk_StructureType.value("DESCRIPTOR_POOL_CREATE_INFO", vk::StructureType::eDescriptorPoolCreateInfo);
    e_vk_StructureType.value("DESCRIPTOR_SET_ALLOCATE_INFO", vk::StructureType::eDescriptorSetAllocateInfo);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET", vk::StructureType::eWriteDescriptorSet);
    e_vk_StructureType.value("COPY_DESCRIPTOR_SET", vk::StructureType::eCopyDescriptorSet);
    e_vk_StructureType.value("FRAMEBUFFER_CREATE_INFO", vk::StructureType::eFramebufferCreateInfo);
    e_vk_StructureType.value("RENDER_PASS_CREATE_INFO", vk::StructureType::eRenderPassCreateInfo);
    e_vk_StructureType.value("COMMAND_POOL_CREATE_INFO", vk::StructureType::eCommandPoolCreateInfo);
    e_vk_StructureType.value("COMMAND_BUFFER_ALLOCATE_INFO", vk::StructureType::eCommandBufferAllocateInfo);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_INFO", vk::StructureType::eCommandBufferInheritanceInfo);
    e_vk_StructureType.value("COMMAND_BUFFER_BEGIN_INFO", vk::StructureType::eCommandBufferBeginInfo);
    e_vk_StructureType.value("RENDER_PASS_BEGIN_INFO", vk::StructureType::eRenderPassBeginInfo);
    e_vk_StructureType.value("BUFFER_MEMORY_BARRIER", vk::StructureType::eBufferMemoryBarrier);
    e_vk_StructureType.value("IMAGE_MEMORY_BARRIER", vk::StructureType::eImageMemoryBarrier);
    e_vk_StructureType.value("MEMORY_BARRIER", vk::StructureType::eMemoryBarrier);
    e_vk_StructureType.value("LOADER_INSTANCE_CREATE_INFO", vk::StructureType::eLoaderInstanceCreateInfo);
    e_vk_StructureType.value("LOADER_DEVICE_CREATE_INFO", vk::StructureType::eLoaderDeviceCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_PROPERTIES", vk::StructureType::ePhysicalDeviceSubgroupProperties);
    e_vk_StructureType.value("BIND_BUFFER_MEMORY_INFO", vk::StructureType::eBindBufferMemoryInfo);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_INFO", vk::StructureType::eBindImageMemoryInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_16_BIT_STORAGE_FEATURES", vk::StructureType::ePhysicalDevice16BitStorageFeatures);
    e_vk_StructureType.value("MEMORY_DEDICATED_REQUIREMENTS", vk::StructureType::eMemoryDedicatedRequirements);
    e_vk_StructureType.value("MEMORY_DEDICATED_ALLOCATE_INFO", vk::StructureType::eMemoryDedicatedAllocateInfo);
    e_vk_StructureType.value("MEMORY_ALLOCATE_FLAGS_INFO", vk::StructureType::eMemoryAllocateFlagsInfo);
    e_vk_StructureType.value("DEVICE_GROUP_RENDER_PASS_BEGIN_INFO", vk::StructureType::eDeviceGroupRenderPassBeginInfo);
    e_vk_StructureType.value("DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO", vk::StructureType::eDeviceGroupCommandBufferBeginInfo);
    e_vk_StructureType.value("DEVICE_GROUP_SUBMIT_INFO", vk::StructureType::eDeviceGroupSubmitInfo);
    e_vk_StructureType.value("DEVICE_GROUP_BIND_SPARSE_INFO", vk::StructureType::eDeviceGroupBindSparseInfo);
    e_vk_StructureType.value("BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO", vk::StructureType::eBindBufferMemoryDeviceGroupInfo);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO", vk::StructureType::eBindImageMemoryDeviceGroupInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GROUP_PROPERTIES", vk::StructureType::ePhysicalDeviceGroupProperties);
    e_vk_StructureType.value("DEVICE_GROUP_DEVICE_CREATE_INFO", vk::StructureType::eDeviceGroupDeviceCreateInfo);
    e_vk_StructureType.value("BUFFER_MEMORY_REQUIREMENTS_INFO_2", vk::StructureType::eBufferMemoryRequirementsInfo2);
    e_vk_StructureType.value("IMAGE_MEMORY_REQUIREMENTS_INFO_2", vk::StructureType::eImageMemoryRequirementsInfo2);
    e_vk_StructureType.value("IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2", vk::StructureType::eImageSparseMemoryRequirementsInfo2);
    e_vk_StructureType.value("MEMORY_REQUIREMENTS_2", vk::StructureType::eMemoryRequirements2);
    e_vk_StructureType.value("SPARSE_IMAGE_MEMORY_REQUIREMENTS_2", vk::StructureType::eSparseImageMemoryRequirements2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FEATURES_2", vk::StructureType::ePhysicalDeviceFeatures2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROPERTIES_2", vk::StructureType::ePhysicalDeviceProperties2);
    e_vk_StructureType.value("FORMAT_PROPERTIES_2", vk::StructureType::eFormatProperties2);
    e_vk_StructureType.value("IMAGE_FORMAT_PROPERTIES_2", vk::StructureType::eImageFormatProperties2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2", vk::StructureType::ePhysicalDeviceImageFormatInfo2);
    e_vk_StructureType.value("QUEUE_FAMILY_PROPERTIES_2", vk::StructureType::eQueueFamilyProperties2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_PROPERTIES_2", vk::StructureType::ePhysicalDeviceMemoryProperties2);
    e_vk_StructureType.value("SPARSE_IMAGE_FORMAT_PROPERTIES_2", vk::StructureType::eSparseImageFormatProperties2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2", vk::StructureType::ePhysicalDeviceSparseImageFormatInfo2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES", vk::StructureType::ePhysicalDevicePointClippingProperties);
    e_vk_StructureType.value("RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO", vk::StructureType::eRenderPassInputAttachmentAspectCreateInfo);
    e_vk_StructureType.value("IMAGE_VIEW_USAGE_CREATE_INFO", vk::StructureType::eImageViewUsageCreateInfo);
    e_vk_StructureType.value("PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO", vk::StructureType::ePipelineTessellationDomainOriginStateCreateInfo);
    e_vk_StructureType.value("RENDER_PASS_MULTIVIEW_CREATE_INFO", vk::StructureType::eRenderPassMultiviewCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_FEATURES", vk::StructureType::ePhysicalDeviceMultiviewFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES", vk::StructureType::ePhysicalDeviceMultiviewProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES", vk::StructureType::ePhysicalDeviceVariablePointersFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES", vk::StructureType::ePhysicalDeviceVariablePointerFeatures);
    e_vk_StructureType.value("PROTECTED_SUBMIT_INFO", vk::StructureType::eProtectedSubmitInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES", vk::StructureType::ePhysicalDeviceProtectedMemoryFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES", vk::StructureType::ePhysicalDeviceProtectedMemoryProperties);
    e_vk_StructureType.value("DEVICE_QUEUE_INFO_2", vk::StructureType::eDeviceQueueInfo2);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_CREATE_INFO", vk::StructureType::eSamplerYcbcrConversionCreateInfo);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_INFO", vk::StructureType::eSamplerYcbcrConversionInfo);
    e_vk_StructureType.value("BIND_IMAGE_PLANE_MEMORY_INFO", vk::StructureType::eBindImagePlaneMemoryInfo);
    e_vk_StructureType.value("IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO", vk::StructureType::eImagePlaneMemoryRequirementsInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES", vk::StructureType::ePhysicalDeviceSamplerYcbcrConversionFeatures);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES", vk::StructureType::eSamplerYcbcrConversionImageFormatProperties);
    e_vk_StructureType.value("DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO", vk::StructureType::eDescriptorUpdateTemplateCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO", vk::StructureType::ePhysicalDeviceExternalImageFormatInfo);
    e_vk_StructureType.value("EXTERNAL_IMAGE_FORMAT_PROPERTIES", vk::StructureType::eExternalImageFormatProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO", vk::StructureType::ePhysicalDeviceExternalBufferInfo);
    e_vk_StructureType.value("EXTERNAL_BUFFER_PROPERTIES", vk::StructureType::eExternalBufferProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ID_PROPERTIES", vk::StructureType::ePhysicalDeviceIdProperties);
    e_vk_StructureType.value("EXTERNAL_MEMORY_BUFFER_CREATE_INFO", vk::StructureType::eExternalMemoryBufferCreateInfo);
    e_vk_StructureType.value("EXTERNAL_MEMORY_IMAGE_CREATE_INFO", vk::StructureType::eExternalMemoryImageCreateInfo);
    e_vk_StructureType.value("EXPORT_MEMORY_ALLOCATE_INFO", vk::StructureType::eExportMemoryAllocateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO", vk::StructureType::ePhysicalDeviceExternalFenceInfo);
    e_vk_StructureType.value("EXTERNAL_FENCE_PROPERTIES", vk::StructureType::eExternalFenceProperties);
    e_vk_StructureType.value("EXPORT_FENCE_CREATE_INFO", vk::StructureType::eExportFenceCreateInfo);
    e_vk_StructureType.value("EXPORT_SEMAPHORE_CREATE_INFO", vk::StructureType::eExportSemaphoreCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO", vk::StructureType::ePhysicalDeviceExternalSemaphoreInfo);
    e_vk_StructureType.value("EXTERNAL_SEMAPHORE_PROPERTIES", vk::StructureType::eExternalSemaphoreProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES", vk::StructureType::ePhysicalDeviceMaintenance3Properties);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_SUPPORT", vk::StructureType::eDescriptorSetLayoutSupport);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES", vk::StructureType::ePhysicalDeviceShaderDrawParametersFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES", vk::StructureType::ePhysicalDeviceShaderDrawParameterFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_11_FEATURES", vk::StructureType::ePhysicalDeviceVulkan11Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_11_PROPERTIES", vk::StructureType::ePhysicalDeviceVulkan11Properties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_12_FEATURES", vk::StructureType::ePhysicalDeviceVulkan12Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_12_PROPERTIES", vk::StructureType::ePhysicalDeviceVulkan12Properties);
    e_vk_StructureType.value("IMAGE_FORMAT_LIST_CREATE_INFO", vk::StructureType::eImageFormatListCreateInfo);
    e_vk_StructureType.value("ATTACHMENT_DESCRIPTION_2", vk::StructureType::eAttachmentDescription2);
    e_vk_StructureType.value("ATTACHMENT_REFERENCE_2", vk::StructureType::eAttachmentReference2);
    e_vk_StructureType.value("SUBPASS_DESCRIPTION_2", vk::StructureType::eSubpassDescription2);
    e_vk_StructureType.value("SUBPASS_DEPENDENCY_2", vk::StructureType::eSubpassDependency2);
    e_vk_StructureType.value("RENDER_PASS_CREATE_INFO_2", vk::StructureType::eRenderPassCreateInfo2);
    e_vk_StructureType.value("SUBPASS_BEGIN_INFO", vk::StructureType::eSubpassBeginInfo);
    e_vk_StructureType.value("SUBPASS_END_INFO", vk::StructureType::eSubpassEndInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_8_BIT_STORAGE_FEATURES", vk::StructureType::ePhysicalDevice8BitStorageFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DRIVER_PROPERTIES", vk::StructureType::ePhysicalDeviceDriverProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_ATOMIC_INT_64_FEATURES", vk::StructureType::ePhysicalDeviceShaderAtomicInt64Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_FLOAT_16_INT_8_FEATURES", vk::StructureType::ePhysicalDeviceShaderFloat16Int8Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES", vk::StructureType::ePhysicalDeviceFloatControlsProperties);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO", vk::StructureType::eDescriptorSetLayoutBindingFlagsCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES", vk::StructureType::ePhysicalDeviceDescriptorIndexingFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES", vk::StructureType::ePhysicalDeviceDescriptorIndexingProperties);
    e_vk_StructureType.value("DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO", vk::StructureType::eDescriptorSetVariableDescriptorCountAllocateInfo);
    e_vk_StructureType.value("DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT", vk::StructureType::eDescriptorSetVariableDescriptorCountLayoutSupport);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES", vk::StructureType::ePhysicalDeviceDepthStencilResolveProperties);
    e_vk_StructureType.value("SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE", vk::StructureType::eSubpassDescriptionDepthStencilResolve);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES", vk::StructureType::ePhysicalDeviceScalarBlockLayoutFeatures);
    e_vk_StructureType.value("IMAGE_STENCIL_USAGE_CREATE_INFO", vk::StructureType::eImageStencilUsageCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES", vk::StructureType::ePhysicalDeviceSamplerFilterMinmaxProperties);
    e_vk_StructureType.value("SAMPLER_REDUCTION_MODE_CREATE_INFO", vk::StructureType::eSamplerReductionModeCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES", vk::StructureType::ePhysicalDeviceVulkanMemoryModelFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES", vk::StructureType::ePhysicalDeviceImagelessFramebufferFeatures);
    e_vk_StructureType.value("FRAMEBUFFER_ATTACHMENTS_CREATE_INFO", vk::StructureType::eFramebufferAttachmentsCreateInfo);
    e_vk_StructureType.value("FRAMEBUFFER_ATTACHMENT_IMAGE_INFO", vk::StructureType::eFramebufferAttachmentImageInfo);
    e_vk_StructureType.value("RENDER_PASS_ATTACHMENT_BEGIN_INFO", vk::StructureType::eRenderPassAttachmentBeginInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES", vk::StructureType::ePhysicalDeviceUniformBufferStandardLayoutFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES", vk::StructureType::ePhysicalDeviceShaderSubgroupExtendedTypesFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES", vk::StructureType::ePhysicalDeviceSeparateDepthStencilLayoutsFeatures);
    e_vk_StructureType.value("ATTACHMENT_REFERENCE_STENCIL_LAYOUT", vk::StructureType::eAttachmentReferenceStencilLayout);
    e_vk_StructureType.value("ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT", vk::StructureType::eAttachmentDescriptionStencilLayout);
    e_vk_StructureType.value("PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES", vk::StructureType::ePhysicalDeviceHostQueryResetFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES", vk::StructureType::ePhysicalDeviceTimelineSemaphoreFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES", vk::StructureType::ePhysicalDeviceTimelineSemaphoreProperties);
    e_vk_StructureType.value("SEMAPHORE_TYPE_CREATE_INFO", vk::StructureType::eSemaphoreTypeCreateInfo);
    e_vk_StructureType.value("TIMELINE_SEMAPHORE_SUBMIT_INFO", vk::StructureType::eTimelineSemaphoreSubmitInfo);
    e_vk_StructureType.value("SEMAPHORE_WAIT_INFO", vk::StructureType::eSemaphoreWaitInfo);
    e_vk_StructureType.value("SEMAPHORE_SIGNAL_INFO", vk::StructureType::eSemaphoreSignalInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES", vk::StructureType::ePhysicalDeviceBufferDeviceAddressFeatures);
    e_vk_StructureType.value("BUFFER_DEVICE_ADDRESS_INFO", vk::StructureType::eBufferDeviceAddressInfo);
    e_vk_StructureType.value("BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO", vk::StructureType::eBufferOpaqueCaptureAddressCreateInfo);
    e_vk_StructureType.value("MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO", vk::StructureType::eMemoryOpaqueCaptureAddressAllocateInfo);
    e_vk_StructureType.value("DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO", vk::StructureType::eDeviceMemoryOpaqueCaptureAddressInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_13_FEATURES", vk::StructureType::ePhysicalDeviceVulkan13Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_13_PROPERTIES", vk::StructureType::ePhysicalDeviceVulkan13Properties);
    e_vk_StructureType.value("PIPELINE_CREATION_FEEDBACK_CREATE_INFO", vk::StructureType::ePipelineCreationFeedbackCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES", vk::StructureType::ePhysicalDeviceShaderTerminateInvocationFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TOOL_PROPERTIES", vk::StructureType::ePhysicalDeviceToolProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES", vk::StructureType::ePhysicalDeviceShaderDemoteToHelperInvocationFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES", vk::StructureType::ePhysicalDevicePrivateDataFeatures);
    e_vk_StructureType.value("DEVICE_PRIVATE_DATA_CREATE_INFO", vk::StructureType::eDevicePrivateDataCreateInfo);
    e_vk_StructureType.value("PRIVATE_DATA_SLOT_CREATE_INFO", vk::StructureType::ePrivateDataSlotCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES", vk::StructureType::ePhysicalDevicePipelineCreationCacheControlFeatures);
    e_vk_StructureType.value("MEMORY_BARRIER_2", vk::StructureType::eMemoryBarrier2);
    e_vk_StructureType.value("BUFFER_MEMORY_BARRIER_2", vk::StructureType::eBufferMemoryBarrier2);
    e_vk_StructureType.value("IMAGE_MEMORY_BARRIER_2", vk::StructureType::eImageMemoryBarrier2);
    e_vk_StructureType.value("DEPENDENCY_INFO", vk::StructureType::eDependencyInfo);
    e_vk_StructureType.value("SUBMIT_INFO_2", vk::StructureType::eSubmitInfo2);
    e_vk_StructureType.value("SEMAPHORE_SUBMIT_INFO", vk::StructureType::eSemaphoreSubmitInfo);
    e_vk_StructureType.value("COMMAND_BUFFER_SUBMIT_INFO", vk::StructureType::eCommandBufferSubmitInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES", vk::StructureType::ePhysicalDeviceSynchronization2Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES", vk::StructureType::ePhysicalDeviceZeroInitializeWorkgroupMemoryFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES", vk::StructureType::ePhysicalDeviceImageRobustnessFeatures);
    e_vk_StructureType.value("COPY_BUFFER_INFO_2", vk::StructureType::eCopyBufferInfo2);
    e_vk_StructureType.value("COPY_IMAGE_INFO_2", vk::StructureType::eCopyImageInfo2);
    e_vk_StructureType.value("COPY_BUFFER_TO_IMAGE_INFO_2", vk::StructureType::eCopyBufferToImageInfo2);
    e_vk_StructureType.value("COPY_IMAGE_TO_BUFFER_INFO_2", vk::StructureType::eCopyImageToBufferInfo2);
    e_vk_StructureType.value("BLIT_IMAGE_INFO_2", vk::StructureType::eBlitImageInfo2);
    e_vk_StructureType.value("RESOLVE_IMAGE_INFO_2", vk::StructureType::eResolveImageInfo2);
    e_vk_StructureType.value("BUFFER_COPY_2", vk::StructureType::eBufferCopy2);
    e_vk_StructureType.value("IMAGE_COPY_2", vk::StructureType::eImageCopy2);
    e_vk_StructureType.value("IMAGE_BLIT_2", vk::StructureType::eImageBlit2);
    e_vk_StructureType.value("BUFFER_IMAGE_COPY_2", vk::StructureType::eBufferImageCopy2);
    e_vk_StructureType.value("IMAGE_RESOLVE_2", vk::StructureType::eImageResolve2);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES", vk::StructureType::ePhysicalDeviceSubgroupSizeControlProperties);
    e_vk_StructureType.value("PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO", vk::StructureType::ePipelineShaderStageRequiredSubgroupSizeCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES", vk::StructureType::ePhysicalDeviceSubgroupSizeControlFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES", vk::StructureType::ePhysicalDeviceInlineUniformBlockFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES", vk::StructureType::ePhysicalDeviceInlineUniformBlockProperties);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK", vk::StructureType::eWriteDescriptorSetInlineUniformBlock);
    e_vk_StructureType.value("DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO", vk::StructureType::eDescriptorPoolInlineUniformBlockCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES", vk::StructureType::ePhysicalDeviceTextureCompressionAstcHdrFeatures);
    e_vk_StructureType.value("RENDERING_INFO", vk::StructureType::eRenderingInfo);
    e_vk_StructureType.value("RENDERING_ATTACHMENT_INFO", vk::StructureType::eRenderingAttachmentInfo);
    e_vk_StructureType.value("PIPELINE_RENDERING_CREATE_INFO", vk::StructureType::ePipelineRenderingCreateInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES", vk::StructureType::ePhysicalDeviceDynamicRenderingFeatures);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_RENDERING_INFO", vk::StructureType::eCommandBufferInheritanceRenderingInfo);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES", vk::StructureType::ePhysicalDeviceShaderIntegerDotProductFeatures);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES", vk::StructureType::ePhysicalDeviceShaderIntegerDotProductProperties);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES", vk::StructureType::ePhysicalDeviceTexelBufferAlignmentProperties);
    e_vk_StructureType.value("FORMAT_PROPERTIES_3", vk::StructureType::eFormatProperties3);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES", vk::StructureType::ePhysicalDeviceMaintenance4Features);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES", vk::StructureType::ePhysicalDeviceMaintenance4Properties);
    e_vk_StructureType.value("DEVICE_BUFFER_MEMORY_REQUIREMENTS", vk::StructureType::eDeviceBufferMemoryRequirements);
    e_vk_StructureType.value("DEVICE_IMAGE_MEMORY_REQUIREMENTS", vk::StructureType::eDeviceImageMemoryRequirements);
    e_vk_StructureType.value("SWAPCHAIN_CREATE_INFO_KHR", vk::StructureType::eSwapchainCreateInfoKHR);
    e_vk_StructureType.value("PRESENT_INFO_KHR", vk::StructureType::ePresentInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_PRESENT_CAPABILITIES_KHR", vk::StructureType::eDeviceGroupPresentCapabilitiesKHR);
    e_vk_StructureType.value("IMAGE_SWAPCHAIN_CREATE_INFO_KHR", vk::StructureType::eImageSwapchainCreateInfoKHR);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR", vk::StructureType::eBindImageMemorySwapchainInfoKHR);
    e_vk_StructureType.value("ACQUIRE_NEXT_IMAGE_INFO_KHR", vk::StructureType::eAcquireNextImageInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_PRESENT_INFO_KHR", vk::StructureType::eDeviceGroupPresentInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR", vk::StructureType::eDeviceGroupSwapchainCreateInfoKHR);
    e_vk_StructureType.value("DISPLAY_MODE_CREATE_INFO_KHR", vk::StructureType::eDisplayModeCreateInfoKHR);
    e_vk_StructureType.value("DISPLAY_SURFACE_CREATE_INFO_KHR", vk::StructureType::eDisplaySurfaceCreateInfoKHR);
    e_vk_StructureType.value("DISPLAY_PRESENT_INFO_KHR", vk::StructureType::eDisplayPresentInfoKHR);
    e_vk_StructureType.value("DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT", vk::StructureType::eDebugReportCallbackCreateInfoEXT);
    e_vk_StructureType.value("DEBUG_REPORT_CREATE_INFO_EXT", vk::StructureType::eDebugReportCreateInfoEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD", vk::StructureType::ePipelineRasterizationStateRasterizationOrderAMD);
    e_vk_StructureType.value("DEBUG_MARKER_OBJECT_NAME_INFO_EXT", vk::StructureType::eDebugMarkerObjectNameInfoEXT);
    e_vk_StructureType.value("DEBUG_MARKER_OBJECT_TAG_INFO_EXT", vk::StructureType::eDebugMarkerObjectTagInfoEXT);
    e_vk_StructureType.value("DEBUG_MARKER_MARKER_INFO_EXT", vk::StructureType::eDebugMarkerMarkerInfoEXT);
    e_vk_StructureType.value("VIDEO_PROFILE_INFO_KHR", vk::StructureType::eVideoProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_CAPABILITIES_KHR", vk::StructureType::eVideoCapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_PICTURE_RESOURCE_INFO_KHR", vk::StructureType::eVideoPictureResourceInfoKHR);
    e_vk_StructureType.value("VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR", vk::StructureType::eVideoSessionMemoryRequirementsKHR);
    e_vk_StructureType.value("BIND_VIDEO_SESSION_MEMORY_INFO_KHR", vk::StructureType::eBindVideoSessionMemoryInfoKHR);
    e_vk_StructureType.value("VIDEO_SESSION_CREATE_INFO_KHR", vk::StructureType::eVideoSessionCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR", vk::StructureType::eVideoSessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR", vk::StructureType::eVideoSessionParametersUpdateInfoKHR);
    e_vk_StructureType.value("VIDEO_BEGIN_CODING_INFO_KHR", vk::StructureType::eVideoBeginCodingInfoKHR);
    e_vk_StructureType.value("VIDEO_END_CODING_INFO_KHR", vk::StructureType::eVideoEndCodingInfoKHR);
    e_vk_StructureType.value("VIDEO_CODING_CONTROL_INFO_KHR", vk::StructureType::eVideoCodingControlInfoKHR);
    e_vk_StructureType.value("VIDEO_REFERENCE_SLOT_INFO_KHR", vk::StructureType::eVideoReferenceSlotInfoKHR);
    e_vk_StructureType.value("QUEUE_FAMILY_VIDEO_PROPERTIES_KHR", vk::StructureType::eQueueFamilyVideoPropertiesKHR);
    e_vk_StructureType.value("VIDEO_PROFILE_LIST_INFO_KHR", vk::StructureType::eVideoProfileListInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR", vk::StructureType::ePhysicalDeviceVideoFormatInfoKHR);
    e_vk_StructureType.value("VIDEO_FORMAT_PROPERTIES_KHR", vk::StructureType::eVideoFormatPropertiesKHR);
    e_vk_StructureType.value("QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR", vk::StructureType::eQueueFamilyQueryResultStatusPropertiesKHR);
    e_vk_StructureType.value("VIDEO_DECODE_INFO_KHR", vk::StructureType::eVideoDecodeInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_CAPABILITIES_KHR", vk::StructureType::eVideoDecodeCapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_DECODE_USAGE_INFO_KHR", vk::StructureType::eVideoDecodeUsageInfoKHR);
    e_vk_StructureType.value("DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV", vk::StructureType::eDedicatedAllocationImageCreateInfoNV);
    e_vk_StructureType.value("DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV", vk::StructureType::eDedicatedAllocationBufferCreateInfoNV);
    e_vk_StructureType.value("DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV", vk::StructureType::eDedicatedAllocationMemoryAllocateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT", vk::StructureType::ePhysicalDeviceTransformFeedbackFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceTransformFeedbackPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT", vk::StructureType::ePipelineRasterizationStateStreamCreateInfoEXT);
    e_vk_StructureType.value("CU_MODULE_CREATE_INFO_NVX", vk::StructureType::eCuModuleCreateInfoNVX);
    e_vk_StructureType.value("CU_FUNCTION_CREATE_INFO_NVX", vk::StructureType::eCuFunctionCreateInfoNVX);
    e_vk_StructureType.value("CU_LAUNCH_INFO_NVX", vk::StructureType::eCuLaunchInfoNVX);
    e_vk_StructureType.value("IMAGE_VIEW_HANDLE_INFO_NVX", vk::StructureType::eImageViewHandleInfoNVX);
    e_vk_StructureType.value("IMAGE_VIEW_ADDRESS_PROPERTIES_NVX", vk::StructureType::eImageViewAddressPropertiesNVX);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_CAPABILITIES_KHR", vk::StructureType::eVideoEncodeH264CapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR", vk::StructureType::eVideoEncodeH264SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR", vk::StructureType::eVideoEncodeH264SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_PICTURE_INFO_KHR", vk::StructureType::eVideoEncodeH264PictureInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR", vk::StructureType::eVideoEncodeH264DpbSlotInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR", vk::StructureType::eVideoEncodeH264NaluSliceInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR", vk::StructureType::eVideoEncodeH264GopRemainingFrameInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_PROFILE_INFO_KHR", vk::StructureType::eVideoEncodeH264ProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR", vk::StructureType::eVideoEncodeH264RateControlInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR", vk::StructureType::eVideoEncodeH264RateControlLayerInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR", vk::StructureType::eVideoEncodeH264SessionCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR", vk::StructureType::eVideoEncodeH264QualityLevelPropertiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR", vk::StructureType::eVideoEncodeH264SessionParametersGetInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR", vk::StructureType::eVideoEncodeH264SessionParametersFeedbackInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_CAPABILITIES_KHR", vk::StructureType::eVideoEncodeH265CapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR", vk::StructureType::eVideoEncodeH265SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR", vk::StructureType::eVideoEncodeH265SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_PICTURE_INFO_KHR", vk::StructureType::eVideoEncodeH265PictureInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR", vk::StructureType::eVideoEncodeH265DpbSlotInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR", vk::StructureType::eVideoEncodeH265NaluSliceSegmentInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR", vk::StructureType::eVideoEncodeH265GopRemainingFrameInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_PROFILE_INFO_KHR", vk::StructureType::eVideoEncodeH265ProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR", vk::StructureType::eVideoEncodeH265RateControlInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR", vk::StructureType::eVideoEncodeH265RateControlLayerInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR", vk::StructureType::eVideoEncodeH265SessionCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR", vk::StructureType::eVideoEncodeH265QualityLevelPropertiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR", vk::StructureType::eVideoEncodeH265SessionParametersGetInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR", vk::StructureType::eVideoEncodeH265SessionParametersFeedbackInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_CAPABILITIES_KHR", vk::StructureType::eVideoDecodeH264CapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_PICTURE_INFO_KHR", vk::StructureType::eVideoDecodeH264PictureInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_PROFILE_INFO_KHR", vk::StructureType::eVideoDecodeH264ProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR", vk::StructureType::eVideoDecodeH264SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR", vk::StructureType::eVideoDecodeH264SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR", vk::StructureType::eVideoDecodeH264DpbSlotInfoKHR);
    e_vk_StructureType.value("TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD", vk::StructureType::eTextureLodGatherFormatPropertiesAMD);
    e_vk_StructureType.value("RENDERING_INFO_KHR", vk::StructureType::eRenderingInfoKHR);
    e_vk_StructureType.value("RENDERING_ATTACHMENT_INFO_KHR", vk::StructureType::eRenderingAttachmentInfoKHR);
    e_vk_StructureType.value("PIPELINE_RENDERING_CREATE_INFO_KHR", vk::StructureType::ePipelineRenderingCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES_KHR", vk::StructureType::ePhysicalDeviceDynamicRenderingFeaturesKHR);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_RENDERING_INFO_KHR", vk::StructureType::eCommandBufferInheritanceRenderingInfoKHR);
    e_vk_StructureType.value("RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR", vk::StructureType::eRenderingFragmentShadingRateAttachmentInfoKHR);
    e_vk_StructureType.value("RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT", vk::StructureType::eRenderingFragmentDensityMapAttachmentInfoEXT);
    e_vk_StructureType.value("ATTACHMENT_SAMPLE_COUNT_INFO_AMD", vk::StructureType::eAttachmentSampleCountInfoAMD);
    e_vk_StructureType.value("ATTACHMENT_SAMPLE_COUNT_INFO_NV", vk::StructureType::eAttachmentSampleCountInfoNV);
    e_vk_StructureType.value("MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX", vk::StructureType::eMultiviewPerViewAttributesInfoNVX);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV", vk::StructureType::ePhysicalDeviceCornerSampledImageFeaturesNV);
    e_vk_StructureType.value("RENDER_PASS_MULTIVIEW_CREATE_INFO_KHR", vk::StructureType::eRenderPassMultiviewCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR", vk::StructureType::ePhysicalDeviceMultiviewFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceMultiviewPropertiesKHR);
    e_vk_StructureType.value("EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV", vk::StructureType::eExternalMemoryImageCreateInfoNV);
    e_vk_StructureType.value("EXPORT_MEMORY_ALLOCATE_INFO_NV", vk::StructureType::eExportMemoryAllocateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FEATURES_2KHR", vk::StructureType::ePhysicalDeviceFeatures2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROPERTIES_2KHR", vk::StructureType::ePhysicalDeviceProperties2KHR);
    e_vk_StructureType.value("FORMAT_PROPERTIES_2KHR", vk::StructureType::eFormatProperties2KHR);
    e_vk_StructureType.value("IMAGE_FORMAT_PROPERTIES_2KHR", vk::StructureType::eImageFormatProperties2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2KHR", vk::StructureType::ePhysicalDeviceImageFormatInfo2KHR);
    e_vk_StructureType.value("QUEUE_FAMILY_PROPERTIES_2KHR", vk::StructureType::eQueueFamilyProperties2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_PROPERTIES_2KHR", vk::StructureType::ePhysicalDeviceMemoryProperties2KHR);
    e_vk_StructureType.value("SPARSE_IMAGE_FORMAT_PROPERTIES_2KHR", vk::StructureType::eSparseImageFormatProperties2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2KHR", vk::StructureType::ePhysicalDeviceSparseImageFormatInfo2KHR);
    e_vk_StructureType.value("MEMORY_ALLOCATE_FLAGS_INFO_KHR", vk::StructureType::eMemoryAllocateFlagsInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_RENDER_PASS_BEGIN_INFO_KHR", vk::StructureType::eDeviceGroupRenderPassBeginInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO_KHR", vk::StructureType::eDeviceGroupCommandBufferBeginInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_SUBMIT_INFO_KHR", vk::StructureType::eDeviceGroupSubmitInfoKHR);
    e_vk_StructureType.value("DEVICE_GROUP_BIND_SPARSE_INFO_KHR", vk::StructureType::eDeviceGroupBindSparseInfoKHR);
    e_vk_StructureType.value("BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO_KHR", vk::StructureType::eBindBufferMemoryDeviceGroupInfoKHR);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO_KHR", vk::StructureType::eBindImageMemoryDeviceGroupInfoKHR);
    e_vk_StructureType.value("VALIDATION_FLAGS_EXT", vk::StructureType::eValidationFlagsEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT", vk::StructureType::ePhysicalDeviceTextureCompressionAstcHdrFeaturesEXT);
    e_vk_StructureType.value("IMAGE_VIEW_ASTC_DECODE_MODE_EXT", vk::StructureType::eImageViewAstcDecodeModeEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceAstcDecodeFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_ROBUSTNESS_CREATE_INFO_EXT", vk::StructureType::ePipelineRobustnessCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT", vk::StructureType::ePhysicalDevicePipelineRobustnessFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT", vk::StructureType::ePhysicalDevicePipelineRobustnessPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GROUP_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceGroupPropertiesKHR);
    e_vk_StructureType.value("DEVICE_GROUP_DEVICE_CREATE_INFO_KHR", vk::StructureType::eDeviceGroupDeviceCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR", vk::StructureType::ePhysicalDeviceExternalImageFormatInfoKHR);
    e_vk_StructureType.value("EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR", vk::StructureType::eExternalImageFormatPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR", vk::StructureType::ePhysicalDeviceExternalBufferInfoKHR);
    e_vk_StructureType.value("EXTERNAL_BUFFER_PROPERTIES_KHR", vk::StructureType::eExternalBufferPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ID_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceIdPropertiesKHR);
    e_vk_StructureType.value("EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR", vk::StructureType::eExternalMemoryBufferCreateInfoKHR);
    e_vk_StructureType.value("EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR", vk::StructureType::eExternalMemoryImageCreateInfoKHR);
    e_vk_StructureType.value("EXPORT_MEMORY_ALLOCATE_INFO_KHR", vk::StructureType::eExportMemoryAllocateInfoKHR);
    e_vk_StructureType.value("IMPORT_MEMORY_FD_INFO_KHR", vk::StructureType::eImportMemoryFdInfoKHR);
    e_vk_StructureType.value("MEMORY_FD_PROPERTIES_KHR", vk::StructureType::eMemoryFdPropertiesKHR);
    e_vk_StructureType.value("MEMORY_GET_FD_INFO_KHR", vk::StructureType::eMemoryGetFdInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR", vk::StructureType::ePhysicalDeviceExternalSemaphoreInfoKHR);
    e_vk_StructureType.value("EXTERNAL_SEMAPHORE_PROPERTIES_KHR", vk::StructureType::eExternalSemaphorePropertiesKHR);
    e_vk_StructureType.value("EXPORT_SEMAPHORE_CREATE_INFO_KHR", vk::StructureType::eExportSemaphoreCreateInfoKHR);
    e_vk_StructureType.value("IMPORT_SEMAPHORE_FD_INFO_KHR", vk::StructureType::eImportSemaphoreFdInfoKHR);
    e_vk_StructureType.value("SEMAPHORE_GET_FD_INFO_KHR", vk::StructureType::eSemaphoreGetFdInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR", vk::StructureType::ePhysicalDevicePushDescriptorPropertiesKHR);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT", vk::StructureType::eCommandBufferInheritanceConditionalRenderingInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT", vk::StructureType::ePhysicalDeviceConditionalRenderingFeaturesEXT);
    e_vk_StructureType.value("CONDITIONAL_RENDERING_BEGIN_INFO_EXT", vk::StructureType::eConditionalRenderingBeginInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_FLOAT_16_INT_8_FEATURES_KHR", vk::StructureType::ePhysicalDeviceShaderFloat16Int8FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FLOAT_16_INT_8_FEATURES_KHR", vk::StructureType::ePhysicalDeviceFloat16Int8FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_16_BIT_STORAGE_FEATURES_KHR", vk::StructureType::ePhysicalDevice16BitStorageFeaturesKHR);
    e_vk_StructureType.value("PRESENT_REGIONS_KHR", vk::StructureType::ePresentRegionsKHR);
    e_vk_StructureType.value("DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO_KHR", vk::StructureType::eDescriptorUpdateTemplateCreateInfoKHR);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineViewportWScalingStateCreateInfoNV);
    e_vk_StructureType.value("SURFACE_CAPABILITIES_2EXT", vk::StructureType::eSurfaceCapabilities2EXT);
    e_vk_StructureType.value("DISPLAY_POWER_INFO_EXT", vk::StructureType::eDisplayPowerInfoEXT);
    e_vk_StructureType.value("DEVICE_EVENT_INFO_EXT", vk::StructureType::eDeviceEventInfoEXT);
    e_vk_StructureType.value("DISPLAY_EVENT_INFO_EXT", vk::StructureType::eDisplayEventInfoEXT);
    e_vk_StructureType.value("SWAPCHAIN_COUNTER_CREATE_INFO_EXT", vk::StructureType::eSwapchainCounterCreateInfoEXT);
    e_vk_StructureType.value("PRESENT_TIMES_INFO_GOOGLE", vk::StructureType::ePresentTimesInfoGOOGLE);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX", vk::StructureType::ePhysicalDeviceMultiviewPerViewAttributesPropertiesNVX);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineViewportSwizzleStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceDiscardRectanglePropertiesEXT);
    e_vk_StructureType.value("PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT", vk::StructureType::ePipelineDiscardRectangleStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceConservativeRasterizationPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT", vk::StructureType::ePipelineRasterizationConservativeStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceDepthClipEnableFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT", vk::StructureType::ePipelineRasterizationDepthClipStateCreateInfoEXT);
    e_vk_StructureType.value("HDR_METADATA_EXT", vk::StructureType::eHdrMetadataEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES_KHR", vk::StructureType::ePhysicalDeviceImagelessFramebufferFeaturesKHR);
    e_vk_StructureType.value("FRAMEBUFFER_ATTACHMENTS_CREATE_INFO_KHR", vk::StructureType::eFramebufferAttachmentsCreateInfoKHR);
    e_vk_StructureType.value("FRAMEBUFFER_ATTACHMENT_IMAGE_INFO_KHR", vk::StructureType::eFramebufferAttachmentImageInfoKHR);
    e_vk_StructureType.value("RENDER_PASS_ATTACHMENT_BEGIN_INFO_KHR", vk::StructureType::eRenderPassAttachmentBeginInfoKHR);
    e_vk_StructureType.value("ATTACHMENT_DESCRIPTION_2KHR", vk::StructureType::eAttachmentDescription2KHR);
    e_vk_StructureType.value("ATTACHMENT_REFERENCE_2KHR", vk::StructureType::eAttachmentReference2KHR);
    e_vk_StructureType.value("SUBPASS_DESCRIPTION_2KHR", vk::StructureType::eSubpassDescription2KHR);
    e_vk_StructureType.value("SUBPASS_DEPENDENCY_2KHR", vk::StructureType::eSubpassDependency2KHR);
    e_vk_StructureType.value("RENDER_PASS_CREATE_INFO_2KHR", vk::StructureType::eRenderPassCreateInfo2KHR);
    e_vk_StructureType.value("SUBPASS_BEGIN_INFO_KHR", vk::StructureType::eSubpassBeginInfoKHR);
    e_vk_StructureType.value("SUBPASS_END_INFO_KHR", vk::StructureType::eSubpassEndInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG", vk::StructureType::ePhysicalDeviceRelaxedLineRasterizationFeaturesIMG);
    e_vk_StructureType.value("SHARED_PRESENT_SURFACE_CAPABILITIES_KHR", vk::StructureType::eSharedPresentSurfaceCapabilitiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR", vk::StructureType::ePhysicalDeviceExternalFenceInfoKHR);
    e_vk_StructureType.value("EXTERNAL_FENCE_PROPERTIES_KHR", vk::StructureType::eExternalFencePropertiesKHR);
    e_vk_StructureType.value("EXPORT_FENCE_CREATE_INFO_KHR", vk::StructureType::eExportFenceCreateInfoKHR);
    e_vk_StructureType.value("IMPORT_FENCE_FD_INFO_KHR", vk::StructureType::eImportFenceFdInfoKHR);
    e_vk_StructureType.value("FENCE_GET_FD_INFO_KHR", vk::StructureType::eFenceGetFdInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR", vk::StructureType::ePhysicalDevicePerformanceQueryFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR", vk::StructureType::ePhysicalDevicePerformanceQueryPropertiesKHR);
    e_vk_StructureType.value("QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR", vk::StructureType::eQueryPoolPerformanceCreateInfoKHR);
    e_vk_StructureType.value("PERFORMANCE_QUERY_SUBMIT_INFO_KHR", vk::StructureType::ePerformanceQuerySubmitInfoKHR);
    e_vk_StructureType.value("ACQUIRE_PROFILING_LOCK_INFO_KHR", vk::StructureType::eAcquireProfilingLockInfoKHR);
    e_vk_StructureType.value("PERFORMANCE_COUNTER_KHR", vk::StructureType::ePerformanceCounterKHR);
    e_vk_StructureType.value("PERFORMANCE_COUNTER_DESCRIPTION_KHR", vk::StructureType::ePerformanceCounterDescriptionKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES_KHR", vk::StructureType::ePhysicalDevicePointClippingPropertiesKHR);
    e_vk_StructureType.value("RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO_KHR", vk::StructureType::eRenderPassInputAttachmentAspectCreateInfoKHR);
    e_vk_StructureType.value("IMAGE_VIEW_USAGE_CREATE_INFO_KHR", vk::StructureType::eImageViewUsageCreateInfoKHR);
    e_vk_StructureType.value("PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO_KHR", vk::StructureType::ePipelineTessellationDomainOriginStateCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SURFACE_INFO_2KHR", vk::StructureType::ePhysicalDeviceSurfaceInfo2KHR);
    e_vk_StructureType.value("SURFACE_CAPABILITIES_2KHR", vk::StructureType::eSurfaceCapabilities2KHR);
    e_vk_StructureType.value("SURFACE_FORMAT_2KHR", vk::StructureType::eSurfaceFormat2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR", vk::StructureType::ePhysicalDeviceVariablePointersFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR", vk::StructureType::ePhysicalDeviceVariablePointerFeaturesKHR);
    e_vk_StructureType.value("DISPLAY_PROPERTIES_2KHR", vk::StructureType::eDisplayProperties2KHR);
    e_vk_StructureType.value("DISPLAY_PLANE_PROPERTIES_2KHR", vk::StructureType::eDisplayPlaneProperties2KHR);
    e_vk_StructureType.value("DISPLAY_MODE_PROPERTIES_2KHR", vk::StructureType::eDisplayModeProperties2KHR);
    e_vk_StructureType.value("DISPLAY_PLANE_INFO_2KHR", vk::StructureType::eDisplayPlaneInfo2KHR);
    e_vk_StructureType.value("DISPLAY_PLANE_CAPABILITIES_2KHR", vk::StructureType::eDisplayPlaneCapabilities2KHR);
    e_vk_StructureType.value("MEMORY_DEDICATED_REQUIREMENTS_KHR", vk::StructureType::eMemoryDedicatedRequirementsKHR);
    e_vk_StructureType.value("MEMORY_DEDICATED_ALLOCATE_INFO_KHR", vk::StructureType::eMemoryDedicatedAllocateInfoKHR);
    e_vk_StructureType.value("DEBUG_UTILS_OBJECT_NAME_INFO_EXT", vk::StructureType::eDebugUtilsObjectNameInfoEXT);
    e_vk_StructureType.value("DEBUG_UTILS_OBJECT_TAG_INFO_EXT", vk::StructureType::eDebugUtilsObjectTagInfoEXT);
    e_vk_StructureType.value("DEBUG_UTILS_LABEL_EXT", vk::StructureType::eDebugUtilsLabelEXT);
    e_vk_StructureType.value("DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT", vk::StructureType::eDebugUtilsMessengerCallbackDataEXT);
    e_vk_StructureType.value("DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT", vk::StructureType::eDebugUtilsMessengerCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceSamplerFilterMinmaxPropertiesEXT);
    e_vk_StructureType.value("SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT", vk::StructureType::eSamplerReductionModeCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT", vk::StructureType::ePhysicalDeviceInlineUniformBlockFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceInlineUniformBlockPropertiesEXT);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT", vk::StructureType::eWriteDescriptorSetInlineUniformBlockEXT);
    e_vk_StructureType.value("DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT", vk::StructureType::eDescriptorPoolInlineUniformBlockCreateInfoEXT);
    e_vk_StructureType.value("SAMPLE_LOCATIONS_INFO_EXT", vk::StructureType::eSampleLocationsInfoEXT);
    e_vk_StructureType.value("RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT", vk::StructureType::eRenderPassSampleLocationsBeginInfoEXT);
    e_vk_StructureType.value("PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT", vk::StructureType::ePipelineSampleLocationsStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceSampleLocationsPropertiesEXT);
    e_vk_StructureType.value("MULTISAMPLE_PROPERTIES_EXT", vk::StructureType::eMultisamplePropertiesEXT);
    e_vk_StructureType.value("BUFFER_MEMORY_REQUIREMENTS_INFO_2KHR", vk::StructureType::eBufferMemoryRequirementsInfo2KHR);
    e_vk_StructureType.value("IMAGE_MEMORY_REQUIREMENTS_INFO_2KHR", vk::StructureType::eImageMemoryRequirementsInfo2KHR);
    e_vk_StructureType.value("IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2KHR", vk::StructureType::eImageSparseMemoryRequirementsInfo2KHR);
    e_vk_StructureType.value("MEMORY_REQUIREMENTS_2KHR", vk::StructureType::eMemoryRequirements2KHR);
    e_vk_StructureType.value("SPARSE_IMAGE_MEMORY_REQUIREMENTS_2KHR", vk::StructureType::eSparseImageMemoryRequirements2KHR);
    e_vk_StructureType.value("IMAGE_FORMAT_LIST_CREATE_INFO_KHR", vk::StructureType::eImageFormatListCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT", vk::StructureType::ePhysicalDeviceBlendOperationAdvancedFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceBlendOperationAdvancedPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT", vk::StructureType::ePipelineColorBlendAdvancedStateCreateInfoEXT);
    e_vk_StructureType.value("PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineCoverageToColorStateCreateInfoNV);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR", vk::StructureType::eWriteDescriptorSetAccelerationStructureKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR", vk::StructureType::eAccelerationStructureBuildGeometryInfoKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR", vk::StructureType::eAccelerationStructureDeviceAddressInfoKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR", vk::StructureType::eAccelerationStructureGeometryAabbsDataKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR", vk::StructureType::eAccelerationStructureGeometryInstancesDataKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR", vk::StructureType::eAccelerationStructureGeometryTrianglesDataKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_KHR", vk::StructureType::eAccelerationStructureGeometryKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_VERSION_INFO_KHR", vk::StructureType::eAccelerationStructureVersionInfoKHR);
    e_vk_StructureType.value("COPY_ACCELERATION_STRUCTURE_INFO_KHR", vk::StructureType::eCopyAccelerationStructureInfoKHR);
    e_vk_StructureType.value("COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR", vk::StructureType::eCopyAccelerationStructureToMemoryInfoKHR);
    e_vk_StructureType.value("COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR", vk::StructureType::eCopyMemoryToAccelerationStructureInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR", vk::StructureType::ePhysicalDeviceAccelerationStructureFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceAccelerationStructurePropertiesKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_CREATE_INFO_KHR", vk::StructureType::eAccelerationStructureCreateInfoKHR);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR", vk::StructureType::eAccelerationStructureBuildSizesInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR", vk::StructureType::ePhysicalDeviceRayTracingPipelineFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceRayTracingPipelinePropertiesKHR);
    e_vk_StructureType.value("RAY_TRACING_PIPELINE_CREATE_INFO_KHR", vk::StructureType::eRayTracingPipelineCreateInfoKHR);
    e_vk_StructureType.value("RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR", vk::StructureType::eRayTracingShaderGroupCreateInfoKHR);
    e_vk_StructureType.value("RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR", vk::StructureType::eRayTracingPipelineInterfaceCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR", vk::StructureType::ePhysicalDeviceRayQueryFeaturesKHR);
    e_vk_StructureType.value("PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineCoverageModulationStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV", vk::StructureType::ePhysicalDeviceShaderSmBuiltinsFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceShaderSmBuiltinsPropertiesNV);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_CREATE_INFO_KHR", vk::StructureType::eSamplerYcbcrConversionCreateInfoKHR);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_INFO_KHR", vk::StructureType::eSamplerYcbcrConversionInfoKHR);
    e_vk_StructureType.value("BIND_IMAGE_PLANE_MEMORY_INFO_KHR", vk::StructureType::eBindImagePlaneMemoryInfoKHR);
    e_vk_StructureType.value("IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO_KHR", vk::StructureType::eImagePlaneMemoryRequirementsInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR", vk::StructureType::ePhysicalDeviceSamplerYcbcrConversionFeaturesKHR);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES_KHR", vk::StructureType::eSamplerYcbcrConversionImageFormatPropertiesKHR);
    e_vk_StructureType.value("BIND_BUFFER_MEMORY_INFO_KHR", vk::StructureType::eBindBufferMemoryInfoKHR);
    e_vk_StructureType.value("BIND_IMAGE_MEMORY_INFO_KHR", vk::StructureType::eBindImageMemoryInfoKHR);
    e_vk_StructureType.value("DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT", vk::StructureType::eDrmFormatModifierPropertiesListEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT", vk::StructureType::ePhysicalDeviceImageDrmFormatModifierInfoEXT);
    e_vk_StructureType.value("IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT", vk::StructureType::eImageDrmFormatModifierListCreateInfoEXT);
    e_vk_StructureType.value("IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT", vk::StructureType::eImageDrmFormatModifierExplicitCreateInfoEXT);
    e_vk_StructureType.value("IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT", vk::StructureType::eImageDrmFormatModifierPropertiesEXT);
    e_vk_StructureType.value("DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2EXT", vk::StructureType::eDrmFormatModifierPropertiesList2EXT);
    e_vk_StructureType.value("VALIDATION_CACHE_CREATE_INFO_EXT", vk::StructureType::eValidationCacheCreateInfoEXT);
    e_vk_StructureType.value("SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT", vk::StructureType::eShaderModuleValidationCacheCreateInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT", vk::StructureType::eDescriptorSetLayoutBindingFlagsCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT", vk::StructureType::ePhysicalDeviceDescriptorIndexingFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceDescriptorIndexingPropertiesEXT);
    e_vk_StructureType.value("DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT", vk::StructureType::eDescriptorSetVariableDescriptorCountAllocateInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT", vk::StructureType::eDescriptorSetVariableDescriptorCountLayoutSupportEXT);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineViewportShadingRateImageStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV", vk::StructureType::ePhysicalDeviceShadingRateImageFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceShadingRateImagePropertiesNV);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineViewportCoarseSampleOrderStateCreateInfoNV);
    e_vk_StructureType.value("RAY_TRACING_PIPELINE_CREATE_INFO_NV", vk::StructureType::eRayTracingPipelineCreateInfoNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_CREATE_INFO_NV", vk::StructureType::eAccelerationStructureCreateInfoNV);
    e_vk_StructureType.value("GEOMETRY_NV", vk::StructureType::eGeometryNV);
    e_vk_StructureType.value("GEOMETRY_TRIANGLES_NV", vk::StructureType::eGeometryTrianglesNV);
    e_vk_StructureType.value("GEOMETRY_AABB_NV", vk::StructureType::eGeometryAabbNV);
    e_vk_StructureType.value("BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV", vk::StructureType::eBindAccelerationStructureMemoryInfoNV);
    e_vk_StructureType.value("WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV", vk::StructureType::eWriteDescriptorSetAccelerationStructureNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV", vk::StructureType::eAccelerationStructureMemoryRequirementsInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceRayTracingPropertiesNV);
    e_vk_StructureType.value("RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV", vk::StructureType::eRayTracingShaderGroupCreateInfoNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_INFO_NV", vk::StructureType::eAccelerationStructureInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV", vk::StructureType::ePhysicalDeviceRepresentativeFragmentTestFeaturesNV);
    e_vk_StructureType.value("PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineRepresentativeFragmentTestStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceMaintenance3PropertiesKHR);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_SUPPORT_KHR", vk::StructureType::eDescriptorSetLayoutSupportKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT", vk::StructureType::ePhysicalDeviceImageViewImageFormatInfoEXT);
    e_vk_StructureType.value("FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT", vk::StructureType::eFilterCubicImageViewImageFormatPropertiesEXT);
    e_vk_StructureType.value("DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT", vk::StructureType::eDeviceQueueGlobalPriorityCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES_KHR", vk::StructureType::ePhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_8_BIT_STORAGE_FEATURES_KHR", vk::StructureType::ePhysicalDevice8BitStorageFeaturesKHR);
    e_vk_StructureType.value("IMPORT_MEMORY_HOST_POINTER_INFO_EXT", vk::StructureType::eImportMemoryHostPointerInfoEXT);
    e_vk_StructureType.value("MEMORY_HOST_POINTER_PROPERTIES_EXT", vk::StructureType::eMemoryHostPointerPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceExternalMemoryHostPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_ATOMIC_INT_64_FEATURES_KHR", vk::StructureType::ePhysicalDeviceShaderAtomicInt64FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR", vk::StructureType::ePhysicalDeviceShaderClockFeaturesKHR);
    e_vk_StructureType.value("PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD", vk::StructureType::ePipelineCompilerControlCreateInfoAMD);
    e_vk_StructureType.value("CALIBRATED_TIMESTAMP_INFO_EXT", vk::StructureType::eCalibratedTimestampInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD", vk::StructureType::ePhysicalDeviceShaderCorePropertiesAMD);
    e_vk_StructureType.value("VIDEO_DECODE_H265_CAPABILITIES_KHR", vk::StructureType::eVideoDecodeH265CapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR", vk::StructureType::eVideoDecodeH265SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR", vk::StructureType::eVideoDecodeH265SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_PROFILE_INFO_KHR", vk::StructureType::eVideoDecodeH265ProfileInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_PICTURE_INFO_KHR", vk::StructureType::eVideoDecodeH265PictureInfoKHR);
    e_vk_StructureType.value("VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR", vk::StructureType::eVideoDecodeH265DpbSlotInfoKHR);
    e_vk_StructureType.value("DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR", vk::StructureType::eDeviceQueueGlobalPriorityCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR", vk::StructureType::ePhysicalDeviceGlobalPriorityQueryFeaturesKHR);
    e_vk_StructureType.value("QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR", vk::StructureType::eQueueFamilyGlobalPriorityPropertiesKHR);
    e_vk_StructureType.value("DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD", vk::StructureType::eDeviceMemoryOverallocationCreateInfoAMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceVertexAttributeDivisorPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT", vk::StructureType::ePipelineVertexInputDivisorStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT", vk::StructureType::ePhysicalDeviceVertexAttributeDivisorFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT", vk::StructureType::ePipelineCreationFeedbackCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceDriverPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceFloatControlsPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceDepthStencilResolvePropertiesKHR);
    e_vk_StructureType.value("SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR", vk::StructureType::eSubpassDescriptionDepthStencilResolveKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV", vk::StructureType::ePhysicalDeviceComputeShaderDerivativesFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV", vk::StructureType::ePhysicalDeviceMeshShaderFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceMeshShaderPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV", vk::StructureType::ePhysicalDeviceFragmentShaderBarycentricFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV", vk::StructureType::ePhysicalDeviceShaderImageFootprintFeaturesNV);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineViewportExclusiveScissorStateCreateInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV", vk::StructureType::ePhysicalDeviceExclusiveScissorFeaturesNV);
    e_vk_StructureType.value("CHECKPOINT_DATA_NV", vk::StructureType::eCheckpointDataNV);
    e_vk_StructureType.value("QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV", vk::StructureType::eQueueFamilyCheckpointPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES_KHR", vk::StructureType::ePhysicalDeviceTimelineSemaphoreFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceTimelineSemaphorePropertiesKHR);
    e_vk_StructureType.value("SEMAPHORE_TYPE_CREATE_INFO_KHR", vk::StructureType::eSemaphoreTypeCreateInfoKHR);
    e_vk_StructureType.value("TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR", vk::StructureType::eTimelineSemaphoreSubmitInfoKHR);
    e_vk_StructureType.value("SEMAPHORE_WAIT_INFO_KHR", vk::StructureType::eSemaphoreWaitInfoKHR);
    e_vk_StructureType.value("SEMAPHORE_SIGNAL_INFO_KHR", vk::StructureType::eSemaphoreSignalInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL", vk::StructureType::ePhysicalDeviceShaderIntegerFunctions2FeaturesINTEL);
    e_vk_StructureType.value("QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL", vk::StructureType::eQueryPoolPerformanceQueryCreateInfoINTEL);
    e_vk_StructureType.value("QUERY_POOL_CREATE_INFO_INTEL", vk::StructureType::eQueryPoolCreateInfoINTEL);
    e_vk_StructureType.value("INITIALIZE_PERFORMANCE_API_INFO_INTEL", vk::StructureType::eInitializePerformanceApiInfoINTEL);
    e_vk_StructureType.value("PERFORMANCE_MARKER_INFO_INTEL", vk::StructureType::ePerformanceMarkerInfoINTEL);
    e_vk_StructureType.value("PERFORMANCE_STREAM_MARKER_INFO_INTEL", vk::StructureType::ePerformanceStreamMarkerInfoINTEL);
    e_vk_StructureType.value("PERFORMANCE_OVERRIDE_INFO_INTEL", vk::StructureType::ePerformanceOverrideInfoINTEL);
    e_vk_StructureType.value("PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL", vk::StructureType::ePerformanceConfigurationAcquireInfoINTEL);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR", vk::StructureType::ePhysicalDeviceVulkanMemoryModelFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT", vk::StructureType::ePhysicalDevicePciBusInfoPropertiesEXT);
    e_vk_StructureType.value("DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD", vk::StructureType::eDisplayNativeHdrSurfaceCapabilitiesAMD);
    e_vk_StructureType.value("SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD", vk::StructureType::eSwapchainDisplayNativeHdrCreateInfoAMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR", vk::StructureType::ePhysicalDeviceShaderTerminateInvocationFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT", vk::StructureType::ePhysicalDeviceFragmentDensityMapFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceFragmentDensityMapPropertiesEXT);
    e_vk_StructureType.value("RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT", vk::StructureType::eRenderPassFragmentDensityMapCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT", vk::StructureType::ePhysicalDeviceScalarBlockLayoutFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceSubgroupSizeControlPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT", vk::StructureType::ePipelineShaderStageRequiredSubgroupSizeCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT", vk::StructureType::ePhysicalDeviceSubgroupSizeControlFeaturesEXT);
    e_vk_StructureType.value("FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR", vk::StructureType::eFragmentShadingRateAttachmentInfoKHR);
    e_vk_StructureType.value("PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR", vk::StructureType::ePipelineFragmentShadingRateStateCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceFragmentShadingRatePropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR", vk::StructureType::ePhysicalDeviceFragmentShadingRateFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR", vk::StructureType::ePhysicalDeviceFragmentShadingRateKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2AMD", vk::StructureType::ePhysicalDeviceShaderCoreProperties2AMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD", vk::StructureType::ePhysicalDeviceCoherentMemoryFeaturesAMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT_64_FEATURES_EXT", vk::StructureType::ePhysicalDeviceShaderImageAtomicInt64FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceMemoryBudgetPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT", vk::StructureType::ePhysicalDeviceMemoryPriorityFeaturesEXT);
    e_vk_StructureType.value("MEMORY_PRIORITY_ALLOCATE_INFO_EXT", vk::StructureType::eMemoryPriorityAllocateInfoEXT);
    e_vk_StructureType.value("SURFACE_PROTECTED_CAPABILITIES_KHR", vk::StructureType::eSurfaceProtectedCapabilitiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV", vk::StructureType::ePhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES_KHR", vk::StructureType::ePhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR);
    e_vk_StructureType.value("ATTACHMENT_REFERENCE_STENCIL_LAYOUT_KHR", vk::StructureType::eAttachmentReferenceStencilLayoutKHR);
    e_vk_StructureType.value("ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT_KHR", vk::StructureType::eAttachmentDescriptionStencilLayoutKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT", vk::StructureType::ePhysicalDeviceBufferDeviceAddressFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT", vk::StructureType::ePhysicalDeviceBufferAddressFeaturesEXT);
    e_vk_StructureType.value("BUFFER_DEVICE_ADDRESS_INFO_EXT", vk::StructureType::eBufferDeviceAddressInfoEXT);
    e_vk_StructureType.value("BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT", vk::StructureType::eBufferDeviceAddressCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceToolPropertiesEXT);
    e_vk_StructureType.value("IMAGE_STENCIL_USAGE_CREATE_INFO_EXT", vk::StructureType::eImageStencilUsageCreateInfoEXT);
    e_vk_StructureType.value("VALIDATION_FEATURES_EXT", vk::StructureType::eValidationFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR", vk::StructureType::ePhysicalDevicePresentWaitFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV", vk::StructureType::ePhysicalDeviceCooperativeMatrixFeaturesNV);
    e_vk_StructureType.value("COOPERATIVE_MATRIX_PROPERTIES_NV", vk::StructureType::eCooperativeMatrixPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceCooperativeMatrixPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV", vk::StructureType::ePhysicalDeviceCoverageReductionModeFeaturesNV);
    e_vk_StructureType.value("PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineCoverageReductionStateCreateInfoNV);
    e_vk_StructureType.value("FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV", vk::StructureType::eFramebufferMixedSamplesCombinationNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT", vk::StructureType::ePhysicalDeviceFragmentShaderInterlockFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT", vk::StructureType::ePhysicalDeviceYcbcrImageArraysFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR", vk::StructureType::ePhysicalDeviceUniformBufferStandardLayoutFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT", vk::StructureType::ePhysicalDeviceProvokingVertexFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT", vk::StructureType::ePipelineRasterizationProvokingVertexStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceProvokingVertexPropertiesEXT);
    e_vk_StructureType.value("HEADLESS_SURFACE_CREATE_INFO_EXT", vk::StructureType::eHeadlessSurfaceCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_KHR", vk::StructureType::ePhysicalDeviceBufferDeviceAddressFeaturesKHR);
    e_vk_StructureType.value("BUFFER_DEVICE_ADDRESS_INFO_KHR", vk::StructureType::eBufferDeviceAddressInfoKHR);
    e_vk_StructureType.value("BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO_KHR", vk::StructureType::eBufferOpaqueCaptureAddressCreateInfoKHR);
    e_vk_StructureType.value("MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO_KHR", vk::StructureType::eMemoryOpaqueCaptureAddressAllocateInfoKHR);
    e_vk_StructureType.value("DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO_KHR", vk::StructureType::eDeviceMemoryOpaqueCaptureAddressInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT", vk::StructureType::ePhysicalDeviceLineRasterizationFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT", vk::StructureType::ePipelineRasterizationLineStateCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceLineRasterizationPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT", vk::StructureType::ePhysicalDeviceShaderAtomicFloatFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT", vk::StructureType::ePhysicalDeviceHostQueryResetFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INDEX_TYPE_UINT_8_FEATURES_EXT", vk::StructureType::ePhysicalDeviceIndexTypeUint8FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceExtendedDynamicStateFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR", vk::StructureType::ePhysicalDevicePipelineExecutablePropertiesFeaturesKHR);
    e_vk_StructureType.value("PIPELINE_INFO_KHR", vk::StructureType::ePipelineInfoKHR);
    e_vk_StructureType.value("PIPELINE_EXECUTABLE_PROPERTIES_KHR", vk::StructureType::ePipelineExecutablePropertiesKHR);
    e_vk_StructureType.value("PIPELINE_EXECUTABLE_INFO_KHR", vk::StructureType::ePipelineExecutableInfoKHR);
    e_vk_StructureType.value("PIPELINE_EXECUTABLE_STATISTIC_KHR", vk::StructureType::ePipelineExecutableStatisticKHR);
    e_vk_StructureType.value("PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR", vk::StructureType::ePipelineExecutableInternalRepresentationKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT", vk::StructureType::ePhysicalDeviceHostImageCopyFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceHostImageCopyPropertiesEXT);
    e_vk_StructureType.value("MEMORY_TO_IMAGE_COPY_EXT", vk::StructureType::eMemoryToImageCopyEXT);
    e_vk_StructureType.value("IMAGE_TO_MEMORY_COPY_EXT", vk::StructureType::eImageToMemoryCopyEXT);
    e_vk_StructureType.value("COPY_IMAGE_TO_MEMORY_INFO_EXT", vk::StructureType::eCopyImageToMemoryInfoEXT);
    e_vk_StructureType.value("COPY_MEMORY_TO_IMAGE_INFO_EXT", vk::StructureType::eCopyMemoryToImageInfoEXT);
    e_vk_StructureType.value("HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT", vk::StructureType::eHostImageLayoutTransitionInfoEXT);
    e_vk_StructureType.value("COPY_IMAGE_TO_IMAGE_INFO_EXT", vk::StructureType::eCopyImageToImageInfoEXT);
    e_vk_StructureType.value("SUBRESOURCE_HOST_MEMCPY_SIZE_EXT", vk::StructureType::eSubresourceHostMemcpySizeEXT);
    e_vk_StructureType.value("HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT", vk::StructureType::eHostImageCopyDevicePerformanceQueryEXT);
    e_vk_StructureType.value("MEMORY_MAP_INFO_KHR", vk::StructureType::eMemoryMapInfoKHR);
    e_vk_StructureType.value("MEMORY_UNMAP_INFO_KHR", vk::StructureType::eMemoryUnmapInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT", vk::StructureType::ePhysicalDeviceShaderAtomicFloat2FeaturesEXT);
    e_vk_StructureType.value("SURFACE_PRESENT_MODE_EXT", vk::StructureType::eSurfacePresentModeEXT);
    e_vk_StructureType.value("SURFACE_PRESENT_SCALING_CAPABILITIES_EXT", vk::StructureType::eSurfacePresentScalingCapabilitiesEXT);
    e_vk_StructureType.value("SURFACE_PRESENT_MODE_COMPATIBILITY_EXT", vk::StructureType::eSurfacePresentModeCompatibilityEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT", vk::StructureType::ePhysicalDeviceSwapchainMaintenance1FeaturesEXT);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_FENCE_INFO_EXT", vk::StructureType::eSwapchainPresentFenceInfoEXT);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT", vk::StructureType::eSwapchainPresentModesCreateInfoEXT);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_MODE_INFO_EXT", vk::StructureType::eSwapchainPresentModeInfoEXT);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT", vk::StructureType::eSwapchainPresentScalingCreateInfoEXT);
    e_vk_StructureType.value("RELEASE_SWAPCHAIN_IMAGES_INFO_EXT", vk::StructureType::eReleaseSwapchainImagesInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT", vk::StructureType::ePhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceDeviceGeneratedCommandsPropertiesNV);
    e_vk_StructureType.value("GRAPHICS_SHADER_GROUP_CREATE_INFO_NV", vk::StructureType::eGraphicsShaderGroupCreateInfoNV);
    e_vk_StructureType.value("GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV", vk::StructureType::eGraphicsPipelineShaderGroupsCreateInfoNV);
    e_vk_StructureType.value("INDIRECT_COMMANDS_LAYOUT_TOKEN_NV", vk::StructureType::eIndirectCommandsLayoutTokenNV);
    e_vk_StructureType.value("INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV", vk::StructureType::eIndirectCommandsLayoutCreateInfoNV);
    e_vk_StructureType.value("GENERATED_COMMANDS_INFO_NV", vk::StructureType::eGeneratedCommandsInfoNV);
    e_vk_StructureType.value("GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV", vk::StructureType::eGeneratedCommandsMemoryRequirementsInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV", vk::StructureType::ePhysicalDeviceDeviceGeneratedCommandsFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV", vk::StructureType::ePhysicalDeviceInheritedViewportScissorFeaturesNV);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV", vk::StructureType::eCommandBufferInheritanceViewportScissorInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES_KHR", vk::StructureType::ePhysicalDeviceShaderIntegerDotProductFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceShaderIntegerDotProductPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT", vk::StructureType::ePhysicalDeviceTexelBufferAlignmentFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceTexelBufferAlignmentPropertiesEXT);
    e_vk_StructureType.value("COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM", vk::StructureType::eCommandBufferInheritanceRenderPassTransformInfoQCOM);
    e_vk_StructureType.value("RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM", vk::StructureType::eRenderPassTransformBeginInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT", vk::StructureType::ePhysicalDeviceDepthBiasControlFeaturesEXT);
    e_vk_StructureType.value("DEPTH_BIAS_INFO_EXT", vk::StructureType::eDepthBiasInfoEXT);
    e_vk_StructureType.value("DEPTH_BIAS_REPRESENTATION_INFO_EXT", vk::StructureType::eDepthBiasRepresentationInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT", vk::StructureType::ePhysicalDeviceDeviceMemoryReportFeaturesEXT);
    e_vk_StructureType.value("DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT", vk::StructureType::eDeviceDeviceMemoryReportCreateInfoEXT);
    e_vk_StructureType.value("DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT", vk::StructureType::eDeviceMemoryReportCallbackDataEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT", vk::StructureType::ePhysicalDeviceRobustness2FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceRobustness2PropertiesEXT);
    e_vk_StructureType.value("SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT", vk::StructureType::eSamplerCustomBorderColorCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceCustomBorderColorPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT", vk::StructureType::ePhysicalDeviceCustomBorderColorFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_LIBRARY_CREATE_INFO_KHR", vk::StructureType::ePipelineLibraryCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV", vk::StructureType::ePhysicalDevicePresentBarrierFeaturesNV);
    e_vk_StructureType.value("SURFACE_CAPABILITIES_PRESENT_BARRIER_NV", vk::StructureType::eSurfaceCapabilitiesPresentBarrierNV);
    e_vk_StructureType.value("SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV", vk::StructureType::eSwapchainPresentBarrierCreateInfoNV);
    e_vk_StructureType.value("PRESENT_ID_KHR", vk::StructureType::ePresentIdKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR", vk::StructureType::ePhysicalDevicePresentIdFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT", vk::StructureType::ePhysicalDevicePrivateDataFeaturesEXT);
    e_vk_StructureType.value("DEVICE_PRIVATE_DATA_CREATE_INFO_EXT", vk::StructureType::eDevicePrivateDataCreateInfoEXT);
    e_vk_StructureType.value("PRIVATE_DATA_SLOT_CREATE_INFO_EXT", vk::StructureType::ePrivateDataSlotCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT", vk::StructureType::ePhysicalDevicePipelineCreationCacheControlFeaturesEXT);
    e_vk_StructureType.value("VIDEO_ENCODE_INFO_KHR", vk::StructureType::eVideoEncodeInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_RATE_CONTROL_INFO_KHR", vk::StructureType::eVideoEncodeRateControlInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR", vk::StructureType::eVideoEncodeRateControlLayerInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_CAPABILITIES_KHR", vk::StructureType::eVideoEncodeCapabilitiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_USAGE_INFO_KHR", vk::StructureType::eVideoEncodeUsageInfoKHR);
    e_vk_StructureType.value("QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR", vk::StructureType::eQueryPoolVideoEncodeFeedbackCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR", vk::StructureType::ePhysicalDeviceVideoEncodeQualityLevelInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR", vk::StructureType::eVideoEncodeQualityLevelPropertiesKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR", vk::StructureType::eVideoEncodeQualityLevelInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR", vk::StructureType::eVideoEncodeSessionParametersGetInfoKHR);
    e_vk_StructureType.value("VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR", vk::StructureType::eVideoEncodeSessionParametersFeedbackInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV", vk::StructureType::ePhysicalDeviceDiagnosticsConfigFeaturesNV);
    e_vk_StructureType.value("DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV", vk::StructureType::eDeviceDiagnosticsConfigCreateInfoNV);
    e_vk_StructureType.value("QUERY_LOW_LATENCY_SUPPORT_NV", vk::StructureType::eQueryLowLatencySupportNV);
    e_vk_StructureType.value("MEMORY_BARRIER_2KHR", vk::StructureType::eMemoryBarrier2KHR);
    e_vk_StructureType.value("BUFFER_MEMORY_BARRIER_2KHR", vk::StructureType::eBufferMemoryBarrier2KHR);
    e_vk_StructureType.value("IMAGE_MEMORY_BARRIER_2KHR", vk::StructureType::eImageMemoryBarrier2KHR);
    e_vk_StructureType.value("DEPENDENCY_INFO_KHR", vk::StructureType::eDependencyInfoKHR);
    e_vk_StructureType.value("SUBMIT_INFO_2KHR", vk::StructureType::eSubmitInfo2KHR);
    e_vk_StructureType.value("SEMAPHORE_SUBMIT_INFO_KHR", vk::StructureType::eSemaphoreSubmitInfoKHR);
    e_vk_StructureType.value("COMMAND_BUFFER_SUBMIT_INFO_KHR", vk::StructureType::eCommandBufferSubmitInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR", vk::StructureType::ePhysicalDeviceSynchronization2FeaturesKHR);
    e_vk_StructureType.value("QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2NV", vk::StructureType::eQueueFamilyCheckpointProperties2NV);
    e_vk_StructureType.value("CHECKPOINT_DATA_2NV", vk::StructureType::eCheckpointData2NV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceDescriptorBufferPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceDescriptorBufferDensityMapPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT", vk::StructureType::ePhysicalDeviceDescriptorBufferFeaturesEXT);
    e_vk_StructureType.value("DESCRIPTOR_ADDRESS_INFO_EXT", vk::StructureType::eDescriptorAddressInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_GET_INFO_EXT", vk::StructureType::eDescriptorGetInfoEXT);
    e_vk_StructureType.value("BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", vk::StructureType::eBufferCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", vk::StructureType::eImageCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", vk::StructureType::eImageViewCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", vk::StructureType::eSamplerCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT", vk::StructureType::eOpaqueCaptureDescriptorDataCreateInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_BUFFER_BINDING_INFO_EXT", vk::StructureType::eDescriptorBufferBindingInfoEXT);
    e_vk_StructureType.value("DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT", vk::StructureType::eDescriptorBufferBindingPushDescriptorBufferHandleEXT);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT", vk::StructureType::eAccelerationStructureCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT", vk::StructureType::ePhysicalDeviceGraphicsPipelineLibraryFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceGraphicsPipelineLibraryPropertiesEXT);
    e_vk_StructureType.value("GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT", vk::StructureType::eGraphicsPipelineLibraryCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD", vk::StructureType::ePhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR", vk::StructureType::ePhysicalDeviceFragmentShaderBarycentricFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceFragmentShaderBarycentricPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR", vk::StructureType::ePhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES_KHR", vk::StructureType::ePhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceFragmentShadingRateEnumsPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV", vk::StructureType::ePhysicalDeviceFragmentShadingRateEnumsFeaturesNV);
    e_vk_StructureType.value("PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV", vk::StructureType::ePipelineFragmentShadingRateEnumStateCreateInfoNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV", vk::StructureType::eAccelerationStructureGeometryMotionTrianglesDataNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV", vk::StructureType::ePhysicalDeviceRayTracingMotionBlurFeaturesNV);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_MOTION_INFO_NV", vk::StructureType::eAccelerationStructureMotionInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT", vk::StructureType::ePhysicalDeviceMeshShaderFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceMeshShaderPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT", vk::StructureType::ePhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT", vk::StructureType::ePhysicalDeviceFragmentDensityMap2FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceFragmentDensityMap2PropertiesEXT);
    e_vk_StructureType.value("COPY_COMMAND_TRANSFORM_INFO_QCOM", vk::StructureType::eCopyCommandTransformInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT", vk::StructureType::ePhysicalDeviceImageRobustnessFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR", vk::StructureType::ePhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR);
    e_vk_StructureType.value("COPY_BUFFER_INFO_2KHR", vk::StructureType::eCopyBufferInfo2KHR);
    e_vk_StructureType.value("COPY_IMAGE_INFO_2KHR", vk::StructureType::eCopyImageInfo2KHR);
    e_vk_StructureType.value("COPY_BUFFER_TO_IMAGE_INFO_2KHR", vk::StructureType::eCopyBufferToImageInfo2KHR);
    e_vk_StructureType.value("COPY_IMAGE_TO_BUFFER_INFO_2KHR", vk::StructureType::eCopyImageToBufferInfo2KHR);
    e_vk_StructureType.value("BLIT_IMAGE_INFO_2KHR", vk::StructureType::eBlitImageInfo2KHR);
    e_vk_StructureType.value("RESOLVE_IMAGE_INFO_2KHR", vk::StructureType::eResolveImageInfo2KHR);
    e_vk_StructureType.value("BUFFER_COPY_2KHR", vk::StructureType::eBufferCopy2KHR);
    e_vk_StructureType.value("IMAGE_COPY_2KHR", vk::StructureType::eImageCopy2KHR);
    e_vk_StructureType.value("IMAGE_BLIT_2KHR", vk::StructureType::eImageBlit2KHR);
    e_vk_StructureType.value("BUFFER_IMAGE_COPY_2KHR", vk::StructureType::eBufferImageCopy2KHR);
    e_vk_StructureType.value("IMAGE_RESOLVE_2KHR", vk::StructureType::eImageResolve2KHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT", vk::StructureType::ePhysicalDeviceImageCompressionControlFeaturesEXT);
    e_vk_StructureType.value("IMAGE_COMPRESSION_CONTROL_EXT", vk::StructureType::eImageCompressionControlEXT);
    e_vk_StructureType.value("SUBRESOURCE_LAYOUT_2EXT", vk::StructureType::eSubresourceLayout2EXT);
    e_vk_StructureType.value("IMAGE_SUBRESOURCE_2EXT", vk::StructureType::eImageSubresource2EXT);
    e_vk_StructureType.value("IMAGE_COMPRESSION_PROPERTIES_EXT", vk::StructureType::eImageCompressionPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT", vk::StructureType::ePhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT", vk::StructureType::ePhysicalDevice4444FormatsFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FAULT_FEATURES_EXT", vk::StructureType::ePhysicalDeviceFaultFeaturesEXT);
    e_vk_StructureType.value("DEVICE_FAULT_COUNTS_EXT", vk::StructureType::eDeviceFaultCountsEXT);
    e_vk_StructureType.value("DEVICE_FAULT_INFO_EXT", vk::StructureType::eDeviceFaultInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_ARM", vk::StructureType::ePhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RGBA_10X6_FORMATS_FEATURES_EXT", vk::StructureType::ePhysicalDeviceRgba10X6FormatsFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE", vk::StructureType::ePhysicalDeviceMutableDescriptorTypeFeaturesVALVE);
    e_vk_StructureType.value("MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE", vk::StructureType::eMutableDescriptorTypeCreateInfoVALVE);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceVertexInputDynamicStateFeaturesEXT);
    e_vk_StructureType.value("VERTEX_INPUT_BINDING_DESCRIPTION_2EXT", vk::StructureType::eVertexInputBindingDescription2EXT);
    e_vk_StructureType.value("VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2EXT", vk::StructureType::eVertexInputAttributeDescription2EXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DRM_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceDrmPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT", vk::StructureType::ePhysicalDeviceAddressBindingReportFeaturesEXT);
    e_vk_StructureType.value("DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT", vk::StructureType::eDeviceAddressBindingCallbackDataEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT", vk::StructureType::ePhysicalDeviceDepthClipControlFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT", vk::StructureType::ePipelineViewportDepthClipControlCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT", vk::StructureType::ePhysicalDevicePrimitiveTopologyListRestartFeaturesEXT);
    e_vk_StructureType.value("FORMAT_PROPERTIES_3KHR", vk::StructureType::eFormatProperties3KHR);
    e_vk_StructureType.value("SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI", vk::StructureType::eSubpassShadingPipelineCreateInfoHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI", vk::StructureType::ePhysicalDeviceSubpassShadingFeaturesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI", vk::StructureType::ePhysicalDeviceSubpassShadingPropertiesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI", vk::StructureType::ePhysicalDeviceInvocationMaskFeaturesHUAWEI);
    e_vk_StructureType.value("MEMORY_GET_REMOTE_ADDRESS_INFO_NV", vk::StructureType::eMemoryGetRemoteAddressInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV", vk::StructureType::ePhysicalDeviceExternalMemoryRdmaFeaturesNV);
    e_vk_StructureType.value("PIPELINE_PROPERTIES_IDENTIFIER_EXT", vk::StructureType::ePipelinePropertiesIdentifierEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT", vk::StructureType::ePhysicalDevicePipelinePropertiesFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_INFO_EXT", vk::StructureType::ePipelineInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT", vk::StructureType::ePhysicalDeviceFrameBoundaryFeaturesEXT);
    e_vk_StructureType.value("FRAME_BOUNDARY_EXT", vk::StructureType::eFrameBoundaryEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT", vk::StructureType::ePhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT);
    e_vk_StructureType.value("SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT", vk::StructureType::eSubpassResolvePerformanceQueryEXT);
    e_vk_StructureType.value("MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT", vk::StructureType::eMultisampledRenderToSingleSampledInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT", vk::StructureType::ePhysicalDeviceExtendedDynamicState2FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceColorWriteEnableFeaturesEXT);
    e_vk_StructureType.value("PIPELINE_COLOR_WRITE_CREATE_INFO_EXT", vk::StructureType::ePipelineColorWriteCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT", vk::StructureType::ePhysicalDevicePrimitivesGeneratedQueryFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR", vk::StructureType::ePhysicalDeviceRayTracingMaintenance1FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_EXT", vk::StructureType::ePhysicalDeviceGlobalPriorityQueryFeaturesEXT);
    e_vk_StructureType.value("QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_EXT", vk::StructureType::eQueueFamilyGlobalPriorityPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT", vk::StructureType::ePhysicalDeviceImageViewMinLodFeaturesEXT);
    e_vk_StructureType.value("IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT", vk::StructureType::eImageViewMinLodCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT", vk::StructureType::ePhysicalDeviceMultiDrawFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceMultiDrawPropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT", vk::StructureType::ePhysicalDeviceImage2DViewOf3DFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceShaderTileImageFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceShaderTileImagePropertiesEXT);
    e_vk_StructureType.value("MICROMAP_BUILD_INFO_EXT", vk::StructureType::eMicromapBuildInfoEXT);
    e_vk_StructureType.value("MICROMAP_VERSION_INFO_EXT", vk::StructureType::eMicromapVersionInfoEXT);
    e_vk_StructureType.value("COPY_MICROMAP_INFO_EXT", vk::StructureType::eCopyMicromapInfoEXT);
    e_vk_StructureType.value("COPY_MICROMAP_TO_MEMORY_INFO_EXT", vk::StructureType::eCopyMicromapToMemoryInfoEXT);
    e_vk_StructureType.value("COPY_MEMORY_TO_MICROMAP_INFO_EXT", vk::StructureType::eCopyMemoryToMicromapInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT", vk::StructureType::ePhysicalDeviceOpacityMicromapFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceOpacityMicromapPropertiesEXT);
    e_vk_StructureType.value("MICROMAP_CREATE_INFO_EXT", vk::StructureType::eMicromapCreateInfoEXT);
    e_vk_StructureType.value("MICROMAP_BUILD_SIZES_INFO_EXT", vk::StructureType::eMicromapBuildSizesInfoEXT);
    e_vk_StructureType.value("ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT", vk::StructureType::eAccelerationStructureTrianglesOpacityMicromapEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI", vk::StructureType::ePhysicalDeviceClusterCullingShaderFeaturesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI", vk::StructureType::ePhysicalDeviceClusterCullingShaderPropertiesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI", vk::StructureType::ePhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI);
    e_vk_StructureType.value("PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceBorderColorSwizzleFeaturesEXT);
    e_vk_StructureType.value("SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT", vk::StructureType::eSamplerBorderColorComponentMappingCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT", vk::StructureType::ePhysicalDevicePageableDeviceLocalMemoryFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES_KHR", vk::StructureType::ePhysicalDeviceMaintenance4FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceMaintenance4PropertiesKHR);
    e_vk_StructureType.value("DEVICE_BUFFER_MEMORY_REQUIREMENTS_KHR", vk::StructureType::eDeviceBufferMemoryRequirementsKHR);
    e_vk_StructureType.value("DEVICE_IMAGE_MEMORY_REQUIREMENTS_KHR", vk::StructureType::eDeviceImageMemoryRequirementsKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM", vk::StructureType::ePhysicalDeviceShaderCorePropertiesARM);
    e_vk_StructureType.value("DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM", vk::StructureType::eDeviceQueueShaderCoreControlCreateInfoARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM", vk::StructureType::ePhysicalDeviceSchedulingControlsFeaturesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM", vk::StructureType::ePhysicalDeviceSchedulingControlsPropertiesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT", vk::StructureType::ePhysicalDeviceImageSlicedViewOf3DFeaturesEXT);
    e_vk_StructureType.value("IMAGE_VIEW_SLICED_CREATE_INFO_EXT", vk::StructureType::eImageViewSlicedCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE", vk::StructureType::ePhysicalDeviceDescriptorSetHostMappingFeaturesVALVE);
    e_vk_StructureType.value("DESCRIPTOR_SET_BINDING_REFERENCE_VALVE", vk::StructureType::eDescriptorSetBindingReferenceVALVE);
    e_vk_StructureType.value("DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE", vk::StructureType::eDescriptorSetLayoutHostMappingInfoVALVE);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceDepthClampZeroOneFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT", vk::StructureType::ePhysicalDeviceNonSeamlessCubeMapFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM", vk::StructureType::ePhysicalDeviceRenderPassStripedFeaturesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM", vk::StructureType::ePhysicalDeviceRenderPassStripedPropertiesARM);
    e_vk_StructureType.value("RENDER_PASS_STRIPE_BEGIN_INFO_ARM", vk::StructureType::eRenderPassStripeBeginInfoARM);
    e_vk_StructureType.value("RENDER_PASS_STRIPE_INFO_ARM", vk::StructureType::eRenderPassStripeInfoARM);
    e_vk_StructureType.value("RENDER_PASS_STRIPE_SUBMIT_INFO_ARM", vk::StructureType::eRenderPassStripeSubmitInfoARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM", vk::StructureType::ePhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM", vk::StructureType::ePhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM);
    e_vk_StructureType.value("SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM", vk::StructureType::eSubpassFragmentDensityMapOffsetEndInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV", vk::StructureType::ePhysicalDeviceCopyMemoryIndirectFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceCopyMemoryIndirectPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV", vk::StructureType::ePhysicalDeviceMemoryDecompressionFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceMemoryDecompressionPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV", vk::StructureType::ePhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV);
    e_vk_StructureType.value("COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV", vk::StructureType::eComputePipelineIndirectBufferInfoNV);
    e_vk_StructureType.value("PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV", vk::StructureType::ePipelineIndirectDeviceAddressInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV", vk::StructureType::ePhysicalDeviceLinearColorAttachmentFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT", vk::StructureType::ePhysicalDeviceImageCompressionControlSwapchainFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM", vk::StructureType::ePhysicalDeviceImageProcessingFeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM", vk::StructureType::ePhysicalDeviceImageProcessingPropertiesQCOM);
    e_vk_StructureType.value("IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM", vk::StructureType::eImageViewSampleWeightCreateInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT", vk::StructureType::ePhysicalDeviceNestedCommandBufferFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceNestedCommandBufferPropertiesEXT);
    e_vk_StructureType.value("EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT", vk::StructureType::eExternalMemoryAcquireUnmodifiedEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT", vk::StructureType::ePhysicalDeviceExtendedDynamicState3FeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceExtendedDynamicState3PropertiesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT", vk::StructureType::ePhysicalDeviceSubpassMergeFeedbackFeaturesEXT);
    e_vk_StructureType.value("RENDER_PASS_CREATION_CONTROL_EXT", vk::StructureType::eRenderPassCreationControlEXT);
    e_vk_StructureType.value("RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT", vk::StructureType::eRenderPassCreationFeedbackCreateInfoEXT);
    e_vk_StructureType.value("RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT", vk::StructureType::eRenderPassSubpassFeedbackCreateInfoEXT);
    e_vk_StructureType.value("DIRECT_DRIVER_LOADING_INFO_LUNARG", vk::StructureType::eDirectDriverLoadingInfoLUNARG);
    e_vk_StructureType.value("DIRECT_DRIVER_LOADING_LIST_LUNARG", vk::StructureType::eDirectDriverLoadingListLUNARG);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT", vk::StructureType::ePhysicalDeviceShaderModuleIdentifierFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceShaderModuleIdentifierPropertiesEXT);
    e_vk_StructureType.value("PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT", vk::StructureType::ePipelineShaderStageModuleIdentifierCreateInfoEXT);
    e_vk_StructureType.value("SHADER_MODULE_IDENTIFIER_EXT", vk::StructureType::eShaderModuleIdentifierEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT", vk::StructureType::ePhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV", vk::StructureType::ePhysicalDeviceOpticalFlowFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceOpticalFlowPropertiesNV);
    e_vk_StructureType.value("OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV", vk::StructureType::eOpticalFlowImageFormatInfoNV);
    e_vk_StructureType.value("OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV", vk::StructureType::eOpticalFlowImageFormatPropertiesNV);
    e_vk_StructureType.value("OPTICAL_FLOW_SESSION_CREATE_INFO_NV", vk::StructureType::eOpticalFlowSessionCreateInfoNV);
    e_vk_StructureType.value("OPTICAL_FLOW_EXECUTE_INFO_NV", vk::StructureType::eOpticalFlowExecuteInfoNV);
    e_vk_StructureType.value("OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV", vk::StructureType::eOpticalFlowSessionCreatePrivateDataInfoNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT", vk::StructureType::ePhysicalDeviceLegacyDitheringFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT", vk::StructureType::ePhysicalDevicePipelineProtectedAccessFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR", vk::StructureType::ePhysicalDeviceMaintenance5FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceMaintenance5PropertiesKHR);
    e_vk_StructureType.value("RENDERING_AREA_INFO_KHR", vk::StructureType::eRenderingAreaInfoKHR);
    e_vk_StructureType.value("DEVICE_IMAGE_SUBRESOURCE_INFO_KHR", vk::StructureType::eDeviceImageSubresourceInfoKHR);
    e_vk_StructureType.value("SUBRESOURCE_LAYOUT_2KHR", vk::StructureType::eSubresourceLayout2KHR);
    e_vk_StructureType.value("IMAGE_SUBRESOURCE_2KHR", vk::StructureType::eImageSubresource2KHR);
    e_vk_StructureType.value("PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR", vk::StructureType::ePipelineCreateFlags2CreateInfoKHR);
    e_vk_StructureType.value("BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR", vk::StructureType::eBufferUsageFlags2CreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR", vk::StructureType::ePhysicalDeviceRayTracingPositionFetchFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT", vk::StructureType::ePhysicalDeviceShaderObjectFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT", vk::StructureType::ePhysicalDeviceShaderObjectPropertiesEXT);
    e_vk_StructureType.value("SHADER_CREATE_INFO_EXT", vk::StructureType::eShaderCreateInfoEXT);
    e_vk_StructureType.value("SHADER_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT", vk::StructureType::eShaderRequiredSubgroupSizeCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM", vk::StructureType::ePhysicalDeviceTilePropertiesFeaturesQCOM);
    e_vk_StructureType.value("TILE_PROPERTIES_QCOM", vk::StructureType::eTilePropertiesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC", vk::StructureType::ePhysicalDeviceAmigoProfilingFeaturesSEC);
    e_vk_StructureType.value("AMIGO_PROFILING_SUBMIT_INFO_SEC", vk::StructureType::eAmigoProfilingSubmitInfoSEC);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM", vk::StructureType::ePhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV", vk::StructureType::ePhysicalDeviceRayTracingInvocationReorderFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceRayTracingInvocationReorderPropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV", vk::StructureType::ePhysicalDeviceExtendedSparseAddressSpaceFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV", vk::StructureType::ePhysicalDeviceExtendedSparseAddressSpacePropertiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceMutableDescriptorTypeFeaturesEXT);
    e_vk_StructureType.value("MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT", vk::StructureType::eMutableDescriptorTypeCreateInfoEXT);
    e_vk_StructureType.value("LAYER_SETTINGS_CREATE_INFO_EXT", vk::StructureType::eLayerSettingsCreateInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM", vk::StructureType::ePhysicalDeviceShaderCoreBuiltinsFeaturesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM", vk::StructureType::ePhysicalDeviceShaderCoreBuiltinsPropertiesARM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT", vk::StructureType::ePhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT", vk::StructureType::ePhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT);
    e_vk_StructureType.value("LATENCY_SLEEP_MODE_INFO_NV", vk::StructureType::eLatencySleepModeInfoNV);
    e_vk_StructureType.value("LATENCY_SLEEP_INFO_NV", vk::StructureType::eLatencySleepInfoNV);
    e_vk_StructureType.value("SET_LATENCY_MARKER_INFO_NV", vk::StructureType::eSetLatencyMarkerInfoNV);
    e_vk_StructureType.value("GET_LATENCY_MARKER_INFO_NV", vk::StructureType::eGetLatencyMarkerInfoNV);
    e_vk_StructureType.value("LATENCY_TIMINGS_FRAME_REPORT_NV", vk::StructureType::eLatencyTimingsFrameReportNV);
    e_vk_StructureType.value("LATENCY_SUBMISSION_PRESENT_ID_NV", vk::StructureType::eLatencySubmissionPresentIdNV);
    e_vk_StructureType.value("OUT_OF_BAND_QUEUE_TYPE_INFO_NV", vk::StructureType::eOutOfBandQueueTypeInfoNV);
    e_vk_StructureType.value("SWAPCHAIN_LATENCY_CREATE_INFO_NV", vk::StructureType::eSwapchainLatencyCreateInfoNV);
    e_vk_StructureType.value("LATENCY_SURFACE_CAPABILITIES_NV", vk::StructureType::eLatencySurfaceCapabilitiesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR", vk::StructureType::ePhysicalDeviceCooperativeMatrixFeaturesKHR);
    e_vk_StructureType.value("COOPERATIVE_MATRIX_PROPERTIES_KHR", vk::StructureType::eCooperativeMatrixPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceCooperativeMatrixPropertiesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM", vk::StructureType::ePhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM);
    e_vk_StructureType.value("MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM", vk::StructureType::eMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR", vk::StructureType::ePhysicalDeviceVideoMaintenance1FeaturesKHR);
    e_vk_StructureType.value("VIDEO_INLINE_QUERY_INFO_KHR", vk::StructureType::eVideoInlineQueryInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV", vk::StructureType::ePhysicalDevicePerStageDescriptorSetFeaturesNV);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM", vk::StructureType::ePhysicalDeviceImageProcessing2FeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM", vk::StructureType::ePhysicalDeviceImageProcessing2PropertiesQCOM);
    e_vk_StructureType.value("SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM", vk::StructureType::eSamplerBlockMatchWindowCreateInfoQCOM);
    e_vk_StructureType.value("SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM", vk::StructureType::eSamplerCubicWeightsCreateInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM", vk::StructureType::ePhysicalDeviceCubicWeightsFeaturesQCOM);
    e_vk_StructureType.value("BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM", vk::StructureType::eBlitImageCubicWeightsInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM", vk::StructureType::ePhysicalDeviceYcbcrDegammaFeaturesQCOM);
    e_vk_StructureType.value("SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM", vk::StructureType::eSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM", vk::StructureType::ePhysicalDeviceCubicClampFeaturesQCOM);
    e_vk_StructureType.value("PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT", vk::StructureType::ePhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceVertexAttributeDivisorPropertiesKHR);
    e_vk_StructureType.value("PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR", vk::StructureType::ePipelineVertexInputDivisorStateCreateInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR", vk::StructureType::ePhysicalDeviceVertexAttributeDivisorFeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT", vk::StructureType::ePhysicalDeviceLayeredDriverPropertiesMSFT);
    e_vk_StructureType.value("CALIBRATED_TIMESTAMP_INFO_KHR", vk::StructureType::eCalibratedTimestampInfoKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR", vk::StructureType::ePhysicalDeviceMaintenance6FeaturesKHR);
    e_vk_StructureType.value("PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR", vk::StructureType::ePhysicalDeviceMaintenance6PropertiesKHR);
    e_vk_StructureType.value("BIND_MEMORY_STATUS_KHR", vk::StructureType::eBindMemoryStatusKHR);
    e_vk_StructureType.value("BIND_DESCRIPTOR_SETS_INFO_KHR", vk::StructureType::eBindDescriptorSetsInfoKHR);
    e_vk_StructureType.value("PUSH_CONSTANTS_INFO_KHR", vk::StructureType::ePushConstantsInfoKHR);
    e_vk_StructureType.value("PUSH_DESCRIPTOR_SET_INFO_KHR", vk::StructureType::ePushDescriptorSetInfoKHR);
    e_vk_StructureType.value("PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR", vk::StructureType::ePushDescriptorSetWithTemplateInfoKHR);
    e_vk_StructureType.value("SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT", vk::StructureType::eSetDescriptorBufferOffsetsInfoEXT);
    e_vk_StructureType.value("BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT", vk::StructureType::eBindDescriptorBufferEmbeddedSamplersInfoEXT);
    e_vk_StructureType.value("PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV", vk::StructureType::ePhysicalDeviceDescriptorPoolOverallocationFeaturesNV);

    py::enum_<vk::SubpassContents> e_vk_SubpassContents(m_vk, "SubpassContents");
    e_vk_SubpassContents.value("INLINE", vk::SubpassContents::eInline);
    e_vk_SubpassContents.value("SECONDARY_COMMAND_BUFFERS", vk::SubpassContents::eSecondaryCommandBuffers);
    e_vk_SubpassContents.value("INLINE_AND_SECONDARY_COMMAND_BUFFERS_EXT", vk::SubpassContents::eInlineAndSecondaryCommandBuffersEXT);

    py::enum_<vk::SubpassDescriptionFlagBits> e_vk_SubpassDescriptionFlagBits(m_vk, "SubpassDescriptionFlagBits");
    e_vk_SubpassDescriptionFlagBits.value("PER_VIEW_ATTRIBUTES_NVX", vk::SubpassDescriptionFlagBits::ePerViewAttributesNVX);
    e_vk_SubpassDescriptionFlagBits.value("PER_VIEW_POSITION_X_ONLY_NVX", vk::SubpassDescriptionFlagBits::ePerViewPositionXOnlyNVX);
    e_vk_SubpassDescriptionFlagBits.value("FRAGMENT_REGION_QCOM", vk::SubpassDescriptionFlagBits::eFragmentRegionQCOM);
    e_vk_SubpassDescriptionFlagBits.value("SHADER_RESOLVE_QCOM", vk::SubpassDescriptionFlagBits::eShaderResolveQCOM);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_ARM", vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentColorAccessARM);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_ARM", vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentDepthAccessARM);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_ARM", vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentStencilAccessARM);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_EXT", vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentColorAccessEXT);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_EXT", vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentDepthAccessEXT);
    e_vk_SubpassDescriptionFlagBits.value("RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_EXT", vk::SubpassDescriptionFlagBits::eRasterizationOrderAttachmentStencilAccessEXT);
    e_vk_SubpassDescriptionFlagBits.value("ENABLE_LEGACY_DITHERING_EXT", vk::SubpassDescriptionFlagBits::eEnableLegacyDitheringEXT);

    py::enum_<vk::SystemAllocationScope> e_vk_SystemAllocationScope(m_vk, "SystemAllocationScope");
    e_vk_SystemAllocationScope.value("COMMAND", vk::SystemAllocationScope::eCommand);
    e_vk_SystemAllocationScope.value("OBJECT", vk::SystemAllocationScope::eObject);
    e_vk_SystemAllocationScope.value("CACHE", vk::SystemAllocationScope::eCache);
    e_vk_SystemAllocationScope.value("DEVICE", vk::SystemAllocationScope::eDevice);
    e_vk_SystemAllocationScope.value("INSTANCE", vk::SystemAllocationScope::eInstance);

    py::enum_<vk::VendorId> e_vk_VendorId(m_vk, "VendorId");
    e_vk_VendorId.value("VIV", vk::VendorId::eVIV);
    e_vk_VendorId.value("VSI", vk::VendorId::eVSI);
    e_vk_VendorId.value("KAZAN", vk::VendorId::eKazan);
    e_vk_VendorId.value("CODEPLAY", vk::VendorId::eCodeplay);
    e_vk_VendorId.value("MESA", vk::VendorId::eMESA);
    e_vk_VendorId.value("POCL", vk::VendorId::ePocl);
    e_vk_VendorId.value("MOBILEYE", vk::VendorId::eMobileye);

    py::enum_<vk::VertexInputRate> e_vk_VertexInputRate(m_vk, "VertexInputRate");
    e_vk_VertexInputRate.value("VERTEX", vk::VertexInputRate::eVertex);
    e_vk_VertexInputRate.value("INSTANCE", vk::VertexInputRate::eInstance);

    py::enum_<vk::ChromaLocation> e_vk_ChromaLocation(m_vk, "ChromaLocation");
    e_vk_ChromaLocation.value("COSITED_EVEN", vk::ChromaLocation::eCositedEven);
    e_vk_ChromaLocation.value("MIDPOINT", vk::ChromaLocation::eMidpoint);

    py::enum_<vk::CommandPoolTrimFlagBits> e_vk_CommandPoolTrimFlagBits(m_vk, "CommandPoolTrimFlagBits");

    py::enum_<vk::DescriptorUpdateTemplateCreateFlagBits> e_vk_DescriptorUpdateTemplateCreateFlagBits(m_vk, "DescriptorUpdateTemplateCreateFlagBits");

    py::enum_<vk::DescriptorUpdateTemplateType> e_vk_DescriptorUpdateTemplateType(m_vk, "DescriptorUpdateTemplateType");
    e_vk_DescriptorUpdateTemplateType.value("DESCRIPTOR_SET", vk::DescriptorUpdateTemplateType::eDescriptorSet);
    e_vk_DescriptorUpdateTemplateType.value("PUSH_DESCRIPTORS_KHR", vk::DescriptorUpdateTemplateType::ePushDescriptorsKHR);

    py::enum_<vk::ExternalFenceFeatureFlagBits> e_vk_ExternalFenceFeatureFlagBits(m_vk, "ExternalFenceFeatureFlagBits");
    e_vk_ExternalFenceFeatureFlagBits.value("EXPORTABLE", vk::ExternalFenceFeatureFlagBits::eExportable);
    e_vk_ExternalFenceFeatureFlagBits.value("IMPORTABLE", vk::ExternalFenceFeatureFlagBits::eImportable);

    py::enum_<vk::ExternalFenceHandleTypeFlagBits> e_vk_ExternalFenceHandleTypeFlagBits(m_vk, "ExternalFenceHandleTypeFlagBits");
    e_vk_ExternalFenceHandleTypeFlagBits.value("OPAQUE_FD", vk::ExternalFenceHandleTypeFlagBits::eOpaqueFd);
    e_vk_ExternalFenceHandleTypeFlagBits.value("OPAQUE_WIN_32", vk::ExternalFenceHandleTypeFlagBits::eOpaqueWin32);
    e_vk_ExternalFenceHandleTypeFlagBits.value("OPAQUE_WIN_32_KMT", vk::ExternalFenceHandleTypeFlagBits::eOpaqueWin32Kmt);
    e_vk_ExternalFenceHandleTypeFlagBits.value("SYNC_FD", vk::ExternalFenceHandleTypeFlagBits::eSyncFd);

    py::enum_<vk::ExternalMemoryFeatureFlagBits> e_vk_ExternalMemoryFeatureFlagBits(m_vk, "ExternalMemoryFeatureFlagBits");
    e_vk_ExternalMemoryFeatureFlagBits.value("DEDICATED_ONLY", vk::ExternalMemoryFeatureFlagBits::eDedicatedOnly);
    e_vk_ExternalMemoryFeatureFlagBits.value("EXPORTABLE", vk::ExternalMemoryFeatureFlagBits::eExportable);
    e_vk_ExternalMemoryFeatureFlagBits.value("IMPORTABLE", vk::ExternalMemoryFeatureFlagBits::eImportable);

    py::enum_<vk::ExternalMemoryHandleTypeFlagBits> e_vk_ExternalMemoryHandleTypeFlagBits(m_vk, "ExternalMemoryHandleTypeFlagBits");
    e_vk_ExternalMemoryHandleTypeFlagBits.value("OPAQUE_FD", vk::ExternalMemoryHandleTypeFlagBits::eOpaqueFd);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("OPAQUE_WIN_32", vk::ExternalMemoryHandleTypeFlagBits::eOpaqueWin32);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("OPAQUE_WIN_32_KMT", vk::ExternalMemoryHandleTypeFlagBits::eOpaqueWin32Kmt);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("D3D11_TEXTURE", vk::ExternalMemoryHandleTypeFlagBits::eD3D11Texture);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("D3D11_TEXTURE_KMT", vk::ExternalMemoryHandleTypeFlagBits::eD3D11TextureKmt);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("D3D12_HEAP", vk::ExternalMemoryHandleTypeFlagBits::eD3D12Heap);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("D3D12_RESOURCE", vk::ExternalMemoryHandleTypeFlagBits::eD3D12Resource);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("DMA_BUF_EXT", vk::ExternalMemoryHandleTypeFlagBits::eDmaBufEXT);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("HOST_ALLOCATION_EXT", vk::ExternalMemoryHandleTypeFlagBits::eHostAllocationEXT);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("HOST_MAPPED_FOREIGN_MEMORY_EXT", vk::ExternalMemoryHandleTypeFlagBits::eHostMappedForeignMemoryEXT);
    e_vk_ExternalMemoryHandleTypeFlagBits.value("RDMA_ADDRESS_NV", vk::ExternalMemoryHandleTypeFlagBits::eRdmaAddressNV);

    py::enum_<vk::ExternalSemaphoreFeatureFlagBits> e_vk_ExternalSemaphoreFeatureFlagBits(m_vk, "ExternalSemaphoreFeatureFlagBits");
    e_vk_ExternalSemaphoreFeatureFlagBits.value("EXPORTABLE", vk::ExternalSemaphoreFeatureFlagBits::eExportable);
    e_vk_ExternalSemaphoreFeatureFlagBits.value("IMPORTABLE", vk::ExternalSemaphoreFeatureFlagBits::eImportable);

    py::enum_<vk::ExternalSemaphoreHandleTypeFlagBits> e_vk_ExternalSemaphoreHandleTypeFlagBits(m_vk, "ExternalSemaphoreHandleTypeFlagBits");
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("OPAQUE_FD", vk::ExternalSemaphoreHandleTypeFlagBits::eOpaqueFd);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("OPAQUE_WIN_32", vk::ExternalSemaphoreHandleTypeFlagBits::eOpaqueWin32);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("OPAQUE_WIN_32_KMT", vk::ExternalSemaphoreHandleTypeFlagBits::eOpaqueWin32Kmt);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("D3D12_FENCE", vk::ExternalSemaphoreHandleTypeFlagBits::eD3D12Fence);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("D3D11_FENCE", vk::ExternalSemaphoreHandleTypeFlagBits::eD3D11Fence);
    e_vk_ExternalSemaphoreHandleTypeFlagBits.value("SYNC_FD", vk::ExternalSemaphoreHandleTypeFlagBits::eSyncFd);

    py::enum_<vk::FenceImportFlagBits> e_vk_FenceImportFlagBits(m_vk, "FenceImportFlagBits");
    e_vk_FenceImportFlagBits.value("TEMPORARY", vk::FenceImportFlagBits::eTemporary);

    py::enum_<vk::MemoryAllocateFlagBits> e_vk_MemoryAllocateFlagBits(m_vk, "MemoryAllocateFlagBits");
    e_vk_MemoryAllocateFlagBits.value("DEVICE_MASK", vk::MemoryAllocateFlagBits::eDeviceMask);
    e_vk_MemoryAllocateFlagBits.value("DEVICE_ADDRESS", vk::MemoryAllocateFlagBits::eDeviceAddress);
    e_vk_MemoryAllocateFlagBits.value("DEVICE_ADDRESS_CAPTURE_REPLAY", vk::MemoryAllocateFlagBits::eDeviceAddressCaptureReplay);

    py::enum_<vk::PeerMemoryFeatureFlagBits> e_vk_PeerMemoryFeatureFlagBits(m_vk, "PeerMemoryFeatureFlagBits");
    e_vk_PeerMemoryFeatureFlagBits.value("COPY_SRC", vk::PeerMemoryFeatureFlagBits::eCopySrc);
    e_vk_PeerMemoryFeatureFlagBits.value("COPY_DST", vk::PeerMemoryFeatureFlagBits::eCopyDst);
    e_vk_PeerMemoryFeatureFlagBits.value("GENERIC_SRC", vk::PeerMemoryFeatureFlagBits::eGenericSrc);
    e_vk_PeerMemoryFeatureFlagBits.value("GENERIC_DST", vk::PeerMemoryFeatureFlagBits::eGenericDst);

    py::enum_<vk::PointClippingBehavior> e_vk_PointClippingBehavior(m_vk, "PointClippingBehavior");
    e_vk_PointClippingBehavior.value("ALL_CLIP_PLANES", vk::PointClippingBehavior::eAllClipPlanes);
    e_vk_PointClippingBehavior.value("USER_CLIP_PLANES_ONLY", vk::PointClippingBehavior::eUserClipPlanesOnly);

    py::enum_<vk::SamplerYcbcrModelConversion> e_vk_SamplerYcbcrModelConversion(m_vk, "SamplerYcbcrModelConversion");
    e_vk_SamplerYcbcrModelConversion.value("RGB_IDENTITY", vk::SamplerYcbcrModelConversion::eRgbIdentity);
    e_vk_SamplerYcbcrModelConversion.value("YCBCR_IDENTITY", vk::SamplerYcbcrModelConversion::eYcbcrIdentity);
    e_vk_SamplerYcbcrModelConversion.value("YCBCR_709", vk::SamplerYcbcrModelConversion::eYcbcr709);
    e_vk_SamplerYcbcrModelConversion.value("YCBCR_601", vk::SamplerYcbcrModelConversion::eYcbcr601);
    e_vk_SamplerYcbcrModelConversion.value("YCBCR_2020", vk::SamplerYcbcrModelConversion::eYcbcr2020);

    py::enum_<vk::SamplerYcbcrRange> e_vk_SamplerYcbcrRange(m_vk, "SamplerYcbcrRange");
    e_vk_SamplerYcbcrRange.value("ITU_FULL", vk::SamplerYcbcrRange::eItuFull);
    e_vk_SamplerYcbcrRange.value("ITU_NARROW", vk::SamplerYcbcrRange::eItuNarrow);

    py::enum_<vk::SemaphoreImportFlagBits> e_vk_SemaphoreImportFlagBits(m_vk, "SemaphoreImportFlagBits");
    e_vk_SemaphoreImportFlagBits.value("TEMPORARY", vk::SemaphoreImportFlagBits::eTemporary);

    py::enum_<vk::SubgroupFeatureFlagBits> e_vk_SubgroupFeatureFlagBits(m_vk, "SubgroupFeatureFlagBits");
    e_vk_SubgroupFeatureFlagBits.value("BASIC", vk::SubgroupFeatureFlagBits::eBasic);
    e_vk_SubgroupFeatureFlagBits.value("VOTE", vk::SubgroupFeatureFlagBits::eVote);
    e_vk_SubgroupFeatureFlagBits.value("ARITHMETIC", vk::SubgroupFeatureFlagBits::eArithmetic);
    e_vk_SubgroupFeatureFlagBits.value("BALLOT", vk::SubgroupFeatureFlagBits::eBallot);
    e_vk_SubgroupFeatureFlagBits.value("SHUFFLE", vk::SubgroupFeatureFlagBits::eShuffle);
    e_vk_SubgroupFeatureFlagBits.value("SHUFFLE_RELATIVE", vk::SubgroupFeatureFlagBits::eShuffleRelative);
    e_vk_SubgroupFeatureFlagBits.value("CLUSTERED", vk::SubgroupFeatureFlagBits::eClustered);
    e_vk_SubgroupFeatureFlagBits.value("QUAD", vk::SubgroupFeatureFlagBits::eQuad);
    e_vk_SubgroupFeatureFlagBits.value("PARTITIONED_NV", vk::SubgroupFeatureFlagBits::ePartitionedNV);

    py::enum_<vk::TessellationDomainOrigin> e_vk_TessellationDomainOrigin(m_vk, "TessellationDomainOrigin");
    e_vk_TessellationDomainOrigin.value("UPPER_LEFT", vk::TessellationDomainOrigin::eUpperLeft);
    e_vk_TessellationDomainOrigin.value("LOWER_LEFT", vk::TessellationDomainOrigin::eLowerLeft);

    py::enum_<vk::DescriptorBindingFlagBits> e_vk_DescriptorBindingFlagBits(m_vk, "DescriptorBindingFlagBits");
    e_vk_DescriptorBindingFlagBits.value("UPDATE_AFTER_BIND", vk::DescriptorBindingFlagBits::eUpdateAfterBind);
    e_vk_DescriptorBindingFlagBits.value("UPDATE_UNUSED_WHILE_PENDING", vk::DescriptorBindingFlagBits::eUpdateUnusedWhilePending);
    e_vk_DescriptorBindingFlagBits.value("PARTIALLY_BOUND", vk::DescriptorBindingFlagBits::ePartiallyBound);
    e_vk_DescriptorBindingFlagBits.value("VARIABLE_DESCRIPTOR_COUNT", vk::DescriptorBindingFlagBits::eVariableDescriptorCount);

    py::enum_<vk::DriverId> e_vk_DriverId(m_vk, "DriverId");
    e_vk_DriverId.value("AMD_PROPRIETARY", vk::DriverId::eAmdProprietary);
    e_vk_DriverId.value("AMD_OPEN_SOURCE", vk::DriverId::eAmdOpenSource);
    e_vk_DriverId.value("MESA_RADV", vk::DriverId::eMesaRadv);
    e_vk_DriverId.value("NVIDIA_PROPRIETARY", vk::DriverId::eNvidiaProprietary);
    e_vk_DriverId.value("INTEL_PROPRIETARY_WINDOWS", vk::DriverId::eIntelProprietaryWindows);
    e_vk_DriverId.value("INTEL_OPEN_SOURCE_MESA", vk::DriverId::eIntelOpenSourceMESA);
    e_vk_DriverId.value("IMAGINATION_PROPRIETARY", vk::DriverId::eImaginationProprietary);
    e_vk_DriverId.value("QUALCOMM_PROPRIETARY", vk::DriverId::eQualcommProprietary);
    e_vk_DriverId.value("ARM_PROPRIETARY", vk::DriverId::eArmProprietary);
    e_vk_DriverId.value("GOOGLE_SWIFTSHADER", vk::DriverId::eGoogleSwiftshader);
    e_vk_DriverId.value("GGP_PROPRIETARY", vk::DriverId::eGgpProprietary);
    e_vk_DriverId.value("BROADCOM_PROPRIETARY", vk::DriverId::eBroadcomProprietary);
    e_vk_DriverId.value("MESA_LLVMPIPE", vk::DriverId::eMesaLlvmpipe);
    e_vk_DriverId.value("MOLTENVK", vk::DriverId::eMoltenvk);
    e_vk_DriverId.value("COREAVI_PROPRIETARY", vk::DriverId::eCoreaviProprietary);
    e_vk_DriverId.value("JUICE_PROPRIETARY", vk::DriverId::eJuiceProprietary);
    e_vk_DriverId.value("VERISILICON_PROPRIETARY", vk::DriverId::eVerisiliconProprietary);
    e_vk_DriverId.value("MESA_TURNIP", vk::DriverId::eMesaTurnip);
    e_vk_DriverId.value("MESA_V3_DV", vk::DriverId::eMesaV3Dv);
    e_vk_DriverId.value("MESA_PANVK", vk::DriverId::eMesaPanvk);
    e_vk_DriverId.value("SAMSUNG_PROPRIETARY", vk::DriverId::eSamsungProprietary);
    e_vk_DriverId.value("MESA_VENUS", vk::DriverId::eMesaVenus);
    e_vk_DriverId.value("MESA_DOZEN", vk::DriverId::eMesaDozen);
    e_vk_DriverId.value("MESA_NVK", vk::DriverId::eMesaNvk);
    e_vk_DriverId.value("IMAGINATION_OPEN_SOURCE_MESA", vk::DriverId::eImaginationOpenSourceMESA);
    e_vk_DriverId.value("MESA_AGXV", vk::DriverId::eMesaAgxv);

    py::enum_<vk::ResolveModeFlagBits> e_vk_ResolveModeFlagBits(m_vk, "ResolveModeFlagBits");
    e_vk_ResolveModeFlagBits.value("NONE", vk::ResolveModeFlagBits::eNone);
    e_vk_ResolveModeFlagBits.value("SAMPLE_ZERO", vk::ResolveModeFlagBits::eSampleZero);
    e_vk_ResolveModeFlagBits.value("AVERAGE", vk::ResolveModeFlagBits::eAverage);
    e_vk_ResolveModeFlagBits.value("MIN", vk::ResolveModeFlagBits::eMin);
    e_vk_ResolveModeFlagBits.value("MAX", vk::ResolveModeFlagBits::eMax);

    py::enum_<vk::SamplerReductionMode> e_vk_SamplerReductionMode(m_vk, "SamplerReductionMode");
    e_vk_SamplerReductionMode.value("WEIGHTED_AVERAGE", vk::SamplerReductionMode::eWeightedAverage);
    e_vk_SamplerReductionMode.value("MIN", vk::SamplerReductionMode::eMin);
    e_vk_SamplerReductionMode.value("MAX", vk::SamplerReductionMode::eMax);
    e_vk_SamplerReductionMode.value("WEIGHTED_AVERAGE_RANGECLAMP_QCOM", vk::SamplerReductionMode::eWeightedAverageRangeclampQCOM);

    py::enum_<vk::SemaphoreType> e_vk_SemaphoreType(m_vk, "SemaphoreType");
    e_vk_SemaphoreType.value("BINARY", vk::SemaphoreType::eBinary);
    e_vk_SemaphoreType.value("TIMELINE", vk::SemaphoreType::eTimeline);

    py::enum_<vk::SemaphoreWaitFlagBits> e_vk_SemaphoreWaitFlagBits(m_vk, "SemaphoreWaitFlagBits");
    e_vk_SemaphoreWaitFlagBits.value("ANY", vk::SemaphoreWaitFlagBits::eAny);

    py::enum_<vk::ShaderFloatControlsIndependence> e_vk_ShaderFloatControlsIndependence(m_vk, "ShaderFloatControlsIndependence");
    e_vk_ShaderFloatControlsIndependence.value("_32_BIT_ONLY", vk::ShaderFloatControlsIndependence::e32BitOnly);
    e_vk_ShaderFloatControlsIndependence.value("ALL", vk::ShaderFloatControlsIndependence::eAll);
    e_vk_ShaderFloatControlsIndependence.value("NONE", vk::ShaderFloatControlsIndependence::eNone);

    py::enum_<vk::AccessFlagBits2> e_vk_AccessFlagBits2(m_vk, "AccessFlagBits2");
    e_vk_AccessFlagBits2.value("NONE", vk::AccessFlagBits2::eNone);
    e_vk_AccessFlagBits2.value("INDIRECT_COMMAND_READ", vk::AccessFlagBits2::eIndirectCommandRead);
    e_vk_AccessFlagBits2.value("INDEX_READ", vk::AccessFlagBits2::eIndexRead);
    e_vk_AccessFlagBits2.value("VERTEX_ATTRIBUTE_READ", vk::AccessFlagBits2::eVertexAttributeRead);
    e_vk_AccessFlagBits2.value("UNIFORM_READ", vk::AccessFlagBits2::eUniformRead);
    e_vk_AccessFlagBits2.value("INPUT_ATTACHMENT_READ", vk::AccessFlagBits2::eInputAttachmentRead);
    e_vk_AccessFlagBits2.value("SHADER_READ", vk::AccessFlagBits2::eShaderRead);
    e_vk_AccessFlagBits2.value("SHADER_WRITE", vk::AccessFlagBits2::eShaderWrite);
    e_vk_AccessFlagBits2.value("COLOR_ATTACHMENT_READ", vk::AccessFlagBits2::eColorAttachmentRead);
    e_vk_AccessFlagBits2.value("COLOR_ATTACHMENT_WRITE", vk::AccessFlagBits2::eColorAttachmentWrite);
    e_vk_AccessFlagBits2.value("DEPTH_STENCIL_ATTACHMENT_READ", vk::AccessFlagBits2::eDepthStencilAttachmentRead);
    e_vk_AccessFlagBits2.value("DEPTH_STENCIL_ATTACHMENT_WRITE", vk::AccessFlagBits2::eDepthStencilAttachmentWrite);
    e_vk_AccessFlagBits2.value("TRANSFER_READ", vk::AccessFlagBits2::eTransferRead);
    e_vk_AccessFlagBits2.value("TRANSFER_WRITE", vk::AccessFlagBits2::eTransferWrite);
    e_vk_AccessFlagBits2.value("HOST_READ", vk::AccessFlagBits2::eHostRead);
    e_vk_AccessFlagBits2.value("HOST_WRITE", vk::AccessFlagBits2::eHostWrite);
    e_vk_AccessFlagBits2.value("MEMORY_READ", vk::AccessFlagBits2::eMemoryRead);
    e_vk_AccessFlagBits2.value("MEMORY_WRITE", vk::AccessFlagBits2::eMemoryWrite);
    e_vk_AccessFlagBits2.value("SHADER_SAMPLED_READ", vk::AccessFlagBits2::eShaderSampledRead);
    e_vk_AccessFlagBits2.value("SHADER_STORAGE_READ", vk::AccessFlagBits2::eShaderStorageRead);
    e_vk_AccessFlagBits2.value("SHADER_STORAGE_WRITE", vk::AccessFlagBits2::eShaderStorageWrite);
    e_vk_AccessFlagBits2.value("VIDEO_DECODE_READ_KHR", vk::AccessFlagBits2::eVideoDecodeReadKHR);
    e_vk_AccessFlagBits2.value("VIDEO_DECODE_WRITE_KHR", vk::AccessFlagBits2::eVideoDecodeWriteKHR);
    e_vk_AccessFlagBits2.value("VIDEO_ENCODE_READ_KHR", vk::AccessFlagBits2::eVideoEncodeReadKHR);
    e_vk_AccessFlagBits2.value("VIDEO_ENCODE_WRITE_KHR", vk::AccessFlagBits2::eVideoEncodeWriteKHR);
    e_vk_AccessFlagBits2.value("TRANSFORM_FEEDBACK_WRITE_EXT", vk::AccessFlagBits2::eTransformFeedbackWriteEXT);
    e_vk_AccessFlagBits2.value("TRANSFORM_FEEDBACK_COUNTER_READ_EXT", vk::AccessFlagBits2::eTransformFeedbackCounterReadEXT);
    e_vk_AccessFlagBits2.value("TRANSFORM_FEEDBACK_COUNTER_WRITE_EXT", vk::AccessFlagBits2::eTransformFeedbackCounterWriteEXT);
    e_vk_AccessFlagBits2.value("CONDITIONAL_RENDERING_READ_EXT", vk::AccessFlagBits2::eConditionalRenderingReadEXT);
    e_vk_AccessFlagBits2.value("COMMAND_PREPROCESS_READ_NV", vk::AccessFlagBits2::eCommandPreprocessReadNV);
    e_vk_AccessFlagBits2.value("COMMAND_PREPROCESS_WRITE_NV", vk::AccessFlagBits2::eCommandPreprocessWriteNV);
    e_vk_AccessFlagBits2.value("FRAGMENT_SHADING_RATE_ATTACHMENT_READ_KHR", vk::AccessFlagBits2::eFragmentShadingRateAttachmentReadKHR);
    e_vk_AccessFlagBits2.value("SHADING_RATE_IMAGE_READ_NV", vk::AccessFlagBits2::eShadingRateImageReadNV);
    e_vk_AccessFlagBits2.value("ACCELERATION_STRUCTURE_READ_KHR", vk::AccessFlagBits2::eAccelerationStructureReadKHR);
    e_vk_AccessFlagBits2.value("ACCELERATION_STRUCTURE_WRITE_KHR", vk::AccessFlagBits2::eAccelerationStructureWriteKHR);
    e_vk_AccessFlagBits2.value("ACCELERATION_STRUCTURE_READ_NV", vk::AccessFlagBits2::eAccelerationStructureReadNV);
    e_vk_AccessFlagBits2.value("ACCELERATION_STRUCTURE_WRITE_NV", vk::AccessFlagBits2::eAccelerationStructureWriteNV);
    e_vk_AccessFlagBits2.value("FRAGMENT_DENSITY_MAP_READ_EXT", vk::AccessFlagBits2::eFragmentDensityMapReadEXT);
    e_vk_AccessFlagBits2.value("COLOR_ATTACHMENT_READ_NONCOHERENT_EXT", vk::AccessFlagBits2::eColorAttachmentReadNoncoherentEXT);
    e_vk_AccessFlagBits2.value("DESCRIPTOR_BUFFER_READ_EXT", vk::AccessFlagBits2::eDescriptorBufferReadEXT);
    e_vk_AccessFlagBits2.value("INVOCATION_MASK_READ_HUAWEI", vk::AccessFlagBits2::eInvocationMaskReadHUAWEI);
    e_vk_AccessFlagBits2.value("SHADER_BINDING_TABLE_READ_KHR", vk::AccessFlagBits2::eShaderBindingTableReadKHR);
    e_vk_AccessFlagBits2.value("MICROMAP_READ_EXT", vk::AccessFlagBits2::eMicromapReadEXT);
    e_vk_AccessFlagBits2.value("MICROMAP_WRITE_EXT", vk::AccessFlagBits2::eMicromapWriteEXT);
    e_vk_AccessFlagBits2.value("OPTICAL_FLOW_READ_NV", vk::AccessFlagBits2::eOpticalFlowReadNV);
    e_vk_AccessFlagBits2.value("OPTICAL_FLOW_WRITE_NV", vk::AccessFlagBits2::eOpticalFlowWriteNV);

    py::enum_<vk::FormatFeatureFlagBits2> e_vk_FormatFeatureFlagBits2(m_vk, "FormatFeatureFlagBits2");
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE", vk::FormatFeatureFlagBits2::eSampledImage);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_IMAGE", vk::FormatFeatureFlagBits2::eStorageImage);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_IMAGE_ATOMIC", vk::FormatFeatureFlagBits2::eStorageImageAtomic);
    e_vk_FormatFeatureFlagBits2.value("UNIFORM_TEXEL_BUFFER", vk::FormatFeatureFlagBits2::eUniformTexelBuffer);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_TEXEL_BUFFER", vk::FormatFeatureFlagBits2::eStorageTexelBuffer);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_TEXEL_BUFFER_ATOMIC", vk::FormatFeatureFlagBits2::eStorageTexelBufferAtomic);
    e_vk_FormatFeatureFlagBits2.value("VERTEX_BUFFER", vk::FormatFeatureFlagBits2::eVertexBuffer);
    e_vk_FormatFeatureFlagBits2.value("COLOR_ATTACHMENT", vk::FormatFeatureFlagBits2::eColorAttachment);
    e_vk_FormatFeatureFlagBits2.value("COLOR_ATTACHMENT_BLEND", vk::FormatFeatureFlagBits2::eColorAttachmentBlend);
    e_vk_FormatFeatureFlagBits2.value("DEPTH_STENCIL_ATTACHMENT", vk::FormatFeatureFlagBits2::eDepthStencilAttachment);
    e_vk_FormatFeatureFlagBits2.value("BLIT_SRC", vk::FormatFeatureFlagBits2::eBlitSrc);
    e_vk_FormatFeatureFlagBits2.value("BLIT_DST", vk::FormatFeatureFlagBits2::eBlitDst);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_FILTER_LINEAR", vk::FormatFeatureFlagBits2::eSampledImageFilterLinear);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_FILTER_CUBIC", vk::FormatFeatureFlagBits2::eSampledImageFilterCubic);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_FILTER_CUBIC_EXT", vk::FormatFeatureFlagBits2::eSampledImageFilterCubicEXT);
    e_vk_FormatFeatureFlagBits2.value("TRANSFER_SRC", vk::FormatFeatureFlagBits2::eTransferSrc);
    e_vk_FormatFeatureFlagBits2.value("TRANSFER_DST", vk::FormatFeatureFlagBits2::eTransferDst);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_FILTER_MINMAX", vk::FormatFeatureFlagBits2::eSampledImageFilterMinmax);
    e_vk_FormatFeatureFlagBits2.value("MIDPOINT_CHROMA_SAMPLES", vk::FormatFeatureFlagBits2::eMidpointChromaSamples);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER", vk::FormatFeatureFlagBits2::eSampledImageYcbcrConversionLinearFilter);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER", vk::FormatFeatureFlagBits2::eSampledImageYcbcrConversionSeparateReconstructionFilter);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT", vk::FormatFeatureFlagBits2::eSampledImageYcbcrConversionChromaReconstructionExplicit);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE", vk::FormatFeatureFlagBits2::eSampledImageYcbcrConversionChromaReconstructionExplicitForceable);
    e_vk_FormatFeatureFlagBits2.value("DISJOINT", vk::FormatFeatureFlagBits2::eDisjoint);
    e_vk_FormatFeatureFlagBits2.value("COSITED_CHROMA_SAMPLES", vk::FormatFeatureFlagBits2::eCositedChromaSamples);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_READ_WITHOUT_FORMAT", vk::FormatFeatureFlagBits2::eStorageReadWithoutFormat);
    e_vk_FormatFeatureFlagBits2.value("STORAGE_WRITE_WITHOUT_FORMAT", vk::FormatFeatureFlagBits2::eStorageWriteWithoutFormat);
    e_vk_FormatFeatureFlagBits2.value("SAMPLED_IMAGE_DEPTH_COMPARISON", vk::FormatFeatureFlagBits2::eSampledImageDepthComparison);
    e_vk_FormatFeatureFlagBits2.value("VIDEO_DECODE_OUTPUT_KHR", vk::FormatFeatureFlagBits2::eVideoDecodeOutputKHR);
    e_vk_FormatFeatureFlagBits2.value("VIDEO_DECODE_DPB_KHR", vk::FormatFeatureFlagBits2::eVideoDecodeDpbKHR);
    e_vk_FormatFeatureFlagBits2.value("ACCELERATION_STRUCTURE_VERTEX_BUFFER_KHR", vk::FormatFeatureFlagBits2::eAccelerationStructureVertexBufferKHR);
    e_vk_FormatFeatureFlagBits2.value("FRAGMENT_DENSITY_MAP_EXT", vk::FormatFeatureFlagBits2::eFragmentDensityMapEXT);
    e_vk_FormatFeatureFlagBits2.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", vk::FormatFeatureFlagBits2::eFragmentShadingRateAttachmentKHR);
    e_vk_FormatFeatureFlagBits2.value("HOST_IMAGE_TRANSFER_EXT", vk::FormatFeatureFlagBits2::eHostImageTransferEXT);
    e_vk_FormatFeatureFlagBits2.value("VIDEO_ENCODE_INPUT_KHR", vk::FormatFeatureFlagBits2::eVideoEncodeInputKHR);
    e_vk_FormatFeatureFlagBits2.value("VIDEO_ENCODE_DPB_KHR", vk::FormatFeatureFlagBits2::eVideoEncodeDpbKHR);
    e_vk_FormatFeatureFlagBits2.value("LINEAR_COLOR_ATTACHMENT_NV", vk::FormatFeatureFlagBits2::eLinearColorAttachmentNV);
    e_vk_FormatFeatureFlagBits2.value("WEIGHT_IMAGE_QCOM", vk::FormatFeatureFlagBits2::eWeightImageQCOM);
    e_vk_FormatFeatureFlagBits2.value("WEIGHT_SAMPLED_IMAGE_QCOM", vk::FormatFeatureFlagBits2::eWeightSampledImageQCOM);
    e_vk_FormatFeatureFlagBits2.value("BLOCK_MATCHING_QCOM", vk::FormatFeatureFlagBits2::eBlockMatchingQCOM);
    e_vk_FormatFeatureFlagBits2.value("BOX_FILTER_SAMPLED_QCOM", vk::FormatFeatureFlagBits2::eBoxFilterSampledQCOM);
    e_vk_FormatFeatureFlagBits2.value("OPTICAL_FLOW_IMAGE_NV", vk::FormatFeatureFlagBits2::eOpticalFlowImageNV);
    e_vk_FormatFeatureFlagBits2.value("OPTICAL_FLOW_VECTOR_NV", vk::FormatFeatureFlagBits2::eOpticalFlowVectorNV);
    e_vk_FormatFeatureFlagBits2.value("OPTICAL_FLOW_COST_NV", vk::FormatFeatureFlagBits2::eOpticalFlowCostNV);

    py::enum_<vk::PipelineCreationFeedbackFlagBits> e_vk_PipelineCreationFeedbackFlagBits(m_vk, "PipelineCreationFeedbackFlagBits");
    e_vk_PipelineCreationFeedbackFlagBits.value("VALID", vk::PipelineCreationFeedbackFlagBits::eValid);
    e_vk_PipelineCreationFeedbackFlagBits.value("APPLICATION_PIPELINE_CACHE_HIT", vk::PipelineCreationFeedbackFlagBits::eApplicationPipelineCacheHit);
    e_vk_PipelineCreationFeedbackFlagBits.value("BASE_PIPELINE_ACCELERATION", vk::PipelineCreationFeedbackFlagBits::eBasePipelineAcceleration);

    py::enum_<vk::PipelineStageFlagBits2> e_vk_PipelineStageFlagBits2(m_vk, "PipelineStageFlagBits2");
    e_vk_PipelineStageFlagBits2.value("NONE", vk::PipelineStageFlagBits2::eNone);
    e_vk_PipelineStageFlagBits2.value("TOP_OF_PIPE", vk::PipelineStageFlagBits2::eTopOfPipe);
    e_vk_PipelineStageFlagBits2.value("DRAW_INDIRECT", vk::PipelineStageFlagBits2::eDrawIndirect);
    e_vk_PipelineStageFlagBits2.value("VERTEX_INPUT", vk::PipelineStageFlagBits2::eVertexInput);
    e_vk_PipelineStageFlagBits2.value("VERTEX_SHADER", vk::PipelineStageFlagBits2::eVertexShader);
    e_vk_PipelineStageFlagBits2.value("TESSELLATION_CONTROL_SHADER", vk::PipelineStageFlagBits2::eTessellationControlShader);
    e_vk_PipelineStageFlagBits2.value("TESSELLATION_EVALUATION_SHADER", vk::PipelineStageFlagBits2::eTessellationEvaluationShader);
    e_vk_PipelineStageFlagBits2.value("GEOMETRY_SHADER", vk::PipelineStageFlagBits2::eGeometryShader);
    e_vk_PipelineStageFlagBits2.value("FRAGMENT_SHADER", vk::PipelineStageFlagBits2::eFragmentShader);
    e_vk_PipelineStageFlagBits2.value("EARLY_FRAGMENT_TESTS", vk::PipelineStageFlagBits2::eEarlyFragmentTests);
    e_vk_PipelineStageFlagBits2.value("LATE_FRAGMENT_TESTS", vk::PipelineStageFlagBits2::eLateFragmentTests);
    e_vk_PipelineStageFlagBits2.value("COLOR_ATTACHMENT_OUTPUT", vk::PipelineStageFlagBits2::eColorAttachmentOutput);
    e_vk_PipelineStageFlagBits2.value("COMPUTE_SHADER", vk::PipelineStageFlagBits2::eComputeShader);
    e_vk_PipelineStageFlagBits2.value("ALL_TRANSFER", vk::PipelineStageFlagBits2::eAllTransfer);
    e_vk_PipelineStageFlagBits2.value("TRANSFER", vk::PipelineStageFlagBits2::eTransfer);
    e_vk_PipelineStageFlagBits2.value("BOTTOM_OF_PIPE", vk::PipelineStageFlagBits2::eBottomOfPipe);
    e_vk_PipelineStageFlagBits2.value("HOST", vk::PipelineStageFlagBits2::eHost);
    e_vk_PipelineStageFlagBits2.value("ALL_GRAPHICS", vk::PipelineStageFlagBits2::eAllGraphics);
    e_vk_PipelineStageFlagBits2.value("ALL_COMMANDS", vk::PipelineStageFlagBits2::eAllCommands);
    e_vk_PipelineStageFlagBits2.value("COPY", vk::PipelineStageFlagBits2::eCopy);
    e_vk_PipelineStageFlagBits2.value("RESOLVE", vk::PipelineStageFlagBits2::eResolve);
    e_vk_PipelineStageFlagBits2.value("BLIT", vk::PipelineStageFlagBits2::eBlit);
    e_vk_PipelineStageFlagBits2.value("CLEAR", vk::PipelineStageFlagBits2::eClear);
    e_vk_PipelineStageFlagBits2.value("INDEX_INPUT", vk::PipelineStageFlagBits2::eIndexInput);
    e_vk_PipelineStageFlagBits2.value("VERTEX_ATTRIBUTE_INPUT", vk::PipelineStageFlagBits2::eVertexAttributeInput);
    e_vk_PipelineStageFlagBits2.value("PRE_RASTERIZATION_SHADERS", vk::PipelineStageFlagBits2::ePreRasterizationShaders);
    e_vk_PipelineStageFlagBits2.value("VIDEO_DECODE_KHR", vk::PipelineStageFlagBits2::eVideoDecodeKHR);
    e_vk_PipelineStageFlagBits2.value("VIDEO_ENCODE_KHR", vk::PipelineStageFlagBits2::eVideoEncodeKHR);
    e_vk_PipelineStageFlagBits2.value("TRANSFORM_FEEDBACK_EXT", vk::PipelineStageFlagBits2::eTransformFeedbackEXT);
    e_vk_PipelineStageFlagBits2.value("CONDITIONAL_RENDERING_EXT", vk::PipelineStageFlagBits2::eConditionalRenderingEXT);
    e_vk_PipelineStageFlagBits2.value("COMMAND_PREPROCESS_NV", vk::PipelineStageFlagBits2::eCommandPreprocessNV);
    e_vk_PipelineStageFlagBits2.value("FRAGMENT_SHADING_RATE_ATTACHMENT_KHR", vk::PipelineStageFlagBits2::eFragmentShadingRateAttachmentKHR);
    e_vk_PipelineStageFlagBits2.value("SHADING_RATE_IMAGE_NV", vk::PipelineStageFlagBits2::eShadingRateImageNV);
    e_vk_PipelineStageFlagBits2.value("ACCELERATION_STRUCTURE_BUILD_KHR", vk::PipelineStageFlagBits2::eAccelerationStructureBuildKHR);
    e_vk_PipelineStageFlagBits2.value("RAY_TRACING_SHADER_KHR", vk::PipelineStageFlagBits2::eRayTracingShaderKHR);
    e_vk_PipelineStageFlagBits2.value("RAY_TRACING_SHADER_NV", vk::PipelineStageFlagBits2::eRayTracingShaderNV);
    e_vk_PipelineStageFlagBits2.value("ACCELERATION_STRUCTURE_BUILD_NV", vk::PipelineStageFlagBits2::eAccelerationStructureBuildNV);
    e_vk_PipelineStageFlagBits2.value("FRAGMENT_DENSITY_PROCESS_EXT", vk::PipelineStageFlagBits2::eFragmentDensityProcessEXT);
    e_vk_PipelineStageFlagBits2.value("TASK_SHADER_NV", vk::PipelineStageFlagBits2::eTaskShaderNV);
    e_vk_PipelineStageFlagBits2.value("MESH_SHADER_NV", vk::PipelineStageFlagBits2::eMeshShaderNV);
    e_vk_PipelineStageFlagBits2.value("TASK_SHADER_EXT", vk::PipelineStageFlagBits2::eTaskShaderEXT);
    e_vk_PipelineStageFlagBits2.value("MESH_SHADER_EXT", vk::PipelineStageFlagBits2::eMeshShaderEXT);
    e_vk_PipelineStageFlagBits2.value("SUBPASS_SHADER_HUAWEI", vk::PipelineStageFlagBits2::eSubpassShaderHUAWEI);
    e_vk_PipelineStageFlagBits2.value("SUBPASS_SHADING_HUAWEI", vk::PipelineStageFlagBits2::eSubpassShadingHUAWEI);
    e_vk_PipelineStageFlagBits2.value("INVOCATION_MASK_HUAWEI", vk::PipelineStageFlagBits2::eInvocationMaskHUAWEI);
    e_vk_PipelineStageFlagBits2.value("ACCELERATION_STRUCTURE_COPY_KHR", vk::PipelineStageFlagBits2::eAccelerationStructureCopyKHR);
    e_vk_PipelineStageFlagBits2.value("MICROMAP_BUILD_EXT", vk::PipelineStageFlagBits2::eMicromapBuildEXT);
    e_vk_PipelineStageFlagBits2.value("CLUSTER_CULLING_SHADER_HUAWEI", vk::PipelineStageFlagBits2::eClusterCullingShaderHUAWEI);
    e_vk_PipelineStageFlagBits2.value("OPTICAL_FLOW_NV", vk::PipelineStageFlagBits2::eOpticalFlowNV);

    py::enum_<vk::PrivateDataSlotCreateFlagBits> e_vk_PrivateDataSlotCreateFlagBits(m_vk, "PrivateDataSlotCreateFlagBits");

    py::enum_<vk::RenderingFlagBits> e_vk_RenderingFlagBits(m_vk, "RenderingFlagBits");
    e_vk_RenderingFlagBits.value("CONTENTS_SECONDARY_COMMAND_BUFFERS", vk::RenderingFlagBits::eContentsSecondaryCommandBuffers);
    e_vk_RenderingFlagBits.value("SUSPENDING", vk::RenderingFlagBits::eSuspending);
    e_vk_RenderingFlagBits.value("RESUMING", vk::RenderingFlagBits::eResuming);
    e_vk_RenderingFlagBits.value("CONTENTS_INLINE_EXT", vk::RenderingFlagBits::eContentsInlineEXT);
    e_vk_RenderingFlagBits.value("ENABLE_LEGACY_DITHERING_EXT", vk::RenderingFlagBits::eEnableLegacyDitheringEXT);

    py::enum_<vk::SubmitFlagBits> e_vk_SubmitFlagBits(m_vk, "SubmitFlagBits");
    e_vk_SubmitFlagBits.value("PROTECTED", vk::SubmitFlagBits::eProtected);

    py::enum_<vk::ToolPurposeFlagBits> e_vk_ToolPurposeFlagBits(m_vk, "ToolPurposeFlagBits");
    e_vk_ToolPurposeFlagBits.value("VALIDATION", vk::ToolPurposeFlagBits::eValidation);
    e_vk_ToolPurposeFlagBits.value("PROFILING", vk::ToolPurposeFlagBits::eProfiling);
    e_vk_ToolPurposeFlagBits.value("TRACING", vk::ToolPurposeFlagBits::eTracing);
    e_vk_ToolPurposeFlagBits.value("ADDITIONAL_FEATURES", vk::ToolPurposeFlagBits::eAdditionalFeatures);
    e_vk_ToolPurposeFlagBits.value("MODIFYING_FEATURES", vk::ToolPurposeFlagBits::eModifyingFeatures);
    e_vk_ToolPurposeFlagBits.value("DEBUG_REPORTING_EXT", vk::ToolPurposeFlagBits::eDebugReportingEXT);
    e_vk_ToolPurposeFlagBits.value("DEBUG_MARKERS_EXT", vk::ToolPurposeFlagBits::eDebugMarkersEXT);

    py::enum_<vk::ColorSpaceKHR> e_vk_ColorSpaceKHR(m_vk, "ColorSpaceKHR");
    e_vk_ColorSpaceKHR.value("SRGB_NONLINEAR", vk::ColorSpaceKHR::eSrgbNonlinear);
    e_vk_ColorSpaceKHR.value("VK_COLORSPACE_SRGB_NONLINEAR", vk::ColorSpaceKHR::eVkColorspaceSrgbNonlinear);
    e_vk_ColorSpaceKHR.value("DISPLAY_P3_NONLINEAR_EXT", vk::ColorSpaceKHR::eDisplayP3NonlinearEXT);
    e_vk_ColorSpaceKHR.value("EXTENDED_SRGB_LINEAR_EXT", vk::ColorSpaceKHR::eExtendedSrgbLinearEXT);
    e_vk_ColorSpaceKHR.value("DISPLAY_P3_LINEAR_EXT", vk::ColorSpaceKHR::eDisplayP3LinearEXT);
    e_vk_ColorSpaceKHR.value("DCI_P3_NONLINEAR_EXT", vk::ColorSpaceKHR::eDciP3NonlinearEXT);
    e_vk_ColorSpaceKHR.value("BT_709_LINEAR_EXT", vk::ColorSpaceKHR::eBt709LinearEXT);
    e_vk_ColorSpaceKHR.value("BT_709_NONLINEAR_EXT", vk::ColorSpaceKHR::eBt709NonlinearEXT);
    e_vk_ColorSpaceKHR.value("BT_2020_LINEAR_EXT", vk::ColorSpaceKHR::eBt2020LinearEXT);
    e_vk_ColorSpaceKHR.value("HDR_10_ST_2084EXT", vk::ColorSpaceKHR::eHdr10St2084EXT);
    e_vk_ColorSpaceKHR.value("DOLBYVISION_EXT", vk::ColorSpaceKHR::eDolbyvisionEXT);
    e_vk_ColorSpaceKHR.value("HDR_10_HLG_EXT", vk::ColorSpaceKHR::eHdr10HlgEXT);
    e_vk_ColorSpaceKHR.value("ADOBERGB_LINEAR_EXT", vk::ColorSpaceKHR::eAdobergbLinearEXT);
    e_vk_ColorSpaceKHR.value("ADOBERGB_NONLINEAR_EXT", vk::ColorSpaceKHR::eAdobergbNonlinearEXT);
    e_vk_ColorSpaceKHR.value("PASS_THROUGH_EXT", vk::ColorSpaceKHR::ePassThroughEXT);
    e_vk_ColorSpaceKHR.value("EXTENDED_SRGB_NONLINEAR_EXT", vk::ColorSpaceKHR::eExtendedSrgbNonlinearEXT);
    e_vk_ColorSpaceKHR.value("DCI_P3_LINEAR_EXT", vk::ColorSpaceKHR::eDciP3LinearEXT);
    e_vk_ColorSpaceKHR.value("DISPLAY_NATIVE_AMD", vk::ColorSpaceKHR::eDisplayNativeAMD);

    py::enum_<vk::CompositeAlphaFlagBitsKHR> e_vk_CompositeAlphaFlagBitsKHR(m_vk, "CompositeAlphaFlagBitsKHR");
    e_vk_CompositeAlphaFlagBitsKHR.value("OPAQUE", vk::CompositeAlphaFlagBitsKHR::eOpaque);
    e_vk_CompositeAlphaFlagBitsKHR.value("PRE_MULTIPLIED", vk::CompositeAlphaFlagBitsKHR::ePreMultiplied);
    e_vk_CompositeAlphaFlagBitsKHR.value("POST_MULTIPLIED", vk::CompositeAlphaFlagBitsKHR::ePostMultiplied);
    e_vk_CompositeAlphaFlagBitsKHR.value("INHERIT", vk::CompositeAlphaFlagBitsKHR::eInherit);

    py::enum_<vk::PresentModeKHR> e_vk_PresentModeKHR(m_vk, "PresentModeKHR");
    e_vk_PresentModeKHR.value("IMMEDIATE", vk::PresentModeKHR::eImmediate);
    e_vk_PresentModeKHR.value("MAILBOX", vk::PresentModeKHR::eMailbox);
    e_vk_PresentModeKHR.value("FIFO", vk::PresentModeKHR::eFifo);
    e_vk_PresentModeKHR.value("FIFO_RELAXED", vk::PresentModeKHR::eFifoRelaxed);
    e_vk_PresentModeKHR.value("SHARED_DEMAND_REFRESH", vk::PresentModeKHR::eSharedDemandRefresh);
    e_vk_PresentModeKHR.value("SHARED_CONTINUOUS_REFRESH", vk::PresentModeKHR::eSharedContinuousRefresh);

    py::enum_<vk::SurfaceTransformFlagBitsKHR> e_vk_SurfaceTransformFlagBitsKHR(m_vk, "SurfaceTransformFlagBitsKHR");
    e_vk_SurfaceTransformFlagBitsKHR.value("IDENTITY", vk::SurfaceTransformFlagBitsKHR::eIdentity);
    e_vk_SurfaceTransformFlagBitsKHR.value("ROTATE_90", vk::SurfaceTransformFlagBitsKHR::eRotate90);
    e_vk_SurfaceTransformFlagBitsKHR.value("ROTATE_180", vk::SurfaceTransformFlagBitsKHR::eRotate180);
    e_vk_SurfaceTransformFlagBitsKHR.value("ROTATE_270", vk::SurfaceTransformFlagBitsKHR::eRotate270);
    e_vk_SurfaceTransformFlagBitsKHR.value("HORIZONTAL_MIRROR", vk::SurfaceTransformFlagBitsKHR::eHorizontalMirror);
    e_vk_SurfaceTransformFlagBitsKHR.value("HORIZONTAL_MIRROR_ROTATE_90", vk::SurfaceTransformFlagBitsKHR::eHorizontalMirrorRotate90);
    e_vk_SurfaceTransformFlagBitsKHR.value("HORIZONTAL_MIRROR_ROTATE_180", vk::SurfaceTransformFlagBitsKHR::eHorizontalMirrorRotate180);
    e_vk_SurfaceTransformFlagBitsKHR.value("HORIZONTAL_MIRROR_ROTATE_270", vk::SurfaceTransformFlagBitsKHR::eHorizontalMirrorRotate270);
    e_vk_SurfaceTransformFlagBitsKHR.value("INHERIT", vk::SurfaceTransformFlagBitsKHR::eInherit);

    py::enum_<vk::DeviceGroupPresentModeFlagBitsKHR> e_vk_DeviceGroupPresentModeFlagBitsKHR(m_vk, "DeviceGroupPresentModeFlagBitsKHR");
    e_vk_DeviceGroupPresentModeFlagBitsKHR.value("LOCAL", vk::DeviceGroupPresentModeFlagBitsKHR::eLocal);
    e_vk_DeviceGroupPresentModeFlagBitsKHR.value("REMOTE", vk::DeviceGroupPresentModeFlagBitsKHR::eRemote);
    e_vk_DeviceGroupPresentModeFlagBitsKHR.value("SUM", vk::DeviceGroupPresentModeFlagBitsKHR::eSum);
    e_vk_DeviceGroupPresentModeFlagBitsKHR.value("LOCAL_MULTI_DEVICE", vk::DeviceGroupPresentModeFlagBitsKHR::eLocalMultiDevice);

    py::enum_<vk::SwapchainCreateFlagBitsKHR> e_vk_SwapchainCreateFlagBitsKHR(m_vk, "SwapchainCreateFlagBitsKHR");
    e_vk_SwapchainCreateFlagBitsKHR.value("SPLIT_INSTANCE_BIND_REGIONS", vk::SwapchainCreateFlagBitsKHR::eSplitInstanceBindRegions);
    e_vk_SwapchainCreateFlagBitsKHR.value("PROTECTED", vk::SwapchainCreateFlagBitsKHR::eProtected);
    e_vk_SwapchainCreateFlagBitsKHR.value("MUTABLE_FORMAT", vk::SwapchainCreateFlagBitsKHR::eMutableFormat);
    e_vk_SwapchainCreateFlagBitsKHR.value("DEFERRED_MEMORY_ALLOCATION_EXT", vk::SwapchainCreateFlagBitsKHR::eDeferredMemoryAllocationEXT);

    py::enum_<vk::DisplayModeCreateFlagBitsKHR> e_vk_DisplayModeCreateFlagBitsKHR(m_vk, "DisplayModeCreateFlagBitsKHR");

    py::enum_<vk::DisplayPlaneAlphaFlagBitsKHR> e_vk_DisplayPlaneAlphaFlagBitsKHR(m_vk, "DisplayPlaneAlphaFlagBitsKHR");
    e_vk_DisplayPlaneAlphaFlagBitsKHR.value("OPAQUE", vk::DisplayPlaneAlphaFlagBitsKHR::eOpaque);
    e_vk_DisplayPlaneAlphaFlagBitsKHR.value("GLOBAL", vk::DisplayPlaneAlphaFlagBitsKHR::eGlobal);
    e_vk_DisplayPlaneAlphaFlagBitsKHR.value("PER_PIXEL", vk::DisplayPlaneAlphaFlagBitsKHR::ePerPixel);
    e_vk_DisplayPlaneAlphaFlagBitsKHR.value("PER_PIXEL_PREMULTIPLIED", vk::DisplayPlaneAlphaFlagBitsKHR::ePerPixelPremultiplied);

    py::enum_<vk::DisplaySurfaceCreateFlagBitsKHR> e_vk_DisplaySurfaceCreateFlagBitsKHR(m_vk, "DisplaySurfaceCreateFlagBitsKHR");

    py::enum_<vk::DebugReportFlagBitsEXT> e_vk_DebugReportFlagBitsEXT(m_vk, "DebugReportFlagBitsEXT");
    e_vk_DebugReportFlagBitsEXT.value("INFORMATION", vk::DebugReportFlagBitsEXT::eInformation);
    e_vk_DebugReportFlagBitsEXT.value("WARNING", vk::DebugReportFlagBitsEXT::eWarning);
    e_vk_DebugReportFlagBitsEXT.value("PERFORMANCE_WARNING", vk::DebugReportFlagBitsEXT::ePerformanceWarning);
    e_vk_DebugReportFlagBitsEXT.value("ERROR", vk::DebugReportFlagBitsEXT::eError);
    e_vk_DebugReportFlagBitsEXT.value("DEBUG", vk::DebugReportFlagBitsEXT::eDebug);

    py::enum_<vk::DebugReportObjectTypeEXT> e_vk_DebugReportObjectTypeEXT(m_vk, "DebugReportObjectTypeEXT");
    e_vk_DebugReportObjectTypeEXT.value("UNKNOWN", vk::DebugReportObjectTypeEXT::eUnknown);
    e_vk_DebugReportObjectTypeEXT.value("INSTANCE", vk::DebugReportObjectTypeEXT::eInstance);
    e_vk_DebugReportObjectTypeEXT.value("PHYSICAL_DEVICE", vk::DebugReportObjectTypeEXT::ePhysicalDevice);
    e_vk_DebugReportObjectTypeEXT.value("DEVICE", vk::DebugReportObjectTypeEXT::eDevice);
    e_vk_DebugReportObjectTypeEXT.value("QUEUE", vk::DebugReportObjectTypeEXT::eQueue);
    e_vk_DebugReportObjectTypeEXT.value("SEMAPHORE", vk::DebugReportObjectTypeEXT::eSemaphore);
    e_vk_DebugReportObjectTypeEXT.value("COMMAND_BUFFER", vk::DebugReportObjectTypeEXT::eCommandBuffer);
    e_vk_DebugReportObjectTypeEXT.value("FENCE", vk::DebugReportObjectTypeEXT::eFence);
    e_vk_DebugReportObjectTypeEXT.value("DEVICE_MEMORY", vk::DebugReportObjectTypeEXT::eDeviceMemory);
    e_vk_DebugReportObjectTypeEXT.value("BUFFER", vk::DebugReportObjectTypeEXT::eBuffer);
    e_vk_DebugReportObjectTypeEXT.value("IMAGE", vk::DebugReportObjectTypeEXT::eImage);
    e_vk_DebugReportObjectTypeEXT.value("EVENT", vk::DebugReportObjectTypeEXT::eEvent);
    e_vk_DebugReportObjectTypeEXT.value("QUERY_POOL", vk::DebugReportObjectTypeEXT::eQueryPool);
    e_vk_DebugReportObjectTypeEXT.value("BUFFER_VIEW", vk::DebugReportObjectTypeEXT::eBufferView);
    e_vk_DebugReportObjectTypeEXT.value("IMAGE_VIEW", vk::DebugReportObjectTypeEXT::eImageView);
    e_vk_DebugReportObjectTypeEXT.value("SHADER_MODULE", vk::DebugReportObjectTypeEXT::eShaderModule);
    e_vk_DebugReportObjectTypeEXT.value("PIPELINE_CACHE", vk::DebugReportObjectTypeEXT::ePipelineCache);
    e_vk_DebugReportObjectTypeEXT.value("PIPELINE_LAYOUT", vk::DebugReportObjectTypeEXT::ePipelineLayout);
    e_vk_DebugReportObjectTypeEXT.value("RENDER_PASS", vk::DebugReportObjectTypeEXT::eRenderPass);
    e_vk_DebugReportObjectTypeEXT.value("PIPELINE", vk::DebugReportObjectTypeEXT::ePipeline);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_SET_LAYOUT", vk::DebugReportObjectTypeEXT::eDescriptorSetLayout);
    e_vk_DebugReportObjectTypeEXT.value("SAMPLER", vk::DebugReportObjectTypeEXT::eSampler);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_POOL", vk::DebugReportObjectTypeEXT::eDescriptorPool);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_SET", vk::DebugReportObjectTypeEXT::eDescriptorSet);
    e_vk_DebugReportObjectTypeEXT.value("FRAMEBUFFER", vk::DebugReportObjectTypeEXT::eFramebuffer);
    e_vk_DebugReportObjectTypeEXT.value("COMMAND_POOL", vk::DebugReportObjectTypeEXT::eCommandPool);
    e_vk_DebugReportObjectTypeEXT.value("SURFACE_KHR", vk::DebugReportObjectTypeEXT::eSurfaceKHR);
    e_vk_DebugReportObjectTypeEXT.value("SWAPCHAIN_KHR", vk::DebugReportObjectTypeEXT::eSwapchainKHR);
    e_vk_DebugReportObjectTypeEXT.value("DEBUG_REPORT_CALLBACK_EXT", vk::DebugReportObjectTypeEXT::eDebugReportCallbackEXT);
    e_vk_DebugReportObjectTypeEXT.value("DEBUG_REPORT", vk::DebugReportObjectTypeEXT::eDebugReport);
    e_vk_DebugReportObjectTypeEXT.value("DISPLAY_KHR", vk::DebugReportObjectTypeEXT::eDisplayKHR);
    e_vk_DebugReportObjectTypeEXT.value("DISPLAY_MODE_KHR", vk::DebugReportObjectTypeEXT::eDisplayModeKHR);
    e_vk_DebugReportObjectTypeEXT.value("VALIDATION_CACHE_EXT", vk::DebugReportObjectTypeEXT::eValidationCacheEXT);
    e_vk_DebugReportObjectTypeEXT.value("VALIDATION_CACHE", vk::DebugReportObjectTypeEXT::eValidationCache);
    e_vk_DebugReportObjectTypeEXT.value("SAMPLER_YCBCR_CONVERSION", vk::DebugReportObjectTypeEXT::eSamplerYcbcrConversion);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_UPDATE_TEMPLATE", vk::DebugReportObjectTypeEXT::eDescriptorUpdateTemplate);
    e_vk_DebugReportObjectTypeEXT.value("CU_MODULE_NVX", vk::DebugReportObjectTypeEXT::eCuModuleNVX);
    e_vk_DebugReportObjectTypeEXT.value("CU_FUNCTION_NVX", vk::DebugReportObjectTypeEXT::eCuFunctionNVX);
    e_vk_DebugReportObjectTypeEXT.value("DESCRIPTOR_UPDATE_TEMPLATE_KHR", vk::DebugReportObjectTypeEXT::eDescriptorUpdateTemplateKHR);
    e_vk_DebugReportObjectTypeEXT.value("ACCELERATION_STRUCTURE_KHR", vk::DebugReportObjectTypeEXT::eAccelerationStructureKHR);
    e_vk_DebugReportObjectTypeEXT.value("SAMPLER_YCBCR_CONVERSION_KHR", vk::DebugReportObjectTypeEXT::eSamplerYcbcrConversionKHR);
    e_vk_DebugReportObjectTypeEXT.value("ACCELERATION_STRUCTURE_NV", vk::DebugReportObjectTypeEXT::eAccelerationStructureNV);

    py::enum_<vk::RasterizationOrderAMD> e_vk_RasterizationOrderAMD(m_vk, "RasterizationOrderAMD");
    e_vk_RasterizationOrderAMD.value("STRICT", vk::RasterizationOrderAMD::eStrict);
    e_vk_RasterizationOrderAMD.value("RELAXED", vk::RasterizationOrderAMD::eRelaxed);

    py::enum_<vk::QueryResultStatusKHR> e_vk_QueryResultStatusKHR(m_vk, "QueryResultStatusKHR");
    e_vk_QueryResultStatusKHR.value("ERROR", vk::QueryResultStatusKHR::eError);
    e_vk_QueryResultStatusKHR.value("NOT_READY", vk::QueryResultStatusKHR::eNotReady);
    e_vk_QueryResultStatusKHR.value("COMPLETE", vk::QueryResultStatusKHR::eComplete);
    e_vk_QueryResultStatusKHR.value("INSUFFICIENT_BITSTREAM_BUFFER_RANGE", vk::QueryResultStatusKHR::eInsufficientBitstreamBufferRange);

    py::enum_<vk::VideoBeginCodingFlagBitsKHR> e_vk_VideoBeginCodingFlagBitsKHR(m_vk, "VideoBeginCodingFlagBitsKHR");

    py::enum_<vk::VideoCapabilityFlagBitsKHR> e_vk_VideoCapabilityFlagBitsKHR(m_vk, "VideoCapabilityFlagBitsKHR");
    e_vk_VideoCapabilityFlagBitsKHR.value("PROTECTED_CONTENT", vk::VideoCapabilityFlagBitsKHR::eProtectedContent);
    e_vk_VideoCapabilityFlagBitsKHR.value("SEPARATE_REFERENCE_IMAGES", vk::VideoCapabilityFlagBitsKHR::eSeparateReferenceImages);

    py::enum_<vk::VideoChromaSubsamplingFlagBitsKHR> e_vk_VideoChromaSubsamplingFlagBitsKHR(m_vk, "VideoChromaSubsamplingFlagBitsKHR");
    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("INVALID", vk::VideoChromaSubsamplingFlagBitsKHR::eInvalid);
    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("MONOCHROME", vk::VideoChromaSubsamplingFlagBitsKHR::eMonochrome);
    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("_420", vk::VideoChromaSubsamplingFlagBitsKHR::e420);
    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("_422", vk::VideoChromaSubsamplingFlagBitsKHR::e422);
    e_vk_VideoChromaSubsamplingFlagBitsKHR.value("_444", vk::VideoChromaSubsamplingFlagBitsKHR::e444);

    py::enum_<vk::VideoCodecOperationFlagBitsKHR> e_vk_VideoCodecOperationFlagBitsKHR(m_vk, "VideoCodecOperationFlagBitsKHR");
    e_vk_VideoCodecOperationFlagBitsKHR.value("NONE", vk::VideoCodecOperationFlagBitsKHR::eNone);
    e_vk_VideoCodecOperationFlagBitsKHR.value("ENCODE_H264", vk::VideoCodecOperationFlagBitsKHR::eEncodeH264);
    e_vk_VideoCodecOperationFlagBitsKHR.value("ENCODE_H265", vk::VideoCodecOperationFlagBitsKHR::eEncodeH265);
    e_vk_VideoCodecOperationFlagBitsKHR.value("DECODE_H264", vk::VideoCodecOperationFlagBitsKHR::eDecodeH264);
    e_vk_VideoCodecOperationFlagBitsKHR.value("DECODE_H265", vk::VideoCodecOperationFlagBitsKHR::eDecodeH265);

    py::enum_<vk::VideoCodingControlFlagBitsKHR> e_vk_VideoCodingControlFlagBitsKHR(m_vk, "VideoCodingControlFlagBitsKHR");
    e_vk_VideoCodingControlFlagBitsKHR.value("RESET", vk::VideoCodingControlFlagBitsKHR::eReset);
    e_vk_VideoCodingControlFlagBitsKHR.value("ENCODE_RATE_CONTROL", vk::VideoCodingControlFlagBitsKHR::eEncodeRateControl);
    e_vk_VideoCodingControlFlagBitsKHR.value("ENCODE_QUALITY_LEVEL", vk::VideoCodingControlFlagBitsKHR::eEncodeQualityLevel);

    py::enum_<vk::VideoComponentBitDepthFlagBitsKHR> e_vk_VideoComponentBitDepthFlagBitsKHR(m_vk, "VideoComponentBitDepthFlagBitsKHR");
    e_vk_VideoComponentBitDepthFlagBitsKHR.value("INVALID", vk::VideoComponentBitDepthFlagBitsKHR::eInvalid);
    e_vk_VideoComponentBitDepthFlagBitsKHR.value("_8", vk::VideoComponentBitDepthFlagBitsKHR::e8);
    e_vk_VideoComponentBitDepthFlagBitsKHR.value("_10", vk::VideoComponentBitDepthFlagBitsKHR::e10);
    e_vk_VideoComponentBitDepthFlagBitsKHR.value("_12", vk::VideoComponentBitDepthFlagBitsKHR::e12);

    py::enum_<vk::VideoEndCodingFlagBitsKHR> e_vk_VideoEndCodingFlagBitsKHR(m_vk, "VideoEndCodingFlagBitsKHR");

    py::enum_<vk::VideoSessionCreateFlagBitsKHR> e_vk_VideoSessionCreateFlagBitsKHR(m_vk, "VideoSessionCreateFlagBitsKHR");
    e_vk_VideoSessionCreateFlagBitsKHR.value("PROTECTED_CONTENT", vk::VideoSessionCreateFlagBitsKHR::eProtectedContent);
    e_vk_VideoSessionCreateFlagBitsKHR.value("ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS", vk::VideoSessionCreateFlagBitsKHR::eAllowEncodeParameterOptimizations);
    e_vk_VideoSessionCreateFlagBitsKHR.value("INLINE_QUERIES", vk::VideoSessionCreateFlagBitsKHR::eInlineQueries);

    py::enum_<vk::VideoSessionParametersCreateFlagBitsKHR> e_vk_VideoSessionParametersCreateFlagBitsKHR(m_vk, "VideoSessionParametersCreateFlagBitsKHR");

    py::enum_<vk::VideoDecodeCapabilityFlagBitsKHR> e_vk_VideoDecodeCapabilityFlagBitsKHR(m_vk, "VideoDecodeCapabilityFlagBitsKHR");
    e_vk_VideoDecodeCapabilityFlagBitsKHR.value("DPB_AND_OUTPUT_COINCIDE", vk::VideoDecodeCapabilityFlagBitsKHR::eDpbAndOutputCoincide);
    e_vk_VideoDecodeCapabilityFlagBitsKHR.value("DPB_AND_OUTPUT_DISTINCT", vk::VideoDecodeCapabilityFlagBitsKHR::eDpbAndOutputDistinct);

    py::enum_<vk::VideoDecodeFlagBitsKHR> e_vk_VideoDecodeFlagBitsKHR(m_vk, "VideoDecodeFlagBitsKHR");

    py::enum_<vk::VideoDecodeUsageFlagBitsKHR> e_vk_VideoDecodeUsageFlagBitsKHR(m_vk, "VideoDecodeUsageFlagBitsKHR");
    e_vk_VideoDecodeUsageFlagBitsKHR.value("DEFAULT", vk::VideoDecodeUsageFlagBitsKHR::eDefault);
    e_vk_VideoDecodeUsageFlagBitsKHR.value("TRANSCODING", vk::VideoDecodeUsageFlagBitsKHR::eTranscoding);
    e_vk_VideoDecodeUsageFlagBitsKHR.value("OFFLINE", vk::VideoDecodeUsageFlagBitsKHR::eOffline);
    e_vk_VideoDecodeUsageFlagBitsKHR.value("STREAMING", vk::VideoDecodeUsageFlagBitsKHR::eStreaming);

    py::enum_<vk::PipelineRasterizationStateStreamCreateFlagBitsEXT> e_vk_PipelineRasterizationStateStreamCreateFlagBitsEXT(m_vk, "PipelineRasterizationStateStreamCreateFlagBitsEXT");

    py::enum_<vk::VideoEncodeH264CapabilityFlagBitsKHR> e_vk_VideoEncodeH264CapabilityFlagBitsKHR(m_vk, "VideoEncodeH264CapabilityFlagBitsKHR");
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("HRD_COMPLIANCE", vk::VideoEncodeH264CapabilityFlagBitsKHR::eHrdCompliance);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("PREDICTION_WEIGHT_TABLE_GENERATED", vk::VideoEncodeH264CapabilityFlagBitsKHR::ePredictionWeightTableGenerated);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("ROW_UNALIGNED_SLICE", vk::VideoEncodeH264CapabilityFlagBitsKHR::eRowUnalignedSlice);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("DIFFERENT_SLICE_TYPE", vk::VideoEncodeH264CapabilityFlagBitsKHR::eDifferentSliceType);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("B_FRAME_IN_L0_LIST", vk::VideoEncodeH264CapabilityFlagBitsKHR::eBFrameInL0List);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("B_FRAME_IN_L1_LIST", vk::VideoEncodeH264CapabilityFlagBitsKHR::eBFrameInL1List);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("PER_PICTURE_TYPE_MIN_MAX_QP", vk::VideoEncodeH264CapabilityFlagBitsKHR::ePerPictureTypeMinMaxQp);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("PER_SLICE_CONSTANT_QP", vk::VideoEncodeH264CapabilityFlagBitsKHR::ePerSliceConstantQp);
    e_vk_VideoEncodeH264CapabilityFlagBitsKHR.value("GENERATE_PREFIX_NALU", vk::VideoEncodeH264CapabilityFlagBitsKHR::eGeneratePrefixNalu);

    py::enum_<vk::VideoEncodeH264RateControlFlagBitsKHR> e_vk_VideoEncodeH264RateControlFlagBitsKHR(m_vk, "VideoEncodeH264RateControlFlagBitsKHR");
    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("ATTEMPT_HRD_COMPLIANCE", vk::VideoEncodeH264RateControlFlagBitsKHR::eAttemptHrdCompliance);
    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("REGULAR_GOP", vk::VideoEncodeH264RateControlFlagBitsKHR::eRegularGop);
    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("REFERENCE_PATTERN_FLAT", vk::VideoEncodeH264RateControlFlagBitsKHR::eReferencePatternFlat);
    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("REFERENCE_PATTERN_DYADIC", vk::VideoEncodeH264RateControlFlagBitsKHR::eReferencePatternDyadic);
    e_vk_VideoEncodeH264RateControlFlagBitsKHR.value("TEMPORAL_LAYER_PATTERN_DYADIC", vk::VideoEncodeH264RateControlFlagBitsKHR::eTemporalLayerPatternDyadic);

    py::enum_<vk::VideoEncodeH264StdFlagBitsKHR> e_vk_VideoEncodeH264StdFlagBitsKHR(m_vk, "VideoEncodeH264StdFlagBitsKHR");
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("SEPARATE_COLOR_PLANE_FLAG_SET", vk::VideoEncodeH264StdFlagBitsKHR::eSeparateColorPlaneFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET", vk::VideoEncodeH264StdFlagBitsKHR::eQpprimeYZeroTransformBypassFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("SCALING_MATRIX_PRESENT_FLAG_SET", vk::VideoEncodeH264StdFlagBitsKHR::eScalingMatrixPresentFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("CHROMA_QP_INDEX_OFFSET", vk::VideoEncodeH264StdFlagBitsKHR::eChromaQpIndexOffset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("SECOND_CHROMA_QP_INDEX_OFFSET", vk::VideoEncodeH264StdFlagBitsKHR::eSecondChromaQpIndexOffset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("PIC_INIT_QP_MINUS_26", vk::VideoEncodeH264StdFlagBitsKHR::ePicInitQpMinus26);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("WEIGHTED_PRED_FLAG_SET", vk::VideoEncodeH264StdFlagBitsKHR::eWeightedPredFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("WEIGHTED_BIPRED_IDC_EXPLICIT", vk::VideoEncodeH264StdFlagBitsKHR::eWeightedBipredIdcExplicit);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("WEIGHTED_BIPRED_IDC_IMPLICIT", vk::VideoEncodeH264StdFlagBitsKHR::eWeightedBipredIdcImplicit);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("TRANSFORM_8X8_MODE_FLAG_SET", vk::VideoEncodeH264StdFlagBitsKHR::eTransform8X8ModeFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DIRECT_SPATIAL_MV_PRED_FLAG_UNSET", vk::VideoEncodeH264StdFlagBitsKHR::eDirectSpatialMvPredFlagUnset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("ENTROPY_CODING_MODE_FLAG_UNSET", vk::VideoEncodeH264StdFlagBitsKHR::eEntropyCodingModeFlagUnset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("ENTROPY_CODING_MODE_FLAG_SET", vk::VideoEncodeH264StdFlagBitsKHR::eEntropyCodingModeFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DIRECT_8X8_INFERENCE_FLAG_UNSET", vk::VideoEncodeH264StdFlagBitsKHR::eDirect8X8InferenceFlagUnset);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("CONSTRAINED_INTRA_PRED_FLAG_SET", vk::VideoEncodeH264StdFlagBitsKHR::eConstrainedIntraPredFlagSet);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DEBLOCKING_FILTER_DISABLED", vk::VideoEncodeH264StdFlagBitsKHR::eDeblockingFilterDisabled);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DEBLOCKING_FILTER_ENABLED", vk::VideoEncodeH264StdFlagBitsKHR::eDeblockingFilterEnabled);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DEBLOCKING_FILTER_PARTIAL", vk::VideoEncodeH264StdFlagBitsKHR::eDeblockingFilterPartial);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("SLICE_QP_DELTA", vk::VideoEncodeH264StdFlagBitsKHR::eSliceQpDelta);
    e_vk_VideoEncodeH264StdFlagBitsKHR.value("DIFFERENT_SLICE_QP_DELTA", vk::VideoEncodeH264StdFlagBitsKHR::eDifferentSliceQpDelta);

    py::enum_<vk::VideoEncodeH265CapabilityFlagBitsKHR> e_vk_VideoEncodeH265CapabilityFlagBitsKHR(m_vk, "VideoEncodeH265CapabilityFlagBitsKHR");
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("HRD_COMPLIANCE", vk::VideoEncodeH265CapabilityFlagBitsKHR::eHrdCompliance);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("PREDICTION_WEIGHT_TABLE_GENERATED", vk::VideoEncodeH265CapabilityFlagBitsKHR::ePredictionWeightTableGenerated);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("ROW_UNALIGNED_SLICE_SEGMENT", vk::VideoEncodeH265CapabilityFlagBitsKHR::eRowUnalignedSliceSegment);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("DIFFERENT_SLICE_SEGMENT_TYPE", vk::VideoEncodeH265CapabilityFlagBitsKHR::eDifferentSliceSegmentType);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("B_FRAME_IN_L0_LIST", vk::VideoEncodeH265CapabilityFlagBitsKHR::eBFrameInL0List);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("B_FRAME_IN_L1_LIST", vk::VideoEncodeH265CapabilityFlagBitsKHR::eBFrameInL1List);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("PER_PICTURE_TYPE_MIN_MAX_QP", vk::VideoEncodeH265CapabilityFlagBitsKHR::ePerPictureTypeMinMaxQp);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("PER_SLICE_SEGMENT_CONSTANT_QP", vk::VideoEncodeH265CapabilityFlagBitsKHR::ePerSliceSegmentConstantQp);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("MULTIPLE_TILES_PER_SLICE_SEGMENT", vk::VideoEncodeH265CapabilityFlagBitsKHR::eMultipleTilesPerSliceSegment);
    e_vk_VideoEncodeH265CapabilityFlagBitsKHR.value("MULTIPLE_SLICE_SEGMENTS_PER_TILE", vk::VideoEncodeH265CapabilityFlagBitsKHR::eMultipleSliceSegmentsPerTile);

    py::enum_<vk::VideoEncodeH265CtbSizeFlagBitsKHR> e_vk_VideoEncodeH265CtbSizeFlagBitsKHR(m_vk, "VideoEncodeH265CtbSizeFlagBitsKHR");
    e_vk_VideoEncodeH265CtbSizeFlagBitsKHR.value("_16", vk::VideoEncodeH265CtbSizeFlagBitsKHR::e16);
    e_vk_VideoEncodeH265CtbSizeFlagBitsKHR.value("_32", vk::VideoEncodeH265CtbSizeFlagBitsKHR::e32);
    e_vk_VideoEncodeH265CtbSizeFlagBitsKHR.value("_64", vk::VideoEncodeH265CtbSizeFlagBitsKHR::e64);

    py::enum_<vk::VideoEncodeH265RateControlFlagBitsKHR> e_vk_VideoEncodeH265RateControlFlagBitsKHR(m_vk, "VideoEncodeH265RateControlFlagBitsKHR");
    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("ATTEMPT_HRD_COMPLIANCE", vk::VideoEncodeH265RateControlFlagBitsKHR::eAttemptHrdCompliance);
    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("REGULAR_GOP", vk::VideoEncodeH265RateControlFlagBitsKHR::eRegularGop);
    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("REFERENCE_PATTERN_FLAT", vk::VideoEncodeH265RateControlFlagBitsKHR::eReferencePatternFlat);
    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("REFERENCE_PATTERN_DYADIC", vk::VideoEncodeH265RateControlFlagBitsKHR::eReferencePatternDyadic);
    e_vk_VideoEncodeH265RateControlFlagBitsKHR.value("TEMPORAL_SUB_LAYER_PATTERN_DYADIC", vk::VideoEncodeH265RateControlFlagBitsKHR::eTemporalSubLayerPatternDyadic);

    py::enum_<vk::VideoEncodeH265StdFlagBitsKHR> e_vk_VideoEncodeH265StdFlagBitsKHR(m_vk, "VideoEncodeH265StdFlagBitsKHR");
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SEPARATE_COLOR_PLANE_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eSeparateColorPlaneFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eSampleAdaptiveOffsetEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SCALING_LIST_DATA_PRESENT_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eScalingListDataPresentFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("PCM_ENABLED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::ePcmEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SPS_TEMPORAL_MVP_ENABLED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eSpsTemporalMvpEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("INIT_QP_MINUS_26", vk::VideoEncodeH265StdFlagBitsKHR::eInitQpMinus26);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("WEIGHTED_PRED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eWeightedPredFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("WEIGHTED_BIPRED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eWeightedBipredFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("LOG_2_PARALLEL_MERGE_LEVEL_MINUS_2", vk::VideoEncodeH265StdFlagBitsKHR::eLog2ParallelMergeLevelMinus2);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SIGN_DATA_HIDING_ENABLED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eSignDataHidingEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("TRANSFORM_SKIP_ENABLED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eTransformSkipEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("TRANSFORM_SKIP_ENABLED_FLAG_UNSET", vk::VideoEncodeH265StdFlagBitsKHR::eTransformSkipEnabledFlagUnset);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::ePpsSliceChromaQpOffsetsPresentFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("TRANSQUANT_BYPASS_ENABLED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eTransquantBypassEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("CONSTRAINED_INTRA_PRED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eConstrainedIntraPredFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("ENTROPY_CODING_SYNC_ENABLED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eEntropyCodingSyncEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eDeblockingFilterOverrideEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eDependentSliceSegmentsEnabledFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("DEPENDENT_SLICE_SEGMENT_FLAG_SET", vk::VideoEncodeH265StdFlagBitsKHR::eDependentSliceSegmentFlagSet);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("SLICE_QP_DELTA", vk::VideoEncodeH265StdFlagBitsKHR::eSliceQpDelta);
    e_vk_VideoEncodeH265StdFlagBitsKHR.value("DIFFERENT_SLICE_QP_DELTA", vk::VideoEncodeH265StdFlagBitsKHR::eDifferentSliceQpDelta);

    py::enum_<vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR> e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR(m_vk, "VideoEncodeH265TransformBlockSizeFlagBitsKHR");
    e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR.value("_4", vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR::e4);
    e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR.value("_8", vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR::e8);
    e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR.value("_16", vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR::e16);
    e_vk_VideoEncodeH265TransformBlockSizeFlagBitsKHR.value("_32", vk::VideoEncodeH265TransformBlockSizeFlagBitsKHR::e32);

    py::enum_<vk::VideoDecodeH264PictureLayoutFlagBitsKHR> e_vk_VideoDecodeH264PictureLayoutFlagBitsKHR(m_vk, "VideoDecodeH264PictureLayoutFlagBitsKHR");
    e_vk_VideoDecodeH264PictureLayoutFlagBitsKHR.value("PROGRESSIVE", vk::VideoDecodeH264PictureLayoutFlagBitsKHR::eProgressive);
    e_vk_VideoDecodeH264PictureLayoutFlagBitsKHR.value("INTERLACED_INTERLEAVED_LINES", vk::VideoDecodeH264PictureLayoutFlagBitsKHR::eInterlacedInterleavedLines);
    e_vk_VideoDecodeH264PictureLayoutFlagBitsKHR.value("INTERLACED_SEPARATE_PLANES", vk::VideoDecodeH264PictureLayoutFlagBitsKHR::eInterlacedSeparatePlanes);

    py::enum_<vk::ShaderInfoTypeAMD> e_vk_ShaderInfoTypeAMD(m_vk, "ShaderInfoTypeAMD");
    e_vk_ShaderInfoTypeAMD.value("STATISTICS", vk::ShaderInfoTypeAMD::eStatistics);
    e_vk_ShaderInfoTypeAMD.value("BINARY", vk::ShaderInfoTypeAMD::eBinary);
    e_vk_ShaderInfoTypeAMD.value("DISASSEMBLY", vk::ShaderInfoTypeAMD::eDisassembly);

    py::enum_<vk::ExternalMemoryFeatureFlagBitsNV> e_vk_ExternalMemoryFeatureFlagBitsNV(m_vk, "ExternalMemoryFeatureFlagBitsNV");
    e_vk_ExternalMemoryFeatureFlagBitsNV.value("DEDICATED_ONLY", vk::ExternalMemoryFeatureFlagBitsNV::eDedicatedOnly);
    e_vk_ExternalMemoryFeatureFlagBitsNV.value("EXPORTABLE", vk::ExternalMemoryFeatureFlagBitsNV::eExportable);
    e_vk_ExternalMemoryFeatureFlagBitsNV.value("IMPORTABLE", vk::ExternalMemoryFeatureFlagBitsNV::eImportable);

    py::enum_<vk::ExternalMemoryHandleTypeFlagBitsNV> e_vk_ExternalMemoryHandleTypeFlagBitsNV(m_vk, "ExternalMemoryHandleTypeFlagBitsNV");
    e_vk_ExternalMemoryHandleTypeFlagBitsNV.value("OPAQUE_WIN_32", vk::ExternalMemoryHandleTypeFlagBitsNV::eOpaqueWin32);
    e_vk_ExternalMemoryHandleTypeFlagBitsNV.value("OPAQUE_WIN_32_KMT", vk::ExternalMemoryHandleTypeFlagBitsNV::eOpaqueWin32Kmt);
    e_vk_ExternalMemoryHandleTypeFlagBitsNV.value("D3D11_IMAGE", vk::ExternalMemoryHandleTypeFlagBitsNV::eD3D11Image);
    e_vk_ExternalMemoryHandleTypeFlagBitsNV.value("D3D11_IMAGE_KMT", vk::ExternalMemoryHandleTypeFlagBitsNV::eD3D11ImageKmt);

    py::enum_<vk::ValidationCheckEXT> e_vk_ValidationCheckEXT(m_vk, "ValidationCheckEXT");
    e_vk_ValidationCheckEXT.value("ALL", vk::ValidationCheckEXT::eAll);
    e_vk_ValidationCheckEXT.value("SHADERS", vk::ValidationCheckEXT::eShaders);

    py::enum_<vk::PipelineRobustnessBufferBehaviorEXT> e_vk_PipelineRobustnessBufferBehaviorEXT(m_vk, "PipelineRobustnessBufferBehaviorEXT");
    e_vk_PipelineRobustnessBufferBehaviorEXT.value("DEVICE_DEFAULT", vk::PipelineRobustnessBufferBehaviorEXT::eDeviceDefault);
    e_vk_PipelineRobustnessBufferBehaviorEXT.value("DISABLED", vk::PipelineRobustnessBufferBehaviorEXT::eDisabled);
    e_vk_PipelineRobustnessBufferBehaviorEXT.value("ROBUST_BUFFER_ACCESS", vk::PipelineRobustnessBufferBehaviorEXT::eRobustBufferAccess);
    e_vk_PipelineRobustnessBufferBehaviorEXT.value("ROBUST_BUFFER_ACCESS_2", vk::PipelineRobustnessBufferBehaviorEXT::eRobustBufferAccess2);

    py::enum_<vk::PipelineRobustnessImageBehaviorEXT> e_vk_PipelineRobustnessImageBehaviorEXT(m_vk, "PipelineRobustnessImageBehaviorEXT");
    e_vk_PipelineRobustnessImageBehaviorEXT.value("DEVICE_DEFAULT", vk::PipelineRobustnessImageBehaviorEXT::eDeviceDefault);
    e_vk_PipelineRobustnessImageBehaviorEXT.value("DISABLED", vk::PipelineRobustnessImageBehaviorEXT::eDisabled);
    e_vk_PipelineRobustnessImageBehaviorEXT.value("ROBUST_IMAGE_ACCESS", vk::PipelineRobustnessImageBehaviorEXT::eRobustImageAccess);
    e_vk_PipelineRobustnessImageBehaviorEXT.value("ROBUST_IMAGE_ACCESS_2", vk::PipelineRobustnessImageBehaviorEXT::eRobustImageAccess2);

    py::enum_<vk::ConditionalRenderingFlagBitsEXT> e_vk_ConditionalRenderingFlagBitsEXT(m_vk, "ConditionalRenderingFlagBitsEXT");
    e_vk_ConditionalRenderingFlagBitsEXT.value("INVERTED", vk::ConditionalRenderingFlagBitsEXT::eInverted);

    py::enum_<vk::SurfaceCounterFlagBitsEXT> e_vk_SurfaceCounterFlagBitsEXT(m_vk, "SurfaceCounterFlagBitsEXT");
    e_vk_SurfaceCounterFlagBitsEXT.value("VBLANK", vk::SurfaceCounterFlagBitsEXT::eVblank);

    py::enum_<vk::DeviceEventTypeEXT> e_vk_DeviceEventTypeEXT(m_vk, "DeviceEventTypeEXT");
    e_vk_DeviceEventTypeEXT.value("DISPLAY_HOTPLUG", vk::DeviceEventTypeEXT::eDisplayHotplug);

    py::enum_<vk::DisplayEventTypeEXT> e_vk_DisplayEventTypeEXT(m_vk, "DisplayEventTypeEXT");
    e_vk_DisplayEventTypeEXT.value("FIRST_PIXEL_OUT", vk::DisplayEventTypeEXT::eFirstPixelOut);

    py::enum_<vk::DisplayPowerStateEXT> e_vk_DisplayPowerStateEXT(m_vk, "DisplayPowerStateEXT");
    e_vk_DisplayPowerStateEXT.value("OFF", vk::DisplayPowerStateEXT::eOff);
    e_vk_DisplayPowerStateEXT.value("SUSPEND", vk::DisplayPowerStateEXT::eSuspend);
    e_vk_DisplayPowerStateEXT.value("ON", vk::DisplayPowerStateEXT::eOn);

    py::enum_<vk::PipelineViewportSwizzleStateCreateFlagBitsNV> e_vk_PipelineViewportSwizzleStateCreateFlagBitsNV(m_vk, "PipelineViewportSwizzleStateCreateFlagBitsNV");

    py::enum_<vk::ViewportCoordinateSwizzleNV> e_vk_ViewportCoordinateSwizzleNV(m_vk, "ViewportCoordinateSwizzleNV");
    e_vk_ViewportCoordinateSwizzleNV.value("POSITIVE_X", vk::ViewportCoordinateSwizzleNV::ePositiveX);
    e_vk_ViewportCoordinateSwizzleNV.value("NEGATIVE_X", vk::ViewportCoordinateSwizzleNV::eNegativeX);
    e_vk_ViewportCoordinateSwizzleNV.value("POSITIVE_Y", vk::ViewportCoordinateSwizzleNV::ePositiveY);
    e_vk_ViewportCoordinateSwizzleNV.value("NEGATIVE_Y", vk::ViewportCoordinateSwizzleNV::eNegativeY);
    e_vk_ViewportCoordinateSwizzleNV.value("POSITIVE_Z", vk::ViewportCoordinateSwizzleNV::ePositiveZ);
    e_vk_ViewportCoordinateSwizzleNV.value("NEGATIVE_Z", vk::ViewportCoordinateSwizzleNV::eNegativeZ);
    e_vk_ViewportCoordinateSwizzleNV.value("POSITIVE_W", vk::ViewportCoordinateSwizzleNV::ePositiveW);
    e_vk_ViewportCoordinateSwizzleNV.value("NEGATIVE_W", vk::ViewportCoordinateSwizzleNV::eNegativeW);

    py::enum_<vk::DiscardRectangleModeEXT> e_vk_DiscardRectangleModeEXT(m_vk, "DiscardRectangleModeEXT");
    e_vk_DiscardRectangleModeEXT.value("INCLUSIVE", vk::DiscardRectangleModeEXT::eInclusive);
    e_vk_DiscardRectangleModeEXT.value("EXCLUSIVE", vk::DiscardRectangleModeEXT::eExclusive);

    py::enum_<vk::PipelineDiscardRectangleStateCreateFlagBitsEXT> e_vk_PipelineDiscardRectangleStateCreateFlagBitsEXT(m_vk, "PipelineDiscardRectangleStateCreateFlagBitsEXT");

    py::enum_<vk::ConservativeRasterizationModeEXT> e_vk_ConservativeRasterizationModeEXT(m_vk, "ConservativeRasterizationModeEXT");
    e_vk_ConservativeRasterizationModeEXT.value("DISABLED", vk::ConservativeRasterizationModeEXT::eDisabled);
    e_vk_ConservativeRasterizationModeEXT.value("OVERESTIMATE", vk::ConservativeRasterizationModeEXT::eOverestimate);
    e_vk_ConservativeRasterizationModeEXT.value("UNDERESTIMATE", vk::ConservativeRasterizationModeEXT::eUnderestimate);

    py::enum_<vk::PipelineRasterizationConservativeStateCreateFlagBitsEXT> e_vk_PipelineRasterizationConservativeStateCreateFlagBitsEXT(m_vk, "PipelineRasterizationConservativeStateCreateFlagBitsEXT");

    py::enum_<vk::PipelineRasterizationDepthClipStateCreateFlagBitsEXT> e_vk_PipelineRasterizationDepthClipStateCreateFlagBitsEXT(m_vk, "PipelineRasterizationDepthClipStateCreateFlagBitsEXT");

    py::enum_<vk::AcquireProfilingLockFlagBitsKHR> e_vk_AcquireProfilingLockFlagBitsKHR(m_vk, "AcquireProfilingLockFlagBitsKHR");

    py::enum_<vk::PerformanceCounterDescriptionFlagBitsKHR> e_vk_PerformanceCounterDescriptionFlagBitsKHR(m_vk, "PerformanceCounterDescriptionFlagBitsKHR");
    e_vk_PerformanceCounterDescriptionFlagBitsKHR.value("PERFORMANCE_IMPACTING", vk::PerformanceCounterDescriptionFlagBitsKHR::ePerformanceImpacting);
    e_vk_PerformanceCounterDescriptionFlagBitsKHR.value("CONCURRENTLY_IMPACTED", vk::PerformanceCounterDescriptionFlagBitsKHR::eConcurrentlyImpacted);

    py::enum_<vk::PerformanceCounterScopeKHR> e_vk_PerformanceCounterScopeKHR(m_vk, "PerformanceCounterScopeKHR");
    e_vk_PerformanceCounterScopeKHR.value("COMMAND_BUFFER", vk::PerformanceCounterScopeKHR::eCommandBuffer);
    e_vk_PerformanceCounterScopeKHR.value("RENDER_PASS", vk::PerformanceCounterScopeKHR::eRenderPass);
    e_vk_PerformanceCounterScopeKHR.value("COMMAND", vk::PerformanceCounterScopeKHR::eCommand);
    e_vk_PerformanceCounterScopeKHR.value("VK_QUERY_SCOPE_COMMAND_BUFFER", vk::PerformanceCounterScopeKHR::eVkQueryScopeCommandBuffer);
    e_vk_PerformanceCounterScopeKHR.value("VK_QUERY_SCOPE_RENDER_PASS", vk::PerformanceCounterScopeKHR::eVkQueryScopeRenderPass);
    e_vk_PerformanceCounterScopeKHR.value("VK_QUERY_SCOPE_COMMAND", vk::PerformanceCounterScopeKHR::eVkQueryScopeCommand);

    py::enum_<vk::PerformanceCounterStorageKHR> e_vk_PerformanceCounterStorageKHR(m_vk, "PerformanceCounterStorageKHR");
    e_vk_PerformanceCounterStorageKHR.value("INT_32", vk::PerformanceCounterStorageKHR::eInt32);
    e_vk_PerformanceCounterStorageKHR.value("INT_64", vk::PerformanceCounterStorageKHR::eInt64);
    e_vk_PerformanceCounterStorageKHR.value("UINT_32", vk::PerformanceCounterStorageKHR::eUint32);
    e_vk_PerformanceCounterStorageKHR.value("UINT_64", vk::PerformanceCounterStorageKHR::eUint64);
    e_vk_PerformanceCounterStorageKHR.value("FLOAT_32", vk::PerformanceCounterStorageKHR::eFloat32);
    e_vk_PerformanceCounterStorageKHR.value("FLOAT_64", vk::PerformanceCounterStorageKHR::eFloat64);

    py::enum_<vk::PerformanceCounterUnitKHR> e_vk_PerformanceCounterUnitKHR(m_vk, "PerformanceCounterUnitKHR");
    e_vk_PerformanceCounterUnitKHR.value("GENERIC", vk::PerformanceCounterUnitKHR::eGeneric);
    e_vk_PerformanceCounterUnitKHR.value("PERCENTAGE", vk::PerformanceCounterUnitKHR::ePercentage);
    e_vk_PerformanceCounterUnitKHR.value("NANOSECONDS", vk::PerformanceCounterUnitKHR::eNanoseconds);
    e_vk_PerformanceCounterUnitKHR.value("BYTES", vk::PerformanceCounterUnitKHR::eBytes);
    e_vk_PerformanceCounterUnitKHR.value("BYTES_PER_SECOND", vk::PerformanceCounterUnitKHR::eBytesPerSecond);
    e_vk_PerformanceCounterUnitKHR.value("KELVIN", vk::PerformanceCounterUnitKHR::eKelvin);
    e_vk_PerformanceCounterUnitKHR.value("WATTS", vk::PerformanceCounterUnitKHR::eWatts);
    e_vk_PerformanceCounterUnitKHR.value("VOLTS", vk::PerformanceCounterUnitKHR::eVolts);
    e_vk_PerformanceCounterUnitKHR.value("AMPS", vk::PerformanceCounterUnitKHR::eAmps);
    e_vk_PerformanceCounterUnitKHR.value("HERTZ", vk::PerformanceCounterUnitKHR::eHertz);
    e_vk_PerformanceCounterUnitKHR.value("CYCLES", vk::PerformanceCounterUnitKHR::eCycles);

    py::enum_<vk::DebugUtilsMessageSeverityFlagBitsEXT> e_vk_DebugUtilsMessageSeverityFlagBitsEXT(m_vk, "DebugUtilsMessageSeverityFlagBitsEXT");
    e_vk_DebugUtilsMessageSeverityFlagBitsEXT.value("VERBOSE", vk::DebugUtilsMessageSeverityFlagBitsEXT::eVerbose);
    e_vk_DebugUtilsMessageSeverityFlagBitsEXT.value("INFO", vk::DebugUtilsMessageSeverityFlagBitsEXT::eInfo);
    e_vk_DebugUtilsMessageSeverityFlagBitsEXT.value("WARNING", vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning);
    e_vk_DebugUtilsMessageSeverityFlagBitsEXT.value("ERROR", vk::DebugUtilsMessageSeverityFlagBitsEXT::eError);

    py::enum_<vk::DebugUtilsMessageTypeFlagBitsEXT> e_vk_DebugUtilsMessageTypeFlagBitsEXT(m_vk, "DebugUtilsMessageTypeFlagBitsEXT");
    e_vk_DebugUtilsMessageTypeFlagBitsEXT.value("GENERAL", vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral);
    e_vk_DebugUtilsMessageTypeFlagBitsEXT.value("VALIDATION", vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation);
    e_vk_DebugUtilsMessageTypeFlagBitsEXT.value("PERFORMANCE", vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance);
    e_vk_DebugUtilsMessageTypeFlagBitsEXT.value("DEVICE_ADDRESS_BINDING", vk::DebugUtilsMessageTypeFlagBitsEXT::eDeviceAddressBinding);

    py::enum_<vk::DebugUtilsMessengerCallbackDataFlagBitsEXT> e_vk_DebugUtilsMessengerCallbackDataFlagBitsEXT(m_vk, "DebugUtilsMessengerCallbackDataFlagBitsEXT");

    py::enum_<vk::DebugUtilsMessengerCreateFlagBitsEXT> e_vk_DebugUtilsMessengerCreateFlagBitsEXT(m_vk, "DebugUtilsMessengerCreateFlagBitsEXT");

    py::enum_<vk::BlendOverlapEXT> e_vk_BlendOverlapEXT(m_vk, "BlendOverlapEXT");
    e_vk_BlendOverlapEXT.value("UNCORRELATED", vk::BlendOverlapEXT::eUncorrelated);
    e_vk_BlendOverlapEXT.value("DISJOINT", vk::BlendOverlapEXT::eDisjoint);
    e_vk_BlendOverlapEXT.value("CONJOINT", vk::BlendOverlapEXT::eConjoint);

    py::enum_<vk::PipelineCoverageToColorStateCreateFlagBitsNV> e_vk_PipelineCoverageToColorStateCreateFlagBitsNV(m_vk, "PipelineCoverageToColorStateCreateFlagBitsNV");

    py::enum_<vk::AccelerationStructureBuildTypeKHR> e_vk_AccelerationStructureBuildTypeKHR(m_vk, "AccelerationStructureBuildTypeKHR");
    e_vk_AccelerationStructureBuildTypeKHR.value("HOST", vk::AccelerationStructureBuildTypeKHR::eHost);
    e_vk_AccelerationStructureBuildTypeKHR.value("DEVICE", vk::AccelerationStructureBuildTypeKHR::eDevice);
    e_vk_AccelerationStructureBuildTypeKHR.value("HOST_OR_DEVICE", vk::AccelerationStructureBuildTypeKHR::eHostOrDevice);

    py::enum_<vk::AccelerationStructureCompatibilityKHR> e_vk_AccelerationStructureCompatibilityKHR(m_vk, "AccelerationStructureCompatibilityKHR");
    e_vk_AccelerationStructureCompatibilityKHR.value("COMPATIBLE", vk::AccelerationStructureCompatibilityKHR::eCompatible);
    e_vk_AccelerationStructureCompatibilityKHR.value("INCOMPATIBLE", vk::AccelerationStructureCompatibilityKHR::eIncompatible);

    py::enum_<vk::AccelerationStructureCreateFlagBitsKHR> e_vk_AccelerationStructureCreateFlagBitsKHR(m_vk, "AccelerationStructureCreateFlagBitsKHR");
    e_vk_AccelerationStructureCreateFlagBitsKHR.value("DEVICE_ADDRESS_CAPTURE_REPLAY", vk::AccelerationStructureCreateFlagBitsKHR::eDeviceAddressCaptureReplay);
    e_vk_AccelerationStructureCreateFlagBitsKHR.value("DESCRIPTOR_BUFFER_CAPTURE_REPLAY_EXT", vk::AccelerationStructureCreateFlagBitsKHR::eDescriptorBufferCaptureReplayEXT);
    e_vk_AccelerationStructureCreateFlagBitsKHR.value("MOTION_NV", vk::AccelerationStructureCreateFlagBitsKHR::eMotionNV);

    py::enum_<vk::AccelerationStructureTypeKHR> e_vk_AccelerationStructureTypeKHR(m_vk, "AccelerationStructureTypeKHR");
    e_vk_AccelerationStructureTypeKHR.value("TOP_LEVEL", vk::AccelerationStructureTypeKHR::eTopLevel);
    e_vk_AccelerationStructureTypeKHR.value("BOTTOM_LEVEL", vk::AccelerationStructureTypeKHR::eBottomLevel);
    e_vk_AccelerationStructureTypeKHR.value("GENERIC", vk::AccelerationStructureTypeKHR::eGeneric);

    py::enum_<vk::BuildAccelerationStructureFlagBitsKHR> e_vk_BuildAccelerationStructureFlagBitsKHR(m_vk, "BuildAccelerationStructureFlagBitsKHR");
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_UPDATE", vk::BuildAccelerationStructureFlagBitsKHR::eAllowUpdate);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_COMPACTION", vk::BuildAccelerationStructureFlagBitsKHR::eAllowCompaction);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("PREFER_FAST_TRACE", vk::BuildAccelerationStructureFlagBitsKHR::ePreferFastTrace);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("PREFER_FAST_BUILD", vk::BuildAccelerationStructureFlagBitsKHR::ePreferFastBuild);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("LOW_MEMORY", vk::BuildAccelerationStructureFlagBitsKHR::eLowMemory);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("MOTION_NV", vk::BuildAccelerationStructureFlagBitsKHR::eMotionNV);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_OPACITY_MICROMAP_UPDATE_EXT", vk::BuildAccelerationStructureFlagBitsKHR::eAllowOpacityMicromapUpdateEXT);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_DISABLE_OPACITY_MICROMAPS_EXT", vk::BuildAccelerationStructureFlagBitsKHR::eAllowDisableOpacityMicromapsEXT);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_OPACITY_MICROMAP_DATA_UPDATE_EXT", vk::BuildAccelerationStructureFlagBitsKHR::eAllowOpacityMicromapDataUpdateEXT);
    e_vk_BuildAccelerationStructureFlagBitsKHR.value("ALLOW_DATA_ACCESS", vk::BuildAccelerationStructureFlagBitsKHR::eAllowDataAccess);

    py::enum_<vk::BuildAccelerationStructureModeKHR> e_vk_BuildAccelerationStructureModeKHR(m_vk, "BuildAccelerationStructureModeKHR");
    e_vk_BuildAccelerationStructureModeKHR.value("BUILD", vk::BuildAccelerationStructureModeKHR::eBuild);
    e_vk_BuildAccelerationStructureModeKHR.value("UPDATE", vk::BuildAccelerationStructureModeKHR::eUpdate);

    py::enum_<vk::CopyAccelerationStructureModeKHR> e_vk_CopyAccelerationStructureModeKHR(m_vk, "CopyAccelerationStructureModeKHR");
    e_vk_CopyAccelerationStructureModeKHR.value("CLONE", vk::CopyAccelerationStructureModeKHR::eClone);
    e_vk_CopyAccelerationStructureModeKHR.value("COMPACT", vk::CopyAccelerationStructureModeKHR::eCompact);
    e_vk_CopyAccelerationStructureModeKHR.value("SERIALIZE", vk::CopyAccelerationStructureModeKHR::eSerialize);
    e_vk_CopyAccelerationStructureModeKHR.value("DESERIALIZE", vk::CopyAccelerationStructureModeKHR::eDeserialize);

    py::enum_<vk::GeometryFlagBitsKHR> e_vk_GeometryFlagBitsKHR(m_vk, "GeometryFlagBitsKHR");
    e_vk_GeometryFlagBitsKHR.value("OPAQUE", vk::GeometryFlagBitsKHR::eOpaque);
    e_vk_GeometryFlagBitsKHR.value("NO_DUPLICATE_ANY_HIT_INVOCATION", vk::GeometryFlagBitsKHR::eNoDuplicateAnyHitInvocation);

    py::enum_<vk::GeometryInstanceFlagBitsKHR> e_vk_GeometryInstanceFlagBitsKHR(m_vk, "GeometryInstanceFlagBitsKHR");
    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_FACING_CULL_DISABLE", vk::GeometryInstanceFlagBitsKHR::eTriangleFacingCullDisable);
    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_FLIP_FACING", vk::GeometryInstanceFlagBitsKHR::eTriangleFlipFacing);
    e_vk_GeometryInstanceFlagBitsKHR.value("FORCE_OPAQUE", vk::GeometryInstanceFlagBitsKHR::eForceOpaque);
    e_vk_GeometryInstanceFlagBitsKHR.value("FORCE_NO_OPAQUE", vk::GeometryInstanceFlagBitsKHR::eForceNoOpaque);
    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_FRONT_COUNTERCLOCKWISE_KHR", vk::GeometryInstanceFlagBitsKHR::eTriangleFrontCounterclockwiseKHR);
    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_CULL_DISABLE", vk::GeometryInstanceFlagBitsKHR::eTriangleCullDisable);
    e_vk_GeometryInstanceFlagBitsKHR.value("TRIANGLE_FRONT_COUNTERCLOCKWISE", vk::GeometryInstanceFlagBitsKHR::eTriangleFrontCounterclockwise);
    e_vk_GeometryInstanceFlagBitsKHR.value("FORCE_OPACITY_MICROMAP_2_STATE_EXT", vk::GeometryInstanceFlagBitsKHR::eForceOpacityMicromap2StateEXT);
    e_vk_GeometryInstanceFlagBitsKHR.value("DISABLE_OPACITY_MICROMAPS_EXT", vk::GeometryInstanceFlagBitsKHR::eDisableOpacityMicromapsEXT);

    py::enum_<vk::GeometryTypeKHR> e_vk_GeometryTypeKHR(m_vk, "GeometryTypeKHR");
    e_vk_GeometryTypeKHR.value("TRIANGLES", vk::GeometryTypeKHR::eTriangles);
    e_vk_GeometryTypeKHR.value("AABBS", vk::GeometryTypeKHR::eAabbs);
    e_vk_GeometryTypeKHR.value("INSTANCES", vk::GeometryTypeKHR::eInstances);

    py::enum_<vk::RayTracingShaderGroupTypeKHR> e_vk_RayTracingShaderGroupTypeKHR(m_vk, "RayTracingShaderGroupTypeKHR");
    e_vk_RayTracingShaderGroupTypeKHR.value("GENERAL", vk::RayTracingShaderGroupTypeKHR::eGeneral);
    e_vk_RayTracingShaderGroupTypeKHR.value("TRIANGLES_HIT_GROUP", vk::RayTracingShaderGroupTypeKHR::eTrianglesHitGroup);
    e_vk_RayTracingShaderGroupTypeKHR.value("PROCEDURAL_HIT_GROUP", vk::RayTracingShaderGroupTypeKHR::eProceduralHitGroup);

    py::enum_<vk::ShaderGroupShaderKHR> e_vk_ShaderGroupShaderKHR(m_vk, "ShaderGroupShaderKHR");
    e_vk_ShaderGroupShaderKHR.value("GENERAL", vk::ShaderGroupShaderKHR::eGeneral);
    e_vk_ShaderGroupShaderKHR.value("CLOSEST_HIT", vk::ShaderGroupShaderKHR::eClosestHit);
    e_vk_ShaderGroupShaderKHR.value("ANY_HIT", vk::ShaderGroupShaderKHR::eAnyHit);
    e_vk_ShaderGroupShaderKHR.value("INTERSECTION", vk::ShaderGroupShaderKHR::eIntersection);

    py::enum_<vk::CoverageModulationModeNV> e_vk_CoverageModulationModeNV(m_vk, "CoverageModulationModeNV");
    e_vk_CoverageModulationModeNV.value("NONE", vk::CoverageModulationModeNV::eNone);
    e_vk_CoverageModulationModeNV.value("RGB", vk::CoverageModulationModeNV::eRgb);
    e_vk_CoverageModulationModeNV.value("ALPHA", vk::CoverageModulationModeNV::eAlpha);
    e_vk_CoverageModulationModeNV.value("RGBA", vk::CoverageModulationModeNV::eRgba);

    py::enum_<vk::PipelineCoverageModulationStateCreateFlagBitsNV> e_vk_PipelineCoverageModulationStateCreateFlagBitsNV(m_vk, "PipelineCoverageModulationStateCreateFlagBitsNV");

    py::enum_<vk::ValidationCacheCreateFlagBitsEXT> e_vk_ValidationCacheCreateFlagBitsEXT(m_vk, "ValidationCacheCreateFlagBitsEXT");

    py::enum_<vk::ValidationCacheHeaderVersionEXT> e_vk_ValidationCacheHeaderVersionEXT(m_vk, "ValidationCacheHeaderVersionEXT");
    e_vk_ValidationCacheHeaderVersionEXT.value("ONE", vk::ValidationCacheHeaderVersionEXT::eOne);

    py::enum_<vk::CoarseSampleOrderTypeNV> e_vk_CoarseSampleOrderTypeNV(m_vk, "CoarseSampleOrderTypeNV");
    e_vk_CoarseSampleOrderTypeNV.value("DEFAULT", vk::CoarseSampleOrderTypeNV::eDefault);
    e_vk_CoarseSampleOrderTypeNV.value("CUSTOM", vk::CoarseSampleOrderTypeNV::eCustom);
    e_vk_CoarseSampleOrderTypeNV.value("PIXEL_MAJOR", vk::CoarseSampleOrderTypeNV::ePixelMajor);
    e_vk_CoarseSampleOrderTypeNV.value("SAMPLE_MAJOR", vk::CoarseSampleOrderTypeNV::eSampleMajor);

    py::enum_<vk::ShadingRatePaletteEntryNV> e_vk_ShadingRatePaletteEntryNV(m_vk, "ShadingRatePaletteEntryNV");
    e_vk_ShadingRatePaletteEntryNV.value("NO_INVOCATIONS", vk::ShadingRatePaletteEntryNV::eNoInvocations);
    e_vk_ShadingRatePaletteEntryNV.value("_16_INVOCATIONS_PER_PIXEL", vk::ShadingRatePaletteEntryNV::e16InvocationsPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("_8_INVOCATIONS_PER_PIXEL", vk::ShadingRatePaletteEntryNV::e8InvocationsPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("_4_INVOCATIONS_PER_PIXEL", vk::ShadingRatePaletteEntryNV::e4InvocationsPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("_2_INVOCATIONS_PER_PIXEL", vk::ShadingRatePaletteEntryNV::e2InvocationsPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("_1_INVOCATION_PER_PIXEL", vk::ShadingRatePaletteEntryNV::e1InvocationPerPixel);
    e_vk_ShadingRatePaletteEntryNV.value("_1_INVOCATION_PER_2X1_PIXELS", vk::ShadingRatePaletteEntryNV::e1InvocationPer2X1Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("_1_INVOCATION_PER_1X2_PIXELS", vk::ShadingRatePaletteEntryNV::e1InvocationPer1X2Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("_1_INVOCATION_PER_2X2_PIXELS", vk::ShadingRatePaletteEntryNV::e1InvocationPer2X2Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("_1_INVOCATION_PER_4X2_PIXELS", vk::ShadingRatePaletteEntryNV::e1InvocationPer4X2Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("_1_INVOCATION_PER_2X4_PIXELS", vk::ShadingRatePaletteEntryNV::e1InvocationPer2X4Pixels);
    e_vk_ShadingRatePaletteEntryNV.value("_1_INVOCATION_PER_4X4_PIXELS", vk::ShadingRatePaletteEntryNV::e1InvocationPer4X4Pixels);

    py::enum_<vk::AccelerationStructureMemoryRequirementsTypeNV> e_vk_AccelerationStructureMemoryRequirementsTypeNV(m_vk, "AccelerationStructureMemoryRequirementsTypeNV");
    e_vk_AccelerationStructureMemoryRequirementsTypeNV.value("OBJECT", vk::AccelerationStructureMemoryRequirementsTypeNV::eObject);
    e_vk_AccelerationStructureMemoryRequirementsTypeNV.value("BUILD_SCRATCH", vk::AccelerationStructureMemoryRequirementsTypeNV::eBuildScratch);
    e_vk_AccelerationStructureMemoryRequirementsTypeNV.value("UPDATE_SCRATCH", vk::AccelerationStructureMemoryRequirementsTypeNV::eUpdateScratch);

    py::enum_<vk::PipelineCompilerControlFlagBitsAMD> e_vk_PipelineCompilerControlFlagBitsAMD(m_vk, "PipelineCompilerControlFlagBitsAMD");

    py::enum_<vk::QueueGlobalPriorityKHR> e_vk_QueueGlobalPriorityKHR(m_vk, "QueueGlobalPriorityKHR");
    e_vk_QueueGlobalPriorityKHR.value("LOW", vk::QueueGlobalPriorityKHR::eLow);
    e_vk_QueueGlobalPriorityKHR.value("MEDIUM", vk::QueueGlobalPriorityKHR::eMedium);
    e_vk_QueueGlobalPriorityKHR.value("HIGH", vk::QueueGlobalPriorityKHR::eHigh);
    e_vk_QueueGlobalPriorityKHR.value("REALTIME", vk::QueueGlobalPriorityKHR::eRealtime);

    py::enum_<vk::MemoryOverallocationBehaviorAMD> e_vk_MemoryOverallocationBehaviorAMD(m_vk, "MemoryOverallocationBehaviorAMD");
    e_vk_MemoryOverallocationBehaviorAMD.value("DEFAULT", vk::MemoryOverallocationBehaviorAMD::eDefault);
    e_vk_MemoryOverallocationBehaviorAMD.value("ALLOWED", vk::MemoryOverallocationBehaviorAMD::eAllowed);
    e_vk_MemoryOverallocationBehaviorAMD.value("DISALLOWED", vk::MemoryOverallocationBehaviorAMD::eDisallowed);

    py::enum_<vk::PerformanceConfigurationTypeINTEL> e_vk_PerformanceConfigurationTypeINTEL(m_vk, "PerformanceConfigurationTypeINTEL");
    e_vk_PerformanceConfigurationTypeINTEL.value("COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED", vk::PerformanceConfigurationTypeINTEL::eCommandQueueMetricsDiscoveryActivated);

    py::enum_<vk::PerformanceOverrideTypeINTEL> e_vk_PerformanceOverrideTypeINTEL(m_vk, "PerformanceOverrideTypeINTEL");
    e_vk_PerformanceOverrideTypeINTEL.value("NULL_HARDWARE", vk::PerformanceOverrideTypeINTEL::eNullHardware);
    e_vk_PerformanceOverrideTypeINTEL.value("FLUSH_GPU_CACHES", vk::PerformanceOverrideTypeINTEL::eFlushGpuCaches);

    py::enum_<vk::PerformanceParameterTypeINTEL> e_vk_PerformanceParameterTypeINTEL(m_vk, "PerformanceParameterTypeINTEL");
    e_vk_PerformanceParameterTypeINTEL.value("HW_COUNTERS_SUPPORTED", vk::PerformanceParameterTypeINTEL::eHwCountersSupported);
    e_vk_PerformanceParameterTypeINTEL.value("STREAM_MARKER_VALID_BITS", vk::PerformanceParameterTypeINTEL::eStreamMarkerValidBits);

    py::enum_<vk::PerformanceValueTypeINTEL> e_vk_PerformanceValueTypeINTEL(m_vk, "PerformanceValueTypeINTEL");
    e_vk_PerformanceValueTypeINTEL.value("UINT_32", vk::PerformanceValueTypeINTEL::eUint32);
    e_vk_PerformanceValueTypeINTEL.value("UINT_64", vk::PerformanceValueTypeINTEL::eUint64);
    e_vk_PerformanceValueTypeINTEL.value("FLOAT", vk::PerformanceValueTypeINTEL::eFloat);
    e_vk_PerformanceValueTypeINTEL.value("BOOL", vk::PerformanceValueTypeINTEL::eBool);
    e_vk_PerformanceValueTypeINTEL.value("STRING", vk::PerformanceValueTypeINTEL::eString);

    py::enum_<vk::QueryPoolSamplingModeINTEL> e_vk_QueryPoolSamplingModeINTEL(m_vk, "QueryPoolSamplingModeINTEL");
    e_vk_QueryPoolSamplingModeINTEL.value("MANUAL", vk::QueryPoolSamplingModeINTEL::eManual);

    py::enum_<vk::FragmentShadingRateCombinerOpKHR> e_vk_FragmentShadingRateCombinerOpKHR(m_vk, "FragmentShadingRateCombinerOpKHR");
    e_vk_FragmentShadingRateCombinerOpKHR.value("KEEP", vk::FragmentShadingRateCombinerOpKHR::eKeep);
    e_vk_FragmentShadingRateCombinerOpKHR.value("REPLACE", vk::FragmentShadingRateCombinerOpKHR::eReplace);
    e_vk_FragmentShadingRateCombinerOpKHR.value("MIN", vk::FragmentShadingRateCombinerOpKHR::eMin);
    e_vk_FragmentShadingRateCombinerOpKHR.value("MAX", vk::FragmentShadingRateCombinerOpKHR::eMax);
    e_vk_FragmentShadingRateCombinerOpKHR.value("MUL", vk::FragmentShadingRateCombinerOpKHR::eMul);

    py::enum_<vk::ShaderCorePropertiesFlagBitsAMD> e_vk_ShaderCorePropertiesFlagBitsAMD(m_vk, "ShaderCorePropertiesFlagBitsAMD");

    py::enum_<vk::ValidationFeatureDisableEXT> e_vk_ValidationFeatureDisableEXT(m_vk, "ValidationFeatureDisableEXT");
    e_vk_ValidationFeatureDisableEXT.value("ALL", vk::ValidationFeatureDisableEXT::eAll);
    e_vk_ValidationFeatureDisableEXT.value("SHADERS", vk::ValidationFeatureDisableEXT::eShaders);
    e_vk_ValidationFeatureDisableEXT.value("THREAD_SAFETY", vk::ValidationFeatureDisableEXT::eThreadSafety);
    e_vk_ValidationFeatureDisableEXT.value("API_PARAMETERS", vk::ValidationFeatureDisableEXT::eApiParameters);
    e_vk_ValidationFeatureDisableEXT.value("OBJECT_LIFETIMES", vk::ValidationFeatureDisableEXT::eObjectLifetimes);
    e_vk_ValidationFeatureDisableEXT.value("CORE_CHECKS", vk::ValidationFeatureDisableEXT::eCoreChecks);
    e_vk_ValidationFeatureDisableEXT.value("UNIQUE_HANDLES", vk::ValidationFeatureDisableEXT::eUniqueHandles);
    e_vk_ValidationFeatureDisableEXT.value("SHADER_VALIDATION_CACHE", vk::ValidationFeatureDisableEXT::eShaderValidationCache);

    py::enum_<vk::ValidationFeatureEnableEXT> e_vk_ValidationFeatureEnableEXT(m_vk, "ValidationFeatureEnableEXT");
    e_vk_ValidationFeatureEnableEXT.value("GPU_ASSISTED", vk::ValidationFeatureEnableEXT::eGpuAssisted);
    e_vk_ValidationFeatureEnableEXT.value("GPU_ASSISTED_RESERVE_BINDING_SLOT", vk::ValidationFeatureEnableEXT::eGpuAssistedReserveBindingSlot);
    e_vk_ValidationFeatureEnableEXT.value("BEST_PRACTICES", vk::ValidationFeatureEnableEXT::eBestPractices);
    e_vk_ValidationFeatureEnableEXT.value("DEBUG_PRINTF", vk::ValidationFeatureEnableEXT::eDebugPrintf);
    e_vk_ValidationFeatureEnableEXT.value("SYNCHRONIZATION_VALIDATION", vk::ValidationFeatureEnableEXT::eSynchronizationValidation);

    py::enum_<vk::CoverageReductionModeNV> e_vk_CoverageReductionModeNV(m_vk, "CoverageReductionModeNV");
    e_vk_CoverageReductionModeNV.value("MERGE", vk::CoverageReductionModeNV::eMerge);
    e_vk_CoverageReductionModeNV.value("TRUNCATE", vk::CoverageReductionModeNV::eTruncate);

    py::enum_<vk::PipelineCoverageReductionStateCreateFlagBitsNV> e_vk_PipelineCoverageReductionStateCreateFlagBitsNV(m_vk, "PipelineCoverageReductionStateCreateFlagBitsNV");

    py::enum_<vk::ProvokingVertexModeEXT> e_vk_ProvokingVertexModeEXT(m_vk, "ProvokingVertexModeEXT");
    e_vk_ProvokingVertexModeEXT.value("FIRST_VERTEX", vk::ProvokingVertexModeEXT::eFirstVertex);
    e_vk_ProvokingVertexModeEXT.value("LAST_VERTEX", vk::ProvokingVertexModeEXT::eLastVertex);

    py::enum_<vk::HeadlessSurfaceCreateFlagBitsEXT> e_vk_HeadlessSurfaceCreateFlagBitsEXT(m_vk, "HeadlessSurfaceCreateFlagBitsEXT");

    py::enum_<vk::LineRasterizationModeEXT> e_vk_LineRasterizationModeEXT(m_vk, "LineRasterizationModeEXT");
    e_vk_LineRasterizationModeEXT.value("DEFAULT", vk::LineRasterizationModeEXT::eDefault);
    e_vk_LineRasterizationModeEXT.value("RECTANGULAR", vk::LineRasterizationModeEXT::eRectangular);
    e_vk_LineRasterizationModeEXT.value("BRESENHAM", vk::LineRasterizationModeEXT::eBresenham);
    e_vk_LineRasterizationModeEXT.value("RECTANGULAR_SMOOTH", vk::LineRasterizationModeEXT::eRectangularSmooth);

    py::enum_<vk::PipelineExecutableStatisticFormatKHR> e_vk_PipelineExecutableStatisticFormatKHR(m_vk, "PipelineExecutableStatisticFormatKHR");
    e_vk_PipelineExecutableStatisticFormatKHR.value("BOOL_32", vk::PipelineExecutableStatisticFormatKHR::eBool32);
    e_vk_PipelineExecutableStatisticFormatKHR.value("INT_64", vk::PipelineExecutableStatisticFormatKHR::eInt64);
    e_vk_PipelineExecutableStatisticFormatKHR.value("UINT_64", vk::PipelineExecutableStatisticFormatKHR::eUint64);
    e_vk_PipelineExecutableStatisticFormatKHR.value("FLOAT_64", vk::PipelineExecutableStatisticFormatKHR::eFloat64);

    py::enum_<vk::HostImageCopyFlagBitsEXT> e_vk_HostImageCopyFlagBitsEXT(m_vk, "HostImageCopyFlagBitsEXT");
    e_vk_HostImageCopyFlagBitsEXT.value("MEMCPY", vk::HostImageCopyFlagBitsEXT::eMemcpy);

    py::enum_<vk::MemoryUnmapFlagBitsKHR> e_vk_MemoryUnmapFlagBitsKHR(m_vk, "MemoryUnmapFlagBitsKHR");

    py::enum_<vk::PresentGravityFlagBitsEXT> e_vk_PresentGravityFlagBitsEXT(m_vk, "PresentGravityFlagBitsEXT");
    e_vk_PresentGravityFlagBitsEXT.value("MIN", vk::PresentGravityFlagBitsEXT::eMin);
    e_vk_PresentGravityFlagBitsEXT.value("MAX", vk::PresentGravityFlagBitsEXT::eMax);
    e_vk_PresentGravityFlagBitsEXT.value("CENTERED", vk::PresentGravityFlagBitsEXT::eCentered);

    py::enum_<vk::PresentScalingFlagBitsEXT> e_vk_PresentScalingFlagBitsEXT(m_vk, "PresentScalingFlagBitsEXT");
    e_vk_PresentScalingFlagBitsEXT.value("ONE_TO_ONE", vk::PresentScalingFlagBitsEXT::eOneToOne);
    e_vk_PresentScalingFlagBitsEXT.value("ASPECT_RATIO_STRETCH", vk::PresentScalingFlagBitsEXT::eAspectRatioStretch);
    e_vk_PresentScalingFlagBitsEXT.value("STRETCH", vk::PresentScalingFlagBitsEXT::eStretch);

    py::enum_<vk::IndirectCommandsLayoutUsageFlagBitsNV> e_vk_IndirectCommandsLayoutUsageFlagBitsNV(m_vk, "IndirectCommandsLayoutUsageFlagBitsNV");
    e_vk_IndirectCommandsLayoutUsageFlagBitsNV.value("EXPLICIT_PREPROCESS", vk::IndirectCommandsLayoutUsageFlagBitsNV::eExplicitPreprocess);
    e_vk_IndirectCommandsLayoutUsageFlagBitsNV.value("INDEXED_SEQUENCES", vk::IndirectCommandsLayoutUsageFlagBitsNV::eIndexedSequences);
    e_vk_IndirectCommandsLayoutUsageFlagBitsNV.value("UNORDERED_SEQUENCES", vk::IndirectCommandsLayoutUsageFlagBitsNV::eUnorderedSequences);

    py::enum_<vk::IndirectCommandsTokenTypeNV> e_vk_IndirectCommandsTokenTypeNV(m_vk, "IndirectCommandsTokenTypeNV");
    e_vk_IndirectCommandsTokenTypeNV.value("SHADER_GROUP", vk::IndirectCommandsTokenTypeNV::eShaderGroup);
    e_vk_IndirectCommandsTokenTypeNV.value("STATE_FLAGS", vk::IndirectCommandsTokenTypeNV::eStateFlags);
    e_vk_IndirectCommandsTokenTypeNV.value("INDEX_BUFFER", vk::IndirectCommandsTokenTypeNV::eIndexBuffer);
    e_vk_IndirectCommandsTokenTypeNV.value("VERTEX_BUFFER", vk::IndirectCommandsTokenTypeNV::eVertexBuffer);
    e_vk_IndirectCommandsTokenTypeNV.value("PUSH_CONSTANT", vk::IndirectCommandsTokenTypeNV::ePushConstant);
    e_vk_IndirectCommandsTokenTypeNV.value("DRAW_INDEXED", vk::IndirectCommandsTokenTypeNV::eDrawIndexed);
    e_vk_IndirectCommandsTokenTypeNV.value("DRAW", vk::IndirectCommandsTokenTypeNV::eDraw);
    e_vk_IndirectCommandsTokenTypeNV.value("DRAW_TASKS", vk::IndirectCommandsTokenTypeNV::eDrawTasks);
    e_vk_IndirectCommandsTokenTypeNV.value("DRAW_MESH_TASKS", vk::IndirectCommandsTokenTypeNV::eDrawMeshTasks);
    e_vk_IndirectCommandsTokenTypeNV.value("PIPELINE", vk::IndirectCommandsTokenTypeNV::ePipeline);
    e_vk_IndirectCommandsTokenTypeNV.value("DISPATCH", vk::IndirectCommandsTokenTypeNV::eDispatch);

    py::enum_<vk::IndirectStateFlagBitsNV> e_vk_IndirectStateFlagBitsNV(m_vk, "IndirectStateFlagBitsNV");
    e_vk_IndirectStateFlagBitsNV.value("FLAG_FRONTFACE", vk::IndirectStateFlagBitsNV::eFlagFrontface);

    py::enum_<vk::DepthBiasRepresentationEXT> e_vk_DepthBiasRepresentationEXT(m_vk, "DepthBiasRepresentationEXT");
    e_vk_DepthBiasRepresentationEXT.value("LEAST_REPRESENTABLE_VALUE_FORMAT", vk::DepthBiasRepresentationEXT::eLeastRepresentableValueFormat);
    e_vk_DepthBiasRepresentationEXT.value("LEAST_REPRESENTABLE_VALUE_FORCE_UNORM", vk::DepthBiasRepresentationEXT::eLeastRepresentableValueForceUnorm);
    e_vk_DepthBiasRepresentationEXT.value("FLOAT", vk::DepthBiasRepresentationEXT::eFloat);

    py::enum_<vk::DeviceMemoryReportEventTypeEXT> e_vk_DeviceMemoryReportEventTypeEXT(m_vk, "DeviceMemoryReportEventTypeEXT");
    e_vk_DeviceMemoryReportEventTypeEXT.value("ALLOCATE", vk::DeviceMemoryReportEventTypeEXT::eAllocate);
    e_vk_DeviceMemoryReportEventTypeEXT.value("FREE", vk::DeviceMemoryReportEventTypeEXT::eFree);
    e_vk_DeviceMemoryReportEventTypeEXT.value("IMPORT", vk::DeviceMemoryReportEventTypeEXT::eImport);
    e_vk_DeviceMemoryReportEventTypeEXT.value("UNIMPORT", vk::DeviceMemoryReportEventTypeEXT::eUnimport);
    e_vk_DeviceMemoryReportEventTypeEXT.value("ALLOCATION_FAILED", vk::DeviceMemoryReportEventTypeEXT::eAllocationFailed);

    py::enum_<vk::DeviceMemoryReportFlagBitsEXT> e_vk_DeviceMemoryReportFlagBitsEXT(m_vk, "DeviceMemoryReportFlagBitsEXT");

    py::enum_<vk::VideoEncodeCapabilityFlagBitsKHR> e_vk_VideoEncodeCapabilityFlagBitsKHR(m_vk, "VideoEncodeCapabilityFlagBitsKHR");
    e_vk_VideoEncodeCapabilityFlagBitsKHR.value("PRECEDING_EXTERNALLY_ENCODED_BYTES", vk::VideoEncodeCapabilityFlagBitsKHR::ePrecedingExternallyEncodedBytes);
    e_vk_VideoEncodeCapabilityFlagBitsKHR.value("INSUFFICIENTSTREAM_BUFFER_RANGE_DETECTION_BIT", vk::VideoEncodeCapabilityFlagBitsKHR::eInsufficientstreamBufferRangeDetectionBit);

    py::enum_<vk::VideoEncodeContentFlagBitsKHR> e_vk_VideoEncodeContentFlagBitsKHR(m_vk, "VideoEncodeContentFlagBitsKHR");
    e_vk_VideoEncodeContentFlagBitsKHR.value("DEFAULT", vk::VideoEncodeContentFlagBitsKHR::eDefault);
    e_vk_VideoEncodeContentFlagBitsKHR.value("CAMERA", vk::VideoEncodeContentFlagBitsKHR::eCamera);
    e_vk_VideoEncodeContentFlagBitsKHR.value("DESKTOP", vk::VideoEncodeContentFlagBitsKHR::eDesktop);
    e_vk_VideoEncodeContentFlagBitsKHR.value("RENDERED", vk::VideoEncodeContentFlagBitsKHR::eRendered);

    py::enum_<vk::VideoEncodeFeedbackFlagBitsKHR> e_vk_VideoEncodeFeedbackFlagBitsKHR(m_vk, "VideoEncodeFeedbackFlagBitsKHR");
    e_vk_VideoEncodeFeedbackFlagBitsKHR.value("stream_BUFFER_OFFSET_BIT", vk::VideoEncodeFeedbackFlagBitsKHR::estreamBufferOffsetBit);
    e_vk_VideoEncodeFeedbackFlagBitsKHR.value("stream_BYTES_WRITTEN_BIT", vk::VideoEncodeFeedbackFlagBitsKHR::estreamBytesWrittenBit);
    e_vk_VideoEncodeFeedbackFlagBitsKHR.value("stream_HAS_OVERRIDES_BIT", vk::VideoEncodeFeedbackFlagBitsKHR::estreamHasOverridesBit);

    py::enum_<vk::VideoEncodeFlagBitsKHR> e_vk_VideoEncodeFlagBitsKHR(m_vk, "VideoEncodeFlagBitsKHR");

    py::enum_<vk::VideoEncodeRateControlFlagBitsKHR> e_vk_VideoEncodeRateControlFlagBitsKHR(m_vk, "VideoEncodeRateControlFlagBitsKHR");

    py::enum_<vk::VideoEncodeRateControlModeFlagBitsKHR> e_vk_VideoEncodeRateControlModeFlagBitsKHR(m_vk, "VideoEncodeRateControlModeFlagBitsKHR");
    e_vk_VideoEncodeRateControlModeFlagBitsKHR.value("DEFAULT", vk::VideoEncodeRateControlModeFlagBitsKHR::eDefault);
    e_vk_VideoEncodeRateControlModeFlagBitsKHR.value("DISABLED", vk::VideoEncodeRateControlModeFlagBitsKHR::eDisabled);
    e_vk_VideoEncodeRateControlModeFlagBitsKHR.value("CBR", vk::VideoEncodeRateControlModeFlagBitsKHR::eCbr);
    e_vk_VideoEncodeRateControlModeFlagBitsKHR.value("VBR", vk::VideoEncodeRateControlModeFlagBitsKHR::eVbr);

    py::enum_<vk::VideoEncodeTuningModeKHR> e_vk_VideoEncodeTuningModeKHR(m_vk, "VideoEncodeTuningModeKHR");
    e_vk_VideoEncodeTuningModeKHR.value("DEFAULT", vk::VideoEncodeTuningModeKHR::eDefault);
    e_vk_VideoEncodeTuningModeKHR.value("HIGH_QUALITY", vk::VideoEncodeTuningModeKHR::eHighQuality);
    e_vk_VideoEncodeTuningModeKHR.value("LOW_LATENCY", vk::VideoEncodeTuningModeKHR::eLowLatency);
    e_vk_VideoEncodeTuningModeKHR.value("ULTRA_LOW_LATENCY", vk::VideoEncodeTuningModeKHR::eUltraLowLatency);
    e_vk_VideoEncodeTuningModeKHR.value("LOSSLESS", vk::VideoEncodeTuningModeKHR::eLossless);

    py::enum_<vk::VideoEncodeUsageFlagBitsKHR> e_vk_VideoEncodeUsageFlagBitsKHR(m_vk, "VideoEncodeUsageFlagBitsKHR");
    e_vk_VideoEncodeUsageFlagBitsKHR.value("DEFAULT", vk::VideoEncodeUsageFlagBitsKHR::eDefault);
    e_vk_VideoEncodeUsageFlagBitsKHR.value("TRANSCODING", vk::VideoEncodeUsageFlagBitsKHR::eTranscoding);
    e_vk_VideoEncodeUsageFlagBitsKHR.value("STREAMING", vk::VideoEncodeUsageFlagBitsKHR::eStreaming);
    e_vk_VideoEncodeUsageFlagBitsKHR.value("RECORDING", vk::VideoEncodeUsageFlagBitsKHR::eRecording);
    e_vk_VideoEncodeUsageFlagBitsKHR.value("CONFERENCING", vk::VideoEncodeUsageFlagBitsKHR::eConferencing);

    py::enum_<vk::DeviceDiagnosticsConfigFlagBitsNV> e_vk_DeviceDiagnosticsConfigFlagBitsNV(m_vk, "DeviceDiagnosticsConfigFlagBitsNV");
    e_vk_DeviceDiagnosticsConfigFlagBitsNV.value("ENABLE_SHADER_DEBUG_INFO", vk::DeviceDiagnosticsConfigFlagBitsNV::eEnableShaderDebugInfo);
    e_vk_DeviceDiagnosticsConfigFlagBitsNV.value("ENABLE_RESOURCE_TRACKING", vk::DeviceDiagnosticsConfigFlagBitsNV::eEnableResourceTracking);
    e_vk_DeviceDiagnosticsConfigFlagBitsNV.value("ENABLE_AUTOMATIC_CHECKPOINTS", vk::DeviceDiagnosticsConfigFlagBitsNV::eEnableAutomaticCheckpoints);
    e_vk_DeviceDiagnosticsConfigFlagBitsNV.value("ENABLE_SHADER_ERROR_REPORTING", vk::DeviceDiagnosticsConfigFlagBitsNV::eEnableShaderErrorReporting);

    py::enum_<vk::GraphicsPipelineLibraryFlagBitsEXT> e_vk_GraphicsPipelineLibraryFlagBitsEXT(m_vk, "GraphicsPipelineLibraryFlagBitsEXT");
    e_vk_GraphicsPipelineLibraryFlagBitsEXT.value("VERTEX_INPUT_INTERFACE", vk::GraphicsPipelineLibraryFlagBitsEXT::eVertexInputInterface);
    e_vk_GraphicsPipelineLibraryFlagBitsEXT.value("PRE_RASTERIZATION_SHADERS", vk::GraphicsPipelineLibraryFlagBitsEXT::ePreRasterizationShaders);
    e_vk_GraphicsPipelineLibraryFlagBitsEXT.value("FRAGMENT_SHADER", vk::GraphicsPipelineLibraryFlagBitsEXT::eFragmentShader);
    e_vk_GraphicsPipelineLibraryFlagBitsEXT.value("FRAGMENT_OUTPUT_INTERFACE", vk::GraphicsPipelineLibraryFlagBitsEXT::eFragmentOutputInterface);

    py::enum_<vk::FragmentShadingRateNV> e_vk_FragmentShadingRateNV(m_vk, "FragmentShadingRateNV");
    e_vk_FragmentShadingRateNV.value("_1_INVOCATION_PER_PIXEL", vk::FragmentShadingRateNV::e1InvocationPerPixel);
    e_vk_FragmentShadingRateNV.value("_1_INVOCATION_PER_1X2_PIXELS", vk::FragmentShadingRateNV::e1InvocationPer1X2Pixels);
    e_vk_FragmentShadingRateNV.value("_1_INVOCATION_PER_2X1_PIXELS", vk::FragmentShadingRateNV::e1InvocationPer2X1Pixels);
    e_vk_FragmentShadingRateNV.value("_1_INVOCATION_PER_2X2_PIXELS", vk::FragmentShadingRateNV::e1InvocationPer2X2Pixels);
    e_vk_FragmentShadingRateNV.value("_1_INVOCATION_PER_2X4_PIXELS", vk::FragmentShadingRateNV::e1InvocationPer2X4Pixels);
    e_vk_FragmentShadingRateNV.value("_1_INVOCATION_PER_4X2_PIXELS", vk::FragmentShadingRateNV::e1InvocationPer4X2Pixels);
    e_vk_FragmentShadingRateNV.value("_1_INVOCATION_PER_4X4_PIXELS", vk::FragmentShadingRateNV::e1InvocationPer4X4Pixels);
    e_vk_FragmentShadingRateNV.value("_2_INVOCATIONS_PER_PIXEL", vk::FragmentShadingRateNV::e2InvocationsPerPixel);
    e_vk_FragmentShadingRateNV.value("_4_INVOCATIONS_PER_PIXEL", vk::FragmentShadingRateNV::e4InvocationsPerPixel);
    e_vk_FragmentShadingRateNV.value("_8_INVOCATIONS_PER_PIXEL", vk::FragmentShadingRateNV::e8InvocationsPerPixel);
    e_vk_FragmentShadingRateNV.value("_16_INVOCATIONS_PER_PIXEL", vk::FragmentShadingRateNV::e16InvocationsPerPixel);
    e_vk_FragmentShadingRateNV.value("NO_INVOCATIONS", vk::FragmentShadingRateNV::eNoInvocations);

    py::enum_<vk::FragmentShadingRateTypeNV> e_vk_FragmentShadingRateTypeNV(m_vk, "FragmentShadingRateTypeNV");
    e_vk_FragmentShadingRateTypeNV.value("FRAGMENT_SIZE", vk::FragmentShadingRateTypeNV::eFragmentSize);
    e_vk_FragmentShadingRateTypeNV.value("ENUMS", vk::FragmentShadingRateTypeNV::eEnums);

    py::enum_<vk::AccelerationStructureMotionInfoFlagBitsNV> e_vk_AccelerationStructureMotionInfoFlagBitsNV(m_vk, "AccelerationStructureMotionInfoFlagBitsNV");

    py::enum_<vk::AccelerationStructureMotionInstanceFlagBitsNV> e_vk_AccelerationStructureMotionInstanceFlagBitsNV(m_vk, "AccelerationStructureMotionInstanceFlagBitsNV");

    py::enum_<vk::AccelerationStructureMotionInstanceTypeNV> e_vk_AccelerationStructureMotionInstanceTypeNV(m_vk, "AccelerationStructureMotionInstanceTypeNV");
    e_vk_AccelerationStructureMotionInstanceTypeNV.value("STATIC", vk::AccelerationStructureMotionInstanceTypeNV::eStatic);
    e_vk_AccelerationStructureMotionInstanceTypeNV.value("MATRIX_MOTION", vk::AccelerationStructureMotionInstanceTypeNV::eMatrixMotion);
    e_vk_AccelerationStructureMotionInstanceTypeNV.value("SRT_MOTION", vk::AccelerationStructureMotionInstanceTypeNV::eSrtMotion);

    py::enum_<vk::ImageCompressionFixedRateFlagBitsEXT> e_vk_ImageCompressionFixedRateFlagBitsEXT(m_vk, "ImageCompressionFixedRateFlagBitsEXT");
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("NONE", vk::ImageCompressionFixedRateFlagBitsEXT::eNone);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_1_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e1Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_2_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e2Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_3_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e3Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_4_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e4Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_5_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e5Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_6_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e6Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_7_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e7Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_8_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e8Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_9_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e9Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_10_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e10Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_11_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e11Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_12_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e12Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_13_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e13Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_14_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e14Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_15_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e15Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_16_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e16Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_17_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e17Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_18_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e18Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_19_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e19Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_20_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e20Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_21_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e21Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_22_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e22Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_23_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e23Bpc);
    e_vk_ImageCompressionFixedRateFlagBitsEXT.value("_24_BPC", vk::ImageCompressionFixedRateFlagBitsEXT::e24Bpc);

    py::enum_<vk::ImageCompressionFlagBitsEXT> e_vk_ImageCompressionFlagBitsEXT(m_vk, "ImageCompressionFlagBitsEXT");
    e_vk_ImageCompressionFlagBitsEXT.value("DEFAULT", vk::ImageCompressionFlagBitsEXT::eDefault);
    e_vk_ImageCompressionFlagBitsEXT.value("FIXED_RATE_DEFAULT", vk::ImageCompressionFlagBitsEXT::eFixedRateDefault);
    e_vk_ImageCompressionFlagBitsEXT.value("FIXED_RATE_EXPLICIT", vk::ImageCompressionFlagBitsEXT::eFixedRateExplicit);
    e_vk_ImageCompressionFlagBitsEXT.value("DISABLED", vk::ImageCompressionFlagBitsEXT::eDisabled);

    py::enum_<vk::DeviceFaultAddressTypeEXT> e_vk_DeviceFaultAddressTypeEXT(m_vk, "DeviceFaultAddressTypeEXT");
    e_vk_DeviceFaultAddressTypeEXT.value("NONE", vk::DeviceFaultAddressTypeEXT::eNone);
    e_vk_DeviceFaultAddressTypeEXT.value("READ_INVALID", vk::DeviceFaultAddressTypeEXT::eReadInvalid);
    e_vk_DeviceFaultAddressTypeEXT.value("WRITE_INVALID", vk::DeviceFaultAddressTypeEXT::eWriteInvalid);
    e_vk_DeviceFaultAddressTypeEXT.value("EXECUTE_INVALID", vk::DeviceFaultAddressTypeEXT::eExecuteInvalid);
    e_vk_DeviceFaultAddressTypeEXT.value("INSTRUCTION_POINTER_UNKNOWN", vk::DeviceFaultAddressTypeEXT::eInstructionPointerUnknown);
    e_vk_DeviceFaultAddressTypeEXT.value("INSTRUCTION_POINTER_INVALID", vk::DeviceFaultAddressTypeEXT::eInstructionPointerInvalid);
    e_vk_DeviceFaultAddressTypeEXT.value("INSTRUCTION_POINTER_FAULT", vk::DeviceFaultAddressTypeEXT::eInstructionPointerFault);

    py::enum_<vk::DeviceFaultVendorBinaryHeaderVersionEXT> e_vk_DeviceFaultVendorBinaryHeaderVersionEXT(m_vk, "DeviceFaultVendorBinaryHeaderVersionEXT");
    e_vk_DeviceFaultVendorBinaryHeaderVersionEXT.value("ONE", vk::DeviceFaultVendorBinaryHeaderVersionEXT::eOne);

    py::enum_<vk::DeviceAddressBindingFlagBitsEXT> e_vk_DeviceAddressBindingFlagBitsEXT(m_vk, "DeviceAddressBindingFlagBitsEXT");
    e_vk_DeviceAddressBindingFlagBitsEXT.value("INTERNAL_OBJECT", vk::DeviceAddressBindingFlagBitsEXT::eInternalObject);

    py::enum_<vk::DeviceAddressBindingTypeEXT> e_vk_DeviceAddressBindingTypeEXT(m_vk, "DeviceAddressBindingTypeEXT");
    e_vk_DeviceAddressBindingTypeEXT.value("BIND", vk::DeviceAddressBindingTypeEXT::eBind);
    e_vk_DeviceAddressBindingTypeEXT.value("UNBIND", vk::DeviceAddressBindingTypeEXT::eUnbind);

    py::enum_<vk::FrameBoundaryFlagBitsEXT> e_vk_FrameBoundaryFlagBitsEXT(m_vk, "FrameBoundaryFlagBitsEXT");
    e_vk_FrameBoundaryFlagBitsEXT.value("FRAME_END", vk::FrameBoundaryFlagBitsEXT::eFrameEnd);

    py::enum_<vk::BuildMicromapFlagBitsEXT> e_vk_BuildMicromapFlagBitsEXT(m_vk, "BuildMicromapFlagBitsEXT");
    e_vk_BuildMicromapFlagBitsEXT.value("PREFER_FAST_TRACE", vk::BuildMicromapFlagBitsEXT::ePreferFastTrace);
    e_vk_BuildMicromapFlagBitsEXT.value("PREFER_FAST_BUILD", vk::BuildMicromapFlagBitsEXT::ePreferFastBuild);
    e_vk_BuildMicromapFlagBitsEXT.value("ALLOW_COMPACTION", vk::BuildMicromapFlagBitsEXT::eAllowCompaction);

    py::enum_<vk::BuildMicromapModeEXT> e_vk_BuildMicromapModeEXT(m_vk, "BuildMicromapModeEXT");
    e_vk_BuildMicromapModeEXT.value("BUILD", vk::BuildMicromapModeEXT::eBuild);

    py::enum_<vk::CopyMicromapModeEXT> e_vk_CopyMicromapModeEXT(m_vk, "CopyMicromapModeEXT");
    e_vk_CopyMicromapModeEXT.value("CLONE", vk::CopyMicromapModeEXT::eClone);
    e_vk_CopyMicromapModeEXT.value("SERIALIZE", vk::CopyMicromapModeEXT::eSerialize);
    e_vk_CopyMicromapModeEXT.value("DESERIALIZE", vk::CopyMicromapModeEXT::eDeserialize);
    e_vk_CopyMicromapModeEXT.value("COMPACT", vk::CopyMicromapModeEXT::eCompact);

    py::enum_<vk::MicromapCreateFlagBitsEXT> e_vk_MicromapCreateFlagBitsEXT(m_vk, "MicromapCreateFlagBitsEXT");
    e_vk_MicromapCreateFlagBitsEXT.value("DEVICE_ADDRESS_CAPTURE_REPLAY", vk::MicromapCreateFlagBitsEXT::eDeviceAddressCaptureReplay);

    py::enum_<vk::MicromapTypeEXT> e_vk_MicromapTypeEXT(m_vk, "MicromapTypeEXT");
    e_vk_MicromapTypeEXT.value("OPACITY_MICROMAP", vk::MicromapTypeEXT::eOpacityMicromap);

    py::enum_<vk::OpacityMicromapFormatEXT> e_vk_OpacityMicromapFormatEXT(m_vk, "OpacityMicromapFormatEXT");
    e_vk_OpacityMicromapFormatEXT.value("_2_STATE", vk::OpacityMicromapFormatEXT::e2State);
    e_vk_OpacityMicromapFormatEXT.value("_4_STATE", vk::OpacityMicromapFormatEXT::e4State);

    py::enum_<vk::OpacityMicromapSpecialIndexEXT> e_vk_OpacityMicromapSpecialIndexEXT(m_vk, "OpacityMicromapSpecialIndexEXT");
    e_vk_OpacityMicromapSpecialIndexEXT.value("FULLY_TRANSPARENT", vk::OpacityMicromapSpecialIndexEXT::eFullyTransparent);
    e_vk_OpacityMicromapSpecialIndexEXT.value("FULLY_OPAQUE", vk::OpacityMicromapSpecialIndexEXT::eFullyOpaque);
    e_vk_OpacityMicromapSpecialIndexEXT.value("FULLY_UNKNOWN_TRANSPARENT", vk::OpacityMicromapSpecialIndexEXT::eFullyUnknownTransparent);
    e_vk_OpacityMicromapSpecialIndexEXT.value("FULLY_UNKNOWN_OPAQUE", vk::OpacityMicromapSpecialIndexEXT::eFullyUnknownOpaque);

    py::enum_<vk::PhysicalDeviceSchedulingControlsFlagBitsARM> e_vk_PhysicalDeviceSchedulingControlsFlagBitsARM(m_vk, "PhysicalDeviceSchedulingControlsFlagBitsARM");
    e_vk_PhysicalDeviceSchedulingControlsFlagBitsARM.value("SHADER_CORE_COUNT", vk::PhysicalDeviceSchedulingControlsFlagBitsARM::eShaderCoreCount);

    py::enum_<vk::MemoryDecompressionMethodFlagBitsNV> e_vk_MemoryDecompressionMethodFlagBitsNV(m_vk, "MemoryDecompressionMethodFlagBitsNV");
    e_vk_MemoryDecompressionMethodFlagBitsNV.value("GDEFLATE_10", vk::MemoryDecompressionMethodFlagBitsNV::eGdeflate10);

    py::enum_<vk::SubpassMergeStatusEXT> e_vk_SubpassMergeStatusEXT(m_vk, "SubpassMergeStatusEXT");
    e_vk_SubpassMergeStatusEXT.value("MERGED", vk::SubpassMergeStatusEXT::eMerged);
    e_vk_SubpassMergeStatusEXT.value("DISALLOWED", vk::SubpassMergeStatusEXT::eDisallowed);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_SIDE_EFFECTS", vk::SubpassMergeStatusEXT::eNotMergedSideEffects);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_SAMPLES_MISMATCH", vk::SubpassMergeStatusEXT::eNotMergedSamplesMismatch);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_VIEWS_MISMATCH", vk::SubpassMergeStatusEXT::eNotMergedViewsMismatch);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_ALIASING", vk::SubpassMergeStatusEXT::eNotMergedAliasing);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_DEPENDENCIES", vk::SubpassMergeStatusEXT::eNotMergedDependencies);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT", vk::SubpassMergeStatusEXT::eNotMergedIncompatibleInputAttachment);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_TOO_MANY_ATTACHMENTS", vk::SubpassMergeStatusEXT::eNotMergedTooManyAttachments);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_INSUFFICIENT_STORAGE", vk::SubpassMergeStatusEXT::eNotMergedInsufficientStorage);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_DEPTH_STENCIL_COUNT", vk::SubpassMergeStatusEXT::eNotMergedDepthStencilCount);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_RESOLVE_ATTACHMENT_REUSE", vk::SubpassMergeStatusEXT::eNotMergedResolveAttachmentReuse);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_SINGLE_SUBPASS", vk::SubpassMergeStatusEXT::eNotMergedSingleSubpass);
    e_vk_SubpassMergeStatusEXT.value("NOT_MERGED_UNSPECIFIED", vk::SubpassMergeStatusEXT::eNotMergedUnspecified);

    py::enum_<vk::DirectDriverLoadingFlagBitsLUNARG> e_vk_DirectDriverLoadingFlagBitsLUNARG(m_vk, "DirectDriverLoadingFlagBitsLUNARG");

    py::enum_<vk::DirectDriverLoadingModeLUNARG> e_vk_DirectDriverLoadingModeLUNARG(m_vk, "DirectDriverLoadingModeLUNARG");
    e_vk_DirectDriverLoadingModeLUNARG.value("EXCLUSIVE", vk::DirectDriverLoadingModeLUNARG::eExclusive);
    e_vk_DirectDriverLoadingModeLUNARG.value("INCLUSIVE", vk::DirectDriverLoadingModeLUNARG::eInclusive);

    py::enum_<vk::OpticalFlowExecuteFlagBitsNV> e_vk_OpticalFlowExecuteFlagBitsNV(m_vk, "OpticalFlowExecuteFlagBitsNV");
    e_vk_OpticalFlowExecuteFlagBitsNV.value("DISABLE_TEMPORAL_HINTS", vk::OpticalFlowExecuteFlagBitsNV::eDisableTemporalHints);

    py::enum_<vk::OpticalFlowGridSizeFlagBitsNV> e_vk_OpticalFlowGridSizeFlagBitsNV(m_vk, "OpticalFlowGridSizeFlagBitsNV");
    e_vk_OpticalFlowGridSizeFlagBitsNV.value("UNKNOWN", vk::OpticalFlowGridSizeFlagBitsNV::eUnknown);
    e_vk_OpticalFlowGridSizeFlagBitsNV.value("_1X1", vk::OpticalFlowGridSizeFlagBitsNV::e1X1);
    e_vk_OpticalFlowGridSizeFlagBitsNV.value("_2X2", vk::OpticalFlowGridSizeFlagBitsNV::e2X2);
    e_vk_OpticalFlowGridSizeFlagBitsNV.value("_4X4", vk::OpticalFlowGridSizeFlagBitsNV::e4X4);
    e_vk_OpticalFlowGridSizeFlagBitsNV.value("_8X8", vk::OpticalFlowGridSizeFlagBitsNV::e8X8);

    py::enum_<vk::OpticalFlowPerformanceLevelNV> e_vk_OpticalFlowPerformanceLevelNV(m_vk, "OpticalFlowPerformanceLevelNV");
    e_vk_OpticalFlowPerformanceLevelNV.value("UNKNOWN", vk::OpticalFlowPerformanceLevelNV::eUnknown);
    e_vk_OpticalFlowPerformanceLevelNV.value("SLOW", vk::OpticalFlowPerformanceLevelNV::eSlow);
    e_vk_OpticalFlowPerformanceLevelNV.value("MEDIUM", vk::OpticalFlowPerformanceLevelNV::eMedium);
    e_vk_OpticalFlowPerformanceLevelNV.value("FAST", vk::OpticalFlowPerformanceLevelNV::eFast);

    py::enum_<vk::OpticalFlowSessionBindingPointNV> e_vk_OpticalFlowSessionBindingPointNV(m_vk, "OpticalFlowSessionBindingPointNV");
    e_vk_OpticalFlowSessionBindingPointNV.value("UNKNOWN", vk::OpticalFlowSessionBindingPointNV::eUnknown);
    e_vk_OpticalFlowSessionBindingPointNV.value("INPUT", vk::OpticalFlowSessionBindingPointNV::eInput);
    e_vk_OpticalFlowSessionBindingPointNV.value("REFERENCE", vk::OpticalFlowSessionBindingPointNV::eReference);
    e_vk_OpticalFlowSessionBindingPointNV.value("HINT", vk::OpticalFlowSessionBindingPointNV::eHint);
    e_vk_OpticalFlowSessionBindingPointNV.value("FLOW_VECTOR", vk::OpticalFlowSessionBindingPointNV::eFlowVector);
    e_vk_OpticalFlowSessionBindingPointNV.value("BACKWARD_FLOW_VECTOR", vk::OpticalFlowSessionBindingPointNV::eBackwardFlowVector);
    e_vk_OpticalFlowSessionBindingPointNV.value("COST", vk::OpticalFlowSessionBindingPointNV::eCost);
    e_vk_OpticalFlowSessionBindingPointNV.value("BACKWARD_COST", vk::OpticalFlowSessionBindingPointNV::eBackwardCost);
    e_vk_OpticalFlowSessionBindingPointNV.value("GLOBAL_FLOW", vk::OpticalFlowSessionBindingPointNV::eGlobalFlow);

    py::enum_<vk::OpticalFlowSessionCreateFlagBitsNV> e_vk_OpticalFlowSessionCreateFlagBitsNV(m_vk, "OpticalFlowSessionCreateFlagBitsNV");
    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("ENABLE_HINT", vk::OpticalFlowSessionCreateFlagBitsNV::eEnableHint);
    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("ENABLE_COST", vk::OpticalFlowSessionCreateFlagBitsNV::eEnableCost);
    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("ENABLE_GLOBAL_FLOW", vk::OpticalFlowSessionCreateFlagBitsNV::eEnableGlobalFlow);
    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("ALLOW_REGIONS", vk::OpticalFlowSessionCreateFlagBitsNV::eAllowRegions);
    e_vk_OpticalFlowSessionCreateFlagBitsNV.value("BOTH_DIRECTIONS", vk::OpticalFlowSessionCreateFlagBitsNV::eBothDirections);

    py::enum_<vk::OpticalFlowUsageFlagBitsNV> e_vk_OpticalFlowUsageFlagBitsNV(m_vk, "OpticalFlowUsageFlagBitsNV");
    e_vk_OpticalFlowUsageFlagBitsNV.value("UNKNOWN", vk::OpticalFlowUsageFlagBitsNV::eUnknown);
    e_vk_OpticalFlowUsageFlagBitsNV.value("INPUT", vk::OpticalFlowUsageFlagBitsNV::eInput);
    e_vk_OpticalFlowUsageFlagBitsNV.value("OUTPUT", vk::OpticalFlowUsageFlagBitsNV::eOutput);
    e_vk_OpticalFlowUsageFlagBitsNV.value("HINT", vk::OpticalFlowUsageFlagBitsNV::eHint);
    e_vk_OpticalFlowUsageFlagBitsNV.value("COST", vk::OpticalFlowUsageFlagBitsNV::eCost);
    e_vk_OpticalFlowUsageFlagBitsNV.value("GLOBAL_FLOW", vk::OpticalFlowUsageFlagBitsNV::eGlobalFlow);

    py::enum_<vk::BufferUsageFlagBits2KHR> e_vk_BufferUsageFlagBits2KHR(m_vk, "BufferUsageFlagBits2KHR");
    e_vk_BufferUsageFlagBits2KHR.value("TRANSFER_SRC", vk::BufferUsageFlagBits2KHR::eTransferSrc);
    e_vk_BufferUsageFlagBits2KHR.value("TRANSFER_DST", vk::BufferUsageFlagBits2KHR::eTransferDst);
    e_vk_BufferUsageFlagBits2KHR.value("UNIFORM_TEXEL_BUFFER", vk::BufferUsageFlagBits2KHR::eUniformTexelBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("STORAGE_TEXEL_BUFFER", vk::BufferUsageFlagBits2KHR::eStorageTexelBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("UNIFORM_BUFFER", vk::BufferUsageFlagBits2KHR::eUniformBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("STORAGE_BUFFER", vk::BufferUsageFlagBits2KHR::eStorageBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("INDEX_BUFFER", vk::BufferUsageFlagBits2KHR::eIndexBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("VERTEX_BUFFER", vk::BufferUsageFlagBits2KHR::eVertexBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("INDIRECT_BUFFER", vk::BufferUsageFlagBits2KHR::eIndirectBuffer);
    e_vk_BufferUsageFlagBits2KHR.value("CONDITIONAL_RENDERING_EXT", vk::BufferUsageFlagBits2KHR::eConditionalRenderingEXT);
    e_vk_BufferUsageFlagBits2KHR.value("SHADER_BINDING_TABLE", vk::BufferUsageFlagBits2KHR::eShaderBindingTable);
    e_vk_BufferUsageFlagBits2KHR.value("RAY_TRACING_NV", vk::BufferUsageFlagBits2KHR::eRayTracingNV);
    e_vk_BufferUsageFlagBits2KHR.value("TRANSFORM_FEEDBACK_BUFFER_EXT", vk::BufferUsageFlagBits2KHR::eTransformFeedbackBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("TRANSFORM_FEEDBACK_COUNTER_BUFFER_EXT", vk::BufferUsageFlagBits2KHR::eTransformFeedbackCounterBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("VIDEO_DECODE_SRC", vk::BufferUsageFlagBits2KHR::eVideoDecodeSrc);
    e_vk_BufferUsageFlagBits2KHR.value("VIDEO_DECODE_DST", vk::BufferUsageFlagBits2KHR::eVideoDecodeDst);
    e_vk_BufferUsageFlagBits2KHR.value("SHADER_DEVICE_ADDRESS", vk::BufferUsageFlagBits2KHR::eShaderDeviceAddress);
    e_vk_BufferUsageFlagBits2KHR.value("ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY", vk::BufferUsageFlagBits2KHR::eAccelerationStructureBuildInputReadOnly);
    e_vk_BufferUsageFlagBits2KHR.value("ACCELERATION_STRUCTURE_STORAGE", vk::BufferUsageFlagBits2KHR::eAccelerationStructureStorage);
    e_vk_BufferUsageFlagBits2KHR.value("SAMPLER_DESCRIPTOR_BUFFER_EXT", vk::BufferUsageFlagBits2KHR::eSamplerDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("RESOURCE_DESCRIPTOR_BUFFER_EXT", vk::BufferUsageFlagBits2KHR::eResourceDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_EXT", vk::BufferUsageFlagBits2KHR::ePushDescriptorsDescriptorBufferEXT);
    e_vk_BufferUsageFlagBits2KHR.value("MICROMAP_BUILD_INPUT_READ_ONLY_EXT", vk::BufferUsageFlagBits2KHR::eMicromapBuildInputReadOnlyEXT);
    e_vk_BufferUsageFlagBits2KHR.value("MICROMAP_STORAGE_EXT", vk::BufferUsageFlagBits2KHR::eMicromapStorageEXT);

    py::enum_<vk::PipelineCreateFlagBits2KHR> e_vk_PipelineCreateFlagBits2KHR(m_vk, "PipelineCreateFlagBits2KHR");
    e_vk_PipelineCreateFlagBits2KHR.value("DISABLE_OPTIMIZATION", vk::PipelineCreateFlagBits2KHR::eDisableOptimization);
    e_vk_PipelineCreateFlagBits2KHR.value("ALLOW_DERIVATIVES", vk::PipelineCreateFlagBits2KHR::eAllowDerivatives);
    e_vk_PipelineCreateFlagBits2KHR.value("DERIVATIVE", vk::PipelineCreateFlagBits2KHR::eDerivative);
    e_vk_PipelineCreateFlagBits2KHR.value("VIEW_INDEX_FROM_DEVICE_INDEX", vk::PipelineCreateFlagBits2KHR::eViewIndexFromDeviceIndex);
    e_vk_PipelineCreateFlagBits2KHR.value("DISPATCH_BASE", vk::PipelineCreateFlagBits2KHR::eDispatchBase);
    e_vk_PipelineCreateFlagBits2KHR.value("DEFER_COMPILE_NV", vk::PipelineCreateFlagBits2KHR::eDeferCompileNV);
    e_vk_PipelineCreateFlagBits2KHR.value("CAPTURE_STATISTICS", vk::PipelineCreateFlagBits2KHR::eCaptureStatistics);
    e_vk_PipelineCreateFlagBits2KHR.value("CAPTURE_INTERNAL_REPRESENTATIONS", vk::PipelineCreateFlagBits2KHR::eCaptureInternalRepresentations);
    e_vk_PipelineCreateFlagBits2KHR.value("FAIL_ON_PIPELINE_COMPILE_REQUIRED", vk::PipelineCreateFlagBits2KHR::eFailOnPipelineCompileRequired);
    e_vk_PipelineCreateFlagBits2KHR.value("EARLY_RETURN_ON_FAILURE", vk::PipelineCreateFlagBits2KHR::eEarlyReturnOnFailure);
    e_vk_PipelineCreateFlagBits2KHR.value("LINK_TIME_OPTIMIZATION_EXT", vk::PipelineCreateFlagBits2KHR::eLinkTimeOptimizationEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("RETAIN_LINK_TIME_OPTIMIZATION_INFO_EXT", vk::PipelineCreateFlagBits2KHR::eRetainLinkTimeOptimizationInfoEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("LIBRARY", vk::PipelineCreateFlagBits2KHR::eLibrary);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_SKIP_TRIANGLES", vk::PipelineCreateFlagBits2KHR::eRayTracingSkipTriangles);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_SKIP_AABBS", vk::PipelineCreateFlagBits2KHR::eRayTracingSkipAabbs);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_NO_NULL_ANY_HIT_SHADERS", vk::PipelineCreateFlagBits2KHR::eRayTracingNoNullAnyHitShaders);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS", vk::PipelineCreateFlagBits2KHR::eRayTracingNoNullClosestHitShaders);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_NO_NULL_MISS_SHADERS", vk::PipelineCreateFlagBits2KHR::eRayTracingNoNullMissShaders);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_NO_NULL_INTERSECTION_SHADERS", vk::PipelineCreateFlagBits2KHR::eRayTracingNoNullIntersectionShaders);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY", vk::PipelineCreateFlagBits2KHR::eRayTracingShaderGroupHandleCaptureReplay);
    e_vk_PipelineCreateFlagBits2KHR.value("INDIRECT_BINDABLE_NV", vk::PipelineCreateFlagBits2KHR::eIndirectBindableNV);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_ALLOW_MOTION_NV", vk::PipelineCreateFlagBits2KHR::eRayTracingAllowMotionNV);
    e_vk_PipelineCreateFlagBits2KHR.value("RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT", vk::PipelineCreateFlagBits2KHR::eRenderingFragmentShadingRateAttachment);
    e_vk_PipelineCreateFlagBits2KHR.value("RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_EXT", vk::PipelineCreateFlagBits2KHR::eRenderingFragmentDensityMapAttachmentEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_OPACITY_MICROMAP_EXT", vk::PipelineCreateFlagBits2KHR::eRayTracingOpacityMicromapEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("COLOR_ATTACHMENT_FEEDBACK_LOOP_EXT", vk::PipelineCreateFlagBits2KHR::eColorAttachmentFeedbackLoopEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_EXT", vk::PipelineCreateFlagBits2KHR::eDepthStencilAttachmentFeedbackLoopEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("NO_PROTECTED_ACCESS_EXT", vk::PipelineCreateFlagBits2KHR::eNoProtectedAccessEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("PROTECTED_ACCESS_ONLY_EXT", vk::PipelineCreateFlagBits2KHR::eProtectedAccessOnlyEXT);
    e_vk_PipelineCreateFlagBits2KHR.value("RAY_TRACING_DISPLACEMENT_MICROMAP_NV", vk::PipelineCreateFlagBits2KHR::eRayTracingDisplacementMicromapNV);
    e_vk_PipelineCreateFlagBits2KHR.value("DESCRIPTOR_BUFFER_EXT", vk::PipelineCreateFlagBits2KHR::eDescriptorBufferEXT);

    py::enum_<vk::ShaderCodeTypeEXT> e_vk_ShaderCodeTypeEXT(m_vk, "ShaderCodeTypeEXT");
    e_vk_ShaderCodeTypeEXT.value("BINARY", vk::ShaderCodeTypeEXT::eBinary);
    e_vk_ShaderCodeTypeEXT.value("SPIRV", vk::ShaderCodeTypeEXT::eSpirv);

    py::enum_<vk::ShaderCreateFlagBitsEXT> e_vk_ShaderCreateFlagBitsEXT(m_vk, "ShaderCreateFlagBitsEXT");
    e_vk_ShaderCreateFlagBitsEXT.value("LINK_STAGE", vk::ShaderCreateFlagBitsEXT::eLinkStage);
    e_vk_ShaderCreateFlagBitsEXT.value("ALLOW_VARYING_SUBGROUP_SIZE", vk::ShaderCreateFlagBitsEXT::eAllowVaryingSubgroupSize);
    e_vk_ShaderCreateFlagBitsEXT.value("REQUIRE_FULL_SUBGROUPS", vk::ShaderCreateFlagBitsEXT::eRequireFullSubgroups);
    e_vk_ShaderCreateFlagBitsEXT.value("NO_TASK_SHADER", vk::ShaderCreateFlagBitsEXT::eNoTaskShader);
    e_vk_ShaderCreateFlagBitsEXT.value("DISPATCH_BASE", vk::ShaderCreateFlagBitsEXT::eDispatchBase);
    e_vk_ShaderCreateFlagBitsEXT.value("FRAGMENT_SHADING_RATE_ATTACHMENT", vk::ShaderCreateFlagBitsEXT::eFragmentShadingRateAttachment);
    e_vk_ShaderCreateFlagBitsEXT.value("FRAGMENT_DENSITY_MAP_ATTACHMENT", vk::ShaderCreateFlagBitsEXT::eFragmentDensityMapAttachment);

    py::enum_<vk::RayTracingInvocationReorderModeNV> e_vk_RayTracingInvocationReorderModeNV(m_vk, "RayTracingInvocationReorderModeNV");
    e_vk_RayTracingInvocationReorderModeNV.value("NONE", vk::RayTracingInvocationReorderModeNV::eNone);
    e_vk_RayTracingInvocationReorderModeNV.value("REORDER", vk::RayTracingInvocationReorderModeNV::eReorder);

    py::enum_<vk::LayerSettingTypeEXT> e_vk_LayerSettingTypeEXT(m_vk, "LayerSettingTypeEXT");
    e_vk_LayerSettingTypeEXT.value("BOOL_32", vk::LayerSettingTypeEXT::eBool32);
    e_vk_LayerSettingTypeEXT.value("INT_32", vk::LayerSettingTypeEXT::eInt32);
    e_vk_LayerSettingTypeEXT.value("INT_64", vk::LayerSettingTypeEXT::eInt64);
    e_vk_LayerSettingTypeEXT.value("UINT_32", vk::LayerSettingTypeEXT::eUint32);
    e_vk_LayerSettingTypeEXT.value("UINT_64", vk::LayerSettingTypeEXT::eUint64);
    e_vk_LayerSettingTypeEXT.value("FLOAT_32", vk::LayerSettingTypeEXT::eFloat32);
    e_vk_LayerSettingTypeEXT.value("FLOAT_64", vk::LayerSettingTypeEXT::eFloat64);
    e_vk_LayerSettingTypeEXT.value("STRING", vk::LayerSettingTypeEXT::eString);

    py::enum_<vk::LatencyMarkerNV> e_vk_LatencyMarkerNV(m_vk, "LatencyMarkerNV");
    e_vk_LatencyMarkerNV.value("SIMULATION_START", vk::LatencyMarkerNV::eSimulationStart);
    e_vk_LatencyMarkerNV.value("SIMULATION_END", vk::LatencyMarkerNV::eSimulationEnd);
    e_vk_LatencyMarkerNV.value("RENDERSUBMIT_START", vk::LatencyMarkerNV::eRendersubmitStart);
    e_vk_LatencyMarkerNV.value("RENDERSUBMIT_END", vk::LatencyMarkerNV::eRendersubmitEnd);
    e_vk_LatencyMarkerNV.value("PRESENT_START", vk::LatencyMarkerNV::ePresentStart);
    e_vk_LatencyMarkerNV.value("PRESENT_END", vk::LatencyMarkerNV::ePresentEnd);
    e_vk_LatencyMarkerNV.value("INPUT_SAMPLE", vk::LatencyMarkerNV::eInputSample);
    e_vk_LatencyMarkerNV.value("TRIGGER_FLASH", vk::LatencyMarkerNV::eTriggerFlash);
    e_vk_LatencyMarkerNV.value("OUT_OF_BAND_RENDERSUBMIT_START", vk::LatencyMarkerNV::eOutOfBandRendersubmitStart);
    e_vk_LatencyMarkerNV.value("OUT_OF_BAND_RENDERSUBMIT_END", vk::LatencyMarkerNV::eOutOfBandRendersubmitEnd);
    e_vk_LatencyMarkerNV.value("OUT_OF_BAND_PRESENT_START", vk::LatencyMarkerNV::eOutOfBandPresentStart);
    e_vk_LatencyMarkerNV.value("OUT_OF_BAND_PRESENT_END", vk::LatencyMarkerNV::eOutOfBandPresentEnd);

    py::enum_<vk::OutOfBandQueueTypeNV> e_vk_OutOfBandQueueTypeNV(m_vk, "OutOfBandQueueTypeNV");
    e_vk_OutOfBandQueueTypeNV.value("RENDER", vk::OutOfBandQueueTypeNV::eRender);
    e_vk_OutOfBandQueueTypeNV.value("PRESENT", vk::OutOfBandQueueTypeNV::ePresent);

    py::enum_<vk::ComponentTypeKHR> e_vk_ComponentTypeKHR(m_vk, "ComponentTypeKHR");
    e_vk_ComponentTypeKHR.value("FLOAT_16", vk::ComponentTypeKHR::eFloat16);
    e_vk_ComponentTypeKHR.value("FLOAT_32", vk::ComponentTypeKHR::eFloat32);
    e_vk_ComponentTypeKHR.value("FLOAT_64", vk::ComponentTypeKHR::eFloat64);
    e_vk_ComponentTypeKHR.value("SINT_8", vk::ComponentTypeKHR::eSint8);
    e_vk_ComponentTypeKHR.value("SINT_16", vk::ComponentTypeKHR::eSint16);
    e_vk_ComponentTypeKHR.value("SINT_32", vk::ComponentTypeKHR::eSint32);
    e_vk_ComponentTypeKHR.value("SINT_64", vk::ComponentTypeKHR::eSint64);
    e_vk_ComponentTypeKHR.value("UINT_8", vk::ComponentTypeKHR::eUint8);
    e_vk_ComponentTypeKHR.value("UINT_16", vk::ComponentTypeKHR::eUint16);
    e_vk_ComponentTypeKHR.value("UINT_32", vk::ComponentTypeKHR::eUint32);
    e_vk_ComponentTypeKHR.value("UINT_64", vk::ComponentTypeKHR::eUint64);

    py::enum_<vk::ScopeKHR> e_vk_ScopeKHR(m_vk, "ScopeKHR");
    e_vk_ScopeKHR.value("DEVICE", vk::ScopeKHR::eDevice);
    e_vk_ScopeKHR.value("WORKGROUP", vk::ScopeKHR::eWorkgroup);
    e_vk_ScopeKHR.value("SUBGROUP", vk::ScopeKHR::eSubgroup);
    e_vk_ScopeKHR.value("QUEUE_FAMILY", vk::ScopeKHR::eQueueFamily);

    py::enum_<vk::BlockMatchWindowCompareModeQCOM> e_vk_BlockMatchWindowCompareModeQCOM(m_vk, "BlockMatchWindowCompareModeQCOM");
    e_vk_BlockMatchWindowCompareModeQCOM.value("MIN", vk::BlockMatchWindowCompareModeQCOM::eMin);
    e_vk_BlockMatchWindowCompareModeQCOM.value("MAX", vk::BlockMatchWindowCompareModeQCOM::eMax);

    py::enum_<vk::CubicFilterWeightsQCOM> e_vk_CubicFilterWeightsQCOM(m_vk, "CubicFilterWeightsQCOM");
    e_vk_CubicFilterWeightsQCOM.value("CATMULL_ROM", vk::CubicFilterWeightsQCOM::eCatmullRom);
    e_vk_CubicFilterWeightsQCOM.value("ZERO_TANGENT_CARDINAL", vk::CubicFilterWeightsQCOM::eZeroTangentCardinal);
    e_vk_CubicFilterWeightsQCOM.value("B_SPLINE", vk::CubicFilterWeightsQCOM::eBSpline);
    e_vk_CubicFilterWeightsQCOM.value("MITCHELL_NETRAVALI", vk::CubicFilterWeightsQCOM::eMitchellNetravali);

    py::enum_<vk::LayeredDriverUnderlyingApiMSFT> e_vk_LayeredDriverUnderlyingApiMSFT(m_vk, "LayeredDriverUnderlyingApiMSFT");
    e_vk_LayeredDriverUnderlyingApiMSFT.value("NONE", vk::LayeredDriverUnderlyingApiMSFT::eNone);
    e_vk_LayeredDriverUnderlyingApiMSFT.value("D3D12", vk::LayeredDriverUnderlyingApiMSFT::eD3D12);

    py::enum_<vk::TimeDomainKHR> e_vk_TimeDomainKHR(m_vk, "TimeDomainKHR");
    e_vk_TimeDomainKHR.value("DEVICE", vk::TimeDomainKHR::eDevice);
    e_vk_TimeDomainKHR.value("CLOCK_MONOTONIC", vk::TimeDomainKHR::eClockMonotonic);
    e_vk_TimeDomainKHR.value("CLOCK_MONOTONIC_RAW", vk::TimeDomainKHR::eClockMonotonicRaw);
    e_vk_TimeDomainKHR.value("QUERY_PERFORMANCE_COUNTER", vk::TimeDomainKHR::eQueryPerformanceCounter);

    m_vk.attr("ATTACHMENT_UNUSED") = py::cast(vk::AttachmentUnused);

    m_vk.attr("FALSE") = py::cast(vk::False);

    m_vk.attr("LOD_CLAMP_NONE") = py::cast(vk::LodClampNone);

    m_vk.attr("MAX_DESCRIPTION_SIZE") = py::cast(vk::MaxDescriptionSize);

    m_vk.attr("MAX_EXTENSION_NAME_SIZE") = py::cast(vk::MaxExtensionNameSize);

    m_vk.attr("MAX_MEMORY_HEAPS") = py::cast(vk::MaxMemoryHeaps);

    m_vk.attr("MAX_MEMORY_TYPES") = py::cast(vk::MaxMemoryTypes);

    m_vk.attr("MAX_PHYSICAL_DEVICE_NAME_SIZE") = py::cast(vk::MaxPhysicalDeviceNameSize);

    m_vk.attr("QUEUE_FAMILY_IGNORED") = py::cast(vk::QueueFamilyIgnored);

    m_vk.attr("REMAINING_ARRAY_LAYERS") = py::cast(vk::RemainingArrayLayers);

    m_vk.attr("REMAINING_MIP_LEVELS") = py::cast(vk::RemainingMipLevels);

    m_vk.attr("SUBPASS_EXTERNAL") = py::cast(vk::SubpassExternal);

    m_vk.attr("TRUE") = py::cast(vk::True);

    m_vk.attr("UUID_SIZE") = py::cast(vk::UuidSize);

    m_vk.attr("WHOLE_SIZE") = py::cast(vk::WholeSize);

    m_vk.attr("LUID_SIZE") = py::cast(vk::LuidSize);

    m_vk.attr("MAX_DEVICE_GROUP_SIZE") = py::cast(vk::MaxDeviceGroupSize);

    m_vk.attr("QUEUE_FAMILY_EXTERNAL") = py::cast(vk::QueueFamilyExternal);

    m_vk.attr("MAX_DRIVER_INFO_SIZE") = py::cast(vk::MaxDriverInfoSize);

    m_vk.attr("MAX_DRIVER_NAME_SIZE") = py::cast(vk::MaxDriverNameSize);

    m_vk.attr("KHR_SURFACE_EXTENSION_NAME") = py::cast(vk::KHRSurfaceExtensionName);

    m_vk.attr("KHR_SURFACE_SPEC_VERSION") = py::cast(vk::KHRSurfaceSpecVersion);

    m_vk.attr("KHR_SWAPCHAIN_EXTENSION_NAME") = py::cast(vk::KHRSwapchainExtensionName);

    m_vk.attr("KHR_SWAPCHAIN_SPEC_VERSION") = py::cast(vk::KHRSwapchainSpecVersion);

    m_vk.attr("KHR_DISPLAY_EXTENSION_NAME") = py::cast(vk::KHRDisplayExtensionName);

    m_vk.attr("KHR_DISPLAY_SPEC_VERSION") = py::cast(vk::KHRDisplaySpecVersion);

    m_vk.attr("KHR_DISPLAY_SWAPCHAIN_EXTENSION_NAME") = py::cast(vk::KHRDisplaySwapchainExtensionName);

    m_vk.attr("KHR_DISPLAY_SWAPCHAIN_SPEC_VERSION") = py::cast(vk::KHRDisplaySwapchainSpecVersion);

    m_vk.attr("EXT_DEBUG_REPORT_EXTENSION_NAME") = py::cast(vk::EXTDebugReportExtensionName);

    m_vk.attr("EXT_DEBUG_REPORT_SPEC_VERSION") = py::cast(vk::EXTDebugReportSpecVersion);

    m_vk.attr("NV_GLSL_SHADER_EXTENSION_NAME") = py::cast(vk::NVGlslShaderExtensionName);

    m_vk.attr("NV_GLSL_SHADER_SPEC_VERSION") = py::cast(vk::NVGlslShaderSpecVersion);

    m_vk.attr("EXT_DEPTH_RANGE_UNRESTRICTED_EXTENSION_NAME") = py::cast(vk::EXTDepthRangeUnrestrictedExtensionName);

    m_vk.attr("EXT_DEPTH_RANGE_UNRESTRICTED_SPEC_VERSION") = py::cast(vk::EXTDepthRangeUnrestrictedSpecVersion);

    m_vk.attr("KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_EXTENSION_NAME") = py::cast(vk::KHRSamplerMirrorClampToEdgeExtensionName);

    m_vk.attr("KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE_SPEC_VERSION") = py::cast(vk::KHRSamplerMirrorClampToEdgeSpecVersion);

    m_vk.attr("IMG_FILTER_CUBIC_EXTENSION_NAME") = py::cast(vk::IMGFilterCubicExtensionName);

    m_vk.attr("IMG_FILTER_CUBIC_SPEC_VERSION") = py::cast(vk::IMGFilterCubicSpecVersion);

    m_vk.attr("AMD_RASTERIZATION_ORDER_EXTENSION_NAME") = py::cast(vk::AMDRasterizationOrderExtensionName);

    m_vk.attr("AMD_RASTERIZATION_ORDER_SPEC_VERSION") = py::cast(vk::AMDRasterizationOrderSpecVersion);

    m_vk.attr("AMD_SHADER_TRINARY_MINMAX_EXTENSION_NAME") = py::cast(vk::AMDShaderTrinaryMinmaxExtensionName);

    m_vk.attr("AMD_SHADER_TRINARY_MINMAX_SPEC_VERSION") = py::cast(vk::AMDShaderTrinaryMinmaxSpecVersion);

    m_vk.attr("AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_EXTENSION_NAME") = py::cast(vk::AMDShaderExplicitVertexParameterExtensionName);

    m_vk.attr("AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_SPEC_VERSION") = py::cast(vk::AMDShaderExplicitVertexParameterSpecVersion);

    m_vk.attr("EXT_DEBUG_MARKER_EXTENSION_NAME") = py::cast(vk::EXTDebugMarkerExtensionName);

    m_vk.attr("EXT_DEBUG_MARKER_SPEC_VERSION") = py::cast(vk::EXTDebugMarkerSpecVersion);

    m_vk.attr("KHR_VIDEO_QUEUE_EXTENSION_NAME") = py::cast(vk::KHRVideoQueueExtensionName);

    m_vk.attr("KHR_VIDEO_QUEUE_SPEC_VERSION") = py::cast(vk::KHRVideoQueueSpecVersion);

    m_vk.attr("KHR_VIDEO_DECODE_QUEUE_EXTENSION_NAME") = py::cast(vk::KHRVideoDecodeQueueExtensionName);

    m_vk.attr("KHR_VIDEO_DECODE_QUEUE_SPEC_VERSION") = py::cast(vk::KHRVideoDecodeQueueSpecVersion);

    m_vk.attr("AMD_GCN_SHADER_EXTENSION_NAME") = py::cast(vk::AMDGcnShaderExtensionName);

    m_vk.attr("AMD_GCN_SHADER_SPEC_VERSION") = py::cast(vk::AMDGcnShaderSpecVersion);

    m_vk.attr("NV_DEDICATED_ALLOCATION_EXTENSION_NAME") = py::cast(vk::NVDedicatedAllocationExtensionName);

    m_vk.attr("NV_DEDICATED_ALLOCATION_SPEC_VERSION") = py::cast(vk::NVDedicatedAllocationSpecVersion);

    m_vk.attr("EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME") = py::cast(vk::EXTTransformFeedbackExtensionName);

    m_vk.attr("EXT_TRANSFORM_FEEDBACK_SPEC_VERSION") = py::cast(vk::EXTTransformFeedbackSpecVersion);

    m_vk.attr("NVX_BINARY_IMPORT_EXTENSION_NAME") = py::cast(vk::NVXBinaryImportExtensionName);

    m_vk.attr("NVX_BINARY_IMPORT_SPEC_VERSION") = py::cast(vk::NVXBinaryImportSpecVersion);

    m_vk.attr("NVX_IMAGE_VIEW_HANDLE_EXTENSION_NAME") = py::cast(vk::NVXImageViewHandleExtensionName);

    m_vk.attr("NVX_IMAGE_VIEW_HANDLE_SPEC_VERSION") = py::cast(vk::NVXImageViewHandleSpecVersion);

    m_vk.attr("AMD_DRAW_INDIRECT_COUNT_EXTENSION_NAME") = py::cast(vk::AMDDrawIndirectCountExtensionName);

    m_vk.attr("AMD_DRAW_INDIRECT_COUNT_SPEC_VERSION") = py::cast(vk::AMDDrawIndirectCountSpecVersion);

    m_vk.attr("AMD_NEGATIVE_VIEWPORT_HEIGHT_EXTENSION_NAME") = py::cast(vk::AMDNegativeViewportHeightExtensionName);

    m_vk.attr("AMD_NEGATIVE_VIEWPORT_HEIGHT_SPEC_VERSION") = py::cast(vk::AMDNegativeViewportHeightSpecVersion);

    m_vk.attr("AMD_GPU_SHADER_HALF_FLOAT_EXTENSION_NAME") = py::cast(vk::AMDGpuShaderHalfFloatExtensionName);

    m_vk.attr("AMD_GPU_SHADER_HALF_FLOAT_SPEC_VERSION") = py::cast(vk::AMDGpuShaderHalfFloatSpecVersion);

    m_vk.attr("AMD_SHADER_BALLOT_EXTENSION_NAME") = py::cast(vk::AMDShaderBallotExtensionName);

    m_vk.attr("AMD_SHADER_BALLOT_SPEC_VERSION") = py::cast(vk::AMDShaderBallotSpecVersion);

    m_vk.attr("KHR_VIDEO_ENCODE_H264_EXTENSION_NAME") = py::cast(vk::KHRVideoEncodeH264ExtensionName);

    m_vk.attr("KHR_VIDEO_ENCODE_H264_SPEC_VERSION") = py::cast(vk::KHRVideoEncodeH264SpecVersion);

    m_vk.attr("KHR_VIDEO_ENCODE_H265_EXTENSION_NAME") = py::cast(vk::KHRVideoEncodeH265ExtensionName);

    m_vk.attr("KHR_VIDEO_ENCODE_H265_SPEC_VERSION") = py::cast(vk::KHRVideoEncodeH265SpecVersion);

    m_vk.attr("KHR_VIDEO_DECODE_H264_EXTENSION_NAME") = py::cast(vk::KHRVideoDecodeH264ExtensionName);

    m_vk.attr("KHR_VIDEO_DECODE_H264_SPEC_VERSION") = py::cast(vk::KHRVideoDecodeH264SpecVersion);

    m_vk.attr("AMD_TEXTURE_GATHER_BIAS_LOD_EXTENSION_NAME") = py::cast(vk::AMDTextureGatherBiasLodExtensionName);

    m_vk.attr("AMD_TEXTURE_GATHER_BIAS_LOD_SPEC_VERSION") = py::cast(vk::AMDTextureGatherBiasLodSpecVersion);

    m_vk.attr("AMD_SHADER_INFO_EXTENSION_NAME") = py::cast(vk::AMDShaderInfoExtensionName);

    m_vk.attr("AMD_SHADER_INFO_SPEC_VERSION") = py::cast(vk::AMDShaderInfoSpecVersion);

    m_vk.attr("KHR_DYNAMIC_RENDERING_EXTENSION_NAME") = py::cast(vk::KHRDynamicRenderingExtensionName);

    m_vk.attr("KHR_DYNAMIC_RENDERING_SPEC_VERSION") = py::cast(vk::KHRDynamicRenderingSpecVersion);

    m_vk.attr("AMD_SHADER_IMAGE_LOAD_STORE_LOD_EXTENSION_NAME") = py::cast(vk::AMDShaderImageLoadStoreLodExtensionName);

    m_vk.attr("AMD_SHADER_IMAGE_LOAD_STORE_LOD_SPEC_VERSION") = py::cast(vk::AMDShaderImageLoadStoreLodSpecVersion);

    m_vk.attr("NV_CORNER_SAMPLED_IMAGE_EXTENSION_NAME") = py::cast(vk::NVCornerSampledImageExtensionName);

    m_vk.attr("NV_CORNER_SAMPLED_IMAGE_SPEC_VERSION") = py::cast(vk::NVCornerSampledImageSpecVersion);

    m_vk.attr("KHR_MULTIVIEW_EXTENSION_NAME") = py::cast(vk::KHRMultiviewExtensionName);

    m_vk.attr("KHR_MULTIVIEW_SPEC_VERSION") = py::cast(vk::KHRMultiviewSpecVersion);

    m_vk.attr("IMG_FORMAT_PVRTC_EXTENSION_NAME") = py::cast(vk::IMGFormatPvrtcExtensionName);

    m_vk.attr("IMG_FORMAT_PVRTC_SPEC_VERSION") = py::cast(vk::IMGFormatPvrtcSpecVersion);

    m_vk.attr("NV_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME") = py::cast(vk::NVExternalMemoryCapabilitiesExtensionName);

    m_vk.attr("NV_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION") = py::cast(vk::NVExternalMemoryCapabilitiesSpecVersion);

    m_vk.attr("NV_EXTERNAL_MEMORY_EXTENSION_NAME") = py::cast(vk::NVExternalMemoryExtensionName);

    m_vk.attr("NV_EXTERNAL_MEMORY_SPEC_VERSION") = py::cast(vk::NVExternalMemorySpecVersion);

    m_vk.attr("KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME") = py::cast(vk::KHRGetPhysicalDeviceProperties2ExtensionName);

    m_vk.attr("KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_SPEC_VERSION") = py::cast(vk::KHRGetPhysicalDeviceProperties2SpecVersion);

    m_vk.attr("KHR_DEVICE_GROUP_EXTENSION_NAME") = py::cast(vk::KHRDeviceGroupExtensionName);

    m_vk.attr("KHR_DEVICE_GROUP_SPEC_VERSION") = py::cast(vk::KHRDeviceGroupSpecVersion);

    m_vk.attr("EXT_VALIDATION_FLAGS_EXTENSION_NAME") = py::cast(vk::EXTValidationFlagsExtensionName);

    m_vk.attr("EXT_VALIDATION_FLAGS_SPEC_VERSION") = py::cast(vk::EXTValidationFlagsSpecVersion);

    m_vk.attr("KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME") = py::cast(vk::KHRShaderDrawParametersExtensionName);

    m_vk.attr("KHR_SHADER_DRAW_PARAMETERS_SPEC_VERSION") = py::cast(vk::KHRShaderDrawParametersSpecVersion);

    m_vk.attr("EXT_SHADER_SUBGROUP_BALLOT_EXTENSION_NAME") = py::cast(vk::EXTShaderSubgroupBallotExtensionName);

    m_vk.attr("EXT_SHADER_SUBGROUP_BALLOT_SPEC_VERSION") = py::cast(vk::EXTShaderSubgroupBallotSpecVersion);

    m_vk.attr("EXT_SHADER_SUBGROUP_VOTE_EXTENSION_NAME") = py::cast(vk::EXTShaderSubgroupVoteExtensionName);

    m_vk.attr("EXT_SHADER_SUBGROUP_VOTE_SPEC_VERSION") = py::cast(vk::EXTShaderSubgroupVoteSpecVersion);

    m_vk.attr("EXT_TEXTURE_COMPRESSION_ASTC_HDR_EXTENSION_NAME") = py::cast(vk::EXTTextureCompressionAstcHdrExtensionName);

    m_vk.attr("EXT_TEXTURE_COMPRESSION_ASTC_HDR_SPEC_VERSION") = py::cast(vk::EXTTextureCompressionAstcHdrSpecVersion);

    m_vk.attr("EXT_ASTC_DECODE_MODE_EXTENSION_NAME") = py::cast(vk::EXTAstcDecodeModeExtensionName);

    m_vk.attr("EXT_ASTC_DECODE_MODE_SPEC_VERSION") = py::cast(vk::EXTAstcDecodeModeSpecVersion);

    m_vk.attr("EXT_PIPELINE_ROBUSTNESS_EXTENSION_NAME") = py::cast(vk::EXTPipelineRobustnessExtensionName);

    m_vk.attr("EXT_PIPELINE_ROBUSTNESS_SPEC_VERSION") = py::cast(vk::EXTPipelineRobustnessSpecVersion);

    m_vk.attr("KHR_MAINTENANCE_1_EXTENSION_NAME") = py::cast(vk::KHRMaintenance1ExtensionName);

    m_vk.attr("KHR_MAINTENANCE_1_SPEC_VERSION") = py::cast(vk::KHRMaintenance1SpecVersion);

    m_vk.attr("KHR_DEVICE_GROUP_CREATION_EXTENSION_NAME") = py::cast(vk::KHRDeviceGroupCreationExtensionName);

    m_vk.attr("KHR_DEVICE_GROUP_CREATION_SPEC_VERSION") = py::cast(vk::KHRDeviceGroupCreationSpecVersion);

    m_vk.attr("MAX_DEVICE_GROUP_SIZE_KHR") = py::cast(vk::MaxDeviceGroupSizeKHR);

    m_vk.attr("KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME") = py::cast(vk::KHRExternalMemoryCapabilitiesExtensionName);

    m_vk.attr("KHR_EXTERNAL_MEMORY_CAPABILITIES_SPEC_VERSION") = py::cast(vk::KHRExternalMemoryCapabilitiesSpecVersion);

    m_vk.attr("LUID_SIZE_KHR") = py::cast(vk::LuidSizeKHR);

    m_vk.attr("KHR_EXTERNAL_MEMORY_EXTENSION_NAME") = py::cast(vk::KHRExternalMemoryExtensionName);

    m_vk.attr("KHR_EXTERNAL_MEMORY_SPEC_VERSION") = py::cast(vk::KHRExternalMemorySpecVersion);

    m_vk.attr("QUEUE_FAMILY_EXTERNAL_KHR") = py::cast(vk::QueueFamilyExternalKHR);

    m_vk.attr("KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME") = py::cast(vk::KHRExternalMemoryFdExtensionName);

    m_vk.attr("KHR_EXTERNAL_MEMORY_FD_SPEC_VERSION") = py::cast(vk::KHRExternalMemoryFdSpecVersion);

    m_vk.attr("KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_EXTENSION_NAME") = py::cast(vk::KHRExternalSemaphoreCapabilitiesExtensionName);

    m_vk.attr("KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_SPEC_VERSION") = py::cast(vk::KHRExternalSemaphoreCapabilitiesSpecVersion);

    m_vk.attr("KHR_EXTERNAL_SEMAPHORE_EXTENSION_NAME") = py::cast(vk::KHRExternalSemaphoreExtensionName);

    m_vk.attr("KHR_EXTERNAL_SEMAPHORE_SPEC_VERSION") = py::cast(vk::KHRExternalSemaphoreSpecVersion);

    m_vk.attr("KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME") = py::cast(vk::KHRExternalSemaphoreFdExtensionName);

    m_vk.attr("KHR_EXTERNAL_SEMAPHORE_FD_SPEC_VERSION") = py::cast(vk::KHRExternalSemaphoreFdSpecVersion);

    m_vk.attr("KHR_PUSH_DESCRIPTOR_EXTENSION_NAME") = py::cast(vk::KHRPushDescriptorExtensionName);

    m_vk.attr("KHR_PUSH_DESCRIPTOR_SPEC_VERSION") = py::cast(vk::KHRPushDescriptorSpecVersion);

    m_vk.attr("EXT_CONDITIONAL_RENDERING_EXTENSION_NAME") = py::cast(vk::EXTConditionalRenderingExtensionName);

    m_vk.attr("EXT_CONDITIONAL_RENDERING_SPEC_VERSION") = py::cast(vk::EXTConditionalRenderingSpecVersion);

    m_vk.attr("KHR_SHADER_FLOAT_16_INT_8_EXTENSION_NAME") = py::cast(vk::KHRShaderFloat16Int8ExtensionName);

    m_vk.attr("KHR_SHADER_FLOAT_16_INT_8_SPEC_VERSION") = py::cast(vk::KHRShaderFloat16Int8SpecVersion);

    m_vk.attr("KHR16_BIT_STORAGE_EXTENSION_NAME") = py::cast(vk::KHR16BitStorageExtensionName);

    m_vk.attr("KHR16_BIT_STORAGE_SPEC_VERSION") = py::cast(vk::KHR16BitStorageSpecVersion);

    m_vk.attr("KHR_INCREMENTAL_PRESENT_EXTENSION_NAME") = py::cast(vk::KHRIncrementalPresentExtensionName);

    m_vk.attr("KHR_INCREMENTAL_PRESENT_SPEC_VERSION") = py::cast(vk::KHRIncrementalPresentSpecVersion);

    m_vk.attr("KHR_DESCRIPTOR_UPDATE_TEMPLATE_EXTENSION_NAME") = py::cast(vk::KHRDescriptorUpdateTemplateExtensionName);

    m_vk.attr("KHR_DESCRIPTOR_UPDATE_TEMPLATE_SPEC_VERSION") = py::cast(vk::KHRDescriptorUpdateTemplateSpecVersion);

    m_vk.attr("NV_CLIP_SPACE_W_SCALING_EXTENSION_NAME") = py::cast(vk::NVClipSpaceWScalingExtensionName);

    m_vk.attr("NV_CLIP_SPACE_W_SCALING_SPEC_VERSION") = py::cast(vk::NVClipSpaceWScalingSpecVersion);

    m_vk.attr("EXT_DIRECT_MODE_DISPLAY_EXTENSION_NAME") = py::cast(vk::EXTDirectModeDisplayExtensionName);

    m_vk.attr("EXT_DIRECT_MODE_DISPLAY_SPEC_VERSION") = py::cast(vk::EXTDirectModeDisplaySpecVersion);

    m_vk.attr("EXT_DISPLAY_SURFACE_COUNTER_EXTENSION_NAME") = py::cast(vk::EXTDisplaySurfaceCounterExtensionName);

    m_vk.attr("EXT_DISPLAY_SURFACE_COUNTER_SPEC_VERSION") = py::cast(vk::EXTDisplaySurfaceCounterSpecVersion);

    m_vk.attr("EXT_DISPLAY_CONTROL_EXTENSION_NAME") = py::cast(vk::EXTDisplayControlExtensionName);

    m_vk.attr("EXT_DISPLAY_CONTROL_SPEC_VERSION") = py::cast(vk::EXTDisplayControlSpecVersion);

    m_vk.attr("GOOGLE_DISPLAY_TIMING_EXTENSION_NAME") = py::cast(vk::GOOGLEDisplayTimingExtensionName);

    m_vk.attr("GOOGLE_DISPLAY_TIMING_SPEC_VERSION") = py::cast(vk::GOOGLEDisplayTimingSpecVersion);

    m_vk.attr("NV_SAMPLE_MASK_OVERRIDE_COVERAGE_EXTENSION_NAME") = py::cast(vk::NVSampleMaskOverrideCoverageExtensionName);

    m_vk.attr("NV_SAMPLE_MASK_OVERRIDE_COVERAGE_SPEC_VERSION") = py::cast(vk::NVSampleMaskOverrideCoverageSpecVersion);

    m_vk.attr("NV_GEOMETRY_SHADER_PASSTHROUGH_EXTENSION_NAME") = py::cast(vk::NVGeometryShaderPassthroughExtensionName);

    m_vk.attr("NV_GEOMETRY_SHADER_PASSTHROUGH_SPEC_VERSION") = py::cast(vk::NVGeometryShaderPassthroughSpecVersion);

    m_vk.attr("NV_VIEWPORT_ARRAY_2_EXTENSION_NAME") = py::cast(vk::NVViewportArray2ExtensionName);

    m_vk.attr("NV_VIEWPORT_ARRAY_2_SPEC_VERSION") = py::cast(vk::NVViewportArray2SpecVersion);

    m_vk.attr("NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_EXTENSION_NAME") = py::cast(vk::NVXMultiviewPerViewAttributesExtensionName);

    m_vk.attr("NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES_SPEC_VERSION") = py::cast(vk::NVXMultiviewPerViewAttributesSpecVersion);

    m_vk.attr("NV_VIEWPORT_SWIZZLE_EXTENSION_NAME") = py::cast(vk::NVViewportSwizzleExtensionName);

    m_vk.attr("NV_VIEWPORT_SWIZZLE_SPEC_VERSION") = py::cast(vk::NVViewportSwizzleSpecVersion);

    m_vk.attr("EXT_DISCARD_RECTANGLES_EXTENSION_NAME") = py::cast(vk::EXTDiscardRectanglesExtensionName);

    m_vk.attr("EXT_DISCARD_RECTANGLES_SPEC_VERSION") = py::cast(vk::EXTDiscardRectanglesSpecVersion);

    m_vk.attr("EXT_CONSERVATIVE_RASTERIZATION_EXTENSION_NAME") = py::cast(vk::EXTConservativeRasterizationExtensionName);

    m_vk.attr("EXT_CONSERVATIVE_RASTERIZATION_SPEC_VERSION") = py::cast(vk::EXTConservativeRasterizationSpecVersion);

    m_vk.attr("EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME") = py::cast(vk::EXTDepthClipEnableExtensionName);

    m_vk.attr("EXT_DEPTH_CLIP_ENABLE_SPEC_VERSION") = py::cast(vk::EXTDepthClipEnableSpecVersion);

    m_vk.attr("EXT_SWAPCHAIN_COLOR_SPACE_EXTENSION_NAME") = py::cast(vk::EXTSwapchainColorSpaceExtensionName);

    m_vk.attr("EXT_SWAPCHAIN_COLOR_SPACE_SPEC_VERSION") = py::cast(vk::EXTSwapchainColorSpaceSpecVersion);

    m_vk.attr("EXT_HDR_METADATA_EXTENSION_NAME") = py::cast(vk::EXTHdrMetadataExtensionName);

    m_vk.attr("EXT_HDR_METADATA_SPEC_VERSION") = py::cast(vk::EXTHdrMetadataSpecVersion);

    m_vk.attr("KHR_IMAGELESS_FRAMEBUFFER_EXTENSION_NAME") = py::cast(vk::KHRImagelessFramebufferExtensionName);

    m_vk.attr("KHR_IMAGELESS_FRAMEBUFFER_SPEC_VERSION") = py::cast(vk::KHRImagelessFramebufferSpecVersion);

    m_vk.attr("KHR_CREATE_RENDERPASS_2_EXTENSION_NAME") = py::cast(vk::KHRCreateRenderpass2ExtensionName);

    m_vk.attr("KHR_CREATE_RENDERPASS_2_SPEC_VERSION") = py::cast(vk::KHRCreateRenderpass2SpecVersion);

    m_vk.attr("IMG_RELAXED_LINE_RASTERIZATION_EXTENSION_NAME") = py::cast(vk::IMGRelaxedLineRasterizationExtensionName);

    m_vk.attr("IMG_RELAXED_LINE_RASTERIZATION_SPEC_VERSION") = py::cast(vk::IMGRelaxedLineRasterizationSpecVersion);

    m_vk.attr("KHR_SHARED_PRESENTABLE_IMAGE_EXTENSION_NAME") = py::cast(vk::KHRSharedPresentableImageExtensionName);

    m_vk.attr("KHR_SHARED_PRESENTABLE_IMAGE_SPEC_VERSION") = py::cast(vk::KHRSharedPresentableImageSpecVersion);

    m_vk.attr("KHR_EXTERNAL_FENCE_CAPABILITIES_EXTENSION_NAME") = py::cast(vk::KHRExternalFenceCapabilitiesExtensionName);

    m_vk.attr("KHR_EXTERNAL_FENCE_CAPABILITIES_SPEC_VERSION") = py::cast(vk::KHRExternalFenceCapabilitiesSpecVersion);

    m_vk.attr("KHR_EXTERNAL_FENCE_EXTENSION_NAME") = py::cast(vk::KHRExternalFenceExtensionName);

    m_vk.attr("KHR_EXTERNAL_FENCE_SPEC_VERSION") = py::cast(vk::KHRExternalFenceSpecVersion);

    m_vk.attr("KHR_EXTERNAL_FENCE_FD_EXTENSION_NAME") = py::cast(vk::KHRExternalFenceFdExtensionName);

    m_vk.attr("KHR_EXTERNAL_FENCE_FD_SPEC_VERSION") = py::cast(vk::KHRExternalFenceFdSpecVersion);

    m_vk.attr("KHR_PERFORMANCE_QUERY_EXTENSION_NAME") = py::cast(vk::KHRPerformanceQueryExtensionName);

    m_vk.attr("KHR_PERFORMANCE_QUERY_SPEC_VERSION") = py::cast(vk::KHRPerformanceQuerySpecVersion);

    m_vk.attr("KHR_MAINTENANCE_2_EXTENSION_NAME") = py::cast(vk::KHRMaintenance2ExtensionName);

    m_vk.attr("KHR_MAINTENANCE_2_SPEC_VERSION") = py::cast(vk::KHRMaintenance2SpecVersion);

    m_vk.attr("KHR_GET_SURFACE_CAPABILITIES_2_EXTENSION_NAME") = py::cast(vk::KHRGetSurfaceCapabilities2ExtensionName);

    m_vk.attr("KHR_GET_SURFACE_CAPABILITIES_2_SPEC_VERSION") = py::cast(vk::KHRGetSurfaceCapabilities2SpecVersion);

    m_vk.attr("KHR_VARIABLE_POINTERS_EXTENSION_NAME") = py::cast(vk::KHRVariablePointersExtensionName);

    m_vk.attr("KHR_VARIABLE_POINTERS_SPEC_VERSION") = py::cast(vk::KHRVariablePointersSpecVersion);

    m_vk.attr("KHR_GET_DISPLAY_PROPERTIES_2_EXTENSION_NAME") = py::cast(vk::KHRGetDisplayProperties2ExtensionName);

    m_vk.attr("KHR_GET_DISPLAY_PROPERTIES_2_SPEC_VERSION") = py::cast(vk::KHRGetDisplayProperties2SpecVersion);

    m_vk.attr("EXT_EXTERNAL_MEMORY_DMA_BUF_EXTENSION_NAME") = py::cast(vk::EXTExternalMemoryDmaBufExtensionName);

    m_vk.attr("EXT_EXTERNAL_MEMORY_DMA_BUF_SPEC_VERSION") = py::cast(vk::EXTExternalMemoryDmaBufSpecVersion);

    m_vk.attr("EXT_QUEUE_FAMILY_FOREIGN_EXTENSION_NAME") = py::cast(vk::EXTQueueFamilyForeignExtensionName);

    m_vk.attr("EXT_QUEUE_FAMILY_FOREIGN_SPEC_VERSION") = py::cast(vk::EXTQueueFamilyForeignSpecVersion);

    m_vk.attr("QUEUE_FAMILY_FOREIGN_EXT") = py::cast(vk::QueueFamilyForeignEXT);

    m_vk.attr("KHR_DEDICATED_ALLOCATION_EXTENSION_NAME") = py::cast(vk::KHRDedicatedAllocationExtensionName);

    m_vk.attr("KHR_DEDICATED_ALLOCATION_SPEC_VERSION") = py::cast(vk::KHRDedicatedAllocationSpecVersion);

    m_vk.attr("EXT_DEBUG_UTILS_EXTENSION_NAME") = py::cast(vk::EXTDebugUtilsExtensionName);

    m_vk.attr("EXT_DEBUG_UTILS_SPEC_VERSION") = py::cast(vk::EXTDebugUtilsSpecVersion);

    m_vk.attr("EXT_SAMPLER_FILTER_MINMAX_EXTENSION_NAME") = py::cast(vk::EXTSamplerFilterMinmaxExtensionName);

    m_vk.attr("EXT_SAMPLER_FILTER_MINMAX_SPEC_VERSION") = py::cast(vk::EXTSamplerFilterMinmaxSpecVersion);

    m_vk.attr("KHR_STORAGE_BUFFER_STORAGE_CLASS_EXTENSION_NAME") = py::cast(vk::KHRStorageBufferStorageClassExtensionName);

    m_vk.attr("KHR_STORAGE_BUFFER_STORAGE_CLASS_SPEC_VERSION") = py::cast(vk::KHRStorageBufferStorageClassSpecVersion);

    m_vk.attr("AMD_GPU_SHADER_INT_16_EXTENSION_NAME") = py::cast(vk::AMDGpuShaderInt16ExtensionName);

    m_vk.attr("AMD_GPU_SHADER_INT_16_SPEC_VERSION") = py::cast(vk::AMDGpuShaderInt16SpecVersion);

    m_vk.attr("AMD_MIXED_ATTACHMENT_SAMPLES_EXTENSION_NAME") = py::cast(vk::AMDMixedAttachmentSamplesExtensionName);

    m_vk.attr("AMD_MIXED_ATTACHMENT_SAMPLES_SPEC_VERSION") = py::cast(vk::AMDMixedAttachmentSamplesSpecVersion);

    m_vk.attr("AMD_SHADER_FRAGMENT_MASK_EXTENSION_NAME") = py::cast(vk::AMDShaderFragmentMaskExtensionName);

    m_vk.attr("AMD_SHADER_FRAGMENT_MASK_SPEC_VERSION") = py::cast(vk::AMDShaderFragmentMaskSpecVersion);

    m_vk.attr("EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME") = py::cast(vk::EXTInlineUniformBlockExtensionName);

    m_vk.attr("EXT_INLINE_UNIFORM_BLOCK_SPEC_VERSION") = py::cast(vk::EXTInlineUniformBlockSpecVersion);

    m_vk.attr("EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME") = py::cast(vk::EXTShaderStencilExportExtensionName);

    m_vk.attr("EXT_SHADER_STENCIL_EXPORT_SPEC_VERSION") = py::cast(vk::EXTShaderStencilExportSpecVersion);

    m_vk.attr("EXT_SAMPLE_LOCATIONS_EXTENSION_NAME") = py::cast(vk::EXTSampleLocationsExtensionName);

    m_vk.attr("EXT_SAMPLE_LOCATIONS_SPEC_VERSION") = py::cast(vk::EXTSampleLocationsSpecVersion);

    m_vk.attr("KHR_RELAXED_BLOCK_LAYOUT_EXTENSION_NAME") = py::cast(vk::KHRRelaxedBlockLayoutExtensionName);

    m_vk.attr("KHR_RELAXED_BLOCK_LAYOUT_SPEC_VERSION") = py::cast(vk::KHRRelaxedBlockLayoutSpecVersion);

    m_vk.attr("KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME") = py::cast(vk::KHRGetMemoryRequirements2ExtensionName);

    m_vk.attr("KHR_GET_MEMORY_REQUIREMENTS_2_SPEC_VERSION") = py::cast(vk::KHRGetMemoryRequirements2SpecVersion);

    m_vk.attr("KHR_IMAGE_FORMAT_LIST_EXTENSION_NAME") = py::cast(vk::KHRImageFormatListExtensionName);

    m_vk.attr("KHR_IMAGE_FORMAT_LIST_SPEC_VERSION") = py::cast(vk::KHRImageFormatListSpecVersion);

    m_vk.attr("EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME") = py::cast(vk::EXTBlendOperationAdvancedExtensionName);

    m_vk.attr("EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION") = py::cast(vk::EXTBlendOperationAdvancedSpecVersion);

    m_vk.attr("NV_FRAGMENT_COVERAGE_TO_COLOR_EXTENSION_NAME") = py::cast(vk::NVFragmentCoverageToColorExtensionName);

    m_vk.attr("NV_FRAGMENT_COVERAGE_TO_COLOR_SPEC_VERSION") = py::cast(vk::NVFragmentCoverageToColorSpecVersion);

    m_vk.attr("KHR_ACCELERATION_STRUCTURE_EXTENSION_NAME") = py::cast(vk::KHRAccelerationStructureExtensionName);

    m_vk.attr("KHR_ACCELERATION_STRUCTURE_SPEC_VERSION") = py::cast(vk::KHRAccelerationStructureSpecVersion);

    m_vk.attr("KHR_RAY_TRACING_PIPELINE_EXTENSION_NAME") = py::cast(vk::KHRRayTracingPipelineExtensionName);

    m_vk.attr("KHR_RAY_TRACING_PIPELINE_SPEC_VERSION") = py::cast(vk::KHRRayTracingPipelineSpecVersion);

    m_vk.attr("SHADER_UNUSED_KHR") = py::cast(vk::ShaderUnusedKHR);

    m_vk.attr("KHR_RAY_QUERY_EXTENSION_NAME") = py::cast(vk::KHRRayQueryExtensionName);

    m_vk.attr("KHR_RAY_QUERY_SPEC_VERSION") = py::cast(vk::KHRRayQuerySpecVersion);

    m_vk.attr("NV_FRAMEBUFFER_MIXED_SAMPLES_EXTENSION_NAME") = py::cast(vk::NVFramebufferMixedSamplesExtensionName);

    m_vk.attr("NV_FRAMEBUFFER_MIXED_SAMPLES_SPEC_VERSION") = py::cast(vk::NVFramebufferMixedSamplesSpecVersion);

    m_vk.attr("NV_FILL_RECTANGLE_EXTENSION_NAME") = py::cast(vk::NVFillRectangleExtensionName);

    m_vk.attr("NV_FILL_RECTANGLE_SPEC_VERSION") = py::cast(vk::NVFillRectangleSpecVersion);

    m_vk.attr("NV_SHADER_SM_BUILTINS_EXTENSION_NAME") = py::cast(vk::NVShaderSmBuiltinsExtensionName);

    m_vk.attr("NV_SHADER_SM_BUILTINS_SPEC_VERSION") = py::cast(vk::NVShaderSmBuiltinsSpecVersion);

    m_vk.attr("EXT_POST_DEPTH_COVERAGE_EXTENSION_NAME") = py::cast(vk::EXTPostDepthCoverageExtensionName);

    m_vk.attr("EXT_POST_DEPTH_COVERAGE_SPEC_VERSION") = py::cast(vk::EXTPostDepthCoverageSpecVersion);

    m_vk.attr("KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME") = py::cast(vk::KHRSamplerYcbcrConversionExtensionName);

    m_vk.attr("KHR_SAMPLER_YCBCR_CONVERSION_SPEC_VERSION") = py::cast(vk::KHRSamplerYcbcrConversionSpecVersion);

    m_vk.attr("KHR_BIND_MEMORY_2_EXTENSION_NAME") = py::cast(vk::KHRBindMemory2ExtensionName);

    m_vk.attr("KHR_BIND_MEMORY_2_SPEC_VERSION") = py::cast(vk::KHRBindMemory2SpecVersion);

    m_vk.attr("EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME") = py::cast(vk::EXTImageDrmFormatModifierExtensionName);

    m_vk.attr("EXT_IMAGE_DRM_FORMAT_MODIFIER_SPEC_VERSION") = py::cast(vk::EXTImageDrmFormatModifierSpecVersion);

    m_vk.attr("EXT_VALIDATION_CACHE_EXTENSION_NAME") = py::cast(vk::EXTValidationCacheExtensionName);

    m_vk.attr("EXT_VALIDATION_CACHE_SPEC_VERSION") = py::cast(vk::EXTValidationCacheSpecVersion);

    m_vk.attr("EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME") = py::cast(vk::EXTDescriptorIndexingExtensionName);

    m_vk.attr("EXT_DESCRIPTOR_INDEXING_SPEC_VERSION") = py::cast(vk::EXTDescriptorIndexingSpecVersion);

    m_vk.attr("EXT_SHADER_VIEWPORT_INDEX_LAYER_EXTENSION_NAME") = py::cast(vk::EXTShaderViewportIndexLayerExtensionName);

    m_vk.attr("EXT_SHADER_VIEWPORT_INDEX_LAYER_SPEC_VERSION") = py::cast(vk::EXTShaderViewportIndexLayerSpecVersion);

    m_vk.attr("NV_SHADING_RATE_IMAGE_EXTENSION_NAME") = py::cast(vk::NVShadingRateImageExtensionName);

    m_vk.attr("NV_SHADING_RATE_IMAGE_SPEC_VERSION") = py::cast(vk::NVShadingRateImageSpecVersion);

    m_vk.attr("NV_RAY_TRACING_EXTENSION_NAME") = py::cast(vk::NVRayTracingExtensionName);

    m_vk.attr("NV_RAY_TRACING_SPEC_VERSION") = py::cast(vk::NVRayTracingSpecVersion);

    m_vk.attr("SHADER_UNUSED_NV") = py::cast(vk::ShaderUnusedNV);

    m_vk.attr("NV_REPRESENTATIVE_FRAGMENT_TEST_EXTENSION_NAME") = py::cast(vk::NVRepresentativeFragmentTestExtensionName);

    m_vk.attr("NV_REPRESENTATIVE_FRAGMENT_TEST_SPEC_VERSION") = py::cast(vk::NVRepresentativeFragmentTestSpecVersion);

    m_vk.attr("KHR_MAINTENANCE_3_EXTENSION_NAME") = py::cast(vk::KHRMaintenance3ExtensionName);

    m_vk.attr("KHR_MAINTENANCE_3_SPEC_VERSION") = py::cast(vk::KHRMaintenance3SpecVersion);

    m_vk.attr("KHR_DRAW_INDIRECT_COUNT_EXTENSION_NAME") = py::cast(vk::KHRDrawIndirectCountExtensionName);

    m_vk.attr("KHR_DRAW_INDIRECT_COUNT_SPEC_VERSION") = py::cast(vk::KHRDrawIndirectCountSpecVersion);

    m_vk.attr("EXT_FILTER_CUBIC_EXTENSION_NAME") = py::cast(vk::EXTFilterCubicExtensionName);

    m_vk.attr("EXT_FILTER_CUBIC_SPEC_VERSION") = py::cast(vk::EXTFilterCubicSpecVersion);

    m_vk.attr("QCOM_RENDER_PASS_SHADER_RESOLVE_EXTENSION_NAME") = py::cast(vk::QCOMRenderPassShaderResolveExtensionName);

    m_vk.attr("QCOM_RENDER_PASS_SHADER_RESOLVE_SPEC_VERSION") = py::cast(vk::QCOMRenderPassShaderResolveSpecVersion);

    m_vk.attr("EXT_GLOBAL_PRIORITY_EXTENSION_NAME") = py::cast(vk::EXTGlobalPriorityExtensionName);

    m_vk.attr("EXT_GLOBAL_PRIORITY_SPEC_VERSION") = py::cast(vk::EXTGlobalPrioritySpecVersion);

    m_vk.attr("KHR_SHADER_SUBGROUP_EXTENDED_TYPES_EXTENSION_NAME") = py::cast(vk::KHRShaderSubgroupExtendedTypesExtensionName);

    m_vk.attr("KHR_SHADER_SUBGROUP_EXTENDED_TYPES_SPEC_VERSION") = py::cast(vk::KHRShaderSubgroupExtendedTypesSpecVersion);

    m_vk.attr("KHR8_BIT_STORAGE_EXTENSION_NAME") = py::cast(vk::KHR8BitStorageExtensionName);

    m_vk.attr("KHR8_BIT_STORAGE_SPEC_VERSION") = py::cast(vk::KHR8BitStorageSpecVersion);

    m_vk.attr("EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME") = py::cast(vk::EXTExternalMemoryHostExtensionName);

    m_vk.attr("EXT_EXTERNAL_MEMORY_HOST_SPEC_VERSION") = py::cast(vk::EXTExternalMemoryHostSpecVersion);

    m_vk.attr("AMD_BUFFER_MARKER_EXTENSION_NAME") = py::cast(vk::AMDBufferMarkerExtensionName);

    m_vk.attr("AMD_BUFFER_MARKER_SPEC_VERSION") = py::cast(vk::AMDBufferMarkerSpecVersion);

    m_vk.attr("KHR_SHADER_ATOMIC_INT_64_EXTENSION_NAME") = py::cast(vk::KHRShaderAtomicInt64ExtensionName);

    m_vk.attr("KHR_SHADER_ATOMIC_INT_64_SPEC_VERSION") = py::cast(vk::KHRShaderAtomicInt64SpecVersion);

    m_vk.attr("KHR_SHADER_CLOCK_EXTENSION_NAME") = py::cast(vk::KHRShaderClockExtensionName);

    m_vk.attr("KHR_SHADER_CLOCK_SPEC_VERSION") = py::cast(vk::KHRShaderClockSpecVersion);

    m_vk.attr("AMD_PIPELINE_COMPILER_CONTROL_EXTENSION_NAME") = py::cast(vk::AMDPipelineCompilerControlExtensionName);

    m_vk.attr("AMD_PIPELINE_COMPILER_CONTROL_SPEC_VERSION") = py::cast(vk::AMDPipelineCompilerControlSpecVersion);

    m_vk.attr("EXT_CALIBRATED_TIMESTAMPS_EXTENSION_NAME") = py::cast(vk::EXTCalibratedTimestampsExtensionName);

    m_vk.attr("EXT_CALIBRATED_TIMESTAMPS_SPEC_VERSION") = py::cast(vk::EXTCalibratedTimestampsSpecVersion);

    m_vk.attr("AMD_SHADER_CORE_PROPERTIES_EXTENSION_NAME") = py::cast(vk::AMDShaderCorePropertiesExtensionName);

    m_vk.attr("AMD_SHADER_CORE_PROPERTIES_SPEC_VERSION") = py::cast(vk::AMDShaderCorePropertiesSpecVersion);

    m_vk.attr("KHR_VIDEO_DECODE_H265_EXTENSION_NAME") = py::cast(vk::KHRVideoDecodeH265ExtensionName);

    m_vk.attr("KHR_VIDEO_DECODE_H265_SPEC_VERSION") = py::cast(vk::KHRVideoDecodeH265SpecVersion);

    m_vk.attr("KHR_GLOBAL_PRIORITY_EXTENSION_NAME") = py::cast(vk::KHRGlobalPriorityExtensionName);

    m_vk.attr("KHR_GLOBAL_PRIORITY_SPEC_VERSION") = py::cast(vk::KHRGlobalPrioritySpecVersion);

    m_vk.attr("MAX_GLOBAL_PRIORITY_SIZE_KHR") = py::cast(vk::MaxGlobalPrioritySizeKHR);

    m_vk.attr("AMD_MEMORY_OVERALLOCATION_BEHAVIOR_EXTENSION_NAME") = py::cast(vk::AMDMemoryOverallocationBehaviorExtensionName);

    m_vk.attr("AMD_MEMORY_OVERALLOCATION_BEHAVIOR_SPEC_VERSION") = py::cast(vk::AMDMemoryOverallocationBehaviorSpecVersion);

    m_vk.attr("EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME") = py::cast(vk::EXTVertexAttributeDivisorExtensionName);

    m_vk.attr("EXT_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION") = py::cast(vk::EXTVertexAttributeDivisorSpecVersion);

    m_vk.attr("EXT_PIPELINE_CREATION_FEEDBACK_EXTENSION_NAME") = py::cast(vk::EXTPipelineCreationFeedbackExtensionName);

    m_vk.attr("EXT_PIPELINE_CREATION_FEEDBACK_SPEC_VERSION") = py::cast(vk::EXTPipelineCreationFeedbackSpecVersion);

    m_vk.attr("KHR_DRIVER_PROPERTIES_EXTENSION_NAME") = py::cast(vk::KHRDriverPropertiesExtensionName);

    m_vk.attr("KHR_DRIVER_PROPERTIES_SPEC_VERSION") = py::cast(vk::KHRDriverPropertiesSpecVersion);

    m_vk.attr("MAX_DRIVER_INFO_SIZE_KHR") = py::cast(vk::MaxDriverInfoSizeKHR);

    m_vk.attr("MAX_DRIVER_NAME_SIZE_KHR") = py::cast(vk::MaxDriverNameSizeKHR);

    m_vk.attr("KHR_SHADER_FLOAT_CONTROLS_EXTENSION_NAME") = py::cast(vk::KHRShaderFloatControlsExtensionName);

    m_vk.attr("KHR_SHADER_FLOAT_CONTROLS_SPEC_VERSION") = py::cast(vk::KHRShaderFloatControlsSpecVersion);

    m_vk.attr("NV_SHADER_SUBGROUP_PARTITIONED_EXTENSION_NAME") = py::cast(vk::NVShaderSubgroupPartitionedExtensionName);

    m_vk.attr("NV_SHADER_SUBGROUP_PARTITIONED_SPEC_VERSION") = py::cast(vk::NVShaderSubgroupPartitionedSpecVersion);

    m_vk.attr("KHR_DEPTH_STENCIL_RESOLVE_EXTENSION_NAME") = py::cast(vk::KHRDepthStencilResolveExtensionName);

    m_vk.attr("KHR_DEPTH_STENCIL_RESOLVE_SPEC_VERSION") = py::cast(vk::KHRDepthStencilResolveSpecVersion);

    m_vk.attr("KHR_SWAPCHAIN_MUTABLE_FORMAT_EXTENSION_NAME") = py::cast(vk::KHRSwapchainMutableFormatExtensionName);

    m_vk.attr("KHR_SWAPCHAIN_MUTABLE_FORMAT_SPEC_VERSION") = py::cast(vk::KHRSwapchainMutableFormatSpecVersion);

    m_vk.attr("NV_COMPUTE_SHADER_DERIVATIVES_EXTENSION_NAME") = py::cast(vk::NVComputeShaderDerivativesExtensionName);

    m_vk.attr("NV_COMPUTE_SHADER_DERIVATIVES_SPEC_VERSION") = py::cast(vk::NVComputeShaderDerivativesSpecVersion);

    m_vk.attr("NV_MESH_SHADER_EXTENSION_NAME") = py::cast(vk::NVMeshShaderExtensionName);

    m_vk.attr("NV_MESH_SHADER_SPEC_VERSION") = py::cast(vk::NVMeshShaderSpecVersion);

    m_vk.attr("NV_FRAGMENT_SHADER_BARYCENTRIC_EXTENSION_NAME") = py::cast(vk::NVFragmentShaderBarycentricExtensionName);

    m_vk.attr("NV_FRAGMENT_SHADER_BARYCENTRIC_SPEC_VERSION") = py::cast(vk::NVFragmentShaderBarycentricSpecVersion);

    m_vk.attr("NV_SHADER_IMAGE_FOOTPRINT_EXTENSION_NAME") = py::cast(vk::NVShaderImageFootprintExtensionName);

    m_vk.attr("NV_SHADER_IMAGE_FOOTPRINT_SPEC_VERSION") = py::cast(vk::NVShaderImageFootprintSpecVersion);

    m_vk.attr("NV_SCISSOR_EXCLUSIVE_EXTENSION_NAME") = py::cast(vk::NVScissorExclusiveExtensionName);

    m_vk.attr("NV_SCISSOR_EXCLUSIVE_SPEC_VERSION") = py::cast(vk::NVScissorExclusiveSpecVersion);

    m_vk.attr("NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME") = py::cast(vk::NVDeviceDiagnosticCheckpointsExtensionName);

    m_vk.attr("NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_SPEC_VERSION") = py::cast(vk::NVDeviceDiagnosticCheckpointsSpecVersion);

    m_vk.attr("KHR_TIMELINE_SEMAPHORE_EXTENSION_NAME") = py::cast(vk::KHRTimelineSemaphoreExtensionName);

    m_vk.attr("KHR_TIMELINE_SEMAPHORE_SPEC_VERSION") = py::cast(vk::KHRTimelineSemaphoreSpecVersion);

    m_vk.attr("INTEL_SHADER_INTEGER_FUNCTIONS_2_EXTENSION_NAME") = py::cast(vk::INTELShaderIntegerFunctions2ExtensionName);

    m_vk.attr("INTEL_SHADER_INTEGER_FUNCTIONS_2_SPEC_VERSION") = py::cast(vk::INTELShaderIntegerFunctions2SpecVersion);

    m_vk.attr("INTEL_PERFORMANCE_QUERY_EXTENSION_NAME") = py::cast(vk::INTELPerformanceQueryExtensionName);

    m_vk.attr("INTEL_PERFORMANCE_QUERY_SPEC_VERSION") = py::cast(vk::INTELPerformanceQuerySpecVersion);

    m_vk.attr("KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME") = py::cast(vk::KHRVulkanMemoryModelExtensionName);

    m_vk.attr("KHR_VULKAN_MEMORY_MODEL_SPEC_VERSION") = py::cast(vk::KHRVulkanMemoryModelSpecVersion);

    m_vk.attr("EXT_PCI_BUS_INFO_EXTENSION_NAME") = py::cast(vk::EXTPciBusInfoExtensionName);

    m_vk.attr("EXT_PCI_BUS_INFO_SPEC_VERSION") = py::cast(vk::EXTPciBusInfoSpecVersion);

    m_vk.attr("AMD_DISPLAY_NATIVE_HDR_EXTENSION_NAME") = py::cast(vk::AMDDisplayNativeHdrExtensionName);

    m_vk.attr("AMD_DISPLAY_NATIVE_HDR_SPEC_VERSION") = py::cast(vk::AMDDisplayNativeHdrSpecVersion);

    m_vk.attr("KHR_SHADER_TERMINATE_INVOCATION_EXTENSION_NAME") = py::cast(vk::KHRShaderTerminateInvocationExtensionName);

    m_vk.attr("KHR_SHADER_TERMINATE_INVOCATION_SPEC_VERSION") = py::cast(vk::KHRShaderTerminateInvocationSpecVersion);

    m_vk.attr("EXT_FRAGMENT_DENSITY_MAP_EXTENSION_NAME") = py::cast(vk::EXTFragmentDensityMapExtensionName);

    m_vk.attr("EXT_FRAGMENT_DENSITY_MAP_SPEC_VERSION") = py::cast(vk::EXTFragmentDensityMapSpecVersion);

    m_vk.attr("EXT_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME") = py::cast(vk::EXTScalarBlockLayoutExtensionName);

    m_vk.attr("EXT_SCALAR_BLOCK_LAYOUT_SPEC_VERSION") = py::cast(vk::EXTScalarBlockLayoutSpecVersion);

    m_vk.attr("GOOGLE_HLSL_FUNCTIONALITY_1_EXTENSION_NAME") = py::cast(vk::GOOGLEHlslFunctionality1ExtensionName);

    m_vk.attr("GOOGLE_HLSL_FUNCTIONALITY_1_SPEC_VERSION") = py::cast(vk::GOOGLEHlslFunctionality1SpecVersion);

    m_vk.attr("GOOGLE_DECORATE_STRING_EXTENSION_NAME") = py::cast(vk::GOOGLEDecorateStringExtensionName);

    m_vk.attr("GOOGLE_DECORATE_STRING_SPEC_VERSION") = py::cast(vk::GOOGLEDecorateStringSpecVersion);

    m_vk.attr("EXT_SUBGROUP_SIZE_CONTROL_EXTENSION_NAME") = py::cast(vk::EXTSubgroupSizeControlExtensionName);

    m_vk.attr("EXT_SUBGROUP_SIZE_CONTROL_SPEC_VERSION") = py::cast(vk::EXTSubgroupSizeControlSpecVersion);

    m_vk.attr("KHR_FRAGMENT_SHADING_RATE_EXTENSION_NAME") = py::cast(vk::KHRFragmentShadingRateExtensionName);

    m_vk.attr("KHR_FRAGMENT_SHADING_RATE_SPEC_VERSION") = py::cast(vk::KHRFragmentShadingRateSpecVersion);

    m_vk.attr("AMD_SHADER_CORE_PROPERTIES_2_EXTENSION_NAME") = py::cast(vk::AMDShaderCoreProperties2ExtensionName);

    m_vk.attr("AMD_SHADER_CORE_PROPERTIES_2_SPEC_VERSION") = py::cast(vk::AMDShaderCoreProperties2SpecVersion);

    m_vk.attr("AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME") = py::cast(vk::AMDDeviceCoherentMemoryExtensionName);

    m_vk.attr("AMD_DEVICE_COHERENT_MEMORY_SPEC_VERSION") = py::cast(vk::AMDDeviceCoherentMemorySpecVersion);

    m_vk.attr("EXT_SHADER_IMAGE_ATOMIC_INT_64_EXTENSION_NAME") = py::cast(vk::EXTShaderImageAtomicInt64ExtensionName);

    m_vk.attr("EXT_SHADER_IMAGE_ATOMIC_INT_64_SPEC_VERSION") = py::cast(vk::EXTShaderImageAtomicInt64SpecVersion);

    m_vk.attr("KHR_SPIRV_14_EXTENSION_NAME") = py::cast(vk::KHRSpirv14ExtensionName);

    m_vk.attr("KHR_SPIRV_14_SPEC_VERSION") = py::cast(vk::KHRSpirv14SpecVersion);

    m_vk.attr("EXT_MEMORY_BUDGET_EXTENSION_NAME") = py::cast(vk::EXTMemoryBudgetExtensionName);

    m_vk.attr("EXT_MEMORY_BUDGET_SPEC_VERSION") = py::cast(vk::EXTMemoryBudgetSpecVersion);

    m_vk.attr("EXT_MEMORY_PRIORITY_EXTENSION_NAME") = py::cast(vk::EXTMemoryPriorityExtensionName);

    m_vk.attr("EXT_MEMORY_PRIORITY_SPEC_VERSION") = py::cast(vk::EXTMemoryPrioritySpecVersion);

    m_vk.attr("KHR_SURFACE_PROTECTED_CAPABILITIES_EXTENSION_NAME") = py::cast(vk::KHRSurfaceProtectedCapabilitiesExtensionName);

    m_vk.attr("KHR_SURFACE_PROTECTED_CAPABILITIES_SPEC_VERSION") = py::cast(vk::KHRSurfaceProtectedCapabilitiesSpecVersion);

    m_vk.attr("NV_DEDICATED_ALLOCATION_IMAGE_ALIASING_EXTENSION_NAME") = py::cast(vk::NVDedicatedAllocationImageAliasingExtensionName);

    m_vk.attr("NV_DEDICATED_ALLOCATION_IMAGE_ALIASING_SPEC_VERSION") = py::cast(vk::NVDedicatedAllocationImageAliasingSpecVersion);

    m_vk.attr("KHR_SEPARATE_DEPTH_STENCIL_LAYOUTS_EXTENSION_NAME") = py::cast(vk::KHRSeparateDepthStencilLayoutsExtensionName);

    m_vk.attr("KHR_SEPARATE_DEPTH_STENCIL_LAYOUTS_SPEC_VERSION") = py::cast(vk::KHRSeparateDepthStencilLayoutsSpecVersion);

    m_vk.attr("EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME") = py::cast(vk::EXTBufferDeviceAddressExtensionName);

    m_vk.attr("EXT_BUFFER_DEVICE_ADDRESS_SPEC_VERSION") = py::cast(vk::EXTBufferDeviceAddressSpecVersion);

    m_vk.attr("EXT_TOOLING_INFO_EXTENSION_NAME") = py::cast(vk::EXTToolingInfoExtensionName);

    m_vk.attr("EXT_TOOLING_INFO_SPEC_VERSION") = py::cast(vk::EXTToolingInfoSpecVersion);

    m_vk.attr("EXT_SEPARATE_STENCIL_USAGE_EXTENSION_NAME") = py::cast(vk::EXTSeparateStencilUsageExtensionName);

    m_vk.attr("EXT_SEPARATE_STENCIL_USAGE_SPEC_VERSION") = py::cast(vk::EXTSeparateStencilUsageSpecVersion);

    m_vk.attr("EXT_VALIDATION_FEATURES_EXTENSION_NAME") = py::cast(vk::EXTValidationFeaturesExtensionName);

    m_vk.attr("EXT_VALIDATION_FEATURES_SPEC_VERSION") = py::cast(vk::EXTValidationFeaturesSpecVersion);

    m_vk.attr("KHR_PRESENT_WAIT_EXTENSION_NAME") = py::cast(vk::KHRPresentWaitExtensionName);

    m_vk.attr("KHR_PRESENT_WAIT_SPEC_VERSION") = py::cast(vk::KHRPresentWaitSpecVersion);

    m_vk.attr("NV_COOPERATIVE_MATRIX_EXTENSION_NAME") = py::cast(vk::NVCooperativeMatrixExtensionName);

    m_vk.attr("NV_COOPERATIVE_MATRIX_SPEC_VERSION") = py::cast(vk::NVCooperativeMatrixSpecVersion);

    m_vk.attr("NV_COVERAGE_REDUCTION_MODE_EXTENSION_NAME") = py::cast(vk::NVCoverageReductionModeExtensionName);

    m_vk.attr("NV_COVERAGE_REDUCTION_MODE_SPEC_VERSION") = py::cast(vk::NVCoverageReductionModeSpecVersion);

    m_vk.attr("EXT_FRAGMENT_SHADER_INTERLOCK_EXTENSION_NAME") = py::cast(vk::EXTFragmentShaderInterlockExtensionName);

    m_vk.attr("EXT_FRAGMENT_SHADER_INTERLOCK_SPEC_VERSION") = py::cast(vk::EXTFragmentShaderInterlockSpecVersion);

    m_vk.attr("EXT_YCBCR_IMAGE_ARRAYS_EXTENSION_NAME") = py::cast(vk::EXTYcbcrImageArraysExtensionName);

    m_vk.attr("EXT_YCBCR_IMAGE_ARRAYS_SPEC_VERSION") = py::cast(vk::EXTYcbcrImageArraysSpecVersion);

    m_vk.attr("KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME") = py::cast(vk::KHRUniformBufferStandardLayoutExtensionName);

    m_vk.attr("KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_SPEC_VERSION") = py::cast(vk::KHRUniformBufferStandardLayoutSpecVersion);

    m_vk.attr("EXT_PROVOKING_VERTEX_EXTENSION_NAME") = py::cast(vk::EXTProvokingVertexExtensionName);

    m_vk.attr("EXT_PROVOKING_VERTEX_SPEC_VERSION") = py::cast(vk::EXTProvokingVertexSpecVersion);

    m_vk.attr("EXT_HEADLESS_SURFACE_EXTENSION_NAME") = py::cast(vk::EXTHeadlessSurfaceExtensionName);

    m_vk.attr("EXT_HEADLESS_SURFACE_SPEC_VERSION") = py::cast(vk::EXTHeadlessSurfaceSpecVersion);

    m_vk.attr("KHR_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME") = py::cast(vk::KHRBufferDeviceAddressExtensionName);

    m_vk.attr("KHR_BUFFER_DEVICE_ADDRESS_SPEC_VERSION") = py::cast(vk::KHRBufferDeviceAddressSpecVersion);

    m_vk.attr("EXT_LINE_RASTERIZATION_EXTENSION_NAME") = py::cast(vk::EXTLineRasterizationExtensionName);

    m_vk.attr("EXT_LINE_RASTERIZATION_SPEC_VERSION") = py::cast(vk::EXTLineRasterizationSpecVersion);

    m_vk.attr("EXT_SHADER_ATOMIC_FLOAT_EXTENSION_NAME") = py::cast(vk::EXTShaderAtomicFloatExtensionName);

    m_vk.attr("EXT_SHADER_ATOMIC_FLOAT_SPEC_VERSION") = py::cast(vk::EXTShaderAtomicFloatSpecVersion);

    m_vk.attr("EXT_HOST_QUERY_RESET_EXTENSION_NAME") = py::cast(vk::EXTHostQueryResetExtensionName);

    m_vk.attr("EXT_HOST_QUERY_RESET_SPEC_VERSION") = py::cast(vk::EXTHostQueryResetSpecVersion);

    m_vk.attr("EXT_INDEX_TYPE_UINT_8_EXTENSION_NAME") = py::cast(vk::EXTIndexTypeUint8ExtensionName);

    m_vk.attr("EXT_INDEX_TYPE_UINT_8_SPEC_VERSION") = py::cast(vk::EXTIndexTypeUint8SpecVersion);

    m_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME") = py::cast(vk::EXTExtendedDynamicStateExtensionName);

    m_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_SPEC_VERSION") = py::cast(vk::EXTExtendedDynamicStateSpecVersion);

    m_vk.attr("KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME") = py::cast(vk::KHRDeferredHostOperationsExtensionName);

    m_vk.attr("KHR_DEFERRED_HOST_OPERATIONS_SPEC_VERSION") = py::cast(vk::KHRDeferredHostOperationsSpecVersion);

    m_vk.attr("KHR_PIPELINE_EXECUTABLE_PROPERTIES_EXTENSION_NAME") = py::cast(vk::KHRPipelineExecutablePropertiesExtensionName);

    m_vk.attr("KHR_PIPELINE_EXECUTABLE_PROPERTIES_SPEC_VERSION") = py::cast(vk::KHRPipelineExecutablePropertiesSpecVersion);

    m_vk.attr("EXT_HOST_IMAGE_COPY_EXTENSION_NAME") = py::cast(vk::EXTHostImageCopyExtensionName);

    m_vk.attr("EXT_HOST_IMAGE_COPY_SPEC_VERSION") = py::cast(vk::EXTHostImageCopySpecVersion);

    m_vk.attr("KHR_MAP_MEMORY_2_EXTENSION_NAME") = py::cast(vk::KHRMapMemory2ExtensionName);

    m_vk.attr("KHR_MAP_MEMORY_2_SPEC_VERSION") = py::cast(vk::KHRMapMemory2SpecVersion);

    m_vk.attr("EXT_SHADER_ATOMIC_FLOAT_2_EXTENSION_NAME") = py::cast(vk::EXTShaderAtomicFloat2ExtensionName);

    m_vk.attr("EXT_SHADER_ATOMIC_FLOAT_2_SPEC_VERSION") = py::cast(vk::EXTShaderAtomicFloat2SpecVersion);

    m_vk.attr("EXT_SURFACE_MAINTENANCE_1_EXTENSION_NAME") = py::cast(vk::EXTSurfaceMaintenance1ExtensionName);

    m_vk.attr("EXT_SURFACE_MAINTENANCE_1_SPEC_VERSION") = py::cast(vk::EXTSurfaceMaintenance1SpecVersion);

    m_vk.attr("EXT_SWAPCHAIN_MAINTENANCE_1_EXTENSION_NAME") = py::cast(vk::EXTSwapchainMaintenance1ExtensionName);

    m_vk.attr("EXT_SWAPCHAIN_MAINTENANCE_1_SPEC_VERSION") = py::cast(vk::EXTSwapchainMaintenance1SpecVersion);

    m_vk.attr("EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_EXTENSION_NAME") = py::cast(vk::EXTShaderDemoteToHelperInvocationExtensionName);

    m_vk.attr("EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION_SPEC_VERSION") = py::cast(vk::EXTShaderDemoteToHelperInvocationSpecVersion);

    m_vk.attr("NV_DEVICE_GENERATED_COMMANDS_EXTENSION_NAME") = py::cast(vk::NVDeviceGeneratedCommandsExtensionName);

    m_vk.attr("NV_DEVICE_GENERATED_COMMANDS_SPEC_VERSION") = py::cast(vk::NVDeviceGeneratedCommandsSpecVersion);

    m_vk.attr("NV_INHERITED_VIEWPORT_SCISSOR_EXTENSION_NAME") = py::cast(vk::NVInheritedViewportScissorExtensionName);

    m_vk.attr("NV_INHERITED_VIEWPORT_SCISSOR_SPEC_VERSION") = py::cast(vk::NVInheritedViewportScissorSpecVersion);

    m_vk.attr("KHR_SHADER_INTEGER_DOT_PRODUCT_EXTENSION_NAME") = py::cast(vk::KHRShaderIntegerDotProductExtensionName);

    m_vk.attr("KHR_SHADER_INTEGER_DOT_PRODUCT_SPEC_VERSION") = py::cast(vk::KHRShaderIntegerDotProductSpecVersion);

    m_vk.attr("EXT_TEXEL_BUFFER_ALIGNMENT_EXTENSION_NAME") = py::cast(vk::EXTTexelBufferAlignmentExtensionName);

    m_vk.attr("EXT_TEXEL_BUFFER_ALIGNMENT_SPEC_VERSION") = py::cast(vk::EXTTexelBufferAlignmentSpecVersion);

    m_vk.attr("QCOM_RENDER_PASS_TRANSFORM_EXTENSION_NAME") = py::cast(vk::QCOMRenderPassTransformExtensionName);

    m_vk.attr("QCOM_RENDER_PASS_TRANSFORM_SPEC_VERSION") = py::cast(vk::QCOMRenderPassTransformSpecVersion);

    m_vk.attr("EXT_DEPTH_BIAS_CONTROL_EXTENSION_NAME") = py::cast(vk::EXTDepthBiasControlExtensionName);

    m_vk.attr("EXT_DEPTH_BIAS_CONTROL_SPEC_VERSION") = py::cast(vk::EXTDepthBiasControlSpecVersion);

    m_vk.attr("EXT_DEVICE_MEMORY_REPORT_EXTENSION_NAME") = py::cast(vk::EXTDeviceMemoryReportExtensionName);

    m_vk.attr("EXT_DEVICE_MEMORY_REPORT_SPEC_VERSION") = py::cast(vk::EXTDeviceMemoryReportSpecVersion);

    m_vk.attr("EXT_ACQUIRE_DRM_DISPLAY_EXTENSION_NAME") = py::cast(vk::EXTAcquireDrmDisplayExtensionName);

    m_vk.attr("EXT_ACQUIRE_DRM_DISPLAY_SPEC_VERSION") = py::cast(vk::EXTAcquireDrmDisplaySpecVersion);

    m_vk.attr("EXT_ROBUSTNESS_2_EXTENSION_NAME") = py::cast(vk::EXTRobustness2ExtensionName);

    m_vk.attr("EXT_ROBUSTNESS_2_SPEC_VERSION") = py::cast(vk::EXTRobustness2SpecVersion);

    m_vk.attr("EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME") = py::cast(vk::EXTCustomBorderColorExtensionName);

    m_vk.attr("EXT_CUSTOM_BORDER_COLOR_SPEC_VERSION") = py::cast(vk::EXTCustomBorderColorSpecVersion);

    m_vk.attr("GOOGLE_USER_TYPE_EXTENSION_NAME") = py::cast(vk::GOOGLEUserTypeExtensionName);

    m_vk.attr("GOOGLE_USER_TYPE_SPEC_VERSION") = py::cast(vk::GOOGLEUserTypeSpecVersion);

    m_vk.attr("KHR_PIPELINE_LIBRARY_EXTENSION_NAME") = py::cast(vk::KHRPipelineLibraryExtensionName);

    m_vk.attr("KHR_PIPELINE_LIBRARY_SPEC_VERSION") = py::cast(vk::KHRPipelineLibrarySpecVersion);

    m_vk.attr("NV_PRESENT_BARRIER_EXTENSION_NAME") = py::cast(vk::NVPresentBarrierExtensionName);

    m_vk.attr("NV_PRESENT_BARRIER_SPEC_VERSION") = py::cast(vk::NVPresentBarrierSpecVersion);

    m_vk.attr("KHR_SHADER_NON_SEMANTIC_INFO_EXTENSION_NAME") = py::cast(vk::KHRShaderNonSemanticInfoExtensionName);

    m_vk.attr("KHR_SHADER_NON_SEMANTIC_INFO_SPEC_VERSION") = py::cast(vk::KHRShaderNonSemanticInfoSpecVersion);

    m_vk.attr("KHR_PRESENT_ID_EXTENSION_NAME") = py::cast(vk::KHRPresentIdExtensionName);

    m_vk.attr("KHR_PRESENT_ID_SPEC_VERSION") = py::cast(vk::KHRPresentIdSpecVersion);

    m_vk.attr("EXT_PRIVATE_DATA_EXTENSION_NAME") = py::cast(vk::EXTPrivateDataExtensionName);

    m_vk.attr("EXT_PRIVATE_DATA_SPEC_VERSION") = py::cast(vk::EXTPrivateDataSpecVersion);

    m_vk.attr("EXT_PIPELINE_CREATION_CACHE_CONTROL_EXTENSION_NAME") = py::cast(vk::EXTPipelineCreationCacheControlExtensionName);

    m_vk.attr("EXT_PIPELINE_CREATION_CACHE_CONTROL_SPEC_VERSION") = py::cast(vk::EXTPipelineCreationCacheControlSpecVersion);

    m_vk.attr("KHR_VIDEO_ENCODE_QUEUE_EXTENSION_NAME") = py::cast(vk::KHRVideoEncodeQueueExtensionName);

    m_vk.attr("KHR_VIDEO_ENCODE_QUEUE_SPEC_VERSION") = py::cast(vk::KHRVideoEncodeQueueSpecVersion);

    m_vk.attr("NV_DEVICE_DIAGNOSTICS_CONFIG_EXTENSION_NAME") = py::cast(vk::NVDeviceDiagnosticsConfigExtensionName);

    m_vk.attr("NV_DEVICE_DIAGNOSTICS_CONFIG_SPEC_VERSION") = py::cast(vk::NVDeviceDiagnosticsConfigSpecVersion);

    m_vk.attr("QCOM_RENDER_PASS_STORE_OPS_EXTENSION_NAME") = py::cast(vk::QCOMRenderPassStoreOpsExtensionName);

    m_vk.attr("QCOM_RENDER_PASS_STORE_OPS_SPEC_VERSION") = py::cast(vk::QCOMRenderPassStoreOpsSpecVersion);

    m_vk.attr("NV_LOW_LATENCY_EXTENSION_NAME") = py::cast(vk::NVLowLatencyExtensionName);

    m_vk.attr("NV_LOW_LATENCY_SPEC_VERSION") = py::cast(vk::NVLowLatencySpecVersion);

    m_vk.attr("KHR_SYNCHRONIZATION_2_EXTENSION_NAME") = py::cast(vk::KHRSynchronization2ExtensionName);

    m_vk.attr("KHR_SYNCHRONIZATION_2_SPEC_VERSION") = py::cast(vk::KHRSynchronization2SpecVersion);

    m_vk.attr("EXT_DESCRIPTOR_BUFFER_EXTENSION_NAME") = py::cast(vk::EXTDescriptorBufferExtensionName);

    m_vk.attr("EXT_DESCRIPTOR_BUFFER_SPEC_VERSION") = py::cast(vk::EXTDescriptorBufferSpecVersion);

    m_vk.attr("EXT_GRAPHICS_PIPELINE_LIBRARY_EXTENSION_NAME") = py::cast(vk::EXTGraphicsPipelineLibraryExtensionName);

    m_vk.attr("EXT_GRAPHICS_PIPELINE_LIBRARY_SPEC_VERSION") = py::cast(vk::EXTGraphicsPipelineLibrarySpecVersion);

    m_vk.attr("AMD_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_EXTENSION_NAME") = py::cast(vk::AMDShaderEarlyAndLateFragmentTestsExtensionName);

    m_vk.attr("AMD_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_SPEC_VERSION") = py::cast(vk::AMDShaderEarlyAndLateFragmentTestsSpecVersion);

    m_vk.attr("KHR_FRAGMENT_SHADER_BARYCENTRIC_EXTENSION_NAME") = py::cast(vk::KHRFragmentShaderBarycentricExtensionName);

    m_vk.attr("KHR_FRAGMENT_SHADER_BARYCENTRIC_SPEC_VERSION") = py::cast(vk::KHRFragmentShaderBarycentricSpecVersion);

    m_vk.attr("KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_EXTENSION_NAME") = py::cast(vk::KHRShaderSubgroupUniformControlFlowExtensionName);

    m_vk.attr("KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_SPEC_VERSION") = py::cast(vk::KHRShaderSubgroupUniformControlFlowSpecVersion);

    m_vk.attr("KHR_ZERO_INITIALIZE_WORKGROUP_MEMORY_EXTENSION_NAME") = py::cast(vk::KHRZeroInitializeWorkgroupMemoryExtensionName);

    m_vk.attr("KHR_ZERO_INITIALIZE_WORKGROUP_MEMORY_SPEC_VERSION") = py::cast(vk::KHRZeroInitializeWorkgroupMemorySpecVersion);

    m_vk.attr("NV_FRAGMENT_SHADING_RATE_ENUMS_EXTENSION_NAME") = py::cast(vk::NVFragmentShadingRateEnumsExtensionName);

    m_vk.attr("NV_FRAGMENT_SHADING_RATE_ENUMS_SPEC_VERSION") = py::cast(vk::NVFragmentShadingRateEnumsSpecVersion);

    m_vk.attr("NV_RAY_TRACING_MOTION_BLUR_EXTENSION_NAME") = py::cast(vk::NVRayTracingMotionBlurExtensionName);

    m_vk.attr("NV_RAY_TRACING_MOTION_BLUR_SPEC_VERSION") = py::cast(vk::NVRayTracingMotionBlurSpecVersion);

    m_vk.attr("EXT_MESH_SHADER_EXTENSION_NAME") = py::cast(vk::EXTMeshShaderExtensionName);

    m_vk.attr("EXT_MESH_SHADER_SPEC_VERSION") = py::cast(vk::EXTMeshShaderSpecVersion);

    m_vk.attr("EXT_YCBCR_2_PLANE_444_FORMATS_EXTENSION_NAME") = py::cast(vk::EXTYcbcr2Plane444FormatsExtensionName);

    m_vk.attr("EXT_YCBCR_2_PLANE_444_FORMATS_SPEC_VERSION") = py::cast(vk::EXTYcbcr2Plane444FormatsSpecVersion);

    m_vk.attr("EXT_FRAGMENT_DENSITY_MAP_2_EXTENSION_NAME") = py::cast(vk::EXTFragmentDensityMap2ExtensionName);

    m_vk.attr("EXT_FRAGMENT_DENSITY_MAP_2_SPEC_VERSION") = py::cast(vk::EXTFragmentDensityMap2SpecVersion);

    m_vk.attr("QCOM_ROTATED_COPY_COMMANDS_EXTENSION_NAME") = py::cast(vk::QCOMRotatedCopyCommandsExtensionName);

    m_vk.attr("QCOM_ROTATED_COPY_COMMANDS_SPEC_VERSION") = py::cast(vk::QCOMRotatedCopyCommandsSpecVersion);

    m_vk.attr("EXT_IMAGE_ROBUSTNESS_EXTENSION_NAME") = py::cast(vk::EXTImageRobustnessExtensionName);

    m_vk.attr("EXT_IMAGE_ROBUSTNESS_SPEC_VERSION") = py::cast(vk::EXTImageRobustnessSpecVersion);

    m_vk.attr("KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_EXTENSION_NAME") = py::cast(vk::KHRWorkgroupMemoryExplicitLayoutExtensionName);

    m_vk.attr("KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_SPEC_VERSION") = py::cast(vk::KHRWorkgroupMemoryExplicitLayoutSpecVersion);

    m_vk.attr("KHR_COPY_COMMANDS_2_EXTENSION_NAME") = py::cast(vk::KHRCopyCommands2ExtensionName);

    m_vk.attr("KHR_COPY_COMMANDS_2_SPEC_VERSION") = py::cast(vk::KHRCopyCommands2SpecVersion);

    m_vk.attr("EXT_IMAGE_COMPRESSION_CONTROL_EXTENSION_NAME") = py::cast(vk::EXTImageCompressionControlExtensionName);

    m_vk.attr("EXT_IMAGE_COMPRESSION_CONTROL_SPEC_VERSION") = py::cast(vk::EXTImageCompressionControlSpecVersion);

    m_vk.attr("EXT_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_EXTENSION_NAME") = py::cast(vk::EXTAttachmentFeedbackLoopLayoutExtensionName);

    m_vk.attr("EXT_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_SPEC_VERSION") = py::cast(vk::EXTAttachmentFeedbackLoopLayoutSpecVersion);

    m_vk.attr("EXT4444_FORMATS_EXTENSION_NAME") = py::cast(vk::EXT4444FormatsExtensionName);

    m_vk.attr("EXT4444_FORMATS_SPEC_VERSION") = py::cast(vk::EXT4444FormatsSpecVersion);

    m_vk.attr("EXT_DEVICE_FAULT_EXTENSION_NAME") = py::cast(vk::EXTDeviceFaultExtensionName);

    m_vk.attr("EXT_DEVICE_FAULT_SPEC_VERSION") = py::cast(vk::EXTDeviceFaultSpecVersion);

    m_vk.attr("ARM_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXTENSION_NAME") = py::cast(vk::ARMRasterizationOrderAttachmentAccessExtensionName);

    m_vk.attr("ARM_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_SPEC_VERSION") = py::cast(vk::ARMRasterizationOrderAttachmentAccessSpecVersion);

    m_vk.attr("EXT_RGBA_10X6_FORMATS_EXTENSION_NAME") = py::cast(vk::EXTRgba10X6FormatsExtensionName);

    m_vk.attr("EXT_RGBA_10X6_FORMATS_SPEC_VERSION") = py::cast(vk::EXTRgba10X6FormatsSpecVersion);

    m_vk.attr("VALVE_MUTABLE_DESCRIPTOR_TYPE_EXTENSION_NAME") = py::cast(vk::VALVEMutableDescriptorTypeExtensionName);

    m_vk.attr("VALVE_MUTABLE_DESCRIPTOR_TYPE_SPEC_VERSION") = py::cast(vk::VALVEMutableDescriptorTypeSpecVersion);

    m_vk.attr("EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME") = py::cast(vk::EXTVertexInputDynamicStateExtensionName);

    m_vk.attr("EXT_VERTEX_INPUT_DYNAMIC_STATE_SPEC_VERSION") = py::cast(vk::EXTVertexInputDynamicStateSpecVersion);

    m_vk.attr("EXT_PHYSICAL_DEVICE_DRM_EXTENSION_NAME") = py::cast(vk::EXTPhysicalDeviceDrmExtensionName);

    m_vk.attr("EXT_PHYSICAL_DEVICE_DRM_SPEC_VERSION") = py::cast(vk::EXTPhysicalDeviceDrmSpecVersion);

    m_vk.attr("EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME") = py::cast(vk::EXTDeviceAddressBindingReportExtensionName);

    m_vk.attr("EXT_DEVICE_ADDRESS_BINDING_REPORT_SPEC_VERSION") = py::cast(vk::EXTDeviceAddressBindingReportSpecVersion);

    m_vk.attr("EXT_DEPTH_CLIP_CONTROL_EXTENSION_NAME") = py::cast(vk::EXTDepthClipControlExtensionName);

    m_vk.attr("EXT_DEPTH_CLIP_CONTROL_SPEC_VERSION") = py::cast(vk::EXTDepthClipControlSpecVersion);

    m_vk.attr("EXT_PRIMITIVE_TOPOLOGY_LIST_RESTART_EXTENSION_NAME") = py::cast(vk::EXTPrimitiveTopologyListRestartExtensionName);

    m_vk.attr("EXT_PRIMITIVE_TOPOLOGY_LIST_RESTART_SPEC_VERSION") = py::cast(vk::EXTPrimitiveTopologyListRestartSpecVersion);

    m_vk.attr("KHR_FORMAT_FEATURE_FLAGS_2_EXTENSION_NAME") = py::cast(vk::KHRFormatFeatureFlags2ExtensionName);

    m_vk.attr("KHR_FORMAT_FEATURE_FLAGS_2_SPEC_VERSION") = py::cast(vk::KHRFormatFeatureFlags2SpecVersion);

    m_vk.attr("HUAWEI_SUBPASS_SHADING_EXTENSION_NAME") = py::cast(vk::HUAWEISubpassShadingExtensionName);

    m_vk.attr("HUAWEI_SUBPASS_SHADING_SPEC_VERSION") = py::cast(vk::HUAWEISubpassShadingSpecVersion);

    m_vk.attr("HUAWEI_INVOCATION_MASK_EXTENSION_NAME") = py::cast(vk::HUAWEIInvocationMaskExtensionName);

    m_vk.attr("HUAWEI_INVOCATION_MASK_SPEC_VERSION") = py::cast(vk::HUAWEIInvocationMaskSpecVersion);

    m_vk.attr("NV_EXTERNAL_MEMORY_RDMA_EXTENSION_NAME") = py::cast(vk::NVExternalMemoryRdmaExtensionName);

    m_vk.attr("NV_EXTERNAL_MEMORY_RDMA_SPEC_VERSION") = py::cast(vk::NVExternalMemoryRdmaSpecVersion);

    m_vk.attr("EXT_PIPELINE_PROPERTIES_EXTENSION_NAME") = py::cast(vk::EXTPipelinePropertiesExtensionName);

    m_vk.attr("EXT_PIPELINE_PROPERTIES_SPEC_VERSION") = py::cast(vk::EXTPipelinePropertiesSpecVersion);

    m_vk.attr("EXT_FRAME_BOUNDARY_EXTENSION_NAME") = py::cast(vk::EXTFrameBoundaryExtensionName);

    m_vk.attr("EXT_FRAME_BOUNDARY_SPEC_VERSION") = py::cast(vk::EXTFrameBoundarySpecVersion);

    m_vk.attr("EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_EXTENSION_NAME") = py::cast(vk::EXTMultisampledRenderToSingleSampledExtensionName);

    m_vk.attr("EXT_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_SPEC_VERSION") = py::cast(vk::EXTMultisampledRenderToSingleSampledSpecVersion);

    m_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_2_EXTENSION_NAME") = py::cast(vk::EXTExtendedDynamicState2ExtensionName);

    m_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_2_SPEC_VERSION") = py::cast(vk::EXTExtendedDynamicState2SpecVersion);

    m_vk.attr("EXT_COLOR_WRITE_ENABLE_EXTENSION_NAME") = py::cast(vk::EXTColorWriteEnableExtensionName);

    m_vk.attr("EXT_COLOR_WRITE_ENABLE_SPEC_VERSION") = py::cast(vk::EXTColorWriteEnableSpecVersion);

    m_vk.attr("EXT_PRIMITIVES_GENERATED_QUERY_EXTENSION_NAME") = py::cast(vk::EXTPrimitivesGeneratedQueryExtensionName);

    m_vk.attr("EXT_PRIMITIVES_GENERATED_QUERY_SPEC_VERSION") = py::cast(vk::EXTPrimitivesGeneratedQuerySpecVersion);

    m_vk.attr("KHR_RAY_TRACING_MAINTENANCE_1_EXTENSION_NAME") = py::cast(vk::KHRRayTracingMaintenance1ExtensionName);

    m_vk.attr("KHR_RAY_TRACING_MAINTENANCE_1_SPEC_VERSION") = py::cast(vk::KHRRayTracingMaintenance1SpecVersion);

    m_vk.attr("EXT_GLOBAL_PRIORITY_QUERY_EXTENSION_NAME") = py::cast(vk::EXTGlobalPriorityQueryExtensionName);

    m_vk.attr("EXT_GLOBAL_PRIORITY_QUERY_SPEC_VERSION") = py::cast(vk::EXTGlobalPriorityQuerySpecVersion);

    m_vk.attr("MAX_GLOBAL_PRIORITY_SIZE_EXT") = py::cast(vk::MaxGlobalPrioritySizeEXT);

    m_vk.attr("EXT_IMAGE_VIEW_MIN_LOD_EXTENSION_NAME") = py::cast(vk::EXTImageViewMinLodExtensionName);

    m_vk.attr("EXT_IMAGE_VIEW_MIN_LOD_SPEC_VERSION") = py::cast(vk::EXTImageViewMinLodSpecVersion);

    m_vk.attr("EXT_MULTI_DRAW_EXTENSION_NAME") = py::cast(vk::EXTMultiDrawExtensionName);

    m_vk.attr("EXT_MULTI_DRAW_SPEC_VERSION") = py::cast(vk::EXTMultiDrawSpecVersion);

    m_vk.attr("EXT_IMAGE_2D_VIEW_OF_3D_EXTENSION_NAME") = py::cast(vk::EXTImage2DViewOf3DExtensionName);

    m_vk.attr("EXT_IMAGE_2D_VIEW_OF_3D_SPEC_VERSION") = py::cast(vk::EXTImage2DViewOf3DSpecVersion);

    m_vk.attr("KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME") = py::cast(vk::KHRPortabilityEnumerationExtensionName);

    m_vk.attr("KHR_PORTABILITY_ENUMERATION_SPEC_VERSION") = py::cast(vk::KHRPortabilityEnumerationSpecVersion);

    m_vk.attr("EXT_SHADER_TILE_IMAGE_EXTENSION_NAME") = py::cast(vk::EXTShaderTileImageExtensionName);

    m_vk.attr("EXT_SHADER_TILE_IMAGE_SPEC_VERSION") = py::cast(vk::EXTShaderTileImageSpecVersion);

    m_vk.attr("EXT_OPACITY_MICROMAP_EXTENSION_NAME") = py::cast(vk::EXTOpacityMicromapExtensionName);

    m_vk.attr("EXT_OPACITY_MICROMAP_SPEC_VERSION") = py::cast(vk::EXTOpacityMicromapSpecVersion);

    m_vk.attr("EXT_LOAD_STORE_OP_NONE_EXTENSION_NAME") = py::cast(vk::EXTLoadStoreOpNoneExtensionName);

    m_vk.attr("EXT_LOAD_STORE_OP_NONE_SPEC_VERSION") = py::cast(vk::EXTLoadStoreOpNoneSpecVersion);

    m_vk.attr("HUAWEI_CLUSTER_CULLING_SHADER_EXTENSION_NAME") = py::cast(vk::HUAWEIClusterCullingShaderExtensionName);

    m_vk.attr("HUAWEI_CLUSTER_CULLING_SHADER_SPEC_VERSION") = py::cast(vk::HUAWEIClusterCullingShaderSpecVersion);

    m_vk.attr("EXT_BORDER_COLOR_SWIZZLE_EXTENSION_NAME") = py::cast(vk::EXTBorderColorSwizzleExtensionName);

    m_vk.attr("EXT_BORDER_COLOR_SWIZZLE_SPEC_VERSION") = py::cast(vk::EXTBorderColorSwizzleSpecVersion);

    m_vk.attr("EXT_PAGEABLE_DEVICE_LOCAL_MEMORY_EXTENSION_NAME") = py::cast(vk::EXTPageableDeviceLocalMemoryExtensionName);

    m_vk.attr("EXT_PAGEABLE_DEVICE_LOCAL_MEMORY_SPEC_VERSION") = py::cast(vk::EXTPageableDeviceLocalMemorySpecVersion);

    m_vk.attr("KHR_MAINTENANCE_4_EXTENSION_NAME") = py::cast(vk::KHRMaintenance4ExtensionName);

    m_vk.attr("KHR_MAINTENANCE_4_SPEC_VERSION") = py::cast(vk::KHRMaintenance4SpecVersion);

    m_vk.attr("ARM_SHADER_CORE_PROPERTIES_EXTENSION_NAME") = py::cast(vk::ARMShaderCorePropertiesExtensionName);

    m_vk.attr("ARM_SHADER_CORE_PROPERTIES_SPEC_VERSION") = py::cast(vk::ARMShaderCorePropertiesSpecVersion);

    m_vk.attr("ARM_SCHEDULING_CONTROLS_EXTENSION_NAME") = py::cast(vk::ARMSchedulingControlsExtensionName);

    m_vk.attr("ARM_SCHEDULING_CONTROLS_SPEC_VERSION") = py::cast(vk::ARMSchedulingControlsSpecVersion);

    m_vk.attr("EXT_IMAGE_SLICED_VIEW_OF_3D_EXTENSION_NAME") = py::cast(vk::EXTImageSlicedViewOf3DExtensionName);

    m_vk.attr("EXT_IMAGE_SLICED_VIEW_OF_3D_SPEC_VERSION") = py::cast(vk::EXTImageSlicedViewOf3DSpecVersion);

    m_vk.attr("REMAINING_3D_SLICES_EXT") = py::cast(vk::Remaining3DSlicesEXT);

    m_vk.attr("VALVE_DESCRIPTOR_SET_HOST_MAPPING_EXTENSION_NAME") = py::cast(vk::VALVEDescriptorSetHostMappingExtensionName);

    m_vk.attr("VALVE_DESCRIPTOR_SET_HOST_MAPPING_SPEC_VERSION") = py::cast(vk::VALVEDescriptorSetHostMappingSpecVersion);

    m_vk.attr("EXT_DEPTH_CLAMP_ZERO_ONE_EXTENSION_NAME") = py::cast(vk::EXTDepthClampZeroOneExtensionName);

    m_vk.attr("EXT_DEPTH_CLAMP_ZERO_ONE_SPEC_VERSION") = py::cast(vk::EXTDepthClampZeroOneSpecVersion);

    m_vk.attr("EXT_NON_SEAMLESS_CUBE_MAP_EXTENSION_NAME") = py::cast(vk::EXTNonSeamlessCubeMapExtensionName);

    m_vk.attr("EXT_NON_SEAMLESS_CUBE_MAP_SPEC_VERSION") = py::cast(vk::EXTNonSeamlessCubeMapSpecVersion);

    m_vk.attr("ARM_RENDER_PASS_STRIPED_EXTENSION_NAME") = py::cast(vk::ARMRenderPassStripedExtensionName);

    m_vk.attr("ARM_RENDER_PASS_STRIPED_SPEC_VERSION") = py::cast(vk::ARMRenderPassStripedSpecVersion);

    m_vk.attr("QCOM_FRAGMENT_DENSITY_MAP_OFFSET_EXTENSION_NAME") = py::cast(vk::QCOMFragmentDensityMapOffsetExtensionName);

    m_vk.attr("QCOM_FRAGMENT_DENSITY_MAP_OFFSET_SPEC_VERSION") = py::cast(vk::QCOMFragmentDensityMapOffsetSpecVersion);

    m_vk.attr("NV_COPY_MEMORY_INDIRECT_EXTENSION_NAME") = py::cast(vk::NVCopyMemoryIndirectExtensionName);

    m_vk.attr("NV_COPY_MEMORY_INDIRECT_SPEC_VERSION") = py::cast(vk::NVCopyMemoryIndirectSpecVersion);

    m_vk.attr("NV_MEMORY_DECOMPRESSION_EXTENSION_NAME") = py::cast(vk::NVMemoryDecompressionExtensionName);

    m_vk.attr("NV_MEMORY_DECOMPRESSION_SPEC_VERSION") = py::cast(vk::NVMemoryDecompressionSpecVersion);

    m_vk.attr("NV_DEVICE_GENERATED_COMMANDS_COMPUTE_EXTENSION_NAME") = py::cast(vk::NVDeviceGeneratedCommandsComputeExtensionName);

    m_vk.attr("NV_DEVICE_GENERATED_COMMANDS_COMPUTE_SPEC_VERSION") = py::cast(vk::NVDeviceGeneratedCommandsComputeSpecVersion);

    m_vk.attr("NV_LINEAR_COLOR_ATTACHMENT_EXTENSION_NAME") = py::cast(vk::NVLinearColorAttachmentExtensionName);

    m_vk.attr("NV_LINEAR_COLOR_ATTACHMENT_SPEC_VERSION") = py::cast(vk::NVLinearColorAttachmentSpecVersion);

    m_vk.attr("GOOGLE_SURFACELESS_QUERY_EXTENSION_NAME") = py::cast(vk::GOOGLESurfacelessQueryExtensionName);

    m_vk.attr("GOOGLE_SURFACELESS_QUERY_SPEC_VERSION") = py::cast(vk::GOOGLESurfacelessQuerySpecVersion);

    m_vk.attr("EXT_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_EXTENSION_NAME") = py::cast(vk::EXTImageCompressionControlSwapchainExtensionName);

    m_vk.attr("EXT_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_SPEC_VERSION") = py::cast(vk::EXTImageCompressionControlSwapchainSpecVersion);

    m_vk.attr("QCOM_IMAGE_PROCESSING_EXTENSION_NAME") = py::cast(vk::QCOMImageProcessingExtensionName);

    m_vk.attr("QCOM_IMAGE_PROCESSING_SPEC_VERSION") = py::cast(vk::QCOMImageProcessingSpecVersion);

    m_vk.attr("EXT_NESTED_COMMAND_BUFFER_EXTENSION_NAME") = py::cast(vk::EXTNestedCommandBufferExtensionName);

    m_vk.attr("EXT_NESTED_COMMAND_BUFFER_SPEC_VERSION") = py::cast(vk::EXTNestedCommandBufferSpecVersion);

    m_vk.attr("EXT_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXTENSION_NAME") = py::cast(vk::EXTExternalMemoryAcquireUnmodifiedExtensionName);

    m_vk.attr("EXT_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_SPEC_VERSION") = py::cast(vk::EXTExternalMemoryAcquireUnmodifiedSpecVersion);

    m_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_3_EXTENSION_NAME") = py::cast(vk::EXTExtendedDynamicState3ExtensionName);

    m_vk.attr("EXT_EXTENDED_DYNAMIC_STATE_3_SPEC_VERSION") = py::cast(vk::EXTExtendedDynamicState3SpecVersion);

    m_vk.attr("EXT_SUBPASS_MERGE_FEEDBACK_EXTENSION_NAME") = py::cast(vk::EXTSubpassMergeFeedbackExtensionName);

    m_vk.attr("EXT_SUBPASS_MERGE_FEEDBACK_SPEC_VERSION") = py::cast(vk::EXTSubpassMergeFeedbackSpecVersion);

    m_vk.attr("LUNARG_DIRECT_DRIVER_LOADING_EXTENSION_NAME") = py::cast(vk::LUNARGDirectDriverLoadingExtensionName);

    m_vk.attr("LUNARG_DIRECT_DRIVER_LOADING_SPEC_VERSION") = py::cast(vk::LUNARGDirectDriverLoadingSpecVersion);

    m_vk.attr("EXT_SHADER_MODULE_IDENTIFIER_EXTENSION_NAME") = py::cast(vk::EXTShaderModuleIdentifierExtensionName);

    m_vk.attr("EXT_SHADER_MODULE_IDENTIFIER_SPEC_VERSION") = py::cast(vk::EXTShaderModuleIdentifierSpecVersion);

    m_vk.attr("MAX_SHADER_MODULE_IDENTIFIER_SIZE_EXT") = py::cast(vk::MaxShaderModuleIdentifierSizeEXT);

    m_vk.attr("EXT_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_EXTENSION_NAME") = py::cast(vk::EXTRasterizationOrderAttachmentAccessExtensionName);

    m_vk.attr("EXT_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_SPEC_VERSION") = py::cast(vk::EXTRasterizationOrderAttachmentAccessSpecVersion);

    m_vk.attr("NV_OPTICAL_FLOW_EXTENSION_NAME") = py::cast(vk::NVOpticalFlowExtensionName);

    m_vk.attr("NV_OPTICAL_FLOW_SPEC_VERSION") = py::cast(vk::NVOpticalFlowSpecVersion);

    m_vk.attr("EXT_LEGACY_DITHERING_EXTENSION_NAME") = py::cast(vk::EXTLegacyDitheringExtensionName);

    m_vk.attr("EXT_LEGACY_DITHERING_SPEC_VERSION") = py::cast(vk::EXTLegacyDitheringSpecVersion);

    m_vk.attr("EXT_PIPELINE_PROTECTED_ACCESS_EXTENSION_NAME") = py::cast(vk::EXTPipelineProtectedAccessExtensionName);

    m_vk.attr("EXT_PIPELINE_PROTECTED_ACCESS_SPEC_VERSION") = py::cast(vk::EXTPipelineProtectedAccessSpecVersion);

    m_vk.attr("KHR_MAINTENANCE_5_EXTENSION_NAME") = py::cast(vk::KHRMaintenance5ExtensionName);

    m_vk.attr("KHR_MAINTENANCE_5_SPEC_VERSION") = py::cast(vk::KHRMaintenance5SpecVersion);

    m_vk.attr("KHR_RAY_TRACING_POSITION_FETCH_EXTENSION_NAME") = py::cast(vk::KHRRayTracingPositionFetchExtensionName);

    m_vk.attr("KHR_RAY_TRACING_POSITION_FETCH_SPEC_VERSION") = py::cast(vk::KHRRayTracingPositionFetchSpecVersion);

    m_vk.attr("EXT_SHADER_OBJECT_EXTENSION_NAME") = py::cast(vk::EXTShaderObjectExtensionName);

    m_vk.attr("EXT_SHADER_OBJECT_SPEC_VERSION") = py::cast(vk::EXTShaderObjectSpecVersion);

    m_vk.attr("QCOM_TILE_PROPERTIES_EXTENSION_NAME") = py::cast(vk::QCOMTilePropertiesExtensionName);

    m_vk.attr("QCOM_TILE_PROPERTIES_SPEC_VERSION") = py::cast(vk::QCOMTilePropertiesSpecVersion);

    m_vk.attr("SEC_AMIGO_PROFILING_EXTENSION_NAME") = py::cast(vk::SECAmigoProfilingExtensionName);

    m_vk.attr("SEC_AMIGO_PROFILING_SPEC_VERSION") = py::cast(vk::SECAmigoProfilingSpecVersion);

    m_vk.attr("QCOM_MULTIVIEW_PER_VIEW_VIEWPORTS_EXTENSION_NAME") = py::cast(vk::QCOMMultiviewPerViewViewportsExtensionName);

    m_vk.attr("QCOM_MULTIVIEW_PER_VIEW_VIEWPORTS_SPEC_VERSION") = py::cast(vk::QCOMMultiviewPerViewViewportsSpecVersion);

    m_vk.attr("NV_RAY_TRACING_INVOCATION_REORDER_EXTENSION_NAME") = py::cast(vk::NVRayTracingInvocationReorderExtensionName);

    m_vk.attr("NV_RAY_TRACING_INVOCATION_REORDER_SPEC_VERSION") = py::cast(vk::NVRayTracingInvocationReorderSpecVersion);

    m_vk.attr("NV_EXTENDED_SPARSE_ADDRESS_SPACE_EXTENSION_NAME") = py::cast(vk::NVExtendedSparseAddressSpaceExtensionName);

    m_vk.attr("NV_EXTENDED_SPARSE_ADDRESS_SPACE_SPEC_VERSION") = py::cast(vk::NVExtendedSparseAddressSpaceSpecVersion);

    m_vk.attr("EXT_MUTABLE_DESCRIPTOR_TYPE_EXTENSION_NAME") = py::cast(vk::EXTMutableDescriptorTypeExtensionName);

    m_vk.attr("EXT_MUTABLE_DESCRIPTOR_TYPE_SPEC_VERSION") = py::cast(vk::EXTMutableDescriptorTypeSpecVersion);

    m_vk.attr("EXT_LAYER_SETTINGS_EXTENSION_NAME") = py::cast(vk::EXTLayerSettingsExtensionName);

    m_vk.attr("EXT_LAYER_SETTINGS_SPEC_VERSION") = py::cast(vk::EXTLayerSettingsSpecVersion);

    m_vk.attr("ARM_SHADER_CORE_BUILTINS_EXTENSION_NAME") = py::cast(vk::ARMShaderCoreBuiltinsExtensionName);

    m_vk.attr("ARM_SHADER_CORE_BUILTINS_SPEC_VERSION") = py::cast(vk::ARMShaderCoreBuiltinsSpecVersion);

    m_vk.attr("EXT_PIPELINE_LIBRARY_GROUP_HANDLES_EXTENSION_NAME") = py::cast(vk::EXTPipelineLibraryGroupHandlesExtensionName);

    m_vk.attr("EXT_PIPELINE_LIBRARY_GROUP_HANDLES_SPEC_VERSION") = py::cast(vk::EXTPipelineLibraryGroupHandlesSpecVersion);

    m_vk.attr("EXT_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_EXTENSION_NAME") = py::cast(vk::EXTDynamicRenderingUnusedAttachmentsExtensionName);

    m_vk.attr("EXT_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_SPEC_VERSION") = py::cast(vk::EXTDynamicRenderingUnusedAttachmentsSpecVersion);

    m_vk.attr("NV_LOW_LATENCY_2_EXTENSION_NAME") = py::cast(vk::NVLowLatency2ExtensionName);

    m_vk.attr("NV_LOW_LATENCY_2_SPEC_VERSION") = py::cast(vk::NVLowLatency2SpecVersion);

    m_vk.attr("KHR_COOPERATIVE_MATRIX_EXTENSION_NAME") = py::cast(vk::KHRCooperativeMatrixExtensionName);

    m_vk.attr("KHR_COOPERATIVE_MATRIX_SPEC_VERSION") = py::cast(vk::KHRCooperativeMatrixSpecVersion);

    m_vk.attr("QCOM_MULTIVIEW_PER_VIEW_RENDER_AREAS_EXTENSION_NAME") = py::cast(vk::QCOMMultiviewPerViewRenderAreasExtensionName);

    m_vk.attr("QCOM_MULTIVIEW_PER_VIEW_RENDER_AREAS_SPEC_VERSION") = py::cast(vk::QCOMMultiviewPerViewRenderAreasSpecVersion);

    m_vk.attr("KHR_VIDEO_MAINTENANCE_1_EXTENSION_NAME") = py::cast(vk::KHRVideoMaintenance1ExtensionName);

    m_vk.attr("KHR_VIDEO_MAINTENANCE_1_SPEC_VERSION") = py::cast(vk::KHRVideoMaintenance1SpecVersion);

    m_vk.attr("NV_PER_STAGE_DESCRIPTOR_SET_EXTENSION_NAME") = py::cast(vk::NVPerStageDescriptorSetExtensionName);

    m_vk.attr("NV_PER_STAGE_DESCRIPTOR_SET_SPEC_VERSION") = py::cast(vk::NVPerStageDescriptorSetSpecVersion);

    m_vk.attr("QCOM_IMAGE_PROCESSING_2_EXTENSION_NAME") = py::cast(vk::QCOMImageProcessing2ExtensionName);

    m_vk.attr("QCOM_IMAGE_PROCESSING_2_SPEC_VERSION") = py::cast(vk::QCOMImageProcessing2SpecVersion);

    m_vk.attr("QCOM_FILTER_CUBIC_WEIGHTS_EXTENSION_NAME") = py::cast(vk::QCOMFilterCubicWeightsExtensionName);

    m_vk.attr("QCOM_FILTER_CUBIC_WEIGHTS_SPEC_VERSION") = py::cast(vk::QCOMFilterCubicWeightsSpecVersion);

    m_vk.attr("QCOM_YCBCR_DEGAMMA_EXTENSION_NAME") = py::cast(vk::QCOMYcbcrDegammaExtensionName);

    m_vk.attr("QCOM_YCBCR_DEGAMMA_SPEC_VERSION") = py::cast(vk::QCOMYcbcrDegammaSpecVersion);

    m_vk.attr("QCOM_FILTER_CUBIC_CLAMP_EXTENSION_NAME") = py::cast(vk::QCOMFilterCubicClampExtensionName);

    m_vk.attr("QCOM_FILTER_CUBIC_CLAMP_SPEC_VERSION") = py::cast(vk::QCOMFilterCubicClampSpecVersion);

    m_vk.attr("EXT_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_EXTENSION_NAME") = py::cast(vk::EXTAttachmentFeedbackLoopDynamicStateExtensionName);

    m_vk.attr("EXT_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_SPEC_VERSION") = py::cast(vk::EXTAttachmentFeedbackLoopDynamicStateSpecVersion);

    m_vk.attr("KHR_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME") = py::cast(vk::KHRVertexAttributeDivisorExtensionName);

    m_vk.attr("KHR_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION") = py::cast(vk::KHRVertexAttributeDivisorSpecVersion);

    m_vk.attr("MSFT_LAYERED_DRIVER_EXTENSION_NAME") = py::cast(vk::MSFTLayeredDriverExtensionName);

    m_vk.attr("MSFT_LAYERED_DRIVER_SPEC_VERSION") = py::cast(vk::MSFTLayeredDriverSpecVersion);

    m_vk.attr("KHR_CALIBRATED_TIMESTAMPS_EXTENSION_NAME") = py::cast(vk::KHRCalibratedTimestampsExtensionName);

    m_vk.attr("KHR_CALIBRATED_TIMESTAMPS_SPEC_VERSION") = py::cast(vk::KHRCalibratedTimestampsSpecVersion);

    m_vk.attr("KHR_MAINTENANCE_6_EXTENSION_NAME") = py::cast(vk::KHRMaintenance6ExtensionName);

    m_vk.attr("KHR_MAINTENANCE_6_SPEC_VERSION") = py::cast(vk::KHRMaintenance6SpecVersion);

    m_vk.attr("NV_DESCRIPTOR_POOL_OVERALLOCATION_EXTENSION_NAME") = py::cast(vk::NVDescriptorPoolOverallocationExtensionName);

    m_vk.attr("NV_DESCRIPTOR_POOL_OVERALLOCATION_SPEC_VERSION") = py::cast(vk::NVDescriptorPoolOverallocationSpecVersion);

    m_vk.attr("HEADER_VERSION") = py::cast(vk::HeaderVersion);

    m_vk.attr("API_VERSION") = py::cast(vk::ApiVersion);

    m_vk.attr("API_VERSION_10") = py::cast(vk::ApiVersion10);

    m_vk.attr("API_VERSION_11") = py::cast(vk::ApiVersion11);

    m_vk.attr("API_VERSION_12") = py::cast(vk::ApiVersion12);

    m_vk.attr("API_VERSION_13") = py::cast(vk::ApiVersion13);

    m_vk.attr("HEADER_VERSION_COMPLETE") = py::cast(vk::HeaderVersionComplete);
}
