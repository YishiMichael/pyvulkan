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
            return Py_TYPE(self) == Py_TYPE(other) ? Py_False : UInt_GetValue(self) == UInt_GetValue(other) ? Py_False : Py_True;
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


#define NEW_ENUM(name)                                             \
    {                                                              \
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)                  \
        .tp_name = MUDULE_NAME "." name,                           \
        .tp_basicsize = sizeof(UIntObject),                        \
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE, \
        .tp_repr = UInt_repr,                                      \
        .tp_hash = UInt_hash,                                      \
        .tp_richcompare = UInt_richcompare,                        \
        .tp_as_number = NULL                                       \
    }
#define NEW_FLAG(name)                                             \
    {                                                              \
        .ob_base = PyVarObject_HEAD_INIT(NULL, 0)                  \
        .tp_name = MUDULE_NAME "." name,                           \
        .tp_basicsize = sizeof(UIntObject),                        \
        .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE, \
        .tp_repr = UInt_repr,                                      \
        .tp_hash = UInt_hash,                                      \
        .tp_richcompare = UInt_richcompare,                        \
        .tp_as_number = &UInt_numbermethods                        \
    }

static PyTypeObject EnumDemoType = NEW_ENUM("EnumDemo");
static PyTypeObject FlagDemoType = NEW_FLAG("FlagDemo");

#undef NEW_FLAG
#undef NEW_ENUM


inline int
EnumInit_AddMember(PyTypeObject *cls, const char *name, uint64_t value) {
    PyObject *enum_member = UInt_New(cls, value);
    int result = PyDict_SetItemString(cls->tp_dict, name, enum_member);
    Py_DECREF(enum_member);
    return result;
}

int
ModuleInit_InitEnums(PyObject *module) {
    PyTypeObject *cls = NULL;

    cls = &EnumDemoType;
    if (PyType_Ready(cls)
        || EnumInit_AddMember(cls, "A", 5)
        || EnumInit_AddMember(cls, "B", 12)
        || PyModule_AddObjectRef(module, "EnumDemo", (PyObject *)cls)
    ) {
        return -1;
    }
    cls = &FlagDemoType;
    if (PyType_Ready(cls)
        || EnumInit_AddMember(cls, "C", 55)
        || EnumInit_AddMember(cls, "D", 119)
        || PyModule_AddObjectRef(module, "FlagDemo", (PyObject *)cls)
    ) {
        return -1;
    }
    return 0;
}


//typedef struct {
//    int int_field;
//    const char *str_field;
//    
//} StructDemo;


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
    if (ModuleInit_InitEnums(module)) {
        Py_DECREF(module);
        return NULL;
    }
    return module;
}
