class Solution:
    def minDistance(self, word1, word2):
        l1=len(word1)
        l2=len(word2)
        dp=[[i+j for i in range(l2+1)] for j in range(l1+1)]
        for i in range(1,l1+1):
            for j in range(1,l2+1):
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+int(not word1[i-1]==word2[j-1]))
        return dp[l1][l2]