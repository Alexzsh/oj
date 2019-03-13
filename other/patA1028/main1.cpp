#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
//--------------------------

string str; 
int a[1000]={0},j,k,l,n,m,t;
char ch='A'; 
//--------------------------
string convert(string s, int numRows) {
    if(numRows==1) return s;
    string ss[numRows];
    int len=s.length();
    for(int i=0;i<len;i++)
        ss[i%numRows].push_back(s[i]);
    s.clear();
    for(int j=0;j<numRows;j++)
        for(int k=0;k<ss[j].size();k++)
            s+=ss[j][k];
    return s;
}
int main() {
	str="wqewqewqeq";
	cout<<convert(str,3); 

return 0;
}
