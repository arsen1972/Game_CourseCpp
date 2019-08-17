#include <iostream>
#include <string>
#include "Cell.h"

// **************************************************** Cell()
Cell::Cell()
{ //LOG_TRACE
}

// **************************************************** ~Cell()
Cell::~Cell()
{ //LOG_TRACE
}

// *************************************************** getLandscape(std::string, std::string)
int Cell::getLandscape(std::string unit, std::string land)
{ 
  int b_rows, b_col;
  for(short i=0; i<ROWS; i++)
  {
    if (land == Cell::landscape[i])
    { b_rows = i;
      break;
  } }
  
  for(short i=0; i<COLS; i++)
  { if (unit == Cell::unitType[i])
    { b_col = i;
      break;
  } }
  
  return Cell::bonus[b_rows][b_col];
}

// **************************************************** bonus[][]
int Cell::bonus[ROWS][COLS] =
{ {20, 30, 57, 100},
  {10, -2, 57, 0},
  {-45, -50, 57, -50} };
  
// **********************************  landscape[]  &  unitType[]
std::string Cell::landscape[] = {"plain", "forest", "sea"};
std::string Cell::unitType[] = {"cavalry", "infantry", "medic", "tank"};
