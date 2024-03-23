from __future__ import annotations


from enum import Enum
from typing import (
    Any,
    Literal,
    Sequence,
    SupportsFloat,
    SupportsInt,
    Union,
    overload
)
from typing_extensions import (
    Buffer,
    Self
)

import numpy as np

import template


class _PyvkObject:
    __slots__ = ("_pyvko",)

    def __init__(
        self: Self,
        _pyvko: Any
    ) -> None:
        super().__init__()
        self._pyvko: Any = _pyvko

    @property
    def _address(
        self: Self
    ) -> bytes:
        return self._pyvko._address


class _PyvkTypes:
    __slots__ = ()

    #Int = SupportsInt
    #Float = SupportsFloat
    #Number = Union[
    #    int,
    #    float,
    #    bool,
    #    np.number[Any],
    #    np.ndarray[tuple[()], np.dtype[Any]]
    #]
    #Array1d = Union[
    #    Sequence[Number],
    #    np.ndarray[tuple[int], np.dtype[Any]],
    #    bytes
    #]
    #OptionalArray1d = Array1d | None
    #Array2d = Union[
    #    Sequence[Sequence[Number]],
    #    Sequence[np.ndarray[tuple[int], np.dtype[Any]]],
    #    np.ndarray[tuple[int, int], np.dtype[Any]],
    #    bytes
    #]
    #OptionalArray2d = Array2d | None
    #Array3d = Union[
    #    Sequence[Sequence[Sequence[Number]]],
    #    Sequence[Sequence[np.ndarray[tuple[int], np.dtype[Any]]]],
    #    Sequence[np.ndarray[tuple[int, int], np.dtype[Any]]],
    #    np.ndarray[tuple[int, int, int], np.dtype[Any]],
    #    bytes
    #]
    #OptionalArray3d = Array3d | None
    #Address = Union[
    #    _PyvkObject,
    #    int
    #]
    #OptionalAddress = Address | None
    #AddressArray1d = Sequence[Address]
    #OptionalAddressArray1d = Sequence[OptionalAddress]
    #AddressOptionalArray1d = AddressArray1d | None
    #OptionalAddressOptionalArray1d = OptionalAddressArray1d | None
    #String = Union[
    #    str,
    #    bytes
    #]
    #OptionalString = String | None

    # array: Sequence[SupportsInt] | Buffer

    @staticmethod
    def as_number(
        obj: Any,
        dtype: type[np.number]
    ) -> bytes:
        match obj:
            case int() | float() | bool():
                return dtype(obj).tobytes()
            case np.number():
                return obj.astype(dtype).tobytes()
            case np.ndarray():
                assert obj.size == 1
                return obj.astype(dtype).tobytes()
            #case bytes():
            #    assert len(obj) == np.dtype(dtype).itemsize
            #    return obj
        raise TypeError(f"Type incompatible with number: {type(obj)}")

    @staticmethod
    def as_address(
        obj: Any
    ) -> bytes:
        match obj:
            case int():
                return np.uint64(obj).tobytes()
            case _PyvkObject():
                return obj._address
        raise TypeError(f"Type incompatible with address: {type(obj)}")

    @staticmethod
    def as_str(
        obj: Any
    ) -> bytes:
        match obj:
            case str():
                return obj.encode()
            case bytes():
                return obj
        raise TypeError(f"Type incompatible with str: {type(obj)}")

    @staticmethod
    def as_array(
        obj: Any,
        dtype: type[np.number[Any]],
        shape: tuple[int, ...]
    ) -> bytes:
        match obj:
            case Sequence():
                array = np.array(obj, dtype)
                assert array.shape == shape
                return array.tobytes()
            case np.ndarray():
                array = obj.astype(dtype)
                assert array.shape == shape
                return array.tobytes()
            case bytes():
                return obj
        raise TypeError(f"Type incompatible with array: {type(obj)}")

    @staticmethod
    def as_arrays(
        obj: Any,
        dtype: type[np.number[Any]],
        shape: tuple[int, ...]
    ) -> bytes:
        match obj:
            case Sequence():
                array = np.array(obj, dtype)
                assert array.shape[1:] == shape
                return array.tobytes()
            case np.ndarray():
                array = obj.astype(dtype)
                assert array.shape[1:] == shape
                return array.tobytes()
            case bytes():
                return obj
        raise TypeError(f"Type incompatible with arrays: {type(obj)}")


class EnumDemo(Enum):
    A = template.EnumDemo_A
    B = template.EnumDemo_B
    C = template.EnumDemo_C
    D = template.EnumDemo_D


class PerformanceValueDataINTEL(_PyvkObject):
    __slots__ = ("_key",)

    @overload
    def __init__(
        self,
        *,
        value_32: _PyvkTypes.Number
    ) -> None: ...

    @overload
    def __init__(
        self,
        *,
        value_64: _PyvkTypes.Number
    ) -> None: ...

    @overload
    def __init__(
        self,
        *,
        value_float: _PyvkTypes.Number
    ) -> None: ...

    @overload
    def __init__(
        self,
        *,
        value_bool: _PyvkTypes.Number
    ) -> None: ...

    @overload
    def __init__(
        self,
        *,
        value_string: _PyvkTypes.String
    ) -> None: ...

    def __init__(
        self,
        **kwargs: Any
    ) -> None:
        try:
            assert kwargs
            key, arg = kwargs.popitem()
            assert not kwargs
        except AssertionError:
            raise TypeError(f"Must specify exactly 1 field for union {type(self).__name__}() (got {len(kwargs)})") from None
        match key:
            case "value_32":
                cdata = template.PerformanceValueDataINTEL_value32(_PyvkTypes.as_number(arg, np.uint32))
            case "value_64":
                cdata = template.PerformanceValueDataINTEL_value64(_PyvkTypes.as_number(arg, np.uint64))
            case "value_float":
                cdata = template.PerformanceValueDataINTEL_valueFloat(_PyvkTypes.as_number(arg, np.float32))
            case "value_bool":
                cdata = template.PerformanceValueDataINTEL_valueBool(_PyvkTypes.as_number(arg, np.uint32))
            case "value_string":
                cdata = template.PerformanceValueDataINTEL_valueString(_PyvkTypes.as_string(arg))
            case _:
                raise TypeError(f"{key} is an invalid keyword argument for {type(self).__name__}()")
        super().__init__(cdata)
        self._key: Literal["value_32", "value_64", "value_float", "value_bool", "value_string"] = key

    def __repr__(
        self
    ) -> str:
        return f"PerformanceValueDataINTEL({self._key}={self.__getattribute__(self._key)!r})"

    @property
    def value_32(
        self
    ) -> int:
        return self._pyvko.value32

    @property
    def value_64(
        self
    ) -> int:
        return self._pyvko.value64

    @property
    def value_float(
        self
    ) -> float:
        return self._pyvko.valueFloat

    @property
    def value_bool(
        self
    ) -> bool:
        return self._pyvko.valueBool

    @property
    def value_string(
        self
    ) -> str:
        return self._pyvko.valueString
