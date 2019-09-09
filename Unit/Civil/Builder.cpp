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
{ return this->Unit<Status, TypeOfTerrain>::getUnitType();
}

// ***************************************************** printUnitFields()
void Builder::printUnitFields() const
{
  cout << "Printing here!!! From Builder" << endl;
//  cout << "unitType is \t" << this->getUnitType() << endl;
//  cout << "Health = \t" << this->getHealth() << endl;
//  cout << "Damage = \t" << this->getDamage() << endl;
//  cout << "Defence = \t" << this->getDefence() << endl;
//  cout << "Bonus factor = \t" << this->getCell()->getLands() << endl;
  cout << endl;
}
/*
// **************************************************** buildBuilderFactory()
void Builder::buildBuilderFactory() //BuilderFactory* buildBuilderFactory()
{
 cout << "BuilderFactory done!" << endl;
 return;                   // new BuilderFactory(get... Civil);
}

// **************************************************** buildMedicFactory()
void Builder::buildMedicFactory() 
{
 cout << "MedicFactory done!" << endl;
 return;
}

// **************************************************** buildAtlantFactory()
void Builder::buildAtlantFactory() 
{
 cout << "AtlantFactory done!" << endl;
 return;
}

// **************************************************** printUnitFields()
void Builder::printUnitFields()
{
  cout << "unitType is \t" << this->getUnitType() << endl;
  cout << "Health = \t" << this->getHealth() << endl;
  cout << endl;
}
*/