cl: main.cpp getDepartment.cpp Unit.cpp Factory.cpp CavalryFactory.cpp Cavalry.cpp
	g++ -c main.cpp getDepartment.cpp fullAttack.cpp Unit.cpp Factory.cpp CavalryFactory.cpp Cavalry.cpp Cell.cpp
	g++ main.o getDepartment.o fullAttack.o Unit.o Factory.o CavalryFactory.o Cavalry.o Cell.o -o all	
clean:
	rm main.o getDepartment.o fullAttack.o Unit.o Factory.o Cavalry.o CavalryFactory.o Cell.o all
