#pragma once
//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
#include <string>
//#include <map>


class Cell
{
public:
   Cell();
   ~Cell();
   int getLandscape(std::string, std::string);
  
private:
  int lands;
  static int bonus [][4];
  static std::string landscape[];
  static std::string unitType[];
  
};