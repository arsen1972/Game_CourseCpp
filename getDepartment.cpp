#include <string>
#include "Factory.h"
#include "CavalryFactory.h"

Factory* getDepartment(const std::string& unitType)
{
  //LOG_TRACE
  return unitType == "cavalry" ? new CavalryFactory() : nullptr;
}