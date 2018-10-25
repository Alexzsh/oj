#include<iostream>
#include<vector>
using namespace std;
vector<int> countBits(int num) {
    vector<int> res={0};
    for(int i=1;i<num;++i){
        if(!(i&(i-1)))
            res.push_back(1);
        else 
            res.push_back(res[i&(i-1)]+1);
    }
    return res;
}   
int* countBitss(int num) {
    int* res = new int[num+1];
    for(int i=1;i<=num;++i) {
        res[i]=res[i>>1]+(i&1);
    }
    return res;

}
int main() {

    int* r=countBitss(10);
    for(int i=0;i<=10;++i)
        cout<<r[i]<<" ";
}
