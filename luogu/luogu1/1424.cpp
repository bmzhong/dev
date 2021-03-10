#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, x, sum = 0;
    cin >> x >> n;
    if (n + x > 8)
    {
        int a = 8 - x;
        int b = n - a;
        int c = b / 7;
        sum += 5 * c * 250;
        int d = b - c * 7;
        if (d > 0 && d < 5)
            sum += d * 250;
        else if(d>=5&&d<=7)
            sum += 5 * 250;
    }
    if (x <= 5)
        sum += (6 - x) * 250;
    cout<<sum<<endl;
    system("pause");
    return 0;
}