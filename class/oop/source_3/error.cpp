#include <string>
#include <iostream>
#include "lexer.h"
using namespace std;

namespace Error
{

int no_of_errors = 0;

double error(const int &rows, const string &s)
{
    no_of_errors++;
    cerr << "error row:" << rows << "   " << s << "\n";
    return 1;
}

string error_msg(const int &error_type)
{
    string error_message=" ";
    if (error_type == 1)
    {
        error_message = "divide by 0";
    }
    if (error_type == 2)
    {
        error_message = ") expected";
    }
    if (error_type == 3)
    {
        error_message = "primary expected";
    }
    return error_message;
}

} // namespace Error
