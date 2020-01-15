#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v(100);
    for (int i = 0; i < 100; ++i)
    {
        cout << v[i] << " ";
        if (i % 10 == 0)
        {
            cout << endl;
        }
    } //像普通数组一样使用vector容器
    vector<int>::iterator i;
    for (i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    } //用!=比较两个迭代器
    for (i = v.begin(); i < v.end(); ++i)
    {
        cout << *i << " ";
    } //用<比较两个迭代器
    i=v.begin();
    while(i!=v.end()){
        cout << *i << " ";
        i+=2;
    }//随机访问迭代器支持“+=”操作。
    system("pause");
    return 0;
}