#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[11], b[6], c[6], N, x, y, mins = 9999999, r1, r2;
bool visited[11];
void dfs(int n, int k);
int main() {
    int line;
    cin >> line;
    cin.get();
    for (int j = 0; j < line; ++j) {
        N = 0;
        char f;
        mins = 9999999;
        string str;
        getline(cin, str);
        int len = str.size();
        for (int i = 0; i < len; ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                a[N++] = str[i] - '0';
            }
        }
        x = N / 2;
        y = N - x;
        dfs(N, x);
        cout << mins << endl;
    }
    system("pause");
    return 0;
}

void dfs(int n, int k) {
    if (k == 0) {
        sort(b, b + x);
        do {
            int p = 0, v1 = 0, v2 = 0, t = 1;
            if (b[0] == 0 && x > 1)
                continue;
            for (int i = x - 1; i >= 0; --i) {
                v1 += b[i] * t;
                t *= 10;
            }
            for (int i = 0; i < N; ++i) {
                if (!visited[i]) {
                    c[p++] = a[i];
                }
            }
            sort(c, c + y);
            do {
                t = 1, v2 = 0;
                if (c[0] != 0 || (c[0] == 0 && y == 1)) {
                    for (int i = y - 1; i >= 0; --i) {
                        v2 += c[i] * t;
                        t *= 10;
                    }
                } else {
                    continue;
                }
                int r = abs(v2 - v1);
                if (r < mins) {
                    mins = r;
                    r1 = v1, r2 = v2;
                }

            } while (next_permutation(c, c + y));
        } while (next_permutation(b, b + x));
    } else {
        for (int i = k - 1; i <= n - 1; ++i) {
            b[k - 1] = a[i];
            visited[i] = true;
            dfs(i, k - 1);
            visited[i] = false;
        }
    }
}