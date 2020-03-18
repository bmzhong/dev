#include <iostream>
using namespace std;
void f(int a,int b){

};
int main()
{
    void (*fp)(int, int);
    cout<<(void *)f<<endl;
    cout<<(void *)(&f)<<endl;
    cout<<(void *)(*f)<<endl;
    cout<<"_____________________"<<endl;
    fp=f;
    cout<<(void *)fp<<endl;
    cout<<(void *)&fp<<endl;
    cout<<(void *)*fp<<endl;
    system("pause");
    return 0;
}

