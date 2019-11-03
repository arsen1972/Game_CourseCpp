#include <iostream>

#include "ObjectGame.h"

using std::cout;
using std::endl;
using std::string;

// ****************************************** ObjectGame()
ObjectGame::ObjectGame()
{ //cout << "   ObjectGame()" << endl;
  id = statID;
  statID++;
}

// ****************************************** ObjectGame(string&)
ObjectGame::ObjectGame(string& uT) : unitType(uT)
{ //cout << "   ObjectGame()" << endl;
  id = statID;
  statID++;
}

// ****************************************** ~ObjectGame()
ObjectGame::~ObjectGame()
{ cout << "   ~ObjectGame()" << endl;
}

// ****************************************** save()
void ObjectGame::save() const
{ cout << "Printing from ObjectGame save()" << endl;
}
// ****************************************** save()
string ObjectGame::toString() const
{
   string str = "Printing from ObjectGame::toString()";
   return str;
}
// ****************************************** string getUnitType() const
string ObjectGame::getUnitType() const
{ cout << "From ObjectGame::getUnitType()" << endl;
}

// ****************************************** void doAction()
void ObjectGame::doAction()
{ cout << "From ObjectGame::doAction()" << endl;
}


// *****************************************
int ObjectGame::statID = 1;