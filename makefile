CC = g++
CFLAGS = -std=c++14
TARGET = prog

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/cartao_credito.o ${BUILD}/conta.o ${BUILD}/transacao.o ${BUILD}/usuario.o ${BUILD}/main.o ${BUILD}/investimento.o ${BUILD}/orcamento.o ${BUILD}/validador.o
	${CC} ${CFLAGS} ${BUILD}/cartao_credito.o ${BUILD}/conta.o ${BUILD}/transacao.o ${BUILD}/usuario.o ${BUILD}/main.o ${BUILD}/investimento.o ${BUILD}/orcamento.o ${BUILD}/validador.o -o ${BUILD}/${TARGET}

${BUILD}/cartao_credito.o: ${INCLUDE}/cartao_credito.hpp ${SRC}/cartao_credito.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/cartao_credito.cpp -o ${BUILD}/cartao_credito.o

${BUILD}/conta.o: ${INCLUDE}/conta.hpp ${SRC}/conta.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/conta.cpp -o ${BUILD}/conta.o

${BUILD}/transacao.o: ${INCLUDE}/transacao.hpp ${SRC}/transacao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/transacao.cpp -o ${BUILD}/transacao.o

${BUILD}/usuario.o: ${INCLUDE}/usuario.hpp ${SRC}/usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/usuario.cpp -o ${BUILD}/usuario.o

${BUILD}/main.o: ${INCLUDE}/cartao_credito.hpp ${INCLUDE}/conta.hpp ${INCLUDE}/transacao.hpp ${INCLUDE}/usuario.hpp ${INCLUDE}/validador.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/main.cpp -o ${BUILD}/main.o

${BUILD}/investimento.o: ${INCLUDE}/investimento.hpp ${SRC}/investimento.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/investimento.cpp -o ${BUILD}/investimento.o

${BUILD}/orcamento.o: ${INCLUDE}/orcamento.hpp ${SRC}/orcamento.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/orcamento.cpp -o ${BUILD}/orcamento.o

${BUILD}/validador.o: ${INCLUDE}/validador.hpp ${INCLUDE}/usuario.hpp ${SRC}/validador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/validador.cpp -o ${BUILD}/validador.o

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
