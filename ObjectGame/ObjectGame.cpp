#include <iostream>
#include "ObjectGame.h"

using std::cout;
using std::endl;
using std::string;

// ****************************************** save()
void ObjectGame::save() const
{
   cout << "Printing from ObjectGame save()" << endl;
}
// ****************************************** save()
string ObjectGame::toString() const
{
   string str = "Printing from ObjectGame::toString()";
   return str;
}