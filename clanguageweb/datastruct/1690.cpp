#include <iostream>
#include <string>
using namespace std;
void get_next(string str, int next[]);
int main()
{
    string str;
    getline(cin,str);
    str.insert(0," ");
    int len=str.length();
    int next[len];
    get_next(str,next);
    for(int i=1;i<len;++i){
        cout<<next[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}

void get_next(string str, int next[])
{
    int len = str.length();
    int i = 1, j = 0;
    next[1] = 0;
    while (i <= len-1)
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
