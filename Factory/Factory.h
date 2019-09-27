#pragma once
#include "../Unit/Unit.hpp"
#include "../Player/Player.h"
#include "../ObjectGame/ObjectGame.h"
//#include "../Unit/Civil/Builder.h"
//#include "../Unit/Enums.h"
#include "../Unit/Typedef.h"
#include "../Cell/Cell.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

class Player;
class Factory : public ObjectGame
{
public:
  Factory();
  virtual ~Factory() = 0;
  virtual UnitCIVIL* getUnit(Status, TypeOfTerrain, string&, int, int, bool, Cell*);
  virtual void save();
  
private:
  string factoryType;
  Cell* cell;
  Player* playerName;
};