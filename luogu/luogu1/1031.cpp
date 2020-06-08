#include <iostream>
using namespace std;
int a[10002], res, av, n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        av += a[i];
    }
    av /= n;
    for (int i = 1; i <= n - 1; ++i)
    {
        if (a[i] > av)
            a[i + 1] += a[i] - av;
        else if(a[i]<av){
            
        }
    }
}