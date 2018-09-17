all: BST.out BST2.out
	

BST.out: main.o
	g++ -ansi -Wall -g  main.o -o BST.out

BST2.out: main2.o
	g++ -ansi -Wall -g  main2.o -o BST2.out

main.o: main.cpp BinarySearchTree.h BinarySearchTree.cpp
	g++ -ansi -Wall -DNDEBUG -g -c main.cpp -o main.o

main2.o: main.cpp BinarySearchTree.h BinarySearchTree.cpp
	g++ -ansi -Wall -g -c main.cpp -o main2.o

clean:
	rm -f main.o main2.o BST.out BST2.out
