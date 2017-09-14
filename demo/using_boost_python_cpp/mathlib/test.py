import mathlib
print dir(mathlib)
a = mathlib.MathLib.Arithmetic()
print a.add(1,2)

b = mathlib.MathLib.List1D()
print dir(b)
print b.zeros(10)
c = b.sort([i for i in range(1000,0,-1)])
print type(c)

y = [1,2,3]
z = [-1,1,1]
print b.dot(y,z)


m = mathlib.MathLib.Matrix.Matrix2D()
mat = m.createMatrix((2,2))
print mat