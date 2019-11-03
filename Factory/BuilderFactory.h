#pragma once

#include <string>
#include <memory>

#include "Factory.h"
#include "../Unit/Civil/Builder.h"
#include "../Unit/Typedef.h"
#include "../ObjectGame/ObjectGame.h"

using std::string;

class BuilderFactory : public Factory
{
public:
  BuilderFactory();
  BuilderFactory(Cell*, string&, Player*);
  ~BuilderFactory();
  UnitCIVIL* getUnit(Status, TypeOfTerrain, string &, int, int, bool, Cell*, Player*) override;
  string getUnitType() const override;
  void setUnitType(string&);
  void save() const override;
  string toString() const override;
  void printUnitFields() const override;
  void doAction() override;
  
private:
//  string unitType;
  
};