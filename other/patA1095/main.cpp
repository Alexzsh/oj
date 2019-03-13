#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
//--------------------------
struct car{
	char name[10],status[5];
	int h,m,s,f=0;
	friend bool operator<(const car& a,const car& b){
		if(a.h!=b.h) return a.h<b.h;
		else if(a.m!=b.m) return a.m<b.m;
		else if(a.s!=b.s) return a.s<b.s;
		else return strcmp(a.name,b.name)<0;
	}
};
vector<car> c;

string str[100],s1,s2,s3; 
int a[1000]={0},y,u,o,n,m,an,maxTime;
char ch='A'; 
//--------------------------
int main() {
	cin>>n>>m;
	c.resize(n);
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d %s",c[i].name,&c[i].h,&c[i].m,&c[i].s,c[i].status);
	} 
	sort(c.begin(),c.end());
	printf("-------------------");
	map<string,int> t;
	map<string,int> res;
	
	for(int i=0;i<n;i++){	
//		printf("%s %d:%d:%d %s\n",c[i].name,c[i].h,c[i].m,c[i].s,c[i].status);
		string sname(c[i].name);
		string sstatus(c[i].status);
		if(sstatus=="in"){
			t[sname]=3600*c[i].h+60*c[i].m+c[i].s;			
		}
		else
		{
			res[sname]=3600*c[i].h+60*c[i].m+c[i].s-t[sname];
			maxTime=max(maxTime,res[sname]);
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d:%d:%d",&y,&o,&u);

		for(int j;j<n;++j){  
            if(y*3600+o*60+u>=t[c[j].name]){  
              if(c[j].status[0]=='i') an++;  
              else an--;  
           }  
           else break;  
        }  
        printf("%d\n",an);  
	}
		

return 0;
}
