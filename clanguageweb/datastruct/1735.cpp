#include <iostream>
#include<cmath>
using namespace std;
// struct Node
// {
//     int data;
//     struct Node *lchild = NULL;
//     struct Node *rchild = NULL;
// };
// typedef Node *PNode;
// void createTree(PNode &p, int a[], int index, int n);
int main()
{
    
    int n, d;
    while (cin >> n && n != 0)
    {
        //PNode T = NULL;
        int a[n + 1];
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        //createTree(T, a, 1, n);
        cin>>d;
        d=pow(2,d-1);
        
        if(d>n){
            cout<<"EMPTY"<<endl;
        }else{
            int max=d*2;
            for(int i=d;i<max&&i<=n;++i){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    system("pause");
    return 0;
}

// void createTree(PNode &p, int a[], int index, int n)
// {
//     if (index > n)
//     {
//         return;
//     }
//     p = new Node;
//     p->data = a[index];
//     createTree(p->lchild, a, 2 * index, n);
//     createTree(p->rchild, a, 2 * index + 1, n);
// }