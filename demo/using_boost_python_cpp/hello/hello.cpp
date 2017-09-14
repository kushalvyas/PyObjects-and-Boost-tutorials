#include "iostream"
#include "string"
#include "vector"

#include <boost/python.hpp>
using namespace std;

char const* greet(){
    return "Hello World";
}


template <class T>
boost::python::list toPythonList(std::vector<T> vector) {
	typename std::vector<T>::iterator iter;
	boost::python::list list;
	for (iter = vector.begin(); iter != vector.end(); ++iter) {
		list.append(*iter);
	}
	return list;
}

class Math{
public:
    int add(int a, int b){
        return (a+b);
    }

    int subtract(int a, int b){
        return (a-b);
    }

    boost::python::list getarray(){
        vector < int > v;
        for(int i=0;i<100;i++){
            v.push_back(i);
        }
        boost::python::list mylist = toPythonList(v);
        return mylist;
    }

    boost::python::list sort(boost::python::list l){
        l.sort();
        return l;
    }
    
};

using namespace boost::python;

BOOST_PYTHON_MODULE(hello){
    def("greet", greet);
    class_<Math>("Math")
        .def("add", &Math::add)
        .def("subtract",&Math::subtract)
        .def("getarray", &Math::getarray)
        .def("sort", &Math::sort);
}