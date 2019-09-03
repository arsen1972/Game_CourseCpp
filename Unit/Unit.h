#pragma once
#include "../Cell/Cell.h"
#include <map>
#include <string>
using std::string;
using std::map;

class Unit
{
 public:
 
   Unit(int, int, bool, Cell*);
   Unit(string, int, int, bool, Cell*);
    ~Unit();
  
   virtual void move(int);
   virtual void buildFactory(string);
   void attack(Unit*);  
   void printUnitFields();
   
 protected:
 
   void setHealth(int);
   void setDamage(int);
   string getUnitType();
   int getHealth();
   int getDamage(); 
   bool getDefence();
   Cell* getCell();
   virtual map<string, int> getAttackMap() = 0;
   virtual map<string, int> getDefenceMap() = 0;

   
 private:
 
   int getAttackBonus();
   int getDefenceBonus();
   string unitType;
   int health;
   int damage;
   bool defence;
   Cell* cell;
};