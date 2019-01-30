# File: "Makefile"
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -g -MMD
EXEC = checkers
OBJECTS = main.o game.o cell.o checker.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
# if you just call "make", this will be the target
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
# "clean" is a task, but not a file name
clean:
	rm ${OBJECTS} ${DEPENDS}
.PHONY: clean

