def fast_exp(base, exponent):
    if ( exponent == 0 ): 
        return 1;
    half = fast_exp(base, exponent // 2)
    
    if ( exponent % 2 == 0 ):
        return half * half
    else:
        return base * half * half

def slow_exp(base, exponent):
    if exponent == 0:
        return 1
    
    res = base
    for i in range(exponent - 1):
        res *= base
    return res

print("fast:", fast_exp(2,2))
print("slow:", slow_exp(2,4))
