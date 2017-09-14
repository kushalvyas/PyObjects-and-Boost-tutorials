#include "iostream"
#include "math.h"
#include "limits"
#include "vector"

#ifndef PYTHON_H
    #include "Python.h"
#endif


using namespace std;



namespace math_framework{
    class Arithmetic{
    public:
        double add(double a, double b);
        double subtract(double a , double b);
        double multiply(double a, double b);
        double divide(double a, double b);
        double fibo_n(double n);
    };
    double Arithmetic::add(double a, double b){
        return (a+b);
    }
    double Arithmetic::subtract(double a, double b){
        return (a-b);
    }
    double Arithmetic::multiply(double a, double b){
        return (a*b);
    }
    double Arithmetic::divide(double a, double b){
        if ( b == 0){
            return numeric_limits<double>::quiet_NaN();
        }
        return (a/b);
    }

    double Arithmetic::fibo_n(double n){
        int a=0;
        int b=1;
        if (n ==0 ){return a;}
        else if ( n == 1){return b;}
        for(int i=0; i<n; i++){
            b = a + b;
            a = b - a;
        }
        return b;
    }

    class List1D{
    public:
        vector < double > inp;
        vector < double > sort_list( );
        void clear();
    };
    vector < double > List1D::sort_list(){
        for(size_t i=0; i< inp.size() ; i++){
            for(size_t j=0; j<inp.size() - 1; j++){
                if(inp.at(j) > inp.at(j+1)){
                    double tmp = inp.at(j+1);
                    inp.at(j+1) = inp.at(j);
                    inp.at(j) = tmp;
                }
            }
        }
        return inp;
    }
    void List1D::clear(){
        inp.clear();
    }

    class Trigo{
    public:
        #define PI 3.14159265
        double mcos(double x, int mode=0);
    };

    double Trigo::mcos(double x, int mode){
        // mode 0 means it is in radians
        if(mode == 1){
            // convert to radians
            x = x*PI/180;
        }
        return cos(x);
    }
    
};



