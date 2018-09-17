containers.out : container.o main.o sortedvector.o vector.o linkedlist.o sortedlinkedlist.o
	g++ -ansi -Wall -g -o containers.out container.o main.o sortedvector.o vector.o linkedlist.o sortedlinkedlist.o

container.o : container.cpp container.h
	g++ -ansi -Wall -g -c container.cpp

main.o : main.cpp container.h sortedvector.h vector.h linkedlist.h sortedlinkedlist.h
	g++ -ansi -Wall -g -c main.cpp

sortedvector.o : sortedvector.cpp sortedvector.h
	g++ -ansi -Wall -g -c sortedvector.cpp

vector.o : vector.cpp vector.h
	g++ -ansi -Wall -g -c vector.cpp

linkedlist.o : linkedlist.cpp linkedlist.h
	g++ -ansi -Wall -g -c linkedlist.cpp

sortedlinkedlist.o : sortedlinkedlist.cpp sortedlinkedlist.h
	g++ -ansi -Wall -g -c sortedlinkedlist.cpp

clean: 
	rm -f containers.out container.o main.o sortedvector.o vector.o linkedlist.o sortedlinkedlist.o
