CC=g++
LD=g++

CFLAGS=
LFLAGS=-lGL -lglfw -lGLEW

SRC=$(shell find . -name \*.cpp)
OBJ=${SRC:.cpp=.o}

OUT=chromaray

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
	${LD} ${OBJ} -o ${OUT} ${LFLAGS}

clean:
	rm ${OBJ} -f
	rm ${OUT} -f
