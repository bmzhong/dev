#include <iostream>
using namespace std;
void func(int n, int i, long long &sum, long long &last);
int main()
{
    int n;
    cin >> n;
    long long sum = 1;
    long long f = 1;
    func(n, 2, sum, f);
    cout << sum << endl;
    system("pause");
    return 0;
}

void func(int n, int i, long long &sum, long long &last)
{
    if (i > n)
    {
        return;
    }
    else
    {
        last = last * i;
        sum += last;
        ++i;
        func(n, i, sum, last);
    }
}