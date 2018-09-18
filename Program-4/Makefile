airline.out : flight.o main.o plane.o utilities.o flights.o passenger.o 
	g++ -ansi -Wall -g -o airline.out flight.o main.o plane.o utilities.o flights.o passenger.o

flight.o : flight.cpp flight.h plane.h flights.h 
	g++ -ansi -Wall -g -c flight.cpp

main.o : main.cpp flights.h utilities.h passenger.h 
	g++ -ansi -Wall -g -c main.cpp

plane.o : plane.cpp plane.h utilities.h passenger.h 
	g++ -ansi -Wall -g -c plane.cpp

utilities.o : utilities.cpp utilities.h 
	g++ -ansi -Wall -g -c utilities.cpp

flights.o : flights.cpp flights.h flight.h utilities.h
	g++ -ansi -Wall -g -c flights.cpp

passenger.o : passenger.cpp passenger.h plane.h
	g++ -ansi -Wall -g -c passenger.cpp

clean : 
	rm -f airline.out flight.o  main.o  plane.o  utilities.o flights.o passenger.o
