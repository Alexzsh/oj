
#include <iostream>
#include <vector>
using namespace std;
vector<int> post,in,level(100000,-1);
int n;
void pre(int root, int start, int end,int index) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    level[index]=post[root];

    pre(root-(end-i+1), start, i - 1,2*index+1);

    pre(root - 1, i + 1, end,2*index+2);
}
 
int main() {
	cin>>n;
	post.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++)
		cin>>post[i];
	for(int i=0;i<n;i++)
		cin>>in[i];
	pre(n-1,0,n-1,0);
	int sum=0;
	for(int i=0;i<level.size();i++){
		if(level[i]!=-1&&sum!=n-1){
			cout<<level[i]<<" ";
			sum++; 
		}
		else if(level[i]!=-1)
		{
			cout<<level[i];
			break;	
		}
	}
    return 0;
}
