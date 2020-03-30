#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class IntSet
{
public:
    vector<T> v;

    IntSet(){};

    IntSet(vector<T> _v)
    {
        v = _v;
    }

    void _set_sort(IntSet &s);

    template <typename U>
    friend ostream &operator<<(ostream &os, const IntSet<U> &s);

    void _set_union(IntSet &s0, IntSet s1, IntSet s2);

    void _set_intersection(IntSet &s0, IntSet s1, IntSet s2);

    void _set_symmetric_difference(IntSet &s0, IntSet s1, IntSet s2);
};

template <typename T>
void _set_sort(IntSet<T> &s)
{
    sort(s.v.begin(), s.v.end());
}
//合并的规则是：若元素e在s1中出现n1次，在s2中出现n2次，则在s0中出现max(n1,n2)次。
template <typename T>
void _set_union(IntSet<T> &s0, IntSet<T> s1, IntSet<T> s2)
{
    vector<T>().swap(s0.v); //将s0.v的capacity置0，防止空间浪费
    _set_sort(s1);
    _set_sort(s2);
    //用两个有序的序列归并到s0.v中。
    int len1 = s1.v.size();
    int len2 = s2.v.size();
    int i = 0, j = 0;
    while (i < len1 || j < len2)
    {
        if (j >= len2 || i < len1 && s1.v[i] < s2.v[j])
            s0.v.push_back(s1.v[i++]); //将s1中的元素放入s0.v中。
        else if (i < len1 && s1.v[i] == s2.v[j])
        { //将s1.v和s2.v中相同元素放入s0.v中。放入max(n1,n2)个，
            T temp = s1.v[i];
            int count1 = 0, count2 = 0;
            while (j < len2 && temp == s2.v[j])
            {
                ++count1;
                ++j;
            }
            while (i < len2 && temp == s1.v[i])
            {
                ++count2;
                ++i;
            }
            for (int k = 0; k < count1 || k < count2; ++k)
            {
                s0.v.push_back(temp);
            }
        }
        else
            s0.v.push_back(s2.v[j++]); //将s2中的元素放入s0.v中。
    }
}
//若元素e在s1.v中出现n1次，在s2.v中出现n2次，则在s0.v中出现min(n1,n2)次。
template <typename T>
void _set_intersection(IntSet<T> &s0, IntSet<T> s1, IntSet<T> s2)
{
    vector<T>().swap(s0.v); //将s0.v的capacity置0，防止空间浪费
    _set_sort(s1);
    _set_sort(s2);
    //用两个有序的序列的交集归并到s0.v中。
    int len1 = s1.v.size();
    int len2 = s2.v.size();
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (s1.v[i] < s2.v[j])
            ++i;
        else if (s2.v[j] < s1.v[i])
            ++j;
        else
        { //元素相同，放入s0.v中
            s0.v.push_back(s1.v[i++]);
            ++j;
        }
    }
}
//若元素e在s1.v中出现n1次，在s2.v中出现n2次，则在s0.v中出现|n1-n2|次。
template <typename T>
void _set_symmetric_difference(IntSet<T> &s0, IntSet<T> s1, IntSet<T> s2)
{
    vector<T>().swap(s0.v); //将s1中的元素放入s0.v中。
    _set_sort(s1);
    _set_sort(s2);
    //用两个有序的序列的交集归并到s0.v中。
    int len1 = s1.v.size();
    int len2 = s2.v.size();
    int i = 0, j = 0;
    while (i < len1 || j < len2)
    {
        if (j >= len2 || i < len1 && s1.v[i] < s2.v[j])
            s0.v.push_back(s1.v[i++]);
        else if (i < len1 && s1.v[i] == s2.v[j])
        {//将|n1-n2|个e放入s0.v中。 
            T temp = s1.v[i];
            int count1 = 0, count2 = 0;
            while (j < len2 && temp == s2.v[j])
            {
                ++count1;
                ++j;
            }
            while (i < len2 && temp == s1.v[i])
            {
                ++count2;
                ++i;
            }
            int count=count1-count2<0?count2-count1:count1-count2;
            for (int k = 0; k < count; ++k)
            {
                s0.v.push_back(temp);
            }
        }
        else
            s0.v.push_back(s2.v[j++]);
    }
}
template <typename T>
ostream &operator<<(ostream &os, const IntSet<T> &s)
{
    for (T it : s.v)
    {
        os << it << " ";
    }
    os << endl;
    return os;
}

int main()
{

    vector<int> v1 = {1, 2, 3, 3, 3, 3,3, 5, 8, 8}, v2 = {1, 3, 3, 4, 5, 5, 6, 7, 7, 9};

    IntSet<int> s0, s1(v1), s2(v2);

    _set_union(s0, s1, s2);
    cout << "union: \n"<< s0;

    _set_intersection(s0, s1, s2);
    cout << "intersection: \n"<< s0;

    _set_symmetric_difference(s0, s1, s2);
    cout << "symmetric_difference: \n"<< s0;

    system("pause");
    return 0;
}
/*测试结果 ：
v1 = {1, 2, 3, 3, 3, 3,3, 5, 8, 8}, v2 = {1, 3, 3, 4, 5, 5, 6, 7, 7, 9}; 
union:
1 2 3 3 3 3 3 4 5 5 6 7 7 8 8 9
intersection:
1 3 3 5
symmetric_difference:
2 3 3 3 4 5 6 7 7 8 8 9
*/ 
