# File: "Makefile"
CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -g -L/usr/X11R6/lib -I/usr/X11R6/include
EXEC = reversi -lX11
OBJECTS = main.o cell.o game.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
# if you just call "make", this will be the target
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
# "clean" is a task, but not a file name
clean:
	rm ${OBJECTS} ${DEPENDS}
.PHONY: clean




