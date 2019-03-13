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
int pre(int n){
	int res=1;
	for(int i=2;i<=n;i++)
		res*=i;
	return res;
}
int main() {
	printf("n e\n");
	printf("- -----------\n");
	printf("%d %d\n",0,1);
	printf("%d %d\n",1,2);
	printf("%d %.1f\n",2,2.5);
	double sum=2.5,res=0.0;
	for(int i=3;i<10;i++){
		res=(1.0/pre(i));
		sum+=res;
		printf("%d %.9f",i,sum);
		if(i!=9) printf("\n");
		
	}

return 0;
}
