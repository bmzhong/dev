#include <iostream>
#include <list>
#include<cstdlib>
#include <algorithm>
#include<string>
using namespace std;
int main()
{
	char * ch = new char[1000];
	itoa(-2147483648,ch,10);
	cout<<abs(-2147483648)<<endl;
    return 0;
}
