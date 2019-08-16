#include <iostream>
#include "Unit.h"

//******************************************************************  fullAttack()  
void fullAttack(Unit* ptr_aggressor, Unit* ptr_victim, short repeat)
{    
  for (int i=0; i<repeat; i++)
  {
    ptr_aggressor->attack(ptr_victim);
    std::cout << "Health unit_1 (aggressor) = " << ptr_aggressor->getHealth() << std::endl;
    std::cout << "Health unit_2 (victim) = " << ptr_victim->getHealth() << std::endl;
  }
      
  if (ptr_aggressor->getHealth() < 7)   //magic number
  { std::cout << "Жизнь агрессора окончена" << std::endl;
    delete ptr_aggressor;
    ptr_aggressor = nullptr;
  }
  if (ptr_victim->getHealth() < 7)   //magic number
  { std::cout << "Жизнь жертвы окончена\n" << std::endl;
    delete ptr_victim;
    ptr_victim = nullptr;
  }
}