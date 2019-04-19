n,k=map(int,input().split())
ei=list(map(int,input().split()))
wi=list(map(int,input().split()))
resi=[(index+1,wi[index]+ei[index%n]) for index in range(n)]
# from functools import cmp_to_key
# def ff(x,y):
#     if x[1]!=y[1]:
#         return x[1]-y[1]
#     else:
#         return y[0]-x[0]
# sorted(resi,key=cmp_to_key(ff))
sorted(resi,key=lambda x: (x[1],x[0]))
print(list(reversed([i[0] for i in resi])))