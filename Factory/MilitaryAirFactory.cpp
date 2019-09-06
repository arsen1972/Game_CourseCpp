#include <string>
#include <iostream>

#include "MilitaryAirFactory.h"
#include "../Unit/Military/Air/Helicopter.h"
#include "../Unit/Military/Air/Deltaplain.h"

#include "../Unit/Unit.h"
#include "../Cell/Cell.h"


MilitaryAirFactory::MilitaryAirFactory()
{//LOG_TRACE
}

MilitaryAirFactory::~MilitaryAirFactory()
{//LOG_TRACE
}

Unit* <Status, TypeOfTerrain> MilitaryAirFactory::getUnit(Status st, TypeOfTerrain tOT, const std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unit<Status, TypeOfTerrain>* ptr_unit = nullptr;
  if(unitType == "helicopter") ptr_unit = new Helicopter(st, tOT, unitType, h, d, def, c);
  else if(unitType == "deltaplain") ptr_unit = new Deltaplain(st, tOT, unitType, h, d, def, c);
  
  return ptr_unit;
}

