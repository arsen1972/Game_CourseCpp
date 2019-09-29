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

#define PATH_OF_SAVE "Save/save.json"
#include "../Json/json.hpp"
using json = nlohmann::json;

using std::cout;
using std::endl;
using std::list;
using std::ofstream;
using std::ifstream;

// *************************************** Player()
Player::Player(string& n) : name(n)
{ //cout << "   " << n << " player born!" << endl;
}

// *************************************** ~Player()
Player::~Player()
{ cout << "   ~Player anigilized...  " << endl;
//  std::for_each(listOfFactory.begin(), listOfFactory.end(), [](shared_ptr <Factory> ptr_factory){ delete ptr_factory;} );

//  std::for_each(listOfObjectGame.begin(), listOfObjectGame.end(), [](UnitCIVIL* ptr_UnitCIVIL){ delete ptr_UnitCIVIL;} );
}

// *************************************** addToList(shared_ptr <Factory> ptr_factory)
void Player::addToList(shared_ptr <ObjectGame> smart_ptr_ObjectGame)
{
  listOfObjectGame.push_back(smart_ptr_ObjectGame); 
  cout << "   SMART_PTR add to list of ObjectGame" << endl;
  return;
}

// ****************************************************  getName()
string Player::getName() const
{ return this->name;}

// ****************************************************  saveGame()
void Player::saveGame() const
{
  ofstream fout;
  fout.open(PATH_OF_SAVE, std::ios::out); //, std::ios::out); // ios::out 
  fout.close(); 
  list<shared_ptr <ObjectGame>>::const_iterator iter = listOfObjectGame.begin();
  for (iter; iter != listOfObjectGame.end(); ++iter)
  { 
    (*iter)->save(); // .get()
    cout << endl;
  }
}
