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
vector<int> vec[1005]; //���ڼ�¼ÿ��վ����ͨ��վ��,��֪��STL�Ļ�������ά����ͺ���
int vis[1005];         //���ڼ�¼վ���Ƿ���ʹ�
       //���ڼ�¼�ؼ���ĸ���
int success_load = 0;  //���ڼ�¼�ܳɹ������·������
int pass_by[1005];     //���ڼ�¼ȫ���ɹ�·��·��ĳ��Ĵ���
int u, v;              //���,�յ�
int n, m;
void dfs(int now)
{
    vis[now] = 1; //����߹��ĵ�
    if (now == v) //����
    {
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 1)
                pass_by[i]++;
        }
        success_load++;
        vis[now] = 0; //ע�����Զ��յ�����,���������,�´������յ�,��Ϊ����ǹ����߲�������
        return;
    }
    for (int i = 0; i < vec[now].size(); i++)
    {
        if (vis[vec[now][i]] == 0) //���׼���ߵĵ�û�б���ǹ�,��ô��������ȥ
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
        vec[a].push_back(b); //a��b��ͨ�����Խ���aվ����ͨ��վ���������
        vec[b].push_back(a); //��������ͼ��ͬ��bҲ��a��ͨ
    }
    cin >> u >> v; //�������,�յ�
    dfs(u);        //dfs�Ĳ����ǵ�ǰ��λ��,����㿪ʼ�������ʴ�������λ��
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