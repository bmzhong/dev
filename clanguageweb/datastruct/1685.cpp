#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct A{
    int arr;
    int time;
};
int main(){
    int m,n,a,b,k=0;
    double t=0;
    A c;
    cin>>m>>n;
    vector<A> v;
    vector<queue<A>> q(m);
    vector<int> ti(m);
    for(int i=0;i<n;++i){
        cin>>a>>b;
        c.arr=a;
        c.time=b;
        v.push_back(c);
    }
}

void deal(vector<queue<A>> &q,int a){
    for(auto &it:q){
        while(!it.empty()){
            A c=it.front();
            if(c.arr+c.time>=a){
                it.pop();
            }else{
                break;
            }
        }
    }
}

void select(vector<queue<A>> q,vector<int> &ti){
    int m=q.size();
    for(auto &it:q){
        while()
    }
}