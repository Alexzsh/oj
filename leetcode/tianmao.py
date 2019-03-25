#字符串任意两个位置字符交换
def str_replace(str, x, y):
  if x == y:
    return str
  x_val = str[x:x+1]
  y_val = str[y:y+1]
  if x < y:
    str = str[0:x] + y_val + str[x+1:y] + x_val + str[y+1:len(str)]
  else:
    str = str[0:y] + x_val + str[y+1:x] + y_val + str[x+1:len(str)]
  return str



def recursive(str, x,res):
  if x == len(str):  # 当x为字符串的最大长度时返回当前字符交换的结果
    res.append(str)
    return
  for i in range(x, len(str)):
    # 递归遍历第i个字符，
    str = str_replace(str, i, x)  
    recursive(str, x+1, res)
    # 恢复字符串原来的顺序，便于下次遍历
    str = str_replace(str, x, i)  


s = 'abc'

res_list = []
recursive(s, 0, res_list)
print(len(res_list), res_list)
