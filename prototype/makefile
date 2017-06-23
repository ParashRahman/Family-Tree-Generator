gs: family_tree.o person.o main.o
	g++ -o gs family_tree.o person.o main.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

family_tree.o: family_tree.h family_tree.cpp
	g++ -std=c++11 -c family_tree.h family_tree.cpp

person.o: person.h person.cpp
	g++ -std=c++11 -c person.h person.cpp
