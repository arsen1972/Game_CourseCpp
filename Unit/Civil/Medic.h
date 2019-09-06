#pragma once
#include "../Unit.h"
#include "../../Factory/Factory.h"
#include "../../Cell/Cell.h"
#include <map>
#include <string>


class Medic : public Unit
{

public:

  Medic(Status, TypeOfTerrain, string, int, int, bool, Cell*);
  ~Medic();
  
  int doHeal(Unit<Status, TypeOfTerrain>*);
//  void printUnitFields() override;
  
protected:

private:
  int heal = 25;
};