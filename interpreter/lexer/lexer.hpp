#ifndef _THIS_IS_LEXER_HPP_FILE
#define _THIS_IS_LEXER_HPP_FILE
#include <fstream>
#include <string>

using namespace std;
enum Token_Type
{
    ERRTOKEN, //错误记号
    ORIGIN,
    SCALE,
    ROT,
    IS, //保留字
    TO,
    STEP,
    DRAW,
    FOR,
    FROM, //保留字
    T,    //参数

    SEMICO,
    L_BRACKET,
    R_BRACKET,
    COMMA, //分隔符
    PLUS,
    MINUS,
    MUL,
    DIV,
    POWER,    //运算符
    FUNC,     //函数
    CONST_ID, //常数
    NONTOKEN, //空记号
    COMMENT,  //注释
    ID        //标识符
};

struct position
{
    int row;
    int col;
};

typedef double (*FuncPtr)(double);

#define TOKEN_LEXEME_MAX 20

struct Token
{
    Token_Type type = ERRTOKEN;
    char lexeme[TOKEN_LEXEME_MAX] = "\0";
    double value = 0.0;
    FuncPtr funcptr = NULL;
    position where = {0, 0};
};

bool initLexer(string filename);

Token getToken();

void closeLexer();
#endif
