#-*- coding:utf-8 -*-
#author: zsh
#modified by zsh at date
#version:
#history:
#relate on:

# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    # 返回ListNode
    def func(self,pHead):
        if pHead.next:
            return self.recur(None,pHead)

    def recur(self,pHead,pNext):
        #递归版
        nNext=pNext.next
        if not nNext:
            pNext.next=pHead
            return pNext
        else:
            pNext.next=pHead
            pHead=pNext
            pNext=nNext
            return self.recur(pHead,pNext)
    def ReverseList(self, pHead):
        # write code here
        #非递归版
        pCur = pHead
        pPre = None
        pRes = None
        if pHead==None or pHead.next==None :
            return pHead
        while pCur!=None:
            pNext = pCur.next
            if pNext!=None:
                pRes=pNext
            pCur.next=pPre
            pPre = pCur
            pCur = pNext
        return pRes

if __name__ == '__main__':
    li=[ListNode(i) for i in range(10)]
    for i in range(9):
        li[i].next=li[i+1]
    node=Solution().func(li[0])
    while node:
        print(node.val)
        node=node.next
        
    
