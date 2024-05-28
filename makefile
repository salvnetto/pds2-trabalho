CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = ControleFinanceiro

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/saldo.o ${BUILD}/metas.o ${BUILD}/banco.o ${BUILD}/contabancaria.o ${BUILD}/main.o ${BUILD}/cartaodecredito.o
	${CC} ${CFLAGS} ${BUILD}/saldo.o ${BUILD}/metas.o ${BUILD}/banco.o ${BUILD}/contabancaria.o ${BUILD}/main.o ${BUILD}/cartaodecredito.o -o ${BUILD}/${TARGET}

${BUILD}/saldo.o: ${INCLUDE}/saldo.hpp ${SRC}/saldo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/saldo.cpp -o ${BUILD}/saldo.o

${BUILD}/metas.o: ${INCLUDE}/metas.hpp ${SRC}/metas.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/metas.cpp -o ${BUILD}/metas.o

${BUILD}/banco.o: ${INCLUDE}/banco.hpp ${SRC}/banco.cpp ${INCLUDE}/contabancaria.hpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/banco.cpp -o ${BUILD}/banco.o

${BUILD}/contabancaria.o: ${INCLUDE}/contabancaria.hpp ${SRC}/contabancaria.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/contabancaria.cpp -o ${BUILD}/contabancaria.o

${BUILD}/cartaodecredito.o: ${INCLUDE}/cartaodecredito.hpp ${SRC}/cartaodecredito.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/cartaodecredito.cpp -o ${BUILD}/cartaodecredito.o

${BUILD}/main.o: ${INCLUDE}/saldo.hpp ${INCLUDE}/metas.hpp ${SRC}/main.cpp ${INCLUDE}/banco.hpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/main.cpp -o ${BUILD}/main.o
