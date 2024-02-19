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


# Refer to https://github.com/ash-rs/ash/blob/master/ash/src/vk/platform_types.rs
PLATFORM_TYPE_DICT: dict[str, str] = {
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
    "LPCWSTR": "uint16_t const *",  # special convension from str required?
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
    "NvSciBufObj": "void"
}
BASETYPE_DICT: dict[str, str] = {
    "ANativeWindow": "void",
    "AHardwareBuffer": "void",
    "CAMetalLayer": "void",
    "MTLDevice_id": "void *",
    "MTLCommandQueue_id": "void *",
    "MTLBuffer_id": "void *",
    "MTLTexture_id": "void *",
    "MTLSharedEvent_id": "void *",
    "IOSurfaceRef": "void *",
    "VkSampleMask": "uint32_t",
    "VkBool32": "uint32_t",
    "VkFlags": "uint32_t",
    "VkFlags64": "uint64_t",
    "VkDeviceSize": "uint64_t",
    "VkDeviceAddress": "uint64_t",
    "VkRemoteAddressNV": "void *"
}


class CType:
    __slots__ = (
        "class_specifier",
        "base_type_str",
        "const_specifiers"
    )

    def __init__(
        self: Self,
        c_type_str: str
    ) -> None:
        super().__init__()
        class_specifier, base_type_str, const_specifiers = type(self).parse_c_type_str(c_type_str)
        self.class_specifier: str | None = class_specifier
        self.base_type_str: str = base_type_str
        self.const_specifiers: tuple[bool, ...] = const_specifiers

    def __str__(
        self: Self
    ) -> str:
        components = [self.base_type_str]
        for index, const_specifier in enumerate(self.const_specifiers):
            if index:
                components.append("*")
            if const_specifier:
                components.append("const")
        return " ".join(components)

    @classmethod
    def parse_c_type_str(
        cls: type[Self],
        c_type_str: str
        #objs: Container[Obj] | None
    ) -> tuple[str | None, str, tuple[bool, ...]]:
        assert (match := re.fullmatch(r"(const\s+)?((struct|union)\s+)?(.+?)(\s+const)?((\s*\*(\s*const)?)*)", c_type_str.strip())) is not None
        class_specifier = match.group(3)
        base_type_str = match.group(4)
        const_specifiers = (
            match.group(1) is not None or match.group(5) is not None,
            *(
                pointer_match.group(1) is not None
                for pointer_match in re.finditer(r"\*(\s*const)?", match.group(6))
            )
        )
        #if objs is not None:
        #    base_type_str = objs.get_nonalias_name(base_type_str)
        return class_specifier, base_type_str, const_specifiers
        ##array_sizes: tuple[str, ...] = ()
        #pointer_count: int = 0
        #is_nonconst_pointer: bool = False
        #components = re.findall(r"\w+|\S", cdecl)
        #match components:
        #    case (base_type_name,):
        #        pass
        #    case (base_type_name, "*"):
        #        pointer_count = 1
        #        is_nonconst_pointer = True
        #    case ("struct", base_type_name, "*"):
        #        pointer_count = 1
        #        is_nonconst_pointer = True
        #    case (base_type_name, "*", "*"):
        #        pointer_count = 2
        #        is_nonconst_pointer = True
        #    case ("struct", base_type_name, "*", "*"):
        #        pointer_count = 2
        #        is_nonconst_pointer = True
        #    #case (base_type_name, name, "[", array_size_0, "]"):
        #    #    array_sizes = (array_size_0,)
        #    #case (base_type_name, name, "[", array_size_0, "]", "[", array_size_1, "]"):
        #    #    array_sizes = (array_size_0, array_size_1)
        #    #case (base_type_name, name, ":", _):
        #    #    pass
        #    case ("const", base_type_name, "*"):
        #        pointer_count = 1
        #    case ("const", "struct", base_type_name, "*"):
        #        pointer_count = 1
        #    case ("const", base_type_name, "*", "const", "*"):
        #        pointer_count = 2
        #    #case ("const", base_type_name, name, "[", array_size_0, "]"):
        #    #    array_sizes = (array_size_0,)
        #    case _:
        #        raise ValueError(cdecl)
        #formatted_cdecl = " ".join(components)
        #return formatted_cdecl, base_type_name, pointer_count, is_nonconst_pointer


class CDeclaration:
    __slots__ = (
        "c_type",
        "name",
        "array_sizes",
        "bitwidth"
    )

    def __init__(
        self: Self,
        c_declaration_str: str
    ) -> None:
        super().__init__()
        c_type_str, name, array_sizes, bitwidth = type(self).parse_c_declaration_str(c_declaration_str)
        self.c_type: CType = CType(c_type_str)
        self.name: str = name
        self.array_sizes: tuple[str, ...] = array_sizes
        self.bitwidth: int | None = bitwidth

    def __str__(
        self: Self
    ) -> str:
        components = [f"{self.c_type}", " ", self.name, *(f"[{array_size}]" for array_size in self.array_sizes)]
        if self.bitwidth is not None:
            components.append(f":{self.bitwidth}")
        return "".join(components)

    @classmethod
    def parse_c_declaration_str(
        cls: type[Self],
        c_declaration_str: str
    ) -> tuple[str, str, tuple[str, ...], int | None]:
        assert (match := re.fullmatch(r"(.*?)\s*(\b\w+\b)((\s*\[\w+\])*)(\s*:\s*(\d+))?", c_declaration_str.strip())) is not None
        c_type_str = match.group(1)
        name = match.group(2)
        array_sizes = tuple(
            array_size_match.group(1)
            for array_size_match in re.finditer(r"\[(\w+)\]", match.group(3))
        )
        bitwidth = int(bitwidth_str) if (bitwidth_str := match.group(6)) is not None else None
        return c_type_str, name, array_sizes, bitwidth


class Label:
    __slots__ = (
        "_name",
        "_alias",
        "_tag",
        "_required",
        "_removed",
        "_hidden"
    )

    def __init__(
        self: Self,
        name: str,
        alias: str | None = None
    ) -> None:
        super().__init__()
        self._name: str = name
        self._alias: str | None = alias
        self._tag: str | None = None
        self._required: bool = False
        self._removed: bool = False
        self._hidden: bool = False

    @property
    def name(
        self: Self
    ) -> str:
        return self._name

    @property
    def alias(
        self: Self
    ) -> str | None:
        return self._alias

    @property
    def tag(
        self: Self
    ) -> str | None:
        return self._tag

    def mark_requirement(
        self: Self,
        batch_tag: str | None,
        hidden: bool,
        tags: set[str]
    ) -> None:
        tag = match.group() if (match := re.search(r"[A-Z]+$", self._name)) is not None else None
        if tag is not None and tag not in tags:
            tag = None
        match batch_tag:
            case "require":
                if self._required:
                    assert self._hidden == hidden
                    assert self._tag == tag
                    return
                self._required = True
            case "remove":
                self._removed = True
            case _:
                return
        self._hidden = hidden
        self._tag = tag

    def check_requirement(
        self: Self
    ) -> bool:
        return self._required and not self._removed and not self._hidden

    #@classmethod
    #def filter[T](
    #    cls: type[Self],
    #    objs: Iterable[T]
    #) -> Iterable[T]:
    #    return filter(
    #        lambda obj: isinstance(obj, Obj) and obj.check_requirement(),
    #        objs
    #    )

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


class Container[ChildT: Obj]:
    __slots__ = (
        "_child_dict",
        #"_alias_dict",
        "_label_dict"
    )

    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self._child_dict: dict[Label, ChildT] = {}
        #self._inverse_dict: dict[ChildT, set[str]] = {}
        #self._alias_dict: dict[str, str] = {}
        self._label_dict: dict[str, Label] = {}
        #self._forwardref_aliases: dict[str, list[str]] = {}

    def iter_filtered_items(
        self: Self
    ) -> Iterator[tuple[ChildT, Label]]:
        for label in self._label_dict.values():
            if not label.check_requirement():
                continue
            yield self.get_child(label.name), label

    #def get_nonalias_name(
    #    self: Self,
    #    name: str
    #) -> str:
    #    label = self._label_dict[name]
    #    while label.alias is not None:
    #        label = self._label_dict[label.alias]
    #    return label.name

    def get_child(
        self: Self,
        name: str
    ) -> ChildT:
        label = self._label_dict[name]
        while label.alias is not None:
            label = self._label_dict[label.alias]
        return self._child_dict[label]

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
        assert not self.contains(name)
        label = Label(name)
        self._label_dict[name] = label
        self._child_dict[label] = child
        #assert child not in self._inverse_dict
        #self._inverse_dict[child] = {name}
        #return child

    def add_alias(
        self: Self,
        name: str,
        alias: str
    ) -> None:
        assert not self.contains(name)
        label = Label(name, alias=alias)
        self._label_dict[name] = label
        #assert name not in self._child_dict

#    def get_label(
#        self: Self,
#        name: str
#    ) -> Label:
#        return self._label_dict[name]

#    def contains(
#        self: Self,
#        name: str
#    ) -> bool:
#        return name in self._label_dict

#    def add_child(
#        self: Self,
#        name: str,
#        child: ChildT
#    ) -> None:
#        assert name not in self._child_dict
#        self._child_dict[name] = child
#        if name in self._label_dict:
#            for alias in self._forwardref_aliases.pop(name):
#                self.add_child(alias, child)
#        else:
#            self._label_dict[name] = Label(name)

    #def add_child_alias(
    #    self: Self,
    #    name: str,
    #    aliased_name: str
    #) -> None:
    #    if aliased_name in self._child_dict:
    #        self.add_child(name, self.get_child(aliased_name))
    #    else:
    #        self._label_dict[name] = Label(name)
    #        self._forwardref_aliases.setdefault(aliased_name, []).append(name)


#class Declaration:
#    __slots__ = (
#        "cdecl",
#        "name",
#        "base_type_name",
#        "array_sizes",
#        "pointer_count",
#        "is_nonconst_pointer",
#        "base_type"
#    )

#    def __init__(
#        self: Self,
#        cdecl: str
#    ) -> None:
#        cdecl, name, base_type_name, array_sizes, pointer_count, is_nonconst_pointer = type(self).parse_cdecl(cdecl)
#        super().__init__()
#        self.cdecl: str = cdecl
#        self.name: str = name
#        self.base_type_name: str = base_type_name
#        self.array_sizes: tuple[str, ...] = array_sizes
#        self.pointer_count: int = pointer_count
#        self.is_nonconst_pointer: bool = is_nonconst_pointer
#        self.base_type: Obj = NotImplemented


class Signature(Obj):
    __slots__ = (
        "return_c_type",
        "arg_c_declarations"
    )

    def __init__(
        self: Self,
        return_c_type_str: str,
        arg_c_declaration_strs: tuple[str, ...]
    ) -> None:
        super().__init__()
        self.return_c_type: CType = CType(return_c_type_str)
        self.arg_c_declarations: tuple[CDeclaration, ...] = tuple(
            CDeclaration(arg_c_declaration_str)
            for arg_c_declaration_str in arg_c_declaration_strs
        )


class ElementaryType(Obj):
    __slots__ = ("py_type_str",)

    def __init__(
        self: Self,
        name: str,
        py_type_str: str
    ) -> None:
        super().__init__()
        self.py_type_str: str = py_type_str

    #def write_cdef(
    #    self: Self,
    #    file: TextIO
    #) -> None:
    #    if self.name == self.ctype:
    #        return
    #    file.write("\n")
    #    file.write(f"typedef {self.ctype} {self.name};\n")

    #def write_pydef(
    #    self: Self,
    #    file: TextIO,
    #    label: Label
    #) -> None:
    #    file.write("\n")
    #    file.write(f"{label.name} = {self.pytype}\n")


#class ElementaryTypedef(Obj):
#    __slots__ = ("elememtary_type",)

#    def __init__(
#        self: Self,
#        name: str,
#        elememtary_type: ElementaryType
#    ) -> None:
#        super().__init__(
#            name=name
#        )
#        self.elememtary_type: ElementaryType = elememtary_type

#    def write_cdef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        file.write("\n")
#        file.write(f"typedef {self.elememtary_type.name} {self.name};\n")


class Typedef(Obj):
    __slots__ = ("c_type",)

    def __init__(
        self: Self,
        c_type_str: str
    ) -> None:
        super().__init__()
        self.c_type: CType = CType(c_type_str)

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef {self.c_type} {label.name};\n")


class ExternalInclude(Obj):
    __slots__ = ()


class Macro(Obj):
    __slots__ = ("py_macro",)

    def __init__(
        self: Self,
        c_macro: str
    ) -> None:
        super().__init__()
        self.py_macro: str | None = type(self).parse_c_macro(c_macro)

    @classmethod
    def parse_c_macro(
        cls: type[Self],
        c_macro: str
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

        c_macro = "".join(filter(None, (
            format_line(line)
            for line in c_macro.splitlines()
        ))).strip()

        if (macro_match := re.fullmatch(r"#define\s+(\b\w+\b)\s*(.*)", c_macro)) is None:
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
        if self.py_macro is None:
            return
        file.write("\n")
        file.write(f"{self.py_macro}\n")


class Constant(Obj):
    __slots__ = (
        "c_value",
        "py_value",
        "cdef_included"
    )

    def __init__(
        self: Self,
        c_value: str
    ) -> None:
        super().__init__()
        py_value, cdef_included = type(self).parse_constant(c_value)
        self.c_value: str = c_value
        self.py_value: str = py_value
        self.cdef_included: bool = cdef_included

    @classmethod
    def parse_constant(
        cls: type[Self],
        c_value: str
    ) -> tuple[str, bool]:
        if c_value.isidentifier():
            return c_value, False
        if c_value.isdigit():
            return c_value, True
        if (match := re.fullmatch(r"0x[\dA-F]+", c_value)) is not None:
            return c_value, True
        if (match := re.fullmatch(r"\(~(\d+)U\)", c_value)) is not None:
            return f"0x{(1 << 32) - 1 - int(match.group(1)):X}", False
        if (match := re.fullmatch(r"\(~(\d+)ULL\)", c_value)) is not None:
            return f"0x{(1 << 64) - 1 - int(match.group(1)):X}", False
        if (match := re.fullmatch(r"([+-]?\d*\.?\d+(?:E[+-]?\d+)?)F?", c_value, flags=re.IGNORECASE)) is not None:
            return f"{match.group(1)}", False
        if (match := re.fullmatch(r"\"\w+\"", c_value)) is not None:
            return c_value, False
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
        file.write(f"#define {label.name} {self.c_value}\n")

    def write_pydef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"{label.name} = {self.py_value}\n")


class EnumMember(Obj):
    __slots__ = ()

    #def __init__(
    #    self: Self,
    #    enum_value: int
    #) -> None:
    #    super().__init__()
    #    self.enum_value: int = enum_value


class Enum(Obj):
    __slots__ = (
        "bitmask",
        "long_bitwidth",
        "members"
    )

    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self.bitmask: bool = False
        self.long_bitwidth: bool = False
        self.members: Container[EnumMember] = Container()

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef {f"VkFlags64" if self.long_bitwidth else f"enum {label.name} {{ ... }}"} {label.name};\n")
        if label.alias is not None:
            return
        for _, member_label in self.members.iter_filtered_items():
            file.write(f"static const {label.name} {member_label.name};\n")

    def write_pydef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        bitmask = self.bitmask
        py_enum_name = label.name
        assert py_enum_name.startswith("Vk")
        py_enum_name = py_enum_name.removeprefix("Vk")

        enum_tag = label.tag
        enum_prefix = label.name
        if enum_tag is not None:
            assert enum_prefix.endswith(enum_tag)
            #if enum_prefix.endswith(enum_tag):
            enum_prefix = enum_prefix.removesuffix(enum_tag)
            #else:
            #    print(label.name, enum_tag)
        second_version = False
        if bitmask:
            assert (match := re.fullmatch(r"(\w+)FlagBits(2)?", enum_prefix)) is not None
            enum_prefix = match.group(1)
            second_version = match.group(2) is not None
        assert re.fullmatch(r"([A-Z][a-z0-9]+)+", enum_prefix)
        enum_prefix = "".join(f"{segment.group().upper()}_" for segment in re.finditer(r"[A-Z][a-z0-9]+", enum_prefix))
        if second_version:
            enum_prefix += "2_"
        if enum_prefix == "VK_RESULT_":
            enum_prefix = "VK_"

        file.write("\n")
        file.write(f"class {py_enum_name}({"Flag" if bitmask else "Enum"}):\n")
        needs_pass = True
        for _, member_label in self.members.iter_filtered_items():
            #if label.name == "VkSubmitFlagBits":
            #    print(member_label.name)
            if member_label.alias is not None:
                continue
            member_name = member_label.name
            assert member_name.startswith(enum_prefix)
            py_member_name = member_name.removeprefix(enum_prefix)
            member_tag = None if label.name in ("VkVendorId", "VkDriverId") else member_label.tag
            if member_tag is not None:
                #print(label.name, member_label.name, member_tag)
                assert py_member_name.endswith(f"_{member_tag}")
                #    print(member_label.alias is not None, py_member_name, member_label_tag)
                py_member_name = py_member_name.removesuffix(f"_{member_tag}")
            if bitmask:
                py_member_name = py_member_name.removesuffix("_BIT")
            if member_tag is not None and member_tag != enum_tag:
                py_member_name = f"{py_member_name}_{member_tag}"
            if py_member_name[0].isdigit():
                py_member_name = f"_{py_member_name}"
            file.write(f"    {py_member_name} = lib.{member_name}\n")
            needs_pass = False
        if needs_pass:
            file.write("    pass\n")


class FunctionPointer(Signature):
    __slots__ = ("cdecl",)

    def __init__(
        self: Self,
        c_statement_str: str
    ) -> None:
        assert (match := re.fullmatch(
            r"typedef\s+(.*)\s+\(VKAPI_PTR \*\w+\)\((.*)\);",
            c_statement_str,
            flags=re.DOTALL
        )) is not None
        assert (args_cdecl := match.group(2)) is not None
        super().__init__(
            return_c_type_str=match.group(1),
            arg_c_declaration_strs=tuple(args_cdecl.split(",")) if args_cdecl != "void" else ()
        )

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"""typedef {self.return_c_type} (*{label.name})({
            ", ".join(f"{arg_declaration}" for arg_declaration in self.arg_c_declarations)
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


class Struct(Obj):
    __slots__ = ("member_c_declarations",)

    class_specifier: ClassVar[str] = "struct"

    def __init__(
        self: Self,
        member_c_declaration_strs: tuple[str, ...]
    ) -> None:
        super().__init__()
        self.member_c_declarations: tuple[CDeclaration, ...] = tuple(
            CDeclaration(member_c_declaration_str)
            for member_c_declaration_str in member_c_declaration_strs
        )

    def write_cdef_incomplete(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef {self.class_specifier} {label.name} {label.name};\n")

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef {self.class_specifier} {label.name} {{\n")
        for arg_declaration in self.member_c_declarations:
            file.write(f"    {arg_declaration};\n")
        file.write(f"}} {label.name};\n")


class Union(Struct):
    __slots__ = ()

    class_specifier: ClassVar[str] = "union"

    #def __init__(
    #    self: Self,
    #    member_c_declaration_strs: tuple[str, ...],
    #    objs: Container[Obj]
    #) -> None:
    #    super().__init__()
    #    self.member_c_declarations: tuple[CDeclaration, ...] = tuple(
    #        CDeclaration(member_c_declaration_str, objs)
    #        for member_c_declaration_str in member_c_declaration_strs
    #    )

    #def write_cdef_incomplete(
    #    self: Self,
    #    file: TextIO,
    #    label: Label
    #) -> None:
    #    file.write("\n")
    #    file.write(f"typedef union {label.name} {label.name};\n")

    #def write_cdef(
    #    self: Self,
    #    file: TextIO,
    #    label: Label
    #) -> None:
    #    file.write("\n")
    #    file.write(f"typedef union {label.name} {{\n")
    #    for arg_declaration in self.member_c_declarations:
    #        file.write(f"    {arg_declaration};\n")
    #    file.write(f"}} {label.name};\n")


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
        "tags",
        "objs"
        #"elementary_type_container",
        #"typedef_container",
        #"external_type_container",
        #"external_include_container",
        #"macro_container",
        #"constant_container",
        #"enum_container",
        #"function_pointer_container",
        #"handle_container",
        #"struct_container",
        #"union_container",
        #"command_container"
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
        self.tags: set[str] = set()
        self.objs: Container[Obj] = Container()
        for name, py_type_str in (
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
            self.objs.add_child(name, ElementaryType(
                name=name,
                py_type_str=py_type_str
            ))

        #self.elementary_type_container: Container[ElementaryType] = Container()
        #self.typedef_container: Container[Typedef] = Container()
        #self.external_type_container: Container[ExternalType] = Container()
        #self.external_include_container: Container[ExternalInclude] = Container()
        #self.macro_container: Container[Macro] = Container()
        #self.constant_container: Container[Constant] = Container()
        #self.enum_container: Container[Enum] = Container()
        #self.function_pointer_container: Container[FunctionPointer] = Container()
        #self.handle_container: Container[Handle] = Container()
        #self.struct_container: Container[Struct] = Container()
        #self.union_container: Container[Union] = Container()
        #self.command_container: Container[Command] = Container()

        #for name, py_type_str in (
        #    ("void", "Never"),
        #    ("char", "str"),
        #    ("short", "int"),
        #    ("int", "int"),
        #    ("long", "int"),
        #    ("unsigned short", "int"),
        #    ("unsigned int", "int"),
        #    ("unsigned long", "int"),
        #    ("size_t", "int"),
        #    ("float", "float"),
        #    ("double", "float"),
        #    ("int8_t", "int"),
        #    ("int16_t", "int"),
        #    ("int32_t", "int"),
        #    ("int64_t", "int"),
        #    ("uint8_t", "int"),
        #    ("uint16_t", "int"),
        #    ("uint32_t", "int"),
        #    ("uint64_t", "int")
        #):
        #    self.elementary_type_container.add_child(name, ElementaryType(
        #        name=name,
        #        py_type_str=py_type_str
        #    ))
        #    #self.elementary_type_container.get_label(name).required = True

    #def iter_interface_obj_items(
    #    self: Self
    #) -> Iterator[tuple[Obj, Label]]:
    #    for container in (
    #        self.elementary_type_container,
    #        self.external_type_container,
    #        self.external_include_container,
    #        self.macro_container,
    #        self.constant_container,
    #        self.enum_container,
    #        self.function_pointer_container,
    #        self.handle_container,
    #        self.struct_container,
    #        self.union_container,
    #        #self.command_container
    #    ):
    #        yield from container.iter_filtered_children_items()

    #def get_interface_label(
    #    self: Self,
    #    name: str
    #) -> Label:
    #    for container in (
    #        self.elementary_type_container,
    #        self.external_type_container,
    #        self.external_include_container,
    #        self.macro_container,
    #        self.constant_container,
    #        self.enum_container,
    #        self.function_pointer_container,
    #        self.handle_container,
    #        self.struct_container,
    #        self.union_container,
    #        #self.command_container
    #    ):
    #        if container.contains(name):
    #            return container.get_label(name)
    #    raise KeyError(name)

    def read_obj(
        self: Self,
        name: str,
        type_xml: etree.Element
    ) -> None:
        if (alias := type_xml.get("alias")) is not None:
            self.objs.add_alias(name, alias)
            return

        required: bool | None = None
        match type_xml.get("category"):
            case None:
                if self.objs.contains(name):
                    return
                obj = Typedef(
                    c_type_str="void" if type_xml.get("requires", "").startswith("vk_video/") else PLATFORM_TYPE_DICT[name]
                )
                required = True
                #obj.required = True
                #self.obj_dict[name] = obj
                #self.external_type_container.get_label(name).required = True

            case "include":
                if self.objs.contains(name):
                    return
                obj = ExternalInclude()
                #self.external_include_container.add_child(name, ExternalInclude())

            case "define":
                obj = Macro(
                    c_macro="".join(type_xml.itertext())
                )
                #self.macro_container.add_child(name, Macro(
                #    c_macro="".join(type_xml.itertext())
                #))

            case "basetype":
                obj = Typedef(
                    c_type_str=BASETYPE_DICT[name]
                )
                #if (alias := type_xml.findtext("type")) is not None and alias.isidentifier():
                #    self.elementary_type_container.add_child_alias(name, alias)
                #else:
                #    self.external_type_container.add_child(name, ExternalType(
                #        name=name
                #    ))

            case "enum":
                obj = Enum()
                #self.enum_container.add_child(name, Enum())

            case "bitmask":
                obj = Typedef(
                    c_type_str=type_xml.findtext("type", "")
                )
                #if (alias := type_xml.get("alias")) is not None:
                #    self.elementary_type_container.add_child_alias(name, alias)
                #else:
                #    self.elementary_type_container.add_child_alias(name, type_xml.findtext("type", ""))

            case "funcpointer":
                obj = FunctionPointer(
                    c_statement_str="".join(type_xml.itertext())
                )

            case "handle":
                obj = Handle()

            case "struct":
                obj = Struct(
                    member_c_declaration_strs=tuple(
                        "".join(member_xml.itertext())
                        for member_xml in type_xml.iterfind("member")
                    )
                )

            case "union":
                obj = Union(
                    member_c_declaration_strs=tuple(
                        "".join(member_xml.itertext())
                        for member_xml in type_xml.iterfind("member")
                    )
                )

            case _ as category:
                raise ValueError(f"Unexpected category name: {category}")

        self.objs.add_child(name, obj)
        self.objs.get_label(name).mark_requirement(
            batch_tag=("require" if required else "remove") if required is not None else None,
            hidden=False,
            tags=self.tags
        )

    def read_constant(
        self: Self,
        name: str,
        enum_xml: etree.Element
    ) -> None:
        if self.objs.contains(name):
            return
        if (alias := enum_xml.get("alias")) is not None:
            self.objs.add_alias(name, alias)
            return
        self.objs.add_child(name, Constant(
            c_value=enum_xml.get("value", "")
        ))

    def read_enum_member(
        self: Self,
        name: str,
        enum_xml: etree.Element,
        enum: Enum
    ) -> None:
        if enum.members.contains(name):
            return
        if (alias := enum_xml.get("alias")) is not None:
            enum.members.add_alias(name, alias)
            return
        enum.members.add_child(name, EnumMember())

    def read_command(
        self: Self,
        command_xml: etree.Element
    ) -> None:
        if (alias := command_xml.get("alias")) is not None:
            self.objs.add_alias(command_xml.get("name", ""), alias)
            return
        assert (proto_xml := command_xml.find("proto")) is not None
        name = proto_xml.findtext("name", "")
        self.objs.add_child(name, Command(
            return_c_type_str="".join(proto_xml.itertext()),
            arg_c_declaration_strs=tuple(
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

        #def extract_tag(
        #    extension_name: str | None
        #) -> str | None:
        #    if extension_name is None:
        #        return None
        #    if (match := re.match(r"^VK_([A-Z]+)_", extension_name)) is None:
        #        return None
        #    if (tag := match.group(1)) == "VERSION":
        #        return None
        #    return tag

        for xml in list(registry_xml.iter()):
            xml[:] = filter(
                lambda child_xml: child_xml.tag != "comment",
                xml
            )

        for xml in registry_xml:
            match xml.tag:
                case "platforms":
                    self.defines.update(
                        (platform_xml.get("protect", ""), platform_xml.get("name", "") == self.platform)
                        for platform_xml in xml.iterfind("platform")
                    )

                case "tags":
                    self.tags.update(
                        tag_xml.get("name", "")
                        for tag_xml in xml.iterfind("tag")
                    )

                case "types":
                    for type_xml in xml.iterfind("type"):
                        if not check_api(type_xml.get("api"), self.api):
                            continue
                        self.read_obj(type_xml.get("name", type_xml.findtext("name", "")), type_xml)

                case "enums":
                    if (enum_name := xml.get("name", "")) == "API Constants":
                        for enum_xml in xml.iterfind("enum"):
                            self.read_constant(enum_xml.get("name", ""), enum_xml)
                    else:
                        assert isinstance((enum := self.objs.get_child(enum_name)), Enum)
                        enum.bitmask = xml.get("type") == "bitmask"
                        enum.long_bitwidth = xml.get("bitwidth") == "64"
                        for enum_xml in xml.iterfind("enum"):
                            member_name = enum_xml.get("name", "")
                            self.read_enum_member(member_name, enum_xml, enum)
                            enum.members.get_label(member_name).mark_requirement(
                                batch_tag="require",
                                hidden=False,
                                tags=self.tags
                            )

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
                            name = feature_unit_xml.get("name", "")
                            match feature_unit_xml.tag:
                                case "type":
                                    label = self.objs.get_label(name)
                                case "enum":
                                    if (extends := feature_unit_xml.get("extends")) is not None:
                                        assert isinstance((enum := self.objs.get_child(extends)), Enum)
                                        self.read_enum_member(name, feature_unit_xml, enum)
                                        label = enum.members.get_label(name)
                                    else:
                                        self.read_constant(name, feature_unit_xml)
                                        label = self.objs.get_label(name)
                                case "command":
                                    label = self.objs.get_label(name)
                                case _:
                                    continue
                            protect = feature_unit_xml.get("protect")
                            label.mark_requirement(
                                batch_tag=feature_batch_xml.tag,
                                hidden=protect is not None and not self.defines.get(protect, False),
                                tags=self.tags
                            )

                case "extensions":
                    for extension_xml in xml.iterfind("extension"):
                        if not check_api(extension_xml.get("api"), self.api) or not check_supported(extension_xml.get("supported"), self.api) \
                                or not check_platform(extension_xml.get("platform"), self.platform):
                            continue
                        for extension_batch_xml in extension_xml:
                            if not check_api(extension_batch_xml.get("api"), self.api):
                                continue
                            for extension_unit_xml in extension_batch_xml:
                                if not check_api(extension_unit_xml.get("api"), self.api):
                                    continue
                                name = extension_unit_xml.get("name", "")
                                match extension_unit_xml.tag:
                                    case "type":
                                        label = self.objs.get_label(name)
                                    case "enum":
                                        if (extends := extension_unit_xml.get("extends")) is not None:
                                            assert isinstance((enum := self.objs.get_child(extends)), Enum)
                                            self.read_enum_member(name, extension_unit_xml, enum)
                                            label = enum.members.get_label(name)
                                        else:
                                            self.read_constant(name, extension_unit_xml)
                                            label = self.objs.get_label(name)
                                    case "command":
                                        label = self.objs.get_label(name)
                                    case _:
                                        continue
                                #print(name, tag)
                                protect = extension_unit_xml.get("protect")
                                label.mark_requirement(
                                    batch_tag=extension_batch_xml.tag,
                                    hidden=protect is not None and not self.defines.get(protect, False),
                                    tags=self.tags
                                )

    def build_cdef(
        self: Self,
        cdef_path: pathlib.Path
    ) -> None:
        with cdef_path.open("w") as file:
            file.write("// Auto-generated C definitions\n")
            for obj, label in self.objs.iter_filtered_items():
                obj.write_cdef_incomplete(file, label)
            for obj, label in self.objs.iter_filtered_items():
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
            for obj, label in self.objs.iter_filtered_items():
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
    #for xml_path in (
    #    "extern/xml/video.xml",
    #    "extern/xml/vk.xml"
    #):
    registry.read_registry_xml(etree.parse("extern/xml/vk.xml").getroot())

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
