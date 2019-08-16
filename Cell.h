#pragma once
//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
#include <utility>


class Cell
{
public:
   Cell();
   ~Cell();
   int getLandscape();
  
private:
  int landscape;
};

