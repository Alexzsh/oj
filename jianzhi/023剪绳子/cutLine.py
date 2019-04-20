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

if __name__ == '__main__':
    g()
    
