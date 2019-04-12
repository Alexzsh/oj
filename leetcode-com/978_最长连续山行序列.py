

def func(nums):
    res = 1
    i=0
    while i<len(nums)-1:
        length = 1

        while i<len(nums)-1 and ((not i & 1 and nums[i] < nums[i+1]) or (i & 1 and nums[i] > nums[i+1])):
            length+=1
            i+=1
        if length==1:
            i+=1
        res=max(res,length)
    return res
        # if check(i,nums):
        #     length+=check(i+1,nums)+check(i-1,nums) 
        #     res=max(res,length)
    return res
def solution(nums):
    # 注意相等的子数组没有起伏不算
    l = len(nums)
    dp_great = [1]*l
    dp_less = [1]*l
    for i in range(l-2,-1,-1):
        if nums[i]>nums[i+1]:
            dp_great[i]=dp_less[i+1]+1
        elif nums[i] < nums[i+1]:
            dp_less[i]=dp_great[i+1]+1
    res=0
    for i in range(l):
        res = max(res,dp_great[i],dp_less[i])
    return res

def gunc(nums):
    if len(nums)==1 or ():
        return 1
    li=[1 if nums[i]>nums[i-1] else 0 if nums[i]<nums[i-1] else -1 for i in range(1,len(nums))]
    res=[0]*len(nums)
    res[0]=1
    res[1]=2
    res_max=2
    for i in range(1,len(li)):
        if li[i]==-1:
            res[i+1]=1
        elif li[i]!=li[i-1]:
            res[i+1]=res[i]+1
        else:
            res[i+1]=2
        res_max = max(res_max, res[i+1])
    return res_max
if __name__ == '__main__':
    # print(gunc([0, 8, 45, 88, 48, 68, 28, 55, 17, 24]))
    print(int(a)*int(b))
