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

// *****************************************************************   BuilderFactory()
BuilderFactory::BuilderFactory()
{ 
//  unitType = "BuilderFactory";
//  cell = gameMap[1][1];

//std::cout << "   BuilderFactory is done! Default constructor" << std::endl;
}

// *****************************************************************   BuilderFactory(Cell*, string&, Player*)
BuilderFactory::BuilderFactory(Cell* c, std::string uT, Player* pl) : Factory(c, pl), unitType(uT)
{ 
  
}

// *****************************************************************   ~BuilderFactory()
BuilderFactory::~BuilderFactory()
{ std::cout << "   ~BuilderFactory is destroy!" << std::endl;
}

// ****************************************************************** getPlayer()
//Player* BuilderFactory::getPlayer()
//{ return this->Factory::getPlayer();
//}

// *****************************************************************   getUnit()
UnitCIVIL* BuilderFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c, Player* pl)
{
  Builder* ptr_unit = nullptr;
  if(unitType == "builder") ptr_unit = new Builder(st, tOT, unitType, h, d, def, c, pl);
  
  cout << "   Builder created!" << endl;
  pl->addToList(ptr_unit);
  
  return ptr_unit;
}

// **************************************************** toString()
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
/*  cout << " Printing from BuilderFactory save()" << endl;
  json j = {
  {"unitType", getUnitType()},
  {"Player", getPlayer()->getName()},
  {"x", getCell()->getX()},
  {"y", getCell()->getY()}
  };

  ofstream fout;
  fout.open(PATH_OF_SAVE, ofstream::app);
  if (!fout.is_open()) {cout << "Error of open file ..." << endl;}
  else  { fout << j << endl;} //  
  fout.close(); 
  cout << "   From builderFactory: object save successfully" << endl;
  cout << "   " << j << endl; // << setw(2) 
 */ 
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
  cout << "   unitType is \t" << this->unitType << endl;
  cout << "   Object coordinates: x = " << this->getCell()->getX() << ", y = " << this->getCell()->getY() << endl;
  cout << endl;
}