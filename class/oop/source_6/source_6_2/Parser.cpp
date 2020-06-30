/*
 * 文件描述：
 *		   Parser.hpp相关函数接口的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
/*
* 转换为后缀表达式的步骤：
*  1、如果遇见右括号，就弹出栈中元素，直到遇到左括号
*  2、遇到运算符，则与栈顶的当前运算符比较。高于栈顶则入栈，否则出栈，直到栈顶运算符
*     的优先级比它低。对于左括号，直接入栈
*  3、遇到操作数，则直接写到后缀表达式里。
*/

#include "Parser.hpp"

Parser::Parser()
{ //定义操作符的优先级
    m["("] = 0;
    m["+"] = 1;
    m["-"] = 1;
    m["*"] = 2;
    m["/"] = 2;
    m[")"] = -1; //')'的值无实际意义
}
//构造语法树，提供给Expr模块
basic_node *Parser::constructTree(const char *str)
{
    Lexer lexer = Lexer(str);
    dispatch(lexer); //转换为后缀表达式
                     /* 
  遍历后缀表达式
  如果是操作符，建立一个节点parent，从
  栈中取出两个元素，先出栈的为parent的右子树，后出栈的为parent的左子树，然后将parent
  入栈；直到扫描完后缀表达式。
*/
    std::stack<basic_node *> st;
    for (auto mToken : suffix)
    {
        basic_node *node = nullptr;
        if (mToken.tok_kind == Lexer::NUMBER)
        {
            node = new CNumberNode(mToken);
            st.push(node);
            continue;
        }
        if (st.size() < 2)
            throw "表达式错误";
        basic_node *rightChild = st.top();
        st.pop();
        basic_node *leftChild = st.top();
        st.pop();
        switch (mToken.tok_kind)
        {
        case Lexer::PLUS:
            node = new CPlusNode(mToken, leftChild, rightChild);
            st.push(node);
            break;
        case Lexer::MINUS:
            node = new CMinusNode(mToken, leftChild, rightChild);
            st.push(node);
            break;
        case Lexer::MUL:
            node = new CMulNode(mToken, leftChild, rightChild);
            st.push(node);
            break;
        case Lexer::DIV:
            node = new CDivNode(mToken, leftChild, rightChild);
            st.push(node);
            break;
        default:
            throw("表达式错误");
            break;
        }
    }
    if (st.size() != 1)
        throw "表达式错误";
    return st.top(); //返回这棵树的根节点
}
//读取第一个操作数或操作符并调用makeSuffix
void Parser::dispatch(Lexer &lexer)
{
    lexer.get_token(); //取一个操作数或操作符
    switch (lexer.currentToken())
    {
    case Lexer::LP:
    case Lexer::NUMBER:
        Parser::makeSuffix(lexer); //建立后缀表达式
        break;
    case Lexer::MINUS:
        lexer.get_token();
        if (lexer.currentToken() == Lexer::NUMBER)
        {
            lexer.oppositeValue();     //value值取反
            Parser::makeSuffix(lexer); //建立后缀表达式
        }
        else
        {
            lexer.setToken(Lexer::ERROR);
            return;
        }
        break;
    case Lexer::PLUS:
        lexer.get_token();
        if (lexer.currentToken() == Lexer::NUMBER)
            Parser::makeSuffix(lexer);
        else
        {
            lexer.setToken(Lexer::ERROR);
            return;
        }
        break;
    case Lexer::PRINT:
    case Lexer::END:
        break; //输入结束
    case Lexer::ERROR:
    case Lexer::MUL:
    case Lexer::DIV:
    case Lexer::RP: //错误输入
        lexer.setToken(Lexer::ERROR);
        throw "表达式错误";
    default:
        return;
    }
    while (!temp_stack.empty())
    { //将temp_stack中剩下的元素直接放入operate中

        suffix.push_back(temp_stack.top());
        temp_stack.pop();
    }
}
//构造后缀表达式
void Parser::makeSuffix(Lexer &lexer)
{
    while (true)
    { //如果是操作符则调用to_stack,如果是变量或数字则放入suffix中。
        std::stringstream ss;
        std::string text;
        double val;
        int pos;
        Lexer::t_token tok;
        switch (lexer.currentToken())
        {
        case Lexer::NUMBER: //‘@’用于标记此处是操作数而不是操作符

            val = lexer.getValue();
            ss << val;
            ss >> text;
            ss.clear();
            pos = lexer.getPos();
            tok.tok_kind = Lexer::NUMBER;
            tok.tok_pos = pos;
            tok.tok_txt = text;
            suffix.push_back(tok);
            break;
        case Lexer::LP:
            tok.tok_txt = "(";
            tok.tok_pos = lexer.getPos();
            tok.tok_kind = Lexer::LP;
            to_stack(lexer, tok, 0);
            break;
        case Lexer::PLUS:
            tok.tok_txt = "+";
            tok.tok_pos = lexer.getPos();
            tok.tok_kind = Lexer::PLUS;
            to_stack(lexer, tok, 1);
            break;
        case Lexer::MINUS:
            tok.tok_txt = "-";
            tok.tok_pos = lexer.getPos();
            tok.tok_kind = Lexer::MINUS;
            to_stack(lexer, tok, 1);
            break;
        case Lexer::MUL:
            tok.tok_txt = "*";
            tok.tok_pos = lexer.getPos();
            tok.tok_kind = Lexer::MUL;
            to_stack(lexer, tok, 2);
            break;
        case Lexer::DIV:
            tok.tok_txt = "/";
            tok.tok_pos = lexer.getPos();
            tok.tok_kind = Lexer::DIV;
            to_stack(lexer, tok, 2);
            break;
        case Lexer::RP:
            tok.tok_txt = ")";
            tok.tok_pos = lexer.getPos();
            tok.tok_kind = Lexer::RP;
            to_stack(lexer, tok, -1);
            break;
        case Lexer::END:
        case Lexer::PRINT:
            return;
        default: //不可能到达
            lexer.setToken(Lexer::ERROR);
            return;
        }
        lexer.get_token(); //取一个操作数或操作符
    }
}
//操作符入栈出栈
void Parser::to_stack(Lexer &lexer, Lexer::t_token tok, int prior1)
{
    Lexer::t_token temp;
    if (tok.tok_txt == ")")
    { //将temp_stack中的操作符放入suffix中，直到遇到'('
        while (!temp_stack.empty())
        {
            temp = temp_stack.top();
            if (temp.tok_txt == "(")
            {
                temp_stack.pop();
                break;
            }
            temp_stack.pop();
            suffix.push_back(temp);
        }
        if (temp.tok_txt != "(")
            lexer.setToken(Lexer::ERROR);
        return;
    }
    while (!temp_stack.empty())
    {
        if (tok.tok_txt == "(") //'('直接压入栈中
            break;
        temp = temp_stack.top();
        int prior2 = m[temp.tok_txt];
        if (prior1 <= prior2)
        { //ch的优先级比栈顶的低，这将temp_stack的元素放入suffix中。
            temp_stack.pop();
            suffix.push_back(temp);
        }
        else
            break;
    }
    temp_stack.push(tok); //将ch压入栈中。
}