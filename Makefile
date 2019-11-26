CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquad
OBJECTS = main.o controller.o game.o display.o board.o block.o block_I.o block_J.o block_L.o block_O.o block_S.o block_Z.o block_T.o block_dot.o level.o level0.o level1.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
