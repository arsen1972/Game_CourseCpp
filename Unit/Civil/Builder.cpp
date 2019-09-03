#include <iostream>
#include <string>
#include <map>
#include "Builder.h"
#include "../../Cell/Cell.h"
#include "../Unit.h"
#include "Civil.h"

using std::map;
using std::string;
using std::cout;
using std::endl;


// ***************************************************** Builder(int, int, bool, Cell*)
Builder::Builder(int h, int d, bool def, Cell* c) : Civil(h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** Builder(string, int, int, bool, Cell*)
Builder::Builder(string uT, int h, int d, bool def, Cell* c) : Civil(uT, h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** ~Builder()
Builder::~Builder()
{ //LOG_TRACE
}
// **************************************************** move(int)
void Builder::move(int a)
{
  size_t step = 1;
  cout << "\nBuilder took " << a << " steps:" << endl;
  if (a > 1)
  {  
    for(cout << "Dyck-dyck, "; step < (a-1); step++)
    { cout << "dyck-dyck, ";
    }
    cout << "dyck-dyck!\n" << endl;
  }
  else cout << "Dyck-dyck!\n" << endl;
  
}
// ****************************************************  buildFactory(string)
void Builder::buildFactory(string fT)
{
  cout << "Build Factory by builder '" << fT << "'" << endl;
  return;
}

// *************************************************** getAttackMap()
map<string, int> Builder::getAttackMap()
{ return this->unitAttackBonus;
}

// *************************************************** getDefenceMap()
map<string, int> Builder::getDefenceMap()
{ return this->unitDefenceBonus;
}

//*************************************** unitAttackBonus & unitDefenceBonus
map<string, int> Builder::unitAttackBonus = { {"plain", 22}, {"forest", 23}, {"sea", 24} };
map<string, int> Builder::unitDefenceBonus = { {"plain", 11}, {"forest", 13}, {"sea", 14} };




