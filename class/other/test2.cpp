#include <iostream>
using namespace std;
class B;
class B{
public:
    B(){cout<<"B"<<endl;}
    ~B(){cout<<"-B"<<endl;}
};
class A
{
public:
    B b;
    A()
    {
        cout << "A" << endl;
    }
    ~A(){cout<<"-A"<<endl;}
};
B func(B& b){
    return b; 
}
int main(){
    B b;
    B b1=func(b);
    system("pause");
    return 0;
}
