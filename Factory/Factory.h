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
  Factory(Cell*);
  virtual ~Factory() = 0;
  virtual UnitCIVIL* getUnit(Status, TypeOfTerrain, string&, int, int, bool, Cell*);
  virtual void save();
  
protected:
  virtual Cell* getCell() const;
  
//  virtual Player* getPlayer() const;
  
private:
  Cell* cell;
//  string factoryType;
//  Player* player;
};