#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string str,str1,str2;
    vector<string> v;
    while(cin>>str1){
        cin>>str2;
        str=str1+str2;
        v.push_back(str);
    }
    for(auto it:v){
        cout<<it<<endl;
    }
    system("pause");
    return 0;
}