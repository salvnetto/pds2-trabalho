CC = g++
CFLAGS = -std=c++14
TARGET = prog

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/cartao_credito.o ${BUILD}/conta.o ${BUILD}/transacao.o ${BUILD}/usuario.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/cartao_credito.o ${BUILD}/conta.o ${BUILD}/transacao.o ${BUILD}/usuario.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/cartao_credito.o: ${INCLUDE}/cartao_credito.h ${SRC}/cartao_credito.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/cartao_credito.cpp -o ${BUILD}/cartao_credito.o

${BUILD}/conta.o: ${INCLUDE}/conta.h ${SRC}/conta.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/conta.cpp -o ${BUILD}/conta.o

${BUILD}/transacao.o: ${INCLUDE}/transacao.h ${SRC}/transacao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/transacao.cpp -o ${BUILD}/transacao.o

${BUILD}/usuario.o: ${INCLUDE}/usuario.h ${SRC}/usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/usuario.cpp -o ${BUILD}/usuario.o

${BUILD}/main.o: ${INCLUDE}/cartao_credito.h ${INCLUDE}/conta.h ${INCLUDE}/transacao.h ${INCLUDE}/usuario.h ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/main.cpp -o ${BUILD}/main.o

builder:
	if not exist build mkdir build

run:
	${BUILD}/${TARGET}

clean:
	del build\*.exe
	del build\*.o

test:
	g++ -std=c++11 -Wall -g test.cpp -o progTeste
	.\progTeste.exe

cleanTest:
	del progTeste.exe
