from __future__ import annotations

import argparse
import itertools
import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    Iterator,
    Self
)

import attrs


BUILTIN_TYPE_DICT = {
    "void": None,  # buffer protocol, absorbing a pointer
    "char": None,  # str, absorbing a pointer
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
    "NvSciBufObj": "void"
}


class CType:
    __slots__ = (
        "_base_type_str",
        "_const_specifier",
        "_pointer_const_specifiers",
        "_array_sizes"
    )

    #_unresolved_c_types: ClassVar[list[CType]] = []

    def __init__(
        self: Self,
        c_type_str: str,
        constant_decimal_literal_dict: dict[str, str] | None = None
    ) -> None:
        super().__init__()
        base_type_str, const_specifier, pointer_const_specifiers, array_sizes = type(self)._parse_c_type_str(
            c_type_str, constant_decimal_literal_dict
        )
        self._base_type_str: str = base_type_str
        self._const_specifier: bool = const_specifier
        self._pointer_const_specifiers: tuple[bool, ...] = pointer_const_specifiers
        self._array_sizes: tuple[str, ...] = array_sizes
        #if any(
        #    array_size_str.isidentifier()
        #    for array_size_str in array_size_strs
        #):
        #    cls = type(self)
        #    cls._unresolved_c_types.append(self)

    @classmethod
    def _parse_c_type_str(
        cls: type[Self],
        c_type_str: str,
        constant_decimal_literal_dict: dict[str, str] | None
    ) -> tuple[str, bool, tuple[bool, ...], tuple[str, ...]]:
        base_type_strs: list[str] = []
        const_specifier: bool = False
        pointer_const_specifiers: list[bool] = []
        array_sizes: list[str] = []

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
                array_size = ""
            else:
                array_size = next_token
                if not array_size.isdecimal():
                    assert constant_decimal_literal_dict is not None
                    array_size = constant_decimal_literal_dict[array_size]
                assert next(tokens) == "]"
            array_sizes.append(array_size)
            next_token = next(tokens, "")
        assert not next_token
        return " ".join(base_type_strs), const_specifier, tuple(pointer_const_specifiers), tuple(array_sizes)

    #@classmethod
    #def resolve_array_sizes(
    #    cls: type[Self],
    #    array_size_values: dict[str, str]
    #) -> None:
    #    while cls._unresolved_c_types:
    #        c_type = cls._unresolved_c_types.pop()
    #        c_type._array_size_strs = tuple(
    #            array_size_values[array_size_str] if array_size_str.isidentifier() else array_size_str
    #            for array_size_str in c_type._array_size_strs
    #        )

    def format(
        self: Self,
        name: str | None = None
    ) -> str:
        return f"""{"const " if self._const_specifier else ""}{self._base_type_str}{"".join(
            f" *{f" const" if pointer_const_specifier else ""}"
            for pointer_const_specifier in self._pointer_const_specifiers
        )}{f" {name}" if name is not None else ""}{"".join(
            f"[{array_size}]"
            for array_size in self._array_sizes
        )}"""


@attrs.frozen(kw_only=True)
class Argument:
    name: str
    c_type: CType


@attrs.frozen(kw_only=True)
class CommandArgument(Argument):
    len_attr: str | None
    altlen_attr: str | None
    optional_attr: str | None
    selector_attr: str | None


@attrs.frozen(kw_only=True)
class Field(Argument):
    bitwidth: int | None
    len_attr: str | None
    altlen_attr: str | None
    optional_attr: str | None
    selector_attr: str | None
    selection_attr: str | None
    values_attr: str | None


@attrs.frozen(kw_only=True)
class Record:
    name: str


#@attrs.frozen(kw_only=True)
#class BlankRecord(Record):
#    pass


@attrs.frozen(kw_only=True)
class BuiltinTypeRecord(Record):
    pass
    #c_type: CType
    #py_type_str: str  # TODO


@attrs.frozen(kw_only=True)
class TypedefRecord(Record):
    c_type_str: str


@attrs.frozen(kw_only=True)
class BitmaskRecord(Record):
    type_attr: str
    requires_attr: str | None


@attrs.frozen(kw_only=True)
class EnumRecord(Record):
    #intrinsic_member_name_list: list[str]
    type_attr: str  # "enum" | "bitmask"
    bitwidth_attr: str | None


@attrs.frozen(kw_only=True)
class HandleRecord(Record):
    parent_attr: str | None


@attrs.frozen(kw_only=True)
class StructRecord(Record):
    field_list: list[Field]
    structextends_attr: str | None
    allowduplicate_attr: str | None


@attrs.frozen(kw_only=True)
class UnionRecord(Record):
    field_list: list[Field]


@attrs.frozen(kw_only=True)
class FunctionPointerRecord(Record):
    return_c_type: CType
    argument_list: list[Argument]


@attrs.frozen(kw_only=True)
class MacroRecord(Record):
    c_type: CType


@attrs.frozen(kw_only=True)
class FunctionMacroRecord(Record):
    return_c_type: CType
    argument_list: list[Argument]


@attrs.frozen(kw_only=True)
class ConstantRecord(Record):
    c_type: CType
    value_attr: str


@attrs.frozen(kw_only=True)
class EnumMemberRecord(Record):
    enum_name: str


@attrs.frozen(kw_only=True)
class CommandRecord(Record):
    #handle_name: str | None
    return_c_type: CType
    command_argument_list: list[CommandArgument]
    type_attr: str | None  # "instance" | "device" | None


#class Requirement:
#    __slots__ = (
#        "_required",
#        "_removed"
#    )

#    def __init__(
#        self: Self
#    ) -> None:
#        super().__init__()
#        self._required: bool = False
#        self._removed: bool = False

#    def mark_required(
#        self: Self
#    ) -> None:
#        self._required = True

#    def mark_removed(
#        self: Self
#    ) -> None:
#        self._removed = True

#    def check_requirement(
#        self: Self
#    ) -> bool:
#        return self._required and not self._removed


#class RecordCollection[T: Record, **P](Mapping[str, T]):
#    __slots__ = (
#        "_record_constructor",
#        "_record_dict",
#        "_alias_forwardref_dict",
#        "_requirement_dict"
#    )

#    def __init__(
#        self: Self,
#        record_constructor: Callable[P, T]
#    ) -> None:
#        super().__init__()
#        self._record_constructor: Callable[P, T] = record_constructor
#        self._record_dict: dict[str, T] = {}
#        self._alias_forwardref_dict: dict[str, list[str]] = {}
#        self._requirement_dict: dict[str, Requirement] = {}

#    def __len__(
#        self: Self
#    ) -> int:
#        return len(self._record_dict)

#    def __iter__(
#        self: Self
#    ) -> Iterator[str]:
#        yield from self._record_dict

#    def __getitem__(
#        self: Self,
#        __name: str
#    ) -> T:
#        return self._record_dict[__name]

#    def new(
#        self: Self,
#        name: str,
#        *args: P.args,
#        **kwargs: P.kwargs
#    ) -> None:
#        assert name not in self._requirement_dict
#        self._requirement_dict[name] = Requirement()
#        self._record_dict[name] = self._record_constructor(*args, **kwargs)

#        resolvable_aliases = [name]
#        while resolvable_aliases:
#            alias = resolvable_aliases.pop(0)
#            for name in self._alias_forwardref_dict.pop(alias, []):
#                self._record_dict[name] = self._record_dict[alias]
#                resolvable_aliases.append(name)

#    def new_alias(
#        self: Self,
#        name: str,
#        alias: str
#    ) -> None:
#        assert name not in self._requirement_dict
#        self._requirement_dict[name] = Requirement()
#        if alias in self._record_dict:
#            self._record_dict[name] = self._record_dict[alias]
#        else:
#            self._alias_forwardref_dict.setdefault(alias, []).append(name)

#    #def get[DefaultT](
#    #    self: Self,
#    #    __name: str,
#    #    __default: DefaultT
#    #) -> T | DefaultT:
#    #    try:
#    #        return self[__name]
#    #    except KeyError:
#    #        return __default

#    def get_requirement(
#        self: Self,
#        __name: str
#    ) -> Requirement:
#        try:
#            return self._requirement_dict[__name]
#        except KeyError:
#            raise KeyError(__name) from None

#    def finalize(
#        self: Self,
#        filter: Callable[[T], bool] | None = None
#    ) -> None:
#        assert not self._alias_forwardref_dict
#        self._record_dict = {
#            name: record
#            for name, record in self._record_dict.items()
#            if self._requirement_dict[name].check_requirement()
#            and (filter is None or filter(record))
#        }


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


@attrs.frozen(kw_only=True)
class Registry:
    version: tuple[int, int, int]
    defines: list[str]
    tags: list[str]
    #blank_records: list[BlankRecord]
    builtin_type_records: list[BuiltinTypeRecord]
    typedef_records: list[TypedefRecord]
    bitmask_records: list[BitmaskRecord]
    enum_records: list[EnumRecord]
    handle_records: list[HandleRecord]
    struct_records: list[StructRecord]
    union_records: list[UnionRecord]
    function_pointer_records: list[FunctionPointerRecord]
    macro_records: list[MacroRecord]
    function_macro_records: list[FunctionMacroRecord]
    constant_records: list[ConstantRecord]
    enum_member_records: list[EnumMemberRecord]
    command_records: list[CommandRecord]


#type RecordUnionType = Union[
#    BlankRecord,
#    BuiltinTypeRecord,
#    TypedefRecord,
#    BitmaskRecord,
#    EnumRecord,
#    HandleRecord,
#    StructRecord,
#    UnionRecord,
#    FunctionPointerRecord,
#    MacroRecord,
#    FunctionMacroRecord,
#    ConstantRecord,
#    EnumMemberRecord,
#    CommandRecord
#]


#class Registry(Mapping[str, RecordUnionType]):
#    __slots__ = (
#        "version_major",
#        "version_minor",
#        "version_patch",
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
#        self: Self
#    ) -> None:
#        super().__init__()
#        self.version_major: int = 0
#        self.version_minor: int = 0
#        self.version_patch: int = 0

#        self.define_list: Final[list[str]] = []
#        self.include_list: Final[list[str]] = []
#        self.tag_list: Final[list[str]] = []

#        self.blank_records: Final = RecordCollection(BlankRecord)
#        self.builtin_type_records: Final = RecordCollection(BuiltinTypeRecord)
#        self.typedef_records: Final = RecordCollection(TypedefRecord)
#        self.bitmask_records: Final = RecordCollection(BitmaskRecord)
#        self.enum_records: Final = RecordCollection(EnumRecord)
#        self.handle_records: Final = RecordCollection(HandleRecord)
#        self.struct_records: Final = RecordCollection(StructRecord)
#        self.union_records: Final = RecordCollection(UnionRecord)
#        self.function_pointer_records: Final = RecordCollection(FunctionPointerRecord)
#        self.macro_records: Final = RecordCollection(MacroRecord)
#        self.function_macro_records: Final = RecordCollection(FunctionMacroRecord)
#        self.constant_records: Final = RecordCollection(ConstantRecord)
#        self.enum_member_records: Final = RecordCollection(EnumMemberRecord)
#        self.command_records: Final = RecordCollection(CommandRecord)

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

#    def __len__(
#        self: Self
#    ) -> int:
#        return sum(map(len, self._records_tuple))

#    def __iter__(
#        self: Self
#    ) -> Iterator[str]:
#        for records in self._records_tuple:
#            yield from records

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

#    #def get[DefaultT](
#    #    self: Self,
#    #    __name: str,
#    #    __default: DefaultT
#    #) -> RecordUnionType | DefaultT:
#    #    for records in self._records_tuple:
#    #        try:
#    #            return records[__name]
#    #        except KeyError:
#    #            continue
#    #    return __default

#    def get_requirement(
#        self: Self,
#        __name: str
#    ) -> Requirement:
#        for records in self._records_tuple:
#            try:
#                return records.get_requirement(__name)
#            except KeyError:
#                continue
#        raise KeyError(__name)

#    def finalize(
#        self: Self
#    ) -> None:
#        self.blank_records.finalize()
#        self.builtin_type_records.finalize()
#        self.macro_records.finalize()
#        self.function_macro_records.finalize()
#        self.typedef_records.finalize()
#        self.bitmask_records.finalize()
#        self.enum_records.finalize()
#        self.handle_records.finalize()
#        self.struct_records.finalize()
#        self.union_records.finalize()
#        self.function_pointer_records.finalize()
#        self.constant_records.finalize()
#        self.enum_member_records.finalize(
#            filter=lambda enum_member:
#                self.enum_records.get_requirement(enum_member.enum_name).check_requirement()
#        )
#        self.command_records.finalize(
#            filter=lambda command:
#                command.handle_name is None or self.handle_records.get_requirement(command.handle_name).check_requirement()
#        )
#        CType.resolve_array_sizes({
#            name: value
#            for name, constant in self.constant_records.items()
#            if (value := constant.value_attr).isdecimal()
#        })


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
        api: str
    ) -> bool:
        api_attr = xml.get("api")
        return api_attr is None or api in api_attr.split(",")

    @classmethod
    def _check_supported(
        cls: type[Self],
        xml: etree.Element,
        api: str
    ) -> bool:
        supported_attr = xml.get("supported")
        return supported_attr is None or supported_attr != "disabled" and api in supported_attr.split(",")

    @classmethod
    def _check_platform(
        cls: type[Self],
        xml: etree.Element,
        platforms: list[str] | None
    ) -> bool:
        platform_attr = xml.get("platform")
        return platform_attr is None or platforms is None or platform_attr in platforms

    #@classmethod
    #def _read_enum_xml(
    #    cls: type[Self],
    #    name: str,
    #    enum_xml: etree.Element
    #    #enum_name: str | None
    #) -> Iterator[Record]:
    #    if enum_name is None:
    #        if (alias := enum_xml.get("alias")) is not None:
    #            registry.constant_records.new_alias(name, alias)
    #            return
    #        value_attr = enum_xml.get("value", "")
    #        if (c_type_str := enum_xml.get("type")) is not None:
    #            c_type = CType(f"const {c_type_str}")
    #        elif value_attr.isidentifier():
    #            c_type = CType("const uint32_t")
    #        elif re.fullmatch(r"\d+|0x[\dA-F]+", value_attr):
    #            c_type = CType("const uint32_t")
    #        elif re.fullmatch(r"\"\w+\"", value_attr) is not None:
    #            c_type = CType("const char[]")
    #        else:
    #            assert False
    #        registry.constant_records.new(
    #            name=name,
    #            c_type=c_type,
    #            value_attr=value_attr
    #        )
    #    else:
    #        if (alias := enum_xml.get("alias")) is not None:
    #            registry.enum_member_records.new_alias(name, alias)
    #            return
    #        if (protect := enum_xml.get("protect")) is not None and protect not in registry.define_list:
    #            return
    #        registry.enum_member_records.new(
    #            name=name,
    #            enum_name=enum_name
    #        )

    @classmethod
    def _read_registry_xml(
        cls: type[Self],
        registry_xml: etree.Element,
        api: str,
        platforms: list[str] | None,
        defines: list[str]
    ) -> Iterator[Record]:

        def resolve_alias(
            name: str,
            xml_dict: dict[str, etree.Element]
        ) -> etree.Element:
            while (alias := (result := xml_dict[name]).get("alias")) is not None:
                name = alias
            return result
            #for name in xml_dict:
            #    alias = name
            #    while (next_alias := xml_dict[alias].get("alias")) is not None:
            #        alias = next_alias
            #    xml_dict[name] = xml_dict[alias]
            #return xml_dict
            #xml = xml_dict[name]
            #while (alias := xml.get("alias")) is not None:
            #    name = alias
            #    xml = xml_dict[name]
            #return name, xml

        #removed_sets: dict[str, set[str]] = {tag: set() for tag in tags}
        #required_dicts: dict[str, dict[str, tuple[etree.Element, str | None]]] = {tag: {} for tag in tags}
        required_types: list[str] = []
        required_enums: list[str] = []
        required_commands: list[str] = []
        removed_types: list[str] = []
        removed_enums: list[str] = []
        removed_commands: list[str] = []
        type_xml_dict: dict[str, etree.Element] = {}
        enum_xml_dict: dict[str, etree.Element] = {}
        command_xml_dict: dict[str, etree.Element] = {}

        enums_xml_dict: dict[str, etree.Element] = {}
        enum_enums_name_dict: dict[str, str | None] = {}
        command_type_attr_dict: dict[str, str | None] = {}

        requirement_items = [
            (removed, requirement_unit_xml_tag, requirement_unit_xml.get("name", ""), requirement_unit_xml, type_attr)
            for requirement_xml, type_attr in itertools.chain((
                (feature_xml, None)
                for feature_xml in registry_xml.iterfind("feature")
                if cls._check_api(feature_xml, api)
            ), (
                (extension_xml, extension_xml.get("type"))
                for extensions_xml in registry_xml.iterfind("extensions")
                for extension_xml in extensions_xml.iterfind("extension")
                if cls._check_api(extension_xml, api)
                and cls._check_supported(extension_xml, api)
                and cls._check_platform(extension_xml, platforms)
            ))
            for requirement_batch_xml in requirement_xml
            if requirement_batch_xml.tag in ("require", "remove")
            and cls._check_api(requirement_batch_xml, api)
            and ((removed := requirement_batch_xml.tag == "remove") or True)
            for requirement_unit_xml in requirement_batch_xml
            if (requirement_unit_xml_tag := requirement_unit_xml.tag) in ("type", "enum", "command")
            and cls._check_api(requirement_unit_xml, api)
        ]
        for removed, requirement_unit_xml_tag, name, _, _ in requirement_items:
            if not removed:
                continue
            match requirement_unit_xml_tag:
                case "type":
                    removed_types.append(name)
                case "enum":
                    removed_enums.append(name)
                case "command":
                    removed_commands.append(name)
        for removed, requirement_unit_xml_tag, name, requirement_unit_xml, type_attr in requirement_items:
            if removed:
                continue
            match requirement_unit_xml_tag:
                case "type":
                    if name in removed_types:
                        continue
                    required_types.append(name)
                case "enum":
                    if name in removed_enums:
                        continue
                    required_enums.append(name)
                    enum_xml_dict[name] = requirement_unit_xml
                    enum_enums_name_dict[name] = requirement_unit_xml.get("extends")
                case "command":
                    if name in removed_commands:
                        continue
                    required_commands.append(name)
                    command_type_attr_dict[name] = type_attr

        for xml in registry_xml:
            match xml.tag:
                case "types":
                    for type_xml in xml.iterfind("type"):
                        if not cls._check_api(type_xml, api):
                            continue
                        name = type_xml.get("name", type_xml.findtext("name", ""))
                        if type_xml.get("category") is None:
                            yield TypedefRecord(
                                name=name,
                                c_type_str=PLATFORM_TYPE_DICT.get(name, "void")
                            )
                            continue
                        if name not in required_types:
                            continue
                        type_xml_dict[name] = type_xml

                case "enums":
                    enums_name = xml.get("name", "")
                    if enums_name == "API Constants":
                        enums_name = None
                    elif enums_name not in required_types:
                        continue
                    else:
                        enums_xml_dict[enums_name] = xml
                    for enum_xml in xml.iterfind("enum"):
                        if not cls._check_api(enum_xml, api):
                            continue
                        name = enum_xml.get("name", "")
                        if enums_name is not None:
                            required_enums.append(name)
                        enum_xml_dict[name] = enum_xml
                        enum_enums_name_dict[name] = enums_name

                case "commands":
                    for command_xml in xml.iterfind("command"):
                        if not cls._check_api(command_xml, api):
                            continue
                        name = command_xml.get("name", command_xml.findtext("proto/name", ""))
                        if name not in required_commands:
                            continue
                        command_xml_dict[name] = command_xml

        #enums_xml_item_dict = {
        #    enums_name: (enums_xml, {
        #        enum_xml.get("name", ""): enum_xml
        #        for enum_xml in enums_xml.iterfind("enum")
        #        if cls._check_api(enum_xml, api)
        #    })
        #    for enums_xml in registry_xml.iterfind("enums")
        #    if (enums_name := enums_xml.get("name", "")) in required_dicts["type"] or enums_name == "API Constants"
        #}
        #xml_dicts = {
        #    "type": {
        #        name: type_xml
        #        for type_xml in registry_xml.iterfind("types/type")
        #        if cls._check_api(type_xml, api)
        #        and (name := type_xml.get("name", type_xml.findtext("name", ""))) in required_dicts["type"]
        #    },
        #    "enum": dict(itertools.chain(
        #        (
        #            (name, enum_xml)
        #            for name, (enum_xml, _) in required_dicts["enum"].items()
        #        ),
        #        itertools.chain.from_iterable(
        #            enums_enum_xml_dict.items()
        #            for _, enums_enum_xml_dict in enums_xml_item_dict.values()
        #        )
        #    )),
        #    "command": {
        #        name: command_xml
        #        for command_xml in registry_xml.iterfind("commands/command")
        #        if cls._check_api(command_xml, api)
        #        and (name := command_xml.get("name", command_xml.findtext("proto/name", ""))) in required_dicts["command"]
        #    }
        #}
        #enums_xml_dict = {
        #    name if name != "API Constants" else None: enums_xml
        #    for enums_xml in registry_xml.iterfind("enums")
        #    if (name := enums_xml.get("name", "")) in required_type_dict or name == "API Constants"
        #}
        #intrinsic_enum_xml_dict_dict = {
        #    enums_name: {
        #        enum_xml.get("name", ""): enum_xml
        #        for enum_xml in enums_xml.iterfind("enum")
        #        if cls._check_api(enum_xml, api)
        #    }
        #    for enums_name, enums_xml in enums_xml_dict.items()
        #}
        #enum_xml_dict = required_enum_dict.copy()
        #enum_xml_dict.update(itertools.chain.from_iterable(
        #    enum_xml_dict.items()
        #    for _, _, enum_xml_dict in enums_item_dict.values()
        #))

        #enum_xml_dict_dict = {
        #    enum_name: {
        #        name: enum_xml
        #        for name, enum_xml in enum_xml_dict.items()
        #    }
        #    for enum_name, (_, _, enum_xml_dict) in enums_item_dict.items()
        #}
        #for name, enum_xml in required_enum_dict.items():
        #    enum_xml_dict_dict.setdefault(enum_xml.get("extends", ""), {})[name] = enum_xml




        #requirement_unit_items = [
        #    (removed, requirement_unit_xml_tag, requirement_unit_xml.get("name", ""), requirement_unit_xml, type_attr)
        #    for requirement_xml, type_attr in itertools.chain((
        #        (feature_xml, None)
        #        for feature_xml in registry_xml.iterfind("feature")
        #        if cls._check_api(feature_xml, api)
        #    ), (
        #        (extension_xml, None if cls._check_ratified(extension_xml, api) else extension_xml.get("type"))
        #        for extensions_xml in registry_xml.iterfind("extensions")
        #        for extension_xml in extensions_xml.iterfind("extension")
        #        if cls._check_api(extension_xml, api)
        #        and cls._check_supported(extension_xml, api)
        #        and cls._check_platform(extension_xml, platforms)
        #    ))
        #    for requirement_batch_xml in requirement_xml
        #    if requirement_batch_xml.tag in ("require", "remove")
        #    and cls._check_api(requirement_batch_xml, api)
        #    and ((removed := requirement_batch_xml.tag == "remove") or True)
        #    for requirement_unit_xml in requirement_batch_xml
        #    if (requirement_unit_xml_tag := requirement_unit_xml.tag) in ("type", "enum", "command")
        #    and cls._check_api(requirement_unit_xml, api)
        #]
        #removed_names = {
        #    name
        #    for removed, _, name, _, _ in requirement_unit_items
        #    if removed
        #}
        #required_unit_dict = {
        #    name: (requirement_unit_xml_tag, requirement_unit_xml, type_attr)
        #    for removed, requirement_unit_xml_tag, name, requirement_unit_xml, type_attr in requirement_unit_items
        #    if not removed
        #    and name not in removed_names
        #}

        #enum_xml_dict_dict: dict[str | None, dict[str, etree.Element]] = {}
        #for enum_name, intrinsic_enum_xml_dict in intrinsic_enum_xml_dict_dict.items():
        #    enum_xml_dict_dict.setdefault(enum_name, {}).update(intrinsic_enum_xml_dict)
        #for requirement_unit_xml_tag, name, requirement_unit_xml, _ in required_unit_items:
        #    if requirement_unit_xml_tag != "enum":
        #        continue
        #    enum_xml_dict_dict.setdefault(requirement_unit_xml.get("extends"), {})[name] = requirement_unit_xml

        #list(itertools.chain((
        #    (removed, requirement_unit_xml_tag, requirement_unit_xml, None)
        #    for feature_xml in registry_xml.iterfind("feature")
        #    if cls._check_api(feature_xml, api)
        #    for requirement_batch_xml in feature_xml
        #    if requirement_batch_xml.tag in ("require", "remove")
        #    and ((removed := requirement_batch_xml.tag == "remove") or True)
        #    for requirement_unit_xml in requirement_batch_xml
        #    if (requirement_unit_xml_tag := requirement_unit_xml.tag) in ("type", "enum", "command")
        #    and cls._check_api(requirement_unit_xml, api)
        #), (
        #    (removed, requirement_unit_xml_tag, requirement_unit_xml, type_attr)
        #    for extension_xml in registry_xml.iterfind("extension")
        #    if cls._check_api(extension_xml, api)
        #    and cls._check_supported(extension_xml, api)
        #    and cls._check_platform(extension_xml, platforms)
        #    and ((type_attr := (None if cls._check_ratified(extension_xml, api) else extension_xml.get("type"))) or True)
        #    for requirement_batch_xml in extension_xml
        #    if requirement_batch_xml.tag in ("require", "remove")
        #    and cls._check_api(requirement_batch_xml, api)
        #    and ((removed := requirement_batch_xml.tag == "remove") or True)
        #    for requirement_unit_xml in requirement_batch_xml
        #    if (requirement_unit_xml_tag := requirement_unit_xml.tag) in ("type", "enum", "command")
        #    and cls._check_api(requirement_unit_xml, api)
        #)))

        #type_requirements = {
        #    name: type_xml_dict[name]
        #    for requirement_unit_xml_tag, name, _, _ in required_unit_items
        #    if requirement_unit_xml_tag == "type"
        #}
        #intrinsic_enum_requirements = {
        #    enum_name: {
        #        enum_xml.get("name", ""): enum_xml
        #        for enum_xml in enums_xml.iterfind("enum")
        #        if cls._check_api(enum_xml, api)
        #    }
        #    for enum_name, type_xml in type_requirements.items()
        #    if type_xml.get("category") == "enum"
        #    if (enums_xml := enums_xml_dict.get(enum_name)) is not None
        #}
        #extrinsic_enum_requirements = {
        #    name: enum_requirement_unit_xml
        #    for requirement_unit_xml_tag, name, enum_requirement_unit_xml, _ in required_unit_items
        #    if requirement_unit_xml_tag == "enum"
        #}
        #command_requirements = {
        #    name: command_xml_dict[name]
        #    for requirement_unit_xml_tag, name, _, _ in required_unit_items
        #    if requirement_unit_xml_tag == "command"
        #}

        constant_decimal_literal_dict: dict[str, str] = {}

        for name in required_enums:
            enum_xml = resolve_alias(name, enum_xml_dict)
            if (enums_name := enum_enums_name_dict.get(name)) is None:
                value_attr = enum_xml.get("value", "")
                if value_attr.isdecimal():
                    constant_decimal_literal_dict[name] = value_attr
                if (c_type_str := enum_xml.get("type")) is not None:
                    c_type = CType(f"const {c_type_str}")
                elif value_attr.isidentifier():
                    c_type = CType("const uint32_t")
                elif re.fullmatch(r"\d+|0x[\dA-F]+", value_attr):
                    c_type = CType("const uint32_t")
                elif re.fullmatch(r"\"\w+\"", value_attr) is not None:
                    c_type = CType("const char[]")
                else:
                    assert False
                yield ConstantRecord(
                    name=name,
                    c_type=c_type,
                    value_attr=value_attr
                )

            else:
                if (protect := enum_xml.get("protect")) is not None and protect not in defines:
                    continue
                yield EnumMemberRecord(
                    name=name,
                    enum_name=enums_name
                )

        for name in required_types:
            type_xml = resolve_alias(name, type_xml_dict)
            match type_xml.get("category"):
                case None:
                    continue
                    #registry.typedef_records.new(
                    #    name=name,
                    #    c_type=CType(PLATFORM_TYPE_DICT.get(name, "void"))
                    #)
                    #registry.typedef_records.get_requirement(name).mark_required()

                case "include":
                    continue
                    #registry.blank_records.new(
                    #    name=name
                    #)

                case "basetype":
                    yield TypedefRecord(
                        name=name,
                        c_type_str=BASE_TYPE_DICT[name]
                    )

                case "bitmask":
                    yield BitmaskRecord(
                        name=name,
                        type_attr=type_xml.findtext("type", ""),
                        requires_attr=type_xml.get("requires")
                    )

                case "enum":
                    enums_xml = enums_xml_dict.get(name)
                    yield EnumRecord(
                        name=name,
                        type_attr=enums_xml.get("type", "enum") if enums_xml is not None else "enum",
                        bitwidth_attr=enums_xml.get("bitwidth") if enums_xml is not None else None
                    )
                    #for enum_member_name in enums_enum_xml_dict:
                    #    yield EnumMemberRecord(
                    #        name=enum_member_name,
                    #        enum_name=name
                    #    )

                case "handle":
                    yield HandleRecord(
                        name=name,
                        parent_attr=type_xml.get("parent")
                    )

                case "struct":
                    yield StructRecord(
                        name=name,
                        field_list=[
                            Field(
                                name=member_xml.findtext("name", ""),
                                c_type=CType(c_type_str, constant_decimal_literal_dict),
                                bitwidth=int(bitwidth_str) if bitwidth_str else None,
                                len_attr=member_xml.get("len"),
                                altlen_attr=member_xml.get("altlen"),
                                optional_attr=member_xml.get("optional"),
                                selector_attr=member_xml.get("selector"),
                                selection_attr=member_xml.get("selection"),
                                values_attr=member_xml.get("values")
                            )
                            for member_xml, (c_type_str, _, bitwidth_str) in (
                                (member_xml, cls._join_xml_text(member_xml, ignored_tags=["comment", "name"]).partition(":"))
                                for member_xml in type_xml.iterfind("member")
                                if cls._check_api(member_xml, api)
                            )
                        ],
                        structextends_attr=type_xml.get("structextends"),
                        allowduplicate_attr=type_xml.get("allowduplicate")
                    )

                case "union":
                    yield UnionRecord(
                        name=name,
                        field_list=[
                            Field(
                                name=member_xml.findtext("name", ""),
                                c_type=CType(c_type_str, constant_decimal_literal_dict),
                                bitwidth=int(bitwidth_str) if bitwidth_str else None,
                                len_attr=member_xml.get("len"),
                                altlen_attr=member_xml.get("altlen"),
                                optional_attr=member_xml.get("optional"),
                                selector_attr=member_xml.get("selector"),
                                selection_attr=member_xml.get("selection"),
                                values_attr=member_xml.get("values")
                            )
                            for member_xml, (c_type_str, _, bitwidth_str) in (
                                (member_xml, cls._join_xml_text(member_xml, ignored_tags=["comment", "name"]).partition(":"))
                                for member_xml in type_xml.iterfind("member")
                                if cls._check_api(member_xml, api)
                            )
                        ]
                    )

                case "funcpointer":
                    assert (match := re.fullmatch(
                        fr"typedef (.*?) \(VKAPI_PTR \*{name}\)\((.*)\);",
                        cls._join_xml_text(type_xml).replace("\n", "")
                    )) is not None
                    yield FunctionPointerRecord(
                        name=name,
                        return_c_type=CType(match.group(1)),
                        argument_list=[
                            Argument(
                                name=argument_name,
                                c_type=CType(c_type_str)
                            )
                            for c_type_str, _, argument_name in (
                                argument_declaration.rpartition(" ")
                                for argument_declaration in arguments_str.split(",")
                            )
                        ] if (arguments_str := match.group(2)) != "void" else []
                    )

                case "define":
                    # Tricky judgement on deciding whether to export this macro...
                    if len(define_contents := tuple(
                        match.group(1)
                        for line in cls._join_xml_text(type_xml).replace("\\\n", "").splitlines()
                        if (match := re.fullmatch(fr"#define {name}\b(.*)", line.lstrip())) is not None
                    )) != 1 or "##" in (define_content := define_contents[0]):
                        continue
                    if (arguments_match := re.match(r"\((.*?)\)", define_content)) is not None:
                        yield FunctionMacroRecord(
                            name=name,
                            return_c_type=CType("const uint32_t"),
                            argument_list=[
                                Argument(
                                    name=argument_name,
                                    c_type=CType("const uint32_t")
                                )
                                for argument_name in arguments_match.group(1).split(", ")
                            ]
                        )
                    else:
                        yield MacroRecord(
                            name=name,
                            c_type=CType("const uint32_t")
                        )

                case _:
                    assert False

        for name in required_commands:
            command_xml = resolve_alias(name, command_xml_dict)
            assert (proto_xml := command_xml.find("proto")) is not None
            #handle_name = (
            #    first_param_type_str
            #    if (first_param_xml := command_xml.find("param")) is not None
            #    and (first_param_type_str := first_param_xml.findtext("type")) is not None
            #    and registry.handle_records.get(first_param_type_str, None) is not None
            #    else None
            #)
            yield CommandRecord(
                name=name,
                return_c_type=CType(cls._join_xml_text(proto_xml, ignored_tags=["comment", "name"]), constant_decimal_literal_dict),
                command_argument_list=[
                    CommandArgument(
                        name=param_xml.findtext("name", ""),
                        c_type=CType(cls._join_xml_text(param_xml, ignored_tags=["comment", "name"]), constant_decimal_literal_dict),
                        len_attr=param_xml.get("len"),
                        altlen_attr=param_xml.get("altlen"),
                        optional_attr=param_xml.get("optional"),
                        selector_attr=param_xml.get("selector"),
                    )
                    for param_xml in command_xml.iterfind("param")
                    if cls._check_api(param_xml, api)
                ],
                type_attr=command_type_attr_dict.get(name)
            )

        #yield from (
        #    record
        #    for record in itertools.chain(
        #        itertools.chain.from_iterable(
        #            cls._read_type_xml(
        #                name=name,
        #                type_xml=resolve_alias(type_xml, type_requirements),
        #                enums_xml=enums_xml_dict.get(name)
        #            )
        #            for name, type_xml in resolve_alias(type_requirements).items()
        #        ),
        #        (
        #            EnumMemberRecord(
        #                name=name,
        #                enum_name=enum_name
        #            )
        #            for enum_name, enum_intrinsic_enum_requirements in intrinsic_enum_requirements.items()
        #            for name, _ in resolve_alias(enum_intrinsic_enum_requirements).items()
        #        ),
        #        itertools.chain.from_iterable(
        #            cls._read_enum_xml(
        #                name=name,
        #                enum_xml=enum_xml
        #            )
        #            for name, enum_xml in resolve_alias(extrinsic_enum_requirements).items()
        #        ),
        #        itertools.chain.from_iterable(
        #            cls._read_command_xml(
        #                name=name,
        #                command_xml=command_xml
        #            )
        #            for name, command_xml in resolve_alias(command_requirements).items()
        #        )
        #    )
        #    if record.name not in removed_names
        #)


        #enums_xml_dict = {
        #    enums_xml.get("name", ""): enums_xml
        #    for enums_xml in registry_xml.iterfind("enums")
        #}

        #intrinsic_enum_xml_list_dict = {
        #    enum_name: list(enums_xml.iterfind("enum"))
        #    for enum_name, enums_xml in enums_xml_dict.items()
        #}
        ##enum_xml_dict = 
        #extrinsic_enum_xml_dict = {
        #    enum_name: list(enums_xml.iterfind("enum"))
        #    for enum_name, enums_xml in enums_xml_dict.items()
        #}

        #records: list[Record] = []
        ##removed_names: set[str] = set()
        #for feature_xml in registry_xml.iterfind("feature"):
        #    if not cls._check_api(feature_xml, api):
        #        continue
        #    for requirement_batch_xml in feature_xml:
        #        if requirement_batch_xml.tag not in ("require", "remove"):
        #            continue
        #        remove = requirement_batch_xml.tag == "remove"
        #        for requirement_unit_xml in requirement_batch_xml:
        #            if requirement_unit_xml.tag not in ("type", "enum", "command"):
        #                continue
        #            if not cls._check_api(requirement_unit_xml, api):
        #                continue
        #            name = requirement_unit_xml.get("name", "")
        #            if remove:
        #                removed_names.add(name)
        #                #registry.get_requirement(name).mark_removed()
        #                continue
        #            match requirement_unit_xml.tag:
        #                case "type":
        #                    alias, alias_xml = find_alias(type_xml_dict, name)
        #                    records.extend(cls._read_type_xml(name, alias_xml, enums_xml_dict.get(alias)))
        #                case "enum":
        #                    records.extend(cls._read_enum_xml(name, requirement_unit_xml))
        #                case "command":
        #                    records.extend(cls._read_command_xml(name, command_xml_dict[name], None))
        #            #if requirement_unit_xml.tag == "enum":
        #            #    cls._read_enum_xml(
        #            #        registry=registry,
        #            #        enum_xml=requirement_unit_xml,
        #            #        enum_name=requirement_unit_xml.get("extends")
        #            #    )
        #            #registry.get_requirement(name).mark_required()

        #for xml in registry_xml:
        #    match xml.tag:
        #        case "platforms":
        #            for platform_xml in xml.iterfind("platform"):
        #                if platforms is None or platform_xml.get("name", "") in platforms:
        #                    registry.define_list.append(platform_xml.get("protect", ""))

        #        case "tags":
        #            for tag_xml in xml.iterfind("tag"):
        #                registry.tag_list.append(tag_xml.get("name", ""))

        #        case "types":
        #            for type_xml in xml.iterfind("type"):
        #                if not cls._check_api(type_xml, api):
        #                    continue
        #                cls._read_type_xml(registry, type_xml)

        #        case "enums":
        #            if (enum_name := xml.get("name", "")) == "API Constants":
        #                enum_name = None
        #            else:
        #                enum = registry.enum_records[enum_name]
        #                enum.type_attr = xml.get("type", "enum")
        #                enum.bitwidth_attr = xml.get("bitwidth")
        #            for enum_xml in xml.iterfind("enum"):
        #                cls._read_enum_xml(
        #                    registry=registry,
        #                    enum_xml=enum_xml,
        #                    enum_name=enum_name
        #                )
        #                if enum_name is not None:
        #                    name = enum_xml.get("name", "")
        #                    registry.enum_member_records.get_requirement(name).mark_required()

        #        case "commands":
        #            for command_xml in xml.iterfind("command"):
        #                if not cls._check_api(command_xml, api):
        #                    continue
        #                cls._read_command_xml(
        #                    registry=registry,
        #                    command_xml=command_xml
        #                )

        #        case "feature":
        #            if not cls._check_api(xml, api):
        #                continue
        #            for requirement_batch_xml in xml:
        #                if requirement_batch_xml.tag not in ("require", "remove"):
        #                    continue
        #                remove = requirement_batch_xml.tag == "remove"
        #                for requirement_unit_xml in requirement_batch_xml:
        #                    if requirement_unit_xml.tag not in ("type", "enum", "command"):
        #                        continue
        #                    if not cls._check_api(requirement_unit_xml, api):
        #                        continue
        #                    name = requirement_unit_xml.get("name", "")
        #                    if remove:
        #                        registry.get_requirement(name).mark_removed()
        #                        continue
        #                    if requirement_unit_xml.tag == "enum":
        #                        cls._read_enum_xml(
        #                            registry=registry,
        #                            enum_xml=requirement_unit_xml,
        #                            enum_name=requirement_unit_xml.get("extends")
        #                        )
        #                    registry.get_requirement(name).mark_required()

        #        case "extensions":
        #            for extension_xml in xml.iterfind("extension"):
        #                if not cls._check_api(extension_xml, api) \
        #                        or not cls._check_supported(extension_xml, api) \
        #                        or not cls._check_platform(extension_xml, platforms):
        #                    continue
        #                extension_type = extension_xml.get("type")
        #                for requirement_batch_xml in extension_xml:
        #                    if requirement_batch_xml.tag not in ("require", "remove"):
        #                        continue
        #                    if not cls._check_api(requirement_batch_xml, api):
        #                        continue
        #                    remove = requirement_batch_xml.tag == "remove"
        #                    for requirement_unit_xml in requirement_batch_xml:
        #                        if requirement_unit_xml.tag not in ("type", "enum", "command"):
        #                            continue
        #                        if not cls._check_api(requirement_unit_xml, api):
        #                            continue
        #                        name = requirement_unit_xml.get("name", "")
        #                        if remove:
        #                            registry.get_requirement(name).mark_removed()
        #                            continue
        #                        if requirement_unit_xml.tag == "enum":
        #                            cls._read_enum_xml(
        #                                registry=registry,
        #                                enum_xml=requirement_unit_xml,
        #                                enum_name=requirement_unit_xml.get("extends")
        #                            )
        #                        if requirement_unit_xml.tag == "command":
        #                            registry.command_records[name].type_attr = extension_type
        #                        registry.get_requirement(name).mark_required()

    @classmethod
    def read(
        cls: type[Self],
        #registry: Registry,
        registry_xml_dir: pathlib.Path,
        api: str,
        platform: str
    ) -> Registry:
        if platform == "all":
            platforms = None
        else:
            platforms = [platform]
            if platform != "provisional":
                platforms.append("provisional")

        video_registry_xml = etree.parse(registry_xml_dir.joinpath("video.xml")).getroot()
        vk_registry_xml = etree.parse(registry_xml_dir.joinpath("vk.xml")).getroot()

        assert (version_xml := vk_registry_xml.find(
            f"types/type[@api='{api}'][name='VK_HEADER_VERSION']"
        )) is not None
        assert (version_match := re.fullmatch(
            r"#define VK_HEADER_VERSION (\d+)",
            cls._join_xml_text(version_xml).splitlines()[-1]
        )) is not None
        assert (version_complete_xml := vk_registry_xml.find(
            f"types/type[@api='{api}'][name='VK_HEADER_VERSION_COMPLETE']"
        )) is not None
        assert (version_complete_match := re.fullmatch(
            r"#define VK_HEADER_VERSION_COMPLETE VK_MAKE_API_VERSION\(\w+, (\d+), (\d+), VK_HEADER_VERSION\)",
            cls._join_xml_text(version_complete_xml).splitlines()[-1]
        )) is not None
        version = (int(version_complete_match.group(1)), int(version_complete_match.group(2)), int(version_match.group(1)))
        defines = [
            platform_xml.get("protect", "")
            for platform_xml in vk_registry_xml.iterfind("platforms/platform")
            if platforms is None or platform_xml.get("name", "") in platforms
        ]
        tags = [
            tag_xml.get("name", "")
            for tag_xml in vk_registry_xml.iterfind("tags/tag")
        ]
        assert platforms is None or len(platforms) == len(defines)

        record_dict: dict[str, Record] = {
            name: BuiltinTypeRecord(
                name=name
                #c_type=CType(name),
                #py_type_str=py_type_str
            )
            for name in BUILTIN_TYPE_DICT
        }
        for registry_xml in (video_registry_xml, vk_registry_xml):
            for record in cls._read_registry_xml(
                registry_xml=registry_xml,
                api=api,
                platforms=platforms,
                defines=defines
            ):
                record_dict.setdefault(record.name, record)

        builtin_type_records: list[BuiltinTypeRecord] = []
        typedef_records: list[TypedefRecord] = []
        bitmask_records: list[BitmaskRecord] = []
        enum_records: list[EnumRecord] = []
        handle_records: list[HandleRecord] = []
        struct_records: list[StructRecord] = []
        union_records: list[UnionRecord] = []
        function_pointer_records: list[FunctionPointerRecord] = []
        macro_records: list[MacroRecord] = []
        function_macro_records: list[FunctionMacroRecord] = []
        constant_records: list[ConstantRecord] = []
        enum_member_records: list[EnumMemberRecord] = []
        command_records: list[CommandRecord] = []
        for record in record_dict.values():
            match record:
                case BuiltinTypeRecord():
                    builtin_type_records.append(record)
                case TypedefRecord():
                    typedef_records.append(record)
                case BitmaskRecord():
                    bitmask_records.append(record)
                case EnumRecord():
                    enum_records.append(record)
                case HandleRecord():
                    handle_records.append(record)
                case StructRecord():
                    struct_records.append(record)
                case UnionRecord():
                    union_records.append(record)
                case FunctionPointerRecord():
                    function_pointer_records.append(record)
                case MacroRecord():
                    macro_records.append(record)
                case FunctionMacroRecord():
                    function_macro_records.append(record)
                case ConstantRecord():
                    constant_records.append(record)
                case EnumMemberRecord():
                    enum_member_records.append(record)
                case CommandRecord():
                    command_records.append(record)
                case _:
                    assert False

        return Registry(
            version=version,
            defines=defines,
            tags=tags,
            builtin_type_records=builtin_type_records,
            typedef_records=typedef_records,
            bitmask_records=bitmask_records,
            enum_records=enum_records,
            handle_records=handle_records,
            struct_records=struct_records,
            union_records=union_records,
            function_pointer_records=function_pointer_records,
            macro_records=macro_records,
            function_macro_records=function_macro_records,
            constant_records=constant_records,
            enum_member_records=enum_member_records,
            command_records=command_records
        )

        #for name, py_type_str in BUILTIN_TYPE_DICT.items():
        #    registry.builtin_type_records.new(
        #        name=name,
        #        c_type=CType(name),
        #        py_type_str=py_type_str
        #    )
        #for registry_xml_path in registry_xml_paths:
        #    registry.include_list.extend(REGISTRY_SRC_DICT[registry_xml_path.name])
        #    cls._read_registry_xml(
        #        registry=registry,
        #        registry_xml=etree.parse(registry_xml_path).getroot(),
        #        api=api,
        #        platforms=platforms
        #    )

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
        enum_dict = {
            enum.name: enum
            for enum in registry.enum_records
        } | {
            bitmask.name: bitmask
            for bitmask in registry.bitmask_records
        }
        struct_dict = {
            struct.name: struct
            for struct in registry.struct_records
        } | {
            union.name: union
            for union in registry.union_records
        }
        handle_dict = {
            handle.name: handle
            for handle in registry.handle_records
        }
        typedef_dict = {
            typedef.name: typedef
            for typedef in registry.typedef_records
        }
        for command in registry.command_records:
            for command_argument in command.command_argument_list:
                c_type = command_argument.c_type
                if c_type._base_type_str in enum_dict:
                    match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                        case False, (), ():
                            pass
                        case True, (), (_):
                            pass
                        case True, (False,), ():
                            pass
                        case False, (False,), ():
                            pass
                        case _:
                            assert False
                elif c_type._base_type_str in struct_dict:
                    match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                        case True, (False,), ():
                            pass
                        case False, (False,), ():
                            pass
                        case True, (True, False), ():
                            pass
                        case _:
                            assert False
                elif c_type._base_type_str in handle_dict:
                    match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                        case False, (), ():
                            pass
                        case True, (False,), ():
                            pass
                        case False, (False,), ():
                            pass
                        case _:
                            assert False
                elif c_type._base_type_str in typedef_dict:
                    match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                        case False, (), ():
                            pass
                        case True, (False,), ():
                            pass
                        case False, (False,), ():
                            pass
                        case _:
                            assert False
                    #if typedef_dict[c_type._base_type_str].c_type._base_type_str == "void":
                    #    match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                    #        case False, (), ():
                    #            pass
                    #        case False, (False,), ():
                    #            pass
                    #        case _:
                    #            assert False
                    #elif typedef_dict[c_type._base_type_str].c_type._base_type_str == "char":
                    #    assert False
                    #elif typedef_dict[c_type._base_type_str].c_type._base_type_str in BUILTIN_TYPE_DICT:
                    #    match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                    #        #case False, (), ():
                    #        #    pass
                    #        #case False, (False,), ():
                    #        #    pass
                    #        case _:
                    #            print(
                    #            command.name,
                    #            command_argument.name,
                    #            c_type._base_type_str,
                    #            c_type._const_specifier,
                    #            c_type._pointer_const_specifiers,
                    #            c_type._array_sizes
                    #        )
                    #else:
                    #    assert False

                    #match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                    #    case _:
                    #        print(
                    #            command.name,
                    #            command_argument.name,
                    #            c_type._base_type_str,
                    #            c_type._const_specifier,
                    #            c_type._pointer_const_specifiers,
                    #            c_type._array_sizes,
                    #            typedef_dict[c_type._base_type_str].c_type.format()
                    #        )
                elif c_type._base_type_str == "void":
                    match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                        case True, (False,), ():
                            pass
                        case False, (False,), ():
                            pass
                        case False, (False, False), ():
                            pass
                        case _:
                            assert False
                elif c_type._base_type_str == "char":
                    match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                        case True, (False,), ():
                            pass
                        case _:
                            assert False
                elif c_type._base_type_str in BUILTIN_TYPE_DICT:
                    match c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
                        case False, (), ():
                            pass
                        case True, (False,), ():
                            pass
                        case False, (False,), ():
                            pass
                        case True, (), (_):
                            pass
                        case True, (True, False), ():
                            pass
                        case _:
                            assert False
                else:
                    print(
                        command.name,
                        command_argument.name,
                        c_type._base_type_str,
                        c_type._const_specifier,
                        c_type._pointer_const_specifiers,
                        c_type._array_sizes
                    )

        yield from ()
        #for name, arg_name, c_type in itertools.chain(
        #    (
        #        (function_pointer.name, argument.name, argument.c_type)
        #        for function_pointer in registry.function_pointer_records
        #        for argument in function_pointer.argument_list
        #    ),
        #    (
        #        (command.name, command_argument.name, command_argument.c_type)
        #        for command in registry.command_records
        #        for command_argument in command.command_argument_list
        #    ),
        #    (
        #        (struct.name, field.name, field.c_type)
        #        for struct in registry.struct_records
        #        for field in struct.field_list
        #    ),
        #    (
        #        (union.name, field.name, field.c_type)
        #        for union in registry.union_records
        #        for field in union.field_list
        #    )
        #):
            #match arg_name, c_type._base_type_str, c_type._const_specifier, c_type._pointer_const_specifiers, c_type._array_sizes:
            #    case (_, base_type_str, False, (), ()) if base_type_str in enum_dict:
            #        # single enum
            #            #if base_type_str in BUILTIN_TYPE_DICT and base_type_str != "void"
            #        pass
            #    case (_, base_type_str, _, _, _) if base_type_str in enum_dict:
            #        print(
            #            name,
            #            arg_name,
            #            c_type._base_type_str,
            #            c_type._const_specifier,
            #            c_type._pointer_const_specifiers,
            #            c_type._array_sizes
            #        )
            #        pass
            #    case ("pNext", "void", True, (False,), ()):
            #        # pNext
            #        pass
            #    case _:
            #        #print(
            #        #    name,
            #        #    arg_name,
            #        #    c_type._base_type_str,
            #        #    c_type._const_specifier,
            #        #    c_type._pointer_const_specifiers,
            #        #    c_type._array_sizes
            #        #)
            #        pass

        #for typedef in registry.typedef_records:
        #    yield f"""typedef {typedef.c_type_str} {typedef.name};"""

        #for bitmask in registry.bitmask_records:
        #    yield f"""typedef {bitmask.type_attr} {bitmask.name};"""

        #for enum in registry.enum_records:
        #    yield f"""typedef {f"VkFlags64" if enum.bitwidth_attr == "64" else f"enum {enum.name} {{ ... }}"} {enum.name};"""

        #for handle in registry.handle_records:
        #    yield f"""typedef struct {handle.name}_T *{handle.name};"""

        #for struct in registry.struct_records:
        #    yield f"""typedef struct {struct.name} {struct.name};"""

        #for union in registry.union_records:
        #    yield f"""typedef union {union.name} {union.name};"""

        #for function_pointer in registry.function_pointer_records:
        #    yield f"""typedef {function_pointer.return_c_type.format()} (* {function_pointer.name})(\n{",\n".join(
        #        f"    {argument.c_type.format(argument.name)}"
        #        for argument in function_pointer.argument_list
        #    ) if function_pointer.argument_list else "    void"}\n);"""

        #for macro in registry.macro_records:
        #    yield f"""static {macro.c_type.format(macro.name)};"""

        #for function_macro in registry.function_macro_records:
        #    yield f"""static {function_macro.return_c_type.format()} {function_macro.name}(\n{",\n".join(
        #        f"    {argument.c_type.format(argument.name)}"
        #        for argument in function_macro.argument_list
        #    ) if function_macro.argument_list else "    void"}\n);"""

        #for constant in registry.constant_records:
        #    yield f"""static {constant.c_type.format(constant.name)};"""

        #for enum_member in registry.enum_member_records:
        #    yield f"""static const {enum_member.enum_name} {enum_member.name};"""

        #for command in registry.command_records:
        #    if command.type_attr is not None:
        #        continue
        #    yield f"""static {command.return_c_type.format()} {command.name}(\n{",\n".join(
        #        f"    {command_argument.c_type.format(command_argument.name)}"
        #        for command_argument in command.command_argument_list
        #    ) if command.command_argument_list else "    void"}\n);"""

        #for struct in registry.struct_records:
        #    yield f"""struct {struct.name} {{\n{"\n".join(
        #        f"    {field.c_type.format(field.name)}{f":{field.bitwidth}" if field.bitwidth is not None else ""};"
        #        for field in struct.field_list
        #    )}\n}};"""

        #for union in registry.union_records:
        #    yield f"""union {union.name} {{\n{"\n".join(
        #        f"    {field.c_type.format(field.name)}{f":{field.bitwidth}" if field.bitwidth is not None else ""};"
        #        for field in union.field_list
        #    )}\n}};"""

    @classmethod
    def _iter_csrc_strs(
        cls: type[Self],
        registry: Registry
    ) -> Iterator[str]:
        for define in registry.defines:
            yield f"#define {define}"

        for include in (
            "vk_video/vulkan_video_codec_h264std.h",
            "vk_video/vulkan_video_codec_h264std_decode.h",
            "vk_video/vulkan_video_codec_h265std.h",
            "vk_video/vulkan_video_codec_h265std_decode.h",
            "vk_video/vulkan_video_codec_h264std_encode.h",
            "vk_video/vulkan_video_codec_h265std_encode.h",
            "vulkan/vulkan.h"
        ):
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

    @classmethod
    def run(
        cls: type[Self],
        registry_xml_dir: pathlib.Path,
        generated_dir: pathlib.Path,
        api: str,
        platform: str,
        targets: str
    ) -> None:
        registry = Program.read(
            registry_xml_dir=registry_xml_dir,
            #registry_xml_paths=[
            #    pathlib.Path("extern/xml/video.xml"),
            #    pathlib.Path("extern/xml/vk.xml")
            #],
            api=api,
            platform=platform
        )

        subdir_name = "_".join((
            api,
            platform,
            *map(str, registry.version)
        ))
        generated_dir.mkdir(exist_ok=True)
        generated_subdir = generated_dir.joinpath(subdir_name)
        generated_subdir.mkdir(exist_ok=True)

        target_list = list(map(str.strip, targets.split(",")))
        assert all(target in ("cdef", "csrc", "pydef") for target in target_list)
        if "cdef" in target_list:
            Program.write_cdef(
                registry=registry,
                cdef_path=generated_subdir.joinpath(f"_vulkan_cdef.h")
            )
        if "csrc" in target_list:
            Program.write_csrc(
                registry=registry,
                csrc_path=generated_subdir.joinpath(f"_vulkan_csrc.h")
            )
        if "pydef" in target_list:
            Program.write_pydef(
                registry=registry,
                pydef_path=generated_subdir.joinpath(f"_pyvulkan.py")
            )


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--api", default="vulkan")
    parser.add_argument("--platform", default="all")
    parser.add_argument("--targets", default="cdef,csrc,pydef")
    arg_namespace = parser.parse_args()
    Program.run(
        registry_xml_dir=pathlib.Path("extern/xml"),
        generated_dir=pathlib.Path("generated"),
        api=arg_namespace.api,
        platform=arg_namespace.platform,
        targets=arg_namespace.targets
    )

    #api = arg_namespace.api
    #platform = arg_namespace.platform
    ##registry = Registry()
    #registry = Program.read(
    #    registry_xml_dir=pathlib.Path("extern/xml"),
    #    #registry_xml_paths=[
    #    #    pathlib.Path("extern/xml/video.xml"),
    #    #    pathlib.Path("extern/xml/vk.xml")
    #    #],
    #    api=api,
    #    platform=platform
    #)
    ##registry.finalize()
