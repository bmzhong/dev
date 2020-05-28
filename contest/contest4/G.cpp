#pragma GCC optimize(2)
#include <stdio.h>
#define min(A,B) (A>B ? B:A)
int m, n;
char ch[2000010];
int num[2000010];
int r[2000010];
void manacher() {
    int len = 2 * n + 2;
    int id = 0;
    int mx = 0;
    for (int i = 1; i < len; i++) {
        if (i < mx)
            r[i] = min(r[2 * id - i], mx - i);
        else
            r[i] = 1;

        while (ch[i - r[i]] == ch[i + r[i]])
            r[i]++;
        if (mx < i + r[i]) {
            id = i;
            mx = i + r[i];
        }
    }
}

int main() {
	scanf("%d %d",&n,&m);
    char temp=getchar();
    for (int j = 0; j < m; ++j) {
        ch[0] = '@';
        ch[1] = '#';
        int k = 2;
        for (int i = 0; i < n; ++i) {
            temp = getchar();
            ch[k++] = temp;
            ch[k++] = '#';
        }
        temp=getchar();
        ch[k] = '\0';
        manacher();
        for (int i = 2; i < 2 * n + 2; ++i) {
            for (int v = i - (r[i] - 1); v <= i; ++v) {
                num[v] += (v - (i - (r[i] - 1)) + 1) / 2;
            }
            for (int v = i + 1; v <= i + (r[i] - 1); ++v) {
                num[v] += ((i + (r[i] - 1)) - v + 1) / 2;
            }
        }
    }
    for (int i = 2; i < 2 * n; i += 2) {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[2 * n]); 
    return 0;
}
