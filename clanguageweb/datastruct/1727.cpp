#include<iostream>
#include<string>
#include<vector>
#include<ctype.h>
using namespace std;
int main(){
    string str;
    vector<string> v;
    while(getline(cin,str)){
        str[0]=(char)toupper(str[0]);
        for(int i=0;i<str.size()-1;++i){
            if(str[i]==' '||str[i]=='\n'||str[i]=='\t'||str[i]=='\r'){
                str[i+1]=(char)toupper(str[i+1]);
            }            
        }
        v.push_back(str);
    }
    for(auto it:v){
        cout<<it<<endl;
    }
    system("pause");
    return 0;
}