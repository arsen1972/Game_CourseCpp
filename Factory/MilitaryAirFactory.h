#pragma once

#include "Factory.h"
#include "../Unit/Unit.h"
#include <string>


class MilitaryAirFactory : public Factory
{
public:
  MilitaryAirFactory();
  ~MilitaryAirFactory();
  Unit<Status, TypeOfTerrain>* getUnit(Status, TypeOfTerrain, string, int, int, bool, Cell*) override;
//  Unit* getUnit(const std::string &, std::string, int, int, bool, Cell*);

};