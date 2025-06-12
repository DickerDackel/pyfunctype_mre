#include <Python.h>

#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"


static PyObject * pyfunctype_mre_zefunction(PyObject *self) {
    return PyUnicode_FromString("Howdydoodle");
}

static PyMethodDef pyfunctype_mre_methods[] = {
    {"zefunction", (PyCFunction)pyfunctype_mre_zefunction, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL},
};

static PyModuleDef pyfunctype_mre_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "pyfunctype_mre",
    .m_doc = "Lorem ipsum...",
    .m_size = -1,
    .m_methods = pyfunctype_mre_methods,
};


PyMODINIT_FUNC PyInit_pyfunctype_mre(void) {
    PyObject *m;

    m = PyModule_Create(&pyfunctype_mre_module);
    if (m == NULL)
	return NULL;

    /* Add a test object to the module */
    PyObject *random_string = PyUnicode_FromString("module level string variable");
    if (random_string != NULL) {
        PyModule_AddObject(m, "random_string", random_string);
    }
    else {
        Py_CLEAR(random_string);
    }

    /* Add a lookup dict to the module using above test object */
    PyObject *this_works = Py_BuildValue("{s: O}", "dolor", random_string);
    if (this_works != NULL) {
        PyModule_AddObject(m, "this_works", this_works);
    }
    else {
        Py_CLEAR(this_works);
    }

    /* Add another lookup dict to the module using the test function */
    PyObject *this_segfaults = Py_BuildValue("{s: O}", "sit", pyfunctype_mre_zefunction);
    if (this_segfaults != NULL) {
        PyModule_AddObject(m, "this_segfaults", this_segfaults);
    }
    else {
        Py_CLEAR(this_segfaults);
    }

    return m;
}
