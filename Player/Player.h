#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <list>

#include "../Unit/Unit.hpp"
#include "../Unit/Typedef.h"

#include "../Factory/Factory.h"
#include "../ObjectGame/ObjectGame.h"

using std::cout;
using std::endl;
using std::list;
using std::shared_ptr;

class Player
{
  public:
  Player();
  Player(string &);
  virtual ~Player();
  string getName() const;
  void addToList(shared_ptr <ObjectGame>);
  void saveGame() const;
  void loadGame();

  private:
  string name;
  list<shared_ptr <ObjectGame>> listOfObjectGame;
  
  protected:
//  ObjectGame* load();
};