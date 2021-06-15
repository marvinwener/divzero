# Project: dRTE_Demo

CC      = gcc
BIN     = divZero

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS_C = $(wildcard *.c) $(wildcard */*.c)

# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS = $(patsubst %.c,%.o,$(SRCS_C))

CFLAGS  = -c


.PHONY: all all-before all-after clean clean-custom

all: divZero

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJS)
	echo $(OBJS)
	$(CC) $(OBJS) -o "divZero"

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.cpp
	$(CC) -x c $(CFLAGS) -o $@ $<
