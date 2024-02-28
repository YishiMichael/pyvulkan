from __future__ import annotations


from typing import (
    TYPE_CHECKING,
    Any
)

if TYPE_CHECKING:
    import cffi
    ffi = cffi.FFI()
    lib: Any = NotImplemented
else:
    from _vulkan_ffi import (
        ffi,
        lib
    )


if __name__ == "__main__":
    application_name = ffi.new("char[]", "Hello Triangle".encode())
    engine_name = ffi.new("char[]", "No Engine".encode())
    app_info = ffi.new("VkApplicationInfo *", {
        "sType": lib.VK_STRUCTURE_TYPE_APPLICATION_INFO,
        "pNext": ffi.NULL,
        "pApplicationName": application_name,
        "applicationVersion": lib.VK_MAKE_API_VERSION(0, 1, 0, 0),
        "pEngineName": engine_name,
        "engineVersion": lib.VK_MAKE_API_VERSION(0, 1, 0, 0),
        "apiVersion": lib.VK_MAKE_API_VERSION(0, 1, 3, 0)
    })

    enabled_extension_names = ["VK_KHR_surface", "VK_KHR_win32_surface"]
    p__enabled_extension_names = [
        ffi.new("char []", s.encode())
        for s in enabled_extension_names
    ]
    pp__enabled_extension_names = ffi.new("char *[]", p__enabled_extension_names)
    instance_create_info = ffi.new("VkInstanceCreateInfo *", {
        "sType": lib.VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        "pNext": ffi.NULL,
        "flags": 0,
        "pApplicationInfo": app_info,
        "enabledLayerCount": 0,
        "ppEnabledLayerNames": ffi.NULL,
        "enabledExtensionCount": len(enabled_extension_names),
        "ppEnabledExtensionNames": pp__enabled_extension_names
    })


    instance = ffi.new("VkInstance *")
    create_return_value = lib.vkCreateInstance(
        instance_create_info,  # pCreateInfo
        ffi.NULL,  # pAllocator
        instance  # pInstance
    )
    print(create_return_value)
    destroy_return_value = lib.vkDestroyInstance(
        instance[0],  # instance
        ffi.NULL  # pAllocator
    )
    print(destroy_return_value)
