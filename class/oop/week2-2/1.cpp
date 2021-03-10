#include <iostream>
using namespace std;
int main()
{
    char ch;
    int size;
    double price;
    int arr[5];
    char *pChar = &ch;
    int *pInt = &size;
    double *pDbl = &price;
    int(*pArr)[5] = &arr;

    printf("%p %p\n", pChar, pChar + 1);
    printf("%p %p\n", pInt, pInt + 1);
    printf("%p %p\n", pDbl, pDbl + 1);
    printf("%p %p\n", pArr, pArr + 1);
    system("pause");
    return 0;
}