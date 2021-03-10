#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while(cin>>str){
        int len=str.size();
        int s=0;
        for(int i=0;i<len;++i){
            s+=str[i]-'0';
        }
        cout<<s<<endl;
    }
    system("pause");
    return 0;
}