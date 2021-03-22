OBJECTS=build
BINARY=bin
INCLUDE=include
SRC=src

binarytree: binarytree.o main.o binary
	g++ -Wall -o ${BINARY}/binarytree ${OBJECTS}/main.o ${OBJECTS}/binarytree.o

main.o: build ${SRC}/main.cpp ${SRC}/binarytree.cpp
	g++ -Wall -c -o ${OBJECTS}/main.o ${SRC}/main.cpp

binarytree.o: build ${SRC}/binarytree.cpp ${INCLUDE}/binarytreenode.h ${INCLUDE}/binarytree.h
	g++ -Wall -c -o ${OBJECTS}/binarytree.o ${SRC}/binarytree.cpp
build:
	mkdir build
binary:
	mkdir bin
clean:
		rm -r ${OBJECTS} ${BINARY}
