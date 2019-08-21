#include <string>
#include <iostream>

#include "CavalryFactory.h"
#include "../Unit/Cavalry.h"
#include "../Unit/Unit.h"
#include "../Cell/Cell.h"


CavalryFactory::CavalryFactory()
{
  //LOG_TRACE
  //std::cout << "The stable is ready!" << std::endl;
}

CavalryFactory::~CavalryFactory()
{ 
  //LOG_TRACE
  //std::cout << "~Stable destroyed" << std::endl;
}

Unit* CavalryFactory::getUnit(const std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unit* ptr_unit = nullptr;
  if(unitType == "cavalry")
  {
    ptr_unit = new Cavalry(h, d, def, c);
  }
  return ptr_unit;
}