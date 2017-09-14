"""
Basic python object oriented stuff

# comment

"""

# first start with normal python
# variable declaration
a = 1
b = 10.005 # floating 
c = "this is a string"
print "Value of a is : ", a
print "Value of b is : ", b
print "Value of c is : ", c

# or
print "a : {0} \nb : {1} \nc: {2}".format(a, b, c)

my_list = [] # empty list (closest interpretation of array)
my_list.append(1) # appends 1 to the list
print my_list

# loops
# FOR LOOP
# range(start: bydefault=0 , stop : need to specify, increment/decrement : by default=1)
my_list = [] #re-initialize the list
for i in range(0, 100, 1): 
	my_list.append(i)
print my_list

# defining a function
def myfunction(input_arg1, input_arg2):
	# lets do dot product
	if len(input_arg1) != len(input_arg2):
		print "DOT product is not possible on inputs of unequal lengths"
		return None

	newlist = []
	for i in range(len(input_arg1)):
		newlist.append(input_arg1[i]*input_arg2[i])

	return newlist

def myfunction_advanced(ip1, ip2):
	assert len(ip1) == len(ip2) , "DOT product is not possible on inputs of unequal lengths"
	return [a*b for(a,b) in zip(ip1, ip2)]


# one way to define lists
inp_list1 = [1, 2, 3]
# another way to define list
inp_list2 = []
inp_list2.append(-1)
inp_list2.append(0)
inp_list2.append(1)

dot1 = myfunction(inp_list1, inp_list2)
print "Dot product1 is " , dot1


# little advanced and cool initialization
inp_list1 = [ i for i in range(1,4)]
inp_list2 = [i for i in range(-1,2)]
dot2 = myfunction_advanced(inp_list1, inp_list2)
print "Dot product2 is " , dot2


# object oriented python

# define a class
class MyClass:
	def __init__(self, args=None):
		print "This is the constructor"
		print "Arguments are None by default, unless passed"

	def method1(self, args=None):
		print "Method1 is called"
		if args is None:
			print "Arguments are None by default, unless passed"
		else:
			print "Arguments are :"

	def method2(self, arg1, arg2, arg3, arg4):
		print "Method2 is called"
		if any([arg1, arg2, arg3, arg4]) is None:
			print "Arguments are None by default, unless passed"
		else:
			print "Arguments are :"
			print arg1
			print arg2
			print arg3
			print arg4

# declaring object of class
my_class_object = MyClass()
my_class_object.method1()


s1 = "Yo. This is a string argument"
s2 = "Another string argument"
a1 = 1
a2 = 100.002
my_class_object.method1(args=s1)
my_class_object.method2(s1,s2,a1,a2 )


