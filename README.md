# pyvulkan

[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](http://choosealicense.com/licenses/mit/)


*The Python binding for Vulkan API.*

*Under construction.*


## Installation
The generated python files run on Python 3.8+. On the other hand, the generator scripts run on Python 3.12+.

`cffi` is the only 3rd party dependency other than the Vulkan SDK.


## Workflow
The library contains two main ingredients: `_vulkan_ffi.py`, `_vulkan.py`. Both are auto-generated from official Vulkan API registry.

It's not guaranteed the interface is kept up-to-date with Vulkan development. To keep up with the latest Vulkan updates, you may also generate these files yourself. Ensure your Python version is 3.12+, and then follow these steps:
- Clone this repository;
- Under `pyvulkan/scripts/xml/`, fetch files `vk.xml` and `video.xml` from [here](https://github.com/KhronosGroup/Vulkan-Docs/tree/main/xml/);
- Under `pyvulkan/scripts/`, run `python generate.py all`.
If run successfully, you should see all files needed under the directory `generated` (there may be other intermediate files).


## License
MIT license
