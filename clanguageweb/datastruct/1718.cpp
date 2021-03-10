#include <iostream>
using namespace std;
void create(int a[], int &n);
void down(int a[], int n, int p);
int main()
{
    int n;
    int a[100001];
    create(a, n);
    int size = n;
    for (int i = 0; i < n; ++i)
    {
        cout << a[0] << " ";
        a[0] = a[size - 1];
        down(a, size, 0);
        --size;
    }
    cout << endl;
    system("pause");
    return 0;
}

void create(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int p;
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        p = i;
        while (p * 2 + 1 < n)
        {
            int lchild = 2 * p + 1;
            int rchild = 2 * p + 2;
            int min = lchild;
            if (rchild < n)
            {
                if (a[lchild] > a[rchild])
                {
                    min = rchild;
                }
            }
            if (a[p] > a[min])
            {
                int t = a[min];
                a[min] = a[p];
                a[p] = t;
                p = min;
            }
            else
            {
                break;
            }
        }
    }
}
void down(int a[], int n, int p)
{
    if (2 * p + 1 > n)
    {
        return;
    }
    while (2 * p + 1 < n)
    {
        int lchild = 2 * p + 1;
        int rchild = 2 * p + 2;
        int min = lchild;
        if (rchild < n)
        {
            if (a[lchild] > a[rchild])
            {
                min = rchild;
            }
        }
        if (a[p] > a[min])
        {
            int t = a[p];
            a[p] = a[min];
            a[min] = t;
            p = min;
        }else{
            break;
        }
    }
}