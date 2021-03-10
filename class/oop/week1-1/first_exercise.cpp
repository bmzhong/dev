#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
using namespace std;
map<string, int> m; //将单词作为键放在map中，单词出现的次数作为值，map对string类型默认按字典序排序。
multiset<string> s; //将单词放入multiset中，set会对string类型默认按字典序排序，可储存相同的值。
void read();
void output_to_file();
void output_to_console();
int main()
{
    read();              //将words.txt中的单词读入m,s容器对象内。
    output_to_console(); //将单词及其出现的次数在控制台按单词字典序排序输出，。
    output_to_file();    //将所有单词按字典序排序写入words.txt中。
    return 0;
}

void output_to_console()
{
    map<string, int> m1(m.begin(), m.end());
    while (!m1.empty())
    {
        cout << (*m1.begin()).first << " " << (*m1.begin()).second << endl;
        m1.erase(m1.begin());
    } //依次输出m中的首元素，并删除，以保证最小的元素在首位置。
}

void output_to_file()
{
    ofstream on(R"(E:\dev\classfile\oop\words.txt)");
    if (!on.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    int count = 0;
    for (string it : s)
    {
        on << it << "   "; //将s中的元素依次写入words.txt文件中
        ++count;
        if (count % 10 == 0) //输入十个单词后换行输入。
            on << endl;
    }
    on.close(); //关闭文件输出流。
}

void read()
{
    ifstream in(R"(E:\dev\classfile\oop\words.txt)");
    if (!in.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    string str, sub;
    int pos1 = 0, pos2 = 0;
    while (getline(in, str)) //依次读入文件中的每一行，默认不会读入行结尾的换行符。
    {
        pos1 = 0, pos2 = 0;
        while ((pos1 = str.find_first_not_of(" \n\t", pos2)) != string::npos)
        { //计算在这一行中pos2位置后面的第一个单词开始的位置。
            if ((pos2 = str.find_first_of(" \n\t", pos1 + 1)) != string::npos)
            {//找到这个单词的结束位置
                sub = str.substr(pos1, pos2 - pos1);//取出这个单词
            }
            else
            { //如果pos==string::npos说明这个单词一直到这行结束。
                sub = str.substr(pos1);
            }
            ++m[sub];//如果单词不存在m中，则会添加这个单词，并且值默认为0，值自增。
            s.insert(sub);
        }
    }
    in.close();//关闭文件输入流。
}