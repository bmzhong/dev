#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class IntSet
{
private:
    vector<int> v;
public:
    IntSet(){}

    

    IntSet(vector<int> _v)
    {
        v = _v;
    }

    void print(){
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    void get_vector(vector<int> &_v){
        // _v.assign(v.begin(),v.end());
        _v=v;
    }

    void _set_sort(IntSet &s);


    void _set_union(IntSet &s0, IntSet s1, IntSet s2);

    void _set_intersection(IntSet &s0, IntSet s1, IntSet s2);

    void _set_symmetric_difference(IntSet &s0, IntSet s1, IntSet s2);
};

// void _set_sort(IntSet &s){

// }
int main(){
    vector<int> v1={1,2,3},v;
    IntSet s(v1);
    s.get_vector(v);
    for(auto it:v){
        cout<<it<<" ";
    }
    v[0]=55;
    s.print();
    system("pause");
    return 0;
}