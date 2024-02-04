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
        "_src_file",
        "_include_dir"
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
        self._include_dir: str = include_dir

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
                for child in type(self)._iter_namespace_child(child_decl, "", self._include_dir)
            )
        )

    @classmethod
    def _iter_namespace_child(
        cls: type[Self],
        decl: clang.Cursor,
        namespace: str,
        include_dir: str
    ) -> Iterator[etree.Element]:
        filename = str(pathlib.Path(decl.location.file.name).relative_to(include_dir)).replace("\\", "/")
        match decl.kind:
            case CursorKind.NAMESPACE:
                yield cls._make_xml(
                    "namespace",
                    dict(
                        name=decl.spelling,
                        namespace=namespace,
                        filename=filename
                    )
                )
                new_namespace = f"{namespace}::{decl.spelling}"
                for child_decl in decl.get_children():
                    yield from cls._iter_namespace_child(child_decl, new_namespace, include_dir)
            case CursorKind.USING_DECLARATION:
                for index in range(lib.clang_getNumOverloadedDecls(decl.referenced)):
                    def_decl = lib.clang_getOverloadedDecl(decl.referenced, index)
                    if def_decl is not None and def_decl.is_definition():
                        yield from cls._iter_namespace_child(def_decl, namespace, include_dir)
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
                    ),
                    (
                        child
                        for child_decl in decl.get_children()
                        for child in cls._iter_class_child(child_decl)
                    )
                )
            case CursorKind.FUNCTION_DECL | CursorKind.FUNCTION_TEMPLATE:
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
            case CursorKind.VAR_DECL:
                yield cls._make_xml(
                    "constant",
                    dict(
                        name=decl.spelling,
                        namespace=namespace
                    )
                )

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
                    "field",
                    dict(
                        name=decl.spelling,
                        type=decl.type.spelling
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


xml = HeaderParser(
    src_file="extern/vulkan/Include/vulkan/vulkan.cppm",
    include_dir="extern/vulkan/Include"
).parse()
assert xml is not None
etree.indent(xml)
etree.ElementTree(xml).write("hpp_registry.xml")
