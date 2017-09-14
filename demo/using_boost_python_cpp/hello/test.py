import hello
import time
print dir(hello)

print hello.greet()

a = hello.Math()
print a.add(1,2)

print a.getarray()

start = time.time()
b= a.sort([i for i in range(10000,0,-1)])
end = time.time()
# print b
print "exec c++", (end-start)


def bubblesort(l):
    for i in range(len(l)):
        for j in range(len(l)-1):
            if l[j] > l[j+1]:
                tmp = l[j+1]
                l[j+1] = l[j]
                l[j] = tmp
    return l
start = time.time()
# b = bubblesort([i for i in range(10000,0,-1)])
b = sorted([i for i in range(10000,0,-1)])
end = time.time()
# print b
print "exec py", (end -start)
