#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    cout<<str.length()<<endl;
    for(int i=0;i<str.length();++i){
        cout<<str[i]<<" ";
    }
    cout<<endl;
    for(int i=str.length()-1;i>=0;--i){
        cout<<str[i];
    }
    cout<<endl;
    system("pause");
    return 0;
}