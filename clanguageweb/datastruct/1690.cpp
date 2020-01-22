#include <iostream>
#include <string>
using namespace std;
void get_next(string str, int next[]);
int main()
{
    string str;
    getline(cin,str);
    int len=str.length();
    int next[len];
    get_next(str,next);
    for(int i=0;i<len;++i){
        cout<<next[i]+1<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}

void get_next(string str, int next[])
{
    int len = str.length();
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len)
    {
        if (j == -1 || str[i] == str[j])
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
