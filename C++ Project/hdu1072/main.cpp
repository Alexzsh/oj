#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;
//--------------------------

string str; 
int a[1000]={0},j,k,l,n,m,num,sx,sy;
char ch='A'; 
struct node{
	int x,y,step,time;
	node(int x,int y,int step,int time):x(x),y(y),step(step),time(time){}
};
int maze[10][10],dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
//--------------------------
bool judge(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return 0;
	if(maze[x][y]==0) return 0;
	return 1; 
}
int bfs(int x,int y){
	queue<node> q;
	
	q.push(node(x,y,0,6));
	while(!q.empty()){
		node Node=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=Node.x+dir[i][0];
			int ny=Node.y+dir[i][1];
			int time=Node.time-1;
			int step=Node.step+1;
			if(judge(nx,ny)&&time>0)
			{
				if(maze[nx][ny]==3) return step;
				else if(maze[nx][ny]==4){
					time=6;
					maze[nx][ny]=0;
				}
				q.push(node(nx,ny,step,time));
			}
			
		}
	}
	return -1;
}
int main() {
	cin>>num;
	while(num--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf("%d",&maze[i][j]);
				if(maze[i][j]==2)
				{
					sx=i,sy=j;
				}
			}
		cout<<bfs(sx,sy)<<"\n";
		
		}
	

return 0;
}
