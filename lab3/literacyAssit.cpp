#include<iostream>
#include<string>
#include<iterator>
#include<fstream>
using namespace std;
void handle(string str);
int main() {
	string str;
	getline(cin,str);
	handle(str);
	return 0;
}

void handle(string str) {
	ifstream file("E:\\dev\\lab3\\test2.txt");
	if(!file.is_open()) {
		cout<<"�ļ���ʧ��"<<endl;
	}
	int pline=0;
	int sum=0;
	string line;
	int strlen=str.length();
	while(getline(file,line)) {
		int count=0;
		int pos=-1;
		int linelen=line.length();
		auto it=line.begin();
		while(true) {
			pos=line.find(str,pos+1);
			if(pos!=-1) {
				if(pos==0) {
					if(linelen==strlen) {
						count++;
					} else if(linelen>strlen) {
						if(line[strlen]==' '||line[strlen]=='	') {
							count++;
						}
					}
				} else if(pos==linelen-strlen-1) {
					count++;
				} else {
					if((line[pos-1]==' '||line[pos-1]=='	')&&(line[pos+strlen]==' '||line[pos+strlen]=='	')) {
						count++;
					}
				}
			}else{
				break;
			}
		}
		sum+=count;
		cout<<"��"<<pline<<"�г���"<<count<<"��"<<endl;
		pline++;
	}
	cout<<"�ܹ�����"<<sum<<"��"<<endl;
}
