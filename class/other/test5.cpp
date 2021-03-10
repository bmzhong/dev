#include<iostream>
using namespace std;
int *fps()
{
    static int n = 0;
    printf("%p\n",&n); 
    return &n;
}

int *fpa(int &arg)
{
    return &arg;
}

int *rl()
{
    int n = 5;
    printf("%p\n",&n); 
    return &n;
}

int &rs()
{
    static int n=2;
    printf("%p\n",&n); 
    return n;
}

int main(){
	int *r=rl();
	printf("%p\n",r);
	
	return 0;
} 

