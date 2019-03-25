def func(nums):
    '''
    [-1]
    '''
    res = -0xffffffff #设置最小值
    sumRes = 0
    for i in nums:
        sumRes += i
        res = max(res, sumRes)
        sumRes = max(0, sumRes)
    return res
if __name__ == '__main__':
    print(-0xfffffff)
            
