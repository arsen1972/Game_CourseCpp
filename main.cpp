#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

#include "Player/Player.h"
#include "Unit/Unit.hpp"
#include "Unit/Civil/Universal.h"
#include "Unit/Civil/Builder.h"
#include "Factory/Factory.h"
#include "Factory/UniversalFactory.h"
#include "Factory/BuilderFactory.h"
#include "Cell/Cell.h"
#include "Unit/Typedef.h"
//#include <boost/static_assert.hpp>
//#include <boost/variant.hpp>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::shared_ptr;

int main()
{
 #include "Cell/Karta.h"
  cout << "\n**************************************************" << endl;

// *******************************************     parametrs for initializations Unit
  std::string unitType = "builder";
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = CIVIL;
  TypeOfTerrain tOT = LAND;
  

  cout << "1.Начальные условия -  Университет СТРОИТЕЛЕЙ (SMART BuilderFactory)" << endl; 
  shared_ptr <BuilderFactory> builderFactory(new BuilderFactory());
  cout << endl;
    
  cout << "2.Первый выпускник этого университета - СТРОИТЕЛЬ (SMART builder)" << endl;
  shared_ptr <UnitCIVIL> smart_ptr_unit_01(builderFactory->getUnit(status, tOT, unitType, 100, 0, 0, &c2));
  cout << endl;
  
  cout << "3.SMART builder рожден с характеристиками:" << endl;
  smart_ptr_unit_01->printUnitFields();
  // cout << endl;
  
  cout << "4.Сохранение объекта builder (SMART)" << endl;
  smart_ptr_unit_01->save();
  cout << endl;

  cout << "5.Рождение нового юнита (SMART) и загрузка сохраненного (to SMART)" << endl;
  shared_ptr <UnitCIVIL> smart_ptr_unit_03(builderFactory->getUnit(status, tOT, unitType, 100, 0, 0, &c3));
  shared_ptr <UnitCIVIL> smart_ptr_unit_02(smart_ptr_unit_03->load());
  cout << endl;
  
  cout << "6.SMART_builder_02 загружен с характеристиками:" << endl;
  smart_ptr_unit_02->printUnitFields();
  
  cout << "7.SMART_builder_02 строит BuilderFactory в ячейке [1][1]:" << endl;
  shared_ptr <BuilderFactory> builderFactory_02(smart_ptr_unit_02->buildBuilderFactory(1,1));
  cout<< endl;
  
  cout << "8.Очищение памяти автоматически (all is SMART)" << endl;
     
  return 0;
}