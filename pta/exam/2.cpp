#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>

using namespace std;
map<string,int> mmm;


int n,m[1005],result,value;
string s[1005],ss[1005],key;
string sum,res;
int main(){
    cin>>n;
    for(int i=0;i<n-1;++i){
        cin>>sum>>key>>value;
        mmm[key]=value;
    }
    cin>>sum>>res;
    map<string,int>::iterator it;
    for(it=mmm.begin();it!=mmm.end();++it){
        if(it->first.find_first_of(res)==0)
            result+=it->second;
    }
    cout<<result;
}
