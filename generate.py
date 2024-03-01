from __future__ import annotations

import argparse
import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    Callable,
    ClassVar,
    Final,
    Iterator,
    Mapping,
    Self,
    Union
)

import attrs


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
        "_base_type_str",
        "_const_specifier",
        "_pointer_const_specifiers",
        "_array_size_strs",
        "_array_sizes"
    )

    _unresolved_c_types: ClassVar[list[CType]] = []

    def __init__(
        self: Self,
        c_type_str: str
    ) -> None:
        super().__init__()
        base_type_str, const_specifier, pointer_const_specifiers, array_size_strs = type(self)._parse_c_type_str(c_type_str)
        self._base_type_str: str = base_type_str
        self._const_specifier: bool = const_specifier
        self._pointer_const_specifiers: tuple[bool, ...] = pointer_const_specifiers
        self._array_size_strs: tuple[str, ...] = array_size_strs
        if any(
            array_size_str.isidentifier()
            for array_size_str in array_size_strs
        ):
            cls = type(self)
            cls._unresolved_c_types.append(self)

    @classmethod
    def _parse_c_type_str(
        cls: type[Self],
        c_type_str: str
    ) -> tuple[str, bool, tuple[bool, ...], tuple[str, ...]]:
        base_type_strs: list[str] = []
        const_specifier: bool = False
        pointer_const_specifiers: list[bool] = []
        array_size_strs: list[str] = []

        tokens = (match.group() for match in re.finditer(r"\w+|\S", c_type_str))
        next_token = next(tokens)
        if next_token == "const":
            const_specifier = True
            next_token = next(tokens)
        while next_token.isidentifier() and next_token != "const":
            base_type_strs.append(next_token)
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
        return " ".join(base_type_strs), const_specifier, tuple(pointer_const_specifiers), tuple(array_size_strs)

    @classmethod
    def resolve_array_sizes(
        cls: type[Self],
        array_size_values: dict[str, str]
    ) -> None:
        while cls._unresolved_c_types:
            c_type = cls._unresolved_c_types.pop()
            c_type._array_size_strs = tuple(
                array_size_values[array_size_str] if array_size_str.isidentifier() else array_size_str
                for array_size_str in c_type._array_size_strs
            )

    def format(
        self: Self,
        name: str | None = None
    ) -> str:
        return f"""{self._base_type_str}{" const" if self._const_specifier else ""}{"".join(
            f" *{f" const" if pointer_const_specifier else ""}"
            for pointer_const_specifier in self._pointer_const_specifiers
        )}{f" {name}" if name is not None else ""}{"".join(
            f"[{array_size_str}]"
            for array_size_str in self._array_size_strs
        )}"""


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
class Record:
    pass


@attrs.define(kw_only=True)
class BlankRecord(Record):
    pass


@attrs.define(kw_only=True)
class BuiltinTypeRecord(Record):
    c_type: CType
    py_type_str: str


@attrs.define(kw_only=True)
class TypedefRecord(Record):
    c_type: CType


@attrs.define(kw_only=True)
class BitmaskRecord(Record):
    attr_type: str
    attr_requires: str | None


@attrs.define(kw_only=True)
class EnumRecord(Record):
    attr_type: str  # "enum" | "bitmask"
    attr_bitwidth: str | None


@attrs.define(kw_only=True)
class HandleRecord(Record):
    attr_parent: str | None


@attrs.define(kw_only=True)
class StructRecord(Record):
    fields: dict[str, Field]
    attr_structextends: str | None
    attr_allowduplicate: str | None


@attrs.define(kw_only=True)
class UnionRecord(Record):
    fields: dict[str, Field]


@attrs.define(kw_only=True)
class FunctionPointerRecord(Record):
    return_c_type: CType
    argument_c_types: dict[str, CType]


@attrs.define(kw_only=True)
class MacroRecord(Record):
    c_type: CType


@attrs.define(kw_only=True)
class FunctionMacroRecord(Record):
    return_c_type: CType
    argument_c_types: dict[str, CType]


@attrs.define(kw_only=True)
class ConstantRecord(Record):
    c_type: CType
    attr_value: str


@attrs.define(kw_only=True)
class EnumMemberRecord(Record):
    enum_name: str


@attrs.define(kw_only=True)
class CommandRecord(Record):
    handle_name: str | None
    return_c_type: CType
    arguments: dict[str, Argument]
    attr_type: str | None  # "instance" | "device" | None


class Requirement:
    __slots__ = (
        "_required",
        "_removed"
    )

    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self._required: bool = False
        self._removed: bool = False

    def mark_required(
        self: Self
    ) -> None:
        self._required = True

    def mark_removed(
        self: Self
    ) -> None:
        self._removed = True

    def check_requirement(
        self: Self
    ) -> bool:
        return self._required and not self._removed


class RecordCollection[T: Record, **P](Mapping[str, T]):
    __slots__ = (
        "_record_constructor",
        "_record_dict",
        "_alias_forwardref_dict",
        "_requirement_dict"
    )

    def __init__(
        self: Self,
        record_constructor: Callable[P, T]
    ) -> None:
        super().__init__()
        self._record_constructor: Callable[P, T] = record_constructor
        self._record_dict: dict[str, T] = {}
        self._alias_forwardref_dict: dict[str, list[str]] = {}
        self._requirement_dict: dict[str, Requirement] = {}

    def __len__(
        self: Self
    ) -> int:
        return len(self._record_dict)

    def __iter__(
        self: Self
    ) -> Iterator[str]:
        yield from self._record_dict

    def __getitem__(
        self: Self,
        __name: str
    ) -> T:
        return self._record_dict[__name]

    def new(
        self: Self,
        name: str,
        *args: P.args,
        **kwargs: P.kwargs
    ) -> None:
        assert name not in self._requirement_dict
        self._requirement_dict[name] = Requirement()
        self._record_dict[name] = self._record_constructor(*args, **kwargs)

        resolvable_aliases = [name]
        while resolvable_aliases:
            alias = resolvable_aliases.pop(0)
            for name in self._alias_forwardref_dict.pop(alias, []):
                self._record_dict[name] = self._record_dict[alias]
                resolvable_aliases.append(name)

    def new_alias(
        self: Self,
        name: str,
        alias: str
    ) -> None:
        assert name not in self._requirement_dict
        self._requirement_dict[name] = Requirement()
        if alias in self._record_dict:
            self._record_dict[name] = self._record_dict[alias]
        else:
            self._alias_forwardref_dict.setdefault(alias, []).append(name)

    #def get[DefaultT](
    #    self: Self,
    #    __name: str,
    #    __default: DefaultT
    #) -> T | DefaultT:
    #    try:
    #        return self[__name]
    #    except KeyError:
    #        return __default

    def get_requirement(
        self: Self,
        __name: str
    ) -> Requirement:
        try:
            return self._requirement_dict[__name]
        except KeyError:
            raise KeyError(__name) from None

    def finalize(
        self: Self,
        filter: Callable[[T], bool] | None = None
    ) -> None:
        assert not self._alias_forwardref_dict
        self._record_dict = {
            name: record
            for name, record in self._record_dict.items()
            if self._requirement_dict[name].check_requirement()
            and (filter is None or filter(record))
        }


#class Registry:
#    __slots__ = (
#        "define_list",
#        "include_list",
#        "tag_list",
#        "blank_records",
#        "builtin_type_records",
#        "macro_records",
#        "function_macro_records",
#        "typedef_records",
#        "bitmask_records",
#        "enum_records",
#        "handle_records",
#        "struct_records",
#        "union_records",
#        "function_pointer_records",
#        "constant_records",
#        "enum_member_records",
#        "command_records",
#        "_records_tuple"
#    )

#    def __init__(
#        self: Self,
#        define_list: list[str],
#        include_list: list[str],
#        tag_list: list[str],
#        blank_records: dict[str, BlankRecord],
#        builtin_type_records: dict[str, BuiltinTypeRecord],
#        macro_records: dict[str, MacroRecord],
#        function_macro_records: dict[str, FunctionMacroRecord],
#        typedef_records: dict[str, TypedefRecord],
#        bitmask_records: dict[str, BitmaskRecord],
#        enum_records: dict[str, EnumRecord],
#        handle_records: dict[str, HandleRecord],
#        struct_records: dict[str, StructRecord],
#        union_records: dict[str, UnionRecord],
#        function_pointer_records: dict[str, FunctionPointerRecord],
#        constant_records: dict[str, ConstantRecord],
#        enum_member_records: dict[str, EnumMemberRecord],
#        command_records: dict[str, CommandRecord]
#    ) -> None:
#        super().__init__()
#        self.define_list: Final[list[str]] = define_list
#        self.include_list: Final[list[str]] = include_list
#        self.tag_list: Final[list[str]] = tag_list

#        self.blank_records: Final[dict[str, BlankRecord]] = blank_records
#        self.builtin_type_records: Final[dict[str, BuiltinTypeRecord]] = builtin_type_records
#        self.macro_records: Final[dict[str, MacroRecord]] = macro_records
#        self.function_macro_records: Final[dict[str, FunctionMacroRecord]] = function_macro_records
#        self.typedef_records: Final[dict[str, TypedefRecord]] = typedef_records
#        self.bitmask_records: Final[dict[str, BitmaskRecord]] = bitmask_records
#        self.enum_records: Final[dict[str, EnumRecord]] = enum_records
#        self.handle_records: Final[dict[str, HandleRecord]] = handle_records
#        self.struct_records: Final[dict[str, StructRecord]] = struct_records
#        self.union_records: Final[dict[str, UnionRecord]] = union_records
#        self.function_pointer_records: Final[dict[str, FunctionPointerRecord]] = function_pointer_records
#        self.constant_records: Final[dict[str, ConstantRecord]] = constant_records
#        self.enum_member_records: Final[dict[str, EnumMemberRecord]] = enum_member_records
#        self.command_records: Final[dict[str, CommandRecord]] = command_records

#        self._records_tuple: Final[tuple] = (
#            self.builtin_type_records,
#            self.blank_records,
#            self.typedef_records,
#            self.bitmask_records,
#            self.enum_records,
#            self.handle_records,
#            self.struct_records,
#            self.union_records,
#            self.function_pointer_records,
#            self.macro_records,
#            self.function_macro_records,
#            self.constant_records,
#            self.enum_member_records,
#            self.command_records
#        )

#    def __getitem__(
#        self: Self,
#        __name: str
#    ) -> RecordUnionType:
#        for records in self._records_tuple:
#            try:
#                return records[__name]
#            except KeyError:
#                continue
#        raise KeyError(__name)

#    def get[DefaultT](
#        self: Self,
#        __name: str,
#        __default: DefaultT
#    ) -> RecordUnionType | DefaultT:
#        for records in self._records_tuple:
#            try:
#                return records[__name]
#            except KeyError:
#                continue
#        return __default


type RecordUnionType = Union[
    BlankRecord,
    BuiltinTypeRecord,
    TypedefRecord,
    BitmaskRecord,
    EnumRecord,
    HandleRecord,
    StructRecord,
    UnionRecord,
    FunctionPointerRecord,
    MacroRecord,
    FunctionMacroRecord,
    ConstantRecord,
    EnumMemberRecord,
    CommandRecord
]


class Registry(Mapping[str, RecordUnionType]):
    __slots__ = (
        "version_major",
        "version_minor",
        "version_patch",
        "define_list",
        "include_list",
        "tag_list",
        "blank_records",
        "builtin_type_records",
        "macro_records",
        "function_macro_records",
        "typedef_records",
        "bitmask_records",
        "enum_records",
        "handle_records",
        "struct_records",
        "union_records",
        "function_pointer_records",
        "constant_records",
        "enum_member_records",
        "command_records",
        "_records_tuple"
    )

    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self.version_major: int = 0
        self.version_minor: int = 0
        self.version_patch: int = 0

        self.define_list: Final[list[str]] = []
        self.include_list: Final[list[str]] = []
        self.tag_list: Final[list[str]] = []

        self.blank_records: Final = RecordCollection(BlankRecord)
        self.builtin_type_records: Final = RecordCollection(BuiltinTypeRecord)
        self.typedef_records: Final = RecordCollection(TypedefRecord)
        self.bitmask_records: Final = RecordCollection(BitmaskRecord)
        self.enum_records: Final = RecordCollection(EnumRecord)
        self.handle_records: Final = RecordCollection(HandleRecord)
        self.struct_records: Final = RecordCollection(StructRecord)
        self.union_records: Final = RecordCollection(UnionRecord)
        self.function_pointer_records: Final = RecordCollection(FunctionPointerRecord)
        self.macro_records: Final = RecordCollection(MacroRecord)
        self.function_macro_records: Final = RecordCollection(FunctionMacroRecord)
        self.constant_records: Final = RecordCollection(ConstantRecord)
        self.enum_member_records: Final = RecordCollection(EnumMemberRecord)
        self.command_records: Final = RecordCollection(CommandRecord)

        self._records_tuple: Final[tuple] = (
            self.builtin_type_records,
            self.blank_records,
            self.typedef_records,
            self.bitmask_records,
            self.enum_records,
            self.handle_records,
            self.struct_records,
            self.union_records,
            self.function_pointer_records,
            self.macro_records,
            self.function_macro_records,
            self.constant_records,
            self.enum_member_records,
            self.command_records
        )

    def __len__(
        self: Self
    ) -> int:
        return sum(map(len, self._records_tuple))

    def __iter__(
        self: Self
    ) -> Iterator[str]:
        for records in self._records_tuple:
            yield from records

    def __getitem__(
        self: Self,
        __name: str
    ) -> RecordUnionType:
        for records in self._records_tuple:
            try:
                return records[__name]
            except KeyError:
                continue
        raise KeyError(__name)

    #def get[DefaultT](
    #    self: Self,
    #    __name: str,
    #    __default: DefaultT
    #) -> RecordUnionType | DefaultT:
    #    for records in self._records_tuple:
    #        try:
    #            return records[__name]
    #        except KeyError:
    #            continue
    #    return __default

    def get_requirement(
        self: Self,
        __name: str
    ) -> Requirement:
        for records in self._records_tuple:
            try:
                return records.get_requirement(__name)
            except KeyError:
                continue
        raise KeyError(__name)

    def finalize(
        self: Self
    ) -> None:
        self.blank_records.finalize()
        self.builtin_type_records.finalize()
        self.macro_records.finalize()
        self.function_macro_records.finalize()
        self.typedef_records.finalize()
        self.bitmask_records.finalize()
        self.enum_records.finalize()
        self.handle_records.finalize()
        self.struct_records.finalize()
        self.union_records.finalize()
        self.function_pointer_records.finalize()
        self.constant_records.finalize()
        self.enum_member_records.finalize(
            filter=lambda enum_member:
                self.enum_records.get_requirement(enum_member.enum_name).check_requirement()
        )
        self.command_records.finalize(
            filter=lambda command:
                command.handle_name is None or self.handle_records.get_requirement(command.handle_name).check_requirement()
        )
        CType.resolve_array_sizes({
            name: value
            for name, constant in self.constant_records.items()
            if (value := constant.attr_value).isdecimal()
        })


class Program:
    __slots__ = ()

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
    ) -> bool:
        api = xml.get("api")
        return api is None or target_api in api.split(",")

    @classmethod
    def _check_supported(
        cls: type[Self],
        xml: etree.Element,
        target_api: str
    ) -> bool:
        supported = xml.get("supported")
        return supported is None or supported != "disabled" and target_api in supported.split(",")

    @classmethod
    def _check_platform(
        cls: type[Self],
        xml: etree.Element,
        target_platforms: list[str] | None
    ) -> bool:
        platform = xml.get("platform")
        return platform is None or target_platforms is None or platform in target_platforms

    @classmethod
    def _read_type_xml(
        cls: type[Self],
        registry: Registry,
        type_xml: etree.Element,
    ) -> None:
        name = type_xml.get("name", type_xml.findtext("name", ""))
        category = type_xml.get("category", "externtype")
        if registry.get(name, None) is not None:
            assert category in ("include", "externtype")
            return

        match category:
            case "include":
                registry.blank_records.new(
                    name=name
                )

            case "basetype":
                registry.typedef_records.new(
                    name=name,
                    c_type=CType(BASE_TYPE_DICT[name])
                )

            case "externtype":
                registry.typedef_records.new(
                    name=name,
                    c_type=CType(PLATFORM_TYPE_DICT.get(name, "void"))
                )
                registry.typedef_records.get_requirement(name).mark_required()

            case "bitmask":
                if (alias := type_xml.get("alias")) is not None:
                    registry.bitmask_records.new_alias(name, alias)
                    return
                registry.bitmask_records.new(
                    name=name,
                    attr_type=type_xml.findtext("type", ""),
                    attr_requires=type_xml.get("requires")
                )

            case "enum":
                if (alias := type_xml.get("alias")) is not None:
                    registry.enum_records.new_alias(name, alias)
                    return
                registry.enum_records.new(
                    name=name,
                    attr_type="enum",  # Fill later
                    attr_bitwidth=None  # Fill later
                )

            case "handle":
                if (alias := type_xml.get("alias")) is not None:
                    registry.handle_records.new_alias(name, alias)
                    return
                registry.handle_records.new(
                    name=name,
                    attr_parent=type_xml.get("parent")
                )

            case "struct":
                if (alias := type_xml.get("alias")) is not None:
                    registry.struct_records.new_alias(name, alias)
                    return
                registry.struct_records.new(
                    name=name,
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
                            (member_xml, cls._join_xml_text(member_xml, ignored_tags=["comment", "name"]).partition(":"))
                            for member_xml in type_xml.iterfind("member")
                        )
                    },
                    attr_structextends=type_xml.get("structextends"),
                    attr_allowduplicate=type_xml.get("allowduplicate")
                )

            case "union":
                if (alias := type_xml.get("alias")) is not None:
                    registry.union_records.new_alias(name, alias)
                    return
                registry.union_records.new(
                    name=name,
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
                            (member_xml, cls._join_xml_text(member_xml, ignored_tags=["comment", "name"]).partition(":"))
                            for member_xml in type_xml.iterfind("member")
                        )
                    }
                )

            case "funcpointer":
                assert (match := re.fullmatch(
                    fr"typedef (.*?) \(VKAPI_PTR \*{name}\)\((.*)\);",
                    cls._join_xml_text(type_xml).replace("\n", "")
                )) is not None
                registry.function_pointer_records.new(
                    name=name,
                    return_c_type=CType(match.group(1)),
                    argument_c_types={
                        argument_name: CType(c_type_str)
                        for c_type_str, _, argument_name in (
                            argument_declaration.rpartition(" ")
                            for argument_declaration in arguments_str.split(",")
                        )
                    } if (arguments_str := match.group(2)) != "void" else {}
                )

            case "define":
                # Tricky judgement on deciding whether to export this macro...
                if len(define_contents := tuple(
                    match.group(1)
                    for line in cls._join_xml_text(type_xml).replace("\\\n", "").splitlines()
                    if (match := re.fullmatch(fr"#define {name}\b(.*)", line.lstrip())) is not None
                )) != 1 or "##" in (define_content := define_contents[0]):
                    registry.blank_records.new(
                        name=name
                    )
                    return
                if (arguments_match := re.match(r"\((.*?)\)", define_content)) is not None:
                    registry.function_macro_records.new(
                        name=name,
                        return_c_type=CType("const uint32_t"),
                        argument_c_types={
                            argument_name: CType("const uint32_t")
                            for argument_name in arguments_match.group(1).split(", ")
                        }
                    )
                else:
                    if name == "VK_HEADER_VERSION":
                        assert (match := re.fullmatch(
                            r" (\d+)",
                            define_content
                        )) is not None
                        registry.version_patch = int(match.group(1))
                    elif name == "VK_HEADER_VERSION_COMPLETE":
                        assert (match := re.fullmatch(
                            r" VK_MAKE_API_VERSION\(\w+, (\d+), (\d+), VK_HEADER_VERSION\)",
                            define_content
                        )) is not None
                        registry.version_major = int(match.group(1))
                        registry.version_minor = int(match.group(2))
                    registry.macro_records.new(
                        name=name,
                        c_type=CType("const uint32_t")
                    )

            case _:
                assert False

    @classmethod
    def _read_enum_xml(
        cls: type[Self],
        registry: Registry,
        enum_xml: etree.Element,
        enum_name: str | None
    ) -> None:
        name = enum_xml.get("name", "")
        if registry.get(name, None) is not None:
            return

        if enum_name is None:
            if (alias := enum_xml.get("alias")) is not None:
                registry.constant_records.new_alias(name, alias)
                return
            attr_value = enum_xml.get("value", "")
            if (c_type_str := enum_xml.get("type")) is not None:
                c_type = CType(f"const {c_type_str}")
            elif attr_value.isidentifier():
                c_type = CType("const uint32_t")
            elif re.fullmatch(r"\d+|0x[\dA-F]+", attr_value):
                c_type = CType("const uint32_t")
            elif re.fullmatch(r"\"\w+\"", attr_value) is not None:
                c_type = CType("const char[]")
            else:
                assert False
            registry.constant_records.new(
                name=name,
                c_type=c_type,
                attr_value=attr_value
            )
        else:
            if (alias := enum_xml.get("alias")) is not None:
                registry.enum_member_records.new_alias(name, alias)
                return
            if (protect := enum_xml.get("protect")) is not None and protect not in registry.define_list:
                return
            registry.enum_member_records.new(
                name=name,
                enum_name=enum_name
            )

    @classmethod
    def _read_command_xml(
        cls: type[Self],
        registry: Registry,
        command_xml: etree.Element
    ) -> None:
        name = command_xml.get("name", command_xml.findtext("proto/name", ""))
        if (alias := command_xml.get("alias")) is not None:
            registry.command_records.new_alias(name, alias)
            return

        assert (proto_xml := command_xml.find("proto")) is not None
        handle_name = (
            first_param_type_str
            if (first_param_xml := command_xml.find("param")) is not None
            and (first_param_type_str := first_param_xml.findtext("type")) is not None
            and registry.handle_records.get(first_param_type_str, None) is not None
            else None
        )
        registry.command_records.new(
            name=name,
            handle_name=handle_name,
            return_c_type=CType(cls._join_xml_text(proto_xml, ignored_tags=["comment", "name"])),
            arguments={
                param_xml.findtext("name", ""): Argument(
                    c_type=CType(cls._join_xml_text(param_xml, ignored_tags=["comment", "name"])),
                    attr_len=param_xml.get("len"),
                    attr_altlen=param_xml.get("altlen"),
                    attr_optional=param_xml.get("optional"),
                    attr_selector=param_xml.get("selector"),
                )
                for param_xml in command_xml.iterfind("param")
            },
            attr_type=None
        )

    @classmethod
    def _read_registry_xml(
        cls: type[Self],
        registry: Registry,
        registry_xml: etree.Element,
        api: str,
        platforms: list[str] | None
    ) -> None:
        for xml in registry_xml:
            match xml.tag:
                case "platforms":
                    for platform_xml in xml.iterfind("platform"):
                        if platforms is None or platform_xml.get("name", "") in platforms:
                            registry.define_list.append(platform_xml.get("protect", ""))

                case "tags":
                    for tag_xml in xml.iterfind("tag"):
                        registry.tag_list.append(tag_xml.get("name", ""))

                case "types":
                    for type_xml in xml.iterfind("type"):
                        if not cls._check_api(type_xml, api):
                            continue
                        cls._read_type_xml(registry, type_xml)

                case "enums":
                    if (enum_name := xml.get("name", "")) == "API Constants":
                        enum_name = None
                    else:
                        enum = registry.enum_records[enum_name]
                        enum.attr_type = xml.get("type", "enum")
                        enum.attr_bitwidth = xml.get("bitwidth")
                    for enum_xml in xml.iterfind("enum"):
                        cls._read_enum_xml(
                            registry=registry,
                            enum_xml=enum_xml,
                            enum_name=enum_name
                        )
                        if enum_name is not None:
                            name = enum_xml.get("name", "")
                            registry.enum_member_records.get_requirement(name).mark_required()

                case "commands":
                    for command_xml in xml.iterfind("command"):
                        if not cls._check_api(command_xml, api):
                            continue
                        cls._read_command_xml(
                            registry=registry,
                            command_xml=command_xml
                        )

                case "feature":
                    if not cls._check_api(xml, api):
                        continue
                    for requirement_batch_xml in xml:
                        if requirement_batch_xml.tag not in ("require", "remove"):
                            continue
                        remove = requirement_batch_xml.tag == "remove"
                        for requirement_unit_xml in requirement_batch_xml:
                            if requirement_unit_xml.tag not in ("type", "enum", "command"):
                                continue
                            if not cls._check_api(requirement_unit_xml, api):
                                continue
                            name = requirement_unit_xml.get("name", "")
                            if remove:
                                registry.get_requirement(name).mark_removed()
                                continue
                            if requirement_unit_xml.tag == "enum":
                                cls._read_enum_xml(
                                    registry=registry,
                                    enum_xml=requirement_unit_xml,
                                    enum_name=requirement_unit_xml.get("extends")
                                )
                            registry.get_requirement(name).mark_required()

                case "extensions":
                    for extension_xml in xml.iterfind("extension"):
                        if not cls._check_api(extension_xml, api) \
                                or not cls._check_supported(extension_xml, api) \
                                or not cls._check_platform(extension_xml, platforms):
                            continue
                        extension_type = extension_xml.get("type")
                        for requirement_batch_xml in extension_xml:
                            if requirement_batch_xml.tag not in ("require", "remove"):
                                continue
                            if not cls._check_api(requirement_batch_xml, api):
                                continue
                            remove = requirement_batch_xml.tag == "remove"
                            for requirement_unit_xml in requirement_batch_xml:
                                if requirement_unit_xml.tag not in ("type", "enum", "command"):
                                    continue
                                if not cls._check_api(requirement_unit_xml, api):
                                    continue
                                name = requirement_unit_xml.get("name", "")
                                if remove:
                                    registry.get_requirement(name).mark_removed()
                                    continue
                                if requirement_unit_xml.tag == "enum":
                                    cls._read_enum_xml(
                                        registry=registry,
                                        enum_xml=requirement_unit_xml,
                                        enum_name=requirement_unit_xml.get("extends")
                                    )
                                if requirement_unit_xml.tag == "command":
                                    registry.command_records[name].attr_type = extension_type
                                registry.get_requirement(name).mark_required()

    @classmethod
    def read(
        cls: type[Self],
        registry: Registry,
        registry_xml_paths: list[pathlib.Path],
        api: str,
        platform: str
    ) -> None:
        if platform == "all":
            platforms = None
        else:
            platforms = [platform]
            if platform != "provisional":
                platforms.append("provisional")

        for name, py_type_str in BUILTIN_TYPE_DICT.items():
            registry.builtin_type_records.new(
                name=name,
                c_type=CType(name),
                py_type_str=py_type_str
            )
        for registry_xml_path in registry_xml_paths:
            registry.include_list.extend(REGISTRY_SRC_DICT[registry_xml_path.name])
            cls._read_registry_xml(
                registry=registry,
                registry_xml=etree.parse(registry_xml_path).getroot(),
                api=api,
                platforms=platforms
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
                            c_type = ffi.typeof("char[]")
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

    @classmethod
    def _iter_cdef_strs(
        cls: type[Self],
        registry: Registry
    ) -> Iterator[str]:
        for name, typedef in registry.typedef_records.items():
            yield f"""typedef {typedef.c_type.format()} {name};"""

        for name, bitmask in registry.bitmask_records.items():
            yield f"""typedef {bitmask.attr_type} {name};"""

        for name, enum in registry.enum_records.items():
            yield f"""typedef {f"VkFlags64" if enum.attr_bitwidth == "64" else f"enum {name} {{ ... }}"} {name};"""

        for name, _ in registry.handle_records.items():
            yield f"""typedef struct {name}_T *{name};"""

        for name, _ in registry.struct_records.items():
            yield f"""typedef struct {name} {name};"""

        for name, _ in registry.union_records.items():
            yield f"""typedef union {name} {name};"""

        for name, function_pointer in registry.function_pointer_records.items():
            yield f"""typedef {function_pointer.return_c_type.format()} (* {name})(\n{",\n".join(
                f"    {argument_c_type.format(argument_name)}"
                for argument_name, argument_c_type in function_pointer.argument_c_types.items()
            ) if function_pointer.argument_c_types else "    void"}\n);"""

        for name, macro in registry.macro_records.items():
            yield f"""static {macro.c_type.format(name)};"""

        for name, function_macro in registry.function_macro_records.items():
            yield f"""static {function_macro.return_c_type.format()} {name}(\n{",\n".join(
                f"    {argument_c_type.format(argument_name)}"
                for argument_name, argument_c_type in function_macro.argument_c_types.items()
            ) if function_macro.argument_c_types else "    void"}\n);"""

        for name, constant in registry.constant_records.items():
            yield f"""static {constant.c_type.format(name)};"""

        for name, enum_member in registry.enum_member_records.items():
            yield f"""static const {enum_member.enum_name} {name};"""

        for name, command in registry.command_records.items():
            if command.attr_type is not None:
                continue
            yield f"""static {command.return_c_type.format()} {name}(\n{",\n".join(
                f"    {argument.c_type.format(argument_name)}"
                for argument_name, argument in command.arguments.items()
            ) if command.arguments else "    void"}\n);"""

        for name, struct in registry.struct_records.items():
            yield f"""struct {name} {{\n{"\n".join(
                f"    {field.c_type.format(field_name)}{f":{field.bitwidth}" if field.bitwidth is not None else ""};"
                for field_name, field in struct.fields.items()
            )}\n}};"""

        for name, union in registry.union_records.items():
            yield f"""union {name} {{\n{"\n".join(
                f"    {field.c_type.format(field_name)}{f":{field.bitwidth}" if field.bitwidth is not None else ""};"
                for field_name, field in union.fields.items()
            )}\n}};"""

    @classmethod
    def _iter_csrc_strs(
        cls: type[Self],
        registry: Registry
    ) -> Iterator[str]:
        for define in registry.define_list:
            yield f"#define {define}"

        for include in registry.include_list:
            yield f"#include <{include}>"

    @classmethod
    def _iter_pydef_strs(
        cls: type[Self],
        registry: Registry
    ) -> Iterator[str]:
        yield from ()
        #for name, macro in registry.macro_records.items():
        #    yield f"""{name}: {BUILTIN_TYPE_DICT[macro.c_type._base_type_str]} = lib.{name}"""

        #for name, function_macro in registry.function_macro_records.items():
        #    yield f"""def {name}(\n{",\n".join(
        #        f"    {argument_c_type.format(argument_name)}"
        #        for argument_name, argument_c_type in function_macro.argument_c_types.items()
        #    ) if function_macro.argument_c_types else "    void"}\n);"""
        #f"""
        #                        {name}: int = lib.{name}
        #                    """
        #                return f"""
        #                    def {name}({", ".join(f"{arg}: int" for arg in args)}) -> int:
        #                        return lib.{name}({", ".join(args)})
        #                """

    @classmethod
    def write_cdef(
        cls: type[Self],
        registry: Registry,
        cdef_path: pathlib.Path
    ) -> None:
        with cdef_path.open("w") as cdef_file:
            cdef_file.write("// Auto-generated C definitions\n")
            for cdef_str in cls._iter_cdef_strs(registry):
                cdef_file.write(f"\n{cdef_str}\n")

    @classmethod
    def write_csrc(
        cls: type[Self],
        registry: Registry,
        csrc_path: pathlib.Path
    ) -> None:
        with csrc_path.open("w") as csrc_file:
            for csrc_str in cls._iter_csrc_strs(registry):
                csrc_file.write(f"{csrc_str}\n")

    @classmethod
    def write_pydef(
        cls: type[Self],
        registry: Registry,
        pydef_path: pathlib.Path
    ) -> None:
        with pydef_path.open("w") as pydef_file:
            pydef_file.write(f"""
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

from _vulkan_ffi import (
    ffi,
    lib
)
            """.strip())
            pydef_file.write("\n\n")
            for pydef_str in cls._iter_pydef_strs(registry):
                pydef_file.write(f"\n{pydef_str}\n")

        #if write_ffi:
        #    ffi = cffi.FFI()
        #    ffi.cdef(csource=cdef_path.read_text())
        #    ffi.set_source(
        #        module_name=str(ffi_path.with_suffix("")).replace("\\", "."),
        #        source="".join((
        #            *(f"#define {define}\n" for define in registry.define_list),
        #            *(f"#include <{include}>\n" for include in registry.include_list)
        #        )),
        #        include_dirs=["extern/vulkan/Include"],
        #        library_dirs=["extern/vulkan/Lib"],
        #        libraries=["vulkan-1"]
        #    )
        #    ffi.compile()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--api", default="vulkan")
    parser.add_argument("--platform", default="all")
    parser.add_argument("--targets", default="cdef,csrc,pydef")
    arg_namespace = parser.parse_args()

    api = arg_namespace.api
    platform = arg_namespace.platform
    registry = Registry()
    Program.read(
        registry=registry,
        registry_xml_paths=[
            pathlib.Path("extern/xml/video.xml"),
            pathlib.Path("extern/xml/vk.xml")
        ],
        api=api,
        platform=platform
    )
    registry.finalize()

    subdir_name = "_".join((
        api,
        platform,
        str(registry.version_major),
        str(registry.version_minor),
        str(registry.version_patch)
    ))
    generated_dir = pathlib.Path("generated")
    generated_dir.mkdir(exist_ok=True)
    generated_subdir = generated_dir.joinpath(subdir_name)
    generated_subdir.mkdir(exist_ok=True)
    targets = list(map(str.strip, arg_namespace.targets.split(",")))
    if "cdef" in targets:
        Program.write_cdef(
            registry=registry,
            cdef_path=generated_subdir.joinpath(f"_vulkan_cdef.h")
        )
    if "csrc" in targets:
        Program.write_csrc(
            registry=registry,
            csrc_path=generated_subdir.joinpath(f"_vulkan_csrc.h")
        )
    if "pydef" in targets:
        Program.write_pydef(
            registry=registry,
            pydef_path=generated_subdir.joinpath(f"_pyvulkan.py")
        )
