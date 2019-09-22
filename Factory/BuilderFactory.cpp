#include "BuilderFactory.h"
#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Builder.h"
#include "../Cell/Cell.h"

#include <string>
#include <iostream>

//#include "../Unit/Enums.h"

BuilderFactory::BuilderFactory()
{ std::cout << "   BuilderFactory is done! Default constructor" << std::endl;
}

BuilderFactory::BuilderFactory(int x, int y) : x(x), y(y)
{ std::cout << "   BuilderFactory (coordinates) is done!" << std::endl;
}

BuilderFactory::~BuilderFactory()
{ std::cout << "   ~BuilderFactory is destroy!" << std::endl;
}

UnitCIVIL* BuilderFactory::getUnit(Status st, TypeOfTerrain tOT, std::string & unitType, int h, int d, bool def, Cell* c)
{
  Builder* ptr_unit = nullptr;
  if(unitType == "builder") ptr_unit = new Builder(st, tOT, unitType, h, d, def, c);
  // добавить сразу пуш_бэк в лист указателей юнитов - обернуть этот метод и пушБэк в еще одну оболочку
  
  return ptr_unit;
}