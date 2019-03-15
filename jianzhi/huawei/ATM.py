#coding=utf-8
"""
@version=1.0
@author:zsh
@file:ATM.py
@time:2019/3/13 19:38
"""


import sys
def func():
    matrix = []
    s = sys.stdin.readline().strip("\n")
    while s!="":
        matrix.append(list(map(int,s.split())))
        s = sys.stdin.readline().strip("\n")
    row = len(matrix)
    col = len(matrix[0])
    monster=[]
    for i in matrix:
        for j in i:
            if j!=0:
                monster.append(j)
    monster.sort()
    direction = [(0,1),(0,-1),(1,0),(-1,0)]
    res,monster_level=[-1],1
    def judge(x,y):
    # judge = lambda x, y: x >= 0 and x < row and y >= 0 and y < col and (
    #         matrix[x][y] != 0 and (matrix[x][y] == 1 or matrix[x][y] >= monster.pop()))
        if x >= 0 and x < row and y >= 0 and y < col:
            if matrix[x][y] != 0:
                if matrix[x][y] == 1 or len(monster)>0 and matrix[x][y] == monster.pop(0):
                    return True
        return False
    def sub_func(x, y, res):
        if judge(x, y):
            matrix[x][y]=0
            res[0] += 1
            if len(monster) == 0:
                return
            for dirc in direction:
                sub_func(x + dirc[0], y + dirc[1], res)
    sub_func(0,0,res)
    return res[0] if len(monster)!=0 and res[0]!=-1 else -1



print(func())