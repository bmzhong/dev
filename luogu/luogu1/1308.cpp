#include<iostream>
#include<string>
#include<algorithm>
#include<ctype.h>
using namespace std;
int main() {
	string str;
	cin>>str;
	char c;
	cin.get(c);
	string text;
	getline(cin,text);
	transform(str.begin(),str.end(),str.begin(),::tolower);
	transform(text.begin(),text.end(),text.begin(),::tolower);
	int i=0;
	int len=str.size();
	int count=0;
	int first=text.find(str,i);
	string temp;
	if(first!=string::npos) {
		while(i<=text.size()) {
			temp=text.substr(i,len);
			int a=temp.compare(str);
			if(a==0) {
				if(i==0&&len!=text.size()) {
					if(!isalpha(text[len]) ) {
						if(count==0) {
							first=i;
						}
						count++;
					}
				} else if(i==0&&len==text.size()) {
					if(count==0) {
						first=i;
					}
					count++;
					break;
				} else if(i+len==text.size()) {
					if(!isalpha(text[i-1])) {
						if(count==0) {
							first=i;
						}
						count++;
					}
				} else if(i!=0&&i+len!=text.size()) {
					if(!isalpha(text[i-1])&&!isalpha(text[i+len])) {
						if(count==0) {
							first=i;
						}
						count++;
					}
				}
			}
			i++;
		}
	}
	if(count!=0) {
		cout<<count<<" "<<first<<endl;
	} else {
		cout<<"-1"<<endl;
	}
	return 0;
}
//8_9���ܿո�
//27_28��¼��һ������������λ�ã���������find��������¼��
//27 ��ϸ˼��Ϊʲô��<=������<  
