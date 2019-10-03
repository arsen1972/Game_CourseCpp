cl: 
	g++ -c main.cpp ./AllGame/AllGame.cpp
	g++ -c ./ObjectGame/ObjectGame.cpp
	g++ -c ./Player/Player.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Civil/Builder.cpp ./Unit/Civil/Medic.cpp
	g++ -c ./Factory/Factory.cpp ./Factory/BuilderFactory.cpp ./Factory/MedicFactory.cpp
	g++ -c ./Cell/Cell.cpp
		
	g++ main.o AllGame.o ObjectGame.o Player.o Unit.o Builder.o Medic.o Factory.o  BuilderFactory.o MedicFactory.o Cell.o -o all	
	clear
	./all
del:
	rm main.o AllGame.o ObjectGame.o Player.o Unit.o Builder.o Medic.o Factory.o  BuilderFactory.o MedicFactory.o Cell.o all
	
re-cl:
	rm main.o AllGame.o ObjectGame.o Player.o Unit.o Builder.o Medic.o Factory.o  BuilderFactory.o MedicFactory.o Cell.o all
	
	g++ -c main.cpp ./AllGame/AllGame.cpp
	g++ -c ./ObjectGame/ObjectGame.cpp
	g++ -c ./Player/Player.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Civil/Builder.cpp ./Unit/Civil/Medic.cpp
	g++ -c ./Factory/Factory.cpp ./Factory/BuilderFactory.cpp ./Factory/MedicFactory.cpp
	g++ -c ./Cell/Cell.cpp
		
	g++ main.o AllGame.o ObjectGame.o Player.o Unit.o Builder.o Medic.o Factory.o BuilderFactory.o MedicFactory.o Cell.o -o all	
	clear
	./all