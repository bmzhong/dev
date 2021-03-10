#include <iostream>
#include <list>
#include<cstdlib>
#include <algorithm>
#include<string>
using namespace std;
int main()
{
	char * ch = new char[1000];
	cout<<itoa(2147488,ch,10)<<endl;
    return 0;
}
