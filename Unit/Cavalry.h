#pragma once
#include "Unit.h"
#include "../Cell/Cell.h"
#include <map>
#include <string>
using std::string;
using std::map;

class Cavalry : public Unit
{

public:

//  Cavalry();
  Cavalry(int, int, bool, Cell*);
  
  ~Cavalry();
  
  void move(int);
  int getAttackBonus();
  int getDefenceBonus();
  Cell* getLands();
  
  
private:

  static map<string, int> unitAttackBonus; 
  static map<string, int> unitDefenceBonus; 
};
