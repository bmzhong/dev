#include <iostream>
#include <string>
using namespace std;
int n, g[21][21], ans, c[21], len[21], b[42];
string a[21];
char s;
void dfs(int x, int cnt) 
{
    bool f = false;
    for (int i = 1; i <= n; ++i)
    {
        if (g[x][i] && c[i] < 2)
        {
            f = true;
            ++c[i];
            b[cnt + 1] = i;
            dfs(i, cnt + 1);
            b[cnt + 1] = 0;
            --c[i];
        }
    }
    if (!f)
    {
        int count = 0;
        for (int i = 0; i <= cnt; ++i)
        {
            count += len[b[i]];
        }
        for (int i = 0; i < cnt; ++i)
        {
            count -= g[b[i]][b[i + 1]];
        }
        if (count > ans)
            ans = count;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        len[i] = a[i].size();
    }
    cin >> s;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            string s1 = a[i], s2 = a[j];
            int k = 0;
            if (i == j)
                k = 1;
            for (; k < s1.size(); ++k)
            {
                if (s1[k] == s2[0])
                {
                    int v = k;
                    while (v < s1.size() && v - k < s2.size())
                    {
                        if (s1[v] != s2[v - k])
                            break;
                        ++v;
                    }
                    if (v == s1.size())
                    {
                        if (k == 0 || v - k == s2.size())
                            break;
                        else
                            g[i][j] = s1.size() - k;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][0] == s)
        {
            c[i] = 1;
            b[0] = i;
            dfs(i, 0);
        }
    }
    printf("%d\n", ans); 
    system("pause");
    return 0;
}

//看清楚题目，求的是长度，而不是字符串。
//注意单词有可能自己和自己连接，
//注意数组作为参数传递的情况，
//回溯不需要传递数组，直接用全局数组就可以。
//注意长度不要重复加。
//dfs前，注意一些变量的赋值。
//写代码之前想清楚怎么写。
//不要写错了变量。
//明确各个变量的意义。