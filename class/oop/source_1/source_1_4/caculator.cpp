/*
 * �ļ�������
 *		   ������ʵ���˱��ʽ���롢�������غ����������ڲ���ʹ�á�		   
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/03/04
 *
 */

#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <string>
using namespace std;

enum Token {
    NAME,NUMBER,END,ERROR,PLUS = '+',MINUS = '-',MUL = '*',DIV = '/',PRINT = ';',ASSIGN = '=',LP = '(',RP = ')'
};
const double flag = 6.666666;//������������ֱ�ʾ���λ���ǲ�������λ��
stack<char> temp_stack;//����׺���ʽת��Ϊ��׺���ʽ�õ���ʱջ
stack<double> calcu;//�����׺���ʽʱ�������ֵ�ջ
vector<double> number;//�����׺���ʽ�õ�����
vector<char> operate;//�����׺���ʽ�еĲ������õ�����
map<char, int> m;//����������������ȼ��Ķ�Ӧ��ϵ
map<string, double> table;//�����������ֵ
Token curr_tok = PRINT;//���浱ǰ��ת̬
double number_value = 0;//���浱ǰ��ȡ��ֵ
string string_value;//���浱ǰ��ȡ�ı�����

Token input();//���뺯��
double express_value();//����ʽ��ֵ�ĺ���
void to_stack(char ch, int prior1);//������ʱջ���������ŵ���׺���ʽ��
void suffix();//����׺���ʽת���ɺ�׺���ʽ
double caculate();//�����׺���ʽ

double dispatch() {//���ݵ�һ�������ֵ������һ������
    switch (curr_tok) {
        case NAME:
            if (input() == ASSIGN) {//��ֵ���ʽ
                table[string_value] = express_value();
                return table[string_value];
            } else {
                cin.putback(curr_tok);
                curr_tok = NAME;
                return express_value();//������ʽ�����ʽ�к��б���
            }
        case LP:case NUMBER:case MINUS:case PLUS:
            return express_value();//������ʽ
        case PRINT:case END:case ERROR:
            return 0;//�������
        case ASSIGN:case MUL:case DIV:
        case RP://��������
            curr_tok = ERROR;
            return 0;
        default:
            return 0;
    }
}

double express_value() {
    suffix();//��׺���ʽת��׺���ʽ
    return caculate();//�����׺���ʽ
}

void to_stack(char ch, int prior1) {
    char temp;
    if (ch == ')') {//��temp_stack�еĲ���������operate�У�ֱ������'('
        while (!temp_stack.empty()) {
            temp = temp_stack.top();
            if (temp == '(') {
                temp_stack.pop();
                break;
            }
            temp_stack.pop();
            operate.push_back(temp);
            number.push_back(flag);
        }
        if (temp != '(')
            curr_tok = ERROR;
        return;
    }
    while (!temp_stack.empty()) {
        if (ch == '(')//'('ֱ��ѹ��ջ��
            break;
        temp = temp_stack.top();
        int prior2 = m[temp];
        if (prior1 <= prior2) {//ch�����ȼ���ջ���ĵͣ��⽫temp_stack��Ԫ�ط���operate�С�
            temp_stack.pop();
            operate.push_back(temp);
            number.push_back(flag);
        } else {
            break;
        }
    }
    temp_stack.push(ch);//��chѹ��ջ�С�
}

void suffix() {//����׺���ʽת���ɺ�׺���ʽ
    if (curr_tok == PLUS)
        input();
    if (curr_tok == NUMBER)
        number.push_back(number_value);//����ֵ����number��
    if (curr_tok == NAME)
        number.push_back(table[string_value]);//��������ֵ����number�С�
    if (curr_tok == MINUS) {
        input();
        if (curr_tok == NUMBER)
            number.push_back(-number_value);
        else {
            curr_tok = ERROR;
            return;
        }
    }
    while (true) {//����ǲ����������to_stack,����Ǳ��������������number�С�
        input();
        switch (curr_tok) {
            case NUMBER:
                number.push_back(number_value);
                break;
            case NAME:
                number.push_back(table[string_value]);
                break;
            case END:case PRINT:
                return;
            case LP:
                to_stack('(', 0);
                break;
            case PLUS:
                to_stack('+', 1);
                break;
            case MINUS:
                to_stack('-', 1);
                break;
            case MUL:
                to_stack('*', 2);
                break;
            case DIV:
                to_stack('/', 2);
                break;
            case RP:
                to_stack(')', -1);
                break;
        }
    }
}

double caculate() {
    while (!temp_stack.empty()) {//��temp_stack��ʣ�µ�Ԫ��ֱ�ӷ���operate��
        operate.push_back(temp_stack.top());
        number.push_back(flag);//��flag��ʾnumber���λ��Ϊ��������
        temp_stack.pop();
    }
    while (!number.empty()) {//�����numberȡ����flag,��calcuջ�е�����Ԫ��ȡ����
        // ��operate�еĲ��������в������������calcu�У���������֣���ֱ�ӷ���calcu�С�
        double temp = number.front();
        number.erase(number.begin());
        if (temp != flag)
            calcu.push(temp);
        else {
            char ch = operate.front();
            operate.erase(operate.begin());
            double rnum = calcu.top();
            calcu.pop();
            double lnum = calcu.top();
            calcu.pop();
            switch (ch) {
                case '*':
                    calcu.push(lnum * rnum);
                    break;
                case '/':
                    if (rnum == 0) {
                        curr_tok = ERROR;
                        return 0;
                    }
                    calcu.push(lnum * rnum);
                    break;
                case '+':
                    calcu.push(lnum + rnum);
                    break;
                case '-':
                    calcu.push(lnum - rnum);
                    break;
            }
        }
    }
    return calcu.top();
}

Token input() {
    char ch = 0;
    cin.get(ch);
    while (ch != '\n' && isspace(ch)) {
        if (!cin.get(ch))
            return END;
    }
    switch (ch) {
        case 0:
            return END;
        case ';':
        case '\n':
            return curr_tok = PRINT;
        case '*':case '/':case '+':case '-':case '(':case ')':case '=':
            return curr_tok = Token(ch);
        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
        case '.': { //NUMBER
            cin.putback(ch);
            cin >> number_value;
            return curr_tok = NUMBER;
        }
        default: { //NAME(��ĸ��ͷ����ĸ���ִ�)
            if (isalpha(ch)) {
                string_value = ch;
                while (cin.get(ch) && isalnum(ch))
                    string_value.push_back(ch);
                cin.putback(ch);
                return curr_tok = NAME;
            }
            return curr_tok = ERROR;
        }
    }
}

int main() {
    table["pi"] = 3.1415926;
    table["e"] = 2.7172818;
    m['('] = 0; m['+'] = 1; m['-'] = 1; m['*'] = 2; m['/'] = 2; m[')'] = -1;// ')'�����ȼ���ʵ������
    while (cin) {
        input();
        double result = dispatch();
        if (curr_tok == ERROR)
            cout << "input error" << endl;
        else
            cout << "output:  " << result << endl;
        stack<char>().swap(temp_stack);//����Ӧ��stack��vector�ÿ�
        stack<double>().swap(calcu);
        number.clear();
        operate.clear();
    }
    return 0;
}
