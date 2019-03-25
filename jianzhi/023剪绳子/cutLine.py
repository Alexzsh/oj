#coding=utf-8
"""
@version=1.0
@author:zsh
@file:tianmao.py
@time:2019/3/19 21:51
"""

#交换str中两个字符的位置
def changeChara(str, first, second):
  if first == second:
    return str
  cur_first = str[first]
  cur_second = str[second]
  if first < second:
    str = str[:first] + cur_second + str[first+1:second] + cur_first + str[second+1:]
  else:
    str = str[:second] + cur_first + str[second+1:first] + cur_second + str[first+1:]
  return str



def recursive(str, x,res):
  # 当交换后达到源字符串长度时即返回
  if x == len(str):
    res.append(str)
    return
  for i in range(x, len(str)):
    # 递归遍历第i个字符，
    str = changeChara(str, i, x)
    recursive(str, x+1, res)
    # 恢复字符串原来的顺序，便于下次遍历
    str = changeChara(str, x, i)

def g():
    s = input()
    res_list = []
    recursive(s, 0, res_list)
    print('res\'s length is ',len(res_list),'\n', res_list)


def miss_nums(nums,n):
    '''
    :param nums 原有数组:
    :param n 表示的值:
    :return  需要插入的值的数量:
    '''
    # res为需要补充的数
    # i 是数组下标
    res,i =0,0
    # miss_num 是假设当前不能表示的最小的数
    miss_num = 1
    while miss_num<=n:
        # print(res,i,miss_num,nums[i])
        if miss_num>=nums[i]:
            # 如果miss_num >= nums[i] 则 可以将miss_nums 加上当前可以新用的nums[i] 表示miss+nums[i]为当前不能被表示的值
            miss_num+=nums[i]
            i+=1
        else:
            # miss在数组区间的断档处，则插入miss，迭代miss_nums为 miss_nums*=2的位置 因为至少可以表示2*miss_num-1的位置，最小不能被表示的是2*miss_num
            res+=1
            miss_num*=2
    return res

print(miss_nums([1,5,10],20))