#pragma once
#include "../Unit.h"
#include "../../Factory/Factory.h"
#include "../../Cell/Cell.h"
#include <map>
#include <string>


class Atlant : public Unit
{

public:

  Atlant(Status, TypeOfTerrain, string, int, int, bool, Cell*);
  ~Atlant();
  
  void buildBuilderFactory();
  void buildMedicFactory();
  void buildAtlantFactory();
  
  int doHeal(Unit<Status, TypeOfTerrain>*);
  
//  void printUnitFields() override const;
  
protected:

private:
  
};