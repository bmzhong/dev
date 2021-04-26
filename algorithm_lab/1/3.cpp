#include <iostream>
using namespace std;
int n, a[1000];
int partition(int l, int r);
void quick_sort(int l, int r);
int main()
{
    cout<<"input:"<<endl;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    quick_sort(0, n - 1);
    cout<<"output:"<<endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
int partition(int l, int r)
{
    int key = a[l];
    while (l < r)
    {
        while (l < r && a[r] >= key)
            --r;
        if (l < r)
            a[l++] = a[r];
        while (l < r && a[l] < key)
            ++l;
        if (l < r)
            a[r--] = a[l];
    }
    a[l] = key;
    return l;
}
void quick_sort(int l, int r)
{
    if (r <= l)
        return;
    int m = partition(l, r);
    quick_sort(l, m - 1);
    quick_sort(m + 1, r);
}
/*
case 1
6
4 6 5 2 1 3
*/