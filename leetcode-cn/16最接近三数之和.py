#-*- coding:utf-8 -*-
#author: zsh
#modified by zsh at date
#version:
#history:
#relate on:
class Solution:
    # 排序后双指针法
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        mmin=0xfffffff
        residual=0xffffff
        for index in range(len(nums)):
            l,r,res=index+1,len(nums)-1,0xfffffff
            while l<r:
                threeSum=nums[l]+nums[r]+nums[index]
                if abs(threeSum-target)<abs(mmin-target):
                    mmin=threeSum
                elif threeSum<target:
                    l+=1
                elif threeSum>target:
                    r-=1
                else:
                    return target
        return mmin
