#include "Factory.h"
#include "../Unit/Unit.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

Factory::Factory()
{ //LOG_TRACE
}

Factory::~Factory()
{ //LOG_TRACE
  std::for_each(departments.begin(), departments.end(), [](Factory* ptr_factory){ delete ptr_factory;} );
}

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
void Factory::addDepartment(Factory* ptr_factory)
{
  departments.push_back(ptr_factory);
  return;
}