#include <iostream>
using namespace std;

void mergesort(int SR[], int TR[], int x, int y);
int main()
{
    int n, c;
    cin>>n;
    int a[1000], b[1000];
    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        a[i] = c;
    }
    mergesort(a,b,0,n-1);
    for(int i=0;i<n-1;++i){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    system("pause");
    return 0;

}

void mergesort(int SR[], int TR[], int x, int y)
{
    if (x == y)
    {
        TR[x] = SR[x];
    }
    else
    {
        int m = x + (y - x) / 2;
        mergesort(SR, TR, x, m);
        mergesort(SR, TR, m + 1, y);
        int p = x, q = m + 1, i = x;
        while (p <= m || q <= y)
        {
            if (p > y || (p <= m && SR[p] < SR[q]))
                TR[i++] = SR[p++];
            else
                TR[i++] = SR[q++];
        }
        for (i = x; i <= y; ++i)
        {
            SR[i] = TR[i];
        }
    }
}