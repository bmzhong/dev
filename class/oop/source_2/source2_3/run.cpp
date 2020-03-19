#include <iostream>
#include "error.cpp"
using namespace std;

int main()
{
    Error::error("i %s %d do%clar\n", "have", 10, 'l');
    system("pause");
    return 0;
}
