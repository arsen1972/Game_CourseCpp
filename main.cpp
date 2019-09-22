#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Player/Player.h"
#include "Unit/Unit.hpp"
#include "Unit/Civil/Universal.h"
#include "Unit/Civil/Builder.h"
#include "Factory/Factory.h"
#include "Factory/UniversalFactory.h"
#include "Factory/BuilderFactory.h"
#include "Cell/Cell.h"
#include "Unit/Typedef.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

int main()
{
  #include "Cell/Karta.h"
  //string name = "player";
  //cout << "Введите свое имя: " ;
  //cin >> name ;
  //cout << endl;
  //Player player_01(name);

// *******************************************     parametrs for initializations
  
  Cell c (0, 0, "plain");
  
  std::string unitType = "builder";
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = CIVIL;
  TypeOfTerrain tOT = LAND;
  
  cout << "\n**************************************************\n" << endl;
  cout << "1. Начальные условия -  Университет СТРОИТЕЛЕЙ (BuilderFactory)" << endl; 
  BuilderFactory* builderFactory = new BuilderFactory();
  cout << endl;
  
  cout << "2. Первый выпускник этого университета - СТРОИТЕЛЬ (builder)" << endl;
  UnitCIVIL* ptr_unit_01 = builderFactory->getUnit(status, tOT, unitType, 100, 0, 0, &c2);
  cout << endl;
  
  cout << "3. builder рожден с характеристиками:" << endl;
  ptr_unit_01->printUnitFields();
  cout << endl;
  
  cout << "4. Сохранение объекта builder" << endl;
  ptr_unit_01->save();
  cout << endl;
  
  cout << "5. Аннигиляция юнита builder_01:" << endl;
  delete ptr_unit_01;
  cout << endl;
  
  cout << "6. Рождение нового юнита и загрузка сохраненного" << endl;
  UnitCIVIL* ptr_unit_03 = builderFactory->getUnit(status, tOT, unitType, 100, 0, 0, &c3);
  UnitCIVIL* ptr_unit_02 = ptr_unit_03->load();
  cout << endl;
  
  cout << "7. builder_02 загружен с характеристиками:" << endl;
  ptr_unit_02->printUnitFields();
  
  cout << "8. builder_02 строит BuilderFactory в ячейке [1][1]:" << endl;
  BuilderFactory* builderFactory_02 = ptr_unit_03->buildBuilderFactory(1,1);
  cout<< endl;

  cout << "9. Очищение памяти" << endl;
  delete builderFactory_02;
  delete ptr_unit_02;
  delete ptr_unit_03;
  delete builderFactory;
  cout<< endl;
     
  return 0;
}