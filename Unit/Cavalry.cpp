#include <iostream>
#include <string>
#include <map>
#include "Cavalry.h"
#include "../Cell/Cell.h"
#include "Unit.h"
using std::string;
using std::cout;
using std::endl;


// ***************************************************** Cavalry(int, int, bool, Cell*)
Cavalry::Cavalry(int h, int d, bool def, Cell* c) : Unit(h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** ~Cavalry()
Cavalry::~Cavalry()
{ //LOG_TRACE
}
// **************************************************** move(int)
void Cavalry::move(int a)
{
  cout << "\nCavalry took " << a << " steps:" << endl;
  if (a>1)
  { cout << "Dyck-dyck, ";
  }
  for(short step=1; step < (a-1); step++)
  { cout << "dyck-dyck, ";
  }
  cout << "dyck-dyck!\n" << endl;
}

// **************************************************** getAttackBonus()
int Cavalry::getAttackBonus()
{ 
  return unitAttackBonus[this->getCell()->getLands()];
}

// **************************************************** getDefenceBonus()
int Cavalry::getDefenceBonus()
{ 
  return (unitDefenceBonus[this->getCell()->getLands()])*(this->getDefence());
}

//*************************************** unitAttackBonus & unitDefenceBonus
std::map<string, int> Cavalry::unitAttackBonus = { {"plain", 11}, {"forest", 22}, {"sea", -22} };
std::map<string, int> Cavalry::unitDefenceBonus = { {"plain", -22}, {"forest", -44}, {"sea", 44} };
