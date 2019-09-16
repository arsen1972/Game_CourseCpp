#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

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
  
//  static vector<vector<Cell*>> karta;
};