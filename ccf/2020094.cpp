#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int n, m, boll[100], r, p[2000][100];
double d[2000][2000], db[2000], sum[2000];
inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int main()
{
    n = read();
    m = read();
    r = read();
    for (int i = 0; i < n; ++i)
    {
        boll[i] = read();
    }
    for (int i = 0; i < m; ++i)
    {
        double temp = 0;
        for (int j = 0; j < n; ++j)
        {
            p[i][j] = read();
            temp += (p[i][j] - boll[j]) * (p[i][j] - boll[j]);
        }
        db[i] = sqrt(temp);
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            double temp = 0;
            for (int k = 0; k < n; ++k)
            {
                temp += (p[i][k] - p[j][k]) * (p[i][k] - p[j][k]);
            }
            d[i][j] = sqrt(temp);
            double p = (d[i][j] + db[i] + db[j]) / 2.0;
            double S = sqrt(p * (p - d[i][j]) * (p - db[i]) * (p - db[j]));
            double h = 2.0*S/d[i][j];
            if (h < r)
            {
                int judge1 = (d[i][j] * d[i][j] + db[i] * db[i] - db[j] * db[j]);
                int judge2 = (d[i][j] * d[i][j] + db[j] * db[j] - db[i] * db[i]);
                if (judge1 > 0 && judge2 > 0)
                {
                    double gama = acos((db[i] * db[i] + db[j] * db[j] - d[i][j] * d[i][j]) / (2.0 * db[i] * db[j]));
                    double alpha = acos(r / db[i]) + acos(r / db[j]);
                    double belta = gama - alpha;
                    d[i][j] = belta * r + sqrt(db[i] * db[i] - r * r) + sqrt(db[j] * db[j] - r * r);
                }
            }
            d[j][i] = d[i][j];
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            sum[i] += d[i][j];
        }
        printf("%.14f\n", sum[i]);
    }
    system("pause");
    return 0;
}
