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

using std::cout;
using std::endl;
using std::list;
using std::ofstream;
using std::ifstream;

// *************************************** Player()
Player::Player(string& n) : name(n)
{ 
}

// *************************************** ~Player()
Player::~Player() //std::for_each(listOfObjectGame.begin(), listOfObjectGame.end(), [](ObjectGame* ptr_objectGame){ delete (*ptr_objectGame);});
{ 
//  std::for_each(listOfObjectGame.begin(), listOfObjectGame.end(), [](ObjectGame* ptr_temp){ delete ptr_temp;});
  list<ObjectGame*>::iterator it = listOfObjectGame.begin();
  for(it; it != listOfObjectGame.end(); it++)
  {
    delete (*it);
  }
  cout << "   ~Player anigilized...  " << endl;
  
}

// *************************************** addToList(shared_ptr <Factory> ptr_factory)
void Player::addToList(ObjectGame* ptr_ObjectGame)
{
  listOfObjectGame.push_back(ptr_ObjectGame); 
  cout << "   ptr_ObjectGame add to list of ObjectGame" << endl;
  return;
}

// ****************************************************  getName()
string Player::getName() const
{ return this->name;}

// ****************************************************  savePlayer()
void Player::savePlayer() const
{
  ofstream fout;
  
  for (list<ObjectGame*>::const_iterator it = listOfObjectGame.begin(); it != listOfObjectGame.end(); ++it)
  { 
    fout.open(PATH_OF_SAVE, ofstream::app);
    fout << (*it)->toString();
    fout.close();
    cout << "   done" << endl;
  }
}

// ***************************************************** loadPlayer()
void Player::loadPlayer()
{
  #include "../Cell/GameMap.h"
  json j;
  string tempString;
  this->listOfObjectGame.clear();
  ifstream fin(PATH_OF_SAVE);
  while (getline(fin, tempString))
  {
    j = json::parse(tempString);
    if (j.at("unitType") == "builder")
    { 
      cout << "\n   builder is load!" << endl;
      this->addToList(new Builder(
      j.at("status"), 
      j.at("typeOfTerrain"), 
      j.at("unitType"), 
      j.at("health"), 
      j.at("damage"), 
      j.at("defence"),
      gameMap[j.at("y")][j.at("x")],
      this));
    }
    
    else if (j.at("unitType") == "medic")
    {
      cout << "\n   medic is load!" << endl;
      this->addToList(new Builder(
      j.at("status"), 
      j.at("typeOfTerrain"), 
      j.at("unitType"), 
      j.at("health"), 
      j.at("damage"), 
      j.at("defence"),
      gameMap[j.at("y")][j.at("x")],
      this));
    }
    
    else if (j.at("unitType") == "medicFactory")
    {
      cout << "\n   medicFactory is load!" << endl;
      this->addToList
      (new MedicFactory(
      gameMap[j.at("y")][j.at("x")],
      j.at("unitType"),
      this));
    }
    
    else if (j.at("unitType") == "builderFactory")
    {
      cout << "\n   buildFactory is load!" << endl;
      this->addToList
      (new MedicFactory(
      gameMap[j.at("y")][j.at("x")],
      j.at("unitType"),
      this));
    }
  }
  fin.close();
}
// ******************************************************** printListOfObjectGame()
void Player::printListOfObjectGame()
{ 
  cout << "   Number elements of listOfObjectGame = " << listOfObjectGame.size() << endl;
  listOfObjectGame.clear();
  cout << "   Number elements of listOfObjectGame = " << listOfObjectGame.size() << endl;
}




