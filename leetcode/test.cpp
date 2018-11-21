#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n,m;
string s,ss;
int a[100]={0};
void test(int &b,int p[]){
    b=10;
    cout<<p[0];
    p[1]=1;
    cout<<p[1];
}
int main() {
    int aa=1;
    test(aa,a);
    cout<<a[0]<<" "<<a[1];
    cout<<aa;
}

