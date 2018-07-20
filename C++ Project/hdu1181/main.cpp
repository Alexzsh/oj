#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------

string str; 
int a[1000]={0},j,k,l,n,m,t;
bool flag;
bool vis[1000][1000];
vector<char> s[1000]; 
//--------------------------
void dfs(char ch){
	
	
	for(int i=0;i<s[ch].size();i++)  
    {  
        if(s[ch][i]!='m'&&!vis[i][ch])  
        vis[i][ch]=1,dfs(s[ch][i]);//我错在把vis[i][x]放在递归的后面了。。哎 不知道怎么想的  
        if(s[ch][i]=='m'&&!vis[i][ch])  
        {  
            flag=1;  
            break;  
        }  
    }  
}
int main() {
	while(cin>>str&&str!="0"){
		s[str[0]].push_back(str[str.length()-1]);
	}
	dfs('b');
	if(flag)
		cout<<"Yes.\n";
	else
		cout<<"No.\n"; 
return 0;
}
