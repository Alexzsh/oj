class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums)==0 or nums==None:
            return 0
        index=1
        cur=0
        for index in range(1,len(nums)):
            if nums[cur]!=nums[index]:
                cur+=1
                nums[cur]=nums[index]
        return cur+1
