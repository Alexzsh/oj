def cmp_to_key(mycmp):
     'Convert a cmp= function into a key= function'
     class K(object):
         def __init__(self, obj, *args):
             print('obj created with ',obj)
             self.obj = obj
         def __lt__(self, other):
             print('comparing less than ',self.obj)
             return mycmp(self.obj, other.obj) < 0
         def __gt__(self, other):
             print('comparing greter than ',self.obj)
             return mycmp(self.obj, other.obj) > 0
         def __eq__(self, other):
             print('comparing equal to ',self.obj)
             return mycmp(self.obj, other.obj) == 0
         def __le__(self, other):
             print('comparing less than equal ',self.obj)
             return mycmp(self.obj, other.obj) <= 0
         def __ge__(self, other):
             print('comparing greater than equal',self.obj)
             return mycmp(self.obj, other.obj) >= 0
         def __ne__(self, other):
             print('comparing not equal ',self.obj)
             return mycmp(self.obj, other.obj) != 0
     return K
def func(nums):
    # from functools import cmp_to_key
    
    nums = map(str,nums)
    numss=sorted(nums,key=cmp_to_key(ff))


    print(numss)
    print(''.join(numss))


def ff(x1, x2):
    return int(x1+x2)-int(x2+x1)
def gunc(nums):
    # from functools import cmp_to_key
    print(sorted(nums),sorted(nums,key=cmp_to_key(ff)))

if __name__ == '__main__':
    # func([3,21,123])
    d={1:'1',2:'2',1:'2'}
    a = {1, 2, 3, 4, 1, 2}
    b = (1,2,3,4,1,2)
    c = [1,2,3,4,1,2]
    print(a,b,c,d)
    # print(sorted([3,2,5,1]))
    # f=lambda x : True if x else False
    # print([f(i) for i in range(-3,3)])
    # gunc([3,21,123])
