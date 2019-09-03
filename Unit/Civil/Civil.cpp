#include <iostream>
#include <string>
#include <map>
#include "Civil.h"
#include "../../Cell/Cell.h"
#include "../Unit.h"
using std::map;
using std::string;
using std::cout;
using std::endl;


// ***************************************************** Cavalry(int, int, bool, Cell*)
Civil::Civil(int h, int d, bool def, Cell* c) : Unit(h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** Cavalry(string, int, int, bool, Cell*)
Civil::Civil(string uT, int h, int d, bool def, Cell* c) : Unit(uT, h, d, def, c)
{ //LOG_TRACE
}
// ***************************************************** ~Civil()
Civil::~Civil()
{
}