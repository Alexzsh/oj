#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
//--------------------------
struct bign{
	int len;
	int d[1000];
	bign(){
		memset(d,0,sizeof(d));
		len=0;
	}
};
bign change(char c[]){
	bign a;
	int len=strlen(c);
	a.len=len;
	for(int i=0;i<a.len;i++){
		a.d[i]=c[len-i-1]-'0';
	}
	return a;
} 
bign addBign(bign b1,bign b2){
	int carry =0;
	bign a;
	for(int i=0;i<b1.len||i<b2.len;i++){
		int temp=b1.d[i]+b2.d[i]+carry;
		carry = temp/10;
		a.d[a.len++]=temp%10;
		
	}
	if(carry!=0)
	{
		a.d[a.len++]=carry;
	}
	return a;
}
bign subBign(bign b1,bign b2){
	bign a;
	for(int i=0;i<b1.len||i<b2.len;i++){
		if(b1.d[i]<b2.d[i]){
			b1.d[i+1]--;
			b1.d[i]+=10; 
		}
		a.d[a.len++]=b1.d[i]-b2.d[i];
	}
	while(a.len-1>=1&&a.d[a.len-1]==0)
		a.len--;
	return a;
}
bign mulBign(bign b1,bign b2){
	bign a;
	while
}
void pp(bign r){
	for(int i=r.len-1;i>=0;i--)
		printf("%d",r.d[i]);
}
int main(){
	char n[1001],m[1001];
	scanf("%s%s",n,m);
	bign q=change(n);
	bign w=change(m);
	bign res=addBign(q,w);
	pp(subBign(q,w));
	pp(res);
	return 0;
}

