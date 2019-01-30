# File: "Makefile"
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -g -MMD
EXEC = connect4
OBJECTS = main.o game.o cell.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
# if you just call "make", this will be the target
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
# "clean" is a task, but not a file name
clean:
	rm ${OBJECTS} ${DEPENDS}
.PHONY: clean

