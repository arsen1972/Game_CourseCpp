#include "Factory.h"
#include "../Unit/Unit.h"
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
  std::for_each(departments.begin(), departments.end(), [](Factory* ptr_factory){ delete ptr_factory;} );
}

// **************************************************    getUnit(const std::string & unitType, int h, int d, bool def, Cell* c)
Unit* Factory::getUnit(const std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unit* ptr_unit = nullptr;
  std::vector<Factory*>::iterator iter = departments.begin();
  
  while ( ptr_unit == nullptr && iter != departments.end() )
  {
    ptr_unit = (*iter)->getUnit(unitType, h, d, def, c);
    ++iter;
  }
  return ptr_unit;
}
// *****************************************************   getUnit(const std::string & unitType)
void Factory::addDepartment(Factory* ptr_factory)
{
  departments.push_back(ptr_factory);
  return;
}