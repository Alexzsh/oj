#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------

string str,pwd,user[1010],pass[1010]; 
int a[1000]={0},j,k,l,n,m,t;
char ch='A'; 
//--------------------------
int main() {
	cin>>n;
	char c[1000];
	c['1']='@';
	c['0']='%';
	c['l']='L';
	c['O']='o'; 
	for(int i=0;i<n;i++){
		cin>>str>>pwd;
		t=0;
		for(int i=0;i<pwd.length();i++){
			if(pwd[i]=='1'||pwd[i]=='0'||pwd[i]=='l'||pwd[i]=='O')
			{
				pwd[i]=c[pwd[i]];
				t=1;		
			}	
		}
		if(t==1){
			user[m]=str;
			pass[m]=pwd;
			m++;
		}
		
			
	}
	if(m>0){
		cout<<m<<"\n";
		for(int i=0;i<m;i++)
			cout<<user[i]<<" "<<pass[i]<<endl; 
	}
	else
	{
		cout<<"There "<<(n==1?"is ":"are ")<<n<<(n==1?" account and no account is modified":" accounts and no account is modified"); 
	}
	

return 0;
}
