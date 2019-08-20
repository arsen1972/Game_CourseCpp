#pragma once
#include "../Cell/Cell.h"
#include <map>
#include <string>
//#define LOG_TRACE printf("function %s() (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__);
using std::string;

class Unit
{
public:
   Unit();
   Unit(int, int);
   Unit(int, int, string);
   virtual ~Unit();
  
   virtual void move(int);
   void attack(Unit*);
   
   void setHealth(int);
   int getHealth();
   
   void setDamage(int);
   int getDamage();
   
   void setCell(string);
   string getCell();
  
   virtual int getAttackBonus(string l) = 0;

private:
   int health;
   int damage;
   string cell;
};