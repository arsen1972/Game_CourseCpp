#include <iostream>
#include <string>
#include <memory>

#include "Builder.h"
#include "../Enums.h"
#include "../../Cell/Cell.h"
#include "../../Cell/GameMap.h"
#include "../Unit.hpp"

#define PATH_OF_SAVE "Save/save.json"
#include "../../Json/json.hpp"
using json = nlohmann::json;

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;

class BuilderFactory;

// ***************************************************** Builder(Status, TypeOfTerrainstring, int, int, bool, Cell*)
Builder::Builder(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : UnitCIVIL(st, tOT, uT, h, d, def, c)
{ //cout << "   Builder is born" << endl;
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
  cout << "   unitType is \t" << this->getUnitType() << endl;
  cout << "   Health = \t" << this->getHealth() << endl;
  cout << "   Damage = \t" << this->getDamage() << endl;
  cout << "   Defence = \t" << this->getDefence() << endl;
  cout << "   Bonus factor = \t" << this->getCell()->getLands() << endl;
  cout << "   Status unit = \t" << this->getStatusString() << endl; // getStatusString() 
  cout << "   Status type of terrian = \t" << this->getTOT() << endl;
  cout << "   Object coordinates: x = " << this->getCell()->getX() << ", y = " << this->getCell()->getY() << endl;
  cout << endl;
}

// ****************************************************save()
void Builder::save() const
{ 
  json j = {
  {"unitType", getUnitType()},
  {"health", getHealth()},
  {"damage", getDamage()},
  {"defence", getDefence()},
  {"status", getStatus()},
  {"typeOfTerrain", getTOT()},
  {"x", getCell()->getX()},
  {"y", getCell()->getY()}
  };

  ofstream fout;
  fout.open(PATH_OF_SAVE, ofstream::app);
  if (!fout.is_open()) {cout << "Error of open file ..." << endl;}
  else  { fout << j << endl;} //  
  fout.close(); 
  cout << "   From Builder: object save successfully" << endl;
  cout << "   " << j << endl; // << setw(2)
  return;
}

// **************************************************** UnitCIVIL* load()
UnitCIVIL* Builder::load()
{
  ifstream fin(PATH_OF_SAVE);
  json j;
  fin >> j;
  fin.close();

  UnitCIVIL* ptr_UnitCIVIL = new Builder(
  j.at("status"), 
  j.at("typeOfTerrain"), 
  j.at("unitType"), 
  j.at("health"), 
  j.at("damage"), 
  j.at("defence"),
  gameMap[j.at("y")][j.at("x")]
  );
  
  return ptr_UnitCIVIL;
}

// метод строительства фабрики BuilderFactory* buildBuilderFactory()
// **************************************************** buildBuilderFactory()
Factory* Builder::buildBuilderFactory()
{ 
  BuilderFactory* newDep;
  newDep = new BuilderFactory(this->getCell(), "builderFactory");
  cout << "   Message from \"Builder\": New BuilderFactory is DONE!!!!" << endl;
  return newDep;
}

/*
// **************************************************** heal(UnitCIVIL*)
void Builder::heal(UnitCIVIL*  ptr_uT) const
{ cout << "   Builder heal other builder" << endl;
  //cout << "   test" << ptr_uT->getHealth() << endl;
  //ptr_uT->setHealth(ptr_uT->getHealth() + 25); 
  
  return;
}
*/