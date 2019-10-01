#pragma once

#include <string>
#include <memory>

#include "Factory.h"
//#include "../Unit/Unit.hpp"
#include "../Unit/Civil/Medic.h"
#include "../Unit/Typedef.h"

class MedicFactory : public Factory
{
public:
  MedicFactory();
  MedicFactory(Cell*, std::string, Player*);
  ~MedicFactory();
  UnitCIVIL* getUnit(Status, TypeOfTerrain, std::string &, int, int, bool, Cell*, Player*) override;
  std::string getUnitType() const;
  void setUnitType(string&);
//  Player* getPlayer() override;
  void save() const override;
  
private:
  std::string unitType;
  
};