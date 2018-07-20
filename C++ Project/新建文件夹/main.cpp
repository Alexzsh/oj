#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
//--------------------------

string str; 
string str1,str2,c,d;
int a[100010]={0},dp[100010],j,k,l,n,m,t;
char ch='A'; 
//--------------------------
bool judge(int n){
	if(n>=0&&n<=255) return 1;
	else return 0;
}
int main() {
	while(scanf("%d",&n)&&n!=0){
		t=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]>=0) t=1;
		}
		if(t==0){
			printf("0 %d %d\n",a[0],a[n-1]);
			continue;
		}
		int start,k=0,end=0,temp=0,max=0;
		for(int i=0;i<n;i++)
		{
			temp+=a[i];
			if(temp>=max)
			{
				max=temp;start=k;end=i;
			}
			if(temp<0)
			{
				temp=0;k=i+1;
			}
		}
		printf("%d %d %d\n",max,a[start],a[end]);
	}

return 0;
}
