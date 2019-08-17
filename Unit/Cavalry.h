#pragma once
#include "Unit.h"

class Cavalry : public Unit
{

public:
  Cavalry();
  Cavalry(int, int);
  ~Cavalry();
  void move(int);
//  void attack(Unit*);
//  void setHealth(int);
//   int getHealth();
//  Cavalry(int h, int d);
//  void setRank(int); 
/*
private:
  int health;
  int damage;
*/
};