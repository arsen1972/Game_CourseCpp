#pragma once
#include <iostream>
#include "Enums.h"
#include "../Cell/Cell.h"
#include <map>
#include <string>

using std::string;
using std::map;
using std::cout;
using std::endl;


// template <typename Status, typename TypeOfTerrain> 
template <typename Status, typename TypeOfTerrain>  // template <bool, TypeOfTerrain>
class Unit
{
// *************************************   Constructor/destructor
 public:
  Unit(Status, TypeOfTerrain, string, int, int, bool, Cell*); 
  virtual ~Unit();
  virtual string getUnitType() const;
  virtual void printUnitFields() const;

 private:                      // ***********************  fields  
  string unitType;
  int health;
  int damage;
  bool defence;   
  Cell* cell;
   
  Status status;
  TypeOfTerrain typeOfTerrain;

  protected:                 // ***********************  methods()
  
  
/*   
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
*/  
};

// ****************************************************   Constructor/destructor
template <typename Status, typename TypeOfTerrain> 
Unit<Status, TypeOfTerrain>::Unit (Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : status(st), typeOfTerrain(tOT), unitType(uT), health(h), damage(d), defence(def), cell(c)
{ cout << "Обьект Unit" << endl;
}
template <typename Status, typename TypeOfTerrain> Unit<Status, TypeOfTerrain>::~Unit()
{ cout << "Обьект ~Unit" << endl;
}
// ****************************************************   getUnitType()
template <typename Status, typename TypeOfTerrain> 
string Unit<Status, TypeOfTerrain>::getUnitType() const
{ return this->unitType;
}

// **************************************************** printUnitFields()
template <typename Status, typename TypeOfTerrain>
void Unit<Status, TypeOfTerrain>::printUnitFields() const
{
  cout << "Printing here!!! From Unit" << endl;
//  cout << "unitType is \t" << this->unitType << endl;
//  cout << "Health = \t" << this->health << endl;
//  cout << "Damage = \t" << this->damage << endl;
//  cout << "Defence = \t" << this->defence << endl;
//  cout << "Bonus factor = \t" << this->getCell()->getLands() << endl;
//  cout << endl;
}
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