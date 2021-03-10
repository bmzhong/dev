#include <iostream>
using namespace std;
struct A
{
    int row;
    int col;
    int data;
    struct A *pi = NULL;
    struct A *pj = NULL;
};
typedef A *PA;
void disp(PA rhead[], PA chead[], int r, int c);
int main()
{
    int r, c;
    cin >> r >> c;
    PA rhead[r]={NULL}, chead[c]={NULL};
    int b;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> b;
            if (b != 0)
            {
                PA a=new A;
                a->data = b;
                a->row = i;
                a->col = j;
                if (!rhead[i])
                {
                    rhead[i] = a;
                }
                else
                {
                    PA p = rhead[i];
                    while (p->pi)
                    {
                        p = p->pi;
                    }
                    p->pi = a;
                }
                if (!chead[j])
                {
                    chead[j] = a;
                }
                else
                {
                    PA p = chead[j];
                    while (p->pj)
                    {
                        p = p->pj;
                    }
                    p->pj = a;
                }
            }
        }
    }
    disp(rhead, chead, r, c);
    system("pause");
    return 0;
}

void create(PA rhead[], PA chead[], int &r, int &c)
{
}

void disp(PA rhead[], PA chead[], int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        PA p = rhead[i];
        for (int j = 0; j < c; ++j)
        {
            if (p && p->row == i && p->col == j)
            {
                cout << p->data << " ";
                p=p->pi;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
