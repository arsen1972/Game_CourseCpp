#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

#include "Player/Player.h"
#include "ObjectGame/ObjectGame.h"
#include "Unit/Unit.hpp"
#include "Unit/Civil/Universal.h"
#include "Unit/Civil/Builder.h"
#include "Unit/Civil/Medic.h"
#include "Factory/Factory.h"
#include "Factory/UniversalFactory.h"
#include "Factory/BuilderFactory.h"
#include "Factory/MedicFactory.h"
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
  std::string unitType_m = "medic";
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = CIVIL;
  TypeOfTerrain tOT = LAND;
 
  cout << " 1.At start given - BuilderFactory const" << endl; 
  Factory* startedBuilderFactory = new BuilderFactory();
  cout << endl;
    
  cout << " 2.First graduate BuilderFactory - Builder" << endl;
  UnitCIVIL* builder_ptr_unit_01 = startedBuilderFactory->getUnit(status, tOT, unitType, 50, 0, 0, gameMap[0][1], smart_ptr_player_01.get());
  cout << endl;
  
  cout << " 3.Builder born with parameters:" << endl;
  builder_ptr_unit_01->printUnitFields();

  cout << " 4.builder_01 move to cell [1][1]:" << endl;
  builder_ptr_unit_01->move(gameMap[1][1]);
  cout << endl;

  cout << "~5.builder_01 build BuilderFactory:" << endl;
  Factory* builderFactory_01 = builder_ptr_unit_01->buildBuilderFactory();
  builderFactory_01->printUnitFields();
  cout<< endl;

  cout << " 5.builder_01 build MedicFactory:" << endl;
  Factory* medicFactory_01 = builder_ptr_unit_01->buildMedicFactory();
  medicFactory_01->printUnitFields();
  cout<< endl;
  
  cout << " 6.MedicFactory produces Medic" << endl;
  UnitCIVIL* medic_ptr_unit_01 = medicFactory_01->getUnit(status, tOT, unitType_m, 100, 0, 0, gameMap[0][1], smart_ptr_player_01.get());
  medic_ptr_unit_01->printUnitFields();
  cout << endl;
  
  cout << " 7.medic_01 heal builder_01:" << endl;
  medic_ptr_unit_01->heal(builder_ptr_unit_01);
  builder_ptr_unit_01->printUnitFields();
  
  cout << " 8.Begin save all object" << endl;
  smart_ptr_player_01->saveGame();
  cout << endl;
  
  cout << " 9.Load all ObjectGame from file" << endl;
  smart_ptr_player_01->loadGame();
  cout << endl;
  
  cout << " 10.Clear memory" << endl;

  delete medic_ptr_unit_01;
  delete medicFactory_01;
  delete builder_ptr_unit_01;
  delete startedBuilderFactory;
//  smart_ptr_player_01->printListOfObjectGame();
  return 0;
}