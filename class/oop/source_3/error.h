/*
 * 文件描述：错误处理器（error handler）接口
 *		   
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/11
 *
 */
#ifndef _Error_
#define _Error_

#include<string>
#include "lexer.h"
#include "parser.h"
using namespace std;

namespace Error{

    extern int no_of_errors;//全局变量no_of_errors表示错误个数 

    double error(const int &rows, const string &msg);//输出错误信息

    string error_msg(const int &error_type);//根据error_tpye的值返回错误信息
}
#endif
