#include<iostream> 
#include<cstring>
using namespace std;
#define MAX 510
#define INF 10000000
int G[MAX][MAX],cost[MAX][MAX],d[MAX],c[MAX],pre[MAX],n,m,j,k,o,p,st,ed;
bool vis[MAX];
void dijkstra(int s){
	fill(d,d+MAX,INF);
	fill(c,c+MAX,INF);
	d[s]=0;
	c[s]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&G[i][j]!=INF){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=1;
		for(int v=0;v<n;v++){
			
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}
				else if(d[u]+G[u][v]==d[v]){
					if(c[u]+cost[u][v]<c[v]){
						c[v]=c[u]+cost[u][v];
						pre[v]=u;
					}
				}
			}
		
	}
}
void dfs(int v){
	if(v==st){
		cout<<v<<" ";
		return; 
	}
	dfs(pre[v]);
	cout<<v<<" ";
	return; 
}
int main(){
	cin>>n>>m>>st>>ed;
	for(int i=0;i<n;i++) pre[i]=i;
	fill(G[0],G[0]+MAX*MAX,INF);
	for(int i=0;i<m;i++){
		cin>>j>>k>>p>>o;
		G[j][k]=G[k][j]=p;
		cost[j][k]=cost[k][j]=o;
	}
	dijkstra(st);
	dfs(ed);
	cout<<d[ed]<<" "<<c[ed]; 
}
