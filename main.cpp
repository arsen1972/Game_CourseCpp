#include <iostream>
#include "Unit/Unit.h"
#include "Unit/Enums.h"
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
  
  // parametrs for initializations
  // string unitType_02 = "cavalry";
  string unitType = "atlant";
  int steps = 5;
  int health_0 = 200; int damage_0 = 20;
  bool defence_0 = false;
  bool defence_1 = true;
  Status status = ATLANT; // Status status = 2;
  TypeOfTerrain tOT = LAND; // TypeOfTerrain tOT = 0;
  
  
  Factory factory;
  factory.addDepartment(getDepartment(unitType));
  Unit<Status, TypeOfTerrain>* ptr_unit = factory.getUnit(CIVIL, LAND, "builder", 200, 20, 0, &C1);
//  Unit<Status, TypeOfTerrain>* ptr_unit_2 = factory.getUnit(status, tOT, unitType, health_0, damage_0, defence_0, cell_02);

//  ptr_unit->printUnitFields();
//  ptr_unit_2->printUnitFields();

  //ptr_unit->buildFactoryCivil("civil"); // стоит фабрику CivilFactory
  //ptr_unit->buildFactoryMilitary("military");  // стоит фабрику MilitaryFactory
  
  /*
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

  //delete ptr_unit2;
  //ptr_unit2 = nullptr;
*/


  delete ptr_unit;
  
  return 0;
}