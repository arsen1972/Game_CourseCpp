#pragma once

#include <iostream>
#include <string>

using std::string;

class ObjectGame
{
public:
  virtual ~ObjectGame() = 0;
  virtual void save() const;
  virtual string toString() const; 
};