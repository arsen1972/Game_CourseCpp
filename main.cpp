#include <iostream>
#include "Unit/Unit.h"
#include "Factory/Factory.h"
#include "Cell/Cell.h"
using std::string;
using std::cout;
using std::endl;

Factory* getDepartment(const string &);
 
int main()
{
  Cell pole ("forest");
  cout << "\nОбьект Cell с состоянием: " << pole.getLands() << endl;

  string unitType = "cavalry";
  int steps = 5;
  int health_0 = 200; int damage_0 = 20;
  
  cout << "\nНачальные значения health & damage:" << endl;
  cout << "health_0 = " << health_0 << endl;
  cout << "damage_0 = " << damage_0 << endl;
  cout << endl;
  
  Factory factory; 
  factory.addDepartment(getDepartment(unitType));
  Unit* ptr_unit = factory.getUnit(unitType, health_0, damage_0); 
  ptr_unit->setCell(pole.getLands());
  
  cout << "Создается первый юнит в режиме \"c параметрами\"" << endl;
  cout << "Health unit_1 (aggressor) = " << ptr_unit->getHealth() << endl;
  cout << "Damage unit_1 (aggressor) = " << ptr_unit->getDamage() << endl;
  cout << "Bonus-parametr (aggressor) = " << ptr_unit->getCell() << endl;
  
  Unit* ptr_unit2 = factory.getUnit(unitType);
  cout << "\nСоздается второй юнит в режиме \"по умолчанию\"" << endl;
  cout << "Health unit_2 (victim) = " << ptr_unit2->getHealth() << endl;
  cout << "Damage unit_2 (victim) = " << ptr_unit2->getDamage() << endl;
  
  ptr_unit->attack(ptr_unit2);
  
  cout << "Показатели после атаки" << std::endl;
  
  cout << "Health unit_1 (aggressor) = " << ptr_unit->getHealth() << endl;
  cout << "Damage unit_1 (aggressor) = " << ptr_unit->getDamage() << endl;

  cout << "Health unit_2 (victim) = " << ptr_unit2->getHealth() << endl;
  cout << "Damage unit_2 (victim) = " << ptr_unit2->getDamage() << endl;
  cout << endl;
  
  delete ptr_unit2;
  delete ptr_unit;

  return 0;
}