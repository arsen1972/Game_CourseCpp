#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

#include "AllGame/AllGame.h"
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
#include "Cell/GameMap.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::shared_ptr;

int main()
{
  AllGame all{"all_Game"};
  
  cout << "\n************************* ------------ *************************" << endl;
  cout << "*************************  START GAME  *************************" << endl;
  cout << "************************* ------------ *************************\n" << endl;
  
// *********************************************** New Players
  bool addPlayers = true;
  while (addPlayers)
  { 
    cout << "Введите имя игрока: " ;
    string playerName;
    cin >> playerName;
    all.creatGamer(playerName);
      
    cout << "Добавить игрока? (Y/N) - ";
    string addPlayerName;
    cin >> addPlayerName;
    if (addPlayerName == "Y" || addPlayerName == "y")
    {
    }
    else
    { addPlayers = false;
    }
  }
  
  cout << endl;
  all.printListOfPlayers();
  cout << endl;

// ************************************************ parametrs for initializations Unit
  std::string unitType = "builder";
  std::string unitTypeFactory = "builderFactory";
  std::string unitType_m = "medic";
  int health_0 = 200;
  int damage_0 = 20;
  bool defence = true;
  Status status = CIVIL;
  TypeOfTerrain tOT = LAND;  
  
  all.runGame();

/* 
  cout << "\n 1.At start given - BuilderFactory const" << endl; 
  Factory* startedBuilderFactory = new BuilderFactory(gameMap[0][0], unitTypeFactory, smart_ptr_player_01.get());
  smart_ptr_player_01->addToList(startedBuilderFactory);
  cout << endl;
  
  cout << "~1.At start given - BuilderFactory const" << endl; 
  Factory* startedBuilderFactory_2= new BuilderFactory(gameMap[1][0], unitTypeFactory, smart_ptr_player_02.get());
  smart_ptr_player_02->addToList(startedBuilderFactory_2);  
  cout << endl;
 
  cout << " 2.First graduate BuilderFactory - Builder" << endl;
  UnitCIVIL* builder_ptr_unit_01 = startedBuilderFactory->getUnit(status, tOT, unitType, 50, 0, 0, gameMap[0][1], smart_ptr_player_01.get());
  cout << endl;
  
  cout << "~2.First graduate BuilderFactory_02 - Builder" << endl;
  UnitCIVIL* builder_ptr_unit_01_2= startedBuilderFactory_2->getUnit(status, tOT, unitType, 100, 0, 0, gameMap[1][0], smart_ptr_player_02.get());
  cout << endl;
  
  cout << " 3.Builder born with parameters:" << endl;
  builder_ptr_unit_01->printUnitFields();
  
  cout << "~3.Builder born with parameters:" << endl;
  builder_ptr_unit_01_2->printUnitFields();

  cout << " 4.builder_01 move to cell [4][4]:" << endl;
  builder_ptr_unit_01->move(gameMap[4][4]);
  cout << endl;

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
  
  cout << " 8.Save all ObjectGame to file" << endl;
  all.saveGame();
  
  cout << " 9.Load all ObjectGame from file" << endl;
  all.loadGame();
*/  
  cout << endl;
  cout << " 10.Clear memory" << endl;

  return 0;
}
