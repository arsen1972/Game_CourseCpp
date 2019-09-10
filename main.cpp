#include <iostream>
#include "Unit/Unit.hpp"
#include "Unit/Enums.h"
#include "Factory/Factory.h"
#include "Cell/Cell.h"
#include <string>

using std::string;
using std::cout;
using std::endl;

Factory* getDepartment(const std::string &);
 
int main()
{

  Cell c ("plain");
  cout << "\nОбьект Cell c инициализирован: " << c.getLands() << endl;
  cout << endl;
// *******************************************     parametrs for initializations
  std::string unitType = "universal";
  int steps = 5;
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = UNIVERSAL; // Status status = 2;
  TypeOfTerrain tOT = LAND; // TypeOfTerrain tOT = 0;
  
  Factory factory;
  factory.addDepartment(getDepartment(unitType));
  
  Unit<Status, TypeOfTerrain>* ptr_unit = factory.getUnit(status, tOT, unitType, health_0, damage_0, defence, &c);
  cout << endl;
  
  Unit<Status, TypeOfTerrain>* ptr_unit_02 = factory.getUnit(status, tOT, unitType, health_0, damage_0, defence, &c);
  cout << endl;
  
  ptr_unit_02->printUnitFields();
  
  ptr_unit->move();
  cout << endl;
  
  ptr_unit->attack(ptr_unit_02);
  
  ptr_unit->buildBuilderFactory(); 
  cout << endl;  
  
  ptr_unit_02->printUnitFields();
  
  delete ptr_unit;
  
  return 0;
}