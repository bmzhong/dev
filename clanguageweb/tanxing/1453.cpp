#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int pos1, pos2;
    int count = 0;
    int n = str1.size();
    for (int i = 0; i < n - 1; ++i)
    {
        if (str1[i] != str2[i] && str1[i + 1] != str2[i + 1]){
            str1[i]=str2[i];
            str1[i+1]=str2[i+1];
            count++;
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
}