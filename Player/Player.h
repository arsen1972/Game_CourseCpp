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
using std::map;

class Player
{
  public:
  Player();
  Player(string &);
  virtual ~Player();
  string getName() const;
  void savePlayer() const;
  void loadPlayer();
  void printPlayerField() const;
  
  void addToMapOfObjectGame(ObjectGame*);
//  void addToListOfFactory(Factory*);
//  void addToListOfUnitCIVIL(UnitCIVIL*);
  
  void printMapOfObjectGame() const;
//  void printListOfFactory() const;
//  void printListOfUnitCIVIL() const;
  
  map<int, ObjectGame*> getMapOfObjectGame() const;
//  list<Factory*> getListOfFactory() const;
//  list<UnitCIVIL*> getListOfUnitCIVIL() const;
  
  private:
  string name;
  map<int, ObjectGame*> mapOfObjectGame;
//  list<Factory*> listOfFactory;
//  list<UnitCIVIL*> listOfUnitCIVIL;
  
  protected:

};