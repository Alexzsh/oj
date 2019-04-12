class Solution:
    #分成左、中、右三段分别操作
    def maxDistToClosest(self, seats: List[int]) -> int:
        i,j=0,len(seats)-1
        while seats[i]==0:
            i+=1
        while seats[j]==0:
            j-=1
        side=(i,len(seats)-1-j)
        mmax=max(side)

        for index in range(len(seats)):
            if seats[index]==0:
                continue
            j=index
            dis = j-i-1
            mmax=max(mmax,dis //2 if dis&1==0 else dis//2+1)
            i=j
        return mmax