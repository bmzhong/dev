#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<iterator>
#include<string>
#include<string.h>
#include<list>
#include<vector>

#define n 30
using namespace std;
typedef struct Node {
    int coe;
    int exp;
} Node, *PNode;

void init(list<Node> (&L)[n]);

bool cmp(Node &node1, Node &node2);

void handle(list<Node> (&L)[n]);

bool cmp1(Node &node1, Node &node2);

void disp(list<Node> (&L)[n]);
/*
 *   L[i].erase(item1);为错误写法，it1,item1迭代器会失效
 *   it1=L[i].erase(item1);正确写法 //https://www.cnblogs.com/blueoverflow/p/4923523.html
 *   */
int main() {
    list<Node> L[n];
    init(L);
    handle(L);
    disp(L);
    return 0;
}

void init(list<Node> (&L)[n]) {
    string str;
    int i = 1;
    while (getline(cin, str) && str.length()) {
        char *p1 = (char *) malloc(180 * sizeof(char));
        char *p2 = (char *) malloc(5 * sizeof(char));
        strcpy(p1, str.c_str());
        p2 = strtok(p1, " ");
        while (p2 != NULL) {
            Node p;
            int a = atoi(p2);
            p.coe = a;
            p2 = strtok(NULL, " ");
            int b = atoi(p2);
            p.exp = b;
            L[i].push_back(p);
            p2 = strtok(NULL, " ");
        }
        ++i;
    }
    Node node;
    node.coe = i - 1;
    node.exp = i - 1;
    L[0].insert(L[0].begin(), node);
}

void handle(list<Node> (&L)[n]) {
    for (int i = 1; i <= (L[0].front().exp); i = i + 2) {
        auto it1 = L[i].begin();
        auto it2 = L[i + 1].begin();
        while (it1 != L[i].end() && it2 != L[i + 1].end()) {
            auto item1=it1;
            auto item2=it2;
            if (item1->exp > item2->exp) {
                it1++;
            } else if (item1->exp < item2->exp) {
                L[i].insert(item1, *item2);
                it1++;
                it2++;
            } else if (item1->exp == item2->exp) {
                item1->coe = item1->coe + item2->coe;
                if (item1->coe == 0) {
                    it1=L[i].erase(item1);//https://www.cnblogs.com/blueoverflow/p/4923523.html
                }else{
                    it1++;
                }
                it2++;
            }

        }
        while (it2 != L[i + 1].end()) {
            L[i].push_back(*it2);
            it2++;
        }
    }
}

void disp(list<Node> (&L)[n]) {
    for (int i = 1; i <= L[0].front().exp; i+=2) {
        for (auto j:L[i]) {
            cout << j.coe << " " << j.exp << " ";
        }
        cout<<endl;
    }
}

bool cmp(Node &node1, Node &node2) {
    node1.coe = node1.coe + node2.coe;
    node2.coe = node1.coe + node2.coe;
    if (node1.exp == node2.exp) {
        return node1.coe < node2.coe;
    }
    return node1.exp < node2.exp;
}

bool cmp1(Node &node1, Node &node2) {
    return node1.exp == node2.exp;
}
