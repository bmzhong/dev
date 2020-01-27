#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int len1=str1.size();
    int len2=str2.size();
    int len=len1>len2?len2:len1;
    int f=0;
    for(int i=0;i<len;++i){
        if(!(str1[i]==str2[i])){
            cout<<str1[i]-str2[i]<<endl;
            f=1;
            break;
        }
    }
    if(f==0){
        cout<<"0"<<endl;
    }
    system("pause");
    return 0;
}