import itertools
import pathlib
import re
import xml.etree.ElementTree as etree


def capital_camelcase_to_upper_underscore(
    s: str
) -> str:
    return "_".join(
        segment.upper() if (segment := s[start:stop]).istitle() else segment
        for start, stop in itertools.pairwise((
            0, *itertools.chain.from_iterable(
                match.span() for match in re.finditer(r"[A-Z][a-z]+", s)
            ), len(s)
        ))
        if start != stop
    )


tree = etree.parse("registry.xml")
with pathlib.Path("module.cpp").open("w") as module_cpp:
    module_cpp.write("""#include <pybind11/pybind11.h>\n""")
    module_cpp.write("""#include <vulkan/vulkan.hpp>\n""")
    module_cpp.write("""\n""")
    module_cpp.write("""namespace py = pybind11;\n""")
    module_cpp.write("""\n""")
    module_cpp.write("""PYBIND11_MODULE(pyvulkan, m) {\n""")

    module_cpp.write(f"""    py::module m_vk = m.def_submodule("vk");\n""")
    module_cpp.write(f"""    py::module m_raii = m_vk.def_submodule("raii");\n""")
    namespace_to_module = {
        "vk": "m_vk",
        "vk::raii": "m_raii"
    }
    for xml in tree.getroot():
        match xml.tag:
            case "enum":
                module_cpp.write("\n")
                name = xml.attrib["name"]
                namespace = xml.attrib["namespace"]
                varname = f"e_{namespace}_{name}"
                module_cpp.write(f"""    py::enum_<{namespace}::{name}> {varname}({namespace_to_module[namespace]}, "{name}");\n""")
                for member_xml in xml.iterfind("member"):
                    member_name = member_xml.attrib["name"]
                    py_member_name = capital_camelcase_to_upper_underscore(member_name.removeprefix("e"))
                    if py_member_name[:1].isdecimal():
                        py_member_name = f"_{py_member_name}"
                    module_cpp.write(f"""    {varname}.value("{py_member_name}", {namespace}::{name}::{member_name});\n""")
            case "constant":
                module_cpp.write("\n")
                name = xml.attrib["name"]
                namespace = xml.attrib["namespace"]
                py_name = capital_camelcase_to_upper_underscore(name)
                module_cpp.write(f"""    {namespace_to_module[namespace]}.attr("{py_name}") = py::cast({namespace}::{name});\n""")

    module_cpp.write("}\n")
