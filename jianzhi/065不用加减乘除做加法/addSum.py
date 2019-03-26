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
if __name__ == '__main__':
    print(add(19,19))
    