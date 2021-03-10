#include<iostream>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<string.h>
#include<string>
#include<iterator>
#include<ctime>
#include<algorithm>
#define OK 1
#define ERROR 0
using namespace std;
typedef int Status;
Status handl();
Status write();
Status recursionSearch(vector<int> s3,int low,int high,int k,int &flag);
Status NoRecursionSearch(vector<int> s3,int k);
Status orderSearch(vector<int> s3,int k) ;
int main() {
    write();
    handl();
    return 0;
}
Status handl() {
    ifstream file(R"(E:\dev\lab5\datafile.txt)");
    if(!file.is_open()) {
        return ERROR;
    }
    string s2;
    int i=1;
    int j=0;
    vector<int> s3;
    while(getline(file,s2)) {
        char *t=new char[20];
        strcpy(t,s2.c_str());
        char *p=strtok(t," ");
        while(p!=NULL) {
            const char *x=p;
            int q=atoi(x);
            s3.push_back(q);
            p=strtok(NULL," ");
        }
        for(auto it:s3) {
            cout<<it<<" ";
        }
        int k;
        cout<<endl<<"输入要查找的元素：";
        cin>>k;
        orderSearch(s3,k);
        stable_sort(begin(s3),end(s3));
        for(auto it:s3) {
            cout<<it<<" ";
        }
        cout<<endl;
        int flag=0;
        NoRecursionSearch(s3,k);
        recursionSearch(s3,0,s3.size(),k,flag);
        if(flag==0) {
            cout<<"文件中没有这个数"<<endl;
        }

    }
    file.close();
    return 	OK;
}

Status recursionSearch(vector<int> s3,int low,int high,int k,int &flag) {
    if(low>high) {
        return ERROR;
    }
    int mid=(low+high)/2;
    if(s3[mid]==k) {
        cout<<"递归折半查找的结果："<<mid<<" ";
        int pos=mid;
        while(s3[--pos]==k) {
            cout<<pos<<" ";
        }
        pos=mid;
        while(s3[++pos]==k) {
            cout<<pos<<" ";
        }
        cout<<endl;
        flag=1;
        return OK;
    } else if(s3[mid]<k) {
        low=mid+1;
        recursionSearch(s3,low,high,k,flag);
    } else {
        high=mid-1;
        recursionSearch(s3,low,high,k,flag);
    }
}

Status NoRecursionSearch(vector<int> s3,int k) {
    int low=0;
    int high=s3.size()-1;
    int mid=0;
    int flag=0;
    while(low<=high) {
        mid=(low+high)/2;
        if(s3[mid]==k) {
            cout<<"非递归折半查找的结果："<<mid<<" ";
            int pos=mid;
            while(s3[--pos]==k) {
                cout<<pos<<" ";
            }
            pos=mid;
            while(s3[++pos]==k) {
                cout<<pos<<" ";
            }
            cout<<endl;
            flag=1;
            break;
        } else if(s3[mid]<k) {
            low=mid+1;
        } else {
            high=mid-1;
        }
    }
    if(flag==0) {
        cout<<"文件中没有这个数"<<endl;
        return ERROR;
    }
    return OK;
}

Status orderSearch(vector<int> s3,int k) {
    int flag=0;
    for(int i=0; i<s3.size(); ++i) {
        if(s3[i]==k) {
            flag=1;
            cout<<"顺序查找的结果："<<i<<" ";
        }
    }
    cout<<endl;
    if(flag==0) {
        cout<<"文件中没有这个元素"<<endl;
        return ERROR;
    }
    return OK;
}

Status write() {
    ofstream file(R"(E:\dev\lab5\datafile.txt)");
    if(!file.is_open()) {
        cout<<"写入文件时打开失败"<<endl;
        return ERROR;
    }
    srand((unsigned int)(time(0)));
    int p=0;
    for(int j=0; j<12; ++j) {
        p=rand()%100;
        file<<p<<" ";
    }
    file.close();
    return OK;
}

