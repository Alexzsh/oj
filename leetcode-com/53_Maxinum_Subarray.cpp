#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n,m;
string s,ss;
int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    int Max = nums[0];
    for(int i=1;i<len;++i){
        nums[i]=max(nums[i],nums[i]+nums[i-1]);
        Max = max(Max,nums[i]);
    }
    return Max;
}
int main() {
    
}

