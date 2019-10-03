#pragma once

#include <iostream>
#include <cstdio>
#include <memory>
#include <string>
#include <list>

#include "../Player/Player.h"

#define PATH_OF_SAVE "Save/gamer.sav"

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::shared_ptr;

class AllGame
{
public:
  AllGame();
  AllGame(int);
  virtual ~AllGame();
  void saveGame();
  void loadGame();
  void addToListOfPlayers(shared_ptr <Player>);
  
private:
  int id;
  
protected:
  list <shared_ptr <Player>> ListOfPlayers;
};
