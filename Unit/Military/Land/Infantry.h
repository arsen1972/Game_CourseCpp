#pragma once
#include "../../Unit.h"
#include "LandUnit.h"
#include "../../../Cell/Cell.h"
#include <map>
#include <string>


class Infantry: public Unit
{

public:

  Infantry(Status, TypeOfTerrain, string, int, int, bool, Cell*);
  ~Infantry() override;
  
  void move(int);
  
  
protected:

  std::map<std::string, int> getAttackMap() override;
  std::map<std::string, int> getDefenceMap() override;

private:
  
  static std::map<std::string, int> unitAttackBonus; 
  static std::map<std::string, int> unitDefenceBonus;
};