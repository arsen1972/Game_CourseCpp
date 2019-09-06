#pragma once

#include "Factory.h"
#include "../Unit/Unit.h"
#include <string>


class LandFactory : public Factory
{
public:
  LandFactory();
  ~LandFactory();
  Unit<Status, TypeOfTerrain>* getUnit(Status, TypeOfTerrain, string, int, int, bool, Cell*) override;
//  Unit* getUnit(const std::string &, std::string, int, int, bool, Cell*);

};