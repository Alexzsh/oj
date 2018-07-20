#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;
//--------------------------

string str; 
int a[1000]={0},j,k,l,n,m,t,dir[4][2]={0,1,0,-1,1,0,-1,0};
char ch='A'; 
char maze[1000][1000];
bool vis[1000][1000];
struct node{
	int x,y,t;
	node(int x,int y,int t):x(x),y(y),t(t){}
	bool operator < (const node& n) const
	{
		return t>n.t;	
	}
};
int sx,sy,ex,ey;
bool judge(int nx,int ny,int step){
		if(vis[nx][ny]||nx<0||ny<0||nx>=n||ny>=m||maze[nx][ny]=='*'||(vis[nx][ny]&&step>=vis[nx][ny])) return false;
		return true;
}
//--------------------------
int bfs(node s){
	priority_queue<node> q;
	q.push(s);
	while(!q.empty()){
		
		node Node=q.top();
		q.pop();
		if(Node.x==ex&&Node.y==ey) return Node.t;
		for(int i=0;i<4;i++){

			int nx=Node.x+dir[i][0];
			int ny=Node.y+dir[i][1];
			int nt=Node.t++;
			
			if(!judge(nx,ny,nt)) continue;
			if(maze[nx][ny]=='|'){
				if(i>1&&nt&1||i<2&&!(nt&1)) nt+=2;	
				nx+=dir[i][0];
				ny+=dir[i][1];
			}
			else if(maze[nx][ny]=='-')
			{
				if(i<2&&nt&1||i>1&&!(nt&1)) nt+=2;	
				nx+=dir[i][0];
				ny+=dir[i][1];
			}		
			if(!judge(nx,ny,nt)) continue;	
			vis[nx][ny]=nt;
			q.push(node(nx,ny,nt));
			
			
		}
	}
}
int main() {
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>maze[i][j];
			if(maze[i][j]=='S'){
				sx=i;
				sy=j;
			}	
			else if(maze[i][j]=='T'){
				ex=i;
				ey=j;
			}
			
		}
	vis[sx][sy]=1;
	cout<<bfs(node(sx,sy,0));		
	

return 0;
}
