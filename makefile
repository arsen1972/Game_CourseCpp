cl: 
	g++ -c main.cpp 
	g++ -c ./Functions/getDepartment.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Military/Military.cpp ./Unit/Military/Land/LandUnit.cpp ./Unit/Military/Land/Cavalry.cpp ./Unit/Civil/Civil.cpp ./Unit/Civil/Builder.cpp
	g++ -c ./Factory/Factory.cpp ./Factory/CavalryFactory.cpp ./Factory/BuilderFactory.cpp
	g++ -c ./Cell/Cell.cpp 
		
	g++ main.o getDepartment.o Unit.o Military.o LandUnit.o Civil.o Factory.o CavalryFactory.o BuilderFactory.o Cavalry.o Builder.o Cell.o -o all	
	clear
	./all
del:
	rm main.o getDepartment.o Unit.o Military.o LandUnit.o Civil.o Factory.o CavalryFactory.o BuilderFactory.o Cavalry.o Builder.o Cell.o all
	
re-cl:
	rm main.o getDepartment.o Unit.o Military.o LandUnit.o Civil.o Factory.o CavalryFactory.o BuilderFactory.o Cavalry.o Builder.o Cell.o all
	
	g++ -c main.cpp 
	g++ -c ./Functions/getDepartment.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Military/Military.cpp ./Unit/Military/Land/LandUnit.cpp ./Unit/Military/Land/Cavalry.cpp ./Unit/Civil/Civil.cpp ./Unit/Civil/Builder.cpp
	g++ -c ./Factory/Factory.cpp ./Factory/CavalryFactory.cpp ./Factory/BuilderFactory.cpp
	g++ -c ./Cell/Cell.cpp  
		
	g++ main.o getDepartment.o Unit.o Military.o LandUnit.o Civil.o Factory.o CavalryFactory.o BuilderFactory.o Cavalry.o Builder.o Cell.o -o all	
	clear
	./all