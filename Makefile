CC=gcc
CFLAGS=-Wall -Wextra -O2 

INC_DIR=/usr/local/include
LIB_DIR=/usr/local/lib/

BIN=utils

all: adding_lib

utils.o: utils.c
	gcc -c -fPIC $^ -o $@

libutils.so: utils.o	
	gcc -shared -o $@ $^

adding_lib: libutils.so
	sudo cp utils.h $(INC_DIR)
	sudo cp $^ $(LIB_DIR)
	sudo ldconfig

clean:
	rm utils.o libutils.so