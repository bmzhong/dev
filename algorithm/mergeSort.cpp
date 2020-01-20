#include <iostream>
using namespace std;
void mergesort(int SR[], int TR[], int x, int y);
int main()
{
    int a[] = {49, 38, 65, 97, 76, 13, 27};
    int b[7];
    mergesort(a, b, 0, 6);
    for (int i = 0; i < 7; ++i)
    {
        cout << b[i] << " ";
    }
    system("pause");
    return 0;
}

void mergesort(int SR[], int TR[], int x, int y)
{
    if (x == y)
        TR[x] = SR[y];
    else
    {
        int m = x + (y - x) / 2;
        mergesort(SR, TR, x, m);
        mergesort(SR, TR, m + 1, y);
        int p=x,q=m+1,k=x;
        while(p<=m||q<=y){
            if(q>y||(p<=m&&SR[p]<=SR[q])) TR[k++]=SR[p++];
            else TR[k++]=SR[q++];
        }
        for(k=x;k<=y;++k){
            SR[k]=TR[k];
        }
    }
}