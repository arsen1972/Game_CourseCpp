#include <iostream>
#include "Unit.h"
#include "../Cell/Cell.h"
using std::map;
using std::string;
using std::cout;
using std::endl;

// **************************************************** Unit(int, int, bool, Cell*)
Unit::Unit(int h , int d, bool def, Cell* c) : health(h), damage(d), defence(def), cell(c)
{ //LOG_TRACE 
}

// **************************************************** Unit(string, int, int, bool, Cell*)
Unit::Unit(string uT, int h , int d, bool def, Cell* c) : unitType(uT), health(h), damage(d), defence(def), cell(c)
{ //LOG_TRACE 
}

// **************************************************** ~Unit()
Unit::~Unit()
{ //LOG_TRACE 
}
   
// **************************************************** setHealth(int h)
void Unit::setHealth(int h)
{ this->health = h;
}

// **************************************************** setHealth(int h)
void Unit::setDamage(int d)
{ this->damage = d;
}

// **************************************************** getUnitType()  
string Unit::getUnitType()
{
  return this->unitType;
}

// **************************************************** getDefence()
bool Unit::getDefence()
{ return this->defence;
}

// **************************************************** getHealth()
int Unit::getHealth()
{ return this->health;
}
// **************************************************** getDamage()
int Unit::getDamage()
{ return this->damage;
}
// **************************************************** getCell()
Cell* Unit::getCell()
{ return this->cell;
}

// **************************************************** move(int)
void Unit::move(int)
{
}

// **************************************************** printUnitFields()
void Unit::printUnitFields()
{
  cout << "unitType is \t" << this->getUnitType() << endl;
  cout << "Health = \t" << this->getHealth() << endl;
  cout << "Damage = \t" << this->getDamage() << endl;
  cout << "Defence = \t" << this->getDefence() << endl;
  cout << "Bonus factor = \t" << this->getCell()->getLands() << endl;
  cout << endl;
}
// ************************************************* buildFactory();
void Unit::buildFactory(string fT)
{
  //cout << "Build Factory " << fT << endl;
}
// ************************************************* getAttackBonus()
int Unit::getAttackBonus()
{
  return this->getAttackMap()[this->getCell()->getLands()];
}

// ************************************************* getDefenceBonus()
int Unit::getDefenceBonus()
{
  return this->getDefenceMap()[this->getCell()->getLands()];
}

// **************************************************** attack(Unit*)
void Unit::attack(Unit* ptr_victim)
{ 
  int bonus = this->getAttackBonus();
  int defenceBonus = ptr_victim->getDefenceBonus();
  cout << "\n****  THE ATTACK HAS BEGIN" << endl;
  cout << "**        bonus = " << bonus << endl;
  cout << "**        defenceBonus = " << defenceBonus << endl;
  cout << "**        Current damage = damage + bonus - defenceBonus = " << bonus + this->damage - defenceBonus<< endl;
  
  ptr_victim->setHealth((ptr_victim->getHealth()) - abs((this->damage + bonus - defenceBonus)));
  this->health = this->health - abs((this->damage)/10);
  
  cout << "****  THE ATTACK IS OVER\n" << endl;
}