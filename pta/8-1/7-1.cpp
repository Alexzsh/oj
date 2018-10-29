#include<iostream>
using namespace std;
string s,text;
int main(){
    while(getline(cin,s)){
        if(s=="end") break;
        if(s=="\n") continue;
        text+=s;
    }
    string ori,tar;
    cin>>ori>>tar;
    while(text.find(ori)!=string::npos)
        text.replace(text.find(ori),ori.length(),tar);
    cout<<text;
}
