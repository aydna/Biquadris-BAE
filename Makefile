CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquad
OBJECTS = main.o window.o controller.o game.o drawer.o text_drawer.o graphics_drawer.o board.o block.o block_I.o block_J.o block_L.o block_O.o block_S.o block_Z.o block_T.o block_dot.o block_doughnut.o block_diag.o block_X.o block_branch.o block_rand.o level.o level0.o level1.o level2.o level3.o level4.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPENDS}


.PHONY: clean sclean makeclean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

sclean:
	rm ${OBJECTS} ${DEPENDS}
	
makeclean:
	make
	make sclean