#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a;
    map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        ++m[a];
    }
    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
    system("pause");
    return 0;
}