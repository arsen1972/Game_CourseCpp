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
  Cell C ("forest");
  Cell* cell = &C;
  cout << "\nОбьект Cell инициализирован: " << cell->getLands() << endl;
  cout << endl;
  
  string unitType = "cavalry";
  int steps = 5;
  int health_0 = 200; int damage_0 = 20;
  bool defence_0 = false;
  bool defence_1 = true;

  Factory factory; 
  factory.addDepartment(getDepartment(unitType));
  Unit* ptr_unit = factory.getUnit(unitType, health_0, damage_0, defence_0, cell);
  
  cout << "  ******************************   Показатели до атаки" << std::endl;
  cout << "\tptr_unit" << endl;
  ptr_unit->print(); 
  cout << endl;
  
  Unit* ptr_unit2 = factory.getUnit(unitType, health_0, damage_0, defence_1, cell);
  cout << "\tptr_unit 2" << endl;
  ptr_unit2->print(); 
  cout << endl; 
  
  ptr_unit->attack(ptr_unit2);
  cout << "\n  ******************************   Показатели после атаки" << std::endl;
  
  cout << "\tptr_unit" << endl;
  ptr_unit->print(); 
  cout << endl;
  
  cout << "\tptr_unit 2" << endl;
  ptr_unit2->print(); 

  delete ptr_unit2;
  //ptr_unit2 = nullptr;
  delete ptr_unit;
  //ptr_unit = nullptr;
  
  cout << endl;
  return 0;
}