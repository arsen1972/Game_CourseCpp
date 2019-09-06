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

// ***************************************************** Cavalry(string, int, int, bool, Cell*)
Infantry::Infantry(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : Unit(st, tOT, uT, h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** ~Cavalry()
Infantry::~Infantry()
{ //LOG_TRACE
}
// **************************************************** move(int)
void Infantry::move(int a)
{
  size_t step = 1;
  cout << "\nCavalry took " << a << " steps:" << endl;
  if (a > 1)
  {  
    for(cout << "Step-step, "; step < (a-1); step++)
    { cout << "step-step, ";
    }
    cout << "step-step!\n" << endl;
  }
  else cout << "Step-step!\n" << endl;
  
}

// *************************************************** getAttackMap()
map<string, int> Infantry::getAttackMap()
{ return this->unitAttackBonus;
}

// *************************************************** getDefenceMap()
map<string, int> Infantry::getDefenceMap()
{ return this->unitDefenceBonus;
}

//*************************************** map<string, int> unitAttackBonus & map<string, int> unitDefenceBonus
map<string, int> Infantry::unitAttackBonus = { {"plain", 22}, {"forest", 23}, {"sea", 24} };
map<string, int> Infantry::unitDefenceBonus = { {"plain", 11}, {"forest", 13}, {"sea", 14} };
