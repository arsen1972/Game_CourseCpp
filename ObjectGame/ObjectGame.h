#pragma once

#include <iostream>
#include <string>

using std::string;

class ObjectGame
{
public:

  ObjectGame();
  ObjectGame(string&);
  virtual ~ObjectGame() = 0;
  virtual void save() const;
  virtual string toString() const;
  virtual string getUnitType() const;
  virtual void doAction();
  
  int id;
  static int statID;
  string unitType;
  
private:
  
};