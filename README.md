# pyvulkan

[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg?style=flat)](http://choosealicense.com/licenses/mit/)


*The Python binding for Vulkan API.*

*Under construction.*


## Installation
The generated python files run on Python 3.8+. On the other hand, the generator scripts run on Python 3.12+.

`cffi` is the only 3rd party dependency other than the Vulkan SDK.

## Workflow
To generate files yourself, ensure your Python version is 3.12+, and execute:
```sh
git clone https://github.com/YishiMichael/pyvulkan.git
cd ./scripts
git clone https://github.com/KhronosGroup/Vulkan-Docs.git
python generate_ffi.py
python generate_vk.py
```
If run successfully, you should see `_vulkan_ffi.py` and `_vulkan.py` under the directory `generated`.


## License
MIT license
