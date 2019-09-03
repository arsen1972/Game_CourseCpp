#pragma once
#include "../Unit.h"
#include "../../Cell/Cell.h"
#include <map>
#include <string>


class Military : public Unit
{

public:

  Military(int, int, bool, Cell*);
  Military(string, int, int, bool, Cell*);
  ~Military();
  
};