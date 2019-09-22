#pragma once

#include <map>
#include <string>

#include "../Unit.hpp"
#include "../Enums.h"
#include "../Typedef.h"
#include "../../Factory/Factory.h"
#include "../../Factory/BuilderFactory.h"
#include "../../Cell/Cell.h"

class Universal : public Unitt // typedef Unit<Status, TypeOfTerrain> Unitt;
{

public:

  Universal(Status, TypeOfTerrain, string, int, int, bool, Cell*);
  ~Universal();
  string getUnitType() const override;
  void printUnitFields() const override;
  Cell* getCell() const override;
  Cell* getLands();
  Status getStatus() const override;
  TypeOfTerrain getTOT() const override;
//  void buildBuilderFactory() override;
    
  std::string getStatusString() const; // only for print

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