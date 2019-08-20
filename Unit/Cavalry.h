#pragma once
#include "Unit.h"
#include <map>
#include <string>
using std::string;
using std::map;

class Cavalry : public Unit
{

public:
  Cavalry();
  Cavalry(int, int);
  
  ~Cavalry();
  
  void move(int);
  
  int getAttackBonus(string);
  
  std::string getLands();
  
private:
static map<string, int>unitAttackBonus;
};

/*
unitAttackBonus["plain"] = 10;
unitAttackBonus["forest"] = 20;
unitAttackBonus["sea"] = -20;
*/