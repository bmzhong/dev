#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
bool lessInt(int n){
    return n <4;
}

template<class T>
void print(T first,T last){
    for(;first!=last;++first){
        cout<<*first<<" ";
    }
    cout<<endl;
}

void printInt(int n){
    cout<<"<"<<n<<">";
}

int main(){
    cout<<"1) "<<min(3,6)<<",  "<<min(2.5,6.3)<<endl;
    int a[10]={1,2,3,4,4,5,6,7,8,9};
    cout<<"2) "<<*min_element(a,a+9)<<", "<<*max_element(a,a+9)<<endl;
    cout<<"3) "<<count(a,a+9,4)<<endl;
    cout<<"4) "<<count_if(a,a+9,lessInt)<<endl;
    list<int> list1(a,a+9);
    int b[2]={4,3};
    vector<int> v(b,b+2);
    list<int>::iterator p;
    p=find_first_of(list1.begin(),list1.end(),b,b+2);
    cout<<"5) "<<*p<<"  "<<distance(list1.begin(),p)<<endl; 
    reverse(v.begin(),v.end());
    int *ptr=find_end(a,a+9,v.begin(),v.end());
    cout<<"6) "<<distance(a,ptr)<<endl;
    p=adjacent_find(list1.begin(),list1.end());
    cout<<"7) "<<*p<<" "<<distance(list1.begin(),p)<<endl;
    cout<<"------------------------------"<<endl;
    print(v.begin(),v.end());
    print(list1.begin(),list1.end());
    p=search(list1.begin(),list1.end(),v.begin(),v.end());
    cout<<"8) "<<distance(list1.begin(),p)<<endl;
    print(a,a+9);
    ptr=search_n(a,a+9,2,4);
    cout<<"9) "<<distance(a,ptr)<<endl;
    cout<<boolalpha;
    cout<<"10) "<<equal(v.begin(),v.end(),a+2)<<endl;
    int c[6]={1,2,3,9,7,8};
    pair<int *,int *> result;
    result=mismatch(c,c+6,a);
    cout<<"11) "<<*result.first<<","<<*result.second<<endl;
    cout<<"12) "<<lexicographical_compare(a,a+10,c,c+6)<<endl;
    for_each(a,a+10,printInt);
    cout<<endl;
    system("pause");
    return 0;
}