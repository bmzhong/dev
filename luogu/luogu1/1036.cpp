#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void func(int n, int k, vector<int> &a, vector<int> &b, int &sum);
bool prime(int a);
int main()
{
    int n, k, x;
    vector<int> a, b;
    cin >> n >> k;
    a.resize(n), b.resize(k);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a[i] = x;
    }
    int sum = 0;
    func(n, k, a, b, sum);
    cout<<sum<<endl;
    system("pause");
    return 0;
}

void func(int n, int k, vector<int> &a, vector<int> &b, int &sum)
{
    if (k == 0)
    {
        int c = 0;
        for (int i = 0; i < b.size(); ++i)
        {
            c += b[i];
        }

        if (c % 2 == 1)
        {
            if (prime(c))
                ++sum;
        }
        else if (c == 2)
        {
            ++sum;
        }
    }

    else
    {
        for (int i = k - 1; i < n; ++i)
        {
            b[k - 1] = a[i];
            func(i, k - 1, a, b, sum);
        }
    }
}

bool prime(int a)
{
    int r = int(sqrt(a));
    for (int i = 2; i <= r; ++i)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}