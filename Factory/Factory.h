//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
#pragma once
#include "../Unit/Unit.h"
#include "../Cell/Cell.h"
#include <vector>
using std::vector;
#include <string>
using std::string;

class Factory
{
public:
  Factory();
  virtual ~Factory();
  virtual Unit* getUnit(const string &);
  virtual Unit* getUnit(const string &, int, int);
  void addDepartment(Factory*);
  
private:
  vector<Factory*>departments;
};