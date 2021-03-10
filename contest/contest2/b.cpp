#include <iostream>
using namespace std;
void bs(int a, int b, int c, int &r);
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int r;
    bs(a,b,c,r);
    system("pause");
    return 0;
}

void bs(int a, int b, int c, int &r)
{
    int max = a > b ? a : b;
    max = max > c ? max : c;
    r = max;
    for (int i = max;; ++i)
    {
        if (i % a == 0 && i % b == 0 && i % c == 0)
        {
            r = i;
            break;
        }
    }
    cout << r << endl;
}