#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    // 打印: 'a'-'z','0'-'9' "
    for (int i = 97; i <= 122; ++i)
    {
        cout << (char)i << " " << i << " 0x" << hex << i << endl;
    }
    for (int i = 0; i <= 9; ++i)
    {
        cout << i << " " << i+48 << " 0x" << hex << i + 48 << endl;
    }
    //打印其他可打印字符
    for (int i = 32; i <= 126; ++i)
    {
        if (i < 48)
            cout << (char)i << " " << i << " 0x" << hex << i << endl;
        if (i > 57 && i < 65)
            cout << (char)i << " " << i << " 0x" << hex << i << endl;
        if (i > 90 && i < 97)
            cout << (char)i << " " << i << " 0x" << hex << i << endl;
        if (i > 122)
            cout << (char)i << " " << i << " 0x" << hex << i << endl;
    }
    system("pause");
    return 0;
}
