#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
//--------------------------
#define max 2010
string str; 
int j,k,l,n,m,t,ans[max];
char ch='A'; 
double a[max],c[max],b[max],anss[max],e;
//--------------------------
int main() {
	cin>>n;
	while(n--)
	{
		cin>>k>>e;
		a[k]=e;
	}
	cin>>n;
	while(n--){
		cin>>k>>e;
		c[k]=e;
	} 
	for(int i=0;i<1001;i++)
		for(int j=0;j<1001;j++)
			b[i+j]+=a[i]*c[j];
	
	for(int i=2001;i>=0;i--){
		if(fabs(b[i])>=0.1)
		{
			ans[t]=i;
			anss[t++]=b[i];
		}
	}
	printf("%d",t);
	for(int i=0;i<t;i++)
		printf(" %d %.1f",ans[i],anss[i]);
	

return 0;
}
