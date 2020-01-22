#include <iostream>
#include <string>
using namespace std;
void get_next(string str, int next[]);
int main()
{
    for (int k = 0; k < 3; ++k)
    {
        string str1, str2;
        cin >> str1 >> str2;
        str1.insert(0, " ");
        str2.insert(0, " ");
        int len1 = str1.length(), len2 = str2.length();
        int next[len2];
        get_next(str2, next);
        int i = 0, j = 0;
        while (i <= len1 - 1 && j <= len2 - 1)
        {
            if (j == 0 || str1[i] == str2[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        if (j > len2 - 1)
        {
            cout << i - (len2 - 1) << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    system("pause");
    return 0;
}

void get_next(string str, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    int len = str.length();
    while (i <= len - 1)
    {
        if (j == 0 || str[i] == str[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}