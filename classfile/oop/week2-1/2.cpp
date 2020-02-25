#include <iostream>
#include <string>
#include <map>
#include <list>
using namespace std;
class My_class
{
    string name;
    int age;
    double score;
    inline void func1(){};
    My_class(string name){};
    ~My_class(){};
    My_class operator++(){return *this;};
};
enum Country
{
    China,
    USA,
    UK
};
int main()
{
    //基本类型
    cout << "char " << sizeof(char) << endl;
    cout << "short int    " << sizeof(short int) << endl;
    cout << "int  " << sizeof(int) << endl;
    cout << "__int64  " << sizeof(__int64) << endl;
    cout << "long int   " << sizeof(long int) << endl;
    cout << "long long int    " << sizeof(long long int) << endl;
    cout << "float    " << sizeof(float) << endl;
    cout << "double" << sizeof(double) << endl;
    cout << "long double" << sizeof(long double) << endl;
    //指针和数组
    cout << "int *" << sizeof(int *) << endl;
    cout << "string *" << sizeof(string *) << endl;
    cout << "double [12]" << sizeof(double[12]) << endl;
    //容器类型和string
    cout << "string   " << sizeof(string) << endl;
    cout << "map<string,double>    " << sizeof(map<string, double>) << endl;
    cout << "list<list<int>>  " << sizeof(list<list<int>>) << endl;
    //类类型和枚举类型
    cout<<"My_class "<<sizeof(My_class)<<endl;
    cout<<"My_class *   "<<sizeof(My_class *)<<endl;
    cout<<"Country  "<<sizeof(Country)<<endl;
    cout<<"Country[12]  "<<sizeof(Country[12])<<endl;
    
    system("pause");
    return 0;
}