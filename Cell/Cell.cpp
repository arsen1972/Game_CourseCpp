#include <iostream>
#include <string>
#include "Cell.h"
using std::string;

// **************************************************** Cell()
Cell::Cell() 
{ this->lands = "sea";  //LOG_TRACE
}
// **************************************************** Cell(string)
Cell::Cell(string l) : lands(l)
{ //LOG_TRACE
}
// **************************************************** ~Cell()
Cell::~Cell()
{ //LOG_TRACE
}
// ************************************************  getLands()
string Cell::getLands() const
{ return this->lands;
}