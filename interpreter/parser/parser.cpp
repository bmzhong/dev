#include "../lexer/lexer.cpp"
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

void initParser(string filename);

void closeParser();

void parserPrint(string msg);

void parserPrint(const char *msg);

void back(string msg);

void enter(string msg);

void matchToken(Token_Type theTokenType);

void fetchToken();

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
    return parent;
}

ExprNode *makeConstNumberNode(Token_Type theTokenType, double value) {
    ExprNode *leafNode = new ExprNode();
    leafNode->constNumber = value;
    return leafNode;
}

ExprNode *makeConstParamNode(Token_Type theTokenType, double *valuePtr) {
    ExprNode *leafNode = new ExprNode();
    leafNode->constParamPtr = valuePtr;
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
    enter("originStatement");
    matchToken(ORIGIN);
    matchToken(IS);
    matchToken(L_BRACKET);
    expression();
    matchToken(COMMA);
    expression();
    matchToken(R_BRACKET);
    back("originStatement");
}

void scaleStatement() {
    enter("scaleStatement");
    matchToken(SCALE);
    matchToken(IS);
    matchToken(L_BRACKET);
    expression();
    matchToken(COMMA);
    expression();
    matchToken(R_BRACKET);
    back("scaleStatement");
}

void rotStatement() {
    enter("rotStatement");
    matchToken(ROT);
    matchToken(IS);
    expression();
    back("rotStatement");
}

void forStatement() {
    enter("forStatement");
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
    back("forStatement");
}

ExprNode *expression() {
    enter("expression");
    ExprNode *left, *right, *thisNode;
    Token_Type tempTokeType;
    left = term();
    while (currToken.type == PLUS || currToken.type == MINUS) {
        tempTokeType = currToken.type;
        matchToken(currToken.type);
        right = term();
        left = makeBinaryNode(tempTokeType, left, right);
    }
    back("expression");
    return thisNode = left;
}

ExprNode *term() {
    ExprNode *thisNode, *left, *right;
    Token_Type tempTokenType;
    left = factor();
    while (currToken.type == MUL || currToken.type == DIV) {
        tempTokenType = currToken.type;
        matchToken(currToken.type);
        right = factor();
        left = makeBinaryNode(tempTokenType, left, right);
    }
    return thisNode = left;
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
    ExprNode *thisNode, *left, *right;
    left = atom();
    if (currToken.type == POWER) {
        matchToken(POWER);
        right = component();
        thisNode = makeBinaryNode(POWER, left, right);
    }
    return thisNode;
}

ExprNode *atom() {
    ExprNode *thisNode, *childNode;
    Token tempToken = currToken;
    switch (currToken.type) {
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
            childNode = expression();
            matchToken(R_BRACKET);
            thisNode = makeFuncNode(FUNC, tempToken.funcptr, childNode);
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