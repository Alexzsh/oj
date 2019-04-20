#-*- coding:utf-8 -*-
#author: zsh
#modified by zsh at date
#version:
#history:
#relate on:
class Solution:
    def countBits(self,num):
        res=[0]*(num+1)
        for i in range(1,num+1):
            res[i]=res[i&(i-1)]+1
        return res
