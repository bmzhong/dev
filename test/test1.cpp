
#include<iostream>

#include<string>

using namespace std;

int main()

{

	string str = "he is@ a@ good boy";

	char * str1 = "12345";

	str=str.replace(0,5,str1);   //用str替换从指定位置开始长度为5的字符串

	cout<<str<<endl;

	return 0; 

}

