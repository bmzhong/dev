#include<iostream>
#include<set>
using namespace std;
int main(){
    int a[5]={3,4,6,1,2};
    set<int> s(a,a+5);
    
    pair<set<int>::iterator,bool> result=s.insert(5);
    if(result.second){
        cout<<*result.first<<endl;
    }
    if(s.insert(5).second){
        cout<<*result.first<<endl;
    }else{
        cout<<"already exist"<<endl;
    }
    pair<set<int>::iterator,set<int>::iterator> p=s.equal_range(4);
    cout<<*p.first<<" "<<*p.second<<endl;
    system("pause");
    return 0;
}