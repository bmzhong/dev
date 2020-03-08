#include <iostream>
#include "atoi.cpp"
using namespace std;
int main()
{
	char *ch = new char[100];
	while (cin >> ch)
	{
		int num = my_atoi::atoi(ch);
		cout << num << endl;
	}
	system("pause");
	return 0;
}
