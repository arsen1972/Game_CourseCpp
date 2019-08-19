#pragma once
//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
#include <string>
#define ROWS 3  // number of landscape types 
#define COLS 4  // number of unit types

class Cell
{
public:
   Cell();
   ~Cell();
   int getBonus(std::string, std::string);
  
private:
  int lands; // std::string lands;
  static int bonus [][COLS];
  static std::string landscape[];
  static std::string unitType[];
  
};