#include <iostream>
#include <queue>
using namespace std;
int n, m, p, q;
int sf[100001][2];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int main()
{
    n = read();
    m = read();
    p = read();
    q = read();
    int temp;
    priority_queue<int> pq;
    for (int i = 1; i <= p; ++i)
    {
        temp = read();
        pq.push(temp);
        sf[i][0]=temp;
        sf[i][1]=200001;
    }
    
    system("pause");
    return 0;
}
