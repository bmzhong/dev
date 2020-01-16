#include <iostream>
#include<vector>
#include<numeric>
using namespace std;

template <class T>
void print(T first, T last)
{
    for (; first != last; ++first)
    {
        cout << *first << " ";
    }
    cout << endl;
}

int square(int &total, int value)
{
    return total += value * value;
}

template <class T>
class Sum
{
private:
    T power;
public:
    Sum(T p):power(p){}
    const T operator () (const T &total,const T & value){
        T v=value;
        for(int i=0;i<power-1;++i){
            v=v*value;
        }
        return total +v;
    }
};
int main()
{
    const int size=10;
    int a1[]={1,2,3,4,5,6,7,8,9,10};
    vector<int> v(a1,a1+size);
    print(v.begin(),v.end());
    int result=accumulate(v.begin(),v.end(),0,square);
    cout<<result<<endl;
    result=accumulate(v.begin(),v.end(),0,Sum<int>(3));
    cout<<result<<endl;
    result=accumulate(v.begin(),v.end(),0,Sum<int>(4));
    cout<<result<<endl;
    system("pause");
    return 0;
}