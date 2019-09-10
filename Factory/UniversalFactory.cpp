#include <string>
#include <iostream>

#include "../Unit/Civil/Universal.h"

#include "UniversalFactory.h"

#include "../Unit/Enums.h"
#include "../Unit/Unit.hpp"
#include "../Cell/Cell.h"


UniversalFactory::UniversalFactory()
{
  std::cout << "UniversalFactory is done!" << std::endl;
}

UniversalFactory::~UniversalFactory()
{
}

Unit<Status, TypeOfTerrain>* UniversalFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unit<Status, TypeOfTerrain>* ptr_unit = nullptr;
  if(unitType == "universal") ptr_unit = new Universal(st, tOT, unitType, h, d, def, c);
//  else if(unitType == "medic") ptr_unit = new Medic(st, tOT, unitType, h, d, def, c);
//  else if(unitType == "atlant") ptr_unit = new Atlant(st, tOT, unitType, h, d, def, c);
//  else if(unitType == "cavalry") ptr_unit = new Cavalry(st, tOT, unitType, h, d, def, c);

  return ptr_unit;
}
