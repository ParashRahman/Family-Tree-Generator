CC = gcc
CFLAGS = -Wall

gs: family_tree.o person.o main.o random_handler.o name_generator.o
	${CC} ${CFLAGS} -o gs family_tree.o person.o main.o random_handler.o name_generator.o

main.o: main.cpp
	${CC} ${CFLAGS} -std=c++11 -c main.cpp

family_tree.o: family_tree.h family_tree.cpp
	${CC} ${CFLAGS} -std=c++11 -c family_tree.h family_tree.cpp

person.o: person.h person.cpp
	${CC} ${CFLAGS} -std=c++11 -c person.h person.cpp

random_handler.o: random_handler.h random_handler.cpp
	${CC} ${CFLAGS} -std=c++11 -c random_handler.h random_handler.cpp

name_generator.o: name_generator.h name_generator.cpp
	${CC} ${CFLAGS} -std=c++11 -c name_generator.h name_generator.cpp
