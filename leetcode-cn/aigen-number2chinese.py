import re
from collections import defaultdict

zero_len = re.compile('零{2,10}')
chinese_num = ['零', '一', '二', '三', '四', '五', '六', '七', '八', '九']
unit = ['零', '十', '百', '千']

pos_dict=defaultdict(list)
pos_dict={1:[0,1],3:[0,2],5:[0,3]}


def format(i):
    """main function
    
    Arguments:
        i {string} -- string num
    
    Returns:
        string -- the chinese format string  
    """
    if len(i)>8:
        i = tran2Chinese(i[0:-8])+'亿'+tran2Chinese(i[0:-4])+'万'+tran2Chinese(i[-4:])
    elif len(i) > 4:
        i = tran2Chinese(i[0:-4])+'万'+tran2Chinese(i[-4:])
    else:
        i = tran2Chinese(i[-4:])
    return i
def insertUnits(s,pos,l):
    """add zero to list after tran2Chinese
    
    Arguments:
        s {list} -- string list
        pos {int} -- position
        l {int} -- string length
    """
    if len(s)>=l:
        s.insert(pos, unit[pos_dict[pos][int(not s[pos] == chinese_num[0])]])
def tran2Chinese(s):
    """transform to chinese
    will add another zero to format multi-zeros
    
    Returns:
        string -- string need to transform
    """
    s = list(reversed(s))
    for i in s:
        s[(s.index(i))] = chinese_num[int(i)]
    insertUnits(s,1,2)
    insertUnits(s,3,4)
    insertUnits(s,5,6)
    s = deleteMulZero(s)
    return s


def deleteMulZero(s):
    """delete multi zeros
    
    Arguments:
        s {string} -- string need to delete
    
    Returns:
        string -- string deleted multi zeros
    """
    s = zero_len.sub('零', ''.join(s))
    s = reversed(list(s)[1:] if len(s)>1 and  s[0]=='零' else s)
    return ''.join(s)

if __name__ == '__main__':
    # num=input()
    num='0'
    print(format(num))

