import pathlib
import re
import xml.etree.ElementTree as etree
from functools import lru_cache
from typing import (
    Any,
    Iterable,
    Iterator,
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
AccessSpecifier = Proxy(clang.AccessSpecifier)
lib = Proxy(clang.Config().lib)


class HeaderParser:
    __slots__ = (
        "_translation_unit",
        "_src_file"
    )

    def __init__(
        self: Self,
        src_file: str,
        include_dir: str
    ) -> None:
        super().__init__()
        self._translation_unit: clang.TranslationUnit = clang.TranslationUnit.from_source(
            filename=src_file,
            args=(
                "-x", "c++-header",
                "-I", include_dir
            ),
            options=clang.TranslationUnit.PARSE_INCOMPLETE | clang.TranslationUnit.PARSE_SKIP_FUNCTION_BODIES
        )
        self._src_file: str = src_file

    def parse(
        self: Self
    ) -> etree.Element:
        return type(self)._make_xml(
            "registry",
            dict(),
            (
                child
                for child_decl in self._translation_unit.cursor.get_children()
                if child_decl.kind == CursorKind.NAMESPACE
                and pathlib.Path(child_decl.location.file.name) == pathlib.Path(self._src_file)
                for child in type(self)._iter_namespace_child(child_decl, None)
            )
        )

    @classmethod
    def _iter_namespace_child(
        cls: type[Self],
        decl: clang.Cursor,
        namespace: str | None
    ) -> Iterator[etree.Element]:
        filename = pathlib.Path(decl.location.file.name).name
        match decl.kind:
            case CursorKind.NAMESPACE:
                new_namespace = f"{namespace}::{decl.spelling}" if namespace is not None else decl.spelling
                for child_decl in decl.get_children():
                    yield from cls._iter_namespace_child(child_decl, new_namespace)
            case CursorKind.USING_DECLARATION:
                for index in range(lib.clang_getNumOverloadedDecls(decl.referenced)):
                    def_decl = lib.clang_getOverloadedDecl(decl.referenced, index)
                    if def_decl is not None and def_decl.is_definition():
                        yield from cls._iter_namespace_child(def_decl, namespace)
            case CursorKind.ENUM_DECL:
                if not decl.is_definition():
                    return
                yield cls._make_xml(
                    "enum",
                    dict(
                        name=decl.spelling,
                        namespace=namespace,
                        filename=filename
                        #elaborated=decl.enum_type.kind == TypeKind.ELABORATED
                    ),
                    (
                        child
                        for child_decl in decl.get_children()
                        for child in cls._iter_enum_child(child_decl)
                    )
                )
            case CursorKind.STRUCT_DECL | CursorKind.UNION_DECL | CursorKind.CLASS_DECL | CursorKind.CLASS_TEMPLATE:
                if not decl.is_definition():
                    return
                #if decl.get_num_template_arguments() != -1:
                #    return
                match decl.kind:
                    case CursorKind.STRUCT_DECL:
                        tag_name = "struct"
                    case CursorKind.UNION_DECL:
                        tag_name = "union"
                    case CursorKind.CLASS_DECL | CursorKind.CLASS_TEMPLATE:
                        tag_name = "class"
                    case _:
                        assert False
                yield cls._make_xml(
                    tag_name,
                    dict(
                        name=decl.spelling,
                        namespace=namespace,
                        filename=filename,
                        template_raw=cls._extract_template(decl)
                        #elaborated=decl.enum_type.kind == TypeKind.ELABORATED
                    ),
                    (
                        child
                        for child_decl in decl.get_children()
                        for child in cls._iter_class_child(child_decl)
                    )
                )
            case CursorKind.FUNCTION_DECL | CursorKind.FUNCTION_TEMPLATE:
                #if decl.kind == CursorKind.FUNCTION_TEMPLATE:
                #    print(decl.spelling)
                #    print(cls._str_from_extent(decl.extent))
                #    print()
                yield cls._make_xml(
                    "function",
                    dict(
                        name=decl.spelling,
                        namespace=namespace,
                        filename=filename,
                        template_raw=cls._extract_template(decl)
                    ),
                    (
                        cls._make_xml(
                            "argument",
                            dict(
                                name=arg_decl.spelling,
                                type=arg_decl.type.spelling,
                                default_raw=cls._extract_rvalue(arg_decl)
                            )
                        )
                        for arg_decl in decl.get_arguments()
                    )
                )
            case CursorKind.TYPE_ALIAS_DECL:
                yield cls._make_xml(
                    "type_alias",
                    dict(
                        name=decl.spelling,
                        namespace=namespace,
                        filename=filename,
                        alias_raw=cls._extract_rvalue(decl)
                    )
                )
                #kinds = tuple(child_decl.kind for child_decl in decl.get_children())
                #if not (
                #    len(kinds) >= 2 and all(
                #        kind == CursorKind.TEMPLATE_REF if index == 0 else CursorKind.TYPE_REF
                #        for index, kind in enumerate(kinds)
                #    )
                #):
                #    print(decl.spelling, [(d.kind, d.spelling) for d in decl.get_children()])
            #case CursorKind.STRUCT_DECL:
            #    if not decl.is_definition():
            #        return
            #    if decl.get_num_template_arguments() != -1:
            #        return
            #    print(decl.spelling)
            #    yield cls._make_xml(
            #        tag_name,
            #        dict(
            #            name=decl.spelling,
            #            namespace=namespace
            #        ),
            #        tuple(
            #            cls._parse_function(function_decl)
            #            for function_decl in decl.get_children()
            #            if (print(function_decl.kind, function_decl.access_specifier, function_decl.availability) or function_decl.kind == CursorKind.FUNCTION_DECL
            #            #if print(constructor_decl.kind) or constructor_decl.kind == CursorKind.CONSTRUCTOR
            #            #and constructor_decl.is_converting_constructor()
            #        )
            #    )
            case CursorKind.VAR_DECL:
                yield cls._make_xml(
                    "constant",
                    dict(
                        name=decl.spelling,
                        namespace=namespace,
                        type=decl.type.spelling
                    )
                )
                ##def_decl = decl.referenced.get_definition()
                #def_decl = None
                ##print(lib.clang_getNumOverloadedDecls(decl.referenced))
                #for index in range(lib.clang_getNumOverloadedDecls(decl.referenced)):
                #    def_decl = lib.clang_getOverloadedDecl(decl.referenced, index)
                #    if def_decl is not None:
                #        break
                ##if decl.spelling == "InstanceCreateInfo":
                ##    print(self._extract_filename(def_decl.location.file.name))
                ##    print(def_decl.kind.is_declaration())
                ##    print(def_decl.kind.is_reference())
                ##    print(def_decl.is_definition())
                ##    print(self._extract_filename(def_decl.get_definition().location.file.name))
                #if def_decl is None:
                #    print(decl.referenced.spelling)
                #    return None
                #if def_decl.kind not in kinds:
                #    kinds.add(def_decl.kind)
                #    #print(self._extract_filename(def_decl.location.file.name), def_decl.kind)
                #match def_decl.kind:
                #    case CursorKind.ENUM_DECL:
                #        return self.parse_enum(def_decl)
                #    case CursorKind.STRUCT_DECL:
                #        return self.parse_struct(def_decl)
                #    case CursorKind.UNION_DECL:
                #        return self.parse_union(def_decl)
                #    case CursorKind.VAR_DECL:
                #        return self.parse_constant(def_decl)
                #    case _:
                #        return None

    #def parse_namespace(
    #    self: Self,
    #    decl: clang.Cursor
    #) -> etree.Element | None:
    #    #print(decl.spelling, decl.displayname, decl.mangled_name, decl.semantic_parent.spelling, decl.lexical_parent.spelling)
    #    return self._make_xml(
    #        "namespace",
    #        dict(
    #            name=decl.spelling,
    #            #elaborated=decl.enum_type.kind == TypeKind.ELABORATED
    #        ),
    #        tuple(
    #            self.parse_obj(child_decl)
    #            for child_decl in decl.get_children()
    #        )
    #    )

    #def parse_enum(
    #    self: Self,
    #    decl: clang.Cursor,
    #    namespace: str
    #) -> etree.Element:
    #    return self._make_xml(
    #        "enum",
    #        dict(
    #            name=decl.spelling,
    #            namespace=namespace
    #            #elaborated=decl.enum_type.kind == TypeKind.ELABORATED
    #        ),
    #        tuple(
    #            self._make_xml(
    #                "member",
    #                dict(
    #                    name=enum_constant_decl.spelling
    #                )
    #            )
    #            for enum_constant_decl in decl.get_children()
    #            if enum_constant_decl.kind == CursorKind.ENUM_CONSTANT_DECL
    #        )
    #    )

    #def parse_struct(
    #    self: Self,
    #    decl: clang.Cursor,
    #    namespace: str
    #) -> etree.Element:
    #    # Every struct has 3 or 4 constructor overloadings in order:
    #    # - Default constructor;
    #    # - Copy constructor;
    #    # - Converting constructor from the corresponding C-style struct;
    #    # - (optional) Enhanced constructor.
    #    constructor_decl = tuple(
    #        constructor_decl
    #        for constructor_decl in decl.get_children()
    #        if print(constructor_decl.kind) or constructor_decl.kind == CursorKind.CONSTRUCTOR
    #        and not (
    #            len(argument_types := constructor_decl.type.argument_types()) == 1
    #            and argument_types[0].spelling in (
    #                f"const {decl.spelling} &",  # Discard copy constructor.
    #                f"const Vk{decl.spelling} &"  # Discard converting constructor.
    #            )
    #        )
    #    )#[-1]  # Pick the enhanced constructor, if it exists.
    #    return self._make_xml(
    #        "struct",
    #        dict(
    #            name=decl.spelling,
    #            namespace=namespace
    #        ),
    #        #(self.parse_function(constructor_decl),)
    #    )

    #def parse_union(
    #    self: Self,
    #    decl: clang.Cursor,
    #    namespace: str
    #) -> etree.Element:
    #    return self._make_xml(
    #        "union",
    #        dict(
    #            name=decl.spelling,
    #            namespace=namespace
    #        ),
    #        tuple(
    #            self.parse_function(constructor_decl)
    #            for constructor_decl in decl.get_children()
    #            if print(constructor_decl.kind) or constructor_decl.kind == CursorKind.CONSTRUCTOR
    #            and constructor_decl.is_converting_constructor()
    #        )
    #    )

    @classmethod
    def _iter_enum_child(
        cls: type[Self],
        decl: clang.Cursor
    ) -> Iterator[etree.Element]:
        match decl.kind:
            case CursorKind.ENUM_CONSTANT_DECL:
                yield cls._make_xml(
                    "member",
                    dict(
                        name=decl.spelling
                    )
                )

    @classmethod
    def _iter_class_child(
        cls: type[Self],
        decl: clang.Cursor
    ) -> Iterator[etree.Element]:
        if decl.access_specifier != AccessSpecifier.PUBLIC:
            return
        match decl.kind:
            case CursorKind.CXX_BASE_SPECIFIER:
                yield cls._make_xml(
                    "base",
                    dict(
                        name=decl.spelling
                    )
                )
            case CursorKind.FIELD_DECL:
                yield cls._make_xml(
                    "member",
                    dict(
                        name=decl.spelling
                    )
                )
            case CursorKind.CONSTRUCTOR | CursorKind.DESTRUCTOR | CursorKind.CONVERSION_FUNCTION \
                    | CursorKind.CXX_METHOD | CursorKind.FUNCTION_TEMPLATE:
                match decl.kind:
                    case CursorKind.CONSTRUCTOR:
                        tag_name = "constructor"
                    case CursorKind.DESTRUCTOR:
                        tag_name = "destructor"
                    case CursorKind.CONVERSION_FUNCTION:
                        tag_name = "conversion_function"
                    case CursorKind.CXX_METHOD | CursorKind.FUNCTION_TEMPLATE:
                        tag_name = "method"
                    case _:
                        assert False
                yield cls._make_xml(
                    tag_name,
                    dict(
                        name=decl.spelling,
                        template_raw=cls._extract_template(decl)
                    ),
                    (
                        cls._make_xml(
                            "argument",
                            dict(
                                name=arg_decl.spelling,
                                type=arg_decl.type.spelling,
                                default_raw=(
                                    rvalue_str or "{}"
                                    if (rvalue_str := cls._extract_rvalue(arg_decl)) is not None
                                    else None
                                )
                            )
                        )
                        for arg_decl in decl.get_arguments()
                    )
                )
                #yield cls._parse_function(decl, tag_name=tag_name)

    #@classmethod
    #def _parse_function(
    #    cls: type[Self],
    #    decl: clang.Cursor,
    #    tag_name: str = "function",
    #    namespace: str | None = None
    #) -> etree.Element:
    #    return cls._make_xml(
    #        tag_name,
    #        dict(
    #            name=decl.spelling,
    #            namespace=namespace,
    #            template_raw=cls._extract_template(decl)
    #        ),
    #        (
    #            cls._make_xml(
    #                "argument",
    #                dict(
    #                    name=arg_decl.spelling,
    #                    type=arg_decl.type.spelling,
    #                    default_raw=(
    #                        rvalue_str or "{}"
    #                        if (rvalue_str := cls._extract_rvalue(arg_decl)) is not None
    #                        else None
    #                    )
    #                )
    #            )
    #            for arg_decl in decl.get_arguments()
    #        )
    #    )

    #def parse_constant(
    #    self: Self,
    #    decl: clang.Cursor,
    #    namespace: str
    #) -> etree.Element:
    #    return self._make_xml(
    #        "constant",
    #        dict(
    #            name=decl.spelling,
    #            namespace=namespace,
    #            type=decl.type.spelling
    #        )
    #    )# if decl.spelling not in ("True", "False") else None
    #    #if decl.spelling in ("True", "False"):
    #    #            continue
    #    #        objs.append(ConstantData(
    #    #            name=decl.spelling,
    #    #            type=decl.type.spelling
    #    #        ))

    @classmethod
    def _make_xml(
        cls: type[Self],
        tag: str,
        attrib: dict[str, str | None],
        subelements: Iterable[etree.Element] | None = None
    ) -> etree.Element:
        xml = etree.Element(tag, {k: v for k, v in attrib.items() if v is not None})
        if subelements is not None:
            xml.extend(tuple(subelements))
        return xml

    @classmethod
    def _str_from_extent(
        cls: type[Self],
        extent: clang.SourceRange
    ) -> str:
        content = cls._get_content(extent.start.file.name)
        result = content[extent.start.offset - extent.start.line + 1 : extent.end.offset - extent.end.line + 1]
        result = re.sub(r"\s+", " ", result.replace("\n", " "))
        #if result.startswith("VULKAN_HPP_NAMESPACE::ShaderStageFlags"):
        #    #print(content[extent.start.offset - extent.start.line + 1 : extent.end.offset - extent.end.line + 1])
        #    file_content_lines = content.splitlines()
        #    print(
        #        file_content_lines[extent.start.line - 1][extent.start.column - 1:extent.end.column - 1]
        #        if extent.start.line == extent.end.line
        #        else "\n".join((
        #            file_content_lines[extent.start.line - 1][extent.start.column - 1:],
        #            *file_content_lines[extent.start.line:extent.end.line - 1],
        #            file_content_lines[extent.end.line - 1][:extent.end.column - 1]
        #        ))
        #    )
        return result

    @classmethod
    def _extract_template(
        cls: type[Self],
        decl: clang.Cursor
    ) -> str | None:
        decl_str = cls._str_from_extent(decl.extent)
        if (match := re.search(fr"\btemplate <(.*?)>", re.split(fr"\b{decl.spelling}\b", decl_str, 1)[0])) is None:
            return None
        return match.group()

    @classmethod
    def _extract_rvalue(
        cls: type[Self],
        decl: clang.Cursor
    ) -> str | None:
        decl_str = cls._str_from_extent(decl.extent)
        if "=" not in decl_str:
            return None
        return decl_str.split("=", 1)[1].strip()

    @staticmethod
    @lru_cache()
    def _get_content(
        filename: str
    ) -> str:
        return pathlib.Path(filename).read_text()

    #@classmethod
    #def _extract_filename(
    #    cls: type[Self],
    #    name: str
    #) -> str | None:
    #    if name == "vulkan/vulkan.cppm":
    #        return name
    #    return cls._slice_right(name.replace("\\", "/"), "includes/")

    #@classmethod
    #def _slice_right(
    #    cls: type[Self],
    #    s: str,
    #    sub: str
    #) -> str | None:
    #    return s[index + len(sub):] if (index := s.rfind(sub)) != -1 else None


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

xml = HeaderParser("includes/vulkan/vulkan.cppm", "includes").parse()
assert xml is not None
etree.indent(xml)
etree.ElementTree(xml).write("registry.xml")
