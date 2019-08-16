#include <iostream>
#include "Unit.h"


// **************************************************** Unit()
Unit::Unit() : health(100), damage(health/5)
{ //LOG_TRACE
}

// **************************************************** Unit(int, int)
Unit::Unit(int h = 100, int d = 20) : health(h), damage(d)
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
// **************************************************** getHealth()
int Unit::getHealth()
{ return this->health;
}
// **************************************************** getDamage()
int Unit::getDamage()
{ return this->damage;
}
// **************************************************** move(int)
void Unit::move(int)
{
}
// **************************************************** attack(Unit*)
void Unit::attack(Unit* ptr_victim)
{ 
  std::cout << "\n **********************************   The attack has begin   *****" << std::endl;
  std::cout << "landscape = " << this->land.getLandscape() << std::endl;
  std::cout << "Current damage = damage + landscape =  " << this->land.getLandscape() + this->damage << std::endl;
  ptr_victim->setHealth((ptr_victim->getHealth()) - (this->damage + (this->land.getLandscape())));
  
  this->health = this->health - (this->damage)/10;
    
  return;
}