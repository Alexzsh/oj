#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
//--------------------------
int m,t=0,key[105],index1=0;
//--------------------------
struct node{
	int val,left,right;
}; 
vector<node> tree;
void inorder(node& n){
	if(n.left!=-1)
		inorder(tree[n.left]);
	n.val=key[index1++];
	if(n.right!=-1)
		inorder(tree[n.right]);
}
void level(){
	queue<node> Q;
	Q.push(tree[0]);
	while(!Q.empty())
	{
		node n=Q.front();
		if(t==0){
			cout<<n.val;
			t=1;
		}
		else 
			cout<<" "<<n.val;
		Q.pop();
		if(n.left!=-1)
			Q.push(tree[n.left]);
		if(n.right!=-1)
			Q.push(tree[n.right]);
		
	}
}
bool cmp(int a,int b){
	return a<b;
}
int main() {
	cin>>m;
	tree.resize(m);
	for(int i=0;i<m;i++)	cin>>tree[i].left>>tree[i].right;
	for(int i=0;i<m;i++)	cin>>key[i];
	sort(key,key+m,cmp);
	inorder(tree[0]);
	level();
	return 0;
}
