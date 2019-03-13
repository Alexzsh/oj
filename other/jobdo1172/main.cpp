#include<iostream>
#include<cstdio>
#include<queue> 
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAX 1010
using namespace std;
int a[MAX][MAX],b[MAX][MAX];
string foo(){
		return "ewe";
};
void bar(const string&s){
	cout<<s;
	return;
}
int main(){
	
	// 那么下面的表达式将是非法的：
//	bar(foo());
//	bar("hello world");
	int n,x;
	cin>>x;
	int res=0;
	while(x){
		x=x&(x-1);
		res++;
	} 
	cout<<res;
	
//	
//	int p,t,g1,g2,g3,gj;
//	while(cin>>p>>t>>g1>>g2>>g3>>gj){
//	
//		int ming=min(g1,g2),maxg=max(g1,g2),mmax=max(g3,maxg);
//		
//		if(abs(g1-g2)<=t) printf("%.1f",double((g1+g2)/2));
//		else{
//			if(g3<=ming) printf("%.1f",double(mmax));
//			else if(g3<=maxg){
//				if(g3>(g1+g2)/2)  printf("%.1f",double((g3+maxg)/2));
//				else  printf("%.1f",double((g3+ming)/2));
//			}
//			else  printf("%.1f\n",double(gj));
//		}
//	}	
	

}

