#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
using namespace std;
//--------------------------
#define MAX 110
string str; 
int a[1000]={0},j,k,l,n,m,t=1,vis[MAX][MAX];
char maze[MAX][MAX];
char ch='A'; 
struct node{
	int x,y;
	int step;
	bool operator<(const node &a) const{
		return a.step<step;
	}
}S,Node; 
struct father{
	int x,y;
}fa[MAX][MAX];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
//--------------------------
bool judge(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return false;
	if(maze[x][y]=='X') return false;
	if(vis[x][y]==1) return false;
	return true;
} 
int bfs(){
	priority_queue<node> q;
	q.push(S);
	while(!q.empty()){
		node p = q.top();
//		printf("(%d,%d)+%d\n",p.x,p.y,p.step);
		q.pop();
		if(p.x==n-1&&p.y==m-1){
			return p.step;
		}
		for(int i=0;i<4;i++){
			int nx=p.x+dir[i][0];
			int ny=p.y+dir[i][1];
			if(judge(nx,ny)){
				Node.x=nx,Node.y=ny;
				Node.step=maze[nx][ny]=='.' ? p.step+1 : p.step+maze[nx][ny]-'0'+1;
				q.push(Node);
				fa[nx][ny].x=p.x,fa[nx][ny].y=p.y;
				vis[nx][ny]=1;
				
			}
		}
	}
	return -1;
}
void dfs(int x,int y){
	if(x==0&&y==0){	
		if(maze[x][y]!='.'){
			int num=maze[x][y]-'0';
	//		printf("%ds:(%d,%d)->(%d,%d)\n",t++,fa[x][y].x,fa[x][y].y,x,y);
			while(num--){
				printf("%ds:FIGHT AT (%d,%d)\n",t++,x,y);
			}
		}
		return;
	}
	else{
		dfs(fa[x][y].x,fa[x][y].y);
		if(maze[x][y]=='.'){
			printf("%ds:(%d,%d)->(%d,%d)\n",t++,fa[x][y].x,fa[x][y].y,x,y);
		}
		else{
			int num=maze[x][y]-'0';
			printf("%ds:(%d,%d)->(%d,%d)\n",t++,fa[x][y].x,fa[x][y].y,x,y);
			while(num--){
				printf("%ds:FIGHT AT (%d,%d)\n",t++,x,y);
			}
		}
			
	}
}
int main() {
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(vis,0,sizeof(vis));
		memset(&fa,0,sizeof(fa));
		t=1;
		for(int i=0;i<n;i++){
			getchar();
			for(int j=0;j<m;j++)
			{
				maze[i][j]=getchar();
			}
			maze[i][m+1]='\0'; 
		}
		S.x=0,S.y=0,S.step=0;
		vis[0][0]=1;
		int ans=bfs();
		if(ans>0)
		{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
			dfs(n-1,m-1);
		}
		else{
			printf("God please help our poor hero.\n");
		}
		printf("FINISH\n");
	}
	
return 0;
}
