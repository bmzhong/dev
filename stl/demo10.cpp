#include<iostream>
#include<set>
using namespace std;

template<class T>
void print(T first,T last){
    for(;first!=last;++first){
        cout<<*first<<" ";
    }
    cout<<endl;
}

class A{
    private:
    int n;
    public:
    A(int _n):n(_n){}
    friend bool operator < (const A &a1,const A &a2){
        return a1.n<a2.n;
    }
    friend ostream & operator << (ostream &os,const A &a1){
        os<<a1.n<<" ";
        return os;
    }

    friend class MyLess;
};

class MyLess{
    public:
    bool operator () (const A &a1,const A &a2){
        return (a1.n%10)<(a2.n%10);
    }
};
int main(){
    const int size=6;
    A a[size]={4,22,19,8,33,40};
    multiset<A> m;
    m.insert(a,a+size);
    m.insert(22);
    print(m.begin(),m.end());
    cout<<"22   "<<m.count(22)<<endl;
    multiset<A>::iterator it=m.find(19);
    if(it!=m.end()){
        cout<<*it<<endl;
    }
    cout<<*m.lower_bound(22)<<" "<<*m.upper_bound(22)<<endl;
    it=m.erase(m.lower_bound(22),m.upper_bound(22));
    cout<<*it<<endl;//注意it在devc++中会失效。
    print(m.begin(),m.end());
    multiset<A,MyLess> m1;
    m1.insert(a,a+size);
    print(m1.begin(),m1.end());
    system("pause");
    return 0;
}