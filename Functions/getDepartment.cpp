#include <string>
#include "../Factory/Factory.h"
#include "../Factory/CavalryFactory.h"

Factory* getDepartment(const std::string& unitType)
{
  //LOG_TRACE
  return unitType == "cavalry" ? new CavalryFactory() : nullptr;
}