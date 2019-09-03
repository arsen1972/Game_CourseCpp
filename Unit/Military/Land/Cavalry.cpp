#include <iostream>
#include <string>
#include <map>
#include "Cavalry.h"
#include "../../../Cell/Cell.h"
#include "../Military.h"
#include "../../Unit.h"
using std::map;
using std::string;
using std::cout;
using std::endl;


// ***************************************************** Cavalry(int, int, bool, Cell*)
Cavalry::Cavalry(int h, int d, bool def, Cell* c) : LandUnit(h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** Cavalry(string, int, int, bool, Cell*)
Cavalry::Cavalry(string uT, int h, int d, bool def, Cell* c) : LandUnit(uT, h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** ~Cavalry()
Cavalry::~Cavalry()
{ //LOG_TRACE
}
// **************************************************** move(int)
void Cavalry::move(int a)
{
  size_t step = 1;
  cout << "\nCavalry took " << a << " steps:" << endl;
  if (a > 1)
  {  
    for(cout << "Dyck-dyck, "; step < (a-1); step++)
    { cout << "dyck-dyck, ";
    }
    cout << "dyck-dyck!\n" << endl;
  }
  else cout << "Dyck-dyck!\n" << endl;
  
}

// *************************************************** getAttackMap()
map<string, int> Cavalry::getAttackMap()
{ return this->unitAttackBonus;
}

// *************************************************** getDefenceMap()
map<string, int> Cavalry::getDefenceMap()
{ return this->unitDefenceBonus;
}

//*************************************** unitAttackBonus & unitDefenceBonus
map<string, int> Cavalry::unitAttackBonus = { {"plain", 22}, {"forest", 23}, {"sea", 24} };
map<string, int> Cavalry::unitDefenceBonus = { {"plain", 11}, {"forest", 13}, {"sea", 14} };
