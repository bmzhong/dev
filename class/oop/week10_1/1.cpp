#include <iostream>
using namespace std;

class Base
{
public:
    virtual void iam() { cout << " Base\n "; }
};

class C : public Base
{
public:
    virtual void iam() { cout << " C\n "; }
};

class D : public Base
{
public:
    virtual void iam() { cout << " D\n "; }
};

void f();

void f();
void f();


void f(){
    cout<<"dsd"<<endl;
}

int main()
{
    f();
    Base b;
    C c;
    D d;

    b.iam();
    c.iam();
    d.iam();

    Base *pb = &b;
    Base *pc = &c;
    Base *pd = &d;

    pb->iam();
    pc->iam();
    pd->iam();
    
    system("pause");
    return 0;
}