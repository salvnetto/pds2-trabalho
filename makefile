CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = ControleFinanceiro

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/saldo.o ${BUILD}/metas.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/saldo.o ${BUILD}/metas.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/saldo.o: ${INCLUDE}/saldo.hpp ${SRC}/saldo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/saldo.cpp -o ${BUILD}/saldo.o

${BUILD}/metas.o: ${INCLUDE}/metas.hpp ${SRC}/metas.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/metas.cpp -o ${BUILD}/metas.o

${BUILD}/main.o: ${INCLUDE}/saldo.hpp ${INCLUDE}/metas.hpp ${SRC}/main.cpp 
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/main.cpp -o ${BUILD}/main.o