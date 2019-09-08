cl: 
	g++ -c main.cpp 
	g++ -c ./Functions/getDepartment.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Civil/Builder.cpp 
	g++ -c ./Factory/Factory.cpp ./Factory/BuilderFactory.cpp
	g++ -c ./Cell/Cell.cpp 
		
	g++ main.o getDepartment.o Unit.o Builder.o Factory.o BuilderFactory.o Cell.o -o all	
	clear
	./all
del:
	rm main.o getDepartment.o Unit.o Builder.o Factory.o BuilderFactory.o Cell.o all
	
re-cl:
	rm main.o getDepartment.o Unit.o Builder.o Factory.o BuilderFactory.o Cell.o all
	
	g++ -c main.cpp 
	g++ -c ./Functions/getDepartment.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Civil/Builder.cpp 
	g++ -c ./Factory/Factory.cpp ./Factory/BuilderFactory.cpp
	g++ -c ./Cell/Cell.cpp 
		
	g++ main.o getDepartment.o Unit.o Builder.o Factory.o BuilderFactory.o Cell.o -o all	
	clear
	./all