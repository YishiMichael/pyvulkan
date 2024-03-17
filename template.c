#define PY_SSIZE_T_CLEAN
#include <Python.h>

#define PyHASH_TRUNC(x) ((x) & ~(Py_hash_t)0)
#define MUDULE_NAME "template"


typedef struct {
    PyObject_HEAD
    uint64_t value;
} UIntObject;

static inline uint64_t
UInt_GetValue(PyObject *self) {
    return ((UIntObject *)self)->value;
}

static inline PyObject *
UInt_New(PyTypeObject *cls, uint64_t value) {
    PyObject *self = cls->tp_alloc(cls, 0);
    ((UIntObject *)self)->value = value;
    return self;
}

static PyObject *
UInt_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<%s: %llu>", Py_TYPE(self)->tp_name, UInt_GetValue(self));
    return result;
}

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

static PyNumberMethods UInt_numbermethods = {
    .nb_and = UInt_and,
    .nb_or = UInt_or
};


typedef struct {
    PyObject_HEAD
    PyTypeObject *uint_cls;
} UIntMetaObject;

static PyObject *
UIntMeta_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<class '%s'>", ((UIntMetaObject *)self)->uint_cls->tp_name);
    return result;
}

static PyObject *
UIntMeta_get(PyObject *self, void *closure) {
    return UInt_New(((UIntMetaObject *)self)->uint_cls, *(uint64_t *)closure);
}


#define ENUM_NEW(name, numbermethods, getsetdefs)                   \
static PyTypeObject name##Type = {                                  \
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)                       \
    .tp_name = MUDULE_NAME "." #name,                               \
    .tp_basicsize = sizeof(UIntObject),                             \
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,      \
    .tp_repr = UInt_repr,                                           \
    .tp_hash = UInt_hash,                                           \
    .tp_richcompare = UInt_richcompare,                             \
    .tp_as_number = (numbermethods)                                 \
};                                                                  \
static PyTypeObject name##MetaType = {                              \
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)                       \
    .tp_name = MUDULE_NAME "." #name "Meta",                        \
    .tp_basicsize = sizeof(UIntMetaObject),                         \
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,      \
    .tp_repr = UIntMeta_repr,                                       \
    .tp_getset = (getsetdefs)                                       \
};                                                                  \
static UIntMetaObject name##MetaObject = {                          \
    PyObject_HEAD_INIT(&name##MetaType)                             \
    .uint_cls = &name##Type                                         \
};

static uint64_t EnumDemo_A = 5;
static uint64_t EnumDemo_B = 12;
static PyGetSetDef EnumDemoType_getsetdefs[] = {
    {"A", UIntMeta_get, NULL, NULL, (void *)&EnumDemo_A},
    {"B", UIntMeta_get, NULL, NULL, (void *)&EnumDemo_B},
    {NULL}
};
ENUM_NEW(EnumDemo, NULL, EnumDemoType_getsetdefs)

static uint64_t FlagDemo_C = 55;
static uint64_t FlagDemo_D = 119;
static PyGetSetDef FlagDemoType_getsetdefs[] = {
    {"C", UIntMeta_get, NULL, NULL, (void *)&FlagDemo_C},
    {"D", UIntMeta_get, NULL, NULL, (void *)&FlagDemo_D},
    {NULL}
};
ENUM_NEW(FlagDemo, &UInt_numbermethods, FlagDemoType_getsetdefs)

#undef ENUM_NEW


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
    uint64_t selection;
    PyObject *obj;
} PerformanceValueDataINTELObject;

// def __new__(
//     cls,
//     /,
//     *,
//     value_32: int = ...,
//     value_64: int = ...,
//     value_float: float = ...,
//     value_bool: bool = ...,
//     value_string: str = ...
// ) -> PerformanceValueDataINTELObject: ...
static PyObject *
PerformanceValueDataINTEL_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    static char *kwlist[] = {"value_32", "value_64", "value_float", "value_bool", "value_string", NULL};
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

    uint64_t *self_selection = &((PerformanceValueDataINTELObject *)self)->selection;
    VkPerformanceValueDataINTEL *self_data = &((PerformanceValueDataINTELObject *)self)->data;
    PyObject **self_obj = &((PerformanceValueDataINTELObject *)self)->obj;

    if (!PyArg_ParseTupleAndKeywords(
        args, kwds, "|$OOOOO", kwlist,
        &arg_value_32, &arg_value_64, &arg_value_float, &arg_value_bool, &arg_value_string
    )) {
        goto error;
    }
    if (arg_value_32) {
        ++argc;
        if (!PyLong_Check(arg_value_32)) {
            PyErr_Format(PyExc_TypeError, "%s() argument 'value_32' should be of type int (got %s)", cls->tp_name, Py_TYPE(arg_value_32)->tp_name);
            goto error;
        }
        *self_selection = 0;
        self_data->value32 = PyLong_AsUnsignedLong(arg_value_32);
        *self_obj = Py_NewRef(arg_value_32);
    }
    if (arg_value_64) {
        ++argc;
        if (!PyLong_Check(arg_value_64)) {
            PyErr_Format(PyExc_TypeError, "%s() argument 'value_64' should be of type int (got %s)", cls->tp_name, Py_TYPE(arg_value_64)->tp_name);
            goto error;
        }
        *self_selection = 1;
        self_data->value64 = PyLong_AsUnsignedLongLong(arg_value_64);
        *self_obj = Py_NewRef(arg_value_64);
    }
    if (arg_value_float) {
        ++argc;
        if (!PyFloat_Check(arg_value_float)) {
            PyErr_Format(PyExc_TypeError, "%s() argument 'value_float' should be of type float (got %s)", cls->tp_name, Py_TYPE(arg_value_float)->tp_name);
            goto error;
        }
        *self_selection = 2;
        self_data->valueFloat = (float)PyFloat_AsDouble(arg_value_float);
        *self_obj = Py_NewRef(arg_value_float);
    }
    if (arg_value_bool) {
        ++argc;
        if (!PyBool_Check(arg_value_bool)) {
            PyErr_Format(PyExc_TypeError, "%s() argument 'value_bool' should be of type bool (got %s)", cls->tp_name, Py_TYPE(arg_value_bool)->tp_name);
            goto error;
        }
        *self_selection = 3;
        self_data->valueBool = arg_value_bool == Py_True;
        *self_obj = Py_NewRef(arg_value_bool);
    }
    if (arg_value_string) {
        ++argc;
        if (!PyUnicode_Check(arg_value_string)) {
            PyErr_Format(PyExc_TypeError, "%s() argument 'value_string' should be of type str (got %s)", cls->tp_name, Py_TYPE(arg_value_string)->tp_name);
            goto error;
        }
        *self_selection = 4;
        self_data->valueString = PyUnicode_AsUTF8(arg_value_string);
        *self_obj = Py_NewRef(arg_value_string);
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

static PyObject *
PerformanceValueDataINTEL_repr(PyObject *self) {
    char *field_name = NULL;
    switch (((PerformanceValueDataINTELObject *)self)->selection) {
        case 0:
            field_name = "value_32";
            break;
        case 1:
            field_name = "value_64";
            break;
        case 2:
            field_name = "value_float";
            break;
        case 3:
            field_name = "value_bool";
            break;
        case 4:
            field_name = "value_string";
            break;
    }
    PyObject *result = PyUnicode_FromFormat("%s(%s=%R)", Py_TYPE(self)->tp_name, field_name, ((PerformanceValueDataINTELObject *)self)->obj);
    return result;
}

static PyTypeObject PerformanceValueDataINTELType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME "." "PerformanceValueDataINTEL",
    .tp_basicsize = sizeof(PerformanceValueDataINTELObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_new = PerformanceValueDataINTEL_new,
    .tp_repr = PerformanceValueDataINTEL_repr
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

#define ENUM_READY(name, module)                                           \
PyType_Ready(&name##Type) < 0 ||                                           \
PyType_Ready(&name##MetaType) < 0 ||                                       \
PyModule_AddObjectRef((module), #name, (PyObject *)&name##MetaObject) < 0

PyMODINIT_FUNC
PyInit_template(void) {
    PyObject *module = PyModule_Create(&template_module);
    if (module == NULL) {
        return NULL;
    }
    if (
        ENUM_READY(EnumDemo, module) ||
        ENUM_READY(FlagDemo, module) ||
        0
    ) {
        Py_DECREF(module);
        return NULL;
    }
    if (
        PyType_Ready(&PerformanceValueDataINTELType) < 0 || PyModule_AddObjectRef(module, "PerformanceValueDataINTEL", (PyObject *)&PerformanceValueDataINTELType) < 0 ||
        0
    ) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}

#undef ENUM_READY
