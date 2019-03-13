#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
//--------------------------
#define maxc 210
#define maxn 10010
string str; 
int a[1000]={0},j,k,l,n,m,t,B[maxc],A[maxn],dp[maxn][maxn],ans=1;
char ch='A'; 
//--------------------------
int main() {
	getline(cin,str);
	for(int i=0;i<str.length();i++)
	{
		dp[i][i]=1;
		if(i<str.length()-1)
			if(str[i]==str[i+1]){
				dp[i][i+1]=1;
				ans=2;	
			} 
	}
	for(int len=3;len<=str.length();len++){
		for(int i=0;i+len-1<str.length();i++){
			j=i+len-1;
			if(str[i]==str[j]&&dp[i+1][j-1]==1)
			{
				dp[i][j]=1;	
				ans=len;
			}
			 
		} 
	} 
	cout<<ans<<endl;

return 0;
}
