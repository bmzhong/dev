#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class IntSet
{
private:
    vector<T> v;

public:
    IntSet() {}

    IntSet(vector<T> _v)
    {
        v = _v;
    }

    void get_vector(vector<T> &_v)
    {
        _v.assign(v.begin(), v.end());
    }

    template <typename U>
    friend ostream &operator<<(ostream &os, const IntSet<U> &s);

    void _set_union(IntSet s1, IntSet s2);

    void _set_intersection(IntSet s1, IntSet s2);

    void _set_symmetric_difference(IntSet s1, IntSet s2);
};

template <typename T>
void IntSet<T>::_set_union(IntSet<T> s1, IntSet<T> s2)
{
    vector<T>().swap(this->v); 
    vector<T> v1, v2;
    s1.get_vector(v1);
    s2.get_vector(v2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int len1 = v1.size();
    int len2 = v2.size();
    int i = 0, j = 0;
    while (i < len1 || j < len2)
    {
        if (j >= len2 || i < len1 && v1[i] < v2[j])
            this->v.push_back(v1[i++]);
        else if (i < len1 && v1[i] == v2[j])
        {
            this->v.push_back(v1[i++]);
            ++j;
        }
        else
            this->v.push_back(v2[j++]); 
    }
}

template <typename T>
void IntSet<T>::_set_intersection(IntSet<T> s1, IntSet<T> s2)
{
    vector<T>().swap(this->v); 
    vector<T> v1, v2;
    s1.get_vector(v1);
    s2.get_vector(v2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int len1 = v1.size();
    int len2 = v2.size();
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (v1[i] < v2[j])
            ++i;
        else if (v2[j] < v1[i])
            ++j;
        else
        { 
            this->v.push_back(v1[i++]);
            ++j;
        }
    }
}

template <typename T>
void IntSet<T>::_set_symmetric_difference(IntSet<T> s1, IntSet<T> s2)
{
    vector<T>().swap(this->v); 
    vector<T> v1, v2;
    s1.get_vector(v1);
    s2.get_vector(v2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int len1 = v1.size();
    int len2 = v2.size();
    int i = 0, j = 0;
    while (i < len1 || j < len2)
    {
        if (j >= len2 || i < len1 && v1[i] < v2[j])
            this->v.push_back(v1[i++]);
        else if (i < len1 && v1[i] == v2[j])
        { 
            ++i;
            ++j;
        }
        else
            this->v.push_back(v2[j++]);
    }
}
template <typename T>
ostream &operator<<(ostream &os, IntSet<T> &s)
{
    vector<T> v;
    s.get_vector(v);
    for (T it : v)
    {
        os << it << " ";
    }
    os << endl;
    return os;
}

int main()
{

    vector<int> v1 = {1, 2, 5, 8}, v2 = {1, 2, 3, 4, 5,9};

    IntSet<int> s0, s1(v1), s2(v2);

    s0._set_union(s1, s2);
    cout << "union: " << endl;
    cout << s0;

    s0._set_intersection(s1, s2);
    cout << "intersection: " << endl;
    cout << s0;

    s0._set_symmetric_difference(s1, s2);
    cout << "symmetric_difference: " << endl;
    cout << s0;

    system("pause");
    return 0;
}
/*
v1 = {1, 2, 5, 8}, v2 = {1, 2, 3, 4, 5,9};
union:
1 2 3 4 5 8 9
intersection:
1 2 5
symmetric_difference:
3 4 8 9
*/