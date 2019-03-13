#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
//--------------------------

#define MAX 100
int n,visited[MAX],a[MAX],p;
bool prime[50];

//--------------------------
void getPrime(){
	int i,j;  
    for(i = 0;i<50;i++)  
    prime[i] = 1;  
    prime[0] = prime[1] = 0;  
    for(i = 2;i<50;i++)  
    {  
        if(prime[i])  
        for(j = i+i;j<50;j+=i)  
        prime[j] = 0;  
    }  
}
void dfs(int m){

	if(m==n+1&&prime[a[1]+a[m-1]]){	
		for(int i = 1;i<n;i++)  
        printf("%d ",a[i]);  
        printf("%d\n",a[n]);  
        return ; 	
	}
	for(int i=2;i<=n;i++){
			if(!visited[i]&&prime[a[m-1]+i]){				
				visited[i]=1;
				a[m]=i;
				dfs(m+1);
				visited[i]=0;
			}
		}
}
int main() {
	getPrime();
	a[1]=1;
	while(~scanf("%d",&n)){
		memset(visited,0,sizeof(visited));	
		printf("Case %d:\n",++p);		
		dfs(2);
		printf("\n");
	}

return 0;
}
