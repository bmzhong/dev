#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
class A
{
private:
    int n;
public:
    A(int _n){n=_n;}
    friend bool operator < (const A &a1,const A &a2);
    friend bool operator == (const A &a1,const A &a2);
    friend ostream & operator << (ostream &os,const A &a1);
};
bool operator < (const A &a1,const A &a2){
    return a1.n<a2.n;
}

bool operator == (const A &a1,const A &a2){
    return a1.n==a2.n;
}

ostream & operator << (ostream &os,const A &a1){
    cout<<a1.n<<" ";
    return os;
}

template<class T>
void print(T first,T last){
    for(;first!=last;++first){
        cout<<*first;
    }
    cout<<endl;
}
main()
{
    A a[]={5,3,2,5,10,2,44,121,11,78,4,1};
    A b[7]={10,30,20,30,30,40,40};
    list<A> list1(a,a+5),list2(b,b+7);
    list1.sort();
    print(list1.begin(),list1.end());
    list1.remove(2);
    print(list1.begin(),list1.end());
    list2.pop_front();
    print(list2.begin(),list2.end());
    list2.unique();
    print(list2.begin(),list2.end());
    list1.merge(list2);
    print(list1.begin(),list1.end());
    print(list2.begin(),list2.end());
    list1.reverse();
    print(list1.begin(),list1.end());
    list2.insert(list2.begin(),a+1,a+9);
    print(list2.begin(),list2.end());
    list<A>::iterator p1,p2,p3;
    print(list1.begin(),list1.end());
    p1=find(list1.begin(),list1.end(),30);
    p2=find(list2.begin(),list2.end(),2);
    p3=find(list2.begin(),list2.end(),121);
    list1.splice(p1,list2,p2,p3);
    print(list1.begin(),list1.end());
    system("pause");
    return 0;
}