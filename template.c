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

static void
UInt_dealloc(PyObject *self) {
    Py_TYPE(self)->tp_free(self);
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
} EnumObject;

static PyObject *
Enum_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<enum '%s'>", ((EnumObject *)self)->uint_cls->tp_name);
    return result;
}

static PyObject *
Enum_get(PyObject *self, void *closure) {
    return UInt_New(((EnumObject *)self)->uint_cls, *(uint64_t *)closure);
}


typedef struct {
    PyObject_HEAD
    PyTypeObject *uint_cls;
} FlagObject;

static PyObject *
Flag_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<flag '%s'>", ((FlagObject *)self)->uint_cls->tp_name);
    return result;
}

static PyObject *
Flag_get(PyObject *self, void *closure) {
    return UInt_New(((FlagObject *)self)->uint_cls, *(uint64_t *)closure);
}


static uint64_t EnumDemo_A = 5;
static uint64_t EnumDemo_B = 12;
static PyGetSetDef EnumDemoEnum_getsetdefs[] = {
    {"A", Enum_get, NULL, NULL, (void *)&EnumDemo_A},
    {"B", Enum_get, NULL, NULL, (void *)&EnumDemo_B},
    {NULL}
};
static PyTypeObject EnumDemoType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME ".EnumDemo",
    .tp_basicsize = sizeof(UIntObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_dealloc = UInt_dealloc,
    .tp_repr = UInt_repr,
    .tp_hash = UInt_hash,
    .tp_richcompare = UInt_richcompare
};
static PyTypeObject EnumDemoEnumType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME ".EnumDemoEnum",
    .tp_basicsize = sizeof(EnumObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_repr = Enum_repr,
    .tp_getset = EnumDemoEnum_getsetdefs
};
static EnumObject EnumDemoEnumObject = {
    PyObject_HEAD_INIT(&EnumDemoEnumType)
    .uint_cls = &EnumDemoType
};

static uint64_t FlagDemo_C = 55;
static uint64_t FlagDemo_D = 119;
static PyGetSetDef FlagDemoFlag_getsetdefs[] = {
    {"C", Flag_get, NULL, NULL, (void *)&FlagDemo_C},
    {"D", Flag_get, NULL, NULL, (void *)&FlagDemo_D},
    {NULL}
};
static PyTypeObject FlagDemoType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME ".FlagDemo",
    .tp_basicsize = sizeof(UIntObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_dealloc = UInt_dealloc,
    .tp_repr = UInt_repr,
    .tp_hash = UInt_hash,
    .tp_richcompare = UInt_richcompare,
    .tp_as_number = &UInt_numbermethods
};
static PyTypeObject FlagDemoFlagType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME ".FlagDemoFlag",
    .tp_basicsize = sizeof(FlagObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,
    .tp_repr = Flag_repr,
    .tp_getset = FlagDemoFlag_getsetdefs
};
static FlagObject FlagDemoFlagObject = {
    PyObject_HEAD_INIT(&FlagDemoFlagType)
    .uint_cls = &FlagDemoType
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
    uint8_t selection;
    //PyObject *obj;
} Py_PerformanceValueDataINTELObject;

static const char Py_PerformanceValueDataINTEL_KEY_value_32[] = "value_32";
static const char Py_PerformanceValueDataINTEL_KEY_value_64[] = "value_64";
static const char Py_PerformanceValueDataINTEL_KEY_value_float[] = "value_float";
static const char Py_PerformanceValueDataINTEL_KEY_value_bool[] = "value_bool";
static const char Py_PerformanceValueDataINTEL_KEY_value_string[] = "value_string";

static void
Py_PerformanceValueDataINTEL_dealloc(PyObject *self) {
    PyObject_GC_UnTrack(self);
    uint8_t *self_selection = &((Py_PerformanceValueDataINTELObject *)self)->selection;
    VkPerformanceValueDataINTEL *self_data = &((Py_PerformanceValueDataINTELObject *)self)->data;
    if (*self_selection == 4 && self_data->valueString != NULL) {
        free(self_data->valueString);
        self_data->valueString = NULL;
    }
    Py_TYPE(self)->tp_free(self);
}

// def __new__(
//     cls,
//     /,
//     *,
//     value_32: SupportsInt | SupportsIndex = ...,
//     value_64: SupportsInt | SupportsIndex = ...,
//     value_float: SupportsFloat | SupportsIndex = ...,
//     value_bool: bool = ...,
//     value_string: str = ...
// ) -> Py_PerformanceValueDataINTELObject: ...
static PyObject *
Py_PerformanceValueDataINTEL_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    static char *kwlist[] = {
        Py_PerformanceValueDataINTEL_KEY_value_32,
        Py_PerformanceValueDataINTEL_KEY_value_64,
        Py_PerformanceValueDataINTEL_KEY_value_float,
        Py_PerformanceValueDataINTEL_KEY_value_bool,
        Py_PerformanceValueDataINTEL_KEY_value_string,
        NULL
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

    uint8_t *self_selection = &((Py_PerformanceValueDataINTELObject *)self)->selection;
    VkPerformanceValueDataINTEL *self_data = &((Py_PerformanceValueDataINTELObject *)self)->data;
    //PyObject **self_obj = &((Py_PerformanceValueDataINTELObject *)self)->obj;

    if (!PyArg_ParseTupleAndKeywords(
        args, kwds, "|$OOOOO", kwlist,
        &arg_value_32, &arg_value_64, &arg_value_float, &arg_value_bool, &arg_value_string
    )) {
        goto error;
    }
    if (arg_value_32) {
        ++argc;
        *self_selection = 0;
        self_data->value32 = PyLong_AsUnsignedLongMask(arg_value_32);
        if (PyErr_Occurred()) {
            PyErr_Format(PyExc_TypeError, "Expecting int (got %s)", Py_TYPE(arg_value_32)->tp_name);
            goto error;
        }
        //if (PyErr_Occurred()) {
        //    goto error;
        //}
        //*self_obj = Py_NewRef(arg_value_32);
    }
    if (arg_value_64) {
        ++argc;
        //if (!PyLong_Check(arg_value_64)) {
        //    goto error;
        //}
        *self_selection = 1;
        self_data->value64 = PyLong_AsUnsignedLongLongMask(arg_value_64);
        if (PyErr_Occurred()) {
            PyErr_Format(PyExc_TypeError, "Expecting int (got %s)", Py_TYPE(arg_value_64)->tp_name);
            goto error;
        }
        //*self_obj = Py_NewRef(arg_value_64);
    }
    if (arg_value_float) {
        ++argc;
        //if (!PyFloat_Check(arg_value_float)) {
        //    goto error;
        //}
        *self_selection = 2;
        self_data->valueFloat = (float)PyFloat_AsDouble(arg_value_float);
        if (PyErr_Occurred()) {
            PyErr_Format(PyExc_TypeError, "Expecting float (got %s)", Py_TYPE(arg_value_float)->tp_name);
            goto error;
        }
        //*self_obj = Py_NewRef(arg_value_float);
    }
    if (arg_value_bool) {
        ++argc;
        if (!PyBool_Check(arg_value_bool)) {
            PyErr_Format(PyExc_TypeError, "Expecting bool (got %s)", Py_TYPE(arg_value_bool)->tp_name);
            goto error;
        }
        *self_selection = 3;
        self_data->valueBool = arg_value_bool == Py_True;
        //*self_obj = Py_NewRef(arg_value_bool);
    }
    if (arg_value_string) {
        ++argc;
        if (!PyUnicode_Check(arg_value_string)) {
            PyErr_Format(PyExc_TypeError, "Expecting str (got %s)", Py_TYPE(arg_value_string)->tp_name);
            goto error;
        }
        *self_selection = 4;
        //Py_ssize_t size = 0;
        //const char *s = PyUnicode_AsUTF8AndSize(arg_value_string, &size);
        self_data->valueString = strdup(PyUnicode_AsUTF8(arg_value_string));
        //memcpy(self_data->valueString, s, size + 1);
        //*self_obj = Py_NewRef(arg_value_string);
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

static int
Py_PerformanceValueDataINTEL_traverse(PyObject *self, visitproc visit, void *arg) {
    return 0;
}

static PyObject *
Py_PerformanceValueDataINTEL_repr(PyObject *self) {
    const char *field_name = NULL;
    PyObject *obj = NULL;
    uint8_t *self_selection = &((Py_PerformanceValueDataINTELObject *)self)->selection;
    VkPerformanceValueDataINTEL *self_data = &((Py_PerformanceValueDataINTELObject *)self)->data;

    switch (*self_selection) {
        case 0:
            field_name = Py_PerformanceValueDataINTEL_KEY_value_32;
            obj = PyLong_FromUnsignedLong(self_data->value32);
            break;
        case 1:
            field_name = Py_PerformanceValueDataINTEL_KEY_value_64;
            obj = PyLong_FromUnsignedLongLong(self_data->value64);
            break;
        case 2:
            field_name = Py_PerformanceValueDataINTEL_KEY_value_float;
            obj = PyFloat_FromDouble((double)self_data->valueFloat);
            break;
        case 3:
            field_name = Py_PerformanceValueDataINTEL_KEY_value_bool;
            obj = self_data->valueBool ? Py_True : Py_False;
            break;
        case 4:
            field_name = Py_PerformanceValueDataINTEL_KEY_value_string;
            obj = PyUnicode_FromString(self_data->valueString);
            break;
        default:
            goto error;
    }
    PyObject *result = PyUnicode_FromFormat("%s(%s=%R)", Py_TYPE(self)->tp_name, field_name, obj);
    Py_DECREF(obj);
    return result;

error:
    Py_XDECREF(obj);
    return NULL;
}

static PyTypeObject PerformanceValueDataINTELType = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = MUDULE_NAME "." "PerformanceValueDataINTEL",
    .tp_basicsize = sizeof(Py_PerformanceValueDataINTELObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_HAVE_GC,
    .tp_dealloc = Py_PerformanceValueDataINTEL_dealloc,
    .tp_new = Py_PerformanceValueDataINTEL_new,
    .tp_traverse = Py_PerformanceValueDataINTEL_traverse,
    .tp_repr = Py_PerformanceValueDataINTEL_repr
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
        PyType_Ready(&EnumDemoType) < 0 || PyType_Ready(&EnumDemoEnumType) < 0 || PyModule_AddObjectRef(module, "EnumDemo", (PyObject *)&EnumDemoEnumObject) < 0 ||
        PyType_Ready(&FlagDemoType) < 0 || PyType_Ready(&FlagDemoFlagType) < 0 || PyModule_AddObjectRef(module, "FlagDemo", (PyObject *)&FlagDemoFlagObject) < 0 ||
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
