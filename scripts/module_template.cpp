#include <cstdlib>
#include <cstring>
#include <list>

#define PYBIND11_DETAILED_ERROR_MESSAGES

#include <pybind11/pybind11.h>
//#include <pybind11/stl.h>
//#include <pybind11/stl_bind.h>
#include <vulkan/vulkan.hpp>

namespace py = pybind11;


//namespace PYBIND11_NAMESPACE { namespace detail {
//    template <>
//    struct type_caster<const char *> {
//    public:
//        PYBIND11_TYPE_CASTER(const char *, const_name("str"));
//
//        bool load(handle src, bool convert) {
//            type_caster<const std::string> caster;
//            bool retval = caster.load(src, convert);
//            const std::string intermediate(caster);
//            py::print("loading...", intermediate);
//            value = intermediate.c_str();
//            return retval;
//        }
//
//        static handle cast(const char * src, return_value_policy policy, handle parent) {
//            const std::string intermediate(src);
//            py::print("casting...", intermediate);
//            return type_caster<const std::string>::cast(intermediate, policy, parent);
//        }
//    };
//}}


class _Memory {
public:
    const void * _allocate(const void * pointer, std::size_t size) {
        void * memory_pointer(std::malloc(size));
        _memory_pointers.push_back(memory_pointer);
        std::memcpy(memory_pointer, pointer, size);
        return const_cast<const void *>(memory_pointer);
    }

    void _clear() {
        for (void * memory_pointer : _memory_pointers) {
            std::free(memory_pointer);
        }
    }

    //template <typename T>
    //static const T * allocate_object(const T & object) {
    //    return allocate(&object, sizeof(T));
    //}

    const char * allocate_string(const py::str & str) {
        const std::string std_str(str.cast<std::string>());
        return static_cast<const char *>(_allocate(std_str.c_str(), std_str.length() + 1));  // Include the null-terminating character.
    }

    const void * allocate_extension_struct(const py::object & object) {
        //vk::StructureType s_type(object.attr("s_type"));
        if (object.is_none()) {
            return nullptr;
        }
        void * pointer = nullptr;
        std::size_t size = 0;
        switch (object.attr("s_type").cast<vk::StructureType>()) {
            case vk::StructureType::eApplicationInfo:
                pointer = &object.cast<vk::ApplicationInfo>();
                size = sizeof(vk::ApplicationInfo);
                break;
        }
        return _allocate(pointer, size);
    }

    const py::str wrap_string(const char * str_ptr) {
        const std::string std_str(str_ptr);
        return py::cast(std_str);
    }

    const py::object wrap_extension_struct(const void * object_ptr) {
        if (object_ptr == nullptr) {
            return py::none();
        }
        py::object object = py::none();
        // The `sType` field is always at the beginning.
        switch (*reinterpret_cast<const vk::StructureType *>(object_ptr)) {
            case vk::StructureType::eApplicationInfo:
                object = py::cast(*reinterpret_cast<const vk::ApplicationInfo *>(object_ptr));
                break;
        }
        return object;
    }

private:
    std::list<void *> _memory_pointers;
};


_Memory _MEMORY;


//template <typename>
//class StringPool
//static std::unordered_map<void *, std::vector<std::string>> string_cache


//template <typename SrcT, typename DstT>
//static inline DstT _cast(SrcT & value) = delete;

//template <>
//static inline const char * _cast<const std::string, const char *>(const std::string & value) {
//    return value.c_str();
//}

//template <>
//static inline const void * _cast<const py::object, const void *>(const py::object & value) {
//    return value.cast<const void *>();
//}


//template <typename StructT>
//class StructWrapper {
//private:
//    std::unique_ptr<StructT> m_struct;
//};


//template<>
//class StructWrapper<vk::ApplicationInfo> {
//public:
//    StructWrapper(
//        std::string application_name_,
//        uint32_t application_version_,
//        std::string engine_name_,
//        uint32_t engine_version_,
//        uint32_t api_version_,
//        py::object next_
//    ):
//        m_struct(new vk::ApplicationInfo(
//            _wrapper_cast<const std::string, const char *>(application_name_),
//            application_version_,
//            _wrapper_cast<const std::string, const char *>(engine_name_),
//            engine_version_,
//            api_version_,
//            _wrapper_cast<const py::object, const void *>(next_)
//        )),
//        em_application_name(&application_name_),
//        em_engine_name(&engine_name_),
//        em_next(&next_)
//    {}

//    std::string getApplicationName() const {
//        return *em_application_name;
//    }

//    void setPApplicationName(std::string application_name_) {
//        m_struct->setPApplicationName(_wrapper_cast<const std::string, const char *>(application_name_));
//        em_application_name.reset(&application_name_);
//    }

//    uint32_t getPApplicationVersion() const {
//        return m_struct->applicationVersion;
//    }

//    void setApplicationVersion(uint32_t application_version_) {
//        m_struct->setApplicationVersion(application_version_);
//    }

//    py::object getPNext() const {
//        return *em_next;
//    }

//    void setPNext(py::object next_) {
//        m_struct->setPNext(_wrapper_cast<const py::object, const void *>(next_));
//        em_next.reset(&next_);
//    }

//private:
//    vk::ApplicationInfo m_struct;
//    std::string em_application_name;
//    std::string em_engine_name;
//    py::object em_next;
//};


//inline const py::str _converter_CString_PyString(const char * value) {
//    std::string intermediate(value);
//    py::print("casting...", intermediate);
//    //return result;
//    return py::cast(intermediate);
//}


//inline const void * _converter_PyObject_VoidPtr(const py::object & value) {
//    //return reinterpret_cast<const void *>(&value);
//    return value.cast<const void *>();
//}


//inline const py::object _converter_VoidPtr_PyObject(const void * value) {
//    //return *reinterpret_cast<const py::object *>(value);
//    return py::cast(value);
//}


//inline VULKAN_HPP_NAMESPACE::ArrayProxyNoTemporaries<const char * const> const _converter_StringVector_ArrayProxyNoTemporaries(const std::vector<std::string> & value) {
//    VULKAN_HPP_NAMESPACE::ArrayProxyNoTemporaries<const char * const> result(
//        static_cast<uint32_t>(value.size()),
//        reinterpret_cast<const char * const *>(value.data())
//    );
//    return result;
//}


//PYBIND11_MAKE_OPAQUE(std::vector<std::string>);

PYBIND11_MODULE(pyvulkan, m) {
    auto _py_atexit = py::module_::import("atexit");
    _py_atexit.attr("register")(py::cpp_function([]() {
        _MEMORY._clear();
    }));

    //py::bind_vector<std::vector<std::string>>(m, "_string_vector");
    py::module n_vk = m.def_submodule("vk");
    py::module n_vk_raii = n_vk.def_submodule("raii");

    py::enum_<vk::InstanceCreateFlagBits> e_vk_InstanceCreateFlagBits(n_vk, "InstanceCreateFlagBits");
    e_vk_InstanceCreateFlagBits.value("ENUMERATE_PORTABILITY_KHR", vk::InstanceCreateFlagBits::eEnumeratePortabilityKHR);

    py::class_<vk::InstanceCreateFlags> e_vk_InstanceCreateFlags(n_vk, "InstanceCreateFlags");

    py::enum_<vk::StructureType> e_vk_StructureType(n_vk, "StructureType");
    e_vk_StructureType.value("ApplicationInfo", vk::StructureType::eApplicationInfo);
    e_vk_StructureType.value("InstanceCreateInfo", vk::StructureType::eInstanceCreateInfo);
    e_vk_StructureType.value("DeviceQueueCreateInfo", vk::StructureType::eDeviceQueueCreateInfo);
    e_vk_StructureType.value("DeviceCreateInfo", vk::StructureType::eDeviceCreateInfo);
    e_vk_StructureType.value("SubmitInfo", vk::StructureType::eSubmitInfo);
    e_vk_StructureType.value("MemoryAllocateInfo", vk::StructureType::eMemoryAllocateInfo);
    e_vk_StructureType.value("MappedMemoryRange", vk::StructureType::eMappedMemoryRange);
    e_vk_StructureType.value("BindSparseInfo", vk::StructureType::eBindSparseInfo);
    e_vk_StructureType.value("FenceCreateInfo", vk::StructureType::eFenceCreateInfo);
    e_vk_StructureType.value("SemaphoreCreateInfo", vk::StructureType::eSemaphoreCreateInfo);
    e_vk_StructureType.value("EventCreateInfo", vk::StructureType::eEventCreateInfo);
    e_vk_StructureType.value("QueryPoolCreateInfo", vk::StructureType::eQueryPoolCreateInfo);
    e_vk_StructureType.value("BufferCreateInfo", vk::StructureType::eBufferCreateInfo);
    e_vk_StructureType.value("BufferViewCreateInfo", vk::StructureType::eBufferViewCreateInfo);
    e_vk_StructureType.value("ImageCreateInfo", vk::StructureType::eImageCreateInfo);
    e_vk_StructureType.value("ImageViewCreateInfo", vk::StructureType::eImageViewCreateInfo);
    e_vk_StructureType.value("ShaderModuleCreateInfo", vk::StructureType::eShaderModuleCreateInfo);
    e_vk_StructureType.value("PipelineCacheCreateInfo", vk::StructureType::ePipelineCacheCreateInfo);
    e_vk_StructureType.value("PipelineShaderStageCreateInfo", vk::StructureType::ePipelineShaderStageCreateInfo);
    e_vk_StructureType.value("PipelineVertexInputStateCreateInfo", vk::StructureType::ePipelineVertexInputStateCreateInfo);
    e_vk_StructureType.value("PipelineInputAssemblyStateCreateInfo", vk::StructureType::ePipelineInputAssemblyStateCreateInfo);
    e_vk_StructureType.value("PipelineTessellationStateCreateInfo", vk::StructureType::ePipelineTessellationStateCreateInfo);
    e_vk_StructureType.value("PipelineViewportStateCreateInfo", vk::StructureType::ePipelineViewportStateCreateInfo);
    e_vk_StructureType.value("PipelineRasterizationStateCreateInfo", vk::StructureType::ePipelineRasterizationStateCreateInfo);
    e_vk_StructureType.value("PipelineMultisampleStateCreateInfo", vk::StructureType::ePipelineMultisampleStateCreateInfo);
    e_vk_StructureType.value("PipelineDepthStencilStateCreateInfo", vk::StructureType::ePipelineDepthStencilStateCreateInfo);
    e_vk_StructureType.value("PipelineColorBlendStateCreateInfo", vk::StructureType::ePipelineColorBlendStateCreateInfo);
    e_vk_StructureType.value("PipelineDynamicStateCreateInfo", vk::StructureType::ePipelineDynamicStateCreateInfo);
    e_vk_StructureType.value("GraphicsPipelineCreateInfo", vk::StructureType::eGraphicsPipelineCreateInfo);
    e_vk_StructureType.value("ComputePipelineCreateInfo", vk::StructureType::eComputePipelineCreateInfo);
    e_vk_StructureType.value("PipelineLayoutCreateInfo", vk::StructureType::ePipelineLayoutCreateInfo);
    e_vk_StructureType.value("SamplerCreateInfo", vk::StructureType::eSamplerCreateInfo);
    e_vk_StructureType.value("DescriptorSetLayoutCreateInfo", vk::StructureType::eDescriptorSetLayoutCreateInfo);
    e_vk_StructureType.value("DescriptorPoolCreateInfo", vk::StructureType::eDescriptorPoolCreateInfo);
    e_vk_StructureType.value("DescriptorSetAllocateInfo", vk::StructureType::eDescriptorSetAllocateInfo);
    e_vk_StructureType.value("WriteDescriptorSet", vk::StructureType::eWriteDescriptorSet);
    e_vk_StructureType.value("CopyDescriptorSet", vk::StructureType::eCopyDescriptorSet);
    e_vk_StructureType.value("FramebufferCreateInfo", vk::StructureType::eFramebufferCreateInfo);
    e_vk_StructureType.value("RenderPassCreateInfo", vk::StructureType::eRenderPassCreateInfo);
    e_vk_StructureType.value("CommandPoolCreateInfo", vk::StructureType::eCommandPoolCreateInfo);
    e_vk_StructureType.value("CommandBufferAllocateInfo", vk::StructureType::eCommandBufferAllocateInfo);
    e_vk_StructureType.value("CommandBufferInheritanceInfo", vk::StructureType::eCommandBufferInheritanceInfo);
    e_vk_StructureType.value("CommandBufferBeginInfo", vk::StructureType::eCommandBufferBeginInfo);
    e_vk_StructureType.value("RenderPassBeginInfo", vk::StructureType::eRenderPassBeginInfo);
    e_vk_StructureType.value("BufferMemoryBarrier", vk::StructureType::eBufferMemoryBarrier);
    e_vk_StructureType.value("ImageMemoryBarrier", vk::StructureType::eImageMemoryBarrier);
    e_vk_StructureType.value("MemoryBarrier", vk::StructureType::eMemoryBarrier);
    e_vk_StructureType.value("LoaderInstanceCreateInfo", vk::StructureType::eLoaderInstanceCreateInfo);
    e_vk_StructureType.value("LoaderDeviceCreateInfo", vk::StructureType::eLoaderDeviceCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceSubgroupProperties", vk::StructureType::ePhysicalDeviceSubgroupProperties);
    e_vk_StructureType.value("BindBufferMemoryInfo", vk::StructureType::eBindBufferMemoryInfo);
    e_vk_StructureType.value("BindImageMemoryInfo", vk::StructureType::eBindImageMemoryInfo);
    e_vk_StructureType.value("PhysicalDevice16BitStorageFeatures", vk::StructureType::ePhysicalDevice16BitStorageFeatures);
    e_vk_StructureType.value("MemoryDedicatedRequirements", vk::StructureType::eMemoryDedicatedRequirements);
    e_vk_StructureType.value("MemoryDedicatedAllocateInfo", vk::StructureType::eMemoryDedicatedAllocateInfo);
    e_vk_StructureType.value("MemoryAllocateFlagsInfo", vk::StructureType::eMemoryAllocateFlagsInfo);
    e_vk_StructureType.value("DeviceGroupRenderPassBeginInfo", vk::StructureType::eDeviceGroupRenderPassBeginInfo);
    e_vk_StructureType.value("DeviceGroupCommandBufferBeginInfo", vk::StructureType::eDeviceGroupCommandBufferBeginInfo);
    e_vk_StructureType.value("DeviceGroupSubmitInfo", vk::StructureType::eDeviceGroupSubmitInfo);
    e_vk_StructureType.value("DeviceGroupBindSparseInfo", vk::StructureType::eDeviceGroupBindSparseInfo);
    e_vk_StructureType.value("BindBufferMemoryDeviceGroupInfo", vk::StructureType::eBindBufferMemoryDeviceGroupInfo);
    e_vk_StructureType.value("BindImageMemoryDeviceGroupInfo", vk::StructureType::eBindImageMemoryDeviceGroupInfo);
    e_vk_StructureType.value("PhysicalDeviceGroupProperties", vk::StructureType::ePhysicalDeviceGroupProperties);
    e_vk_StructureType.value("DeviceGroupDeviceCreateInfo", vk::StructureType::eDeviceGroupDeviceCreateInfo);
    e_vk_StructureType.value("BufferMemoryRequirementsInfo2", vk::StructureType::eBufferMemoryRequirementsInfo2);
    e_vk_StructureType.value("ImageMemoryRequirementsInfo2", vk::StructureType::eImageMemoryRequirementsInfo2);
    e_vk_StructureType.value("ImageSparseMemoryRequirementsInfo2", vk::StructureType::eImageSparseMemoryRequirementsInfo2);
    e_vk_StructureType.value("MemoryRequirements2", vk::StructureType::eMemoryRequirements2);
    e_vk_StructureType.value("SparseImageMemoryRequirements2", vk::StructureType::eSparseImageMemoryRequirements2);
    e_vk_StructureType.value("PhysicalDeviceFeatures2", vk::StructureType::ePhysicalDeviceFeatures2);
    e_vk_StructureType.value("PhysicalDeviceProperties2", vk::StructureType::ePhysicalDeviceProperties2);
    e_vk_StructureType.value("FormatProperties2", vk::StructureType::eFormatProperties2);
    e_vk_StructureType.value("ImageFormatProperties2", vk::StructureType::eImageFormatProperties2);
    e_vk_StructureType.value("PhysicalDeviceImageFormatInfo2", vk::StructureType::ePhysicalDeviceImageFormatInfo2);
    e_vk_StructureType.value("QueueFamilyProperties2", vk::StructureType::eQueueFamilyProperties2);
    e_vk_StructureType.value("PhysicalDeviceMemoryProperties2", vk::StructureType::ePhysicalDeviceMemoryProperties2);
    e_vk_StructureType.value("SparseImageFormatProperties2", vk::StructureType::eSparseImageFormatProperties2);
    e_vk_StructureType.value("PhysicalDeviceSparseImageFormatInfo2", vk::StructureType::ePhysicalDeviceSparseImageFormatInfo2);
    e_vk_StructureType.value("PhysicalDevicePointClippingProperties", vk::StructureType::ePhysicalDevicePointClippingProperties);
    e_vk_StructureType.value("RenderPassInputAttachmentAspectCreateInfo", vk::StructureType::eRenderPassInputAttachmentAspectCreateInfo);
    e_vk_StructureType.value("ImageViewUsageCreateInfo", vk::StructureType::eImageViewUsageCreateInfo);
    e_vk_StructureType.value("PipelineTessellationDomainOriginStateCreateInfo", vk::StructureType::ePipelineTessellationDomainOriginStateCreateInfo);
    e_vk_StructureType.value("RenderPassMultiviewCreateInfo", vk::StructureType::eRenderPassMultiviewCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceMultiviewFeatures", vk::StructureType::ePhysicalDeviceMultiviewFeatures);
    e_vk_StructureType.value("PhysicalDeviceMultiviewProperties", vk::StructureType::ePhysicalDeviceMultiviewProperties);
    e_vk_StructureType.value("PhysicalDeviceVariablePointersFeatures", vk::StructureType::ePhysicalDeviceVariablePointersFeatures);
    e_vk_StructureType.value("PhysicalDeviceVariablePointerFeatures", vk::StructureType::ePhysicalDeviceVariablePointerFeatures);
    e_vk_StructureType.value("ProtectedSubmitInfo", vk::StructureType::eProtectedSubmitInfo);
    e_vk_StructureType.value("PhysicalDeviceProtectedMemoryFeatures", vk::StructureType::ePhysicalDeviceProtectedMemoryFeatures);
    e_vk_StructureType.value("PhysicalDeviceProtectedMemoryProperties", vk::StructureType::ePhysicalDeviceProtectedMemoryProperties);
    e_vk_StructureType.value("DeviceQueueInfo2", vk::StructureType::eDeviceQueueInfo2);
    e_vk_StructureType.value("SamplerYcbcrConversionCreateInfo", vk::StructureType::eSamplerYcbcrConversionCreateInfo);
    e_vk_StructureType.value("SamplerYcbcrConversionInfo", vk::StructureType::eSamplerYcbcrConversionInfo);
    e_vk_StructureType.value("BindImagePlaneMemoryInfo", vk::StructureType::eBindImagePlaneMemoryInfo);
    e_vk_StructureType.value("ImagePlaneMemoryRequirementsInfo", vk::StructureType::eImagePlaneMemoryRequirementsInfo);
    e_vk_StructureType.value("PhysicalDeviceSamplerYcbcrConversionFeatures", vk::StructureType::ePhysicalDeviceSamplerYcbcrConversionFeatures);
    e_vk_StructureType.value("SamplerYcbcrConversionImageFormatProperties", vk::StructureType::eSamplerYcbcrConversionImageFormatProperties);
    e_vk_StructureType.value("DescriptorUpdateTemplateCreateInfo", vk::StructureType::eDescriptorUpdateTemplateCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceExternalImageFormatInfo", vk::StructureType::ePhysicalDeviceExternalImageFormatInfo);
    e_vk_StructureType.value("ExternalImageFormatProperties", vk::StructureType::eExternalImageFormatProperties);
    e_vk_StructureType.value("PhysicalDeviceExternalBufferInfo", vk::StructureType::ePhysicalDeviceExternalBufferInfo);
    e_vk_StructureType.value("ExternalBufferProperties", vk::StructureType::eExternalBufferProperties);
    e_vk_StructureType.value("PhysicalDeviceIdProperties", vk::StructureType::ePhysicalDeviceIdProperties);
    e_vk_StructureType.value("ExternalMemoryBufferCreateInfo", vk::StructureType::eExternalMemoryBufferCreateInfo);
    e_vk_StructureType.value("ExternalMemoryImageCreateInfo", vk::StructureType::eExternalMemoryImageCreateInfo);
    e_vk_StructureType.value("ExportMemoryAllocateInfo", vk::StructureType::eExportMemoryAllocateInfo);
    e_vk_StructureType.value("PhysicalDeviceExternalFenceInfo", vk::StructureType::ePhysicalDeviceExternalFenceInfo);
    e_vk_StructureType.value("ExternalFenceProperties", vk::StructureType::eExternalFenceProperties);
    e_vk_StructureType.value("ExportFenceCreateInfo", vk::StructureType::eExportFenceCreateInfo);
    e_vk_StructureType.value("ExportSemaphoreCreateInfo", vk::StructureType::eExportSemaphoreCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceExternalSemaphoreInfo", vk::StructureType::ePhysicalDeviceExternalSemaphoreInfo);
    e_vk_StructureType.value("ExternalSemaphoreProperties", vk::StructureType::eExternalSemaphoreProperties);
    e_vk_StructureType.value("PhysicalDeviceMaintenance3Properties", vk::StructureType::ePhysicalDeviceMaintenance3Properties);
    e_vk_StructureType.value("DescriptorSetLayoutSupport", vk::StructureType::eDescriptorSetLayoutSupport);
    e_vk_StructureType.value("PhysicalDeviceShaderDrawParametersFeatures", vk::StructureType::ePhysicalDeviceShaderDrawParametersFeatures);
    e_vk_StructureType.value("PhysicalDeviceShaderDrawParameterFeatures", vk::StructureType::ePhysicalDeviceShaderDrawParameterFeatures);
    e_vk_StructureType.value("PhysicalDeviceVulkan11Features", vk::StructureType::ePhysicalDeviceVulkan11Features);
    e_vk_StructureType.value("PhysicalDeviceVulkan11Properties", vk::StructureType::ePhysicalDeviceVulkan11Properties);
    e_vk_StructureType.value("PhysicalDeviceVulkan12Features", vk::StructureType::ePhysicalDeviceVulkan12Features);
    e_vk_StructureType.value("PhysicalDeviceVulkan12Properties", vk::StructureType::ePhysicalDeviceVulkan12Properties);
    e_vk_StructureType.value("ImageFormatListCreateInfo", vk::StructureType::eImageFormatListCreateInfo);
    e_vk_StructureType.value("AttachmentDescription2", vk::StructureType::eAttachmentDescription2);
    e_vk_StructureType.value("AttachmentReference2", vk::StructureType::eAttachmentReference2);
    e_vk_StructureType.value("SubpassDescription2", vk::StructureType::eSubpassDescription2);
    e_vk_StructureType.value("SubpassDependency2", vk::StructureType::eSubpassDependency2);
    e_vk_StructureType.value("RenderPassCreateInfo2", vk::StructureType::eRenderPassCreateInfo2);
    e_vk_StructureType.value("SubpassBeginInfo", vk::StructureType::eSubpassBeginInfo);
    e_vk_StructureType.value("SubpassEndInfo", vk::StructureType::eSubpassEndInfo);
    e_vk_StructureType.value("PhysicalDevice8BitStorageFeatures", vk::StructureType::ePhysicalDevice8BitStorageFeatures);
    e_vk_StructureType.value("PhysicalDeviceDriverProperties", vk::StructureType::ePhysicalDeviceDriverProperties);
    e_vk_StructureType.value("PhysicalDeviceShaderAtomicInt64Features", vk::StructureType::ePhysicalDeviceShaderAtomicInt64Features);
    e_vk_StructureType.value("PhysicalDeviceShaderFloat16Int8Features", vk::StructureType::ePhysicalDeviceShaderFloat16Int8Features);
    e_vk_StructureType.value("PhysicalDeviceFloatControlsProperties", vk::StructureType::ePhysicalDeviceFloatControlsProperties);
    e_vk_StructureType.value("DescriptorSetLayoutBindingFlagsCreateInfo", vk::StructureType::eDescriptorSetLayoutBindingFlagsCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceDescriptorIndexingFeatures", vk::StructureType::ePhysicalDeviceDescriptorIndexingFeatures);
    e_vk_StructureType.value("PhysicalDeviceDescriptorIndexingProperties", vk::StructureType::ePhysicalDeviceDescriptorIndexingProperties);
    e_vk_StructureType.value("DescriptorSetVariableDescriptorCountAllocateInfo", vk::StructureType::eDescriptorSetVariableDescriptorCountAllocateInfo);
    e_vk_StructureType.value("DescriptorSetVariableDescriptorCountLayoutSupport", vk::StructureType::eDescriptorSetVariableDescriptorCountLayoutSupport);
    e_vk_StructureType.value("PhysicalDeviceDepthStencilResolveProperties", vk::StructureType::ePhysicalDeviceDepthStencilResolveProperties);
    e_vk_StructureType.value("SubpassDescriptionDepthStencilResolve", vk::StructureType::eSubpassDescriptionDepthStencilResolve);
    e_vk_StructureType.value("PhysicalDeviceScalarBlockLayoutFeatures", vk::StructureType::ePhysicalDeviceScalarBlockLayoutFeatures);
    e_vk_StructureType.value("ImageStencilUsageCreateInfo", vk::StructureType::eImageStencilUsageCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceSamplerFilterMinmaxProperties", vk::StructureType::ePhysicalDeviceSamplerFilterMinmaxProperties);
    e_vk_StructureType.value("SamplerReductionModeCreateInfo", vk::StructureType::eSamplerReductionModeCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceVulkanMemoryModelFeatures", vk::StructureType::ePhysicalDeviceVulkanMemoryModelFeatures);
    e_vk_StructureType.value("PhysicalDeviceImagelessFramebufferFeatures", vk::StructureType::ePhysicalDeviceImagelessFramebufferFeatures);
    e_vk_StructureType.value("FramebufferAttachmentsCreateInfo", vk::StructureType::eFramebufferAttachmentsCreateInfo);
    e_vk_StructureType.value("FramebufferAttachmentImageInfo", vk::StructureType::eFramebufferAttachmentImageInfo);
    e_vk_StructureType.value("RenderPassAttachmentBeginInfo", vk::StructureType::eRenderPassAttachmentBeginInfo);
    e_vk_StructureType.value("PhysicalDeviceUniformBufferStandardLayoutFeatures", vk::StructureType::ePhysicalDeviceUniformBufferStandardLayoutFeatures);
    e_vk_StructureType.value("PhysicalDeviceShaderSubgroupExtendedTypesFeatures", vk::StructureType::ePhysicalDeviceShaderSubgroupExtendedTypesFeatures);
    e_vk_StructureType.value("PhysicalDeviceSeparateDepthStencilLayoutsFeatures", vk::StructureType::ePhysicalDeviceSeparateDepthStencilLayoutsFeatures);
    e_vk_StructureType.value("AttachmentReferenceStencilLayout", vk::StructureType::eAttachmentReferenceStencilLayout);
    e_vk_StructureType.value("AttachmentDescriptionStencilLayout", vk::StructureType::eAttachmentDescriptionStencilLayout);
    e_vk_StructureType.value("PhysicalDeviceHostQueryResetFeatures", vk::StructureType::ePhysicalDeviceHostQueryResetFeatures);
    e_vk_StructureType.value("PhysicalDeviceTimelineSemaphoreFeatures", vk::StructureType::ePhysicalDeviceTimelineSemaphoreFeatures);
    e_vk_StructureType.value("PhysicalDeviceTimelineSemaphoreProperties", vk::StructureType::ePhysicalDeviceTimelineSemaphoreProperties);
    e_vk_StructureType.value("SemaphoreTypeCreateInfo", vk::StructureType::eSemaphoreTypeCreateInfo);
    e_vk_StructureType.value("TimelineSemaphoreSubmitInfo", vk::StructureType::eTimelineSemaphoreSubmitInfo);
    e_vk_StructureType.value("SemaphoreWaitInfo", vk::StructureType::eSemaphoreWaitInfo);
    e_vk_StructureType.value("SemaphoreSignalInfo", vk::StructureType::eSemaphoreSignalInfo);
    e_vk_StructureType.value("PhysicalDeviceBufferDeviceAddressFeatures", vk::StructureType::ePhysicalDeviceBufferDeviceAddressFeatures);
    e_vk_StructureType.value("BufferDeviceAddressInfo", vk::StructureType::eBufferDeviceAddressInfo);
    e_vk_StructureType.value("BufferOpaqueCaptureAddressCreateInfo", vk::StructureType::eBufferOpaqueCaptureAddressCreateInfo);
    e_vk_StructureType.value("MemoryOpaqueCaptureAddressAllocateInfo", vk::StructureType::eMemoryOpaqueCaptureAddressAllocateInfo);
    e_vk_StructureType.value("DeviceMemoryOpaqueCaptureAddressInfo", vk::StructureType::eDeviceMemoryOpaqueCaptureAddressInfo);
    e_vk_StructureType.value("PhysicalDeviceVulkan13Features", vk::StructureType::ePhysicalDeviceVulkan13Features);
    e_vk_StructureType.value("PhysicalDeviceVulkan13Properties", vk::StructureType::ePhysicalDeviceVulkan13Properties);
    e_vk_StructureType.value("PipelineCreationFeedbackCreateInfo", vk::StructureType::ePipelineCreationFeedbackCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceShaderTerminateInvocationFeatures", vk::StructureType::ePhysicalDeviceShaderTerminateInvocationFeatures);
    e_vk_StructureType.value("PhysicalDeviceToolProperties", vk::StructureType::ePhysicalDeviceToolProperties);
    e_vk_StructureType.value("PhysicalDeviceShaderDemoteToHelperInvocationFeatures", vk::StructureType::ePhysicalDeviceShaderDemoteToHelperInvocationFeatures);
    e_vk_StructureType.value("PhysicalDevicePrivateDataFeatures", vk::StructureType::ePhysicalDevicePrivateDataFeatures);
    e_vk_StructureType.value("DevicePrivateDataCreateInfo", vk::StructureType::eDevicePrivateDataCreateInfo);
    e_vk_StructureType.value("PrivateDataSlotCreateInfo", vk::StructureType::ePrivateDataSlotCreateInfo);
    e_vk_StructureType.value("PhysicalDevicePipelineCreationCacheControlFeatures", vk::StructureType::ePhysicalDevicePipelineCreationCacheControlFeatures);
    e_vk_StructureType.value("MemoryBarrier2", vk::StructureType::eMemoryBarrier2);
    e_vk_StructureType.value("BufferMemoryBarrier2", vk::StructureType::eBufferMemoryBarrier2);
    e_vk_StructureType.value("ImageMemoryBarrier2", vk::StructureType::eImageMemoryBarrier2);
    e_vk_StructureType.value("DependencyInfo", vk::StructureType::eDependencyInfo);
    e_vk_StructureType.value("SubmitInfo2", vk::StructureType::eSubmitInfo2);
    e_vk_StructureType.value("SemaphoreSubmitInfo", vk::StructureType::eSemaphoreSubmitInfo);
    e_vk_StructureType.value("CommandBufferSubmitInfo", vk::StructureType::eCommandBufferSubmitInfo);
    e_vk_StructureType.value("PhysicalDeviceSynchronization2Features", vk::StructureType::ePhysicalDeviceSynchronization2Features);
    e_vk_StructureType.value("PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures", vk::StructureType::ePhysicalDeviceZeroInitializeWorkgroupMemoryFeatures);
    e_vk_StructureType.value("PhysicalDeviceImageRobustnessFeatures", vk::StructureType::ePhysicalDeviceImageRobustnessFeatures);
    e_vk_StructureType.value("CopyBufferInfo2", vk::StructureType::eCopyBufferInfo2);
    e_vk_StructureType.value("CopyImageInfo2", vk::StructureType::eCopyImageInfo2);
    e_vk_StructureType.value("CopyBufferToImageInfo2", vk::StructureType::eCopyBufferToImageInfo2);
    e_vk_StructureType.value("CopyImageToBufferInfo2", vk::StructureType::eCopyImageToBufferInfo2);
    e_vk_StructureType.value("BlitImageInfo2", vk::StructureType::eBlitImageInfo2);
    e_vk_StructureType.value("ResolveImageInfo2", vk::StructureType::eResolveImageInfo2);
    e_vk_StructureType.value("BufferCopy2", vk::StructureType::eBufferCopy2);
    e_vk_StructureType.value("ImageCopy2", vk::StructureType::eImageCopy2);
    e_vk_StructureType.value("ImageBlit2", vk::StructureType::eImageBlit2);
    e_vk_StructureType.value("BufferImageCopy2", vk::StructureType::eBufferImageCopy2);
    e_vk_StructureType.value("ImageResolve2", vk::StructureType::eImageResolve2);
    e_vk_StructureType.value("PhysicalDeviceSubgroupSizeControlProperties", vk::StructureType::ePhysicalDeviceSubgroupSizeControlProperties);
    e_vk_StructureType.value("PipelineShaderStageRequiredSubgroupSizeCreateInfo", vk::StructureType::ePipelineShaderStageRequiredSubgroupSizeCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceSubgroupSizeControlFeatures", vk::StructureType::ePhysicalDeviceSubgroupSizeControlFeatures);
    e_vk_StructureType.value("PhysicalDeviceInlineUniformBlockFeatures", vk::StructureType::ePhysicalDeviceInlineUniformBlockFeatures);
    e_vk_StructureType.value("PhysicalDeviceInlineUniformBlockProperties", vk::StructureType::ePhysicalDeviceInlineUniformBlockProperties);
    e_vk_StructureType.value("WriteDescriptorSetInlineUniformBlock", vk::StructureType::eWriteDescriptorSetInlineUniformBlock);
    e_vk_StructureType.value("DescriptorPoolInlineUniformBlockCreateInfo", vk::StructureType::eDescriptorPoolInlineUniformBlockCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceTextureCompressionAstcHdrFeatures", vk::StructureType::ePhysicalDeviceTextureCompressionAstcHdrFeatures);
    e_vk_StructureType.value("RenderingInfo", vk::StructureType::eRenderingInfo);
    e_vk_StructureType.value("RenderingAttachmentInfo", vk::StructureType::eRenderingAttachmentInfo);
    e_vk_StructureType.value("PipelineRenderingCreateInfo", vk::StructureType::ePipelineRenderingCreateInfo);
    e_vk_StructureType.value("PhysicalDeviceDynamicRenderingFeatures", vk::StructureType::ePhysicalDeviceDynamicRenderingFeatures);
    e_vk_StructureType.value("CommandBufferInheritanceRenderingInfo", vk::StructureType::eCommandBufferInheritanceRenderingInfo);
    e_vk_StructureType.value("PhysicalDeviceShaderIntegerDotProductFeatures", vk::StructureType::ePhysicalDeviceShaderIntegerDotProductFeatures);
    e_vk_StructureType.value("PhysicalDeviceShaderIntegerDotProductProperties", vk::StructureType::ePhysicalDeviceShaderIntegerDotProductProperties);
    e_vk_StructureType.value("PhysicalDeviceTexelBufferAlignmentProperties", vk::StructureType::ePhysicalDeviceTexelBufferAlignmentProperties);
    e_vk_StructureType.value("FormatProperties3", vk::StructureType::eFormatProperties3);
    e_vk_StructureType.value("PhysicalDeviceMaintenance4Features", vk::StructureType::ePhysicalDeviceMaintenance4Features);
    e_vk_StructureType.value("PhysicalDeviceMaintenance4Properties", vk::StructureType::ePhysicalDeviceMaintenance4Properties);
    e_vk_StructureType.value("DeviceBufferMemoryRequirements", vk::StructureType::eDeviceBufferMemoryRequirements);
    e_vk_StructureType.value("DeviceImageMemoryRequirements", vk::StructureType::eDeviceImageMemoryRequirements);
    e_vk_StructureType.value("SwapchainCreateInfoKHR", vk::StructureType::eSwapchainCreateInfoKHR);
    e_vk_StructureType.value("PresentInfoKHR", vk::StructureType::ePresentInfoKHR);
    e_vk_StructureType.value("DeviceGroupPresentCapabilitiesKHR", vk::StructureType::eDeviceGroupPresentCapabilitiesKHR);
    e_vk_StructureType.value("ImageSwapchainCreateInfoKHR", vk::StructureType::eImageSwapchainCreateInfoKHR);
    e_vk_StructureType.value("BindImageMemorySwapchainInfoKHR", vk::StructureType::eBindImageMemorySwapchainInfoKHR);
    e_vk_StructureType.value("AcquireNextImageInfoKHR", vk::StructureType::eAcquireNextImageInfoKHR);
    e_vk_StructureType.value("DeviceGroupPresentInfoKHR", vk::StructureType::eDeviceGroupPresentInfoKHR);
    e_vk_StructureType.value("DeviceGroupSwapchainCreateInfoKHR", vk::StructureType::eDeviceGroupSwapchainCreateInfoKHR);
    e_vk_StructureType.value("DisplayModeCreateInfoKHR", vk::StructureType::eDisplayModeCreateInfoKHR);
    e_vk_StructureType.value("DisplaySurfaceCreateInfoKHR", vk::StructureType::eDisplaySurfaceCreateInfoKHR);
    e_vk_StructureType.value("DisplayPresentInfoKHR", vk::StructureType::eDisplayPresentInfoKHR);
    e_vk_StructureType.value("DebugReportCallbackCreateInfoEXT", vk::StructureType::eDebugReportCallbackCreateInfoEXT);
    e_vk_StructureType.value("DebugReportCreateInfoEXT", vk::StructureType::eDebugReportCreateInfoEXT);
    e_vk_StructureType.value("PipelineRasterizationStateRasterizationOrderAMD", vk::StructureType::ePipelineRasterizationStateRasterizationOrderAMD);
    e_vk_StructureType.value("DebugMarkerObjectNameInfoEXT", vk::StructureType::eDebugMarkerObjectNameInfoEXT);
    e_vk_StructureType.value("DebugMarkerObjectTagInfoEXT", vk::StructureType::eDebugMarkerObjectTagInfoEXT);
    e_vk_StructureType.value("DebugMarkerMarkerInfoEXT", vk::StructureType::eDebugMarkerMarkerInfoEXT);
    e_vk_StructureType.value("VideoProfileInfoKHR", vk::StructureType::eVideoProfileInfoKHR);
    e_vk_StructureType.value("VideoCapabilitiesKHR", vk::StructureType::eVideoCapabilitiesKHR);
    e_vk_StructureType.value("VideoPictureResourceInfoKHR", vk::StructureType::eVideoPictureResourceInfoKHR);
    e_vk_StructureType.value("VideoSessionMemoryRequirementsKHR", vk::StructureType::eVideoSessionMemoryRequirementsKHR);
    e_vk_StructureType.value("BindVideoSessionMemoryInfoKHR", vk::StructureType::eBindVideoSessionMemoryInfoKHR);
    e_vk_StructureType.value("VideoSessionCreateInfoKHR", vk::StructureType::eVideoSessionCreateInfoKHR);
    e_vk_StructureType.value("VideoSessionParametersCreateInfoKHR", vk::StructureType::eVideoSessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VideoSessionParametersUpdateInfoKHR", vk::StructureType::eVideoSessionParametersUpdateInfoKHR);
    e_vk_StructureType.value("VideoBeginCodingInfoKHR", vk::StructureType::eVideoBeginCodingInfoKHR);
    e_vk_StructureType.value("VideoEndCodingInfoKHR", vk::StructureType::eVideoEndCodingInfoKHR);
    e_vk_StructureType.value("VideoCodingControlInfoKHR", vk::StructureType::eVideoCodingControlInfoKHR);
    e_vk_StructureType.value("VideoReferenceSlotInfoKHR", vk::StructureType::eVideoReferenceSlotInfoKHR);
    e_vk_StructureType.value("QueueFamilyVideoPropertiesKHR", vk::StructureType::eQueueFamilyVideoPropertiesKHR);
    e_vk_StructureType.value("VideoProfileListInfoKHR", vk::StructureType::eVideoProfileListInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceVideoFormatInfoKHR", vk::StructureType::ePhysicalDeviceVideoFormatInfoKHR);
    e_vk_StructureType.value("VideoFormatPropertiesKHR", vk::StructureType::eVideoFormatPropertiesKHR);
    e_vk_StructureType.value("QueueFamilyQueryResultStatusPropertiesKHR", vk::StructureType::eQueueFamilyQueryResultStatusPropertiesKHR);
    e_vk_StructureType.value("VideoDecodeInfoKHR", vk::StructureType::eVideoDecodeInfoKHR);
    e_vk_StructureType.value("VideoDecodeCapabilitiesKHR", vk::StructureType::eVideoDecodeCapabilitiesKHR);
    e_vk_StructureType.value("VideoDecodeUsageInfoKHR", vk::StructureType::eVideoDecodeUsageInfoKHR);
    e_vk_StructureType.value("DedicatedAllocationImageCreateInfoNV", vk::StructureType::eDedicatedAllocationImageCreateInfoNV);
    e_vk_StructureType.value("DedicatedAllocationBufferCreateInfoNV", vk::StructureType::eDedicatedAllocationBufferCreateInfoNV);
    e_vk_StructureType.value("DedicatedAllocationMemoryAllocateInfoNV", vk::StructureType::eDedicatedAllocationMemoryAllocateInfoNV);
    e_vk_StructureType.value("PhysicalDeviceTransformFeedbackFeaturesEXT", vk::StructureType::ePhysicalDeviceTransformFeedbackFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceTransformFeedbackPropertiesEXT", vk::StructureType::ePhysicalDeviceTransformFeedbackPropertiesEXT);
    e_vk_StructureType.value("PipelineRasterizationStateStreamCreateInfoEXT", vk::StructureType::ePipelineRasterizationStateStreamCreateInfoEXT);
    e_vk_StructureType.value("CuModuleCreateInfoNVX", vk::StructureType::eCuModuleCreateInfoNVX);
    e_vk_StructureType.value("CuFunctionCreateInfoNVX", vk::StructureType::eCuFunctionCreateInfoNVX);
    e_vk_StructureType.value("CuLaunchInfoNVX", vk::StructureType::eCuLaunchInfoNVX);
    e_vk_StructureType.value("ImageViewHandleInfoNVX", vk::StructureType::eImageViewHandleInfoNVX);
    e_vk_StructureType.value("ImageViewAddressPropertiesNVX", vk::StructureType::eImageViewAddressPropertiesNVX);
    e_vk_StructureType.value("VideoEncodeH264CapabilitiesKHR", vk::StructureType::eVideoEncodeH264CapabilitiesKHR);
    e_vk_StructureType.value("VideoEncodeH264SessionParametersCreateInfoKHR", vk::StructureType::eVideoEncodeH264SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264SessionParametersAddInfoKHR", vk::StructureType::eVideoEncodeH264SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264PictureInfoKHR", vk::StructureType::eVideoEncodeH264PictureInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264DpbSlotInfoKHR", vk::StructureType::eVideoEncodeH264DpbSlotInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264NaluSliceInfoKHR", vk::StructureType::eVideoEncodeH264NaluSliceInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264GopRemainingFrameInfoKHR", vk::StructureType::eVideoEncodeH264GopRemainingFrameInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264ProfileInfoKHR", vk::StructureType::eVideoEncodeH264ProfileInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264RateControlInfoKHR", vk::StructureType::eVideoEncodeH264RateControlInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264RateControlLayerInfoKHR", vk::StructureType::eVideoEncodeH264RateControlLayerInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264SessionCreateInfoKHR", vk::StructureType::eVideoEncodeH264SessionCreateInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264QualityLevelPropertiesKHR", vk::StructureType::eVideoEncodeH264QualityLevelPropertiesKHR);
    e_vk_StructureType.value("VideoEncodeH264SessionParametersGetInfoKHR", vk::StructureType::eVideoEncodeH264SessionParametersGetInfoKHR);
    e_vk_StructureType.value("VideoEncodeH264SessionParametersFeedbackInfoKHR", vk::StructureType::eVideoEncodeH264SessionParametersFeedbackInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265CapabilitiesKHR", vk::StructureType::eVideoEncodeH265CapabilitiesKHR);
    e_vk_StructureType.value("VideoEncodeH265SessionParametersCreateInfoKHR", vk::StructureType::eVideoEncodeH265SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265SessionParametersAddInfoKHR", vk::StructureType::eVideoEncodeH265SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265PictureInfoKHR", vk::StructureType::eVideoEncodeH265PictureInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265DpbSlotInfoKHR", vk::StructureType::eVideoEncodeH265DpbSlotInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265NaluSliceSegmentInfoKHR", vk::StructureType::eVideoEncodeH265NaluSliceSegmentInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265GopRemainingFrameInfoKHR", vk::StructureType::eVideoEncodeH265GopRemainingFrameInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265ProfileInfoKHR", vk::StructureType::eVideoEncodeH265ProfileInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265RateControlInfoKHR", vk::StructureType::eVideoEncodeH265RateControlInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265RateControlLayerInfoKHR", vk::StructureType::eVideoEncodeH265RateControlLayerInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265SessionCreateInfoKHR", vk::StructureType::eVideoEncodeH265SessionCreateInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265QualityLevelPropertiesKHR", vk::StructureType::eVideoEncodeH265QualityLevelPropertiesKHR);
    e_vk_StructureType.value("VideoEncodeH265SessionParametersGetInfoKHR", vk::StructureType::eVideoEncodeH265SessionParametersGetInfoKHR);
    e_vk_StructureType.value("VideoEncodeH265SessionParametersFeedbackInfoKHR", vk::StructureType::eVideoEncodeH265SessionParametersFeedbackInfoKHR);
    e_vk_StructureType.value("VideoDecodeH264CapabilitiesKHR", vk::StructureType::eVideoDecodeH264CapabilitiesKHR);
    e_vk_StructureType.value("VideoDecodeH264PictureInfoKHR", vk::StructureType::eVideoDecodeH264PictureInfoKHR);
    e_vk_StructureType.value("VideoDecodeH264ProfileInfoKHR", vk::StructureType::eVideoDecodeH264ProfileInfoKHR);
    e_vk_StructureType.value("VideoDecodeH264SessionParametersCreateInfoKHR", vk::StructureType::eVideoDecodeH264SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VideoDecodeH264SessionParametersAddInfoKHR", vk::StructureType::eVideoDecodeH264SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VideoDecodeH264DpbSlotInfoKHR", vk::StructureType::eVideoDecodeH264DpbSlotInfoKHR);
    e_vk_StructureType.value("TextureLodGatherFormatPropertiesAMD", vk::StructureType::eTextureLodGatherFormatPropertiesAMD);
    e_vk_StructureType.value("RenderingInfoKHR", vk::StructureType::eRenderingInfoKHR);
    e_vk_StructureType.value("RenderingAttachmentInfoKHR", vk::StructureType::eRenderingAttachmentInfoKHR);
    e_vk_StructureType.value("PipelineRenderingCreateInfoKHR", vk::StructureType::ePipelineRenderingCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceDynamicRenderingFeaturesKHR", vk::StructureType::ePhysicalDeviceDynamicRenderingFeaturesKHR);
    e_vk_StructureType.value("CommandBufferInheritanceRenderingInfoKHR", vk::StructureType::eCommandBufferInheritanceRenderingInfoKHR);
    e_vk_StructureType.value("RenderingFragmentShadingRateAttachmentInfoKHR", vk::StructureType::eRenderingFragmentShadingRateAttachmentInfoKHR);
    e_vk_StructureType.value("RenderingFragmentDensityMapAttachmentInfoEXT", vk::StructureType::eRenderingFragmentDensityMapAttachmentInfoEXT);
    e_vk_StructureType.value("AttachmentSampleCountInfoAMD", vk::StructureType::eAttachmentSampleCountInfoAMD);
    e_vk_StructureType.value("AttachmentSampleCountInfoNV", vk::StructureType::eAttachmentSampleCountInfoNV);
    e_vk_StructureType.value("MultiviewPerViewAttributesInfoNVX", vk::StructureType::eMultiviewPerViewAttributesInfoNVX);
    e_vk_StructureType.value("PhysicalDeviceCornerSampledImageFeaturesNV", vk::StructureType::ePhysicalDeviceCornerSampledImageFeaturesNV);
    e_vk_StructureType.value("RenderPassMultiviewCreateInfoKHR", vk::StructureType::eRenderPassMultiviewCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceMultiviewFeaturesKHR", vk::StructureType::ePhysicalDeviceMultiviewFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceMultiviewPropertiesKHR", vk::StructureType::ePhysicalDeviceMultiviewPropertiesKHR);
    e_vk_StructureType.value("ExternalMemoryImageCreateInfoNV", vk::StructureType::eExternalMemoryImageCreateInfoNV);
    e_vk_StructureType.value("ExportMemoryAllocateInfoNV", vk::StructureType::eExportMemoryAllocateInfoNV);
    e_vk_StructureType.value("PhysicalDeviceFeatures2KHR", vk::StructureType::ePhysicalDeviceFeatures2KHR);
    e_vk_StructureType.value("PhysicalDeviceProperties2KHR", vk::StructureType::ePhysicalDeviceProperties2KHR);
    e_vk_StructureType.value("FormatProperties2KHR", vk::StructureType::eFormatProperties2KHR);
    e_vk_StructureType.value("ImageFormatProperties2KHR", vk::StructureType::eImageFormatProperties2KHR);
    e_vk_StructureType.value("PhysicalDeviceImageFormatInfo2KHR", vk::StructureType::ePhysicalDeviceImageFormatInfo2KHR);
    e_vk_StructureType.value("QueueFamilyProperties2KHR", vk::StructureType::eQueueFamilyProperties2KHR);
    e_vk_StructureType.value("PhysicalDeviceMemoryProperties2KHR", vk::StructureType::ePhysicalDeviceMemoryProperties2KHR);
    e_vk_StructureType.value("SparseImageFormatProperties2KHR", vk::StructureType::eSparseImageFormatProperties2KHR);
    e_vk_StructureType.value("PhysicalDeviceSparseImageFormatInfo2KHR", vk::StructureType::ePhysicalDeviceSparseImageFormatInfo2KHR);
    e_vk_StructureType.value("MemoryAllocateFlagsInfoKHR", vk::StructureType::eMemoryAllocateFlagsInfoKHR);
    e_vk_StructureType.value("DeviceGroupRenderPassBeginInfoKHR", vk::StructureType::eDeviceGroupRenderPassBeginInfoKHR);
    e_vk_StructureType.value("DeviceGroupCommandBufferBeginInfoKHR", vk::StructureType::eDeviceGroupCommandBufferBeginInfoKHR);
    e_vk_StructureType.value("DeviceGroupSubmitInfoKHR", vk::StructureType::eDeviceGroupSubmitInfoKHR);
    e_vk_StructureType.value("DeviceGroupBindSparseInfoKHR", vk::StructureType::eDeviceGroupBindSparseInfoKHR);
    e_vk_StructureType.value("BindBufferMemoryDeviceGroupInfoKHR", vk::StructureType::eBindBufferMemoryDeviceGroupInfoKHR);
    e_vk_StructureType.value("BindImageMemoryDeviceGroupInfoKHR", vk::StructureType::eBindImageMemoryDeviceGroupInfoKHR);
    e_vk_StructureType.value("ValidationFlagsEXT", vk::StructureType::eValidationFlagsEXT);
    e_vk_StructureType.value("PhysicalDeviceTextureCompressionAstcHdrFeaturesEXT", vk::StructureType::ePhysicalDeviceTextureCompressionAstcHdrFeaturesEXT);
    e_vk_StructureType.value("ImageViewAstcDecodeModeEXT", vk::StructureType::eImageViewAstcDecodeModeEXT);
    e_vk_StructureType.value("PhysicalDeviceAstcDecodeFeaturesEXT", vk::StructureType::ePhysicalDeviceAstcDecodeFeaturesEXT);
    e_vk_StructureType.value("PipelineRobustnessCreateInfoEXT", vk::StructureType::ePipelineRobustnessCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDevicePipelineRobustnessFeaturesEXT", vk::StructureType::ePhysicalDevicePipelineRobustnessFeaturesEXT);
    e_vk_StructureType.value("PhysicalDevicePipelineRobustnessPropertiesEXT", vk::StructureType::ePhysicalDevicePipelineRobustnessPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceGroupPropertiesKHR", vk::StructureType::ePhysicalDeviceGroupPropertiesKHR);
    e_vk_StructureType.value("DeviceGroupDeviceCreateInfoKHR", vk::StructureType::eDeviceGroupDeviceCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceExternalImageFormatInfoKHR", vk::StructureType::ePhysicalDeviceExternalImageFormatInfoKHR);
    e_vk_StructureType.value("ExternalImageFormatPropertiesKHR", vk::StructureType::eExternalImageFormatPropertiesKHR);
    e_vk_StructureType.value("PhysicalDeviceExternalBufferInfoKHR", vk::StructureType::ePhysicalDeviceExternalBufferInfoKHR);
    e_vk_StructureType.value("ExternalBufferPropertiesKHR", vk::StructureType::eExternalBufferPropertiesKHR);
    e_vk_StructureType.value("PhysicalDeviceIdPropertiesKHR", vk::StructureType::ePhysicalDeviceIdPropertiesKHR);
    e_vk_StructureType.value("ExternalMemoryBufferCreateInfoKHR", vk::StructureType::eExternalMemoryBufferCreateInfoKHR);
    e_vk_StructureType.value("ExternalMemoryImageCreateInfoKHR", vk::StructureType::eExternalMemoryImageCreateInfoKHR);
    e_vk_StructureType.value("ExportMemoryAllocateInfoKHR", vk::StructureType::eExportMemoryAllocateInfoKHR);
    e_vk_StructureType.value("ImportMemoryFdInfoKHR", vk::StructureType::eImportMemoryFdInfoKHR);
    e_vk_StructureType.value("MemoryFdPropertiesKHR", vk::StructureType::eMemoryFdPropertiesKHR);
    e_vk_StructureType.value("MemoryGetFdInfoKHR", vk::StructureType::eMemoryGetFdInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceExternalSemaphoreInfoKHR", vk::StructureType::ePhysicalDeviceExternalSemaphoreInfoKHR);
    e_vk_StructureType.value("ExternalSemaphorePropertiesKHR", vk::StructureType::eExternalSemaphorePropertiesKHR);
    e_vk_StructureType.value("ExportSemaphoreCreateInfoKHR", vk::StructureType::eExportSemaphoreCreateInfoKHR);
    e_vk_StructureType.value("ImportSemaphoreFdInfoKHR", vk::StructureType::eImportSemaphoreFdInfoKHR);
    e_vk_StructureType.value("SemaphoreGetFdInfoKHR", vk::StructureType::eSemaphoreGetFdInfoKHR);
    e_vk_StructureType.value("PhysicalDevicePushDescriptorPropertiesKHR", vk::StructureType::ePhysicalDevicePushDescriptorPropertiesKHR);
    e_vk_StructureType.value("CommandBufferInheritanceConditionalRenderingInfoEXT", vk::StructureType::eCommandBufferInheritanceConditionalRenderingInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceConditionalRenderingFeaturesEXT", vk::StructureType::ePhysicalDeviceConditionalRenderingFeaturesEXT);
    e_vk_StructureType.value("ConditionalRenderingBeginInfoEXT", vk::StructureType::eConditionalRenderingBeginInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderFloat16Int8FeaturesKHR", vk::StructureType::ePhysicalDeviceShaderFloat16Int8FeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceFloat16Int8FeaturesKHR", vk::StructureType::ePhysicalDeviceFloat16Int8FeaturesKHR);
    e_vk_StructureType.value("PhysicalDevice16BitStorageFeaturesKHR", vk::StructureType::ePhysicalDevice16BitStorageFeaturesKHR);
    e_vk_StructureType.value("PresentRegionsKHR", vk::StructureType::ePresentRegionsKHR);
    e_vk_StructureType.value("DescriptorUpdateTemplateCreateInfoKHR", vk::StructureType::eDescriptorUpdateTemplateCreateInfoKHR);
    e_vk_StructureType.value("PipelineViewportWScalingStateCreateInfoNV", vk::StructureType::ePipelineViewportWScalingStateCreateInfoNV);
    e_vk_StructureType.value("SurfaceCapabilities2EXT", vk::StructureType::eSurfaceCapabilities2EXT);
    e_vk_StructureType.value("DisplayPowerInfoEXT", vk::StructureType::eDisplayPowerInfoEXT);
    e_vk_StructureType.value("DeviceEventInfoEXT", vk::StructureType::eDeviceEventInfoEXT);
    e_vk_StructureType.value("DisplayEventInfoEXT", vk::StructureType::eDisplayEventInfoEXT);
    e_vk_StructureType.value("SwapchainCounterCreateInfoEXT", vk::StructureType::eSwapchainCounterCreateInfoEXT);
    e_vk_StructureType.value("PresentTimesInfoGOOGLE", vk::StructureType::ePresentTimesInfoGOOGLE);
    e_vk_StructureType.value("PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX", vk::StructureType::ePhysicalDeviceMultiviewPerViewAttributesPropertiesNVX);
    e_vk_StructureType.value("PipelineViewportSwizzleStateCreateInfoNV", vk::StructureType::ePipelineViewportSwizzleStateCreateInfoNV);
    e_vk_StructureType.value("PhysicalDeviceDiscardRectanglePropertiesEXT", vk::StructureType::ePhysicalDeviceDiscardRectanglePropertiesEXT);
    e_vk_StructureType.value("PipelineDiscardRectangleStateCreateInfoEXT", vk::StructureType::ePipelineDiscardRectangleStateCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceConservativeRasterizationPropertiesEXT", vk::StructureType::ePhysicalDeviceConservativeRasterizationPropertiesEXT);
    e_vk_StructureType.value("PipelineRasterizationConservativeStateCreateInfoEXT", vk::StructureType::ePipelineRasterizationConservativeStateCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceDepthClipEnableFeaturesEXT", vk::StructureType::ePhysicalDeviceDepthClipEnableFeaturesEXT);
    e_vk_StructureType.value("PipelineRasterizationDepthClipStateCreateInfoEXT", vk::StructureType::ePipelineRasterizationDepthClipStateCreateInfoEXT);
    e_vk_StructureType.value("HdrMetadataEXT", vk::StructureType::eHdrMetadataEXT);
    e_vk_StructureType.value("PhysicalDeviceImagelessFramebufferFeaturesKHR", vk::StructureType::ePhysicalDeviceImagelessFramebufferFeaturesKHR);
    e_vk_StructureType.value("FramebufferAttachmentsCreateInfoKHR", vk::StructureType::eFramebufferAttachmentsCreateInfoKHR);
    e_vk_StructureType.value("FramebufferAttachmentImageInfoKHR", vk::StructureType::eFramebufferAttachmentImageInfoKHR);
    e_vk_StructureType.value("RenderPassAttachmentBeginInfoKHR", vk::StructureType::eRenderPassAttachmentBeginInfoKHR);
    e_vk_StructureType.value("AttachmentDescription2KHR", vk::StructureType::eAttachmentDescription2KHR);
    e_vk_StructureType.value("AttachmentReference2KHR", vk::StructureType::eAttachmentReference2KHR);
    e_vk_StructureType.value("SubpassDescription2KHR", vk::StructureType::eSubpassDescription2KHR);
    e_vk_StructureType.value("SubpassDependency2KHR", vk::StructureType::eSubpassDependency2KHR);
    e_vk_StructureType.value("RenderPassCreateInfo2KHR", vk::StructureType::eRenderPassCreateInfo2KHR);
    e_vk_StructureType.value("SubpassBeginInfoKHR", vk::StructureType::eSubpassBeginInfoKHR);
    e_vk_StructureType.value("SubpassEndInfoKHR", vk::StructureType::eSubpassEndInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceRelaxedLineRasterizationFeaturesIMG", vk::StructureType::ePhysicalDeviceRelaxedLineRasterizationFeaturesIMG);
    e_vk_StructureType.value("SharedPresentSurfaceCapabilitiesKHR", vk::StructureType::eSharedPresentSurfaceCapabilitiesKHR);
    e_vk_StructureType.value("PhysicalDeviceExternalFenceInfoKHR", vk::StructureType::ePhysicalDeviceExternalFenceInfoKHR);
    e_vk_StructureType.value("ExternalFencePropertiesKHR", vk::StructureType::eExternalFencePropertiesKHR);
    e_vk_StructureType.value("ExportFenceCreateInfoKHR", vk::StructureType::eExportFenceCreateInfoKHR);
    e_vk_StructureType.value("ImportFenceFdInfoKHR", vk::StructureType::eImportFenceFdInfoKHR);
    e_vk_StructureType.value("FenceGetFdInfoKHR", vk::StructureType::eFenceGetFdInfoKHR);
    e_vk_StructureType.value("PhysicalDevicePerformanceQueryFeaturesKHR", vk::StructureType::ePhysicalDevicePerformanceQueryFeaturesKHR);
    e_vk_StructureType.value("PhysicalDevicePerformanceQueryPropertiesKHR", vk::StructureType::ePhysicalDevicePerformanceQueryPropertiesKHR);
    e_vk_StructureType.value("QueryPoolPerformanceCreateInfoKHR", vk::StructureType::eQueryPoolPerformanceCreateInfoKHR);
    e_vk_StructureType.value("PerformanceQuerySubmitInfoKHR", vk::StructureType::ePerformanceQuerySubmitInfoKHR);
    e_vk_StructureType.value("AcquireProfilingLockInfoKHR", vk::StructureType::eAcquireProfilingLockInfoKHR);
    e_vk_StructureType.value("PerformanceCounterKHR", vk::StructureType::ePerformanceCounterKHR);
    e_vk_StructureType.value("PerformanceCounterDescriptionKHR", vk::StructureType::ePerformanceCounterDescriptionKHR);
    e_vk_StructureType.value("PhysicalDevicePointClippingPropertiesKHR", vk::StructureType::ePhysicalDevicePointClippingPropertiesKHR);
    e_vk_StructureType.value("RenderPassInputAttachmentAspectCreateInfoKHR", vk::StructureType::eRenderPassInputAttachmentAspectCreateInfoKHR);
    e_vk_StructureType.value("ImageViewUsageCreateInfoKHR", vk::StructureType::eImageViewUsageCreateInfoKHR);
    e_vk_StructureType.value("PipelineTessellationDomainOriginStateCreateInfoKHR", vk::StructureType::ePipelineTessellationDomainOriginStateCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceSurfaceInfo2KHR", vk::StructureType::ePhysicalDeviceSurfaceInfo2KHR);
    e_vk_StructureType.value("SurfaceCapabilities2KHR", vk::StructureType::eSurfaceCapabilities2KHR);
    e_vk_StructureType.value("SurfaceFormat2KHR", vk::StructureType::eSurfaceFormat2KHR);
    e_vk_StructureType.value("PhysicalDeviceVariablePointersFeaturesKHR", vk::StructureType::ePhysicalDeviceVariablePointersFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceVariablePointerFeaturesKHR", vk::StructureType::ePhysicalDeviceVariablePointerFeaturesKHR);
    e_vk_StructureType.value("DisplayProperties2KHR", vk::StructureType::eDisplayProperties2KHR);
    e_vk_StructureType.value("DisplayPlaneProperties2KHR", vk::StructureType::eDisplayPlaneProperties2KHR);
    e_vk_StructureType.value("DisplayModeProperties2KHR", vk::StructureType::eDisplayModeProperties2KHR);
    e_vk_StructureType.value("DisplayPlaneInfo2KHR", vk::StructureType::eDisplayPlaneInfo2KHR);
    e_vk_StructureType.value("DisplayPlaneCapabilities2KHR", vk::StructureType::eDisplayPlaneCapabilities2KHR);
    e_vk_StructureType.value("MemoryDedicatedRequirementsKHR", vk::StructureType::eMemoryDedicatedRequirementsKHR);
    e_vk_StructureType.value("MemoryDedicatedAllocateInfoKHR", vk::StructureType::eMemoryDedicatedAllocateInfoKHR);
    e_vk_StructureType.value("DebugUtilsObjectNameInfoEXT", vk::StructureType::eDebugUtilsObjectNameInfoEXT);
    e_vk_StructureType.value("DebugUtilsObjectTagInfoEXT", vk::StructureType::eDebugUtilsObjectTagInfoEXT);
    e_vk_StructureType.value("DebugUtilsLabelEXT", vk::StructureType::eDebugUtilsLabelEXT);
    e_vk_StructureType.value("DebugUtilsMessengerCallbackDataEXT", vk::StructureType::eDebugUtilsMessengerCallbackDataEXT);
    e_vk_StructureType.value("DebugUtilsMessengerCreateInfoEXT", vk::StructureType::eDebugUtilsMessengerCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceSamplerFilterMinmaxPropertiesEXT", vk::StructureType::ePhysicalDeviceSamplerFilterMinmaxPropertiesEXT);
    e_vk_StructureType.value("SamplerReductionModeCreateInfoEXT", vk::StructureType::eSamplerReductionModeCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceInlineUniformBlockFeaturesEXT", vk::StructureType::ePhysicalDeviceInlineUniformBlockFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceInlineUniformBlockPropertiesEXT", vk::StructureType::ePhysicalDeviceInlineUniformBlockPropertiesEXT);
    e_vk_StructureType.value("WriteDescriptorSetInlineUniformBlockEXT", vk::StructureType::eWriteDescriptorSetInlineUniformBlockEXT);
    e_vk_StructureType.value("DescriptorPoolInlineUniformBlockCreateInfoEXT", vk::StructureType::eDescriptorPoolInlineUniformBlockCreateInfoEXT);
    e_vk_StructureType.value("SampleLocationsInfoEXT", vk::StructureType::eSampleLocationsInfoEXT);
    e_vk_StructureType.value("RenderPassSampleLocationsBeginInfoEXT", vk::StructureType::eRenderPassSampleLocationsBeginInfoEXT);
    e_vk_StructureType.value("PipelineSampleLocationsStateCreateInfoEXT", vk::StructureType::ePipelineSampleLocationsStateCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceSampleLocationsPropertiesEXT", vk::StructureType::ePhysicalDeviceSampleLocationsPropertiesEXT);
    e_vk_StructureType.value("MultisamplePropertiesEXT", vk::StructureType::eMultisamplePropertiesEXT);
    e_vk_StructureType.value("BufferMemoryRequirementsInfo2KHR", vk::StructureType::eBufferMemoryRequirementsInfo2KHR);
    e_vk_StructureType.value("ImageMemoryRequirementsInfo2KHR", vk::StructureType::eImageMemoryRequirementsInfo2KHR);
    e_vk_StructureType.value("ImageSparseMemoryRequirementsInfo2KHR", vk::StructureType::eImageSparseMemoryRequirementsInfo2KHR);
    e_vk_StructureType.value("MemoryRequirements2KHR", vk::StructureType::eMemoryRequirements2KHR);
    e_vk_StructureType.value("SparseImageMemoryRequirements2KHR", vk::StructureType::eSparseImageMemoryRequirements2KHR);
    e_vk_StructureType.value("ImageFormatListCreateInfoKHR", vk::StructureType::eImageFormatListCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceBlendOperationAdvancedFeaturesEXT", vk::StructureType::ePhysicalDeviceBlendOperationAdvancedFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceBlendOperationAdvancedPropertiesEXT", vk::StructureType::ePhysicalDeviceBlendOperationAdvancedPropertiesEXT);
    e_vk_StructureType.value("PipelineColorBlendAdvancedStateCreateInfoEXT", vk::StructureType::ePipelineColorBlendAdvancedStateCreateInfoEXT);
    e_vk_StructureType.value("PipelineCoverageToColorStateCreateInfoNV", vk::StructureType::ePipelineCoverageToColorStateCreateInfoNV);
    e_vk_StructureType.value("WriteDescriptorSetAccelerationStructureKHR", vk::StructureType::eWriteDescriptorSetAccelerationStructureKHR);
    e_vk_StructureType.value("AccelerationStructureBuildGeometryInfoKHR", vk::StructureType::eAccelerationStructureBuildGeometryInfoKHR);
    e_vk_StructureType.value("AccelerationStructureDeviceAddressInfoKHR", vk::StructureType::eAccelerationStructureDeviceAddressInfoKHR);
    e_vk_StructureType.value("AccelerationStructureGeometryAabbsDataKHR", vk::StructureType::eAccelerationStructureGeometryAabbsDataKHR);
    e_vk_StructureType.value("AccelerationStructureGeometryInstancesDataKHR", vk::StructureType::eAccelerationStructureGeometryInstancesDataKHR);
    e_vk_StructureType.value("AccelerationStructureGeometryTrianglesDataKHR", vk::StructureType::eAccelerationStructureGeometryTrianglesDataKHR);
    e_vk_StructureType.value("AccelerationStructureGeometryKHR", vk::StructureType::eAccelerationStructureGeometryKHR);
    e_vk_StructureType.value("AccelerationStructureVersionInfoKHR", vk::StructureType::eAccelerationStructureVersionInfoKHR);
    e_vk_StructureType.value("CopyAccelerationStructureInfoKHR", vk::StructureType::eCopyAccelerationStructureInfoKHR);
    e_vk_StructureType.value("CopyAccelerationStructureToMemoryInfoKHR", vk::StructureType::eCopyAccelerationStructureToMemoryInfoKHR);
    e_vk_StructureType.value("CopyMemoryToAccelerationStructureInfoKHR", vk::StructureType::eCopyMemoryToAccelerationStructureInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceAccelerationStructureFeaturesKHR", vk::StructureType::ePhysicalDeviceAccelerationStructureFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceAccelerationStructurePropertiesKHR", vk::StructureType::ePhysicalDeviceAccelerationStructurePropertiesKHR);
    e_vk_StructureType.value("AccelerationStructureCreateInfoKHR", vk::StructureType::eAccelerationStructureCreateInfoKHR);
    e_vk_StructureType.value("AccelerationStructureBuildSizesInfoKHR", vk::StructureType::eAccelerationStructureBuildSizesInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceRayTracingPipelineFeaturesKHR", vk::StructureType::ePhysicalDeviceRayTracingPipelineFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceRayTracingPipelinePropertiesKHR", vk::StructureType::ePhysicalDeviceRayTracingPipelinePropertiesKHR);
    e_vk_StructureType.value("RayTracingPipelineCreateInfoKHR", vk::StructureType::eRayTracingPipelineCreateInfoKHR);
    e_vk_StructureType.value("RayTracingShaderGroupCreateInfoKHR", vk::StructureType::eRayTracingShaderGroupCreateInfoKHR);
    e_vk_StructureType.value("RayTracingPipelineInterfaceCreateInfoKHR", vk::StructureType::eRayTracingPipelineInterfaceCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceRayQueryFeaturesKHR", vk::StructureType::ePhysicalDeviceRayQueryFeaturesKHR);
    e_vk_StructureType.value("PipelineCoverageModulationStateCreateInfoNV", vk::StructureType::ePipelineCoverageModulationStateCreateInfoNV);
    e_vk_StructureType.value("PhysicalDeviceShaderSmBuiltinsFeaturesNV", vk::StructureType::ePhysicalDeviceShaderSmBuiltinsFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceShaderSmBuiltinsPropertiesNV", vk::StructureType::ePhysicalDeviceShaderSmBuiltinsPropertiesNV);
    e_vk_StructureType.value("SamplerYcbcrConversionCreateInfoKHR", vk::StructureType::eSamplerYcbcrConversionCreateInfoKHR);
    e_vk_StructureType.value("SamplerYcbcrConversionInfoKHR", vk::StructureType::eSamplerYcbcrConversionInfoKHR);
    e_vk_StructureType.value("BindImagePlaneMemoryInfoKHR", vk::StructureType::eBindImagePlaneMemoryInfoKHR);
    e_vk_StructureType.value("ImagePlaneMemoryRequirementsInfoKHR", vk::StructureType::eImagePlaneMemoryRequirementsInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceSamplerYcbcrConversionFeaturesKHR", vk::StructureType::ePhysicalDeviceSamplerYcbcrConversionFeaturesKHR);
    e_vk_StructureType.value("SamplerYcbcrConversionImageFormatPropertiesKHR", vk::StructureType::eSamplerYcbcrConversionImageFormatPropertiesKHR);
    e_vk_StructureType.value("BindBufferMemoryInfoKHR", vk::StructureType::eBindBufferMemoryInfoKHR);
    e_vk_StructureType.value("BindImageMemoryInfoKHR", vk::StructureType::eBindImageMemoryInfoKHR);
    e_vk_StructureType.value("DrmFormatModifierPropertiesListEXT", vk::StructureType::eDrmFormatModifierPropertiesListEXT);
    e_vk_StructureType.value("PhysicalDeviceImageDrmFormatModifierInfoEXT", vk::StructureType::ePhysicalDeviceImageDrmFormatModifierInfoEXT);
    e_vk_StructureType.value("ImageDrmFormatModifierListCreateInfoEXT", vk::StructureType::eImageDrmFormatModifierListCreateInfoEXT);
    e_vk_StructureType.value("ImageDrmFormatModifierExplicitCreateInfoEXT", vk::StructureType::eImageDrmFormatModifierExplicitCreateInfoEXT);
    e_vk_StructureType.value("ImageDrmFormatModifierPropertiesEXT", vk::StructureType::eImageDrmFormatModifierPropertiesEXT);
    e_vk_StructureType.value("DrmFormatModifierPropertiesList2EXT", vk::StructureType::eDrmFormatModifierPropertiesList2EXT);
    e_vk_StructureType.value("ValidationCacheCreateInfoEXT", vk::StructureType::eValidationCacheCreateInfoEXT);
    e_vk_StructureType.value("ShaderModuleValidationCacheCreateInfoEXT", vk::StructureType::eShaderModuleValidationCacheCreateInfoEXT);
    e_vk_StructureType.value("DescriptorSetLayoutBindingFlagsCreateInfoEXT", vk::StructureType::eDescriptorSetLayoutBindingFlagsCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceDescriptorIndexingFeaturesEXT", vk::StructureType::ePhysicalDeviceDescriptorIndexingFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceDescriptorIndexingPropertiesEXT", vk::StructureType::ePhysicalDeviceDescriptorIndexingPropertiesEXT);
    e_vk_StructureType.value("DescriptorSetVariableDescriptorCountAllocateInfoEXT", vk::StructureType::eDescriptorSetVariableDescriptorCountAllocateInfoEXT);
    e_vk_StructureType.value("DescriptorSetVariableDescriptorCountLayoutSupportEXT", vk::StructureType::eDescriptorSetVariableDescriptorCountLayoutSupportEXT);
    e_vk_StructureType.value("PipelineViewportShadingRateImageStateCreateInfoNV", vk::StructureType::ePipelineViewportShadingRateImageStateCreateInfoNV);
    e_vk_StructureType.value("PhysicalDeviceShadingRateImageFeaturesNV", vk::StructureType::ePhysicalDeviceShadingRateImageFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceShadingRateImagePropertiesNV", vk::StructureType::ePhysicalDeviceShadingRateImagePropertiesNV);
    e_vk_StructureType.value("PipelineViewportCoarseSampleOrderStateCreateInfoNV", vk::StructureType::ePipelineViewportCoarseSampleOrderStateCreateInfoNV);
    e_vk_StructureType.value("RayTracingPipelineCreateInfoNV", vk::StructureType::eRayTracingPipelineCreateInfoNV);
    e_vk_StructureType.value("AccelerationStructureCreateInfoNV", vk::StructureType::eAccelerationStructureCreateInfoNV);
    e_vk_StructureType.value("GeometryNV", vk::StructureType::eGeometryNV);
    e_vk_StructureType.value("GeometryTrianglesNV", vk::StructureType::eGeometryTrianglesNV);
    e_vk_StructureType.value("GeometryAabbNV", vk::StructureType::eGeometryAabbNV);
    e_vk_StructureType.value("BindAccelerationStructureMemoryInfoNV", vk::StructureType::eBindAccelerationStructureMemoryInfoNV);
    e_vk_StructureType.value("WriteDescriptorSetAccelerationStructureNV", vk::StructureType::eWriteDescriptorSetAccelerationStructureNV);
    e_vk_StructureType.value("AccelerationStructureMemoryRequirementsInfoNV", vk::StructureType::eAccelerationStructureMemoryRequirementsInfoNV);
    e_vk_StructureType.value("PhysicalDeviceRayTracingPropertiesNV", vk::StructureType::ePhysicalDeviceRayTracingPropertiesNV);
    e_vk_StructureType.value("RayTracingShaderGroupCreateInfoNV", vk::StructureType::eRayTracingShaderGroupCreateInfoNV);
    e_vk_StructureType.value("AccelerationStructureInfoNV", vk::StructureType::eAccelerationStructureInfoNV);
    e_vk_StructureType.value("PhysicalDeviceRepresentativeFragmentTestFeaturesNV", vk::StructureType::ePhysicalDeviceRepresentativeFragmentTestFeaturesNV);
    e_vk_StructureType.value("PipelineRepresentativeFragmentTestStateCreateInfoNV", vk::StructureType::ePipelineRepresentativeFragmentTestStateCreateInfoNV);
    e_vk_StructureType.value("PhysicalDeviceMaintenance3PropertiesKHR", vk::StructureType::ePhysicalDeviceMaintenance3PropertiesKHR);
    e_vk_StructureType.value("DescriptorSetLayoutSupportKHR", vk::StructureType::eDescriptorSetLayoutSupportKHR);
    e_vk_StructureType.value("PhysicalDeviceImageViewImageFormatInfoEXT", vk::StructureType::ePhysicalDeviceImageViewImageFormatInfoEXT);
    e_vk_StructureType.value("FilterCubicImageViewImageFormatPropertiesEXT", vk::StructureType::eFilterCubicImageViewImageFormatPropertiesEXT);
    e_vk_StructureType.value("DeviceQueueGlobalPriorityCreateInfoEXT", vk::StructureType::eDeviceQueueGlobalPriorityCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR", vk::StructureType::ePhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR);
    e_vk_StructureType.value("PhysicalDevice8BitStorageFeaturesKHR", vk::StructureType::ePhysicalDevice8BitStorageFeaturesKHR);
    e_vk_StructureType.value("ImportMemoryHostPointerInfoEXT", vk::StructureType::eImportMemoryHostPointerInfoEXT);
    e_vk_StructureType.value("MemoryHostPointerPropertiesEXT", vk::StructureType::eMemoryHostPointerPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceExternalMemoryHostPropertiesEXT", vk::StructureType::ePhysicalDeviceExternalMemoryHostPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderAtomicInt64FeaturesKHR", vk::StructureType::ePhysicalDeviceShaderAtomicInt64FeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceShaderClockFeaturesKHR", vk::StructureType::ePhysicalDeviceShaderClockFeaturesKHR);
    e_vk_StructureType.value("PipelineCompilerControlCreateInfoAMD", vk::StructureType::ePipelineCompilerControlCreateInfoAMD);
    e_vk_StructureType.value("CalibratedTimestampInfoEXT", vk::StructureType::eCalibratedTimestampInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderCorePropertiesAMD", vk::StructureType::ePhysicalDeviceShaderCorePropertiesAMD);
    e_vk_StructureType.value("VideoDecodeH265CapabilitiesKHR", vk::StructureType::eVideoDecodeH265CapabilitiesKHR);
    e_vk_StructureType.value("VideoDecodeH265SessionParametersCreateInfoKHR", vk::StructureType::eVideoDecodeH265SessionParametersCreateInfoKHR);
    e_vk_StructureType.value("VideoDecodeH265SessionParametersAddInfoKHR", vk::StructureType::eVideoDecodeH265SessionParametersAddInfoKHR);
    e_vk_StructureType.value("VideoDecodeH265ProfileInfoKHR", vk::StructureType::eVideoDecodeH265ProfileInfoKHR);
    e_vk_StructureType.value("VideoDecodeH265PictureInfoKHR", vk::StructureType::eVideoDecodeH265PictureInfoKHR);
    e_vk_StructureType.value("VideoDecodeH265DpbSlotInfoKHR", vk::StructureType::eVideoDecodeH265DpbSlotInfoKHR);
    e_vk_StructureType.value("DeviceQueueGlobalPriorityCreateInfoKHR", vk::StructureType::eDeviceQueueGlobalPriorityCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceGlobalPriorityQueryFeaturesKHR", vk::StructureType::ePhysicalDeviceGlobalPriorityQueryFeaturesKHR);
    e_vk_StructureType.value("QueueFamilyGlobalPriorityPropertiesKHR", vk::StructureType::eQueueFamilyGlobalPriorityPropertiesKHR);
    e_vk_StructureType.value("DeviceMemoryOverallocationCreateInfoAMD", vk::StructureType::eDeviceMemoryOverallocationCreateInfoAMD);
    e_vk_StructureType.value("PhysicalDeviceVertexAttributeDivisorPropertiesEXT", vk::StructureType::ePhysicalDeviceVertexAttributeDivisorPropertiesEXT);
    e_vk_StructureType.value("PipelineVertexInputDivisorStateCreateInfoEXT", vk::StructureType::ePipelineVertexInputDivisorStateCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceVertexAttributeDivisorFeaturesEXT", vk::StructureType::ePhysicalDeviceVertexAttributeDivisorFeaturesEXT);
    e_vk_StructureType.value("PipelineCreationFeedbackCreateInfoEXT", vk::StructureType::ePipelineCreationFeedbackCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceDriverPropertiesKHR", vk::StructureType::ePhysicalDeviceDriverPropertiesKHR);
    e_vk_StructureType.value("PhysicalDeviceFloatControlsPropertiesKHR", vk::StructureType::ePhysicalDeviceFloatControlsPropertiesKHR);
    e_vk_StructureType.value("PhysicalDeviceDepthStencilResolvePropertiesKHR", vk::StructureType::ePhysicalDeviceDepthStencilResolvePropertiesKHR);
    e_vk_StructureType.value("SubpassDescriptionDepthStencilResolveKHR", vk::StructureType::eSubpassDescriptionDepthStencilResolveKHR);
    e_vk_StructureType.value("PhysicalDeviceComputeShaderDerivativesFeaturesNV", vk::StructureType::ePhysicalDeviceComputeShaderDerivativesFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceMeshShaderFeaturesNV", vk::StructureType::ePhysicalDeviceMeshShaderFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceMeshShaderPropertiesNV", vk::StructureType::ePhysicalDeviceMeshShaderPropertiesNV);
    e_vk_StructureType.value("PhysicalDeviceFragmentShaderBarycentricFeaturesNV", vk::StructureType::ePhysicalDeviceFragmentShaderBarycentricFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceShaderImageFootprintFeaturesNV", vk::StructureType::ePhysicalDeviceShaderImageFootprintFeaturesNV);
    e_vk_StructureType.value("PipelineViewportExclusiveScissorStateCreateInfoNV", vk::StructureType::ePipelineViewportExclusiveScissorStateCreateInfoNV);
    e_vk_StructureType.value("PhysicalDeviceExclusiveScissorFeaturesNV", vk::StructureType::ePhysicalDeviceExclusiveScissorFeaturesNV);
    e_vk_StructureType.value("CheckpointDataNV", vk::StructureType::eCheckpointDataNV);
    e_vk_StructureType.value("QueueFamilyCheckpointPropertiesNV", vk::StructureType::eQueueFamilyCheckpointPropertiesNV);
    e_vk_StructureType.value("PhysicalDeviceTimelineSemaphoreFeaturesKHR", vk::StructureType::ePhysicalDeviceTimelineSemaphoreFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceTimelineSemaphorePropertiesKHR", vk::StructureType::ePhysicalDeviceTimelineSemaphorePropertiesKHR);
    e_vk_StructureType.value("SemaphoreTypeCreateInfoKHR", vk::StructureType::eSemaphoreTypeCreateInfoKHR);
    e_vk_StructureType.value("TimelineSemaphoreSubmitInfoKHR", vk::StructureType::eTimelineSemaphoreSubmitInfoKHR);
    e_vk_StructureType.value("SemaphoreWaitInfoKHR", vk::StructureType::eSemaphoreWaitInfoKHR);
    e_vk_StructureType.value("SemaphoreSignalInfoKHR", vk::StructureType::eSemaphoreSignalInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL", vk::StructureType::ePhysicalDeviceShaderIntegerFunctions2FeaturesINTEL);
    e_vk_StructureType.value("QueryPoolPerformanceQueryCreateInfoINTEL", vk::StructureType::eQueryPoolPerformanceQueryCreateInfoINTEL);
    e_vk_StructureType.value("QueryPoolCreateInfoINTEL", vk::StructureType::eQueryPoolCreateInfoINTEL);
    e_vk_StructureType.value("InitializePerformanceApiInfoINTEL", vk::StructureType::eInitializePerformanceApiInfoINTEL);
    e_vk_StructureType.value("PerformanceMarkerInfoINTEL", vk::StructureType::ePerformanceMarkerInfoINTEL);
    e_vk_StructureType.value("PerformanceStreamMarkerInfoINTEL", vk::StructureType::ePerformanceStreamMarkerInfoINTEL);
    e_vk_StructureType.value("PerformanceOverrideInfoINTEL", vk::StructureType::ePerformanceOverrideInfoINTEL);
    e_vk_StructureType.value("PerformanceConfigurationAcquireInfoINTEL", vk::StructureType::ePerformanceConfigurationAcquireInfoINTEL);
    e_vk_StructureType.value("PhysicalDeviceVulkanMemoryModelFeaturesKHR", vk::StructureType::ePhysicalDeviceVulkanMemoryModelFeaturesKHR);
    e_vk_StructureType.value("PhysicalDevicePciBusInfoPropertiesEXT", vk::StructureType::ePhysicalDevicePciBusInfoPropertiesEXT);
    e_vk_StructureType.value("DisplayNativeHdrSurfaceCapabilitiesAMD", vk::StructureType::eDisplayNativeHdrSurfaceCapabilitiesAMD);
    e_vk_StructureType.value("SwapchainDisplayNativeHdrCreateInfoAMD", vk::StructureType::eSwapchainDisplayNativeHdrCreateInfoAMD);
    e_vk_StructureType.value("PhysicalDeviceShaderTerminateInvocationFeaturesKHR", vk::StructureType::ePhysicalDeviceShaderTerminateInvocationFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceFragmentDensityMapFeaturesEXT", vk::StructureType::ePhysicalDeviceFragmentDensityMapFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceFragmentDensityMapPropertiesEXT", vk::StructureType::ePhysicalDeviceFragmentDensityMapPropertiesEXT);
    e_vk_StructureType.value("RenderPassFragmentDensityMapCreateInfoEXT", vk::StructureType::eRenderPassFragmentDensityMapCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceScalarBlockLayoutFeaturesEXT", vk::StructureType::ePhysicalDeviceScalarBlockLayoutFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceSubgroupSizeControlPropertiesEXT", vk::StructureType::ePhysicalDeviceSubgroupSizeControlPropertiesEXT);
    e_vk_StructureType.value("PipelineShaderStageRequiredSubgroupSizeCreateInfoEXT", vk::StructureType::ePipelineShaderStageRequiredSubgroupSizeCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceSubgroupSizeControlFeaturesEXT", vk::StructureType::ePhysicalDeviceSubgroupSizeControlFeaturesEXT);
    e_vk_StructureType.value("FragmentShadingRateAttachmentInfoKHR", vk::StructureType::eFragmentShadingRateAttachmentInfoKHR);
    e_vk_StructureType.value("PipelineFragmentShadingRateStateCreateInfoKHR", vk::StructureType::ePipelineFragmentShadingRateStateCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceFragmentShadingRatePropertiesKHR", vk::StructureType::ePhysicalDeviceFragmentShadingRatePropertiesKHR);
    e_vk_StructureType.value("PhysicalDeviceFragmentShadingRateFeaturesKHR", vk::StructureType::ePhysicalDeviceFragmentShadingRateFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceFragmentShadingRateKHR", vk::StructureType::ePhysicalDeviceFragmentShadingRateKHR);
    e_vk_StructureType.value("PhysicalDeviceShaderCoreProperties2AMD", vk::StructureType::ePhysicalDeviceShaderCoreProperties2AMD);
    e_vk_StructureType.value("PhysicalDeviceCoherentMemoryFeaturesAMD", vk::StructureType::ePhysicalDeviceCoherentMemoryFeaturesAMD);
    e_vk_StructureType.value("PhysicalDeviceShaderImageAtomicInt64FeaturesEXT", vk::StructureType::ePhysicalDeviceShaderImageAtomicInt64FeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceMemoryBudgetPropertiesEXT", vk::StructureType::ePhysicalDeviceMemoryBudgetPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceMemoryPriorityFeaturesEXT", vk::StructureType::ePhysicalDeviceMemoryPriorityFeaturesEXT);
    e_vk_StructureType.value("MemoryPriorityAllocateInfoEXT", vk::StructureType::eMemoryPriorityAllocateInfoEXT);
    e_vk_StructureType.value("SurfaceProtectedCapabilitiesKHR", vk::StructureType::eSurfaceProtectedCapabilitiesKHR);
    e_vk_StructureType.value("PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV", vk::StructureType::ePhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR", vk::StructureType::ePhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR);
    e_vk_StructureType.value("AttachmentReferenceStencilLayoutKHR", vk::StructureType::eAttachmentReferenceStencilLayoutKHR);
    e_vk_StructureType.value("AttachmentDescriptionStencilLayoutKHR", vk::StructureType::eAttachmentDescriptionStencilLayoutKHR);
    e_vk_StructureType.value("PhysicalDeviceBufferDeviceAddressFeaturesEXT", vk::StructureType::ePhysicalDeviceBufferDeviceAddressFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceBufferAddressFeaturesEXT", vk::StructureType::ePhysicalDeviceBufferAddressFeaturesEXT);
    e_vk_StructureType.value("BufferDeviceAddressInfoEXT", vk::StructureType::eBufferDeviceAddressInfoEXT);
    e_vk_StructureType.value("BufferDeviceAddressCreateInfoEXT", vk::StructureType::eBufferDeviceAddressCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceToolPropertiesEXT", vk::StructureType::ePhysicalDeviceToolPropertiesEXT);
    e_vk_StructureType.value("ImageStencilUsageCreateInfoEXT", vk::StructureType::eImageStencilUsageCreateInfoEXT);
    e_vk_StructureType.value("ValidationFeaturesEXT", vk::StructureType::eValidationFeaturesEXT);
    e_vk_StructureType.value("PhysicalDevicePresentWaitFeaturesKHR", vk::StructureType::ePhysicalDevicePresentWaitFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceCooperativeMatrixFeaturesNV", vk::StructureType::ePhysicalDeviceCooperativeMatrixFeaturesNV);
    e_vk_StructureType.value("CooperativeMatrixPropertiesNV", vk::StructureType::eCooperativeMatrixPropertiesNV);
    e_vk_StructureType.value("PhysicalDeviceCooperativeMatrixPropertiesNV", vk::StructureType::ePhysicalDeviceCooperativeMatrixPropertiesNV);
    e_vk_StructureType.value("PhysicalDeviceCoverageReductionModeFeaturesNV", vk::StructureType::ePhysicalDeviceCoverageReductionModeFeaturesNV);
    e_vk_StructureType.value("PipelineCoverageReductionStateCreateInfoNV", vk::StructureType::ePipelineCoverageReductionStateCreateInfoNV);
    e_vk_StructureType.value("FramebufferMixedSamplesCombinationNV", vk::StructureType::eFramebufferMixedSamplesCombinationNV);
    e_vk_StructureType.value("PhysicalDeviceFragmentShaderInterlockFeaturesEXT", vk::StructureType::ePhysicalDeviceFragmentShaderInterlockFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceYcbcrImageArraysFeaturesEXT", vk::StructureType::ePhysicalDeviceYcbcrImageArraysFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceUniformBufferStandardLayoutFeaturesKHR", vk::StructureType::ePhysicalDeviceUniformBufferStandardLayoutFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceProvokingVertexFeaturesEXT", vk::StructureType::ePhysicalDeviceProvokingVertexFeaturesEXT);
    e_vk_StructureType.value("PipelineRasterizationProvokingVertexStateCreateInfoEXT", vk::StructureType::ePipelineRasterizationProvokingVertexStateCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceProvokingVertexPropertiesEXT", vk::StructureType::ePhysicalDeviceProvokingVertexPropertiesEXT);
    e_vk_StructureType.value("HeadlessSurfaceCreateInfoEXT", vk::StructureType::eHeadlessSurfaceCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceBufferDeviceAddressFeaturesKHR", vk::StructureType::ePhysicalDeviceBufferDeviceAddressFeaturesKHR);
    e_vk_StructureType.value("BufferDeviceAddressInfoKHR", vk::StructureType::eBufferDeviceAddressInfoKHR);
    e_vk_StructureType.value("BufferOpaqueCaptureAddressCreateInfoKHR", vk::StructureType::eBufferOpaqueCaptureAddressCreateInfoKHR);
    e_vk_StructureType.value("MemoryOpaqueCaptureAddressAllocateInfoKHR", vk::StructureType::eMemoryOpaqueCaptureAddressAllocateInfoKHR);
    e_vk_StructureType.value("DeviceMemoryOpaqueCaptureAddressInfoKHR", vk::StructureType::eDeviceMemoryOpaqueCaptureAddressInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceLineRasterizationFeaturesEXT", vk::StructureType::ePhysicalDeviceLineRasterizationFeaturesEXT);
    e_vk_StructureType.value("PipelineRasterizationLineStateCreateInfoEXT", vk::StructureType::ePipelineRasterizationLineStateCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceLineRasterizationPropertiesEXT", vk::StructureType::ePhysicalDeviceLineRasterizationPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderAtomicFloatFeaturesEXT", vk::StructureType::ePhysicalDeviceShaderAtomicFloatFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceHostQueryResetFeaturesEXT", vk::StructureType::ePhysicalDeviceHostQueryResetFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceIndexTypeUint8FeaturesEXT", vk::StructureType::ePhysicalDeviceIndexTypeUint8FeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceExtendedDynamicStateFeaturesEXT", vk::StructureType::ePhysicalDeviceExtendedDynamicStateFeaturesEXT);
    e_vk_StructureType.value("PhysicalDevicePipelineExecutablePropertiesFeaturesKHR", vk::StructureType::ePhysicalDevicePipelineExecutablePropertiesFeaturesKHR);
    e_vk_StructureType.value("PipelineInfoKHR", vk::StructureType::ePipelineInfoKHR);
    e_vk_StructureType.value("PipelineExecutablePropertiesKHR", vk::StructureType::ePipelineExecutablePropertiesKHR);
    e_vk_StructureType.value("PipelineExecutableInfoKHR", vk::StructureType::ePipelineExecutableInfoKHR);
    e_vk_StructureType.value("PipelineExecutableStatisticKHR", vk::StructureType::ePipelineExecutableStatisticKHR);
    e_vk_StructureType.value("PipelineExecutableInternalRepresentationKHR", vk::StructureType::ePipelineExecutableInternalRepresentationKHR);
    e_vk_StructureType.value("PhysicalDeviceHostImageCopyFeaturesEXT", vk::StructureType::ePhysicalDeviceHostImageCopyFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceHostImageCopyPropertiesEXT", vk::StructureType::ePhysicalDeviceHostImageCopyPropertiesEXT);
    e_vk_StructureType.value("MemoryToImageCopyEXT", vk::StructureType::eMemoryToImageCopyEXT);
    e_vk_StructureType.value("ImageToMemoryCopyEXT", vk::StructureType::eImageToMemoryCopyEXT);
    e_vk_StructureType.value("CopyImageToMemoryInfoEXT", vk::StructureType::eCopyImageToMemoryInfoEXT);
    e_vk_StructureType.value("CopyMemoryToImageInfoEXT", vk::StructureType::eCopyMemoryToImageInfoEXT);
    e_vk_StructureType.value("HostImageLayoutTransitionInfoEXT", vk::StructureType::eHostImageLayoutTransitionInfoEXT);
    e_vk_StructureType.value("CopyImageToImageInfoEXT", vk::StructureType::eCopyImageToImageInfoEXT);
    e_vk_StructureType.value("SubresourceHostMemcpySizeEXT", vk::StructureType::eSubresourceHostMemcpySizeEXT);
    e_vk_StructureType.value("HostImageCopyDevicePerformanceQueryEXT", vk::StructureType::eHostImageCopyDevicePerformanceQueryEXT);
    e_vk_StructureType.value("MemoryMapInfoKHR", vk::StructureType::eMemoryMapInfoKHR);
    e_vk_StructureType.value("MemoryUnmapInfoKHR", vk::StructureType::eMemoryUnmapInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceShaderAtomicFloat2FeaturesEXT", vk::StructureType::ePhysicalDeviceShaderAtomicFloat2FeaturesEXT);
    e_vk_StructureType.value("SurfacePresentModeEXT", vk::StructureType::eSurfacePresentModeEXT);
    e_vk_StructureType.value("SurfacePresentScalingCapabilitiesEXT", vk::StructureType::eSurfacePresentScalingCapabilitiesEXT);
    e_vk_StructureType.value("SurfacePresentModeCompatibilityEXT", vk::StructureType::eSurfacePresentModeCompatibilityEXT);
    e_vk_StructureType.value("PhysicalDeviceSwapchainMaintenance1FeaturesEXT", vk::StructureType::ePhysicalDeviceSwapchainMaintenance1FeaturesEXT);
    e_vk_StructureType.value("SwapchainPresentFenceInfoEXT", vk::StructureType::eSwapchainPresentFenceInfoEXT);
    e_vk_StructureType.value("SwapchainPresentModesCreateInfoEXT", vk::StructureType::eSwapchainPresentModesCreateInfoEXT);
    e_vk_StructureType.value("SwapchainPresentModeInfoEXT", vk::StructureType::eSwapchainPresentModeInfoEXT);
    e_vk_StructureType.value("SwapchainPresentScalingCreateInfoEXT", vk::StructureType::eSwapchainPresentScalingCreateInfoEXT);
    e_vk_StructureType.value("ReleaseSwapchainImagesInfoEXT", vk::StructureType::eReleaseSwapchainImagesInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT", vk::StructureType::ePhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceDeviceGeneratedCommandsPropertiesNV", vk::StructureType::ePhysicalDeviceDeviceGeneratedCommandsPropertiesNV);
    e_vk_StructureType.value("GraphicsShaderGroupCreateInfoNV", vk::StructureType::eGraphicsShaderGroupCreateInfoNV);
    e_vk_StructureType.value("GraphicsPipelineShaderGroupsCreateInfoNV", vk::StructureType::eGraphicsPipelineShaderGroupsCreateInfoNV);
    e_vk_StructureType.value("IndirectCommandsLayoutTokenNV", vk::StructureType::eIndirectCommandsLayoutTokenNV);
    e_vk_StructureType.value("IndirectCommandsLayoutCreateInfoNV", vk::StructureType::eIndirectCommandsLayoutCreateInfoNV);
    e_vk_StructureType.value("GeneratedCommandsInfoNV", vk::StructureType::eGeneratedCommandsInfoNV);
    e_vk_StructureType.value("GeneratedCommandsMemoryRequirementsInfoNV", vk::StructureType::eGeneratedCommandsMemoryRequirementsInfoNV);
    e_vk_StructureType.value("PhysicalDeviceDeviceGeneratedCommandsFeaturesNV", vk::StructureType::ePhysicalDeviceDeviceGeneratedCommandsFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceInheritedViewportScissorFeaturesNV", vk::StructureType::ePhysicalDeviceInheritedViewportScissorFeaturesNV);
    e_vk_StructureType.value("CommandBufferInheritanceViewportScissorInfoNV", vk::StructureType::eCommandBufferInheritanceViewportScissorInfoNV);
    e_vk_StructureType.value("PhysicalDeviceShaderIntegerDotProductFeaturesKHR", vk::StructureType::ePhysicalDeviceShaderIntegerDotProductFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceShaderIntegerDotProductPropertiesKHR", vk::StructureType::ePhysicalDeviceShaderIntegerDotProductPropertiesKHR);
    e_vk_StructureType.value("PhysicalDeviceTexelBufferAlignmentFeaturesEXT", vk::StructureType::ePhysicalDeviceTexelBufferAlignmentFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceTexelBufferAlignmentPropertiesEXT", vk::StructureType::ePhysicalDeviceTexelBufferAlignmentPropertiesEXT);
    e_vk_StructureType.value("CommandBufferInheritanceRenderPassTransformInfoQCOM", vk::StructureType::eCommandBufferInheritanceRenderPassTransformInfoQCOM);
    e_vk_StructureType.value("RenderPassTransformBeginInfoQCOM", vk::StructureType::eRenderPassTransformBeginInfoQCOM);
    e_vk_StructureType.value("PhysicalDeviceDepthBiasControlFeaturesEXT", vk::StructureType::ePhysicalDeviceDepthBiasControlFeaturesEXT);
    e_vk_StructureType.value("DepthBiasInfoEXT", vk::StructureType::eDepthBiasInfoEXT);
    e_vk_StructureType.value("DepthBiasRepresentationInfoEXT", vk::StructureType::eDepthBiasRepresentationInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceDeviceMemoryReportFeaturesEXT", vk::StructureType::ePhysicalDeviceDeviceMemoryReportFeaturesEXT);
    e_vk_StructureType.value("DeviceDeviceMemoryReportCreateInfoEXT", vk::StructureType::eDeviceDeviceMemoryReportCreateInfoEXT);
    e_vk_StructureType.value("DeviceMemoryReportCallbackDataEXT", vk::StructureType::eDeviceMemoryReportCallbackDataEXT);
    e_vk_StructureType.value("PhysicalDeviceRobustness2FeaturesEXT", vk::StructureType::ePhysicalDeviceRobustness2FeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceRobustness2PropertiesEXT", vk::StructureType::ePhysicalDeviceRobustness2PropertiesEXT);
    e_vk_StructureType.value("SamplerCustomBorderColorCreateInfoEXT", vk::StructureType::eSamplerCustomBorderColorCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceCustomBorderColorPropertiesEXT", vk::StructureType::ePhysicalDeviceCustomBorderColorPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceCustomBorderColorFeaturesEXT", vk::StructureType::ePhysicalDeviceCustomBorderColorFeaturesEXT);
    e_vk_StructureType.value("PipelineLibraryCreateInfoKHR", vk::StructureType::ePipelineLibraryCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDevicePresentBarrierFeaturesNV", vk::StructureType::ePhysicalDevicePresentBarrierFeaturesNV);
    e_vk_StructureType.value("SurfaceCapabilitiesPresentBarrierNV", vk::StructureType::eSurfaceCapabilitiesPresentBarrierNV);
    e_vk_StructureType.value("SwapchainPresentBarrierCreateInfoNV", vk::StructureType::eSwapchainPresentBarrierCreateInfoNV);
    e_vk_StructureType.value("PresentIdKHR", vk::StructureType::ePresentIdKHR);
    e_vk_StructureType.value("PhysicalDevicePresentIdFeaturesKHR", vk::StructureType::ePhysicalDevicePresentIdFeaturesKHR);
    e_vk_StructureType.value("PhysicalDevicePrivateDataFeaturesEXT", vk::StructureType::ePhysicalDevicePrivateDataFeaturesEXT);
    e_vk_StructureType.value("DevicePrivateDataCreateInfoEXT", vk::StructureType::eDevicePrivateDataCreateInfoEXT);
    e_vk_StructureType.value("PrivateDataSlotCreateInfoEXT", vk::StructureType::ePrivateDataSlotCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDevicePipelineCreationCacheControlFeaturesEXT", vk::StructureType::ePhysicalDevicePipelineCreationCacheControlFeaturesEXT);
    e_vk_StructureType.value("VideoEncodeInfoKHR", vk::StructureType::eVideoEncodeInfoKHR);
    e_vk_StructureType.value("VideoEncodeRateControlInfoKHR", vk::StructureType::eVideoEncodeRateControlInfoKHR);
    e_vk_StructureType.value("VideoEncodeRateControlLayerInfoKHR", vk::StructureType::eVideoEncodeRateControlLayerInfoKHR);
    e_vk_StructureType.value("VideoEncodeCapabilitiesKHR", vk::StructureType::eVideoEncodeCapabilitiesKHR);
    e_vk_StructureType.value("VideoEncodeUsageInfoKHR", vk::StructureType::eVideoEncodeUsageInfoKHR);
    e_vk_StructureType.value("QueryPoolVideoEncodeFeedbackCreateInfoKHR", vk::StructureType::eQueryPoolVideoEncodeFeedbackCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceVideoEncodeQualityLevelInfoKHR", vk::StructureType::ePhysicalDeviceVideoEncodeQualityLevelInfoKHR);
    e_vk_StructureType.value("VideoEncodeQualityLevelPropertiesKHR", vk::StructureType::eVideoEncodeQualityLevelPropertiesKHR);
    e_vk_StructureType.value("VideoEncodeQualityLevelInfoKHR", vk::StructureType::eVideoEncodeQualityLevelInfoKHR);
    e_vk_StructureType.value("VideoEncodeSessionParametersGetInfoKHR", vk::StructureType::eVideoEncodeSessionParametersGetInfoKHR);
    e_vk_StructureType.value("VideoEncodeSessionParametersFeedbackInfoKHR", vk::StructureType::eVideoEncodeSessionParametersFeedbackInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceDiagnosticsConfigFeaturesNV", vk::StructureType::ePhysicalDeviceDiagnosticsConfigFeaturesNV);
    e_vk_StructureType.value("DeviceDiagnosticsConfigCreateInfoNV", vk::StructureType::eDeviceDiagnosticsConfigCreateInfoNV);
    e_vk_StructureType.value("QueryLowLatencySupportNV", vk::StructureType::eQueryLowLatencySupportNV);
    e_vk_StructureType.value("MemoryBarrier2KHR", vk::StructureType::eMemoryBarrier2KHR);
    e_vk_StructureType.value("BufferMemoryBarrier2KHR", vk::StructureType::eBufferMemoryBarrier2KHR);
    e_vk_StructureType.value("ImageMemoryBarrier2KHR", vk::StructureType::eImageMemoryBarrier2KHR);
    e_vk_StructureType.value("DependencyInfoKHR", vk::StructureType::eDependencyInfoKHR);
    e_vk_StructureType.value("SubmitInfo2KHR", vk::StructureType::eSubmitInfo2KHR);
    e_vk_StructureType.value("SemaphoreSubmitInfoKHR", vk::StructureType::eSemaphoreSubmitInfoKHR);
    e_vk_StructureType.value("CommandBufferSubmitInfoKHR", vk::StructureType::eCommandBufferSubmitInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceSynchronization2FeaturesKHR", vk::StructureType::ePhysicalDeviceSynchronization2FeaturesKHR);
    e_vk_StructureType.value("QueueFamilyCheckpointProperties2NV", vk::StructureType::eQueueFamilyCheckpointProperties2NV);
    e_vk_StructureType.value("CheckpointData2NV", vk::StructureType::eCheckpointData2NV);
    e_vk_StructureType.value("PhysicalDeviceDescriptorBufferPropertiesEXT", vk::StructureType::ePhysicalDeviceDescriptorBufferPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT", vk::StructureType::ePhysicalDeviceDescriptorBufferDensityMapPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceDescriptorBufferFeaturesEXT", vk::StructureType::ePhysicalDeviceDescriptorBufferFeaturesEXT);
    e_vk_StructureType.value("DescriptorAddressInfoEXT", vk::StructureType::eDescriptorAddressInfoEXT);
    e_vk_StructureType.value("DescriptorGetInfoEXT", vk::StructureType::eDescriptorGetInfoEXT);
    e_vk_StructureType.value("BufferCaptureDescriptorDataInfoEXT", vk::StructureType::eBufferCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("ImageCaptureDescriptorDataInfoEXT", vk::StructureType::eImageCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("ImageViewCaptureDescriptorDataInfoEXT", vk::StructureType::eImageViewCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("SamplerCaptureDescriptorDataInfoEXT", vk::StructureType::eSamplerCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("OpaqueCaptureDescriptorDataCreateInfoEXT", vk::StructureType::eOpaqueCaptureDescriptorDataCreateInfoEXT);
    e_vk_StructureType.value("DescriptorBufferBindingInfoEXT", vk::StructureType::eDescriptorBufferBindingInfoEXT);
    e_vk_StructureType.value("DescriptorBufferBindingPushDescriptorBufferHandleEXT", vk::StructureType::eDescriptorBufferBindingPushDescriptorBufferHandleEXT);
    e_vk_StructureType.value("AccelerationStructureCaptureDescriptorDataInfoEXT", vk::StructureType::eAccelerationStructureCaptureDescriptorDataInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT", vk::StructureType::ePhysicalDeviceGraphicsPipelineLibraryFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT", vk::StructureType::ePhysicalDeviceGraphicsPipelineLibraryPropertiesEXT);
    e_vk_StructureType.value("GraphicsPipelineLibraryCreateInfoEXT", vk::StructureType::eGraphicsPipelineLibraryCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD", vk::StructureType::ePhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD);
    e_vk_StructureType.value("PhysicalDeviceFragmentShaderBarycentricFeaturesKHR", vk::StructureType::ePhysicalDeviceFragmentShaderBarycentricFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceFragmentShaderBarycentricPropertiesKHR", vk::StructureType::ePhysicalDeviceFragmentShaderBarycentricPropertiesKHR);
    e_vk_StructureType.value("PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR", vk::StructureType::ePhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR", vk::StructureType::ePhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceFragmentShadingRateEnumsPropertiesNV", vk::StructureType::ePhysicalDeviceFragmentShadingRateEnumsPropertiesNV);
    e_vk_StructureType.value("PhysicalDeviceFragmentShadingRateEnumsFeaturesNV", vk::StructureType::ePhysicalDeviceFragmentShadingRateEnumsFeaturesNV);
    e_vk_StructureType.value("PipelineFragmentShadingRateEnumStateCreateInfoNV", vk::StructureType::ePipelineFragmentShadingRateEnumStateCreateInfoNV);
    e_vk_StructureType.value("AccelerationStructureGeometryMotionTrianglesDataNV", vk::StructureType::eAccelerationStructureGeometryMotionTrianglesDataNV);
    e_vk_StructureType.value("PhysicalDeviceRayTracingMotionBlurFeaturesNV", vk::StructureType::ePhysicalDeviceRayTracingMotionBlurFeaturesNV);
    e_vk_StructureType.value("AccelerationStructureMotionInfoNV", vk::StructureType::eAccelerationStructureMotionInfoNV);
    e_vk_StructureType.value("PhysicalDeviceMeshShaderFeaturesEXT", vk::StructureType::ePhysicalDeviceMeshShaderFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceMeshShaderPropertiesEXT", vk::StructureType::ePhysicalDeviceMeshShaderPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT", vk::StructureType::ePhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceFragmentDensityMap2FeaturesEXT", vk::StructureType::ePhysicalDeviceFragmentDensityMap2FeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceFragmentDensityMap2PropertiesEXT", vk::StructureType::ePhysicalDeviceFragmentDensityMap2PropertiesEXT);
    e_vk_StructureType.value("CopyCommandTransformInfoQCOM", vk::StructureType::eCopyCommandTransformInfoQCOM);
    e_vk_StructureType.value("PhysicalDeviceImageRobustnessFeaturesEXT", vk::StructureType::ePhysicalDeviceImageRobustnessFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR", vk::StructureType::ePhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR);
    e_vk_StructureType.value("CopyBufferInfo2KHR", vk::StructureType::eCopyBufferInfo2KHR);
    e_vk_StructureType.value("CopyImageInfo2KHR", vk::StructureType::eCopyImageInfo2KHR);
    e_vk_StructureType.value("CopyBufferToImageInfo2KHR", vk::StructureType::eCopyBufferToImageInfo2KHR);
    e_vk_StructureType.value("CopyImageToBufferInfo2KHR", vk::StructureType::eCopyImageToBufferInfo2KHR);
    e_vk_StructureType.value("BlitImageInfo2KHR", vk::StructureType::eBlitImageInfo2KHR);
    e_vk_StructureType.value("ResolveImageInfo2KHR", vk::StructureType::eResolveImageInfo2KHR);
    e_vk_StructureType.value("BufferCopy2KHR", vk::StructureType::eBufferCopy2KHR);
    e_vk_StructureType.value("ImageCopy2KHR", vk::StructureType::eImageCopy2KHR);
    e_vk_StructureType.value("ImageBlit2KHR", vk::StructureType::eImageBlit2KHR);
    e_vk_StructureType.value("BufferImageCopy2KHR", vk::StructureType::eBufferImageCopy2KHR);
    e_vk_StructureType.value("ImageResolve2KHR", vk::StructureType::eImageResolve2KHR);
    e_vk_StructureType.value("PhysicalDeviceImageCompressionControlFeaturesEXT", vk::StructureType::ePhysicalDeviceImageCompressionControlFeaturesEXT);
    e_vk_StructureType.value("ImageCompressionControlEXT", vk::StructureType::eImageCompressionControlEXT);
    e_vk_StructureType.value("SubresourceLayout2EXT", vk::StructureType::eSubresourceLayout2EXT);
    e_vk_StructureType.value("ImageSubresource2EXT", vk::StructureType::eImageSubresource2EXT);
    e_vk_StructureType.value("ImageCompressionPropertiesEXT", vk::StructureType::eImageCompressionPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT", vk::StructureType::ePhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT);
    e_vk_StructureType.value("PhysicalDevice4444FormatsFeaturesEXT", vk::StructureType::ePhysicalDevice4444FormatsFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceFaultFeaturesEXT", vk::StructureType::ePhysicalDeviceFaultFeaturesEXT);
    e_vk_StructureType.value("DeviceFaultCountsEXT", vk::StructureType::eDeviceFaultCountsEXT);
    e_vk_StructureType.value("DeviceFaultInfoEXT", vk::StructureType::eDeviceFaultInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM", vk::StructureType::ePhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM);
    e_vk_StructureType.value("PhysicalDeviceRgba10X6FormatsFeaturesEXT", vk::StructureType::ePhysicalDeviceRgba10X6FormatsFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceMutableDescriptorTypeFeaturesVALVE", vk::StructureType::ePhysicalDeviceMutableDescriptorTypeFeaturesVALVE);
    e_vk_StructureType.value("MutableDescriptorTypeCreateInfoVALVE", vk::StructureType::eMutableDescriptorTypeCreateInfoVALVE);
    e_vk_StructureType.value("PhysicalDeviceVertexInputDynamicStateFeaturesEXT", vk::StructureType::ePhysicalDeviceVertexInputDynamicStateFeaturesEXT);
    e_vk_StructureType.value("VertexInputBindingDescription2EXT", vk::StructureType::eVertexInputBindingDescription2EXT);
    e_vk_StructureType.value("VertexInputAttributeDescription2EXT", vk::StructureType::eVertexInputAttributeDescription2EXT);
    e_vk_StructureType.value("PhysicalDeviceDrmPropertiesEXT", vk::StructureType::ePhysicalDeviceDrmPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceAddressBindingReportFeaturesEXT", vk::StructureType::ePhysicalDeviceAddressBindingReportFeaturesEXT);
    e_vk_StructureType.value("DeviceAddressBindingCallbackDataEXT", vk::StructureType::eDeviceAddressBindingCallbackDataEXT);
    e_vk_StructureType.value("PhysicalDeviceDepthClipControlFeaturesEXT", vk::StructureType::ePhysicalDeviceDepthClipControlFeaturesEXT);
    e_vk_StructureType.value("PipelineViewportDepthClipControlCreateInfoEXT", vk::StructureType::ePipelineViewportDepthClipControlCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT", vk::StructureType::ePhysicalDevicePrimitiveTopologyListRestartFeaturesEXT);
    e_vk_StructureType.value("FormatProperties3KHR", vk::StructureType::eFormatProperties3KHR);
    e_vk_StructureType.value("SubpassShadingPipelineCreateInfoHUAWEI", vk::StructureType::eSubpassShadingPipelineCreateInfoHUAWEI);
    e_vk_StructureType.value("PhysicalDeviceSubpassShadingFeaturesHUAWEI", vk::StructureType::ePhysicalDeviceSubpassShadingFeaturesHUAWEI);
    e_vk_StructureType.value("PhysicalDeviceSubpassShadingPropertiesHUAWEI", vk::StructureType::ePhysicalDeviceSubpassShadingPropertiesHUAWEI);
    e_vk_StructureType.value("PhysicalDeviceInvocationMaskFeaturesHUAWEI", vk::StructureType::ePhysicalDeviceInvocationMaskFeaturesHUAWEI);
    e_vk_StructureType.value("MemoryGetRemoteAddressInfoNV", vk::StructureType::eMemoryGetRemoteAddressInfoNV);
    e_vk_StructureType.value("PhysicalDeviceExternalMemoryRdmaFeaturesNV", vk::StructureType::ePhysicalDeviceExternalMemoryRdmaFeaturesNV);
    e_vk_StructureType.value("PipelinePropertiesIdentifierEXT", vk::StructureType::ePipelinePropertiesIdentifierEXT);
    e_vk_StructureType.value("PhysicalDevicePipelinePropertiesFeaturesEXT", vk::StructureType::ePhysicalDevicePipelinePropertiesFeaturesEXT);
    e_vk_StructureType.value("PipelineInfoEXT", vk::StructureType::ePipelineInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceFrameBoundaryFeaturesEXT", vk::StructureType::ePhysicalDeviceFrameBoundaryFeaturesEXT);
    e_vk_StructureType.value("FrameBoundaryEXT", vk::StructureType::eFrameBoundaryEXT);
    e_vk_StructureType.value("PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT", vk::StructureType::ePhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT);
    e_vk_StructureType.value("SubpassResolvePerformanceQueryEXT", vk::StructureType::eSubpassResolvePerformanceQueryEXT);
    e_vk_StructureType.value("MultisampledRenderToSingleSampledInfoEXT", vk::StructureType::eMultisampledRenderToSingleSampledInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceExtendedDynamicState2FeaturesEXT", vk::StructureType::ePhysicalDeviceExtendedDynamicState2FeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceColorWriteEnableFeaturesEXT", vk::StructureType::ePhysicalDeviceColorWriteEnableFeaturesEXT);
    e_vk_StructureType.value("PipelineColorWriteCreateInfoEXT", vk::StructureType::ePipelineColorWriteCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT", vk::StructureType::ePhysicalDevicePrimitivesGeneratedQueryFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceRayTracingMaintenance1FeaturesKHR", vk::StructureType::ePhysicalDeviceRayTracingMaintenance1FeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceGlobalPriorityQueryFeaturesEXT", vk::StructureType::ePhysicalDeviceGlobalPriorityQueryFeaturesEXT);
    e_vk_StructureType.value("QueueFamilyGlobalPriorityPropertiesEXT", vk::StructureType::eQueueFamilyGlobalPriorityPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceImageViewMinLodFeaturesEXT", vk::StructureType::ePhysicalDeviceImageViewMinLodFeaturesEXT);
    e_vk_StructureType.value("ImageViewMinLodCreateInfoEXT", vk::StructureType::eImageViewMinLodCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceMultiDrawFeaturesEXT", vk::StructureType::ePhysicalDeviceMultiDrawFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceMultiDrawPropertiesEXT", vk::StructureType::ePhysicalDeviceMultiDrawPropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceImage2DViewOf3DFeaturesEXT", vk::StructureType::ePhysicalDeviceImage2DViewOf3DFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderTileImageFeaturesEXT", vk::StructureType::ePhysicalDeviceShaderTileImageFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderTileImagePropertiesEXT", vk::StructureType::ePhysicalDeviceShaderTileImagePropertiesEXT);
    e_vk_StructureType.value("MicromapBuildInfoEXT", vk::StructureType::eMicromapBuildInfoEXT);
    e_vk_StructureType.value("MicromapVersionInfoEXT", vk::StructureType::eMicromapVersionInfoEXT);
    e_vk_StructureType.value("CopyMicromapInfoEXT", vk::StructureType::eCopyMicromapInfoEXT);
    e_vk_StructureType.value("CopyMicromapToMemoryInfoEXT", vk::StructureType::eCopyMicromapToMemoryInfoEXT);
    e_vk_StructureType.value("CopyMemoryToMicromapInfoEXT", vk::StructureType::eCopyMemoryToMicromapInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceOpacityMicromapFeaturesEXT", vk::StructureType::ePhysicalDeviceOpacityMicromapFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceOpacityMicromapPropertiesEXT", vk::StructureType::ePhysicalDeviceOpacityMicromapPropertiesEXT);
    e_vk_StructureType.value("MicromapCreateInfoEXT", vk::StructureType::eMicromapCreateInfoEXT);
    e_vk_StructureType.value("MicromapBuildSizesInfoEXT", vk::StructureType::eMicromapBuildSizesInfoEXT);
    e_vk_StructureType.value("AccelerationStructureTrianglesOpacityMicromapEXT", vk::StructureType::eAccelerationStructureTrianglesOpacityMicromapEXT);
    e_vk_StructureType.value("PhysicalDeviceClusterCullingShaderFeaturesHUAWEI", vk::StructureType::ePhysicalDeviceClusterCullingShaderFeaturesHUAWEI);
    e_vk_StructureType.value("PhysicalDeviceClusterCullingShaderPropertiesHUAWEI", vk::StructureType::ePhysicalDeviceClusterCullingShaderPropertiesHUAWEI);
    e_vk_StructureType.value("PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI", vk::StructureType::ePhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI);
    e_vk_StructureType.value("PhysicalDeviceBorderColorSwizzleFeaturesEXT", vk::StructureType::ePhysicalDeviceBorderColorSwizzleFeaturesEXT);
    e_vk_StructureType.value("SamplerBorderColorComponentMappingCreateInfoEXT", vk::StructureType::eSamplerBorderColorComponentMappingCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT", vk::StructureType::ePhysicalDevicePageableDeviceLocalMemoryFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceMaintenance4FeaturesKHR", vk::StructureType::ePhysicalDeviceMaintenance4FeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceMaintenance4PropertiesKHR", vk::StructureType::ePhysicalDeviceMaintenance4PropertiesKHR);
    e_vk_StructureType.value("DeviceBufferMemoryRequirementsKHR", vk::StructureType::eDeviceBufferMemoryRequirementsKHR);
    e_vk_StructureType.value("DeviceImageMemoryRequirementsKHR", vk::StructureType::eDeviceImageMemoryRequirementsKHR);
    e_vk_StructureType.value("PhysicalDeviceShaderCorePropertiesARM", vk::StructureType::ePhysicalDeviceShaderCorePropertiesARM);
    e_vk_StructureType.value("DeviceQueueShaderCoreControlCreateInfoARM", vk::StructureType::eDeviceQueueShaderCoreControlCreateInfoARM);
    e_vk_StructureType.value("PhysicalDeviceSchedulingControlsFeaturesARM", vk::StructureType::ePhysicalDeviceSchedulingControlsFeaturesARM);
    e_vk_StructureType.value("PhysicalDeviceSchedulingControlsPropertiesARM", vk::StructureType::ePhysicalDeviceSchedulingControlsPropertiesARM);
    e_vk_StructureType.value("PhysicalDeviceImageSlicedViewOf3DFeaturesEXT", vk::StructureType::ePhysicalDeviceImageSlicedViewOf3DFeaturesEXT);
    e_vk_StructureType.value("ImageViewSlicedCreateInfoEXT", vk::StructureType::eImageViewSlicedCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE", vk::StructureType::ePhysicalDeviceDescriptorSetHostMappingFeaturesVALVE);
    e_vk_StructureType.value("DescriptorSetBindingReferenceVALVE", vk::StructureType::eDescriptorSetBindingReferenceVALVE);
    e_vk_StructureType.value("DescriptorSetLayoutHostMappingInfoVALVE", vk::StructureType::eDescriptorSetLayoutHostMappingInfoVALVE);
    e_vk_StructureType.value("PhysicalDeviceDepthClampZeroOneFeaturesEXT", vk::StructureType::ePhysicalDeviceDepthClampZeroOneFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceNonSeamlessCubeMapFeaturesEXT", vk::StructureType::ePhysicalDeviceNonSeamlessCubeMapFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceRenderPassStripedFeaturesARM", vk::StructureType::ePhysicalDeviceRenderPassStripedFeaturesARM);
    e_vk_StructureType.value("PhysicalDeviceRenderPassStripedPropertiesARM", vk::StructureType::ePhysicalDeviceRenderPassStripedPropertiesARM);
    e_vk_StructureType.value("RenderPassStripeBeginInfoARM", vk::StructureType::eRenderPassStripeBeginInfoARM);
    e_vk_StructureType.value("RenderPassStripeInfoARM", vk::StructureType::eRenderPassStripeInfoARM);
    e_vk_StructureType.value("RenderPassStripeSubmitInfoARM", vk::StructureType::eRenderPassStripeSubmitInfoARM);
    e_vk_StructureType.value("PhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM", vk::StructureType::ePhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM);
    e_vk_StructureType.value("PhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM", vk::StructureType::ePhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM);
    e_vk_StructureType.value("SubpassFragmentDensityMapOffsetEndInfoQCOM", vk::StructureType::eSubpassFragmentDensityMapOffsetEndInfoQCOM);
    e_vk_StructureType.value("PhysicalDeviceCopyMemoryIndirectFeaturesNV", vk::StructureType::ePhysicalDeviceCopyMemoryIndirectFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceCopyMemoryIndirectPropertiesNV", vk::StructureType::ePhysicalDeviceCopyMemoryIndirectPropertiesNV);
    e_vk_StructureType.value("PhysicalDeviceMemoryDecompressionFeaturesNV", vk::StructureType::ePhysicalDeviceMemoryDecompressionFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceMemoryDecompressionPropertiesNV", vk::StructureType::ePhysicalDeviceMemoryDecompressionPropertiesNV);
    e_vk_StructureType.value("PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV", vk::StructureType::ePhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV);
    e_vk_StructureType.value("ComputePipelineIndirectBufferInfoNV", vk::StructureType::eComputePipelineIndirectBufferInfoNV);
    e_vk_StructureType.value("PipelineIndirectDeviceAddressInfoNV", vk::StructureType::ePipelineIndirectDeviceAddressInfoNV);
    e_vk_StructureType.value("PhysicalDeviceLinearColorAttachmentFeaturesNV", vk::StructureType::ePhysicalDeviceLinearColorAttachmentFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT", vk::StructureType::ePhysicalDeviceImageCompressionControlSwapchainFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceImageProcessingFeaturesQCOM", vk::StructureType::ePhysicalDeviceImageProcessingFeaturesQCOM);
    e_vk_StructureType.value("PhysicalDeviceImageProcessingPropertiesQCOM", vk::StructureType::ePhysicalDeviceImageProcessingPropertiesQCOM);
    e_vk_StructureType.value("ImageViewSampleWeightCreateInfoQCOM", vk::StructureType::eImageViewSampleWeightCreateInfoQCOM);
    e_vk_StructureType.value("PhysicalDeviceNestedCommandBufferFeaturesEXT", vk::StructureType::ePhysicalDeviceNestedCommandBufferFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceNestedCommandBufferPropertiesEXT", vk::StructureType::ePhysicalDeviceNestedCommandBufferPropertiesEXT);
    e_vk_StructureType.value("ExternalMemoryAcquireUnmodifiedEXT", vk::StructureType::eExternalMemoryAcquireUnmodifiedEXT);
    e_vk_StructureType.value("PhysicalDeviceExtendedDynamicState3FeaturesEXT", vk::StructureType::ePhysicalDeviceExtendedDynamicState3FeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceExtendedDynamicState3PropertiesEXT", vk::StructureType::ePhysicalDeviceExtendedDynamicState3PropertiesEXT);
    e_vk_StructureType.value("PhysicalDeviceSubpassMergeFeedbackFeaturesEXT", vk::StructureType::ePhysicalDeviceSubpassMergeFeedbackFeaturesEXT);
    e_vk_StructureType.value("RenderPassCreationControlEXT", vk::StructureType::eRenderPassCreationControlEXT);
    e_vk_StructureType.value("RenderPassCreationFeedbackCreateInfoEXT", vk::StructureType::eRenderPassCreationFeedbackCreateInfoEXT);
    e_vk_StructureType.value("RenderPassSubpassFeedbackCreateInfoEXT", vk::StructureType::eRenderPassSubpassFeedbackCreateInfoEXT);
    e_vk_StructureType.value("DirectDriverLoadingInfoLUNARG", vk::StructureType::eDirectDriverLoadingInfoLUNARG);
    e_vk_StructureType.value("DirectDriverLoadingListLUNARG", vk::StructureType::eDirectDriverLoadingListLUNARG);
    e_vk_StructureType.value("PhysicalDeviceShaderModuleIdentifierFeaturesEXT", vk::StructureType::ePhysicalDeviceShaderModuleIdentifierFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderModuleIdentifierPropertiesEXT", vk::StructureType::ePhysicalDeviceShaderModuleIdentifierPropertiesEXT);
    e_vk_StructureType.value("PipelineShaderStageModuleIdentifierCreateInfoEXT", vk::StructureType::ePipelineShaderStageModuleIdentifierCreateInfoEXT);
    e_vk_StructureType.value("ShaderModuleIdentifierEXT", vk::StructureType::eShaderModuleIdentifierEXT);
    e_vk_StructureType.value("PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT", vk::StructureType::ePhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceOpticalFlowFeaturesNV", vk::StructureType::ePhysicalDeviceOpticalFlowFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceOpticalFlowPropertiesNV", vk::StructureType::ePhysicalDeviceOpticalFlowPropertiesNV);
    e_vk_StructureType.value("OpticalFlowImageFormatInfoNV", vk::StructureType::eOpticalFlowImageFormatInfoNV);
    e_vk_StructureType.value("OpticalFlowImageFormatPropertiesNV", vk::StructureType::eOpticalFlowImageFormatPropertiesNV);
    e_vk_StructureType.value("OpticalFlowSessionCreateInfoNV", vk::StructureType::eOpticalFlowSessionCreateInfoNV);
    e_vk_StructureType.value("OpticalFlowExecuteInfoNV", vk::StructureType::eOpticalFlowExecuteInfoNV);
    e_vk_StructureType.value("OpticalFlowSessionCreatePrivateDataInfoNV", vk::StructureType::eOpticalFlowSessionCreatePrivateDataInfoNV);
    e_vk_StructureType.value("PhysicalDeviceLegacyDitheringFeaturesEXT", vk::StructureType::ePhysicalDeviceLegacyDitheringFeaturesEXT);
    e_vk_StructureType.value("PhysicalDevicePipelineProtectedAccessFeaturesEXT", vk::StructureType::ePhysicalDevicePipelineProtectedAccessFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceMaintenance5FeaturesKHR", vk::StructureType::ePhysicalDeviceMaintenance5FeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceMaintenance5PropertiesKHR", vk::StructureType::ePhysicalDeviceMaintenance5PropertiesKHR);
    e_vk_StructureType.value("RenderingAreaInfoKHR", vk::StructureType::eRenderingAreaInfoKHR);
    e_vk_StructureType.value("DeviceImageSubresourceInfoKHR", vk::StructureType::eDeviceImageSubresourceInfoKHR);
    e_vk_StructureType.value("SubresourceLayout2KHR", vk::StructureType::eSubresourceLayout2KHR);
    e_vk_StructureType.value("ImageSubresource2KHR", vk::StructureType::eImageSubresource2KHR);
    e_vk_StructureType.value("PipelineCreateFlags2CreateInfoKHR", vk::StructureType::ePipelineCreateFlags2CreateInfoKHR);
    e_vk_StructureType.value("BufferUsageFlags2CreateInfoKHR", vk::StructureType::eBufferUsageFlags2CreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceRayTracingPositionFetchFeaturesKHR", vk::StructureType::ePhysicalDeviceRayTracingPositionFetchFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceShaderObjectFeaturesEXT", vk::StructureType::ePhysicalDeviceShaderObjectFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderObjectPropertiesEXT", vk::StructureType::ePhysicalDeviceShaderObjectPropertiesEXT);
    e_vk_StructureType.value("ShaderCreateInfoEXT", vk::StructureType::eShaderCreateInfoEXT);
    e_vk_StructureType.value("ShaderRequiredSubgroupSizeCreateInfoEXT", vk::StructureType::eShaderRequiredSubgroupSizeCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceTilePropertiesFeaturesQCOM", vk::StructureType::ePhysicalDeviceTilePropertiesFeaturesQCOM);
    e_vk_StructureType.value("TilePropertiesQCOM", vk::StructureType::eTilePropertiesQCOM);
    e_vk_StructureType.value("PhysicalDeviceAmigoProfilingFeaturesSEC", vk::StructureType::ePhysicalDeviceAmigoProfilingFeaturesSEC);
    e_vk_StructureType.value("AmigoProfilingSubmitInfoSEC", vk::StructureType::eAmigoProfilingSubmitInfoSEC);
    e_vk_StructureType.value("PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM", vk::StructureType::ePhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM);
    e_vk_StructureType.value("PhysicalDeviceRayTracingInvocationReorderFeaturesNV", vk::StructureType::ePhysicalDeviceRayTracingInvocationReorderFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceRayTracingInvocationReorderPropertiesNV", vk::StructureType::ePhysicalDeviceRayTracingInvocationReorderPropertiesNV);
    e_vk_StructureType.value("PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV", vk::StructureType::ePhysicalDeviceExtendedSparseAddressSpaceFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceExtendedSparseAddressSpacePropertiesNV", vk::StructureType::ePhysicalDeviceExtendedSparseAddressSpacePropertiesNV);
    e_vk_StructureType.value("PhysicalDeviceMutableDescriptorTypeFeaturesEXT", vk::StructureType::ePhysicalDeviceMutableDescriptorTypeFeaturesEXT);
    e_vk_StructureType.value("MutableDescriptorTypeCreateInfoEXT", vk::StructureType::eMutableDescriptorTypeCreateInfoEXT);
    e_vk_StructureType.value("LayerSettingsCreateInfoEXT", vk::StructureType::eLayerSettingsCreateInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceShaderCoreBuiltinsFeaturesARM", vk::StructureType::ePhysicalDeviceShaderCoreBuiltinsFeaturesARM);
    e_vk_StructureType.value("PhysicalDeviceShaderCoreBuiltinsPropertiesARM", vk::StructureType::ePhysicalDeviceShaderCoreBuiltinsPropertiesARM);
    e_vk_StructureType.value("PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT", vk::StructureType::ePhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT", vk::StructureType::ePhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT);
    e_vk_StructureType.value("LatencySleepModeInfoNV", vk::StructureType::eLatencySleepModeInfoNV);
    e_vk_StructureType.value("LatencySleepInfoNV", vk::StructureType::eLatencySleepInfoNV);
    e_vk_StructureType.value("SetLatencyMarkerInfoNV", vk::StructureType::eSetLatencyMarkerInfoNV);
    e_vk_StructureType.value("GetLatencyMarkerInfoNV", vk::StructureType::eGetLatencyMarkerInfoNV);
    e_vk_StructureType.value("LatencyTimingsFrameReportNV", vk::StructureType::eLatencyTimingsFrameReportNV);
    e_vk_StructureType.value("LatencySubmissionPresentIdNV", vk::StructureType::eLatencySubmissionPresentIdNV);
    e_vk_StructureType.value("OutOfBandQueueTypeInfoNV", vk::StructureType::eOutOfBandQueueTypeInfoNV);
    e_vk_StructureType.value("SwapchainLatencyCreateInfoNV", vk::StructureType::eSwapchainLatencyCreateInfoNV);
    e_vk_StructureType.value("LatencySurfaceCapabilitiesNV", vk::StructureType::eLatencySurfaceCapabilitiesNV);
    e_vk_StructureType.value("PhysicalDeviceCooperativeMatrixFeaturesKHR", vk::StructureType::ePhysicalDeviceCooperativeMatrixFeaturesKHR);
    e_vk_StructureType.value("CooperativeMatrixPropertiesKHR", vk::StructureType::eCooperativeMatrixPropertiesKHR);
    e_vk_StructureType.value("PhysicalDeviceCooperativeMatrixPropertiesKHR", vk::StructureType::ePhysicalDeviceCooperativeMatrixPropertiesKHR);
    e_vk_StructureType.value("PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM", vk::StructureType::ePhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM);
    e_vk_StructureType.value("MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM", vk::StructureType::eMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM);
    e_vk_StructureType.value("PhysicalDeviceVideoMaintenance1FeaturesKHR", vk::StructureType::ePhysicalDeviceVideoMaintenance1FeaturesKHR);
    e_vk_StructureType.value("VideoInlineQueryInfoKHR", vk::StructureType::eVideoInlineQueryInfoKHR);
    e_vk_StructureType.value("PhysicalDevicePerStageDescriptorSetFeaturesNV", vk::StructureType::ePhysicalDevicePerStageDescriptorSetFeaturesNV);
    e_vk_StructureType.value("PhysicalDeviceImageProcessing2FeaturesQCOM", vk::StructureType::ePhysicalDeviceImageProcessing2FeaturesQCOM);
    e_vk_StructureType.value("PhysicalDeviceImageProcessing2PropertiesQCOM", vk::StructureType::ePhysicalDeviceImageProcessing2PropertiesQCOM);
    e_vk_StructureType.value("SamplerBlockMatchWindowCreateInfoQCOM", vk::StructureType::eSamplerBlockMatchWindowCreateInfoQCOM);
    e_vk_StructureType.value("SamplerCubicWeightsCreateInfoQCOM", vk::StructureType::eSamplerCubicWeightsCreateInfoQCOM);
    e_vk_StructureType.value("PhysicalDeviceCubicWeightsFeaturesQCOM", vk::StructureType::ePhysicalDeviceCubicWeightsFeaturesQCOM);
    e_vk_StructureType.value("BlitImageCubicWeightsInfoQCOM", vk::StructureType::eBlitImageCubicWeightsInfoQCOM);
    e_vk_StructureType.value("PhysicalDeviceYcbcrDegammaFeaturesQCOM", vk::StructureType::ePhysicalDeviceYcbcrDegammaFeaturesQCOM);
    e_vk_StructureType.value("SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM", vk::StructureType::eSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM);
    e_vk_StructureType.value("PhysicalDeviceCubicClampFeaturesQCOM", vk::StructureType::ePhysicalDeviceCubicClampFeaturesQCOM);
    e_vk_StructureType.value("PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT", vk::StructureType::ePhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT);
    e_vk_StructureType.value("PhysicalDeviceVertexAttributeDivisorPropertiesKHR", vk::StructureType::ePhysicalDeviceVertexAttributeDivisorPropertiesKHR);
    e_vk_StructureType.value("PipelineVertexInputDivisorStateCreateInfoKHR", vk::StructureType::ePipelineVertexInputDivisorStateCreateInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceVertexAttributeDivisorFeaturesKHR", vk::StructureType::ePhysicalDeviceVertexAttributeDivisorFeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceLayeredDriverPropertiesMSFT", vk::StructureType::ePhysicalDeviceLayeredDriverPropertiesMSFT);
    e_vk_StructureType.value("CalibratedTimestampInfoKHR", vk::StructureType::eCalibratedTimestampInfoKHR);
    e_vk_StructureType.value("PhysicalDeviceMaintenance6FeaturesKHR", vk::StructureType::ePhysicalDeviceMaintenance6FeaturesKHR);
    e_vk_StructureType.value("PhysicalDeviceMaintenance6PropertiesKHR", vk::StructureType::ePhysicalDeviceMaintenance6PropertiesKHR);
    e_vk_StructureType.value("BindMemoryStatusKHR", vk::StructureType::eBindMemoryStatusKHR);
    e_vk_StructureType.value("BindDescriptorSetsInfoKHR", vk::StructureType::eBindDescriptorSetsInfoKHR);
    e_vk_StructureType.value("PushConstantsInfoKHR", vk::StructureType::ePushConstantsInfoKHR);
    e_vk_StructureType.value("PushDescriptorSetInfoKHR", vk::StructureType::ePushDescriptorSetInfoKHR);
    e_vk_StructureType.value("PushDescriptorSetWithTemplateInfoKHR", vk::StructureType::ePushDescriptorSetWithTemplateInfoKHR);
    e_vk_StructureType.value("SetDescriptorBufferOffsetsInfoEXT", vk::StructureType::eSetDescriptorBufferOffsetsInfoEXT);
    e_vk_StructureType.value("BindDescriptorBufferEmbeddedSamplersInfoEXT", vk::StructureType::eBindDescriptorBufferEmbeddedSamplersInfoEXT);
    e_vk_StructureType.value("PhysicalDeviceDescriptorPoolOverallocationFeaturesNV", vk::StructureType::ePhysicalDeviceDescriptorPoolOverallocationFeaturesNV);

    //struct _vk_ApplicationInfo_Wrapper : public vk::ApplicationInfo {
    //public:
    //    _vk_ApplicationInfo_Wrapper(
    //        std::string application_name_,
    //        uint32_t application_version_,
    //        std::string engine_name_,
    //        uint32_t engine_version_,
    //        uint32_t api_version_,
    //        py::object next_
    //    ):
    //        vk::ApplicationInfo(
    //            __converter::string_to_charptr(application_name_),
    //            application_version_,
    //            __converter::string_to_charptr(engine_name_),
    //            engine_version_,
    //            api_version_,
    //            __converter::object_to_voidptr(next_)
    //        ),
    //        _application_name(application_name_),
    //        _engine_name(engine_name_),
    //        _next(next_)
    //    {}

    //public:
    //    std::string _application_name;
    //    std::string _engine_name;
    //    py::object _next;
    //};

    py::class_<vk::ApplicationInfo> s_vk_ApplicationInfo(n_vk, "ApplicationInfo");
    s_vk_ApplicationInfo.def(
        py::init(
            //<std::string, uint32_t, std::string, uint32_t, uint32_t, py::object>
            //&vk::ApplicationInfo::ApplicationInfo<const char *, uint32_t, const char *, uint32_t, uint32_t, const void *>
        [](
            const py::str & application_name_,
            const py::int_ & application_version_,
            const py::str & engine_name_,
            const py::int_ & engine_version_,
            const py::int_ & api_version_,
            const py::object & next_
        ) -> vk::ApplicationInfo {

            //pools::string.push_back(std::shared_ptr(&application_name));
            //pools::string.push_back(std::shared_ptr(&engine_name));
            return vk::ApplicationInfo(
                _MEMORY.allocate_string(application_name_),
                //_wrapper_cast<const std::string, const char *>(application_name_),
                application_version_.cast<uint32_t>(),
                _MEMORY.allocate_string(engine_name_),
                //_wrapper_cast<const std::string, const char *>(engine_name_),
                engine_version_.cast<uint32_t>(),
                api_version_.cast<uint32_t>(),
                _MEMORY.allocate_extension_struct(next_)
                //_wrapper_cast<const py::object, const void *>(next_)

                //__converter::string_to_charptr(application_name),
                //application_version,
                //__converter::string_to_charptr(engine_name),
                //engine_version,
                //api_version,
                //&next
            );
        }),
        py::arg("application_name") = py::str(),
        py::arg("application_version") = py::int_(),
        py::arg("engine_name") = py::str(),
        py::arg("engine_version") = py::int_(),
        py::arg("api_version") = py::int_(),
        py::arg("next") = py::none(),
        py::keep_alive<1, 2>(),
        py::keep_alive<1, 3>(),
        py::keep_alive<1, 4>(),
        py::keep_alive<1, 5>(),
        py::keep_alive<1, 6>(),
        py::keep_alive<1, 7>()
    );
    s_vk_ApplicationInfo.def_property_readonly(
        "s_type",
        py::cpp_function(
            [](
                const vk::ApplicationInfo & self
            ) -> py::object {
                return py::cast(self.sType);
            },
            py::return_value_policy::reference_internal
        )
    );
    s_vk_ApplicationInfo.def_property(
        "application_name",
        py::cpp_function(
            [](
                const vk::ApplicationInfo & self
            ) -> py::str {
                return _MEMORY.wrap_string(self.pApplicationName);
            },
            py::return_value_policy::reference_internal
        ),
        py::cpp_function(
            [](
                vk::ApplicationInfo & self,
                const py::str & application_name_
            ) -> void {
                //self._application_name = application_name_;
                //self.setPApplicationName(__converter::string_to_charptr(application_name_));
                self.setPApplicationName(_MEMORY.allocate_string(application_name_));
            },
            py::keep_alive<1, 2>()
        )
    );
    //s_vk_ApplicationInfo.def_property(
    //    "application_version",
    //    [](
    //        const vk::ApplicationInfo & self
    //    ) {
    //        return self.applicationVersion;
    //    },
    //    [](
    //        vk::ApplicationInfo & self,
    //        uint32_t     application_version
    //    ) {
    //        self.setApplicationVersion(application_version);
    //    }
    //);
    //s_vk_ApplicationInfo.def_property(
    //    "engine_name",
    //    [](
    //        const vk::ApplicationInfo & self
    //    ) {
    //        return _converter_CString_PyString(self.pEngineName);
    //    },
    //    [](
    //        vk::ApplicationInfo & self,
    //        py::str engine_name
    //    ) {
    //        self.setPEngineName(_converter_PyString_CString(engine_name));
    //    }
    //);
    //s_vk_ApplicationInfo.def_property(
    //    "engine_version",
    //    [](
    //        const vk::ApplicationInfo & self
    //    ) {
    //        return self.engineVersion;
    //    },
    //    [](
    //        vk::ApplicationInfo & self,
    //        py::int_ engine_version
    //    ) {
    //        self.setEngineVersion(engine_version);
    //    }
    //);
    s_vk_ApplicationInfo.def_property(
        "api_version",
        py::cpp_function(
            [](
                const vk::ApplicationInfo & self
            ) -> py::int_ {
                return py::cast(self.apiVersion);
            },
            py::return_value_policy::reference_internal
        ),
        py::cpp_function(
            [](
                vk::ApplicationInfo & self,
                const py::int_ & api_version_
            ) -> void {
                self.setApiVersion(api_version_.cast<uint32_t>());
            },
            py::keep_alive<1, 2>()
        )
    );
    s_vk_ApplicationInfo.def_property(
        "next",
        py::cpp_function(
            [](
                const vk::ApplicationInfo & self
            ) {
                return _MEMORY.wrap_extension_struct(self.pNext);
            },
            py::return_value_policy::reference_internal
        ),
        py::cpp_function(
            [](
                vk::ApplicationInfo & self,
                const py::object & next_
            ) -> void {
                //self._next = next_;
                //self.setPNext(__converter::object_to_voidptr(next_));
                self.setPNext(_MEMORY.allocate_extension_struct(next_));
            },
            py::keep_alive<1, 2>()
        )
    );

    //py::class_<vk::InstanceCreateInfo> s_vk_InstanceCreateInfo(n_vk, "InstanceCreateInfo");
    //s_vk_InstanceCreateInfo.def(py::init(
    //    [](
    //        vk::InstanceCreateFlags flags,
    //        std::optional<const vk::ApplicationInfo> application_info,
    //        const std::vector<std::string> & enabled_layer_names,
    //        const std::vector<std::string> & enabled_extension_names = {},
    //        const void * next = nullptr
    //    ) {
    //        return vk::InstanceCreateInfo{
    //            flags,
    //            application_info.has_value() ? &application_info.value() : nullptr,
    //            _converter_StringVector_ArrayProxyNoTemporaries(enabled_layer_names),
    //            _converter_StringVector_ArrayProxyNoTemporaries(enabled_extension_names),
    //            next
    //        };
    //    }),
    //    py::arg("flags"),
    //    py::arg("application_info") = py::none(),
    //    py::arg("enabled_layer_names"),
    //    py::arg("enabled_extension_names") = std::vector<std::string>{},
    //    py::arg("next") = nullptr
    //);
    //s_vk_InstanceCreateInfo.def_readonly("s_type", &vk::InstanceCreateInfo::sType);
    //s_vk_InstanceCreateInfo.def_property("next", [](const vk::InstanceCreateInfo & self) { return self.pNext; }, &vk::InstanceCreateInfo::setPNext);
    //s_vk_InstanceCreateInfo.def_property("flags", [](const vk::InstanceCreateInfo & self) { return self.flags; }, &vk::InstanceCreateInfo::setFlags);
    //s_vk_InstanceCreateInfo.def_property("application_info", [](const vk::InstanceCreateInfo & self) { return self.pApplicationInfo; }, &vk::InstanceCreateInfo::setPApplicationInfo);
    //s_vk_InstanceCreateInfo.def_readonly("enabled_layer_count", &vk::InstanceCreateInfo::enabledLayerCount);
    //s_vk_InstanceCreateInfo.def_property("enabled_layer_names", [](const vk::InstanceCreateInfo & self) { return self.ppEnabledLayerNames; }, &vk::InstanceCreateInfo::setPpEnabledLayerNames);
    //s_vk_InstanceCreateInfo.def_readonly("enabled_extension_count", &vk::InstanceCreateInfo::enabledExtensionCount);
    //s_vk_InstanceCreateInfo.def_property("enabled_extension_names", [](const vk::InstanceCreateInfo & self) { return self.ppEnabledExtensionNames; }, &vk::InstanceCreateInfo::setPpEnabledExtensionNames);
}
