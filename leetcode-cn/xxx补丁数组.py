def miss_nums(nums, n):
    '''
    :param nums 原有数组:
    :param n 表示的值:
    :return  需要插入的值的数量:
    '''
    # res为需要补充的数
    # i 是数组下标
    res, i = 0, 0
    # miss_num 是假设当前不能表示的最小的数
    miss_num = 1
    while miss_num <= n:
        # print(res,i,miss_num,nums[i])
        if miss_num >= nums[i]:
            # 如果miss_num >= nums[i] 则 可以将miss_nums 加上当前可以新用的nums[i] 表示miss+nums[i]为当前不能被表示的值
            miss_num += nums[i]
            i += 1
        else:
            # miss在数组区间的断档处，则插入miss，迭代miss_nums为 miss_nums*=2的位置 因为至少可以表示2*miss_num-1的位置，最小不能被表示的是2*miss_num
            res += 1
            miss_num *= 2
    return res


print(miss_nums([1, 5, 10], 20))
