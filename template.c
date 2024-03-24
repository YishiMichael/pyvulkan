#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <numpy/ndarrayobject.h>

#define PyHASH_TRUNC(x) ((x) & ~(Py_hash_t)0)


typedef struct {
    PyObject_HEAD
    uint64_t value;
} PYVK_UInt64_Object;

static inline uint64_t
PYVK_UInt64_GetValue(PyObject *self) {
    return ((PYVK_UInt64_Object *)self)->value;
}

static inline PyObject *
PYVK_UInt64_New(PyTypeObject *cls, uint64_t value) {
    PyObject *self = cls->tp_alloc(cls, 0);
    ((PYVK_UInt64_Object *)self)->value = value;
    return self;
}

static void
PYVK_UInt64_dealloc(PyObject *self) {
    Py_TYPE(self)->tp_free(self);
}

static PyObject *
PYVK_UInt64_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<%s: %llu>", Py_TYPE(self)->tp_name, PYVK_UInt64_GetValue(self));
    return result;
}

static PyObject *
PYVK_UInt64_invert(PyObject *self) {
    return PYVK_UInt64_New(Py_TYPE(self), ~PYVK_UInt64_GetValue(self));
}

static PyObject *
PYVK_UInt64_and(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    return PYVK_UInt64_New(Py_TYPE(self), PYVK_UInt64_GetValue(self) & PYVK_UInt64_GetValue(other));
}

static PyObject *
PYVK_UInt64_xor(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    return PYVK_UInt64_New(Py_TYPE(self), PYVK_UInt64_GetValue(self) ^ PYVK_UInt64_GetValue(other));
}

static PyObject *
PYVK_UInt64_or(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    return PYVK_UInt64_New(Py_TYPE(self), PYVK_UInt64_GetValue(self) | PYVK_UInt64_GetValue(other));
}

static PyNumberMethods PYVK_UInt64_as_number = {
    .nb_invert = PYVK_UInt64_invert,
    .nb_and = PYVK_UInt64_and,
    .nb_xor = PYVK_UInt64_xor,
    .nb_or = PYVK_UInt64_or
};

static Py_hash_t
PYVK_UInt64_hash(PyObject *self) {
    Py_hash_t result = PyHASH_TRUNC(PYVK_UInt64_GetValue(self));
    if (result == -1) {
        result = -2;
    }
    return result;
}

static PyObject *
PYVK_UInt64_richcompare(PyObject *self, PyObject *other, int op) {
    switch (op) {
        case Py_EQ:
            return Py_TYPE(self) != Py_TYPE(other) ? Py_False : PYVK_UInt64_GetValue(self) != PYVK_UInt64_GetValue(other) ? Py_False : Py_True;
        case Py_NE:
            return Py_TYPE(self) != Py_TYPE(other) ? Py_True : PYVK_UInt64_GetValue(self) != PYVK_UInt64_GetValue(other) ? Py_True : Py_False;
    }
    return Py_NotImplemented;
}


typedef struct {
    PyObject_HEAD
    PyTypeObject *uint_cls;
} PYVK_EnumMeta_Object;

static PyObject *
PYVK_EnumMeta_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<enum '%s'>", ((PYVK_EnumMeta_Object *)self)->uint_cls->tp_name);
    return result;
}

static PyObject *
PYVK_EnumMeta_get(PyObject *self, void *closure) {
    return PYVK_UInt64_New(((PYVK_EnumMeta_Object *)self)->uint_cls, *(uint64_t *)closure);
}


typedef struct {
    PyObject_HEAD
    PyTypeObject *uint_cls;
} PYVK_FlagMeta_Object;

static PyObject *
PYVK_FlagMeta_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<flag '%s'>", ((PYVK_FlagMeta_Object *)self)->uint_cls->tp_name);
    return result;
}

static PyObject *
PYVK_FlagMeta_get(PyObject *self, void *closure) {
    return PYVK_UInt64_New(((PYVK_FlagMeta_Object *)self)->uint_cls, *(uint64_t *)closure);
}


static uint64_t PYVKEnumDemo_A = 5;
static uint64_t PYVKEnumDemo_B = 12;
static PyGetSetDef PYVKEnumDemo_Meta_getset[] = {
    {
        .name = "A",
        .get = PYVK_EnumMeta_get,
        .closure = (void *)&PYVKEnumDemo_A
    },
    {
        .name = "B",
        .get = PYVK_EnumMeta_get,
        .closure = (void *)&PYVKEnumDemo_B
    },
    {NULL}
};
static PyTypeObject PYVKEnumDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "template.EnumDemo",
    .tp_basicsize = sizeof(PYVK_UInt64_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_dealloc = PYVK_UInt64_dealloc,
    .tp_repr = PYVK_UInt64_repr,
    .tp_hash = PYVK_UInt64_hash,
    .tp_richcompare = PYVK_UInt64_richcompare
};
static PyTypeObject PYVKEnumDemo_Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "template.EnumDemo_Meta",
    .tp_basicsize = sizeof(PYVK_EnumMeta_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_repr = PYVK_EnumMeta_repr,
    .tp_getset = PYVKEnumDemo_Meta_getset
};
static PYVK_EnumMeta_Object PYVKEnumDemo_Meta_Object = {
    PyObject_HEAD_INIT(&PYVKEnumDemo_Meta_Type)
    .uint_cls = &PYVKEnumDemo_Type
};

static uint64_t PYVKFlagDemo_C = 55;
static uint64_t PYVKFlagDemo_D = 119;
static PyGetSetDef PYVKFlagDemo_Meta_getset[] = {
    {
        .name = "C",
        .get = PYVK_FlagMeta_get,
        .closure = (void *)&PYVKFlagDemo_C
    },
    {
        .name = "D",
        .get = PYVK_FlagMeta_get,
        .closure = (void *)&PYVKFlagDemo_D
    },
    {NULL}
};
static PyTypeObject PYVKFlagDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "template.FlagDemo",
    .tp_basicsize = sizeof(PYVK_UInt64_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_dealloc = PYVK_UInt64_dealloc,
    .tp_repr = PYVK_UInt64_repr,
    .tp_as_number = &PYVK_UInt64_as_number,
    .tp_hash = PYVK_UInt64_hash,
    .tp_richcompare = PYVK_UInt64_richcompare
};
static PyTypeObject PYVKFlagDemo_Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "template.FlagDemo_Meta",
    .tp_basicsize = sizeof(PYVK_FlagMeta_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_repr = PYVK_FlagMeta_repr,
    .tp_getset = PYVKFlagDemo_Meta_getset
};
static PYVK_FlagMeta_Object PYVKFlagDemo_Meta_Object = {
    PyObject_HEAD_INIT(&PYVKFlagDemo_Meta_Type)
    .uint_cls = &PYVKFlagDemo_Type
};


typedef uint32_t VkBool32;

static inline int
PYVK_NPY_UINT32_0D_FROM_uint32_t(uint32_t *csrc, PyObject *base, PyObject **pydst) {
    *pydst = PyArray_SimpleNewFromData(0, NULL, NPY_UINT32, csrc);
    if (!*pydst) {
        return -1;
    }
    if (PyArray_SetBaseObject((PyArrayObject *)*pydst, base) < 0) {
        Py_DECREF(*pydst);
        *pydst = NULL;
        return -1;
    }
    Py_INCREF(base);
    return 0;
}

static inline int
PYVK_NPY_UINT64_0D_FROM_uint64_t(uint64_t *csrc, PyObject *base, PyObject **pydst) {
    *pydst = PyArray_SimpleNewFromData(0, NULL, NPY_UINT64, csrc);
    if (!*pydst) {
        return -1;
    }
    if (PyArray_SetBaseObject((PyArrayObject *)*pydst, base) < 0) {
        Py_DECREF(*pydst);
        *pydst = NULL;
        return -1;
    }
    Py_INCREF(base);
    return 0;
}

static inline int
PYVK_NPY_FLOAT_0D_FROM_float(float *csrc, PyObject *base, PyObject **pydst) {
    *pydst = PyArray_SimpleNewFromData(0, NULL, NPY_FLOAT, csrc);
    if (!*pydst) {
        return -1;
    }
    if (PyArray_SetBaseObject((PyArrayObject *)*pydst, base) < 0) {
        Py_DECREF(*pydst);
        *pydst = NULL;
        return -1;
    }
    Py_INCREF(base);
    return 0;
}

static inline int
PYVK_NPY_UINT32_0D_FROM_VkBool32(VkBool32 *csrc, PyObject *base, PyObject **pydst) {
    *pydst = PyArray_SimpleNewFromData(0, NULL, NPY_UINT32, csrc);
    if (!*pydst) {
        return -1;
    }
    if (PyArray_SetBaseObject((PyArrayObject *)*pydst, base) < 0) {
        Py_DECREF(*pydst);
        *pydst = NULL;
        return -1;
    }
    Py_INCREF(base);
    return 0;
}

static inline int
PYVK_bytes_FROM_const_charp(const char **csrc, PyObject **pydst) {
    *pydst = PyBytes_FromString(*csrc);
    if (!*pydst) {
        return -1;
    }
    return 0;
}

static inline int
PYVK_NPY_UINT32_0D_AS_uint32_t(PyObject *pysrc, uint32_t *cdst) {
    *cdst = *(uint32_t *)PyArray_DATA(pysrc);
    return 0;
}

static inline int
PYVK_NPY_UINT64_0D_AS_uint64_t(PyObject *pysrc, uint64_t *cdst) {
    *cdst = *(uint64_t *)PyArray_DATA(pysrc);
    return 0;
}

static inline int
PYVK_NPY_FLOAT_0D_AS_float(PyObject *pysrc, float *cdst) {
    *cdst = *(float *)PyArray_DATA(pysrc);
    return 0;
}

static inline int
PYVK_NPY_UINT32_0D_AS_VkBool32(PyObject *pysrc, VkBool32 *cdst) {
    *cdst = *(VkBool32 *)PyArray_DATA(pysrc);
    return 0;
}

static inline int
PYVK_bytes_AS_const_charp(PyObject *pysrc, const char **cdst, PyObject **pyref) {
    *cdst = PyBytes_AS_STRING(pysrc);
    *pyref = Py_NewRef(pysrc);
    return 0;
}

static int
PYVK_PY_SCALAR_TO_NPY_UINT32_0D(PyObject *pysrc, PyObject **pydst) {
    *pydst = (
        PyArray_IsPythonNumber(pysrc) ? PyArray_FROM_OT(pysrc, NPY_UINT32) :
        PyArray_IsZeroDim(pysrc) ? PyArray_CastToType((PyArrayObject *)pysrc, PyArray_DescrFromType(NPY_UINT32), 0) :
        PyArray_IsScalar(pysrc, Generic) ? PyArray_FromScalar(pysrc, PyArray_DescrFromType(NPY_UINT32)) :
        NULL
    );
    if (!*pydst) {
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into uint32", Py_TYPE(pysrc)->tp_name);
        return 0;
    }
    if (PyErr_Occurred()) {
        *pydst = NULL;
        return 0;
    }
    return 1;
}

static int
PYVK_PY_SCALAR_TO_NPY_UINT64_0D(PyObject *pysrc, PyObject **pydst) {
    *pydst = (
        PyArray_IsPythonNumber(pysrc) ? PyArray_FROM_OT(pysrc, NPY_UINT64) :
        PyArray_IsZeroDim(pysrc) ? PyArray_CastToType((PyArrayObject *)pysrc, PyArray_DescrFromType(NPY_UINT64), 0) :
        PyArray_IsScalar(pysrc, Generic) ? PyArray_FromScalar(pysrc, PyArray_DescrFromType(NPY_UINT64)) :
        NULL
    );
    if (!*pydst) {
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into uint64", Py_TYPE(pysrc)->tp_name);
        return 0;
    }
    if (PyErr_Occurred()) {
        *pydst = NULL;
        return 0;
    }
    return 1;
}

static int
PYVK_PY_SCALAR_TO_NPY_FLOAT_0D(PyObject *pysrc, PyObject **pydst) {
    *pydst = (
        PyArray_IsPythonNumber(pysrc) ? PyArray_FROM_OT(pysrc, NPY_FLOAT) :
        PyArray_IsZeroDim(pysrc) ? PyArray_CastToType((PyArrayObject *)pysrc, PyArray_DescrFromType(NPY_FLOAT), 0) :
        PyArray_IsScalar(pysrc, Generic) ? PyArray_FromScalar(pysrc, PyArray_DescrFromType(NPY_FLOAT)) :
        NULL
    );
    if (!*pydst) {
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into float", Py_TYPE(pysrc)->tp_name);
        return 0;
    }
    if (PyErr_Occurred()) {
        *pydst = NULL;
        return 0;
    }
    return 1;
}

static int
PYVK_PY_SUPPORTS_BOOL_TO_NPY_UINT32_0D(PyObject *pysrc, PyObject **pydst) {
    *pydst = (
        PyArray_IsPythonNumber(pysrc) ? PyArray_FROM_OT(pysrc, NPY_UINT32) :
        PyArray_IsZeroDim(pysrc) ? PyArray_CastToType((PyArrayObject *)pysrc, PyArray_DescrFromType(NPY_UINT32), 0) :
        PyArray_IsScalar(pysrc, Generic) ? PyArray_FromScalar(pysrc, PyArray_DescrFromType(NPY_UINT32)) :
        NULL
    );
    // Note: We do not perform a ==0 conversion here.
    if (!*pydst) {
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into bool", Py_TYPE(pysrc)->tp_name);
        return 0;
    }
    if (PyErr_Occurred()) {
        *pydst = NULL;
        return 0;
    }
    return 1;
}

static int
PYVK_PY_SUPPORTS_STR_TO_bytes(PyObject *pysrc, PyObject **pydst) {
    *pydst = (
        PyUnicode_Check(pysrc) ? PyUnicode_AsEncodedString(pysrc, "utf-8", "strict") :
        PyBytes_Check(pysrc) ? Py_NewRef(pysrc) :
        NULL
    );
    if (!*pydst) {
        PyErr_Format(PyExc_TypeError, "Cannot convert %s into bytes", Py_TYPE(pysrc)->tp_name);
        return 0;
    }
    if (PyErr_Occurred()) {
        *pydst = NULL;
        return 0;
    }
    return 1;
}


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
    PyObject *ref;
} PYVKPerformanceValueDataINTEL_Object;

static PyObject *
PYVKPerformanceValueDataINTEL_get__address(PyObject *self, void *Py_UNUSED(closure)) {
    return PyLong_FromUnsignedLongLong((uint64_t)&((PYVKPerformanceValueDataINTEL_Object *)self)->data);
}

static PyObject *
PYVKPerformanceValueDataINTEL_get(PyObject *self, void *closure) {
    const char *key = (const char *)closure;
    if (((PYVKPerformanceValueDataINTEL_Object *)self)->key != key) {
        PyErr_Format(PyExc_RuntimeError, "Union object was created via key '%s' (accessing '%s')", ((PYVKPerformanceValueDataINTEL_Object *)self)->key, key);
        return NULL;
    }
    PyObject *obj = NULL;
    if ((
        key == PYVKPerformanceValueDataINTEL_KEY_value32 ? PYVK_NPY_UINT32_0D_FROM_uint32_t(&((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32, self, &obj) :
        key == PYVKPerformanceValueDataINTEL_KEY_value64 ? PYVK_NPY_UINT64_0D_FROM_uint64_t(&((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64, self, &obj) :
        key == PYVKPerformanceValueDataINTEL_KEY_valueFloat ? PYVK_NPY_FLOAT_0D_FROM_float(&((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat, self, &obj) :
        key == PYVKPerformanceValueDataINTEL_KEY_valueBool ? PYVK_NPY_UINT32_0D_FROM_VkBool32(&((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool, self, &obj) :
        key == PYVKPerformanceValueDataINTEL_KEY_valueString ? PYVK_bytes_FROM_const_charp(&((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString, &obj) :
        0
    ) < 0) {
        Py_XDECREF(obj);
        return NULL;
    }
    return obj;
}

static void
PYVKPerformanceValueDataINTEL_dealloc(PyObject *self) {
    PyObject_GC_UnTrack(self);
    Py_CLEAR(((PYVKPerformanceValueDataINTEL_Object *)self)->ref);
    Py_TYPE(self)->tp_free(self);
}

static PyObject *
PYVKPerformanceValueDataINTEL_repr(PyObject *self) {
    PyObject *obj = PYVKPerformanceValueDataINTEL_get(self, (void *)((PYVKPerformanceValueDataINTEL_Object *)self)->key);
    if (!obj) {
        return NULL;
    }
    PyObject *result = PyUnicode_FromFormat("%s(%s=%R)", Py_TYPE(self)->tp_name, ((PYVKPerformanceValueDataINTEL_Object *)self)->key, obj);
    Py_DECREF(obj);
    return result;
}

static int
PYVKPerformanceValueDataINTEL_traverse(PyObject *self, visitproc visit, void *arg) {
    Py_VISIT(((PYVKPerformanceValueDataINTEL_Object *)self)->ref);
    return 0;
}

static int
PYVKPerformanceValueDataINTEL_clear(PyObject *self) {
    Py_CLEAR(((PYVKPerformanceValueDataINTEL_Object *)self)->ref);
    return 0;
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
    static char *kwlist[] = {
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
        args, kwds, "|$O&O&O&O&O&", kwlist,
        PYVK_PY_SCALAR_TO_NPY_UINT32_0D, &arg_value32,
        PYVK_PY_SCALAR_TO_NPY_UINT64_0D, &arg_value64,
        PYVK_PY_SCALAR_TO_NPY_FLOAT_0D, &arg_valueFloat,
        PYVK_PY_SUPPORTS_BOOL_TO_NPY_UINT32_0D, &arg_valueBool,
        PYVK_PY_SUPPORTS_STR_TO_bytes, &arg_valueString
    )) {
        goto error;
    }
    if (PyDict_Size(kwds) != 1) {
        PyErr_Format(PyExc_TypeError, "Must specify exactly 1 field for union %s()", cls->tp_name);
        goto error;
    }
    if ((
        arg_value32 ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value32, PYVK_NPY_UINT32_0D_AS_uint32_t(arg_value32, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32)) :
        arg_value64 ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value64, PYVK_NPY_UINT64_0D_AS_uint64_t(arg_value64, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64)) :
        arg_valueFloat ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueFloat, PYVK_NPY_FLOAT_0D_AS_float(arg_valueFloat, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat)) :
        arg_valueBool ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueBool, PYVK_NPY_UINT32_0D_AS_VkBool32(arg_valueBool, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool)) :
        arg_valueString ? (((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueString, PYVK_bytes_AS_const_charp(arg_valueString, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString, &((PYVKPerformanceValueDataINTEL_Object *)self)->ref)) :
        0
    ) < 0) {
        goto error;
    }
    return self;

error:
    Py_XDECREF(self);
    return NULL;
}

static PyTypeObject PYVKPerformanceValueDataINTEL_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "template.PerformanceValueDataINTEL",
    .tp_basicsize = sizeof(PYVKPerformanceValueDataINTEL_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_dealloc = PYVKPerformanceValueDataINTEL_dealloc,
    .tp_repr = PYVKPerformanceValueDataINTEL_repr,
    .tp_traverse = PYVKPerformanceValueDataINTEL_traverse,
    .tp_clear = PYVKPerformanceValueDataINTEL_clear,
    .tp_getset = PYVKPerformanceValueDataINTEL_getset,
    .tp_new = PYVKPerformanceValueDataINTEL_new
};


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


static PyModuleDef template_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "template",
    .m_doc = "Example module that creates an extension type.",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_template(void) {
    import_array();
    if (PyErr_Occurred() || !PyArray_API) {
        return NULL;
    }

    PyObject *module = PyModule_Create(&template_module);
    if (!module) {
        return NULL;
    }
    if (
        PyType_Ready(&PYVKEnumDemo_Type) < 0 || PyType_Ready(&PYVKEnumDemo_Meta_Type) < 0 || PyModule_AddObjectRef(module, "EnumDemo", (PyObject *)&PYVKEnumDemo_Meta_Object) < 0 ||
        PyType_Ready(&PYVKFlagDemo_Type) < 0 || PyType_Ready(&PYVKFlagDemo_Meta_Type) < 0 || PyModule_AddObjectRef(module, "FlagDemo", (PyObject *)&PYVKFlagDemo_Meta_Object) < 0 ||
        0
    ) {
        Py_DECREF(module);
        return NULL;
    }
    if (
        PyType_Ready(&PYVKPerformanceValueDataINTEL_Type) < 0 || PyModule_AddObjectRef(module, "PerformanceValueDataINTEL", (PyObject *)&PYVKPerformanceValueDataINTEL_Type) < 0 ||
        0
    ) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
