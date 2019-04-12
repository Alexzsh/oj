def func(A):
    # 双向求解可以解决负数相乘顺序以及子数组起始的问题
    B = A[::-1]
    for i in range(1, len(A)):
        A[i] *= A[i - 1] or 1
        B[i] *= B[i - 1] or 1
    return max(max(A), max(B))
if __name__ == '__main__':
    print(func([2, -3, -2, 4]))
