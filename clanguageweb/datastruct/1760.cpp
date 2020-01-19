#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int k=str.length();
    if(k%2==0){
        cout<<"NO"<<endl;
    }else{
        string str1=str.substr(0,(k-1)/2);
        string str2=str.substr((k-1)/2+1);
        reverse(str2.begin(),str2.end());
        if(str1==str2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    system("pause");
    return 0;
}