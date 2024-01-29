import pathlib
import re
import xml.etree.ElementTree as etree


def capital_camelcase_to_upper_underscore(
    s: str
) -> str:
    segments = re.findall(r"[A-Z]+(?=[A-Z\d])|[A-Z][a-z]*|[A-Z]+$|\d+", s)
    assert sum(map(len, segments)) == len(s)
    return "_".join(map(str.upper, segments))


tree = etree.parse("registry.xml")
with pathlib.Path("module.cpp").open("w") as module_cpp:
    module_cpp.write("#include <pybind11/pybind11.h>\n")
    module_cpp.write("#include <vulkan/vulkan.hpp>\n")
    module_cpp.write("\n")
    module_cpp.write("namespace py = pybind11;\n")
    module_cpp.write("\n")
    module_cpp.write("PYBIND11_MODULE(pyvulkan, m) {\n")

    module_cpp.write(f"    py::module m_vk = m.def_submodule(\"vk\");\n")
    module_cpp.write(f"    py::module m_raii = m_vk.def_submodule(\"raii\");\n")
    module_cpp.write("\n")
    namespace_to_module = {
        "vk": "m_vk",
        "vk::raii": "m_raii"
    }
    for xml in tree.iterfind("constant"):
        name = xml.attrib["name"]
        namespace = xml.attrib["namespace"]
        py_name = capital_camelcase_to_upper_underscore(name)
        module_cpp.write(f"    {namespace_to_module[namespace]}.attr(\"{py_name}\") = py::cast({namespace}::{name});\n")

    module_cpp.write("}\n")
