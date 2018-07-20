#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------
#define MAX 10010

int father[MAX],course[MAX],isRoot[MAX],vis[MAX];
struct Data{
	int id,fid,mid,num,area;
	int cid[10];
}data[1005];
struct node{
	int id,people;
	double num,area;
	bool flag=false;
}ans[MAX];
//--------------------------
void init(){
	for(int i=0;i<=MAX;i++)
		father[i]=i;	
}
int findFather(int x){
	while(x!=father[x])
		x=father[x];
	return x;
}
void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb){
		father[max(fa,fb)]=min(fa,fb);
	}	
}
bool cmp(node a,node b){
	if(a.area!=b.area)
		return a.area>b.area;
	else
		return a.id<b.id;
}
int main() {
//	int n,j,h;
//	scanf("%d",&n);
//	init(n);
//	for(int i=1;i<=n;i++)
//	{
//		scanf("%d:",&j);
//		for(int k=0;k<j;k++){
//			scanf("%d",&h);
//			if(course[h]==0) course[h]=i;
//			Union(i,findFather(course[h]));
//		}
//		
//	}
//	for(int i=1;i<=n;i++){
//		isRoot[findFather(i)]++;	
//	}
//	int ans=0;
//	for(int i=1;i<=n;i++){
//		if(isRoot[i]!=0)
//			ans++;
//	}
//	cout<<ans<<"\n";
//	sort(isRoot+1,isRoot+n+1,cmp);
//	for(int i=1;i<=ans;i++)
//	{
//		cout<<isRoot[i];
//		if(i<ans) cout<<" ";
//	}

	//1104
	int n,k,h,id,fid,mid;
	init();
	cin>>n;
	for(int i=0;i<n;i++){	
		cin>>data[i].id>>data[i].fid>>data[i].mid>>h;
		vis[data[i].id]=true;
		if(data[i].fid!=-1){
			vis[data[i].fid]=true;
			Union(data[i].fid,data[i].id);
		}
		if(data[i].mid!=-1){
			vis[data[i].mid]=true;
			Union(data[i].mid,data[i].id);
		}
		for(int j=0;j<h;j++){
			cin>>data[i].cid[j];
			vis[data[i].cid[j]]=true;
			Union(data[i].id,data[i].cid[j]);
		}
		cin>>data[i].num>>data[i].area;
	}
	for(int i=0;i<n;i++){
		int id=findFather(data[i].id);
		ans[id].id=id;
		ans[id].num+=data[i].num;
		ans[id].area+=data[i].area;
		ans[id].flag=true;
	}
	for(int i=0;i<10000;i++){
		if(vis[i])	ans[findFather(i)].people++;
		if(ans[i].flag) k++;
	}
	for(int i=0;i<10000;i++){
		if(ans[i].flag){
			ans[i].num=(double)(ans[i].num*1.0/ans[i].people);
			ans[i].area=(double)(ans[i].area*1.0/ans[i].people);
		}
	}
	sort(ans,ans+10000,cmp);
	printf("%d\n",k);
	for(int i=0;i<k;i++){
		printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);
	}
	
	 

return 0;
}
