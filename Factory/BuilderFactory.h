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
  BuilderFactory(Cell*, std::string, Player*);
  ~BuilderFactory();
  UnitCIVIL* getUnit(Status, TypeOfTerrain, std::string &, int, int, bool, Cell*, Player*) override;
  std::string getUnitType() const;
  void setUnitType(string&);
//  Player* getPlayer() override;
  void save() const override;
  
private:
  std::string unitType;
  
};