#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
template <class T>
void print(T first, T last)
{
    for (; first != last; ++first)
    {
        cout << *first << ",";
    }
    cout<<endl;
}
int main()
{
    int a[5] = {4, 5, 3, 1, 2};
    int b[5];
    memcpy(b, a, sizeof(a));
    print(b, b + 5);
    partial_sort(b, b + 3, b + 5);
    print(b,b+5);
    memset(b,0,sizeof(b));
    print(a,a+5);
    partial_sort_copy(a,a+4,b,b+3);
    print(b,b+5);
    int c[8]={4,1,2,6,5,3,7,0};
    nth_element(c,c+3,c+8);
    print(c,c+8); 
    memcpy(b,a,sizeof(a));
    print(b,b+5);
    make_heap(b,b+5);
    print(b,b+5);
    vector<int> v(b,b+5);
    v.push_back(9);
    push_heap(v.begin(),v.end());
    print(v.begin(),v.end());
    pop_heap(v.begin(),v.end());
    print(v.begin(),v.end());
    sort_heap(v.begin(),v.end()-1);
    cout<<*v.rbegin()<<endl;
    print(v.begin(),v.end()-1);
    system("pause");
    return 0;
}