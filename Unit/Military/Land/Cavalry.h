#pragma once
#include "../../Unit.h"
#include "LandUnit.h"
#include "../../../Cell/Cell.h"
#include <map>
#include <string>


class Cavalry : public LandUnit
{

public:

//  Cavalry();
  Cavalry(int, int, bool, Cell*);
  Cavalry(string, int, int, bool, Cell*);
  ~Cavalry();
  
  void move(int);
  
  
protected:

  std::map<std::string, int> getAttackMap();
  std::map<std::string, int> getDefenceMap();

private:
  
  static std::map<std::string, int> unitAttackBonus; 
  static std::map<std::string, int> unitDefenceBonus;
};