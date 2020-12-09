#ifndef _THIS_IS_ERROR_HPP
#define _THIS_IS_ERROR_HPP
#include <fstream>
bool initError();

void closeError();

void lexerError(char errorChar,int row,int col);

void parserError1(int row,int col);

void parserError2(char lexeme[],int row,int col);
#endif