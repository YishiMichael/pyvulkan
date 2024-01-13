import argparse
import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    Self,
    TextIO
)

import cffi


class Obj:
    __slots__ = ()

    def write_c(
        self: Self,
        file: TextIO
    ) -> None:
        pass

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        pass


class Macro(Obj):
    __slots__ = ("pydef",)

    def __init__(
        self: Self,
        pydef: str
    ) -> None:
        super().__init__()
        self.pydef: str = pydef

    @classmethod
    def parse_pydef(
        cls: type[Self],
        cdef: str
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

        cdef = "".join(filter(None, (
            format_line(line)
            for line in cdef.splitlines()
        ))).strip()

        if (match := re.fullmatch(r"#define (\w+) (\d+)", cdef)) is not None:
            # A number.
            name = match.group(1)
            value = match.group(2)
            return f"{name} = {value}"
        if (match := re.fullmatch(r"#define (\w+) (\w+)\(((?:\w+, )*\w+)\)", cdef)) is not None:
            # A number from a macro function call.
            name = match.group(1)
            func_name = match.group(2)
            args = tuple(arg_match.group() for arg_match in re.finditer(r"\w+", match.group(3)))
            return f"{name} = {func_name}({", ".join(args)})"
        if (match := re.fullmatch(r"#define (\w+)\(((?:\w+, )*\w+)\) \((.*)\)", cdef)) is not None:
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

    @classmethod
    def parse_value_pydef(
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
        file.write(f"{self.pydef}\n")


class Type(Obj):
    __slots__ = ("name",)

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__()
        self.name: str = name


class TypeAlias(Type):
    __slots__ = ("alias",)

    def __init__(
        self: Self,
        name: str,
        alias: str
    ) -> None:
        super().__init__(name)
        self.alias: str = alias

    def write_c(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        #file.write(f"typedef {self.alias} {self.name};\n")

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"{self.name} = {self.alias}\n")


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

    def write_c(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"typedef {self.elementary_type.name} {self.name};\n")

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

    def write_c(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"typedef struct {self.name}_T *{self.name};\n")

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
        "aliases",
        "is_bitmask"
    )

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__(name)
        self.fields: dict[str, int] = {}
        self.aliases: dict[str, str] = {}
        self.is_bitmask: bool = False

    @classmethod
    def parse_field_value(
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
            # Skip if duplicate.
            assert self.fields[field_name] == field_value
            return
        self.fields[field_name] = field_value

    def read_alias(
        self: Self,
        field_name: str,
        alias: str
    ) -> None:
        if field_name in self.aliases:
            # Skip if duplicate.
            assert self.aliases[field_name] == alias
            return
        self.aliases[field_name] = alias

    def write_c(
        self: Self,
        file: TextIO
    ) -> None:
        if self.is_bitmask:
            return
        file.write("\n")
        if self.fields or self.aliases:
            file.write(f"typedef enum {{\n")
            for field_name, field_value in self.fields.items():
                file.write(f"    {field_name} = {field_value},\n")
            for field_name, alias in self.aliases.items():
                file.write(f"    {field_name} = {alias},\n")
            file.write(f"}} {self.name};\n")
        else:
            file.write(f"typedef uint32_t {self.name};\n")

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        if self.is_bitmask:
            return
        file.write("\n")
        file.write(f"class {self.name}(Enum):\n")
        if self.fields or self.aliases:
            for field_name, field_value in self.fields.items():
                file.write(f"    {field_name} = {field_value}\n")
            for field_name, alias in self.aliases.items():
                file.write(f"    {field_name} = {alias}\n")
        else:
            file.write("    pass\n")


class Flag(Type):
    __slots__ = (
        "long_bitwidth",
        "bitmask_enum",
        "bitmask_enum_name"
    )

    def __init__(
        self: Self,
        name: str,
        long_bitwidth: bool,
        bitmask_enum_name: str | None
    ) -> None:
        super().__init__(name)
        self.long_bitwidth: bool = long_bitwidth
        self.bitmask_enum_name: str | None = bitmask_enum_name
        self.bitmask_enum: Enum | None = None

    def attach_bitmask_enum(
        self: Self,
        bitmask_enum: Enum
    ) -> None:
        assert self.bitmask_enum is None
        assert bitmask_enum.name == self.bitmask_enum_name
        assert not bitmask_enum.is_bitmask
        self.bitmask_enum = bitmask_enum
        bitmask_enum.is_bitmask = True

    def write_c(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        if self.long_bitwidth:
            file.write(f"typedef VkFlags64 {self.name};\n")
            if (bitmask_enum := self.bitmask_enum) is not None:
                file.write(f"typedef VkFlags64 {bitmask_enum.name};\n")
                for field_name, field_value in bitmask_enum.fields.items():
                    file.write(f"static const {bitmask_enum.name} {field_name} = 0x{field_value:016X};\n")
                for field_name, alias in bitmask_enum.aliases.items():
                    file.write(f"static const {bitmask_enum.name} {field_name} = {alias};\n")
        else:
            file.write(f"typedef VkFlags {self.name};\n")
            if (bitmask_enum := self.bitmask_enum) is not None:
                if bitmask_enum.fields or bitmask_enum.aliases:
                    file.write(f"typedef enum {{\n")
                    for field_name, field_value in bitmask_enum.fields.items():
                        file.write(f"    {field_name} = 0x{field_value:08X},\n")
                    for field_name, alias in bitmask_enum.aliases.items():
                        file.write(f"    {field_name} = {alias},\n")
                    file.write(f"}} {bitmask_enum.name};\n")
                else:
                    file.write(f"typedef VkFlags {bitmask_enum.name};\n")
        #if (bitmask_enum := self.bitmask_enum) is None or (not bitmask_enum.fields and not bitmask_enum.aliases):
        #    file.write(f"typedef {"VkFlags64" if self.long_bitwidth else "VkFlags"} {self.name};\n")
        #    return
        #file.write(f"typedef enum {{\n")
        #for field_name, field_value in self.fields.items():
        #    file.write(f"    {field_name} = {field_value},\n")
        #for field_name, alias in self.aliases.items():
        #    file.write(f"    {field_name} = {alias},\n")
        #file.write(f"}} {self.name};\n")

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"class {self.name}(Flag):\n")
        if (bitmask_enum := self.bitmask_enum) is not None:
            if bitmask_enum.fields or bitmask_enum.aliases:
                bitwidth = 64 if self.long_bitwidth else 32
                for field_name, field_value in bitmask_enum.fields.items():
                    file.write(f"    {field_name} = 0x{field_value:0{bitwidth // 4}X}\n")
                for field_name, alias in bitmask_enum.aliases.items():
                    file.write(f"    {field_name} = {alias}\n")
            else:
                file.write("    pass\n")
            file.write(f"{bitmask_enum.name} = {self.name}\n")
        else:
            file.write("    pass\n")


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
                self.append_obj(Macro(
                    pydef=f"{name} = {alias}"
                ))
                return
            if (value_pydef := Macro.parse_value_pydef(
                value=enum_xml.attrib.get("value")
            )) is None:
                return
            self.append_obj(Macro(
                pydef=f"{name} = {value_pydef}"
            ))
            return
        if alias is not None:
            enum.read_alias(name, alias)
            return
        enum.read_field(name, Enum.parse_field_value(
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
                self.append_obj(TypeAlias(
                    name=name,
                    alias=alias
                ))
                continue

            match type_xml.attrib.get("category"):
                case None:
                    if self.has_type(name):
                        continue
                    external_type = ExternalType(name)
                    self.add_type(name, external_type)
                    self.append_obj(external_type)

                case "define":
                    if (pydef := Macro.parse_pydef(
                        cdef="".join(type_xml.itertext())
                    )) is None:
                        continue
                    macro = Macro(
                        pydef=pydef
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

                case "funcpointer":
                    pass

                case "enum":
                    enum = Enum(name)
                    self.add_type(name, enum)
                    self.append_obj(enum)

                case "bitmask":
                    flag = Flag(
                        name,
                        long_bitwidth=type_xml.findtext("type") == "VkFlags64",
                        bitmask_enum_name=type_xml.attrib.get("requires") or type_xml.attrib.get("bitvalues")
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
            if (bitmask_enum_name := flag.bitmask_enum_name) is None:
                continue
            flag.attach_bitmask_enum(self.get_enum(bitmask_enum_name))

    def build_cdef(
        self: Self,
        cdef_path: pathlib.Path
    ) -> None:
        with cdef_path.open("w", newline="\n") as file:
            file.write("// Auto-generated C definitions\n")

            for obj in self.objs:
                obj.write_c(file)

    def build_ffi(
        self: Self,
        ffi_path: pathlib.Path,
        cdef_path: pathlib.Path
    ) -> None:
        ffi = cffi.FFI()
        ffi.cdef(cdef_path.read_text(), override=True)
        ffi.set_source(str(ffi_path.with_suffix("")).replace("\\", "."), None)
        ffi.compile()

    def build_pydef(
        self: Self,
        pydef_path: pathlib.Path,
        preamble_path: pathlib.Path
    ) -> None:
        with pydef_path.open("w", newline="\n") as file:
            file.write(preamble_path.read_text())

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
    here = pathlib.Path()
    registry = Registry()
    for xml in (
        here.joinpath("xml/video.xml"),
        here.joinpath("xml/vk.xml")
    ):
        registry.read_registry(registry_xml=etree.parse(xml).getroot())

    generated_dir = here.joinpath("generated")
    generated_dir.mkdir(exist_ok=True)
    cdef_path = generated_dir.joinpath("_vulkan.h")
    pydef_path = generated_dir.joinpath("_vulkan.py")
    ffi_path = generated_dir.joinpath("_vulkan_ffi.py")
    preamble_path = here.joinpath("preamble.py")

    parser = argparse.ArgumentParser()
    parser.add_argument("mode", choices=("all", "cdef", "ffi", "pydef"))
    match parser.parse_args().mode:
        case "all":
            registry.build_cdef(cdef_path)
            registry.build_ffi(ffi_path, cdef_path)
            registry.build_pydef(pydef_path, preamble_path)

        case "cdef":
            registry.build_cdef(cdef_path)

        case "ffi":
            registry.build_cdef(cdef_path)
            registry.build_ffi(ffi_path, cdef_path)

        case "pydef":
            registry.build_pydef(pydef_path, preamble_path)

    #with (
    #    generated_dir.joinpath("_vulkan.h").open("w", newline="\n") as vulkan_h,
    #    generated_dir.joinpath("_vulkan.py").open("w", newline="\n") as vulkan_py
    #):
    #    vulkan_py.write(pathlib.Path("preamble.py").read_text())
    #    registry.write_c(vulkan_h)
    #    registry.write_py(vulkan_py)


if __name__ == "__main__":
    main()
