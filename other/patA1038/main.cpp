#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//--------------------------
#define MAX 100010
bool cmp(string s1,string s2){
	return s1+s2<s2+s1;
}
long long int n,m,a[MAX];
string str[10010]; 
//--------------------------
int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ans=1;
	for(int i=0;i<n;i++)
	{
		int j=upper_bound(a+i+1,a+n,(long long)(a[i]*m))-a;
		ans=max(ans,j-i);
	}
	cout<<ans<<endl;
return 0;
}
