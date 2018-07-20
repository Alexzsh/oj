#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
//--------------------------
int res;
char ch[30],a[10],ans[10];
int visit[30];

//--------------------------
void dfs(int n){
	
	if(n==5){
		int temp = (a[0]-'@')-pow((a[1]-'@'),2)+pow(a[2]-'@',3)-pow(a[3]-'@',4)+pow(a[4]-'@',5); 
		if(temp==res&&strcmp(a,ans)>0){
			strcpy(ans,a);
		}
		return;
	}
	for(int i=0;i<strlen(ch);i++){
		if(!visit[ch[i]-'A']){
			a[n]=ch[i];
			visit[ch[i]-'A']=1;
			dfs(n+1);
			visit[ch[i]-'A']=0;
		}
}
				
}
int main(){
	while(cin>>res>>ch&&(res||strcmp(ch,"END"))){
		memset(visit,0,sizeof(visit));
       	memset(ans,'\0',sizeof(ans));
		memset(a,'\0',sizeof(a));
		if(strlen(ch)<5){
			cout<<"no solution\n";
			continue;
		}

	
		dfs(0);
		cout<<(strlen(ans)?ans:"no solution"); 
		cout<<"\n"; 
	}
return 0;
}
