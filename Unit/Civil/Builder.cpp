#include <iostream>
#include <string>
#include <map>
#include "Builder.h"
#include "../../Cell/Cell.h"
#include "../Unit.hpp"
using std::map;
using std::string;
using std::cout;
using std::endl;

// ***************************************************** Builder(Status, TypeOfTerrainstring, int, int, bool, Cell*)
Builder::Builder(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : Unitt(st, tOT, uT, h, d, def, c)
{ cout << "Обьект Builder" << endl;
}

// ***************************************************** ~Builder()
Builder::~Builder()
{ cout << "Обьект ~Builder" << endl;
}

// ***************************************************** getUnitType()
string Builder::getUnitType() const
{ return this->Unitt::getUnitType();
}

// ***************************************************** getHealth()
int Builder::getHealth() const
{ return this->Unitt::getHealth();
}

// ****************************************************   setHealth()
void Builder::setHealth(int h)
{ this->Unitt::setHealth(h);
}

// ***************************************************** getDamage()
int Builder::getDamage() const
{ return this->Unitt::getDamage();
}

// ***************************************************** getDefence()
bool Builder::getDefence() const
{ return this->Unitt::getDefence();
}

// **************************************************** getCell()
Cell* Builder::getCell() const
{ return this->Unitt::getCell();
}

// **************************************************** getStatus()
Status Builder::getStatus() const
{ return this->Unitt::getStatus();
}

// **************************************************** getTOT()
TypeOfTerrain Builder::getTOT() const
{ return this->Unitt::getTOT();
}

// **************************************************** getStatusString()  only for print
string Builder::getStatusString() const
{ return "Builder";
}

// ****************************************************   move()
void Builder::move()
{ cout << "Builder Топ-топ!" << endl;
}

// ***************************************************** printUnitFields()
void Builder::printUnitFields() const
{
  cout << "Printing here!!! From class Builder" << endl;
  cout << "unitType is \t" << this->getUnitType() << endl;
  cout << "Health = \t" << this->getHealth() << endl;
//  cout << "Damage = \t" << this->getDamage() << endl;
//  cout << "Defence = \t" << this->getDefence() << endl;
//  cout << "Bonus factor = \t" << this->getCell()->getLands() << endl;
//  cout << "Status unit = \t" << this->getStatusString() << endl;
//  cout << "Status type of terrian = \t" << this->getTOT() << endl;
  
  cout << endl;
}

// **************************************************** getAttackBonus()
int Builder::getAttackBonus()
{ return unitAttackBonus[this->getCell()->getLands()];
}

// **************************************************** getDefenceBonus()
int Builder::getDefenceBonus()
{ return (unitDefenceBonus[this->getCell()->getLands()])*(this->getDefence());
}

//*************************************** unitAttackBonus & unitDefenceBonus
std::map<string, int> Builder::unitAttackBonus = { {"plain", 11}, {"forest", 22}, {"sea", -22} };
std::map<string, int> Builder::unitDefenceBonus = { {"plain", -22}, {"forest", -44}, {"sea", 44} };

/*
// метод строительства фабрики
// *************************************************** Factory* buildBuilderFactory()
Factory* Builder::buildBuilderFactory(string uT)
{ 
  Factory* newDep;
  if (uT == "Builder") newDep = new BuilderFactory();

  return newDep;
}
*/
/*
// ****************************************************   buildBuilderFactory()
void Builder::buildBuilderFactory() const
{ cout << "\nBuilderFactory is done by Builder" << endl;
}
*/