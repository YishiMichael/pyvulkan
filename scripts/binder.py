from __future__ import annotations

import itertools
import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    Self,
    TextIO
)


class Name:
    __slots__ = ("_segments",)

    def __init__(
        self: Self,
        name: str  # UpperCamelCase or lowerCamelCase
    ) -> None:
        super().__init__()
        self._segments: tuple[str, ...] = tuple(
            name[start:stop]
            for start, stop in itertools.pairwise((
                0, *itertools.chain.from_iterable(
                    match.span() for match in re.finditer(r"[A-Z][a-z]+", name)
                ), len(name)
            ))
            if start != stop
        )

    def to_upper_underscore(
        self: Self
    ) -> str:
        return "_".join(
            segment.upper() if segment.isalpha() else segment
            for segment in self._segments
        )

    def to_lower_underscore(
        self: Self
    ) -> str:
        return "_".join(
            segment.lower() if segment.isalpha() else segment
            for segment in self._segments
        )

    def to_capital_camel_case(
        self: Self
    ) -> str:
        return "".join(
            segment.title() if segment.isalpha() else segment
            for segment in self._segments
        )

    def removeprefix(
        self: Self,
        *prefixes: str
    ) -> Name:
        segments = self._segments
        start_index = 1 if segments and segments[0] in prefixes else 0
        return Name("".join(segments[start_index:]))


#def capital_camelcase_to_upper_underscore(
#    s: str
#) -> str:
#    return "_".join(
#        segment.upper() if (segment := s[start:stop]).istitle() else segment
#        for start, stop in itertools.pairwise((
#            0, *itertools.chain.from_iterable(
#                match.span() for match in re.finditer(r"[A-Z][a-z]+", s)
#            ), len(s)
#        ))
#        if start != stop
#    )


r"""
for xml in tree.getroot():
    name = xml.get("name", "")
    namespace = xml.get("namespace", "")

    match xml.tag:
        case "namespace":
            varname_prefix = "n"
            py_name = name

        case "enum":
            varname_prefix = "e"
            py_name = name
            for child_xml in xml.iterfind("member"):
                member_name = child_xml.get("name", "")
                py_member_name = Name(member_name).removeprefix("e").to_upper_underscore()
                if not py_member_name[:1].isalpha():
                    py_member_name = f"_{py_member_name}"
                child_xml.set("py_name", py_member_name)

        case "struct":
            varname_prefix = "s"
            py_name = name

            # Every struct has 3 or 4 constructor overloadings in order:
            # - Default constructor;
            # - Copy constructor;
            # - Converting constructor from the corresponding C-style struct;
            # - (optional) Enhanced constructor.
            # We pick the very last constructor, with the copy constructor
            # and the converting constructor skipped.
            prev_constructor_xml: etree.Element | None = None
            for constructor_xml in xml.iterfind("constructor"):
                argument_type_strs: list[str] = []
                for argument_xml in constructor_xml.iterfind("argument"):
                    argument_name = argument_xml.get("name", "")
                    argument_type = argument_xml.get("type", "")
                    argument_type_strs.append(argument_type)
                    argument_type_raw = (
                        f"const {namespace}::{match.group(1)} &"
                        if (match := re.fullmatch(r"const (\w+) &", argument_type)) is not None
                        else argument_type
                    )
                    argument_py_name = Name(argument_name.removesuffix("_")).to_lower_underscore()
                    argument_xml.set("py_name", argument_py_name)
                    argument_xml.set("type_raw", argument_type_raw)

                if tuple(argument_type_strs) in (
                    (f"const {name} &",),
                    (f"const Vk{name} &",)
                ):
                    constructor_xml.set("ignored", "true")
                    continue
                if prev_constructor_xml is not None:
                    prev_constructor_xml.set("ignored", "true")
                prev_constructor_xml = constructor_xml

            setter_names = set(
                Name(method_xml.get("name", "")).removeprefix("set").to_lower_underscore()
                for method_xml in xml.iterfind("method")
            )
            for field_xml in xml.iterfind("field"):
                field_name = field_xml.get("name", "")
                field_name_obj = Name(field_name)
                field_writable = field_name_obj.to_lower_underscore() in setter_names
                field_py_name = field_name_obj.removeprefix("p", "pp", "pfn").to_lower_underscore()
                if field_writable:
                    field_xml.set("writable", "true")
                field_xml.set("py_name", field_py_name)

        case "union":
            varname_prefix = "u"
            py_name = name

        case "class":
            varname_prefix = "c"
            py_name = name

            if xml.get("template_raw"):
                xml.set("ignored", "true")  # TODO

        case "function":
            varname_prefix = None
            py_name = name

        case "type_alias":
            varname_prefix = None
            py_name = name

        case "constant":
            varname_prefix = None
            py_name = Name(name).to_upper_underscore()

        case _:
            assert False

    if varname_prefix is not None:
        xml.set("varname", f"{varname_prefix}{namespace.replace("::", "_")}_{name}")
    xml.set("py_name", py_name)
"""


def get_varname(
    tag: str,
    namespace: str,
    name: str
) -> str:
    varname_prefix = {
        "namespace": "n",
        "enum": "e",
        "struct": "s",
        "union": "u",
        "class": "c"
    }.get(tag, "")
    return f"{varname_prefix}{namespace.replace("::", "_")}_{name}"


def get_py_name(
    tag: str,
    name: str
) -> str:
    if tag == "constant":
        return Name(name).to_upper_underscore()
    return name
                

def write_enum(
    xml: etree.Element,
    module_cpp: TextIO
) -> None:
    name = xml.get("name", "")
    namespace = xml.get("namespace", "")
    varname = get_varname(xml.tag, namespace, name)
    module_cpp.write("\n")
    for child_xml in xml:
        match child_xml.tag:
            case "member":
                member_name = child_xml.get("name", "")
                py_member_name = Name(member_name).removeprefix("e").to_upper_underscore()
                if not py_member_name[:1].isalpha():
                    py_member_name = f"_{py_member_name}"
                module_cpp.write(f"""    {varname}.value("{py_member_name}", {namespace}::{name}::{member_name});\n""")


def write_struct(
    xml: etree.Element,
    module_cpp: TextIO
) -> None:
    name = xml.get("name", "")
    namespace = xml.get("namespace", "")
    varname = get_varname(xml.tag, namespace, name)

    constructor_xml: etree.Element | None = None
    field_xml_items: list[tuple[etree.Element, str | None]] = []
    setter_names: list[str] = []
    for child_xml in xml:
        match child_xml.tag:
            case "constructor":
                # Every struct has 3 or 4 constructor overloadings in order:
                # - Default constructor;
                # - Copy constructor;
                # - Converting constructor from the corresponding C-style struct;
                # - (optional) Enhanced constructor.
                # We pick the very last constructor, with the copy constructor
                # and the converting constructor skipped.

                #argument_type_strs: list[str] = []
                #for argument_xml in child_xml.iterfind("argument"):
                #    argument_name = argument_xml.get("name", "")
                #    argument_type = argument_xml.get("type", "")
                #    argument_type_strs.append(argument_type)
                #    argument_type_raw = (
                #        f"const {namespace}::{match.group(1)} &"
                #        if (match := re.fullmatch(r"const (\w+) &", argument_type)) is not None
                #        else argument_type
                #    )
                #    argument_py_name = Name(argument_name.removesuffix("_")).to_lower_underscore()
                #    argument_xml.set("py_name", argument_py_name)
                #    argument_xml.set("type_raw", argument_type_raw)

                if tuple(
                    argument_xml.get("type", "")
                    for argument_xml in child_xml.iterfind("argument")
                ) in (
                    (f"const {name} &",),
                    (f"const Vk{name} &",)
                ):
                    continue
                constructor_xml = child_xml

            case "method":
                setter_names.append(child_xml.get("name", ""))

            case "field":
                field_name = child_xml.get("name", "")
                if (type_str := child_xml.get("type", "")).endswith("*"):
                    if field_name == "pNext" or type_str == "const char *" or type_str == "const char *const *":
                        continue
                    print(name, field_name, type_str)
                setter_name = f"set{Name(field_name).to_capital_camel_case()}"
                if setter_name not in setter_names:
                    setter_name = None
                #field_writable = Name().to_lower_underscore() in setter_names
                field_xml_items.append((child_xml, setter_name))
                #field_py_name = field_name_obj.removeprefix("p", "pp", "pfn").to_lower_underscore()



    #setter_names = set(
    #    Name(method_xml.get("name", "")).removeprefix("set").to_lower_underscore()
    #    for method_xml in xml.iterfind("method")
    #)
    #for field_xml in xml.iterfind("field"):
    #    field_name = field_xml.get("name", "")
    #    field_name_obj = Name(field_name)
    #    field_writable = field_name_obj.to_lower_underscore() in setter_names
    #    field_py_name = field_name_obj.removeprefix("p", "pp", "pfn").to_lower_underscore()
    #    if field_writable:
    #        field_xml.set("writable", "true")
    #    field_xml.set("py_name", field_py_name)



tree = etree.parse("hpp_registry.xml")

with pathlib.Path("module.cpp").open("w") as module_cpp:
    module_cpp.write("#include <pybind11/pybind11.h>\n")
    module_cpp.write("#include <vulkan/vulkan.hpp>\n")
    module_cpp.write("\n")
    module_cpp.write("namespace py = pybind11;\n")
    module_cpp.write("\n")
    module_cpp.write("PYBIND11_MODULE(pyvulkan, m) {\n")

    namespace_varname_dict = {"": "m"}
    for xml in tree.getroot():
        #if xml.get("ignored") == "true":
        #    continue
        name = xml.get("name", "")
        namespace = xml.get("namespace", "")
        varname = get_varname(xml.tag, namespace, name)
        py_name = get_py_name(xml.tag, name)
        namespace_varname = namespace_varname_dict[namespace]
        match xml.tag:
            case "namespace":
                module_cpp.write(f"""    py::module {varname} = {namespace_varname}.def_submodule("{py_name}");\n""")
                namespace_varname_dict[f"{namespace}::{name}"] = varname
            case "enum":
                module_cpp.write(f"""    py::enum_<{namespace}::{name}> {varname}({namespace_varname}, "{py_name}");\n""")
            case "struct":# | "union" | "class":
                module_cpp.write(f"""    py::class_<{namespace}::{name}> {varname}({namespace_varname}, "{py_name}");\n""")
            case "constant":
                py_name = Name(name).to_upper_underscore()
                module_cpp.write(f"""    {namespace_varname}.attr("{py_name}") = py::cast({namespace}::{name});\n""")

    for xml in tree.getroot():
        #if xml.get("ignored") == "true":
        #    continue
        match xml.tag:
            case "enum":
                write_enum(xml, module_cpp)

            case "struct":
                write_struct(xml, module_cpp)
                #module_cpp.write("\n")
                ##varname = xml.get("varname", "")
                #for child_xml in xml:
                #    #if child_xml.get("ignored") == "true":
                #    #    continue
                #    match child_xml.tag:
                #        case "constructor":
                #            module_cpp.write(f"""    {varname}.def(py::init<{", ".join(
                #                f"{argument_xml.get("type_raw", "")}"
                #                for argument_xml in child_xml.iterfind("argument")
                #            )}>(), {", ".join(
                #                (
                #                    f"""py::arg("{argument_xml.get("py_name", "")}")"""
                #                    + (f""" = {
                #                        default
                #                        if not (default.startswith("{") and default.endswith("}"))
                #                        else "nullptr"
                #                        if (argument_type := argument_xml.get("type_raw", "")).endswith("*")
                #                        else f"{argument_type.removeprefix("const ").removesuffix(" &")}{default}"  # TODO: work?
                #                    }""" if (default := argument_xml.get("default_raw", "")) else "")
                #                )
                #                for argument_xml in child_xml.iterfind("argument")
                #            )});\n""")
                #        #case "field":




    #module_cpp.write(f"""    py::module m_raii = m_vk.def_submodule("raii");\n""")
    #namespace_to_module = {
    #    "vk": "m_vk",
    #    "vk::raii": "m_raii"
    #}
    #for xml in tree.getroot():
    #    if (prefix := {
    #        "struct": "s",
    #        "union": "u",
    #        "class": "c"
    #    }.get(xml.tag)) is None:
    #        continue
    #    name = xml.attrib["name"]
    #    namespace = xml.attrib["namespace"]
    #    varname = f"{prefix}_{namespace}_{name}"
    #    module_cpp.write(f"""    py::class_<{namespace}::{name}> {varname}({namespace_to_module[namespace]}, "{name}");\n""")

    #for xml in tree.getroot():
    #    match xml.tag:
    #        case "enum":
    #            module_cpp.write("\n")
    #            name = xml.attrib["name"]
    #            namespace = xml.attrib["namespace"]
    #            varname = f"e_{namespace}_{name}"
    #            module_cpp.write(f"""    py::enum_<{namespace}::{name}> {varname}({namespace_to_module[namespace]}, "{name}");\n""")
    #            for member_xml in xml.iterfind("member"):
    #                member_name = member_xml.attrib["name"]
    #                py_member_name = capital_camelcase_to_upper_underscore(member_name.removeprefix("e"))
    #                if py_member_name[:1].isdecimal():
    #                    py_member_name = f"_{py_member_name}"
    #                module_cpp.write(f"""    {varname}.value("{py_member_name}", {namespace}::{name}::{member_name});\n""")
    #        case "constant":
    #            module_cpp.write("\n")
    #            name = xml.attrib["name"]
    #            namespace = xml.attrib["namespace"]
    #            py_name = capital_camelcase_to_upper_underscore(name)
    #            module_cpp.write(f"""    {namespace_to_module[namespace]}.attr("{py_name}") = py::cast({namespace}::{name});\n""")

    module_cpp.write("}\n")
