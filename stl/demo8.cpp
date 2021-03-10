#include<iostream>
#include<algorithm>
using namespace std;
template<class T>
void print(T first,T last){
    for(;first!=last;++first){
        cout<<*first<<" ";
    }
    cout<<endl;
}
class A{
    public:
    int n;
    A(int _n):n(_n){}
};

bool operator > (const A &a1,const A &a2){
    return a1.n>a2.n;
}

bool operator < (const A &a1,const A &a2){
    return a1.n<a2.n;
}

bool GreaterA(const A &a1,const A &a2){
    return a1.n>a2.n;
}


struct LessA{
    bool operator () (const A &a1,const A &a2){
        return (a1.n%10)<(a2.n%10);
    }
};
ostream & operator << (ostream &os,const A & a1 ){
    os<<a1.n<<" ";
    return  os;
}
int main(){
    int a1[]={5,2,4,1};
    A a2[]={13,12,9,8,16};
    sort(a1,a1+4);
    print(a1,a1+4);
    sort(a2,a2+5);
    print(a2,a2+5);
    sort(a2,a2+5,GreaterA);
    print(a2,a2+5);
    sort(a2,a2+5,LessA());
    print(a2,a2+5);
    sort(a2,a2+5,greater<A>());
    print(a2,a2+5);
    system("pause");
    return 0;
}


