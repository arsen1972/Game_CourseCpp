#include <iostream>
#include <string>
#include <memory>

#include "Builder.h"
#include "../Enums.h"
#include "../../Player/Player.h"
#include "../../Cell/Cell.h"
#include "../../Cell/GameMap.h"
#include "../Unit.hpp"

#include "../../Json/json.hpp"
using json = nlohmann::json;

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

class BuilderFactory;
class MedicFactory;

// ***************************************************** Builder(Status, TypeOfTerrainstring, int, int, bool, Cell*)
Builder::Builder(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c, Player* pl) :
 UnitCIVIL(st, tOT, uT, h, d, def, c, pl)
{ 
}

// ***************************************************** ~Builder()
Builder::~Builder()
{ cout << "   ~Builder is annihilated" << endl;
}

// ***************************************************** getUnitType()
string Builder::getUnitType() const
{ return this->UnitCIVIL::getUnitType();
}

// ***************************************************** getHealth()
int Builder::getHealth() const
{ return this->UnitCIVIL::getHealth();
}

// ****************************************************   setHealth()
void Builder::setHealth(int h)
{ this->UnitCIVIL::setHealth(h);
}

// ***************************************************** getDamage()
int Builder::getDamage() const
{ return this->UnitCIVIL::getDamage();
}

// ***************************************************** getDefence()
bool Builder::getDefence() const
{ return this->UnitCIVIL::getDefence();
}

// **************************************************** getCell()
Cell* Builder::getCell() const
{ return this->UnitCIVIL::getCell();
}

// **************************************************** setCell(Cell*)
void Builder::setCell(Cell* c)
{ 
  this->UnitCIVIL::setCell(c);
  return;
}

// **************************************************** getPlayer()
Player* Builder::getPlayer() const
{ return this->UnitCIVIL::getPlayer();
}

// **************************************************** getStatus()
Status Builder::getStatus() const
{ return this->UnitCIVIL::getStatus();
}

// **************************************************** getTOT()
TypeOfTerrain Builder::getTOT() const
{ return this->UnitCIVIL::getTOT();
}

// **************************************************** getStatusString()  only for print
string Builder::getStatusString() const
{ return "CIVIL";
}

// **************************************************** move(Cell*)
void Builder::move(Cell* c)
{ 
  this->setCell(c);
  cout << "   Builder go to cell with coordinates x = " << getCell()->getX() << ", y = " << getCell()->getY() << endl;
}

// ***************************************************** printUnitFields()
void Builder::printUnitFields() const
{
  cout << "   unitType is \t" << this->unitType << endl;
  cout << "   Health = \t" << this->getHealth() << endl;
//  cout << "   Damage = \t" << this->getDamage() << endl;
//  cout << "   Defence = \t" << this->getDefence() << endl;
//  cout << "   Bonus factor = \t" << this->getCell()->getLands() << endl;
  cout << "   Player = \t" << this->getPlayer()->getName() << endl;
  cout << "   Status unit = \t" << this->getStatusString() << endl; // getStatusString() 
  cout << "   Status type of terrian = \t" << this->getTOT() << endl;
  cout << "   Object coordinates: x = " << this->getCell()->getX() << ", y = " << this->getCell()->getY() << endl;
  cout << endl;
}

// **************************************************** toString()
string Builder::toString() const
{ 
  json j = {
  {"unitType", getUnitType()},
  {"health", getHealth()},
  {"player", getPlayer()->getName()},
  {"damage", getDamage()},
  {"defence", getDefence()},
  {"status", getStatus()},
  {"typeOfTerrain", getTOT()},
  {"x", getCell()->getX()},
  {"y", getCell()->getY()}
  };
  
  string str = j.dump() + "\n";
  
  return str;
}

// **************************************************** save()
void Builder::save() const
{ 

}

// **************************************************** buildBuilderFactory()
Factory* Builder::buildBuilderFactory()
{ 
  string uT = "builderFactory";
  BuilderFactory* ptr_Factory = new BuilderFactory(this->getCell(), uT, this->getPlayer());
  cout << "   Message from \"Builder\": New BuilderFactory is DONE!!!!" << endl;
//  this->getPlayer()->addToListOfFactory(ptr_Factory);
  this->getPlayer()->addToMapOfObjectGame(ptr_Factory);
  return ptr_Factory;
}

// **************************************************** buildMedicFactory()
Factory* Builder::buildMedicFactory()
{ 
  MedicFactory* newDep;
  newDep = new MedicFactory(this->getCell(), "medicFactory", this->getPlayer());
  cout << "   Message from \"Builder\": New MedicFactory is DONE!!!!" << endl;
//  this->getPlayer()->addToListOfFactory(newDep);
//  this->getPlayer()->addToListOfObjectGame(ptr_Factory);
  return newDep;
}

// ***************************************************  void doAction()
void Builder::doAction()
{
  cout << "Bulder doAction()" << endl;
}