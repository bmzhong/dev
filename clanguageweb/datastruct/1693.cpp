#include <iostream>
using namespace std;
struct A
{
    int row;
    int data;
    int col;
};
struct B
{
    A arr[12500];
    int mu, nu, tu;
};
int main()
{
    int r, c, b;
    scanf("%d %d", &r, &c);
    B m, t;
    m.tu=0,t.tu=0;
    m.nu=c;
    m.mu=r;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            scanf("%d", &b);
            if (b != 0)
            {
                A a;
                a.row = i;
                a.col = j;
                a.data = b;
                m.arr[m.tu] = a;
                ++m.tu;
            }
        }
    }
    t.tu = m.tu;
    t.mu = m.nu;
    t.nu = m.mu;
    int num[m.nu], cpot[m.nu];
    for (int i = 0; i < m.nu; ++i)
    {
        num[i] = 0;
    }
    for (int i = 0; i < m.tu; ++i)
    {
        ++num[m.arr[i].col];
    }
    cpot[0] = 0;
    for (int i = 1; i < m.nu; ++i)
    {
        cpot[i] = cpot[i - 1] + num[i - 1];
    }
    for (int i = 0; i < m.tu; ++i)
    {
        int j = m.arr[i].col;
        int q = cpot[j];
        t.arr[q].col = m.arr[i].row;
        t.arr[q].data = m.arr[i].data;
        t.arr[q].row = m.arr[i].col;
        ++cpot[j];
    }
    int p = 0;
    for (int i = 0; i < t.mu; ++i)
    {
        for (int j = 0; j < t.nu - 1; ++j)
        {
            if (t.arr[p].data != 0 && t.arr[p].col == j && t.arr[p].row == i)
            {
                printf("%d ", t.arr[p].data);
                ++p;
            }
            else
            {
                printf("0 ");
            }
        }
        if (t.arr[p].data != 0 && t.arr[p].col == t.nu - 1 && t.arr[p].row == i)
        {
            printf("%d\n", t.arr[p].data);
            ++p;
        }else{
            printf("0\n");
        }
    }
    system("pause");
    return 0;
}