#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------

string str; 
int a[100010]={0},j,k,l,n,m,t;
char ch='A'; 

//--------------------------
int main() {
	
	
		scanf("%d",&n);
		m=n;
		
		memset(a,0,sizeof(a));
		l=0,t=0,j=0;
		bool flag=false;
		while(n--){
			scanf("%d",&a[j++]);
		}
		int cur=0,sum=a[0],s=0,e=0;
		for(int i=0;i<m;i++)
		{
			if(a[i]>=0) flag=true;
			if(cur<0){
				s=i;
				e=i;
				cur=a[i];
			}
			else{
				cur+=a[i];
				e=i;
			}
			if(cur>sum)
			{
				sum=cur;
				l=s;
				t=e;
			}
		}
		if(!flag) printf("0 %d %d\n",a[0],a[m-1]); 
		else printf("%d %d %d\n",sum,a[l],a[t]); 
	
	 

return 0;
}
