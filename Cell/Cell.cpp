#include <iostream>
#include <string>
#include "Cell.h"
using std::string;

// **************************************************** Cell()
Cell::Cell() 
{ this->lands = "sea";
  this->X = 0;
  this->Y = 0;
}
// **************************************************** Cell(string, int, int)
Cell::Cell(string l, int x, int y) : lands(l), X(x), Y(y)
{
}
// **************************************************** ~Cell()
Cell::~Cell()
{ //LOG_TRACE
}
// ************************************************  getLands()
string Cell::getLands() const
{ return this->lands;
}

// ************************************************  getX()
int Cell::getX() const
{ return this->X;
}

// ************************************************  getY()
int Cell::getY() const
{ return this->Y;
}

// ************************************************  vector<vector<Cell*>> initializ
