#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n, k, a[251];
string num;
int main()
{
    cin >> num >> k;
    n = num.size();
    int m = n - k, p = -1;
    for (int i = 0; i < m; ++i)
    {
        int mins = 10;
        for (int j = p + 1; j <= k + i; ++j)
        {
            if (a[j] == 0 && num[j] - '0' < mins) // <和<=有很大区别
            {
                mins = num[j] - '0';
                p = j;
                if (mins == 0)
                    break;
            }
        }
        a[p] = 1;
    }
    int f = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1)
        {
            if (f == 0 && num[i] != '0')
            {
                printf("%c", num[i]);
                f = 1;
            }
            else if (f == 1)
                printf("%c", num[i]);
        }
    }
    if (f == 0)
        printf("0");
    printf("\n");
    system("pause");
    return 0;
}