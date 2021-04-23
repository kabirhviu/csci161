CC=g++ -Wall
SRC=src
INCLUDE=include
BUILD=build
BINARY=bin


all: ${BINARY}/TestStack


${BINARY}/TestStack: ${BUILD}/TestStack.o ${BUILD}/ArrayStack.o ${BUILD}/LinkedListStack.o
	${CC} -I${INCLUDE} -o ${BINARY}/TestStack ${BUILD}/TestStack.o ${BUILD}/ArrayStack.o ${BUILD}/LinkedListStack.o

${BUILD}/TestStack.o:
	${CC} -c -I${INCLUDE} -o ${BUILD}/TestStack.o ${SRC}/TestStack.cpp

${BUILD}/ArrayStack.o:
	$(CC) -c -I${INCLUDE} -o ${BUILD}/ArrayStack.o ${SRC}/ArrayStack.cpp

${BUILD}/LinkedListStack.o:
	$(CC) -c -I${INCLUDE} -o ${BUILD}/LinkedListStack.o ${SRC}/LinkedListStack.cpp


.PHONY: clean run


clean:
	rm -rf ${BUILD}/* ${BINARY}/*

run: ${BINARY}/TestStack
	${BINARY}/TestStack
