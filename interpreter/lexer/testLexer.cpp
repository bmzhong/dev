#include <iostream>
#include <string>
#include "lexer.cpp"
using namespace std;
int main()
{
    string filename="E:\\clionData\\learnCpp\\interpreter\\lexer\\draw1.txt";
    if (!initLexer(filename))
    {
        cout << "error" << endl;
    }
    printf("type        lexeme     value        functionPtr             where\n");
    Token token;
    while(true){
        token=getToken();
        if(token.type!=NONTOKEN)
            printf("%4d %12s %12f %12x \t\t (%4d,%4d) \n",token.type,token.lexeme,token.value,token.funcptr,token.where.row,token.where.col);
        else
            break;
    }
    closeLexer();
    system("pause");
    return 0;
}
