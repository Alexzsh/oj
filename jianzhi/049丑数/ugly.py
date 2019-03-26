def func(index):
    if index == 0:
            return 0
    mul2,mul3,mul5=0,0,0
    res=[1]
    while len(res)<index:
        min_res = min(2*res[mul2], 3*res[mul3], 5*res[mul5])
        res.append(min_res)
        while res[-1] >= 2*res[mul2]:
            mul2+=1
        while res[-1] >= 3*res[mul3]:
            mul3+=1
        while res[-1] >= 5*res[mul5]:
            mul5+=1
    return res[index-1]
if __name__ == '__main__':
    print(func(4))
            
