/*
 * 文件描述：
 *		   Parser.hpp相关函数接口的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/23
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
    m['('] = 0;
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    m[')'] = -1; //')'的值无实际意义
}
//构造语法树，提供给Expr模块
Node *Parser::constructTree(const char *str)
{
    Lexer lexer = Lexer(str);
    dispatch(lexer);//转换为后缀表达式
//  遍历后缀表达式
//  如果是操作符，建立一个节点parent，从
//  栈中取出两个元素，先出栈的为parent的右子树，后出栈的为parent的左子树，然后将parent
//  入栈；直到扫描完后缀表达式。
    std::stack<Node *> st;
    for (auto it : suffix)
    {
        if (it.second == '@')//这个位置是操作数
        {
            Node *node = new Node(Lexer::NUMBER, nullptr, nullptr, it.first);
            st.push(node);
        }
        else//这个位置是操作符
        {
            if (st.size() < 2)
                throw "表达式错误";
            Node *rightChild = st.top();
            st.pop();
            Node *leftChild = st.top();
            st.pop();
            Node *parent = new Node(Lexer::Token_type(it.second), leftChild, rightChild);
            st.push(parent);
        }
    }
    if (st.size() != 1)
        throw "表达式错误";
    return st.top();//返回这棵树的根节点
}
//读取第一个操作数或操作符并调用makeSuffix
void Parser::dispatch(Lexer &lexer)
{
    lexer.get_token();//取一个操作数或操作符
    switch (lexer.currentToken())
    {
    case Lexer::LP:
    case Lexer::NUMBER:
        Parser::makeSuffix(lexer);//建立后缀表达式
        break;
    case Lexer::MINUS:
        lexer.get_token();
        if (lexer.currentToken() == Lexer::NUMBER)
        {
            lexer.oppositeValue();//value值取反
            Parser::makeSuffix(lexer);//建立后缀表达式
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
        suffix.push_back(std::make_pair(0, temp_stack.top()));
        temp_stack.pop();
    }
}
//构造后缀表达式
void Parser::makeSuffix(Lexer &lexer)
{
    while (true)
    { //如果是操作符则调用to_stack,如果是变量或数字则放入suffix中。
        switch (lexer.currentToken())
        {
        case Lexer::NUMBER://‘@’用于标记此处是操作数而不是操作符
            suffix.push_back(std::make_pair(lexer.getValue(), '@'));
            break;
        case Lexer::LP:
            to_stack(lexer, '(', 0);
            break;
        case Lexer::PLUS:
            to_stack(lexer, '+', 1);
            break;
        case Lexer::MINUS:
            to_stack(lexer, '-', 1);
            break;
        case Lexer::MUL:
            to_stack(lexer, '*', 2);
            break;
        case Lexer::DIV:
            to_stack(lexer, '/', 2);
            break;
        case Lexer::RP:
            to_stack(lexer, ')', -1);
            break;
        case Lexer::END:
        case Lexer::PRINT:
            return;
        default://不可能到达
            lexer.setToken(Lexer::ERROR);
            return;
        }
        lexer.get_token();//取一个操作数或操作符
    }
}
//操作符入栈出栈
void Parser::to_stack(Lexer &lexer, char ch, int prior1)
{
    char temp;
    if (ch == ')')
    { //将temp_stack中的操作符放入suffix中，直到遇到'('
        while (!temp_stack.empty())
        {
            temp = temp_stack.top();
            if (temp == '(')
            {
                temp_stack.pop();
                break;
            }
            temp_stack.pop();
            suffix.push_back(std::make_pair(0, temp));
        }
        if (temp != '(')
            lexer.setToken(Lexer::ERROR);
        return;
    }
    while (!temp_stack.empty())
    {
        if (ch == '(') //'('直接压入栈中
            break;
        temp = temp_stack.top();
        int prior2 = m[temp];
        if (prior1 <= prior2)
        { //ch的优先级比栈顶的低，这将temp_stack的元素放入suffix中。
            temp_stack.pop();
            suffix.push_back(std::make_pair(0, temp));
        }
        else
            break;
    }
    temp_stack.push(ch); //将ch压入栈中。
}