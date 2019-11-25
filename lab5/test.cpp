#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
void fun(int *&n){
	n=(int *)malloc(sizeof(int));
	*n=10;
}
int main(){
	int a=0;
	int *i=NULL;
	fun(i);
	cout<<*i;
	return 0;
}
