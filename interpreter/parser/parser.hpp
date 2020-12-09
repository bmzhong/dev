#ifndef _THIS_IS_PARSER_HPP
#define _THIS_IS_PARSER_HPP
#include "../lexer/lexer.hpp"
struct ExprNode
{
    Token_Type tokenType=ERRTOKEN;
    ExprNode * left=NULL;
    ExprNode * right=NULL;
    ExprNode * child=NULL;
    FuncPtr funcPtr=NULL;
    double constNumber=0.0;
    double * constParamPtr=NULL;
};
#endif