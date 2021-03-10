#include <iostream>
#include <cstdio>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int n, a[5000000], k;
int quicksort(int left, int right)
{
    int mid = a[left];
    while (left < right)
    {
        while (left < right && mid <= a[right])
            --right;
        a[left] = a[right];
        while (left < right && mid >= a[left])
            ++left;
        a[right] = a[left];
    }
    return left;
}
void find_k(int left, int right)
{
    int temp = quicksort(left, right);
    if (temp == k)
        printf("%d\n", a[temp]);
    else if (k - 1 < temp)
        find_k(left, temp - 1);
    else
        find_k(temp + 1, right);
}
int main()
{
    n = read();
    k = read();
    for (int i = 0; i < n; ++i)
    {
        a[i] = read();
    }
    find_k(0, n - 1);
    system("pause");
    return 0;
}