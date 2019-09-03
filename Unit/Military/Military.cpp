#include <iostream>
#include <string>
#include <map>
#include "Military.h"
#include "../../Cell/Cell.h"
#include "../Unit.h"
using std::map;
using std::string;
using std::cout;
using std::endl;


// ***************************************************** Military(int, int, bool, Cell*)
Military::Military(int h, int d, bool def, Cell* c) : Unit(h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** Military(string, int, int, bool, Cell*)
Military::Military(string uT, int h, int d, bool def, Cell* c) : Unit(uT, h, d, def, c)
{ //LOG_TRACE
}

// ***************************************************** ~Military()
Military::~Military()
{ //LOG_TRACE
}