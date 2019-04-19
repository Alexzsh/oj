#-*- coding:utf-8 -*-
#author: zsh
#modified by zsh at date
#version:
#history:
#relate on:
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if len(rotateArray)==0:
            return 0

        left = 0
        right = len(rotateArray)-1
        mid = left
        while rotateArray[left] >= rotateArray[right]:
            if right-left==1:
                mid=right
                break
            mid = left+int((right-left)/2)
            if rotateArray[mid] == rotateArray[left] and rotateArray[mid] == rotateArray[right]:
                return min(rotateArray[left:right+1])
            if rotateArray[mid]>=rotateArray[left] :
                left=mid
            else:
                right=mid

        return rotateArray[mid]
    def func(self,num):
        if not num:
            return 0
        
        left=0
        right=len(num)-1
        while num[left]>=num[right]:
            if right-left==1:
                return num[right]
            if num[left]==num[right] and num[left]==num[mid]:
                return min(num[left:right+1])
            mid=left+(right-left)>>1
            if num[left]>num[mid]:
                right=mid
            else:
                left=mid

solution = Solution()

print(solution.minNumberInRotateArray(
    [1,0,1,1,1]))
