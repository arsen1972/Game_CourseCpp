#include <string>
#include <iostream>

#include "MilitaryNavyFactory.h"
#include "../Unit/Military/Navy/Linkor.h"
#include "../Unit/Military/Navy/Fregat.h"

#include "../Unit/Unit.h"
#include "../Cell/Cell.h"


MilitaryNavyFactory::MilitaryNavyFactory()
{//LOG_TRACE
}

MilitaryNavyFactory::~MilitaryNavyFactory()
{//LOG_TRACE
}

Unit* <Status, TypeOfTerrain> MilitaryNavyFactory::getUnit(Status st, TypeOfTerrain tOT, const std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unit<Status, TypeOfTerrain>* ptr_unit = nullptr;
  if(unitType == "linkor") ptr_unit = new Linkor(st, tOT, unitType, h, d, def, c);
  else if(unitType == "fregat") ptr_unit = new Fregat(st, tOT, unitType, h, d, def, c);
  
  return ptr_unit;
}

