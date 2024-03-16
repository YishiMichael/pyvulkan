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

//static PyObject *
//UInt_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
//    static char *kwlist[] = {"value", NULL};
//    PyObject *self = cls->tp_alloc(cls, 0);
//    if (self == NULL) {
//        return NULL;
//    }
//    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|K", kwlist, &UInt_GetValue(self))) {
//        Py_DECREF(self);
//        return NULL;
//    }
//    return self;
//}

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
    PyTypeObject *uint_tp;
} UIntMetaObject;

static PyObject *
UIntMeta_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<class '%s'>", ((UIntMetaObject *)self)->uint_tp->tp_name);
    return result;
}

static PyObject *
UIntMeta_get(PyObject *self, void *closure) {
    return UInt_New(((UIntMetaObject *)self)->uint_tp, *(uint64_t *)closure);
}


#define ENUM_ENTRY(name, value)                                     \
{#name, UIntMeta_get, NULL, NULL, (void *)&(value)}

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
    .uint_tp = &name##Type                                          \
};

static uint64_t EnumDemo_A = 5;
static uint64_t EnumDemo_B = 12;
static PyGetSetDef EnumDemoType_getsetdefs[] = {
    ENUM_ENTRY(A, EnumDemo_A),
    ENUM_ENTRY(B, EnumDemo_B),
    {NULL}
};
ENUM_NEW(EnumDemo, NULL, EnumDemoType_getsetdefs)

static uint64_t FlagDemo_C = 55;
static uint64_t FlagDemo_D = 119;
static PyGetSetDef FlagDemoType_getsetdefs[] = {
    ENUM_ENTRY(C, FlagDemo_C),
    ENUM_ENTRY(D, FlagDemo_D),
    {NULL}
};
ENUM_NEW(FlagDemo, &UInt_numbermethods, FlagDemoType_getsetdefs)

#undef ENUM_NEW
#undef ENUM_ENTRY


//inline int
//EnumInit_AddMember(PyTypeObject *cls, const char *name, uint64_t value) {
//    PyObject *enum_member = UInt_New(cls, value);
//    int result = PyDict_SetItemString(cls->tp_dict, name, enum_member);
//    Py_DECREF(enum_member);
//    return result;
//}

//int
//ModuleInit_InitEnums(PyObject *module) {
//    return (
//        PyType_Ready(&EnumDemoType) || PyModule_AddObjectRef(module, "EnumDemo", (PyObject *)&EnumDemoType) ||
//        PyType_Ready(&FlagDemoType) || PyModule_AddObjectRef(module, "FlagDemo", (PyObject *)&FlagDemoType) ||
//        0
//    );
//    //PyTypeObject *cls = NULL;

//    //cls = &EnumDemoType;
//    //if (PyType_Ready(cls) || PyModule_AddObjectRef(module, "EnumDemo", (PyObject *)cls)) {
//    //    return -1;
//    //}
//    //cls = &FlagDemoType;
//    //if (PyType_Ready(cls) || PyModule_AddObjectRef(module, "FlagDemo", (PyObject *)cls)) {
//    //    return -1;
//    //}
//    //return 0;
//}


typedef struct {
    int m_int;
    const char *m_str;
    void *m_bytes;
    int m_bytes_len;
} StructDemo;


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
    return module;
}

#undef ENUM_READY
