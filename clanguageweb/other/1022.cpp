#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> s;
    int i = 1, sum = 0, coe = 1;
    while (n != 0)
    {
        sum += coe * i;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    system("pause");
    return 0;
}