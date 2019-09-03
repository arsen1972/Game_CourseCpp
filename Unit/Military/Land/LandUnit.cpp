#include <iostream>
#include <string>
#include <map>
#include "Cavalry.h"
#include "../../../Cell/Cell.h"
#include "../../Unit.h"
#include "../Military.h"

using std::map;
using std::string;
using std::cout;
using std::endl;


// ***************************************************** LandUnit(int, int, bool, Cell*)
LandUnit::LandUnit(int h, int d, bool def, Cell* c) : Military(h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** LandUnit(string, int, int, bool, Cell*)
LandUnit::LandUnit(string uT, int h, int d, bool def, Cell* c) : Military(uT, h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** ~LandUnit()
LandUnit::~LandUnit()
{ //LOG_TRACE
}