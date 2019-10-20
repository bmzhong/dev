#include<iostream>
using namespace std;
int main(){
	int q[5]={1,2,3,4};
	int *p=q;
	cout<<*p++<<endl;
	cout<<*p++<<endl;
	cout<<*--p<<endl;
	cout<<*p<<endl;
	cout<<*p--<<endl;
	cout<<*p;
	
	return 0;
}

