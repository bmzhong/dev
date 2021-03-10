#include <iostream>
#include <algorithm>
using namespace std;
void maxLen(int max, int &len);
void radixsort(int a[], int n, int len);
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    auto it = max_element(a, a + n - 1);
    int len;
    maxLen(*it, len);
    radixsort(a,n,len);
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}

void maxLen(int max, int &len)
{
    len = 0;
    while (max != 0)
    {
        ++len;
        max /= 10;
    }
}

void radixsort(int a[], int n, int len)
{
    int temp[n];
    int count[10];
    int radix = 1;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            count[j] = 0;
        }
        for (int j = 0; j < n; ++j)
        {
            int r = (a[j] / radix) % 10;
            ++count[r];
        }
        for(int j=1;j<10;++j){
            count[j]=count[j-1]+count[j];
        }
        for (int j = n - 1; j >= 0; --j)
        {
            int r = (a[j] / radix) % 10;
            temp[count[r] - 1] = a[j];
            --count[r];
        }
        for (int j = 0; j < n; ++j)
        {
            a[j] = temp[j];
        }
        radix = radix * 10;
    }
}