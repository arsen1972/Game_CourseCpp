#pragma once

#include "Factory.h"
#include "../Unit/Unit.hpp"
#include <string>


class UniversalFactory : public Factory
{
public:
  UniversalFactory();
  ~UniversalFactory();
  Unit<Status, TypeOfTerrain>* getUnit(Status, TypeOfTerrain, std::string &, int, int, bool, Cell*);
};