#include <iostream>
#include <cstdio>
#include <string>
#include <list>

#include "Player.h"
#include "../Unit/Unit.hpp"
#include "../Factory/Factory.h"
#include "../Factory/BuilderFactory.h"
#include "../Unit/Civil/Builder.h"
#include "../ObjectGame/ObjectGame.h"
#include "../Cell/GameMap.h"

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::map;
using std::pair;
using std::ofstream;
using std::ifstream;
using std::for_each;

// *************************************** Player()
Player::Player(string& n) : name(n)
{ 
  // Factory* startedBuilderFactory = new BuilderFactory(gameMap[0][0], "builderFactory", this);
  // this->addToListFactory(startedBuilderFactory);
  string uT = "builderFactory";
  Factory* ptr_factory = new BuilderFactory(gameMap[0][0], uT, this);
//  addToListOfFactory(ptr_factory); //new BuilderFactory(gameMap[0][0], "builderFactory", this));
  addToMapOfObjectGame(ptr_factory);
//  addToListFactory(new BuilderFactory(gameMap[1][1], "builderFactory", this));
}

// *************************************** ~Player()
Player::~Player()
{ 
//  for_each(listOfFactory.begin(), listOfFactory.end(), [](Factory* ptr_temp){ delete ptr_temp;});
//  for_each(listOfUnitCIVIL.begin(), listOfUnitCIVIL.end(), [](UnitCIVIL* ptr_temp){ delete ptr_temp;});
  
  map<int, ObjectGame*>::iterator it = mapOfObjectGame.begin();
  for(it; it != mapOfObjectGame.end(); it++) delete (it->second);
//   for_each(mapOfObjectGame.begin(), mapOfObjectGame.end(), [](ObjectGame* ptr_temp){ delete ptr_temp;});
  
  cout << "   ~Player anigilized...  " << endl;
}

// *************************************** addToMapOfObjectGame(ObjectGame*)
void Player::addToMapOfObjectGame(ObjectGame* ptr_ObjectGame)
{
  mapOfObjectGame.insert(pair<int, ObjectGame*> (ptr_ObjectGame->id, ptr_ObjectGame));
//  cout << "   ptr_ObjectGame add to list of ObjectGame" << endl;
  return;
}

// ******************************************************  getMapOfObjectGame()
map<int, ObjectGame*> Player::getMapOfObjectGame() const
{ return mapOfObjectGame;
}

// ******************************************************** printMapOfObjectGame()
void Player::printMapOfObjectGame() const
{ 
  map<int, ObjectGame*>::const_iterator it = mapOfObjectGame.begin();
  for (it; it != mapOfObjectGame.end(); it++)
  { // cout << "Тип юнита: " << it->second->unitType << ". Его идентификатор id = " << it->first << endl;
    cout << it->second->unitType << "\tid = " << it->first << endl;    
  }
  // mapOfObjectGame.clear();
  // cout << "   Number elements of mapOfObjectGame = " << mapOfObjectGame.size() << endl;
}

/*
// *************************************** addToListOfFactory(Factory*)
void Player::addToListOfFactory(Factory* ptr_Factory)
{
  listOfFactory.push_back(ptr_Factory); 
//  cout << "   ptr_Factory to list of Factory" << endl;
  return;
}

// ******************************************************  getListOfObjectGame()
list<Factory*> Player::getListOfFactory() const
{ return listOfFactory;
}

// ******************************************************** printListOfObjectGame()
void Player::printListOfFactory() const
{ 
//  cout << "   Number elements of listOfObjectGame = " << listOfObjectGame.size() << endl;
  list<Factory*>::const_iterator it = listOfFactory.begin();
  for (it; it!= listOfFactory.end(); it++)
  { cout << (*it)->getUnitType() << " id = " << (*it)->id << endl;
  }
  // listOfFactory.clear();
  // cout << "   Number elements of listOfFactory = " << listOfFactory.size() << endl;
}


// *************************************** addToListOfUnitCIVIL(UnitCIVIL*)
void Player::addToListOfUnitCIVIL(UnitCIVIL* ptr_UnitCIVIL)
{
  listOfUnitCIVIL.push_back(ptr_UnitCIVIL); 
//  cout << "   ptr_UnitCIVIL add to list of UnitCIVIL" << endl;
  return;
}

// ******************************************************  getListOfUnitCIVIL()
list<UnitCIVIL*> Player::getListOfUnitCIVIL() const
{ return listOfUnitCIVIL;
}

// ******************************************************** printListOfUnitCIVIL()
void Player::printListOfUnitCIVIL() const
{ 
//  cout << "   Number elements of listOfUnitCIVIL = " << listOfUnitCIVIL.size() << endl;
  list<UnitCIVIL*>::const_iterator it = listOfUnitCIVIL.begin();
  for (it; it!= listOfUnitCIVIL.end(); it++)
  { cout << (*it)->getUnitType() << " id = " << (*it)->id << endl;
  }
  // listOfUnitCIVIL.clear();
  // cout << "   Number elements of listOfUnitCIVIL = " << listOfUnitCIVIL.size() << endl;
}
*/

// ****************************************************  getName()
string Player::getName() const
{ return this->name;}

// ****************************************************  savePlayer()
void Player::savePlayer() const
{
  ofstream fout;
  
  for (map<int, ObjectGame*>::const_iterator it = mapOfObjectGame.begin(); it != mapOfObjectGame.end(); ++it)
  { 
    fout.open(PATH_OF_SAVE, ofstream::app);
//    fout << (*it)->second->toString();
    fout.close();
    cout << "   done" << endl;
  }
}

// ***************************************************** loadPlayer()
void Player::loadPlayer()
{
  json j;
  string tempString;
  this->mapOfObjectGame.clear();
  
  ifstream fin(PATH_OF_SAVE);
  while (getline(fin, tempString))
  {
    j = json::parse(tempString);
    if (j.at("unitType") == "builder")
    { 
      this->addToMapOfObjectGame(new Builder(
      j.at("status"), 
      j.at("typeOfTerrain"), 
      j.at("unitType"), 
      j.at("health"), 
      j.at("damage"), 
      j.at("defence"),
      gameMap[j.at("y")][j.at("x")],
      this));
      cout << "\n   builder is load!" << endl;
    }
    
    else if (j.at("unitType") == "medic")
    {
      this->addToMapOfObjectGame(new Medic(
      j.at("status"), 
      j.at("typeOfTerrain"), 
      j.at("unitType"), 
      j.at("health"), 
      j.at("damage"), 
      j.at("defence"),
      gameMap[j.at("y")][j.at("x")],
      this));
      cout << "\n   medic is load!" << endl;
    }
    
    else if (j.at("unitType") == "medicFactory")
    {
      this->addToMapOfObjectGame
      (new MedicFactory(
      gameMap[j.at("y")][j.at("x")],
      j.at("unitType"),
      this));
      cout << "\n   medicFactory is load!" << endl;
    }
    
    else if (j.at("unitType") == "medicFactory")
    {
      this->addToMapOfObjectGame
      (new MedicFactory(
      gameMap[j.at("y")][j.at("x")],
      j.at("unitType"),
      this));
      cout << "\n   buildFactory is load!" << endl;
    }
  }
  fin.close();
}

// *******************************************************  printPlayerField()
void Player::printPlayerField() const
{
  cout << " Данные нового игрока: " << endl;
  cout << "   Name: " << name << endl;
  cout << endl;
}






