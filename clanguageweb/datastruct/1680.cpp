#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int a;
    queue<int> s;
    while(cin>>a){
        while(a!=0){
            int b=a%8;
            s.push(b);
            a/=8;
        }
        int i=1;
        int c=0;
        while(!s.empty()){
            c+=s.front()*i;
            i*=10;
            s.pop();
        }
        v.push_back(c);
    }
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<endl;
    }
    system("pause");
    return 0;
}