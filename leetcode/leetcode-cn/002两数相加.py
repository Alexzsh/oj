#-*- coding:utf-8 -*-
#author: zsh
#modified by zsh at date
#version:
#history:
#relate on:
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# 注意进位以及补位
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        res = 0
        flag = 0
        ress=[None]
        resss=ress[0]
        while l1!=None or l2!=None:
            if l1==None and l2!=None:
                l1=ListNode(0)
            if l1!=None and l2==None:
                l2=ListNode(0)
            res = (l1.val+l2.val+flag)%10
            l1.val = res
            flag = (l1.val+l2.val+flag)//10
            ress[0]=l1
            l1=l1.next
            l2=l2.next
        if flag!=0:
            ress[0].next = ListNode(flag)
        return resss
