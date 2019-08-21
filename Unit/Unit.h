#pragma once
#include "../Cell/Cell.h"
#include <map>
#include <string>
//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
using std::string;

class Unit
{
public:
   Unit(int, int, bool, Cell*);
   virtual ~Unit();
  
   virtual void move(int);
   void attack(Unit*);
   
   void setHealth(int);
   int getHealth();
   
   void setDamage(int);
   int getDamage();
  
   virtual int getAttackBonus() = 0;
   virtual int getDefenceBonus() = 0;
   
   bool getDefence();
   Cell* getCell();
   
   void print();
   
private:

   int health;
   int damage;
   bool defence;
   Cell* cell;
};