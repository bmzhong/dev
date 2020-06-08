#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int a[6][6], b[6], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, x, y;
set<int> s;
void dfs(int step);
int main()
{
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            x=i,y=j;
            dfs(0);
        }
    }
    cout<<s.size()<<endl;
    system("pause");
    return 0;
}

void dfs(int step)
{
    b[step++] = a[x][y];
    pair<int, int> p(x, y);
    if (step > 5)
    {
        int ans = 0, t = 1;
        for (int i = 5; i >= 0; --i)
        {
            ans += b[i] * t;
            t *= 10;
        }
        s.insert(ans);
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        x = p.first + dx[i];
        y = p.second + dy[i];
        if (x >= 1 && x <= 5 && y >= 1 && y <= 5)
        {
            dfs(step);
        }
    }
}