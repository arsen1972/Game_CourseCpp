#include <iostream>
#include <string>
#include <map>
#include "Atlant.h"
#include "../../Cell/Cell.h"
//#include "../Military.h"
#include "../Unit.h"
using std::map;
using std::string;
using std::cout;
using std::endl;


// ***************************************************** Atlant(string, int, int, bool, Cell*)
Atlant::Atlant(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : Unit(st, tOT, uT, h, d, def, c)
{ 
}

// ***************************************************** ~Atlant()
Atlant::~Atlant()
{ 
}

// **************************************************** buildBuilderFactory()
void Atlant::buildBuilderFactory() //BuilderFactory* buildBuilderFactory()
{
 cout << "BuilderFactory done!" << endl;
 return;                   // new BuilderFactory(get... Civil);
}

// **************************************************** buildMedicFactory()
void Atlant::buildMedicFactory() 
{
 cout << "MedicFactory done!" << endl;
 return;
}

// **************************************************** buildAtlantFactory()
void Atlant::buildAtlantFactory() 
{
 cout << "AtlantFactory done!" << endl;
 return;
}

/*// ***************************************************  printUnitFields()
void Atlant::printUnitFields()
{
  cout << "unitType is \t" << this->getUnitType() << endl;
  cout << "Health = \t" << this->getHealth() << endl;
  cout << "Damage = \t" << this->getDamage() << endl;
  cout << "Defence = \t" << this->getDefence() << endl;
  cout << "Bonus factor = \t" << this->getCell()->getLands() << endl;
  cout << "Heal:\t" << this->heal << endl;
  cout << endl;
}*/