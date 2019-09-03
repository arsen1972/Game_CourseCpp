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
  Cell C1 ("forest");
  Cell* cell_01 = &C1;
  Cell C2 ("plain");
  Cell* cell_02 = &C2;
  
  cout << endl;
  cout << "Обьект Cell C1 инициализирован: " << cell_01->getLands() << endl;
  cout << "Обьект Cell C2 инициализирован: " << cell_02->getLands() << endl;
  cout << endl;
  
  string unitType = "cavalry";
  string unitType_02 = "builder";
  int steps = 5;
  int health_0 = 200; int damage_0 = 20;
  bool defence_0 = false;
  bool defence_1 = true;

  Factory factory; 
  factory.addDepartment(getDepartment(unitType));
  Unit* ptr_unit = factory.getUnit(unitType, health_0, damage_0, defence_0, cell_01);
  
  cout << "   ПОКАЗАТЕЛИ ДО АТАКИ" << std::endl;
  cout << "\tptr_unit" << endl;
  ptr_unit->printUnitFields();
  
  factory.addDepartment(getDepartment(unitType_02));
  Unit* ptr_unit2 = factory.getUnit(unitType_02, health_0, damage_0, defence_0, cell_02);
  cout << "\tptr_unit 2" << endl;
  ptr_unit2->printUnitFields(); 
  ptr_unit2->buildFactory("Civil");
  
//  ptr_unit->move(5);
  ptr_unit->attack(ptr_unit2);
  cout << "\n   ПОКАЗАТЕЛИ ПОСЛЕ АТАКИ" << std::endl;
  cout << "\tptr_unit" << endl;
  ptr_unit->printUnitFields(); 
  
  cout << "\tptr_unit 2" << endl;
  ptr_unit2->printUnitFields(); 

  delete ptr_unit2;
  //ptr_unit2 = nullptr;
  delete ptr_unit;
  //ptr_unit = nullptr;
  
  return 0;
}