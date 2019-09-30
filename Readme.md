	30/09/2019

- Работающая версия. Скрин;
- SMART ptr for Unit & Factory;
- Пакетное сохранение (поочередный вызов save() );
- Лечение юнита юнитом (пока для проверки функционирования оба юнита - builder);
- пообъектная загрузка (простой load() );
- строительство фабрики в клетке, где находится builder (который может сделать move(x,y) в другую клетку);
- class Player - SMART_ptr;
- add field "Player* player" (with the necessary methods) to class Factory;