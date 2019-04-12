def func(A):
    #双指针法
    left,right=0,len(A)-1
    while left<right:
        while left<right and A[left] & 1 == 0:
            left+=1
        while left <right and A[right]&1 !=0:
            right-=1
        if left<right:
            A[left],A[right]=A[right],A[left]
        left+=1
        right-=1
    return A
if __name__ == '__main__':
    print(func([1,2]))
    
