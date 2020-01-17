#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string str;
    int n;
    vector<string> v;
    cin>>n;
    cin.get();
    for(int i=0;i<n;++i){
        getline(cin,str);
        sort(str.begin(),str.end());
        v.push_back(str);
    }
    for(int i=0;i<n;++i){
        cout<<v[i]<<endl;
    }    
    return 0;
}