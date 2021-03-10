#include <iostream>
#include <set>
#include <map>
using namespace std;
set<int> st;
int p, a[1000001], n;
#define min(x, y) (x) > (y) ? (y) : (x)
void solve();
int main()
{
    scanf("%d", &p);
    for (int i = 1; i <= p; ++i)
    {
        scanf("%d", &a[i]);
        st.insert(a[i]);
    }
    n = st.size();
    solve();
    system("pause");
    return 0;
}
void solve()
{
    map<int, int> mp;
    int cnt = 0;
    int i = 1, j = 1, res = 2147483647 / 2;
    while (true)
    {
        while (j <= p && cnt < n)
        {
            if (mp[a[j++]]++ == 0)
                ++cnt;
        }
        if (cnt < n)
            break;
        res = min(res, j - i);
        if (--mp[a[i++]] == 0)
            --cnt;
    }
    if(res==2147483647 / 2)
        res=0;
    printf("%d\n",res);
}