#include<iostream>
#include<string>
using namespace std;
int main(){
    pair<int,double> p;
    cout<<p.first<<" "<<p.second<<endl;
    pair<string,int> p1("20",4);
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int,int> p2(pair<char,char>('a','b'));
    cout<<p2.first<<" "<<p2.second<<endl;
    pair<int,string> p3=make_pair(200,"hello");
    cout<<p3.first<<" "<<p3.second<<endl;
    system("pause");
    return 0;
}