def func(x,n):
    if x==0:
        return "0"
    flag = 1 if x<0 else 0
    x=x* (-1 if flag==1 else 1)
    res=[]
    while x!=0:
        res.append(str(x%n))
        x//=n
    if flag==1:
        res.append('-')
    res.reverse()
    return ''.join(res)
if __name__ == '__main__':
    print(func(-7,7))
