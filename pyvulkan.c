#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <numpy/ndarrayobject.h>


static uint64_t PYVKEnumDemo_A = 5;
static uint64_t PYVKEnumDemo_B = 12;

static uint64_t PYVKFlagDemo_C = 55;
static uint64_t PYVKFlagDemo_D = 118;

typedef uint32_t VkBool32;

typedef enum {
    VK_STRUCTURE_TYPE_STRUCT_DEMO = 0
} VkStructureType;


// base class

typedef struct {
    PyObject_HEAD
} PYVK_Data_Object;

static void
PYVK_Data_dealloc(PyObject *self) {
    Py_TYPE(self)->tp_free(self);
}

static PyTypeObject PYVK_Data_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Data",
    .tp_basicsize = sizeof(PYVK_Data_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_dealloc = PYVK_Data_dealloc
};


static PyTypeObject PYVK_Enum_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Enum",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &PYVK_Data_Type
};


// enums

typedef struct {
    PyObject_HEAD
    uint64_t value;
} PYVK_Enum64_Object;

static PyObject *
PYVK_Enum64_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<%s: %llu>", Py_TYPE(self)->tp_name, ((PYVK_Enum64_Object *)self)->value);
    return result;
}

static Py_hash_t
PYVK_Enum64_hash(PyObject *self) {
    Py_hash_t result = ((PYVK_Enum64_Object *)self)->value & ~(Py_hash_t)0;
    if (result == -1) {
        result = -2;
    }
    return result;
}

static PyObject *
PYVK_Enum64_richcompare(PyObject *self, PyObject *other, int op) {
    switch (op) {
        case Py_EQ:
            return (
                Py_TYPE(self) != Py_TYPE(other) ? Py_False :
                ((PYVK_Enum64_Object *)self)->value != ((PYVK_Enum64_Object *)other)->value ? Py_False :
                Py_True
            );
        case Py_NE:
            return (
                Py_TYPE(self) != Py_TYPE(other) ? Py_True :
                ((PYVK_Enum64_Object *)self)->value != ((PYVK_Enum64_Object *)other)->value ? Py_True :
                Py_False
            );
    }
    return Py_NotImplemented;
}

static PyTypeObject PYVK_Enum64_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Enum64",
    .tp_basicsize = sizeof(PYVK_Enum64_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_repr = PYVK_Enum64_repr,
    .tp_hash = PYVK_Enum64_hash,
    .tp_richcompare = PYVK_Enum64_richcompare,
    .tp_base = &PYVK_Enum_Type
};


static PyObject *
PYVK_Flag64_invert(PyObject *self) {
    PyObject *result = Py_TYPE(self)->tp_alloc(Py_TYPE(self), 0);
    ((PYVK_Enum64_Object *)result)->value = ~((PYVK_Enum64_Object *)self)->value;
    return result;
}

static PyObject *
PYVK_Flag64_and(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    PyObject *result = Py_TYPE(self)->tp_alloc(Py_TYPE(self), 0);
    ((PYVK_Enum64_Object *)result) = ((PYVK_Enum64_Object *)self)->value & ((PYVK_Enum64_Object *)other)->value;
    return result;
}

static PyObject *
PYVK_Flag64_xor(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    PyObject *result = Py_TYPE(self)->tp_alloc(Py_TYPE(self), 0);
    ((PYVK_Enum64_Object *)result) = ((PYVK_Enum64_Object *)self)->value ^ ((PYVK_Enum64_Object *)other)->value;
    return result;
}

static PyObject *
PYVK_Flag64_or(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    PyObject *result = Py_TYPE(self)->tp_alloc(Py_TYPE(self), 0);
    ((PYVK_Enum64_Object *)result) = ((PYVK_Enum64_Object *)self)->value | ((PYVK_Enum64_Object *)other)->value;
    return result;
}

static PyNumberMethods PYVK_Flag64_as_number = {
    .nb_invert = PYVK_Flag64_invert,
    .nb_and = PYVK_Flag64_and,
    .nb_xor = PYVK_Flag64_xor,
    .nb_or = PYVK_Flag64_or
};

static PyTypeObject PYVK_Flag64_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Flag64",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_as_number = &PYVK_Flag64_as_number,
    .tp_base = &PYVK_Enum64_Type
};


static PyTypeObject PYVK_EnumMeta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._EnumMeta",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &PYVK_Data_Type
};


typedef struct {
    PyObject_HEAD
    PyTypeObject *enum64_cls;
} PYVK_Enum64Meta_Object;

static PyObject *
PYVK_Enum64Meta_get(PyObject *self, void *closure) {
    PYVK_Enum64_Object *result = PyObject_New(PYVK_Enum64_Object, ((PYVK_Enum64Meta_Object *)self)->enum64_cls);
    result->value = *(uint64_t *)closure;
    return result;
}

static PyObject *
PYVK_Enum64Meta_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<enum64 '%s'>", ((PYVK_Enum64Meta_Object *)self)->enum64_cls->tp_name);
    return result;
}

static PyTypeObject PYVK_Enum64Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Enum64Meta",
    .tp_basicsize = sizeof(PYVK_Enum64Meta_Object),
    .tp_repr = PYVK_Enum64Meta_repr,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &PYVK_EnumMeta_Type
};

static PyObject *
PYVK_Flag64Meta_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<flag64 '%s'>", ((PYVK_Enum64Meta_Object *)self)->enum64_cls->tp_name);
    return result;
}

static PyTypeObject PYVK_Flag64Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Flag64Meta",
    .tp_repr = PYVK_Flag64Meta_repr,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &PYVK_Enum64Meta_Type
};


static PyGetSetDef PYVKEnumDemo_Meta_getset[] = {
    {
        .name = "A",
        .get = PYVK_Enum64Meta_get,
        .closure = (void *)&PYVKEnumDemo_A
    },
    {
        .name = "B",
        .get = PYVK_Enum64Meta_get,
        .closure = (void *)&PYVKEnumDemo_B
    },
    {NULL}
};

static PyTypeObject PYVKEnumDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.EnumDemo",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    .tp_base = &PYVK_Enum64_Type
};

static PyTypeObject PYVKEnumDemo_Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.EnumDemo_Meta",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    .tp_getset = PYVKEnumDemo_Meta_getset,
    .tp_base = &PYVK_Enum64Meta_Type
};

static PYVK_Enum64Meta_Object PYVKEnumDemo_Meta_Object = {
    PyObject_HEAD_INIT(&PYVKEnumDemo_Meta_Type)
    .enum64_cls = &PYVKEnumDemo_Type
};  // final


static PyGetSetDef PYVKFlagDemo_Meta_getset[] = {
    {
        .name = "C",
        .get = PYVK_Enum64Meta_get,
        .closure = (void *)&PYVKFlagDemo_C
    },
    {
        .name = "D",
        .get = PYVK_Enum64Meta_get,
        .closure = (void *)&PYVKFlagDemo_D
    },
    {NULL}
};

static PyTypeObject PYVKFlagDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.FlagDemo",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    .tp_base = &PYVK_Flag64_Type
};

static PyTypeObject PYVKFlagDemo_Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.FlagDemo_Meta",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    .tp_getset = PYVKFlagDemo_Meta_getset,
    .tp_base = &PYVK_Flag64Meta_Type
};

static PYVK_Enum64Meta_Object PYVKFlagDemo_Meta_Object = {
    PyObject_HEAD_INIT(&PYVKFlagDemo_Meta_Type)
    .enum64_cls = &PYVKFlagDemo_Type
};  // final


// c -> py converters

static PyObject *
PYVK_Construct__PyBytes__char_p(const char *csrc) {
    return PyBytes_FromString(csrc);
}

static PyObject *
PYVK_Construct__PyBytes__char_x16(const char csrc[16]) {
    return PyBytes_FromString(csrc);
}

// Use PyArray_SimpleNew, memcpy for 1d arrays
// PyObject *pydst = PyArray_SimpleNew(0, NULL, NPY_UINT32);
// if (!pydst) {
//     return NULL;
// }
// memcpy(PyArray_DATA(pydst), &csrc, sizeof(csrc));
static PyObject *
PYVK_Construct__NPY_UINT32_Scalar__uint32(uint32_t csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_UINT32), NULL);
}

static PyObject *
PYVK_Construct__NPY_UINT64_Scalar__uint64(uint64_t csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_UINT64), NULL);
}

static PyObject *
PYVK_Construct__NPY_FLOAT_Scalar__float(float csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_FLOAT), NULL);
}

static PyObject *
PYVK_Construct__NPY_UINT32_Scalar__bool32(VkBool32 csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_UINT32), NULL);
}

static PyObject *
PYVK_Construct__PYVKStructDemo__VkStructDemo_p(VkStructDemo *csrc) {

}

static PyObject *
PYVK_Construct__PYVK_Struct__pNext(void *csrc) {
    switch (*(VkStructureType *)csrc) {
        case VK_STRUCTURE_TYPE_STRUCT_DEMO:
            return PYVK_Construct__PYVKStructDemo__VkStructDemo_p(*(VkStructDemo *)csrc);
    }
    PyErr_Format(PyExc_RuntimeError, "Unrecognized pNext field");
    return NULL;
}


// py -> c converters

// 1d, 2d, 3d arrays - PyArray_AsCArray & PyArray_Free
static int
PYVK_Convert__ScalarLike__uint32(PyObject *pysrc, uint32_t *cdst) {
    PyObject *array = PyArray_FROM_OTF(pysrc, NPY_UINT32, NPY_ARRAY_FORCECAST);
    if (!array || !PyArray_IsZeroDim(array)) {
        Py_CLEAR(array);
        if (!PyErr_Occurred()) {
            PyErr_Format(PyExc_TypeError, "Cannot convert %s into uint32", Py_TYPE(pysrc)->tp_name);
        }
        return -1;
    }
    *cdst = *(uint32_t *)PyArray_DATA(array);
    Py_CLEAR(array);
    return 0;
}

static int
PYVK_Convert__ScalarLike__uint64(PyObject *pysrc, uint64_t *cdst) {
    PyObject *array = PyArray_FROM_OTF(pysrc, NPY_UINT64, NPY_ARRAY_FORCECAST);
    if (!array || !PyArray_IsZeroDim(array)) {
        Py_CLEAR(array);
        if (!PyErr_Occurred()) {
            PyErr_Format(PyExc_TypeError, "Cannot convert %s into uint64", Py_TYPE(pysrc)->tp_name);
        }
        return -1;
    }
    *cdst = *(uint64_t *)PyArray_DATA(array);
    Py_CLEAR(array);
    return 0;
}

static int
PYVK_Convert__ScalarLike__float(PyObject *pysrc, float *cdst) {
    PyObject *array = PyArray_FROM_OTF(pysrc, NPY_FLOAT, NPY_ARRAY_FORCECAST);
    if (!array || !PyArray_IsZeroDim(array)) {
        Py_CLEAR(array);
        if (!PyErr_Occurred()) {
            PyErr_Format(PyExc_TypeError, "Cannot convert %s into float", Py_TYPE(pysrc)->tp_name);
        }
        return -1;
    }
    *cdst = *(float *)PyArray_DATA(array);
    Py_CLEAR(array);
    return 0;
}

static int
PYVK_Convert__ScalarLike__bool32(PyObject *pysrc, VkBool32 *cdst) {
    PyObject *array = PyArray_FROM_OTF(pysrc, NPY_BOOL, NPY_ARRAY_FORCECAST);
    if (!array || !PyArray_IsZeroDim(array)) {
        Py_CLEAR(array);
        if (!PyErr_Occurred()) {
            PyErr_Format(PyExc_TypeError, "Cannot convert %s into VkBool32", Py_TYPE(pysrc)->tp_name);
        }
        return -1;
    }
    Py_SETREF(array, PyArray_CastToType(array, PyArray_DescrFromType(NPY_UINT32), 0));
    *cdst = *(VkBool32 *)PyArray_DATA(array);
    Py_CLEAR(array);
    return 0;
}

static int
PYVK_Convert__BytesLike__char_p(PyObject *pysrc, const char **cdst) {
    const char *str = (
        PyBytes_Check(pysrc) ? PyBytes_AsString(pysrc) :
        PyUnicode_Check(pysrc) ? PyUnicode_AsUTF8(pysrc) :
        NULL
    );
    if (!str) {
        if (!PyErr_Occurred()) {
            PyErr_Format(PyExc_TypeError, "Cannot convert %s into char_p", Py_TYPE(pysrc)->tp_name);
        }
        return -1;
    }
    size_t buffer_size = (strlen(str) + 1) * sizeof(char);
    *cdst = PyMem_RawMalloc(buffer_size);
    memcpy(*cdst, str, buffer_size);
    return 0;
    //*pydst = (
    //    PyUnicode_Check(pysrc) ? PyUnicode_AsEncodedString(pysrc, "utf-8", "strict") :
    //    PyBytes_Check(pysrc) ? Py_NewRef(pysrc) :
    //    NULL
    //);
    //if (!*pydst) {
    //    PyErr_Format(PyExc_TypeError, "Cannot convert %s into bytes", Py_TYPE(pysrc)->tp_name);
    //    return 0;
    //}
    //if (PyErr_Occurred()) {
    //    *pydst = NULL;
    //    return 0;
    //}
    //return 1;
}


// unions

static PyTypeObject PYVK_Union_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Union",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &PYVK_Data_Type
};


typedef union {
    uint32_t value32;
    uint64_t value64;
    float valueFloat;
    VkBool32 valueBool;
    const char *valueString;
} VkPerformanceValueDataINTEL;

static const char PYVKPerformanceValueDataINTEL_KEY_value32[] = "value_32";
static const char PYVKPerformanceValueDataINTEL_KEY_value64[] = "value_64";
static const char PYVKPerformanceValueDataINTEL_KEY_valueFloat[] = "value_float";
static const char PYVKPerformanceValueDataINTEL_KEY_valueBool[] = "value_bool";
static const char PYVKPerformanceValueDataINTEL_KEY_valueString[] = "value_string";

typedef struct {
    PyObject_HEAD
    VkPerformanceValueDataINTEL data;
    const char *key;
} PYVKPerformanceValueDataINTEL_Object;

//static void
//PYVKPerformanceValueDataINTEL_dealloc(PyObject *self) {
//    PyObject_GC_UnTrack(self);
//    Py_CLEAR(((PYVKPerformanceValueDataINTEL_Object *)self)->ref);
//    Py_TYPE(self)->tp_free(self);
//}

//static PyObject *
//PYVKPerformanceValueDataINTEL_repr(PyObject *self) {
//    const char *key = ((PYVKPerformanceValueDataINTEL_Object *)self)->key;
//    PyObject *arg = PyObject_GetAttrString(self, key);
//    if (!arg) {
//        return NULL;
//    }
//    PyObject *result = PyUnicode_FromFormat("%s(%s=%R)", Py_TYPE(self)->tp_name, key, arg);
//    Py_CLEAR(arg);
//    return result;
//}

//static int
//PYVKPerformanceValueDataINTEL_traverse(PyObject *self, visitproc visit, void *arg) {
//    Py_VISIT(((PYVKPerformanceValueDataINTEL_Object *)self)->ref);
//    return 0;
//}

//static int
//PYVKPerformanceValueDataINTEL_clear(PyObject *self) {
//    Py_CLEAR(((PYVKPerformanceValueDataINTEL_Object *)self)->ref);
//    return 0;
//}

static PyObject *
PYVKPerformanceValueDataINTEL_get__address(PyObject *self, void *Py_UNUSED(closure)) {
    return PyLong_FromVoidPtr(&((PYVKPerformanceValueDataINTEL_Object *)self)->data);
}

static PyObject *
PYVKPerformanceValueDataINTEL_get_value32(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PYVKPerformanceValueDataINTEL_Object *)self)->key != PYVKPerformanceValueDataINTEL_KEY_value32) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PYVKPerformanceValueDataINTEL_Object *)self)->key, PYVKPerformanceValueDataINTEL_KEY_value32);
        return NULL;
    }
    return PYVK_Construct__NPY_UINT32_Scalar__uint32(((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32);
}

static PyObject *
PYVKPerformanceValueDataINTEL_get_value64(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PYVKPerformanceValueDataINTEL_Object *)self)->key != PYVKPerformanceValueDataINTEL_KEY_value64) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PYVKPerformanceValueDataINTEL_Object *)self)->key, PYVKPerformanceValueDataINTEL_KEY_value64);
        return NULL;
    }
    return PYVK_Construct__NPY_UINT64_Scalar__uint64(((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64);
}

static PyObject *
PYVKPerformanceValueDataINTEL_get_valueFloat(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PYVKPerformanceValueDataINTEL_Object *)self)->key != PYVKPerformanceValueDataINTEL_KEY_valueFloat) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PYVKPerformanceValueDataINTEL_Object *)self)->key, PYVKPerformanceValueDataINTEL_KEY_valueFloat);
        return NULL;
    }
    return PYVK_Construct__NPY_FLOAT_Scalar__float(((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat);
}

static PyObject *
PYVKPerformanceValueDataINTEL_get_valueBool(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PYVKPerformanceValueDataINTEL_Object *)self)->key != PYVKPerformanceValueDataINTEL_KEY_valueBool) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PYVKPerformanceValueDataINTEL_Object *)self)->key, PYVKPerformanceValueDataINTEL_KEY_valueBool);
        return NULL;
    }
    return PYVK_Construct__NPY_UINT32_Scalar__bool32(((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool);
}

static PyObject *
PYVKPerformanceValueDataINTEL_get_valueString(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PYVKPerformanceValueDataINTEL_Object *)self)->key != PYVKPerformanceValueDataINTEL_KEY_valueString) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PYVKPerformanceValueDataINTEL_Object *)self)->key, PYVKPerformanceValueDataINTEL_KEY_valueString);
        return NULL;
    }
    return PYVK_Construct__PyBytes__char_p(((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString);
}

static PyGetSetDef PYVKPerformanceValueDataINTEL_getset[] = {
    {
        .name = "_address",
        .get = PYVKPerformanceValueDataINTEL_get__address
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_value32,
        .get = PYVKPerformanceValueDataINTEL_get_value32
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_value64,
        .get = PYVKPerformanceValueDataINTEL_get_value64
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_valueFloat,
        .get = PYVKPerformanceValueDataINTEL_get_valueFloat
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_valueBool,
        .get = PYVKPerformanceValueDataINTEL_get_valueBool
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_valueString,
        .get = PYVKPerformanceValueDataINTEL_get_valueString
    },
    {NULL}
};

// def _new__(
//     cls,
//     /,
//     *,
//     value_32: SupportsInt = ...,
//     value_64: SupportsInt = ...,
//     value_float: SupportsFloat = ...,
//     value_bool: bool = ...,
//     value_string: str = ...
// ) -> PerformanceValueDataINTEL: ...
static PyObject *
PYVKPerformanceValueDataINTEL_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    static const char *kwlist[] = {
        PYVKPerformanceValueDataINTEL_KEY_value32,
        PYVKPerformanceValueDataINTEL_KEY_value64,
        PYVKPerformanceValueDataINTEL_KEY_valueFloat,
        PYVKPerformanceValueDataINTEL_KEY_valueBool,
        PYVKPerformanceValueDataINTEL_KEY_valueString,
        {NULL}
    };
    PyObject *self = NULL;
    PyObject *arg_value32 = NULL;
    PyObject *arg_value64 = NULL;
    PyObject *arg_valueFloat = NULL;
    PyObject *arg_valueBool = NULL;
    PyObject *arg_valueString = NULL;

    self = Py_TYPE(cls)->tp_alloc(Py_TYPE(cls), 0);
    if (!self) {
        goto error;
    }
    if (!PyArg_ParseTupleAndKeywords(
        args, kwds, "|$OOOOO", kwlist,
        &arg_value32, &arg_value64, &arg_valueFloat, &arg_valueBool, &arg_valueString
    )) {
        goto error;
    }
    if (PyDict_Size(kwds) != 1) {
        PyErr_Format(PyExc_TypeError, "Must specify exactly 1 field via keyword argument for union %s()", cls->tp_name);
        goto error;
    }
    if ((
        arg_value32 ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value32, PYVK_Convert__ScalarLike__uint32(arg_value32, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32)) :
        arg_value64 ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value64, PYVK_Convert__ScalarLike__uint64(arg_value64, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64)) :
        arg_valueFloat ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueFloat, PYVK_Convert__ScalarLike__float(arg_valueFloat, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat)) :
        arg_valueBool ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueBool, PYVK_Convert__ScalarLike__bool32(arg_valueBool, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool)) :
        arg_valueString ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueString, PYVK_Convert__BytesLike__char_p(arg_valueString, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString)) :
        0
    ) < 0) {
        goto error;
    }
    return self;

error:
    Py_CLEAR(self);
    return NULL;
}

static void
PYVKPerformanceValueDataINTEL_free(void *self) {
    const char *key = ((PYVKPerformanceValueDataINTEL_Object *)self)->key;
    VkPerformanceValueDataINTEL *data = &((PYVKPerformanceValueDataINTEL_Object *)self)->data;
    if (
        key == PYVKPerformanceValueDataINTEL_KEY_valueString ? (PyMem_RawFree(data->valueString), data->valueString = NULL, 0) :
        0
    ) {}
    PyObject_Free(self);
}

static PyTypeObject PYVKPerformanceValueDataINTEL_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.PerformanceValueDataINTEL",
    .tp_basicsize = sizeof(PYVKPerformanceValueDataINTEL_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    //.tp_repr = PYVKPerformanceValueDataINTEL_repr,
    .tp_getset = PYVKPerformanceValueDataINTEL_getset,
    .tp_base = &PYVK_Union_Type,
    .tp_new = PYVKPerformanceValueDataINTEL_new,
    .tp_free = PYVKPerformanceValueDataINTEL_free
};


// structs

static PyTypeObject PYVK_Struct_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Struct",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &PYVK_Data_Type
};



typedef struct {
    VkStructureType sType;
    const char *pStr;
    const char str16[16];
    void *pNext;
    float matrix[3][4];
    uint32_t valueCount;
    uint32_t *values;
    PerformanceValueDataINTEL *child;  // optional: can be NULL
    uint32_t childrenCount;
    PerformanceValueDataINTEL *children;
} VkStructDemo;

static const char PYVKStructDemo_KEY_sType[] = "s_type";
static const char PYVKStructDemo_KEY_pStr[] = "str";
static const char PYVKStructDemo_KEY_str16[] = "str16";
static const char PYVKStructDemo_KEY_pNext[] = "next";
static const char PYVKStructDemo_KEY_matrix[] = "matrix";
static const char PYVKStructDemo_KEY_valueCount[] = "value_count";
static const char PYVKStructDemo_KEY_values[] = "values";
static const char PYVKStructDemo_KEY_child[] = "child";
static const char PYVKStructDemo_KEY_childrenCount[] = "children_count";
static const char PYVKStructDemo_KEY_children[] = "children";

typedef struct {
    PyObject_HEAD
    VkStructDemo data;
} PYVKStructDemo_Object;

static PyObject *
PYVKStructDemo_get__address(PyObject *self, void *Py_UNUSED(closure)) {
    return PyLong_FromVoidPtr(&((PYVKStructDemo_Object *)self)->data);
}

static PyObject *
PYVKStructDemo_get_pStr(PyObject *self, void *Py_UNUSED(closure)) {
    return PYVK_Construct__PyBytes__char_p(((PYVKStructDemo_Object *)self)->data.pStr);
}

static PyObject *
PYVKStructDemo_get_str16(PyObject *self, void *Py_UNUSED(closure)) {
    return PYVK_Construct__PyBytes__char_x16(((PYVKStructDemo_Object *)self)->data.str16);
}

static PyObject *
PYVKStructDemo_get_pNext(PyObject *self, void *Py_UNUSED(closure)) {
    return PYVK_Construct__PYVK_Struct__pNext(((PYVKStructDemo_Object *)self)->data.pNext);
}

static PyObject *
PYVKStructDemo_get_matrix(PyObject *self, void *Py_UNUSED(closure)) {
    return PYVK_Construct__NPY_FLOAT_Array2D__float_x3_x4(((PYVKStructDemo_Object *)self)->data.matrix);
}

static PyObject *
PYVKStructDemo_get_valueCount(PyObject *self, void *Py_UNUSED(closure)) {
    return PYVK_Construct__NPY_UINT32_Scalar__uint32(((PYVKStructDemo_Object *)self)->data.valueCount);
}

static PyObject *
PYVKStructDemo_get_values(PyObject *self, void *Py_UNUSED(closure)) {
    return PYVK_Construct__NPY_UINT32_Array1D__uint32_p(((PYVKStructDemo_Object *)self)->data.values, ((PYVKStructDemo_Object *)self)->data.valueCount);
}

static PyObject *
PYVKStructDemo_get_child(PyObject *self, void *Py_UNUSED(closure)) {
    return PYVK_Construct__PYVKPerformanceValueDataINTEL_Optional__VkPerformanceValueDataINTEL_p(((PYVKStructDemo_Object *)self)->data.child);
}

static PyObject *
PYVKStructDemo_get_childrenCount(PyObject *self, void *Py_UNUSED(closure)) {
    return PYVK_Construct__NPY_UINT32_Scalar__uint32(((PYVKStructDemo_Object *)self)->data.childrenCount);
}

static PyObject *
PYVKStructDemo_get_children(PyObject *self, void *Py_UNUSED(closure)) {
    return PYVK_Construct__PYVKPerformanceValueDataINTEL_tuple__VkPerformanceValueDataINTEL_p(((PYVKStructDemo_Object *)self)->data.children, ((PYVKStructDemo_Object *)self)->data.childrenCount);
}

static PyGetSetDef PYVKStructDemo_getset[] = {
    {
        .name = "_address",
        .get = PYVKStructDemo_get__address
    },
    {
        .name = PYVKStructDemo_KEY_pStr,
        .get = PYVKStructDemo_get_pStr
    },
    {
        .name = PYVKStructDemo_KEY_str16,
        .get = PYVKStructDemo_get_str16
    },
    {
        .name = PYVKStructDemo_KEY_pNext,
        .get = PYVKStructDemo_get_pNext
    },
    {
        .name = PYVKStructDemo_KEY_matrix,
        .get = PYVKStructDemo_get_matrix
    },
    {
        .name = PYVKStructDemo_KEY_valueCount,
        .get = PYVKStructDemo_get_valueCount
    },
    {
        .name = PYVKStructDemo_KEY_values,
        .get = PYVKStructDemo_get_values
    },
    {
        .name = PYVKStructDemo_KEY_child,
        .get = PYVKStructDemo_get_child
    },
    {
        .name = PYVKStructDemo_KEY_childrenCount,
        .get = PYVKStructDemo_get_childrenCount
    },
    {
        .name = PYVKStructDemo_KEY_children,
        .get = PYVKStructDemo_get_children
    },
    {NULL}
};

static PyObject *
PYVKStructDemo_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    static const char *kwlist[] = {
        PYVKStructDemo_KEY_pStr,
        PYVKStructDemo_KEY_str16,
        PYVKStructDemo_KEY_pNext,
        PYVKStructDemo_KEY_matrix,
        PYVKStructDemo_KEY_valueCount,
        PYVKStructDemo_KEY_values,
        PYVKStructDemo_KEY_child,
        PYVKStructDemo_KEY_childrenCount,
        PYVKStructDemo_KEY_children,
        {NULL}
    };
    PyObject *self = NULL;
    PyObject *arg_str16 = NULL;
    PyObject *arg_pNext = NULL;
    PyObject *arg_matrix = NULL;
    PyObject *arg_valueCount = NULL;
    PyObject *arg_values = NULL;
    PyObject *arg_child = NULL;
    PyObject *arg_childrenCount = NULL;
    PyObject *arg_children = NULL;

    self = Py_TYPE(cls)->tp_alloc(Py_TYPE(cls), 0);
    if (!self) {
        goto error;
    }
    if (!PyArg_ParseTupleAndKeywords(
        args, kwds, "|OOOOOOOO", kwlist,
        &arg_str16, &arg_pNext, &arg_matrix, &arg_valueCount, &arg_values, &arg_child, &arg_childrenCount, &arg_children
    )) {
        goto error;
    }
    if ((
        arg_value32 ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value32, PYVK_Convert__ScalarLike__uint32(arg_value32, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32)) :
        arg_value64 ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value64, PYVK_Convert__ScalarLike__uint64(arg_value64, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64)) :
        arg_valueFloat ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueFloat, PYVK_Convert__ScalarLike__float(arg_valueFloat, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat)) :
        arg_valueBool ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueBool, PYVK_Convert__ScalarLike__bool32(arg_valueBool, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool)) :
        arg_valueString ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueString, PYVK_Convert__BytesLike__char_p(arg_valueString, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString)) :
        0
    ) < 0) {
        goto error;
    }
    return self;

error:
    Py_CLEAR(self);
    return NULL;
}





static PyModuleDef pyvulkan_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "pyvulkan",
    .m_doc = "Example module that creates an extension type.",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_pyvulkan(void) {
    import_array();
    if (PyErr_Occurred() || !PyArray_API) {
        return NULL;
    }

    PyObject *module = PyModule_Create(&pyvulkan_module);
    if (!module) {
        return NULL;
    }
    if (
        PyType_Ready(&PYVK_Data_Type) < 0 || PyModule_AddObjectRef(module, "_Data", &PYVK_Data_Type) < 0 ||
        PyType_Ready(&PYVK_Enum_Type) < 0 || PyModule_AddObjectRef(module, "_Enum", &PYVK_Enum_Type) < 0 ||
        PyType_Ready(&PYVK_Enum64_Type) < 0 || PyModule_AddObjectRef(module, "_Enum64", &PYVK_Enum64_Type) < 0 ||
        PyType_Ready(&PYVK_Flag64_Type) < 0 || PyModule_AddObjectRef(module, "_Flag64", &PYVK_Flag64_Type) < 0 ||
        PyType_Ready(&PYVKEnumDemo_Type) < 0 || PyType_Ready(&PYVKEnumDemo_Meta_Type) < 0 || PyModule_AddObjectRef(module, "EnumDemo", &PYVKEnumDemo_Meta_Object) < 0 ||
        PyType_Ready(&PYVKFlagDemo_Type) < 0 || PyType_Ready(&PYVKFlagDemo_Meta_Type) < 0 || PyModule_AddObjectRef(module, "FlagDemo", &PYVKFlagDemo_Meta_Object) < 0 ||
        PyType_Ready(&PYVK_Union_Type) < 0 || PyModule_AddObjectRef(module, "_Union", &PYVK_Union_Type) < 0 ||
        PyType_Ready(&PYVKPerformanceValueDataINTEL_Type) < 0 || PyModule_AddObjectRef(module, "PerformanceValueDataINTEL", &PYVKPerformanceValueDataINTEL_Type) < 0 ||
        PyType_Ready(&PYVK_Struct_Type) < 0 || PyModule_AddObjectRef(module, "_Struct", &PYVK_Struct_Type) < 0 ||
        0
    ) {
        Py_CLEAR(module);
        return NULL;
    }
    return module;
}
