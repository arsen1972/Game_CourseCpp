#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <boost/any.hpp>

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
using std::shared_ptr;

int main()
{
 #include "Cell/GameMap.h"
  cout << "\n************************* ------------ *************************" << endl;
  cout << "*************************  START GAME  *************************" << endl;
  cout << "************************* ------------ *************************\n" << endl;
// ******************************************* New Player
  string playerName = "Gamer";
  Player player_01 (playerName);
  cout << endl;

// ************************************************ parametrs for initializations Unit
  std::string unitType = "builder";
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = CIVIL;
  TypeOfTerrain tOT = LAND;
 
  cout << " 1.At start given -  BuilderFactory" << endl; 
  shared_ptr <Factory> builderFactory (new BuilderFactory());
  player_01.addToList(builderFactory);
  cout << endl;
    
  cout << " 2.First graduate BuilderFactory - Builder" << endl;
  shared_ptr <UnitCIVIL> smart_ptr_unit_01(builderFactory->getUnit(status, tOT, unitType, 100, 0, 0, gameMap[0][1]));
  player_01.addToList(smart_ptr_unit_01);
  cout << endl;
  
  cout << " 3.Builder born with parameters:" << endl;
  smart_ptr_unit_01->printUnitFields();
  // cout << endl;
  
  cout << " 4.Save object Builder" << endl;
  smart_ptr_unit_01->save();
  cout << endl;

  cout << " 5.Birth of a unit & loading saved" << endl;
  shared_ptr <UnitCIVIL> smart_ptr_unit_03(builderFactory->getUnit(status, tOT, unitType, 100, 0, 0, gameMap[0][1]));
  shared_ptr <UnitCIVIL> smart_ptr_unit_02(smart_ptr_unit_03->load());
  player_01.addToList(smart_ptr_unit_02);
  cout << endl;
  
  cout << " 6.builder_02 loaded with parameters:" << endl;
  smart_ptr_unit_02->printUnitFields();

  cout << " 7.builder_02 move to cell [1][1]:" << endl;
  smart_ptr_unit_02->move(gameMap[1][1]);
  cout << endl;
  
  cout << " 8.builder_02 creates BuilderFactory:" << endl;
  shared_ptr <Factory> builderFactory_02(smart_ptr_unit_02->buildBuilderFactory());
  player_01.addToList(builderFactory_02);
  builderFactory_02->save();
  cout<< endl;
  
  cout << " 9.builder_02 heal builder_01:" << endl;
  smart_ptr_unit_02->heal(smart_ptr_unit_03.get());
  cout<< endl;
  
  cout << "10.Auto clear memory (all SMART)" << endl;
     
  return 0;
}