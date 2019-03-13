#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
//--------------------------
struct man{
	string name,gender,id; 
	int t;	
}f,m,stu[1010];

int a[1000]={0},j,k,l,n,t,fs,ms;
char ch='A'; 
//--------------------------
int main() {
	cin>>n;
	if(n==0){
		cout<<"Absent\nAbsent\nNA";
		return 0;
	}	
	f.t=0,f.gender="";
	m.t=100,m.gender=""; 

	for(int i=0;i<n;i++)
	{
		cin>>stu[i].name>>stu[i].gender>>stu[i].id>>stu[i].t;
		if(stu[i].gender=="F"){
			if(stu[i].t>=f.t)
				f=stu[i];
		}	
		else
			if(stu[i].t<=m.t)
				m=stu[i]; 
	}
	if(f.gender!="")
		cout<<f.name<<" "<<f.id<<endl;
	else
		cout<<"Absent\n"; 
	if(m.gender!="")
		cout<<m.name<<" "<<m.id<<endl; 
	else
		cout<<"Absent\n";
	if(f.gender==""||m.gender=="")	cout<<"NA";
	else cout<<abs(m.t-f.t);
return 0;
}
