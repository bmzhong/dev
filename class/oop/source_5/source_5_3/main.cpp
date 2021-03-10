#include "Ptr_to_T.cpp"
#include <iostream>
using namespace std;
struct A
{
    int m1;
    int m2;
    A(int _a, int _b) : m1(_a), m2(_b) {}
    A() = default;
};
int main()
{
    int arr[6] = {1, 2, 3, 4};
    Ptr_to_T<int> parr(arr, &arr[0], 6);
    for (int i = 0; i < 6; ++i)
    {
        cout << *parr << " ";
        ++parr;
    }
    cout << endl;

    parr--;
    parr--;
    parr--;
    *parr = 100;
    cout << *parr.operator->() << endl;

    A a[5] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {0, 0}};
    Ptr_to_T<A> pa(a, &a[0], 5);
    pa->m1 = -1;
    pa->m2 = -2;
    pa.operator++(1);
    pa.operator++();
    pa.operator--();
    pa.operator->()->m1=1111;
    for(int i=0;i<10;++i){
        cout<<"("<<(*pa).m1<<","<<(*pa).m2<<")    ";
        ++pa;
    }
    cout<<endl;
    system("pause");
    return 0;
}