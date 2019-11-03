#pragma once

#include "../Unit/Unit.hpp"
#include "../Player/Player.h"
#include "../ObjectGame/ObjectGame.h"
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
  Factory(Cell*, Player*);
  Factory(Cell*, string&, Player*);
  virtual ~Factory() = 0;
  virtual UnitCIVIL* getUnit(Status, TypeOfTerrain, string&, int, int, bool, Cell*, Player*);
  virtual void save();
  virtual string toString() const;
  virtual void printUnitFields() const;
  virtual string getUnitType() const override;
  virtual void doAction() override;
  
protected:
  Cell* getCell() const;
  Player* getPlayer() const;
  
private:
  Cell* cell;
  Player* player;
};