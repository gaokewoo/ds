CC_FLAGS= -g -Wall -fpic
CC=g++

SRCS = $(wildcard *.cc)
BUILD = $(patsubst %.cc, %.o, $(SRCS))

LIB_NAME=libalg.so

all:$(LIB_NAME) 
OBJS=$(BUILD)

$(LIB_NAME):$(OBJS)
	$(CC) -shared -o $@ $(OBJS)
	@if [ ! -d ../lib/ ];then mkdir ../lib/;fi
	mv -f $@ ../lib/
	@echo "### $@ loaded ###\n"

.cc.o:
	$(CC) $(CC_FLAGS)   -c $<

clean:
	rm -f *.o

