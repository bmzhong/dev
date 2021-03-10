#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include <random>
#include <ctime>
using namespace std;
typedef struct Node{
    int coe;
    int exp;
    Node(int coe,int exp){
        this->exp=exp;
        this->coe=coe;
    };

}Node;
bool test(int &a){
    return a<10;
}

bool test1(Node &node1,Node &node2){
    if(node1.exp==node2.exp){
        return node1.coe < node2.coe;
    }
    return node1.exp<node2.exp;
}
int main(){
    srand((unsigned int)time(NULL));
    list<int> a{1,2,3,8,454,555};
    list<Node> b;
    list<int> d(5,7);
    list<int> e(a.begin(),a.end());
    int g[]={9,2,35,4,51,16,71,48,9};
    list<int> f(g,g+9);
    vector<int> h(9);
    copy(g+0,g+9,h.begin());
    copy(g+2,g+9,g);
//    Node c;
//    b.push_back(c);
    for(int i=0;i<8;++i){
        Node node(rand()%50,rand()%50);
        b.push_back(node);
    }
    Node node1(12,11),node2(13,11),node3(14,11),node4(15,11);
    b.push_back(node4);
    b.push_back(node2);
    b.push_back(node1);
    b.push_back(node3);
    //    cout<<h.size();
    copy(h.begin()+2,h.end(),h.begin());
    h.push_back(111);
    e.push_front(111);
    e.push_back(222);
    cout<<e.empty()<<endl;
    e.resize(10,12);
    //e.clear();
    e.pop_back();
    e.pop_front();
    cout<<e.front()<<" "<<e.back()<<endl;
    cout<<e.size()<<endl;
    e.assign(10,8);
    e.assign(a.begin(),a.end());
    swap(d,e);
    swap(d,e);
    e.reverse();
    e.merge(d,greater<>());
    e.sort(greater<>());
    e.insert(e.begin(),123);
    e.insert(e.begin(),2,123);
    e.insert(e.begin(),a.begin(),a.end());
    e.erase(e.begin());
    e.remove(7);
    e.remove_if(test);
//    for(auto item:e) {
//        cout << item<<" ";
//    }
//    cout<<endl;
//    for(auto item:b) {
//        cout <<"coe: " <<item.coe << "   exp: "<<item.exp<<endl;
//    }
//    cout<<endl;
//    b.sort(test1);
//    for(auto item:b) {
//        cout <<"coe: " <<item.coe << "   exp: "<<item.exp<<endl;
//    }

  //  e.erase(e.begin(),e.end());
//    b.remove_if(test1);
//    for(auto item:b) {
//        cout << item.coe << "  ";
//    }
//    for (auto i=h.begin(); i!=h.end() ; ++i) {
//        cout<<*i<<" ";
//    }
//    cout<<b.size()<<" ";
//    for(int i=0;i<4;++i){
//        cout<<g[i]<<" ";
//    }
    f.sort();
    for(auto item=f.begin();item!=f.end();++item){
       // *item=6;
        cout<<*item<<"  ";
    }
    return 0;
}
