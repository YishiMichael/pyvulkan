from pybind11.setup_helpers import Pybind11Extension
from setuptools import setup


ext_modules = [
    Pybind11Extension(
        name="pyvulkan",
        sources=["scripts/module.cpp"],
        include_dirs=["scripts/extern/pybind11/include", "scripts/extern/vulkan/Include"],
        library_dirs=["scripts/extern/vulkan/Lib"],
        libraries=["vulkan-1"],
        #cxx_std=17
    ),
]

setup(
    ext_modules=ext_modules
)
