#ifndef PYTHON_H
    #define PYTHON_H
    #include "Python.h"
#endif
#include "math_framework.cpp"
#include "ctime"

using namespace math_framework;

Arithmetic ar;
List1D l1d;
Trigo trig;

static PyObject* my_math_arithmetic_add(PyObject* self, PyObject* args);

static PyObject* my_math_arithmetic_subtract(PyObject* self, PyObject* args);

static PyObject* my_math_arithmetic_multiply(PyObject* self, PyObject* args);

static PyObject* my_math_arithmetic_divide(PyObject* self, PyObject* args);

static PyObject* my_math_sort_list(PyObject* self, PyObject* args);

static PyObject* my_math_cos(PyObject* self, PyObject* args);

static PyObject* my_math_fibo(PyObject* self, PyObject* args);

static PyMethodDef build_methods[] = {
    {
        "arithmetic_add", my_math_arithmetic_add, METH_VARARGS, "arithmetic add method"
    },
    {
        "arithmetic_subtract", my_math_arithmetic_subtract, METH_VARARGS, "arithmetic subtract"
    },
    {
        "arithmetic_multiply", my_math_arithmetic_multiply, METH_VARARGS, "arithmetic multiply"
    },
    {
        "arithmetic_divide", my_math_arithmetic_divide, METH_VARARGS, "arithmetic divide"
    },
    {
        "sort_list", my_math_sort_list, METH_VARARGS, "sortlist"
    },
    {
        "cos", my_math_cos, METH_VARARGS, "cos theta"
    },
    {
        "fibo_n", my_math_fibo, METH_VARARGS, "fibonacci upto n"
    },
    {   
        NULL , NULL, 0, NULL
    }
};


PyMODINIT_FUNC initmy_math(void){
    (void) Py_InitModule("my_math", build_methods);
}

static PyObject* my_math_arithmetic_add(PyObject* self, PyObject* args){
    double a=0, b=0;
    if(!PyArg_ParseTuple(args, "dd", &a, &b)){
        return NULL;
    }
    double answer = ar.add(a, b);
    return Py_BuildValue("d", answer); 
}

static PyObject* my_math_arithmetic_subtract(PyObject* self, PyObject* args){
    double a=0, b=0;
    if(!PyArg_ParseTuple(args, "dd", &a, &b)){
        return NULL;
    }
    double answer = ar.subtract(a, b);
    return Py_BuildValue("d", answer); 
}
static PyObject* my_math_arithmetic_multiply(PyObject* self, PyObject* args){
    double a=0, b=0;
    if(!PyArg_ParseTuple(args, "dd", &a, &b)){
        return NULL;
    }
    double answer = ar.multiply(a, b);
    return Py_BuildValue("d", answer); 
}

static PyObject* my_math_arithmetic_divide(PyObject* self, PyObject* args){
    double a=0, b=0;
    if(!PyArg_ParseTuple(args, "dd", &a, &b)){
        return NULL;
    }
    double answer = ar.divide(a, b);
    return Py_BuildValue("d", answer); 
}


// fibo

static PyObject* my_math_fibo(PyObject* self, PyObject* args){
    double n=0;
    if(!PyArg_ParseTuple(args, "d", &n)){
        return NULL;
    }
    double answer = ar.fibo_n(n);
    return Py_BuildValue("d", answer); 
}



// 
//  create sort_list methods
// 
//  



static PyObject* my_math_sort_list(PyObject* self, PyObject* args){
    
    vector < vector < double> > data;
    if(PyTuple_Check(args)){
        // std::cout << "ARgs size :" << PyTuple_Size(args) << endl;
        int start_s = clock();
        for(Py_ssize_t i=0; i<PyTuple_Size(args); i++){
            // (sort every list)
            PyObject* element_list = PyTuple_GetItem(args, i);
            // std::cout << "ELement " << i << " size is : " << PyList_Size(element_list) << endl;
            
            for(Py_ssize_t j=0; j<PyList_Size(element_list); j++){
                PyObject* value = PyList_GetItem(element_list, j);
                l1d.inp.push_back(PyFloat_AsDouble(value));
            }
            
            data.push_back(l1d.sort_list()); // return sorted list
            l1d.clear(); // empties the input list
        }
        int stop_s = clock();
        std::cout << "C++ Sort " << (stop_s-start_s)/(double(2.8)*1000000000) << endl;


        /*
        *   returning singular lists
        PyObject *retr = PyList_New((size_t)data.at(0).size());
        for(size_t i=0; i < data.at(0).size(); i++){
            PyList_SET_ITEM(retr, i, PyFloat_FromDouble(data.at(0).at(i)));
        }

        PyObject* retr2 = PyList_New((size_t)data.at(1).size());
        for(size_t i=0; i<data.at(1).size(); i++){
            PyList_SET_ITEM(retr2, i, PyFloat_FromDouble(data.at(1).at(i)));
        }
        */
        PyObject* retr_list = PyList_New((size_t)data.size());
        for(size_t i=0; i<data.size(); i++){
            PyObject* tmplist = PyList_New((size_t)data.at(i).size());
            vector < double> tmpvec = data.at(i);
            for(size_t j=0; j<data.at(i).size(); j++){
                PyList_SET_ITEM(tmplist, j, PyFloat_FromDouble(tmpvec.at(j)));
            }
            PyList_SET_ITEM(retr_list, i, tmplist);
        }
        // PyList_SET_ITEM(retr_list, 0, retr);
        // PyList_SET_ITEM(retr_list, 1, retr2);
        return retr_list;

    }

    Py_RETURN_NONE;
}


static PyObject* my_math_cos(PyObject* self, PyObject* args){
    double x=NULL;
    int mode = NULL;
    if(!PyArg_ParseTuple(args, "di", &x, &mode)){
        return NULL;
    }
    cout << "x is " << x << " and mode is " << mode << endl;
    if(mode != NULL){
        return Py_BuildValue("d", trig.mcos(x, mode));
    }
    return Py_BuildValue("d", trig.mcos(x));
}

int main(int argc, char* argv[]){
    Py_SetProgramName(argv[0]);
    Py_Initialize(); // initializes the interpretor
    initmy_math(); // initializes my modules
}

