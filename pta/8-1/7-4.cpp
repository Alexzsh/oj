#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool sortFunc(string a,string b) {
    return a.length()<b.length();
}
int main() {
    int n,i;
    while(cin>>n){ 
        vector<string> *vec = new vector<string>();
        getchar();
        for(i=0;i<n;++i) {
            string s;
            getline(cin,s);
            if(s!="stop"){
                vec->push_back(s);    
            }
            else{
                break;
            }
        }
        stable_sort(vec->begin(),vec->begin()+i,sortFunc);
        for(vector<string>::iterator it=vec->begin();it!=vec->begin()+i;it++){
            cout<<*it<<endl;    
        }
        
    }
}
