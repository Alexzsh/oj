def func3():
    n,m = map(int,input().split())
    li = list(map(int,input().split()))
    li.sort()
    summ=0
    i=0
    while m>0 and i<n:
        
        
        if max(li)==0:
            print(0)
        
        if li[i]!=summ:
            print(li[i]-summ)
            summ=li[i]
            m-=1    
            i+=1
        else:
            i+=1
            continue
def func2():
    m=input()
    li=list(map(int,input().split()))
    summ = 0
    temp=0
    for i in range(len(li)):
        temp+=abs(summ+li[i])
        summ+=li[i]
    print(temp)
def func1():
    m,n = map(int,input().split())
    i = m//(n+1)
    j = m%(n+1)
    if j!=0:
        i+=1
    print(n+i)
if __name__ == '__main__':
    func1()
