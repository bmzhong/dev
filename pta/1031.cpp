#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
    int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    map<int,char> m={{0,'1'},{1,'0'},{2,'X'},{3,'9'},{4,'8'},
    {5,'7'},{6,'6'},{7,'5'},{8,'4'},{9,'3'},{10,'2'}};
    int n;
    cin>>n;
    cin.get();
    vector<string> v;
    string str;
    for(int i=0;i<n;++i){
        getline(cin,str);
        int sum=0;
        int flag=1;
        for(int j=0;j<17;++j){
            if(isdigit(str[j])){
                sum+=(str[j]-'0')*a[j];
            }else{
                flag=0;
                break;
            }
        }
        if(flag==1){
            sum=sum%11;
            if(str[17]==m[sum]){
                str="pass";
            }
        }
        v.push_back(str);
    }
    int k=0;
    for(int i;i<v.size();++i){
        if(v[i]!="pass"){
            k=1;
            cout<<v[i]<<endl;
        }
    }
    if(k==0){
        cout<<"All passed"<<endl;
    }
    system("pause");
    return 0;
}