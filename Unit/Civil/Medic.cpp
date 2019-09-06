#include <iostream>
#include <string>

#include "../../Cell/Cell.h"
#include "../Unit.h"
using std::map;
using std::string;
using std::cout;
using std::endl;


// ***************************************************** Medic(string, int, int, bool, Cell*)
Medic::Medic(Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : Unit(st, tOT, uT, h, d, def, c)
{ 
}

// ***************************************************** ~Medic()
Medic::~Medic()
{ 
}

// ***************************************************** int heal(Unit* ptr_Unit)
int heal(Unit<Status, TypeOfTerrain>* ptr_Unit)
{
  return ptr_Unit->getHealth() + heal;
}
/*// ***************************************************** printUnitFields()
void printUnitFields()
{
  cout << "unitType:\t" << this->unitType << endl;
  cout << "health:\t" << this->health << endl;
  cout << "damage:\t" << "ZERO" << endl;
  cout << "defence:\t" << "ZERO" << endl;
  cout << "Heal:\t" << this->heal << endl;
}*/