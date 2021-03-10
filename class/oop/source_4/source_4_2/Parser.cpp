/*
 * �ļ�������
 *		   Parser.hpp��غ����ӿڵ�ʵ�֡�
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/23
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
    m['('] = 0;
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    m[')'] = -1; //')'��ֵ��ʵ������
}
//�����﷨�����ṩ��Exprģ��
Node *Parser::constructTree(const char *str)
{
    Lexer lexer = Lexer(str);
    dispatch(lexer);//ת��Ϊ��׺���ʽ
//  ������׺���ʽ
//  ����ǲ�����������һ���ڵ�parent����
//  ջ��ȡ������Ԫ�أ��ȳ�ջ��Ϊparent�������������ջ��Ϊparent����������Ȼ��parent
//  ��ջ��ֱ��ɨ�����׺���ʽ��
    std::stack<Node *> st;
    for (auto it : suffix)
    {
        if (it.second == '@')//���λ���ǲ�����
        {
            Node *node = new Node(Lexer::NUMBER, nullptr, nullptr, it.first);
            st.push(node);
        }
        else//���λ���ǲ�����
        {
            if (st.size() < 2)
                throw "���ʽ����";
            Node *rightChild = st.top();
            st.pop();
            Node *leftChild = st.top();
            st.pop();
            Node *parent = new Node(Lexer::Token_type(it.second), leftChild, rightChild);
            st.push(parent);
        }
    }
    if (st.size() != 1)
        throw "���ʽ����";
    return st.top();//����������ĸ��ڵ�
}
//��ȡ��һ���������������������makeSuffix
void Parser::dispatch(Lexer &lexer)
{
    lexer.get_token();//ȡһ���������������
    switch (lexer.currentToken())
    {
    case Lexer::LP:
    case Lexer::NUMBER:
        Parser::makeSuffix(lexer);//������׺���ʽ
        break;
    case Lexer::MINUS:
        lexer.get_token();
        if (lexer.currentToken() == Lexer::NUMBER)
        {
            lexer.oppositeValue();//valueֵȡ��
            Parser::makeSuffix(lexer);//������׺���ʽ
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
        suffix.push_back(std::make_pair(0, temp_stack.top()));
        temp_stack.pop();
    }
}
//�����׺���ʽ
void Parser::makeSuffix(Lexer &lexer)
{
    while (true)
    { //����ǲ����������to_stack,����Ǳ��������������suffix�С�
        switch (lexer.currentToken())
        {
        case Lexer::NUMBER://��@�����ڱ�Ǵ˴��ǲ����������ǲ�����
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
        default://�����ܵ���
            lexer.setToken(Lexer::ERROR);
            return;
        }
        lexer.get_token();//ȡһ���������������
    }
}
//��������ջ��ջ
void Parser::to_stack(Lexer &lexer, char ch, int prior1)
{
    char temp;
    if (ch == ')')
    { //��temp_stack�еĲ���������suffix�У�ֱ������'('
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
        if (ch == '(') //'('ֱ��ѹ��ջ��
            break;
        temp = temp_stack.top();
        int prior2 = m[temp];
        if (prior1 <= prior2)
        { //ch�����ȼ���ջ���ĵͣ��⽫temp_stack��Ԫ�ط���suffix�С�
            temp_stack.pop();
            suffix.push_back(std::make_pair(0, temp));
        }
        else
            break;
    }
    temp_stack.push(ch); //��chѹ��ջ�С�
}