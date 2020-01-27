#include <iostream>
using namespace std;
void bs(int &b, int m, int n);
void ys(int &y, int m, int n);
int main()
{
    int m, n;
    int y, b;
    cin>>m>>n;
    ys(y,m,n);
    bs(b,m,n);
    cout<<y<<endl;
    cout<<b<<endl;
    system("pause");
    return 0;
}
void ys(int &y, int m, int n)
{
    int c = m > n ? n : m;
    y=1;
    for (int i = 2; i <= c; ++i)
    {
        if (m % i == 0 && n % i == 0)
        {
            y = i;
        }
    }
}

void bs(int &b, int m, int n)
{
    int a = m > n ? m : n;
    for (int i = a;; ++i)
    {
        if (i % m == 0 && i % n == 0)
        {
            b = i;
            break;
        }
    }
}