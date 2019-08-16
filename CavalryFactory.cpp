#include "CavalryFactory.h"
#include "Cavalry.h"
#include "Unit.h"
#include <string>
#include <iostream>

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


Unit* CavalryFactory::getUnit(const std::string& unitType)
{
  Unit* ptr_unit = nullptr;
  if(unitType == "cavalry")
  {
    ptr_unit = new Cavalry();
  }
  return ptr_unit;
}


Unit* CavalryFactory::getUnit(const std::string& unitType, int h, int d)
{
  Unit* ptr_unit = nullptr;
  if(unitType == "cavalry")
  {
    ptr_unit = new Cavalry(h, d);
  }
  return ptr_unit;
}