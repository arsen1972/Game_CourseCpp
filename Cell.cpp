#include <iostream>
#include "Cell.h"


// **************************************************** Cell()
Cell::Cell() : landscape(10)
{ //LOG_TRACE
}

// **************************************************** ~Cell()
Cell::~Cell()
{ //LOG_TRACE
}

//***************************************************** getLandscape()
int Cell::getLandscape()
{
  return this->landscape;
}
