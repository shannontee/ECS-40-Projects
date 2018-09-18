templates.out : main.o
	g++ -ansi -Wall -g -o templates.out main.o

main.o : main.cpp vector.h
	g++ -ansi -Wall -g -c main.cpp

clean:
	rm -f templates.out main.o
