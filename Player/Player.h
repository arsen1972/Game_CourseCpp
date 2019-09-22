#include <iostream>
#include <string>
#include <list>

//#include "Unit/Unit.hpp"
#include "../Factory/Factory.h"

using std::cout;
using std::endl;
using std::list;

class Player
{
  public:
  Player();
  Player(string &);
  virtual ~Player();
  void addlistOfFactory(Factory*);
  
  private:
  string name;
  list<Factory*> listOfFactory;
  
  protected:
//  virtual void save();
//  virtual void load();
};