#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------

string str; 
int a[100],k,l,n,m,t;
char c[5]={'S','H','C','D','J'}; 
//--------------------------
int main() {
	cin>>n;
	for(int i=1;i<=54;i++)
		cin>>a[i];
	while(n--)
	{
		int j=1;
		for(int i=1;i<=54;i++)
		{	
			int t=a[a[j]];
			a[a[j]]=j;
			j=a[a[j]];
		}
	}
	for(int i=0;i<54;i++)
		cout<<c[a[i]/10-1]<<a[i]%14<<" ";	

return 0;
}
