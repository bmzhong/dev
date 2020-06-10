#include <iostream>
#include <cstring>

using namespace std;
int parent[10002], m, n;

void unite(int x, int y);

int find_root(int x);

bool isSame(int x, int y);
void init();

int main()
{
    cin >> n >> m;
    init();
    int t1, t2, t3;
    for (int i = 0; i < m; ++i)
    {
        cin >> t1 >> t2 >> t3;
        if (t1 == 1)
        {
            unite(t2, t3);
        }
        else if (t1 == 2)
        {
            if (isSame(t2, t3))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
    system("pause");
    return 0;
}

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }
}

void unite(int x, int y)
{
    int x_root = find_root(x);
    int y_root = find_root(y);
    if (x_root != y_root)
        parent[x_root] = y_root;
}

// void unite(int x, int y)
// {
//     int x_root = find_root(x);
//     int y_root = find_root(y);
//     if (x_root == y_root)
//         return;
//     if (rank[x_root] < rank[y_root])
//         parent[x_root] = y_root;
//     else
//     {
//         parent[y_root] = x_root;
//         if (rank[x_root] == rank[y_root])
//             ++rank[x_root];
//     }
// }

int find_root(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find_root(parent[x]);
}

bool isSame(int x, int y)
{
    return find_root(x) == find_root(y);
}