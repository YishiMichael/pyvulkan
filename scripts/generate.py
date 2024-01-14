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
    __slots__ = ("name",)

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__()
        self.name: str = name

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
    __slots__ = ("py_macro",)

    def __init__(
        self: Self,
        name: str,
        py_macro: str
    ) -> None:
        super().__init__(name)
        self.py_macro: str = py_macro

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

        if (match := re.fullmatch(r"#define (\w+) (\d+)", c_macro)) is not None:
            # A number.
            name = match.group(1)
            value = match.group(2)
            return f"{name} = {value}"
        if (match := re.fullmatch(r"#define (\w+) (\w+)\(((?:\w+, )*\w+)\)", c_macro)) is not None:
            # A number from a macro function call.
            name = match.group(1)
            func_name = match.group(2)
            args = tuple(arg_match.group() for arg_match in re.finditer(r"\w+", match.group(3)))
            return f"{name} = {func_name}({", ".join(args)})"
        if (match := re.fullmatch(r"#define (\w+)\(((?:\w+, )*\w+)\) \((.*)\)", c_macro)) is not None:
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
        file.write(f"{self.py_macro}\n")


class Constant(Macro):
    __slots__ = ("value_str",)

    def __init__(
        self: Self,
        name: str,
        value_str: str
    ) -> None:
        super().__init__(name, f"{name} = {value_str}")
        self.value_str: str = value_str

    @classmethod
    def parse_value(
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


#class Type(Obj):
#    __slots__ = ()


class TypeAlias(Obj):
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
        #file.write(f"{self.name} = {self.alias}\n")


class Declaration(Obj):
    __slots__ = (
        "cdecl",
        "base_type_name",
        "array_size_names",
        "pointer_count",
        "is_nonconst_pointer",
        "base_type",
        "array_sizes"
    )

    def __init__(
        self: Self,
        cdecl: str
        #base: Obj,
        #pointer_count: int,
        #array_sizes: tuple[int, ...]
    ) -> None:
        name, base_type_name, array_size_names, pointer_count, is_nonconst_pointer = type(self).parse_cdecl(cdecl)
        super().__init__(name)
        self.cdecl: str = cdecl
        self.base_type_name: str = base_type_name
        self.array_size_names: tuple[str, ...] = array_size_names
        self.pointer_count: int = pointer_count
        self.is_nonconst_pointer: bool = is_nonconst_pointer
        self.base_type: Obj = NotImplemented
        self.array_sizes: tuple[int, ...] = NotImplemented

    @classmethod
    def parse_cdecl(
        cls: type[Self],
        cdecl: str
    ) -> tuple[str, str, tuple[str, ...], int, bool]:
        assert (match := re.fullmatch(
            r"\s*(\bconst\b)?\s*(?:\bstruct\b)?\s*(\b\w+\b)\s*(\*)?\s*(\bconst\b)?\s*(\*)?\s*(\b\w+\b)?((?:\[\w+\])*)(?:\s*:\s*\d+)?\s*",
            cdecl
        )) is not None
        name = name_group if (name_group := match.group(6)) is not None else ""
        base_type_name = match.group(2)
        array_size_names = tuple(
            array_size_name_match.group()
            for array_size_name_match in re.finditer(r"\w+", match.group(7))
        )
        pointer_count = len(array_size_names) + int(match.group(3) is not None) + int(match.group(5) is not None)
        is_nonconst_pointer = any((
            match.group(1) is None and match.group(3) is not None,
            match.group(4) is None and match.group(5) is not None
        ))
        return name, base_type_name, array_size_names, pointer_count, is_nonconst_pointer


class Signature(Obj):
    __slots__ = (
        #"return_cdecl",
        #"arg_names",
        #"arg_cdecls",
        "return_declaration",
        "arg_declarations"
    )

    def __init__(
        self: Self,
        name: str,
        return_cdecl: str,
        #arg_names: tuple[str, ...],
        arg_cdecls: tuple[str, ...]
    ) -> None:
        super().__init__(name)
        #self.return_cdecl: str = return_cdecl
        #self.arg_names: tuple[str, ...] = arg_names
        #self.arg_cdecls: tuple[str, ...] = arg_cdecls
        self.return_declaration: Declaration = Declaration(return_cdecl)
        self.arg_declarations: tuple[Declaration, ...] = tuple(
            Declaration(arg_cdecl)
            for arg_cdecl in arg_cdecls
        )


class ElementaryType(Obj):
    __slots__ = ("py_type",)

    def __init__(
        self: Self,
        name: str,
        py_type: type
    ) -> None:
        super().__init__(name)
        self.py_type: type = py_type


class ElementaryTypedef(Obj):
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


class ExternalType(Obj):
    __slots__ = ()

    #def write_py(
    #    self: Self,
    #    file: TextIO
    #) -> None:
    #    file.write(f"{self.name} = Never\n")


class Enum(Obj):
    __slots__ = (
        "fields",
        "aliases",
        "long_bitwidth"
    )

    def __init__(
        self: Self,
        name: str
    ) -> None:
        super().__init__(name)
        self.fields: dict[str, int] = {}
        self.aliases: dict[str, str] = {}
        self.long_bitwidth: bool | None = None

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
            # Skip if duplicated.
            assert self.fields[field_name] == field_value
            return
        self.fields[field_name] = field_value

    def read_alias(
        self: Self,
        field_name: str,
        alias: str
    ) -> None:
        if field_name in self.aliases:
            # Skip if duplicated.
            assert self.aliases[field_name] == alias
            return
        self.aliases[field_name] = alias

    def write_c(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        if self.long_bitwidth is None:
            if self.fields or self.aliases:
                file.write(f"typedef enum {{\n")
                for field_name, field_value in self.fields.items():
                    file.write(f"    {field_name} = {field_value},\n")
                for field_name, alias in self.aliases.items():
                    file.write(f"    {field_name} = {alias},\n")
                file.write(f"}} {self.name};\n")
            else:
                file.write(f"typedef uint32_t {self.name};\n")
        elif not self.long_bitwidth:
            if self.fields or self.aliases:
                file.write(f"typedef enum {{\n")
                for field_name, field_value in self.fields.items():
                    file.write(f"    {field_name} = 0x{field_value:08X},\n")
                for field_name, alias in self.aliases.items():
                    file.write(f"    {field_name} = {alias},\n")
                file.write(f"}} {self.name};\n")
            else:
                file.write(f"typedef uint32_t {self.name};\n")
        else:
            file.write(f"typedef VkFlags64 {self.name};\n")
            for field_name, field_value in self.fields.items():
                file.write(f"static const {self.name} {field_name} = 0x{field_value:016X}ULL;\n")
            for field_name, alias in self.aliases.items():
                file.write(f"static const {self.name} {field_name} = {alias};\n")

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        if self.fields or self.aliases:
            file.write(f"class {self.name}(Enum):\n")
            for field_name, field_value in self.fields.items():
                file.write(f"    {field_name} = {field_value}\n")
            for field_name, alias in self.aliases.items():
                file.write(f"    {field_name} = {alias}\n")
        else:
            file.write(f"class {self.name}(Enum):\n")
            file.write("    pass\n")


class Flag(Obj):
    __slots__ = (
        "long_bitwidth",
        "bitmask_enum_name",
        "bitmask_enum"
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
        self.bitmask_enum: Enum | None = NotImplemented

    def write_c(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        file.write(f"typedef {"VkFlags64" if self.long_bitwidth else "VkFlags"} {self.name};\n")

    def write_py(
        self: Self,
        file: TextIO
    ) -> None:
        file.write("\n")
        if (bitmask_enum := self.bitmask_enum) is not None and (bitmask_enum.fields or bitmask_enum.aliases):
            bitwidth = 64 if self.long_bitwidth else 32
            file.write(f"class {self.name}(Flag):\n")
            for field_name, field_value in bitmask_enum.fields.items():
                file.write(f"    {field_name} = 0x{field_value:0{bitwidth // 4}X}\n")
            for field_name, alias in bitmask_enum.aliases.items():
                file.write(f"    {field_name} = {alias}\n")
        else:
            file.write(f"class {self.name}(Flag):\n")
            file.write("    pass\n")


class Handle(Obj):
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


class Struct(Signature):
    __slots__ = ()

    def __init__(
        self: Self,
        name: str,
        #arg_names: tuple[str, ...],
        arg_cdecls: tuple[str, ...]
    ) -> None:
        super().__init__(
            name=name,
            return_cdecl="void",
            #arg_names=arg_names,
            arg_cdecls=arg_cdecls
        )


class Union(Signature):
    __slots__ = ()

    def __init__(
        self: Self,
        name: str,
        #arg_names: tuple[str, ...],
        arg_cdecls: tuple[str, ...]
    ) -> None:
        super().__init__(
            name=name,
            return_cdecl="void",
            #arg_names=arg_names,
            arg_cdecls=arg_cdecls
        )


class FunctionPointer(Signature):
    __slots__ = ()


class Command(Signature):
    __slots__ = ()


class Registry:
    __slots__ = ("obj_dict",)

    def __init__(
        self: Self
    ) -> None:
        super().__init__()
        obj_dict: dict[str, Obj] = {
            name: ExternalType(name)
            for name in (
                "void",
                "char"
            )
        }
        obj_dict.update(
            (name, ElementaryType(
                name=name,
                py_type=py_type
            ))
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
        )
        #self.objs: list[Obj] = []
        self.obj_dict: dict[str, Obj] = obj_dict

    #def append_obj(
    #    self: Self,
    #    obj: Obj
    #) -> None:
    #    self.objs.append(obj)

    def add_obj(
        self: Self,
        type_obj: Obj
    ) -> None:
        assert type_obj.name not in self.obj_dict
        self.obj_dict[type_obj.name] = type_obj

    def has_obj(
        self: Self,
        type_name: str
    ) -> bool:
        return type_name in self.obj_dict

    def get_obj(
        self: Self,
        type_name: str
    ) -> Obj:
        return self.obj_dict[type_name]

    def get_constant(
        self: Self,
        constant_name: str
    ) -> Constant:
        constant = self.get_obj(constant_name)
        assert isinstance(constant, Constant)
        return constant

    def get_elementary_type(
        self: Self,
        elementary_type_name: str
    ) -> ElementaryType:
        elementary_type = self.get_obj(elementary_type_name)
        assert isinstance(elementary_type, ElementaryType)
        return elementary_type

    def get_enum(
        self: Self,
        enum_name: str
    ) -> Enum:
        enum = self.get_obj(enum_name)
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
                self.add_obj(Constant(
                    name=name,
                    value_str=alias
                ))
                return
            if (value_str := Constant.parse_value(
                value=enum_xml.attrib.get("value")
            )) is None:
                return
            self.add_obj(Constant(
                name=name,
                value_str=value_str
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

        for comment_xml in registry_xml.iter("comment"):
            comment_xml.clear()

        for type_xml in registry_xml.iterfind("types/type"):
            if not check_api_attr(type_xml):
                continue

            name = name_text if (name_text := type_xml.findtext("name")) is not None else type_xml.attrib["name"]
            if (alias := type_xml.attrib.get("alias")) is not None:
                self.add_obj(TypeAlias(
                    name,
                    alias=alias
                ))
                continue

            match type_xml.attrib.get("category"):
                case None:
                    if self.has_obj(name):
                        continue
                    self.add_obj(ExternalType(name))
                    #self.append_obj(external_type)

                case "include":
                    pass

                case "define":
                    if (py_macro := Macro.parse_c_macro(
                        c_macro="".join(type_xml.itertext())
                    )) is None:
                        continue
                    self.add_obj(Macro(
                        name,
                        py_macro=py_macro
                    ))

                case "basetype":
                    self.add_obj(
                        ElementaryTypedef(name, self.get_elementary_type(match.group(1)))
                        if (match := re.fullmatch(r"typedef (\w+) \w+;", "".join(type_xml.itertext()))) is not None
                        else ExternalType(name)
                    )
                    #self.append_obj(elementary_typedef)

                case "enum":
                    self.add_obj(Enum(name))
                    #self.append_obj(enum)

                case "bitmask":
                    self.add_obj(Flag(
                        name,
                        long_bitwidth=type_xml.findtext("type") == "VkFlags64",
                        bitmask_enum_name=type_xml.attrib.get("requires") or type_xml.attrib.get("bitvalues")
                    ))
                    #self.append_obj(flag)

                case "handle":
                    self.add_obj(Handle(name))
                    #self.append_obj(handle)

                case "struct":
                    self.add_obj(Struct(
                        name,
                        arg_cdecls=tuple(
                            "".join(member_xml.itertext())
                            for member_xml in type_xml.iterfind("member")
                        )
                    ))
                    #self.append_obj(struct)

                case "union":
                    self.add_obj(Union(
                        name,
                        arg_cdecls=tuple(
                            "".join(member_xml.itertext())
                            for member_xml in type_xml.iterfind("member")
                        )
                    ))
                    #self.append_obj(union)

                case "funcpointer":
                    assert (match := re.fullmatch(
                        r"typedef (.*) \(VKAPI_PTR \*\w+\)\((.*)\);",
                        "".join(type_xml.itertext()),
                        flags=re.DOTALL
                    )) is not None
                    assert (args_cdecl := match.group(2)) is not None
                    self.add_obj(FunctionPointer(
                        name,
                        return_cdecl=match.group(1),
                        arg_cdecls=tuple(args_cdecl.split(","))
                    ))
                    #self.append_obj(function_pointer)

                case _ as category:
                    raise ValueError(f"Unexpected category name: {category}")

        for enums_xml in registry_xml.iterfind("enums"):
            enum = self.get_enum(enum_name) if self.has_obj(enum_name := enums_xml.attrib["name"]) else None
            if enum is not None:
                enum.long_bitwidth = (
                    enums_xml.attrib.get("bitwidth") == "64"
                    if enums_xml.attrib.get("type") == "bitmask"
                    else None
                )
            for enum_xml in enums_xml.iterfind("enum"):
                if not check_api_attr(enum_xml):
                    continue
                self.read_field_or_constant(enum, enum_xml, None)

        for command_xml in registry_xml.iterfind("commands/command"):
            if not check_api_attr(command_xml):
                continue
            if (alias := command_xml.attrib.get("alias")) is not None:
                self.add_obj(TypeAlias(
                    command_xml.attrib["name"],
                    alias=alias
                ))
                continue
            assert (proto_xml := command_xml.find("proto")) is not None 
            assert (name := proto_xml.findtext("name")) is not None
            self.add_obj(Command(
                name=name,
                return_cdecl="".join(proto_xml.itertext()).removesuffix(name),
                arg_cdecls=tuple(
                    "".join(param_xml.itertext())
                    for param_xml in command_xml.iterfind("param")
                )
            ))

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

        for flag in self.obj_dict.values():
            if not isinstance(flag, Flag):
                continue
            if (bitmask_enum_name := flag.bitmask_enum_name) is None:
                bitmask_enum = None
            else:
                bitmask_enum = self.get_enum(bitmask_enum_name)
                assert bitmask_enum.name == flag.bitmask_enum_name
                assert bitmask_enum.long_bitwidth is flag.long_bitwidth
            flag.bitmask_enum = bitmask_enum

        for signature in self.obj_dict.values():
            if not isinstance(signature, Signature):
                continue
            for declaration in (signature.return_declaration, *signature.arg_declarations):
                declaration.base_type = self.get_obj(declaration.base_type_name)
                declaration.array_sizes = tuple(
                    int(array_size_name)
                    if re.fullmatch(r"\d+", array_size_name)
                    else int(self.get_constant(array_size_name).value_str)
                    for array_size_name in declaration.array_size_names
                )

    def build_cdef(
        self: Self,
        cdef_path: pathlib.Path
    ) -> None:
        with cdef_path.open("w") as file:
            file.write("// Auto-generated C definitions\n")

            for obj in self.obj_dict.values():
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
        with pydef_path.open("w") as file:
            file.write(preamble_path.read_text())

            for obj in self.obj_dict.values():
                obj.write_py(file)

            file.write("\n")
            file.write("RETURN_CODES.update({\n")
            file.write("    result_field.value: result_field.name\n")
            file.write("    for result_field in VkResult\n")
            file.write("    if isinstance(result_field.value, int)\n")
            file.write("})\n")

            file.write("\n")
            file.write("__all__ = (\n")
            for obj in self.obj_dict.values():
                if isinstance(obj, ElementaryType | ExternalType):
                    continue
                file.write(f"    \"{obj.name}\",\n")
            file.write(")\n")


def main() -> None:
    this_dir = pathlib.Path()
    registry = Registry()
    for xml in (
        this_dir.joinpath("xml/video.xml"),
        this_dir.joinpath("xml/vk.xml")
    ):
        registry.read_registry(registry_xml=etree.parse(xml).getroot())

    generated_dir = this_dir.joinpath("generated")
    generated_dir.mkdir(exist_ok=True)
    cdef_path = generated_dir.joinpath("_vulkan.h")
    pydef_path = generated_dir.joinpath("_vulkan.py")
    ffi_path = generated_dir.joinpath("_vulkan_ffi.py")
    preamble_path = this_dir.joinpath("preamble.py")

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


if __name__ == "__main__":
    main()
