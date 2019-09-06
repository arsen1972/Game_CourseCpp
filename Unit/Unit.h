#pragma once
#include "Enums.h"
#include "../Cell/Cell.h"
#include <map>
#include <string>

using std::string;
using std::map;

template <typename Status, typename TypeOfTerrain>  // template <bool, TypeOfTerrain>
class Unit
{
// *************************************   Constructor/destructor
 public:
  Unit(Status, TypeOfTerrain, string, int, int, bool, Cell*); 
  virtual ~Unit();

 private:                      // ***********************  fields  
  string unitType;
  int health;
  int damage;
  bool defence;   
  Cell* cell;
   
  Status status;
  TypeOfTerrain typeOfTerrain;

 protected:                 // ***********************  methods()
  
  string getUnitType();
   
  int getHealth();
  int getDamage();
  Status getStatus();
  TypeOfTerrain getTOT();
   
  virtual void move(int);
   
  int getAttackBonus();
  int getDefenceBonus();
   
  Cell* getCell();
  
 public:
  virtual void printUnitFields();
};
/*
// *******************************************  template specialization for CIVIL units
template <>   // может сделать CIVIL чистым шаблоном, а MILITARY - специализацией?
class Unit < CIVIL, TypeOfTerrain>
{
// *************************************   Constructor/destructor
 public:
  Unit(Status, TypeOfTerrain, string, int, int, bool, Cell*);
  virtual ~Unit() = 0;

 private:                       // ***********************  fields  
  string unitType;
  int health;
  int damage;
  bool defence;   
  Cell* cell;
   
  Status status;
  TypeOfTerrain tOT;

 protected:                  // ***********************  methods()
  
  string getUnitType();
   
  int getHealth();
  int getDamage();
  Status getStatus();
  TypeOfTerrain getTOT();
  int getDefenceBonus();
  Cell* getCell();    
     
  virtual void move(int);
  
  virtual void printUnitFields();
};

// *******************************************  template specialization for MILITARY units
template  <>
class Unit < MILITARY, typename TypeOfTerrain>
{
// *************************************   Constructor/destructor
 public:
  Unit(Status, TypeOfTerrain, string, int, int, bool, Cell*); //
  virtual ~Unit() = 0;

 private:                      // ***********************  fields  
  string unitType;
  int health;
  int damage;
  bool defence;   
  Cell* cell;
   
  Status status; 
  TypeOfTerrain tOT;

 protected:                 // ***********************  methods()
  
  string getUnitType();
   
  int getHealth();
  int getDamage();
  Status getStatus();
  TypeOfTerrain getTOT();
   
  virtual void move(int);
   
  int getAttackBonus();
  int getDefenceBonus();
   
  virtual void printUnitFields();
   
  void attack(Unit*);
  bool getDefence();
  virtual map<string, int> getAttackMap() = 0;
  virtual map<string, int> getDefenceMap() = 0;
   
  Cell* getCell();
   
};


*/