#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include<iomanip>
using namespace std;
double func(string str);
string func2(double d);
int main()
{
    string str, str1, str2;
    double d;
    vector<string> v;
    while (cin >> str1 >> str2)
    {
        double d1 = func(str1);
        double d2 = func(str2);
        double d = d1 + d2;
        str=func2(d);
        v.push_back(str);
    }
    for(auto it:v){
        cout<<it<<endl;
    }

    system("pause");
    return 0;
}

string func2(double d){
    stringstream s;
    string str1;
    int r=0;
    if(d>0){
        r=1;
    }else if(d<0){
        r=-1;
        d=(double)-1*d;
    }                                         
    if(d-int(d)>0){
        s<<fixed<<setprecision(15)<<d;
        string str;
        s>>str;
        int q=str.find_last_not_of("0");
        str.erase(q+1);
        int pos1=str.find(".");
        if(str[0]=='0'){
            int pos2=str.find_first_not_of("0.");
            int a=pos2-2;
            string str2=str.substr(pos2);
            str2.insert(0,"0.");
            str2.append("e-");
            s.clear();
            s<<a;
            string str3;
            s>>str3;
            str2.append(str3);
            str1=str2;
        }else{
            int pos2=str.find(".");
            string str2=str.substr(0,pos2);
            string str3=str.substr(pos2+1);
            str2.insert(1,".");
            str2.append(str3);
            int a=pos2-1;
            s.clear();
            s<<a;
            string str4;
            s>>str4;
            str2.append("e");
            str2.append(str4);
            str1=str2;
        }
    }else{
        int a=int(d);
        s.clear();
        s<<a;
        s>>str1;
    }
    if(r<0){
        str1.insert(0,"-");
    }
    return str1;
}

double func(string str)
{
    char f = str[0];
    if (f == '-')
    {
        str.erase(0, 1);
    }
    double d;
    stringstream s;
    int pos1 = str.find_first_of("Ee");
    if (pos1 != string::npos)
    {
        string str1 = str.substr(pos1 + 1);
        string str2 = str.substr(0, pos1);
        s << str1;
        int a;
        s >> a;
        s.clear();

        s << str2;
        s >> d;
        s.clear();
        if (a > 0)
        {
            string str3("1");
            str3.append(a, '0');
            int b;
            s << str3;
            s >> b;
            d = d * b;
        }
        if (a < 0)
        {
            a = -1 * a;
            s.clear();
            string str3("1");
            str3.append(a, '0');
            int b;
            s << str3;
            s >> b;
            d = d / b;
        }
        if (f == '-')
        {
            d = -1 * d;
        }
    }
    else
    {
        s.clear();
        s << str;
        s >> d;
        if (f == '-')
        {
            d = -1 * d;
        }
    }
    return d;
}