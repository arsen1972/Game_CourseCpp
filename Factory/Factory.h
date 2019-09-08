#pragma once
#include "../Unit/Unit.hpp"
#include "../Unit/Enums.h"
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
  virtual ~Factory();
  virtual Unit<Status, TypeOfTerrain>* getUnit(Status, TypeOfTerrain, string&, int, int, bool, Cell*);
  //Unit<Status, TypeOfTerrain>* Factory::getUnit(Status, TypeOfTerrain, string &, int h, int d, bool def, Cell* c)
  void addDepartment(Factory*);
  
private:
  vector<Factory*>departments;
};