/*
 * 文件描述：
 *		   输入word，创建二叉树，先序中序输出，删除二叉树
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/19
 *
 */
#include <iostream>
#include <string>
#include "btree.cpp"
using namespace Btree;
PNode root = 0; //二叉树的根节点
int main()
{
    string str;//输入的单词
    //将输入的单词存储到树中
    while (cin >> str)
        insert(root, str);
    cout << endl;
    //先序遍历输出
    preOrder(root, 0);
    //中序遍历输出
    midOrder(root);
    //删除树中的所有节点
    delete_tree(root);

    system("pause");
    return 0;
}
