#pragma once

#include <iostream>
#include <string>

using std::string;

class MoveAction : public Action
{
public:

  void execut() override;
  void doAction() override;
  
private:
  
};