#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
string a, b, t1, t2;
string m[7][2];
int ans = 2147483647, n;
void dfs(string s, int cnt)
{
    if (cnt > 10)
        return;
    if (s == b && cnt < ans)
        ans = cnt;
    else
    {
        for (int i = 0; i < n; ++i)
        {
            int k = 0, p = 0;
            while (true)
            {
                p = s.find(m[i][0], k);
                if (p == string::npos)
                    break;
                string temp;
                string t1 = s.substr(0, p);
                string t2 = s.substr(p + m[i][0].size());
                dfs(t1 + m[i][1] + t2, cnt + 1);
                k = p + 1;
            }
        }
    }
}
int main()
{
    cin >> a >> b;
    while (cin >> t1 >> t2)
    {
        m[n][0] = t1;
        m[n++][1] = t2;
    }
    dfs(a, 0);
    if (ans == 2147483647)
        printf("NO ANSWER!\n");
    else
        printf("%d\n", ans);
    system("pause");
    return 0;
}
