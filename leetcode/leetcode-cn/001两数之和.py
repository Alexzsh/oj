#-*- coding:utf-8 -*-
#author: zsh
#modified by zsh at date
#version:
#history:
#relate on:
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        res = {}
        for index,i in enumerate(nums):
            if target-i not in res.keys():
                res[i]=index
            else:
                return [res[target-i],index]
        return []
