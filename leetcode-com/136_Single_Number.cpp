#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();++i)
        sum^=nums[i];
    return sum;
}
int main(){
    vector<int> n={4,1,4,1,5} ;
    cout<<singleNumber(n);
}
