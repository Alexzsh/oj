#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    vector<int> tmp;
    for(vector<int>::iterator it = nums.begin();it!=nums.end();it++){
        if(*it==0){
            tmp.push_back(*it);
            it=nums.erase(it);
        }
     } 
    for(vector<int>::iterator it = tmp.begin();it!=tmp.end();it++){
        nums.push_back(*it);
    }
}
int main(){
vector<int> vec;
	vec.push_back(100);
	vec.push_back(0);
	vec.push_back(300);
	vec.push_back(300);
	vec.push_back(300);
	vec.push_back(0);
    moveZeroes(vec);
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++)
        cout<<*it<<" ";
}
