#pragma once
#include "../Unit.hpp"
#include "../Enums.h"
#include "../../Factory/Factory.h"
#include "../../Cell/Cell.h"
#include <map>
#include <string>


class Builder : public Unit<Status, TypeOfTerrain>
{
typedef Unit<Status, TypeOfTerrain> Unitt;

public:

  Builder(Status, TypeOfTerrain, string, int, int, bool, Cell*);
  ~Builder();
  
//  void printUnitFields() override;

/*  
  BuilderFactory* buildBuilderFactory();
  MedicFactory* buildMedicFactory();
  AtlantFactory* buildAtlantFactory();

  
protected:
  void buildBuilderFactory();
  void buildMedicFactory();
  void buildAtlantFactory();

private:
  
*/
};