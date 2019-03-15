#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000

int matrix[MAX][MAX] = {{0}};

int main()
{
    //freopen("input.txt", "r", stdin);

    int i, j;
    int max = 1;
    int size;

    string s;
    while(getline(cin,s)):

    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
            scanf("%d", &matrix[i][j]);

    for(i=1; i<size; i++)
        for(j=1; j<size; j++)
            if(matrix[i][j] == 1)
            {
                int min = 0;
                min = matrix[i-1][j]>matrix[i][j-1] ? matrix[i][j-1] : matrix[i-1][j];
                min = min>matrix[i-1][j-1] ? matrix[i-1][j-1] : min;
                matrix[i][j] = min + 1;
                max = max<matrix[i][j] ? matrix[i][j] : max;
            }

    printf("%d", max);

    return 0;
}

