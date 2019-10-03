#include <string>
#include <iostream>

#include "Factory.h"
#include "MedicFactory.h"
#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Medic.h"
#include "../Cell/Cell.h"
#include "../Player/Player.h"
#include "../ObjectGame/ObjectGame.h"

#include "../Json/json.hpp"
using json = nlohmann::json;


// *****************************************************************   MedicFactory()
MedicFactory::MedicFactory()
{ 
//  unitType = "MedicFactory";
//  cell = gameMap[1][1];

//std::cout << "   BuilderFactory is done! Default constructor" << std::endl;
}

// *****************************************************************   MedicFactory(Cell*, string&)
MedicFactory::MedicFactory(Cell* c, std::string uT, Player* pl) : Factory(c, pl), unitType(uT)
{ 
//  unitType = uT;
}

// *****************************************************************   ~MedicFactory()
MedicFactory::~MedicFactory()
{ std::cout << "   ~MedicFactory is destroy!" << std::endl;
}

// ****************************************************************** getPlayer()
//Player* MedicFactory::getPlayer()
//{ return this->Factory::getPlayer();
//}

// *****************************************************************   getUnit()
UnitCIVIL* MedicFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c, Player* pl)
{
  Medic* ptr_unit = nullptr;
  if(unitType == "medic") ptr_unit = new Medic(st, tOT, unitType, h, d, def, this->getCell(), pl);
  
  cout << "   Medic created!" << endl;
  pl->addToList(ptr_unit);
  
  return ptr_unit;
}

// **************************************************** toString()
string MedicFactory::toString() const
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
void MedicFactory::save() const
{ 
/*  cout << " Printing from MedicFactory save()" << endl;
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
std::string MedicFactory::getUnitType() const
{ return this->unitType;
}

// **************************************************  setUnitType(string&)
void MedicFactory::setUnitType(string& uT)
{ 
  unitType = uT;
  return;
}

// **************************************************** printUnitFields()
void MedicFactory::printUnitFields() const
{ 
  cout << "   From MedicFactory:" << endl;
  cout << "   unitType is \t" << this->unitType << endl;
  cout << "   Object coordinates: x = " << this->getCell()->getX() << ", y = " << this->getCell()->getY() << endl;
  cout << endl;
}