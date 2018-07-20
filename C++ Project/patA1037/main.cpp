#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//--------------------------

const int MAX=100010;
int n,m,a[MAX],b[MAX],pos,neg,j,sum,p;
string ch;
int findPos(int* arr,int begin,int n){
	for(int i=begin;i<n;i++)
		if(arr[i]!=i) return i;
	return 0;
}
//--------------------------
int main() {
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>p;
		a[p]=i;		
	}
	m=1;
	m=findPos(a,m,n);
		
	while(m){
		if(a[0]==0){
			swap(a[m],a[0]);
			sum++;			
		}
		while(a[0]!=0){
			swap(a[0],a[a[0]]);
			sum++;

		}
		m=findPos(a,m,n);
	}
	cout<<sum;
return 0;
}
