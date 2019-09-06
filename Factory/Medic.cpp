#include <string>
#include <iostream>

#include "../Unit/Civil/Builder.h"
#include "../Unit/Civil/Medic.h"
#include "../Unit/Civil/Atlant.h"
#include "../Unit/Military/Land/Cavalry.h"

#include "../Unit/Enums.h"
#include "../Unit/Unit.h"
#include "../Cell/Cell.h"


BuilderFactory::BuilderFactory()
{//LOG_TRACE
}

BuilderFactory::~BuilderFactory()
{//LOG_TRACE
}

Unit<Status, TypeOfTerrain>* BuilderFactory::getUnit(Status st, TypeOfTerrain tOT, const std::string & unitType, int h, int d, bool def, Cell* c)
{
  Unit<Status, TypeOfTerrain>* ptr_unit = nullptr;
  if(unitType == "builder") ptr_unit = new Builder(st, tOT, unitType, h, d, def, c);
  else if(unitType == "medic") ptr_unit = new Medic(st, tOT, unitType, h, d, def, c);
  else if(unitType == "atlant") ptr_unit = new Atlant(st, tOT, unitType, h, d, def, c);
  else if(unitType == "cavalry") ptr_unit = new Cavalry(st, tOT, unitType, h, d, def, c);

  return ptr_unit;
}

