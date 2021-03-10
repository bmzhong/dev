#include<iostream>
#include<map>
using namespace std;

template<class T1,class T2>
ostream & operator << (ostream &os,const pair<T1,T2> p){
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
}

template<class T>
void print(T first,T  last){
    for(;first!=last;++first){
        cout<<*first<<" ";
    }
    cout<<endl;
}
int main(){
    map<int,double,greater<int> > m;
    pair<map<int,double,greater<int> >::iterator,bool> p=m.insert(map<int,double,greater<int> >::value_type(15,2.7));
    if(!p.second){
        cout<<"already exist"<<endl;
    }
    cout<<m.count(15)<<endl;
    m.insert(make_pair(20,9.3));
    cout<<m[40]<<endl;
    print(m.begin(),m.end());
    m[15]=3.2;
    m[63]=1.84545;
    print(m.begin(),m.end());
    system("pause");
    return 0;
}