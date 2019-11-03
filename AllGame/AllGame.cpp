#include <iostream>
#include <cstdio>
#include <memory>
#include <string>
#include <list>

#include "AllGame.h"
#include "../Player/Player.h"
#include "../Unit/Unit.hpp"
#include "../Factory/Factory.h"
#include "../Factory/BuilderFactory.h"
#include "../Unit/Civil/Builder.h"
#include "../ObjectGame/ObjectGame.h"
#include "../Cell/GameMap.h"

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::ofstream;
using std::ifstream;
using std::shared_ptr;

// **************************************************** AllGame()
AllGame::AllGame()
{ cout << "   AllGame done" << endl;
}

// **************************************************** AllGame(int)
AllGame::AllGame(string tL) : title(tL)
{ cout << "\nAllGame done title: " << title << endl;
}

// **************************************************** ~AllGame()
AllGame::~AllGame()
{ 
  clearGameMap(gameMap);
  ListOfPlayers.clear();
  cout << "   ~AllGame() " << title << endl;
}

// **************************************************** creatGamer(string)
void AllGame::creatGamer(string nP)
{
  shared_ptr <Player> smart_ptr_player(new Player(nP));
  addToListOfPlayers(smart_ptr_player);
}
// **************************************************** addToListOfPlayers(shared_ptr <Player>)
void AllGame::addToListOfPlayers(shared_ptr <Player> smart_ptr_Player)
{
  ListOfPlayers.push_back(smart_ptr_Player); 
//  cout << "   ptr_Player add to list of Players. Size of list: " << ListOfPlayers.size() << endl;
  return;
}

// **************************************************** saveGame()
void AllGame::saveGame()
{
  ofstream fout;
  fout.open(PATH_OF_SAVE, std::ios::out); 
  fout.close();
  cout << "   Save file clear\n" << endl;
  int i = 1;
  list<shared_ptr <Player>>::iterator it = ListOfPlayers.begin();
  for(it; it != ListOfPlayers.end(); it++)
  {
    cout << " 8.Begin save all object Player " << i << endl; i++;
    (*it)->savePlayer();
    cout << endl;
} }

// **************************************************** loadGame()
void AllGame::loadGame()
{
  int i = 1;
  list<shared_ptr <Player>>::iterator it = ListOfPlayers.begin();
  for(it; it != ListOfPlayers.end(); ++it)
  { cout << "   Load all object Player " << i << endl; i++;
    if((*it)->getName() == "Gamer_" + to_string(i))
    {
      (*it)->loadPlayer();
      cout << endl;
  } }
  cout << endl;
}

// *****************************************************  clearGameMap(vector<vector<Cell*>>)
void AllGame::clearGameMap(vector<vector<Cell*>> gM)
{ for(int i = 0; i<gM.size(); i++)
  { for(int j = 0; j<gM[i].size(); j++)
    { delete gameMap[i][j];
} } }

// ************************************************ runGame()
void AllGame::runGame()
{
  cout << "ОСНОВНОЕ МЕНЮ:" << endl;
  cout << "N(n) <- Начать новую игру" << endl;
  cout << "L(l) <- Загрузить игру" << endl;
  cout << "Q(q) <- Выход из игры" << endl;
    
  bool game_run = true;
  
  while(game_run)
  {
    string tempSelect;
    cin >> tempSelect;
    if (tempSelect == "N" || tempSelect == "n")
    { cout << "You selected NEW GAME" << endl;
      cout << "Стартовый бонус каждому новому игроку - BuilderFactory" << endl;
      #include "games_loop.h"
      break;
    }
    
    else if (tempSelect == "L" || tempSelect == "l") 
    { cout << "You selected LOAD GAME" << endl;
      game_run = false;
    }
    
    else if (tempSelect == "Q" || tempSelect == "q") 
    { cout << "You selected EXIT and exit!" << endl;
      game_run = false;
    }
    
    else 
    { cout << "Наигрались???" << endl;
    }

    game_run = false;
  }
}

// **************************************************  printListOfPlayers()
void AllGame::printListOfPlayers() const
{ 
  cout << "   List of players:" << endl;
  list <shared_ptr <Player>>::const_iterator it = ListOfPlayers.begin();
  for (it; it != ListOfPlayers.end(); it++)
  { cout << "Игрок \"" << (*it)->getName() << "\"" << endl;
  }
}



