CC = g++
CFLAGS = -Werror -g
CXXFLAGS = -std=c++11

gs: family_tree.o person.o main.o random_handler.o name_generator.o logger.o tui.o person_stats.o
	${CC} ${CFLAGS} ${CXXFLAGS} -o gs family_tree.o person.o person_stats.o main.o random_handler.o name_generator.o logger.o tui.o

family_tree.o: family_tree.h family_tree.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c family_tree.h family_tree.cpp


logger.o: logger.h logger.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c logger.h logger.cpp

main.o: main.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c main.cpp

name_generator.o: name_generator.h name_generator.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c name_generator.h name_generator.cpp

person.o: person.h person.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c person.h person.cpp

person_stats.o: person_stats.h person_stats.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c person_stats.h person_stats.cpp

random_handler.o: random_handler.h random_handler.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c random_handler.h random_handler.cpp

tui.o: tui.h tui.cpp
	${CC} ${CFLAGS} ${CXXFLAGS} -c tui.h tui.cpp

clean:
	rm -rf *.o
