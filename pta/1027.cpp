#include <iostream>
#include <string>
using namespace std;
void func(int &k, int n);
int main()
{
    int n, k;
    char c;
    cin >> n >> c;
    func(k, n);
    string str;
    int d = 2 * k - 1;
    for (int i = d; i >= 1; i -= 2)
    {
        str.assign(i, c);
        str.insert(0, (d - i) / 2, ' ');
        str.append((d - i) / 2, ' ');
        cout << str << endl;
    }
    for (int i = 3; i <= d; i += 2)
    {
        str.assign(i, c);
        str.insert(0, (d - i) / 2, ' ');
        str.append((d - i) / 2, ' ');
        cout<<str<<endl;
    }
    cout<<n-2*k*k+1<<endl;
    system("pause");
    return 0;
}
void func(int &k, int n)
{
    int i = 1;
    k = 0;
    while ((2 * i * i - 1) <= n)
    {
        ++i;
    }
    k = i - 1;
}
