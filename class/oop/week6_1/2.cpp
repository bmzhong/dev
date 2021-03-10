#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

template<typename T>
class A
{
public:
    vector<T> v;
    A(vector<T> _v){
        v=_v;
    }
};
int main()
{
    vector<int> k = {11, 2, 5, 5, 45};
    A<int> a(k);
    sort(a.v.begin(),a.v.end());
    system("pause");
    return 0;
}