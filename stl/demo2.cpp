#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main(){
    list<int> v={4,1,3,2,6,5,7,8,12};
    list<int>::iterator i;
    for(i=v.begin();i!=v.end();++i){
        cout<<*i<<" ";
    }
    cout<<endl;
    i=v.begin();
    advance(i,6);
    advance(i,-2);
    cout<<*i<<endl;
    cout<<"-----------------"<<endl;
    cout<<distance(v.begin(),i)<<endl;
    iter_swap(v.begin(),i);
    cout<<*v.begin()<<endl;
    system("pause");
    return 0;
}