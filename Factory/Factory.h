#pragma once
//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);

#include "../Unit/Unit.h"
#include <vector>
#include <string>

class Factory
{
public:
  Factory();
  virtual ~Factory();
  virtual Unit* getUnit(const std::string &);
  virtual Unit* getUnit(const std::string &, int, int);
  void addDepartment(Factory*);
  
private:
  std::vector<Factory*>departments;
};