#include <iostream>
#include <cstdio>
using namespace std;
int s, t, w;
char ch[27];
int find_first();
int main()
{
    scanf("%d%d%d", &s, &t, &w);
    scanf("%s", ch);
    for (int k = 0; k < 5; ++k)
    {
        int pos = find_first();
        if (pos)
        {
            int temp = int(ch[pos]);
            for (int i = pos; i < w; ++i)
            {
                ch[i] = char(temp + i-pos+1);
            }
            printf("%s\n", ch);
        }
        else
        {
            break;
        }
    }
    system("pause");
    return 0;
}

int find_first()
{
    int i;
    for (i = 1; i <= w; ++i)
    {
        if (ch[w - i] != char(t + 'a' - i))
            return w - i;
    }
    return 0;
}