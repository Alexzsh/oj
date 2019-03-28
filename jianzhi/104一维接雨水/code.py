def trap(A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        l, r = 0, n - 1

        ans = 0
        max_l = max_r = 0

        while l <= r:
            if A[l] <= A[r]:
                if A[l] > max_l:
                    max_l = A[l]
                else:
                    ans += max_l - A[l]

                l += 1
            else:
                if A[r] > max_r:
                    max_r = A[r]
                else:
                    ans += max_r - A[r]

                r -= 1

        return ans
def func(A):
    max_l = [0]*len(A)
    max_r = [0]*len(A)

    for i in range(1,len(A)):
        max_l[i] = max(max_l[i-1],A[i-1])
    for i in range(len(A)-2,-1,-1):
        max_r[i] = max(max_r[i+1],A[i+1])
    res = 0
    print(max_l,max_r)
    for i in range(0,len(max_l)):
        res += max(0,min(max_l[i],max_r[i])-A[i])
    return res
if __name__ == '__main__':
    A=[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(trap(A))
    print(func(A))
