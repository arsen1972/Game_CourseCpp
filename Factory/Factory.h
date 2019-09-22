#pragma once
#include "../Unit/Unit.hpp"
//#include "../Unit/Civil/Builder.h"
//#include "../Unit/Enums.h"
#include "../Unit/Typedef.h"
#include "../Cell/Cell.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

class Factory
{
public:
  Factory();
  virtual ~Factory() = 0;
//  Unitt* getUnit(Status, TypeOfTerrain, string&, int, int, bool, Cell*);
  
private:
//  std::vector<Factory*>departments;
  Cell* cell;
  
};