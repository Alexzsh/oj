class Solution:
    # 双指针法得到当前最大值
    def sortedSquares(self, A: List[int]) -> List[int]:
        left = 0
        right = len(A)-1
        res = []
        while left < right:
            if abs(A[left]) > abs(A[right]):
                res.append(A[left]**2)
                left += 1
            elif abs(A[left]) < abs(A[right]):
                res.append(A[right]**2)
                right -= 1
            else:
                res.extend([A[right]**2, A[right]**2])
                left += 1
                right -= 1
        if left == right:
            res.append(A[right]**2 if A[right] <= 0 else A[left]**2)
        return res[::-1]
