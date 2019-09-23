#include <iostream>
#include <string>
#include <list>

#include "../Unit/Unit.hpp"
#include "../Unit/Typedef.h"

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
  void addlistOfUnitCIVIL(UnitCIVIL*);
  
  private:
  string name;
  list<Factory*> listOfFactory;
  list<UnitCIVIL*> listOfUnitCIVIL;
  
  protected:
//  void save();
//  void load();
};