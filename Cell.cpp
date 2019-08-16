#include <iostream>
#include <string>
#include "Cell.h"
//#include <map>

// **************************************************** Cell()
Cell::Cell() //: landscape(10)
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
  for(short i=0; i<3; i++)
  {
    if (land == Cell::landscape[i])
    { b_rows = i;
      break;
  } }
  
  for(short i=0; i<4; i++)
  { if (unit == Cell::unitType[i])
    { b_col = i;
      break;
  } }
  
  return Cell::bonus[b_rows][b_col];
}

// **************************************************** bonus[][]
int Cell::bonus[3][4] =
{ {20, 30, 57, 100},
  {10, -2, 57, 0},
  {-45, -50, 57, -50} };
  
// **********************************  landscape[]  &  unitType[]
std::string Cell::landscape[] = {"plain", "forest", "sea"};
std::string Cell::unitType[] = {"cavalry", "infantry", "medic", "tank"};
