/*
 * 文件描述：
 *		   声明和实现了表达式输入、计算等相关函数，并用于测试使用。		   
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
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
const double flag = 6.666666;//出现了这个数字表示这个位置是操作符的位置
stack<char> temp_stack;//将中缀表达式转换为后缀表达式用的临时栈
stack<double> calcu;//计算后缀表达式时储存数字的栈
vector<double> number;//储存后缀表达式用的向量
vector<char> operate;//储存后缀表达式中的操作符用的向量
map<char, int> m;//储存操作符及其优先级的对应关系
map<string, double> table;//储存变量及其值
Token curr_tok = PRINT;//储存当前的转态
double number_value = 0;//储存当前读取的值
string string_value;//储存当前读取的变量名

Token input();//输入函数
double express_value();//求表达式的值的函数
void to_stack(char ch, int prior1);//利用临时栈将操作符放到后缀表达式中
void suffix();//将中缀表达式转换成后缀表达式
double caculate();//计算后缀表达式

double dispatch() {//根据第一次输入的值决定下一步操作
    switch (curr_tok) {
        case NAME:
            if (input() == ASSIGN) {//赋值表达式
                table[string_value] = express_value();
                return table[string_value];
            } else {
                cin.putback(curr_tok);
                curr_tok = NAME;
                return express_value();//计算表达式，表达式中含有变量
            }
        case LP:case NUMBER:case MINUS:case PLUS:
            return express_value();//计算表达式
        case PRINT:case END:case ERROR:
            return 0;//输入结束
        case ASSIGN:case MUL:case DIV:
        case RP://错误输入
            curr_tok = ERROR;
            return 0;
        default:
            return 0;
    }
}

double express_value() {
    suffix();//中缀表达式转后缀表达式
    return caculate();//计算后缀表达式
}

void to_stack(char ch, int prior1) {
    char temp;
    if (ch == ')') {//将temp_stack中的操作符放入operate中，直到遇到'('
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
        if (ch == '(')//'('直接压入栈中
            break;
        temp = temp_stack.top();
        int prior2 = m[temp];
        if (prior1 <= prior2) {//ch的优先级比栈顶的低，这将temp_stack的元素放入operate中。
            temp_stack.pop();
            operate.push_back(temp);
            number.push_back(flag);
        } else {
            break;
        }
    }
    temp_stack.push(ch);//将ch压入栈中。
}

void suffix() {//将中缀表达式转换成后缀表达式
    if (curr_tok == PLUS)
        input();
    if (curr_tok == NUMBER)
        number.push_back(number_value);//将数值放入number中
    if (curr_tok == NAME)
        number.push_back(table[string_value]);//将变量的值放入number中。
    if (curr_tok == MINUS) {
        input();
        if (curr_tok == NUMBER)
            number.push_back(-number_value);
        else {
            curr_tok = ERROR;
            return;
        }
    }
    while (true) {//如果是操作符则调用to_stack,如果是变量或数字则放入number中。
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
    while (!temp_stack.empty()) {//将temp_stack中剩下的元素直接放入operate中
        operate.push_back(temp_stack.top());
        number.push_back(flag);//用flag表示number这个位置为操作符，
        temp_stack.pop();
    }
    while (!number.empty()) {//如果从number取出是flag,则将calcu栈中的两个元素取出，
        // 用operate中的操作符进行操作，结果放入calcu中，如果是数字，则直接放入calcu中。
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
        default: { //NAME(字母开头的字母数字串)
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
    m['('] = 0; m['+'] = 1; m['-'] = 1; m['*'] = 2; m['/'] = 2; m[')'] = -1;// ')'的优先级无实际意义
    while (cin) {
        input();
        double result = dispatch();
        if (curr_tok == ERROR)
            cout << "input error" << endl;
        else
            cout << "output:  " << result << endl;
        stack<char>().swap(temp_stack);//将相应的stack和vector置空
        stack<double>().swap(calcu);
        number.clear();
        operate.clear();
    }
    return 0;
}
