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
    A arr[10000];
    int cpot[1000] = {0};
    int mu, nu, tu = 0;
};
void select(int &s, int &e,int i,B m);
int main()
{
    int r1, c1, r2, c2, b;
    scanf("%d %d", &r1, &c1);
    B m, t, q;
    m.mu = r1;
    m.nu = c1;
    int f1 = -1;
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c1; ++j)
        {
            scanf("%d", &b);
            if (b != 0)
            {
                A a;
                a.data = b;
                a.col = j;
                a.row = i;
                if (f1 != i)
                {
                    m.cpot[i] = m.tu;
                }
                f1 = i;
                m.arr[m.tu++] = a;
            }
        }
    }
    scanf("%d %d", &r2, &c2);
    t.mu = r2;
    t.nu = c2;
    f1 = -1;
    for (int i = 0; i < r2; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            scanf("%d", &b);
            if (b != 0)
            {
                A a;
                a.data = b;
                a.col = j;
                a.row = i;
                if (f1 != i)
                {
                    t.cpot[i] = t.tu;
                }
                f1 = i;
                t.arr[t.tu++] = a;
            }
        }
    }
    int s,e;
    int i=0;
    while(i<m.tu){
        select(s,e,m.arr[i].row,m);
    }
    system("pause");
    return 0;
}

void select(int &s, int &e,int i,B m)
{
    s = m.cpot[i];
    int pr = i + 1;
    while (m.cpot[pr] == 0)
    {
        ++pr;
    }
    e = m.cpot[pr] - 1;
}