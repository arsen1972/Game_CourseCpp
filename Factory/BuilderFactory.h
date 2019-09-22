#pragma once

#include "Factory.h"
//#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Builder.h"
#include "../Unit/Typedef.h"

#include <string>

class BuilderFactory : public Factory
{
public:
  BuilderFactory();
  BuilderFactory(int x, int y);
  ~BuilderFactory();
  UnitCIVIL* getUnit(Status, TypeOfTerrain, std::string &, int, int, bool, Cell*);
  
private:
  int x;
  int y;
};