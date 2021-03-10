#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int weight = 0;
    int parent = 0;
    int lchild = 0;
    int rchild = 0;
};
typedef Node *PN;
void select(PN &pn, int e, int &s1, int &s2);
void init(PN &pn, int &n);
void createTHTree(PN &pn, int n);
void coding(PN &pn, int n, vector<string> &v);
void tranverse(vector<string> &v);
int main()
{
    PN pn;
    int n;
    vector<string> v;
    init(pn, n);
    createTHTree(pn, n);
    coding(pn, n, v);
    tranverse(v);
    delete [] pn;
    system("pause");
    return 0;
}

void init(PN &pn, int &n)
{
    cin >> n;
    pn = new Node[2 * n];
    for (int i = 1; i <= n; ++i)
    {
        cin >> pn[i].weight;
    }
}

void createTHTree(PN &pn, int n)
{
    int s1, s2;
    for (int i = n + 1; i <= 2 * n - 1; ++i)
    {
        select(pn, i - 1, s1, s2);
        pn[s1].parent = i;
        pn[s2].parent = i;
        pn[i].lchild = s1;
        pn[i].rchild = s2;
        pn[i].weight = pn[s1].weight + pn[s2].weight;
    }
}

void select(PN &pn, int e, int &s1, int &s2)
{
    int i = 1;
    while (pn[i].parent && i <= e) //注意是pn[i].parent而不是！pn[i].parent
    {
        ++i;
    }
    s1 = i++;
    while (pn[i].parent && i <= e)
    {
        ++i;
    }
    s2 = i++;
    if (pn[s1].weight > pn[s2].weight) //注意这里的判断条件是pn[s1].weight > pn[s2].weight而不是s1>s2;
    {
        int t;
        t = s1;
        s1 = s2;
        s2 = t;
    }
    for (; i <= e; ++i)
    {
        if (pn[i].parent)
            continue;
        else
        {
            if (pn[i].weight < pn[s1].weight)
            {
                s2 = s1;
                s1 = i;
                //continue;//注意如果不加continue，会影响 else if (pn[i].weight < pn[s2].weight)的判断。
            }
            else if (pn[i].weight < pn[s2].weight)
                s2 = i;
            // 不能写成pn[i].weight > pn[s2].weight&&pn[i].weight < pn[s2].weight.
            //要考虑pn[i].weight == pn[s2].weight的情况。
        }
    }
    if (s1 > s2)
    {
        int t = s2;
        s2 = s1;
        s1 = t;
    } //让下标小的为s1,而不是权重小的为s1。从而使左孩子为下标小的，而不是权重小的。参考书上149页。
}

void coding(PN &pn, int n, vector<string> &v)
{
    int m = 2 * n - 1;
    v.resize(n+1);
    for (int i = 1; i <= m; ++i)
    {
        pn[i].weight = 0;
    }
    string str = "";
    while (m)
    {
        if (pn[m].weight == 0)
        {
            pn[m].weight = 1;
            if (pn[m].lchild)
            {
                m = pn[m].lchild;
                str += "0";
            }else if(!pn[m].rchild){
                v[m]=str;
            }
        }else if(pn[m].weight==1){
            pn[m].weight=2;
            if(pn[m].rchild){
                str+="1";
                m=pn[m].rchild;
            }
        }else {
            m=pn[m].parent;
            if(str.length()>0) str.pop_back();
        }
    }
}

void tranverse(vector<string> &v)
{
    int len = v.size();
    for (int i = 1; i < len; ++i)
    {
        cout << v[i] << endl;
    }
}