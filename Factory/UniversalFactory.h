#pragma once

#include "Factory.h"
#include "../Unit/Unit.hpp"
#include "../Unit/Typedef.h"
#include <string>


class UniversalFactory : public Factory
{
public:
  UniversalFactory();
  UniversalFactory(int x, int y);
  ~UniversalFactory();
  Unitt* getUnit(Status, TypeOfTerrain, std::string &, int, int, bool, Cell*);
  
private:
  int x;
  int y;
};