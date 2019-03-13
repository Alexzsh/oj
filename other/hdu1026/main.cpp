#include <iostream>
#include <algorithm>
#include <string.h>
#include<math.h>
using namespace std;
//--------------------------
#define MAX 105
char map[MAX][MAX];
int n,m,k,time,flag,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}},vis[MAX][MAX],sqe[MAX][MAX],p,l; 

void dfs(int si,int sj,int time){
	if(si<0||si>n||sj<0||sj>m)
		return;

	if(si==n-1&&sj==m-1){
		flag=1;
		return;
	}
	for(int i=0;i<4;i++){
		if(!vis[si+dir[i][0]][sj+dir[i][1]]&&map[si+dir[i][0]][sj+dir[i][1]]!='X'){
			
			
				vis[si+dir[i][0]][sj+dir[i][1]]=1;
				sqe[k][0]=si+dir[i][0];
				sqe[k][1]=sj+dir[i][1];
				k++;
				if(map[si+dir[i][0]][sj+dir[i][1]]=='.')
					dfs(si+dir[i][0],sj+dir[i][1],time+1);
				else
					dfs(si+dir[i][0],sj+dir[i][1],time+map[si+dir[i][0]][sj+dir[i][1]]-'0');
				vis[si+dir[i][0]][sj+dir[i][1]]=0;
				sqe[k][0]=0;
				sqe[k][1]=0;
				k--;
				
			
			
			
		}
	}
}
//--------------------------
int main() {
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>map[i][j];
		k=0;
		time=0;
		sqe[0][0]=0;
		sqe[0][1]=0;
		memset(vis,0,sizeof(vis));
		dfs(0,0,0);
		if(flag==1){
			printf("It takes %d seconds to reach the target position, let me show you the way.",time);
			for(int i=0;i<time;i++){
				char ch=map[sqe[i+1][0]][sqe[i+1][1]];
				if(ch=='.')
					printf("%ds:(%d,%d)->(%d,%d)\n",++p,sqe[i][0],sqe[i][1],sqe[i+1][0],sqe[i+1][1]);
				else{
					for(int j=1;j<=ch-'0';j++){
						printf("%ds:FIGHT AT (%d,%d)\n",++p,sqe[i][0],sqe[i][1]);
					}
				}
			}
			
		}
		else
		{
			printf("God please help our poor hero.\n");
		}
		printf("FINISH\n");
	}

return 0;
}
