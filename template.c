#define PY_SSIZE_T_CLEAN
#include <Python.h>

#define PyHASH_TRUNC(x) ((x) & ~(Py_hash_t)0)
#define MUDULE_NAME "template"


typedef struct {
    PyObject_HEAD
    uint64_t value;
} UInt_Object;

static inline uint64_t
UInt_GetValue(PyObject *self) {
    return ((UInt_Object *)self)->value;
}

static inline PyObject *
UInt_New(PyTypeObject *cls, uint64_t value) {
    PyObject *self = cls->tp_alloc(cls, 0);
    ((UInt_Object *)self)->value = value;
    return self;
}

static void
UInt_dealloc(PyObject *self) {
    Py_TYPE(self)->tp_free(self);
}

static PyObject *
UInt_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<%s: %llu>", Py_TYPE(self)->tp_name, UInt_GetValue(self));
    return result;
}

static PyObject *
UInt_and(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    return UInt_New(Py_TYPE(self), UInt_GetValue(self) & UInt_GetValue(other));
}

static PyObject *
UInt_or(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    return UInt_New(Py_TYPE(self), UInt_GetValue(self) | UInt_GetValue(other));
}

static PyNumberMethods UInt_as_number = {
    .nb_and = UInt_and,
    .nb_or = UInt_or
};

static Py_hash_t
UInt_hash(PyObject *self) {
    Py_hash_t result = PyHASH_TRUNC(UInt_GetValue(self));
    if (result == -1) {
        result = -2;
    }
    return result;
}

static PyObject *
UInt_richcompare(PyObject *self, PyObject *other, int op) {
    switch (op) {
        case Py_EQ:
            return Py_TYPE(self) != Py_TYPE(other) ? Py_False : UInt_GetValue(self) != UInt_GetValue(other) ? Py_False : Py_True;
        case Py_NE:
            return Py_TYPE(self) != Py_TYPE(other) ? Py_True : UInt_GetValue(self) != UInt_GetValue(other) ? Py_True : Py_False;
    }
    return Py_NotImplemented;
}


typedef struct {
    PyObject_HEAD
    PyTypeObject *uint_cls;
} Enum_Object;

static PyObject *
Enum_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<enum '%s'>", ((Enum_Object *)self)->uint_cls->tp_name);
    return result;
}

static PyObject *
Enum_get(PyObject *self, void *closure) {
    return UInt_New(((Enum_Object *)self)->uint_cls, *(uint64_t *)closure);
}


typedef struct {
    PyObject_HEAD
    PyTypeObject *uint_cls;
} Flag_Object;

static PyObject *
Flag_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<flag '%s'>", ((Flag_Object *)self)->uint_cls->tp_name);
    return result;
}

static PyObject *
Flag_get(PyObject *self, void *closure) {
    return UInt_New(((Flag_Object *)self)->uint_cls, *(uint64_t *)closure);
}


static uint64_t EnumDemo_A = 5;
static uint64_t EnumDemo_B = 12;
static PyGetSetDef Enum_EnumDemo_getset[] = {
    {
        .name = "A",
        .get = Enum_get,
        .closure = (void *)&EnumDemo_A
    },
    {
        .name = "B",
        .get = Enum_get,
        .closure = (void *)&EnumDemo_B
    },
    {NULL}
};
static PyTypeObject EnumDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME "." "EnumDemo",
    .tp_basicsize = sizeof(UInt_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_dealloc = UInt_dealloc,
    .tp_repr = UInt_repr,
    .tp_hash = UInt_hash,
    .tp_richcompare = UInt_richcompare
};
static PyTypeObject Enum_EnumDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME "." "_Enum_EnumDemo",
    .tp_basicsize = sizeof(Enum_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_repr = Enum_repr,
    .tp_getset = Enum_EnumDemo_getset
};
static Enum_Object Enum_EnumDemo_Object = {
    PyObject_HEAD_INIT(&Enum_EnumDemo_Type)
    .uint_cls = &EnumDemo_Type
};

static uint64_t FlagDemo_C = 55;
static uint64_t FlagDemo_D = 119;
static PyGetSetDef Flag_FlagDemo_getsetdefs[] = {
    {
        .name = "C",
        .get = Flag_get,
        .closure = (void *)&FlagDemo_C
    },
    {
        .name = "D",
        .get = Flag_get,
        .closure = (void *)&FlagDemo_D
    },
    {NULL}
};
static PyTypeObject FlagDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME "." "FlagDemo",
    .tp_basicsize = sizeof(UInt_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_dealloc = UInt_dealloc,
    .tp_repr = UInt_repr,
    .tp_as_number = &UInt_as_number,
    .tp_hash = UInt_hash,
    .tp_richcompare = UInt_richcompare
};
static PyTypeObject Flag_FlagDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME "." "_Flag_FlagDemo",
    .tp_basicsize = sizeof(Flag_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_repr = Flag_repr,
    .tp_getset = Flag_FlagDemo_getsetdefs
};
static Flag_Object Flag_FlagDemo_Object = {
    PyObject_HEAD_INIT(&Flag_FlagDemo_Type)
    .uint_cls = &FlagDemo_Type
};


typedef uint32_t VkBool32;
typedef union {
    uint32_t value32;
    uint64_t value64;
    float valueFloat;
    VkBool32 valueBool;
    const char *valueString;
} VkPerformanceValueDataINTEL;

typedef struct {
    PyObject_HEAD
    VkPerformanceValueDataINTEL data;
    const char *key;
    PyObject *arg;
} Py_PerformanceValueDataINTEL_Object;

static const char Py_PerformanceValueDataINTEL_KEY_value_32[] = "value_32";
static const char Py_PerformanceValueDataINTEL_KEY_value_64[] = "value_64";
static const char Py_PerformanceValueDataINTEL_KEY_value_float[] = "value_float";
static const char Py_PerformanceValueDataINTEL_KEY_value_bool[] = "value_bool";
static const char Py_PerformanceValueDataINTEL_KEY_value_string[] = "value_string";

static void
Py_PerformanceValueDataINTEL_dealloc(PyObject *self) {
    PyObject_GC_UnTrack(self);
    Py_CLEAR(((Py_PerformanceValueDataINTEL_Object *)self)->arg);
    Py_TYPE(self)->tp_free(self);
}

static PyObject *
Py_PerformanceValueDataINTEL_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("%s(%s=%R)", Py_TYPE(self)->tp_name, ((Py_PerformanceValueDataINTEL_Object *)self)->key, ((Py_PerformanceValueDataINTEL_Object *)self)->arg);
    return result;
}

static int
Py_PerformanceValueDataINTEL_traverse(PyObject *self, visitproc visit, void *arg) {
    Py_VISIT(((Py_PerformanceValueDataINTEL_Object *)self)->arg);
    return 0;
}

static int
Py_PerformanceValueDataINTEL_clear(PyObject *self) {
    Py_CLEAR(((Py_PerformanceValueDataINTEL_Object *)self)->arg);
    return 0;
}

static PyObject *
Py_PerformanceValueDataINTEL_get(PyObject *self, void *closure) {
    if (((Py_PerformanceValueDataINTEL_Object *)self)->key != (const char *)closure) {
        PyErr_Format(PyExc_AttributeError, "Union object was created via key '%s' (accessing '%s')", ((Py_PerformanceValueDataINTEL_Object *)self)->key, (char *)closure);
        return NULL;
    }
    return Py_NewRef(((Py_PerformanceValueDataINTEL_Object *)self)->arg);
}

static PyGetSetDef Py_PerformanceValueDataINTEL_getset[] = {
    {
        .name = Py_PerformanceValueDataINTEL_KEY_value_32,
        .get = Py_PerformanceValueDataINTEL_get,
        .closure = (void *)Py_PerformanceValueDataINTEL_KEY_value_32
    },
    {
        .name = Py_PerformanceValueDataINTEL_KEY_value_64,
        .get = Py_PerformanceValueDataINTEL_get,
        .closure = (void *)Py_PerformanceValueDataINTEL_KEY_value_64
    },
    {
        .name = Py_PerformanceValueDataINTEL_KEY_value_float,
        .get = Py_PerformanceValueDataINTEL_get,
        .closure = (void *)Py_PerformanceValueDataINTEL_KEY_value_float
    },
    {
        .name = Py_PerformanceValueDataINTEL_KEY_value_bool,
        .get = Py_PerformanceValueDataINTEL_get,
        .closure = (void *)Py_PerformanceValueDataINTEL_KEY_value_bool
    },
    {
        .name = Py_PerformanceValueDataINTEL_KEY_value_string,
        .get = Py_PerformanceValueDataINTEL_get,
        .closure = (void *)Py_PerformanceValueDataINTEL_KEY_value_string
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
// ) -> Py_PerformanceValueDataINTEL_Object: ...
static PyObject *
Py_PerformanceValueDataINTEL_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    static char *kwlist[] = {
        Py_PerformanceValueDataINTEL_KEY_value_32,
        Py_PerformanceValueDataINTEL_KEY_value_64,
        Py_PerformanceValueDataINTEL_KEY_value_float,
        Py_PerformanceValueDataINTEL_KEY_value_bool,
        Py_PerformanceValueDataINTEL_KEY_value_string,
        {NULL}
    };
    int argc = 0;
    PyObject *arg_value_32 = NULL;
    PyObject *arg_value_64 = NULL;
    PyObject *arg_value_float = NULL;
    PyObject *arg_value_bool = NULL;
    PyObject *arg_value_string = NULL;
    PyObject *self = NULL;

    self = cls->tp_alloc(cls, 0);
    if (self == NULL) {
        goto error;
    }

    const char **self_key = &((Py_PerformanceValueDataINTEL_Object *)self)->key;
    VkPerformanceValueDataINTEL *self_data = &((Py_PerformanceValueDataINTEL_Object *)self)->data;
    PyObject **self_arg = &((Py_PerformanceValueDataINTEL_Object *)self)->arg;

    if (!PyArg_ParseTupleAndKeywords(
        args, kwds, "|$OOOOO", kwlist,
        &arg_value_32, &arg_value_64, &arg_value_float, &arg_value_bool, &arg_value_string
    )) {
        goto error;
    }
    if (arg_value_32) {
        ++argc;
        *self_key = Py_PerformanceValueDataINTEL_KEY_value_32;
        if (!(*self_arg = PyLong_Check(arg_value_32) ? Py_NewRef(arg_value_32) : PyNumber_Long(arg_value_32))) {
            PyErr_Format(PyExc_TypeError, "Expecting int (got %s)", Py_TYPE(arg_value_32)->tp_name);
            goto error;
        }
        self_data->value32 = PyLong_AsUnsignedLong(*self_arg);
        if (PyErr_Occurred()) {
            goto error;
        }
    }
    if (arg_value_64) {
        ++argc;
        *self_key = Py_PerformanceValueDataINTEL_KEY_value_64;
        if (!(*self_arg = PyLong_Check(arg_value_64) ? Py_NewRef(arg_value_64) : PyNumber_Long(arg_value_64))) {
            PyErr_Format(PyExc_TypeError, "Expecting int (got %s)", Py_TYPE(arg_value_64)->tp_name);
            goto error;
        }
        self_data->value64 = PyLong_AsUnsignedLongLong(*self_arg);
        if (PyErr_Occurred()) {
            goto error;
        }
    }
    if (arg_value_float) {
        ++argc;
        *self_key = Py_PerformanceValueDataINTEL_KEY_value_float;
        if (!(*self_arg = PyFloat_Check(arg_value_float) ? Py_NewRef(arg_value_float) : PyNumber_Float(arg_value_float))) {
            PyErr_Format(PyExc_TypeError, "Expecting float (got %s)", Py_TYPE(arg_value_float)->tp_name);
            goto error;
        }
        self_data->valueFloat = (float)PyFloat_AsDouble(*self_arg);
        if (PyErr_Occurred()) {
            goto error;
        }
    }
    if (arg_value_bool) {
        ++argc;
        *self_key = Py_PerformanceValueDataINTEL_KEY_value_bool;
        if (!(*self_arg = PyBool_Check(arg_value_bool) ? Py_NewRef(arg_value_bool) : NULL)) {
            PyErr_Format(PyExc_TypeError, "Expecting bool (got %s)", Py_TYPE(arg_value_bool)->tp_name);
            goto error;
        }
        self_data->valueBool = Py_IsTrue(*self_arg);
        if (PyErr_Occurred()) {
            goto error;
        }
    }
    if (arg_value_string) {
        ++argc;
        *self_key = Py_PerformanceValueDataINTEL_KEY_value_string;
        if (!(*self_arg = PyUnicode_Check(arg_value_string) ? Py_NewRef(arg_value_string) : NULL)) {
            PyErr_Format(PyExc_TypeError, "Expecting str (got %s)", Py_TYPE(arg_value_string)->tp_name);
            goto error;
        }
        self_data->valueString = PyUnicode_AsUTF8(*self_arg);
        if (PyErr_Occurred()) {
            goto error;
        }
    }
    if (argc != 1) {
        PyErr_Format(PyExc_TypeError, "%s() takes exactly 1 argument (%i given)", cls->tp_name, argc);
        goto error;
    }
    return self;

error:
    Py_XDECREF(self);
    Py_XDECREF(arg_value_32);
    Py_XDECREF(arg_value_64);
    Py_XDECREF(arg_value_float);
    Py_XDECREF(arg_value_bool);
    Py_XDECREF(arg_value_string);
    return NULL;
}

static PyTypeObject Py_PerformanceValueDataINTEL_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME "." "PerformanceValueDataINTEL",
    .tp_basicsize = sizeof(Py_PerformanceValueDataINTEL_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_dealloc = Py_PerformanceValueDataINTEL_dealloc,
    .tp_repr = Py_PerformanceValueDataINTEL_repr,
    .tp_traverse = Py_PerformanceValueDataINTEL_traverse,
    .tp_clear = Py_PerformanceValueDataINTEL_clear,
    .tp_getset = Py_PerformanceValueDataINTEL_getset,
    .tp_new = Py_PerformanceValueDataINTEL_new
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
    .m_name = MUDULE_NAME,
    .m_doc = "Example module that creates an extension type.",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_template(void) {
    PyObject *module = PyModule_Create(&template_module);
    if (module == NULL) {
        return NULL;
    }
    if (
        PyType_Ready(&EnumDemo_Type) < 0 || PyType_Ready(&Enum_EnumDemo_Type) < 0 || PyModule_AddObjectRef(module, "EnumDemo", (PyObject *)&Enum_EnumDemo_Object) < 0 ||
        PyType_Ready(&FlagDemo_Type) < 0 || PyType_Ready(&Flag_FlagDemo_Type) < 0 || PyModule_AddObjectRef(module, "FlagDemo", (PyObject *)&Flag_FlagDemo_Object) < 0 ||
        0
    ) {
        Py_DECREF(module);
        return NULL;
    }
    if (
        PyType_Ready(&Py_PerformanceValueDataINTEL_Type) < 0 || PyModule_AddObjectRef(module, "PerformanceValueDataINTEL", (PyObject *)&Py_PerformanceValueDataINTEL_Type) < 0 ||
        0
    ) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
