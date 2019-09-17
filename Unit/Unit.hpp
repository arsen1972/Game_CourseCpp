#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>

#include "Enums.h"
#include "../Cell/Cell.h"
//#include "../Factory/Factory.h"

#define PATH_OF_SAVE "Save/saves.csv"

using std::string;
using std::to_string;
using std::map;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::vector;

template <Status stat, typename TOT> // template <Status stat, TypeOfTerrain TypeOT>  
class Unit
{
// *************************************   Constructor/destructor
 public:
  Unit();
  Unit(Status, TypeOfTerrain, string, int, int, bool, Cell*); 
  virtual ~Unit();
  virtual string getUnitType() const;
  virtual void printUnitFields() const;
  virtual void move();
  void attack(Unit*);
  virtual void save();
  virtual string load();
  virtual Cell* getCell() const;
  virtual void buildBuilderFactory();
  
 private:                      // ***********************  fields  
  string unitType;
  int health;
  int damage;
  bool defence; 
    
  Cell* cell;
   
  Status status;
  TypeOfTerrain typeOfTerrain;

  protected:                   // ***********************  methods()
  
  virtual int getHealth() const;
  virtual void setHealth(int);
  virtual int getDamage() const;
  virtual bool getDefence() const;
  virtual Status getStatus() const;
  virtual TypeOfTerrain getTOT() const;

  
  virtual int getAttackBonus() = 0;
  virtual int getDefenceBonus() = 0;
 
};

template <Status stat, typename TOT> // template <typename Status, typename TypeOfTerrain>
Unit<stat, TOT>::Unit()  // Unit<Status, TypeOfTerrain>
{}
// ****************************************************   Constructor/destructor
template <Status stat, typename TOT> 
Unit<stat, TOT>::Unit (Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : status(st), typeOfTerrain(tOT), unitType(uT), health(h), damage(d), defence(def), cell(c)
{ cout << "Обьект Unit" << endl;
}

template <Status stat, typename TOT> 
Unit<stat, TOT>::~Unit()
{ cout << "Обьект ~Unit" << endl;
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
{ 
  vector<string> v_temp;
  string inString;
  ifstream fin(PATH_OF_SAVE);
  getline(fin, inString);
  fin.close();
  
  char* temp_text = new char[inString.size()+1];
  strcpy(temp_text, inString.c_str());
  char* c_temp = strtok(temp_text, ";");
  
  while (c_temp != NULL)
  {
    v_temp.push_back(c_temp);
    c_temp = strtok (NULL, ";");
  }
  
  unitType = v_temp[0];
  health = atoi(v_temp[1].c_str());
  damage = atoi(v_temp[2].c_str());
  defence = atoi(v_temp[3].c_str());
  
  // по сохраненным/загруженным координатам берем элемент karta[x][y] (получаем указатель и им инициализируем объект)
  
  switch (atoi(v_temp[7].c_str()))
  {
    case 0: status = CIVIL; break;
    case 1: status = MILITARY; break;
    case 2: status = UNIVERSAL;
  }
  
  return inString; //for (int i = 0; i < v_temp.size(); i++) { cout << "Element №" << i << " = " << v_temp[i] << endl; }
}


// ****************************************************   buildBuilderFactory()
template <Status stat, typename TOT> 
void Unit<stat, TOT>::buildBuilderFactory()
{ cout << "BuilderFactory is done virtual" << endl;
}

// ***********************************************************************************************
// *******************************************  template specialization for CIVIL units  *********
// ***********************************************************************************************
template <typename TOT>
class Unit<CIVIL, TOT>
{
// *************************************   Constructor/destructor
 public:
  Unit();
  Unit(Status, TypeOfTerrain, string, int, int, bool, Cell*); 
  virtual ~Unit();
  virtual string getUnitType() const;
  virtual void printUnitFields() const;
  virtual void move();
  void attack(Unit*);
  virtual void save();
  virtual string load();
  virtual Cell* getCell() const;
  virtual void buildBuilderFactory();
  
 private:                      // ***********************  fields  
  string unitType;
  int health;
  int damage;
  bool defence; 
    
  Cell* cell;
   
  Status status;
  TypeOfTerrain typeOfTerrain;

  protected:                   // ***********************  methods()
  
  virtual int getHealth() const;
  virtual void setHealth(int);
  virtual int getDamage() const;
  virtual bool getDefence() const;
  virtual Status getStatus() const;
  virtual TypeOfTerrain getTOT() const;

  
  virtual int getAttackBonus() = 0;
  virtual int getDefenceBonus() = 0;
 
};

template <typename TOT>
Unit<CIVIL, TOT>::Unit()
{}
// ****************************************************   Constructor/destructor
template <typename TOT> 
Unit<CIVIL, TOT>::Unit (Status st, TypeOfTerrain tOT, string uT, int h, int d, bool def, Cell* c) : status(st), typeOfTerrain(tOT), unitType(uT), health(h), damage(d), defence(def), cell(c)
{ cout << "Обьект Unit" << endl;
}

template <typename TOT> 
Unit<CIVIL, TOT>::~Unit()
{ cout << "Обьект ~Unit" << endl;
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

// **************************************************** getStatus()
template <typename TOT>
Status Unit<CIVIL, TOT>::getStatus() const
{
  return this->status;
}

// **************************************************** getTOT()
template <typename TOT>
TypeOfTerrain Unit<CIVIL, TOT>::getTOT() const
{
  return this->typeOfTerrain;
}
  
// **************************************************** printUnitFields()
template <typename TOT>
void Unit<CIVIL, TOT>::printUnitFields() const
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
template <typename TOT> 
void Unit<CIVIL, TOT>::move()
{
  cout << "Unit Топ-топ!" << endl;
}

// ****************************************************   attack(Unit*)
template <typename TOT> 
void Unit<CIVIL, TOT>::attack(Unit* ptr_victim)
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
template <typename TOT>
void Unit<CIVIL, TOT>::save()
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
template <typename TOT>
string Unit<CIVIL, TOT>::load()
{ 
  vector<string> v_temp;
  string inString;
  ifstream fin(PATH_OF_SAVE);
  getline(fin, inString);
  fin.close();
  
  char* temp_text = new char[inString.size()+1];
  strcpy(temp_text, inString.c_str());
  char* c_temp = strtok(temp_text, ";");
  
  while (c_temp != NULL)
  {
    v_temp.push_back(c_temp);
    c_temp = strtok (NULL, ";");
  }
  
  unitType = v_temp[0];
  health = atoi(v_temp[1].c_str());
  damage = atoi(v_temp[2].c_str());
  defence = atoi(v_temp[3].c_str());
  
  // по сохраненным/загруженным координатам берем элемент karta[x][y] (получаем указатель и им инициализируем объект)
  
  switch (atoi(v_temp[7].c_str()))
  {
    case 0: status = CIVIL; break;
    case 1: status = MILITARY; break;
    case 2: status = UNIVERSAL;
  }
  return inString; 
}

// ****************************************************   buildBuilderFactory()
template <typename TOT> 
void Unit<CIVIL, TOT>::buildBuilderFactory()
{ cout << "BuilderFactory is done virtual" << endl;
}

// ***********************************************************************************************
// *******************************************  template specialization for MILITARY units  *********
// ***********************************************************************************************


