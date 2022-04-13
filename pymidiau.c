#include <Python.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *c_main (void *t);

static PyObject *method_midiau(PyObject *self, PyObject *args) {
    char *arg1, *arg2;
    int bytes_copied = -1;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "ss", &arg1, &arg2)) {
        return NULL;
    }

    printf("Hello %s %s\n", arg1,arg2);
    return PyLong_FromLong(bytes_copied);
}

static PyMethodDef FputsMethods[] = {
    {"midiau", method_midiau, METH_VARARGS, "Python interface for midiau C library function"},
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef midiaumodule = {
    PyModuleDef_HEAD_INIT,
    "midiau",
    "Python interface for the midiau C library function",
    -1,
    FputsMethods
};

PyMODINIT_FUNC PyInit_pymidiau(void) {
    pthread_t pid;
    pthread_create(&pid, NULL, c_main, NULL);
    return PyModule_Create(&midiaumodule);
}