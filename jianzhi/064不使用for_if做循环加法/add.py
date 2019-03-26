res=1
def func(n):
    global res
    res *= n
    return n>1 and func(n-1)

if __name__ == '__main__':
    func(5)
    print(res)
    
