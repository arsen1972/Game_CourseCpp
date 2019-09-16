#include <string>
#include <iostream>

#include "../Unit/Civil/Builder.h"

#include "BuilderFactory.h"

#include "../Unit/Enums.h"
#include "../Unit/Unit.hpp"
#include "../Cell/Cell.h"


BuilderFactory::BuilderFactory()
{
  std::cout << "BuilderFactory is done!" << std::endl;
}

BuilderFactory::~BuilderFactory()
{
  std::cout << "BuilderFactory is destroy!" << std::endl;
}

UnitCIVIL* BuilderFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c)
{
  UnitCIVIL* ptr_unit = nullptr;
  //if(unitType == "builder")
  ptr_unit = new Builder(st, tOT, unitType, h, d, def, c);
  return ptr_unit;
}
