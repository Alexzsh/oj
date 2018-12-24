#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>


using namespace std;

int n,m,upHour,upMinute,upSecond;
string s,ss;

int main(){
    cin>>n;
    while(n--){
        int hour,minute,second;
        scanf("%d:%d:%d",&hour,&minute,&second);
        cin>>m;
        upSecond=(second+m)/60;
        second=(second+m)%60;
        upMinute=(minute+upSecond)/60;
        minute=(minute+upSecond)%60;
        upHour=(hour+upMinute)/24;
        hour=(hour+upMinute)%24;
        printf("time: %d:%d:%d\n",hour,minute,second);
    }
}
