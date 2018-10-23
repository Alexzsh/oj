#include<iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int sum=0;
    
    while(x||y){
        sum+= x&1 ^  y&1 ? 1:0;
        x>>=1;
        y>>=1;
    }
    return sum;
}

int main() {
    cout<< hammingDistance(1,4);
}
