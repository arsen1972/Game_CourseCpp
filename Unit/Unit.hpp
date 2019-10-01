#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <memory>

#include "../Json/json.hpp"
#include "../Save/pathOfSave.h"

#include "Enums.h"
//#include "Typedef.h"
#include "../Cell/Cell.h"
//#include "../Cell/GameMap.h"
#include "../ObjectGame/ObjectGame.h"
//#include "../Player/Player.h"
//#include "../Factory/Factory.h"
//#include "../Factory/BuilderFactory.h"

using std::string;
using std::to_string;
using std::map;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::vector;
using json = nlohmann::json; // using nlohmann::json;

class Factory;
class Player;

template <Status stat, typename TOT> // template <Status stat, TypeOfTerrain TypeOT>  
class Unit : public ObjectGame
{
// *************************************   Constructor/destructor
 public:
  Unit();
  Unit(Status, TypeOfTerrain, string, int, int, bool, Cell*); 
  virtual ~Unit();

  virtual void printUnitFields() const;
  virtual void move();
  void attack(Unit*);
  void heal(Unit*);
  virtual void save();
  virtual string load();
  void buildBuilderFactory();
  
 private:                      // ***********************  fields  
  Status status;
  string unitType;
  int health;
  int damage;
  bool defence;
  TypeOfTerrain typeOfTerrain;
  Cell* cell;

  protected:                   // ***********************  methods()
  
  virtual Status getStatus() const;
  virtual string getUnitType() const;
  virtual int getHealth() const;
  virtual void setHealth(int);
  virtual int getDamage() const;
  virtual bool getDefence() const;
  virtual TypeOfTerrain getTOT() const;
  virtual Cell* getCell() const;
  
  virtual int getAttackBonus() = 0;
  virtual int getDefenceBonus() = 0;
 
};

template <Status stat, typename TOT>
Unit<stat, TOT>::Unit()
{
}
// ****************************************************   Constructor/destructor
template <Status stat, typename TOT> 
Unit<stat, TOT>::Unit (Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : status(st), typeOfTerrain(tOT), unitType(uT), health(h), damage(d), defence(def), cell(c)
{ cout << "   Unit is born" << endl;
}

template <Status stat, typename TOT> 
Unit<stat, TOT>::~Unit()
{ cout << "   ~Unit is annihilated" << endl;
}
// ****************************************************   getUnitType()
template <Status stat, typename TOT> 
string Unit<stat, TOT>::getUnitType() const
{ return this->unitType;
}

// ****************************************************   getHealth()
template <Status stat, typename TOT> 
int Unit<stat, TOT>::getHealth() const
{ return this->health;
}

// ****************************************************   setHealth()
template <Status stat, typename TOT> 
void Unit<stat, TOT>::setHealth(int h)
{ this->health = h;
}

// ****************************************************   getDamage()
template <Status stat, typename TOT> 
int Unit<stat, TOT>::getDamage() const
{ return this->damage;
}
// ****************************************************   getDefence()
template <Status stat, typename TOT> 
bool Unit<stat, TOT>::getDefence() const
{ return this->defence;
}

// **************************************************** getCell()
template <Status stat, typename TOT>
Cell* Unit<stat, TOT>::getCell() const
{ return this->cell;
}

// **************************************************** getStatus()
template <Status stat, typename TOT>
Status Unit<stat, TOT>::getStatus() const
{
  return this->status;
}

// **************************************************** getTOT()
template <Status stat, typename TOT>
TypeOfTerrain Unit<stat, TOT>::getTOT() const
{
  return this->typeOfTerrain;
}
  
// **************************************************** printUnitFields()
template <Status stat, typename TOT>
void Unit<stat, TOT>::printUnitFields() const
{
  cout << "Printing here!!! From Unit" << endl;
  cout << endl;
  cout << "unitType is \t" << this->unitType << endl;
  cout << "Health = \t" << this->health << endl;
  cout << "Damage = \t" << this->damage << endl;
  cout << "Defence = \t" << this->defence << endl;
  cout << "Bonus factor = \t" << this->getCell()->getLands() << endl;
  cout << "Status unit = \t" << this->getStatus() << endl; 
  cout << endl;
}

// ****************************************************   move()
template <Status stat, typename TOT> 
void Unit<stat, TOT>::move()
{
  cout << "Unit Топ-топ!" << endl;
}

// ****************************************************   attack(Unit*)
template <Status stat, typename TOT> 
void Unit<stat, TOT>::attack(Unit* ptr_victim)
{ 
  int bonus = this->getAttackBonus();
  int defenceBonus = ptr_victim->getDefenceBonus();
  cout << "\n  ******************************   The attack has begin" << endl;
  cout << "bonus = " << bonus << endl;
  cout << "defenceBonus = " << defenceBonus << endl;
  cout << "Current damage = damage + bonus + defenceBonus = " << bonus + this->damage + defenceBonus<< endl;
  
  ptr_victim->setHealth((ptr_victim->getHealth()) - abs((this->damage + bonus + defenceBonus)));
  this->health = this->health - abs((this->damage)/10);
  
  cout << "\n  . . . . . . . . . . . . . . . .   The attack is over" << endl;
}

// **************************************************** save()
template <Status stat, typename TOT>
void Unit<stat, TOT>::save()
{
  string str_temp;
  str_temp = unitType + ";" + to_string(health) + ";" + to_string(damage) + ";" + to_string(defence) + ";" + getCell()->getLands() + ";" + to_string(getCell()->getX()) + ";" + to_string(getCell()->getY()) + ";" + to_string(getStatus()) + ";" + to_string(getTOT());
  ofstream fout;
  fout.open(PATH_OF_SAVE);
  if (!fout.is_open()) {cout << "Ошибка открытия файла..." << endl;}
  else  { fout << str_temp << endl;}
  fout.close(); 
  cout << "Объект успешно сохранен" << endl;
}

// **************************************************** load()
template <Status stat, typename TOT>
string Unit<stat, TOT>::load()
{string inString;
  return inString;}

// ***********************************************************************************************
// *******************************************  template specialization for CIVIL units  *********
// ***********************************************************************************************

template <typename TOT>
class Unit<CIVIL, TOT> : public ObjectGame
{
// *************************************   Constructor/destructor
public:
  Unit();
  Unit(Status, TypeOfTerrain, string, int, int, bool, Cell*, Player*); 
  virtual ~Unit();
                             // ***********************  methods()
  virtual void printUnitFields() const;
  virtual void move(Cell*);
  virtual void heal(Unit<CIVIL, TOT>*) const;
  virtual void save() const;
//  virtual Unit<CIVIL, TOT>* load();
  virtual Factory* buildBuilderFactory();
  virtual Factory* buildMedicFactory();

protected:          // ***********************  methods()
    
  virtual Status getStatus() const;
  virtual string getUnitType() const;
  
  virtual int getHealth() const;
  virtual void setHealth(int);
  
  virtual int getDamage() const;
  virtual bool getDefence() const;
  virtual TypeOfTerrain getTOT() const;
  
  virtual Cell* getCell() const;
  virtual void setCell(Cell*);
  
  virtual Player* getPlayer() const;
//  virtual void setPlayer(Player*);  
 
private:                      // ***********************  fields  
  Status status;
  string unitType;
  int health;
  int damage;
  bool defence;
  TypeOfTerrain typeOfTerrain;
  Cell* cell;
  Player* player;
};

template <typename TOT>
Unit<CIVIL, TOT>::Unit()
{}
// ****************************************************   Constructor/destructor
template <typename TOT> 
Unit<CIVIL, TOT>::Unit (Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c, Player* pl) :
 status(st), typeOfTerrain(tOT), unitType(uT), health(h), damage(d), defence(def), cell(c), player(pl)
{ //cout << "   Unit is born" << endl;
}

template <typename TOT> 
Unit<CIVIL, TOT>::~Unit()
{ cout << "   ~Unit is annihilated" << endl;
}
// ****************************************************   getUnitType()
template <typename TOT> 
string Unit<CIVIL, TOT>::getUnitType() const
{ return this->unitType;
}

// ****************************************************   getHealth()
template <typename TOT> 
int Unit<CIVIL, TOT>::getHealth() const
{ return this->health;
}

// ****************************************************   setHealth()
template <typename TOT> 
void Unit<CIVIL, TOT>::setHealth(int h)
{ this->health = h;
}

// ****************************************************   getDamage()
template <typename TOT> 
int Unit<CIVIL, TOT>::getDamage() const
{ return this->damage;
}
// ****************************************************   getDefence()
template <typename TOT> 
bool Unit<CIVIL, TOT>::getDefence() const
{ return this->defence;
}

// **************************************************** getCell()
template <typename TOT>
Cell* Unit<CIVIL, TOT>::getCell() const
{ return this->cell;
}

// **************************************************** setCell(Cell*)
template <typename TOT>
void Unit<CIVIL, TOT>::setCell(Cell* c)
{ cell = c;
  return ;
}

// **************************************************** getPlayer()
template <typename TOT>
Player* Unit<CIVIL, TOT>::getPlayer() const
{ return this->player;
}

// **************************************************** getStatus()
template <typename TOT>
Status Unit<CIVIL, TOT>::getStatus() const
{ return this->status;
}

// **************************************************** getTOT()
template <typename TOT>
TypeOfTerrain Unit<CIVIL, TOT>::getTOT() const
{ return this->typeOfTerrain;
}
  
// **************************************************** printUnitFields()
template <typename TOT>
void Unit<CIVIL, TOT>::printUnitFields() const
{
  cout << "Printing here!!! From UnitCIVIL" << endl;
  cout << endl;
  cout << "unitType is \t" << this->unitType << endl;
  cout << "Health = \t" << this->health << endl;
//  cout << "Damage = \t" << this->damage << endl;
//  cout << "Defence = \t" << this->defence << endl;
//  cout << "Player = " << this->getPlayer()->getName() << endl;
//  cout << "Bonus factor = \t" << this->getCell()->getLands() << endl;
  cout << "Status unit = \t" << this->getStatus() << endl;
  cout << "Object coordinates: x = " << this->getCell()->getX() << ", y = " << this->getCell()->getY() << endl; 
  cout << endl;
}

// **************************************************** move(Cell*)
template <typename TOT> 
void Unit<CIVIL, TOT>::move(Cell* c)
{ cell = c;
  cout << "Unit go to cell with coordinates x = " << getCell()->getY() << ", y = " << getCell()->getX() << endl;
}

// **************************************************** heal(Unit<CIVIL, TOT>*)
template <typename TOT> 
void Unit<CIVIL, TOT>::heal(Unit<CIVIL, TOT>* s_Ptr) const
{ s_Ptr->setHealth(s_Ptr->getHealth() + 25);
  cout << "          Unit is heal" << endl;
}

// **************************************************** save()
template <typename TOT>
void Unit<CIVIL, TOT>::save() const
{ cout << "Printing from UnitCIVIL save()" << endl;
}

// **************************************************** load()
//template <typename TOT>
//Unit<CIVIL, TOT>* Unit<CIVIL, TOT>::load()
//{ Unit<CIVIL, TOT>* ptr_Unitt;
//  return ptr_Unitt; 
//}

// ****************************************************   buildBuilderFactory()
template <typename TOT> 
Factory* Unit<CIVIL, TOT>::buildBuilderFactory()
{ 
}

// ****************************************************   buildBuilderFactory(Cell*, std::string, Player*)
//template <typename TOT> 
//Factory* Unit<CIVIL, TOT>::buildBuilderFactory(Cell* c, std::string uT, Player* pl)
//{ 
//}

// ****************************************************   buildMedicFactory()
template <typename TOT> 
Factory* Unit<CIVIL, TOT>::buildMedicFactory()
{ 
}

// ****************************************************   buildMedicFactory(Cell*, std::string, Player*)
//template <typename TOT> 
//Factory* Unit<CIVIL, TOT>::buildMedicFactory(Cell* c, std::string uT, Player* pl)
//{ 
//}

// ***********************************************************************************************
// *******************************************  template specialization for MILITARY units  *********
// ***********************************************************************************************


