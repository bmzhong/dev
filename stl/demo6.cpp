#include<iostream>
using namespace std;
class Average{
    public:
     double operator () (int a1,int a2,int a3){
         return (double)(a1+a2+a3)/3;
     }
};
int main(){
    Average a;
    cout<<a(1,4,3)<<endl;
    system("pause");
    return 0;
}