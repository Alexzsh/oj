#coding=utf-8
"""
@version=1.0
@author:zsh
@file:subMatrix.py
@time:2019/3/13 19:21
"""
n = int(input())
matrix = []
res = 1
for i in range(n):
    matrix.append(list(map(int,input())))
row = n
col = len(matrix[0])
if row == 1:
    print(max(matrix[0]))
else:
    for i in range(1,row):
        for j in range(1,col):
            if matrix[i][j]==1:
                dp_min = min(matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1])
                matrix[i][j]=dp_min+1
                res = max(res,matrix[i][j])
    print(res**2)