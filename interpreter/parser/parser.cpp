#ifndef _THIS_IS_PARSER_CPP
#define _THIS_IS_PARSER_CPP

#include "../lexer/lexer.cpp"
#include "parser.hpp"
#include "../error/error.cpp"
#include <cstdio>
#include "../semantics/semantics.cpp"

#define _SEMANTICS_

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

void initParser(string filename);

void closeParser();

void parserPrint(string msg);

void parserPrint(const char *msg);

void back(string msg);

void enter(string msg);

void matchToken(Token_Type theTokenType);

void fetchToken();

void deleteTree(ExprNode *root);

void printByPreOrder(ExprNode *root, int nodeIndent);


Token currToken;
double parameter;

int indent;
ofstream parserOut;

void parser(string filename) {
    initParser(filename);
    fetchToken();
    program();
    closeParser();
}

void initParser(string filename) {
    if (!initLexer(filename))
        parserError3("initParser error");
    parserOut.open("E:\\clionData\\learnCpp\\interpreter\\parser\\parserLog.txt");
    parameter = 0.0;
    indent = 0;
}

double *getTAddress() {
    return &parameter;
}

void closeParser() {
    closeLexer();
    if (parserOut.is_open()) {
        parserOut.flush();
        parserOut.close();
    }
}

void fetchToken() {
    currToken = getToken();
    if (currToken.type == ERRTOKEN)
        parserError1(currToken.where.row, currToken.where.col);
}

void matchToken(Token_Type theTokenType) {
    if (currToken.type != theTokenType)
        parserError2(currToken.lexeme, currToken.where.row, currToken.where.col);
    fetchToken();
}

ExprNode *makeBinaryNode(Token_Type theTokenType, ExprNode *left, ExprNode *right) {
    ExprNode *parent = new ExprNode();
    parent->left = left;
    parent->right = right;
    parent->tokenType = theTokenType;
    return parent;
}

ExprNode *makeFuncNode(Token_Type theTokenType, FuncPtr funcPtr, ExprNode *child) {
    ExprNode *parent = new ExprNode();
    parent->child = child;
    parent->funcPtr = funcPtr;
    parent->tokenType = theTokenType;
    return parent;
}

ExprNode *makeConstNumberNode(Token_Type theTokenType, double value) {
    ExprNode *leafNode = new ExprNode();
    leafNode->constNumber = value;
    leafNode->tokenType = theTokenType;
    return leafNode;
}

ExprNode *makeConstParamNode(Token_Type theTokenType, double *valuePtr) {
    ExprNode *leafNode = new ExprNode();
    leafNode->constParamPtr = valuePtr;
    leafNode->tokenType = theTokenType;
    return leafNode;
}

void program() {
    enter("program");
    while (currToken.type != NONTOKEN) {
        statement();
        matchToken(SEMICO);
    }
    back("program");
}

void statement() {
    enter("statement");
    switch (currToken.type) {
        case ORIGIN:
            originStatement();
            break;
        case SCALE:
            scaleStatement();
            break;
        case ROT:
            rotStatement();
            break;
        case FOR:
            forStatement();
            break;
        default:
            parserError2(currToken.lexeme, currToken.where.row, currToken.where.col);
    }
    back("statement");
}

void originStatement() {
    ExprNode *originXPtr, *originYPtr;
    enter("originStatement");
    matchToken(ORIGIN);
    matchToken(IS);
    matchToken(L_BRACKET);
    originXPtr = expression();
    printByPreOrder(originXPtr, 0);
    matchToken(COMMA);
    originYPtr = expression();
    printByPreOrder(originYPtr, 0);
    matchToken(R_BRACKET);
    back("originStatement");
#ifdef _SEMANTICS_
    setOrigin(originXPtr, originYPtr);
#endif
    deleteTree(originXPtr);
    deleteTree(originYPtr);
}

void scaleStatement() {
    ExprNode *scaleXPtr, *scaleYPtr;
    enter("scaleStatement");
    matchToken(SCALE);
    matchToken(IS);
    matchToken(L_BRACKET);
    scaleXPtr = expression();
    printByPreOrder(scaleXPtr, 0);
    matchToken(COMMA);
    scaleYPtr = expression();
    printByPreOrder(scaleYPtr, 0);
    matchToken(R_BRACKET);
    back("scaleStatement");
#ifdef _SEMANTICS_
    setScale(scaleXPtr, scaleYPtr);
#endif
    deleteTree(scaleXPtr);
    deleteTree(scaleYPtr);
}

void rotStatement() {
    ExprNode *anglePtr;
    enter("rotStatement");
    matchToken(ROT);
    matchToken(IS);
    anglePtr = expression();
    printByPreOrder(anglePtr, 0);
    back("rotStatement");
#ifdef _SEMANTICS_
    setRotate(anglePtr);
#endif
    deleteTree(anglePtr);
}

void forStatement() {
    ExprNode *start, *end, *step, *dotX, *dotY;
    enter("forStatement");
    matchToken(FOR);
    matchToken(T);
    matchToken(FROM);
    start = expression();
    printByPreOrder(start, 0);
    matchToken(TO);
    end = expression();
    printByPreOrder(end, 0);
    matchToken(STEP);
    step = expression();
    printByPreOrder(step, 0);
    matchToken(DRAW);
    matchToken(L_BRACKET);
    dotX = expression();
    printByPreOrder(dotX, 0);
    matchToken(COMMA);
    dotY = expression();
    printByPreOrder(dotY, 0);
    matchToken(R_BRACKET);
    back("forStatement");
#ifdef _SEMANTICS_
    drawLoop(start, end, step, dotX, dotY);
#endif
    deleteTree(start);
    deleteTree(end);
    deleteTree(step);
    deleteTree(dotX);
    deleteTree(dotY);
}

ExprNode *expression() {
    enter("expression");
    ExprNode *left, *right;
    Token_Type tempTokeType;
    left = term();
    while (currToken.type == PLUS || currToken.type == MINUS) {
        tempTokeType = currToken.type;
        matchToken(currToken.type);
        right = term();
        left = makeBinaryNode(tempTokeType, left, right);
    }
    back("expression");
    return  left;
}

ExprNode *term() {
    ExprNode *left, *right;
    Token_Type tempTokenType;
    left = factor();
    while (currToken.type == MUL || currToken.type == DIV) {
        tempTokenType = currToken.type;
        matchToken(currToken.type);
        right = factor();
        left = makeBinaryNode(tempTokenType, left, right);
    }
    return  left;
}

ExprNode *factor() {
    ExprNode *thisNode, *left, *right;
    if (currToken.type == PLUS) {
        matchToken(currToken.type);
        thisNode = factor();
    } else if (currToken.type == MINUS) {
        matchToken(MINUS);
        right = factor();
        left = new ExprNode();
        left->constNumber = 0.0;
        left->tokenType = CONST_ID;
        thisNode = makeBinaryNode(MINUS, left, right);
    } else {
        thisNode = component();
    }
    return thisNode;
}

ExprNode *component() {
    ExprNode *left, *right;
    left = atom();
    if (currToken.type == POWER) {
        matchToken(POWER);
        right = component();
        left = makeBinaryNode(POWER, left, right);
    }
    return left;
}

ExprNode *atom() {
    ExprNode *thisNode, *childNode;
    Token tempToken = currToken;
    switch (currToken.type) {
        case CONST_ID:
            matchToken(CONST_ID);
            thisNode = makeConstNumberNode(CONST_ID, tempToken.value);
            break;
        case T:
            matchToken(T);
            thisNode = makeConstParamNode(T, &parameter);
            break;
        case FUNC:
            matchToken(FUNC);
            matchToken(L_BRACKET);
            childNode = expression();
            matchToken(R_BRACKET);
            thisNode = makeFuncNode(FUNC, tempToken.funcptr, childNode);
            break;
        case L_BRACKET:
            matchToken(L_BRACKET);
            thisNode=expression();
            matchToken(R_BRACKET);
            break;
        default:
            parserError2(currToken.lexeme, currToken.where.row, currToken.where.col);
    }
    return thisNode;
}

void enter(string msg) {
    for (int i = 0; i < indent; ++i) {
        parserPrint(" ");
    }
    string outMsg = "enter in " + msg + "\n";
    parserPrint(outMsg);
    indent += 2;
}

void back(string msg) {
    indent -= 2;
    for (int i = 0; i < indent; ++i) {
        parserPrint(" ");
    }
    string outMsg = "exit from " + msg + "\n";
    parserPrint(outMsg);
}

void parserPrint(const char *msg) {
    parserOut << msg;
}

void parserPrint(string msg) {
    parserOut << msg;
}

void printByPreOrder(ExprNode *root, int nodeIndent) {
    char ch[40] = {"\0"};
    int len = 0;
    if (NULL == root)
        return;
    for (int i = 0; i < nodeIndent + indent; ++i) {
        parserPrint(" ");
    }
    switch (root->tokenType) {
        case PLUS:
            parserPrint("+\n");
            break;
        case MINUS:
            parserPrint("-\n");
            break;
        case MUL:
            parserPrint("*\n");
            break;
        case DIV:
            parserPrint("/\n");
            break;
        case POWER:
            parserPrint("**\n");
            break;
        case T:
            parserPrint("T\n");
            return;
        case FUNC:
            sprintf(ch, "%p", root->funcPtr);
            len = strlen(ch);
            ch[len] = '\n';
            ch[len + 1] = '\0';
            parserPrint(ch);
            printByPreOrder(root->child, nodeIndent + 2);
            return;
        case CONST_ID:
            sprintf(ch, "%.2f", root->constNumber);
            len = strlen(ch);
            ch[len] = '\n';
            ch[len + 1] = '\0';
            parserPrint(ch);
            break;
        default:
            parserPrint("errorNode");
            return;
    }
    printByPreOrder(root->left, nodeIndent + 2);
    printByPreOrder(root->right, nodeIndent + 2);
}

void deleteTree(ExprNode *root) {
    if (NULL == root)
        return;
    switch (root->tokenType) {
        case PLUS:
        case MINUS:
        case DIV:
        case MUL:
        case POWER:
            deleteTree(root->left);
            deleteTree(root->right);
            break;
        case FUNC:
            deleteTree(root->child);
            break;
    }
    delete root;
}

#endif