#include <iostream>
#include <string>
#include "Cell.h"
using std::string;

// **************************************************** Cell()
Cell::Cell()
{ this->lands = "empty";
//LOG_TRACE
}
// **************************************************** Cell(string)
Cell::Cell(string l = "empty") : lands(l)
{ 
  this->lands = l;
}
// **************************************************** ~Cell()
Cell::~Cell()
{ //LOG_TRACE
}
// ************************************************  getLands()
string Cell::getLands() const
{
  return this->lands;
}