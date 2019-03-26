def func(nums):
    from functools import cmp_to_key
    nums = map(str,nums)
    numss=sorted(nums,key=cmp_to_key(lambda x1,x2: int(x1+x2)-int(x2+x1)))
    print(''.join(numss))
if __name__ == '__main__':
    func([3,21,123])
