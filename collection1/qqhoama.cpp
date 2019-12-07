#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void num(vector<int> &v1,vector<int> &v2,vector<int> &v4);
int main() {
    int n;
    cin>>n;
    vector<int> v1,v2,v4;
    int a,b;
    for(int i=0; i<n; ++i) {
        cin>>a;
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end());
    num(v1,v2,v4);
    return 0;
}

void num(vector<int> &v1,vector<int> &v2,vector<int> &v4) {
    for(auto it:v1) {
        int a=it,b;
        int sum=0;
        while(a!=0) {
            b=a%10;
            sum=sum+b;
            a=a/10;
        }
        v2.push_back(sum);
    }
    int temp=v2.front();
    v4.push_back(0);
    for(int i=0; i<v2.size(); ++i) {
        if(v2[i]>temp) {
            temp=v2[i];
            v4.front()=i;
        }
    }
    for(int i=0; i<v2.size(); ++i) {
        if(v2[i]==temp&&v4.front()!=i) {
            v4.push_back(i);
        }
    }
    if(v4.size()==1) {
        cout<<v1[v4.front()]<<endl;
    } else {
        int temp=v1[v4[0]];
        for(int i=0; i<v4.size(); ++i) {
            if(v1[v4[i]]>temp) {
                temp=v1[v4[i]];
            }
        }
        cout<<temp<<endl;
    }
}
