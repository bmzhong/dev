/*
 * 文件描述：
 *		   从命令行输入参数，输出"Hello,name!"
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/19
 *
 */
#include<iostream>
using namespace std;
int main(int argc,char * argv[]){
    if(argc<=1)
        return 0;
    for(int i=1;i<=argc;++i){
        cout<<"Hello,"<<argv[i]<<"!"<<endl;
    }
    system("pause");
    return 0;
}