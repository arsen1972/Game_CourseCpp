#include <iostream>
#include "Unit.h"
#include "Factory.h"

void fullAttack(Unit*, Unit*, short);
Factory* getDepartment(const std::string &);

int main(int argv, char* argc[])
{ 
  std::string unitType = "cavalry";
  //std::cout << "\nEnter the unitType (cavalry):  " << std::endl;
  //std::cin >> unitType;
  
  int steps = 5;
  //std::cout << "Enter the number of steps:  " << std::endl;
  //std::cin >> steps;
  //std::cout << std::endl;

  int health_0 = 200; int damage_0 = 50;
  
  std::cout << "\nНачальные значения health & damage:" << std::endl;
  std::cout << "health_0 = " << health_0 << std::endl;
  std::cout << "damage_0 = " << damage_0 << std::endl;
  
  Factory factory; factory.addDepartment(getDepartment(unitType));
  
  Unit* ptr_unit = factory.getUnit(unitType, health_0, damage_0); 
  std::cout << "Создается первый юнит в режиме \"c параметрами\"" << std::endl;
  std::cout << "Health unit_1 (aggressor) = " << ptr_unit->getHealth() << std::endl;
  std::cout << "Damage unit_1 (aggressor) = " << ptr_unit->getDamage() << std::endl;
  
  Unit* ptr_unit2 = factory.getUnit(unitType);
  std::cout << "\nСоздается второй юнит в режиме \"по умолчанию\"" << std::endl;
  std::cout << "Health unit_2 (victim) = " << ptr_unit2->getHealth() << std::endl;
  std::cout << "Damage unit_2 (victim) = " << ptr_unit2->getDamage() << std::endl;
  
  fullAttack(ptr_unit, ptr_unit2, 3);
  //delete ptr_unit2;
  ptr_unit2 = nullptr;
  //delete ptr_unit;
  ptr_unit = nullptr;
  
  return 0;
}