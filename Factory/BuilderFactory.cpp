#include <string>
#include <iostream>

#include "BuilderFactory.h"
#include "../Unit/Civil/Builder.h"
#include "../Unit/Unit.h"
#include "../Cell/Cell.h"


BuilderFactory::BuilderFactory()
{
  //LOG_TRACE
  //std::cout << "The stable is ready!" << std::endl;
}

BuilderFactory::~BuilderFactory()
{ 
  //LOG_TRACE
  //std::cout << "~Stable destroyed" << std::endl;
}
/*
Unit* BuilderFactory::getUnit(const std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unit* ptr_unit = nullptr;
  if(unitType == "cavalry")
  {
    ptr_unit = new Cavalry(h, d, def, c);
  }
  return ptr_unit;
}
*/
Unit* BuilderFactory::getUnit(const std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unit* ptr_unit = nullptr;
  if(unitType == "builder")
  { 
    ptr_unit = new Builder(unitType, h, d, def, c);
  }
  return ptr_unit;
}

