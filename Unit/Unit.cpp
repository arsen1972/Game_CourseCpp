#include <iostream>
#include "Unit.h"
#include "../Cell/Cell.h"

// **************************************************** Unit()
Unit::Unit() : health(100), damage(health/5), cell("empty")
{ //LOG_TRACE
}
// **************************************************** Unit(int, int)  
Unit::Unit(int h = 100, int d = 20) : health(h), damage(d)
{ //LOG_TRACE
}
// **************************************************** Unit(int, int, string)  
Unit::Unit(int h = 100, int d = 20, string c = "empty") : health(h), damage(d), cell(c)
{ //LOG_TRACE
}
// **************************************************** Unit(int, int, Cell&)
/*
Unit::Unit(int h = 100, int d = 20, Cell& c) 
{ 
 this->health = h;
 this->damage = d;
 this->cell = c.getLands(); 
//LOG_TRACE
}
*/
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
// **************************************************** setCell()
void Unit::setCell(string c)
{ this->cell = c;
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
string Unit::getCell()
{ return this->cell;
}
// **************************************************** move(int)
void Unit::move(int)
{
}
// **************************************************** attack(Unit*)
void Unit::attack(Unit* ptr_victim)
{ 
  int bonus =  this->getAttackBonus("forest");  // this->getAttackBonus(this->cell.lands);
  std::cout << "\n **********************************   The attack has begin   *****" << std::endl;
  std::cout << "bonus = " << bonus << std::endl;
  std::cout << "Current damage = damage + bonus =  " << bonus + this->damage << std::endl;
  ptr_victim->setHealth((ptr_victim->getHealth()) - (this->damage + bonus));
  
  this->health = this->health - (this->damage)/10;
    
  return;
}