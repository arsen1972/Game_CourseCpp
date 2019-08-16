#pragma once
//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
#include "Cell.h"

class Unit
{
public:
           Unit();
   Unit(int, int);
  virtual ~Unit();
  virtual void move(int);
   void attack(Unit*);
   void setHealth(int);
   void setDamage(int);
   int getHealth();
   int getDamage();
  
private:
  int health;
  int damage;
  Cell land;
};

