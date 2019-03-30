#-*- coding:utf-8 -*-
#author: zsh
#modified by zsh at date
#version:
#history:
#relate on:
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def func(self,nums,l,r):
        if l>=r:
            return 
        mmax=0
        iindex =0
        for index,i in enumerate(nums):
            if i>mmax:
                mmax=i
                iindex=index
        root = TreeNode(mmax)
        
        root.left=self.constructMaximumBinaryTree(nums[l:iindex])
        root.right = self.constructMaximumBinaryTree(nums[iindex+1:r])
        return root
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
        res=self.func(nums,0,len(nums))
        return res
        
        
