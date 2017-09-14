import os,sys, time
# add the my_math.so library
# os.sys.path.insert(0, "/home/kushal/Documents/lectures/framework_design_with_python_cpp/demo/using_pyobjeccts_cpp/build/lib.linux-x86_64-2.7/")
os.sys.path.insert(0, os.path.join( os.getcwd() , "build/lib.linux-x86_64-2.7/"))

import my_math
print dir(my_math)

# ['__doc__', '__file__', '__name__', '__package__', 'arithmetic_add', 'arithmetic_divide', 'arithmetic_multiply', 'arithmetic_subtract', 'cos', 'fibo_n', 'sort_list']
# these are the possible methods
# 

# reimport it as a shorted name
import my_math as mm
a1 =  mm.arithmetic_add(1,2) 
a2 =  mm.arithmetic_subtract(10, 2)
a3 =  mm.arithmetic_multiply(100, 3)
a4 =  mm.arithmetic_divide(400, 4.23)
a5 =  mm.arithmetic_divide(1000,0)
a6 =  mm.cos(0, 0)

start = time.time()
a7 =  mm.fibo_n(1000)
end = time.time()


for i, each in enumerate([a1, a2, a3, a4, a5, a6, a7, ]):
	print "a%d : %s"%(i, each)

print "For fibonacci function , time taken is ", (end-start)

# replicating the python fibo
def fibo_n(n):
	# same implementation as in my_math.cc
	a = 0
	b = 1
	if ( n == 0):
		return a
	elif (n == 1):
		return b
	for i in range(n):
		b = b + a
		a = b - a
	return b

start = time.time()
py_a7 = fibo_n(1000)
end = time.time()
print "For python-fibonacci, time taken is " , (end - start)


print "lastly .. sorting a list"
sortedlist = mm.sort_list([1, 100, 330, 903, -1, 34 , 5])
print sortedlist




