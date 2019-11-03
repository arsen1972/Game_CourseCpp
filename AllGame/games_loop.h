int step = 1;
bool play = true;

while(play)
{ 
  list <shared_ptr <Player>>::const_iterator itPlayer = ListOfPlayers.begin();
  for (itPlayer; itPlayer != ListOfPlayers.end(); itPlayer++)
  { 
    Factory* currentFactory = nullptr;
    UnitCIVIL* currentUnitCIVIL = nullptr;
  
    list <shared_ptr <Player>>::const_iterator itNextPlayer = ++itPlayer; --itPlayer;
    cout << "\n*****  У игрока " << (*itPlayer)->getName() << " в наличии: " << endl;
    cout << "список ObjectGame: " << endl;
    (*itPlayer)->printMapOfObjectGame(); 
        
    cout << endl;
    cout << (*itPlayer)->getName() << " делает ход № " << step << endl;
    
    cout << "Введите id с кем/чем работать: ";
    string idInput;
    cin >> idInput;
    int selectID = atoi(idInput.c_str());
    cout << "You select: " << selectID << endl;
    cout << "Сейчас в map (количество ObjectGame) = " << (*itPlayer)->getMapOfObjectGame().size() << endl;
    
    map<int, ObjectGame*>::iterator itOG = (*itPlayer)->getMapOfObjectGame().begin();
    for(itOG; itOG != (*itPlayer)->getMapOfObjectGame().end(); itOG++)
    { 
      ObjectGame* ptr_tempObjectGame = (*itPlayer)->getMapOfObjectGame().at(selectID);
      cout << "ПРОВЕРКА!!!!  тип данных: " << ptr_tempObjectGame->unitType << endl;
      
      if (selectID < 1)
      { cout << "Нет такого id... Игрок пропускает ход." << endl;
      }
    
      else
      {
        cout << "id корректен! Проверимся дальше: " << endl;
        cout << "current id elementOfMap = " << (*itPlayer)->getMapOfObjectGame().at(selectID)->id << endl;
        cout << "               selectID = " << selectID << endl;
      
        if (ptr_tempObjectGame->unitType == "builderFactory")
        { 
          cout << "Вы выбрали объект " << itOG->second->unitType << " Он умеет только делать builder-ов" << endl;
          cout << "Хотите ли создать \"builder\". (Y/N) ? " ;
          string isBuilder;
          cin >> isBuilder;
          currentFactory = dynamic_cast<Factory*>(ptr_tempObjectGame);
    
          if(isBuilder == "Y" || isBuilder == "y")
          {
            cout << "Рождаем билдера -> "; 
            string strTemp = "builder";
            UnitCIVIL* cur_Unit = currentFactory->getUnit(CIVIL, LAND, strTemp, 200, 0, 0, gameMap[0][1], (*itPlayer).get());
            cur_Unit->printUnitFields();
          }
          else 
          { cout << "O-o... error!" << endl;
          }
          break;
        }

        else if (ptr_tempObjectGame->unitType == "builder")
        { 
          cout << "Вы выбрали объект " << itOG->second->unitType << ". Пока он умеет только строить builderFactory" << endl;
          cout << "Хотите ли построить \"builderFactory\". (Y/N) ? " ;
          string isBuilderFactory;
          cin >> isBuilderFactory;
          currentUnitCIVIL = dynamic_cast<UnitCIVIL*>(ptr_tempObjectGame);
          
          if(isBuilderFactory == "Y" || isBuilderFactory == "y")
          {
            cout << "Строим  builderFactory -> "; 
            currentFactory = currentUnitCIVIL->buildBuilderFactory();
            currentFactory->printUnitFields();
          }
          else 
          { cout << "O-o... error!" << endl;
          }
          break;
        }

        else 
        { cout << "Вы НИЧЕГО не выбрали!!!" << endl; break;
        }
        
      }  
    }
    
    if(itNextPlayer == ListOfPlayers.end())
    { 
      cout << "\n***************   Ход № " << step << " закончен. Начинаем ход № " << step + 1 << endl;
      itNextPlayer = ListOfPlayers.begin();
      itPlayer = --ListOfPlayers.begin();
      step++;
    }

    cout << "\nПередать ход следующему игроку " << (*itNextPlayer)->getName() << "(Y/N)? ";  
    string nextPlayStep;
    cin >> nextPlayStep;

    if(nextPlayStep == "Y"||nextPlayStep == "y")
    { continue;}
    else
    { break;}
  }

  cout << "Согласны выйти из игры? (Y/any_key)" << endl;
  string tempPlay;
  cin >> tempPlay;

  if (tempPlay == "Y" || tempPlay == "y")
  {play = false;}   
}
