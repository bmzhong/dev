#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
void modify(int &n){n*=n;}
int square(int n){return n*n;}
int zero(){return 0;}
int one(){return 1;}
bool even(int n){return !(n%2);}
template<class T>
void print(T first,T last){
    for(;first!=last;++first){
        cout<<*first<<",";
    }
    cout<<endl;
}
int main(){
    int a[6]={1,2,3,4,5,6};
    int b[6];
    copy(a,a+6,b);
    print(b,b+6);
    copy_backward(b,b+4,b+5);
    print(b,b+5);
    list<int> list1(5);
    transform(a,a+5,list1.begin(),square);
    print(list1.begin(),list1.end());
    swap_ranges(list1.begin(),list1.end(),b);
    print(list1.begin(),list1.end());
    fill(b,b+6,0);
    print(b,b+6);
    fill_n(b+2,3,1);
    print(b,b+6);
    copy(a,a+6,b);
    print(b,b+6);
    generate(b,b+6,zero);
    print(b,b+6);
    generate_n(b+1,3,one);
    print(b,b+6);
    replace(b,b+6,1,3);
    print(b,b+6);
    replace_if(b,b+6,even,7);
    print(b,b+6);
    replace_copy(a,a+6,b,3,30);
    print(b,b+6);
    replace_copy_if(a,a+6,b,even,70);
    print(b,b+6);
    system("pause");
    return 0;
}