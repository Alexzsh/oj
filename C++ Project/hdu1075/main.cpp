#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
//--------------------------

string str; 
int a[1000]={0},j,k,l,n,m,t;
char ch[3010]; 
//--------------------------
map<string,string> dic;

int main() {
	string s1;
	cin>>s1;
	while(cin>>s1&&s1!="END"){
		
		string b;
		cin>>b;
//		int k=getId(key);
//		cout<<k<<"\n"; 
		dic[b]=s1;
		
	}
	
	getchar();
	while(gets(ch)&&strcmp(ch,"END")!=0){

		if(strcmp(ch,"START")==0) continue;
		string ss;
		int j=0;
		for(int i=0;i<strlen(ch);i++)
		{
			if(ch[i]>='a'&&ch[i]<='z') ss+=ch[i];
			else
			{
				
				if(dic.find(ss)!=dic.end()) cout<<dic[ss];
				else cout<<ss;
				ss=""; 
				cout<<ch[i];
			}
			
		}
		printf("\n"); 
	}
	
	
return 0;
}
