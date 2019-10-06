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
using std::endl;
using std::list;
using std::ofstream;
using std::ifstream;
using std::shared_ptr;

// **************************************************** AllGame()
AllGame::AllGame()
{
  cout << "   AllGame done" << endl;
}

// **************************************************** AllGame(int)
AllGame::AllGame(int id):id(id)
{
  cout << "   AllGame done № " << id << endl;
}

// **************************************************** ~AllGame()
AllGame::~AllGame()
{ 
  clearGameMap(gameMap);
  cout << "   ~AllGame delete № " << id  << endl;
}

// **************************************************** addToListOfPlayers(shared_ptr <Player>)
void AllGame::addToListOfPlayers(shared_ptr <Player> smart_ptr_Player)
{
  ListOfPlayers.push_back(smart_ptr_Player); 
  cout << "   ptr_Player add to list of Players. Size of list: " << ListOfPlayers.size() << endl;
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
  }
}

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





