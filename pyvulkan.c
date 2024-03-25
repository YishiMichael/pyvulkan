#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <numpy/ndarrayobject.h>


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
    PYVK_Data_Object base;
    uint64_t value;
} PYVK_Enum64_Object;

static inline PyObject *
PYVK_Enum64_New(PyTypeObject *cls, uint64_t value) {
    PyObject *self = cls->tp_alloc(cls, 0);
    ((PYVK_Enum64_Object *)self)->value = value;
    return self;
}

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
    return PYVK_Enum64_New(Py_TYPE(self), ~((PYVK_Enum64_Object *)self)->value);
}

static PyObject *
PYVK_Flag64_and(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    return PYVK_Enum64_New(Py_TYPE(self), ((PYVK_Enum64_Object *)self)->value & ((PYVK_Enum64_Object *)other)->value);
}

static PyObject *
PYVK_Flag64_xor(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    return PYVK_Enum64_New(Py_TYPE(self), ((PYVK_Enum64_Object *)self)->value ^ ((PYVK_Enum64_Object *)other)->value);
}

static PyObject *
PYVK_Flag64_or(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    return PYVK_Enum64_New(Py_TYPE(self), ((PYVK_Enum64_Object *)self)->value | ((PYVK_Enum64_Object *)other)->value);
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
    PYVK_Data_Object base;
    PyTypeObject *enum64_cls;
} PYVK_Enum64Meta_Object;

static PyObject *
PYVK_Enum64Meta_get(PyObject *self, void *closure) {
    return PYVK_Enum64_New(((PYVK_Enum64Meta_Object *)self)->enum64_cls, *(uint64_t *)closure);
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


static uint64_t PYVKEnumDemo_A = 5;
static uint64_t PYVKEnumDemo_B = 12;

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
    .base = {
        PyObject_HEAD_INIT(&PYVKEnumDemo_Meta_Type)
    },
    .enum64_cls = &PYVKEnumDemo_Type
};  // final


static uint64_t PYVKFlagDemo_C = 55;
static uint64_t PYVKFlagDemo_D = 118;

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
    .base = {
        PyObject_HEAD_INIT(&PYVKFlagDemo_Meta_Type)
    },
    .enum64_cls = &PYVKFlagDemo_Type
};  // final


// converters

typedef uint32_t VkBool32;

// Use PyArray_SimpleNew, memcpy for 1d arrays
// PyObject *pydst = PyArray_SimpleNew(0, NULL, NPY_UINT32);
// if (!pydst) {
//     return NULL;
// }
// memcpy(PyArray_DATA(pydst), &csrc, sizeof(csrc));
static PyObject *
PYVK_Scalar_From_uint32(uint32_t csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_UINT32), NULL);
    //PyObject *scalar = PyArray_SimpleNew(0, NULL, NPY_UINT32);
    //if (!scalar) {
    //    return NULL;
    //}
    //memcpy(PyArray_DATA(pydst), &csrc, sizeof(csrc));
    //return pydst;
    //*pydst = PyArray_SimpleNewFromData(0, NULL, NPY_UINT32, csrc);
    //if (!*pydst) {
    //    return -1;
    //}
    //if (PyArray_SetBaseObject((PyArrayObject *)*pydst, base) < 0) {
    //    Py_CLEAR(*pydst);
    //    *pydst = NULL;
    //    return -1;
    //}
    //Py_INCREF(base);
    //return 0;
}

static PyObject *
PYVK_Scalar_From_uint64(uint64_t csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_UINT64), NULL);
    //*pydst = PyArray_SimpleNewFromData(0, NULL, NPY_UINT64, csrc);
    //if (!*pydst) {
    //    return -1;
    //}
    //if (PyArray_SetBaseObject((PyArrayObject *)*pydst, base) < 0) {
    //    Py_CLEAR(*pydst);
    //    *pydst = NULL;
    //    return -1;
    //}
    //Py_INCREF(base);
    //return 0;
}

static PyObject *
PYVK_Scalar_From_float(float csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_FLOAT), NULL);
    //*pydst = PyArray_SimpleNewFromData(0, NULL, NPY_FLOAT, csrc);
    //if (!*pydst) {
    //    return -1;
    //}
    //if (PyArray_SetBaseObject((PyArrayObject *)*pydst, base) < 0) {
    //    Py_CLEAR(*pydst);
    //    *pydst = NULL;
    //    return -1;
    //}
    //Py_INCREF(base);
    //return 0;
}

static PyObject *
PYVK_Scalar_From_VkBool32(VkBool32 csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_UINT32), NULL);
    //*pydst = PyArray_SimpleNewFromData(0, NULL, NPY_UINT32, csrc);
    //if (!*pydst) {
    //    return -1;
    //}
    //if (PyArray_SetBaseObject((PyArrayObject *)*pydst, base) < 0) {
    //    Py_CLEAR(*pydst);
    //    *pydst = NULL;
    //    return -1;
    //}
    //Py_INCREF(base);
    //return 0;
}

static PyObject *
PYVK_Str_From_charp(const char *csrc) {
    return PyUnicode_FromString(csrc);
    //*pydst = PyBytes_FromString(*csrc);
    //if (!*pydst) {
    //    return -1;
    //}
    //return 0;
}

//static inline int
//PYVK_NPY_UINT32_0D_AS_uint32_t(PyObject *pysrc, uint32_t *cdst) {
//    *cdst = *(uint32_t *)PyArray_DATA(pysrc);
//    return 0;
//}

//static inline int
//PYVK_NPY_UINT64_0D_AS_uint64_t(PyObject *pysrc, uint64_t *cdst) {
//    *cdst = *(uint64_t *)PyArray_DATA(pysrc);
//    return 0;
//}

//static inline int
//PYVK_NPY_FLOAT_0D_AS_float(PyObject *pysrc, float *cdst) {
//    *cdst = *(float *)PyArray_DATA(pysrc);
//    return 0;
//}

//static inline int
//PYVK_NPY_UINT32_0D_AS_VkBool32(PyObject *pysrc, VkBool32 *cdst) {
//    *cdst = *(VkBool32 *)PyArray_DATA(pysrc);
//    return 0;
//}

//static inline int
//PYVK_bytes_AS_const_charp(PyObject *pysrc, const char **cdst) {
//    *cdst = PyBytes_AS_STRING(pysrc);
//    //*pyref = Py_NewRef(pysrc);
//    return 0;
//}

// 1d, 2d, 3d arrays - PyArray_AsCArray & PyArray_Free
static int
PYVK_ScalarLike_As_uint32(PyObject *pysrc, uint32_t *cdst) {
    PyObject *array = PyArray_FROM_OTF(pysrc, NPY_UINT32, NPY_ARRAY_FORCECAST);
    if (!array || !PyArray_IsZeroDim(array)) {
        Py_CLEAR(array);
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into uint32", Py_TYPE(pysrc)->tp_name);
        return -1;
    }
    *cdst = *(uint32_t *)PyArray_DATA(array);
    Py_CLEAR(array);
    return 0;
}

static int
PYVK_ScalarLike_As_uint64(PyObject *pysrc, uint64_t *cdst) {
    PyObject *array = PyArray_FROM_OTF(pysrc, NPY_UINT64, NPY_ARRAY_FORCECAST);
    if (!array || !PyArray_IsZeroDim(array)) {
        Py_CLEAR(array);
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into uint64", Py_TYPE(pysrc)->tp_name);
        return -1;
    }
    *cdst = *(uint64_t *)PyArray_DATA(array);
    Py_CLEAR(array);
    return 0;
}

static int
PYVK_ScalarLike_As_float(PyObject *pysrc, float *cdst) {
    PyObject *array = PyArray_FROM_OTF(pysrc, NPY_FLOAT, NPY_ARRAY_FORCECAST);
    if (!array || !PyArray_IsZeroDim(array)) {
        Py_CLEAR(array);
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into float", Py_TYPE(pysrc)->tp_name);
        return -1;
    }
    *cdst = *(float *)PyArray_DATA(array);
    Py_CLEAR(array);
    return 0;
}

static int
PYVK_ScalarLike_As_VkBool32(PyObject *pysrc, VkBool32 *cdst) {
    // Note: We do not perform a ==0 conversion here.
    PyObject *array = PyArray_FROM_OTF(pysrc, NPY_UINT32, NPY_ARRAY_FORCECAST);
    if (!array || !PyArray_IsZeroDim(array)) {
        Py_CLEAR(array);
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into VkBool32", Py_TYPE(pysrc)->tp_name);
        return -1;
    }
    *cdst = *(VkBool32 *)PyArray_DATA(array);
    Py_CLEAR(array);
    return 0;
}

static int
PYVK_StrLike_As_charp(PyObject *pysrc, const char **cdst) {
    const char *str = (
        PyUnicode_Check(pysrc) ? PyUnicode_AsUTF8(pysrc) :
        PyBytes_Check(pysrc) ? PyBytes_AsString(pysrc) :
        NULL
    );
    if (!str) {
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into charp", Py_TYPE(pysrc)->tp_name);
        return -1;
    }
    size_t buffer_size = (strlen(str) + 1) * sizeof(char);
    *cdst = PyObject_Malloc(buffer_size);
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
    PYVK_Data_Object base;
    const char *key;
    VkPerformanceValueDataINTEL data;
    //PyObject *ref;
} PYVKPerformanceValueDataINTEL_Object;

static PyObject *
PYVKPerformanceValueDataINTEL_GetArg(PyObject *self) {
    const char *key = ((PYVKPerformanceValueDataINTEL_Object *)self)->key;
    VkPerformanceValueDataINTEL *data = &((PYVKPerformanceValueDataINTEL_Object *)self)->data;
    PyObject *arg = (
        key == PYVKPerformanceValueDataINTEL_KEY_value32 ? PYVK_Scalar_From_uint32(data->value32) :
        key == PYVKPerformanceValueDataINTEL_KEY_value64 ? PYVK_Scalar_From_uint64(data->value64) :
        key == PYVKPerformanceValueDataINTEL_KEY_valueFloat ? PYVK_Scalar_From_float(data->valueFloat) :
        key == PYVKPerformanceValueDataINTEL_KEY_valueBool ? PYVK_Scalar_From_VkBool32(data->valueBool) :
        key == PYVKPerformanceValueDataINTEL_KEY_valueString ? PYVK_Str_From_charp(data->valueString) :
        NULL
    );
    if (!arg) {
        return NULL;
    }
    return arg;
}

//static void
//PYVKPerformanceValueDataINTEL_dealloc(PyObject *self) {
//    PyObject_GC_UnTrack(self);
//    Py_CLEAR(((PYVKPerformanceValueDataINTEL_Object *)self)->ref);
//    Py_TYPE(self)->tp_free(self);
//}

static PyObject *
PYVKPerformanceValueDataINTEL_repr(PyObject *self) {
    PyObject *arg = PYVKPerformanceValueDataINTEL_GetArg(self);
    if (!arg) {
        return NULL;
    }
    PyObject *result = PyUnicode_FromFormat("%s(%s=%R)", Py_TYPE(self)->tp_name, ((PYVKPerformanceValueDataINTEL_Object *)self)->key, arg);
    Py_CLEAR(arg);
    return result;
}

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
    return PyLong_FromUnsignedLongLong((uint64_t)&((PYVKPerformanceValueDataINTEL_Object *)self)->data);
}

static PyObject *
PYVKPerformanceValueDataINTEL_get(PyObject *self, void *closure) {
    if (((PYVKPerformanceValueDataINTEL_Object *)self)->key != (const char *)closure) {
        PyErr_Format(PyExc_RuntimeError, "Union object was created via key '%s' (accessing '%s')", ((PYVKPerformanceValueDataINTEL_Object *)self)->key, (const char *)closure);
        return NULL;
    }
    return PYVKPerformanceValueDataINTEL_GetArg(self);
}

static PyGetSetDef PYVKPerformanceValueDataINTEL_getset[] = {
    {
        .name = "_address",
        .get = PYVKPerformanceValueDataINTEL_get__address
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_value32,
        .get = PYVKPerformanceValueDataINTEL_get,
        .closure = (void *)PYVKPerformanceValueDataINTEL_KEY_value32
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_value64,
        .get = PYVKPerformanceValueDataINTEL_get,
        .closure = (void *)PYVKPerformanceValueDataINTEL_KEY_value64
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_valueFloat,
        .get = PYVKPerformanceValueDataINTEL_get,
        .closure = (void *)PYVKPerformanceValueDataINTEL_KEY_valueFloat
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_valueBool,
        .get = PYVKPerformanceValueDataINTEL_get,
        .closure = (void *)PYVKPerformanceValueDataINTEL_KEY_valueBool
    },
    {
        .name = PYVKPerformanceValueDataINTEL_KEY_valueString,
        .get = PYVKPerformanceValueDataINTEL_get,
        .closure = (void *)PYVKPerformanceValueDataINTEL_KEY_valueString
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

    self = cls->tp_alloc(cls, 0);
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
        PyErr_Format(PyExc_TypeError, "Must specify exactly 1 field for union %s()", cls->tp_name);
        goto error;
    }
    if ((
        arg_value32 ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value32, PYVK_ScalarLike_As_uint32(arg_value32, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32)) :
        arg_value64 ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value64, PYVK_ScalarLike_As_uint64(arg_value64, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64)) :
        arg_valueFloat ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueFloat, PYVK_ScalarLike_As_float(arg_valueFloat, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat)) :
        arg_valueBool ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueBool, PYVK_ScalarLike_As_VkBool32(arg_valueBool, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool)) :
        arg_valueString ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueString, PYVK_StrLike_As_charp(arg_valueString, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString)) :
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
        key == PYVKPerformanceValueDataINTEL_KEY_valueString ? (PyObject_Free(data->valueString), data->valueString = NULL, 0) :
        0
    ) {}
    PyObject_Free(self);
}

static PyTypeObject PYVKPerformanceValueDataINTEL_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.PerformanceValueDataINTEL",
    .tp_basicsize = sizeof(PYVKPerformanceValueDataINTEL_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    //.tp_dealloc = PYVKPerformanceValueDataINTEL_dealloc,
    .tp_repr = PYVKPerformanceValueDataINTEL_repr,
    //.tp_traverse = PYVKPerformanceValueDataINTEL_traverse,
    //.tp_clear = PYVKPerformanceValueDataINTEL_clear,
    .tp_getset = PYVKPerformanceValueDataINTEL_getset,
    .tp_base = &PYVK_Union_Type,
    .tp_new = PYVKPerformanceValueDataINTEL_new,
    .tp_free = PYVKPerformanceValueDataINTEL_free
};
// TODO: use PyObject_Malloc, PyObject_Free


//typedef struct {
//    uint32_t m_int;
//} ChildStructDemo;

//typedef struct {
//    uint32_t m_int;
//    const char *m_str;
//    void *m_bytes;
//    int m_bytes_len;
//    void *m_next;
//    ChildStructDemo *m_children;
//} ParentStructDemo;


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
        PyType_Ready(&PYVK_Data_Type) < 0 || PyModule_AddObjectRef(module, "_Data", (PyObject *)&PYVK_Data_Type) < 0 ||
        PyType_Ready(&PYVK_Enum_Type) < 0 || PyModule_AddObjectRef(module, "_Enum", (PyObject *)&PYVK_Enum_Type) < 0 ||
        PyType_Ready(&PYVK_Enum64_Type) < 0 || PyModule_AddObjectRef(module, "_Enum64", (PyObject *)&PYVK_Enum64_Type) < 0 ||
        PyType_Ready(&PYVK_Flag64_Type) < 0 || PyModule_AddObjectRef(module, "_Flag64", (PyObject *)&PYVK_Flag64_Type) < 0 ||
        PyType_Ready(&PYVKEnumDemo_Type) < 0 || PyType_Ready(&PYVKEnumDemo_Meta_Type) < 0 || PyModule_AddObjectRef(module, "EnumDemo", (PyObject *)&PYVKEnumDemo_Meta_Object) < 0 ||
        PyType_Ready(&PYVKFlagDemo_Type) < 0 || PyType_Ready(&PYVKFlagDemo_Meta_Type) < 0 || PyModule_AddObjectRef(module, "FlagDemo", (PyObject *)&PYVKFlagDemo_Meta_Object) < 0 ||
        PyType_Ready(&PYVK_Union_Type) < 0 || PyModule_AddObjectRef(module, "_Union", (PyObject *)&PYVK_Union_Type) < 0 ||
        PyType_Ready(&PYVKPerformanceValueDataINTEL_Type) < 0 || PyModule_AddObjectRef(module, "PerformanceValueDataINTEL", (PyObject *)&PYVKPerformanceValueDataINTEL_Type) < 0 ||
        0
    ) {
        Py_CLEAR(module);
        return NULL;
    }
    return module;
}
