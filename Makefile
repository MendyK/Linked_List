CC = gcc
FLAGS = -Wall
RM = rm -vrf
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
PROG = $(patsubst %.c, %, $(SRC))

all: index

index:
	$(CC) $(FLAGS) $(SRC) -o linkedlist_test

clean:
	$(RM) $(OBJ)
	$(RM) $(PROG)
