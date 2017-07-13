LinkedList.out: LinkedList.o main.o
					g++ -Wall -o LinkedList.out LinkedList.o main.o

LinkedList.o: LinkedList.cpp LinkedList.h
					g++ -Wall -c LinkedList.cpp

main.o: main.cpp LinkedList.h
					g++ -Wall -c main.cpp

clean:
					rm -rf LinkedList.out LinkedList.o main.o
