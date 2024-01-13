#import itertools
import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    Self,
    TextIO
)


#class Aliases:
#    __slots__ = ("alias_dict",)

#    def __init__(
#        self: Self
#    ) -> None:
#        super().__init__()
#        self.alias_dict: dict[str, str] = {}

#    def is_empty(
#        self: Self
#    ) -> bool:
#        return not self.alias_dict

#    def read_alias(
#        self: Self,
#        name: str,
#        alias: str
#    ) -> None:
#        self.alias_dict[name] = alias

#    def write_aliases(
#        self: Self,
#        vulkan_py: TextIO,
#        indent: str
#    ) -> None:
#        alias_dict = self.alias_dict
#        if not alias_dict:
#            return
#        vulkan_py.write("\n\n")
#        for name in sorted(alias_dict):
#            alias = alias_dict[name]
#            next_alias = alias_dict.get(alias)
#            while next_alias is not None:
#                alias = next_alias
#                next_alias = alias_dict.get(alias)
#            vulkan_py.write(f"{indent}{name} = {alias}\n")


class Obj:
    __slots__ = ()

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        pass

    #def key(
    #    self: Self
    #) -> Any:
    #    return 0  # No ordering.


class Alias(Obj):
    __slots__ = (
        "name",
        "alias"
    )

    def __init__(
        self: Self,
        name: str,
        alias: str
    ) -> None:
        super().__init__()
        self.name: str = name
        self.alias: str = alias

    #def write_with_indent(
    #    self: Self,
    #    vulkan_py: TextIO,
    #    indent: str
    #) -> None:
    #    vulkan_py.write(f"{indent}{self.name} = {self.alias}\n")

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write(f"{self.name} = {self.alias}\n")


#class Category[ObjT: Obj](Obj):
#    __slots__ = (
#        "obj_list",
#        "aliases"
#    )

#    def __init__(
#        self: Self
#    ) -> None:
#        super().__init__()
#        self.obj_list: list[ObjT] = []
#        self.aliases: Aliases = Aliases()

#    def is_empty(
#        self: Self
#    ) -> bool:
#        return not self.obj_list

#    def iter_sorted_objs(
#        self: Self
#    ) -> Iterator[ObjT]:
#        yield from sorted(self.obj_list, key=lambda obj: obj.key())

#    def iter_sorted_objs_without_duplicates(
#        self: Self
#    ) -> Iterator[ObjT]:
#        prev_key = None
#        for obj in self.iter_sorted_objs():
#            key = obj.key()
#            if prev_key == key:
#                continue
#            yield obj
#            prev_key = key

#    def append_obj(
#        self: Self,
#        obj: ObjT
#    ) -> None:
#        self.obj_list.append(obj)

#    def set_alias(
#        self: Self,
#        name: str,
#        alias: str
#    ) -> None:
#        self.aliases.read_alias(name, alias)

#    def write(
#        self: Self,
#        vulkan_py: TextIO
#    ) -> None:
#        for obj in self.iter_sorted_objs():
#            obj.write(vulkan_py)
#        self.aliases.write_aliases(vulkan_py, indent="")


#class ExternalType(Obj):
#    __slots__ = ("name",)

#    def __init__(
#        self: Self,
#        name: str
#    ) -> None:
#        super().__init__()
#        self.name: str = name

#    def write(
#        self: Self,
#        vulkan_py: TextIO
#    ) -> None:
#        vulkan_py.write(f"{self.name} = Never\n")


#class Field(Obj):
#    __slots__ = (
#        "name",
#        "value_int"
#    )

#    def __init__(
#        self: Self,
#        name: str,
#        value_int: int
#    ) -> None:
#        super().__init__()
#        self.name: str = name
#        self.value_int: int = value_int

#    #def key(
#    #    self: Self
#    #) -> int:
#    #    return self.value_int


class Define(Obj):
    __slots__ = ("code",)

    def __init__(
        self: Self,
        code: str
    ) -> None:
        super().__init__()
        self.code: str = code

    @classmethod
    def build_code(
        cls: type[Self],
        macro: str
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

        macro = "".join(filter(None, (
            format_line(line)
            for line in macro.splitlines()
        ))).strip()

        if (match := re.fullmatch(r"#define (\w+) (\d+)", macro)) is not None:
            # Defines a literal number.
            name = match.group(1)
            value = match.group(2)
            return f"{name} = {value}"
        if (match := re.fullmatch(r"#define (\w+) (\w+)\(((?:\w+, )*\w+)\)", macro)) is not None:
            # Defines a literal number with a macro function call.
            name = match.group(1)
            func_name = match.group(2)
            args = tuple(arg_match.group() for arg_match in re.finditer(r"\w+", match.group(3)))
            return f"{name} = {func_name}({", ".join(args)})"
        if (match := re.fullmatch(r"#define (\w+)\(((?:\w+, )*\w+)\) \((.*)\)", macro)) is not None:
            # Defines a macro function.
            name = match.group(1)
            args = tuple(arg_match.group() for arg_match in re.finditer(r"\w+", match.group(2)))
            result = match.group(3)
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
            return f"def {name}({", ".join(f"{arg}: int" for arg in args)}) -> int: return {result}"
        return None


    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write(f"{self.code}\n")


class Constant(Obj):
    __slots__ = (
        "name",
        "value_code"
    )

    def __init__(
        self: Self,
        name: str,
        value_code: str
    ) -> None:
        super().__init__()
        self.name: str = name
        self.value_code: str = value_code

    @classmethod
    def build_value_code(
        cls: type[Self],
        value: str | None
    ) -> str | None:
        if value is None:
            return None
        if (match := re.fullmatch(r"\d+", value)) is not None:
            return match.group()
        if (match := re.fullmatch(r"0x[\dA-F]+", value)) is not None:
            return match.group()
        if (match := re.fullmatch(r"\(~(\d+)U\)", value)) is not None:
            return f"0x{(1 << 32) - 1 - int(match.group(1)):X}"
        if (match := re.fullmatch(r"\(~(\d+)ULL\)", value)) is not None:
            return f"0x{(1 << 64) - 1 - int(match.group(1)):X}"
        if (match := re.fullmatch(r"([+-]?\d*\.?\d+(E[+-]?\d+)?)F?", value, flags=re.IGNORECASE)) is not None:
            return match.group(1)
        if (match := re.fullmatch(r"\"\w+\"", value)) is not None:
            return match.group()
        if (match := re.fullmatch(r"\w+", value)) is not None:
            return match.group()
        raise ValueError

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write(f"{self.name} = {self.value_code}\n")

    #def key(
    #    self: Self
    #) -> str:
    #    return self.name


class Handle(Obj):
    __slots__ = ("name",)

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__()
        self.name: str = name

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write(f"class {self.name}(VulkanCData):\n")
        vulkan_py.write(f"    __slots__ = ()\n")


class Enum(Obj):
    __slots__ = (
        "name",
        "fields",
        "aliases"
    )

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__()
        self.name: str = name
        self.fields: dict[str, int] = {}
        self.aliases: dict[str, str] = {}

    @classmethod
    def build_field_value(
        cls: type[Self],
        value: str | None,
        bitpos: str | None,
        offset: str | None,
        extnumber: str | None,
        direction: str | None,
        number: str | None
    ) -> int:
        if value is not None:
            return int(value, base=16 if value.startswith("0x") else 10)
        if bitpos is not None:
            return 1 << int(bitpos)
        if offset is not None:
            if extnumber is not None:
                number = extnumber
            else:
                assert number is not None
            sign = -1 if direction == "-" else 1
            return sign * (1000000000 + (int(number) - 1) * 1000 + int(offset))
        raise ValueError

    def read_field(
        self: Self,
        field_name: str,
        field_value: int
    ) -> None:
        if field_name in self.fields:
            # Do not record duplicates.
            assert self.fields[field_name] == field_value
            return
        self.fields[field_name] = field_value

    def read_alias(
        self: Self,
        field_name: str,
        alias: str
    ) -> None:
        if field_name in self.aliases:
            # Do not record duplicates.
            assert self.aliases[field_name] == alias
            return
        self.aliases[field_name] = alias

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write(f"class {self.name}(Enum):\n")
        if not self.fields and not self.aliases:
            vulkan_py.write("    pass\n")
            return
        for field_name, field_value in self.fields.items():
            vulkan_py.write(f"    {field_name} = {field_value}\n")
        for field_name, alias in self.aliases.items():
            vulkan_py.write(f"    {field_name} = {alias}\n")

    #def key(
    #    self: Self
    #) -> str:
    #    return self.name


class Flag(Obj):
    __slots__ = (
        "name",
        "bitwidth",
        "bits_enum",
        "bits_enum_name"
    )

    def __init__(
        self: Self,
        name: str,
        bitwidth: int,
        bits_enum_name: str | None
    ) -> None:
        super().__init__()
        self.name: str = name
        self.bitwidth: int = bitwidth
        self.bits_enum_name: str | None = bits_enum_name
        self.bits_enum: Enum | None = None

    def attach_bits_enum(
        self: Self,
        bits_enum: Enum
    ) -> None:
        assert self.bits_enum is None
        assert bits_enum.name == self.bits_enum_name
        self.bits_enum = bits_enum

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write(f"class {self.name}(Flag):\n")
        if (bits_enum := self.bits_enum) is None or (not bits_enum.fields and not bits_enum.aliases):
            vulkan_py.write("    pass\n")
            return
        for field_name, field_value in bits_enum.fields.items():
            vulkan_py.write(f"    {field_name} = 0x{field_value:0{self.bitwidth // 4}X}\n")
        for field_name, alias in bits_enum.aliases.items():
            vulkan_py.write(f"    {field_name} = {alias}\n")

    #def key(
    #    self: Self
    #) -> str:
    #    return self.name





class Registry:
    __slots__ = (
        "objs",
        "type_dict"
        #"return_codes",
        #"external_types",
        #"defines",
        #"handles",
        #"constants",
        #"enums",
        #"flags"
    )

    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self.objs: list[Obj] = []
        self.type_dict: dict[str, type | Handle | Enum | Flag | None] = {
            # void, char
            "void": None,
            "int": int,
            "size_t": int,
            "float": float,
            "double": float,
            "char": str,
            "int8_t": int,
            "int16_t": int,
            "int32_t": int,
            "int64_t": int,
            "uint8_t": int,
            "uint16_t": int,
            "uint32_t": int,
            "uint64_t": int
        }
        #self.return_codes: Category[Field] = Category()
        #self.external_types: Category[ExternalType] = Category()
        #self.defines: Category[Define] = Category()
        #self.constants: Category[Constant] = Category()
        #self.handles: Category[Handle] = Category()
        #self.enums: Category[Enum] = Category()
        #self.flags: Category[Flag] = Category()

    def append_obj(
        self: Self,
        obj: Obj
    ) -> None:
        self.objs.append(obj)

    def read_alias(
        self: Self,
        name: str,
        alias: str
    ) -> None:
        self.append_obj(Alias(
            name=name,
            alias=alias
        ))

    def add_type(
        self: Self,
        type_name: str,
        type_obj: type | Handle | Enum | Flag | None
    ) -> None:
        assert type_name not in self.type_dict
        self.type_dict[type_name] = type_obj

    def has_type(
        self: Self,
        type_name: str
    ) -> bool:
        return type_name in self.type_dict

    def get_type(
        self: Self,
        type_name: str
    ) -> type | Handle | Enum | Flag | None:
        return self.type_dict[type_name]

    #def query_type_with_bound[BoundT: Obj](
    #    self: Self,
    #    type_name: str,
    #    bound: type[BoundT]
    #) -> BoundT | None:
    #    if not self.has_type(type_name):
    #        return None
    #    result = self.get_type(type_name)
    #    assert isinstance(result, bound)
    #    return result

    def read_field_or_constant(
        self: Self,
        enum: Enum | None,
        enum_xml: etree.Element,
        number: str | None
    ) -> None:
        name = enum_xml.attrib["name"]
        alias = enum_xml.attrib.get("alias")
        if enum is None:
            if alias is not None:
                self.read_alias(name, alias)
                return
            if (value_code := Constant.build_value_code(
                value=enum_xml.attrib.get("value")
            )) is None:
                return
            self.append_obj(Constant(
                name=name,
                value_code=value_code
            ))
            return
        #enum = self.get_type(enum_name)
        #assert isinstance(enum, Enum)
        if alias is not None:
            enum.read_alias(name, alias)
            return
        #print(enum_xml.attrib)
        enum.read_field(name, Enum.build_field_value(
            value=enum_xml.attrib.get("value"),
            bitpos=enum_xml.attrib.get("bitpos"),
            offset=enum_xml.attrib.get("offset"),
            extnumber=enum_xml.attrib.get("extnumber"),
            direction=enum_xml.attrib.get("direction"),
            number=number
        ))

    def read_registry(
        self: Self,
        registry_xml: etree.Element
    ) -> None:

        def check_api_attr(
            xml: etree.Element
        ) -> bool:
            api_attr = xml.attrib.get("api")
            return api_attr is None or "vulkan" in api_attr.split(",")

        # TODO: remove
        #def type_requirement_headers_satisfied(
        #    requires: str | None
        #) -> bool:
        #    if requires is None:
        #        return True
        #    if requires in ("stdint", "vk_platform"):
        #        return True
        #    if requires.startswith("vk_video/"):
        #        return True
        #    return False

        # TODO: remove
        def get_bitwidth_from_flag_type(
            flag_type_text: str | None
        ) -> int:
            match flag_type_text:
                case "VkFlags":
                    return 32
                case "VkFlags64":
                    return 64
            raise ValueError

        #def add_group_entry(
        #    group: Enum | Category[Constant],
        #    enum_xml: etree.Element,
        #    number: str | None
        #) -> None:
        #    name = enum_xml.attrib["name"]
        #    alias = enum_xml.attrib.get("alias")
        #    if alias is not None:
        #        group.set_alias(name, alias)
        #        return
        #    match group:
        #        case Enum():
        #            group.append_obj(Field(
        #                name=name,
        #                value_int=Field.build_value_int(
        #                    value=enum_xml.attrib.get("value"),
        #                    bitpos=enum_xml.attrib.get("bitpos"),
        #                    offset=enum_xml.attrib.get("offset"),
        #                    extnumber=enum_xml.attrib.get("extnumber"),
        #                    direction=enum_xml.attrib.get("direction"),
        #                    number=number
        #                )
        #            ))
        #        case Category():
        #            if (value_code := Constant.build_value_code(
        #                value=enum_xml.attrib.get("value")
        #            )) is None:
        #                return
        #            group.append_obj(Constant(
        #                name=name,
        #                value_code=value_code
        #            ))

        #def type_xml_categorize_key(
        #    type_xml: etree.Element
        #) -> str:
        #    return type_xml.attrib.get("category", "")

        #type_xml_categories = {
        #    category: tuple(
        #        (
        #            type_xml,
        #            (
        #                name_text
        #                if (name_text := type_xml.findtext("name")) is not None
        #                else type_xml.attrib["name"]
        #            ),
        #            type_xml.attrib.get("alias")
        #        )
        #        for type_xml in type_xml_iterator
        #    )
        #    for category, type_xml_iterator in itertools.groupby(
        #        sorted(
        #            filter(check_api_attr, registry_xml.iterfind("types/type")),
        #            key=type_xml_categorize_key
        #        ),
        #        key=type_xml_categorize_key
        #    )
        #}

        for type_xml in registry_xml.iterfind("types/type"):
            if not check_api_attr(type_xml):
                continue

            name = name_text if (name_text := type_xml.findtext("name")) is not None else type_xml.attrib["name"]
            if (alias := type_xml.attrib.get("alias")) is not None:
                self.read_alias(name, alias)
                continue

            match type_xml.attrib.get("category"):
                case None:
                    if self.has_type(name):
                        continue
                    self.add_type(name, None)

                case "define":
                    if (code := Define.build_code(
                        macro="".join(type_xml.itertext())
                    )) is None:
                        continue
                    define = Define(
                        code=code
                    )
                    self.append_obj(define)

                case "basetype":
                    self.add_type(
                        name,
                        (
                            self.get_type(match.group(1))
                            if (match := re.fullmatch(r"typedef (\w+) \w+;", "".join(type_xml.itertext()))) is not None
                            else None
                        )
                    )

                case "handle":
                    handle = Handle(
                        name=name
                    )
                    self.append_obj(handle)
                    self.add_type(name, handle)

                case "enum":
                    enum = Enum(
                        name=name
                    )
                    self.append_obj(enum)
                    self.add_type(name, enum)

                case "bitmask":
                    flag = Flag(
                        name=name,
                        bitwidth=get_bitwidth_from_flag_type(type_xml.findtext("type")),
                        bits_enum_name=type_xml.attrib.get("requires") or type_xml.attrib.get("bitvalues")
                    )
                    self.append_obj(flag)
                    self.add_type(name, flag)



        #tuple(
        #    (
        #        type_xml,
        #        type_xml.attrib.get("category"),
        #        (
        #            name_text
        #            if (name_text := type_xml.findtext("name")) is not None
        #            else type_xml.attrib["name"]
        #        ),
        #        type_xml.attrib.get("alias")
        #    )
        #    for type_xml in registry_xml.iterfind("types/type")
        #    if check_api_attr(type_xml)
        #)

        #for type_xml, name, _ in type_xml_categories.get("", ()):
        #    if type_requirement_headers_satisfied(type_xml.attrib.get("requires")):
        #        continue
        #    self.external_types.append_obj(ExternalType(
        #        name=name
        #    ))


        #for _, name, _ in type_xml_categories.get("", ()):
        #    if self.has_type(name):
        #        continue
        #    self.add_type(name, None)

        #for define_type_xml, name, alias in type_xml_categories.get("define", ()):
        #    if alias is not None:
        #        self.defines.set_alias(name, alias)
        #        continue
        #    if (code := Define.build_code(
        #        macro="".join(define_type_xml.itertext())
        #    )) is None:
        #        continue
        #    self.defines.append_obj(Define(
        #        code=code
        #    ))

        #for basetype_type_xml, name, _ in type_xml_categories.get("basetype", ()):
        #    self.add_type(
        #        name,
        #        (
        #            self.get_type(match.group(1))
        #            if (match := re.fullmatch(r"typedef (\w+) \w+;", "".join(basetype_type_xml.itertext()))) is not None
        #            else None
        #        )
        #    )

        #for _, name, alias in type_xml_categories.get("handle", ()):
        #    if alias is not None:
        #        self.handles.set_alias(name, alias)
        #        continue
        #    handle = Handle(
        #        name=name
        #    )
        #    self.handles.append_obj(handle)
        #    self.add_type(name, handle)

        #for _, name, alias in type_xml_categories.get("enum", ()):
        #    if alias is not None:
        #        self.enums.set_alias(name, alias)
        #        continue
        #    enum = Enum(
        #        name=name
        #    )
        #    self.enums.append_obj(enum)
        #    self.add_type(name, enum)

        #enum_dict = {
        #    enum.name: enum
        #    for enum in self.enums.iter_sorted_objs()
        #}
        #for bitmask_type_xml, name, alias in type_xml_categories.get("bitmask", ()):
        #    if alias is not None:
        #        self.flags.set_alias(name, alias)
        #        continue
        #    flag = Flag(
        #        name=name,
        #        bitwidth=get_bitwidth_from_flag_type(bitmask_type_xml.findtext("type")),
        #        bits_enum=enum_dict[bits_name] if (
        #            bits_name := bitmask_type_xml.attrib.get("requires") or bitmask_type_xml.attrib.get("bitvalues")
        #        ) is not None else None
        #    )
        #    self.flags.append_obj(flag)
        #    self.add_type(name, flag)

        for enums_xml in registry_xml.iterfind("enums"):
            if not self.has_type(enum_name := enums_xml.attrib["name"]):
                enum = None
            else:
                enum = self.get_type(enum_name)
                assert isinstance(enum, Enum)
            for enum_xml in enums_xml.iterfind("enum"):
                if not check_api_attr(enum_xml):
                    continue
                self.read_field_or_constant(enum, enum_xml, None)
                #name = enum_xml.attrib["name"]
                #if (alias := enum_xml.attrib.get("alias")) is not None:
                #    enum.read_alias(name, alias)
                #    continue
                #enum.read_field(name, Enum.build_field_value(
                #    value=enum_xml.attrib.get("value"),
                #    bitpos=enum_xml.attrib.get("bitpos"),
                #    offset=enum_xml.attrib.get("offset"),
                #    extnumber=enum_xml.attrib.get("extnumber"),
                #    direction=enum_xml.attrib.get("direction"),
                #    number=None
                #))
                #match group:
                #    case Enum():
                #        group.append_obj(Field(
                #            name=name,
                #            value_int=Field.build_value_int(
                #                value=enum_xml.attrib.get("value"),
                #                bitpos=enum_xml.attrib.get("bitpos"),
                #                offset=enum_xml.attrib.get("offset"),
                #                extnumber=enum_xml.attrib.get("extnumber"),
                #                direction=enum_xml.attrib.get("direction"),
                #                number=number
                #            )
                #        ))
                #match self.get_type(enum_name)
                #add_group_entry(
                #    group=enum_dict.get(enum_name, self.constants),
                #    enum_xml=enum_xml,
                #    number=None
                #)

        for feature_xml in registry_xml.iterfind("feature"):
            if not check_api_attr(feature_xml):
                continue
            for enum_xml in feature_xml.iterfind("require/enum"):
                if not check_api_attr(enum_xml):
                    continue
                if (enum_name := enum_xml.attrib.get("extends")) is None:
                    enum = None
                else:
                    enum = self.get_type(enum_name)
                    assert isinstance(enum, Enum)
                self.read_field_or_constant(enum, enum_xml, None)
                #name = enum_xml.attrib["name"]
                #alias = enum_xml.attrib.get("alias")
                #if (enum_name := enum_xml.attrib.get("extends")) is None:
                #    if alias is not None:
                #        print("alias missing!!!")
                #    if (value_code := Constant.build_value_code(
                #        value=enum_xml.attrib.get("value")
                #    )) is None:
                #        continue
                #    self.append_obj(Constant(
                #        name=name,
                #        value_code=value_code
                #    ))
                #    continue
                #enum = self.get_type(enum_name)
                #assert isinstance(enum, Enum)
                #if alias is not None:
                #    enum.read_alias(name, alias)
                #    continue
                #enum.read_field(name, Enum.build_field_value(
                #    value=enum_xml.attrib.get("value"),
                #    bitpos=enum_xml.attrib.get("bitpos"),
                #    offset=enum_xml.attrib.get("offset"),
                #    extnumber=enum_xml.attrib.get("extnumber"),
                #    direction=enum_xml.attrib.get("direction"),
                #    number=None
                #))
                #add_group_entry(
                #    group=enum_dict[enum_name] if (enum_name := enum_xml.attrib.get("extends")) is not None else self.constants,
                #    enum_xml=enum_xml,
                #    number=None
                #)

        for extension_xml in registry_xml.iterfind("extensions/extension"):
            number = extension_xml.attrib.get("number")
            for require_xml in extension_xml.iterfind("require"):
                if not check_api_attr(require_xml):
                    continue
                for enum_xml in require_xml.iterfind("enum"):
                    if not check_api_attr(enum_xml):
                        continue
                    #add_group_entry(
                    #    group=enum_dict[enum_name] if (enum_name := enum_xml.attrib.get("extends")) is not None else self.constants,
                    #    enum_xml=enum_xml,
                    #    number=extension_xml.attrib.get("number")
                    #)
                    if (enum_name := enum_xml.attrib.get("extends")) is None:
                        enum = None
                    else:
                        enum = self.get_type(enum_name)
                        assert isinstance(enum, Enum)
                    self.read_field_or_constant(enum, enum_xml, number)
                    #name = enum_xml.attrib["name"]
                    #alias = enum_xml.attrib.get("alias")
                    #if (enum_name := enum_xml.attrib.get("extends")) is None:
                    #    if alias is not None:
                    #        print("alias missing!!!")
                    #    if (value_code := Constant.build_value_code(
                    #        value=enum_xml.attrib.get("value")
                    #    )) is None:
                    #        continue
                    #    self.append_obj(Constant(
                    #        name=name,
                    #        value_code=value_code
                    #    ))
                    #    continue
                    #enum = self.get_type(enum_name)
                    #assert isinstance(enum, Enum)
                    #if alias is not None:
                    #    enum.read_alias(name, alias)
                    #    continue
                    #enum.read_field(name, Enum.build_field_value(
                    #    value=enum_xml.attrib.get("value"),
                    #    bitpos=enum_xml.attrib.get("bitpos"),
                    #    offset=enum_xml.attrib.get("offset"),
                    #    extnumber=enum_xml.attrib.get("extnumber"),
                    #    direction=enum_xml.attrib.get("direction"),
                    #    number=extension_xml.attrib.get("number")
                    #))



        #if (result_enum := enum_dict.get("VkResult")) is not None:
        #    for result_field in result_enum.iter_sorted_objs():
        #        self.return_codes.append_obj(result_field)

    def write_registry(
        self: Self,
        vulkan_py: TextIO
    ) -> None:

        #vulkan_py.write("\n\n## external types\n")
        #self.external_types.write(vulkan_py)

        #vulkan_py.write("\n\n## defines\n")
        #self.defines.write(vulkan_py)

        #vulkan_py.write("\n\n## constants\n")
        #self.constants.write(vulkan_py)

        #vulkan_py.write("\n\n## handles\n")
        #self.handles.write(vulkan_py)

        #vulkan_py.write("\n\n## enums\n")
        #self.enums.write(vulkan_py)

        #vulkan_py.write("\n\n## flags\n")
        #self.flags.write(vulkan_py)

        for obj in self.objs:
            vulkan_py.write("\n")
            obj.write(vulkan_py)

        vulkan_py.write("\n")
        vulkan_py.write("RETURN_CODES.update({\n")
        vulkan_py.write("    result_field.value: result_field.name\n")
        vulkan_py.write("    for result_field in VkResult\n")
        vulkan_py.write("    if isinstance(result_field.value, int)\n")
        vulkan_py.write("})\n")

        # TODO: Generate __all__


def main() -> None:
    generated_dir = pathlib.Path("generated")
    generated_dir.mkdir(exist_ok=True)

    with generated_dir.joinpath("_vulkan.py").open("w", newline="\n") as vulkan_py:
        vulkan_py.write(pathlib.Path("preamble.py").read_text())
        registry = Registry()
        for xml in (
            pathlib.Path("Vulkan-Docs/xml/video.xml"),
            pathlib.Path("Vulkan-Docs/xml/vk.xml")
        ):
            registry.read_registry(registry_xml=etree.parse(xml).getroot())
        registry.write_registry(vulkan_py)


if __name__ == "__main__":
    main()
