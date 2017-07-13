BST.out: BST.o main.o
					g++ -Wall -o BST.out BST.o main.o

BST.o: BST.cpp BST.h
					g++ -Wall -c BST.cpp

main.o: main.cpp BST.h
					g++ -Wall -c main.cpp

clean:
					rm -rf BST.o main.o BST.out
