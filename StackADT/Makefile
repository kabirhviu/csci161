CC=g++ -Wall
SRC=src
INCLUDE=include
BUILD=build
BIN=bin


build: TestStack.o ArrayStack.o LinkedListStack.o
	${CC} -I${INCLUDE} -o ${BIN}/TestStack ${BUILD}/TestStack.o ${BUILD}/ArrayStack.o ${BUILD}/LinkedListStack.o

TestStack.o:
	${CC} -c -I${INCLUDE} -o ${BUILD}/TestStack.o ${SRC}/TestStack.cpp

ArrayStack.o:
	$(CC) -c -I${INCLUDE} -o ${BUILD}/ArrayStack.o ${SRC}/ArrayStack.cpp

LinkedListStack.o:
	$(CC) -c -I${INCLUDE} -o ${BUILD}/LinkedListStack.o ${SRC}/LinkedListStack.cpp

clean:
	rm -rf ${BUILD}/* ${BIN}/*
