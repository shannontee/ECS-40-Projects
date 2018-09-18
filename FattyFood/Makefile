food.out : food.o main.o fattyfood.o
	g++ -ansi -Wall -g -o food.out main.o food.o fattyfood.o

food.o : food.cpp food.h
	g++ -ansi -Wall -g -c food.cpp

fattyfood.o: fattyfood.cpp fattyfood.h
	g++ -ansi -Wall -g -c fattyfood.cpp

main.o : main.cpp food.h fattyfood.h
	g++ -ansi -Wall -g -c main.cpp

clean:
	rm -f food.out food.o main.o fattyfood.o
