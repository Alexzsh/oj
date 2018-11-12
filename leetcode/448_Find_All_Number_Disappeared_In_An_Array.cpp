#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
vector<int> findDisappearedNumbers(vector<int>& nums) {
       for(int i=0;i<nums.size();++i){
           int m = abs(nums[i])-1;
           nums[m]=nums[m]>0?-nums[m]:nums[m];
       }
       vector<int> vec;
       for(int i=0;i<nums.size();++i){
            if(nums[i]>0)
                vec.push_back(i+1);
       }
       return vec;
    }
int n,m;
string s,ss;

int main() {
    vector<int> vec={4,3,2,7,8,2,3,1};
    cout<<findDisappearedNumbers(vec)[0];
}

