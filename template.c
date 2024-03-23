#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <numpy/ndarrayobject.h>


typedef uint32_t VkBool32;


static inline void
PYVK_NPY_UINT32_FROM_uint32_t(uint32_t csrc, PyObject **pydst) {
    PyArray_Descr *dtype = PyArray_DescrFromType(NPY_UINT32);
    *pydst = PyArray_Scalar(&csrc, dtype, NULL);
}

static inline void
PYVK_NPY_UINT64_FROM_uint64_t(uint64_t csrc, PyObject **pydst) {
    PyArray_Descr *dtype = PyArray_DescrFromType(NPY_UINT64);
    *pydst = PyArray_Scalar(&csrc, dtype, NULL);
}

static inline void
PYVK_NPY_FLOAT_FROM_float(float csrc, PyObject **pydst) {
    PyArray_Descr *dtype = PyArray_DescrFromType(NPY_FLOAT);
    *pydst = PyArray_Scalar(&csrc, dtype, NULL);
}

static inline void
PYVK_NPY_UINT32_FROM_VkBool32(VkBool32 csrc, PyObject **pydst) {
    PyArray_Descr *dtype = PyArray_DescrFromType(NPY_UINT32);
    *pydst = PyArray_Scalar(&csrc, dtype, NULL);
}

static inline void
PYVK_bytes_FROM_const_charp(const char *csrc, PyObject **pydst) {
    *pydst = PyUnicode_FromString(csrc);
}

static inline void
PYVK_NPY_UINT32_AS_uint32_t(PyObject *pysrc, uint32_t *cdst) {
    PyArray_ScalarAsCtype(pysrc, cdst);
}

static inline void
PYVK_NPY_UINT64_AS_uint64_t(PyObject *pysrc, uint64_t *cdst) {
    PyArray_ScalarAsCtype(pysrc, cdst);
}

static inline void
PYVK_NPY_FLOAT_AS_float(PyObject *pysrc, float *cdst) {
    PyArray_ScalarAsCtype(pysrc, cdst);
}

static inline void
PYVK_NPY_UINT32_AS_VkBool32(PyObject *pysrc, VkBool32 *cdst) {
    PyArray_ScalarAsCtype(pysrc, cdst);
}

static inline void
PYVK_bytes_AS_const_charp(PyObject *pysrc, const char **cdst, PyObject **pyref) {
    *cdst = PyBytes_AS_STRING(pysrc);
    *pyref = Py_NewRef(pysrc);
}

static int
PYVK_PY_SCALAR_TO_NPY_UINT32(PyObject *pysrc, PyObject **pydst) {
    PyArray_Descr *dtype = PyArray_DescrFromType(NPY_UINT32);
    if (PyArray_IsPythonNumber(pysrc)) {
        uint32_t value = PyLong_AsUnsignedLongMask(pysrc);
        if (PyErr_Occurred()) {
            return 0;
        }
        *pydst = PyArray_Scalar(&value, dtype, NULL);
        return 1;
    }
    if (PyArray_CheckScalar(pysrc)) {
        *pydst = PyArray_FromScalar(pysrc, dtype); // TODO
        return 1;
    }
    PyErr_Format(PyExc_TypeError, "Cannot convert %s into uint32", Py_TYPE(pysrc)->tp_name);
    return 0;
}

static int
PYVK_PY_SCALAR_TO_NPY_UINT64(PyObject *pysrc, PyObject **pydst) {
    PyArray_Descr *dtype = PyArray_DescrFromType(NPY_UINT64);
    if (PyArray_IsPythonNumber(pysrc)) {
        uint64_t value = PyLong_AsUnsignedLongLongMask(pysrc);
        if (PyErr_Occurred()) {
            return 0;
        }
        *pydst = PyArray_Scalar(&value, dtype, NULL);
        return 1;
    }
    if (PyArray_CheckScalar(pysrc)) {
        *pydst = PyArray_FromScalar(pysrc, dtype);
        return 1;
    }
    PyErr_Format(PyExc_TypeError, "Cannot convert %s into uint64", Py_TYPE(pysrc)->tp_name);
    return 0;
}

static int
PYVK_PY_SCALAR_TO_NPY_FLOAT(PyObject *pysrc, PyObject **pydst) {
    PyArray_Descr *dtype = PyArray_DescrFromType(NPY_FLOAT);
    if (PyArray_IsPythonNumber(pysrc)) {
        float value = (float)PyFloat_AsDouble(pysrc);
        if (PyErr_Occurred()) {
            return 0;
        }
        *pydst = PyArray_Scalar(&value, dtype, NULL);
        return 1;
    }
    if (PyArray_CheckScalar(pysrc)) {
        *pydst = PyArray_FromScalar(pysrc, dtype);
        return 1;
    }
    PyErr_Format(PyExc_TypeError, "Cannot convert %s into float", Py_TYPE(pysrc)->tp_name);
    return 0;
}

static int
PYVK_PY_SUPPORTS_BOOL_TO_NPY_UINT32(PyObject *pysrc, PyObject **pydst) {
    PyArray_Descr *dtype = PyArray_DescrFromType(NPY_UINT32);
    if (PyArray_IsPythonNumber(pysrc) | PyArray_CheckScalar(pysrc)) {
        uint32_t value = PyObject_IsTrue(pysrc);
        if (PyErr_Occurred()) {
            return 0;
        }
        *pydst = PyArray_Scalar(&value, dtype, NULL);
        return 1;
    }
    PyErr_Format(PyExc_TypeError, "Cannot convert %s into bool", Py_TYPE(pysrc)->tp_name);
    return 0;
}

static int
PYVK_PY_SUPPORTS_STR_TO_bytes(PyObject *pysrc, PyObject **pydst) {
    if (PyUnicode_Check(pysrc)) {
        *pydst = PyUnicode_AsEncodedString(pysrc, "utf-8", "strict");
        return 1;
    }
    if (PyBytes_Check(pysrc)) {
        *pydst = Py_NewRef(pysrc);
        return 1;
    }
    return 0;
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
        PyErr_Format(PyExc_AttributeError, "Union object was created via key '%s' (accessing '%s')", ((PYVKPerformanceValueDataINTEL_Object *)self)->key, key);
        return NULL;
    }
    PyObject *obj = NULL;
    if (key == PYVKPerformanceValueDataINTEL_KEY_value32) {
        PYVK_NPY_UINT32_FROM_uint32_t(((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32, &obj);
        //obj = PyLong_FromUnsignedLong(((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32);
    } else if (key == PYVKPerformanceValueDataINTEL_KEY_value64) {
        PYVK_NPY_UINT64_FROM_uint64_t(((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64, &obj);
        //obj = PyLong_FromUnsignedLongLong(((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64);
    } else if (key == PYVKPerformanceValueDataINTEL_KEY_valueFloat) {
        PYVK_NPY_FLOAT_FROM_float(((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat, &obj);
        //obj = PyFloat_FromDouble((double)((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat);
    } else if (key == PYVKPerformanceValueDataINTEL_KEY_valueBool) {
        PYVK_NPY_UINT32_FROM_VkBool32(((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool, &obj);
        //obj = ((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool ? Py_True : Py_False;
    } else if (key == PYVKPerformanceValueDataINTEL_KEY_valueString) {
        PYVK_bytes_FROM_const_charp(((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString, &obj);
        //obj = PyUnicode_FromString(((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString);
    } else {
        PyErr_Format(PyExc_AttributeError, "Unknown key: %s", key);
    }
    if (PyErr_Occurred()) {
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
        PYVK_PY_SCALAR_TO_NPY_UINT32, &arg_value32,
        PYVK_PY_SCALAR_TO_NPY_UINT64, &arg_value64,
        PYVK_PY_SCALAR_TO_NPY_FLOAT, &arg_valueFloat,
        PYVK_PY_SUPPORTS_BOOL_TO_NPY_UINT32, &arg_valueBool,
        PYVK_PY_SUPPORTS_STR_TO_bytes, &arg_valueString
    )) {
        goto error;
    }
    if (PyDict_Size(kwds) != 1) {
        PyErr_Format(PyExc_TypeError, "Must specify exactly 1 field for union %s()", cls->tp_name);
        goto error;
    }
    if (arg_value32) {
        ((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value32;
        PYVK_NPY_UINT32_AS_uint32_t(arg_value32, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32);
        //PyArray_ScalarAsCtype(arg_value32, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value32);
    } else if (arg_value64) {
        ((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_value64;
        PYVK_NPY_UINT64_AS_uint64_t(arg_value64, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64);
        //PyArray_ScalarAsCtype(arg_value64, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.value64);
    } else if (arg_valueFloat) {
        ((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueFloat;
        PYVK_NPY_FLOAT_AS_float(arg_valueFloat, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat);
        //PyArray_ScalarAsCtype(arg_valueFloat, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueFloat);
    } else if (arg_valueBool) {
        ((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueBool;
        PYVK_NPY_UINT32_AS_VkBool32(arg_valueBool, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool);
        //PyArray_ScalarAsCtype(arg_valueBool, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueBool);
    } else if (arg_valueString) {
        ((PYVKPerformanceValueDataINTEL_Object *)self)->key = PYVKPerformanceValueDataINTEL_KEY_valueString;
        PYVK_bytes_AS_const_charp(arg_valueString, &((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString, &((PYVKPerformanceValueDataINTEL_Object *)self)->ref);
        //((PYVKPerformanceValueDataINTEL_Object *)self)->ref = Py_NewRef(arg_valueString);
        //((PYVKPerformanceValueDataINTEL_Object *)self)->data.valueString = PyBytes_AS_STRING(arg_valueString);
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
        PyModule_AddIntConstant(module, "EnumDemo_A", 5) < 0 ||
        PyModule_AddIntConstant(module, "EnumDemo_B", 12) < 0 ||
        PyModule_AddIntConstant(module, "EnumDemo_C", 55) < 0 ||
        PyModule_AddIntConstant(module, "EnumDemo_D", 119) < 0 ||
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
