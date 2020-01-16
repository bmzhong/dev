#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<double> p;
    p.push(3.2);
    p.push(9.8);
    p.push(9.8);
    p.push(5.4);
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;
    priority_queue<double,vector<double>,greater<double>> p1;
    cout<<"-------------------------------------"<<endl;
    p1.push(6.4);
    p1.push(36.1);
    p1.push(2.5);
    p1.push(1.7);
    p1.push(5.8);
    p1.push(6.9);
    while(!p1.empty()){
        cout<<p1.top()<<" ";
        p1.pop();
    }
    system("pause");
    return 0;
}