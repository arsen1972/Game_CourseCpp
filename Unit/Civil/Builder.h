#pragma once

#include <map>
#include <string>

#include "../Unit.hpp"
#include "../Enums.h"
#include "../Typedef.h"
#include "../../Factory/Factory.h"
#include "../../Factory/BuilderFactory.h"
#include "../../Cell/Cell.h"

class BuilderFactory;

class Builder : public UnitCIVIL // typedef Unit<CIVIL, TypeOfTerrain> UnitCIVIL;
{
public:
  Builder(Status, TypeOfTerrain, string, int, int, bool, Cell*);
  ~Builder();
  string getUnitType() const override;
  Cell* getCell() const override;
  Cell* getLands() const;
  Status getStatus() const override;
  std::string getStatusString() const; // only for print
  TypeOfTerrain getTOT() const override;
  void printUnitFields() const override;
  void move() override;
  void save() override;
  
// *************************************************  add method() 
  UnitCIVIL* load() override;
  BuilderFactory* buildBuilderFactory() override;
  BuilderFactory* buildBuilderFactory(int x, int y) override;
  
  int getAttackBonus();
  int getDefenceBonus();
  
protected:
  int getHealth() const override;
  void setHealth(int) override;
  int getDamage() const override;
  bool getDefence() const override;

private:
  static map<string, int> unitAttackBonus; 
  static map<string, int> unitDefenceBonus;
};
