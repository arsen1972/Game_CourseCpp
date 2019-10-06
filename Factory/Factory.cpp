#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Factory.h"

using std::string;
using std::cout;
using std::endl;

// *****************************************************************   Factory()
Factory::Factory()
{ 
}

// *****************************************************************   Factory(Cell*)
Factory::Factory(Cell* c) : cell(c)
{ 
}

// *****************************************************************   Factory(Cell*, Player*)
Factory::Factory(Cell* c, Player* pl) : cell(c), player(pl)
{ 
} 
 
// *****************************************************************   ~Factory()
Factory::~Factory()
{ cout << "   ~Factory is destroy" << endl;
}

// ************************************************** getUnit(Status, TypeOfTerrain, unitType, h, d, def,c)
UnitCIVIL* Factory::getUnit(Status st, TypeOfTerrain tOT, string& unitType, int h, int d, bool def, Cell* c, Player* pl)
{ //  return ptr_unit;
}

// **************************************************  getCell()
Cell* Factory::getCell() const
{ return this->cell;
}

// **************************************************  getPlayer()
Player* Factory::getPlayer() const
{ return this->player;
}

// **************************************************** toString()
string Factory::toString() const
{
  string str = "from Factory";
  return str;
}

// ***************************************************************** save()
void Factory::save()
{ std::cout << "   Factory is save" << std::endl;
}

// **************************************************** printUnitFields()
void Factory::printUnitFields() const
{ 
  cout << "   From Factory virtual" << endl;
  cout << "   unitType is \t" << "Base Factory" << endl;
  cout << "   Object coordinates: x = " << this->getCell()->getX() << ", y = " << this->getCell()->getY() << endl;
  cout << endl;
}