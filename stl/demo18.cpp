#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
template<class T>
void print(T first,T last){
    for(;first!=last;++first){
        cout<<*first<<",";
    }
    cout<<endl;
}
int main(){
    int a[5]={1,2,3,2,5};
    int b[6]={1,2,3,2,5,6};
    int *p=remove(a,a+5,2);
    print(a,a+3);
    cout<<p-a<<endl;
    vector<int> v(b,b+6);
    remove(v.begin(),v.end(),2);
    print(v.begin(),v.end());
    cout<<v.size()<<endl;
    system("pause");
    return 0;
}