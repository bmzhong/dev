#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
int  main(){
    string str,str1,str2;
    set<string> s;
    vector<set<string>> v;
    while(getline(cin,str1)){
        for(int i=0;i<str1.size();++i){
            str2=str1.substr(i);
            s.insert(str2);
        }
        v.push_back(s);
        s.clear();
    }
    for(auto it:v){
        for(auto it1:it){
            cout<<it1<<endl;
        }            
    }
    system("pause");
    return 0;
}