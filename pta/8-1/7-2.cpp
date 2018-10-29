#include<iostream>
using namespace std;
int main() {
    string s;
    cin>>s;
    cout<<"year:"<<s.substr(0,4)<<'\n'<<"department:"<<s.substr(4,2)<<'\n'<<"class:"<<s.substr(6,2)<<endl;
}
