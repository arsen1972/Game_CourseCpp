#pragma once

#include "Factory.h"
#include "../Unit/Unit.h"
#include <string>


class BuilderFactory : public Factory
{
public:
  BuilderFactory();
  ~BuilderFactory();
  Unit* getUnit(const std::string &, int, int, bool, Cell*);
  Unit* getUnit(const std::string &, std::string, int, int, bool, Cell*);

};