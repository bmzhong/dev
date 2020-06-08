#include <stdio.h>
#include<iostream>
char hash[100];
int loc;

void print()
{
    int i;
    for(i = 0; i < loc; i++)
        printf("%c ", hash[i]);
    printf("\n");
    return;
}

void swap(int src, int dst)
{
    int temp;
    temp = hash[src];
    hash[src] = hash[dst];
    hash[dst] = temp;

}

void sort(int level)
{
    int i;
    if(level == loc){
        print();
        return;
    }
    sort(level + 1);
    for(i = 0; i+level < loc; i++){
        swap(level + i, level - 1);
        sort(level + 1);
    }
    for(i = loc - level - 1; i>= 0;i--)
        swap(level+i, level - 1);
}

int main()
{
    scanf("%s",hash);
    scanf("%d", &loc);
    sort(1);
    std::cout<<loc<<std::endl;
    system("pause");
    return 0;
}