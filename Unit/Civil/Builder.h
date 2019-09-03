#pragma once
#include "../Unit.h"
#include "Civil.h"
#include "../../Cell/Cell.h"
#include "../../Factory/Factory.h"
#include <map>
#include <string>


class Builder : public Civil
{

public:

  Builder(int, int, bool, Cell*);
  Builder(string, int, int, bool, Cell*);
  ~Builder();
  
  void move(int);
  void buildFactory(string);
 
protected:

  std::map<std::string, int> getAttackMap();
  std::map<std::string, int> getDefenceMap();

private:
  
  static std::map<std::string, int> unitAttackBonus; 
  static std::map<std::string, int> unitDefenceBonus;
};