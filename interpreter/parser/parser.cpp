#include "parser.hpp"
#include "../error/error.cpp"

void program();
void statement();
void originStatement();
void scaleStatement();
void rotStatement();
void forStatement();
ExprNode *expression();
ExprNode *term();
ExprNode *factor();
ExprNode *component();
ExprNode *atom();

Token currToken;
double parameter;

void fetchToken()
{
    currToken = getToken();
    if (currToken.type == ERRTOKEN)
        parserError1(currToken.where.row, currToken.where.col);
}

void matchToken(Token_Type theTokenType)
{
    if (currToken.type != theTokenType)
        parserError2(currToken.lexeme, currToken.where.row, currToken.where.col);
    fetchToken();
}

ExprNode *makeBinaryNode(Token_Type theTokenType, ExprNode *left, ExprNode *right)
{
    ExprNode *parent = new ExprNode();
    parent->left = left;
    parent->right = right;
    parent->tokenType = theTokenType;
    return parent;
}

ExprNode *makeFuncNode(Token_Type theTokenType, FuncPtr funcPtr, ExprNode *child)
{
    ExprNode *parent = new ExprNode();
    parent->child = child;
    parent->funcPtr = funcPtr;
    return parent;
}

ExprNode *makeConstNumberNode(Token_Type theTokenType, double value)
{
    ExprNode *leafNode = new ExprNode();
    leafNode->constNumber = value;
    return leafNode;
}

ExprNode *makeConstParamNode(Token_Type theTokenType, double *valuePtr)
{
    ExprNode *leafNode = new ExprNode();
    leafNode->constParamPtr = valuePtr;
    return leafNode;
}

void program()
{
    if (currToken.type == NONTOKEN)
        return;
    statement();
    matchToken(SEMICO);
    program();
}

void statement()
{
    switch (currToken.type)
    {
    case ORIGIN:
        originStatement();
        break;
    case SCALE:
        scaleStatement();
        break;
    case ROT:
        scaleStatement();
        break;
    case FOR:
        forStatement();
        break;
    default:
        parserError2(currToken.lexeme, currToken.where.row, currToken.where.col);
    }
}

void originStatement()
{
    matchToken(ORIGIN);
    matchToken(IS);
    matchToken(L_BRACKET);
    expression();
    matchToken(COMMA);
    expression();
    matchToken(R_BRACKET);
}

void scaleStatement()
{
    matchToken(SCALE);
    matchToken(IS);
    matchToken(L_BRACKET);
    expression();
    matchToken(COMMA);
    expression();
    matchToken(R_BRACKET);
}

void rotStatement()
{
    matchToken(ROT);
    matchToken(IS);
    expression();
}

void forStatement()
{
    matchToken(FOR);
    matchToken(T);
    matchToken(FROM);
    expression();
    matchToken(TO);
    expression();
    matchToken(STEP);
    expression();
    matchToken(DRAW);
    matchToken(L_BRACKET);
    expression();
    matchToken(COMMA);
    expression();
    matchToken(R_BRACKET);
}

ExprNode *expression()
{
    ExprNode *left, *right;
    Token_Type theTokeType;
    left = term();
    while (currToken.type == PLUS || currToken.type == MINUS)
    {
        theTokeType = currToken.type;
        matchToken(theTokeType);
        right = term();
    }
}

ExprNode *atom()
{
    ExprNode *thisNode,*childNode;
    Token theToken = currToken;
    switch (currToken.type)
    {
    case CONST_ID:
        matchToken(CONST_ID);
        thisNode = makeConstNumberNode(CONST_ID, currToken.value);
        break;
    case T:
        matchToken(T);
        thisNode = makeConstParamNode(T, &parameter);
        break;
    case FUNC:
        matchToken(FUNC);
        matchToken(L_BRACKET);

    }
}