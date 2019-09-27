#include <iostream>
#include <string>
#include <list>

#include "Player.h"
//#include "../Unit/Unit.hpp"
#include "../Factory/Factory.h"

using std::cout;
using std::endl;
using std::list;

// *************************************** Player()
Player::Player(string & n) : name(n)
{ //cout << "   " << n << " player born!" << endl;
}

// *************************************** ~Player()
Player::~Player()
{ //cout << "   ~Player anigilized...  " << endl;
//  std::for_each(listOfFactory.begin(), listOfFactory.end(), [](shared_ptr <Factory> ptr_factory){ delete ptr_factory;} );
//  std::for_each(listOfUnitCIVIL.begin(), listOfUnitCIVIL.end(), [](UnitCIVIL* ptr_UnitCIVIL){ delete ptr_UnitCIVIL;} );
}

// *************************************** addToList(shared_ptr <Factory> ptr_factory)
void Player::addToList(shared_ptr <ObjectGame> smart_ptr_ObjectGame)
{
  listOfObjectGame.push_back(smart_ptr_ObjectGame); // list<shared_ptr <Factory>> listOfFactory;
  cout << "   SMART_PTR add to list of ObjectGame" << endl;
  return;
}
/*
// *************************************** addlistOfUnitCIVIL(UnitCIVIL* ptr_UnitCIVIL)
void Player::addlistOfUnitCIVIL(UnitCIVIL* ptr_UnitCIVIL)
{
  listOfUnitCIVIL.push_back(ptr_UnitCIVIL);
  cout << "   UnitCIVIL add to list of UnitCIVIL" << endl;
  return;
}
*/
//  virtual void saveFactory();
//  virtual void loadFactory();