#include <iostream>
using namespace std;
int a[100000000], b[100000000];
int n;
void merge_sort(int x, int y);
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    merge_sort(0, n);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}

void merge_sort(int x, int y)
{
    if (y-x>1)
    {
        int m = x + (y - x) / 2;
        merge_sort(x, m);
        merge_sort(m, y);
        int i = x, j = m, k = x;
        while (i < m || j < y)
        {
            if (j >= y || (i < m && a[i] < a[j]))
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }
        k = x;
        while (k < y)
        {
            a[k] = b[k];
            ++k;
        }
    }
}
