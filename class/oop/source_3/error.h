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
