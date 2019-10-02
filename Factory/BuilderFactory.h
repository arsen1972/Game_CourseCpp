#pragma once

#include <string>
#include <memory>

#include "Factory.h"
//#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Builder.h"
#include "../Unit/Typedef.h"

using std::string;

class BuilderFactory : public Factory
{
public:
  BuilderFactory();
  BuilderFactory(Cell*, std::string, Player*);
  ~BuilderFactory();
  UnitCIVIL* getUnit(Status, TypeOfTerrain, string &, int, int, bool, Cell*, Player*) override;
  string getUnitType() const;
  void setUnitType(string&);
  void save() const override;
  string toString() const override;
  void printUnitFields() const override;
  
private:
  string unitType;
  
};