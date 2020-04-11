#ifndef _Error_
#define _Error_

#include<string>
#include "lexer.h"
#include "parser.h"
using namespace std;

namespace Error{

    extern int no_of_errors;

    double error(const int &rows, const string &s);

    string error_msg(const int &run_type);
}
#endif
