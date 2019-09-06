#pragma once

#include "Factory.h"
#include "../Unit/Unit.h"
#include <string>


class AtlantFactory : public Factory
{
public:
  AtlantFactory();
  ~AtlantFactory();
  Unit<Status, TypeOfTerrain>* getUnit(Status, TypeOfTerrain, string, int, int, bool, Cell*) override;
//  Unit* getUnit(const std::string &, std::string, int, int, bool, Cell*);

};