#pragma once
#include "../Unit.h"
#include "../../Cell/Cell.h"
#include <map>
#include <string>


class Civil : public Unit
{

public:

  Civil(int, int, bool, Cell*);
  Civil(string, int, int, bool, Cell*);
  ~Civil();
  
};