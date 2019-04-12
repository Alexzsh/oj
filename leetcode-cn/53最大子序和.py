class Solution:
    # 注意初始化大小
    def maxSubArray(self, nums: List[int]) -> int:
        
        dp = mmax = -0xffffffff
        for i in range(len(nums)):
            dp = max(nums[i], dp+nums[i])
            mmax = max(dp, mmax)
        return mmax
