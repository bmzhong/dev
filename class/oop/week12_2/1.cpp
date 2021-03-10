#include <iostream>
using namespace std;

template <class T>
int partition(T a[], int x, int y)
{
    T pivotkey = a[x];
    while (x < y)
    {
        while (x < y && a[y] > pivotkey)
            --y;
        a[x] = a[y];
        while (x < y && a[x] < pivotkey)
            ++x;
        a[y] = a[x];
    }
    a[x] = pivotkey;
    return x;
}
template <class T>
void qsort(T a[], int x, int y)
{
    int m = partition(a, x, y);
    if (m - 1 > x)
    {
        qsort(a, x, m - 1);
    }
    if (m + 1 < y)
    {
        qsort(a, m + 1, y);
    }
}
int main()
{
    int a[6] = {1, 5, 4, 2, 7, 12};
    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
    qsort(a, 0, 5);
    cout << "qsort: " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << a[i] << "\t";
    }
    cout << endl << endl;

    double b[6] = {1.2, 5.3, 2.2, 2.6, 7.1, 12.2};
    for (int i = 0; i < 5; ++i)
    {
        cout << b[i] << "\t";
    }
    cout << endl;
    cout << "qsort: " << endl;
    qsort(b, 0, 5);
    for (int i = 0; i < 5; ++i)
    {
        cout << b[i] << "\t";
    }
    cout << endl;
    system("pause");
    return 0;
}