#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//--------------------------

#define MAX 100010
string str;
int i,j,le[MAX],right[MAX],sum,l,r; 
//--------------------------
int main() {
	 getline(cin,str);
	 int len = str.length();
	 for(i=0;i<len;i++){
	 	
	 	if(i>0)
	 		le[i]=str[i]=='P'?le[i-1]+1:le[i-1]; 
	 	else
	 		le[0]=str[0]=='P'?1:0; 
	 }
	 for(j=len-1;j>0;j--){
	 	if(str[j]=='T') r++;
	 	if(str[j]=='A') (sum+=le[j]*r)%=1000000007;
	 }
	 cout<<sum;

return 0;
}
