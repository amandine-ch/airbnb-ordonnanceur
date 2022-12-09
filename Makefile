CC=gcc
CP=CP
CFLAGS=-Wall
RM=rm -r

SRC=src
OBJ=obj


SRCS=$(wildcard $(SRC)/*.c)
HEADS=$(wildcard $(SRC)/*.h)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))


BINDIR=bin
BIN=$(BINDIR)/main

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lm

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -lm

.PHONY: clean

clean:
	$(RM) $(BINDIR)/* || echo Rien à supprimer dans bin
	$(RM) $(OBJ)/* || echo Rien à supprimer dans obj