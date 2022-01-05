GCC = gcc
INCLUDES = -I ./lib
CFLAGS = -Wall
LDFLAGS = -lncurses
CC = ${GCC} ${CFLAGS} ${INCLUDES}
OBJS = main.o board.o objects.o
EXE = target.out
SRC_DIR = ./lib
.PHONY: all clean

all: ${OBJS}
	@echo "Building..."
	${CC} ${OBJS} -o ${EXE} ${LDFLAGS}
	-rm -f *.o

main.o: ./main.c
	${CC} -c ./main.c

board.o: ${SRC_DIR}/board.c
	${CC} -c ${SRC_DIR}/board.c

objects.o: ${SRC_DIR}/objects.c
	${CC} -c ${SRC_DIR}/objects.c

clean:
	@echo "Cleaning up..."
	-rm -f *.o
	-rm -f *.out