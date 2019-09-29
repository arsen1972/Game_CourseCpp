#pragma once

#include <string>

#include "Factory.h"
//#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Builder.h"
#include "../Unit/Typedef.h"

class BuilderFactory : public Factory
{
public:
  BuilderFactory();
  BuilderFactory(Cell*, std::string);
  ~BuilderFactory();
  UnitCIVIL* getUnit(Status, TypeOfTerrain, std::string &, int, int, bool, Cell*) override;
  std::string getUnitType() const;
  void setUnitType(string&);
  void save() const override;
  
private:
  std::string unitType;
  
};