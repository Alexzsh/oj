#include<iostream>
using namespace std;
int dp[30][50000];
int n,m,z;
int pri[30],cj[30];
int main(){
    cin>>n>>m;
    for(int i = 1;i<=m;i++)
    {
        cin>>pri[i]>>cj[i];
        cj[i]*=pri[i];
    }
    for(int i = 1;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=dp[i-1][j];
        for(int j=pri[i];j<=n;j++)
        {

            dp[i][j]=max(dp[i][j],dp[i-1][j-pri[i]]+cj[i]);
        }
    }
    cout<<dp[m][n];
}
