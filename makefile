cl: 
	g++ -c main.cpp 
	g++ -c ./Functions/getDepartment.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Cavalry.cpp 
	g++ -c ./Factory/Factory.cpp ./Factory/CavalryFactory.cpp
	g++ -c ./Cell/Cell.cpp 
		
	g++ main.o getDepartment.o Unit.o Factory.o CavalryFactory.o Cavalry.o Cell.o -o all	

del:
	rm main.o getDepartment.o Unit.o Factory.o CavalryFactory.o Cavalry.o Cell.o all
	
re-cl:
	rm main.o getDepartment.o Unit.o Factory.o CavalryFactory.o Cavalry.o Cell.o all
	
	g++ -c main.cpp 
	g++ -c ./Functions/getDepartment.cpp 
	g++ -c ./Unit/Unit.cpp ./Unit/Cavalry.cpp 
	g++ -c ./Factory/Factory.cpp ./Factory/CavalryFactory.cpp
	g++ -c ./Cell/Cell.cpp 
		
	g++ main.o getDepartment.o Unit.o Factory.o CavalryFactory.o Cavalry.o Cell.o -o all