#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>


using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        // return 0 paths if grid is empty
        if(obstacleGrid.empty()) return 0;
        
        int row_size = obstacleGrid.size();
        int col_size = obstacleGrid[0].size();
        // use an array initalized to 0 to track the number of paths for each row
        int dp[col_size];
        memset(dp,0,sizeof(dp));
        int row = 0;
        int prev = 1;
        
        while(row < row_size) {
            int col = 0;
            while (col < col_size) {
                
                // there is an obstacle (1)
                if(obstacleGrid[row][col] == 1) {
                    dp[col] = 0;
                    prev = 0;
                }
                else {
                    prev += dp[col];
                    dp[col] = prev;
                }
                col++;
            }
            prev = 0;
            row++;
        }
        
        return dp[col_size-1];
    }

int n,m;
string s,ss;
int main(){
    cin>>n>>m;
    vector<vector<int>> vec(n,vector<int>(m,0));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>vec[i][j];
    cout<<uniquePathsWithObstacles(vec);
}
