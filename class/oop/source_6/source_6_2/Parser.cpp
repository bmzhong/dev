/*
 * �ļ�������
 *		   Parser.hpp��غ����ӿڵ�ʵ�֡�
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */
/*
* ת��Ϊ��׺���ʽ�Ĳ��裺
*  1��������������ţ��͵���ջ��Ԫ�أ�ֱ������������
*  2�����������������ջ���ĵ�ǰ������Ƚϡ�����ջ������ջ�������ջ��ֱ��ջ�������
*     �����ȼ������͡����������ţ�ֱ����ջ
*  3����������������ֱ��д����׺���ʽ�
*/

#include "Parser.hpp"

Parser::Parser()
{ //��������������ȼ�
    m["("] = 0;
    m["+"] = 1;
    m["-"] = 1;
    m["*"] = 2;
    m["/"] = 2;
    m[")"] = -1; //')'��ֵ��ʵ������
}
//�����﷨�����ṩ��Exprģ��
basic_node *Parser::constructTree(const char *str)
{
    Lexer lexer = Lexer(str);
    dispatch(lexer); //ת��Ϊ��׺���ʽ
                     /* 
  ������׺���ʽ
  ����ǲ�����������һ���ڵ�parent����
  ջ��ȡ������Ԫ�أ��ȳ�ջ��Ϊparent�������������ջ��Ϊparent����������Ȼ��parent
  ��ջ��ֱ��ɨ�����׺���ʽ��
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
            throw "���ʽ����";
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
            throw("���ʽ����");
            break;
        }
    }
    if (st.size() != 1)
        throw "���ʽ����";
    return st.top(); //����������ĸ��ڵ�
}
//��ȡ��һ���������������������makeSuffix
void Parser::dispatch(Lexer &lexer)
{
    lexer.get_token(); //ȡһ���������������
    switch (lexer.currentToken())
    {
    case Lexer::LP:
    case Lexer::NUMBER:
        Parser::makeSuffix(lexer); //������׺���ʽ
        break;
    case Lexer::MINUS:
        lexer.get_token();
        if (lexer.currentToken() == Lexer::NUMBER)
        {
            lexer.oppositeValue();     //valueֵȡ��
            Parser::makeSuffix(lexer); //������׺���ʽ
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
        break; //�������
    case Lexer::ERROR:
    case Lexer::MUL:
    case Lexer::DIV:
    case Lexer::RP: //��������
        lexer.setToken(Lexer::ERROR);
        throw "���ʽ����";
    default:
        return;
    }
    while (!temp_stack.empty())
    { //��temp_stack��ʣ�µ�Ԫ��ֱ�ӷ���operate��

        suffix.push_back(temp_stack.top());
        temp_stack.pop();
    }
}
//�����׺���ʽ
void Parser::makeSuffix(Lexer &lexer)
{
    while (true)
    { //����ǲ����������to_stack,����Ǳ��������������suffix�С�
        std::stringstream ss;
        std::string text;
        double val;
        int pos;
        Lexer::t_token tok;
        switch (lexer.currentToken())
        {
        case Lexer::NUMBER: //��@�����ڱ�Ǵ˴��ǲ����������ǲ�����

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
        default: //�����ܵ���
            lexer.setToken(Lexer::ERROR);
            return;
        }
        lexer.get_token(); //ȡһ���������������
    }
}
//��������ջ��ջ
void Parser::to_stack(Lexer &lexer, Lexer::t_token tok, int prior1)
{
    Lexer::t_token temp;
    if (tok.tok_txt == ")")
    { //��temp_stack�еĲ���������suffix�У�ֱ������'('
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
        if (tok.tok_txt == "(") //'('ֱ��ѹ��ջ��
            break;
        temp = temp_stack.top();
        int prior2 = m[temp.tok_txt];
        if (prior1 <= prior2)
        { //ch�����ȼ���ջ���ĵͣ��⽫temp_stack��Ԫ�ط���suffix�С�
            temp_stack.pop();
            suffix.push_back(temp);
        }
        else
            break;
    }
    temp_stack.push(tok); //��chѹ��ջ�С�
}