#pragma once

#include <iostream>
#include <string>

using std::string;

class AttackAction : public Action
{
public:

  void execut() override;
  void doAction() override;
    
private:
  
};