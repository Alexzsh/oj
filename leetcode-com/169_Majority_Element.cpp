#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int majorityElement(vector<int>& nums) {
    int res=0;
    int count=0;
    for(int num:nums){
        if(!count){
            res=num;
            count++;
        }else 
            count+=num==res?1:-1;
    }
    return res;
}
int n,m;
string s,ss;

int main() {
    vector<int> vec={1,1,2,2,3};
    cout<<majorityElement(vec);
}

