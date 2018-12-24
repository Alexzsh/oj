#include<iostream>
#include<map>
using namespace std;

typedef map<int,char*> ismap;

int main(){
    int i=1,j;
    char* str[10]={"one","two","three","fore","five","six","sever","eight","nine","ten"};
    ismap trans_map1;
    ismap::iterator it;
    for(i=1;i<=10;i++)  trans_map1.insert(ismap::value_type(i,str[i-1]));
    for(it=trans_map1.begin();it!=trans_map1.end();it++) 
        cout<<(*it).first<<'\t'<<(*it).second<<endl;
    cout<<trans_map1.size()<<endl;
    cout<<"请输入1~10的数字："<<endl;
    cin>>j;
    it=trans_map1.find(j);
    cout<<(*it).first<<'\t'<<(*it).second<<endl;
    return 0;
}

