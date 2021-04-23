CC=g++ -Wall
SRC=src
INCLUDE=include
BUILD=build
BINARY=bin


${BINARY}/StackADTMain: ${BUILD}/StackADTMain.o ${BUILD}/ArrayStack.o ${BUILD}/LinkedListStack.o
	${CC} -I${INCLUDE} -o ${BINARY}/StackADTMain ${BUILD}/StackADTMain.o ${BUILD}/ArrayStack.o ${BUILD}/LinkedListStack.o

${BUILD}/StackADTMain.o:
	${CC} -c -I${INCLUDE} -o ${BUILD}/StackADTMain.o ${SRC}/StackADTMain.cpp

${BUILD}/ArrayStack.o:
	$(CC) -c -I${INCLUDE} -o ${BUILD}/ArrayStack.o ${SRC}/ArrayStack.cpp

${BUILD}/LinkedListStack.o:
	$(CC) -c -I${INCLUDE} -o ${BUILD}/LinkedListStack.o ${SRC}/LinkedListStack.cpp


.PHONY: clean run


clean:
	rm -rf ${BUILD}/* ${BINARY}/*

run: ${BINARY}/StackADTMain
	${BINARY}/StackADTMain
