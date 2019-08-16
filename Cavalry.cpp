#include <iostream>
#include "Cavalry.h"
#include "Unit.h"

// ***************************************************** Cavalry()
Cavalry::Cavalry()
{
  this->setHealth(150);
  this->setDamage(30);
  
  //LOG_TRACE
}
// ***************************************************** Cavalry(int, int)
Cavalry::Cavalry(int h, int d) : Unit(h, d)
{ //LOG_TRACE
}
// ***************************************************** ~Cavalry()
Cavalry::~Cavalry()
{ //LOG_TRACE
}

// **************************************************** move(int)
void Cavalry::move(int a)
{
  std::cout << "\nCavalry took " << a << " steps:" << std::endl;
  
  if (a>1)
  { std::cout << "Dyck-dyck, ";
  }
  
  for(short step=1; step < (a-1); step++)
  { std::cout << "dyck-dyck, ";
  }
  
  std::cout << "dyck-dyck!\n" << std::endl;
}

/*// **************************************************** setHealth()
void Cavalry::setHealth(int h)
{ this->health = h;
}

// **************************************************** getHealth()
int Cavalry::getHealth()
{ return this->health;
}
*/
// **************************************************** attack(Unit*)
/*
void Cavalry::attack(Unit* ptr_unit)
{
  ptr_unit->setHealth((ptr_unit->getHealth()) - (this->damage));
  
  this->health = this->health - (this->damage)/10;
  
  if (ptr_unit->getHealth() < 19)   //magic number
  { ptr_unit->setHealth(0);
  }
  
  return;
}*/
//******************************************************************************
/*
Cavalry::Cavalry()
{
  LOG_TRACE
  //std::cout << "Cavalry is born!\n" << std::endl;
}

Cavalry::Cavalry(int h, int d)
{
  this->health = h;
  this->damage = d;
  LOG_TRACE
  //std::cout << "Cavalry is born!\n" << std::endl;
}
*/