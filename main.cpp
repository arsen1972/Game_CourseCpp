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
  cout << "\n**************************************************" << endl;
  
  string name = "Player";
  Player player_01(name);
  cout << endl;
  
// *******************************************     parametrs for initializations Unit
  std::string unitType = "builder";
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = CIVIL;
  TypeOfTerrain tOT = LAND;
  

  cout << "1.Начальные условия -  Университет СТРОИТЕЛЕЙ (BuilderFactory)" << endl; 
  BuilderFactory* builderFactory = new BuilderFactory();
  player_01.addlistOfFactory(builderFactory);
  cout << endl;
    
  cout << "2.Первый выпускник этого университета - СТРОИТЕЛЬ (builder)" << endl;
  UnitCIVIL* ptr_unit_01 = builderFactory->getUnit(status, tOT, unitType, 100, 0, 0, &c2);
  player_01.addlistOfUnitCIVIL(ptr_unit_01);
  cout << endl;
  
  cout << "3.builder рожден с характеристиками:" << endl;
  ptr_unit_01->printUnitFields();
  // cout << endl;
  
  cout << "4.Сохранение объекта builder" << endl;
  ptr_unit_01->save();
  cout << endl;

  cout << "5.Рождение нового юнита и загрузка сохраненного" << endl;
  UnitCIVIL* ptr_unit_03 = builderFactory->getUnit(status, tOT, unitType, 100, 0, 0, &c3);
  UnitCIVIL* ptr_unit_02 = ptr_unit_03->load();
  player_01.addlistOfUnitCIVIL(ptr_unit_02);
  player_01.addlistOfUnitCIVIL(ptr_unit_03);
  cout << endl;
  
  cout << "6.builder_02 загружен с характеристиками:" << endl;
  ptr_unit_02->printUnitFields();
  
  cout << "7.builder_02 строит BuilderFactory в ячейке [1][1]:" << endl;
  BuilderFactory* builderFactory_02 = ptr_unit_02->buildBuilderFactory(1,1);
  player_01.addlistOfFactory(builderFactory_02);
  cout<< endl;
  
  cout << "8.Очищение памяти автоматически" << endl;
     
  return 0;
}