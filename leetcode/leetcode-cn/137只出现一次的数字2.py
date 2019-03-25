class Solution:
    def singleNumber(self, nums) :
        a,b=0,0
        for i in nums:
            a = (a^i)&~b
            b = (b^i)&~a
        print(a)
if __name__ == '__main__':
    Solution().singleNumber([0,1,0,1,98,0,1,99,98,98])
    
