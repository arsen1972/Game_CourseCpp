#include "Factory.h"
//#include "../Unit/Unit.hpp"
//#include "../Cell/Cell.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;

// *****************************************************************   Factory()
Factory::Factory()
{ //cout << "   Factory is done" << endl;
}

// *****************************************************************   Factory(Cell*)
Factory::Factory(Cell* c) : cell(c)
{ //cout << "   Factory is done" << endl;
}

// *****************************************************************   Factory(Cell*, string, Player*)
Factory::Factory(Cell* c, string uT, Player* pl) : cell(c), unitType(uT), player(pl)
{ //cout << "   Factory is done" << endl;
} 
 
// *****************************************************************   ~Factory()
Factory::~Factory()
{ cout << "   ~Factory is destroy" << endl;
}

// ************************************************** getUnit(Status, TypeOfTerrain, unitType, h, d, def,c)
UnitCIVIL* Factory::getUnit(Status st, TypeOfTerrain tOT, string& unitType, int h, int d, bool def, Cell* c)
{ //  return ptr_unit;
}

// **************************************************  getCell()
Cell* Factory::getCell() const
{ return this->cell;
}

// **************************************************  getFactoryName()
string Factory::getFactoryName() const
{ return this->unitType;
}

// **************************************************  getPlayer()
Player* Factory::getPlayer() const
{ return this->player;
}

// ***************************************************************** save()
void Factory::save()
{ std::cout << "   Factory is save" << std::endl;
}