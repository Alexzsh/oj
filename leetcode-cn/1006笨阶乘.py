def func():
    pass


# def clumsy(N):
#     op = ['*', '/', '+', '-']
#     mul = [str(N)]
#     N-=1
#     count = 0
#     while N >= 1:
#         if count == 1:
#             t = mul.pop(-1)
#             res = int(int(t)/N)
#             mul.append(str(res))
#         else:
#             mul.extend([op[count],str(N)])
#         count += 1
#         count %= 4
#         N -= 1
#     res = ''.join(mul)
#     return int(eval(res))
def clumsy(N):
    switch={
        1:lambda x: 1 if x==1 else N+2,
        2:lambda x: 2 if x==2 else N+2,
        3:lambda x: 3 if x==6 else N-1,
        0:lambda x: 7 if x==4 else N+1
    }[N%4](N)
    return switch
if __name__ == '__main__':
    # a=eval('1+2')
    # print(a)
    print(clumsy(10))
