#include <iostream>
#include "Cavalry.h"
#include "Unit.h"
#include <string>
#include <map>
using std::string;

// ***************************************************** Cavalry()
Cavalry::Cavalry()
{
  this->setHealth(150);
  this->setDamage(30);
  this->setCell("empty");
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

// **************************************************** getAttackBonus()
int Cavalry::getAttackBonus(string l)
{ 
  return 33; //Cavalry::unitAttackBonus[l];
}
//**************************************************** unitAttackBonus
map<string, int> Cavalry::unitAttackBonus;
 
//unitAttackBonus["plain"] = 10;
//unitAttackBonus["forest"] = 20;
//unitAttackBonus["sea"] = -20;


