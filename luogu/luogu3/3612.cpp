#include <iostream>
#include <string>
using namespace std;
long long n;
string s;
int main()
{
    cin >> s;
    cin >> n;
    int m = s.length();
    long long N = m; //不能写成的int,否则N=N*2会成负数，陷入死循环
    while (N < n)
        N = N * 2;
    while (N > m)
    {
        N /= 2;
        if (n == N + 1)
            --n;
        else
        {
            n = n - (N + 1);
            N = m;
            while (N < n)
                N = N * 2;
        }
    }
    cout << s[n - 1] << endl; //不是s[n],字符串的下标从0开始
    system("pause");
    return 0;
}