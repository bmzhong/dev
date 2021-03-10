/*
 * ����ʵ��Ļ���˼·��
 * 
 *   1.Lexerģ������ɨ���ַ�����ÿ�ζ�ȡһ��double���͵������߲�������curr_tok���浱ǰ
 *     ɨ���״̬��number_value���浱ǰ��ȡ��ֵ��
 * 
 *   2.Parserģ�����ڹ����﷨�������ַ���ת���ɺ�׺���ʽ�������׺���ʽ�����ͺͱ���Ϊ
 *     vector<pair<double, char>> suffix,����һ��Node���͵�ջ��Ȼ���ǰ����ɨ���׺��
 *     ��ʽ�������������ֱ�ӽ���Ҷ�ӽڵ㲢����ջ������ǲ�����������һ���ڵ�parent����
 *     ջ��ȡ������Ԫ�أ��ȳ�ջ��Ϊparent�������������ջ��Ϊparent����������Ȼ��parent
 *     ��ջ��ֱ��ɨ�����׺���ʽ�����ջ�л�ʣ�������ĸ��ڵ㣬���ظ��ڵ��Exprģ�飬����
 *     �������׺���ʽ�ļ������ơ�
 * 
 *   3.Nodeģ���ṩ�﷨���Ľڵ����ͣ�˽�г�Ա����midRecursion��preRecursion��postRecursion
 *     �ֱ�����������򡢺�����������������н����ڵ�����������������׺ǰ׺��׺�ַ�����˽��
 *     ��Ա����caculateByPost���ڼ�����ʽ�����ṩһ����Щ�����Ĺ����ӿڸ�Exprģ�顣
 * 
 *   4.Exprģ�飺���캯������Parseģ�����غ��������﷨�����������������﷨������Ա����
 *     printMid��printPre��printPost��GetValue����Nodeģ�����غ����õ���Ӧ���ַ�����
 *     �����ַ����ṩ���û���
 * 
 *   5.�쳣�������쳣��������������ʾ��Ϣ���������׳���main������ӡ������Ϣ�� 
 *
 */

/*
 * �ļ�������
 *		   main���������ڲ��Գ���Ĺ��ܡ�
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/23
 *
 */

#include "Expr.hpp"
#include <string>


using namespace std;
int main()
{
    string str;
    cin >> str;
    try
    {
        Expr *ex = new Expr(str.c_str());
        cout << "��׺���ʽ��";
        ex->printMid();
        cout << "ǰ׺���ʽ: ";
        ex->printPre();
        cout << "��׺���ʽ: ";
        ex->printPost();
        cout << "���ʽ��ֵ: ";
        cout << ex->getValue() << endl;
        delete ex;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    system("pause");
    return 0;
}