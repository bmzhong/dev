/*
 * 文件描述：实现符号表（symbol table）
 *		   
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/11
 *
 */
#include <map>
#include <string>
using namespace std;

namespace Symbol_table
{

map<string, double> table;
//初始化表
void init()
{
    table["pi"] = 3.1415926;
    table["e"] = 2.7172818;
}
//添加变量
void add(const string &name, const double &value)
{
    table[name] = value;
}
//查询变量的值
double select(const string &name)
{
    if (table.find(name) != table.end())
        return table[name];
    return 0;
}
//更新变量的值
void update(const string &name, const double &value)
{
    table[name] = value;
}

} // namespace Symbol_table