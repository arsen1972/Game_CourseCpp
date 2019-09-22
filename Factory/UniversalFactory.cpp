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

UniversalFactory::UniversalFactory(int x, int y) : x(x), y(y)
{
  std::cout << "UniversalFactory coordinates is done!" << std::endl;
}

UniversalFactory::~UniversalFactory()
{
  std::cout << "UniversalFactory is destroy!" << std::endl;
}

Unitt* UniversalFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unitt* ptr_unit = nullptr;
  if(unitType == "universal") ptr_unit = new Universal(st, tOT, unitType, h, d, def, c);
  return ptr_unit;
}
