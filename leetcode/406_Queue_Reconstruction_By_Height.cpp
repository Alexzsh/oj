#include<iostream>
#include<vector>
using namespace std;
bool sortFunc(const pair<int,int> &a,const pair<int,int> &b){
    return a.first != b.first ? a.first<b.first : a.second<b.second;
}
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    vector<pair<int,int>> res(people.size(),make_pair(0,0));
    sort(people.begin(),people.end(),sortFunc);

    return people;
}


int main(){

}
