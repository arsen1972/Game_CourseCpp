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
  cout << "   " << n << " player born!" << endl;
}

// *************************************** ~Player()
Player::~Player()
{
  cout << "   ~Player anigilized...  " << endl;
  std::for_each(listOfFactory.begin(), listOfFactory.end(), [](Factory* ptr_factory){ delete ptr_factory;} );
  std::for_each(listOfUnitCIVIL.begin(), listOfUnitCIVIL.end(), [](UnitCIVIL* ptr_UnitCIVIL){ delete ptr_UnitCIVIL;} );

}

// *************************************** addlistOfFactory(Factory* ptr_factory)
void Player::addlistOfFactory(Factory* ptr_factory)
{
  listOfFactory.push_back(ptr_factory); // list<Factory*> listOfFactory;
  cout << "   Factory add to list of Factoryes" << endl;
  return;
}

// *************************************** addlistOfUnitCIVIL(UnitCIVIL* ptr_UnitCIVIL)
void Player::addlistOfUnitCIVIL(UnitCIVIL* ptr_UnitCIVIL)
{
  listOfUnitCIVIL.push_back(ptr_UnitCIVIL);
  cout << "   UnitCIVIL add to list of UnitCIVIL" << endl;
  return;
}
//  virtual void saveFactory();
//  virtual void loadFactory();