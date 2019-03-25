def func(li):
    li.append(li[0])
    n = len(li)
    res = [1 for i in range(n)]
    for i in range(1, n):
        if li[i-1] < li[i]:
            res[i] = res[i-1] + 1
    res[-1]=max(res[0],res[-1])
    res[0]=res[-1]

    for i in range(n-1, 0, -1):
        if li[i-1] > li[i]:
            res[i-1] = max(res[i-1], res[i]+1)
    res[-1]=min(res[0],res[-1])
    res[0]=res[-1]
    return sum(res[:-1])
n = int(input())
for i in range(n):
    m = input()
    li = list(map(int,input().split()))
    print(func(li))
