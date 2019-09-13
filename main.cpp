#include <iostream>
#include <string>
#include <fstream>

#include "Unit/Unit.hpp"
#include "Unit/Civil/Universal.h"
#include "Unit/Civil/Builder.h"
#include "Unit/Enums.h"
#include "Factory/Factory.h"
#include "Factory/UniversalFactory.h"
#include "Factory/BuilderFactory.h"
#include "Cell/Cell.h"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

//Factory* getDepartment(const std::string &);
 
int main()
{
  Cell c ("plain", 0, 0);
  cout << "\nОбьект Cell c инициализирован: " << c.getLands() << endl;
  cout << endl;
  
// *******************************************     parametrs for initializations
//  std::string unitType = "universal";
  std::string unitType_2 = "builder";
  int steps = 5;
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = UNIVERSAL;
  TypeOfTerrain tOT = LAND;
/*
// Строительство фабрики и юнита в ней
  cout << "\nСтроительство Университета Тайных УНИВЕРСАЛОВ" << endl; 
  Factory* universalFactory = new UniversalFactory(); 
  
  cout << "Первый выпускник этого университета - УНИВЕРСАЛ\n" << endl;
  Unit<Status, TypeOfTerrain>* ptr_unit_01 = universalFactory->getUnit(status, tOT, unitType, health_0, damage_0, defence, &c);
  ptr_unit_01->printUnitFields();
*/
// Строительство фабрики и юнита в ней  BUILDER
  cout << "Данный со старта Университет СТРОИТЕЛЕЙ" << endl; 
  Factory* builderFactory = new BuilderFactory();
  
  cout << "Первый выпускник этого университета - СТРОИТЕЛЬ" << endl;
  Unit<Status, TypeOfTerrain>* ptr_unit_02 = builderFactory->getUnit(status, tOT, unitType_2, health_0, damage_0, defence, &c);
  cout << endl;
  ptr_unit_02->printUnitFields();
  
//  ptr_unit_02->save();
  delete ptr_unit_02;
  
  Unit<Status, TypeOfTerrain>* ptr_unit_03 = builderFactory->getUnit(status, tOT, unitType_2, health_0, damage_0, defence, &c);
  cout << "\nПолучена строка: \n" << ptr_unit_03->load() << endl; // распарсить и передать в конструктор
  cout << endl;
  ptr_unit_03->printUnitFields();
  
//  delete universalFactory;
  delete builderFactory;
  delete ptr_unit_03;
  
  return 0;
}