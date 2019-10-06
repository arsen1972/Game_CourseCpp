#pragma once

#include <string>
#include <memory>

#include "Factory.h"
#include "../Unit/Civil/Medic.h"
#include "../Unit/Typedef.h"

using std::string;

class MedicFactory : public Factory
{
public:
  MedicFactory();
  MedicFactory(Cell*, string, Player*);
  ~MedicFactory();
  UnitCIVIL* getUnit(Status, TypeOfTerrain, string &, int, int, bool, Cell*, Player*) override;
  string getUnitType() const;
  void setUnitType(string&);
  void save() const override;
  string toString() const override;
  void printUnitFields() const override;
  
private:
  string unitType;
  
};