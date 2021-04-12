#include <iostream>
using namespace std;
int partition(int a[], int x, int y);
void quick_sort(int a[], int x, int y);
int main()
{
    int a[6]={1,5,4,2,7,12};

    quick_sort(a,0,5);
    for(int i=0;i<5;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;

}

int partition(int a[], int x, int y)
{
    int pivotkey = a[x];
    while (x < y)
    {
        while (x<y&&a[y] > pivotkey)
            --y;
        a[x] = a[y];
        while (x<y&&a[x] < pivotkey)
            ++x;
        a[y] = a[x];
    }
    a[x] = pivotkey;
    return x;
}

void quick_sort(int a[], int x, int y)
{
    int m = partition(a, x, y);
    if (m - 1 > x)
    {
        quickSort(a, x, m - 1);
    }
    if (m + 1 < y)
    {
        quickSort(a, m + 1, y);
    }
}
//24 27��Ҫȷ��x<y
