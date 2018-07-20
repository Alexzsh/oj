#include<iostream>
#include<algorithm>
#include<string.h>
#include<cstdio> 
#include<cmath>
using namespace std;


struct bign{
	int d[1000],len;
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
};
bign change(string s){
	bign num;
	
	num.len=s.length();
	for(int i=0;i<num.len;i++)
		num.d[i]=s[num.len-i-1]-'0';
	return num; 
}
bign add(bign a,bign b){
	int carry=0;
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){
		int num=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=num%10;
		carry=num/10;
	}
	if(carry!=0)
		c.d[c.len++]=carry;
	return c;
	
}
bool jugde(bign num){
	for(int i=0;i<num.len;i++)
		if(num.d[i]!=num.d[num.len-i-1])
			return false;
	return true;
}
int main(){
	string str1;
	int m;
	cin>>str1>>m;
	bign a=change(str1);
	int i;
	for(i=1;i<=m&&!jugde(a);i++){
		bign b=a;
		reverse(b.d,b.d+b.len);
		a=add(a,b);
	}
	for(int j=a.len-1;j>=0;j--)
		cout<<a.d[j];
	cout<<"\n";
	cout<<i-1; 
	return 0;
}
