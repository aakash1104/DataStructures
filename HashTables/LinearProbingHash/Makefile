LinearProbing.out: LinearProbing.o main.o
					g++ -Wall -o LinearProbing.out LinearProbing.o main.o

LinearProbing.o: LinearProbing.cpp LinearProbing.h
					g++ -Wall -c LinearProbing.cpp

main.o: main.cpp LinearProbing.h
					g++ -Wall -c main.cpp

clean:
					rm -rf LinearProbing.o main.o LinearProbing.out
