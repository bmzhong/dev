#include <iostream>
#include <vector>
#include<iterator>
#include <algorithm>
#include<list>
#include<cstring>
using namespace std;
bool lessInt (int n){return n<4;}
template<class T>
void print(T first,T last){
    for(;first!=last;++first){
        cout<<*first<<",";
    }
    cout<<endl;
}
int main(){
    int a[5]={1,2,3,2,5};
    int b[6]={1,2,5,2,5,6};
    int c[6]={0,0,0,0,0,0};
    remove_if(b,b+6,lessInt);
    print(b,b+6);
    int *p=remove_copy(a,a+5,c,2);
    print(c,c+6);
    memset(c,0,sizeof(c));
    remove_copy_if(a,a+5,c,lessInt);
    print(c,c+5);
    int d[9]={1,2,2,2,3,3,4};
    vector<int> v;
    v.insert(v.begin(),d,d+7);
    unique(d,d+7);
    print(d,d+7);
    memset(d,0,sizeof(d));
    unique_copy(v.begin(),v.end(),d);
    print(d,d+7);
    system("pause");
    return 0;
}