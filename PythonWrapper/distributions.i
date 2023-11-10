%module distributions

%typemap(out) float* %{
    int len = (int) $1[0];
    $result = PyList_New(len);
    for (int i = 0; i < len; i++) {
        PyList_SetItem($result, i, PyFloat_FromDouble($1[i+1]));
    }
%}

%typemap(out) int* %{
    int len = $1[0];
    $result = PyList_New(len);
    for (int i = 0; i < len; i++) {
        PyList_SetItem($result, i, PyInt_FromLong($1[i+1]));
    }
%}

%{
#include "distributions.h"
%}

%include "distributions.h"