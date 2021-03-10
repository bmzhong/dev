// #include <iostream>
// using namespace std;
// int a[1001][1001], n, m;
// int u, v, h = 0;
// void dijstra(int dot);
// bool visited[1001] = {false};
// int weight[1001] = {0};
// int inf = 99999999;
// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < m; ++i)
//     {
//         cin >> u >> v;
//         a[u][v] = 1;
//         a[v][u] = 1;
//     }
//     cin >> u >> v;
//     dijstra(u);
//     if (weight[v] == inf)
//         cout << -1 << endl;
//     else
//         cout << weight[v] - 1 << endl;
//     system("pause");
//     return 0;
// }
// void dijstra(int dot)
// {
//     for (int i = 1; i <= n; ++i)
//     {
//         if (a[dot][i])
//             weight[i] = 1;
//         else
//             weight[i] = inf;
//     }
//     visited[dot] = true;
//     for (int i = 1; i <= n; ++i)
//     {
//         int min = inf;
//         int p;
//         for (int j = 1; j <= n; ++j)
//         {
//             if (!visited[j] && weight[j] < min)
//             {
//                 min = weight[j];
//                 p = j;
//             }
//         }
//         visited[p] = true;
//         for (int j = 1; j <= n; ++j)
//         {
//             if (!a[p][j])
//                 a[p][j] = inf;
//             if (!visited[j] && weight[j] > weight[p] + a[p][j])
//             {
//                 weight[j] = weight[p] + a[p][j];
//             }
//         }
//     }
// }
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> vec[1005]; //用于记录每个站点连通的站点,不知道STL的话看作二维数组就好了
int vis[1005];         //用于记录站点是否访问过
       //用于记录关键点的个数
int success_load = 0;  //用于记录能成功到达的路径条数
int pass_by[1005];     //用于记录全部成功路径路过某点的次数
int u, v;              //起点,终点
int n, m;
void dfs(int now)
{
    vis[now] = 1; //标记走过的点
    if (now == v) //出口
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 1)
                pass_by[i]++;
        }
        success_load++;
        vis[now] = 0; //注意必须对对终点清零,如果不清零,下次再找终点,因为被标记过就走不进来了
        return;
    }
    for (int i = 0; i < vec[now].size(); i++)
    {
        if (vis[vec[now][i]] == 0) //如果准备走的点没有被标记过,那么尝试走下去
        {
            dfs(vec[now][i]);
        }
    }
    vis[now] = 0;
}

int main()
{
    cin >> n >> m;
    int a, b;
    int count = 0;  
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b); //a与b连通，所以将与a站点连通的站点存入数组
        vec[b].push_back(a); //这是无向图，同理b也与a连通
    }
    cin >> u >> v; //读入起点,终点
    dfs(u);        //dfs的参数是当前的位置,从起点开始搜索，故传入起点的位置
    for (int i = 1; i <= n; i++)
    {
        if (pass_by[i] == success_load && i != u && i != v)
            count++;
    }
    if (success_load == 0)
        cout << "-1" << endl;
    else
        cout << count << endl;
    system("pause");
    return 0;
}