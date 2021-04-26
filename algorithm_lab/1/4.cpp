#include <iostream>
#include <string>
using namespace std;
int a[1000], b[1000], m, n, k;
int find_k(int al, int ar, int bl, int br, int k);
int main()
{
    cout << "input " << endl;
    cin >> m >> n >> k;
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    cout << "output " << endl;
    cout << find_k(0, m - 1, 0, n - 1, k) << endl;
    system("pause");
    return 0;
}

int find_k(int al, int ar, int bl, int br, int k)
{
    if (al > ar)
        return b[bl + k - 1];
    if (bl > br)
        return a[al + k - 1];
    int ma = (al + ar) / 2, mb = (bl + br) / 2;
    if (a[ma] >= b[mb])
    {
        if (k <= ma - al + 1 + mb - bl)
            return find_k(al, ar, bl, mb - 1, k);
        else
            return find_k(ma + 1, ar, bl, br, k - (ma - al + 1));
    }
    else
    {
        if (k <= ma - al + 1 + mb - bl)
            return find_k(al, ma - 1, bl, br, k);
        else
            return find_k(al, ar, mb + 1, br, k - (mb - bl + 1));
    }
}
/*
case1:
5 5 3
9 7 5 3 1
10 8 6 4 2

case 2:
6 6 6
6 5 4 3 2 1
12 11 10 9 8 7
*/