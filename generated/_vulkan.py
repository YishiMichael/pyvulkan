
from __future__ import annotations

# Auto-generated python interface

from enum import (
    Enum,
    Flag
)
from typing import (
    Never,
    Union
)

import cffi

from _vulkan_ffi import (
    ffi,
    lib
)


def VK_MAKE_VIDEO_STD_VERSION(major: int, minor: int, patch: int) -> int:
    return lib.VK_MAKE_VIDEO_STD_VERSION(major, minor, patch)

def VK_MAKE_API_VERSION(variant: int, major: int, minor: int, patch: int) -> int:
    return lib.VK_MAKE_API_VERSION(variant, major, minor, patch)

def VK_API_VERSION_VARIANT(version: int) -> int:
    return lib.VK_API_VERSION_VARIANT(version)

def VK_API_VERSION_MAJOR(version: int) -> int:
    return lib.VK_API_VERSION_MAJOR(version)

def VK_API_VERSION_MINOR(version: int) -> int:
    return lib.VK_API_VERSION_MINOR(version)

def VK_API_VERSION_PATCH(version: int) -> int:
    return lib.VK_API_VERSION_PATCH(version)
