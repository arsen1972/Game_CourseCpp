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
   void print();
   
 protected:
 
   void setHealth(int);
   void setDamage(int);
   int getHealth();
   int getDamage(); 
   bool getDefence();
   Cell* getCell();
   virtual std::map<string, int> getAttackMap() = 0;
   virtual std::map<string, int> getDefenceMap() = 0;

   
 private:
 
   int getAttackBonus();
   int getDefenceBonus();
   int health;
   int damage;
   bool defence;
   Cell* cell;
};