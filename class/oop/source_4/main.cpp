#include <iostream>
#include <string>
#include "Tree.h"
using namespace std;
int main()
{
    Tree *tree = new Tree();
    string word;
	
	while(cin>>word)
		tree->regist((word));

    tree->print_byorder(cout);

	delete tree;

    system("pause");
    return 0;
}
