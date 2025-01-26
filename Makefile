CC=gcc
CFLAGS=-Wall -Wextra -O2 

INC_DIR=/usr/local/include
LIB_DIR=/usr/local/lib/

HEADER=utils.h

SRC_DIR=src
BLD_DIR=build

CFILES=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(CFILES))

BIN=utils

all: setup adding_lib

# utils.o: utils.c
#	gcc -c -fPIC $^ -o $@

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) -fPIC $< -o $@

libutils.so: $(OBJS)	
	gcc -shared -o $@ $^

adding_lib: libutils.so
	sudo cp $(HEADER) $(INC_DIR)
	sudo cp $^ $(LIB_DIR)
	sudo ldconfig

setup:
	@mkdir -p $(BLD_DIR)

clean:
	rm $(OBJS) libutils.so