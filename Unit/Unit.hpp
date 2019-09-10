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



template <typename Status, typename TypeOfTerrain>
class Unit
{
// *************************************   Constructor/destructor
 public:
  Unit(Status, TypeOfTerrain, string, int, int, bool, Cell*); 
  virtual ~Unit();
  virtual string getUnitType() const;
  virtual void printUnitFields() const;
  virtual void move();
  void attack(Unit*);
  
  virtual Cell* getCell() const;
  virtual void buildBuilderFactory() const;
  
 private:                      // ***********************  fields  
  string unitType;
  int health;
  int damage;
  bool defence; 
    
  Cell* cell;
   
  Status status;
  TypeOfTerrain typeOfTerrain;

  protected:                   // ***********************  methods()
  
  virtual int getHealth() const;
  virtual void setHealth(int);
  virtual int getDamage() const;
  virtual bool getDefence() const;
  virtual Status getStatus() const;
  virtual TypeOfTerrain getTOT() const;

  
  virtual int getAttackBonus() = 0;
  virtual int getDefenceBonus() = 0;
 
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

// ****************************************************   getHealth()
template <typename Status, typename TypeOfTerrain> 
int Unit<Status, TypeOfTerrain>::getHealth() const
{ return this->health;
}

// ****************************************************   setHealth()
template <typename Status, typename TypeOfTerrain> 
void Unit<Status, TypeOfTerrain>::setHealth(int h)
{ this->health = h;
}

// ****************************************************   getDamage()
template <typename Status, typename TypeOfTerrain> 
int Unit<Status, TypeOfTerrain>::getDamage() const
{ return this->damage;
}
// ****************************************************   getDefence()
template <typename Status, typename TypeOfTerrain> 
bool Unit<Status, TypeOfTerrain>::getDefence() const
{ return this->defence;
}

// **************************************************** getCell()
template <typename Status, typename TypeOfTerrain>
Cell* Unit<Status, TypeOfTerrain>::getCell() const
{ return this->cell;
}

// **************************************************** getStatus()
template <typename Status, typename TypeOfTerrain>
Status Unit<Status, TypeOfTerrain>::getStatus() const
{
  return this->status;
}

// **************************************************** getTOT()
template <typename Status, typename TypeOfTerrain>
TypeOfTerrain Unit<Status, TypeOfTerrain>::getTOT() const
{
  return this->typeOfTerrain;
}
  
// **************************************************** printUnitFields()
template <typename Status, typename TypeOfTerrain>
void Unit<Status, TypeOfTerrain>::printUnitFields() const
{
  cout << "Printing here!!! From Unit" << endl;
  cout << endl;
  cout << "unitType is \t" << this->unitType << endl;
  cout << "Health = \t" << this->health << endl;
  cout << "Damage = \t" << this->damage << endl;
  cout << "Defence = \t" << this->defence << endl;
  cout << "Bonus factor = \t" << this->getCell()->getLands() << endl;
  cout << "Status unit = \t" << this->getStatus() << endl; 
  cout << endl;
}

// ****************************************************   move()
template <typename Status, typename TypeOfTerrain> 
void Unit<Status, TypeOfTerrain>::move()
{
  cout << "Unit Топ-топ!" << endl;
}

// ****************************************************   attack(Unit*)
template <typename Status, typename TypeOfTerrain> 
void Unit<Status, TypeOfTerrain>::attack(Unit* ptr_victim)
{ 
  int bonus = this->getAttackBonus();
  int defenceBonus = ptr_victim->getDefenceBonus();
  cout << "\n  ******************************   The attack has begin" << endl;
  cout << "bonus = " << bonus << endl;
  cout << "defenceBonus = " << defenceBonus << endl;
  cout << "Current damage = damage + bonus + defenceBonus = " << bonus + this->damage + defenceBonus<< endl;
  
  ptr_victim->setHealth((ptr_victim->getHealth()) - abs((this->damage + bonus + defenceBonus)));
  this->health = this->health - abs((this->damage)/10);
  
  cout << "\n  . . . . . . . . . . . . . . . .   The attack is over" << endl;
}

// ****************************************************   buildBuilderFactory()
template <typename Status, typename TypeOfTerrain> 
void Unit<Status, TypeOfTerrain>::buildBuilderFactory() const
{
  cout << "BuilderFactory is done virtual" << endl;
}
/*
// *******************************************  template specialization for CIVIL units
template <>
class Unit < CIVIL, TypeOfTerrain>
{
   
};
*/