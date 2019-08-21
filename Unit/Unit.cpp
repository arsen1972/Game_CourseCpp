#include <iostream>
#include "Unit.h"
#include "../Cell/Cell.h"
using std::string;
using std::cout;
using std::endl;

// **************************************************** Unit(int, int, bool, Cell*)
Unit::Unit(int h, int d, bool def, Cell* c)
{ 
 this->health = h;
 this->damage = d;
 this->defence = def;
 this->cell = c;
//LOG_TRACE
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
// **************************************************** print()
void Unit::print()
{
  cout << "Health = \t" << this->getHealth() << endl;
  cout << "Damage = \t" << this->getDamage() << endl;
  cout << "Defence = \t" << this->getDefence() << endl;
}
// **************************************************** attack(Unit*)
void Unit::attack(Unit* ptr_victim)
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