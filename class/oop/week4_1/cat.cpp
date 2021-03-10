#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc <= 1)
        return 0;
    char ch;
    for (int i = 1; i < argc; ++i)
    {
        ifstream in(argv[i]);
        if(!in.is_open()){
        	cout<<"文件打开失败"<<endl; 
        	return 0; 
		}
        while (!in.eof())
        {
        	in.get(ch);
            cout << ch;
        }
        cout << endl;
        in.close();
    }
    return 0;
}
