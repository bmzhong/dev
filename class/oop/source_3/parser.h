#ifndef _Parser_
#define _Parser_

#include <string>
#include "lexer.h"

using namespace std;

namespace Parser
{

extern int error_type;//记录表达计算过程中的错误类型，以便在main函数中统一调用error处理

double expr(bool get); //表达式分析开始以及处理'+'、'-'运算（符）

double term(bool get); //处理'*'、'/'运算（符）

double prim(bool get); //表达式的基本项
} // namespace Parser

#endif