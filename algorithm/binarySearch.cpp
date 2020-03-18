#include <iostream>
using namespace std;
int bisearch(int a[], int x, int y, int v);
int main()
{
    int a[] ={1,2,3,4,5,6,7};
    int v=6;
    cout<<bisearch(a,0,6,v)<<endl;
    system("pause");
    return 0; 
}

int bisearch(int a[], int x, int y, int v)
{
    int i = x, j = y, m;
    while (i < y)
    {
        m = x + (y - x) / 2;
        if (a[m] == v)
            return m;
        else if (a[m] > v)
            y = m - 1;
        else
            x = m + 1;
    }
    return -1;
}