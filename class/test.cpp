// #include <iostream>
// using namespace std;
// int & f(){
//     static int m=3;
//     return m;
// }
// int main()
// {
//     int k=f();
//     k=1;
//     cout<<k<<endl;
//     system("pause");
//     return 0;
// }
#include <iostream>
using namespace std;
class IntArray
{
private:
    int *pa;
    int sz;

public:
    IntArray(int a)
    {
        pa = new int[a];
        sz = a;
    }
    ~IntArray() { delete[] pa; };
    IntArray(IntArray &pt)
    {
        pa = new int[pt.sz];
        pa = pt.pa;
        sz = pt.sz;
    }
    IntArray operator++(int)
    {
        int *pc = new int[sz];
        for (int i = 0; i < sz; i++)
        {
            pc[i] = pa[i];
            pc[i]++;
        }
        pa=pc;
        delete[] pc;
        return *this;
    }
    int *operator[](int a) { return &pa[a]; }
};

int main()
{
    IntArray ia(3), ib(ia);
    int a=3;
    a++;
    for (int i = 0; i < 3; i++)
        *(ia[i]) = i + 5;
    ib++;
    for (int j = 0; j < 3; j++)
        cout << *(ia[j]) << " ";
    cout << endl;
    for (int k = 0; k < 3; k++)
        cout << *(ib[k]) << " ";
    cout << endl;
    cout<<a;
    system("pause");
    return 0;
}