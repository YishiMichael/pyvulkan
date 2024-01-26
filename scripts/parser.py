import pathlib
import re
import xml.etree.ElementTree as etree
from typing import (
    Any,
    Iterable,
    Self
)

import clang.cindex as clang


class Proxy:
    __slots__ = ("_obj",)

    def __init__(
        self: Self,
        obj: Any
    ) -> None:
        super().__init__()
        self._obj = obj

    def __getattribute__(
        self: Self,
        __name: str
    ) -> Any:
        if __name == "_obj":
            return super().__getattribute__(__name)
        return getattr(self._obj, __name)


CursorKind = Proxy(clang.CursorKind)
TypeKind = Proxy(clang.TypeKind)
lib = Proxy(clang.Config().lib)


class VulkanHeaderParser:
    __slots__ = ()

    FILES = {
        f"vulkan/{filename}": directory_path.joinpath(filename).read_text()
        for directory_path, _, filenames in pathlib.Path("vulkan").walk()
        for filename in filenames
    }

    @classmethod
    def parse(
        cls: type[Self],
        decl: clang.Cursor
    ) -> etree.Element | None:
        for child_decl in decl.get_children():
            match child_decl.location.file.name.removeprefix(".\\"), child_decl.kind:
                case "vulkan/vulkan.cppm", CursorKind.NAMESPACE:
                    if (xml := cls.parse_namespace(child_decl)) is not None:
                        return xml
        return None

    @classmethod
    def parse_namespace(
        cls: type[Self],
        decl: clang.Cursor
    ) -> etree.Element | None:
        return cls._make_xml(
            "namespace",
            dict(
                name=decl.spelling,
                #elaborated=decl.enum_type.kind == TypeKind.ELABORATED
            ),
            (
                cls.parse_namespace_obj(child_decl)
                for child_decl in decl.get_children()
            )
        )
        #xml = etree.Element("namespace", )
        #for child_decl in decl.get_children():
        #    match cls._extract_filename(child_decl.location.file.name.removeprefix(".\\")), child_decl.kind:
        #        case "vulkan.cppm", CursorKind.NAMESPACE:
        #            xml.append(cls.parse_namespace(child_decl))
        #        case "vulkan.cppm", CursorKind.USING_DECLARATION:
        #            ref_decl = lib.clang_getOverloadedDecl(child_decl.referenced, 0)
        #            match cls._extract_filename(ref_decl.location.file.name.removeprefix(".\\")), ref_decl.kind:
        #                case "vulkan_enums.hpp", CursorKind.ENUM_DECL:
        #                    xml.append(cls.parse_enum(ref_decl))
        #                case "vulkan_structs.hpp", CursorKind.STRUCT_DECL:
        #                    xml.append(cls.parse_struct(ref_decl))
        #                case "vulkan_structs.hpp", CursorKind.UNION_DECL:
        #                    xml.append(cls.parse_union(ref_decl))
        #                case "vulkan.hpp", CursorKind.VAR_DECL:
        #                    xml.append(cls.parse_constant(ref_decl))
        #return xml

    @classmethod
    def parse_namespace_obj(
        cls: type[Self],
        decl: clang.Cursor
    ) -> etree.Element | None:
        match decl.location.file.name.removeprefix(".\\"), decl.kind:
            case "vulkan/vulkan.cppm", CursorKind.NAMESPACE:
                return cls.parse_namespace(decl)
            case "vulkan/vulkan.cppm", CursorKind.USING_DECLARATION:
                ref_decl = lib.clang_getOverloadedDecl(decl.referenced, 0)
                match ref_decl.location.file.name.removeprefix(".\\"), ref_decl.kind:
                    case "vulkan/vulkan_enums.hpp", CursorKind.ENUM_DECL:
                        return cls.parse_enum(ref_decl)
                    case "vulkan/vulkan_structs.hpp", CursorKind.STRUCT_DECL:
                        return cls.parse_struct(ref_decl)
                    case "vulkan/vulkan_structs.hpp", CursorKind.UNION_DECL:
                        return cls.parse_union(ref_decl)
                    case "vulkan/vulkan.hpp", CursorKind.VAR_DECL:
                        return cls.parse_constant(ref_decl)
                    case _:
                        return None
            case _:
                return None

    @classmethod
    def parse_enum(
        cls: type[Self],
        decl: clang.Cursor
    ) -> etree.Element | None:
        return cls._make_xml(
            "enum",
            dict(
                name=decl.spelling,
                #elaborated=decl.enum_type.kind == TypeKind.ELABORATED
            ),
            (
                cls._make_xml(
                    "member",
                    dict(
                        name=enum_constant_decl.spelling
                    )
                )
                for enum_constant_decl in decl.get_children()
                if enum_constant_decl.kind == CursorKind.ENUM_CONSTANT_DECL
            )
        )

    @classmethod
    def parse_struct(
        cls: type[Self],
        decl: clang.Cursor
    ) -> etree.Element | None:
        # Every struct has 3 or 4 constructor overloadings in order:
        # - Default constructor;
        # - Copy constructor;
        # - Converting constructor from the corresponding C-style struct;
        # - (optional) Enhanced constructor.
        constructor_decl = tuple(
            constructor_decl
            for constructor_decl in decl.get_children()
            if constructor_decl.kind == CursorKind.CONSTRUCTOR
            and not (
                len(argument_types := constructor_decl.type.argument_types()) == 1
                and argument_types[0].spelling in (
                    f"const {decl.spelling} &",  # Discard copy constructor.
                    f"const Vk{decl.spelling} &"  # Discard converting constructor.
                )
            )
        )[-1]  # Pick the enhanced constructor, if it exists.
        return cls._make_xml(
            "struct",
            dict(
                name=decl.spelling
            ),
            (cls.parse_function(constructor_decl),)
        )

    @classmethod
    def parse_union(
        cls: type[Self],
        decl: clang.Cursor
    ) -> etree.Element | None:
        return cls._make_xml(
            "union",
            dict(
                name=decl.spelling
            ),
            (
                cls.parse_function(constructor_decl)
                for constructor_decl in decl.get_children()
                if constructor_decl.kind == CursorKind.CONSTRUCTOR
                and constructor_decl.is_converting_constructor()
            )
        )

    @classmethod
    def parse_function(
        cls: type[Self],
        decl: clang.Cursor
    ) -> etree.Element | None:

        def re_translate(
            string: str,
            translation: dict[str, str]
        ) -> str:
            for pattern, repl in translation.items():
                string = re.sub(pattern, repl, string)
            return string

        return cls._make_xml(
            "function",
            dict(
                name=decl.spelling
            ),
            (
                cls._make_xml(
                    "argument",
                    dict(
                        name=arg_decl.spelling,
                        type=arg_decl.type.spelling,
                        default=(
                            re_translate(
                                default_str.strip().replace("\n", " "),
                                {
                                    r"\s+": " ",
                                    r"\bVULKAN_HPP_NAMESPACE\b": "vk",
                                    r"\bVULKAN_HPP_RAII_NAMESPACE\b": "raii"
                                }
                            )
                            if "=" in (arg_decl_str := cls._str_from_extent(arg_decl.extent))
                            and (default_str := cls._slice_right(arg_decl_str, "=")) is not None
                            else None
                        )
                    )
                )
                for arg_decl in decl.get_arguments() 
            )
        )

    @classmethod
    def parse_constant(
        cls: type[Self],
        decl: clang.Cursor
    ) -> etree.Element | None:
        return cls._make_xml(
            "constant",
            dict(
                name=decl.spelling,
                type=decl.type.spelling
            )
        ) if decl.spelling not in ("True", "False") else None
        #if decl.spelling in ("True", "False"):
        #            continue
        #        objs.append(ConstantData(
        #            name=decl.spelling,
        #            type=decl.type.spelling
        #        ))

    @classmethod
    def _make_xml(
        cls: type[Self],
        tag: str,
        attrib: dict[str, str | None],
        subelements: Iterable[etree.Element | None] | None = None
    ) -> etree.Element:
        xml = etree.Element(tag, {k: v for k, v in attrib.items() if v is not None})
        if subelements is not None:
            xml.extend(subelement for subelement in subelements if subelement is not None)
        return xml

    @classmethod
    def _str_from_extent(
        cls: type[Self],
        extent: clang.SourceRange
    ) -> str:
        file_content_lines = cls.FILES[extent.start.file.name.removeprefix(".\\")].splitlines()
        if extent.start.line == extent.end.line:
            return file_content_lines[extent.start.line - 1][extent.start.column - 1:extent.end.column - 1]
        return "\n".join((
            file_content_lines[extent.start.line - 1][extent.start.column - 1:],
            *file_content_lines[extent.start.line:extent.end.line - 1],
            file_content_lines[extent.end.line - 1][:extent.end.column - 1]
        ))

    #@classmethod
    #def _extract_filename(
    #    cls: type[Self],
    #    name: str
    #) -> str | None:
    #    return cls._slice_right(name.replace("\\", "/"), "vulkan/")

    @classmethod
    def _slice_right(
        cls: type[Self],
        s: str,
        sub: str
    ) -> str | None:
        return s[index + len(sub):] if (index := s.rfind(sub)) != -1 else None


"""
@dataclass
class EnumData:
    name: str
    elaborated: bool
    member_names: tuple[str, ...]


@dataclass
class ArgumentData:
    name: str
    type: str
    default: str | None


@dataclass
class StructData:
    name: str
    constructor_arguments: tuple[ArgumentData, ...]


@dataclass
class UnionData:
    name: str
    constructors_argument: tuple[ArgumentData, ...]


@dataclass
class ConstantData:
    name: str
    type: str


objs = []
kinds = set()

for module_decl in tu.cursor.get_children():
    if module_decl.kind != CursorKind.NAMESPACE or module_decl.location.file.name.removeprefix(".\\") != "vulkan.cppm":
        continue
    for using_decl in module_decl.get_children():
        if using_decl.kind != CursorKind.USING_DECLARATION:
            continue
        decl = lib.clang_getOverloadedDecl(using_decl.referenced, 0)
        match decl.kind:
            case CursorKind.ENUM_DECL:
                #print(decl.spelling, decl.is_scoped_enum())
                #for enum_constant_decl in decl.get_children():
                #    if enum_constant_decl.kind != CursorKind.ENUM_CONSTANT_DECL:
                #        continue
                #    print(enum_constant_decl.kind, enum_constant_decl.spelling)
                objs.append(EnumData(
                    name=decl.spelling,
                    elaborated=decl.enum_type.kind == TypeKind.ELABORATED,
                    member_names=tuple(
                        enum_constant_decl.spelling
                        for enum_constant_decl in decl.get_children()
                        if enum_constant_decl.kind == CursorKind.ENUM_CONSTANT_DECL
                    )
                ))
            case CursorKind.STRUCT_DECL:
                # Every struct has 3 or 4 constructor overloadings in order:
                # - Default constructor;
                # - Copy constructor;
                # - Converting constructor from the corresponding C-style struct;
                # - (optional) Enhanced constructor.
                arg_decls = tuple(
                    constructor_decl
                    for constructor_decl in decl.get_children()
                    if constructor_decl.kind == CursorKind.CONSTRUCTOR
                    and not (
                        len(argument_types := constructor_decl.type.argument_types()) == 1
                        and argument_types[0].spelling in (
                            f"const {decl.spelling} &",  # Discard copy constructor.
                            f"const Vk{decl.spelling} &"  # Discard converting constructor.
                        )
                    )
                )[-1].get_arguments()  # Pick the enhanced constructor, if it exists.
                objs.append(StructData(
                    name=decl.spelling,
                    constructor_arguments=tuple(
                        ArgumentData(
                            name=arg_decl.spelling,
                            type=arg_decl.type.spelling,
                            default=(
                                re.sub(
                                    r" *(\n *)+",
                                    " ",
                                    re.sub(
                                        r"\bVULKAN_HPP_NAMESPACE\b",
                                        "vk",
                                        arg_decl_str.split("=", 1)[1].strip()
                                    )
                                )
                                if "=" in (arg_decl_str := str_from_extent(arg_decl.extent))
                                else None
                            )
                        )
                        for arg_decl in arg_decls
                    )
                ))
                #for argument_decl in constructor_decl.get_children():
                #    print(argument_decl.kind, argument_decl.spelling)
                #for arg_decl in constructor_decl.get_arguments():
                #    print(" ", arg_decl.type.spelling, arg_decl.spelling, repr(str_from_extent(arg_decl.extent)))
                #    #for c_decl in arg_decl.get_children():
                #    #    print("   ", c_decl.kind, c_decl.linkage, c_decl.spelling, [t.spelling for t in c_decl.get_tokens()])
                #    #    for cc_decl in c_decl.get_children():
                #    #        print("     ", cc_decl.kind, cc_decl.linkage, cc_decl.spelling, [t.spelling for t in cc_decl.get_tokens()])
                #    #        for ccc_decl in cc_decl.get_children():
                #    #            print("       ", ccc_decl.kind, ccc_decl.linkage, ccc_decl.spelling, [t.spelling for t in ccc_decl.get_tokens()])
                #    #            for cccc_decl in ccc_decl.get_children():
                #    #                print("         ", cccc_decl.kind, cccc_decl.linkage, cccc_decl.spelling, [t.spelling for t in cccc_decl.get_tokens()])
                #for constructor_decl in decl.get_children():
                #    if constructor_decl.kind != CursorKind.CONSTRUCTOR:
                #        continue
                #    #print(list((t.kind, t.spelling) for t in constructor_decl.get_arguments()))
                #    #print(
                #    #    constructor_decl.is_converting_constructor(),
                #    #    constructor_decl.is_copy_constructor(),
                #    #    constructor_decl.is_default_constructor(),
                #    #    constructor_decl.is_move_constructor()
                #    #)
                #print(any(
                #    t.spelling == "pNext_"
                #    for constructor_decl in decl.get_children()
                #    if constructor_decl.kind == CursorKind.CONSTRUCTOR
                #    for t in constructor_decl.get_arguments()
                #), decl.spelling)
            case CursorKind.UNION_DECL:
                arg_decls = tuple(
                    next(constructor_decl.get_arguments())
                    for constructor_decl in decl.get_children()
                    if constructor_decl.kind == CursorKind.CONSTRUCTOR
                    and constructor_decl.is_converting_constructor()
                )
                objs.append(UnionData(
                    name=decl.spelling,
                    constructors_argument=tuple(
                        ArgumentData(
                            name=arg_decl.spelling,
                            type=arg_decl.type.spelling,
                            default=(
                                arg_decl_str.split("=", 1)[1].strip()
                                if "=" in (arg_decl_str := str_from_extent(arg_decl.extent))
                                else None
                            )
                        )
                        for arg_decl in arg_decls
                    )
                ))
            #case CursorKind.CLASS_TEMPLATE:
            #    print(decl.spelling)
            case CursorKind.CLASS_DECL:
                #pass
                print(decl.spelling)
                for c_decl in decl.get_children():
                    print(" ", c_decl.kind, c_decl.spelling)
                print()
            case CursorKind.VAR_DECL:
                if decl.spelling in ("True", "False"):
                    continue
                objs.append(ConstantData(
                    name=decl.spelling,
                    type=decl.type.spelling
                ))
            case _:
                #print(decl.kind, decl.spelling)
                kinds.add(decl.kind)
        #if not (vk_ns.kind == CursorKind.NAMESPACE and vk_ns.spelling == "vk"):
        #    continue
        #for obj in vk_ns.get_children():
        #    if obj.kind not in (
        #        #CursorKind.VAR_DECL,
        #        CursorKind.NAMESPACE,
        #        #CursorKind.CLASS_TEMPLATE,
        #        #CursorKind.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION,
        #        #CursorKind.UNION_DECL,
        #        ##CursorKind.USING_DECLARATION,
        #        #CursorKind.CLASS_DECL,
        #        #CursorKind.TYPE_ALIAS_DECL,
        #        #CursorKind.ENUM_DECL,
        #        #CursorKind.STRUCT_DECL,
        #        #CursorKind.TYPE_ALIAS_TEMPLATE_DECL,
        #        #CursorKind.FUNCTION_DECL,
        #        #CursorKind.FUNCTION_TEMPLATE
        #    ):
        #        continue
        #    print(obj.kind, obj.type, obj.spelling)

print(kinds)
"""


tu = clang.TranslationUnit.from_source(
    filename="vulkan/vulkan.cppm",
    args=[
        "-x", "c++-header",
        "-I", "."
    ],
    options=clang.TranslationUnit.PARSE_SKIP_FUNCTION_BODIES
)

xml = VulkanHeaderParser.parse(tu.cursor)
assert xml is not None
etree.indent(xml)
etree.ElementTree(xml).write("registry.xml")
