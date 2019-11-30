#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
typedef struct Node{
    int coe;
    int exp;
}Node;
int main(){
    list<int> a{1,2,3,8,454,555};
    list<Node> b;
    list<int> d(5,7);
    list<int> e(a.begin(),a.end());
    int g[]={1,2,3,4,5,6,7,8,9};
    list<int> f(g+2,g+4);
    vector<int> h(9);
    copy(g+0,g+9,h.begin());
    copy(g+2,g+9,g);
    Node c;
    b.push_back(c);
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
    e.merge(d,greater<int>());
    e.sort(greater<int>());
    sort(begin(h),end(h),greater<int>());
//    for(auto item:e){
//        cout<<item<<" ";
//    }
//    for (auto i=h.begin(); i!=h.end() ; ++i) {
//        cout<<*i<<" ";
//    }
//    cout<<b.size()<<" ";
//    for(int i=0;i<4;++i){
//        cout<<g[i]<<" ";
//    }
//    for(auto item=f.begin();item!=f.end();++item){
//       // *item=6;
//        cout<<*item<<"  ";
//    }
    return 0;
}
