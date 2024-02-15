from __future__ import annotations

import argparse
import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
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

    #@property
    #def obj(
    #    self: Self
    #) -> ObjT:
    #    return self._obj

    def mark_requirement(
        self: Self,
        batch_tag: str | None,
        tag: str | None,
        hidden: bool
        #platform_protect: str,
        #protect: str
    ) -> None:
        match batch_tag:
            case "require":
                if self.required:
                    #print(self.xml.tag, self.xml.attrib)
                    assert self.tag == tag
                    assert self.hidden == hidden
                    #assert self.label == label
                    #assert self.platform_protect == platform_protect
                    #assert self.protect == protect
                    return
                self.required = True
            case "remove":
                self.removed = True
            case _:
                return
        self.tag = tag
        self.hidden = hidden
        #self.platform_protect = platform_protect
        #self.protect = protect

    def check_requirement(
        self: Self
    ) -> bool:
        return self.required and not self.removed and not self.hidden


class Obj:
    __slots__ = ()

    #def __init__(
    #    self: Self
    #) -> None:
    #    super().__init__()
    #    self.label_dict: dict[str, Label] = {}
    #    #self.aliases: list[str] = []
    #    #self.platform_protect: str = ""
    #    #self.protect: str = ""

    #def add_alias(
    #    self: Self,
    #    name: str
    #) -> None:
    #    self.aliases.append(name)

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

    #def write_binding_with_protects(
    #    self: Self,
    #    module_cpp: TextIO
    #) -> None:
    #    if not self.required or self.removed:
    #        return
    #    if self.platform_protect:
    #        module_cpp.write(f"""#ifdef {self.platform_protect}""")
    #    if self.protect:
    #        module_cpp.write(f"""#ifdef {self.protect}""")
    #    self.write_binding(module_cpp)
    #    if self.protect:
    #        module_cpp.write(f"""#endif""")
    #    if self.platform_protect:
    #        module_cpp.write(f"""#endif""")


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
        #self._alias_dict: dict[str, str] = {}

    #def empty(
    #    self: Self
    #) -> bool:
    #    return not self._dict

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
        #child = self._child_dict[aliased_name]
        #assert name not in child.label_dict
        #child.label_dict[name] = Label()
        #assert name not in self._child_dict
        #self._child_dict[name] = child


#class Obj:
#    __slots__ = (
#        "name",
#        "requires"
#    )

#    def __init__(
#        self: Self,
#        name: str,
#        requires: set[str] | None = None
#    ) -> None:
#        super().__init__()
#        self.name: str = name
#        self.requires: set[str] | None = requires

#    def write_cdef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        pass

#    def write_pydef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        pass


#class Alias(Obj):
#    __slots__ = ("alias",)

#    def __init__(
#        self: Self,
#        name: str,
#        alias: str
#    ) -> None:
#        super().__init__(
#            name=name,
#            requires={alias}
#        )
#        self.alias: str = alias

#    def write_cdef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        file.write("\n")
#        file.write(f"typedef {self.alias} {self.name};\n")

#    def write_pydef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        pass
#        #file.write("\n")
#        #file.write(f"{self.name} = {self.alias}\n")


class Macro(Obj):
    __slots__ = (
        #"cmacro",
        "pymacro",
    )

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

        # A macro alias.
        #if (match := re.fullmatch(r"\w+", value)) is not None:
        #    return f"{name} = {value}"

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

    #def write_cdef(
    #    self: Self,
    #    file: TextIO
    #) -> None:
    #    if not self.pymacro:
    #        #file.write(f"{self.name} = None\n")
    #        return
    #    file.write("\n")
    #    file.write(f"{self.cmacro}\n")

    def write_pydef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        if self.pymacro is None:
            #file.write(f"{self.name} = None\n")
            return
        file.write("\n")
        file.write(f"{self.pymacro}\n")


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
        #name: str,
        return_cdecl: str,
        arg_cdecls: tuple[str, ...]
    ) -> None:
        #return_declaration = Declaration(return_cdecl)
        #arg_declarations = tuple(
        #    Declaration(arg_cdecl)
        #    for arg_cdecl in arg_cdecls
        #)
        super().__init__(
            #name=name
            #requires={
            #    return_declaration.base_type_name,
            #    *(arg_declaration.base_type_name for arg_declaration in arg_declarations)
            #}
        )
        self.return_declaration: Declaration = Declaration(return_cdecl)
        self.arg_declarations: tuple[Declaration, ...] = tuple(
            Declaration(arg_cdecl)
            for arg_cdecl in arg_cdecls
        )


class ElementaryType(Obj):
    __slots__ = ("py_type",)

    def __init__(
        self: Self,
        #name: str,
        py_type: str
    ) -> None:
        super().__init__(
            #name=name
        )
        self.py_type: str = py_type


#class ElementaryTypedef(Obj):
#    __slots__ = ("elementary_type",)

#    def __init__(
#        self: Self,
#        name: str,
#        elementary_type: ElementaryType
#    ) -> None:
#        super().__init__(
#            name=name
#            #requires={elementary_type.name}
#        )
#        #self.name: str = name
#        self.elementary_type: ElementaryType = elementary_type

#    def write_cdef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        file.write("\n")
#        file.write(f"typedef {self.elementary_type.name} {self.name};\n")

#    def write_pydef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        file.write("\n")
#        file.write(f"{self.name} = {self.elementary_type.py_type}\n")


class ExternalType(Obj):
    __slots__ = ()

    #def __init__(
    #    self: Self,
    #    name: str
    #) -> None:
    #    super().__init__(
    #        name=name
    #    )

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef struct {label.name}_T *{label.name};\n")

    #def write_pydef(
    #    self: Self,
    #    file: TextIO
    #) -> None:
    #    file.write(f"{self.name} = Never\n")


class ExternalInclude(Obj):
    __slots__ = ()


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
        if cvalue.isdigit() or cvalue.isidentifier():
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
    #    name: str
    #) -> None:
    #    super().__init__(
    #        name=name
    #    )


class Enums(Container[Enum]):
    __slots__ = (
        "bitmask",
        "long_bitwidth"
        #"enum_dict",
        #"alias_dict"
    )

    def __init__(
        self: Self
        #name: str
    ) -> None:
        super().__init__(
            #name=name
        )
        self.bitmask: bool = False
        self.long_bitwidth: bool = False
        #self.enum_dict: dict[str, Enum] = {}
        #self.alias_dict: dict[str, str] = {}

    #@classmethod
    #def parse_field_value(
    #    cls: type[Self],
    #    value: str | None,
    #    bitpos: str | None,
    #    offset: str | None,
    #    extnumber: str | None,
    #    direction: str | None,
    #    number: str | None
    #) -> int:
    #    if value is not None:
    #        return int(value, base=16 if value.startswith("0x") else 10)
    #    if bitpos is not None:
    #        return 1 << int(bitpos)
    #    if offset is not None:
    #        if extnumber is not None:
    #            number = extnumber
    #        else:
    #            assert number is not None
    #        sign = -1 if direction == "-" else 1
    #        return sign * (1000000000 + (int(number) - 1) * 1000 + int(offset))
    #    raise ValueError

    #def read_field(
    #    self: Self,
    #    field_name: str,
    #    field_value: int
    #) -> None:
    #    if field_name in self.fields:
    #        # Skip if duplicated.
    #        assert self.fields[field_name] == field_value
    #        return
    #    self.fields[field_name] = field_value

    #def read_alias(
    #    self: Self,
    #    field_name: str,
    #    alias: str
    #) -> None:
    #    if field_name in self.aliases:
    #        # Skip if duplicated.
    #        assert self.aliases[field_name] == alias
    #        return
    #    self.aliases[field_name] = alias

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        enum_names = tuple(
            enum_label.name
            for _, enum_label in self.iter_filtered_children_items()
        )
        file.write("\n")
        if self.long_bitwidth:
            file.write(f"typedef VkFlags64 {label.name};\n")
            for enum_name in enum_names:
                file.write(f"static const {label.name} {enum_name};\n")
            return
        if not enum_names:
            file.write(f"typedef uint32_t {label.name};\n")
            return
        file.write(f"typedef enum {{\n")
        for enum_name in enum_names:
            file.write(f"    {enum_name} = ...,\n")  # TODO: trailing comma
        file.write(f"}} {label.name};\n")
        #if not self.bitmask:
        #    if self.fields or self.aliases:
        #        file.write(f"typedef enum {{\n")
        #        for field_name, field_value in self.fields.items():
        #            file.write(f"    {field_name} = {field_value},\n")
        #        for field_name, alias in self.aliases.items():
        #            file.write(f"    {field_name} = {alias},\n")
        #        file.write(f"}} {self.name};\n")
        #    else:
        #        file.write(f"typedef uint32_t {self.name};\n")
        #elif not self.long_bitwidth:
        #    if self.fields or self.aliases:
        #        file.write(f"typedef enum {{\n")
        #        for field_name, field_value in self.fields.items():
        #            file.write(f"    {field_name} = 0x{field_value:08X},\n")
        #        for field_name, alias in self.aliases.items():
        #            file.write(f"    {field_name} = {alias},\n")
        #        file.write(f"}} {self.name};\n")
        #    else:
        #        file.write(f"typedef uint32_t {self.name};\n")
        #else:
        #    file.write(f"typedef VkFlags64 {self.name};\n")
        #    for field_name, field_value in self.fields.items():
        #        file.write(f"static const {self.name} {field_name} = 0x{field_value:016X}ULL;\n")
        #    for field_name, alias in self.aliases.items():
        #        file.write(f"static const {self.name} {field_name} = {alias};\n")

    def write_pydef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        enum_names = tuple(
            enum_label.name
            for _, enum_label in self.iter_filtered_children_items()
        )
        file.write("\n")
        file.write(f"class {label.name}({"Flag" if self.bitmask else "Enum"}):\n")
        if not enum_names:
            file.write("    pass\n")
            return
        for enum_name in enum_names:
            file.write(f"    {enum_name.removeprefix("VK_")} = lib.{enum_name}\n")
        #if self.long_bitwidth is None:
        #    if self.fields or self.aliases:
        #        file.write(f"class {self.name}(Enum):\n")
        #        for field_name, field_value in self.fields.items():
        #            file.write(f"    {field_name} = {field_value}\n")
        #        for field_name, alias in self.aliases.items():
        #            file.write(f"    {field_name} = {alias}\n")
        #    else:
        #        file.write(f"class {self.name}(Enum):\n")
        #        file.write("    pass\n")
        #else:
        #    if self.fields or self.aliases:
        #        bitwidth = 64 if self.long_bitwidth else 32
        #        file.write(f"class {self.name}(Enum):\n")
        #        for field_name, field_value in self.fields.items():
        #            file.write(f"    {field_name} = 0x{field_value:0{bitwidth // 4}X}\n")
        #        for field_name, alias in self.aliases.items():
        #            file.write(f"    {field_name} = {alias}\n")
        #    else:
        #        file.write(f"class {self.name}(Enum):\n")
        #        file.write("    pass\n")


#class Flag(Obj):
#    __slots__ = (
#        "flag_type_name",
#        "bitmask_enum_name",
#        "bitmask_enum"
#    )

#    def __init__(
#        self: Self,
#        name: str,
#        flag_type_name: str,
#        bitmask_enum_name: str | None
#    ) -> None:
#        super().__init__(
#            name=name,
#            requires={bitmask_enum_name} if bitmask_enum_name is not None else None
#        )
#        self.flag_type_name: str = flag_type_name
#        self.bitmask_enum_name: str | None = bitmask_enum_name
#        self.bitmask_enum: Enum | None = NotImplemented

#    def write_cdef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        file.write("\n")
#        file.write(f"typedef {self.flag_type_name} {self.name};\n")

#    def write_pydef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        file.write("\n")
#        if (bitmask_enum := self.bitmask_enum) is not None and (bitmask_enum.fields or bitmask_enum.aliases):
#            bitwidth = 64 if bitmask_enum.long_bitwidth else 32
#            file.write(f"class {self.name}(Flag):\n")
#            for field_name, field_value in bitmask_enum.fields.items():
#                file.write(f"    {field_name} = 0x{field_value:0{bitwidth // 4}X}\n")
#            for field_name, alias in bitmask_enum.aliases.items():
#                file.write(f"    {field_name} = {alias}\n")
#        else:
#            file.write(f"class {self.name}(Flag):\n")
#            file.write("    pass\n")


class Handle(Obj):
    __slots__ = ()

    #def __init__(
    #    self: Self,
    #    name: str
    #) -> None:
    #    super().__init__(
    #        name=name
    #    )

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef struct {label.name}_T *{label.name};\n")

    def write_pydef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"class {label.name}(VulkanCData):\n")
        file.write(f"    __slots__ = ()\n")


class Struct(Signature):
    __slots__ = ()

    def __init__(
        self: Self,
        #name: str,
        arg_cdecls: tuple[str, ...]
    ) -> None:
        super().__init__(
            #name=name,
            return_cdecl="void _",
            arg_cdecls=arg_cdecls
        )
    
    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef struct {{\n")
        for arg_declaration in self.arg_declarations:
            file.write(f"    {arg_declaration.cdecl};\n")
        file.write(f"}} {label.name};\n")


class Union(Signature):
    __slots__ = ()

    def __init__(
        self: Self,
        #name: str,
        arg_cdecls: tuple[str, ...]
    ) -> None:
        super().__init__(
            #name=name,
            return_cdecl="void _",
            arg_cdecls=arg_cdecls
        )
    
    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"typedef union {{\n")
        for arg_declaration in self.arg_declarations:
            file.write(f"    {arg_declaration.cdecl};\n")
        file.write(f"}} {label.name};\n")


class FunctionPointer(Signature):
    __slots__ = ("cdecl",)

    def __init__(
        self: Self,
        #name: str,
        cdecl: str
    ) -> None:
        assert (match := re.fullmatch(
            r"typedef\s+(.*)\s+\(VKAPI_PTR \*\w+\)\((.*)\);",
            cdecl,
            flags=re.DOTALL
        )) is not None
        assert (args_cdecl := match.group(2)) is not None
        super().__init__(
            #name=name,
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


class Command(Signature):
    __slots__ = ()

    def write_cdef(
        self: Self,
        file: TextIO,
        label: Label
    ) -> None:
        file.write("\n")
        file.write(f"""{self.return_declaration.cdecl}({
            ", ".join(arg_declaration.cdecl for arg_declaration in self.arg_declarations)
        });\n""")


#class CommandAlias(Obj):
#    __slots__ = ("command",)

#    def __init__(
#        self: Self,
#        name: str,
#        command: Command
#    ) -> None:
#        super().__init__(
#            name=name
#            #requires={command.name}
#        )
#        self.command: Command = command

#    def write_cdef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        file.write("\n")
#        file.write(f"""{self.command.return_declaration.cdecl.removesuffix(self.command.name)}{self.name}({
#            ", ".join(arg_declaration.cdecl for arg_declaration in self.command.arg_declarations)
#        });\n""")

#    def write_pydef(
#        self: Self,
#        file: TextIO
#    ) -> None:
#        pass
#        #file.write("\n")
#        #file.write(f"{self.name} = {self.command.name}\n")


class Registry:
    __slots__ = (
        "api",
        "platform",
        "defines",
        "elementary_type_container",
        "external_type_container",
        "external_include_container",
        "macro_container",
        #"elementary_typedef_container",
        "constant_container",
        "enums_container",
        "handle_container",
        "struct_container",
        "union_container",
        "function_pointer_container",
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
        #obj_dict: dict[str, Obj] = {
        #    name: ExternalType(name)
        #    for name in (
        #        "void",
        #        "char"
        #    )
        #}
        #obj_dict.update(
        #    (name, ElementaryType(
        #        name=name,
        #        py_type=py_type
        #    ))
        #    for name, py_type in (
        #        ("void", type(None)),
        #        ("char", str),
        #        ("int", int),
        #        ("size_t", int),
        #        ("float", float),
        #        ("double", float),
        #        ("int8_t", int),
        #        ("int16_t", int),
        #        ("int32_t", int),
        #        ("int64_t", int),
        #        ("uint8_t", int),
        #        ("uint16_t", int),
        #        ("uint32_t", int),
        #        ("uint64_t", int),
        #    )
        #)
        #self.obj_dict: dict[str, Obj] = {
        #    name: ElementaryType(
        #        name=name,
        #        py_type=py_type
        #    )
        #    for name, py_type in (
        #        ("void", type(None)),
        #        ("char", str),
        #        ("int", int),
        #        ("size_t", int),
        #        ("float", float),
        #        ("double", float),
        #        ("int8_t", int),
        #        ("int16_t", int),
        #        ("int32_t", int),
        #        ("int64_t", int),
        #        ("uint8_t", int),
        #        ("uint16_t", int),
        #        ("uint32_t", int),
        #        ("uint64_t", int),
        #    )
        #}
        #self.platform_protect_dict: dict[str, str] = {"": ""}
        self.elementary_type_container: Container[ElementaryType] = Container()
        self.external_type_container: Container[ExternalType] = Container()
        self.external_include_container: Container[ExternalInclude] = Container()
        self.macro_container: Container[Macro] = Container()
        #self.elementary_typedef_container: Container[ElementaryTypedef] = Container()
        self.constant_container: Container[Constant] = Container()
        self.enums_container: Container[Enums] = Container()
        self.handle_container: Container[Handle] = Container()
        self.struct_container: Container[Struct] = Container()
        self.union_container: Container[Union] = Container()
        self.function_pointer_container: Container[FunctionPointer] = Container()
        self.command_container: Container[Command] = Container()
        for name, py_type in (
            ("void", "type(None)"),
            ("char", "str"),
            ("int", "int"),
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
            ("uint64_t", "int"),
            ("stdint", "int")
        ):
            self.elementary_type_container.add_child(name, ElementaryType(
                py_type=py_type
            ))
            self.elementary_type_container.get_label(name).required = True

        #self.elementary_type_container: Container[ElementaryType] = elementary_type_container
        #self.constant_container: Container[Constant] = constant_container
        #self.enums_container: Container[Enums] = enums_container
        #self.command_container: Container[Command] = command_container
        #self.interface_type_chain_map: collections.ChainMap[str, Obj] = collections.ChainMap(
        #    elementary_type_container.get_obj_dict(),
        #    constant_container.get_obj_dict(),
        #    enums_container.get_obj_dict()
        #)

    def iter_interface_obj_items(
        self: Self
    ) -> Iterator[tuple[Obj, Label]]:
        for container in (
            self.elementary_type_container,
            self.external_type_container,
            self.external_include_container,
            self.macro_container,
            #self.elementary_typedef_container,
            self.constant_container,
            self.enums_container,
            self.handle_container,
            self.struct_container,
            self.union_container,
            self.function_pointer_container
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
            #self.elementary_typedef_container,
            self.constant_container,
            self.enums_container,
            self.handle_container,
            self.struct_container,
            self.union_container,
            self.function_pointer_container
        ):
            if container.contains(name):
                return container.get_label(name)
        raise KeyError(name)

    #def iter_objs(
    #    self: Self
    #) -> Iterator[Obj]:
    #    yield from filter(Obj.check_requirement, self.interface_type_chain_map.values())

    #def iter_objs_by_requirement(
    #    self: Self,
    #    objs: list[Obj],
    #    defined_obj_names: set[str]
    #) -> Iterator[Obj]:
    #    dependent_dict: dict[Obj, set[str]] = {
    #        # Discard self-referent requirement.
    #        obj: set(
    #            require
    #            for require in obj.requires
    #            if require not in defined_obj_names and require != obj.name
    #        ) if obj.requires is not None else set()
    #        for obj in objs
    #    }
    #    #support_dict: dict[str, list[Obj]] = {}
    #    #yielded_names: set[str] = set()
    #    while dependent_dict:
    #        for obj, obj_requires in dependent_dict.items():
    #            if obj_requires:
    #                continue
    #            dependent_dict.pop(obj)
    #            yield obj
    #            for _, supported_obj_requires in dependent_dict.items():
    #                supported_obj_requires.discard(obj.name)
    #            break
    #        else:
    #            print(dependent_dict)
    #            raise ValueError

    #def iter_obj_names(
    #    self: Self
    #) -> Iterator[str]:
    #    yield from self.obj_dict

    #def iter_objs(
    #    self: Self
    #) -> Iterator[Obj]:
    #    yield from self.obj_dict.values()
        ##dependent_dict = {
        ##    obj: obj.requires.copy()
        ##    for obj in self.obj_dict.values()
        ##    if obj.requires is not None
        ##}
        #dependent_dict: dict[Obj, set[str]] = {
        #    # Discard self-referent requirement.
        #    obj: obj.requires.difference({obj.name}) if obj.requires is not None else set()
        #    for obj in self.obj_dict.values()
        #}
        ##support_dict: dict[str, list[Obj]] = {}
        ##yielded_names: set[str] = set()
        #while dependent_dict:
        #    for obj, obj_requires in dependent_dict.items():
        #        if obj_requires:
        #            continue
        #        dependent_dict.pop(obj)
        #        yield obj
        #        for _, supported_obj_requires in dependent_dict.items():
        #            supported_obj_requires.discard(obj.name)
        #        break
        #    else:
        #        raise ValueError
        #    #dependent_dict_items_iter = iter(dependent_dict.items())
        #    #obj, obj_requires = next(dependent_dict_items_iter)
        #    #while obj_requires:
        #    #    obj, obj_requires = next(dependent_dict_items_iter)
        #    #dependent_dict.pop(obj)
        #    #yield obj
        #    #for supported_obj, supported_obj_requires in dependent_dict.items():


        #for obj in self.obj_dict.values():
        #    #occurred_names.add(name)
        #    requires = obj.requires.difference(yielded_names) if obj.requires is not None else set()
        #    requires.discard(obj.name)  # Discard self-referent requirement.
        #    if requires:
        #        for require in requires:
        #            support_dict.setdefault(require, []).append(obj)
        #        continue
        #    yieldable_objs = [obj]
        #    while yieldable_objs:
        #        yielded_obj = yieldable_objs.pop(0)
        #        name = yielded_obj.name
        #        yielded_names.add(name)
        #        yield yielded_obj
        #        yieldable_objs = [
        #            supported_obj
        #            for supported_obj in support_dict.pop(name, [])
        #            if yielded_obj.requires is None or not yielded_obj.requires.difference(yielded_names)
        #        ] + yieldable_objs
        #        #for supported_obj in support_dict.pop(name, []):
        #        #    requires = yielded_obj.requires.difference(yielded_names) if yielded_obj.requires is not None else set()
        #        #    dependent = dependent_dict[supported_obj]
        #        #    dependent.remove(name)
        #        #    if dependent:
        #        #        continue
        #        #    dependent_dict.pop(supported_obj)
        #        #    yieldable_objs.insert(0, supported_obj)
        ##print(support_dict)
        ##assert not support_dict

    #def add_obj(
    #    self: Self,
    #    type_obj: Obj
    #) -> None:
    #    assert type_obj.name not in self.obj_dict
    #    self.obj_dict[type_obj.name] = type_obj

    #def has_obj(
    #    self: Self,
    #    type_name: str
    #) -> bool:
    #    return type_name in self.obj_dict

    #def get_obj(
    #    self: Self,
    #    type_name: str
    #) -> Obj:
    #    return self.obj_dict[type_name]

    #def get_elementary_type(
    #    self: Self,
    #    elementary_type_name: str
    #) -> ElementaryType:
    #    elementary_type = self.get_obj(elementary_type_name)
    #    assert isinstance(elementary_type, ElementaryType)
    #    return elementary_type

    #def get_enum(
    #    self: Self,
    #    enum_name: str
    #) -> Enum:
    #    enum = self.get_obj(enum_name)
    #    assert isinstance(enum, Enum)
    #    return enum

    #def get_command(
    #    self: Self,
    #    command_name: str
    #) -> Command:
    #    command = self.get_obj(command_name)
    #    assert isinstance(command, Command)
    #    return command

    def read_interface_obj(
        self: Self,
        type_xml: etree.Element
    ) -> None:
        name = type_xml.get("name", type_xml.findtext("name", ""))
        assert name
        #if type_xml.findtext("type") == "VkFlags":
        #    print(name, type_xml.attrib, type_xml.findtext("type"))
        match type_xml.get("category"):
            case None:
                if not self.external_type_container.contains(name):
                    self.external_type_container.add_child(name, ExternalType())

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
                    self.external_type_container.add_child(name, ExternalType())
                #else:
                #    type_objs.append(ExternalType(
                #        name=name
                #    ))

            case "enum":
                self.enums_container.add_child(name, Enums())

            case "bitmask":
                if (alias := type_xml.get("alias")) is not None:
                    self.elementary_type_container.add_child_alias(name, alias)
                else:
                    self.elementary_type_container.add_child_alias(name, type_xml.findtext("type", ""))
                #type_objs.append(Flag(
                #    name=name,
                #    flag_type_name=type_xml.findtext("type", ""),
                #    bitmask_enum_name=type_xml.get("requires") or type_xml.get("bitvalues")
                #    #cdecl="".join(type_xml.itertext()),
                #    #bitmask_enum=(
                #    #    self.get_enum(bitmask_enum_name)
                #    #    if (bitmask_enum_name := type_xml.get("requires") or type_xml.get("bitvalues")) is not None
                #    #    else None
                #    #)
                #))

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

            case "funcpointer":
                self.function_pointer_container.add_child(name, FunctionPointer(
                    cdecl="".join(type_xml.itertext())
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
        #print(name, enum_xml.attrib)
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

    #def read_extended_constant_or_enum(
    #    self: Self,
    #    enum_xml: etree.Element
    #) -> None:
    #    if (extends := enum_xml.get("extends")) is not None:
    #        self.read_enum(self.enums_container.get_child(extends), enum_xml)
    #    else:
    #        self.read_constant(enum_xml)

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
            xml: etree.Element,
            api: str
        ) -> bool:
            api_attr = xml.get("api")
            return api_attr is None or api in api_attr.split(",")

        def check_platform(
            xml: etree.Element,
            platform: str
        ) -> bool:
            platform_attr = xml.get("platform")
            return platform_attr is None or platform_attr == platform

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
                        #self.platform_protect_dict[platform_xml.get("name", "")] = platform_xml.get("protect", "")
                case "types":
                    for type_xml in xml.iterfind("type"):
                        if not check_api(type_xml, self.api):
                            continue
                        self.read_interface_obj(type_xml)
                        #type_name = type_xml.get("name", type_xml.findtext("name", ""))
                        #type_requirement_dict[type_name] = Requirement(type_xml)
                        #type_dict[type_xml.get("name", type_xml.findtext("name", ""))] = type_xml
                case "enums":
                    #enum_names: list[str] = []
                    #enums_name = xml.get("name", "")
                    #enum_names_dict[enums_name] = enum_names
                    #enums_name = xml.get("name", "")
                    if (enums_name := xml.get("name", "")) == "API Constants":
                        for enum_xml in xml.iterfind("enum"):
                            self.read_constant(enum_xml)
                            #    enum_xml=
                            #    name=enum_xml.get("name", ""),
                            #    value=enum_xml.get("value"),
                            #    alias=enum_xml.get("alias")
                            #)
                    else:
                        enums = self.enums_container.get_child(enums_name)
                        enums.bitmask = xml.get("type") == "bitmask"
                        enums.long_bitwidth = xml.get("bitwidth") == "64"
                        #Enums(
                        #    name=enums_name
                        #)
                        #self.enums_container.add_child(enums)
                        #self.enums_dict[enums_name] = enums
                        for enum_xml in xml.iterfind("enum"):
                            self.read_enum(enums, enum_xml)
                            #self.read_enum(
                            #    enums_name=enums_name,
                            #    name=enum_xml.get("name", ""),
                            #    alias=enum_xml.get("alias")
                            #)
                            #enum_name = enum_xml.get("name", "")
                            #if (alias := enum_xml.get("alias")) is not None:
                            #    enums.add_member_alias(enum_name, alias)
                            #else:
                            #    enums.add_member(enum_name)

                    #enums_xml_dict[enums_name] = xml
                    #enums_members_requirement_dict[enums_name] = {
                    #    enum_xml.get("name", ""): Requirement(enum_xml)
                    #    for enum_xml in xml.iterfind("enum")
                    #}
                    #for enum_xml in xml.iterfind("enum"):
                    #    #if " " not in enums_name:
                    #    #    enum_xml.set("extends", enums_name)
                    #    enum_name = enum_xml.get("name", "")
                    #    enum_dict[enum_name] = Requirement(enum_xml)
                    #    #enum_names.append(enum_name)
                    #    #enum_member_dict[enum_xml.get("name", "")] = enum_xml
                case "commands":
                    for command_xml in xml.iterfind("command"):
                        if not check_api(command_xml, self.api):
                            continue
                        self.read_command(command_xml)
                        ##command_name = command_xml.get("name", command_xml.findtext("proto/name", ""))
                        #if (alias := command_xml.get("alias")) is not None:
                        #    self.command_container.add_child_alias(command_xml.get("name", ""), alias)
                        #else:
                        #    assert (proto_xml := command_xml.find("proto")) is not None
                        #    self.command_container.add_child(Command(
                        #        name=proto_xml.findtext("name", ""),
                        #        return_cdecl="".join(proto_xml.itertext()),
                        #        arg_cdecls=tuple(
                        #            "".join(param_xml.itertext())
                        #            for param_xml in command_xml.iterfind("param")
                        #        )
                        #    ))
                        #    #command_requirement_dict[command_name] = Requirement(command_xml)
                        #    #command_requirement_dict[command_xml.findtext("proto/name", "")] = command_xml
                case "features":
                    for feature_xml in xml.iterfind("feature"):
                        if not check_api(feature_xml, self.api):
                            continue
                        for feature_batch_xml in feature_xml:
                            for feature_unit_xml in feature_batch_xml:
                                if not check_api(feature_unit_xml, self.api):
                                    continue
                                feature_unit_name = feature_unit_xml.get("name", "")
                                match feature_unit_xml.tag:
                                    case "type":
                                        label = self.get_interface_label(feature_unit_name)
                                        #requirement = type_requirement_dict[feature_unit_name]
                                    case "enum":
                                        if (extends := feature_unit_xml.get("extends")) is not None:
                                            self.read_enum(self.enums_container.get_child(extends), feature_unit_xml)
                                            label = self.enums_container.get_child(extends).get_label(feature_unit_name)
                                        else:
                                            self.read_constant(feature_unit_xml)
                                            label = self.constant_container.get_label(feature_unit_name)
                                        #requirement = Requirement(feature_unit_xml)
                                        #enums_members_requirement_dict[feature_unit_xml.get("extends", "")][feature_unit_name] = requirement
                                    case "command":
                                        label = self.command_container.get_label(feature_unit_name)
                                    case _:
                                        continue
                                #if (requirement_dict := requirement_dicts.get(feature_obj_xml.tag)) is None:
                                #    continue
                                protect = feature_unit_xml.get("protect")
                                label.mark_requirement(
                                    batch_tag=feature_batch_xml.tag,
                                    hidden=protect is not None and not self.defines.get(protect, False),
                                    #protect=feature_unit_xml.get("protect", "")
                                    tag=None
                                )
                case "extensions":
                    for extension_xml in xml.iterfind("extension"):
                        if not check_api(extension_xml, self.api) or not check_platform(extension_xml, self.platform):
                            continue
                        extension_tag = extract_tag(extension_xml.get("name"))
                        #platform = extension_xml.get("platform", "")
                        for extension_batch_xml in extension_xml:
                            if not check_api(extension_batch_xml, self.api):
                                continue
                            extension_batch_tag = extract_tag(extension_batch_xml.get("depends"))
                            for extension_unit_xml in extension_batch_xml:
                                if not check_api(extension_unit_xml, self.api):
                                    continue
                                extension_unit_name = extension_unit_xml.get("name", "")
                                match extension_unit_xml.tag:
                                    case "type":
                                        label = self.get_interface_label(extension_unit_name)
                                        tag = extension_batch_tag or extension_tag
                                        #requirement = type_requirement_dict[extension_unit_name]
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
                                        #print(extension_unit_name)
                                        label = self.command_container.get_label(extension_unit_name)
                                        tag = extension_tag
                                    case _:
                                        continue
                                protect = extension_unit_xml.get("protect")
                                #print(extension_unit_name, tag)
                                label.mark_requirement(
                                    batch_tag=extension_batch_xml.tag,
                                    hidden=protect is not None and not self.defines.get(protect, False),
                                    #protect=extension_unit_xml.get("protect", ""),
                                    tag=tag
                                    #platform=platform
                                )

    r"""
    def read_registry(
        self: Self,
        registry_xml: etree.Element
    ) -> None:

        #def sort_xml_by_requirement(
        #    xml_iter: Iterator[etree.Element]
        #) -> Iterator[tuple[str, etree.Element]]:
        #    dependent_dict: dict[str, list[tuple[str, etree.Element]]] = {}
        #    occurred_names: set[str] = set()
        #    for xml in xml_iter:
        #        name = xml.findtext("name") or xml.get("name", "")
        #        occurred_names.add(name)
        #        requires = (
        #            None  # Ignore requires attribute for macros.
        #            if xml.get("category") in ("include", "define")
        #            else xml.get("bitvalues") or xml.get("requires")
        #        )
        #        if requires is not None and requires not in occurred_names:
        #            dependent_dict.setdefault(requires, []).append((name, xml))
        #            continue
        #        yield name, xml
        #        if (dependent_xml_item_list := dependent_dict.pop(name, None)) is not None:
        #            yield from dependent_xml_item_list
        #    assert not dependent_dict

        for xml in list(registry_xml.iter()):
            xml[:] = filter(
                lambda child_xml: (
                    child_xml.tag != "comment"
                    and ((api_attr := child_xml.get("api")) is None or "vulkan" in api_attr.split(","))
                ),
                xml
            )

        type_objs: list[Obj] = []
        for type_xml in registry_xml.iterfind("types/type"):
            name = type_xml.findtext("name") or type_xml.get("name", "")
            if (alias := type_xml.get("alias")) is not None:
                type_objs.append(Alias(
                    name=name,
                    alias=alias
                ))
                continue

            match type_xml.get("category"):
                case None:
                    if self.has_obj(name):
                        continue
                    type_objs.append(ExternalType(
                        name=name
                    ))

                case "include":
                    pass

                case "define":
                    type_objs.append(Macro(
                        name=name,
                        cmacro="".join(type_xml.itertext())
                    ))

                case "basetype":
                    if (match := re.fullmatch(r"typedef\s+(\w+)\s+\w+;", "".join(type_xml.itertext()))) is not None:
                        type_objs.append(ElementaryTypedef(
                            name=name,
                            elementary_type=self.get_elementary_type(match.group(1))
                        ))
                    else:
                        type_objs.append(ExternalType(
                            name=name
                        ))

                case "enum":
                    type_objs.append(Enum(
                        name=name
                    ))

                case "bitmask":
                    type_objs.append(Flag(
                        name=name,
                        flag_type_name=type_xml.findtext("type", ""),
                        bitmask_enum_name=type_xml.get("requires") or type_xml.get("bitvalues")
                        #cdecl="".join(type_xml.itertext()),
                        #bitmask_enum=(
                        #    self.get_enum(bitmask_enum_name)
                        #    if (bitmask_enum_name := type_xml.get("requires") or type_xml.get("bitvalues")) is not None
                        #    else None
                        #)
                    ))

                case "handle":
                    type_objs.append(Handle(
                        name=name
                    ))

                case "struct":
                    type_objs.append(Struct(
                        name=name,
                        arg_cdecls=tuple(
                            "".join(member_xml.itertext())
                            for member_xml in type_xml.iterfind("member")
                        )
                    ))

                case "union":
                    type_objs.append(Union(
                        name=name,
                        arg_cdecls=tuple(
                            "".join(member_xml.itertext())
                            for member_xml in type_xml.iterfind("member")
                        )
                    ))

                case "funcpointer":
                    type_objs.append(FunctionPointer(
                        name=name,
                        cdecl="".join(type_xml.itertext())
                    ))

                case _ as category:
                    raise ValueError(f"Unexpected category name: {category}")

        for type_obj in self.iter_objs_by_requirement(type_objs, set(self.iter_obj_names())):
            self.add_obj(type_obj)
            if isinstance(type_obj, Flag):
                type_obj.bitmask_enum = self.get_enum(type_obj.bitmask_enum_name) if type_obj.bitmask_enum_name is not None else None
            if isinstance(type_obj, Signature):
                for declaration in (type_obj.return_declaration, *type_obj.arg_declarations):
                    declaration.base_type = self.get_obj(declaration.base_type_name)

        for enums_xml in registry_xml.iterfind("enums"):
            enum = self.get_enum(enum_name) if self.has_obj(enum_name := enums_xml.get("name", "")) else None
            if enum is not None:
                enum.long_bitwidth = (
                    enums_xml.get("bitwidth") == "64"
                    if enums_xml.get("type") == "bitmask"
                    else None
                )
            for enum_xml in enums_xml.iterfind("enum"):
                self.read_field_or_constant(enum, enum_xml, None)

        for command_xml in registry_xml.iterfind("commands/command"):
            if (alias := command_xml.get("alias")) is not None:
                command = self.get_command(alias)
                self.add_obj(CommandAlias(
                    name=command_xml.get("name", ""),
                    command=command
                ))
                continue
            assert (proto_xml := command_xml.find("proto")) is not None 
            assert (name := proto_xml.findtext("name")) is not None
            self.add_obj(Command(
                name=name,
                return_cdecl="".join(proto_xml.itertext()),
                arg_cdecls=tuple(
                    "".join(param_xml.itertext())
                    for param_xml in command_xml.iterfind("param")
                )
            ))

        for enum_xml in registry_xml.iterfind("feature/require/enum"):
            enum = self.get_enum(enum_name) if (enum_name := enum_xml.get("extends")) is not None else None
            self.read_field_or_constant(enum, enum_xml, None)

        for extension_xml in registry_xml.iterfind("extensions/extension"):
            number = extension_xml.get("number")
            for enum_xml in extension_xml.iterfind("require/enum"):
                enum = self.get_enum(enum_name) if (enum_name := enum_xml.get("extends")) is not None else None
                self.read_field_or_constant(enum, enum_xml, number)
    """

    def build_cdef(
        self: Self,
        cdef_path: pathlib.Path
    ) -> None:
        with cdef_path.open("w") as file:
            file.write("// Auto-generated C definitions\n")
            for obj, label in self.iter_interface_obj_items():
                obj.write_cdef(file, label)

    def build_ffi(
        self: Self,
        ffi_path: pathlib.Path,
        cdef_path: pathlib.Path
    ) -> None:
        c_sources = [
            "vk_video/vulkan_video_codec_h264std.h",
            "vk_video/vulkan_video_codec_h264std_decode.h",
            "vk_video/vulkan_video_codec_h264std_encode.h",
            "vk_video/vulkan_video_codec_h265std.h",
            "vk_video/vulkan_video_codec_h265std_decode.h",
            "vk_video/vulkan_video_codec_h265std_encode.h",
            "vk_video/vulkan_video_codecs_common.h",
            "vulkan/vulkan.h"
        ]
        ffi = cffi.FFI()
        ffi.cdef(csource=cdef_path.read_text())
        ffi.set_source(
            module_name=str(ffi_path.with_suffix("")).replace("\\", "."),
            source="".join((
                *(f"#define {define}\n" for define, enabled in self.defines.items() if enabled),
                *(f"#include <{filename}>\n" for filename in c_sources)
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
        #preamble_path: pathlib.Path
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
            file.write("from typing import Union\n")
            file.write("\n")
            file.write("import cffi\n")
            file.write("\n")
            file.write(f".{ffi_path.relative_to(pydef_path.parent).stem} import (\n")
            file.write("    ffi,\n")
            file.write("    lib\n")
            file.write(")\n")
            file.write("\n\n")
            #file.write(preamble_path.read_text())
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
    registry = Registry(api="vulkan", platform="win32", defines=["VK_ENABLE_BETA_EXTENSIONS"])
    for xml in (
        this_dir.joinpath("extern/xml/video.xml"),
        this_dir.joinpath("extern/xml/vk.xml")
    ):
        registry.read_registry_xml(etree.parse(xml).getroot())

    generated_dir = this_dir.joinpath("generated")
    generated_dir.mkdir(exist_ok=True)
    cdef_path = generated_dir.joinpath("_vulkan.h")
    pydef_path = generated_dir.joinpath("_vulkan.py")
    ffi_path = generated_dir.joinpath("_vulkan_ffi.py")
    #preamble_path = this_dir.joinpath("preamble.py")

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
            registry.build_cdef(cdef_path)
            registry.build_ffi(ffi_path, cdef_path)

        case "pydef":
            registry.build_pydef(pydef_path, ffi_path)


if __name__ == "__main__":
    main()
