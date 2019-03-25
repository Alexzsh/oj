#include <stdio.h>
int fenshengzi(int a[], int n, int m, int left, int right)
{
    int number = 0, i, mid;
    mid = (left + right) / 2;
    for (i = 0; i < n; i++)
        number = number + a[i] / mid;

    if (left == right - 1)
        return left;
    else if (number >= m)
        fenshengzi(a, n, m, mid, right);
    else if (number < m)
        fenshengzi(a, n, m, left, mid);
}

int main()
{
    int n, m, i, a[10000], number = 0;
    long long all = 0, avg;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        all = all + a[i];
    }
    avg = all / m;
    for (i = 0; i < n; i++)
        number = number + a[i] / avg;

    if (number == m)
        printf("%.2f", (double)(avg));
    else
        printf("%.2f", (double)(fenshengzi(a, n, m, 0, avg)));

    return 0;
}
