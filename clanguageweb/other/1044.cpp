#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<string> s;
    string str;
    for(int i=0;i<3;++i){
        getline(cin,str);
        s.push_back(str);
    }
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();++i){
        cout<<s[i]<<endl;
    }
    system("pause");
    return 0;
}