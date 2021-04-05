#include <iostream>
using namespace std;
int n, k, a[1000], b[1000];
void dfs(int cnt, int s)
{
    if (cnt == k)
    {
        for (int i = 0; i < k; ++i)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = s; i < n; ++i)
        {
            b[cnt] = a[i];
            dfs(cnt + 1, i + 1);
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        a[i] = i + 1;
    }
    dfs(0, 0);
    system("pause");
    return 0;
}