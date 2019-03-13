#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>
#include <stack>
using namespace std;
//--------------------------
#define MAX 505 
#define INF 100000000

string str;
bool flag;
int vis[505],d[505],wei[505],num[505],G[505][505],cost[MAX][MAX],c[MAX],n,m,c1,c2,k,l,p,q,opt=INF;

vector<int> pre[MAX],path,tmp;
//--------------------------
void dijkstra(int s){
	fill(d,d+MAX,INF);
	
	
	d[s]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return ;
		vis[u]=1;
		for(int j=0;j<n;j++){
			if(!vis[j]&&G[u][j]!=INF){
				if(d[u]+G[u][j]<d[j])
				{
					d[j]=d[u]+G[u][j];
					pre[j].clear();
					pre[j].push_back(u);
				}
				else if(d[j]==d[u]+G[u][j]){	
					pre[j].push_back(u);
				}
			}
		}
	}

}
void dfs(int s){
	if(s==c1){
		tmp.push_back(s);
		int v=0;
		for(int i=tmp.size()-1;i>0;i--)
		{
			v+=cost[tmp[i]][tmp[i-1]];
		}
		if(v<opt)
		{
			opt=v;
			path=tmp;
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(s);
	for(int i=0;i<pre[s].size();i++){
		dfs(pre[s][i]);
	}
	tmp.pop_back();
}
void printP()
{
	for(int i=path.size()-1;i>=0;i--)
	{
		cout<<path[i]<<" ";
	}
}
int main() {
	cin>>n>>m>>c1>>c2;
	
	fill(G[0],G[0]+MAX*MAX,INF);
	fill(cost[0],cost[0]+MAX*MAX,INF);
	
	for(int i=0;i<m;i++){
		cin>>k>>l>>p>>q;
		G[k][l]=G[l][k]=p;
		cost[k][l]=cost[l][k]=q;	
	}
	dijkstra(c1);
	dfs(c2);
	printP();
	cout<<d[c2]<<" "<<opt; 
	return 0;
}
