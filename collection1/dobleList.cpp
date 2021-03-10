#include<iostream>
#include<cstdlib>
#include<algorithm>
#include <string>
#include <string.h>
#include<iterator>
#include<vector>

using namespace std;

int main() {
	vector<int> L;
	string str;
	int a, b, c;
	while (getline(cin, str)) {
		int num = str.find(" ", 2);
		char *s = (char *) malloc(80 * sizeof(char));
		strcpy(s, str.c_str());
		char *p = strtok(s, " ");
		a = atoi(p);
		p=strtok(NULL, " ");
		b=atoi(p);
		p=strtok(NULL," ");
		c=atoi(p);
		if(a==0) {
			if(L.size()>0) {
				for(auto item:L) {
					cout<<item<<" ";
				}
				cout<<endl;
			}else{
				continue;
			}
		}
		if(a==1) {
			if(b<=L.size()+1) {
				L.insert(L.begin()+b-1,c);
			} else {
				continue;
			}

		}
		if(a==2) {
			if(b<=L.size())
			L.erase(L.begin()+b-1);
		}
	}
	return 0;
}
