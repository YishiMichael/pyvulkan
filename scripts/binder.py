from __future__ import annotations

import pathlib
import re
import xml.etree.ElementTree as etree
#from dataclasses import dataclass
#from functools import lru_cache
from collections import deque
from typing import (
    Callable,
    ClassVar,
    Self,
    TextIO
)


class WordCase:
    __slots__ = ()

    verifier: ClassVar[str] = NotImplemented
    converter: ClassVar[Callable[[str], str]] = NotImplemented

    @classmethod
    def verify(
        cls: type[Self],
        word: str
    ) -> str:
        assert re.fullmatch(cls.verifier, word) is not None
        return word

    @classmethod
    def convert(
        cls: type[Self],
        word: str
    ) -> str:
        return cls.converter(word)


class UpperCase(WordCase):
    __slots__ = ()

    verifier: ClassVar[str] = r"[A-Z\d]+"
    converter: ClassVar[Callable[[str], str]] = str.upper


class LowerCase(WordCase):
    __slots__ = ()

    verifier: ClassVar[str] = r"[a-z\d]+"
    converter: ClassVar[Callable[[str], str]] = str.lower


class TitleCase(WordCase):
    __slots__ = ()

    verifier: ClassVar[str] = r"[A-Z\d][a-z\d]*"
    converter: ClassVar[Callable[[str], str]] = lambda s: f"{s[0].upper()}{s[1:].lower()}"


class ChunkCase:
    __slots__ = ()

    head_word_case: ClassVar[type[WordCase]] = WordCase
    tail_words_case: ClassVar[type[WordCase]] = WordCase
    splitter: ClassVar[str] = NotImplemented
    joiner: ClassVar[str] = NotImplemented

    @classmethod
    def split(
        cls: type[Self],
        chunk: str
    ) -> list[str]:
        words = re.split(cls.splitter, chunk)
        return [
            cls.head_word_case.verify(words[0]),
            *(cls.tail_words_case.verify(tail_word) for tail_word in words[1:])
        ]

    @classmethod
    def join(
        cls: type[Self],
        words: list[str]
    ) -> str:
        words = [
            cls.head_word_case.convert(words[0]),
            *(cls.tail_words_case.convert(tail_word) for tail_word in words[1:])
        ]
        return cls.joiner.join(words)


class UpperCamelCase(ChunkCase):
    __slots__ = ()

    head_word_case: ClassVar[type[WordCase]] = TitleCase
    tail_words_case: ClassVar[type[WordCase]] = TitleCase
    splitter: ClassVar[str] = r"(?<=[a-z])(?=[A-Z])"
    joiner: ClassVar[str] = ""


class LowerCamelCase(ChunkCase):
    __slots__ = ()

    head_word_case: ClassVar[type[WordCase]] = LowerCase
    tail_words_case: ClassVar[type[WordCase]] = TitleCase
    splitter: ClassVar[str] = r"(?<=[a-z])(?=[A-Z])"
    joiner: ClassVar[str] = ""


class UpperUnderscoreCase(ChunkCase):
    __slots__ = ()

    head_word_case: ClassVar[type[WordCase]] = UpperCase
    tail_words_case: ClassVar[type[WordCase]] = UpperCase
    splitter: ClassVar[str] = r"_"
    joiner: ClassVar[str] = "_"


class LowerUnderscoreCase(ChunkCase):
    __slots__ = ()

    head_word_case: ClassVar[type[WordCase]] = LowerCase
    tail_words_case: ClassVar[type[WordCase]] = LowerCase
    splitter: ClassVar[str] = r"_"
    joiner: ClassVar[str] = "_"


class Chunk:
    __slots__ = ("_words",)

    def __init__(
        self: Self,
        words: deque[str]
    ) -> None:
        super().__init__()
        self._words: deque[str] = words

    def copy(
        self: Self
    ) -> Self:
        return type(self)(self._words)

    def lstrip_re(
        self: Self,
        prefix_re: str
    ) -> str | None:
        if re.fullmatch(prefix_re, self._words[0]):
            return self._words.popleft()
        return None

    def rstrip_re(
        self: Self,
        suffix_re: str
    ) -> str | None:
        if re.fullmatch(suffix_re, self._words[-1]):
            return self._words.pop()
        return None

    def lstrip(
        self: Self,
        prefix: str
    ) -> None:
        assert self._words.popleft() == prefix

    def rstrip(
        self: Self,
        suffix: str
    ) -> None:
        assert self._words.popleft() == suffix

    def lconcat(
        self: Self,
        prefix: str
    ) -> None:
        self._words.appendleft(prefix)

    def rconcat(
        self: Self,
        suffix: str
    ) -> None:
        self._words.appendleft(suffix)

    @classmethod
    def from_str(
        cls: type[Self],
        chunk: str,
        chunk_case: type[ChunkCase]
    ) -> Self:
        return cls(deque(chunk_case.split(chunk)))

    def to_str(
        self: Self,
        chunk_case: type[ChunkCase]
    ) -> str:
        return chunk_case.join(list(self._words))


#class NameCases:
#    upper_camel_case: ClassVar[NameCase] = NameCase(
#        head_segment_case=SegmentCases.title_case,
#        tail_segments_case=SegmentCases.title_case,
#        splitter=r"(?<=[a-z])(?=[A-Z])",
#        joiner=""
#    )
#    lower_camel_case: ClassVar[NameCase] = NameCase(
#        head_segment_case=SegmentCases.lower_case,
#        tail_segments_case=SegmentCases.title_case,
#        splitter=r"(?<=[a-z])(?=[A-Z])",
#        joiner=""
#    )
#    upper_underscore_case: ClassVar[NameCase] = NameCase(
#        head_segment_case=SegmentCases.upper_case,
#        tail_segments_case=SegmentCases.upper_case,
#        splitter=r"_",
#        joiner="_"
#    )
#    lower_underscore_case: ClassVar[NameCase] = NameCase(
#        head_segment_case=SegmentCases.lower_case,
#        tail_segments_case=SegmentCases.lower_case,
#        splitter=r"_",
#        joiner="_"
#    )

    r"""
    def convert_name(
        name: str,
        input_case: NameCase,
        output_case: NameCase,
        *,
        remove_prefixes: tuple[str, ...] = (),
        remove_suffixes: tuple[str, ...] = (),
        append_prefixes: tuple[str, ...] = (),
        append_suffixes: tuple[str, ...] = ()
    ) -> str:

        def convert_segment(
            segment: str,
            input_case: NameCase,
            output_case: NameCase,
            is_first_segment: bool
        ) -> str:
            match input_case:
                case NameCase.UPPER_CAMEL_CASE:
                    segment_pattern = r"[A-Z\d][a-z\d]*"
                case NameCase.LOWER_CAMEL_CASE:
                    segment_pattern = r"[a-z\d]+" if is_first_segment else r"[A-Z\d][a-z\d]*"
                case NameCase.UPPER_UNDERSCORE_CASE:
                    segment_pattern = r"[A-Z\d]+"
                case NameCase.LOWER_UNDERSCORE_CASE:
                    segment_pattern = r"[a-z\d]+"
            assert re.fullmatch(segment_pattern, segment)
            lowercase_segment = segment.lower()
            match output_case:
                case NameCase.UPPER_CAMEL_CASE:
                    converter = r"[A-Z]\w*"
                case NameCase.LOWER_CAMEL_CASE:
                    converter = r"[a-z]\w*" if is_first_segment else r"[A-Z]\w*"
                case NameCase.UPPER_UNDERSCORE_CASE:
                    converter = r"[A-Z\d]+"
                case NameCase.LOWER_UNDERSCORE_CASE:
                    converter = r"[a-z\d]+"

        case_to_joiner = {
            NameCase.UPPER_CAMEL_CASE: "",
            NameCase.LOWER_CAMEL_CASE: "",
            NameCase.UPPER_UNDERSCORE_CASE: "_",
            NameCase.LOWER_UNDERSCORE_CASE: "_"
        }
        input_joiner = case_to_joiner[input_case]
        output_joiner = case_to_joiner[output_case]
        #match input_case:
        #    case NameCase.CAPITAL_CAMEL_CASE | NameCase.LOWER_CAMEL_CASE:
        #        input_joiner = ""
        #        split_pattern = r"(?<=[a-z])(?=[A-Z])"
        #    case NameCase.CAPITAL_UNDERSCORE_CASE | NameCase.LOWER_UNDERSCORE_CASE:
        #        input_joiner = "_"
        #        split_pattern = r"_"
        #match output_case:
        #    case NameCase.CAPITAL_CAMEL_CASE | NameCase.LOWER_CAMEL_CASE:
        #        output_joiner = ""
        #    case NameCase.CAPITAL_UNDERSCORE_CASE | NameCase.LOWER_UNDERSCORE_CASE:
        #        output_joiner = "_"

        #result = name
        assert name.startswith(full_remove_prefix)
        assert name.endswith(full_remove_suffix)
        return "".join((
            full_append_prefix,
            output_joiner.join(
                convert_segment(segment, input_case, output_case, index == 0)
                for index, segment in re.split(
                    r"_" if input_joiner else r"(?<=[a-z])(?=[A-Z])",
                    name.removeprefix(full_remove_prefix).removesuffix(full_remove_suffix)
                )
            ),
            full_append_suffix
        ))
        #for prefix in remove_prefixes:
        #    assert result.startswith(f"{prefix}{input_joiner}")
        #    result.removeprefix(f"{prefix}{input_joiner}")
        #for suffix in reversed(remove_suffixes):
        #    assert result.endswith(f"{input_joiner}{suffix}")
        #    result.removesuffix(f"{input_joiner}{suffix}")

        #result = output_joiner.join(
        #    convert_segment(segment, input_case, output_case, index == 0)
        #    for index, segment in re.split(r"_" if input_joiner else r"(?<=[a-z])(?=[A-Z])", result)
        #)

        #for prefix in reversed(append_prefixes):
        #    assert result.startswith(f"{prefix}{input_joiner}")
        #    result.removeprefix(f"{prefix}{input_joiner}")
        #for suffix in append_suffixes:
        #    assert result.endswith(f"{input_joiner}{suffix}")
        #    result.removesuffix(f"{input_joiner}{suffix}")
        #segments = tuple(
        #    name[start:stop]
        #    for start, stop in itertools.pairwise((
        #        0, *itertools.chain.from_iterable(
        #            match.span() for match in re.finditer(split_pattern, name)
        #        ), len(name)
        #    ))
        #    if start != stop
        #)
    """


#type StringsLike = str | tuple[str, ...]
#type NamePattern = (
#    type[NameCase]
#    | tuple[StringsLike, type[NameCase]]
#    | tuple[type[NameCase], StringsLike]
#    | tuple[StringsLike, type[NameCase], StringsLike]
#)
#type NamePattern = tuple[tuple[str, ...], type[NameCase], tuple[str, ...]]


#class Name:
#    __slots__ = ("_segments",)

#    def __init__(
#        self: Self,
#        name: str,
#        name_case: type[NameCase]
#        #name_case: NameCase,
#        #prefixes: tuple[str, ...] = (),
#        #suffixes: tuple[str, ...] = ()
#    ) -> None:
#        super().__init__()
#        #cls = type(self)
#        #prefixes, name_case, suffixes = pattern
#        #prefix = cls._build_full_prefix(prefixes, name_case.joiner)
#        #suffix = cls._build_full_suffix(suffixes, name_case.joiner)
#        #assert name.startswith(prefix) and name.endswith(suffix)
#        #name_body = name.removeprefix(prefix).removesuffix(suffix)
#        self._segments: tuple[str, ...] = name_case.split(name)

#    def to(
#        self: Self,
#        pattern: NamePattern
#    ) -> str:
#        cls = type(self)
#        prefixes, name_case, suffixes = pattern
#        prefix = cls._build_full_prefix(prefixes, name_case.joiner)
#        suffix = cls._build_full_suffix(suffixes, name_case.joiner)
#        name_body = name_case.join(self._segments)
#        return f"{prefix}{name_body}{suffix}"

    #@classmethod
    #def _parse_pattern(
    #    cls: type[Self],
    #    pattern: NamePattern
    #) -> tuple[tuple[str, ...], type[NameCase], tuple[str, ...]]:

    #    def parse_strings(
    #        strings_like: StringsLike
    #    ) -> tuple[str, ...]:
    #        return strings_like if isinstance(strings_like, tuple) else (strings_like,)

    #    match pattern:
    #        case type() as name_case:
    #            return (), name_case, ()
    #        case (prefixes, type() as name_case):
    #            return parse_strings(prefixes), name_case, ()
    #        case (type() as name_case, suffixes):
    #            return (), name_case, parse_strings(suffixes)
    #        case (prefixes, type() as name_case, suffixes):
    #            return parse_strings(prefixes), name_case, parse_strings(suffixes)

    #@classmethod
    #def _build_full_prefix(
    #    cls: type[Self],
    #    prefixes: tuple[str, ...],
    #    joiner: str
    #) -> str:
    #    return "".join(f"{prefix}{joiner}" for prefix in filter(None, prefixes))

    #@classmethod
    #def _build_full_suffix(
    #    cls: type[Self],
    #    suffixes: tuple[str, ...],
    #    joiner: str
    #) -> str:
    #    return "".join(f"{joiner}{suffix}" for suffix in filter(None, suffixes))


#@lru_cache()
#def convert_name(
#    name: str,
#    input_case: NameCase,
#    output_case: NameCase,
#    *,
#    remove_prefixes: tuple[str | None, ...] = (),
#    remove_suffixes: tuple[str | None, ...] = (),
#    append_prefixes: tuple[str | None, ...] = (),
#    append_suffixes: tuple[str | None, ...] = ()
#) -> str:
#    remove_prefix = "".join(f"{prefix}{input_case.joiner}" for prefix in filter(None, remove_prefixes))
#    remove_suffix = "".join(f"{input_case.joiner}{suffix}" for suffix in filter(None, remove_suffixes))
#    append_prefix = "".join(f"{prefix}{output_case.joiner}" for prefix in filter(None, append_prefixes))
#    append_suffix = "".join(f"{output_case.joiner}{suffix}" for suffix in filter(None, append_suffixes))

#    result = name
#    assert result.startswith(remove_prefix) and result.endswith(remove_suffix)
#    result = result.removeprefix(remove_prefix).removesuffix(remove_suffix)
#    result = output_case.joiner.join(output_case.convert_segments(input_case._verify_segments(
#        tuple(re.split(input_case.splitter, result))
#    )))
#    result = f"{append_prefix}{result}{append_suffix}"
#    return result


#class Name:
#    __slots__ = ("_segments",)

#    def __init__(
#        self: Self,
#        name: str  # UpperCamelCase or lowerCamelCase
#    ) -> None:
#        super().__init__()
#        self._segments: tuple[str, ...] = tuple(
#            name[start:stop]
#            for start, stop in itertools.pairwise((
#                0, *itertools.chain.from_iterable(
#                    match.span() for match in re.finditer(r"[A-Z][a-z]+", name)
#                ), len(name)
#            ))
#            if start != stop
#        )

#    def to_upper_underscore(
#        self: Self
#    ) -> str:
#        return "_".join(
#            segment.upper() if segment.isalpha() else segment
#            for segment in self._segments
#        )

#    def to_lower_underscore(
#        self: Self
#    ) -> str:
#        return "_".join(
#            segment.lower() if segment.isalpha() else segment
#            for segment in self._segments
#        )

#    def to_capital_camel_case(
#        self: Self
#    ) -> str:
#        return "".join(
#            segment.title() if segment.isalpha() else segment
#            for segment in self._segments
#        )

#    def removeprefix(
#        self: Self,
#        *prefixes: str
#    ) -> Name:
#        segments = self._segments
#        start_index = 1 if segments and segments[0] in prefixes else 0
#        return Name("".join(segments[start_index:]))


#def capital_camelcase_to_upper_underscore(
#    s: str
#) -> str:
#    return "_".join(
#        segment.upper() if (segment := s[start:stop]).istitle() else segment
#        for start, stop in itertools.pairwise((
#            0, *itertools.chain.from_iterable(
#                match.span() for match in re.finditer(r"[A-Z][a-z]+", s)
#            ), len(s)
#        ))
#        if start != stop
#    )


r"""
for xml in tree.getroot():
    name = xml.get("name", "")
    namespace = xml.get("namespace", "")

    match xml.tag:
        case "namespace":
            varname_prefix = "n"
            py_name = name

        case "enum":
            varname_prefix = "e"
            py_name = name
            for child_xml in xml.iterfind("member"):
                member_name = child_xml.get("name", "")
                py_member_name = Name(member_name).removeprefix("e").to_upper_underscore()
                if not py_member_name[:1].isalpha():
                    py_member_name = f"_{py_member_name}"
                child_xml.set("py_name", py_member_name)

        case "struct":
            varname_prefix = "s"
            py_name = name

            # Every struct has 3 or 4 constructor overloadings in order:
            # - Default constructor;
            # - Copy constructor;
            # - Converting constructor from the corresponding C-style struct;
            # - (optional) Enhanced constructor.
            # We pick the very last constructor, with the copy constructor
            # and the converting constructor skipped.
            prev_constructor_xml: etree.Element | None = None
            for constructor_xml in xml.iterfind("constructor"):
                argument_type_strs: list[str] = []
                for argument_xml in constructor_xml.iterfind("argument"):
                    argument_name = argument_xml.get("name", "")
                    argument_type = argument_xml.get("type", "")
                    argument_type_strs.append(argument_type)
                    argument_type_raw = (
                        f"const {namespace}::{match.group(1)} &"
                        if (match := re.fullmatch(r"const (\w+) &", argument_type)) is not None
                        else argument_type
                    )
                    argument_py_name = Name(argument_name.removesuffix("_")).to_lower_underscore()
                    argument_xml.set("py_name", argument_py_name)
                    argument_xml.set("type_raw", argument_type_raw)

                if tuple(argument_type_strs) in (
                    (f"const {name} &",),
                    (f"const Vk{name} &",)
                ):
                    constructor_xml.set("ignored", "true")
                    continue
                if prev_constructor_xml is not None:
                    prev_constructor_xml.set("ignored", "true")
                prev_constructor_xml = constructor_xml

            setter_names = set(
                Name(method_xml.get("name", "")).removeprefix("set").to_lower_underscore()
                for method_xml in xml.iterfind("method")
            )
            for field_xml in xml.iterfind("field"):
                field_name = field_xml.get("name", "")
                field_name_obj = Name(field_name)
                field_writable = field_name_obj.to_lower_underscore() in setter_names
                field_py_name = field_name_obj.removeprefix("p", "pp", "pfn").to_lower_underscore()
                if field_writable:
                    field_xml.set("writable", "true")
                field_xml.set("py_name", field_py_name)

        case "union":
            varname_prefix = "u"
            py_name = name

        case "class":
            varname_prefix = "c"
            py_name = name

            if xml.get("template_raw"):
                xml.set("ignored", "true")  # TODO

        case "function":
            varname_prefix = None
            py_name = name

        case "type_alias":
            varname_prefix = None
            py_name = name

        case "constant":
            varname_prefix = None
            py_name = Name(name).to_upper_underscore()

        case _:
            assert False

    if varname_prefix is not None:
        xml.set("varname", f"{varname_prefix}{namespace.replace("::", "_")}_{name}")
    xml.set("py_name", py_name)
"""


r'''
def get_varname(
    tag: str,
    namespace: str,
    name: str
) -> str:
    varname_prefix = {
        "namespace": "n",
        "enum": "e",
        "struct": "s",
        "union": "u",
        "class": "c"
    }.get(tag, "")
    return f"{varname_prefix}{namespace.replace("::", "_")}_{name}"


def get_py_name(
    tag: str,
    name: str
) -> str:
    if tag == "constant":
        return Name(name).to_upper_underscore()
    return name


def write_enum(
    xml: etree.Element,
    module_cpp: TextIO
) -> None:
    name = xml.get("name", "")
    namespace = xml.get("namespace", "")
    varname = get_varname(xml.tag, namespace, name)
    module_cpp.write("\n")
    for child_xml in xml:
        match child_xml.tag:
            case "member":
                member_name = child_xml.get("name", "")
                py_member_name = Name(member_name).removeprefix("e").to_upper_underscore()
                if not py_member_name[:1].isalpha():
                    py_member_name = f"_{py_member_name}"
                module_cpp.write(f"""    {varname}.value("{py_member_name}", {namespace}::{name}::{member_name});\n""")


def write_struct(
    xml: etree.Element,
    module_cpp: TextIO
) -> None:
    name = xml.get("name", "")
    namespace = xml.get("namespace", "")
    varname = get_varname(xml.tag, namespace, name)

    constructor_xml: etree.Element | None = None
    field_xml_items: list[tuple[etree.Element, str | None]] = []
    setter_names: list[str] = []
    for child_xml in xml:
        match child_xml.tag:
            case "constructor":
                # Every struct has 3 or 4 constructor overloadings in order:
                # - Default constructor;
                # - Copy constructor;
                # - Converting constructor from the corresponding C-style struct;
                # - (optional) Enhanced constructor.
                # We pick the very last constructor, with the copy constructor
                # and the converting constructor skipped.

                #argument_type_strs: list[str] = []
                #for argument_xml in child_xml.iterfind("argument"):
                #    argument_name = argument_xml.get("name", "")
                #    argument_type = argument_xml.get("type", "")
                #    argument_type_strs.append(argument_type)
                #    argument_type_raw = (
                #        f"const {namespace}::{match.group(1)} &"
                #        if (match := re.fullmatch(r"const (\w+) &", argument_type)) is not None
                #        else argument_type
                #    )
                #    argument_py_name = Name(argument_name.removesuffix("_")).to_lower_underscore()
                #    argument_xml.set("py_name", argument_py_name)
                #    argument_xml.set("type_raw", argument_type_raw)

                if tuple(
                    argument_xml.get("type", "")
                    for argument_xml in child_xml.iterfind("argument")
                ) in (
                    (f"const {name} &",),
                    (f"const Vk{name} &",)
                ):
                    continue
                constructor_xml = child_xml

            case "method":
                setter_names.append(child_xml.get("name", ""))

            case "field":
                field_name = child_xml.get("name", "")
                if (type_str := child_xml.get("type", "")).endswith("*"):
                    if field_name == "pNext" or type_str == "const char *" or type_str == "const char *const *":
                        continue
                    print(name, field_name, type_str)
                setter_name = f"set{Name(field_name).to_capital_camel_case()}"
                if setter_name not in setter_names:
                    setter_name = None
                #field_writable = Name().to_lower_underscore() in setter_names
                field_xml_items.append((child_xml, setter_name))
                #field_py_name = field_name_obj.removeprefix("p", "pp", "pfn").to_lower_underscore()



    #setter_names = set(
    #    Name(method_xml.get("name", "")).removeprefix("set").to_lower_underscore()
    #    for method_xml in xml.iterfind("method")
    #)
    #for field_xml in xml.iterfind("field"):
    #    field_name = field_xml.get("name", "")
    #    field_name_obj = Name(field_name)
    #    field_writable = field_name_obj.to_lower_underscore() in setter_names
    #    field_py_name = field_name_obj.removeprefix("p", "pp", "pfn").to_lower_underscore()
    #    if field_writable:
    #        field_xml.set("writable", "true")
    #    field_xml.set("py_name", field_py_name)
'''


class Obj:
    __slots__ = (
        "c_name",
        "cpp_name",
        "py_name",
        "protects"
    )

    def __init__(
        self: Self,
        c_name: str,
        cpp_name: str,
        py_name: str,
        #label: str = None,
        #c_pattern: NamePattern,
        #cpp_pattern: NamePattern,
        #py_pattern: NamePattern,
        protects: tuple[str, ...]
    ) -> None:
        #name = Name(c_name, c_pattern)
        self.c_name: str = c_name
        self.cpp_name: str = cpp_name
        self.py_name: str = py_name
        self.protects: tuple[str, ...] = protects

    #c_name: str
    #cpp_namespace: str

    #@property
    #@abstractmethod
    #def cpp_name(
    #    self: Self
    #) -> str:
    #    pass

    #@property
    #def cpp_qualname(
    #    self: Self
    #) -> str:
    #    return f"{self.cpp_namespace}::{self.cpp_name}"

    #@property
    #@abstractmethod
    #def py_name(
    #    self: Self
    #) -> str:
    #    pass


class Enum(Obj):
    __slots__ = ()

    def __init__(
        self: Self,
        c_name: str,
        #enums_c_name: str,
        #bitfield: bool,
        #label: str,
        protects: tuple[str, ...],
        enums: Enums
    ) -> None:
        #enums_prefix = Name(enums_c_name, ("Vk", UpperCamelCase, "")).to(("", UpperUnderscoreCase, ""))
        enums_prefix = Name(enums.c_name, (("Vk",), UpperCamelCase, ("FlagBits" if enums.bitfield else "",))).to(((), UpperUnderscoreCase, ()))
        super().__init__(
            c_name=c_name,
            c_pattern=(("VK", enums_prefix), UpperUnderscoreCase, ("BIT" if enums.bitfield else "", label)),
            cpp_pattern=(("e",), UpperCamelCase, ()),
            py_pattern=(("e",), LowerUnderscoreCase, ()),
            #c_name_case=NameCases.upper_underscore_case,
            #cpp_name_case=NameCases.lower_camel_case,
            #py_name_case=NameCases.upper_underscore_case,
            #c_prefixes=,
            #c_suffixes=(label,),
            #cpp_prefixes=("e",),
            #py_prefixes=("e",),  # TODO: e1D
            protects=protects
        )

    #enum_c_name: str
    #label: str

    #@property
    #def cpp_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.c_name,
    #        input_case=NameCases.upper_underscore_case,
    #        output_case=NameCases.lower_camel_case,
    #        remove_prefixes=("VK", convert_name(
    #            name=self.enum_c_name,
    #            input_case=NameCases.upper_camel_case,
    #            output_case=NameCases.upper_underscore_case,
    #            remove_prefixes=("Vk",)
    #        )),
    #        remove_suffixes=(self.label,),
    #        append_prefixes=("e",)
    #    )

    #@property
    #def py_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.cpp_name,
    #        input_case=NameCases.lower_camel_case,
    #        output_case=NameCases.upper_underscore_case,
    #        remove_prefixes=("e",),
    #        append_prefixes=("e",)  # TODO: e1D
    #    )


class Constant(Obj):
    __slots__ = ()

    def __init__(
        self: Self,
        c_name: str,
        #label: str,
        protects: tuple[str, ...],
        label_re: str
    ) -> None:
        name = Name.from_str(c_name, UpperUnderscoreCase)
        name.lstrip("VK")
        label = name.lstrip_re(label_re)
        c_pattern = ("VK", "{label}", "{name:UpperUnderscoreCase}")
        cpp_pattern = ("{label}", "{name:UpperCamelCase}")
        py_pattern = ("{label}", "{name:UpperUnderscoreCase}")
        assert (match := re.fullmatch(fr"VK_(?:({"|".join(labels)})_)?(\w+)", c_name)) is not None
        label = match.group(1) or ""
        segments = UpperUnderscoreCase.split(match.group(2))
        super().__init__(
            c_name="_".join(filter(None, ("VK", label, UpperUnderscoreCase.join(segments)))),
            cpp_name="".join(filter(None, (label, UpperCamelCase.join(segments)))),
            py_name="_".join(filter(None, (label, UpperUnderscoreCase.join(segments)))),
            #c_pattern=(("VK", label), UpperUnderscoreCase, ()),
            #cpp_pattern=((label,), UpperCamelCase, ()),
            #py_pattern=((label,), UpperUnderscoreCase, ()),
            #c_name_case=NameCases.upper_underscore_case,
            #cpp_name_case=NameCases.lower_camel_case,
            #py_name_case=NameCases.upper_underscore_case,
            #c_prefixes=("VK", label),
            #cpp_prefixes=(label,),
            #py_prefixes=(label,),  # TODO: e1D
            protects=protects
        )
    #label: str

    #@property
    #def cpp_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.c_name,
    #        input_case=NameCases.upper_underscore_case,
    #        output_case=NameCases.upper_camel_case,
    #        remove_prefixes=("VK", self.label),
    #        append_prefixes=(self.label,)
    #    )

    #@property
    #def py_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.cpp_name,
    #        input_case=NameCases.upper_camel_case,
    #        output_case=NameCases.upper_underscore_case,
    #        remove_prefixes=(self.label,),
    #        append_prefixes=(self.label,)
    #    )


class Define(Obj):
    __slots__ = ()

    def __init__(
        self: Self,
        c_name: str
        #protects: tuple[str, ...]
    ) -> None:
        super().__init__(
            c_name=c_name,
            c_pattern=(("VK",), UpperUnderscoreCase, ()),
            cpp_pattern=((), LowerCamelCase, ()),
            py_pattern=((), LowerUnderscoreCase, ()),
            protects=()
            #c_name_case=NameCases.upper_underscore_case,
            #cpp_name_case=NameCases.lower_camel_case,
            #py_name_case=NameCases.lower_underscore_case,
            #c_prefixes=("VK",),
            #protects
        )

    #@property
    #def cpp_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.c_name,
    #        input_case=NameCases.upper_underscore_case,
    #        output_case=NameCases.lower_camel_case,
    #        remove_prefixes=("VK",)
    #    )

    #@property
    #def py_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.cpp_name,
    #        input_case=NameCases.lower_camel_case,
    #        output_case=NameCases.lower_underscore_case
    #    )


class Enums(Obj):
    __slots__ = (
        "bitfield",
        "members"
    )

    def __init__(
        self: Self,
        c_name: str,
        label: str,
        protects: tuple[str, ...],
        bitfield: bool
    ) -> None:
        super().__init__(
            c_name=c_name,
            c_pattern=(("Vk",), UpperCamelCase, (label,)),
            cpp_pattern=((), UpperCamelCase, (label,)),
            py_pattern=((), UpperCamelCase, (label,)),
            protects=protects
        )
        self.bitfield: bool = bitfield
        self.members: list[Enum] = []

    def append_enum(
        self: Self,
        enum: Enum
    ) -> None:
        self.members.append(enum)

    #@property
    #def cpp_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.c_name,
    #        input_case=NameCases.upper_camel_case,
    #        output_case=NameCases.upper_camel_case,
    #        remove_prefixes=("Vk",)
    #    )

    #@property
    #def py_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.cpp_name,
    #        input_case=NameCases.upper_camel_case,
    #        output_case=NameCases.upper_camel_case
    #    )


class Command(Obj):
    __slots__ = ()

    def __init__(
        self: Self,
        c_name: str,
        label: str,
        protects: tuple[str, ...]
    ) -> None:
        super().__init__(
            c_name=c_name,
            c_pattern=(("vk",), UpperCamelCase, (label,)),
            cpp_pattern=((), LowerCamelCase, (label,)),
            py_pattern=((), LowerUnderscoreCase, (label,)),
            protects=protects
        )

    #label: str

    #@property
    #def cpp_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.c_name,
    #        input_case=NameCases.upper_camel_case,
    #        output_case=NameCases.lower_camel_case,
    #        remove_prefixes=("vk",),
    #        remove_suffixes=(self.label,)
    #    )

    #@property
    #def py_name(
    #    self: Self
    #) -> str:
    #    return convert_name(
    #        name=self.cpp_name,
    #        input_case=NameCases.lower_camel_case,
    #        output_case=NameCases.lower_underscore_case
    #    )


class Type(Obj):
    __slots__ = ()

    def __init__(
        self: Self,
        c_name: str,
        label: str,
        protects: tuple[str, ...]
    ) -> None:
        super().__init__(
            c_name=c_name,
            c_pattern=(("Vk",), UpperCamelCase, (label,)),
            cpp_pattern=((), UpperCamelCase, (label,)),
            py_pattern=((), UpperCamelCase, (label,)),
            protects=protects
        )


class AliasType(Type):
    __slots__ = ("aliased_type",)

    def __init__(
        self: Self,
        c_name: str,
        aliased_type: Type,
        label: str,
        protects: tuple[str, ...]
    ) -> None:
        super().__init__(
            c_name=c_name,
            label=label,
            protects=protects
        )
        self.aliased_type: Type = aliased_type


class Handle(Type):
    __slots__ = ()


class Struct(Type):
    __slots__ = ()


class Union(Type):
    __slots__ = ()


class Requirement:
    __slots__ = (
        "_xml",
        "_feature_required",
        "_feature_removed",
        "_feature_protect",
        "_extension_required",
        "_extension_removed",
        "_extension_protect",
        #"_extension_label",
        "_extension_platform_protect"
    )

    def __init__(
        self: Self,
        xml: etree.Element
    ) -> None:
        super().__init__()
        self._xml: etree.Element = xml
        self._feature_required: bool = False
        self._feature_removed: bool = False
        self._feature_protect: str = ""
        self._extension_required: bool = False
        self._extension_removed: bool = False
        self._extension_protect: str = ""
        #self._extension_label: str = ""
        self._extension_platform_protect: str = ""

    def mark_feature(
        self: Self,
        batch_tag: str,
        protect: str
    ) -> None:
        match batch_tag:
            case "require":
                if self._feature_required:
                    assert self._feature_protect == protect
                    return
                self._feature_required = True
            case "remove":
                assert not self._feature_removed
                self._feature_removed = True
            case _:
                return
        self._feature_protect = protect

    def mark_extension(
        self: Self,
        batch_tag: str,
        #label: str,
        platform_protect: str,
        protect: str
    ) -> None:
        match batch_tag:
            case "require":
                if self._extension_required:
                    assert self._extension_protect == protect
                    #assert self._extension_label == label
                    assert self._extension_platform_protect == platform_protect
                    return
                self._extension_required = True
            case "remove":
                assert not self._extension_removed
                self._extension_removed = True
            case _:
                return
        self._extension_protect = protect
        #self._extension_label = label
        self._extension_platform_protect = platform_protect

    @property
    def xml(
        self: Self
    ) -> etree.Element:
        return self._xml

    @property
    def required(
        self: Self
    ) -> bool:
        if self._feature_required and not self._feature_removed:
            return True
        if self._extension_required and not self._extension_removed:
            return True
        return False

    #@property
    #def label(
    #    self: Self
    #) -> str:
    #    if self._feature_required and not self._feature_removed:
    #        return ""
    #    if self._extension_required and not self._extension_removed:
    #        return self._extension_label
    #    return ""

    @property
    def protects(
        self: Self
    ) -> tuple[str, ...]:
        if self._feature_required and not self._feature_removed:
            return (self._feature_protect,)
        if self._extension_required and not self._extension_removed:
            return (self._extension_protect, self._extension_platform_protect)
        return ()


#class Requirements(dict[str, dict[str, Requirement]]):
#    def __init__(
#        self: Self
#    ) -> None:
#        super().__init__(
#            type={},
#            enum={},
#            command={}
#        )

#    def add_requirement(
#        self: Self,
#        tag: str,
#        name: str,
#        xml: etree.Element
#    ) -> None:
#        #match xml.tag:
#        #    case "type":
#        #        name = xml.get("name", xml.findtext("name", ""))
#        #    case "enum":
#        #        name = xml.get("name", "")
#        #    case "command":
#        #        name = xml.findtext("proto/name", "")
#        #    case _:
#        #        assert False
#        #assert name
#        assert name not in self[tag]
#        self[tag][name] = Requirement(xml)


class Binder:
    __slots__ = (
        #"_registry_xml_tree",
        #"_platform_dict",
        #"_label_dict",
        #"_obj_dict"
        #"_define_dict",
        #"_enum_dict",
        #"_struct_dict",
        #"_union_dict",
        #"_handle_dict",
        #"_command_dict"
    )

    #def __init__(
    #    self: Self,
    #    registry_xml_tree: etree.ElementTree
    #) -> None:
    #    super().__init__()
    #    self._registry_xml_tree: etree.ElementTree = registry_xml_tree
        #self._platform_dict: dict[str, str] = {}
        #self._label_dict: dict[str, etree.Element] = {}
        #self._obj_dict: dict[str, Obj] = {}
        #self._define_dict: dict[str, Define] = {}
        #self._enum_dict: dict[str, Enum] = {}
        #self._struct_dict: dict[str, Struct] = {}
        #self._union_dict: dict[str, Union] = {}
        #self._handle_dict: dict[str, Handle] = {}
        #self._command_dict: dict[str, Command] = {}

    @classmethod
    def run(
        cls: type[Self],
        registry_xml_path: pathlib.Path,
        module_cpp_path: pathlib.Path
    ) -> None:
        objs = cls.read_registry(etree.parse(registry_xml_path).getroot())
        with module_cpp_path.open("w") as module_cpp:
            pass
        #obj_dict = self.read_registry(self._registry_xml_tree.getroot())
        #self.write_registry(obj_dict, module_cpp)

    @classmethod
    def read_registry(
        cls: type[Self],
        registry_xml: etree.Element
    ) -> list[Obj]:

        def check_api(
            xml: etree.Element
        ) -> bool:
            return (api_attr := xml.get("api")) is None or "vulkan" in api_attr.split(",")

        platform_dict: dict[str, str] = {"": ""}
        requirement_dicts: dict[str, dict[str, Requirement]] = {
            "type": {},
            "enum": {},
            "command": {}
        }
        #enum_names_dict: dict[str, list[str]] = {}
        #type_dict: dict[str, etree.Element] = {}
        #enum_member_dict: dict[str, etree.Element] = {}
        #command_dict: dict[str, etree.Element] = {}
        for xml in registry_xml:
            match xml.tag:
                case "platforms":
                    for platform_xml in xml.iterfind("platform"):
                        platform_dict[platform_xml.get("name", "")] = platform_xml.get("protect", "")
                case "types":
                    for type_xml in xml.iterfind("type"):
                        if not check_api(type_xml):
                            continue
                        type_name = type_xml.get("name", type_xml.findtext("name", ""))
                        requirement_dicts["type"][type_name] = Requirement(type_xml)
                        #type_dict[type_xml.get("name", type_xml.findtext("name", ""))] = type_xml
                case "enums":
                    #enum_names: list[str] = []
                    #if " " in (enums_name := xml.get("name", "")):
                    #    enums_name = ""
                    #enum_names_dict[enums_name] = enum_names
                    #enums_name = xml.get("name", "")
                    for enum_xml in xml.iterfind("enum"):
                        #if " " not in enums_name:
                        #    enum_xml.set("extends", enums_name)
                        enum_name = enum_xml.get("name", "")
                        requirement_dicts["enum"][enum_name] = Requirement(enum_xml)
                        #enum_names.append(enum_name)
                        #enum_member_dict[enum_xml.get("name", "")] = enum_xml
                case "commands":
                    for command_xml in xml.iterfind("command"):
                        if not check_api(command_xml):
                            continue
                        command_name = command_xml.get("name", command_xml.findtext("proto/name", ""))
                        requirement_dicts["command"][command_name] = Requirement(command_xml)
                        #command_dict[command_xml.findtext("proto/name", "")] = command_xml
                case "features":
                    for feature_xml in xml.iterfind("feature"):
                        if not check_api(feature_xml):
                            continue
                        for feature_batch_xml in feature_xml:
                            for feature_obj_xml in feature_batch_xml:
                                if not check_api(feature_obj_xml):
                                    continue
                                if (requirement_dict := requirement_dicts.get(feature_obj_xml.tag)) is None:
                                    continue
                                requirement_dict.setdefault(feature_obj_xml.get("name", ""), Requirement(feature_obj_xml)).mark_feature(
                                    batch_tag=feature_batch_xml.tag,
                                    protect=feature_obj_xml.get("protect", "")
                                )
                case "extensions":
                    for extension_xml in xml.iterfind("extension"):
                        if not check_api(extension_xml):
                            continue
                        #label = match.group(1) if (match := re.match(r"^VK_([A-Z]+)_", extension_xml.get("name", ""))) is not None else ""
                        platform_protect = platform_dict[extension_xml.get("platform", "")]
                        for extension_batch_xml in extension_xml:
                            if not check_api(extension_batch_xml):
                                continue
                            for extension_obj_xml in extension_batch_xml:
                                if not check_api(extension_obj_xml):
                                    continue
                                if (requirement_dict := requirement_dicts.get(extension_obj_xml.tag)) is None:
                                    continue
                                #print(extension_obj_xml.get("name", ""), requirement._required)
                                requirement_dict.setdefault(extension_obj_xml.get("name", ""), Requirement(extension_obj_xml)).mark_extension(
                                    batch_tag=extension_batch_xml.tag,
                                    protect=extension_obj_xml.get("protect", ""),
                                    #label=label,
                                    platform_protect=platform_protect
                                )


                        #self.read_obj(type_xml)

        enums_bitfield_dict: dict[str, bool] = {}
        enums_members_dict: dict[str, dict[str, Requirement]] = {}
        for enums_xml in registry_xml.iterfind("enums"):
            if " " in (enums_name := enums_xml.get("name", "")):
                enums_name = ""
            enums_bitfield_dict[enums_name] = enums_xml.get("type") == "bitmask"
            enums_members_dict[enums_name] = {
                (enum_name := enum_xml.get("name", "")): requirement_dicts["enum"][enum_name]
                for enum_xml in enums_xml.iterfind("enum")
            }
        for enum_name, enum_requirement in requirement_dicts["enum"].items():
            enums_members_dict[enum_requirement.xml.get("extends", "")][enum_name] = enum_requirement


        objs: list[Obj] = []
        for type_name, type_requirement in requirement_dicts["type"].items():
            if not type_requirement.required:
                continue
            match type_requirement.xml.get("category", ""):

                case "enum":
                    #if (enums_xml := registry_xml.find(f"enums[@name='{type_name}']")) is None:
                    #    continue  # TODO: alias
                    #member_requirements = {
                    #    (enum_name := enum_xml.get("name", "")): requirement_dicts["enum"][enum_name]
                    #    for enum_xml in enums_xml.iterfind("enum")
                    #} | {
                    #    enum_name: enum_requirement
                    #    for enum_name, enum_requirement in requirement_dicts["enum"].items()
                    #    if enum_requirement.xml.get("extends") == type_name
                    #}
                    bitfield = enums_bitfield_dict[type_name]
                    obj = Enums(
                        c_name=type_name,
                        label=type_requirement.label,
                        protects=type_requirement.protects,
                        bitfield=bitfield,
                        members=tuple(
                            Enum(
                                c_name=enum_name,
                                enums_c_name=type_name,
                                bitfield=bitfield,
                                label=enum_requirement.label,
                                protects=enum_requirement.protects
                            )
                            for enum_name, enum_requirement in enums_members_dict[type_name].items()
                        )
                    )
                    objs.append(obj)
        return objs

    #def read_obj(
    #    self: Self,
    #    type_xml: etree.Element
    #) -> None:
    #    #category = type_xml.get("category")
    #    #if category not in ("define", "enum", "struct", "union"):
    #    #    return
    #    c_name = type_xml.get("name", type_xml.findtext("name", ""))
    #    match type_xml.get("category"):
    #        case "define":
    #            obj = Define(c_name)

    #    name = type_xml.get("name", type_xml.findtext("name", ""))
    #    cpp_name = name.removeprefix("Vk")
    #    py_name = cpp_name
    #    if (alias := type_xml.get("alias")) is not None:
    #        cpp_alias = alias.removeprefix("Vk")
    #        py_alias = cpp_alias
    #        module_cpp.write(f"""    py::class_<vk::{cpp_name}, vk::{cpp_alias}>(n_vk, "{py_alias}");\n""")
    #        return

    #    match category:
    #        #case "bitmask":
    #        #    module_cpp.write(f"""    py::class_<vk::{cpp_name}>(n_vk, "{py_name}");\n""")
    #        case "enum":
    #            varname = f"e_vk_{cpp_name}"
    #            module_cpp.write(f"""    py::enum_<vk::{cpp_name}> {varname}(n_vk, "{py_name}");\n""")
    #        case _:
    #            char = {
    #                "struct": "s",
    #                "union": "u",
    #                #"handle": "h"
    #            }[category]
    #            varname = f"{char}_vk_{cpp_name}"
    #            module_cpp.write(f"""    py::class_<vk::{cpp_name}> {varname}(n_vk, "{py_name}");\n""")

    def write_registry(
        self: Self,
        obj_dict: dict[str, Obj],
        module_cpp: TextIO
    ) -> None:
        module_cpp.write("#include <pybind11/pybind11.h>\n")
        module_cpp.write("#include <vulkan/vulkan.hpp>\n")
        module_cpp.write("\n")
        module_cpp.write("namespace py = pybind11;\n")
        module_cpp.write("\n")
        module_cpp.write("PYBIND11_MODULE(pyvulkan, m) {\n")
        module_cpp.write(f"""    py::module n_vk = m.def_submodule("vk");\n""")
        module_cpp.write("}\n")


if __name__ == "__main__":
    Binder.run(
        registry_xml_path=pathlib.Path("extern/xml/vk.xml"),
        module_cpp_path=pathlib.Path("module.cpp")
    )


r'''
with pathlib.Path("module.cpp").open("w") as module_cpp:
    namespace_varname_dict = {"": "m"}
    for xml in tree:
        match xml.tag:
            case "types":

        #if xml.get("ignored") == "true":
        #    continue
        name = xml.get("name", "")
        namespace = xml.get("namespace", "")
        varname = get_varname(xml.tag, namespace, name)
        py_name = get_py_name(xml.tag, name)
        namespace_varname = namespace_varname_dict[namespace]
        match xml.tag:
            case "namespace":
                module_cpp.write(f"""    py::module {varname} = {namespace_varname}.def_submodule("{py_name}");\n""")
                namespace_varname_dict[f"{namespace}::{name}"] = varname
            case "enum":
                module_cpp.write(f"""    py::enum_<{namespace}::{name}> {varname}({namespace_varname}, "{py_name}");\n""")
            case "struct":# | "union" | "class":
                module_cpp.write(f"""    py::class_<{namespace}::{name}> {varname}({namespace_varname}, "{py_name}");\n""")
            case "constant":
                py_name = Name(name).to_upper_underscore()
                module_cpp.write(f"""    {namespace_varname}.attr("{py_name}") = py::cast({namespace}::{name});\n""")

    for xml in tree.getroot():
        #if xml.get("ignored") == "true":
        #    continue
        match xml.tag:
            case "enum":
                write_enum(xml, module_cpp)

            case "struct":
                write_struct(xml, module_cpp)
                #module_cpp.write("\n")
                ##varname = xml.get("varname", "")
                #for child_xml in xml:
                #    #if child_xml.get("ignored") == "true":
                #    #    continue
                #    match child_xml.tag:
                #        case "constructor":
                #            module_cpp.write(f"""    {varname}.def(py::init<{", ".join(
                #                f"{argument_xml.get("type_raw", "")}"
                #                for argument_xml in child_xml.iterfind("argument")
                #            )}>(), {", ".join(
                #                (
                #                    f"""py::arg("{argument_xml.get("py_name", "")}")"""
                #                    + (f""" = {
                #                        default
                #                        if not (default.startswith("{") and default.endswith("}"))
                #                        else "nullptr"
                #                        if (argument_type := argument_xml.get("type_raw", "")).endswith("*")
                #                        else f"{argument_type.removeprefix("const ").removesuffix(" &")}{default}"  # TODO: work?
                #                    }""" if (default := argument_xml.get("default_raw", "")) else "")
                #                )
                #                for argument_xml in child_xml.iterfind("argument")
                #            )});\n""")
                #        #case "field":




    #module_cpp.write(f"""    py::module m_raii = m_vk.def_submodule("raii");\n""")
    #namespace_to_module = {
    #    "vk": "m_vk",
    #    "vk::raii": "m_raii"
    #}
    #for xml in tree.getroot():
    #    if (prefix := {
    #        "struct": "s",
    #        "union": "u",
    #        "class": "c"
    #    }.get(xml.tag)) is None:
    #        continue
    #    name = xml.attrib["name"]
    #    namespace = xml.attrib["namespace"]
    #    varname = f"{prefix}_{namespace}_{name}"
    #    module_cpp.write(f"""    py::class_<{namespace}::{name}> {varname}({namespace_to_module[namespace]}, "{name}");\n""")

    #for xml in tree.getroot():
    #    match xml.tag:
    #        case "enum":
    #            module_cpp.write("\n")
    #            name = xml.attrib["name"]
    #            namespace = xml.attrib["namespace"]
    #            varname = f"e_{namespace}_{name}"
    #            module_cpp.write(f"""    py::enum_<{namespace}::{name}> {varname}({namespace_to_module[namespace]}, "{name}");\n""")
    #            for member_xml in xml.iterfind("member"):
    #                member_name = member_xml.attrib["name"]
    #                py_member_name = capital_camelcase_to_upper_underscore(member_name.removeprefix("e"))
    #                if py_member_name[:1].isdecimal():
    #                    py_member_name = f"_{py_member_name}"
    #                module_cpp.write(f"""    {varname}.value("{py_member_name}", {namespace}::{name}::{member_name});\n""")
    #        case "constant":
    #            module_cpp.write("\n")
    #            name = xml.attrib["name"]
    #            namespace = xml.attrib["namespace"]
    #            py_name = capital_camelcase_to_upper_underscore(name)
    #            module_cpp.write(f"""    {namespace_to_module[namespace]}.attr("{py_name}") = py::cast({namespace}::{name});\n""")

    module_cpp.write("}\n")
'''
