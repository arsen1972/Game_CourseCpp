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
  shared_ptr <Player> smart_ptr_player_01 (new Player(playerName));

// ************************************************ parametrs for initializations Unit
  std::string unitType = "builder";
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = CIVIL;
  TypeOfTerrain tOT = LAND;
 
  cout << " 1.At start given -  BuilderFactory const" << endl; 
  shared_ptr <Factory> builderFactory (new BuilderFactory());
  cout << endl;
    
  cout << " 2.First graduate BuilderFactory - Builder" << endl;
  shared_ptr <UnitCIVIL> smart_ptr_unit_01(builderFactory->getUnit(status, tOT, unitType, 50, 0, 0, gameMap[0][1]));
  smart_ptr_player_01->addToList(smart_ptr_unit_01);
  cout << endl;
  
  cout << " 3.Builder born with parameters:" << endl;
  smart_ptr_unit_01->printUnitFields();

  cout << " 4.Birth of a unit & loading saved" << endl;
  shared_ptr <UnitCIVIL> smart_ptr_unit_03(builderFactory->getUnit(status, tOT, unitType, 100, 0, 0, gameMap[0][1]));
  smart_ptr_player_01->addToList(smart_ptr_unit_03);
  cout << endl;

  cout << " 5.builder_03 move to cell [1][1]:" << endl;
  smart_ptr_unit_03->move(gameMap[1][1]);
  cout << endl;
  
  cout << " 6.builder_03 build BuilderFactory:" << endl;
  shared_ptr <Factory> builderFactory_02(smart_ptr_unit_03->buildBuilderFactory());
  smart_ptr_player_01->addToList(builderFactory_02);
  cout<< endl;
  
  cout << " 7.builder_02 heal builder_01:" << endl;
  smart_ptr_unit_03->heal(smart_ptr_unit_01.get());
  smart_ptr_unit_01->printUnitFields();

  cout << " 8.Begin save all object" << endl;
  smart_ptr_player_01->saveGame();
  
  cout << " 9.Auto clear memory (all SMART)" << endl;

  return 0;
}