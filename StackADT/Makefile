CC=g++ 
CFLAGS=-Wall -ggdb
SOURCE=src
INCLUDE=include
BUILD=build
BINARY=bin


all: ${BINARY}/StackADTMain ${BINARY}/ArrayStackMain ${BINARY}/LinkedListStackMain

${BINARY}/StackADTMain: ${SOURCE}/StackADTMain.cpp ${SOURCE}/ArrayStack.cpp ${SOURCE}/LinkedListStack.cpp ${INCLUDE}/StackADT.h
	${CC} ${CFLAGS} -I${INCLUDE} -o ${BINARY}/StackADTMain ${SOURCE}/StackADTMain.cpp


${BINARY}/ArrayStackMain: ${SOURCE}/ArrayStackMain.cpp ${SOURCE}/ArrayStack.cpp  ${INCLUDE}/StackADT.h
	${CC} ${CFLAGS} -I${INCLUDE} -o ${BINARY}/ArrayStackMain ${SOURCE}/ArrayStackMain.cpp



${BINARY}/LinkedListStackMain: ${SOURCE}/LinkedListStackMain.cpp ${SOURCE}/LinkedListStack.cpp ${INCLUDE}/StackADT.h
	${CC} ${CFLAGS} -I${INCLUDE} -o ${BINARY}/LinkedListStackMain ${SOURCE}/LinkedListStackMain.cpp


.PHONY: clean run-adt-stack run-array-stack run-linked-stack


clean:
	rm -rf ${BUILD}/* ${BINARY}/*

run-adt-stack: ${BINARY}/StackADTMain
	${BINARY}/StackADTMain


run-array-stack: ${BINARY}/ArrayStackMain
	${BINARY}/ArrayStackMain


run-linked-stack: ${BINARY}/LinkedListStackMain
	${BINARY}/LinkedListStackMain
