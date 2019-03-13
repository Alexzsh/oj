#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
//--------------------------

string str; 
int a[100010]={0},b[10000],j,k,l,n,m,t,flag;
char ch='A'; 
vector<int> res;
//--------------------------
int main() {
	while(cin>>n&&n!=0){
		k=0;
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++){
			if(b[i-1]>0)
				b[i]=b[i-1]+a[i];
			else
				b[i]=a[i];
			t=max(t,b[i]);		
		}
		cout<<t<<endl;
	}
return 0;
}
