#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Unit/Unit.hpp"
#include "Unit/Civil/Universal.h"
#include "Unit/Civil/Builder.h"
#include "Factory/Factory.h"
#include "Factory/UniversalFactory.h"
#include "Factory/BuilderFactory.h"
#include "Cell/Cell.h"
//#include "Unit/Enums.h"
#include "Unit/Typedef.h"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

//Factory* getDepartment(const std::string &);

int main()
{
  Cell c1 ("plain", 0, 0);
  Cell c2 ("plain", 0, 1);
  Cell c3 ("forest", 1, 0);
  Cell c4 ("forest", 1, 1);

static vector<vector<Cell*>> karta = { { &c1, &c2 },
                                       { &c3, &c4 } };
//  cout << "Адреса ячеек Сell:" << endl;
//  cout << "&c1 = " << &c1 << endl;
//  cout << "&c2 = " << &c2 << endl;
//  cout << "&c3 = " << &c3 << endl;
//  cout << "&c4 = " << &c4 << endl;
//  cout << endl;

  
// *******************************************     parametrs for initializations
  std::string unitType = "universal";
  std::string unitType_2 = "builder";
  
  int steps = 5;
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = UNIVERSAL;
  TypeOfTerrain tOT = LAND;

// Строительство фабрики и юнита в ней
  cout << "\nСтроительство Университета Тайных УНИВЕРСАЛОВ" << endl; 
  UniversalFactory* universalFactory = new UniversalFactory(); 
  
  cout << "Первый выпускник этого университета - УНИВЕРСАЛ\n" << endl;
  Unitt* ptr_unit_01 = universalFactory->getUnit(status, tOT, unitType, health_0, damage_0, defence, karta[1][1]);
  ptr_unit_01->printUnitFields();
  
  ptr_unit_01->buildBuilderFactory();
  
// Строительство фабрики и юнита в ней  BUILDER
  cout << "Данный со старта Университет СТРОИТЕЛЕЙ" << endl; 
  BuilderFactory* builderFactory = new BuilderFactory();
  cout << endl;
  
  cout << "Первый выпускник этого университета - СТРОИТЕЛЬ" << endl;
  UnitCIVIL* ptr_unit_02 = builderFactory->getUnit(status, tOT, unitType_2, 100, 0, 0, karta[0][0]);
  cout << endl;
  ptr_unit_02->printUnitFields();
  
  
  ptr_unit_02->save();
  UnitCIVIL* ptr_unit_03 = builderFactory->getUnit(status, tOT, unitType, health_0, damage_0, defence, &c3);
  cout << "\nПолучена строка:\t" << ptr_unit_03->load() << endl; 
  cout << endl;
  ptr_unit_03->printUnitFields();
  
  ptr_unit_02->buildBuilderFactory();
  
  delete universalFactory;
  delete builderFactory;
  delete ptr_unit_01;
  delete ptr_unit_02;
  delete ptr_unit_03;
  
  return 0;
}