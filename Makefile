CC=g++
LD=g++

CFLAGS=
LFLAGS=-lGL -lglfw -lGLEW

SRC=$(shell find . -name \*.cpp)
OBJ=${SRC:.cpp=.o}

BIN_DIR=bin/
OUT=${BIN_DIR}chromaray

all: options build

options:
	@echo CC 	= ${CC}
	@echo LD 	= ${LD}
	@echo CFLAGS 	= ${CFLAGS}
	@echo LFLAGS 	= ${LFLAGS}
	@echo SRC 	= ${SRC}
	@echo OBJ 	= ${OBJ}

.cpp.o:
	${CC} -c $< ${CFLAGS} -o $@

build: ${OBJ}
	mkdir ${BIN_DIR} -p
	${LD} ${OBJ} -o ${OUT} ${LFLAGS}

clean:
	rm ${OBJ} -f
	rm ${OUT} -f
