#pragma once
//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
#include "../Cell/Cell.h"

class Unit
{
public:
   Unit();
   Unit(int, int);
   virtual ~Unit();
  
   virtual void move(int);
   void attack(Unit*);
   
   void setHealth(int);
   int getHealth();
   
   void setDamage(int);
   int getDamage();
  
private:
//  std::string unitType;
  int health;
  int damage;
  Cell* land;
};