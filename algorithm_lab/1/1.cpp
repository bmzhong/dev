#include <iostream>
using namespace std;
const int maxn = 10000;
int s[maxn], t[maxn], n, x;
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
}
void merge_sort(int l, int r)
{
    if (r > l)
    {
        int m = (l + r) / 2;
        merge_sort(l, m);
        merge_sort(m + 1, r);
        int i = l, j = m + 1, k = l;
        while (i <= m && j <= r)
        {
            if (s[i] <= s[j])
                t[k++] = s[i++];
            else
                t[k++] = s[j++];
        }
        while (i <= m)
            t[k++] = s[i++];
        while (j <= m)
            t[k++] = s[j++];
        k = l;
    }
}