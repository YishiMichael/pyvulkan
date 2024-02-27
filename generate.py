from __future__ import annotations

import argparse
import itertools
import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    Iterator,
    Self,
    TextIO
)

import attrs
import cffi


REGISTRY_SRC_DICT = {
    "video.xml": [
        "vk_video/vulkan_video_codec_h264std.h",
        "vk_video/vulkan_video_codec_h264std_decode.h",
        "vk_video/vulkan_video_codec_h265std.h",
        "vk_video/vulkan_video_codec_h265std_decode.h",
        "vk_video/vulkan_video_codec_h264std_encode.h",
        "vk_video/vulkan_video_codec_h265std_encode.h"
    ],
    "vk.xml": [
        "vulkan/vulkan.h"
    ]
}

BUILTIN_TYPE_DICT = {
    "void": "Never",
    "char": "str",
    "short": "int",
    "int": "int",
    "long": "int",
    "unsigned short": "int",
    "unsigned int": "int",
    "unsigned long": "int",
    "size_t": "int",
    "float": "float",
    "double": "float",
    "int8_t": "int",
    "int16_t": "int",
    "int32_t": "int",
    "int64_t": "int",
    "uint8_t": "int",
    "uint16_t": "int",
    "uint32_t": "int",
    "uint64_t": "int"
}

BASE_TYPE_DICT = {
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

# Refer to https://github.com/ash-rs/ash/blob/master/ash/src/vk/platform_types.rs
PLATFORM_TYPE_DICT = {
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


class CType:
    __slots__ = (
        "_class_str",
        "_const_specifier",
        "_pointer_const_specifiers",
        "_array_size_strs"
    )

    def __init__(
        self: Self,
        c_type_str: str
    ) -> None:
        super().__init__()
        class_str, const_specifier, pointer_const_specifiers, array_size_strs = type(self)._parse_c_type_str(c_type_str)
        self._class_str: str = class_str
        self._const_specifier: bool = const_specifier
        self._pointer_const_specifiers: tuple[bool, ...] = pointer_const_specifiers
        self._array_size_strs: tuple[str, ...] = array_size_strs

    def format(
        self: Self,
        name: str | None = None
    ) -> str:
        return f"""{self._class_str}{" const" if self._const_specifier else ""}{"".join(
            f" *{f" const" if pointer_const_specifier else ""}"
            for pointer_const_specifier in self._pointer_const_specifiers
        )}{f" {name}" if name is not None else ""}{"".join(
            f"[{array_size_str}]"
            for array_size_str in self._array_size_strs
        )}"""
        #components = [self.base_type_str]
        #for index, const_specifier in enumerate(self.const_specifiers):
        #    if index:
        #        components.append("*")
        #    #if const_specifier:
        #    if format_spec != "v":
        #        components.append("const")
        #return " ".join(components)

    @classmethod
    def _parse_c_type_str(
        cls: type[Self],
        c_type_str: str
        #objs: Container[Obj] | None
    ) -> tuple[str, bool, tuple[bool, ...], tuple[str, ...]]:
        #class_specifier: str | None = None
        const_specifier: bool = False
        pointer_const_specifiers: list[bool] = []
        array_size_strs: list[str] = []

        tokens = (match.group() for match in re.finditer(r"\w+|\S", c_type_str))
        next_token = next(tokens)
        if next_token == "const":
            const_specifier = True
            next_token = next(tokens)
        class_str = next_token
        while next_token.isidentifier() and next_token != "const":
            class_str = f"{class_str} next_token"
            next_token = next(tokens, "")
        if next_token == "const":
            const_specifier = True
            next_token = next(tokens, "")
        while next_token == "*":
            pointer_const_specifier = False
            next_token = next(tokens, "")
            if next_token == "const":
                pointer_const_specifier = True
                next_token = next(tokens, "")
            pointer_const_specifiers.append(pointer_const_specifier)
        while next_token == "[":
            next_token = next(tokens)
            if next_token == "]":
                array_size_str = ""
            else:
                array_size_str = next_token
                assert array_size_str.isdecimal() or array_size_str.isidentifier()
                assert next(tokens) == "]"
            array_size_strs.append(array_size_str)
            next_token = next(tokens, "")
        assert not next_token
        #base_type_str = next(tokens)
        #if base_type_str in ("struct", "union"):
        #    class_specifier = base_type_str
        #    base_type_str = next(tokens)
        #assert base_type_str.isidentifier()
        #next_token = next(tokens, "")
        #if next_token == "const":
        #    const_specifier = True
        #    next_token = next(tokens, "")
        #while next_token in 
        #while tokens[-1] == "]":
        #    assert tokens.pop() == "]"
        #    array_size_str = tokens.pop()
        #    assert array_size_str.isdecimal() or array_size_str.isidentifier()
        #    array_size_strs.insert(0, array_size_str)
        #    assert tokens.pop() == "["


        #assert (match := re.fullmatch(r"(const\s+)?((struct|union)\s+)?(.+?)(\s+const)?((\s*\*(\s*const)?)*)", c_type_str.strip())) is not None
        #class_specifier = match.group(3)
        #base_type_str = match.group(4)
        #const_specifiers = (
        #    match.group(1) is not None or match.group(5) is not None,
        #    *(
        #        pointer_match.group(1) is not None
        #        for pointer_match in re.finditer(r"\*(\s*const)?", match.group(6))
        #    )
        #)
        #if objs is not None:
        #    base_type_str = objs.get_nonalias_name(base_type_str)
        return class_str, const_specifier, tuple(pointer_const_specifiers), tuple(array_size_strs)
        ##array_size_strs: tuple[str, ...] = ()
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
        #    #case (base_type_name, name, "[", array_size_str_0, "]"):
        #    #    array_size_strs = (array_size_str_0,)
        #    #case (base_type_name, name, "[", array_size_str_0, "]", "[", array_size_str_1, "]"):
        #    #    array_size_strs = (array_size_str_0, array_size_str_1)
        #    #case (base_type_name, name, ":", _):
        #    #    pass
        #    case ("const", base_type_name, "*"):
        #        pointer_count = 1
        #    case ("const", "struct", base_type_name, "*"):
        #        pointer_count = 1
        #    case ("const", base_type_name, "*", "const", "*"):
        #        pointer_count = 2
        #    #case ("const", base_type_name, name, "[", array_size_str_0, "]"):
        #    #    array_size_strs = (array_size_str_0,)
        #    case _:
        #        raise ValueError(cdecl)
        #formatted_cdecl = " ".join(components)
        #return formatted_cdecl, base_type_name, pointer_count, is_nonconst_pointer


#class CDeclaration:
#    __slots__ = (
#        "c_type",
#        "name",
#        "array_size_strs",
#        "bitwidth"
#    )

#    def __init__(
#        self: Self,
#        c_decl_str: str
#    ) -> None:
#        super().__init__()
#        c_type_str, name, array_size_strs, bitwidth = type(self).parse_c_decl_str(c_decl_str)
#        self.c_type: CType = CType(c_type_str)
#        self.name: str = name
#        self.array_size_strs: tuple[str, ...] = array_size_strs
#        self.bitwidth: int | None = bitwidth

#    def __format__(
#        self: Self,
#        format_spec: str | None
#    ) -> str:
#        components = [f"{self.c_type:format_spec}", " ", self.name, *(f"[{array_size_str}]" for array_size_str in self.array_size_strs)]
#        if self.bitwidth is not None:
#            components.append(f":{self.bitwidth}")
#        return "".join(components)

#    @classmethod
#    def parse_c_decl_str(
#        cls: type[Self],
#        c_decl_str: str
#    ) -> tuple[str, str, tuple[str, ...], int | None]:
#        assert (match := re.fullmatch(r"(.*?)\s*(\b\w+\b)((\s*\[\w*\])*)(\s*:\s*(\d+))?", c_decl_str.strip())) is not None
#        c_type_str = match.group(1)
#        name = match.group(2)
#        array_size_strs = tuple(
#            array_size_str_match.group(1)
#            for array_size_str_match in re.finditer(r"\[(\w*)\]", match.group(3))
#        )
#        bitwidth = int(bitwidth_str) if (bitwidth_str := match.group(6)) is not None else None
#        return c_type_str, name, array_size_strs, bitwidth


#class CDecl:
#    __slots__ = (
#        "name",
#        "_c_decl_str_segments"
#    )

#    def __init__(
#        self: Self,
#        # Must contain a name; may contain `const/struct/union/*/[...]`, but not bitwidth.
#        c_decl_str: str,
#        name: str
#    ) -> None:
#        super().__init__()
#        self.name: str = name
#        self._c_decl_str_segments: tuple[str, ...] = tuple(
#            segment if (segment := match.group()) != name else "$"
#            for match in re.finditer(r"\w+|\S", c_decl_str)
#        )
#        assert list(self._c_decl_str_segments).count("$") == 1

#    @classmethod
#    def _generate_segments(
#        cls: type[Self],
#        segments: Iterable[str],
#        name: str
#    ) -> Iterator[str]:
#        prev_segment = ""
#        for segment in segments:
#            if segment == "$":
#                if not name:
#                    continue
#                segment = name
#            if (prev_segment.isidentifier() or prev_segment in ("*", ",")) and (segment.isidentifier() or segment == "*"):
#                yield " "
#            yield segment
#            prev_segment = segment

#    def format(
#        self: Self,
#        name: str | None = None,
#        #omit_const: bool = False
#    ) -> str:
#        if name is None:
#            name = self.name
#        return "".join(type(self)._generate_segments(self._c_decl_str_segments, name))
#        #return "".join(type(self)._generate_segments(filter(
#        #    lambda segment: not omit_const or segment != "const",
#        #    self._c_decl_str_segments
#        #), name))

#    #def get_cffi_type_str(
#    #    self: Self,
#    #    name_replacement: str | None = None
#    #) -> str:
#    #    #components = list(filter(lambda component: component != "const", self._c_decl_str_components))
#    #    #name_index = 3 if components[0] in ("struct", "union") else 2
#    #    #if components[name_index].isidentifier():
#    #    #    components.pop(name_index)
#    #    #return " ".join(components)


#class TypeCDecl(CDecl):
#    __slots__ = ()

#    def __init__(
#        self: Self,
#        c_type_str: str
#    ) -> None:
#        super().__init__(
#            c_decl_str=f"{c_type_str} _",
#            name="_"
#        )


#class CallableCDecl(CDecl):
#    __slots__ = (
#        "return_c_decl",
#        "arg_c_decls"
#    )

#    def __init__(
#        self: Self,
#        #c_decl_str: str,
#        return_c_decl: TypeCDecl,
#        arg_c_decls: tuple[CDecl, ...],
#        name: str
#        #return_c_type_str: str,
#        #arg_c_decl_strs: tuple[str, ...]
#    ) -> None:
#        super().__init__(c_decl_str=f"{return_c_decl.format(name="")} (* {name})({", ".join(
#            arg_c_decl.format() for arg_c_decl in arg_c_decls
#        )})", name=name)
#        #assert (match := re.fullmatch(
#        #    fr"(.*?)\(\s*\*\s*{name}\s*\)\s*\((.*)\)",
#        #    c_decl_str,
#        #    flags=re.DOTALL
#        #)) is not None
#        #return_c_decl_str = f"{match.group(1)} _"
#        #args_c_decl_str = match.group(2)
#        self.return_c_decl: TypeCDecl = return_c_decl
#        self.arg_c_decls: tuple[CDecl, ...] = arg_c_decls


#class RequirementRecord:
#    __slots__ = (
#        "_required",
#        "_removed",
#        "_enabled"
#    )

#    def __init__(
#        self: Self
#    ) -> None:
#        super().__init__()
#        self._required: bool = False
#        self._removed: bool = False
#        self._enabled: bool = False

#    def mark(
#        self: Self,
#        requirement_batch_tag: str | None,
#        enabled: bool
#    ) -> None:
#        #if (match := re.search(r"[A-Z]+$", self._name)) is not None:
#        #    tag = match.group()
#        #    if tag not in tags:
#        #        tag = None
#        #else:
#        #    tag = None
#        match requirement_batch_tag:
#            case "require":
#                if self._required:
#                    assert self._enabled == enabled
#                    #assert self._tag == tag
#                    return
#                self._required = True
#            case "remove":
#                self._removed = True
#            case _:
#                return
#        self._enabled = enabled
#        #self._tag = tag

#    def check(
#        self: Self
#    ) -> bool:
#        return self._required and not self._removed and self._enabled


@attrs.define(kw_only=True)
class Field:
    c_type: CType
    bitwidth: int | None
    # Attributes for auto-filling
    attr_len: str | None
    attr_altlen: str | None
    attr_optional: str | None
    attr_selector: str | None
    attr_selection: str | None
    attr_values: str | None


@attrs.define(kw_only=True)
class Argument:
    c_type: CType
    # Attributes for auto-filling
    attr_len: str | None
    attr_altlen: str | None
    attr_optional: str | None
    attr_selector: str | None


@attrs.define(kw_only=True)
class Obj:
    #name: str
    # Possible scoping:
    # Enum |> EnumMember
    # Handle |> Command
    scope: str | None = None
    required: bool = False
    removed: bool = False
    #attr_platform: str | None = None
    attr_protect: str | None = None


@attrs.define(kw_only=True)
class AliasObj(Obj):
    alias: str


@attrs.define(kw_only=True)
class Include(Obj):
    pass
    #text: str


@attrs.define(kw_only=True)
class Define(Obj):
    c_type: CType
    argument_c_types: dict[str, CType] | None
    #text: str


@attrs.define(kw_only=True)
class BuiltinType(Obj):
    c_type: CType
    py_type_str: str


#@attrs.define(kw_only=True)
#class BaseType(Obj):
#    c_type: CType


#@attrs.define(kw_only=True)
#class ExternalType(Obj):
#    c_type: CType


@attrs.define(kw_only=True)
class Typedef(Obj):
    c_type: CType


@attrs.define(kw_only=True)
class Bitmask(Obj):
    attr_requires: str | None


@attrs.define(kw_only=True)
class Enum(Obj):
    attr_type: str  # "enum" | "bitmask"
    attr_bitwidth: str | None


@attrs.define(kw_only=True)
class FunctionPointer(Obj):
    return_c_type: CType
    argument_c_types: dict[str, CType]


@attrs.define(kw_only=True)
class Handle(Obj):
    attr_parent: str | None


@attrs.define(kw_only=True)
class Struct(Obj):
    fields: dict[str, Field]
    attr_structextends: str | None
    attr_allowduplicate: str | None


@attrs.define(kw_only=True)
class Union(Obj):
    fields: dict[str, Field]


@attrs.define(kw_only=True)
class Constant(Obj):
    c_type: CType
    attr_value: str


#@attrs.define(kw_only=True)
#class ConstantExtrinsic(Obj):
#    pass


@attrs.define(kw_only=True)
class EnumMember(Obj):
    pass


#@attrs.define(kw_only=True)
#class EnumMemberExtrinsic(Obj):
#    pass


@attrs.define(kw_only=True)
class Command(Obj):
    arguments: dict[str, Argument]


#class Obj:
#    __slots__ = (
#        "name",
#        "alias",
#        "category",
#        "xml",
#        #"_tag",
#        "required",
#        "removed",
#        "enabled"
#    )

#    def __init__(
#        self: Self,
#        name: str,
#        alias: str | None,
#        category: str,
#        xml: etree.Element
#    ) -> None:
#        super().__init__()
#        self.name: str = name
#        self.alias: str | None = alias
#        self.category: str = category
#        self.xml: etree.Element = xml
#        #self.alias: str | None = alias
#        #self._tag: str | None = None
#        self.required: bool = False
#        self.removed: bool = False
#        self.enabled: bool = False

#    #@property
#    #def tag(
#    #    self: Self
#    #) -> str | None:
#    #    return self._tag

#    #@classmethod
#    #def filter[T](
#    #    cls: type[Self],
#    #    objs: Iterable[T]
#    #) -> Iterable[T]:
#    #    return filter(
#    #        lambda obj: isinstance(obj, Obj) and obj.check_requirement(),
#    #        objs
#    #    )

#class Obj:
#    __slots__ = ()

#    def write_cdef_incomplete(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        pass

#    def write_cdef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        pass

#    def write_pydef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        pass


#class Container[ChildT: Obj]:
#    __slots__ = (
#        "_child_dict",
#        #"_alias_dict",
#        "_label_dict"
#    )

#    def __init__(
#        self: Self
#    ) -> None:
#        super().__init__()
#        self._child_dict: dict[Label, ChildT] = {}
#        #self._inverse_dict: dict[ChildT, set[str]] = {}
#        #self._alias_dict: dict[str, str] = {}
#        self._label_dict: dict[str, Label] = {}
#        #self._forwardref_aliases: dict[str, list[str]] = {}

#    def iter_filtered_items(
#        self: Self
#    ) -> Iterator[tuple[ChildT, Label]]:
#        for label in self._label_dict.values():
#            if not label.check_requirement():
#                continue
#            yield self.get_child(label.name), label

#    #def get_nonalias_name(
#    #    self: Self,
#    #    name: str
#    #) -> str:
#    #    label = self._label_dict[name]
#    #    while label.alias is not None:
#    #        label = self._label_dict[label.alias]
#    #    return label.name

#    def get_child(
#        self: Self,
#        name: str
#    ) -> ChildT:
#        label = self._label_dict[name]
#        while label.alias is not None:
#            label = self._label_dict[label.alias]
#        return self._child_dict[label]

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
#        assert not self.contains(name)
#        label = Label(name)
#        self._label_dict[name] = label
#        self._child_dict[label] = child
#        #assert child not in self._inverse_dict
#        #self._inverse_dict[child] = {name}
#        #return child

#    def add_alias(
#        self: Self,
#        name: str,
#        alias: str
#    ) -> None:
#        assert not self.contains(name)
#        label = Label(name, alias=alias)
#        self._label_dict[name] = label
#        #assert name not in self._child_dict

##    def get_label(
##        self: Self,
##        name: str
##    ) -> Label:
##        return self._label_dict[name]

##    def contains(
##        self: Self,
##        name: str
##    ) -> bool:
##        return name in self._label_dict

##    def add_child(
##        self: Self,
##        name: str,
##        child: ChildT
##    ) -> None:
##        assert name not in self._child_dict
##        self._child_dict[name] = child
##        if name in self._label_dict:
##            for alias in self._forwardref_aliases.pop(name):
##                self.add_child(alias, child)
##        else:
##            self._label_dict[name] = Label(name)

#    #def add_child_alias(
#    #    self: Self,
#    #    name: str,
#    #    aliased_name: str
#    #) -> None:
#    #    if aliased_name in self._child_dict:
#    #        self.add_child(name, self.get_child(aliased_name))
#    #    else:
#    #        self._label_dict[name] = Label(name)
#    #        self._forwardref_aliases.setdefault(aliased_name, []).append(name)


#class Declaration:
#    __slots__ = (
#        "cdecl",
#        "name",
#        "base_type_name",
#        "array_size_strs",
#        "pointer_count",
#        "is_nonconst_pointer",
#        "base_type"
#    )

#    def __init__(
#        self: Self,
#        cdecl: str
#    ) -> None:
#        cdecl, name, base_type_name, array_size_strs, pointer_count, is_nonconst_pointer = type(self).parse_cdecl(cdecl)
#        super().__init__()
#        self.cdecl: str = cdecl
#        self.name: str = name
#        self.base_type_name: str = base_type_name
#        self.array_size_strs: tuple[str, ...] = array_size_strs
#        self.pointer_count: int = pointer_count
#        self.is_nonconst_pointer: bool = is_nonconst_pointer
#        self.base_type: Obj = NotImplemented


class ElementaryType(Obj):
    __slots__ = ("py_type_str",)

    def __init__(
        self: Self,
        #name: str,
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


#class Typedef(Obj):
#    __slots__ = ("c_decl",)

#    def __init__(
#        self: Self,
#        c_type_str: str
#    ) -> None:
#        super().__init__()
#        self.c_decl: CDecl = CDecl(
#            name="_",
#            c_decl_str=f"{c_type_str} _"
#        )

#    def write_cdef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        file.write("\n")
#        file.write(f"typedef {self.c_decl.format(name="")} {label.name};\n")


#class ExternalInclude(Obj):
#    __slots__ = ()


## TODO: expose macros through c script (under #include <vulkan/vulkan.h>)
#class Macro(Obj):
#    __slots__ = ("py_macro",)

#    def __init__(
#        self: Self,
#        c_macro: str
#    ) -> None:
#        super().__init__()
#        self.py_macro: str | None = type(self).parse_c_macro(c_macro)

#    @classmethod
#    def parse_c_macro(
#        cls: type[Self],
#        c_macro: str
#    ) -> str | None:

#        def format_line(
#            line: str
#        ) -> str:
#            line = line.strip()
#            if "//" in line:  # Remove comments.
#                line = line[:line.index("//")].rstrip()
#            if line.endswith("\\"):  # Join line continuation.
#                return line.rstrip("\\")
#            return line + "\n"

#        c_macro = "".join(filter(None, (
#            format_line(line)
#            for line in c_macro.splitlines()
#        ))).strip()

#        if (macro_match := re.fullmatch(r"#define\s+(\b\w+\b)\s*(.*)", c_macro)) is None:
#            return None

#        name = macro_match.group(1)
#        value = macro_match.group(2)

#        # A number literal.
#        if value.isdecimal():
#            return f"{name} = {value}"

#        # A number from a macro function call.
#        if (match := re.fullmatch(r"(\w+)\(((?:\w+,\s*)*\w+)\)", value)) is not None:
#            func_name = match.group(1)
#            args = tuple(arg_match.group() for arg_match in re.finditer(r"\w+", match.group(2)))
#            return f"{name} = {func_name}({", ".join(args)})"

#        # A macro function.
#        if (match := re.fullmatch(r"\(((?:\w+,\s*)*\w+)\)\s*\((.*)\)", value)) is not None:
#            args = tuple(arg_match.group() for arg_match in re.finditer(r"\w+", match.group(1)))
#            result = match.group(2)
#            result = re.sub(
#                r"\(uint32_t\)\((\w+)\)",
#                lambda match: match.group(1),
#                result
#            )
#            result = re.sub(
#                r"\b(\d+|0x[\dA-F]+)U",
#                lambda match: match.group(1),
#                result
#            )
#            result = re.sub(
#                r"\((\w+)\)",
#                lambda match: match.group(1),
#                result
#            )
#            return "\n".join((
#                f"def {name}(",
#                *(f"    {arg}: int," for  arg in args),
#                ") -> int:",
#                f"    return {result}"
#            ))

#        return None

#    def write_pydef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        if self.py_macro is None:
#            return
#        file.write("\n")
#        file.write(f"{self.py_macro}\n")


#class Constant(Obj):
#    __slots__ = (
#        "c_decl",
#        "c_value"
#        #"write_macro"
#    )

#    def __init__(
#        self: Self,
#        c_value: str,
#        c_type_str: str | None
#    ) -> None:
#        super().__init__()
#        #c_type_str, write_macro = type(self).parse_constant(c_value)
#        if c_type_str is not None:
#            c_decl = TypeCDecl(c_type_str=c_type_str)
#        elif c_value.isidentifier():
#            c_decl = TypeCDecl(c_type_str="uint64_t")
#        elif re.fullmatch(r"0|[1-9][0-9]*|0x[\dA-F]+", c_value) is not None:
#            c_decl = TypeCDecl(c_type_str="uint64_t")
#        #if (match := re.fullmatch(r"0x[\dA-F]+", c_value)) is not None:
#        #    return c_value, True
#        #if (match := re.fullmatch(r"\(~(\d+)U\)", c_value)) is not None:
#        #    return f"0x{(1 << 32) - 1 - int(match.group(1)):X}", False
#        #if (match := re.fullmatch(r"\(~(\d+)ULL\)", c_value)) is not None:
#        #    return f"0x{(1 << 64) - 1 - int(match.group(1)):X}", False
#        #if (match := re.fullmatch(r"([+-]?\d*\.?\d+(?:E[+-]?\d+)?)F?", c_value, flags=re.IGNORECASE)) is not None:
#        #    return f"{match.group(1)}", False
#        elif re.fullmatch(r"\"\w+\"", c_value) is not None:
#            c_decl = CDecl(c_decl_str="char _[]", name="_")
#        else:
#            assert False
#        self.c_decl: CDecl = c_decl
#        self.c_value: str | None = c_value if c_value.isdecimal() else None
#        #self.py_value: str = py_value
#        #self.write_macro: bool = write_macro

#    def write_cdef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        file.write("\n")
#        if self.c_value is not None:
#            #file.write(f"{self.name} = None\n")
#            file.write(f"#define {label.name} {self.c_value}\n")
#        else:
#            file.write(f"static const {self.c_decl.format(name=label.name)};\n")

#    def write_pydef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        file.write("\n")
#        file.write(f"{label.name} = lib.{label.name}\n")


#class EnumMember(Obj):
#    __slots__ = ()

#    #def __init__(
#    #    self: Self,
#    #    enum_value: int
#    #) -> None:
#    #    super().__init__()
#    #    self.enum_value: int = enum_value


#class Enum(Obj):
#    __slots__ = (
#        "bitmask",
#        "long_bitwidth",
#        "members"
#    )

#    def __init__(
#        self: Self
#    ) -> None:
#        super().__init__()
#        self.bitmask: bool = False
#        self.long_bitwidth: bool = False
#        self.members: Container[EnumMember] = Container()

#    def write_cdef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        file.write("\n")
#        file.write(f"typedef {f"VkFlags64" if self.long_bitwidth else f"enum {label.name} {{ ... }}"} {label.name};\n")
#        if label.alias is not None:
#            return
#        for _, member_label in self.members.iter_filtered_items():
#            file.write(f"static const uint64_t {member_label.name};\n")

#    def write_pydef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        bitmask = self.bitmask
#        #assert label.name.startswith("Vk"), label.name
#        py_enum_name = label.name.removeprefix("Vk")

#        enum_tag = label.tag
#        assert (match := re.fullmatch(r"(([A-Z][a-z0-9]+)+?)(FlagBits(2)?)?([A-Z]+)?", label.name)) is not None
#        assert enum_tag == match.group(5)
#        assert bitmask == (match.group(3) is not None)
#        member_prefixes = [segment.group().upper() for segment in re.finditer(r"[A-Z][a-z0-9]+", match.group(1))]
#        if member_prefixes == ["VK", "RESULT"]:
#            member_prefixes.pop()
#        if match.group(4) is not None:
#            member_prefixes.append("2")

#        file.write("\n")
#        file.write(f"class {py_enum_name}({"Flag" if bitmask else "Enum"}):\n")
#        class_body_empty = True
#        for _, member_label in self.members.iter_filtered_items():
#            member_segments = member_label.name.split("_")
#            if member_label.alias is not None:
#                continue
#            member_segments = member_segments[len(member_prefixes):]
#            if (member_tag := member_label.tag) is not None:
#                assert member_segments.pop() == member_tag
#            if bitmask and member_segments[-1] == "BIT":
#                member_segments.pop()
#            if member_tag is not None and member_tag != enum_tag:
#                member_segments.append(member_tag)
#            py_membr_name = "_".join(member_segments)
#            if not py_membr_name.isidentifier():
#                py_membr_name = f"_{py_membr_name}"
#            file.write(f"    {py_membr_name} = lib.{member_label.name}\n")
#            class_body_empty = False
#        if class_body_empty:
#            file.write("    pass\n")


#class FunctionPointer(Obj):
#    __slots__ = ("c_decl",)

#    def __init__(
#        self: Self,
#        c_statement_str: str,
#        name: str
#    ) -> None:
#        super().__init__()
#        assert (match := re.fullmatch(
#            r"typedef\s+(.*?)\s*\(VKAPI_PTR\s*\*\w+\)\((.*)\);",
#            c_statement_str,
#            flags=re.DOTALL
#        )) is not None
#        return_c_type_str = match.group(1)
#        args_c_decl_str = match.group(2)
#        arg_c_decl_strs = args_c_decl_str.split(",") if args_c_decl_str.strip() != "void" else []
#        self.c_decl: CallableCDecl = CallableCDecl(
#            return_c_decl=TypeCDecl(c_type_str=return_c_type_str),
#            arg_c_decls=tuple(
#                CDecl(c_decl_str=arg_c_decl_str, name=arg_c_decl_str.rsplit(" ", 1)[-1])
#                for arg_c_decl_str in arg_c_decl_strs
#            ),
#            name=name
#        )

#    def write_cdef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        file.write("\n")
#        #file.write(f"""typedef {self.return_c_type.get_c_decl_str()} (*{label.name})({
#        #    ", ".join(f"{arg_decl.get_c_decl_str()}" for arg_decl in self.arg_c_decls)
#        #});\n""")
#        file.write(f"""typedef {self.c_decl.format(name=label.name)};\n""")


#class Handle(Obj):
#    __slots__ = ()

#    def write_cdef_incomplete(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        file.write("\n")
#        file.write(f"typedef struct {label.name}_T *{label.name};\n")

#    #def write_pydef(
#    #    self: Self,
#    #    file: TextIO,
#    #    label: Label
#    #) -> None:
#    #    file.write("\n")
#    #    file.write(f"class {label.name}(VulkanCData):\n")
#    #    file.write(f"    __slots__ = ()\n")


#class Struct(Obj):
#    __slots__ = ("member_c_decls",)

#    class_specifier: ClassVar[str] = "struct"

#    def __init__(
#        self: Self,
#        member_c_decl_str_name_pairs: tuple[tuple[str, str], ...]
#        #member_c_decl_strs: tuple[str, ...],
#        #member_names: tuple[str, ...]
#    ) -> None:
#        super().__init__()
#        self.member_c_decls: tuple[CDecl, ...] = tuple(
#            CDecl(
#                c_decl_str=member_c_decl_str,
#                name=member_name
#            )
#            for member_c_decl_str, member_name in member_c_decl_str_name_pairs
#        )

#    def write_cdef_incomplete(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        file.write("\n")
#        file.write(f"typedef {self.class_specifier} {label.name} {label.name};\n")

#    def write_cdef(
#        self: Self,
#        file: TextIO,
#        label: Label
#    ) -> None:
#        file.write("\n")
#        file.write(f"typedef {self.class_specifier} {label.name} {{\n")
#        for c_decl in self.member_c_decls:
#            file.write(f"    {c_decl.format()};\n")  # TODO: bitwidth
#        file.write(f"}} {label.name};\n")


#class Union(Struct):
#    __slots__ = ()

#    class_specifier: ClassVar[str] = "union"

#    #def __init__(
#    #    self: Self,
#    #    member_c_decl_strs: tuple[str, ...],
#    #    objs: Container[Obj]
#    #) -> None:
#    #    super().__init__()
#    #    self.member_c_decls: tuple[CDeclaration, ...] = tuple(
#    #        CDeclaration(member_c_decl_str, objs)
#    #        for member_c_decl_str in member_c_decl_strs
#    #    )

#    #def write_cdef_incomplete(
#    #    self: Self,
#    #    file: TextIO,
#    #    label: Label
#    #) -> None:
#    #    file.write("\n")
#    #    file.write(f"typedef union {label.name} {label.name};\n")

#    #def write_cdef(
#    #    self: Self,
#    #    file: TextIO,
#    #    label: Label
#    #) -> None:
#    #    file.write("\n")
#    #    file.write(f"typedef union {label.name} {{\n")
#    #    for arg_decl in self.member_c_decls:
#    #        file.write(f"    {arg_decl};\n")
#    #    file.write(f"}} {label.name};\n")


#class Command(Obj):
#    __slots__ = ("c_decl",)

#    def __init__(
#        self: Self,
#        return_c_type_str: str,
#        arg_c_decl_str_name_pairs: tuple[tuple[str, str], ...],
#        name: str
#    ) -> None:
#        super().__init__()
#        self.c_decl: CallableCDecl = CallableCDecl(
#            return_c_decl=TypeCDecl(c_type_str=return_c_type_str),
#            arg_c_decls=tuple(
#                CDecl(
#                    c_decl_str=c_decl_str,
#                    name=name
#                )
#                for c_decl_str, name in arg_c_decl_str_name_pairs
#            ),
#            name=name
#        )

#    #def write_cdef(
#    #    self: Self,
#    #    file: TextIO,
#    #    label: Label
#    #) -> None:
#    #    file.write("\n")
#    #    file.write(f"""{self.return_decl.cdecl}({
#    #        ", ".join(arg_decl.cdecl for arg_decl in self.arg_decls)
#    #    });\n""")


#class Registry:
#    __slots__ = (
#        "api",
#        "platform",
#        "defines",
#        "tags",
#        "objs"
#        #"elementary_type_container",
#        #"typedef_container",
#        #"external_type_container",
#        #"external_include_container",
#        #"macro_container",
#        #"constant_container",
#        #"enum_container",
#        #"function_pointer_container",
#        #"handle_container",
#        #"struct_container",
#        #"union_container",
#        #"command_container"
#    )

#    def __init__(
#        self: Self,
#        api: str,
#        platform: str,
#        defines: list[str]
#    ) -> None:
#        super().__init__()
#        self.api: str = api
#        self.platform: str = platform
#        self.defines: dict[str, bool] = dict.fromkeys(defines, True)
#        self.tags: set[str] = set()
#        self.objs: Container[Obj] = Container()
#        for name, py_type_str in (
#            ("void", "Never"),
#            ("char", "str"),
#            ("short", "int"),
#            ("int", "int"),
#            ("long", "int"),
#            ("unsigned short", "int"),
#            ("unsigned int", "int"),
#            ("unsigned long", "int"),
#            ("size_t", "int"),
#            ("float", "float"),
#            ("double", "float"),
#            ("int8_t", "int"),
#            ("int16_t", "int"),
#            ("int32_t", "int"),
#            ("int64_t", "int"),
#            ("uint8_t", "int"),
#            ("uint16_t", "int"),
#            ("uint32_t", "int"),
#            ("uint64_t", "int")
#        ):
#            self.objs.add_child(name, ElementaryType(
#                #name=name,
#                py_type_str=py_type_str
#            ))

#        #self.elementary_type_container: Container[ElementaryType] = Container()
#        #self.typedef_container: Container[Typedef] = Container()
#        #self.external_type_container: Container[ExternalType] = Container()
#        #self.external_include_container: Container[ExternalInclude] = Container()
#        #self.macro_container: Container[Macro] = Container()
#        #self.constant_container: Container[Constant] = Container()
#        #self.enum_container: Container[Enum] = Container()
#        #self.function_pointer_container: Container[FunctionPointer] = Container()
#        #self.handle_container: Container[Handle] = Container()
#        #self.struct_container: Container[Struct] = Container()
#        #self.union_container: Container[Union] = Container()
#        #self.command_container: Container[Command] = Container()

#        #for name, py_type_str in (
#        #    ("void", "Never"),
#        #    ("char", "str"),
#        #    ("short", "int"),
#        #    ("int", "int"),
#        #    ("long", "int"),
#        #    ("unsigned short", "int"),
#        #    ("unsigned int", "int"),
#        #    ("unsigned long", "int"),
#        #    ("size_t", "int"),
#        #    ("float", "float"),
#        #    ("double", "float"),
#        #    ("int8_t", "int"),
#        #    ("int16_t", "int"),
#        #    ("int32_t", "int"),
#        #    ("int64_t", "int"),
#        #    ("uint8_t", "int"),
#        #    ("uint16_t", "int"),
#        #    ("uint32_t", "int"),
#        #    ("uint64_t", "int")
#        #):
#        #    self.elementary_type_container.add_child(name, ElementaryType(
#        #        name=name,
#        #        py_type_str=py_type_str
#        #    ))
#        #    #self.elementary_type_container.get_label(name).required = True

#    #def iter_interface_obj_items(
#    #    self: Self
#    #) -> Iterator[tuple[Obj, Label]]:
#    #    for container in (
#    #        self.elementary_type_container,
#    #        self.external_type_container,
#    #        self.external_include_container,
#    #        self.macro_container,
#    #        self.constant_container,
#    #        self.enum_container,
#    #        self.function_pointer_container,
#    #        self.handle_container,
#    #        self.struct_container,
#    #        self.union_container,
#    #        #self.command_container
#    #    ):
#    #        yield from container.iter_filtered_children_items()

#    #def get_interface_label(
#    #    self: Self,
#    #    name: str
#    #) -> Label:
#    #    for container in (
#    #        self.elementary_type_container,
#    #        self.external_type_container,
#    #        self.external_include_container,
#    #        self.macro_container,
#    #        self.constant_container,
#    #        self.enum_container,
#    #        self.function_pointer_container,
#    #        self.handle_container,
#    #        self.struct_container,
#    #        self.union_container,
#    #        #self.command_container
#    #    ):
#    #        if container.contains(name):
#    #            return container.get_label(name)
#    #    raise KeyError(name)

#    def read_obj(
#        self: Self,
#        name: str,
#        type_xml: etree.Element
#    ) -> None:
#        if (alias := type_xml.get("alias")) is not None:
#            self.objs.add_alias(name, alias)
#            return

#        required: bool | None = None
#        match type_xml.get("category"):
#            case None:
#                if self.objs.contains(name):
#                    return
#                obj = Typedef(
#                    c_type_str="void" if type_xml.get("requires", "").startswith("vk_video/") else PLATFORM_TYPE_DICT[name]
#                )
#                required = True
#                #obj.required = True
#                #self.obj_dict[name] = obj
#                #self.external_type_container.get_label(name).required = True

#            case "include":
#                if self.objs.contains(name):
#                    return
#                obj = ExternalInclude()
#                #self.external_include_container.add_child(name, ExternalInclude())

#            case "define":
#                obj = Macro(
#                    c_macro="".join(type_xml.itertext())
#                )
#                #self.macro_container.add_child(name, Macro(
#                #    c_macro="".join(type_xml.itertext())
#                #))

#            case "basetype":
#                obj = Typedef(
#                    c_type_str=BASE_TYPE_DICT[name]
#                )
#                #if (alias := type_xml.findtext("type")) is not None and alias.isidentifier():
#                #    self.elementary_type_container.add_child_alias(name, alias)
#                #else:
#                #    self.external_type_container.add_child(name, ExternalType(
#                #        name=name
#                #    ))

#            case "enum":
#                obj = Enum()
#                #self.enum_container.add_child(name, Enum())

#            case "bitmask":
#                obj = Typedef(
#                    c_type_str=type_xml.findtext("type", "")
#                )
#                #if (alias := type_xml.get("alias")) is not None:
#                #    self.elementary_type_container.add_child_alias(name, alias)
#                #else:
#                #    self.elementary_type_container.add_child_alias(name, type_xml.findtext("type", ""))

#            case "funcpointer":
#                obj = FunctionPointer(
#                    c_statement_str="".join(type_xml.itertext()),
#                    name=name
#                )

#            case "handle":
#                obj = Handle()

#            case "struct":
#                obj = Struct(
#                    member_c_decl_str_name_pairs=tuple(
#                        ("".join(member_xml.itertext()), member_xml.findtext("name", ""))
#                        for member_xml in tuple(type_xml.iterfind("member"))
#                    )
#                )

#            case "union":
#                obj = Union(
#                    member_c_decl_str_name_pairs=tuple(
#                        ("".join(member_xml.itertext()), member_xml.findtext("name", ""))
#                        for member_xml in tuple(type_xml.iterfind("member"))
#                    )
#                )

#            case _ as category:
#                raise ValueError(f"Unexpected category name: {category}")

#        self.objs.add_child(name, obj)
#        self.objs.get_label(name).mark_requirement(
#            batch_tag=("require" if required else "remove") if required is not None else None,
#            hidden=False,
#            tags=self.tags
#        )

#    def read_constant(
#        self: Self,
#        name: str,
#        enum_xml: etree.Element
#    ) -> None:
#        if self.objs.contains(name):
#            return
#        if (alias := enum_xml.get("alias")) is not None:
#            self.objs.add_alias(name, alias)
#            return
#        self.objs.add_child(name, Constant(
#            c_value=enum_xml.get("value", ""),
#            c_type_str=enum_xml.get("type")
#        ))

#    def read_enum_member(
#        self: Self,
#        name: str,
#        enum_xml: etree.Element,
#        enum: Enum
#    ) -> None:
#        if enum.members.contains(name):
#            return
#        if (alias := enum_xml.get("alias")) is not None:
#            enum.members.add_alias(name, alias)
#            return
#        enum.members.add_child(name, EnumMember())

#    def read_command(
#        self: Self,
#        command_xml: etree.Element
#    ) -> None:
#        if (alias := command_xml.get("alias")) is not None:
#            self.objs.add_alias(command_xml.get("name", ""), alias)
#            return
#        assert (proto_xml := command_xml.find("proto")) is not None
#        name = proto_xml.findtext("name", "")
#        self.objs.add_child(name, Command(
#            return_c_type_str=proto_xml.findtext("type", ""),
#            arg_c_decl_str_name_pairs=tuple(
#                ("".join(param_xml.itertext()), param_xml.findtext("name", ""))
#                for param_xml in command_xml.iterfind("param")
#            ),
#            name=name
#        ))

#    def build_cdef(
#        self: Self,
#        cdef_path: pathlib.Path
#    ) -> None:
#        with cdef_path.open("w") as file:
#            file.write("// Auto-generated C definitions\n")
#            for obj, label in self.objs.iter_filtered_items():
#                obj.write_cdef_incomplete(file, label)
#            for obj, label in self.objs.iter_filtered_items():
#                obj.write_cdef(file, label)

#    def build_ffi(
#        self: Self,
#        ffi_path: pathlib.Path,
#        cdef_path: pathlib.Path
#    ) -> None:
#        ffi = cffi.FFI()
#        ffi.cdef(csource=cdef_path.read_text())
#        ffi.set_source(
#            module_name=str(ffi_path.with_suffix("")).replace("\\", "."),
#            source="".join((
#                *(f"#define {define}\n" for define, enabled in self.defines.items() if enabled),
#                "#include <vulkan/vulkan.h>\n"
#            )),
#            include_dirs=["extern/vulkan/Include"],
#            library_dirs=["extern/vulkan/Lib"],
#            libraries=["vulkan-1"]
#        )
#        ffi.compile()

#    def build_pydef(
#        self: Self,
#        pydef_path: pathlib.Path,
#        ffi_path: pathlib.Path
#    ) -> None:
#        with pydef_path.open("w") as file:
#            file.write("from __future__ import annotations\n")
#            file.write("\n")
#            file.write("# Auto-generated python interface\n")
#            file.write("\n")
#            file.write("from enum import (\n")
#            file.write("    Enum,\n")
#            file.write("    Flag\n")
#            file.write(")\n")
#            file.write("from typing import (\n")
#            file.write("    Never,\n")
#            file.write("    Union\n")
#            file.write(")\n")
#            file.write("\n")
#            file.write("import cffi\n")
#            file.write("\n")
#            file.write(f"from {ffi_path.relative_to(pydef_path.parent).stem} import (\n")
#            file.write("    ffi,\n")
#            file.write("    lib\n")
#            file.write(")\n")
#            file.write("\n\n")
#            for obj, label in self.objs.iter_filtered_items():
#                obj.write_pydef(file, label)

#            #file.write("\n")
#            #file.write("RETURN_CODES.update({\n")
#            #file.write("    result_field.value: result_field.name\n")
#            #file.write("    for result_field in VkResult\n")
#            #file.write("    if isinstance(result_field.value, int)\n")
#            #file.write("})\n")

#            #file.write("\n")
#            #file.write("__all__ = (\n")
#            #for obj in self.iter_objs():
#            #    if isinstance(obj, ElementaryType | ExternalType):
#            #        continue
#            #    file.write(f"    \"{obj.name}\",\n")
#            #file.write(")\n")


#def main() -> None:
#    registry = Registry(
#        api="vulkan",
#        platform="win32",
#        defines=["VK_ENABLE_BETA_EXTENSIONS"]
#    )
#    for xml_path in (
#        "extern/xml/video.xml",
#        "extern/xml/vk.xml"
#    ):
#        registry.read_registry_xml(etree.parse(xml_path).getroot())


#    match parser.parse_args().mode:
#        case "all":
#            registry.build_cdef(cdef_path)
#            registry.build_ffi(ffi_path, cdef_path)
#            registry.build_pydef(pydef_path, ffi_path)

#        case "cdef":
#            registry.build_cdef(cdef_path)

#        case "ffi":
#            #registry.build_cdef(cdef_path)
#            registry.build_ffi(ffi_path, cdef_path)

#        case "pydef":
#            registry.build_pydef(pydef_path, ffi_path)


class Registry:
    __slots__ = (
        #"api",
        #"platform",
        "_define_list",
        "_include_list",
        "_tag_list",
        "_obj_dict"
        #"_requirement_dict"
        #"enum_children_dict"
    )

    def __init__(
        self: Self
        #api: str,
        #platform: str,
        #defines: list[str]
        #registry_xml_paths: list[pathlib.Path],
        #cdef_path: pathlib.Path,
        #pydef_path: pathlib.Path,
        #ffi_path: pathlib.Path
    ) -> None:
        #self.api: str = api
        #self.platform: str = platform
        self._define_list: list[str] = []
        self._include_list: list[str] = []
        self._tag_list: list[str] = []
        self._obj_dict: dict[str, Obj] = {}
        #self._requirement_dict: dict[str, RequirementRecord] = {}
        #self.enum_children_dict: dict[str, dict[str, Obj]] = {}

    @classmethod
    def _join_xml_text(
        cls: type[Self],
        xml: etree.Element,
        *,
        ignored_tags: list[str] | None = None
    ) -> str:

        def itertext(
            xml: etree.Element,
            ignored_tags: list[str] | None
        ) -> Iterator[str]:
            if xml.text is not None:
                yield xml.text
            for child in xml:
                if ignored_tags is None or child.tag not in ignored_tags:
                    yield from itertext(child, ignored_tags)
                if child.tail is not None:
                    yield child.tail

        return "".join(itertext(xml, ignored_tags))

    @classmethod
    def _check_api(
        cls: type[Self],
        xml: etree.Element,
        target_api: str
        #api: str | None,
        #target_api: str
    ) -> bool:
        api = xml.get("api")
        return api is None or target_api in api.split(",")

    @classmethod
    def _check_supported(
        cls: type[Self],
        xml: etree.Element,
        target_api: str
        #supported: str | None,
        #target_api: str
    ) -> bool:
        supported = xml.get("supported")
        return supported is None or target_api in supported.split(",") and supported != "disabled"

    @classmethod
    def _check_platform(
        cls: type[Self],
        xml: etree.Element,
        target_platform: str
        #platform: str | None,
        #target_platform: str
    ) -> bool:
        platform = xml.get("platform")
        return platform is None or platform == target_platform

    def _has_obj(
        self: Self,
        name: str
    ) -> bool:
        return name in self._obj_dict

    def _get_obj(
        self: Self,
        name: str
    ) -> Obj:
        return self._obj_dict[name]

    def _add_obj(
        self: Self,
        name: str,
        obj: Obj
    ) -> None:
        assert name not in self._obj_dict
        self._obj_dict[name] = obj
            #self._requirement_dict[name] = RequirementRecord()

    def _read_type_xml(
        self: Self,
        type_xml: etree.Element,
    ) -> None:
        name = type_xml.get("name", type_xml.findtext("name", ""))
        if (alias := type_xml.get("alias")) is not None:
            self._add_obj(name, AliasObj(
                alias=alias
            ))
            return

        match type_xml.get("category", "externtype"):
            case "include":
                if self._has_obj(name):
                    return
                obj = Include()

            case "define":
                define_contents = tuple(
                    match.group(1)
                    for line in self._join_xml_text(type_xml).replace("\\\n", "").splitlines()
                    if (match := re.fullmatch(fr"#define {name}\b(.*)", line.lstrip())) is not None
                )
                if len(define_contents) != 1:
                    obj = Define(
                        c_type=CType("void"),
                        argument_c_types=None
                    )
                else:
                    (define_content,) = define_contents
                    obj = Define(
                        c_type=CType("uint32_t"),
                        argument_c_types={
                            argument_name: CType("uint32_t")
                            for argument_name in arguments_match.group(1).split(", ")
                        } if (arguments_match := re.match(r"\((.*?)\)", define_content)) is not None else None
                    )

            case "basetype":
                obj = Typedef(
                    c_type=CType(BASE_TYPE_DICT[name])
                )

            case "externtype":
                if self._has_obj(name):
                    return
                if name not in PLATFORM_TYPE_DICT:
                    print("Missing externtype:", name)
                obj = Typedef(
                    c_type=CType(PLATFORM_TYPE_DICT.get(name, "void"))
                )

            case "bitmask":
                obj = Bitmask(
                    attr_requires=type_xml.get("requires")
                )

            case "enum":
                obj = Enum(
                    attr_type="enum",  # Fill later
                    attr_bitwidth=None  # Fill later
                )

            case "funcpointer":
                assert (match := re.fullmatch(
                    fr"typedef (.*?) \(VKAPI_PTR \*{name}\)\((.*)\);",
                    self._join_xml_text(type_xml).replace("\n", "")
                )) is not None
                obj = FunctionPointer(
                    return_c_type=CType(match.group(1)),
                    argument_c_types={
                        argument_name: CType(c_type_str)
                        for c_type_str, _, argument_name in (
                            argument_declaration.rpartition(" ")
                            for argument_declaration in arguments_str.split(",")
                        )
                    } if (arguments_str := match.group(2)) != "void" else {}
                )

            case "handle":
                obj = Handle(
                    attr_parent=type_xml.get("parent")
                )

            case "struct":
                obj = Struct(
                    fields={
                        member_xml.findtext("name", ""): Field(
                            c_type=CType(c_type_str),
                            bitwidth=int(bitwidth_str) if bitwidth_str else None,
                            attr_len=member_xml.get("len"),
                            attr_altlen=member_xml.get("altlen"),
                            attr_optional=member_xml.get("optional"),
                            attr_selector=member_xml.get("selector"),
                            attr_selection=member_xml.get("selection"),
                            attr_values=member_xml.get("values")
                        )
                        for member_xml, (c_type_str, _, bitwidth_str) in (
                            (member_xml, self._join_xml_text(member_xml, ignored_tags=["comment", "name"]).partition(":"))
                            for member_xml in type_xml.iterfind("member")
                        )
                    },
                    attr_structextends=type_xml.get("structextends"),
                    attr_allowduplicate=type_xml.get("allowduplicate")
                )

            case "union":
                obj = Union(
                    fields={
                        member_xml.findtext("name", ""): Field(
                            c_type=CType(c_type_str),
                            bitwidth=int(bitwidth_str) if bitwidth_str else None,
                            attr_len=member_xml.get("len"),
                            attr_altlen=member_xml.get("altlen"),
                            attr_optional=member_xml.get("optional"),
                            attr_selector=member_xml.get("selector"),
                            attr_selection=member_xml.get("selection"),
                            attr_values=member_xml.get("values")
                        )
                        for member_xml, (c_type_str, _, bitwidth_str) in (
                            (member_xml, self._join_xml_text(member_xml, ignored_tags=["comment", "name"]).partition(":"))
                            for member_xml in type_xml.iterfind("member")
                        )
                    }
                )

            case _:
                assert False

        self._add_obj(name, obj)

    def _read_enum_xml(
        self: Self,
        enum_xml: etree.Element,
        enum_name: str | None
    ) -> None:
        name = enum_xml.get("name", "")
        if self._has_obj(name):
            return
        if (alias := enum_xml.get("alias")) is not None:
            self._add_obj(name, AliasObj(
                alias=alias
            ))
            return

        if enum_name is None:
            if (attr_value := enum_xml.get("value")) is None:
                return
            if (c_type_str := enum_xml.get("type")) is not None:
                c_type = CType(c_type_str)
            elif attr_value.isidentifier():
                c_type = CType("uint32_t")
            elif re.fullmatch(r"\d+|0x[\dA-F]+", attr_value):
                c_type = CType("uint32_t")
            elif re.fullmatch(r"\"\w+\"", attr_value) is not None:
                c_type = CType("char []")
            else:
                assert False
            obj = Constant(
                c_type=c_type,
                attr_value=attr_value
            )
        else:
            obj = EnumMember(
                scope=enum_name,
                attr_protect=enum_xml.get("protect")
            )

        self._add_obj(name, obj)

    def _read_command_xml(
        self: Self,
        command_xml: etree.Element
    ) -> None:
        if (alias := command_xml.get("alias")) is not None:
            name = command_xml.get("name", "")
            self._add_obj(name, AliasObj(
                alias=alias
            ))
            return

        assert (proto_xml := command_xml.find("proto")) is not None
        name = proto_xml.findtext("name", "")
        scope = (
            first_param_type_str
            if (first_param_xml := command_xml.find("param")) is not None
            and (first_param_type_str := first_param_xml.findtext("type")) is not None
            and isinstance(self._get_obj(first_param_type_str), Handle)
            else None
        )
        self._add_obj(name, Command(
            scope=scope,
            arguments={
                param_xml.findtext("name", ""): Argument(
                    c_type=CType(self._join_xml_text(param_xml, ignored_tags=["comment", "name"])),
                    attr_len=param_xml.get("len"),
                    attr_altlen=param_xml.get("altlen"),
                    attr_optional=param_xml.get("optional"),
                    attr_selector=param_xml.get("selector"),
                )
                for param_xml in command_xml.iterfind("param")
            }
        ))

        #self._add_obj(self.obj_dict, Obj(
        #    name=(
        #        proto_xml.findtext("name", "")
        #        if (proto_xml := command_xml.find("proto")) is not None
        #        else command_xml.get("name", "")
        #    ),
        #    alias=command_xml.get("alias"),
        #    category="command",
        #    xml=command_xml
        #))

    #def _read_requirement_unit_xml(
    #    self: Self,
    #    requirement_unit_xml: etree.Element,
    #    remove: bool
    #) -> None:
    #    name = requirement_unit_xml.get("name", "")
    #    if remove:
    #        self._get_obj(name).removed = True
    #        return

    #    #protect = requirement_unit_xml.get("protect")
    #    if requirement_unit_xml.tag == "enum":
    #        self._read_extended_enum_xml(requirement_unit_xml)

    #    self._get_obj(name).required = True
    #    #obj = self.obj_dict[requirement_unit_xml.get("name", "")]
    #    #requirement_batch_tag = requirement_batch_xml.tag
    #    #enabled = (protect := requirement_unit_xml.get("protect")) is None or self._define_list.get(protect, False)
    #    #obj.mark_requirement(requirement_batch_tag, enabled)
    #    #if obj.category == "enum":
    #    #    for enum_member in self.enum_children_dict.get(obj.name, {}).values():
    #    #        if enum_member.category == "enum_member_intrinsic":
    #    #            enum_member.mark_requirement(requirement_batch_tag, enabled)


    #def _read_requirement_batch_xml(
    #    self: Self,
    #    requirement_batch_xml: etree.Element,
    #    api: str
    #) -> None:
    #    for requirement_unit_xml in requirement_batch_xml:
    #        if not self._check_api(requirement_unit_xml, api):
    #            continue
    #        #protect = requirement_unit_xml.get("protect")
    #        if requirement_unit_xml.tag == "enum":
    #            enum_name = requirement_unit_xml.get("extends")
    #            obj = Obj(
    #                name=requirement_unit_xml.get("name", ""),
    #                alias=requirement_unit_xml.get("alias"),
    #                category="enum_member_extrinsic" if enum_name is not None else "constant_extrinsic",
    #                xml=requirement_unit_xml
    #            )
    #            self._add_obj(obj)
    #            #if enum_name is not None:
    #            #    self._add_obj(self.enum_children_dict.setdefault(enum_name, {}), obj)

    #        obj = self.obj_dict[requirement_unit_xml.get("name", "")]
    #        requirement_batch_tag = requirement_batch_xml.tag
    #        enabled = (protect := requirement_unit_xml.get("protect")) is None or self._define_list.get(protect, False)
    #        obj.mark_requirement(requirement_batch_tag, enabled)
    #        if obj.category == "enum":
    #            for enum_member in self.enum_children_dict.get(obj.name, {}).values():
    #                if enum_member.category == "enum_member_intrinsic":
    #                    enum_member.mark_requirement(requirement_batch_tag, enabled)

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

    def _read_registry_xml(
        self: Self,
        registry_xml: etree.Element,
        api: str,
        platform: str
        #registry_xml_path: pathlib.Path
    ) -> None:
        for xml in registry_xml:
            match xml.tag:
                case "platforms":
                    for platform_xml in xml.iterfind("platform"):
                        if platform_xml.get("name", "") == platform:
                            self._define_list.append(platform_xml.get("protect", ""))

                case "tags":
                    for tag_xml in xml.iterfind("tag"):
                        self._tag_list.append(tag_xml.get("name", ""))

                case "types":
                    for type_xml in xml.iterfind("type"):
                        if not self._check_api(type_xml, api):
                            continue
                        self._read_type_xml(type_xml)
                        #self._add_obj(self.obj_dict, Obj(
                        #    name=type_xml.get("name", type_xml.findtext("name", "")),
                        #    alias=type_xml.get("alias"),
                        #    category=type_xml.get("category", "externtype"),
                        #    xml=type_xml
                        #))

                case "enums":
                    #enum_dict = (
                    #    enum_children_dict.setdefault(enum_name, {})
                    #    if (enum_name := xml.get("name", "")) != "API Constants"
                    #    else None
                    #)
                    #enum_name = xml.get("name", "")
                    if (enum_name := xml.get("name", "")) == "API Constants":
                        enum_name = None
                    else:
                        assert isinstance(enum := self._get_obj(enum_name), Enum)
                        enum.attr_type = xml.get("type", "enum")
                        enum.attr_bitwidth = xml.get("bitwidth")
                    for enum_xml in xml.iterfind("enum"):
                        self._read_enum_xml(
                            enum_xml=enum_xml,
                            enum_name=enum_name
                        )
                        if enum_name is not None:
                            name = enum_xml.get("name", "")
                            self._get_obj(name).required = True
                        #name = enum_xml.get("name", "")
                        #if (alias := enum_xml.get("alias")) is not None:
                        #    self._add_obj(name, AliasObj(
                        #        alias=alias
                        #    ))
                        #    continue
                        #if enum_name is None:
                        #    obj = Constant(
                        #        c_type=CType(enum_xml.get("type", "")),
                        #        attr_value=enum_xml.get("value", "")
                        #    )
                        #else:
                        #    obj = EnumMember(
                        #        scope=enum_name,
                        #        required=True
                        #    )
                        #self._add_obj(name, obj)
                    #for enum_xml in xml.iterfind("enum"):
                    #    obj = Obj(
                    #        name=enum_xml.get("name", ""),
                    #        alias=enum_xml.get("alias"),
                    #        category="enum_member_intrinsic" if enum_name is not None else "constant_intrinsic",
                    #        xml=enum_xml
                    #    )
                    #    self._add_obj(self.obj_dict, obj)
                    #    if enum_name is not None:
                    #        self._add_obj(self.enum_children_dict.setdefault(enum_name, {}), obj)
                    #    for enum_xml in xml.iterfind("enum"):
                    #        _add_obj(obj_dict, Obj(
                    #            name=enum_xml.get("name", ""),
                    #            category="constant",
                    #            xml=enum_xml
                    #        ))
                    #else:
                    #    #assert isinstance((enum := objs.get_child(enum_name)), Enum)
                    #    #enum.bitmask = xml.get("type") == "bitmask"
                    #    #enum.long_bitwidth = xml.get("bitwidth") == "64"
                    #    for enum_xml in xml.iterfind("enum"):
                    #        _add_obj(obj_dict, _add_obj(enum_children_dict[enum_name], Obj(
                    #            name=enum_xml.get("name", ""),
                    #            category="enum_member",
                    #            xml=enum_xml
                    #        )))
                    #        #member_name = enum_xml.get("name", "")
                    #        #read_enum_member(member_name, enum_xml, enum)
                    #        #enum.members.get_label(member_name).mark_requirement(
                    #        #    batch_tag="require",
                    #        #    hidden=False
                    #        #    #tags=_tag_list
                    #        #)

                case "commands":
                    for command_xml in xml.iterfind("command"):
                        if not self._check_api(command_xml, api):
                            continue
                        self._read_command_xml(
                            command_xml=command_xml
                        )

                case "feature":
                    if not self._check_api(xml, api):
                        continue
                    for requirement_batch_xml in xml:
                        if requirement_batch_xml.tag not in ("require", "remove"):
                            continue
                        remove = requirement_batch_xml.tag == "remove"
                        for requirement_unit_xml in requirement_batch_xml:
                            if requirement_unit_xml.tag not in ("type", "enum", "command"):
                                continue
                            if not self._check_api(requirement_unit_xml, api):
                                continue
                            name = requirement_unit_xml.get("name", "")
                            if remove:
                                self._get_obj(name).removed = True
                                continue
                            #protect = requirement_unit_xml.get("protect")
                            if requirement_unit_xml.tag == "enum":
                                self._read_enum_xml(
                                    enum_xml=requirement_unit_xml,
                                    enum_name=requirement_unit_xml.get("extends")
                                )
                            self._get_obj(name).required = True
                            #self._read_requirement_unit_xml(
                            #    requirement_unit_xml=requirement_unit_xml,
                            #    remove=remove
                            #)
                        #self._read_requirement_batch_xml(
                        #    requirement_batch_xml=requirement_batch_xml,
                        #    api=api
                        #)
                            #name = feature_unit_xml.get("name", "")
                            #match feature_unit_xml.tag:
                            #    case "type":
                            #        obj = obj_dict[name]
                            #    case "enum":
                            #        obj = add_enum_member(
                            #            obj_dict=obj_dict,
                            #            enum_dict=(
                            #                enum_children_dict[extends]
                            #                if (extends := feature_unit_xml.get("extends")) is not None
                            #                else None
                            #            ),
                            #            enum_xml=feature_unit_xml
                            #        )
                            #        #if (extends := feature_unit_xml.get("extends")) is not None:
                            #        #    #assert isinstance((enum := objs.get_child(extends)), Enum)
                            #        #    obj = _add_obj(obj_dict, _add_obj(enum_children_dict[extends], Obj(
                            #        #        name=name,
                            #        #        category="enum_member",
                            #        #        xml=feature_unit_xml
                            #        #    )))
                            #        #    #read_enum_member(name, feature_unit_xml, enum)
                            #        #    #label = enum.members.get_label(name)
                            #        #else:
                            #        #    obj = _add_obj(obj_dict, Obj(
                            #        #        name=name,
                            #        #        category="constant",
                            #        #        xml=feature_unit_xml
                            #        #    ))
                            #        #    #read_constant(name, feature_unit_xml)
                            #        #    #label = objs.get_label(name)
                            #    case "command":
                            #        obj = obj_dict[name]
                            #        #label = objs.get_label(name)
                            #    case _:
                            #        continue
                            #obj

                case "extensions":
                    for extension_xml in xml.iterfind("extension"):
                        if not self._check_api(extension_xml, api) or not self._check_supported(extension_xml, api) \
                                or not self._check_platform(extension_xml, platform):
                            continue
                        for requirement_batch_xml in extension_xml:
                            if not self._check_api(requirement_batch_xml, api):
                                continue
                            #self._read_requirement_batch_xml(
                            #    requirement_batch_xml=requirement_batch_xml,
                            #    api=api
                            #)
                            remove = requirement_batch_xml.tag == "remove"
                            for requirement_unit_xml in requirement_batch_xml:
                                if requirement_unit_xml.tag not in ("type", "enum", "command"):
                                    continue
                                if not self._check_api(requirement_unit_xml, api):
                                    continue
                                name = requirement_unit_xml.get("name", "")
                                if remove:
                                    self._get_obj(name).removed = True
                                    continue
                                #protect = requirement_unit_xml.get("protect")
                                if requirement_unit_xml.tag == "enum":
                                    self._read_enum_xml(
                                        enum_xml=requirement_unit_xml,
                                        enum_name=requirement_unit_xml.get("extends")
                                    )
                                self._get_obj(name).required = True
                            #    if requirement_unit_xml.tag == "enum":
                            #        add_enum_member(
                            #            obj_dict=obj_dict,
                            #            enum_dict=(
                            #                enum_children_dict[extends]
                            #                if (extends := requirement_unit_xml.get("extends")) is not None
                            #                else None
                            #            ),
                            #            enum_xml=requirement_unit_xml
                            #        )
                            #    obj_dict[requirement_unit_xml.get("name", "")].mark_requirement(
                            #        batch_tag=requirement_batch_xml.tag,
                            #        enabled=_define_list.get(requirement_unit_xml.get("protect", ""), False)
                            #        #hidden=(protect := requirement_unit_xml.get("protect")) is not None and not _define_list.get(protect, False)
                            #        #tags=_tag_list
                            #    )
                            #    #name = extension_unit_xml.get("name", "")
                            #    #match extension_unit_xml.tag:
                            #    #    case "type":
                            #    #        obj = obj_dict[name]
                            #    #    case "enum":
                            #    #        if (extends := extension_unit_xml.get("extends")) is not None:
                            #    #            #assert isinstance((enum := objs.get_child(extends)), Enum)
                            #    #            obj = _add_obj(obj_dict, _add_obj(enum_children_dict[extends], Obj(
                            #    #                name=name,
                            #    #                category="enum_member",
                            #    #                xml=extension_unit_xml
                            #    #            )))
                            #    #            #read_enum_member(name, extension_unit_xml, enum)
                            #    #            #label = enum.members.get_label(name)
                            #    #        else:
                            #    #            obj = _add_obj(obj_dict, Obj(
                            #    #                name=name,
                            #    #                category="constant",
                            #    #                xml=extension_unit_xml
                            #    #            ))
                            #    #            #read_constant(name, extension_unit_xml)
                            #    #            #label = objs.get_label(name)
                            #    #    case "command":
                            #    #        obj = obj_dict[name]
                            #    #        #label = objs.get_label(name)
                            #    #    case _:
                            #    #        continue
                            #    ##print(name, tag)
                            #    #protect = extension_unit_xml.get("protect")
                            #    #obj.mark_requirement(
                            #    #    batch_tag=extension_batch_xml.tag,
                            #    #    hidden=protect is not None and not _define_list.get(protect, False)
                            #    #    #tags=tags
                            #    #)

    def read(
        self: Self,
        registry_xml_paths: list[pathlib.Path],
        api: str,
        platform: str,
        defines: list[str]
    ) -> None:
        self._define_list.extend(defines)
        for name, py_type_str in BUILTIN_TYPE_DICT.items():
            self._add_obj(name, BuiltinType(
                c_type=CType(name),
                py_type_str=py_type_str
            ))
        #self.obj_dict.update(
        #    (name, Obj(
        #        name=name,
        #        alias=None,
        #        category="elememtary_type",
        #        xml=etree.Element("type", {
        #            "py_type_str": py_type_str
        #        })
        #    ))
        #    for name, py_type_str in BUILTIN_TYPE_DICT.items()
        #)
        for registry_xml_path in registry_xml_paths:
            self._include_list.extend(REGISTRY_SRC_DICT[registry_xml_path.name])
            #for include in REGISTRY_SRC_DICT[registry_xml_path.name]:
            #    self._add_obj(include, Include())
            #includes = REGISTRY_SRC_DICT[registry_xml_path.name]  # TODO
            #registry_xml = etree.parse(registry_xml_path).getroot()
            #for xml in list(registry_xml.iter()):
            #    xml[:] = filter(
            #        lambda child_xml: child_xml.tag != "comment",
            #        xml
            #    )  # TODO: better approach?
            self._read_registry_xml(
                registry_xml=etree.parse(registry_xml_path).getroot(),
                api=api,
                platform=platform
            )

    def _check_obj_requirement(
        self: Self,
        obj: Obj
    ) -> bool:
        return (
            (obj.scope is None or self._check_obj_requirement(self._get_obj(obj.scope)))
            and obj.required
            and not obj.removed
            and (obj.attr_protect is None or obj.attr_protect in self._define_list)
        )

    def _get_obj_def(
        self: Self,
        category: str,
        section: str,
        name: str,
        xml: etree.Element
    ) -> str | None:
        match category:
            case "include":
                return None
                #match section:
                #    case "cdef_preamble":
                #        return None
                #    case "pydef_preamble":
                #        return None
                #    case "cdef_document":
                #        return None
                #    case "pydef_document":
                #        return None

            case "define":
                c_macro_str = "".join(xml.itertext())
                if (match := re.match(fr"#define {name}(\(.*?\))?", c_macro_str)) is None:
                    return None
                args = (
                    tuple(arg_match.group() for arg_match in re.finditer(r"\w+", args_match))
                    if (args_match := match.group(1)) is not None
                    else None
                )
                #    write_cdef(f"uint32_t {name}({", ".join("uint32_t" for _ in args)});")
                #    write_pydef(
                #        f"def {name}({", ".join(f"{arg}: int" for arg in args)}) -> int:",
                #        f"    return lib.{name}({", ".join(args)})"
                #    )
                #else:
                #    write_cdef(f"static const uint32_t {name};")
                #    write_pydef(f"{name}: int = lib.{name}")
                match section:
                    case "cdef_preamble":
                        if args is None:
                            return f"""
                                static const uint32_t {name};
                            """
                        return f"""
                            uint32_t {name}({", ".join("uint32_t" for _ in args)});
                        """
                    case "pydef_preamble":
                        if args is None:
                            return f"""
                                {name}: int = lib.{name}
                            """
                        return f"""
                            def {name}({", ".join(f"{arg}: int" for arg in args)}) -> int:
                                return lib.{name}({", ".join(args)})
                        """
                    case _:
                        return None

            case "basetype":
                match section:
                    case "cdef_preamble":
                        c_type = ffi.typeof(BASETYPE_DICT[name])
                        return f"""
                            typedef {c_type.cname} {name};
                        """
                    case _:
                        return None

            case "externtype":
                match section:
                    case "cdef_preamble":
                        c_type = ffi.typeof(PLATFORM_TYPE_DICT[name])
                        #c_type_str = ffi.getctype("void" if obj.xml.get("requires", "").startswith("vk_video/") else PLATFORM_TYPE_DICT[name])
                        return f"""
                            typedef {c_type.cname} {name};
                        """
                    case _:
                        return None

            case "enum":
                match section:
                    case "cdef_preamble":
                        return f"""
                            typedef {f"VkFlags64" if xml.get("bitwidth") == "64" else f"enum {name} {{ ... }}"} {name};
                        """
                    case _:
                        return None

            case "bitmask":
                match section:
                    case "cdef_preamble":
                        c_type = ffi.typeof(xml.findtext("type", ""))
                        return f"""
                            typedef {c_type.cname} {name};
                        """
                    case _:
                        return None

            case "funcpointer":
                match section:
                    case "cdef_document":
                        c_statement_str = "".join(xml.itertext())
                        assert (match := re.fullmatch(
                            fr"typedef (.*?)\(VKAPI_PTR \*{name}\)(.*);",
                            c_statement_str,
                            flags=re.DOTALL
                        )) is not None
                        c_type = ffi.typeof(f"{match.group(1)}(*){match.group(2)}")
                        return f"""
                            {ffi.getctype(c_type, name)};
                        """
                    case _:
                        return None

            case "handle":
                match section:
                    case "cdef_preamble":
                        return f"""
                            typedef struct {name}_T *{name};
                        """
                    case "pydef_document":
                        return f"""
                            class {name}(VulkanCData):
                                __slots__ = ()
                        """

            case "struct":
                match section:
                    case "cdef_preamble":
                        return f"""
                            typedef struct {name} {name};
                        """
                    case _:
                        return None

            case "union":
                match section:
                    case "cdef_preamble":
                        return f"""
                            typedef union {name} {name};
                        """
                    case _:
                        return None

            case "constant_intrinsic":
                match section:
                    case "cdef_preamble":
                        c_value = xml.get("value", "")
                        if c_value.isdecimal():
                            return f"""
                                #define {name} {c_value}
                            """
                        c_type = ffi.typeof(xml.get("type", ""))
                        return f"""
                            static const {ffi.getctype(c_type, name)};
                        """
                    case _:
                        return None

            case "constant_extrinsic":
                match section:
                    case "cdef_preamble":
                        c_value = xml.get("value", "")
                        if c_value.isdecimal():
                            return f"""
                                #define {name} {c_value}
                            """
                        if c_value.isidentifier():
                            c_type = ffi.typeof("uint32_t")
                        elif re.fullmatch(r"0x[\dA-F]+", c_value) is not None:
                            c_type = ffi.typeof("uint32_t")
                        elif re.fullmatch(r"\"\w+\"", c_value) is not None:
                            c_type = ffi.typeof("char []")
                        else:
                            assert False
                        return f"""
                            static const {ffi.getctype(c_type, name)};
                        """
                    case _:
                        return None

            case "enum_member_intrinsic":
                match section:
                    case "cdef_preamble":
                        return f"""
                            static const uint64_t {name};
                        """
                    case _:
                        return None

            case "enum_member_extrinsic":
                match section:
                    case "cdef_preamble":
                        return f"""
                            static const uint64_t {name};
                        """
                    case _:
                        return None

            case "command":
                return None

        assert False

    def _write_str(
        self: Self,
        file: TextIO,
        content: str
    ) -> None:
        lines = content.splitlines()
        assert lines.pop(0) == ""
        spaces = lines.pop(-1) + "    "
        assert not spaces.strip(" ")
        file.write("\n")
        for line in lines:
            if line:
                assert line.startswith(spaces)
                line = line.removeprefix(spaces)
            file.write(f"{line}\n")

    def _write_cdef(
        self: Self,
        cdef_file: TextIO,
        obj_items_grouped: dict[type[Obj], list[tuple[str, Obj]]]
    ) -> None:
        pass

    def _write_pydef(
        self: Self,
        pydef_file: TextIO,
        obj_items_grouped: dict[type[Obj], list[tuple[str, Obj]]]
    ) -> None:
        pass

    def write(
        self: Self,
        cdef_path: pathlib.Path,
        pydef_path: pathlib.Path,
        ffi_path: pathlib.Path,
        build_cdef: bool,
        build_pydef: bool,
        build_ffi: bool
    ) -> None:
        obj_items: list[tuple[str, Obj]] = []
        for name, obj in self._obj_dict.items():
            while isinstance(obj, AliasObj) and self._check_obj_requirement(obj):
                obj = self._obj_dict[obj.alias]
            if not self._check_obj_requirement(obj):
                continue
            obj_items.append((name, obj))
        #obj_triplets: list[tuple[str, str, etree.Element]] = []
        #for name, obj in self.obj_dict.items():
        #    while obj.alias is not None:
        #        obj = self.obj_dict[obj.alias]
        #    if obj.check_requirement():
        #        obj_triplets.append((obj.category, name, obj.xml))

        obj_classes: list[type[Obj]] = [
            Include,
            Define,
            BuiltinType,
            Typedef,
            Bitmask,
            Enum,
            FunctionPointer,
            Handle,
            Struct,
            Union,
            Constant,
            EnumMember,
            Command
        ]
        obj_items.sort(key=lambda t: obj_classes.index(type(t[1])))
        obj_items_grouped: dict[type[Obj], list[tuple[str, Obj]]] = {
            obj_cls: []
            for obj_cls in obj_classes
        }
        for obj_cls, obj_items_iter in itertools.groupby(obj_items, key=lambda t: type(t[1])):
            obj_items_grouped[obj_cls].extend(obj_items_iter)

        #category_order = [
        #    "include",
        #    "define",
        #    "basetype",
        #    "externtype",
        #    "enum",
        #    "bitmask",
        #    "funcpointer",
        #    "handle",
        #    "struct",
        #    "union",
        #    "constant_intrinsic",
        #    "constant_extrinsic",
        #    "enum_member_intrinsic",
        #    "enum_member_extrinsic",
        #    "command"
        #]
        #obj_triplets.sort(key=lambda t: category_order.index(t[0]))

        if build_cdef:
            with cdef_path.open("w") as cdef_file:
                self._write_str(cdef_file, f"""
                    // Auto-generated C definitions
                """)
                self._write_cdef(
                    cdef_file=cdef_file,
                    obj_items_grouped=obj_items_grouped
                )
                #for section in ("cdef_preamble", "cdef_document"):
                #    for category, name, xml in obj_triplets:
                #        self._write_str(cdef_file, self._get_obj_def(
                #            category=category,
                #            section=section,
                #            name=name,
                #            xml=xml
                #        ))

        if build_pydef:
            #self._build_pydef(
            #    pydef_path=pydef_path,
            #    obj_items_grouped=obj_items_grouped
            #)
            with pydef_path.open("w") as pydef_file:
                self._write_str(pydef_file, f"""
                    from __future__ import annotations

                    # Auto-generated python interface

                    from enum import (
                        Enum,
                        Flag
                    )
                    from typing import (
                        Never,
                        Union
                    )

                    import cffi

                    from {ffi_path.relative_to(pydef_path.parent).stem} import (
                        ffi,
                        lib
                    )

                """)
                self._write_pydef(
                    pydef_file=pydef_file,
                    obj_items_grouped=obj_items_grouped
                )
                #for section in ("pydef_preamble", "pydef_document"):
                #    for category, name, xml in obj_triplets:
                #        self._write_str(pydef_file, self._get_obj_def(
                #            category=category,
                #            section=section,
                #            name=name,
                #            xml=xml
                #        ))

        if build_ffi:
            ffi = cffi.FFI()
            ffi.cdef(csource=cdef_path.read_text())
            ffi.set_source(
                module_name=str(ffi_path.with_suffix("")).replace("\\", "."),
                source="".join((
                    *(f"#define {define}\n" for define in self._define_list),
                    *(f"#include <{include}>\n" for include in self._include_list)
                )),
                include_dirs=["extern/vulkan/Include"],
                library_dirs=["extern/vulkan/Lib"],
                libraries=["vulkan-1"]
            )
            ffi.compile()

        #def write_cdef(
        #    *cdef_strs: str
        #) -> None:
        #    cdef_str = "\n".join(cdef_strs)
        #    ffi.cdef(cdef_str)
        #    cdef_file.write(f"\n{cdef_str}\n")

        #def write_pydef(
        #    *pydef_strs: str
        #) -> None:
        #    pydef_str = "\n".join(pydef_strs)
        #    pydef_file.write(f"\n{pydef_str}\n")

        #def write_preamble(
        #    category: str,
        #    name: str,
        #    xml: etree.Element
        #) -> None:

        #def write_document(
        #    category: str,
        #    name: str,
        #    xml: etree.Element
        #) -> None:
        #    match category:
        #        case "":
        #            pass  # TODO

        #        case "include":
        #            pass

        #        case "define":
        #            pass

        #        case "basetype":
        #            pass  # TODO

        #        case "enum":
        #            pass  # TODO

        #        case "bitmask":
        #            pass  # TODO

        #        case "funcpointer":
        #            pass

        #        case "handle":
        #            write_pydef(
        #                f"class {name}(VulkanCData):",
        #                f"    __slots__ = ()"
        #            )

        #        case "struct":
        #            pass  # TODO

        #        case "union":
        #            pass  # TODO

        #        case "constant_intrinsic":
        #            pass

        #        case "constant_extrinsic":
        #            pass

        #        case "enum_member_intrinsic":
        #            pass

        #        case "enum_member_extrinsic":
        #            pass

        #        case "command":
        #            pass  # TODO

        #        case _:
        #            assert False

        #write_cdef("// Auto-generated C definitions")
        #write_pydef(
        #    "from __future__ import annotations",
        #    "",
        #    "# Auto-generated python interface",
        #    "",
        #    "from enum import (",
        #    "    Enum,",
        #    "    Flag",
        #    ")",
        #    "from typing import (",
        #    "    Never,",
        #    "    Union",
        #    ")",
        #    "",
        #    "import cffi",
        #    "",
        #    f"from {ffi_path.relative_to(pydef_path.parent).stem} import (",
        #    "    ffi,",
        #    "    lib",
        #    ")",
        #    ""
        #)

        
        #for category, name, xml in obj_triplets:
        #    write_preamble(category, name, xml)
        #for category, name, xml in obj_triplets:
        #    write_document(category, name, xml)

        #ffi.set_source(
        #    module_name=str(ffi_path.with_suffix("")).replace("\\", "."),
        #    source="".join((
        #        *(f"#define {define}\n" for define, enabled in self._define_list.items() if enabled),
        #        "#include <vulkan/vulkan.h>\n"
        #    )),
        #    include_dirs=["extern/vulkan/Include"],
        #    library_dirs=["extern/vulkan/Lib"],
        #    libraries=["vulkan-1"]
        #)
        #ffi.compile()


if __name__ == "__main__":
    modes = {
        "all": ["build_cdef", "build_pydef", "build_ffi"],
        "cdef": ["build_cdef"],
        "pydef": ["build_pydef"],
        "ffi": ["build_ffi"],
    }
    parser = argparse.ArgumentParser()
    parser.add_argument("mode", choices=modes)
    commands = modes[parser.parse_args().mode]

    generated_dir = pathlib.Path("generated")
    generated_dir.mkdir(exist_ok=True)

    registry = Registry()
    registry.read(
        registry_xml_paths=[
            pathlib.Path("extern/xml/video.xml"),
            pathlib.Path("extern/xml/vk.xml")
        ],
        api="vulkan",
        platform="win32",
        defines=[
            "VK_ENABLE_BETA_EXTENSIONS"
        ]
    )
    registry.write(
        cdef_path=generated_dir.joinpath("_vulkan_cdef.h"),
        pydef_path=generated_dir.joinpath("_vulkan.py"),
        ffi_path=generated_dir.joinpath("_vulkan_ffi.py"),
        build_cdef="build_cdef" in commands,
        build_pydef="build_pydef" in commands,
        build_ffi="build_ffi" in commands
    )
