#coding=utf-8
"""
@version=1.0
@author:zsh
@file:first.py
@time:2019/3/13 18:59
"""
def func():
    ip1,ip2,mask = input().split()
    ip1_list = list(map(int,ip1.split('.')))
    ip2_list = list(map(int,ip2.split('.')))
    mask_list = list(map(int,mask.split('.')))
    res=[]
    flag = True
    for i in range(len(mask_list)):
        item1 = ip1_list[i] & mask_list[i]
        item2 =ip2_list[i]&mask_list[i]
        res.append(item1)
        if item1!=item2:
            flag=False
    res_ip = '.'.join([str(j) for j in res])
    print('1' if flag else '0',res_ip)

func()