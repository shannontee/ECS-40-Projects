Airline.out : flight.o main.o plane.o utilities.o 
		g++ -Wall -g -o airline.out flight.o main.o plane.o utilities.o 
 
flight.o : flight.cpp flight.h
		g++ -Wall -g -c flight.cpp
 
main.o : main.cpp flight.h utilities.h
		g++ -Wall -g -c main.cpp
 
plane.o : plane.cpp plane.h utilities.h
		g++ -Wall -g -c plane.cpp
 
utilities.o : utilities.cpp utilities.h
		g++ -Wall -g -c utilities.cpp 
clean :
		rm -f airline.out flight.o  main.o  plane.o  utilities.o
