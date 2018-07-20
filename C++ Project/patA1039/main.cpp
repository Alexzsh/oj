#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;
//--------------------------

char str[20]; 
int a[1000]={0},j,k,l,n,t,stuSum,couNum,couSum,couId,stuNum;
char ch='A'; 
string s[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string ss[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
set<int> se[55];
map<string,int> m;
string u[170];
//--------------------------
void init(){
	for(int i=0;i<13;i++){
		u[i]=s[i];
		m[s[i]]=i;
		u[i*13]=ss[i];
		m[ss[i]]=i*13;
	}
	for(int i=1;i<13;i++)
		for(int j=1;j<13;j++)
		{
			string str1=ss[i]+" "+s[j];
			u[i*13+j]=str1;
			m[str1]=i*13+j; 
		}
}
int main() {
	init();
	scanf("%d%*c",&n);
	for(int i=0;i<n;i++)
	{
		string s1;
		getline(cin,s1);
		if(s1[0]>='0'&&s1[0]<='9'){
			int num=0;
			for(int i=0;i<s1.length();i++)
				num=num*10+(s1[i]-'0');
			cout<<u[num]<<endl; 
		}
		else
			cout<<m[s1]<<endl;
	}
	

return 0;
}
