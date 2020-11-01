#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 505;
int Q, M, N, S, u, v, type[maxn], s_len, len[maxn], pf[maxn];
int topo[maxn], in[maxn], res[10005][maxn], level[10005];
queue<int> que, tue;
struct A
{
    int dir, id;
};
vector<A> node[maxn];
vector<int> G[maxn];
string func;
bool topo_sort()
{
    for (int i = 1; i <= N; ++i)
    {
        if (!in[i])
            que.push(i);
    }
    while (!que.empty())
    {
        u = que.front();
        que.pop();
        tue.push(u);
        int length = G[u].size();
        for (int i = 0; i < length; ++i)
        {
            v = G[u][i];
            --in[v];
            if (!in[v])
                que.push(v);
        }
    }
    if (tue.size() != N){
        while (!tue.empty())
            tue.pop();
        return false;
    }
    int i = 1;
    while (!tue.empty())
    {
        topo[i++] = tue.front();
        tue.pop();
    }
    return true;
}
int main()
{
    cin >> Q;
    A a;
    char c;
    for (int w = 0; w < Q; ++w)
    {
        cin >> M >> N;
        for (int i = 1; i <= N; ++i)
        {
            cin >> func;
            if (func == "NOT")
                type[i] = 1;
            else if (func == "AND")
                type[i] = 2;
            else if (func == "OR")
                type[i] = 3;
            else if (func == "XOR")
                type[i] = 4;
            else if (func == "NAND")
                type[i] = 5;
            else if (func == "NOR")
                type[i] = 6;
            cin >> len[i];
            for (int j = 0; j < len[i]; ++j)
            {
                cin >> c >> a.id;
                if (c == 'I')
                    a.dir = 1;
                else
                {
                    a.dir = 0;
                    G[a.id].push_back(i);
                    ++in[i];
                }
                node[i].push_back(a);
            }
        }
        bool judge = topo_sort();
        cin >> S;
        for (int i = 1; i <= S; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                cin >> level[j];
            }
            if (judge)
            {
                for (int k = 1; k <= N; ++k)
                {
                    u = topo[k];
                    int or1 = 0, and1 = 1, object1 = 0, xor1 = 0;
                    for (int j = 0; j < len[u]; ++j)
                    {
                        a = node[u][j];
                        if (a.dir)
                        {
                            or1 = (or1 | level[a.id]);
                            and1 = (and1 & level[a.id]);
                            object1 = !level[a.id];
                            xor1 = (xor1 ^ level[a.id]);
                        }
                        else
                        {
                            or1 = (or1 | res[i][a.id]);
                            and1 = (and1 & res[i][a.id]);
                            object1 = !res[a.id];
                            xor1 = (xor1 ^ res[i][a.id]);
                        }
                    }
                    switch (type[u])
                    {
                    case 1:
                        res[i][u] = object1;
                        break;
                    case 2:
                        res[i][u] = and1;
                        break;
                    case 3:
                        res[i][u] = or1;
                        break;
                    case 4:
                        res[i][u] = xor1;
                        break;
                    case 5:
                        res[i][u] = !and1;
                        break;
                    case 6:
                        res[i][u] = !or1;
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= S; ++i)
        {
            cin >> s_len;
            for (int j = 1; j <= s_len; ++j)
            {
                cin >> u;
                pf[j] = res[i][u];
            }
            if (judge)
            {
                for (int j = 1; j <= s_len; ++j)
                {
                    printf("%d%c", pf[j], j == s_len ? '\n' : ' ');
                }
            }
        }
        if (!judge)
            printf("LOOP\n");
        for (int i = 1; i <= N; ++i)
        {
            vector<A>().swap(node[i]);
            // node[i].clear();
            G[i].clear();
            vector<int>().swap(G[i]);
            in[i] = 0;
        }
    }
    system("pause");
    return 0;
}