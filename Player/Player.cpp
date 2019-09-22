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
{ 
  cout << n << " player born!" << endl;
}

// *************************************** ~Player()
Player::~Player()
{
  cout << "~Player anigilized...  " << endl;
  std::for_each(listOfFactory.begin(), listOfFactory.end(), [](Factory* ptr_factory){ delete ptr_factory;} );
}

// *************************************** addlistOfFactory(Factory* ptr_factory)
void Player::addlistOfFactory(Factory* ptr_factory)
{
  listOfFactory.push_back(ptr_factory); // list<Factory*> listOfFactory;
  cout << "Factory add to list of Factoryes" << endl;
  return;
}

//  virtual void saveFactory();
//  virtual void loadFactory();