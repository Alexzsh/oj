def add(num1,num2):
    res=0
    carry=0
    while True:
        res=num1^num2
        carry=(num1&num2)<<1
        num1=res
        num2=carry
        if num2==0:
            break
    return res
def g(num1):
    return num1 if num1 <= 0x7FFFFFFF else ~(num1 ^ 0xFFFFFFFF)
if __name__ == '__main__':
    print(g(0xffffffff))
    print(~0)
    
