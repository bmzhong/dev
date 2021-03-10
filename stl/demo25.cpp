#include <iostream>
#include <set>
using namespace std;
struct A
{
    bool operator () (int a,int b){
        return a>b;
    }
};
int main()
{
    set<int, A> s;//不是set<int,A()> s;
}