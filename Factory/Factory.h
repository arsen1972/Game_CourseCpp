#pragma once
#include "../Unit/Unit.h"
#include "../Unit/Enums.h"
#include "../Cell/Cell.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class Factory
{
public:
  Factory();
  virtual ~Factory();
  virtual Unit<Status, TypeOfTerrain>* getUnit(Status, TypeOfTerrain, string, int, int, bool, Cell*);
  void addDepartment(Factory*);
  
private:
  vector<Factory*>departments;
};