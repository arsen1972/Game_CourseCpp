#include "Factory.h"
#include "../Unit/Unit.h"
#include "../Cell/Cell.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// *****************************************************************   Factory()
Factory::Factory()
{ //LOG_TRACE
}

// *****************************************************************   ~Factory()
Factory::~Factory()
{ //LOG_TRACE
  std::for_each(departments.begin(), departments.end(), [](Factory* ptr_factory){ delete ptr_factory;} );
}

// *****************************************************************   getUnit(const std::string & unitType)
Unit* Factory::getUnit(const std::string & unitType)
{
  Unit* ptr_unit = nullptr;
  std::vector<Factory*>::iterator iter = departments.begin();
  
  while ( ptr_unit == nullptr && iter != departments.end() )
  {
    ptr_unit = (*iter)->getUnit(unitType);
    ++iter;
  }
  return ptr_unit;
}

// ***************************************************    getUnit(const std::string & unitType, int h, int d)
Unit* Factory::getUnit(const std::string & unitType, int h, int d)
{
  Unit* ptr_unit = nullptr;
  std::vector<Factory*>::iterator iter = departments.begin();
  
  while ( ptr_unit == nullptr && iter != departments.end() )
  {
    ptr_unit = (*iter)->getUnit(unitType, h, d);
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