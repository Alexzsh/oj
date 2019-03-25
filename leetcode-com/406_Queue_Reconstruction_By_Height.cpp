#include<iostream>
#include<vector>
using namespace std;
bool sortFunc(const pair<int,int> &a,const pair<int,int> &b){
    return a.first != b.first ? a.first<b.first : a.second<b.second;
}
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    vector<pair<int,int>> res(people.size(),make_pair(0,0));
    sort(people.begin(),people.end(),sortFunc);
    vector<pair<int,int>>::iterator it,its;
    for(it=people.begin();it!=people.end();it++) {
        
        for(its=res.begin();its!=res.end();it++){
                
        }
    }
    return people;
}


int main(){

}
