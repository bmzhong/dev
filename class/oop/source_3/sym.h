/*
 * 文件描述：符号表（symbol table）接口
 *		   
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/11
 *
 */
#ifndef _Symbol_table_
#define _Symbol_table_

#include<map>
#include<string>
using namespace std;

namespace Symbol_table{
   
   extern map<string, double> table; //符号表: "常量（变量）名-值" 

   void init();//初始化table

   void add(const string &name,const double &value);//添加变量和值

   double select(const string &name);//查询变量的值

   void update(const string &name,const double &value);//更新变量的值

}

#endif