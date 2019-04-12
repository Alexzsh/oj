def solution(nums):
    # 注意相等的子数组没有起伏不算
    l = len(nums)
    dp_great = [1]*l
    dp_less = [1]*l
    for i in range(l-2, -1, -1):
        if nums[i] > nums[i+1]:
            dp_great[i] = dp_less[i+1]+1
        elif nums[i] < nums[i+1]:
            dp_less[i] = dp_great[i+1]+1
    res = 0
    for i in range(l):
        res = max(res, dp_great[i], dp_less[i])
    return res
