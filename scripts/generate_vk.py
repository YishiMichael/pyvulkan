import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    Self,
    TextIO
)


class Obj:
    __slots__ = ()

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        pass


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

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"{self.name} = {self.alias}\n")


class Macro(Obj):
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
        macro_str: str
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

        macro_str = "".join(filter(None, (
            format_line(line)
            for line in macro_str.splitlines()
        ))).strip()

        if (match := re.fullmatch(r"#define (\w+) (\d+)", macro_str)) is not None:
            # A number.
            name = match.group(1)
            value = match.group(2)
            return f"{name} = {value}"
        if (match := re.fullmatch(r"#define (\w+) (\w+)\(((?:\w+, )*\w+)\)", macro_str)) is not None:
            # A number from a macro function call.
            name = match.group(1)
            func_name = match.group(2)
            args = tuple(arg_match.group() for arg_match in re.finditer(r"\w+", match.group(3)))
            return f"{name} = {func_name}({", ".join(args)})"
        if (match := re.fullmatch(r"#define (\w+)\(((?:\w+, )*\w+)\) \((.*)\)", macro_str)) is not None:
            # A macro function.
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
            return "\n".join((
                f"def {name}(",
                *(f"    {arg}: int," for  arg in args),
                ") -> int:",
                f"    return {result}"
            ))
        return None


    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"{self.code}\n")


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

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"{self.name} = {self.value_code}\n")


class Type(Obj):
    __slots__ = ("name",)

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__()
        self.name: str = name


class ElementaryType(Type):
    __slots__ = ("py_type",)

    def __init__(
        self: Self,
        name: str,
        py_type: type
    ) -> None:
        super().__init__(name)
        self.py_type: type = py_type


class ElementaryTypedef(Type):
    __slots__ = ("elementary_type",)

    def __init__(
        self: Self,
        name: str,
        elementary_type: ElementaryType
    ) -> None:
        super().__init__(name)
        self.name: str = name
        self.elementary_type: ElementaryType = elementary_type

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"{self.name} = {self.elementary_type.py_type.__name__}\n")


class ExternalType(Type):
    __slots__ = ()

    #def write_py(
    #    self: Self,
    #    file: TextIO
    #) -> None:
    #    file.write(f"{self.name} = Never\n")


class Handle(Type):
    __slots__ = ()

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"class {self.name}(VulkanCData):\n")
        file.write(f"    __slots__ = ()\n")


class Enum(Type):
    __slots__ = (
        "fields",
        "aliases"
    )

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__(name)
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

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"class {self.name}(Enum):\n")
        if not self.fields and not self.aliases:
            file.write("    pass\n")
            return
        for field_name, field_value in self.fields.items():
            file.write(f"    {field_name} = {field_value}\n")
        for field_name, alias in self.aliases.items():
            file.write(f"    {field_name} = {alias}\n")


class Flag(Type):
    __slots__ = (
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
        super().__init__(name)
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

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"class {self.name}(Flag):\n")
        if (bits_enum := self.bits_enum) is None or (not bits_enum.fields and not bits_enum.aliases):
            file.write("    pass\n")
            return
        for field_name, field_value in bits_enum.fields.items():
            file.write(f"    {field_name} = 0x{field_value:0{self.bitwidth // 4}X}\n")
        for field_name, alias in bits_enum.aliases.items():
            file.write(f"    {field_name} = {alias}\n")


class Registry:
    __slots__ = (
        "objs",
        "type_dict"
    )

    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        self.objs: list[Obj] = []
        self.type_dict: dict[str, Type] = {
            name: ElementaryType(
                name=name,
                py_type=py_type
            )
            for name, py_type in (
                ("int", int),
                ("size_t", int),
                ("float", float),
                ("double", float),
                ("char", str),
                ("int8_t", int),
                ("int16_t", int),
                ("int32_t", int),
                ("int64_t", int),
                ("uint8_t", int),
                ("uint16_t", int),
                ("uint32_t", int),
                ("uint64_t", int),
            )
            # void, char
        }

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
        type_obj: Type
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
    ) -> Type:
        return self.type_dict[type_name]

    def get_elementary_type(
        self: Self,
        elementary_type_name: str
    ) -> ElementaryType:
        elementary_type = self.get_type(elementary_type_name)
        assert isinstance(elementary_type, ElementaryType)
        return elementary_type

    def get_elementary_typedef(
        self: Self,
        elementary_typedef_name: str
    ) -> ElementaryTypedef:
        elementary_typedef = self.get_type(elementary_typedef_name)
        assert isinstance(elementary_typedef, ElementaryTypedef)
        return elementary_typedef

    def get_enum(
        self: Self,
        enum_name: str
    ) -> Enum:
        enum = self.get_type(enum_name)
        assert isinstance(enum, Enum)
        return enum

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
        if alias is not None:
            enum.read_alias(name, alias)
            return
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
                    external_type = ExternalType(name)
                    self.add_type(name, external_type)
                    self.append_obj(external_type)

                case "define":
                    if (code := Macro.build_code(
                        macro_str="".join(type_xml.itertext())
                    )) is None:
                        continue
                    macro = Macro(
                        code=code
                    )
                    self.append_obj(macro)

                case "basetype":
                    basetype = (
                        ElementaryTypedef(name, self.get_elementary_type(match.group(1)))
                        if (match := re.fullmatch(r"typedef (\w+) \w+;", "".join(type_xml.itertext()))) is not None
                        else ExternalType(name)
                    )
                    self.add_type(name, basetype)
                    self.append_obj(basetype)

                case "handle":
                    handle = Handle(name)
                    self.add_type(name, handle)
                    self.append_obj(handle)

                case "enum":
                    enum = Enum(name)
                    self.add_type(name, enum)
                    self.append_obj(enum)

                case "bitmask":
                    elementary_typedef = self.get_elementary_typedef(type_xml.findtext("type", ""))
                    assert (match := re.fullmatch(r"uint(\d+)_t", elementary_typedef.elementary_type.name)) is not None
                    flag = Flag(
                        name,
                        bitwidth=int(match.group(1)),
                        bits_enum_name=type_xml.attrib.get("requires") or type_xml.attrib.get("bitvalues")
                    )
                    self.add_type(name, flag)
                    self.append_obj(flag)

        for enums_xml in registry_xml.iterfind("enums"):
            enum = self.get_enum(enum_name) if self.has_type(enum_name := enums_xml.attrib["name"]) else None
            for enum_xml in enums_xml.iterfind("enum"):
                if not check_api_attr(enum_xml):
                    continue
                self.read_field_or_constant(enum, enum_xml, None)

        for feature_xml in registry_xml.iterfind("feature"):
            if not check_api_attr(feature_xml):
                continue
            for enum_xml in feature_xml.iterfind("require/enum"):
                if not check_api_attr(enum_xml):
                    continue
                enum = self.get_enum(enum_name) if (enum_name := enum_xml.attrib.get("extends")) is not None else None
                self.read_field_or_constant(enum, enum_xml, None)

        for extension_xml in registry_xml.iterfind("extensions/extension"):
            number = extension_xml.attrib.get("number")
            for require_xml in extension_xml.iterfind("require"):
                if not check_api_attr(require_xml):
                    continue
                for enum_xml in require_xml.iterfind("enum"):
                    if not check_api_attr(enum_xml):
                        continue
                    enum = self.get_enum(enum_name) if (enum_name := enum_xml.attrib.get("extends")) is not None else None
                    self.read_field_or_constant(enum, enum_xml, number)

        for flag in self.type_dict.values():
            if not isinstance(flag, Flag):
                continue
            if (bits_enum_name := flag.bits_enum_name) is None:
                continue
            flag.attach_bits_enum(self.get_enum(bits_enum_name))

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        for obj in self.objs:
            obj.write_py(file)

        file.write("\n")
        file.write("RETURN_CODES.update({\n")
        file.write("    result_field.value: result_field.name\n")
        file.write("    for result_field in VkResult\n")
        file.write("    if isinstance(result_field.value, int)\n")
        file.write("})\n")

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
        registry.write_py(vulkan_py)


if __name__ == "__main__":
    main()
