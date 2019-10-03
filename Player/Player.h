#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <list>

#include "../Unit/Unit.hpp"
#include "../Unit/Typedef.h"

#include "../Factory/Factory.h"
#include "../ObjectGame/ObjectGame.h"

#define PATH_OF_SAVE "Save/gamer.sav"

using std::cout;
using std::endl;
using std::string;
using std::list;


class Player
{
  public:
  Player();
  Player(string &);
  virtual ~Player();
  string getName() const;
  void addToList(ObjectGame*);
  void savePlayer() const;
  void loadPlayer();
  void printListOfObjectGame();

  
  private:
  string name;
  list<ObjectGame*> listOfObjectGame;
  
  protected:

};