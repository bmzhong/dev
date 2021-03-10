#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

struct A{
    string name;
    string year;
    string month;
    string day;
};
bool operator < (const A &a1,const A &a2){
    if(a1.year<a2.year){
        return true;
    }else if(a1.year==a2.year){
        if(a1.month<a2.month){
            return true;
        }else if(a1.month==a2.month){
            if(a1.day<a2.day){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }else{
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    A a;
    set<A> s;
    string str1;
    int pos1=0,pos2;
    for(int i=0;i<n;++i){
        cin>>a.name>>str1;
        pos1=str1.find('/');
        a.year=str1.substr(0,pos1);
        pos2=str1.find("/",pos1+1);
        a.month=str1.substr(pos1+1,pos2-pos1-1);
        a.day=str1.substr(pos2+1);
        s.insert(a);
    }
    A u,l;
    u.name=" ";l.name=" ";
    u.year="2014";l.year="1814";
    u.month="09";l.month="09";
    u.day="06";l.day="06";
    auto pu=upper_bound(s.begin(),s.end(),u);
    auto pl=lower_bound(s.begin(),s.end(),l);
    auto pp1=pu;
    int s1=0,s2=0;
    while(pu!=s.end()){
        ++s1;
        pu++;
    }
    auto pp3=s.begin();
    while(pp3!=pl){
        ++s2;
        ++pp3;
    }

    cout<<n-s1-s2<<" "<<pl->name<<" "<<(--pp1)->name<<endl;
    system("pause");
    return 0;
}
//56 row pp1=--pu;pu会变化。