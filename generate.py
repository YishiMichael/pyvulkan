from __future__ import annotations

import argparse
import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    ClassVar,
    Iterator,
    Self,
    TextIO
)

import cffi


class Label:
    __slots__ = (
        "name",
        "tag",
        "required",
        "removed",
        "hidden"
    )

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__()
        self.name: str = name
        self.tag: str | None = None
        self.required: bool = False
        self.removed: bool = False
        self.hidden: bool = False

    def mark_requirement(
        self: Self,
        batch_tag: str | None,
        tag: str | None,
        hidden: bool
    ) -> None:
        match batch_tag:
            case "require":
                if self.required:
                    assert self.tag == tag
                    assert self.hidden == hidden
                    return
                self.required = True
            case "remove":
                self.removed = True
            case _:
                return
        self.tag = tag
        self.hidden = hidden

    def check_requirement(
        self: Self
    ) -> bool:
        return self.required and not self.removed and not self.hidden


class Obj:
    __slots__ = ()

    def write_cdef_incomplete(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        pass

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        pass

    def write_pydef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        pass


class Container[ChildT: Obj](Obj):
    __slots__ = (
        "_child_dict",
        "_label_dict",
        "_forwardref_aliases"
    )

    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self._child_dict: dict[str, ChildT] = {}
        self._label_dict: dict[str, Label] = {}
        self._forwardref_aliases: dict[str, list[str]] = {}

    def iter_filtered_children_items(
        self: Self
    ) -> Iterator[tuple[ChildT, Label]]:
        for name, child in self._child_dict.items():
            label = self._label_dict[name]
            if not label.check_requirement():
                continue
            yield child, label

    def get_child(
        self: Self,
        name: str
    ) -> ChildT:
        return self._child_dict[name]

    def get_label(
        self: Self,
        name: str
    ) -> Label:
        return self._label_dict[name]

    def contains(
        self: Self,
        name: str
    ) -> bool:
        return name in self._label_dict

    def add_child(
        self: Self,
        name: str,
        child: ChildT
    ) -> None:
        assert name not in self._child_dict
        self._child_dict[name] = child
        if name in self._label_dict:
            for alias in self._forwardref_aliases.pop(name):
                self.add_child(alias, child)
        else:
            self._label_dict[name] = Label(name)

    def add_child_alias(
        self: Self,
        name: str,
        aliased_name: str
    ) -> None:
        if aliased_name in self._child_dict:
            self.add_child(name, self.get_child(aliased_name))
        else:
            self._label_dict[name] = Label(name)
            self._forwardref_aliases.setdefault(aliased_name, []).append(name)


class Declaration:
    __slots__ = (
        "cdecl",
        "name",
        "base_type_name",
        "array_sizes",
        "pointer_count",
        "is_nonconst_pointer",
        "base_type"
    )

    def __init__(
        self: Self,
        cdecl: str
    ) -> None:
        cdecl, name, base_type_name, array_sizes, pointer_count, is_nonconst_pointer = type(self).parse_cdecl(cdecl)
        super().__init__()
        self.cdecl: str = cdecl
        self.name: str = name
        self.base_type_name: str = base_type_name
        self.array_sizes: tuple[str, ...] = array_sizes
        self.pointer_count: int = pointer_count
        self.is_nonconst_pointer: bool = is_nonconst_pointer
        self.base_type: Obj = NotImplemented

    @classmethod
    def parse_cdecl(
        cls: type[Self],
        cdecl: str
    ) -> tuple[str, str, str, tuple[str, ...], int, bool]:
        array_sizes: tuple[str, ...] = ()
        pointer_count: int = 0
        is_nonconst_pointer: bool = False
        components = re.findall(r"\w+|\S", cdecl)
        match components:
            case (base_type_name, name):
                pass
            case (base_type_name, "*", name):
                pointer_count = 1
                is_nonconst_pointer = True
            case ("struct", base_type_name, "*", name):
                pointer_count = 1
                is_nonconst_pointer = True
            case (base_type_name, "*", "*", name):
                pointer_count = 2
                is_nonconst_pointer = True
            case ("struct", base_type_name, "*", "*", name):
                pointer_count = 2
                is_nonconst_pointer = True
            case (base_type_name, name, "[", array_size_0, "]"):
                array_sizes = (array_size_0,)
            case (base_type_name, name, "[", array_size_0, "]", "[", array_size_1, "]"):
                array_sizes = (array_size_0, array_size_1)
            case (base_type_name, name, ":", _):
                pass
            case ("const", base_type_name, "*", name):
                pointer_count = 1
            case ("const", "struct", base_type_name, "*", name):
                pointer_count = 1
            case ("const", base_type_name, "*", "const", "*", name):
                pointer_count = 2
            case ("const", base_type_name, name, "[", array_size_0, "]"):
                array_sizes = (array_size_0,)
            case _:
                raise ValueError(cdecl)
        formatted_cdecl = " ".join(components)
        return formatted_cdecl, name, base_type_name, array_sizes, pointer_count, is_nonconst_pointer


class Signature(Obj):
    __slots__ = (
        "return_declaration",
        "arg_declarations"
    )

    def __init__(
        self: Self,
        return_cdecl: str,
        arg_cdecls: tuple[str, ...]
    ) -> None:
        super().__init__()
        self.return_declaration: Declaration = Declaration(return_cdecl)
        self.arg_declarations: tuple[Declaration, ...] = tuple(
            Declaration(arg_cdecl)
            for arg_cdecl in arg_cdecls
        )


class ElementaryType(Obj):
    __slots__ = (
        "ctype",
        "pytype"
    )

    def __init__(
        self: Self,
        ctype: str,
        pytype: str
    ) -> None:
        super().__init__()
        self.ctype: str = ctype
        self.pytype: str = pytype

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        if label.name == self.ctype:
            return
        file.write("\n")
        file.write(f"typedef {self.ctype} {label.name};\n")

    #def write_pydef(
    #    self: Self,
    #    file: TextIO,
    #    label: Label
    #) -> None:
    #    file.write("\n")
    #    file.write(f"{label.name} = {self.pytype}\n")


class ExternalType(Obj):
    __slots__ = ("ctype",)

    # https://github.com/ash-rs/ash/blob/master/ash/src/vk/platform_types.rs
    EXTERNAL_TYPE_CTYPE_DICT: ClassVar[dict[str, str]] = {
        "Display": "void",
        "VisualID": "unsigned int",
        "Window": "unsigned long",
        "RROutput": "unsigned long",
        "wl_display": "void",
        "wl_surface": "void",
        "HINSTANCE": "void *",
        "HWND": "void *",
        "HMONITOR": "void *",
        "HANDLE": "void *",
        "SECURITY_ATTRIBUTES": "void",
        "DWORD": "unsigned long",
        "LPCWSTR": "const uint16_t *",  # special convension from str required?
        "xcb_connection_t": "void",
        "xcb_visualid_t": "uint32_t",
        "xcb_window_t": "uint32_t",
        "IDirectFB": "void",
        "IDirectFBSurface": "void",
        "zx_handle_t": "uint32_t",
        "GgpStreamDescriptor": "uint32_t",
        "GgpFrameToken": "uint64_t",
        "_screen_context": "void",
        "_screen_window": "void",
        "_screen_buffer": "void",
        "NvSciSyncAttrList": "void *",
        "NvSciSyncObj": "void",
        "NvSciSyncFence": "void",
        "NvSciBufAttrList": "void *",
        "NvSciBufObj": "void",

        "ANativeWindow": "void",
        "AHardwareBuffer": "void",
        "CAMetalLayer": "void",
        "MTLDevice_id": "void *",
        "MTLCommandQueue_id": "void *",
        "MTLBuffer_id": "void *",
        "MTLTexture_id": "void *",
        "MTLSharedEvent_id": "void *",
        "IOSurfaceRef": "void *"
    }

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__()
        self.ctype: str = type(self).EXTERNAL_TYPE_CTYPE_DICT[name]

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef {self.ctype} {label.name};\n")


class ExternalInclude(Obj):
    __slots__ = ()


class Macro(Obj):
    __slots__ = ("pymacro",)

    def __init__(
        self: Self,
        cmacro: str
    ) -> None:
        super().__init__()
        self.pymacro: str | None = type(self).parse_cmacro(cmacro)

    @classmethod
    def parse_cmacro(
        cls: type[Self],
        cmacro: str
    ) -> str | None:

        def format_line(
            line: str
        ) -> str:
            line = line.strip()
            if "//" in line:  # Remove comments.
                line = line[:line.index("//")].rstrip()
            if line.endswith("\\"):  # Join line continuation.
                return line.rstrip("\\")
            return line + "\n"

        cmacro = "".join(filter(None, (
            format_line(line)
            for line in cmacro.splitlines()
        ))).strip()

        if (macro_match := re.fullmatch(r"#define\s+(\b\w+\b)\s*(.*)", cmacro)) is None:
            return None

        name = macro_match.group(1)
        value = macro_match.group(2)

        # A number literal.
        if value.isdigit():
            return f"{name} = {value}"

        # A number from a macro function call.
        if (match := re.fullmatch(r"(\w+)\(((?:\w+,\s*)*\w+)\)", value)) is not None:
            func_name = match.group(1)
            args = tuple(arg_match.group() for arg_match in re.finditer(r"\w+", match.group(2)))
            return f"{name} = {func_name}({", ".join(args)})"

        # A macro function.
        if (match := re.fullmatch(r"\(((?:\w+,\s*)*\w+)\)\s*\((.*)\)", value)) is not None:
            args = tuple(arg_match.group() for arg_match in re.finditer(r"\w+", match.group(1)))
            result = match.group(2)
            result = re.sub(
                r"\(uint32_t\)\((\w+)\)",
                lambda match: match.group(1),
                result
            )
            result = re.sub(
                r"\b(\d+|0x[\dA-F]+)U",
                lambda match: match.group(1),
                result
            )
            result = re.sub(
                r"\((\w+)\)",
                lambda match: match.group(1),
                result
            )
            return "\n".join((
                f"def {name}(",
                *(f"    {arg}: int," for  arg in args),
                ") -> int:",
                f"    return {result}"
            ))

        return None

    def write_pydef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        if self.pymacro is None:
            return
        file.write("\n")
        file.write(f"{self.pymacro}\n")


class Constant(Obj):
    __slots__ = (
        "cvalue",
        "pyvalue",
        "cdef_included"
    )

    def __init__(
        self: Self,
        cvalue: str
    ) -> None:
        super().__init__()
        pyvalue, cdef_included = type(self).parse_constant(cvalue)
        self.cvalue: str = cvalue
        self.pyvalue: str = pyvalue
        self.cdef_included: bool = cdef_included

    @classmethod
    def parse_constant(
        cls: type[Self],
        cvalue: str
    ) -> tuple[str, bool]:
        if cvalue.isidentifier():
            return cvalue, False
        if cvalue.isdigit():
            return cvalue, True
        if (match := re.fullmatch(r"0x[\dA-F]+", cvalue)) is not None:
            return cvalue, True
        if (match := re.fullmatch(r"\(~(\d+)U\)", cvalue)) is not None:
            return f"0x{(1 << 32) - 1 - int(match.group(1)):X}", False
        if (match := re.fullmatch(r"\(~(\d+)ULL\)", cvalue)) is not None:
            return f"0x{(1 << 64) - 1 - int(match.group(1)):X}", False
        if (match := re.fullmatch(r"([+-]?\d*\.?\d+(?:E[+-]?\d+)?)F?", cvalue, flags=re.IGNORECASE)) is not None:
            return f"{match.group(1)}", False
        if (match := re.fullmatch(r"\"\w+\"", cvalue)) is not None:
            return cvalue, False
        assert False

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        if not self.cdef_included:
            #file.write(f"{self.name} = None\n")
            return
        file.write("\n")
        file.write(f"#define {label.name} {self.cvalue}\n")

    def write_pydef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"{label.name} = {self.pyvalue}\n")


class Enum(Obj):
    __slots__ = ()

    #def __init__(
    #    self: Self,
    #    enum_value: int
    #) -> None:
    #    super().__init__()
    #    self.enum_value: int = enum_value


class Enums(Container[Enum]):
    __slots__ = (
        "bitmask",
        "long_bitwidth"
    )

    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self.bitmask: bool = False
        self.long_bitwidth: bool = False

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef {f"VkFlags64" if self.long_bitwidth else f"enum {label.name} {{ ... }}"} {label.name};\n")
        for _, enum_label in self.iter_filtered_children_items():
            file.write(f"static const {label.name} {enum_label.name};\n")

    def write_pydef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"class {label.name}({"Flag" if self.bitmask else "Enum"}):\n")
        if not (enum_items := tuple(self.iter_filtered_children_items())):
            file.write("    pass\n")
            return
        for _, enum_label in enum_items:
            # TODO: strip enums name
            file.write(f"    {enum_label.name.removeprefix("VK_")} = lib.{enum_label.name}\n")


class FunctionPointer(Signature):
    __slots__ = ("cdecl",)

    def __init__(
        self: Self,
        cdecl: str
    ) -> None:
        assert (match := re.fullmatch(
            r"typedef\s+(.*)\s+\(VKAPI_PTR \*\w+\)\((.*)\);",
            cdecl,
            flags=re.DOTALL
        )) is not None
        assert (args_cdecl := match.group(2)) is not None
        super().__init__(
            return_cdecl=f"{match.group(1)} _",
            arg_cdecls=tuple(args_cdecl.split(",")) if args_cdecl != "void" else ()
        )

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"""typedef {self.return_declaration.cdecl.removesuffix(" _")} (*{label.name})({
            ", ".join(arg_declaration.cdecl for arg_declaration in self.arg_declarations)
        });\n""")


class Handle(Obj):
    __slots__ = ()

    def write_cdef_incomplete(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef struct {label.name}_T *{label.name};\n")

    #def write_pydef(
    #    self: Self,
    #    file: TextIO,
    #    label: Label
    #) -> None:
    #    file.write("\n")
    #    file.write(f"class {label.name}(VulkanCData):\n")
    #    file.write(f"    __slots__ = ()\n")


class Struct(Signature):
    __slots__ = ()

    def __init__(
        self: Self,
        arg_cdecls: tuple[str, ...]
    ) -> None:
        super().__init__(
            return_cdecl="void _",
            arg_cdecls=arg_cdecls
        )

    def write_cdef_incomplete(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef struct {label.name} {label.name};\n")
    
    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef struct {label.name} {{\n")
        for arg_declaration in self.arg_declarations:
            file.write(f"    {arg_declaration.cdecl};\n")
        file.write(f"}} {label.name};\n")


class Union(Signature):
    __slots__ = ()

    def __init__(
        self: Self,
        arg_cdecls: tuple[str, ...]
    ) -> None:
        super().__init__(
            return_cdecl="void _",
            arg_cdecls=arg_cdecls
        )

    def write_cdef_incomplete(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef union {label.name} {label.name};\n")
    
    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef union {label.name} {{\n")
        for arg_declaration in self.arg_declarations:
            file.write(f"    {arg_declaration.cdecl};\n")
        file.write(f"}} {label.name};\n")


class Command(Signature):
    __slots__ = ()

    #def write_cdef(
    #    self: Self,
    #    file: TextIO,
    #    label: Label
    #) -> None:
    #    file.write("\n")
    #    file.write(f"""{self.return_declaration.cdecl}({
    #        ", ".join(arg_declaration.cdecl for arg_declaration in self.arg_declarations)
    #    });\n""")


class Registry:
    __slots__ = (
        "api",
        "platform",
        "defines",
        "elementary_type_container",
        "external_type_container",
        "external_include_container",
        "macro_container",
        "constant_container",
        "enums_container",
        "function_pointer_container",
        "handle_container",
        "struct_container",
        "union_container",
        "command_container"
    )

    def __init__(
        self: Self,
        api: str,
        platform: str,
        defines: list[str]
    ) -> None:
        super().__init__()
        self.api: str = api
        self.platform: str = platform
        self.defines: dict[str, bool] = dict.fromkeys(defines, True)
        self.elementary_type_container: Container[ElementaryType] = Container()
        self.external_type_container: Container[ExternalType] = Container()
        self.external_include_container: Container[ExternalInclude] = Container()
        self.macro_container: Container[Macro] = Container()
        self.constant_container: Container[Constant] = Container()
        self.enums_container: Container[Enums] = Container()
        self.function_pointer_container: Container[FunctionPointer] = Container()
        self.handle_container: Container[Handle] = Container()
        self.struct_container: Container[Struct] = Container()
        self.union_container: Container[Union] = Container()
        self.command_container: Container[Command] = Container()

        for name, pytype in (
            ("void", "Never"),
            ("char", "str"),
            ("short", "int"),
            ("int", "int"),
            ("long", "int"),
            ("unsigned short", "int"),
            ("unsigned int", "int"),
            ("unsigned long", "int"),
            ("size_t", "int"),
            ("float", "float"),
            ("double", "float"),
            ("int8_t", "int"),
            ("int16_t", "int"),
            ("int32_t", "int"),
            ("int64_t", "int"),
            ("uint8_t", "int"),
            ("uint16_t", "int"),
            ("uint32_t", "int"),
            ("uint64_t", "int")
        ):
            self.elementary_type_container.add_child(name, ElementaryType(
                ctype=name,
                pytype=pytype
            ))
            self.elementary_type_container.get_label(name).required = True

    def iter_interface_obj_items(
        self: Self
    ) -> Iterator[tuple[Obj, Label]]:
        for container in (
            self.elementary_type_container,
            self.external_type_container,
            self.external_include_container,
            self.macro_container,
            self.constant_container,
            self.enums_container,
            self.function_pointer_container,
            self.handle_container,
            self.struct_container,
            self.union_container,
            #self.command_container
        ):
            yield from container.iter_filtered_children_items()

    def get_interface_label(
        self: Self,
        name: str
    ) -> Label:
        for container in (
            self.elementary_type_container,
            self.external_type_container,
            self.external_include_container,
            self.macro_container,
            self.constant_container,
            self.enums_container,
            self.function_pointer_container,
            self.handle_container,
            self.struct_container,
            self.union_container,
            #self.command_container
        ):
            if container.contains(name):
                return container.get_label(name)
        raise KeyError(name)

    def read_interface_obj(
        self: Self,
        type_xml: etree.Element
    ) -> None:
        name = type_xml.get("name", type_xml.findtext("name", ""))
        assert name
        match type_xml.get("category"):
            case None:
                if not self.elementary_type_container.contains(name) and not self.external_type_container.contains(name) \
                        and not type_xml.get("requires", "").startswith("vk_video/"):
                    self.external_type_container.add_child(name, ExternalType(
                        name=name
                    ))
                    self.external_type_container.get_label(name).required = True

            case "include":
                if not self.external_include_container.contains(name):
                    self.external_include_container.add_child(name, ExternalInclude())

            case "define":
                self.macro_container.add_child(name, Macro(
                    cmacro="".join(type_xml.itertext())
                ))

            case "basetype":
                if (alias := type_xml.findtext("type")) is not None and alias.isidentifier():
                    self.elementary_type_container.add_child_alias(name, alias)
                else:
                    self.external_type_container.add_child(name, ExternalType(
                        name=name
                    ))

            case "enum":
                self.enums_container.add_child(name, Enums())

            case "bitmask":
                if (alias := type_xml.get("alias")) is not None:
                    self.elementary_type_container.add_child_alias(name, alias)
                else:
                    self.elementary_type_container.add_child_alias(name, type_xml.findtext("type", ""))

            case "funcpointer":
                self.function_pointer_container.add_child(name, FunctionPointer(
                    cdecl="".join(type_xml.itertext())
                ))

            case "handle":
                self.handle_container.add_child(name, Handle())

            case "struct":
                self.struct_container.add_child(name, Struct(
                    arg_cdecls=tuple(
                        "".join(member_xml.itertext())
                        for member_xml in type_xml.iterfind("member")
                    )
                ))

            case "union":
                self.union_container.add_child(name, Union(
                    arg_cdecls=tuple(
                        "".join(member_xml.itertext())
                        for member_xml in type_xml.iterfind("member")
                    )
                ))

            case _ as category:
                raise ValueError(f"Unexpected category name: {category}")

    def read_constant(
        self: Self,
        enum_xml: etree.Element
    ) -> None:
        name = enum_xml.get("name", "")
        if self.constant_container.contains(name):
            return
        if (alias := enum_xml.get("alias")) is not None:
            self.constant_container.add_child_alias(name, alias)
            return
        self.constant_container.add_child(name, Constant(
            cvalue=enum_xml.get("value", "")
        ))

    def read_enum(
        self: Self,
        enums: Enums,
        enum_xml: etree.Element
    ) -> None:
        name = enum_xml.get("name", "")
        if enums.contains(name):
            return
        if (alias := enum_xml.get("alias")) is not None:
            enums.add_child_alias(name, alias)
            return
        enums.add_child(name, Enum())

    def read_command(
        self: Self,
        command_xml: etree.Element
    ) -> None:
        if (alias := command_xml.get("alias")) is not None:
            self.command_container.add_child_alias(command_xml.get("name", ""), alias)
            return
        assert (proto_xml := command_xml.find("proto")) is not None
        name = proto_xml.findtext("name", "")
        self.command_container.add_child(name, Command(
            return_cdecl="".join(proto_xml.itertext()),
            arg_cdecls=tuple(
                "".join(param_xml.itertext())
                for param_xml in command_xml.iterfind("param")
            )
        ))

    def read_registry_xml(
        self: Self,
        registry_xml: etree.Element
    ) -> None:

        def check_api(
            api: str | None,
            target_api: str
        ) -> bool:
            return api is None or target_api in api.split(",")

        def check_supported(
            supported: str | None,
            target_api: str
        ) -> bool:
            return check_api(supported, target_api) and supported != "disabled"

        def check_platform(
            platform: str | None,
            target_platform: str
        ) -> bool:
            return platform is None or platform == target_platform

        def extract_tag(
            extension_name: str | None
        ) -> str | None:
            if extension_name is None:
                return None
            if (match := re.match(r"^VK_([A-Z]+)_", extension_name)) is None:
                return None
            if (tag := match.group(1)) == "VERSION":
                return None
            return tag

        for xml in list(registry_xml.iter()):
            xml[:] = filter(
                lambda child_xml: child_xml.tag != "comment",
                xml
            )

        for xml in registry_xml:
            match xml.tag:
                case "platforms":
                    for platform_xml in xml.iterfind("platform"):
                        self.defines[platform_xml.get("protect", "")] = platform_xml.get("name", "") == self.platform

                case "types":
                    for type_xml in xml.iterfind("type"):
                        if not check_api(type_xml.get("api"), self.api):
                            continue
                        self.read_interface_obj(type_xml)

                case "enums":
                    if (enums_name := xml.get("name", "")) == "API Constants":
                        for enum_xml in xml.iterfind("enum"):
                            self.read_constant(enum_xml)
                    else:
                        enums = self.enums_container.get_child(enums_name)
                        enums.bitmask = xml.get("type") == "bitmask"
                        enums.long_bitwidth = xml.get("bitwidth") == "64"
                        for enum_xml in xml.iterfind("enum"):
                            self.read_enum(enums, enum_xml)
                            enums.get_label(enum_xml.get("name", "")).required = True

                case "commands":
                    for command_xml in xml.iterfind("command"):
                        if not check_api(command_xml.get("api"), self.api):
                            continue
                        self.read_command(command_xml)

                case "feature":
                    if not check_api(xml.get("api"), self.api):
                        continue
                    for feature_batch_xml in xml:
                        for feature_unit_xml in feature_batch_xml:
                            if not check_api(feature_unit_xml.get("api"), self.api):
                                continue
                            feature_unit_name = feature_unit_xml.get("name", "")
                            match feature_unit_xml.tag:
                                case "type":
                                    label = self.get_interface_label(feature_unit_name)
                                case "enum":
                                    if (extends := feature_unit_xml.get("extends")) is not None:
                                        self.read_enum(self.enums_container.get_child(extends), feature_unit_xml)
                                        label = self.enums_container.get_child(extends).get_label(feature_unit_name)
                                    else:
                                        self.read_constant(feature_unit_xml)
                                        label = self.constant_container.get_label(feature_unit_name)
                                case "command":
                                    label = self.command_container.get_label(feature_unit_name)
                                case _:
                                    continue
                            protect = feature_unit_xml.get("protect")
                            label.mark_requirement(
                                batch_tag=feature_batch_xml.tag,
                                hidden=protect is not None and not self.defines.get(protect, False),
                                tag=None
                            )

                case "extensions":
                    for extension_xml in xml.iterfind("extension"):
                        if not check_api(extension_xml.get("api"), self.api) or not check_supported(extension_xml.get("supported"), self.api) \
                                or not check_platform(extension_xml.get("platform"), self.platform):
                            continue
                        extension_tag = extract_tag(extension_xml.get("name"))
                        for extension_batch_xml in extension_xml:
                            if not check_api(extension_batch_xml.get("api"), self.api):
                                continue
                            extension_batch_tag = extract_tag(extension_batch_xml.get("depends"))
                            for extension_unit_xml in extension_batch_xml:
                                if not check_api(extension_unit_xml.get("api"), self.api):
                                    continue
                                extension_unit_name = extension_unit_xml.get("name", "")
                                match extension_unit_xml.tag:
                                    case "type":
                                        label = self.get_interface_label(extension_unit_name)
                                        tag = extension_batch_tag or extension_tag
                                        if extension_unit_name == "VkFlags64":
                                            tag = None
                                    case "enum":
                                        if (extends := extension_unit_xml.get("extends")) is not None:
                                            self.read_enum(self.enums_container.get_child(extends), extension_unit_xml)
                                            label = self.enums_container.get_child(extends).get_label(extension_unit_name)
                                            tag = None
                                        else:
                                            self.read_constant(extension_unit_xml)
                                            label = self.constant_container.get_label(extension_unit_name)
                                            tag = extension_batch_tag or extension_tag
                                    case "command":
                                        label = self.command_container.get_label(extension_unit_name)
                                        tag = extension_tag
                                    case _:
                                        continue
                                protect = extension_unit_xml.get("protect")
                                label.mark_requirement(
                                    batch_tag=extension_batch_xml.tag,
                                    hidden=protect is not None and not self.defines.get(protect, False),
                                    tag=tag
                                )

    def build_cdef(
        self: Self,
        cdef_path: pathlib.Path
    ) -> None:
        with cdef_path.open("w") as file:
            file.write("// Auto-generated C definitions\n")
            for obj, label in self.iter_interface_obj_items():
                obj.write_cdef_incomplete(file, label)
            for obj, label in self.iter_interface_obj_items():
                obj.write_cdef(file, label)

    def build_ffi(
        self: Self,
        ffi_path: pathlib.Path,
        cdef_path: pathlib.Path
    ) -> None:
        ffi = cffi.FFI()
        ffi.cdef(csource=cdef_path.read_text())
        ffi.set_source(
            module_name=str(ffi_path.with_suffix("")).replace("\\", "."),
            source="".join((
                *(f"#define {define}\n" for define, enabled in self.defines.items() if enabled),
                "#include <vulkan/vulkan.h>\n"
            )),
            include_dirs=["extern/vulkan/Include"],
            library_dirs=["extern/vulkan/Lib"],
            libraries=["vulkan-1"]
        )
        ffi.compile()

    def build_pydef(
        self: Self,
        pydef_path: pathlib.Path,
        ffi_path: pathlib.Path
    ) -> None:
        with pydef_path.open("w") as file:
            file.write("from __future__ import annotations\n")
            file.write("\n")
            file.write("# Auto-generated python interface\n")
            file.write("\n")
            file.write("from enum import (\n")
            file.write("    Enum,\n")
            file.write("    Flag\n")
            file.write(")\n")
            file.write("from typing import (\n")
            file.write("    Never,\n")
            file.write("    Union\n")
            file.write(")\n")
            file.write("\n")
            file.write("import cffi\n")
            file.write("\n")
            file.write(f"from {ffi_path.relative_to(pydef_path.parent).stem} import (\n")
            file.write("    ffi,\n")
            file.write("    lib\n")
            file.write(")\n")
            file.write("\n\n")
            for obj, label in self.iter_interface_obj_items():
                obj.write_pydef(file, label)

            #file.write("\n")
            #file.write("RETURN_CODES.update({\n")
            #file.write("    result_field.value: result_field.name\n")
            #file.write("    for result_field in VkResult\n")
            #file.write("    if isinstance(result_field.value, int)\n")
            #file.write("})\n")

            #file.write("\n")
            #file.write("__all__ = (\n")
            #for obj in self.iter_objs():
            #    if isinstance(obj, ElementaryType | ExternalType):
            #        continue
            #    file.write(f"    \"{obj.name}\",\n")
            #file.write(")\n")


def main() -> None:
    this_dir = pathlib.Path()
    registry = Registry(
        api="vulkan",
        platform="win32",
        defines=["VK_ENABLE_BETA_EXTENSIONS"]
    )
    for xml_path in (
        "extern/xml/video.xml",
        "extern/xml/vk.xml"
    ):
        registry.read_registry_xml(etree.parse(xml_path).getroot())

    generated_dir = this_dir.joinpath("generated")
    generated_dir.mkdir(exist_ok=True)
    cdef_path = generated_dir.joinpath("_vulkan.h")
    pydef_path = generated_dir.joinpath("_vulkan.py")
    ffi_path = generated_dir.joinpath("_vulkan_ffi.py")

    parser = argparse.ArgumentParser()
    parser.add_argument("mode", choices=("all", "cdef", "ffi", "pydef"))
    match parser.parse_args().mode:
        case "all":
            registry.build_cdef(cdef_path)
            registry.build_ffi(ffi_path, cdef_path)
            registry.build_pydef(pydef_path, ffi_path)

        case "cdef":
            registry.build_cdef(cdef_path)

        case "ffi":
            #registry.build_cdef(cdef_path)
            registry.build_ffi(ffi_path, cdef_path)

        case "pydef":
            registry.build_pydef(pydef_path, ffi_path)


if __name__ == "__main__":
    main()
