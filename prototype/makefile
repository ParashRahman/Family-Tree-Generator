CC = g++
CFLAGS = -Werror -g
CXXFLAGS = -std=c++11

gs: family_tree.o person.o main.o random_handler.o name_generator.o logger.o tui.o
	${CC} ${CFLAGS} ${CXXFLAGS} -o gs family_tree.o person.o main.o random_handler.o name_generator.o logger.o tui.o

main.o: main.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c main.cpp

family_tree.o: family_tree.h family_tree.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c family_tree.h family_tree.cpp

person.o: person.h person.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c person.h person.cpp

random_handler.o: random_handler.h random_handler.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c random_handler.h random_handler.cpp

name_generator.o: name_generator.h name_generator.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c name_generator.h name_generator.cpp

tui.o: tui.h tui.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c tui.h tui.cpp

logger.o: logger.h logger.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c logger.h logger.cpp

clean:
	rm -rf *.o
