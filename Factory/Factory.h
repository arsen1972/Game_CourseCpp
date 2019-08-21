//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
#pragma once
#include "../Unit/Unit.h"
#include "../Cell/Cell.h"
#include <vector>
#include <string>
using std::string;

class Factory
{
public:
  Factory();
  virtual ~Factory();
  virtual Unit* getUnit(const string &, int, int, bool, Cell*);
  void addDepartment(Factory*);
  
private:
  std::vector<Factory*>departments;
};