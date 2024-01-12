import pathlib
import re
import subprocess
import sys

import cffi


def replace_platform_dependent_macros(
    vk_platform_h_content: str
) -> str:
    # Specifically treat platform-dependent definitions,
    # meanwhile get rid of statements that cannot be parsed by pycparser.
    replace_start_match = re.compile(r"#if defined\(_WIN32\)").search(vk_platform_h_content)
    assert replace_start_match is not None
    replace_start = replace_start_match.start()
    replace_end_match = re.compile(r"#endif\n").search(vk_platform_h_content, pos=replace_start)
    assert replace_end_match is not None
    replace_end = replace_end_match.end()
    return "".join((
        vk_platform_h_content[:replace_start],
        "#define VKAPI_ATTR\n",
        "#define VKAPI_CALL\n",
        "#define VKAPI_PTR\n",
        vk_platform_h_content[replace_end:]
    ))



def get_cdef_str(
    vk_xml: pathlib.Path,
    video_xml: pathlib.Path,
    generated_dir: pathlib.Path
) -> str:
    genvk_py = pathlib.Path("Vulkan-Docs/scripts/genvk.py")

    # Generate header files.
    vk_video_dir = generated_dir.joinpath("vk_video")
    vk_video_dir.mkdir(exist_ok=True)
    for codec_filename in (
        "vulkan_video_codecs_common",
        "vulkan_video_codec_h264std",
        "vulkan_video_codec_h264std_decode",
        "vulkan_video_codec_h264std_encode",
        "vulkan_video_codec_h265std",
        "vulkan_video_codec_h265std_decode",
        "vulkan_video_codec_h265std_encode",
    ):  # Entries from genvk.py.
        subprocess.check_call((
            sys.executable,
            genvk_py,
            "-registry",
            video_xml,
            "-o",
            generated_dir.joinpath(vk_video_dir.name),
            f"{codec_filename}.h"
        ))

    vk_platform_h = generated_dir.joinpath("vk_platform.h")
    vk_platform_h.write_text(replace_platform_dependent_macros(
        pathlib.Path("Vulkan-Docs/include/vulkan/vk_platform.h").read_text()
    ))

    vulkan_core_h = generated_dir.joinpath("vulkan_core.h")
    subprocess.check_call((
        sys.executable,
        genvk_py,
        "-registry",
        vk_xml,
        "-o",
        generated_dir,
        vulkan_core_h.name
    ))

    # Preprocess vulkan_core.h.
    vulkan_core_preprocessed_h = generated_dir.joinpath("vulkan_core_preprocessed.h")
    subprocess.check_call((
        "gcc",
        "-E",  # Preprocess only.
        "-P",  # Inhibit generation of linemarkers.
        "-D", "VK_NO_STDDEF_H",
        "-D", "VK_NO_STDINT_H",
        vulkan_core_h,
        "-o",
        vulkan_core_preprocessed_h
    ))

    return vulkan_core_preprocessed_h.read_text()


def main() -> None:
    vk_xml = pathlib.Path("Vulkan-Docs/xml/vk.xml")
    video_xml = pathlib.Path("Vulkan-Docs/xml/video.xml")
    generated_dir = pathlib.Path("generated")
    generated_dir.mkdir(exist_ok=True)

    cdef_str = get_cdef_str(
        vk_xml=vk_xml,
        video_xml=video_xml,
        generated_dir=generated_dir
    )
    ffi = cffi.FFI()
    ffi.cdef(cdef_str, override=True)
    ffi.set_source(str(generated_dir.joinpath("_vulkan_ffi")).replace("\\", "."), None)
    ffi.compile()


if __name__ == "__main__":
    main()
