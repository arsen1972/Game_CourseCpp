#include <iostream>
#include <string>
#include <map>
#include "Builder.h"
#include "../../Cell/Cell.h"
//#include "../Military.h"
#include "../Unit.h"
using std::map;
using std::string;
using std::cout;
using std::endl;

// ***************************************************** Builder(string, int, int, bool, Cell*)
Builder::Builder(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : Unit(st, tOT, uT, h, d, def, c)
{ 
}

// ***************************************************** ~Builder()
Builder::~Builder()
{ 
}

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