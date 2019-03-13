#-*- coding:utf-8 -*-
#author: zsh
#modified by zsh at date
#version:
#history:
#relate on:
# 注意是子串不是子序列
# i-j的结果是max(i-j+1,ans) 考虑j位置与不考虑的原结果
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i,ans=-1,0
        res={}
        for j in range(len(s)):
            if s[j] in res:
                i = max(res[s[j]],i)
            ans = max(ans,j-i)
            res[s[j]]=j
        return ans
