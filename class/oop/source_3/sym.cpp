#include <map>
#include <string>
using namespace std;

namespace Symbol_table
{

map<string, double> table;
//��ʼ����
void init()
{
    table["pi"] = 3.1415926;
    table["e"] = 2.7172818;
}
//��ӱ���
void add(const string &name, const double &value)
{
    table[name] = value;
}
//��ѯ������ֵ
double select(const string &name)
{
    if (table.find(name) != table.end())
        return table[name];
    return 0;
}
//���±�����ֵ
void update(const string &name, const double &value)
{
    table[name] = value;
}

} // namespace Symbol_table