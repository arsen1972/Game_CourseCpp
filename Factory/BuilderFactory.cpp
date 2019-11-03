#include <string>
#include <iostream>

#include "Factory.h"
#include "BuilderFactory.h"
#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Builder.h"
#include "../Cell/Cell.h"
#include "../Player/Player.h"
#include "../ObjectGame/ObjectGame.h"

#include "../Json/json.hpp"

using json = nlohmann::json;
using std::string;

// *****************************************************************   BuilderFactory()
BuilderFactory::BuilderFactory()
{ 
}

// *****************************************************************   BuilderFactory(Cell*, string&, Player*)
BuilderFactory::BuilderFactory(Cell* c, string& uT, Player* pl) : Factory(c, uT, pl) //, unitType(uT)
{ 
  
}

// *****************************************************************   ~BuilderFactory()
BuilderFactory::~BuilderFactory()
{ std::cout << "   ~BuilderFactory is destroy!" << std::endl;
}

// *****************************************************************   getUnit()
UnitCIVIL* BuilderFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c, Player* player)
{ 
  UnitCIVIL* ptr_unit = nullptr;
  
  if(unitType == "builder")
  {
    ptr_unit = new Builder(st, tOT, unitType, h, d, def, c, player);
//    player->addToListOfUnitCIVIL(ptr_unit);
    player->addToMapOfObjectGame(ptr_unit);
    cout << "builder успешно создан, добавлен в список Юнитов и пронумерован!" << endl;
  }
  return ptr_unit;
}
/*

// *****************************************************************   getUnit()
void BuilderFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c, Player* player)
{
  if(unitType == "builder") player->addToListOfUnitCIVIL(new Builder(st, tOT, unitType, h, d, def, c, player));
  cout << "builder успешно создан, добавлен в список Юнитов и пронумерован!" << endl;
  return;
}

*/
// ****************************************************   toString()
string BuilderFactory::toString() const
{ 
  json j = {
  {"unitType", getUnitType()},
  {"Player", getPlayer()->getName()},
  {"x", getCell()->getX()},
  {"y", getCell()->getY()}
  };
  
  string str = j.dump() + "\n";
  
  return str;
}

// *****************************************************************   save()
void BuilderFactory::save() const
{ 
  return;
}

// ************************************************************** getUnitType()
std::string BuilderFactory::getUnitType() const
{ return this->unitType;
}

// **************************************************  setUnitType(string&)
void BuilderFactory::setUnitType(string& uT)
{ 
  unitType = uT;
  return;
}

// **************************************************** printUnitFields()
void BuilderFactory::printUnitFields() const
{ 
  cout << "   From BuilderFactory:" << endl;
  cout << "   unitType is \t" << unitType << endl;
  cout << "   Object coordinates: x = " << this->getCell()->getX() << ", y = " << this->getCell()->getY() << endl;
  cout << endl;
}

// ***************************************************  void doAction()
void BuilderFactory::doAction()
{
  cout << "BuilderFactory doAction()" << endl;
}