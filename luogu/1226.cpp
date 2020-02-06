#include <iostream>
using namespace std;
int main()
{
    long long b, p, k, ans = 1;
    cin >> b >> p >> k;
    long long b1=b,p1=p;
    while (p)
    {
        if (p & 1)
            ans = (ans * b) % k;
        b = (b * b) % k;
        p>>=1;
    }
    cout<<b1<<"^"<<p1<<" mod "<<k<<"="<<ans<<endl;
    system("pause");
    return 0;
}