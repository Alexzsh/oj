#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------

string str; 
int j,k,n,m,t,sum;
double l,a[1010];
char ch='A'; 
//--------------------------
int main() {
	cin>>n;
	memset(a,0,sizeof(a));
	while(n--){
		cin>>k>>l;
		a[k]+=l;
		if(k>m) m=k;
	}
	cin>>n;

	while(n--){
		cin>>k>>l;
		a[k]+=l;
		if(k>m) m=k;
	}
	for(int i=1001;i>=0;i--){
		if(a[i]!=0)
			sum++;
	}
	printf("%d",sum);
	if(sum!=0)
		for(int i=1001;i>=0;i--){
			if(a[i]!=0){
				printf(" %d %.1f",i,a[i]);
			}
		} 
	printf("\n");
return 0;
}
