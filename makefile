CC = g++
CFLAGS = -std=c++14
TARGET = prog

BUILD = ./build
SRC = ./src
INCLUDE = ./include

all: ${BUILD}/${TARGET}

${BUILD}/${TARGET}: ${BUILD}/cartao_credito.o ${BUILD}/conta.o ${BUILD}/investimento.o ${BUILD}/metas.o ${BUILD}/transacao.o ${BUILD}/usuario.o ${BUILD}/validador.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/cartao_credito.o ${BUILD}/conta.o ${BUILD}/investimento.o ${BUILD}/metas.o ${BUILD}/transacao.o ${BUILD}/usuario.o ${BUILD}/validador.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/cartao_credito.o: ${INCLUDE}/Financas/cartao_credito.hpp ${INCLUDE}/Financas/transacao.hpp ${SRC}/Financas/cartao_credito.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Financas/ -c ${SRC}/Financas/cartao_credito.cpp -o ${BUILD}/cartao_credito.o

${BUILD}/conta.o: ${INCLUDE}/Usuario/conta.hpp ${INCLUDE}/Financas/cartao_credito.hpp ${INCLUDE}/Financas/investimento.hpp ${INCLUDE}/Financas/metas.hpp ${SRC}/Usuario/conta.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Usuario/ -I ${INCLUDE}/Financas/ -c ${SRC}/Usuario/conta.cpp -o ${BUILD}/conta.o

${BUILD}/investimento.o: ${INCLUDE}/Financas/investimento.hpp ${SRC}/Financas/investimento.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Financas/ -c ${SRC}/Financas/investimento.cpp -o ${BUILD}/investimento.o

${BUILD}/metas.o: ${INCLUDE}/Financas/metas.hpp ${SRC}/Financas/metas.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Financas/ -c ${SRC}/Financas/metas.cpp -o ${BUILD}/metas.o

${BUILD}/transacao.o: ${INCLUDE}/Financas/transacao.hpp ${SRC}/Financas/transacao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Financas/ -c ${SRC}/Financas/transacao.cpp -o ${BUILD}/transacao.o

${BUILD}/usuario.o: ${INCLUDE}/Usuario/usuario.hpp ${INCLUDE}/Usuario/conta.hpp ${INCLUDE}/Financas/cartao_credito.hpp ${SRC}/Usuario/usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Usuario/ -I ${INCLUDE}/Financas/ -c ${SRC}/Usuario/usuario.cpp -o ${BUILD}/usuario.o

${BUILD}/main.o: ${INCLUDE}/Financas/cartao_credito.hpp ${INCLUDE}/Usuario/conta.hpp ${INCLUDE}/Financas/transacao.hpp ${INCLUDE}/Usuario/usuario.hpp ${INCLUDE}/Usuario/validador.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Financas/ -I ${INCLUDE}/Usuario/ -c ${SRC}/main.cpp -o ${BUILD}/main.o

${BUILD}/validador.o: ${INCLUDE}/Usuario/validador.hpp ${INCLUDE}/Usuario/usuario.hpp ${SRC}/Usuario/validador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Usuario/ -I ${INCLUDE}/Financas/ -c ${SRC}/Usuario/validador.cpp -o ${BUILD}/validador.o

.PHONY: builder run clean cleanTest test

builder:
	mkdir -p ${BUILD}

run:
	${BUILD}/${TARGET}

clean:
	rm -f ${BUILD}/*.exe ${BUILD}/*.o

test:
	${CC} -std=c++11 -Wall -g test.cpp -o progTeste
	./progTeste

cleanTest:
	rm -f progTeste
