#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <numpy/ndarrayobject.h>


static uint64_t PyvkEnumDemo_A = 5;
static uint64_t PyvkEnumDemo_B = 12;

static uint64_t PyvkFlagDemo_C = 55;
static uint64_t PyvkFlagDemo_D = 118;

typedef uint32_t VkBool32;

typedef enum {
    VK_STRUCTURE_TYPE_STRUCT_DEMO = 0
} VkStructureType;


// base

typedef struct {
    PyObject_HEAD
} Pyvk_Object_Object;

static void
Pyvk_Object_dealloc(PyObject *self) {
    Py_TYPE(self)->tp_free(self);
}

static PyTypeObject Pyvk_Object_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Object",
    .tp_basicsize = sizeof(Pyvk_Object_Object),
    .tp_dealloc = Pyvk_Object_dealloc,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE
};


// enums

static PyTypeObject Pyvk_Enum_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Enum",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &Pyvk_Object_Type
};


typedef struct {
    PyObject_HEAD
    uint64_t value;
} Pyvk_Enum64_Object;

static PyObject *
Pyvk_Enum64_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<%s: %llu>", Py_TYPE(self)->tp_name, ((Pyvk_Enum64_Object *)self)->value);
    return result;
}

static Py_hash_t
Pyvk_Enum64_hash(PyObject *self) {
    Py_hash_t result = ((Pyvk_Enum64_Object *)self)->value & ~(Py_hash_t)0;
    if (result == -1) {
        result = -2;
    }
    return result;
}

static PyObject *
Pyvk_Enum64_richcompare(PyObject *self, PyObject *other, int op) {
    switch (op) {
        case Py_EQ:
            return (
                Py_TYPE(self) != Py_TYPE(other) ? Py_False :
                ((Pyvk_Enum64_Object *)self)->value != ((Pyvk_Enum64_Object *)other)->value ? Py_False :
                Py_True
            );
        case Py_NE:
            return (
                Py_TYPE(self) != Py_TYPE(other) ? Py_True :
                ((Pyvk_Enum64_Object *)self)->value != ((Pyvk_Enum64_Object *)other)->value ? Py_True :
                Py_False
            );
    }
    return Py_NotImplemented;
}

static PyTypeObject Pyvk_Enum64_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Enum64",
    .tp_basicsize = sizeof(Pyvk_Enum64_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_repr = Pyvk_Enum64_repr,
    .tp_hash = Pyvk_Enum64_hash,
    .tp_richcompare = Pyvk_Enum64_richcompare,
    .tp_base = &Pyvk_Enum_Type
};


static PyObject *
Pyvk_Flag64_invert(PyObject *self) {
    PyObject *result = Py_TYPE(self)->tp_alloc(Py_TYPE(self), 0);
    ((Pyvk_Enum64_Object *)result)->value = ~((Pyvk_Enum64_Object *)self)->value;
    return result;
}

static PyObject *
Pyvk_Flag64_and(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    PyObject *result = Py_TYPE(self)->tp_alloc(Py_TYPE(self), 0);
    ((Pyvk_Enum64_Object *)result) = ((Pyvk_Enum64_Object *)self)->value & ((Pyvk_Enum64_Object *)other)->value;
    return result;
}

static PyObject *
Pyvk_Flag64_xor(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    PyObject *result = Py_TYPE(self)->tp_alloc(Py_TYPE(self), 0);
    ((Pyvk_Enum64_Object *)result) = ((Pyvk_Enum64_Object *)self)->value ^ ((Pyvk_Enum64_Object *)other)->value;
    return result;
}

static PyObject *
Pyvk_Flag64_or(PyObject *self, PyObject *other) {
    if (Py_TYPE(self) != Py_TYPE(other)) {
        return Py_NotImplemented;
    }
    PyObject *result = Py_TYPE(self)->tp_alloc(Py_TYPE(self), 0);
    ((Pyvk_Enum64_Object *)result) = ((Pyvk_Enum64_Object *)self)->value | ((Pyvk_Enum64_Object *)other)->value;
    return result;
}

static PyNumberMethods Pyvk_Flag64_as_number = {
    .nb_invert = Pyvk_Flag64_invert,
    .nb_and = Pyvk_Flag64_and,
    .nb_xor = Pyvk_Flag64_xor,
    .nb_or = Pyvk_Flag64_or
};

static PyTypeObject Pyvk_Flag64_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Flag64",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_as_number = &Pyvk_Flag64_as_number,
    .tp_base = &Pyvk_Enum64_Type
};


//typedef struct {
//    PyObject_HEAD
//} Pyvk_EnumMeta_Object;

static PyTypeObject Pyvk_EnumMeta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._EnumMeta",
    //.tp_basicsize = sizeof(Pyvk_EnumMeta_Object),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &Pyvk_Object_Type
};


typedef struct {
    PyObject_HEAD
    PyTypeObject *enum64_cls;
} Pyvk_Enum64Meta_Object;

static PyObject *
Pyvk_Enum64Meta_get(PyObject *self, void *closure) {
    Pyvk_Enum64_Object *result = PyObject_New(Pyvk_Enum64_Object, ((Pyvk_Enum64Meta_Object *)self)->enum64_cls);
    result->value = *(uint64_t *)closure;
    return result;
}

static PyObject *
Pyvk_Enum64Meta_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<enum64 '%s'>", ((Pyvk_Enum64Meta_Object *)self)->enum64_cls->tp_name);
    return result;
}

static PyTypeObject Pyvk_Enum64Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Enum64Meta",
    .tp_basicsize = sizeof(Pyvk_Enum64Meta_Object),
    .tp_repr = Pyvk_Enum64Meta_repr,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &Pyvk_EnumMeta_Type
};

static PyObject *
Pyvk_Flag64Meta_repr(PyObject *self) {
    PyObject *result = PyUnicode_FromFormat("<flag64 '%s'>", ((Pyvk_Enum64Meta_Object *)self)->enum64_cls->tp_name);
    return result;
}

static PyTypeObject Pyvk_Flag64Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Flag64Meta",
    .tp_repr = Pyvk_Flag64Meta_repr,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &Pyvk_Enum64Meta_Type
};


static PyGetSetDef PyvkEnumDemo_Meta_getset[] = {
    {
        .name = "A",
        .get = Pyvk_Enum64Meta_get,
        .closure = (void *)&PyvkEnumDemo_A
    },
    {
        .name = "B",
        .get = Pyvk_Enum64Meta_get,
        .closure = (void *)&PyvkEnumDemo_B
    },
    {NULL}
};

static PyTypeObject PyvkEnumDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.EnumDemo",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    .tp_base = &Pyvk_Enum64_Type
};

static PyTypeObject PyvkEnumDemo_Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.EnumDemo_Meta",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    .tp_getset = PyvkEnumDemo_Meta_getset,
    .tp_base = &Pyvk_Enum64Meta_Type
};

static Pyvk_Enum64Meta_Object PyvkEnumDemo_Meta_Object = {
    PyObject_HEAD_INIT(&PyvkEnumDemo_Meta_Type)
    .enum64_cls = &PyvkEnumDemo_Type
};  // final


static PyGetSetDef PyvkFlagDemo_Meta_getset[] = {
    {
        .name = "C",
        .get = Pyvk_Enum64Meta_get,
        .closure = (void *)&PyvkFlagDemo_C
    },
    {
        .name = "D",
        .get = Pyvk_Enum64Meta_get,
        .closure = (void *)&PyvkFlagDemo_D
    },
    {NULL}
};

static PyTypeObject PyvkFlagDemo_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.FlagDemo",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    .tp_base = &Pyvk_Flag64_Type
};

static PyTypeObject PyvkFlagDemo_Meta_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.FlagDemo_Meta",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    .tp_getset = PyvkFlagDemo_Meta_getset,
    .tp_base = &Pyvk_Flag64Meta_Type
};

static Pyvk_Enum64Meta_Object PyvkFlagDemo_Meta_Object = {
    PyObject_HEAD_INIT(&PyvkFlagDemo_Meta_Type)
    .enum64_cls = &PyvkFlagDemo_Type
};  // final


// c -> py converters

typedef struct {
    PyObject_HEAD
    PyObject *enum64_cls;
} Pyvk_Field_Object;


static PyObject *
Pyvk_Construct__PyBytes__char_p(const char *csrc) {
    return PyBytes_FromString(csrc);
}

static PyObject *
Pyvk_Construct__PyBytes__char_x16(const char csrc[16]) {
    return PyBytes_FromString(csrc);
}

// Use PyArray_SimpleNew, memcpy for 1d arrays
// PyObject *pydst = PyArray_SimpleNew(0, NULL, NPY_UINT32);
// if (!pydst) {
//     return NULL;
// }
// memcpy(PyArray_DATA(pydst), &csrc, sizeof(csrc));
static PyObject *
Pyvk_Construct__NPY_UINT32_Scalar__uint32(uint32_t csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_UINT32), NULL);
}

static PyObject *
Pyvk_Construct__NPY_UINT64_Scalar__uint64(uint64_t csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_UINT64), NULL);
}

static PyObject *
Pyvk_Construct__NPY_FLOAT_Scalar__float(float csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_FLOAT), NULL);
}

static PyObject *
Pyvk_Construct__NPY_UINT32_Scalar__bool32(VkBool32 csrc) {
    return PyArray_Scalar(&csrc, PyArray_DescrFromType(NPY_UINT32), NULL);
}

static PyObject *
Pyvk_Construct__PyvkStructDemo__VkStructDemo_p(VkStructDemo *csrc) {

}

static PyObject *
Pyvk_Construct__Pyvk_Struct__pNext(void *csrc) {
    switch (*(VkStructureType *)csrc) {
        case VK_STRUCTURE_TYPE_STRUCT_DEMO:
            return Pyvk_Construct__PyvkStructDemo__VkStructDemo_p(*(VkStructDemo *)csrc);
    }
    PyErr_Format(PyExc_RuntimeError, "Unrecognized pNext field");
    return NULL;
}


// py -> c converters

// 1d, 2d, 3d arrays - PyArray_AsCArray & PyArray_Free
static int
Pyvk_Convert__ScalarLike__uint32(PyObject *pysrc, uint32_t *cdst) {
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
Pyvk_Convert__ScalarLike__uint64(PyObject *pysrc, uint64_t *cdst) {
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
Pyvk_Convert__ScalarLike__float(PyObject *pysrc, float *cdst) {
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
Pyvk_Convert__ScalarLike__bool32(PyObject *pysrc, VkBool32 *cdst) {
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
Pyvk_Convert__BytesLike__char_p(PyObject *pysrc, char **cdst, PyObject *pyref) {
    *pyref = (
        PyUnicode_Check(pysrc) ? Py_NewRef(pysrc) :
        PyBytes_Check(pysrc) ? Py_NewRef(pysrc) :  // TODO
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


// data

//typedef struct {
//    PyObject_HEAD
//} Pyvk_Data_Object;

//static void
//Pyvk_Data_dealloc(PyObject *self) {
//    Py_TYPE(self)->tp_free(self);
//}

//// subtypes may require gc
//static PyTypeObject Pyvk_Data_Type = {
//    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
//    .tp_name = "pyvulkan._Data",
//    .tp_basicsize = sizeof(Pyvk_Data_Object),
//    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
//    .tp_dealloc = Pyvk_Data_dealloc
//};


// unions

//typedef struct {
//    PyObject_HEAD
//} Pyvk_Union_Object;

//static void
//Pyvk_Union_dealloc(PyObject *self) {
//    Py_TYPE(self)->tp_free(self);
//}

static PyTypeObject Pyvk_Union_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Union",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &Pyvk_Object_Type
};


typedef union {
    uint32_t value32;
    uint64_t value64;
    float valueFloat;
    VkBool32 valueBool;
    const char *valueString;
} VkPerformanceValueDataINTEL;

static const char PyvkPerformanceValueDataINTEL_KEY_value32[] = "value_32";
static const char PyvkPerformanceValueDataINTEL_KEY_value64[] = "value_64";
static const char PyvkPerformanceValueDataINTEL_KEY_valueFloat[] = "value_float";
static const char PyvkPerformanceValueDataINTEL_KEY_valueBool[] = "value_bool";
static const char PyvkPerformanceValueDataINTEL_KEY_valueString[] = "value_string";

typedef struct {
    PyObject_HEAD
    VkPerformanceValueDataINTEL data;
    const char *key;
    PyObject *ref_valueString;
} PyvkPerformanceValueDataINTEL_Object;

static void
PyvkPerformanceValueDataINTEL_dealloc(PyObject *self) {
    PyObject_GC_UnTrack(self);
    Py_CLEAR(((PyvkPerformanceValueDataINTEL_Object *)self)->ref_valueString);
    Py_TYPE(self)->tp_free(self);
}

//static PyObject *
//PyvkPerformanceValueDataINTEL_repr(PyObject *self) {
//    const char *key = ((PyvkPerformanceValueDataINTEL_Object *)self)->key;
//    PyObject *arg = PyObject_GetAttrString(self, key);
//    if (!arg) {
//        return NULL;
//    }
//    PyObject *result = PyUnicode_FromFormat("%s(%s=%R)", Py_TYPE(self)->tp_name, key, arg);
//    Py_CLEAR(arg);
//    return result;
//}

static int
PyvkPerformanceValueDataINTEL_traverse(PyObject *self, visitproc visit, void *arg) {
    Py_VISIT(((PyvkPerformanceValueDataINTEL_Object *)self)->ref_valueString);
    return 0;
}

static int
PyvkPerformanceValueDataINTEL_clear(PyObject *self) {
    Py_CLEAR(((PyvkPerformanceValueDataINTEL_Object *)self)->ref_valueString);
    return 0;
}

static PyObject *
PyvkPerformanceValueDataINTEL_get__address(PyObject *self, void *Py_UNUSED(closure)) {
    return PyLong_FromVoidPtr(&((PyvkPerformanceValueDataINTEL_Object *)self)->data);
}

static PyObject *
PyvkPerformanceValueDataINTEL_get_value32(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PyvkPerformanceValueDataINTEL_Object *)self)->key != PyvkPerformanceValueDataINTEL_KEY_value32) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PyvkPerformanceValueDataINTEL_Object *)self)->key, PyvkPerformanceValueDataINTEL_KEY_value32);
        return NULL;
    }
    return Pyvk_Construct__NPY_UINT32_Scalar__uint32(((PyvkPerformanceValueDataINTEL_Object *)self)->data.value32);
}

static PyObject *
PyvkPerformanceValueDataINTEL_get_value64(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PyvkPerformanceValueDataINTEL_Object *)self)->key != PyvkPerformanceValueDataINTEL_KEY_value64) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PyvkPerformanceValueDataINTEL_Object *)self)->key, PyvkPerformanceValueDataINTEL_KEY_value64);
        return NULL;
    }
    return Pyvk_Construct__NPY_UINT64_Scalar__uint64(((PyvkPerformanceValueDataINTEL_Object *)self)->data.value64);
}

static PyObject *
PyvkPerformanceValueDataINTEL_get_valueFloat(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PyvkPerformanceValueDataINTEL_Object *)self)->key != PyvkPerformanceValueDataINTEL_KEY_valueFloat) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PyvkPerformanceValueDataINTEL_Object *)self)->key, PyvkPerformanceValueDataINTEL_KEY_valueFloat);
        return NULL;
    }
    return Pyvk_Construct__NPY_FLOAT_Scalar__float(((PyvkPerformanceValueDataINTEL_Object *)self)->data.valueFloat);
}

static PyObject *
PyvkPerformanceValueDataINTEL_get_valueBool(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PyvkPerformanceValueDataINTEL_Object *)self)->key != PyvkPerformanceValueDataINTEL_KEY_valueBool) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PyvkPerformanceValueDataINTEL_Object *)self)->key, PyvkPerformanceValueDataINTEL_KEY_valueBool);
        return NULL;
    }
    return Pyvk_Construct__NPY_UINT32_Scalar__bool32(((PyvkPerformanceValueDataINTEL_Object *)self)->data.valueBool);
}

static PyObject *
PyvkPerformanceValueDataINTEL_get_valueString(PyObject *self, void *Py_UNUSED(closure)) {
    if (((PyvkPerformanceValueDataINTEL_Object *)self)->key != PyvkPerformanceValueDataINTEL_KEY_valueString) {
        PyErr_Format(PyExc_RuntimeError, "%s object was created via key '%s' (accessing '%s')", Py_TYPE(self)->tp_name, ((PyvkPerformanceValueDataINTEL_Object *)self)->key, PyvkPerformanceValueDataINTEL_KEY_valueString);
        return NULL;
    }
    return Pyvk_Construct__PyBytes__char_p(((PyvkPerformanceValueDataINTEL_Object *)self)->data.valueString);
}

static PyGetSetDef PyvkPerformanceValueDataINTEL_getset[] = {
    {
        .name = "_address",
        .get = PyvkPerformanceValueDataINTEL_get__address
    },
    {
        .name = PyvkPerformanceValueDataINTEL_KEY_value32,
        .get = PyvkPerformanceValueDataINTEL_get_value32
    },
    {
        .name = PyvkPerformanceValueDataINTEL_KEY_value64,
        .get = PyvkPerformanceValueDataINTEL_get_value64
    },
    {
        .name = PyvkPerformanceValueDataINTEL_KEY_valueFloat,
        .get = PyvkPerformanceValueDataINTEL_get_valueFloat
    },
    {
        .name = PyvkPerformanceValueDataINTEL_KEY_valueBool,
        .get = PyvkPerformanceValueDataINTEL_get_valueBool
    },
    {
        .name = PyvkPerformanceValueDataINTEL_KEY_valueString,
        .get = PyvkPerformanceValueDataINTEL_get_valueString
    },
    {NULL}
};

// @overload
// def __new__(
//     cls,
//     *,
//     value_32: SupportsInt
// ) -> PerformanceValueDataINTEL: ...
static PyObject *
PyvkPerformanceValueDataINTEL_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    static const char *kwlist[] = {
        PyvkPerformanceValueDataINTEL_KEY_value32,
        PyvkPerformanceValueDataINTEL_KEY_value64,
        PyvkPerformanceValueDataINTEL_KEY_valueFloat,
        PyvkPerformanceValueDataINTEL_KEY_valueBool,
        PyvkPerformanceValueDataINTEL_KEY_valueString,
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
        arg_value32 ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_value32, Pyvk_Convert__ScalarLike__uint32(arg_value32, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.value32)) :
        arg_value64 ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_value64, Pyvk_Convert__ScalarLike__uint64(arg_value64, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.value64)) :
        arg_valueFloat ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_valueFloat, Pyvk_Convert__ScalarLike__float(arg_valueFloat, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.valueFloat)) :
        arg_valueBool ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_valueBool, Pyvk_Convert__ScalarLike__bool32(arg_valueBool, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.valueBool)) :
        arg_valueString ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_valueString, Pyvk_Convert__BytesLike__char_p(arg_valueString, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.valueString, &((PyvkPerformanceValueDataINTEL_Object *)self)->ref_valueString)) :
        0
    ) < 0) {
        goto error;
    }
    return self;

error:
    Py_CLEAR(self);
    return NULL;
}

//static void
//PyvkPerformanceValueDataINTEL_free(void *self) {
//    const char *key = ((PyvkPerformanceValueDataINTEL_Object *)self)->key;
//    VkPerformanceValueDataINTEL *data = &((PyvkPerformanceValueDataINTEL_Object *)self)->data;
//    if (
//        key == PyvkPerformanceValueDataINTEL_KEY_valueString ? (PyMem_RawFree(data->valueString), data->valueString = NULL, 0) :
//        0
//    ) {}
//    PyObject_Free(self);
//}

static PyTypeObject PyvkPerformanceValueDataINTEL_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan.PerformanceValueDataINTEL",
    .tp_basicsize = sizeof(PyvkPerformanceValueDataINTEL_Object),
    .tp_dealloc = PyvkPerformanceValueDataINTEL_dealloc,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE,  // final
    .tp_traverse = PyvkPerformanceValueDataINTEL_traverse,
    .tp_clear = PyvkPerformanceValueDataINTEL_clear,
    .tp_getset = PyvkPerformanceValueDataINTEL_getset,
    .tp_base = &Pyvk_Union_Type,
    .tp_new = PyvkPerformanceValueDataINTEL_new
    //.tp_free = PyvkPerformanceValueDataINTEL_free
};


// structs

static PyTypeObject Pyvk_Struct_Type = {
    .ob_base = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyvulkan._Struct",
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_IMMUTABLETYPE | Py_TPFLAGS_BASETYPE,
    .tp_base = &Pyvk_Object_Type
};



typedef struct {
    VkStructureType sType;
    const char *pStr;
    const char str16[16];
    void *pNext;
    float matrix[3][4];
    uint32_t valueCount;
    uint32_t *values;  // len = valueCount
    PerformanceValueDataINTEL *child;  // optional: can be NULL
    uint32_t childrenCount;
    PerformanceValueDataINTEL *children;  // len = childrenCount
} VkStructDemo;

static const char PyvkStructDemo_KEY_sType[] = "s_type";
static const char PyvkStructDemo_KEY_pStr[] = "str";
static const char PyvkStructDemo_KEY_str16[] = "str16";
static const char PyvkStructDemo_KEY_pNext[] = "next";
static const char PyvkStructDemo_KEY_matrix[] = "matrix";
static const char PyvkStructDemo_KEY_valueCount[] = "value_count";
static const char PyvkStructDemo_KEY_values[] = "values";
static const char PyvkStructDemo_KEY_child[] = "child";
static const char PyvkStructDemo_KEY_childrenCount[] = "children_count";
static const char PyvkStructDemo_KEY_children[] = "children";

typedef struct {
    PyObject_HEAD
    VkStructDemo data;
} PyvkStructDemo_Object;

static PyObject *
PyvkStructDemo_get__address(PyObject *self, void *Py_UNUSED(closure)) {
    return PyLong_FromVoidPtr(&((PyvkStructDemo_Object *)self)->data);
}

static PyObject *
PyvkStructDemo_get_pStr(PyObject *self, void *Py_UNUSED(closure)) {
    return Pyvk_Construct__PyBytes__char_p(((PyvkStructDemo_Object *)self)->data.pStr);
}

static PyObject *
PyvkStructDemo_get_str16(PyObject *self, void *Py_UNUSED(closure)) {
    return Pyvk_Construct__PyBytes__char_x16(((PyvkStructDemo_Object *)self)->data.str16);
}

static PyObject *
PyvkStructDemo_get_pNext(PyObject *self, void *Py_UNUSED(closure)) {
    return Pyvk_Construct__Pyvk_Struct__pNext(((PyvkStructDemo_Object *)self)->data.pNext);
}

static PyObject *
PyvkStructDemo_get_matrix(PyObject *self, void *Py_UNUSED(closure)) {
    return Pyvk_Construct__NPY_FLOAT_Array2D__float_x3_x4(((PyvkStructDemo_Object *)self)->data.matrix);
}

static PyObject *
PyvkStructDemo_get_valueCount(PyObject *self, void *Py_UNUSED(closure)) {
    return Pyvk_Construct__NPY_UINT32_Scalar__uint32(((PyvkStructDemo_Object *)self)->data.valueCount);
}

static PyObject *
PyvkStructDemo_get_values(PyObject *self, void *Py_UNUSED(closure)) {
    return Pyvk_Construct__NPY_UINT32_Array1D__uint32_p(((PyvkStructDemo_Object *)self)->data.values, ((PyvkStructDemo_Object *)self)->data.valueCount);
}

static PyObject *
PyvkStructDemo_get_child(PyObject *self, void *Py_UNUSED(closure)) {
    return Pyvk_Construct__PyvkPerformanceValueDataINTEL_Optional__VkPerformanceValueDataINTEL_p(((PyvkStructDemo_Object *)self)->data.child);
}

static PyObject *
PyvkStructDemo_get_childrenCount(PyObject *self, void *Py_UNUSED(closure)) {
    return Pyvk_Construct__NPY_UINT32_Scalar__uint32(((PyvkStructDemo_Object *)self)->data.childrenCount);
}

static PyObject *
PyvkStructDemo_get_children(PyObject *self, void *Py_UNUSED(closure)) {
    return Pyvk_Construct__PyvkPerformanceValueDataINTEL_tuple__VkPerformanceValueDataINTEL_p(((PyvkStructDemo_Object *)self)->data.children, ((PyvkStructDemo_Object *)self)->data.childrenCount);
}

static PyGetSetDef PyvkStructDemo_getset[] = {
    {
        .name = "_address",
        .get = PyvkStructDemo_get__address
    },
    {
        .name = PyvkStructDemo_KEY_pStr,
        .get = PyvkStructDemo_get_pStr
    },
    {
        .name = PyvkStructDemo_KEY_str16,
        .get = PyvkStructDemo_get_str16
    },
    {
        .name = PyvkStructDemo_KEY_pNext,
        .get = PyvkStructDemo_get_pNext
    },
    {
        .name = PyvkStructDemo_KEY_matrix,
        .get = PyvkStructDemo_get_matrix
    },
    {
        .name = PyvkStructDemo_KEY_valueCount,
        .get = PyvkStructDemo_get_valueCount
    },
    {
        .name = PyvkStructDemo_KEY_values,
        .get = PyvkStructDemo_get_values
    },
    {
        .name = PyvkStructDemo_KEY_child,
        .get = PyvkStructDemo_get_child
    },
    {
        .name = PyvkStructDemo_KEY_childrenCount,
        .get = PyvkStructDemo_get_childrenCount
    },
    {
        .name = PyvkStructDemo_KEY_children,
        .get = PyvkStructDemo_get_children
    },
    {NULL}
};

static PyObject *
PyvkStructDemo_new(PyTypeObject *cls, PyObject *args, PyObject *kwds) {
    static const char *kwlist[] = {
        PyvkStructDemo_KEY_pStr,
        PyvkStructDemo_KEY_str16,
        PyvkStructDemo_KEY_pNext,
        PyvkStructDemo_KEY_matrix,
        PyvkStructDemo_KEY_valueCount,
        PyvkStructDemo_KEY_values,
        PyvkStructDemo_KEY_child,
        PyvkStructDemo_KEY_childrenCount,
        PyvkStructDemo_KEY_children,
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
        arg_value32 ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_value32, Pyvk_Convert__ScalarLike__uint32(arg_value32, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.value32)) :
        arg_value64 ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_value64, Pyvk_Convert__ScalarLike__uint64(arg_value64, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.value64)) :
        arg_valueFloat ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_valueFloat, Pyvk_Convert__ScalarLike__float(arg_valueFloat, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.valueFloat)) :
        arg_valueBool ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_valueBool, Pyvk_Convert__ScalarLike__bool32(arg_valueBool, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.valueBool)) :
        arg_valueString ? (((PyvkPerformanceValueDataINTEL_Object *)self)->key = PyvkPerformanceValueDataINTEL_KEY_valueString, Pyvk_Convert__BytesLike__char_p(arg_valueString, &((PyvkPerformanceValueDataINTEL_Object *)self)->data.valueString)) :
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
        PyType_Ready(&Pyvk_Object_Type) < 0 || PyModule_AddObjectRef(module, "_Object", &Pyvk_Object_Type) < 0 ||
        PyType_Ready(&Pyvk_Enum_Type) < 0 || PyModule_AddObjectRef(module, "_Enum", &Pyvk_Enum_Type) < 0 ||
        PyType_Ready(&Pyvk_Enum64_Type) < 0 || PyModule_AddObjectRef(module, "_Enum64", &Pyvk_Enum64_Type) < 0 ||
        PyType_Ready(&Pyvk_Flag64_Type) < 0 || PyModule_AddObjectRef(module, "_Flag64", &Pyvk_Flag64_Type) < 0 ||
        PyType_Ready(&PyvkEnumDemo_Type) < 0 || PyType_Ready(&PyvkEnumDemo_Meta_Type) < 0 || PyModule_AddObjectRef(module, "EnumDemo", &PyvkEnumDemo_Meta_Object) < 0 ||
        PyType_Ready(&PyvkFlagDemo_Type) < 0 || PyType_Ready(&PyvkFlagDemo_Meta_Type) < 0 || PyModule_AddObjectRef(module, "FlagDemo", &PyvkFlagDemo_Meta_Object) < 0 ||
        PyType_Ready(&Pyvk_Union_Type) < 0 || PyModule_AddObjectRef(module, "_Union", &Pyvk_Union_Type) < 0 ||
        PyType_Ready(&PyvkPerformanceValueDataINTEL_Type) < 0 || PyModule_AddObjectRef(module, "PerformanceValueDataINTEL", &PyvkPerformanceValueDataINTEL_Type) < 0 ||
        PyType_Ready(&Pyvk_Struct_Type) < 0 || PyModule_AddObjectRef(module, "_Struct", &Pyvk_Struct_Type) < 0 ||
        0
    ) {
        Py_CLEAR(module);
        return NULL;
    }
    return module;
}
