#include <iostream>
using namespace std;
void func(int n, int &sum);
int main()
{
    int n, sum = 1;
    cin >> n;
    func(n,sum);
    cout<<sum<<endl;
    system("pause");
    return 0;
}

void func(int n, int &sum)
{
    for (int i = 1; i <= n / 2; ++i)
    {
        sum++;
        func(i, sum);
    }
}