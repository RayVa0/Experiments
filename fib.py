

def fib(n):
    if n == 0: 
        return 0
    if n == 1:
        return 1

    a = 0
    b = 1
    c = 1

    for i in range(2,n):
        tempc = c
        c = c + b
        a = b
        b = tempc

    return c

print("Result:", fib(150))
    

