#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n,k;
    stack<int> s;
    cin>>n>>k;
    if(n==0){
        cout<<0;
        return 0;
    }
    while(n){
        s.push(n%k);
        n/=k;
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    system("pause");
    return 0;
}