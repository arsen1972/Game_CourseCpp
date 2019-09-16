#include "Factory.h"
#include "../Unit/Unit.hpp"
#include "../Cell/Cell.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;

// *****************************************************************   Factory()
Factory::Factory()
{ //LOG_TRACE
}

// *****************************************************************   ~Factory()
Factory::~Factory()
{ //LOG_TRACE
  //std::for_each(departments.begin(), departments.end(), [](Factory* ptr_factory){ delete ptr_factory;} );
}

/*// ************************************************** getUnit(Status, TypeOfTerrain, unitType, h, d, def,c)
Unitt* Factory::getUnit(Status st, TypeOfTerrain tOT, string& unitType, int h, int d, bool def, Cell* c)
{
  Unitt* ptr_unit = nullptr;
  std::vector<Factory*>::iterator iter = departments.begin();
  
  while ( ptr_unit == nullptr && iter != departments.end() )
  {
    ptr_unit = (*iter)->getUnit(st, tOT, unitType, h, d, def, c);
    ++iter;
  }
  return ptr_unit;
}
*/
/*
// *****************************************************   getUnit(const std::string & unitType)
void Factory::addDepartment(Factory* ptr_factory)
{
  departments.push_back(ptr_factory);
  return;
}
*/