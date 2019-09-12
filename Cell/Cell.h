#pragma once
#include <string>
using std::string;

class Cell
{
public:
   Cell();
   Cell(string, int, int);
   ~Cell();
   string getLands() const;
   int getX() const;
   int getY() const;
   
private:
  int X;
  int Y;
  string lands;
};