#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <string>
using namespace std;

enum Token {
    NAME,NUMBER,END,ERROR,PLUS = '+',MINUS = '-',MUL = '*',DIV = '/',PRINT = ';',ASSIGN = '=',LP = '(',RP = ')'
};
const double flag = 6.666666;
stack<char> temp_stack;
stack<double> calcu;
vector<double> number;
vector<char> operate;
map<char, int> m;
map<string, double> table;
Token curr_tok = PRINT;
double number_value = 0;
string string_value;

Token input();
double express_value();
void to_stack(char ch, int prior1);
void suffix();
double caculate();

double dispatch() {
    switch (curr_tok) {
        case NAME:
            if (input() == ASSIGN) {
                table[string_value] = express_value();
                return table[string_value];
            } else {
                cin.putback(curr_tok);
                curr_tok = NAME;
                return express_value();
            }
        case LP:case NUMBER:case MINUS:case PLUS:
            return express_value();
        case PRINT:case END:case ERROR:
            return 0;
        case ASSIGN:case MUL:case DIV:
        case RP:
            curr_tok = ERROR;
            return 0;
        default:
            return 0;
    }
}

double express_value() {
    suffix();
    return caculate();
}

void to_stack(char ch, int prior1) {
    char temp;
    if (ch == ')') {
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
        if (ch == '(')
            break;
        temp = temp_stack.top();
        int prior2 = m[temp];
        if (prior1 <= prior2) {
            temp_stack.pop();
            operate.push_back(temp);
            number.push_back(flag);
        } else {
            break;
        }
    }
    temp_stack.push(ch);
}

void suffix() {
    if (curr_tok == PLUS)
        input();
    if (curr_tok == NUMBER)
        number.push_back(number_value);
    if (curr_tok == NAME)
        number.push_back(table[string_value]);
    if (curr_tok == MINUS) {
        input();
        if (curr_tok == NUMBER)
            number.push_back(-number_value);
        else {
            curr_tok = ERROR;
            return;
        }
    }
    while (true) {
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
    while (!temp_stack.empty()) {
        operate.push_back(temp_stack.top());
        number.push_back(flag);
        temp_stack.pop();
    }
    while (!number.empty()) {
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
    m['('] = 0; m['+'] = 1; m['-'] = 1; m['*'] = 2; m['/'] = 2; m[')'] = -1;
    while (cin) {
        input();
        double result = dispatch();
        if (curr_tok == ERROR)
            cout << "input error" << endl;
        else
            cout << "output:  " << result << endl;
        stack<char>().swap(temp_stack);
        stack<double>().swap(calcu);
        number.clear();
        operate.clear();
    }
    return 0;
}
