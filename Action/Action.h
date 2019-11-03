#pragma once

#include <iostream>
#include <string>

using std::string;

class Action
{
public:

  Action();
  virtual ~Action() = 0;
  virtual void execut();
  
private:
  
};