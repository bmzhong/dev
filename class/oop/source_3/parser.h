#ifndef _Parser_
#define _Parser_

#include <string>
#include "lexer.h"

using namespace std;

namespace Parser
{

extern int error_type;//��¼����������еĴ������ͣ��Ա���main������ͳһ����error����

double expr(bool get); //���ʽ������ʼ�Լ�����'+'��'-'���㣨����

double term(bool get); //����'*'��'/'���㣨����

double prim(bool get); //���ʽ�Ļ�����
} // namespace Parser

#endif