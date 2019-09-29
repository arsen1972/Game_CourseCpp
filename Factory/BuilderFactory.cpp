#include <string>
#include <iostream>

#include "BuilderFactory.h"
#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Builder.h"
#include "../Cell/Cell.h"


#define PATH_OF_SAVE "Save/save.json"
#include "../Json/json.hpp"
using json = nlohmann::json;


//#include "../Unit/Enums.h"

// *****************************************************************   BuilderFactory()
BuilderFactory::BuilderFactory()
{ 
//  unitType = "BuilderFactory";
//  cell = gameMap[1][1];

//std::cout << "   BuilderFactory is done! Default constructor" << std::endl;
}

// *****************************************************************   BuilderFactory(Cell*, string&)
BuilderFactory::BuilderFactory(Cell* c, std::string uT) : Factory(c), unitType(uT)
{ 
  
}

// *****************************************************************   ~BuilderFactory()
BuilderFactory::~BuilderFactory()
{ std::cout << "   ~BuilderFactory is destroy!" << std::endl;
}

// *****************************************************************   getUnit()
UnitCIVIL* BuilderFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c)
{
  Builder* ptr_unit = nullptr;
  if(unitType == "builder") ptr_unit = new Builder(st, tOT, unitType, h, d, def, c);
  return ptr_unit;
}

// *****************************************************************   save()
void BuilderFactory::save() const
{ 
//  cout << " Printing from BuilderFactory save()" << endl;
  json j = {
  {"unitType", getUnitType()},
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
std::string BuilderFactory::getUnitType() const
{ return this->unitType;
}

// **************************************************  setUnitType(string&)
void BuilderFactory::setUnitType(string& uT)
{ 
  unitType = uT;
  return;
}