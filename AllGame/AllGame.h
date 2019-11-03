#pragma once

#include <iostream>
#include <cstdio>
#include <memory>
#include <string>
#include <list>

#include "../Player/Player.h"
#include "../Cell/Cell.h"
#include "../Factory/Factory.h"
#include "../Unit/Unit.hpp"

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
  AllGame(string);
  virtual ~AllGame();
  void runGame();
  void creatGamer(string);
  string getTitle() const;
  void saveGame();
  void loadGame();
  void addToListOfPlayers(shared_ptr <Player>);
  void printListOfPlayers() const;
  void clearGameMap(vector<vector<Cell*>>);
  
private:
  string title;
  list <shared_ptr <Player>> ListOfPlayers;
//  Player* player;
  
protected:
  
};
