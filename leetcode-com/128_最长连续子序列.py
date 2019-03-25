def func(nums):
    # nums=list(set(nums))
    res=0
    for i in nums:
        print(nums)
        count=1
        nums.remove(i)
        left = i-1
        while left in nums:
            count+=1
            nums.remove(left)
            left-=1
        right = i+1
        while right in nums:
            count+=1
            nums.remove(right)
            right+=1
        res=max(res,count)
    return res
if __name__ == '__main__':
    print(func([-7, 2, -3, 8, 9, 0, 8, 4, -5, 8, -5, -5, 1, 6, 4]))
