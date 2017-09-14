#include "iostream"
#include "math.h"
#include "vector"
#include "string"

// boost includes
#include <boost/python.hpp>
#include <boost/numpy.hpp>
namespace py = boost::python;
namespace np = boost::numpy;

namespace MathLib{
    class Arithmetic{
    public:
        int add(int a, int b){
            return a+b;
        }
        int subtract(int a, int b){
            return a-b;
        }
    };

    class List1D{
    public:
        py::list zeros(int n){
            py::list t;
            t.append(0);
            t*=n;
            return t;
        }
        py::list sort(py::list l){
            l.sort();
            return l;
        }
        py::list dot(py::list l1, py::list l2){
            py::list newlist;
            if(py::len(l1) != py::len(l2)){
                return newlist;
            }
            for(size_t i=0; i< py::len(l1); i++){
                newlist.append(l1[i]*l2[i]);
            }
            return newlist;
        }
    };
    
    namespace Matrix{
        class Matrix2D{
        public:
            py::list createMatrix(py::tuple shape){
                py::list mat;
                int rows, cols;
                rows = py::extract<int>(shape[0]);
                cols = py::extract<int>(shape[1]);
                for(int row=0; row<rows; row++){
                    py::list newmat;
                    for(int col=0; col<cols;col++){
                        newmat.append(NULL);
                    }
                    mat.append(newmat);
                }
                return mat;
            }
        };
    }
}

class mLib{};
class mMat{};


BOOST_PYTHON_MODULE(mathlib){
    using namespace boost::python;
    scope a = class_<mLib>("MathLib");
    class_<MathLib::Arithmetic>("Arithmetic")
        .def("add",&MathLib::Arithmetic::add)
        .def("subtract", &MathLib::Arithmetic::subtract);
    class_<MathLib::List1D>("List1D")
        .def("zeros", &MathLib::List1D::zeros)
        .def("sort", &MathLib::List1D::sort)
        .def("dot", &MathLib::List1D::dot);

    scope b = class_<mMat>("Matrix");
    class_<MathLib::Matrix::Matrix2D>("Matrix2D")
        .def("createMatrix", &MathLib::Matrix::Matrix2D::createMatrix);

    
}