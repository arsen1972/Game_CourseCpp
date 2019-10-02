#pragma once

#include <iostream>
#include <string>

using std::string;

class ObjectGame
{
public:
  virtual void save() const;
  virtual string toString() const; 
};