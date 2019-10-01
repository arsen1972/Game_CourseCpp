#include <string>
#include <iostream>

#include "Factory.h"
#include "MedicFactory.h"
#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Medic.h"
#include "../Cell/Cell.h"

#include "../Save/pathOfSave.h"
#include "../Json/json.hpp"
using json = nlohmann::json;


//#include "../Unit/Enums.h"

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
  if(unitType == "medic") ptr_unit = new Medic(st, tOT, unitType, h, d, def, c, pl);
  return ptr_unit;
}

// *****************************************************************   save()
void MedicFactory::save() const
{ 
//  cout << " Printing from MedicFactory save()" << endl;
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