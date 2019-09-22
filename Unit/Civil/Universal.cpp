#include <iostream>
#include <string>
#include <map>
#include "Universal.h"
#include "../Enums.h"
#include "../../Cell/Cell.h"
#include "../Unit.hpp"
using std::map;
using std::string;
using std::cout;
using std::endl;

// ***************************************************** Universal(Status, TypeOfTerrainstring, int, int, bool, Cell*)
Universal::Universal(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : Unitt(st, tOT, uT, h, d, def, c)
{ cout << "Обьект Universal" << endl;
}

// ***************************************************** ~Universal()
Universal::~Universal()
{ cout << "Обьект ~Universal" << endl;
}

// ***************************************************** getUnitType()
string Universal::getUnitType() const
{ return this->Unitt::getUnitType();
}

// ***************************************************** getHealth()
int Universal::getHealth() const
{ return this->Unitt::getHealth();
}

// ****************************************************   setHealth()
void Universal::setHealth(int h)
{ this->Unitt::setHealth(h);
}

// ***************************************************** getDamage()
int Universal::getDamage() const
{ return this->Unitt::getDamage();
}

// ***************************************************** getDefence()
bool Universal::getDefence() const
{ return this->Unitt::getDefence();
}

// **************************************************** getCell()
Cell* Universal::getCell() const
{ return this->Unitt::getCell();
}

// **************************************************** getStatus()
Status Universal::getStatus() const
{ return this->Unitt::getStatus();
}

// **************************************************** getTOT()
TypeOfTerrain Universal::getTOT() const
{ return this->Unitt::getTOT();
}

// **************************************************** getStatusString()  only for print
string Universal::getStatusString() const
{ return "Universal";
}

// ****************************************************   move()
void Universal::move()
{ cout << "Universal Топ-топ!" << endl;
}

// ***************************************************** printUnitFields()
void Universal::printUnitFields() const
{
  cout << "Printing here!!! From class Universal" << endl;
  cout << "unitType is \t" << this->getUnitType() << endl;
  cout << "Health = \t" << this->getHealth() << endl;
  cout << "Damage = \t" << this->getDamage() << endl;
  cout << "Defence = \t" << this->getDefence() << endl;
//  cout << "Bonus factor = \t" << this->getCell()->getLands() << endl;
  cout << "Status unit = \t" << this->getStatusString() << endl;
//  cout << "Status type of terrian = \t" << this->getTOT() << endl;
  cout << endl;
}

// **************************************************** getAttackBonus()
int Universal::getAttackBonus()
{ return unitAttackBonus[this->getCell()->getLands()];
}

// **************************************************** getDefenceBonus()
int Universal::getDefenceBonus()
{ return (unitDefenceBonus[this->getCell()->getLands()])*(this->getDefence());
}

//*************************************** unitAttackBonus & unitDefenceBonus
std::map<string, int> Universal::unitAttackBonus = { {"plain", 11}, {"forest", 22}, {"sea", -22} };
std::map<string, int> Universal::unitDefenceBonus = { {"plain", -22}, {"forest", -44}, {"sea", 44} };


/*
// метод строительства фабрики
// ****************************************************   buildBuilderFactory()
void Universal::buildBuilderFactory()
{ 
  cout << "UniversalFactory is done virtual" << endl;
  cout << endl;
}

// *************************************************** Factory* buildBuilderFactory()
UniversalFactory* Universal::buildBuilderFactory()
{ 
  Factory* newDep;
 // if (uT == "universal") 
  newDep = new UniversalFactory();

  return newDep;
}
*/