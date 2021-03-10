/*
 * 本次实验的基本思路：
 * 
 *   1.Lexer模块用于扫描字符串：每次读取一个double类型的数或者操作符，curr_tok保存当前
 *     扫描的状态，number_value保存当前读取的值。
 * 
 *   2.Parser模块用于构建语法树：将字符串转换成后缀表达式，储存后缀表达式的类型和变量为
 *     vector<pair<double, char>> suffix,建立一个Node类型的栈，然后从前往后扫描后缀表
 *     达式，如果是数字则直接建立叶子节点并且入栈，如果是操作符，建立一个节点parent，从
 *     栈中取出两个元素，先出栈的为parent的右子树，后出栈的为parent的左子树，然后将parent
 *     入栈；直到扫描完后缀表达式。最后栈中还剩整棵树的根节点，返回根节点给Expr模块，整个
 *     过程与后缀表达式的计算类似。
 * 
 *   3.Node模块提供语法树的节点类型，私有成员函数midRecursion，preRecursion，postRecursion
 *     分别进行中序、先序、后序遍历，遍历过程中将本节点的数或操作符加入中缀前缀后缀字符串。私有
 *     成员函数caculateByPost用于计算表达式。并提供一组这些函数的公共接口给Expr模块。
 * 
 *   4.Expr模块：构造函数调用Parse模块的相关函数建立语法树，析构函数销毁语法树。成员函数
 *     printMid、printPre、printPost、GetValue调用Node模块的相关函数得到相应的字符串，
 *     并将字符串提供给用户。
 * 
 *   5.异常处理：从异常发生处将错误提示信息不断向上抛出，main函数打印错误信息。 
 *
 */

/*
 * 文件描述：
 *		   main函数，用于测试程序的功能。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
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
        cout << "中缀表达式：";
        ex->printMid();
        cout << "前缀表达式: ";
        ex->printPre();
        cout << "后缀表达式: ";
        ex->printPost();
        cout << "表达式的值: ";
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