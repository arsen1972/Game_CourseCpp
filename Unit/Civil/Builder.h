#pragma once

#include <string>
#include <memory>

#include "../Unit.hpp"
#include "../Enums.h"
#include "../Typedef.h"
#include "../../Factory/Factory.h"
#include "../../Factory/BuilderFactory.h"
#include "../../Factory/MedicFactory.h"
#include "../../Cell/Cell.h"

class BuilderFactory;

class Builder : public UnitCIVIL // typedef Unit<CIVIL, TypeOfTerrain> UnitCIVIL;
{
public:
  Builder(Status, TypeOfTerrain, string, int, int, bool, Cell*, Player*);
  ~Builder();
  string getUnitType() const override;
  Cell* getCell() const override;
  void setCell(Cell*) override;
  Player* getPlayer() const override;
  Cell* getLands() const;
  Status getStatus() const override;
  std::string getStatusString() const; // only for print
  TypeOfTerrain getTOT() const override;
  void printUnitFields() const override;
  void move(Cell*) override;
  void save() const override;
  
// *************************************************  add method() 
//  UnitCIVIL* load() override;
  Factory* buildBuilderFactory() override;
  Factory* buildMedicFactory() override;
  
//  Factory* buildBuilderFactory(Cell*, std::string, Player*) override;
//  Factory* buildMedicFactory(Cell*, std::string, Player*) override;
  
  
protected:
  int getHealth() const override;
  void setHealth(int) override;
  int getDamage() const override;
  bool getDefence() const override;

private:

};
