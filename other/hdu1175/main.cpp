#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------

string str; 
int a[1000]={0},j,k,l,n,m,t,s,d,f,g,ans;
char ch='A'; 
int maze[1010][1010],dir[4][2]={0,1,0,-1,1,0,-1,0};
bool vis[1010][1010],flag=0;
bool judge(int x,int y){
	
	if(maze[x][y]!=0&&maze[x][y]!=ans) return false;
	if(vis[x][y]) return false;
	return true;
}
void dfs(int x,int y,int z,int k){
	if(flag) return;
	if(k>2) return;
	if(x<=0||x>n||y<=0||y>m) return ;
	if(x==f&&y==g)
	{
		flag=1;
		return;
	}
	if(k==2)
		if(!(z == 1 && x>f && y==g || z == 2 && x<f && y==g || z == 3 && y>g && x==f || z==4 && y<g && x==f))  
        	return;  
    
	if(maze[x][y]!=0||vis[x][y]) return;
	vis[x][y]=1;
	if(z==1)
	{
		dfs(x-1,y,1,k);
		dfs(x+1,y,2,k+1);
		dfs(x,y-1,3,k+1);
		dfs(x,y+1,4,k+1);	
	}
	else if(z==2)
	{
		dfs(x-1,y,1,k+1);
		dfs(x+1,y,2,k);
		dfs(x,y-1,3,k+1);
		dfs(x,y+1,4,k+1);	
	}
	else if(z==3)
	{
		dfs(x-1,y,1,k+1);
		dfs(x+1,y,2,k+1);
		dfs(x,y-1,3,k);
		dfs(x,y+1,4,k+1);	
	}
	else if(z==4)
	{
		dfs(x-1,y,1,k+1);
		dfs(x+1,y,2,k+1);
		dfs(x,y-1,3,k+1);
		dfs(x,y+1,4,k);
	}
	vis[x][y]=0;
	
	
}
//--------------------------
int main() {
	while(cin>>n>>m&&(n||m)){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>maze[i][j];
		cin>>t;
		while(t--){
			flag=0;
			memset(vis,0,sizeof(vis));
			cin>>s>>d>>f>>g;
			if(s==f&&d==g){
				cout<<"No\n";
				continue; 
			}
			else if(maze[s][d]==maze[f][g]&&maze[s][d]!=0){
				dfs(s-1,d,1,0);
				dfs(s+1,d,2,0);
				dfs(s,d-1,3,0);
				dfs(s,d+1,4,0);
				if(flag)
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
			else
				cout<<"NO\n"; 		 
		}
	}

return 0;
}
