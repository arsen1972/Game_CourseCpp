#include <string>
#include "../Factory/Factory.h"
#include "../Factory/UniversalFactory.h"


using std::string;

Factory* getDepartment(const string& unitType)
{ 
  Factory* newDep;
  if (unitType == "universal") newDep = new UniversalFactory();

  return newDep;
}
