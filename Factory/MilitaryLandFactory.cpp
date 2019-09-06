#include <string>
#include <iostream>

#include "MilitaryLandFactory.h"
#include "../Unit/Military/Land/Cavalry.h"
#include "../Unit/Military/Land/Infantry.h"

#include "../Unit/Unit.h"
#include "../Cell/Cell.h"


MilitaryLandFactory::MilitaryLandFactory()
{//LOG_TRACE
}

MilitaryLandFactory::~MilitaryLandFactory()
{//LOG_TRACE
}

Unit* <Status, TypeOfTerrain> MilitaryLandFactory::getUnit(Status st, TypeOfTerrain tOT, const std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unit<Status, TypeOfTerrain>* ptr_unit = nullptr;
  if(unitType == "cavalry") ptr_unit = new Cavalry(st, tOT, unitType, h, d, def, c);
  else if(unitType == "infantry") ptr_unit = new Infantry(st, tOT, unitType, h, d, def, c);
  
  return ptr_unit;
}

