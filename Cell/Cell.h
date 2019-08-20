#pragma once
//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
#include <string>
using std::string;

class Cell
{
public:
   Cell();
   Cell(string l);
   ~Cell();
   string getLands() const;
  
private:
  string lands;
};