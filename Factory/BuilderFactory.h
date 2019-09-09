#pragma once

#include "Factory.h"
#include "../Unit/Unit.hpp"
#include <string>


class BuilderFactory : public Factory
{
public:
  BuilderFactory();
  ~BuilderFactory();
  Unit<Status, TypeOfTerrain>* getUnit(Status, TypeOfTerrain, std::string &, int, int, bool, Cell*);
};