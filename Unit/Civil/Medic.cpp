#include <iostream>
#include <string>
#include <memory>

#include "Medic.h"
#include "../Enums.h"
#include "../../Cell/Cell.h"
#include "../../Player/Player.h"
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


// ***************************************************** Medic(Status, TypeOfTerrainstring, int, int, bool, Cell*)
Medic::Medic(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c, Player* pl) :
 UnitCIVIL(st, tOT, uT, h, d, def, c, pl)
{ 
}

// ***************************************************** ~Builder()
Medic::~Medic()
{ cout << "   ~Medic is annihilated" << endl;
}

// ***************************************************** getUnitType()
string Medic::getUnitType() const
{ return this->UnitCIVIL::getUnitType();
}

// ***************************************************** getHealth()
int Medic::getHealth() const
{ return this->UnitCIVIL::getHealth();
}

// ****************************************************   setHealth()
void Medic::setHealth(int h)
{ this->UnitCIVIL::setHealth(h);
}

// ***************************************************** getDamage()
int Medic::getDamage() const
{ return this->UnitCIVIL::getDamage();
}

// ***************************************************** getDefence()
bool Medic::getDefence() const
{ return this->UnitCIVIL::getDefence();
}

// **************************************************** getCell()
Cell* Medic::getCell() const
{ return this->UnitCIVIL::getCell();
}

// **************************************************** setCell(Cell*)
void Medic::setCell(Cell* c)
{ 
  this->UnitCIVIL::setCell(c);
  return;
}

// **************************************************** getPlayer()
Player* Medic::getPlayer() const
{ return this->UnitCIVIL::getPlayer();
}

// **************************************************** getStatus()
Status Medic::getStatus() const
{ return this->UnitCIVIL::getStatus();
}

// **************************************************** getTOT()
TypeOfTerrain Medic::getTOT() const
{ return this->UnitCIVIL::getTOT();
}

// **************************************************** getStatusString()  only for print
string Medic::getStatusString() const
{ return "CIVIL";
}

// **************************************************** move(Cell*)
void Medic::move(Cell* c)
{ 
  this->setCell(c);
  cout << "   Builder go to cell with coordinates x = " << getCell()->getX() << ", y = " << getCell()->getY() << endl;
}

// ***************************************************** printUnitFields()
void Medic::printUnitFields() const
{
  cout << "   unitType is \t" << this->getUnitType() << endl;
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
string Medic::toString() const
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

// ****************************************************save()
void Medic::save() const
{ 

}
/*
// **************************************************** UnitCIVIL* load()
UnitCIVIL* Medic::load()
{
  #include "../../Cell/GameMap.h"
  ifstream fin(PATH_OF_SAVE);
  json j;
  fin >> j;
  fin.close();

  UnitCIVIL* ptr_UnitCIVIL = new Medic(
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
*/