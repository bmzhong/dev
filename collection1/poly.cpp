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

void init(vector<Node> (&L)[n]);
bool cmp(Node &node1, Node &node2);
void handle(vector<Node> (&L)[n]);
bool cmp1(Node &node1, Node &node2);
int main() {
    vector<Node> L[n];
    init(L);
    handle(L);
    return 0;
}

void init(vector<Node> (&L)[n]) {
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
    L[0].insert(L[0].begin(),node);
}

void handle(vector<Node> (&L)[n]) {
    for (int i = 1; i <= (L[0].front().exp); i = i + 2) {
    	L[i+1].front();
//   		merge(L[i].begin(),L[i].end(),L[i+1].begin(),L[i+1].end(),L[i],cmp);
//        sort(L[i].begin(), L[i].end(), cmp);
        
    }
}

bool cmp(Node &node1, Node &node2) {
    node1.coe=node1.coe+node2.coe;
    node2.coe=node1.coe+node2.coe;
    if (node1.exp == node2.exp) {
        return node1.coe < node2.coe;
    }
    return node1.exp < node2.exp;
}

bool cmp1(Node &node1, Node &node2) {
    return node1.exp == node2.exp;
}
