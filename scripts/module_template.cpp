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


namespace __converter {
    static inline const char * string_to_cstring(const std::string & value) {
        return value.c_str();
    }

    static inline const void * object_to_voidptr(const py::object & value) {
        return value.cast<const void *>();
    }
}


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
    //py::bind_vector<std::vector<std::string>>(m, "_string_vector");
    py::module n_vk = m.def_submodule("vk");
    py::module n_vk_raii = n_vk.def_submodule("raii");

    py::enum_<vk::InstanceCreateFlagBits> e_vk_InstanceCreateFlagBits(n_vk, "InstanceCreateFlagBits");
    e_vk_InstanceCreateFlagBits.value("ENUMERATE_PORTABILITY_KHR", vk::InstanceCreateFlagBits::eEnumeratePortabilityKHR);

    py::class_<vk::InstanceCreateFlags> e_vk_InstanceCreateFlags(n_vk, "InstanceCreateFlags");

    class vk_ApplicationInfo_Wrapper {
    public:
        vk_ApplicationInfo_Wrapper(
            std::string application_name_,
            uint32_t application_version_,
            std::string engine_name_,
            uint32_t engine_version_,
            uint32_t api_version_,
            py::object next_
        ):
            _self(vk::ApplicationInfo(
                __converter::string_to_cstring(application_name_),
                application_version_,
                __converter::string_to_cstring(engine_name_),
                engine_version_,
                api_version_,
                __converter::object_to_voidptr(next_)
            )),
            application_name(application_name_),
            engine_name(engine_name_),
            next(next_)
        {}

    public:
        vk::ApplicationInfo _self;
        std::string application_name;
        std::string engine_name;
        py::object next;
    };

    py::class_<vk_ApplicationInfo_Wrapper> s_vk_ApplicationInfo(n_vk, "ApplicationInfo");
    s_vk_ApplicationInfo.def(
        py::init<std::string, uint32_t, std::string, uint32_t, uint32_t, py::object>(
            //&vk::ApplicationInfo::ApplicationInfo<const char *, uint32_t, const char *, uint32_t, uint32_t, const void *>
        /*[](
            std::string application_name,
            py::int_ application_version,
            py::str engine_name,
            py::int_ engine_version,
            py::int_ api_version,
            py::object next
        ) {
            return std::unique_ptr<vk::ApplicationInfo>(new vk::ApplicationInfo(
                (__converter::string_to_cstring(application_name)),
                application_version,
                _converter_PyString_CString(engine_name),
                engine_version,
                api_version,
                &next
            ));
        }*/),
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
                const vk_ApplicationInfo_Wrapper & self
            ) {
                return self._self.sType;
            },
            py::return_value_policy::reference_internal
        )
    );
    s_vk_ApplicationInfo.def_property(
        "application_name",
        py::cpp_function(
            [](
                const vk_ApplicationInfo_Wrapper & self
            ) {
                return self.application_name;
            },
            py::return_value_policy::reference_internal
        ),
        py::cpp_function(
            [](
                vk_ApplicationInfo_Wrapper & self,
                const std::string application_name_
            ) {
                self.application_name = application_name_;
                self._self.setPApplicationName(__converter::string_to_cstring(application_name_));
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
    //s_vk_ApplicationInfo.def_property(
    //    "api_version",
    //    [](
    //        const vk::ApplicationInfo & self
    //    ) {
    //        return self.apiVersion;
    //    },
    //    [](
    //        vk::ApplicationInfo & self,
    //        py::int_ api_version
    //    ) {
    //        self.setApiVersion(api_version);
    //    }
    //);
    s_vk_ApplicationInfo.def_property(
        "next",
        py::cpp_function(
            [](
                const vk_ApplicationInfo_Wrapper & self
            ) {
                return self.next;
            },
            py::return_value_policy::reference_internal
        ),
        py::cpp_function(
            [](
                vk_ApplicationInfo_Wrapper & self,
                py::object next_
            ) {
                self.next = next_;
                self._self.setPNext(__converter::object_to_voidptr(next_));
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
