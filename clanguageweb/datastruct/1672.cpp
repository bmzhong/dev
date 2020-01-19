#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
void write(vector<vector<char>> &h, int n, int m);
void handle(vector<vector<char>> &h, int &r, int n, int m);
int main()
{
    vector<int> re;
    vector<vector<char>> h;
    int t;
    cin >> t;
    int m, n, r = 0;
    for (int i = 0; i < t; ++i)
    {
        r = 0;
        cin >> n >> m;
        write(h, n, m);
        handle(h, r, n, m);
        re.push_back(r);
    }
    system("pause");
    return 0;
}

void handle(vector<vector<char>> &h, int &r, int n, int m)
{
    r = 0;
    int s = 0, e, flag = 0;
    pair<int, int> p, p1, p2;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (h[i][j] == 'S')
            {
                flag = 1;
                p.first = i;
                p.second = j;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    int d = 0;
    flag = 0;
    stack<pair<int, int>> st;
    st.push(p);
    int i = p.first, j = p.second;
    while (!st.empty())
    {
        flag = 0;
        p2 = p1;
        if (h[i][j] == 'E')
        {
            break;
        }
        else if (h[i][j + 1] == '-' && d != 3)
        {
            ++j;
            p1.first = i;
            p1.second = j;
            st.push(p1);
            flag = 1;
            d = 1;
        }
        else if (h[i + 1][j] == '-' && d != 4)
        {
            ++i;
            p1.first = i;
            p1.second = j;
            st.push(p1);
            flag = 1;
            d = 2;
        }
        else if (h[i][j - 1] == '-' && d != 1)
        {
            --j;
            p1.first = i;
            p1.second = j;
            st.push(p1);
            flag = 1;
            d = 3;
        }
        else if (h[i - 1][j] == '-' && d != 2)
        {
            --i;
            p1.first = i;
            p1.second = j;
            st.push(p1);
            flag = 1;
            d = 4;
        }
        if (flag == 0)
        {
            h[i][j] = '#';
            st.pop();
            if (!st.empty())
            {
                i = st.top().first;
                j = st.top().second;
            }
        }
    }
}

void write(vector<vector<char>> &h, int n, int m)
{
    vector<char> v;

    char a;
    v.assign(m + 2, '#');
    h.push_back(v);
    v.clear();
    for (int j = 0; j < n; ++j)
    {
        v.push_back('#');
        for (int k = 0; k < m; ++k)
        {
            cin >> a;
            v.push_back(a);
        }
        v.push_back('#');
        h.push_back(v);
        v.clear();
    }
    v.assign(m + 2, '#');
    h.push_back(v);
    v.clear();
}