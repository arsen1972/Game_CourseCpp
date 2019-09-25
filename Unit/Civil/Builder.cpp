#include <iostream>
#include <string>
#include <map>
#include "Builder.h"
#include "../Enums.h"
#include "../../Cell/Cell.h"
#include "../../Cell/Karta.h"
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
{ cout << "   Builder is born" << endl;
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

// ****************************************************   move()
void Builder::move()
{ cout << "Builder Топ-топ!" << endl;
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
  cout << "   x = \t\t" << this->getCell()->getX() << endl;
  cout << "   y = \t\t" << this->getCell()->getY() << endl;
  cout << endl;
}

// ****************************************************save()

void Builder::save()
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
  fout.open(PATH_OF_SAVE);
  if (!fout.is_open()) {cout << "Ошибка открытия файла..." << endl;}
  else  { fout << j << endl;} //  
  fout.close(); 
  cout << "   From Builder: объект успешно сохранен с параметрами:" << endl;
  cout << std::setw(2) << j << endl;
  return;
}

// Builder::Builder(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c)
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
  karta[j.at("x")][j.at("y")] //  getCell()
  );
  
  return ptr_UnitCIVIL;
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

// метод строительства фабрики BuilderFactory* buildBuilderFactory()
// **************************************************** buildBuilderFactory()
BuilderFactory* Builder::buildBuilderFactory()
{ 
  BuilderFactory* newDep;
  newDep = new BuilderFactory();
  cout << "   Сообщение из \"Builder\": New BuilderFactory is DONE!!!!" << endl;
  return newDep;
}

// **************************************************** buildBuilderFactory(int x, int y)
BuilderFactory* Builder::buildBuilderFactory(int x, int y)
{ 
  BuilderFactory* newDep;
  newDep = new BuilderFactory(x, y);
  cout << "   Сообщение из \"Builder\": New BuilderFactory is DONE!!!!" << endl;
  return newDep;
}