#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    priority_queue<int>  p;
    int a;
    while(cin>>a){
        p.push(a);
        for(int i=0;i<9;++i){
            cin>>a;
            p.push(a);
        }
        v.push_back(p.top());
        priority_queue<int> ().swap(p);
    }
    for(auto it:v){
        cout<<"max="<<it<<endl;
    }
    system("pause");
    return 0;
}