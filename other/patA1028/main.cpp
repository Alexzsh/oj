#include <iostream>
using namespace std;
// Author: Tanky Woo
// www.wutianqi.com
const int _max = 10001; 
// c1�Ǳ�������������������ϵ���Ŀ
// c2���м���������ÿһ�ε����
int c1[_max], c2[_max];   
int main()
{	//int n,i,j,k;
	int nNum;   // 
	int i, j, k;

	while(cin >> nNum&&nNum)
	{
		for(i=0; i<=nNum; ++i)   // ---- ��
		{
			c1[i] = 1;
			c2[i] = 0;
		}
		for(i=2; i*i<=nNum; ++i)   // ----- ��
		{

			for(j=0; j<=nNum; ++j)   // ----- ��
				for(k=0; k+j<=nNum; k+=i*i)  // ---- ��
				{
					c2[j+k] += c1[j];
				}
			for(j=0; j<=nNum; ++j)     // ---- ��
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		cout << c1[nNum] << endl;
	}
	return 0;
}
