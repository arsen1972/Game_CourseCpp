#pragma once
#include "../../Unit.h"
#include "../Military.h"
#include "../../../Cell/Cell.h"
#include <map>
#include <string>


class LandUnit : public Military
{

public:

  LandUnit(int, int, bool, Cell*);
  LandUnit(string, int, int, bool, Cell*);
  ~LandUnit();
  

};