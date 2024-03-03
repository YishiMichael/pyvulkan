from __future__ import annotations

import pathlib

import cffi


def build_ffi(
    dir_path: pathlib.Path
) -> None:
    ffi = cffi.FFI()
    ffi.cdef(csource=dir_path.joinpath("_vulkan_cdef.h").read_text())
    ffi.set_source(
        module_name=str(dir_path.joinpath("_vulkan_ffi")).replace("\\", "."),
        source=dir_path.joinpath("_vulkan_csrc.h").read_text(),
        include_dirs=["extern/vulkan/Include"],
        library_dirs=["extern/vulkan/Lib"],
        libraries=["vulkan-1"]
    )
    ffi.compile()


if __name__ == "__main__":
    build_ffi(pathlib.Path("generated/vulkan_win32_1_3_275"))
