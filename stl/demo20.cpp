#include<iostream>
#include<algorithm>
#include<ctime>
#include<iterator>
using namespace std;
bool lessInt(int n){return n<4;}
template<class T>
void print(T first,T last){
    for(;first!=last;++first){
        cout<<*first<<",";
    }
    cout<<endl;
}
int main(){
    int a[5]={1,2,3,4,5};
    reverse(a,a+5);
    print(a,a+5);
    int b[5]={0,0,0,0,0};
    reverse_copy(a,a+5,b);
    print(b,b+5);
    print(a,a+5);
    bool result=prev_permutation(a,a+5);
    print(a,a+5);
    result=next_permutation(a,a+5);
    result=next_permutation(a,a+5);
    print(a,a+5);
    srand(time(0));
    random_shuffle(a,a+5);
    print(a,a+5);
    partition(a,a+5,lessInt);
    print(a,a+5);
    stable_partition(a,a+5,lessInt);
    print(a,a+5);
    system("pause");
    return 0;
}