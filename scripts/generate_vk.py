import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    Any,
    Iterator,
    Self,
    TextIO
)


#def iterfind(
#    xml: etree.Element,
#    path: str,
#    check_api: bool
#) -> Iterator[etree.Element]:
#    split_index = path.index("/") if "/" in path else None
#    tag = path if split_index is None else path[:split_index]
#    tail = path if split_index is None else path[split_index + 1:]
#    for child in xml.iterfind(tag):
#        if check_api:
#            api_attr = child.attrib.get("api")
#            if api_attr is not None and "vulkan" not in api_attr.split(","):
#                continue
#        if split_index is None:
#            yield child
#        else:
#            yield from iterfind(child, tail, check_api=check_api)


class Aliases:
    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self.alias_dict: dict[str, str] = {}

    def read_alias(
        self: Self,
        name: str,
        alias: str
    ) -> None:
        self.alias_dict[name] = alias

    def write_aliases(
        self: Self,
        vulkan_py: TextIO,
        indent: str = ""
    ) -> None:
        alias_dict = self.alias_dict
        for name in sorted(alias_dict):
            alias = alias_dict[name]
            next_alias = alias_dict.get(alias)
            while next_alias is not None:
                alias = next_alias
                next_alias = alias_dict.get(alias)
            vulkan_py.write(f"{indent}{name} = {alias}\n")


class Obj:
    #@abstractmethod
    #@classmethod
    #def build(
    #    cls: type[Self],
    #    name: str,
    #    *args: P.args,
    #    **kwargs: P.kwargs
    #) -> Self | None:
    #    pass

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        pass

    def key(
        self: Self
    ) -> Any:
        return 0  # No ordering.


class Category[ObjT: Obj](Obj):
    def __init__(
        self: Self
        #obj_type: type[ObjT]
        #category_name: Optional[str]
    ) -> None:
        super().__init__()
        #self.obj_type: type[ObjT] = obj_type
        #self.category_name: Optional[str] = category_name
        #self.build_obj: Callable[[etree.Element], ObjT] = build_obj
        #self.write_obj: Callable[[TextIO, ObjT], None] = write_obj
        self.obj_list: list[ObjT] = []
        self.aliases: Aliases = Aliases()

    def is_empty(
        self: Self
    ) -> bool:
        return not self.obj_list

    def iter_sorted_objs(
        self: Self
    ) -> Iterator[ObjT]:
        yield from sorted(self.obj_list, key=lambda obj: obj.key())

    def iter_sorted_objs_without_duplicates(
        self: Self
    ) -> Iterator[ObjT]:
        prev_key = None
        for obj in self.iter_sorted_objs():
            key = obj.key()
            if prev_key == key:
                continue
            yield obj
            prev_key = key

    def append_obj(
        self: Self,
        obj: ObjT
    ) -> None:
        self.obj_list.append(obj)

    def set_alias(
        self: Self,
        name: str,
        alias: str
    ) -> None:
        self.aliases.read_alias(name, alias)

    #def read_obj(
    #    self: Self,
    #    name: str,
    #    alias: str | None,
    #    *args: P.args,
    #    **kwargs: P.kwargs
    #    #xml: etree.Element
    #) -> None:
    #    #name = xml.attrib.get("name")
    #    #if name is None:
    #    #    name_xml = xml.find("name")
    #    #    assert name_xml is not None
    #    #    name = name_xml.text
    #    #    assert name is not None
    #    #alias = xml.attrib.get("alias")
    #    if alias is not None:
    #        self.aliases.read_alias(name, alias)
    #        return
    #    obj = self.obj_type.build(name=name, *args, **kwargs)
    #    if obj is None:
    #        return
    #    self.obj_dict[name] = obj

    #def get_obj(
    #    self: Self,
    #    name: str
    #) -> ObjT:
    #    return self.obj_dict[name]

    #def get_obj_optional(
    #    self: Self,
    #    name: str
    #) -> ObjT | None:
    #    return self.obj_dict.get(name)

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        #if self.category_name is not None:
        #    vulkan_py.write(f"## {self.category_name}\n\n")
        for obj in self.iter_sorted_objs():
            obj.write(vulkan_py)
        #vulkan_py.write("\n\n")
        #self.aliases.write_aliases(vulkan_py, indent="")


class Define(Obj):
    def __init__(
        self: Self,
        code: str
        #macro: str
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
            return f"def {name}({", ".join(f"{arg}: int" for arg in args)}) -> int: return {result}"
        return None


    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write(self.code)
        vulkan_py.write("\n")


#class Defines:
#    def __init__(
#        self
#    ) -> None:
#        super().__init__()
#        self.code_list: List[str] = []

#    def read_code_from_type_xml(
#        self,
#        type_xml: etree.Element
#    ) -> None:
#        code = self.convert_macro_to_code(
#            macro="".join(type_xml.itertext())
#        )
#        if code is None:
#            return
#        self.code_list.append(code)

#    def write(
#        self,
#        vulkan_py: TextIO
#    ) -> None:
#        vulkan_py.write("\n\n## defines\n")
#        for code in self.code_list:
#            vulkan_py.write(code)
#            vulkan_py.write("\n")


class Constant(Obj):
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
        if (match := re.fullmatch(r"([+-]?\d*\.?\d+(E[+-]?\d+)?)F?", value, flags=re.IGNORECASE)) is not None:
            return match.group(1)
        if (match := re.fullmatch(r"\"\w+\"", value)) is not None:
            return match.group()
        if (match := re.fullmatch(r"\(~(\d+)U\)", value)) is not None:
            return f"0x{(1 << 32) - 1 - int(match.group(1)):X}"
        if (match := re.fullmatch(r"\(~(\d+)ULL\)", value)) is not None:
            return f"0x{(1 << 64) - 1 - int(match.group(1)):X}"
        raise ValueError

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write(f"{self.name} = {self.value_code}\n")

    def key(
        self: Self
    ) -> str:
        return self.name


#class FlagField(Obj):
#    def __init__(
#        self: Self,
#        name: str,
#        bitwidth: int,
#        value: str | None,
#        bitpos: str | None
#    ) -> None:
#        super().__init__()
#        if value is not None:
#            value_int = int(value, base=16 if value.startswith("0x") else 10)
#        elif bitpos is not None:
#            value_int = 1 << int(bitpos)
#        else:
#            raise ValueError
#        self.name: str = name
#        self.value_int: int = value_int
#        self.bitwidth: int = bitwidth
#
#    def write(
#        self: Self,
#        vulkan_py: TextIO
#    ) -> None:
#        vulkan_py.write(f"    {self.name} = 0x{self.value_int:0{self.bitwidth // 4}X}\n")
#
#    def key(
#        self: Self
#    ) -> int:
#        return self.value_int


class Field(Obj):
    def __init__(
        self: Self,
        name: str,
        value_int: int
    ) -> None:
        super().__init__()
        #value = xml.attrib.get("value")
        #if value is None:
        #    return None
        self.name: str = name
        self.value_int: int = value_int
        #self.value_str: str = f"{value_int}"

    @classmethod
    def build_value_int(
        cls: type[Self],
        value: str | None,
        bitpos: str | None,
        offset: str | None,
        extnumber: str | None,
        direction: str | None,
        extension_number: int | None
    ) -> int:
        if value is not None:
            return int(value, base=16 if value.startswith("0x") else 10)
        if bitpos is not None:
            return 1 << int(bitpos)
        if offset is not None:
            if extnumber is not None:
                extension_number = int(extnumber)
            else:
                assert extension_number is not None
            sign = -1 if direction == "-" else 1
            return sign * (1000000000 + (extension_number - 1) * 1000 + int(offset))
        raise ValueError

    #def write(
    #    self: Self,
    #    vulkan_py: TextIO
    #) -> None:
    #    vulkan_py.write(f"    {self.name} = {self.value_int}\n")

    def key(
        self: Self
    ) -> int:
        return self.value_int


class Enum(Category[Field]):
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
        vulkan_py.write("\n\n")
        vulkan_py.write(f"class {self.name}(Enum):\n")
        if self.is_empty():
            vulkan_py.write("    pass\n")
        for field in self.iter_sorted_objs_without_duplicates():
            vulkan_py.write(f"    {field.name} = {field.value_int}\n")
        self.aliases.write_aliases(vulkan_py, indent="    ")

    def key(
        self: Self
    ) -> str:
        return self.name


class Flag(Obj):
    def __init__(
        self: Self,
        name: str,
        bitwidth: int,
        bits_enum: Enum | None
    ) -> None:
        super().__init__()
        self.name: str = name
        self.bitwidth: int = bitwidth
        self.bits_enum: Enum | None = bits_enum

    def write(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write("\n\n")
        vulkan_py.write(f"class {self.name}(Flag):\n")
        if (bits_enum := self.bits_enum) is None:
            vulkan_py.write(f"    pass\n")
            return
        if bits_enum.is_empty():
            vulkan_py.write("    pass\n")
        for field in bits_enum.iter_sorted_objs_without_duplicates():
            vulkan_py.write(f"    {field.name} = 0x{field.value_int:0{self.bitwidth // 4}X}\n")
        bits_enum.aliases.write_aliases(vulkan_py, indent="    ")

    def key(
        self: Self
    ) -> str:
        return self.name


#class Enum(Obj):
#    def __init__(
#        self: Self,
#        name: str
#    ) -> None:
#        super().__init__()
#        self.name: str = name
#        self.members: Category[EnumField] = Category(EnumField)

#    @classmethod
#    def build(
#        cls: type[Self],
#        name: str
#        #xml: etree.Element
#    ) -> Self:
#        return cls(
#            name=name
#        )

#    def write(
#        self: Self,
#        vulkan_py: TextIO
#    ) -> None:
#        vulkan_py.write(f"class {self.name}(Enum):\n")
#        self.members.write(vulkan_py)


#class Enum(Obj):
#    def __init__(
#        self,
#        name: str,
#        bitwidth: int | None
#    ) -> None:
#        super().__init__()
#        self.name: str = name
#        self.bitwidth: int | None = bitwidth
#        self.members: Category[Constant] = Category(Constant)
#        #self.member_list: List[Tuple[str, str, int]] = []
#        #self.aliases: Aliases = Aliases()

#    @classmethod
#    def convert_field_value(
#        cls,
#        value: str | None,
#        bitpos: str | None,
#        offset: str | None,
#        extnumber: str | None,
#        direction: str | None,
#        extension_number: int | None
#    ) -> int:
#        if value is not None:
#            return int(value, base=16 if value.startswith("0x") else 10)
#        if bitpos is not None:
#            return 1 << int(bitpos)
#        if offset is not None:
#            if extnumber is not None:
#                extension_number = int(extnumber)
#            else:
#                assert extension_number is not None
#            sign = -1 if direction == "-" else 1
#            return sign * (1000000000 + (extension_number - 1) * 1000 + int(offset))
#        raise ValueError

#    def read_member_from_enum_xml(
#        self,
#        enum_xml: etree.Element,
#        extension_number: int | None
#    ) -> None:
#        name = enum_xml.attrib["name"]
#        alias = enum_xml.attrib.get("alias")
#        if alias is not None:
#            self.aliases[name] = alias
#            return

#        if not self.name:
#            value = enum_xml.attrib.get("value")
#            if value is None:
#                return
#            const_value = self.convert_const_value(
#                value=value
#            )
#            value_str = const_value
#            key = 0  # Order by name.
#        else:
#            field_value = self.convert_field_value(
#                value=enum_xml.get("value"),
#                bitpos=enum_xml.get("bitpos"),
#                offset=enum_xml.get("offset"),
#                extnumber=enum_xml.get("extnumber"),
#                direction=enum_xml.get("dir"),
#                extension_number=extension_number
#            )
#            value_str = f"0x{field_value:0{self.bitwidth // 4}X}" if self.bitwidth is not None else f"{field_value}"
#            key = field_value
#        self.member_list.append((name, value_str, key))

#    def iter_items(
#        self
#    ) -> Iterator[Tuple[str, str]]:
#        member_list = self.member_list
#        # Handle duplicated enum definitions
#        prev_name = ""
#        prev_value_str = 0
#        for name, value_str, _ in sorted(member_list, key=lambda t: (t[2], t[0])):
#            if name == prev_name:
#                print(f"{name} duplicated")
#                assert value_str == prev_value_str
#                continue
#            yield name, value_str
#            prev_name = name
#            prev_value_str = value_str

#    @classmethod
#    def build(
#        cls: type[EnumT],
#        type_xml: etree.Element
#    ) -> Optional[EnumT]:
#        code = cls.convert_macro_to_code(
#            macro="".join(type_xml.itertext())
#        )
#        if code is None:
#            return None
#        return cls(code)

#    def write(
#        self,
#        vulkan_py: TextIO
#    ) -> None:
#        if self.name:
#            indent = "    "
#            vulkan_py.write(f"class {self.name}({"Flag" if self.bitwidth is not None else "Enum"}):\n")
#            if not self.member_list:
#                vulkan_py.write(f"    pass\n")
#        else:
#            indent = ""
#        for name, value in self.iter_items():
#            vulkan_py.write(f"{indent}{name} = {value}\n")
#        self.aliases.write(vulkan_py, indent)


#class Enums:
#    def __init__(
#        self
#    ) -> None:
#        super().__init__()
#        self.enum_dict: dict[str, Enum] = {}

#    def read_enum_from_enums_xml(
#        self,
#        enums_xml: etree.Element
#    ) -> None:
#        enum_type = enums_xml.attrib.get("type")
#        name = enums_xml.attrib["name"] if enum_type is not None else ""
#        enum = Enum(
#            name=name,
#            bitwidth=int(enums_xml.attrib.get("bitwidth", "32")) if enum_type == "bitmask" else None
#        )
#        for enum_xml in enums_xml.iterfind("enum"):
#            if not check_api_attr(enum_xml):
#                continue
#            enum.read_member_from_enum_xml(enum_xml, None)
#        self.enum_dict[name] = enum

#    def get_enum(
#        self,
#        enum_name: str
#    ) -> Enum:
#        return self.enum_dict[enum_name]

#    def write(
#        self,
#        vulkan_py: TextIO
#    ) -> None:
#        enum_dict = self.enum_dict.copy()

#        vulkan_py.write("\n\n## constants\n")
#        constants_enum = enum_dict.pop("")
#        for name, value in constants_enum.iter_items():
#            vulkan_py.write(f"{name} = {value}\n")
#        for name, alias in constants_enum.iter_aliases():
#            vulkan_py.write(f"{name} = {alias}\n")

#        vulkan_py.write("\n\n## enums\n")
#        for enum in enum_dict.values():
#            vulkan_py.write("\n\n")
#            enum.write(vulkan_py)


#class Struct:
#    def __init__(
#        self,
#        name: str
#    ) -> None:
#        super().__init__()
#        self.name: str = name


#class Structs:
#    def __init__(self):
#        super().__init__()
#        self.aliases: dict[str, str] = {}

#    def read_struct_from_type_xml(
#        self,
#        type_xml: etree.Element
#    ) -> None:
#        pass

#    def write(
#        self,
#        vulkan_py: TextIO
#    ) -> None:
#        pass


class Registry:
    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self.return_codes: Category[Field] = Category()
        self.defines: Category[Define] = Category()
        self.constants: Category[Constant] = Category()
        self.enums: Category[Enum] = Category()
        self.flags: Category[Flag] = Category()

    @classmethod
    def check_api_attr(
        cls: type[Self],
        xml: etree.Element
    ) -> bool:
        api_attr = xml.attrib.get("api")
        return api_attr is None or "vulkan" in api_attr.split(",")

        #if (flag := self.flags.get_obj_optional(group_name)) is not None:
        #    if alias is not None:
        #        flag.set_alias(name, alias)
        #    else:
        #        flag.append_obj(FlagField(
        #            name=name,
        #            bitwidth=flag.bitwidth,
        #            value=enum_xml.attrib.get("value"),
        #            bitpos=enum_xml.attrib.get("bitpos")
        #        ))
        #elif (enum := self.enums.get_obj_optional(group_name)) is not None:
        #    if alias is not None:
        #        enum.set_alias(name, alias)
        #    else:
        #        print(enum_xml.attrib, extension_number)
        #        enum.append_obj(Field(
        #            name=name,
        #            value=enum_xml.attrib.get("value"),
        #            bitpos=enum_xml.attrib.get("bitpos"),
        #            offset=enum_xml.attrib.get("offset"),
        #            extnumber=enum_xml.attrib.get("extnumber"),
        #            direction=enum_xml.attrib.get("direction"),
        #            extension_number=extension_number
        #        ))
        #else:
        #    if alias is not None:
        #        self.constants.set_alias(name, alias)
        #    else:
        #        if (value := enum_xml.attrib.get("value")) is None:
        #            return
        #        self.constants.append_obj(Constant(
        #            name=name,
        #            value=value
        #        ))

    def read_registry(
        self: Self,
        registry_xml: etree.Element
    ) -> None:

        def get_bitwidth_from_flag_type(
            flag_type_text: str | None
        ) -> int:
            match flag_type_text:
                case "VkFlags":
                    return 32
                case "VkFlags64":
                    return 64
            raise ValueError

        def add_group_entry(
            group: Enum | Category[Constant],
            enum_xml: etree.Element,
            extension_number: int | None
        ) -> None:
            name = enum_xml.attrib["name"]
            alias = enum_xml.attrib.get("alias")
            if alias is not None:
                group.set_alias(name, alias)
                return
            match group:
                case Enum():
                    group.append_obj(Field(
                        name=name,
                        value_int=Field.build_value_int(
                            value=enum_xml.attrib.get("value"),
                            bitpos=enum_xml.attrib.get("bitpos"),
                            offset=enum_xml.attrib.get("offset"),
                            extnumber=enum_xml.attrib.get("extnumber"),
                            direction=enum_xml.attrib.get("direction"),
                            extension_number=extension_number
                        )
                    ))
                case Category():
                    if (value_code := Constant.build_value_code(
                        value=enum_xml.attrib.get("value")
                    )) is None:
                        return
                    group.append_obj(Constant(
                        name=name,
                        value_code=value_code
                    ))

        #flag_name_to_bits_name_dict: dict[str, str] = {}

        type_xml_items_list = tuple(
            (
                type_xml,
                type_xml.attrib.get("category"),
                (
                    name_text
                    if (name_text := type_xml.findtext("name")) is not None
                    else type_xml.attrib["name"]
                ),
                type_xml.attrib.get("alias")
            )
            for type_xml in registry_xml.iterfind("types/type")
            if self.check_api_attr(type_xml)
        )
        #define_type_xml_list: list[etree.Element] = []
        #enum_type_xml_list: list[etree.Element] = []
        #bitmask_type_xml_list: list[etree.Element] = []
        #for type_xml in registry_xml.iterfind("types/type"):
        #    if not self.check_api_attr(type_xml):
        #        continue
        #    match type_xml.attrib.get("category"):
        #        case "define":
        #            define_type_xml_list.append(type_xml)
        #        case "enum":
        #            enum_type_xml_list.append(type_xml)
        #        case "bitmask":
        #            bitmask_type_xml_list.append(type_xml)

        for define_type_xml, category, name, alias in type_xml_items_list:
            if category != "define":
                continue
            if alias is not None:
                self.defines.set_alias(name, alias)
                continue
            if (code := Define.build_code(
                macro="".join(define_type_xml.itertext())
            )) is None:
                continue
            self.defines.append_obj(Define(
                code=code
            ))

        for _, category, name, alias in type_xml_items_list:
            if category != "enum":
                continue
            if alias is not None:
                self.enums.set_alias(name, alias)
                continue
            self.enums.append_obj(Enum(
                name=name
            ))

        enum_dict = {
            enum.name: enum
            for enum in self.enums.iter_sorted_objs()
        }
        for bitmask_type_xml, category, name, alias in type_xml_items_list:
            if category != "bitmask":
                continue
            if alias is not None:
                self.flags.set_alias(name, alias)
                continue
            bits_name = bitmask_type_xml.attrib.get("requires") or bitmask_type_xml.attrib.get("bitvalues")
            self.flags.append_obj(Flag(
                name=name,
                bitwidth=get_bitwidth_from_flag_type(bitmask_type_xml.findtext("type")),
                bits_enum=enum_dict[bits_name] if bits_name is not None else None
            ))
            #match type_xml.attrib.get("category"):
            #    case "define":
            #    case "enum":
            #        if alias is not None:
            #            self.enums.set_alias(name, alias)
            #        else:
            #            if name not in enum_dict:
            #                enum = Enum(
            #                    name=name
            #                )
            #                enum_dict[name] = enum
            #                self.enums.append_obj(enum)
            #    case "bitmask":
            #        if alias is not None:
            #            self.flags.set_alias(name, alias)
            #        else:
            #            bits_name = type_xml.attrib.get("requires") or type_xml.attrib.get("bitvalues")
            #            if bits_name is not None:
            #                if bits_name not in enum_dict:
            #                    bits_enum = Enum(
            #                        name=bits_name
            #                    )
            #                    enum_dict[bits_name] = bits_enum
            #                    self.enums.append_obj(bits_enum)
            #                else:
            #                    bits_enum = enum_dict[bits_name]
            #            else:
            #                bits_enum = None
            #            self.flags.append_obj(Flag(
            #                name=name,
            #                bitwidth=get_bitwidth_from_flag_type(type_xml.findtext("type")),
            #                bits_enum=bits_enum
            #            ))

        for enums_xml in registry_xml.iterfind("enums"):
            enum_name = enums_xml.attrib["name"]
            for enum_xml in enums_xml.iterfind("enum"):
                if not self.check_api_attr(enum_xml):
                    continue
                add_group_entry(
                    group=enum_dict.get(enum_name, self.constants),
                    enum_xml=enum_xml,
                    extension_number=None
                )
            #group = self.get_group()
            #enum_xml_tuple = tuple(
            #    enum_xml
            #    for enum_xml in enums_xml.iterfind("enum")
            #    if self.check_api_attr(enum_xml)
            #)
            #match group:
            #    case Enum():
            #        for enum_xml in enum_xml_tuple:
            #            group.append_obj(
            #                name := enum_xml.attrib["name"],
            #                EnumField(
            #                    name=name,
            #                    value=enum_xml.attrib.get("value"),
            #                    offset=enum_xml.attrib.get("offset"),
            #                    extnumber=enum_xml.attrib.get("extnumber"),
            #                    direction=enum_xml.attrib.get("direction"),
            #                    extension_number=None
            #                )
            #            )
            #    case Flag():
            #        for enum_xml in enum_xml_tuple:
            #            group.append_obj(
            #                name := enum_xml.attrib["name"],
            #                FlagField(
            #                    name=name,
            #                    bitwidth=bitwidth,
            #                    value=enum_xml.attrib.get("value"),
            #                    bitpos=enum_xml.attrib.get("bitpos")
            #                )
            #            )
            #    case Category():
            #        for enum_xml in enum_xml_tuple:
            #            if (value := enum_xml.attrib.get("value")) is None:
            #                continue
            #            group.append_obj(
            #                name := enum_xml.attrib["name"],
            #                Constant(
            #                    name=name,
            #                    value=value
            #                )
            #            )

        for feature_xml in registry_xml.iterfind("feature"):
            if not self.check_api_attr(feature_xml):
                continue
            for enum_xml in feature_xml.iterfind("require/enum"):
                if not self.check_api_attr(enum_xml):
                    continue
                add_group_entry(
                    group=enum_dict[enum_name] if (enum_name := enum_xml.attrib.get("extends")) is not None else self.constants,
                    enum_xml=enum_xml,
                    extension_number=None
                )

        for extension_xml in registry_xml.iterfind("extensions/extension"):
            extension_number = int(extension_xml.attrib["number"])
            for require_xml in extension_xml.iterfind("require"):
                if not self.check_api_attr(require_xml):
                    continue
                for enum_xml in require_xml.iterfind("enum"):
                    if not self.check_api_attr(enum_xml):
                        continue
                    add_group_entry(
                        group=enum_dict[enum_name] if (enum_name := enum_xml.attrib.get("extends")) is not None else self.constants,
                        enum_xml=enum_xml,
                        extension_number=extension_number
                    )

        for result_field in enum_dict["VkResult"].iter_sorted_objs():
            self.return_codes.append_obj(result_field)

    def write_registry(
        self: Self,
        vulkan_py: TextIO
    ) -> None:
        vulkan_py.write("\n\n## return codes\n")
        vulkan_py.write("RETURN_CODES.update({\n")
        for return_code in self.return_codes.iter_sorted_objs():
            vulkan_py.write(f"    {return_code.value_int}: \"{return_code.name}\",\n")
        vulkan_py.write("})\n")

        vulkan_py.write("\n\n## defines\n")
        self.defines.write(vulkan_py)
        self.defines.aliases.write_aliases(vulkan_py)

        vulkan_py.write("\n\n## constants\n")
        self.constants.write(vulkan_py)
        self.constants.aliases.write_aliases(vulkan_py)

        vulkan_py.write("\n\n## enums\n")
        self.enums.write(vulkan_py)
        vulkan_py.write("\n\n")
        self.enums.aliases.write_aliases(vulkan_py)

        vulkan_py.write("\n\n## flags\n")
        self.flags.write(vulkan_py)
        vulkan_py.write("\n\n")
        self.flags.aliases.write_aliases(vulkan_py)
        #self.structs.write(vulkan_py)

        # TODO: Generate __all__



#def write_vulkan_py(
#    vulkan_py: TextIO,
#    registry_xml: etree.Element
#) -> None:
#    defines = Defines()
#    for type_xml in registry_xml.iterfind("types/type"):
#        if not check_api_attr(type_xml):
#            continue
#        if type_xml.attrib.get("category") != "define":
#            continue
#        defines.read_code_from_type_xml(type_xml)
#    defines.write(vulkan_py)

#    # TODO: read enums from types/type[@category="enum"]
#    enums = Enums()
#    for type_xml in registry_xml.iterfind("types/type"):
#        if not check_api_attr(type_xml):
#            continue
#        if type_xml.attrib.get("category") != "define":
#            continue
#        enums.read_enum_from_type_xml(type_xml)
#    for enums_xml in registry_xml.iterfind("enums"):
#        enums.read_enum_from_enums_xml(enums_xml)
#    for feature_xml in registry_xml.iterfind("feature"):
#        if not check_api_attr(feature_xml):
#            continue
#        for enum_xml in feature_xml.iterfind("require/enum"):
#            if not check_api_attr(enum_xml):
#                continue
#            enums.get_enum(enum_xml.attrib.get("extends", "")).read_member_from_enum_xml(enum_xml, None)
#    for extension_xml in registry_xml.iterfind("extensions/extension"):
#        extension_number = int(extension_xml.attrib["number"])
#        for require_xml in extension_xml.iterfind("require"):
#            if not check_api_attr(require_xml):
#                continue
#            for enum_xml in require_xml.iterfind("enum"):
#                if not check_api_attr(enum_xml):
#                    continue
#                enums.get_enum(enum_xml.attrib.get("extends", "")).read_member_from_enum_xml(enum_xml, extension_number)
#    enums.write(vulkan_py)

#    structs = Structs()
#    for type_xml in registry_xml.iterfind("types/type"):
#        if not check_api_attr(type_xml):
#            continue
#        if type_xml.attrib.get("category") != "struct":
#            continue
#        structs.read_struct_from_type_xml(type_xml)
#    structs.write(vulkan_py)


def main() -> None:
    vk_xml = pathlib.Path("Vulkan-Docs/xml/vk.xml")
    generated_dir = pathlib.Path("generated")
    generated_dir.mkdir(exist_ok=True)

    with generated_dir.joinpath("_vulkan.py").open("w") as vulkan_py:
        vulkan_py.write(pathlib.Path("preamble.py").read_text())
        registry = Registry()
        registry.read_registry(registry_xml=etree.parse(vk_xml).getroot())
        registry.write_registry(vulkan_py)
        #write_vulkan_py(
        #    vulkan_py=vulkan_py,
        #    registry_xml=etree.parse(vk_xml).getroot()
        #)


if __name__ == "__main__":
    main()
