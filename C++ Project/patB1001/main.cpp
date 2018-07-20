#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
//--------------------------
struct stu{
	string num;
	int sco;
	int fr;
	int ln;
	int lr;
}student[1000];
bool cmp(stu s1,stu s2){
	if(s1.sco!=s2.sco)
		return s1.sco >s2.sco;
	else
		return s1.num<s2.num;
}
int n,m,a,b,s[100005],sum,p;
char ch,c[1000][1000],cc[100];
string ss[100];
//--------------------------
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		sum+=m;
		for(int j=1;j<=m;j++){
			cin>>student[p].num>>student[p].sco;
			student[p].ln=i;
			p++;			
		}
		sort(student+p-m,student+p,cmp);//排序要从每一组的第一个开始 
		student[p-m].lr=1;
		for(int k=p-m+1;k<=p;k++)
			student[k].lr=(student[k].sco==student[k-1].sco?student[k-1].lr:k+1-p+m);//同样一组排序的组数 
	}				
	sort(student,student+sum,cmp);

	student[0].fr=1;
	
	for(int l=1;l<=p;l++)
		student[l].fr=(student[l].sco==student[l-1].sco?student[l-1].fr:l+1);
	cout<<sum<<"\n";
	for(int l=0;l<sum;l++)
	{
		cout<<student[l].num<<" "<<student[l].fr<<" "<<student[l].ln<<" "<<student[l].lr<<"\n"; 
	} 
	
	

return 0;
}
