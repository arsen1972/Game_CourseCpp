#include <string>
#include "../Factory/Factory.h"
#include "../Factory/CavalryFactory.h"
#include "../Factory/BuilderFactory.h"
#include <map>

Factory* getDepartment(const std::string& unitType)
{ 
  Factory* newDep;
  if (unitType == "cavalry") newDep = new CavalryFactory();
  if (unitType == "builder") newDep = new BuilderFactory();
  
  return newDep;
}
