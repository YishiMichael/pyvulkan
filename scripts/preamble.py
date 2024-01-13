from __future__ import annotations

from enum import (
    Enum,
    Flag
)
from typing import (
    Any,
    Dict,
    Never,
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
