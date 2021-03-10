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
    while (pn[i].parent&&i<=e)//注意是pn[i].parent而不是！pn[i].parent
    {
        ++i;
    }
    s1 = i++;
    while (pn[i].parent&&i<=e)
    {
        ++i;
    }
    s2 = i++;
    if (pn[s1].weight > pn[s2].weight)//注意这里的判断条件是pn[s1].weight > pn[s2].weight而不是s1>s2;
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
                continue;//注意如果不加continue，会影响 else if (pn[i].weight < pn[s2].weight)的判断。
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
    for (int i = 1; i <= n; ++i)
    {
        string str;
        int j = i;
        int k = pn[i].parent;
        while (k)
        {
            pn[k].lchild == j ? str += "0" : str += "1";
            j = k;
            k = pn[k].parent;
        }
        reverse(str.begin(),str.end());
        v.push_back(str);
    }
}

void tranverse(vector<string> &v)
{
    int len = v.size();
    for (int i = 0; i < len; ++i)
    {
        cout << v[i] << endl;
    }
}