#pragma once
#include "../Unit.hpp"
#include "../Enums.h"
#include "../../Factory/Factory.h"
#include "../../Cell/Cell.h"
#include <map>
#include <string>


class Builder : public Unit<Status, TypeOfTerrain>
{
typedef Unit<Status, TypeOfTerrain> Unitt;

public:

  Builder(Status, TypeOfTerrain, string, int, int, bool, Cell*);
  ~Builder();
  string getUnitType() const override;
  void printUnitFields() const override;
  Cell* getCell() const override;
  Cell* getLands();
  Status getStatus() const override;
  TypeOfTerrain getTOT() const override;

  std::string getStatusString() const; // only for print
  Factory* buildBuilderFactory();
  
  int getAttackBonus();
  int getDefenceBonus();
  
protected:
  int getHealth() const override;
  void setHealth(int) override;
  int getDamage() const override;
  bool getDefence() const override;
  void move() override;

private:
  static map<string, int> unitAttackBonus; 
  static map<string, int> unitDefenceBonus;
};