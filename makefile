cl: 
	g++ -c main.cpp 
	g++ -c ./Functions/getDepartment.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Civil/Builder.cpp ./Unit/Civil/Medic.cpp ./Unit/Civil/Atlant.cpp 
	g++ -c ./Unit/Military/Land/Cavalry.cpp ./Unit/Military/Land/Infantry.cpp 
	g++ -c ./Factory/Factory.cpp ./Factory/BuilderFactory.cpp ./Factory/MedicFactory.cpp ./Factory/AtlantFactory.cpp
	g++ -c ./Factory/MilitaryLandFactory.cpp ./Factory/MilitaryNavyFactory.cpp ./Factory/MilitaryAirFactory.cpp 
	g++ -c ./Cell/Cell.cpp 
		
	g++ main.o getDepartment.o Unit.o Builder.o Medic.o Atlant.o Cavalry.o Infantry.o Factory.o BuilderFactory.cpp MedicFactory.o AtlantFactory.o MilitaryLandFactory.o MilitaryNavyFactory.o MilitaryAirFactory.o Cell.o -o all	
	clear
	./all
del:
	rm main.o getDepartment.o Unit.o Builder.o Medic.o Atlant.o Cavalry.o Infantry.o Factory.o BuilderFactory.cpp MedicFactory.o AtlantFactory.o MilitaryLandFactory.o MilitaryNavyFactory.o MilitaryAirFactory.o Cell.o all
	
re-cl:
	rm main.o getDepartment.o Unit.o Builder.o Medic.o Atlant.o Cavalry.o Infantry.o Factory.o BuilderFactory.cpp MedicFactory.o AtlantFactory.o MilitaryLandFactory.o MilitaryNavyFactory.o MilitaryAirFactory.o Cell.o all
	
	g++ -c main.cpp 
	g++ -c ./Functions/getDepartment.cpp
	g++ -c ./Unit/Unit.cpp ./Unit/Civil/Builder.cpp ./Unit/Civil/Medic.cpp ./Unit/Civil/Atlant.cpp 
	g++ -c ./Unit/Military/Land/Cavalry.cpp ./Unit/Military/Land/Infantry.cpp 
	g++ -c ./Factory/Factory.cpp ./Factory/BuilderFactory.cpp ./Factory/MedicFactory.cpp ./Factory/AtlantFactory.cpp
	g++ -c ./Factory/MilitaryLandFactory.cpp ./Factory/MilitaryNavyFactory.cpp ./Factory/MilitaryAirFactory.cpp 
	g++ -c ./Cell/Cell.cpp 
		
	g++ main.o getDepartment.o Unit.o Builder.o Medic.o Atlant.o Cavalry.o Infantry.o Factory.o BuilderFactory.cpp MedicFactory.o AtlantFactory.o MilitaryLandFactory.o MilitaryNavyFactory.o MilitaryAirFactory.o Cell.o -o all	
	clear
	./all