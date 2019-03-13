#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------

string str; 
int a[1000]={0},j,k,l,n,m,t;
char ch='A'; 
//--------------------------
void printP(int n){
	for(int i=0;i<n-1;i++)
		cout<<a[i]<<" ";
	cout<<a[n-1]<<"\n";
}
int main() {
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
			a[i]=i+1;
		int b=1;
		do{
			if(b==m)
				break;
			b++;
		}while(next_permutation(a,a+n));
		printP(n);
	}

return 0;
}
