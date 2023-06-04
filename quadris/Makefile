CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -g -MMD
EXEC = quadris
OBJECTS = main.o Grid.o subject.o textdisplay.o  block.o Iblock.o Jblock.o Lblock.o Oblock.o Sblock.o Tblock.o Zblock.o level.o level0.o level1.o level2.o level3.o level4.o
DEPENDS = ${OBJECTS:.o=.d} 


${EXEC}: ${OBJECTS} 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 
-include ${DEPENDS} 

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS} 
.PHONY: clean
