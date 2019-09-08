#pragma once

#include "Factory.h"
#include "../Unit/Unit.hpp"
#include <string>


class BuilderFactory : public Factory
{
public:
  BuilderFactory();
  ~BuilderFactory();
//  Unit<Status, TypeOfTerrain>* getUnit(Status, TypeOfTerrain, string, int, int, bool, Cell*);
//  Unit* getUnit(const std::string &, std::string, int, int, bool, Cell*);

};