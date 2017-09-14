#include "iostream"
#include "vector"
#include "math.h"

using namespace std;

class MyClass{
public:
	void hello(){
		cout << "Hello ...! I am object of MyClass" << endl;
	}

	int add(int a, int b){
		int c = a +b;
		return c;
	}

	// new method of defining methods
	vector < int > create_n_array(int n);
};

vector < int > MyClass::create_n_array(int n){
	// define vector
	vector <int> v;
	for (int i=0; i<n;i++){
		v.push_back(i);
	}
	return v;
}


int main(int argc, char* argv[]){

	// create object of class
	MyClass m;
	m.hello();

	int c = m.add(3, 4);
	cout << "Value of c is " << c << endl; /// endl means "\n"

	vector < int > myvec = m.create_n_array(100);
	// print vector
	for(int i=0; i<myvec.size(); i++){
		cout << myvec[i] << " " ;
	}
	cout << endl;
}


/*
	to compile run command:
	g++ intro.cpp -o intro

	to execute run command
	./intro
 */
