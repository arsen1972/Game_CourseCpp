#include <string>
#include "../Factory/Factory.h"
#include "../Factory/AtlantFactory.h"
#include "../Factory/BuilderFactory.h"
//#include "../Factory/MilitaryLandFactory.h"


using std::string;

Factory* getDepartment(const string& unitType)
{ 

  Factory* newDep;
  if (unitType == "atlant") newDep = new AtlantFactory();
  else if (unitType == "builder") newDep = new BuilderFactory();
//  else if (unitType == "medic") newDep = new MedicFactory();
//  else if (unitType == "cavalry") newDep = new MilitaryLandFactory();

  return newDep;
}
