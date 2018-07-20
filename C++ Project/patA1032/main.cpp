#include<iostream>  
using namespace std;  
#include<cstring>  
int map[100005];  
int vst[100005] = { 0 };  
int main(){  
    memset(map, -1, sizeof(map));  
    int add1, add2, n;  
	scanf("%d%d%d",&add1,&add2,&n); 
    for (int i = 0; i < n; i++){  
        int a, b; char ch;  
        scanf("%d %c %d",&a,&ch,&b); 
        map[a] = b;  
    }  
    int add = add1;  
    while (add != -1){  
        vst[add] = 1;  
        add = map[add];  
    }  
    add = add2;  
    while (add != -1 && !vst[add]){  
        add = map[add];  
    }  
    if (add == -1)  
        printf("-1");  
    else  
        printf("%05d", add);  
} 
