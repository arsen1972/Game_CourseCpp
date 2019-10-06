#pragma once

#include <iostream>
#include <cstdio>
#include <memory>
#include <string>
#include <list>

#include "../Player/Player.h"
#include "../Cell/Cell.h"

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
  void clearGameMap(vector<vector<Cell*>>);
  
private:
  int id;
  list <shared_ptr <Player>> ListOfPlayers;
  
protected:
  
};
