GCC = gcc
INCLUDES = -I ./lib
CC = ${GCC} ${INCLUDES}
OBJS = main.o coordinates.o board.o
EXE = target.out
SRC_DIR = ./lib
.PHONY: all clean

all: ${OBJS}
	@echo "Building..."
	${CC} ${OBJS} -o ${EXE}
	-rm -f *.o

main.o: ./main.c
	${CC} -c ./main.c

board.o: ${SRC_DIR}/board.c
	${CC} -c ${SRC_DIR}/board.c

coordinates.o: ${SRC_DIR}/coordinates.c
	${CC} -c ${SRC_DIR}/coordinates.c

clean:
	@echo "Cleaning up..."
	-rm -f *.o
	-rm -f *.out