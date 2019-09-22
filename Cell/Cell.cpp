#include <iostream>
#include <string>

#include "Cell.h"

using std::string;

// **************************************************** Cell()
Cell::Cell() 
{ 
  this->x = 0;
  this->y = 0;
  this->lands = "plain";
}

// **************************************************** Cell(string, int, int)
Cell::Cell(int x, int y, string l) : x(x), y(y), lands(l)
{}

// **************************************************** ~Cell()
Cell::~Cell()
{}

// ****************************************************  getX()
int Cell::getX() const
{ return this->x;}

// ****************************************************  getY()
int Cell::getY() const
{ return this->y;}

// ****************************************************  getLands()
string Cell::getLands() const
{ return this->lands;}