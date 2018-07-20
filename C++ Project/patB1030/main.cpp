#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 100000; //�δ������ж������ǲ��ǿ�С��



int main(int argc, char const *argv[])
{
    int num[Max+10];
    int N;
    long long x, p;
    int res, maxn = 0;
    scanf("%d %d",&N, &p );
    for(int i = 0; i<N; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num+N);   //��ɵ�������
    for(int i = 0; i < N; i++)
    {
        x = num[i] * p; //���x���ܴﵽ18λ��,��Ҫ��֤x�洢��ȷ��long long ���ͣ�pҲ������long long ����
        res = upper_bound(num+i,num+N, x) - num-i;    //��һ������M>m*p��ǰһλΪ���һ������M<=m*p�ģ���һ��1���ټ�һ��1���൱�ڵ���
        if(res > maxn)   maxn = res;
    }
    printf("%d\n",maxn );
    return 0;
}
