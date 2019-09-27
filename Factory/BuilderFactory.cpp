#include "BuilderFactory.h"
#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Builder.h"
#include "../Cell/Cell.h"

#include <string>
#include <iostream>

//#include "../Unit/Enums.h"

// *****************************************************************   BuilderFactory()
BuilderFactory::BuilderFactory()
{ //std::cout << "   BuilderFactory is done! Default constructor" << std::endl;
}

// *****************************************************************   ~BuilderFactory()
BuilderFactory::~BuilderFactory()
{ //std::cout << "   ~BuilderFactory is destroy!" << std::endl;
}

// *****************************************************************   getUnit()
UnitCIVIL* BuilderFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c)
{
  Builder* ptr_unit = nullptr;
  if(unitType == "builder") ptr_unit = new Builder(st, tOT, unitType, h, d, def, c);
  return ptr_unit;
}

// *****************************************************************   save()
void BuilderFactory::save()
{
  std::cout << "   BuilderFactory is save" << std::endl;
}