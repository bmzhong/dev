#include <iostream>
#include <cstring>

using namespace std;
int n, f[1000000], s[1000000];

int mutil(int lenf, int x) {
    int b[3], c[1000] = {0};
    int lenx = x / 10 ? 2 : 1;
    if (lenx == 1)
        b[0] = x;
    else {
        b[0] = x % 10;
        b[1] = x / 10;
    }
    int lenc = lenf + lenx;
    for (int i = 0; i < lenx; ++i) {
        int jw = 0;
        for (int j = 0; j < lenf; ++j) {
            c[i + j] = c[i + j] + jw + b[i] * f[j];
            jw = c[i + j] / 10;
            c[i + j] %= 10;
        }
        c[i + lenf] = jw;
    }
    while (lenc > 1 && !c[lenc - 1])
        --lenc;
    for (int i = 0; i < lenc; ++i) {
        f[i] = c[i];
    }
    return lenc;
}

int main() {
    scanf("%d", &n);
    int lenf = 1, lens = 1;
    s[0] = f[0] = 1;
    for (int i = 2; i <= n; ++i) {
        lenf = mutil(lenf, i);
        int len = lenf > lens ? lenf : lens;
        int jw = 0;
        for (int j = 0; j < len; ++j) {
            s[j] = s[j] + f[j] + jw;
            jw = s[j] / 10;
            s[j] %= 10;
        }
        if (jw) {
            ++len;
            s[len - 1] = 1;
        }
        lens = len;
    }
    for (int i = lens - 1; i >= 0; --i) {
        printf("%d", s[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}