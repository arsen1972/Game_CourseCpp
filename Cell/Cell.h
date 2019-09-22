#pragma once

#include <string>

using std::string;

class Cell
{
public:
   Cell();
   Cell(int, int, string);
   ~Cell();
   string getLands() const;
   int getX() const;
   int getY() const;
   
private:
  int x;
  int y;
  string lands;

};