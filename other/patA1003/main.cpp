#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------
#define MAX 505
#define INF 0x3fffffff
string str; 
int a[1000]={0},j,k,l,n,m,t,st,ed,vis[MAX],d[MAX],num[MAX],w[MAX],wei[MAX],G[MAX][MAX];
char ch='A'; 
//--------------------------
void dijstra(int s){
	fill(d,d+MAX,INF);
	fill(num,num+MAX,0);
	fill(w,w+MAX,0);
	d[s]=0;
	num[s]=1;
	w[s]=wei[s];
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++)
		{
			if(!vis[j]&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
	
	if(u==-1) return;
	vis[u]=1;
	for(int v=0;v<n;v++){
		if(!vis[v]&&G[u][v]!=INF)
		{
			if(d[u]+G[u][v]<d[v])
			{
				d[v]=d[u]+G[u][v];
				w[v]=w[u]+wei[v];
				num[v]=num[u];
			}
			else if(d[u]+G[u][v]==d[v]){
				w[v]=max(w[v],w[u]+wei[v]);
				num[v]+=num[u];
			}
		}
	}
	}
}
int main() {
	cin>>n>>m>>st>>ed;
	fill(G[0],G[0]+MAX*MAX,INF);
	
	for(int i=0;i<n;i++)
		cin>>wei[i];
	for(int i=0;i<m;i++){
		cin>>k>>l>>t;
		G[k][l]=G[l][k]=t;
	}
	dijstra(st);
	cout<<num[ed]<<"   "<<w[ed]; 
return 0;
}
