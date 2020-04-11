#ifndef _Symbol_table_
#define _Symbol_table_

#include<map>
#include<string>
using namespace std;

namespace Symbol_table{
   
   extern map<string, double> table; 

   void init();

   void add(const string &name,const double &value);

   double select(const string &name);

   void update(const string &name,const double &value);

}

#endif