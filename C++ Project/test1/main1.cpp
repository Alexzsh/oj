#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 10000
#define INF 0x7fffffff

int x[MAX],y[MAX];
double G[MAX][MAX];
double cal(int i,int j){
	int width=abs(x[j]-x[i]);
	int len=abs(y[j]-y[i]);
	return sqrt(width*width+len*len);
}
int main() {
	cout<<(0x6f)<<endl<<(0x7f)<<endl;
	cout<<(!(1<<2)&6);
//	int n,m,a,b;
//	fill(G[0],G[0]+MAX*MAX,INF);
//	freopen("in.txt","r",stdin);
//	cin>>n;
//	for(int i=1;i<=n;i++)
//		cin>>x[i]>>y[i];
//	cin>>m;
//	for(int i=0;i<m;i++)
//	{
//		cin>>a>>b;
//		G[a][b]=G[b][a]=cal(a,b);
//	}
//	for(int k=1;k<=n;k++)
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
//				if(i!=k&&k!=j&&i!=j)
//					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
//	cin>>a>>b;
//	printf("%.2f",G[a][b]);
//	fclose(stdin);
	return 0;
}
