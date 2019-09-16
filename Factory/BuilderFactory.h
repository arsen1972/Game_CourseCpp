#pragma once

#include "Factory.h"
#include "../Unit/Unit.hpp"
#include "../Unit/Typedef.h"
#include <string>


class BuilderFactory : public Factory
{
public:
  BuilderFactory();
  ~BuilderFactory();
  UnitCIVIL* getUnit(Status, TypeOfTerrain, std::string &, int, int, bool, Cell*);
};