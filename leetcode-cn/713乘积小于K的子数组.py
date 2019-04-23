class Solution:
    def numSubarrayProductLessThanK(self, nums, k):
        i = 0
        count = 0
        multi = 1
        j = 0
        while j < len(nums):
            multi *= nums[j]
            while multi >= k:
                multi //= nums[i]
                i += 1
            count += (j - i+1)
            j += 1
        return count
