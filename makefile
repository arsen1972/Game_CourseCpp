cl: 
	g++ -c main.cpp 
	g++ -c ./Unit/Unit.cpp ./Unit/Civil/Universal.cpp ./Unit/Civil/Builder.cpp
	g++ -c ./Factory/Factory.cpp ./Factory/UniversalFactory.cpp ./Factory/BuilderFactory.cpp
	g++ -c ./Cell/Cell.cpp 
		
	g++ main.o Unit.o Universal.o Builder.o Factory.o UniversalFactory.o BuilderFactory.o Cell.o -o all	
	clear
	./all
del:
	rm main.o Unit.o Universal.o Builder.o Factory.o UniversalFactory.o BuilderFactory.o Cell.o all
	
re-cl:
	rm main.o Unit.o Universal.o Builder.o Factory.o UniversalFactory.o BuilderFactory.o Cell.o all
	
	g++ -c main.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Civil/Universal.cpp ./Unit/Civil/Builder.cpp
	g++ -c ./Factory/Factory.cpp ./Factory/UniversalFactory.cpp ./Factory/BuilderFactory.cpp
	g++ -c ./Cell/Cell.cpp 
		
	g++ main.o Unit.o Universal.o Builder.o Factory.o UniversalFactory.o BuilderFactory.o Cell.o -o all	
	clear
	./all