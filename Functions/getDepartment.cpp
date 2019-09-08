#include <string>
#include "../Factory/Factory.h"
#include "../Factory/BuilderFactory.h"


using std::string;

Factory* getDepartment(const string& unitType)
{ 
  Factory* newDep;
  if (unitType == "builder") newDep = new BuilderFactory();

  return newDep;
}
